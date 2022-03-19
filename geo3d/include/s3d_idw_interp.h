#ifndef _GM_IDW_INTERP_H
#define _GM_IDW_INTERP_H

#include "s3d_KerInterpIDWDef.h"
#include "gmeMdl.h"
#include "s3d_MeshIdxTbl.h"

using namespace Smart3dMap;

namespace Smart3dMap
{
	typedef struct Interp2SampDotDist
	{
		gme_vector3d*	sampleDot;//������
		double			distSqure; //�������������ľ��뷽
	}Interp2SampDotDist;

	typedef struct IdxBlockInfo //�����������
	{
		vector<gme_vector3d*>	sampleDot; //�������ݿ��е�������
	}IdxBlockInfo;

	//��ֵ�࣬Ϊ���ύ����Ч�ʣ��ᱸ���м����
	class LIB_S3DKERINTERPIDW_EXP gm_idw_interp
	{
	public:
		gm_idw_interp();
		~gm_idw_interp();

	public:
		//���ò�ֵ����, adjPntCls--�����β�ֵ���е��ڽ������μ���.
		void setInterpParam(long searchDotNum = 3, vector<gme_vector3d>* interpRgn=nullptr, double insertX=100, double insertY=100, char distPower = 2, char adjPntCls=1);
		//��������������
		void setSampDots(gme_vector3d* sampDots, long sampDotsNum);

		//�����ֵ interpType��־��ֵ�������ͣ�0--��ͨIDW��ֵ����1--�����β�ֵ��;
		double interpolate1Dot(gme_vector3d* interpDot, char interpType = 0);
		//ȫ�����ֵ
		vector<gme_vector3d>* interpolateAllDots(vector<gme_vector3d>* interpDots=nullptr, char interpType = 0, gmeSurface* interpSurf = nullptr, vector<gme_vector3d>* surfBound=nullptr);
		//ȡ����Χ��
		gme_rect_3d* getInterpBox();
		//ȡ���߽�
		vector<gme_vector3d>* getInterpRgn();
		//��ջ���
		void clearBuffer();

	private:
		//���ò�ֵ��
		void setInterpDots(vector<gme_vector3d>* interpDots, char interpType);

		//������ֵ��ģ����...
		void createTmplateSurf();

		//�������������...
		void calInterpDotsIdx();

		//����1��ֱ�Ӹ���idw�������в�ֵ
		//���ݴ�����������������ڵ��������.
		void calInterpDotIdxBlockNo(gme_vector2d* interpDot, long& idxBlockXNo, long& idxBlockYNo);
		//�����������ݵ��������
		void buildIndexTbl();
		//�������������������㣬���ص�ǰ�յ��ĵ���
		long searchSampIn_A_Block(gme_vector2d& curInterpDots, double idxNoX, double idxNoY, vector<Interp2SampDotDist>& distList);
		//�������������������Z��ֵ
		void interpSampDot(gme_vector2d& curInterpDots, vector<Interp2SampDotDist>& distList, double& dZ);

		//����2���Ƚ���ɢ��������������ʷ֣�Ȼ���ڸ���n-��������������idw��ֵ


	private:
		double			m_insertX, m_insertY;//�����ļ��
		char			m_adjPntCls; //���������������ļ���
		long			m_searchDotNum;//��������������
		char			m_distPower;   //IDW��ָ��,Ĭ��2��
		vector<gme_vector3d>* m_oriInterpRgn;//��ֵ�Ķ���η�Χ
		vector<gme_vector3d> m_interpRgn;//��ֵ�Ķ���η�Χ
		gme_rect_3d		m_dotsBox; //���ݵİ�Χ��

		gme_vector2d		m_idxBlockStep;	//������Ĵ�С
		gme_vector2i		m_idxBlockNum;	//XY�����ϵ���������Ŀ

		vector<gme_vector3d> m_SampDots;      //������
		vector<gme_vector3d> m_interpDots;	 //�����
		vector<vector<IdxBlockInfo>> m_blockIdxTbl;//�����ݵ�������
		gmeSurface			m_idwSurf; //��ʼ�����㹹��������������...
		long				m_gridXNum, m_gridYNum; //x/y�����ϵ�������
		s3d_TriMeshIdxTbl*	m_triIdxTbl; //��������������...
	};
}

#endif _GM_IDW_INTERP_H