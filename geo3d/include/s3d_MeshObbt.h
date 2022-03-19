//计算点集包围盒（方向包围盒与轴向包围盒）
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
		// ----------------- 建立网格的Smart3dMap树 -------------------- //
		void	BuildMeshObbt(gme_vector3d *pTinPnt, long lPntNum, gme_triangle *pTinNet, long lNetNum);
		// 取出模型的方向包围盒
		void	GetObbOfModel(gme_vector3d* pBoxCenter, double *pAxisLen, gme_vector3d* pAxisXYZ);
		// 取出方向包围盒的8个顶点(上顶面4个顶点--->下顶面4个顶点)   
		// 备注：此函数主要用于三维数据的方向包围盒求取，对于二维数据只需使用前4个顶点即可（舍弃Z坐标）
		void	Get8VertexOfOBB(gme_vector3d pVertex[8]);
		void	GetAABB(gme_rect_3d* aabb);
		Obbt_Obj getObbtObj() { return m_obbtObj; }



	protected:
		//创建  mesh 的OBBT
		void	BuildMeshObbt(OGSimpleMesh* pSurface);
		//pTris：每个三角形的三个顶点坐标(9个double)
		long	BuildMeshObbt(const double *pTris, long lTriNum);
		long	BuildMeshObbt(const double *pTrisDot1, const double *pTrisDot2, const double *pTrisDot3, long lTriNum);
		// ----------------- 建立离散点的Smart3dMap树 -------------------- //
		//没相邻的三个点构成一个三角形...
		long	BuildDiscDotsObbt(const double *pDots, long lDotsNum);

		//取出Smart3dMap树中的三角形数
		//返回值：成功返回三角形数，失败返回-1.
		long	GetTriNumFromObbt();

		// -------------------- Smart3dMap树中取出三角形数据 --------------------- //
		//参数: 
		//		pTriDots -------> 三角形的顶点数据(3个gme_vector3d顶点)
		//		lTriNo ---------> 三角形编号
		//返回值：无返回值.
		void	GetTriDotFromObbt(gme_vector3d *pTriDots, long lTriNo);

		void	Get4VertexOfOBB(gme_vector3d pVertex[4]);
		//向Smart3dMap树中添加三角形
		long	Add1TriToObbt(const double *Pnt1, const double *Pnt2,
			const double *Pnt3, long lTriNo);
		//检查输入数据的正确性，正确返回1 错误返回0 
		long	CheckMesh();
		void	CalMeshAABB();
		//创建Smart3dMap树对象...
		void	CreateObbtObj();
		//释放Smart3dMap树对象...
		void	DeleteObbtObj();
		//建立Smart3dMap树
		long	BuildObbt();



	private:
		Obbt_Obj					m_obbtObj;
		OGSimpleMesh				m_simpMesh;        // 原始模型 
		gme_rect_3d					m_meshBox;		   // 模型的轴向包围盒
		vector<CollisionTriPair>	m_triPairs;
	};

	//检测两个方向包围盒是否发生碰撞，返回值：0——不碰撞，1——碰撞
	//triPairs为发生碰撞的相交三角形对
	bool LIB_GMKEROBBT_EXP collideDetect(CMeshObbt& obj1, CMeshObbt& obj2, vector<CollisionTriPair>& triPairs);

	LIB_GMKEROBBT_EXP void* G3DXGetOBB(gmeSurface* pSurf);
	LIB_GMKEROBBT_EXP void	G3DXReleaseOBB(void* p);
}