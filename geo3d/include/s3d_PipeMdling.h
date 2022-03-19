#pragma once

#include "s3d_KerPipeMdlDef.h"

#include "s3d_KerGeomodelDef.h"
#include "s3d_KerAuxDef.h"
#include "s3d_SimpleMesh.h"
#include "s3d_IteratorWrapper.h"




namespace Smart3dMap
{
	enum GM_ModelType
	{		
		MT_DIRECT =1,	//不光滑
		MT_SMOOTH =2 //光滑
	};	
	enum GM_CornerType //光滑类型
	{
		CN_DEGREE = 1,// base on the 'separate Degree' to build the smooth corner
		CN_SECNUM = 2// base on 'the number of the sect' to build the smooth corner 
	};

	class _Ray
	{
	protected:
		gme_vector3d mOrigin;
		gme_vector3d mDirection;

	public:
		_Ray() {}
		virtual ~_Ray() {}

		/** Sets the origin of the ray. */
		void setOrigin(Real x, Real y, Real z) {
			mOrigin.x = x; mOrigin.y = y; mOrigin.z = z;
		}
		/** Gets the origin of the ray. */
		const gme_vector3d& getOrigin(void) const { return mOrigin; }

		/** Sets the direction of the ray. */
		void setDirection(Real x, Real y, Real z) { mDirection.x = x; mDirection.y = y; mDirection.z = z; }
		/** Gets the direction of the ray. */
		const gme_vector3d& getDirection(void) const { return mDirection; }

		/** Gets the position of a point t units along the ray. */
		gme_vector3d getPoint(Real t) const {
			return gme_vector3d(mOrigin + (mDirection * t));
		}
	};

	class _Plane
	{
	public:
		_Plane();
		_Plane(const gme_vector3d& rkNormal, const gme_vector3d& rkPoint)
		{
			normal = rkNormal;
			d = -rkNormal.dot(rkPoint);
		}

		enum Side
		{
			NO_SIDE,
			POSITIVE_SIDE,
			NEGATIVE_SIDE
		};

		gme_vector3d normal;
		Real d;
	};

	class LIB_S3DKERPIPEMDL_EXP gm_pipe_Modeling
	{
	public:
		typedef std::vector<SuperMesh*> SuperMeshList;
		typedef VectorIterator<SuperMeshList> SuperMeshIterator;

		gm_pipe_Modeling();
		virtual ~gm_pipe_Modeling();

		// clear the pipeline parameter
		void clearAll();

		//	set the colour for every piece of the pipeline
		void addCol(ColourValue& col);
		void addCols(ColourValue* cols, long num);

		// set the center line of the pipeline by every points in it
		void addPnt(gme_vector3d& pnt);
		void addDouPnt(gme_vector3d& pnt);
		void addPnts(gme_vector3d* pnts, long num);
		void addDouPnts(gme_vector3d* pnts, long num);
		gme_vector3d getOffsetPnt();

		// set the section of the three-dimensional pipeline
        void addSection(gme_vector2f* point2D, long* ne, long cirNum);
		void setCentPnt(gme_vector2f centPnt);
		float getRadius();

		// set the ratio of the pipeline
		void addRatio(long pecNum, double* segPec);

		// set the basic pipeline info, it refers to the vision effect
		void setBegin(BOOL isBegin);
		void setEnd(BOOL isEnd);
		void setIndex32(BOOL isIndex32);
		void setDouSide(BOOL isDou);
		void setEveryCover(BOOL isCover);
		void setFaceVector(BOOL isFaceVector);

		void setCorner(GM_CornerType crntype, double crnPara);

		void build(GM_ModelType modType);

		//	get the iterator of the pipe model
		SuperMeshIterator getSubMeshIterator(void)
        { 
			return SuperMeshIterator(m_SupMshlist.begin(), m_SupMshlist.end()); 
		}

		// the private function
	private:
		// build the pipeline directly
		void _createDirPipe(int num);

		gme_vector3d _createDirNormal(int num);

		void _createDirBody(SuperMesh* super, int num);

		void _AvgDirBody(OGSimpleMesh* single, _Plane& secPlane, int num, bool Out);
		// add the index buffer using average vector
		void _addIndex16(OGSimpleMesh* single, int pipeNum, bool Out);
		void _addIndex32(OGSimpleMesh* single, int pipeNum, bool Out);
		
		
		// build the pipeline smoothly
		void _createSmthPipe(int num);

