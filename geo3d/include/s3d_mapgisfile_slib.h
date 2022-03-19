#pragma once

#pragma pack(push, 1)

	#include "s3d_mapgisfile_pro.h"

namespace Smart3dMap
{
	enum s3d_GraphType
	{
		//����ͼ�����Ͷ���
		SHAPE_UNKNOWN = 0x0000,	//δ֪����
		SHAPE_LINE = 0x0001,	//��
		SHAPE_POLYGON = 0x0002,	//�����
		SHAPE_ARC = 0x0010,		//Բ��
		SHAPE_CIRCLE = 0x0020,	//Բ
		SHAPE_COLOR = 0x0040,	//��ɫ

		//ͼ��״̬����
		SHAPE_SYMBLE = 0x4000,  //���� (�����)

		SHAPE_FILL = 0x8000		//���
	};


	//ͼ�λ��࣬����ͼ�ξ��Ӵ�����
	class MAPGISLINE;
	class S3DKERGIS_ADAPTER_EXP SHAPEOBJ
	{
	public:
		SHAPEOBJ();
		virtual ~SHAPEOBJ();

	public:
		bool IsFill();	 //�Ƿ����
		void SetFill();

		int  GetType();   //ͼ������
		void SetType(s3d_GraphType graphType = SHAPE_UNKNOWN);

		void SetColorID(int clrID); //MapGIS��ɫ��
		int  GetColorID();

		void SetID(int newid); //ͼԪ��
		int  GetID();

		void SetID2(int newid); //����ͼԪ��
		int  GetID2();


		//CMYK��ɫ
		virtual void SetCmykClr(unsigned char c, unsigned char m, unsigned char y, unsigned char k) {}
		virtual void GetCmykClr(unsigned char& c, unsigned char& m, unsigned char& y, unsigned char& k) {}

		//רɫ
		virtual void SetSpecClrNos(unsigned char* specClrNos, long specClrNum) {}
		virtual void GetSpecClrNos(unsigned *& specClrNos, long& specClrNum) {}

		//RGB��ɫ
		virtual void SetRgbClr(unsigned long rgbClr) { }
		virtual unsigned long GetRgbClr() { return 0; }
		virtual void GetRgbClr(unsigned char& r, unsigned char& g, unsigned char& b) {}

		//���ϵ�����
		virtual void SetLinDots(_D_DOT* linDots, int linDotNum) {}
		virtual void GetLinDots(_D_DOT*& linDots, int& linDotNum) {}

		//���б�
		virtual void SetLins(MAPGISLINE* lins, int linNum) {}
		virtual void GetLins(MAPGISLINE*& lins, int& linNum) {}

		//Բ
		virtual void SetCircle(_D_DOT& center, double& radius) {}
		virtual void GetCircle(_D_DOT& center, double& radius) {}

		//����
		virtual void SetArc(_D_DOT& center, double& radius, double& begin, double& end) {}
		virtual void GetArc(_D_DOT& center, double& radius, double& begin, double& end) {}

		virtual void Draw(unsigned long dc, int x, int y, int scale) = 0;

	protected:
		int				m_graphType;  //ͼ������
		int				m_graphId;    //ͼԪid��
		int				m_graphId2;   //ͼԪid��
		int				m_clrId;      //ͼԪ��ɫID
	};

	//��ɫ
	class  S3DKERGIS_ADAPTER_EXP  MAPGISCOLOR : public SHAPEOBJ
	{
	public:
		MAPGISCOLOR();
		MAPGISCOLOR(unsigned long color);
		virtual ~MAPGISCOLOR();

	public:
		//CMYK��ɫ
		virtual void SetCmykClr(unsigned char c, unsigned char m, unsigned char y, unsigned char k);
		virtual void GetCmykClr(unsigned char& c, unsigned char& m, unsigned char& y, unsigned char& k);

		//RGB��ɫ
		virtual void SetRgbClr(unsigned long rgbClr);
		virtual unsigned long GetRgbClr();
		virtual void GetRgbClr(unsigned char& r, unsigned char& g, unsigned char& b);

		virtual void Draw(unsigned long dc, int x, int y, int scale);

	private:
		unsigned char    m_C, m_M, m_Y, m_K; //��ɫ
		unsigned char    m_SpecClrNos[28];	 //רɫ��
		unsigned long    m_rgb;         //ת�����RGB��ɫֵ
	};


	//����
	class  S3DKERGIS_ADAPTER_EXP  MAPGISLINE : public SHAPEOBJ
	{
	public:
		MAPGISLINE();
		MAPGISLINE(_D_DOT* data, int n);
		virtual ~MAPGISLINE();

	public:
		void Create(_D_DOT* data, int n);
		void Create(const MAPGISLINE& src);

		//���ϵ�����
		virtual void SetLinDots(_D_DOT* linDots, int linDotNum);
		virtual void GetLinDots(_D_DOT*& linDots, int& linDotNum);

		virtual void Draw(unsigned long dc, int x, int y, int scale);

	public:
		_D_DOT* m_linDots;
		int     m_linDotNum;
	};

	//�����
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

