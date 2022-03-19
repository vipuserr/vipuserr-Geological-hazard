#pragma once

#include <s3d_KerMathDef.h>

#include <QThread>
#include <flann/flann.hpp>
#include <Eigen/Core>
#include <Eigen/Dense>

#include <gme_Ref.h>
#include <osg/Vec3d>
#include <s3d_Math.h>
#include "gme_vector2.h"
#include "gme_vector3.h"
#include "gme_vector4.h"
#include <s3d_BndingBox.h>

namespace Smart3dMap
{
	enum enum_CzqType
	{
		TYPE_IDW = 0,
		TYPE_KRIGING = 1,
		TYPE_IDWEX = 2,
		TYPE_KRIGINGEX = 3,
		TYPE_NEAREST = 4,
		TYPE_RBF = 5,
		TYPE_RBFEX = 6,
		TYPE_HRBF = 7
	};

	class LIB_GMKERMATH_EXP FLANN_KdTree
	{
	public:
		FLANN_KdTree();
		~FLANN_KdTree();
		const int ndem = 3; //维度

		void InitTree(const QList<gme_vector4d> &atts);
		void Search(gme_vector3d pos, int nk, QList<gme_vector4d>& out, vector<long>* dotIdx = nullptr);
		void Search(gme_vector3d pos, float radius, QList<gme_vector4d> &out, vector<long>* dotIdx = nullptr);

	private:
		QList<gme_vector4d>              m_pAtts;
		flann::Matrix<double>*           m_dataset;
		flann::Index<flann::L2<double>>* m_pIndex;
	};

	class LIB_GMKERMATH_EXP Interpolater : public s3d_Ref
	{
	public:
		Interpolater();
		~Interpolater();

		virtual void AddSourcePnt(const gme_vector4d &pt);
		virtual void SetSourcePnts(const QList<gme_vector4d>& list);
		virtual void GetIpVal(gme_vector4d &pos) {}
		virtual void ClearSourcePnt();
		bool         CheckTarget(gme_vector4d& target);
		long	 GetNumSourcePnt();
		BoundingBox  GetInputBoundBox();
		QList<gme_vector4d>  GetSourceArray() { return m_sdata; }
	protected:
		QList<gme_vector4d>    m_sdata;      //源数据
	};

	class LIB_GMKERMATH_EXP IDW : public Interpolater
	{
	public:
		IDW();
		virtual void SetSourcePnts(const QList<gme_vector4d>& list);
		virtual void GetIpVal(gme_vector4d &pos);
		void	 SetBetaVal(double dbeta) { m_beta = dbeta; }

	protected:
		double                  m_beta;
	};
	class LIB_GMKERMATH_EXP IDWEX : public IDW
	{
	public:
		IDWEX();
		virtual void SetSourcePnts(const QList<gme_vector4d>& list);
		void         SetSearchNum(const int &nSearchNum);
		void         SetSearchDistance(const double &dDistance);
		virtual void GetIpVal(gme_vector4d &pos);

	protected:
		FLANN_KdTree            m_pkd;
		int                     m_nSearch;
		float                   m_dDistance;
	};

	//简单克里金插值
	class LIB_GMKERMATH_EXP Kriging : public Interpolater
	{
	public:
		Kriging();
		virtual void SetSourcePnts(const QList<gme_vector4d>& list);
		virtual void GetIpVal(gme_vector4d &pos);
		void         SetSemivariance(const int &nSemivariance);

	protected:
		void         CalMatrixKn(QList<gme_vector4d> &list);
		double       CalCij(const gme_vector4d &pos1, const gme_vector4d &pos2);
		void         CalVal(gme_vector4d &pos, QList<gme_vector4d> &list);
	protected:
		Eigen::MatrixXd         m_Kn;
		Eigen::VectorXd         m_D;
		int                     m_Semivariance; //克里金参数
	};
	class LIB_GMKERMATH_EXP KrigingEx : public Kriging
	{
	public:
		KrigingEx();
		void         SetSearchNum(const int &nSearchNum);
		void         SetSearchDistance(const double &dDistance);
		virtual void SetSourcePnts(const QList<gme_vector4d>& list);
		virtual void GetIpVal(gme_vector4d &pos);

	protected:
		FLANN_KdTree            m_pkd;
		int                     m_nSearch;
		float                   m_dDistance;
	};

	class LIB_GMKERMATH_EXP Nearest : public Interpolater
	{
	public:
		Nearest();
		virtual void SetSourcePnts(const QList<gme_vector4d>& list);
		virtual void GetIpVal(gme_vector4d &pos);

	protected:
		FLANN_KdTree            m_pkd;
	};

	class LIB_GMKERMATH_EXP NumCzq :public s3d_Ref
	{
	public:
		NumCzq(int cztype = TYPE_IDW, bool bIsNormalized = true);
		~NumCzq();
		static int  SelectCzqType();
		Interpolater* GetCzq();
		virtual void  SetPntSource(QList<gme_vector4d> points);
		virtual void  SetPntSource(QList<gme_vector3d> points);
		virtual void  SetPntSource(QList<gme_vector2d> points);
		virtual void  GetPntCz(gme_vector4d &pnt);
		virtual void GetPntCz(gme_vector3d &pnt);
		virtual void GetPntCz(gme_vector2d &pnt);

	protected:
		void     GetCPUCount();

	private:
		void     CreateCzq(int type);

	protected:
		       
		int                         m_ntype;
		int                         m_ProcessNum;
		int                         m_CzCount;
		int                         m_totalCount;
		gme_vector3d                m_dMaxPos;
		gme_vector3d                m_dMinPos;
		gme_vector3d                m_dInvPos;
		Interpolater*               m_pIp;
		bool                        m_bIsNormalized;
	};
	
}