		bool _calCornerInfo(int num, gme_vector3d& Opnt, gme_vector3d& Lpnt, gme_vector3d& Rpnt, double& halfDeg);
		void _createCorner(OGSimpleMesh* single, gme_vector3d& Opnt, gme_vector3d& beginPnt, gme_vector3d& endPnt, double& halfDeg, bool Out);
		void _insertSection(OGSimpleMesh* single, Quaternion& quat, gme_vector3d& beginPnt, gme_vector3d& Opnt,
			bool Out, bool isRecord);

		void _creatSmthBody(SuperMesh* super, gme_vector3d& beginPnt, gme_vector3d& endPnt, gme_vector3d& secNormal, int num);
		void _SmthDirBody(OGSimpleMesh* single, _Plane& secPlane, gme_vector3d& headCen, gme_vector3d& tailCen, gme_vector3d& dir, double currRatio, bool Out);

		// build the pipeline by the face normal
		void _FaceBody(OGSimpleMesh* single, _Plane& secPlane, gme_vector3d& cenPnt, gme_vector3d& dir, bool Out, double currRatio);
		void _FaceHeadBody(OGSimpleMesh* single, gme_vector3d& cenPnt, bool Out);
		void _FaceTailBody(OGSimpleMesh* single, _Plane& secPlane, gme_vector3d& cenPnt, gme_vector3d& dir, bool Out, double currRatio);

		// add the index buffer using face normal
		void _addFaceIndex16(OGSimpleMesh* single, int pipeNum, bool Out);
		void _addFaceIndex32(OGSimpleMesh* single, int pipeNum, bool Out);
		
		// calculate the first section
		void _initSection(gme_vector3d& cenPnt, gme_vector3d& normal);

		// make the section close
		void _createCover(SuperMesh* super, int currNum, bool Out);

		// the method about the section setting
		void _G3DXChangeOrder(gme_vector2d *lpDot, long *ne, long nCir);
		long _G3DXTriangleDissect(gme_vector2d *lpDot, long *ne, long nCir, Triangle32 **pMcseq, long *nSeq);
		long _G3DXTriangle16Dissect(gme_vector2d *lpDot, long *ne, long nCir, Triangle16 **pMcseq, long *nSeq);
        void _G3DXFreeTriangleBuf(Triangle32 **pMcseq);
		void _G3DXFreeTriangle16Buf(Triangle16 **pMcseq);
		template<class T> void InvertTypeSet(T *Set, long SetNum);

		bool _G3DVertexEqual(gme_vector3d fntPnt, gme_vector3d backPnt);

		// the private parameter
	private:
		typedef std::vector<gme_vector3d> PointList;
		typedef std::vector<ColourValue> ColorList;
		typedef std::vector<double> RatioList;

		typedef std::vector<Triangle32> Tri32List;
		typedef std::vector<Triangle16> Tri16List;
 
		SuperMeshList m_SupMshlist;

		ColorList	m_Colorlist;
		ColourValue m_currCol;
		
		PointList	m_Pointlist;
		gme_vector3d m_OffsetPnt;

		gme_vector3d*    m_pCurrPnt;
		
		gme_vector2d*  m_pSecDotList;
		long*   m_pNeList;
		gme_vector2f m_CenPnt;
		int		m_CirNum;
		float	m_Radius;
		int		m_SecNum;
		bool	m_bSetCent;

		Tri32List m_Tri32list;
		Tri16List m_Tri16list;

		RatioList m_Ratiolist;
		
		BOOL m_bBegin;
		BOOL m_bEnd;
		BOOL m_bIndex32;
		BOOL m_bFaceVector;
		BOOL m_bDoubleSide;
		BOOL m_bSegCover;

		GM_ModelType  m_modelType;
		GM_CornerType m_crnType;
		double	   m_crnPara;
		
		// the first ratio parameter
		double  m_dFstRatio;
		// the smooth modeling parameters
		bool	m_bHeadBld;
		gme_vector3d m_headBackPnt;
		gme_vector3d m_headFntPnt;
		double  m_headDeg;
		gme_vector3d m_Opnt;
	};	

	//返回0表示三点共线，非0表示不共线（2D)
	double LIB_S3DKERPIPEMDL_EXP _Judg2DPntPos(double *pa, double *pb, double *pc);
}
