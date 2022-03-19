//����㼯��Χ�У������Χ���������Χ�У�
#pragma  once

#include "s3d_KerObbtDef.h"

//#include "s3d_MathDef.h"
#include "s3d_SimpleMesh.h"
#include "gmeMdl.h"

namespace  Smart3dMap
{
	typedef class RAPID_model*  Obbt_Obj;

	typedef struct CollisionTriPair
	{
		long	lTriNo1, lTriNo2;
	}CollisionTriPair;



	class LIB_GMKEROBBT_EXP  CMeshObbt
	{
	public:
		CMeshObbt();
		~CMeshObbt();

	public:
		// ----------------- ���������Smart3dMap�� -------------------- //
		void	BuildMeshObbt(gme_vector3d *pTinPnt, long lPntNum, gme_triangle *pTinNet, long lNetNum);
		// ȡ��ģ�͵ķ����Χ��
		void	GetObbOfModel(gme_vector3d* pBoxCenter, double *pAxisLen, gme_vector3d* pAxisXYZ);
		// ȡ�������Χ�е�8������(�϶���4������--->�¶���4������)   
		// ��ע���˺�����Ҫ������ά���ݵķ����Χ����ȡ�����ڶ�ά����ֻ��ʹ��ǰ4�����㼴�ɣ�����Z���꣩
		void	Get8VertexOfOBB(gme_vector3d pVertex[8]);
		void	GetAABB(gme_rect_3d* aabb);
		Obbt_Obj getObbtObj() { return m_obbtObj; }



	protected:
		//����  mesh ��OBBT
		void	BuildMeshObbt(OGSimpleMesh* pSurface);
		//pTris��ÿ�������ε�������������(9��double)
		long	BuildMeshObbt(const double *pTris, long lTriNum);
		long	BuildMeshObbt(const double *pTrisDot1, const double *pTrisDot2, const double *pTrisDot3, long lTriNum);
		// ----------------- ������ɢ���Smart3dMap�� -------------------- //
		//û���ڵ������㹹��һ��������...
		long	BuildDiscDotsObbt(const double *pDots, long lDotsNum);

		//ȡ��Smart3dMap���е���������
		//����ֵ���ɹ���������������ʧ�ܷ���-1.
		long	GetTriNumFromObbt();

		// -------------------- Smart3dMap����ȡ������������ --------------------- //
		//����: 
		//		pTriDots -------> �����εĶ�������(3��gme_vector3d����)
		//		lTriNo ---------> �����α��
		//����ֵ���޷���ֵ.
		void	GetTriDotFromObbt(gme_vector3d *pTriDots, long lTriNo);

		void	Get4VertexOfOBB(gme_vector3d pVertex[4]);
		//��Smart3dMap�������������
		long	Add1TriToObbt(const double *Pnt1, const double *Pnt2,
			const double *Pnt3, long lTriNo);
		//����������ݵ���ȷ�ԣ���ȷ����1 ���󷵻�0 
		long	CheckMesh();
		void	CalMeshAABB();
		//����Smart3dMap������...
		void	CreateObbtObj();
		//�ͷ�Smart3dMap������...
		void	DeleteObbtObj();
		//����Smart3dMap��
		long	BuildObbt();



	private:
		Obbt_Obj					m_obbtObj;
		OGSimpleMesh				m_simpMesh;        // ԭʼģ�� 
		gme_rect_3d					m_meshBox;		   // ģ�͵������Χ��
		vector<CollisionTriPair>	m_triPairs;
	};

	//������������Χ���Ƿ�����ײ������ֵ��0��������ײ��1������ײ
	//triPairsΪ������ײ���ཻ�����ζ�
	bool LIB_GMKEROBBT_EXP collideDetect(CMeshObbt& obj1, CMeshObbt& obj2, vector<CollisionTriPair>& triPairs);

	LIB_GMKEROBBT_EXP void* G3DXGetOBB(gmeSurface* pSurf);
	LIB_GMKEROBBT_EXP void	G3DXReleaseOBB(void* p);
}