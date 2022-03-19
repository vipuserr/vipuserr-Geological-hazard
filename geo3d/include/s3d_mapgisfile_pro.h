#pragma once

#pragma pack(push, 1)

	#pragma pack(push, 8)
		#include "gmeMdl.h"
	#pragma pack(pop)

	#include "s3d_KerGISAdapterDef.h"
	#include "s3d_GisStru.h"

	using namespace std;


	namespace Smart3dMap
	{

		class S3DKERGIS_ADAPTER_EXP  gm_mapgis_vector
		{
		public:
			gm_mapgis_vector();
			virtual ~gm_mapgis_vector();

		public:
			//取带路径的文件名
			void _getPathFile(string& name);
			void _setPathFile(string& name);
			//取路径名
			void _getPath(string& name);
			void _setPath(string& name);
			//取文件名
			void _getFile(string& name);
			void _setFile(string& name);
			//取文件标题
			void _getTitle(string& name);
			void _setTitle(string& name);

			void loadFile(string strPathFile);
			void createFile(string strPathFile, GM_VECTOR_TYPE vecType = GM_PNT);
			void closeFile();
			void saveFile();

			//取图层文件类型（0-GM_LIN  1-GM_PNT  2-GM_REG）
			int getLayerType();
			void setLayerType(GM_VECTOR_TYPE vecType);

			//取出图元个数
			int getGraphNum();

			void getPntText(long i, string& str);
			void getPntText(vector<string>& strList);
			void setPntText(vector<string>& strList);

			//取出点
			void getPnt(vector<GM_PNT_INFO>*& pntsInfo, vector<_D_DOT>*& pntsCoord);
			void setPnt(vector<GM_PNT_INFO>* pntsInfo, vector<_D_DOT>* pntsCoord);
			//取出线
			void getLin(vector<GM_LIN_INFO>*& linsInfo, vector<vector<_D_DOT>>*& linsCoord);
			void setLin(vector<GM_LIN_INFO>* linsInfo, vector<vector<_D_DOT>>* linsCoord);
			//取出区
			void getReg(vector<GM_REG_INFO>*& regsInfo, vector<GM_REG_SEG>*& regsSeg,
				vector<GM_LIN_INFO>*& regLinsInfo, vector<vector<_D_DOT>>*& regLinsCoord, vector<GM_LIN_TOP>*& regLinsTop, vector<GM_LIN_NODE>*& regLinsNode);
			void setReg(vector<GM_REG_INFO>* regsInfo, vector<GM_REG_SEG>* regsSeg,
				vector<GM_LIN_INFO>* regLinsInfo, vector<vector<_D_DOT>>* regLinsCoord, vector<GM_LIN_TOP>* regLinsTop=NULL, vector<GM_LIN_NODE>* regLinsNode = NULL);

			//取文件范围
			void _getRange(_D_RECT *rc);
			void _setRange(_D_RECT *rc);
			//取地图参数
			void getMapPara(GM_MAP_PARA* mappara);
			void setMapPara(GM_MAP_PARA* mappara);

			//矢量文件的属性结构
			void _getAttStru(gmeFields*& m_attStru);
			void _setAttStru(gmeFields* m_attStru);
			void _getAtt(gmeRecordSet*& m_attStru);
			void _setAtt(gmeRecordSet* m_attStru);

			void _getAttStru_reg(gmeFields*& m_attStru);
			void _setAttStru_reg(gmeFields* m_attStru);
			void _getAtt_reg(gmeRecordSet*& m_attStru);
			void _setAtt_reg(gmeRecordSet* m_attStru);


		private:
			//取点数据
			//1.点显示参数
			void getPntDispParam();
			//2.点注记
			void getPntNote();
			//3.点属性结构及属性
			void getPntAtt();
			//4.点图元范围
			void getPntGraphRect();
			//5.点图元存在标志
			void getPntGraphExistFlag();

			//取线数据
			//1.线显示参数
			void getLinDispParam();
			//2.线坐标
			void getLinCoord();
			//3.线属性结构及属性
			void getLinAtt();
			//4.线拓扑
			void getLinTopo();
			//5.线结点信息
			void getLinTiePnts();
			//6.线结点属性
			void getLinTieAtt();
			//7.点图元范围
			void getLinGraphRect();
			//8.点图元存在标志
			void getLinGraphExistFlag();

			//取区数据
			//1.弧段线显示参数
			void getArcDispParam();
			//2.区的弧段数据：结点、弧段线坐标、弧段号
			void getArcData();
			//3.弧段线属性结构及属性
			void getArcAtt();
			//4.弧段线拓扑
			void getArcTopo();
			//5.弧段线结点信息
			void getArcTiePnts();
			//6.弧段线结点属性
			void getArcTieAtt();
			//7.弧段图元范围
			void getArcGraphRect();
			//8.弧段图元存在标志
			void getArcGraphExistFlag();
			//9.区显示参数
			void getRegDispParam();
			//10.取属性结构和属性
			void getRegAtt();
			//11.区图元范围
			void getRegGraphRect();
			//12.区图元存在标志
			void getRegGraphExistFlag();

			//获取点/线（或弧段）的属性数据
			void getVecAttInfo(long vecAttrDataHeaderIndex = 2);

		private:
			//写点数据
			//1.点显示参数
			void setPntDispParam();
			//2.点注记
			void setPntNote();
			//3.点属性结构及属性
			void setPntAtt();
			//4.点图元范围
			void setPntGraphRect();
			//5.点图元存在标志
			void setPntGraphExistFlag();

			//写线数据
			//1.线显示参数
			void setLinDispParam();
			//2.线坐标
			void setLinCoord();
			//3.线属性结构及属性
			void setLinAtt();
			//4.线拓扑
			void setLinTopo();
			//5.线结点信息
			void setLinTiePnts();
			//6.线结点属性
			void setLinTieAtt();
			//7.点图元范围
			void setLinGraphRect();
			//8.点图元存在标志
			void setLinGraphExistFlag();

			//写区数据
			//1.弧段线显示参数
			void setArcDispParam();
			//2.区的弧段数据：结点、弧段线坐标、弧段号
			void setArcData();
			//3.弧段线属性结构及属性
			void setArcAtt();
			//4.弧段线拓扑
			void setArcTopo();
			//5.弧段线结点信息
			void setArcTiePnts();
			//6.弧段线结点属性
			void setArcTieAtt();
			//7.弧段图元范围
			void setArcGraphRect();
			//8.弧段图元存在标志
			void setArcGraphExistFlag();
			//9.区显示参数
			void setRegDispParam();
			//10.取属性结构和属性
			void setRegAtt();
			//11.区图元范围
			void setRegGraphRect();
			//12.区图元存在标志
			void setRegGraphExistFlag();

			//计算文件中的偏移量
			void calHeadOffset();
			//点/线属性信息...			
			void setVecAttInfo(long vecAttrDataHeaderIndex = 2);

		public:
			_VECTOR_FILE_HEADER m_vecFileHeader; //工作区文件头
			_PROJECTITEM m_vecItemInfo; //工作区文件在工程文件中的信息
			VecHeadInfo m_vecHeadInfo[16];//工作区数据头信息

			string		m_strPath_File;//图层文件的全路径文件名...
			string		m_strPath;	//图层文件的全路径
			string		m_strFile;	//图层文件的文件名
			string		m_strTitle;	//图层文件的标题

			vector<_D_RECT> m_graphRect;//点线图元范围...
			vector<GM_GRAPH_EXIST> m_graphExist;//点线图元对象是否物理存在
			vector<_D_RECT> m_graphRect_reg;//区图元范围...
			vector<GM_GRAPH_EXIST> m_graphExist_reg;//区图元对象是否物理存在

			vector<GM_PNT_INFO> m_pntInfo;//点信息
			vector<_D_DOT> m_pntsCoord;//点坐标列表
			vector<string> m_pntStrBuf; //点的字符串列表(n*128bytes)

			vector<GM_LIN_INFO> m_linInfo;//线信息
			vector<vector<_D_DOT>> m_linsCoord;//线坐标列表

			vector<GM_REG_INFO> m_regInfo;//区信息
			vector<GM_REG_SEG> m_regData; //区的列表
			vector<GM_LIN_TOP>  m_regLinsTop; //区中的线拓扑
			vector<GM_LIN_NODE>	m_regLinsNode;//区中的线节点信息

			//点/线的属性结构
			GM_ATTRTBL_HEAD m_vecAttTblHead; //工作区属性表头信息
			vector<GM_Fld_DEF> m_vecFldStru; //工作区字段定义信息
			gmeFields		m_attStru;
			gmeRecordSet	m_attRcdSet;

			//区属性结构...
			GM_ATTRTBL_HEAD m_vecAttTblHead_reg; //工作区属性表头信息
			vector<GM_Fld_DEF> m_vecFldStru_reg; //工作区字段定义信息
			gmeFields		m_attStru_reg;
			gmeRecordSet	m_attRcdSet_reg;

		private:
			fstream*	m_filePtr; //文件指针...
			char*	m_pMemBuf;
		};




		class  S3DKERGIS_ADAPTER_EXP gm_mapgis_prj
		{
		public:
			gm_mapgis_prj();
			virtual ~gm_mapgis_prj();

		public:
			//创建工程文件
			void _PRJCreateProject(string prjname);
			//装入工程文件
			void _PRJLoadProject(string prjname);
			//关闭工程文件
			void _PRJCloseProject();
			//保存工程文件
			void _PRJSaveProject();

			//取带路径的文件名
			void _PRJGetPathName(string& pathname);
			void _PRJSetPathName(string& pathname);

			//取不带路径的文件名
			void _PRJGetFileName(string& filename);
			void _PRJSetFileName(string& filename);

			//取工程的图层文件数
			int _PRJGetFileNum();
			void _PRJSetFileNum(long fileNum);

			//取工程文件的地图参数...
			GM_MAP_PARA& GetMapPara();
			void SetMapPara(GM_MAP_PARA& mappara);

			//存取工程文件的范围
			void _PRJSetRange(_D_RECT *rc);
			void _PRJGetRange(_D_RECT *rc);

			//向工程中添加图层文件...
			void _PRJAppend(string vecfname);
			void _PRJAppend(vector<string>& vecfname);
			string _PRJGetItem(int no, string& name); //no从0开始
			void _PRJGetItem(vector<string>& name);
			gm_mapgis_vector* _PRJGetItem(int no); //no从0开始
			vector<gm_mapgis_vector*>& _PRJGetItem();

		private:
			//释放工程文件中的矢量图层列表
			void closeVecList();

		public:
			_PROJECTHEAD	m_prjHead; //工程文件头...
			vector<gm_mapgis_vector*> m_layerList;

			string		m_strPath_File;//工程文件的全路径文件名...
			string		m_strPath;	  //工程文件的全路径
			string		m_strFile;	  //工程文件的文件名
			string		m_strTitle;	  //工程文件的标题

		private:
			fstream*			m_filePtr; //文件指针...
		};

		string S3DKERGIS_ADAPTER_EXP _pathChange(string input);
	}



#pragma pack(pop)
