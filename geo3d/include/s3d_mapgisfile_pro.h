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
			//ȡ��·�����ļ���
			void _getPathFile(string& name);
			void _setPathFile(string& name);
			//ȡ·����
			void _getPath(string& name);
			void _setPath(string& name);
			//ȡ�ļ���
			void _getFile(string& name);
			void _setFile(string& name);
			//ȡ�ļ�����
			void _getTitle(string& name);
			void _setTitle(string& name);

			void loadFile(string strPathFile);
			void createFile(string strPathFile, GM_VECTOR_TYPE vecType = GM_PNT);
			void closeFile();
			void saveFile();

			//ȡͼ���ļ����ͣ�0-GM_LIN  1-GM_PNT  2-GM_REG��
			int getLayerType();
			void setLayerType(GM_VECTOR_TYPE vecType);

			//ȡ��ͼԪ����
			int getGraphNum();

			void getPntText(long i, string& str);
			void getPntText(vector<string>& strList);
			void setPntText(vector<string>& strList);

			//ȡ����
			void getPnt(vector<GM_PNT_INFO>*& pntsInfo, vector<_D_DOT>*& pntsCoord);
			void setPnt(vector<GM_PNT_INFO>* pntsInfo, vector<_D_DOT>* pntsCoord);
			//ȡ����
			void getLin(vector<GM_LIN_INFO>*& linsInfo, vector<vector<_D_DOT>>*& linsCoord);
			void setLin(vector<GM_LIN_INFO>* linsInfo, vector<vector<_D_DOT>>* linsCoord);
			//ȡ����
			void getReg(vector<GM_REG_INFO>*& regsInfo, vector<GM_REG_SEG>*& regsSeg,
				vector<GM_LIN_INFO>*& regLinsInfo, vector<vector<_D_DOT>>*& regLinsCoord, vector<GM_LIN_TOP>*& regLinsTop, vector<GM_LIN_NODE>*& regLinsNode);
			void setReg(vector<GM_REG_INFO>* regsInfo, vector<GM_REG_SEG>* regsSeg,
				vector<GM_LIN_INFO>* regLinsInfo, vector<vector<_D_DOT>>* regLinsCoord, vector<GM_LIN_TOP>* regLinsTop=NULL, vector<GM_LIN_NODE>* regLinsNode = NULL);

			//ȡ�ļ���Χ
			void _getRange(_D_RECT *rc);
			void _setRange(_D_RECT *rc);
			//ȡ��ͼ����
			void getMapPara(GM_MAP_PARA* mappara);
			void setMapPara(GM_MAP_PARA* mappara);

			//ʸ���ļ������Խṹ
			void _getAttStru(gmeFields*& m_attStru);
			void _setAttStru(gmeFields* m_attStru);
			void _getAtt(gmeRecordSet*& m_attStru);
			void _setAtt(gmeRecordSet* m_attStru);

			void _getAttStru_reg(gmeFields*& m_attStru);
			void _setAttStru_reg(gmeFields* m_attStru);
			void _getAtt_reg(gmeRecordSet*& m_attStru);
			void _setAtt_reg(gmeRecordSet* m_attStru);


		private:
			//ȡ������
			//1.����ʾ����
			void getPntDispParam();
			//2.��ע��
			void getPntNote();
			//3.�����Խṹ������
			void getPntAtt();
			//4.��ͼԪ��Χ
			void getPntGraphRect();
			//5.��ͼԪ���ڱ�־
			void getPntGraphExistFlag();

			//ȡ������
			//1.����ʾ����
			void getLinDispParam();
			//2.������
			void getLinCoord();
			//3.�����Խṹ������
			void getLinAtt();
			//4.������
			void getLinTopo();
			//5.�߽����Ϣ
			void getLinTiePnts();
			//6.�߽������
			void getLinTieAtt();
			//7.��ͼԪ��Χ
			void getLinGraphRect();
			//8.��ͼԪ���ڱ�־
			void getLinGraphExistFlag();

			//ȡ������
			//1.��������ʾ����
			void getArcDispParam();
			//2.���Ļ������ݣ���㡢���������ꡢ���κ�
			void getArcData();
			//3.���������Խṹ������
			void getArcAtt();
			//4.����������
			void getArcTopo();
			//5.�����߽����Ϣ
			void getArcTiePnts();
			//6.�����߽������
			void getArcTieAtt();
			//7.����ͼԪ��Χ
			void getArcGraphRect();
			//8.����ͼԪ���ڱ�־
			void getArcGraphExistFlag();
			//9.����ʾ����
			void getRegDispParam();
			//10.ȡ���Խṹ������
			void getRegAtt();
			//11.��ͼԪ��Χ
			void getRegGraphRect();
			//12.��ͼԪ���ڱ�־
			void getRegGraphExistFlag();

			//��ȡ��/�ߣ��򻡶Σ�����������
			void getVecAttInfo(long vecAttrDataHeaderIndex = 2);

		private:
			//д������
			//1.����ʾ����
			void setPntDispParam();
			//2.��ע��
			void setPntNote();
			//3.�����Խṹ������
			void setPntAtt();
			//4.��ͼԪ��Χ
			void setPntGraphRect();
			//5.��ͼԪ���ڱ�־
			void setPntGraphExistFlag();

			//д������
			//1.����ʾ����
			void setLinDispParam();
			//2.������
			void setLinCoord();
			//3.�����Խṹ������
			void setLinAtt();
			//4.������
			void setLinTopo();
			//5.�߽����Ϣ
			void setLinTiePnts();
			//6.�߽������
			void setLinTieAtt();
			//7.��ͼԪ��Χ
			void setLinGraphRect();
			//8.��ͼԪ���ڱ�־
			void setLinGraphExistFlag();

			//д������
			//1.��������ʾ����
			void setArcDispParam();
			//2.���Ļ������ݣ���㡢���������ꡢ���κ�
			void setArcData();
			//3.���������Խṹ������
			void setArcAtt();
			//4.����������
			void setArcTopo();
			//5.�����߽����Ϣ
			void setArcTiePnts();
			//6.�����߽������
			void setArcTieAtt();
			//7.����ͼԪ��Χ
			void setArcGraphRect();
			//8.����ͼԪ���ڱ�־
			void setArcGraphExistFlag();
			//9.����ʾ����
			void setRegDispParam();
			//10.ȡ���Խṹ������
			void setRegAtt();
			//11.��ͼԪ��Χ
			void setRegGraphRect();
			//12.��ͼԪ���ڱ�־
			void setRegGraphExistFlag();

			//�����ļ��е�ƫ����
			void calHeadOffset();
			//��/��������Ϣ...			
			void setVecAttInfo(long vecAttrDataHeaderIndex = 2);

		public:
			_VECTOR_FILE_HEADER m_vecFileHeader; //�������ļ�ͷ
			_PROJECTITEM m_vecItemInfo; //�������ļ��ڹ����ļ��е���Ϣ
			VecHeadInfo m_vecHeadInfo[16];//����������ͷ��Ϣ

			string		m_strPath_File;//ͼ���ļ���ȫ·���ļ���...
			string		m_strPath;	//ͼ���ļ���ȫ·��
			string		m_strFile;	//ͼ���ļ����ļ���
			string		m_strTitle;	//ͼ���ļ��ı���

			vector<_D_RECT> m_graphRect;//����ͼԪ��Χ...
			vector<GM_GRAPH_EXIST> m_graphExist;//����ͼԪ�����Ƿ��������
			vector<_D_RECT> m_graphRect_reg;//��ͼԪ��Χ...
			vector<GM_GRAPH_EXIST> m_graphExist_reg;//��ͼԪ�����Ƿ��������

			vector<GM_PNT_INFO> m_pntInfo;//����Ϣ
			vector<_D_DOT> m_pntsCoord;//�������б�
			vector<string> m_pntStrBuf; //����ַ����б�(n*128bytes)

			vector<GM_LIN_INFO> m_linInfo;//����Ϣ
			vector<vector<_D_DOT>> m_linsCoord;//�������б�

			vector<GM_REG_INFO> m_regInfo;//����Ϣ
			vector<GM_REG_SEG> m_regData; //�����б�
			vector<GM_LIN_TOP>  m_regLinsTop; //���е�������
			vector<GM_LIN_NODE>	m_regLinsNode;//���е��߽ڵ���Ϣ

			//��/�ߵ����Խṹ
			GM_ATTRTBL_HEAD m_vecAttTblHead; //���������Ա�ͷ��Ϣ
			vector<GM_Fld_DEF> m_vecFldStru; //�������ֶζ�����Ϣ
			gmeFields		m_attStru;
			gmeRecordSet	m_attRcdSet;

			//�����Խṹ...
			GM_ATTRTBL_HEAD m_vecAttTblHead_reg; //���������Ա�ͷ��Ϣ
			vector<GM_Fld_DEF> m_vecFldStru_reg; //�������ֶζ�����Ϣ
			gmeFields		m_attStru_reg;
			gmeRecordSet	m_attRcdSet_reg;

		private:
			fstream*	m_filePtr; //�ļ�ָ��...
			char*	m_pMemBuf;
		};




		class  S3DKERGIS_ADAPTER_EXP gm_mapgis_prj
		{
		public:
			gm_mapgis_prj();
			virtual ~gm_mapgis_prj();

		public:
			//���������ļ�
			void _PRJCreateProject(string prjname);
			//װ�빤���ļ�
			void _PRJLoadProject(string prjname);
			//�رչ����ļ�
			void _PRJCloseProject();
			//���湤���ļ�
			void _PRJSaveProject();

			//ȡ��·�����ļ���
			void _PRJGetPathName(string& pathname);
			void _PRJSetPathName(string& pathname);

			//ȡ����·�����ļ���
			void _PRJGetFileName(string& filename);
			void _PRJSetFileName(string& filename);

			//ȡ���̵�ͼ���ļ���
			int _PRJGetFileNum();
			void _PRJSetFileNum(long fileNum);

			//ȡ�����ļ��ĵ�ͼ����...
			GM_MAP_PARA& GetMapPara();
			void SetMapPara(GM_MAP_PARA& mappara);

			//��ȡ�����ļ��ķ�Χ
			void _PRJSetRange(_D_RECT *rc);
			void _PRJGetRange(_D_RECT *rc);

			//�򹤳������ͼ���ļ�...
			void _PRJAppend(string vecfname);
			void _PRJAppend(vector<string>& vecfname);
			string _PRJGetItem(int no, string& name); //no��0��ʼ
			void _PRJGetItem(vector<string>& name);
			gm_mapgis_vector* _PRJGetItem(int no); //no��0��ʼ
			vector<gm_mapgis_vector*>& _PRJGetItem();

		private:
			//�ͷŹ����ļ��е�ʸ��ͼ���б�
			void closeVecList();

		public:
			_PROJECTHEAD	m_prjHead; //�����ļ�ͷ...
			vector<gm_mapgis_vector*> m_layerList;

			string		m_strPath_File;//�����ļ���ȫ·���ļ���...
			string		m_strPath;	  //�����ļ���ȫ·��
			string		m_strFile;	  //�����ļ����ļ���
			string		m_strTitle;	  //�����ļ��ı���

		private:
			fstream*			m_filePtr; //�ļ�ָ��...
		};

		string S3DKERGIS_ADAPTER_EXP _pathChange(string input);
	}



#pragma pack(pop)