		//���б�
		virtual void SetLins(MAPGISLINE* lins, int linNum);
		virtual void GetLins(MAPGISLINE*& lins, int& linNum);

		virtual void Draw(unsigned long dc, int x, int y, int scale);

	private:
		MAPGISLINE* m_lines;
		int         m_linNum;
	};

	//Բ
	class  S3DKERGIS_ADAPTER_EXP   MAPGISCIRCLE : public SHAPEOBJ
	{
	public:
		MAPGISCIRCLE();
		MAPGISCIRCLE(_D_DOT  data, double r1);
		virtual ~MAPGISCIRCLE();

	public:
		void Create(_D_DOT  data, double r1);
		void Create(const MAPGISCIRCLE& src);

		//Բ
		virtual void SetCircle(_D_DOT& center, double& radius);
		virtual void GetCircle(_D_DOT& center, double& radius);

		virtual void Draw(unsigned long dc, int x, int y, int scale);

	private:
		_D_DOT  m_circleCenter;
		double m_circleR;
	};

	//����
	class  S3DKERGIS_ADAPTER_EXP  MAPGISARC : public SHAPEOBJ
	{
	public:
		MAPGISARC();
		MAPGISARC(_D_DOT  data, double r1, double b, double e);
		virtual ~MAPGISARC();

	public:
		void Create(_D_DOT  data, double r1, double b, double e);
		void Create(const MAPGISARC& src);

		//����
		virtual void SetArc(_D_DOT& center, double& radius, double& begin, double& end);
		virtual void GetArc(_D_DOT& center, double& radius, double& begin, double& end);

		virtual void Draw(unsigned long dc, int x, int y, int scale);

	private:
		_D_DOT  m_arcCenter;
		double m_arcR;
		double m_arcBegin;
		double m_arcEnd;
	};



	//slib�е���ͼ�⡢���Ϳ⡢ͼ���⡢��ɫ���еķ������飬����ͼ�λ��������Ķ���
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
		void SetAtGrow(int nIndex, SHAPEOBJ* newElement); //�ڴ��Զ�����

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
		//���ſ�ļ��غ���...
		void  LoadMapGisColorStyle(char* pathfile, SHAPEOBJARY*  colorlib=NULL);     //װ��MAPGIS��ɫ��
		void  LoadMapGisPntStyle(char* pathfile, SHAPEOBJARY*  pointlib = NULL);    //װ��MAPGIS��ͼ��
		void  LoadMapGisLineStyle(char* pathfile, SHAPEOBJARY*  linelib = NULL);      //װ��MAPGIS���Ϳ�
		void  LoadMapGisRegionStyle(char* pathfile, SHAPEOBJARY*  regionlib = NULL);  //װ��MAPGIS���ƿ�

		//����MapGIS��slib·���õ���ɫ�⡢���ſ⡢���Ϳ⡢ͼ���⣨�ú������Զ���������4��������
		void loadMapGisSlib(char* pathname,
							SHAPEOBJARY**  colorlib = nullptr, SHAPEOBJARY**  pointlib = nullptr,
							SHAPEOBJARY**  linelib = nullptr, SHAPEOBJARY**  regionlib = nullptr);

		//�ر�slib��
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
		//��ɫת��
		static void cmyk2rgb(unsigned char c, unsigned char m, unsigned char y, unsigned char k, unsigned char &r, unsigned char &g, unsigned char &b);
		static void rgb2cmyk(unsigned char r, unsigned char g, unsigned char b, unsigned char& c, unsigned char& m, unsigned char& y, unsigned char& k);

		//����mapgis��ɫ��תrgb
		void getRgbClr(long lMapGISClrNo, unsigned char& r, unsigned char& g, unsigned char& b); //��ɫ�Ŵ�1��ʼ
		//����mapgis��ɫ��תcmyk
		void getCmykClr(long lMapGISClrNo, unsigned char& c, unsigned char& m, unsigned char& y, unsigned char& k); //��ɫ�Ŵ�1��ʼ

		//����RGB����һ��GIS��ɫ��.
		long getGisClr(unsigned char r, unsigned char g, unsigned char b); 
		//����cmyk����һ��GIS��ɫ��.
		long getGisClr(unsigned char c, unsigned char m, unsigned char y, unsigned char k); 

		//��MapGIS��ɫ�������һ����ɫ���������ֱ�ӷ�����ɫ��...
		long AddAColor(unsigned char r, unsigned char g, unsigned char b);

	private:
		std::string	m_gisLibPath;//���ſ�·��

		int		m_hClrlibFp;
		int		m_hPntlibFp;
		int		m_hLinlibFp;
		int		m_hReglibFp;

		bool		m_bClrlibChg;
		bool		m_bPntlibChg;
		bool		m_bLinlibChg;
		bool		m_bReglibChg;

		SHAPEOBJARY  m_colorlib; //��ɫ��
		SHAPEOBJARY  m_pointlib; //��ͼ��
		SHAPEOBJARY  m_linelib;  //���Ϳ�
		SHAPEOBJARY  m_regionlib;//ͼ����

		short		m_sExtClrNum;

	};

}

#pragma pack(pop)
