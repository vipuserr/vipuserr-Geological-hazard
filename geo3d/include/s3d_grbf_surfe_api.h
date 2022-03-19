#ifndef SURFE_API
#define SURFE_API

#include <Eigen/Core>

#include "s3d_KerInterpRBFDef.h" 
#include <s3d_grbf_modelling_parameters.h>


class GRBF_Modelling_Methods;


class  LIB_S3DKERINTERPRBF_EXP Surfe_API {
private:
	// members
	GRBF_Modelling_Methods *method_;

	bool have_interpolant_;
	bool parameters_changed_;
	bool constraints_changed_;

	// methods
	GRBF_Modelling_Methods* get_method_from_parameters(const Parameters_& params);

public:
	Surfe_API(const int &modelling_method);//���ý�ģ����
	Surfe_API(const Parameters_& params);
	
	// Manually (no input files) adding constraints to interpolant methods
	//��ӵ���Լ��
	void AddInterfaceConstraint(
		const double &x, const double &y, const double &z,
		const double &level
	);
	void AddPlanarConstraintwNormal(
		const double &x, const double &y, const double &z,
		const double &nx, const double &ny, const double &nz
	);
	void AddPlanarConstraintwStrikeDipPolarity(
		const double &x, const double &y, const double &z,
		const double &strike, const double &dip, const int &polarity
	);
	void AddPlanarConstraintwAzimuthDipPolarity(
		const double &x, const double &y, const double &z,
		const double &azimuth, const double &dip, const int &polarity
	);
	void AddTangentConstraint(
		const double &x, const double &y, const double &z,
		const double &tx, const double &ty, const double &tz
	);
	void AddInequalityConstraint(
		const double &x, const double &y, const double &z,
		const double &level
	);
	//�����ֵ
	void ComputeInterpolant();

	void SetRegressionSmoothing(const bool &use_regression_smoothing, const double &amount);//���ÿ��ЧӦ
	void SetGreedyAlgorithm(const bool &use_greedy, const double &interface_uncertainty, const double &angular_uncertainty);//����̰���㷨��only single surface
	void SetRestrictedRange(const bool &use_restricted_range, const double &interface_uncertainty = 0, const double &angular_uncertainty = 0);//�������Ʒ�Χ
	void SetRBFKernel(const Parameter_Types::RBF &rbf);//���û�����
	void SetRBFKernel(const char *rbf_name);//���û�����
	void SetRBFShapeParameter(const double &shape_param);//for SPD ����������Ҫ������״����
	void SetPolynomialOrder(const int &poly_order);//���ö���ʽ����
	void SetGlobalAnisotropy(const bool &g_anisotropy);//����ȫ�ָ�������

	//��ȡ��ֵ������һ���ֵ
	//������
	double EvaluateInterpolantAtPoint(
		const double &x, const double &y, const double &z
	);
	//��ȡ��ֵ������һ���ʸ��
	//�ݶȳ�
	Eigen::Vector3d EvaluateVectorInterpolantAtPoint(
		const double &x, const double &y, const double &z
	);
	//��ȡ�ռ����
	//��Χ�м��ֱ���
	SpatialParameters GetDataBoundsAndResolution();

	// Array of interface reference points: 1 per interface. 
	// n x 3 matrix, n = number of interfaces 
	//����ο���
	Eigen::MatrixXd GetInterfaceReferencePoints();

	// Array of interface constraints
	// n x 4 matrix, n = number of interface points
	// columns: x, y, z, level
	// level: structural levels (interface codes)
	Eigen::MatrixXd GetInterfaceConstraints();
	void SetInterfaceConstraints(const Eigen::MatrixXd &interface_constraints);

	// Array of planar constraints
	// n x 6 matrix, n = number of planar points
	// columns: x, y, z, nx, ny, nz
	// nx, ny, nz : components of the normal vector
	Eigen::MatrixXd GetPlanarConstraints();
	void SetPlanarConstraints(const Eigen::MatrixXd &planar_constraints);

	// Array of tangent constraints
	// n x 6 matrix, n = number of tangent points
	// columns: x, y, z, vx, vy, vz
	// vx, vy, vz : components of the tangent vector
	Eigen::MatrixXd GetTangentConstraints();
	void SetTangentConstraints(const Eigen::MatrixXd &tangent_constraints);

	// Array of inequality constraints
	// n x 4 matrix, n = number of inequality points
	// columns: x, y, z, level
	// level: structural level (compatible with interface level codes)
	Eigen::MatrixXd GetInequalityConstraints();
	void SetInequalityConstraints(const Eigen::MatrixXd &inequality_constraints);

	int GetNumberOfInterfaces();

	bool InterpolantComputed() const { return have_interpolant_; }

};

#endif // SURFE_API
