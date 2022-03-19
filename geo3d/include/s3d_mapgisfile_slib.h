#pragma once

#pragma pack(push, 1)

	#include "s3d_mapgisfile_pro.h"

namespace Smart3dMap
{
	enum s3d_GraphType
	{
		//基本图形类型定义
		SHAPE_UNKNOWN = 0x0000,	//未知类型
		SHAPE_LINE = 0x0001,	//线
		SHAPE_POLYGON = 0x0002,	//多边形
		SHAPE_ARC = 0x0010,		//圆弧
		SHAPE_CIRCLE = 0x0020,	//圆
		SHAPE_COLOR = 0x0040,	//颜色

		//图形状态定义
		SHAPE_SYMBLE = 0x4000,  //符号 (组合型)

		SHAPE_FILL = 0x8000		//填充
	};


	//图形基类，所有图形均从此派生
	class MAPGISLINE;
	class S3DKERGIS_ADAPTER_EXP SHAPEOBJ
	{
	public:
		SHAPEOBJ();
		virtual ~SHAPEOBJ();

	public:
		bool IsFill();	 //是否填充
		void SetFill();

		int  GetType();   //图形类型
		void SetType(s3d_GraphType graphType = SHAPE_UNKNOWN);

		void SetColorID(int clrID); //MapGIS颜色号
		int  GetColorID();

		void SetID(int newid); //图元号
		int  GetID();

		void SetID2(int newid); //辅助图元号
		int  GetID2();


		//CMYK颜色
		virtual void SetCmykClr(unsigned char c, unsigned char m, unsigned char y, unsigned char k) {}
		virtual void GetCmykClr(unsigned char& c, unsigned char& m, unsigned char& y, unsigned char& k) {}

		//专色
		virtual void SetSpecClrNos(unsigned char* specClrNos, long specClrNum) {}
		virtual void GetSpecClrNos(unsigned *& specClrNos, long& specClrNum) {}

		//RGB颜色
		virtual void SetRgbClr(unsigned long rgbClr) { }
		virtual unsigned long GetRgbClr() { return 0; }
		virtual void GetRgbClr(unsigned char& r, unsigned char& g, unsigned char& b) {}

		//线上点坐标
		virtual void SetLinDots(_D_DOT* linDots, int linDotNum) {}
		virtual void GetLinDots(_D_DOT*& linDots, int& linDotNum) {}

		//线列表
		virtual void SetLins(MAPGISLINE* lins, int linNum) {}
		virtual void GetLins(MAPGISLINE*& lins, int& linNum) {}

		//圆
		virtual void SetCircle(_D_DOT& center, double& radius) {}
		virtual void GetCircle(_D_DOT& center, double& radius) {}

		//弧度
		virtual void SetArc(_D_DOT& center, double& radius, double& begin, double& end) {}
		virtual void GetArc(_D_DOT& center, double& radius, double& begin, double& end) {}

		virtual void Draw(unsigned long dc, int x, int y, int scale) = 0;

	protected:
		int				m_graphType;  //图形类型
		int				m_graphId;    //图元id号
		int				m_graphId2;   //图元id号
		int				m_clrId;      //图元颜色ID
	};

	//颜色
	class  S3DKERGIS_ADAPTER_EXP  MAPGISCOLOR : public SHAPEOBJ
	{
	public:
		MAPGISCOLOR();
		MAPGISCOLOR(unsigned long color);
		virtual ~MAPGISCOLOR();

	public:
		//CMYK颜色
		virtual void SetCmykClr(unsigned char c, unsigned char m, unsigned char y, unsigned char k);
		virtual void GetCmykClr(unsigned char& c, unsigned char& m, unsigned char& y, unsigned char& k);

		//RGB颜色
		virtual void SetRgbClr(unsigned long rgbClr);
		virtual unsigned long GetRgbClr();
		virtual void GetRgbClr(unsigned char& r, unsigned char& g, unsigned char& b);

		virtual void Draw(unsigned long dc, int x, int y, int scale);

	private:
		unsigned char    m_C, m_M, m_Y, m_K; //四色
		unsigned char    m_SpecClrNos[28];	 //专色号
		unsigned long    m_rgb;         //转换后的RGB颜色值
	};


	//曲线
	class  S3DKERGIS_ADAPTER_EXP  MAPGISLINE : public SHAPEOBJ
	{
	public:
		MAPGISLINE();
		MAPGISLINE(_D_DOT* data, int n);
		virtual ~MAPGISLINE();

	public:
		void Create(_D_DOT* data, int n);
		void Create(const MAPGISLINE& src);

		//线上点坐标
		virtual void SetLinDots(_D_DOT* linDots, int linDotNum);
		virtual void GetLinDots(_D_DOT*& linDots, int& linDotNum);

		virtual void Draw(unsigned long dc, int x, int y, int scale);

	public:
		_D_DOT* m_linDots;
		int     m_linDotNum;
	};

	//多边形
	class  S3DKERGIS_ADAPTER_EXP  MAPGISPOLYGON : public SHAPEOBJ
	{
	public:
		MAPGISPOLYGON();
		MAPGISPOLYGON(MAPGISLINE* data, int n);
		MAPGISPOLYGON(_D_DOT* data, int* m, int n);
		virtual ~MAPGISPOLYGON();

	public:
		void Create(MAPGISLINE* data, int n);
		void Create(const MAPGISPOLYGON& src);

		//线列表
		virtual void SetLins(MAPGISLINE* lins, int linNum);
		virtual void GetLins(MAPGISLINE*& lins, int& linNum);

		virtual void Draw(unsigned long dc, int x, int y, int scale);

	private:
		MAPGISLINE* m_lines;
		int         m_linNum;
	};

