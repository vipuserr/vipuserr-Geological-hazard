#pragma once
#include <vector>
using namespace std;

#include <s3d_KerAttMdlExp.h>
#include <s3d_KerAttStruDef.h>
#include <gmeEntity.h>

namespace Smart3dMap 
{
	//�������ݷ����ࣺ����ȡ��ԭʼ���ݽ��з�������
	class LIB_S3DKERATTMDL_EXP attAnalyCls
	{
	public:
		attAnalyCls(void);
		~attAnalyCls(void);
	public:
		//�����������ݣ����ز�����+�ռ�����
		int  loadSampleDots(vector<attDataStru>  &sampledots);

		//��ȡ�ز��Ӧ����������
		int  GetLayerDatas(string &stratcode, vector<gme_vector4d> &sampledots);

		//��ȡ�ز��Ӧ����������
		int  GetAllLayerDatas(map<string, vector<gme_vector4d>> &sampledots);

	private:
		//���ñ��룬����������
		int  ClassifyDatasByLayer();

	private:
		vector<attDataStru>               *  m_pAllSampDots;   //�������������...
		map<string, vector<gme_vector4d>>    m_strToD4dotsMap; //�ز��Ӧ������...
	};

	//�������ݴ���
	class LIB_S3DKERATTMDL_EXP attCreateCls
	{
	public:
		attCreateCls();
		~attCreateCls();

	public:
		// װ�ؽṹ��ģ�ͣ��ز���� ӳ�� �ṹģ��
		int setMdlParam(attMdlParam &param);
		//����ģ�͵�box
		void setMdlBox(gme_rect_3d& mdlBox);

		//���ñ�׼�ز��Ӧ�����
		void setStdStrat(map<string, int>& basLayersVec);

		// װ����������
		int loadSampleDatas(map<string, vector<gme_vector4d>> &sampledots);

		// һ��װ�����еز���ģ��
		int loadGeoEntity(map<string, vector<gmeEntity*>> &allStratMdl);
		// ��ӵز���ģ��
		int add1GeoEntity(string stratCode, vector<gmeEntity*>& stratMdl);

		// ������ά����ģ��
		int Create3dGridMdl();

		// �жϸ����ز����ԡ������������ֵ
		int Cal3dGridAttVal();

	public:
		//���ṹģ��դ�񻯺����������������
		void geoStruMdl2CSV(string &filepath, bool isOptInvalid = true);
		void geoStruMdl2VTK(string &filepath, bool isOptInvalid = true);

		//�����������Ϊ�ļ���ʽ...XYZ��IJK��size(X)��size(Y)��size(Z)��attVal����ṹģ�͵�csv�ļ���isOptInvalid:�Ƿ������Чֵ
		//����ṹģ�͵�����...
		int GeoStruMdl2CSV(string &filepath, bool isOptInvalid = true);
		int GeoStruMdl2VTK(string &filepath, bool isOptInvalid = true);
		//�������ģ�͵�csv/vtk�ļ�
		int GeoAttMdl2CSV(string &filepath, bool isOptInvalid = true);
		int GeoAttMdl2VTK(string &filepath, bool isOptInvalid = true);
		int GeoAttMdl2CSV(string& filePath, long * pXNum, long * pYNum, long * pZNum,
			gme_vector3d * pXYZGap, gme_vector3d  *  pMinPnt,
			vector<double>* pAttValues, bool isOptInvalid = true);
		int GeoAttMdl2VTK(string& filePath, long * pXNum, long * pYNum, long * pZNum,
			gme_vector3d * pXYZGap, gme_vector3d  *  pMinPnt,
			vector<double>* pAttValues, bool isOptInvalid = true);

		// ������������ڴ����ݼ�
		int OutPutAttMdlDatas( gme_rect_3d  * pMdlBox, long * pXNum, long * pYNum, long * pZNum,
			                     gme_vector3d * pXYZGap, gme_vector3d  *  pMinPnt, 
			                     gme_vector3d * pMaxPnt, vector<double>** pAttValues);

		//����ÿ����Ԫ���Ӧ�ĵز����
		void getAttrValsCode(vector<string>& stratCodes);


	private:
		// ��ȡrect3d
		int   CalEntityRect3d();

		// ��ʼ����������
		int   init3dGridParam();

		// �Ը������ݽ�������任...
		int   TransLateGridDatas();

		// �Ը������ݽ�������任���任...
		int   ReTransLateGridDatas();

		// ��ȡ�����������ݣ��ϲ���һ������
		int   GetAllSampleDots();
		
		// ������ʵ��λ�ù�ϵ�ж�
		int   CaluGridStrCode( short strcode, gmeEntity * pEnty, gme_vector3d &dot,
			                   double &dx, double &dy, bool &bdxy);

		// ����任ϵ��
		int   CaluTransCof(gme_vector3d &centerdot, double &dx, double &dy, bool &bdxy);

		// ��ʼ�����ݱ�ͷ
		void  initFileCSVHead(vector<string> &vec);

	private:
		vector<gme_vector4d>                    m_allSamples;  // ������������
		map<string, vector<gme_vector4d>>     * m_pSampleDots; // �������ݼ���...

		gme_rect_3d                             m_MdlBox;    // �ṹģ����ά�������
		attMdlParam                             m_mdlParam;  // ��ά���Ը�����ģ����
		vector<string>                          m_StrCode;   // �ز�����б�
		map<string, short>                      m_StrIndex;  // �ز����������ʼ��0
		map<short, string>                      m_ShortIdx;  // �ز����������ʼ��0
		map<gmeEntity*, gme_rect_3d>            m_EntyRect;  // ÿ���ز����Ӧ���������
		map<string, vector<gmeEntity*>>         m_EntyModel; // װ�صز���ģ��

		int                                     m_xNum;        // X���������Ŀ
		int                                     m_yNum;        // Y���������Ŀ
		int                                     m_zNum;        // Z���������Ŀ
		gme_vector3d                            m_dGap;        // xyz��������Ĳ���
		gme_vector3d                            m_minPnt;      // ��С���ĵ�
		gme_vector3d                            m_maxPnt;      // ������ĵ�
		vector<char>                            m_attFlgs;     // XYZ������������Ӧ�ĵ���
		vector<double>                          m_attVals;     // XYZ������������Ӧ�ĵ�����
		vector<string>							m_attValsCode; // XYZ������������Ӧ�ĵ��Ӧ�ĵز����
		vector<attIndex>                        m_vecIndex;    // XYZ����������
		vector<gme_vector3d>                    m_vecDots;     // XYZ������������Ӧ�ĵ�����
		
		map<string, int>						m_basLayersVec; //��׼�ز����

	};
}