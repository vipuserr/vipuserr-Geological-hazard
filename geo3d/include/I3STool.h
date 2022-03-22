#pragma once

#include "s3d_baseapplib_global.h"

#include <string>

#include "gmeMdl.h"

namespace Smart3dMap
{
	// slpk�ļ��Ŀռ�ο�����
	enum SLPK_SR
	{
		WGS84_4326, // ȫ�����γ����
		WGS84_3857, // ȫ��ī����ͶӰ����
		BeiJing54_118d30m // ����54�����뾭��118��30��
	};

	/*!
		\brief ����ת������ -- ���� -- ��Ҫʵ�ִ��麯����������任

		\log  -- LH.2022.03.02 15:21 commented.
	*/ 
	struct CS_transformation
	{
		virtual bool transform(gme_vector3d* points, size_t count) = 0;
	};

	template<class T>
	struct TifDataTemplate
	{
		std::vector<T> m_data; // ���ݾ���
		std::pair<int, int> m_w_h; // ���ݾ���� width �� height
		short channel; // ���ݾ�����һ��Ԫ�ذ����� T ���͵����ݵĶ���(�൱��λͼ��ͨ����������24λͼ��ͨ����Ϊ3����һ�����غ����������ֽ�����ֵ)

		std::pair<double, double> m_origin_xy; // ���Ͻ�ͶӰ����
		std::pair<double, double> m_origin_ll; // ���Ͻ�wgs84-4326��γ��(����)����
		std::pair<double, double> m_cell_size; // ���ؼ������ʵ�ʾ���(���Ƶ�λ)
	};
	typedef struct TifDataTemplate<double> DEMData; // channel must be 1.
	typedef struct TifDataTemplate<char> ImageData; // channel must be 3.
	
	class S3D_BASEAPPLIB_EXPORT I3STool
	{
	public:
		// ���ڲ��Եĺ�������ά���߲��ɵ���(��������һ��û������)��
		static int RunTest();
		
		/*!
			\brief gmeModelתi3s(slpk)�ӿ�

			\param gme_model ģ��
			\param slpk_path slpk�ļ��洢·��(�����ļ���׺��.slpk��)��
			\param err_str ת��δ�ɹ�ʱ�Ĵ�����Ϣ��

			\TODO ������������һ�����ذ汾
		*/
		static bool gmeModelToSLPK(const gmeModel* gme_model, const std::string &slpk_path, std::string *err_str = nullptr);
		
		/*!
			\brief gmeModelתi3s(slpk)�ӿ�

			\param gme_model ģ��
			\param slpk_path slpk�ļ��洢·��(�����ļ���׺��.slpk��)��
			\param slpk_sr slpk�ļ��ռ�ο�����
			\param transformation ʵ���� CS_transformation.transform(...) ����������ָ�룬���ڽ� gme_model �е�����ת��Ϊ���� slpk_sr ��������꣬Ϊ����ת����
			\param err_str ת��δ�ɹ�ʱ�Ĵ�����Ϣ��

			\TODO
				1. ĿǰgmeModel��֧�ֽṹ��ģ�͡������ģ�ͺ���ά����ģ�͡�
		*/
		static bool gmeModelToSLPK(const gmeModel* gme_model, const std::string &slpk_path, const SLPK_SR slpk_sr, CS_transformation *transformation = nullptr, std::string *err_str = nullptr);

		/*!
			\brief ���ݵ���ͼ����ɫͼ����slpk�ļ�

			\param dem_pic_path ����ͼ·��������ͼΪ16λ��png��ʽͼƬ���ҳ�����ȣ������������ɫͼ��1�����ء�
			\param horizontal_resolution ����ͼ��ˮƽ�ֱ���
			\param z_unit ����ͼ������ֵ��Ӧ�����Ƶ�λ(���磬0.1m/pixel)
			\param color_pic_path ��ɫͼ·������ɫͼΪrgba��ͨ��32λ��png��ʽͼƬ���ҳ�����ȣ���Ϊ2�ı�����
			\param slpk_path ���ɵ�slpk�ļ��ı���λ�á�
			\param err_str ת��ʧ�ܵĴ�����Ϣ��

			\note �����������̣���ͨ�ã�����
			\TODO: ֧��tiff��ʽ�ĵ���ͼ��֧�ֳ�����ȵ�ͼƬ��֧�ֳ�������2�ı�����ͼƬ��
		*/
		static bool rasterToSLPK(const std::string &dem_pic_path, const double horizontal_resolution, const double z_unit, const std::string &color_pic_path, const std::string &slpk_path, std::string *err_str = nullptr);
		
		/*!
			\brief ���ݵ���ͼ���ݺ���ɫͼ��������slpk�ļ�(�������ⲿ���н����õ�)

			\param size_w_h ����ͼ�ĳߴ�(w=width, h=height)
			\param dem_data ����ͼ�ĸ߳����ݡ�
			\param horizontal_resolution ����ͼ��ˮƽ�ֱ���
			\param color_data ��ɫͼ���ݣ�Ҫ��ÿ������Ϊ��ͨ��24λ(3Byte)������ͼƬ�ߴ��w��h���ȵ���ͼ�ߴ���1�����ء�
			\param slpk_path ���ɵ�slpk�ļ��ı���λ�á�
			\param err_str ת��ʧ�ܵĴ�����Ϣ��

			\note δ���ԣ�����
			\TODO: ֧��tiff��ʽ�ĵ���ͼ��֧�ֳ�����ȵ�ͼƬ��֧�ֳ�������2�ı�����ͼƬ��
		*/
		//static bool rasterToSLPK(const std::pair<int, int> &size_w_h, const std::vector<double> &dem_data, const double horizontal_resolution, const std::vector<char> &color_data, const std::string &slpk_path, std::string *err_str = nullptr);
		
		// TODO: ʵ�ַ����㷨����ʹ�� -- LH.2021.02.25 15:51 recorded.
		static bool rasterToSLPK(const DEMData &dem_data, const ImageData &color_data, const std::string &slpk_path, std::string *err_str = nullptr);

	private:
	};
}