	//圆
	class  S3DKERGIS_ADAPTER_EXP   MAPGISCIRCLE : public SHAPEOBJ
	{
	public:
		MAPGISCIRCLE();
		MAPGISCIRCLE(_D_DOT  data, double r1);
		virtual ~MAPGISCIRCLE();

	public:
		void Create(_D_DOT  data, double r1);
		void Create(const MAPGISCIRCLE& src);

		//圆
		virtual void SetCircle(_D_DOT& center, double& radius);
		virtual void GetCircle(_D_DOT& center, double& radius);

		virtual void Draw(unsigned long dc, int x, int y, int scale);

	private:
		_D_DOT  m_circleCenter;
		double m_circleR;
	};

	//弧度
	class  S3DKERGIS_ADAPTER_EXP  MAPGISARC : public SHAPEOBJ
	{
	public:
		MAPGISARC();
		MAPGISARC(_D_DOT  data, double r1, double b, double e);
		virtual ~MAPGISARC();

	public:
		void Create(_D_DOT  data, double r1, double b, double e);
		void Create(const MAPGISARC& src);

		//弧度
		virtual void SetArc(_D_DOT& center, double& radius, double& begin, double& end);
		virtual void GetArc(_D_DOT& center, double& radius, double& begin, double& end);

		virtual void Draw(unsigned long dc, int x, int y, int scale);

	private:
		_D_DOT  m_arcCenter;
		double m_arcR;
		double m_arcBegin;
		double m_arcEnd;
	};



	//slib中的子图库、线型库、图案库、颜色库中的符号数组，管理图形基类派生的对像
	class S3DKERGIS_ADAPTER_EXP  SHAPEOBJARY : public SHAPEOBJ
	{
	public:
		SHAPEOBJARY();
		virtual ~SHAPEOBJARY();

		void SetSize(int nNewSize, int nGrowBy = 1024);
		int GetSize();

		int Add(SHAPEOBJ* newElement);
		SHAPEOBJ* operator[](int nIndex) const;

		virtual void Draw(unsigned long dc, int x, int y, int scale);

	private:
		void SetAtGrow(int nIndex, SHAPEOBJ* newElement); //内存自动增长

	private:
		SHAPEOBJ**     m_pData;
		int            m_nSize;
		int            m_nMaxSize;
		int            m_nGrowBy;
	};



	class S3DKERGIS_ADAPTER_EXP gm_mapgis_slib
	{
	public:
		gm_mapgis_slib();
		virtual ~gm_mapgis_slib();

	public:
		//符号库的加载函数...
		void  LoadMapGisColorStyle(char* pathfile, SHAPEOBJARY*  colorlib=NULL);     //装入MAPGIS颜色库
		void  LoadMapGisPntStyle(char* pathfile, SHAPEOBJARY*  pointlib = NULL);    //装入MAPGIS子图库
		void  LoadMapGisLineStyle(char* pathfile, SHAPEOBJARY*  linelib = NULL);      //装入MAPGIS线型库
		void  LoadMapGisRegionStyle(char* pathfile, SHAPEOBJARY*  regionlib = NULL);  //装入MAPGIS花纹库

		//根据MapGIS的slib路径得到颜色库、符号库、线型库、图案库（该函数会自动调用上述4个函数）
		void loadMapGisSlib(char* pathname,
							SHAPEOBJARY**  colorlib = nullptr, SHAPEOBJARY**  pointlib = nullptr,
							SHAPEOBJARY**  linelib = nullptr, SHAPEOBJARY**  regionlib = nullptr);

		//关闭slib库
		void closeClrlib();
		void closePntlib();
		void closeLinlib();
		void closeReglib();

		void closeSlib();

		SHAPEOBJARY*  GetColorLib();
		SHAPEOBJARY*  GetPntLib();
		SHAPEOBJARY*  GetLinLib();
		SHAPEOBJARY*  GetRegLib();

	public:
		//颜色转换
		static void cmyk2rgb(unsigned char c, unsigned char m, unsigned char y, unsigned char k, unsigned char &r, unsigned char &g, unsigned char &b);
		static void rgb2cmyk(unsigned char r, unsigned char g, unsigned char b, unsigned char& c, unsigned char& m, unsigned char& y, unsigned char& k);

		//根据mapgis颜色号转rgb
		void getRgbClr(long lMapGISClrNo, unsigned char& r, unsigned char& g, unsigned char& b); //颜色号从1开始
		//根据mapgis颜色号转cmyk
		void getCmykClr(long lMapGISClrNo, unsigned char& c, unsigned char& m, unsigned char& y, unsigned char& k); //颜色号从1开始

		//根据RGB返回一个GIS颜色号.
		long getGisClr(unsigned char r, unsigned char g, unsigned char b); 
		//根据cmyk返回一个GIS颜色号.
		long getGisClr(unsigned char c, unsigned char m, unsigned char y, unsigned char k); 

		//向MapGIS颜色库中添加一个颜色，如果有则直接返回颜色号...
		long AddAColor(unsigned char r, unsigned char g, unsigned char b);

	private:
		std::string	m_gisLibPath;//符号库路径

		int		m_hClrlibFp;
		int		m_hPntlibFp;
		int		m_hLinlibFp;
		int		m_hReglibFp;

		bool		m_bClrlibChg;
		bool		m_bPntlibChg;
		bool		m_bLinlibChg;
		bool		m_bReglibChg;

		SHAPEOBJARY  m_colorlib; //颜色库
		SHAPEOBJARY  m_pointlib; //子图库
		SHAPEOBJARY  m_linelib;  //线型库
		SHAPEOBJARY  m_regionlib;//图案库

		short		m_sExtClrNum;

	};

}

#pragma pack(pop)
