#pragma once

#include "s3d_baseapplib_global.h"

#include <string>

#include "gmeMdl.h"

namespace Smart3dMap
{
	// slpk文件的空间参考规则
	enum SLPK_SR
	{
		WGS84_4326, // 全球地理经纬坐标
		WGS84_3857, // 全球墨卡托投影坐标
		BeiJing54_118d30m // 北京54，中央经线118度30分
	};

	/*!
		\brief 坐标转换工具 -- 基类 -- 需要实现纯虚函数用于坐标变换

		\log  -- LH.2022.03.02 15:21 commented.
	*/ 
	struct CS_transformation
	{
		virtual bool transform(gme_vector3d* points, size_t count) = 0;
	};

	template<class T>
	struct TifDataTemplate
	{
		std::vector<T> m_data; // 数据矩阵
		std::pair<int, int> m_w_h; // 数据矩阵的 width 和 height
		short channel; // 数据矩阵中一个元素包含的 T 类型的数据的多少(相当于位图的通道数，比如24位图的通道数为3，即一个像素含有三个单字节整数值)

		std::pair<double, double> m_origin_xy; // 左上角投影坐标
		std::pair<double, double> m_origin_ll; // 左上角wgs84-4326经纬度(地理)坐标
		std::pair<double, double> m_cell_size; // 像素间距代表的实际距离(米制单位)
	};
	typedef struct TifDataTemplate<double> DEMData; // channel must be 1.
	typedef struct TifDataTemplate<char> ImageData; // channel must be 3.
	
	class S3D_BASEAPPLIB_EXPORT I3STool
	{
	public:
		// 用于测试的函数，非维护者不可调用(函数体中一般没有内容)。
		static int RunTest();
		
		/*!
			\brief gmeModel转i3s(slpk)接口

			\param gme_model 模型
			\param slpk_path slpk文件存储路径(包含文件后缀“.slpk”)。
			\param err_str 转换未成功时的错误信息。

			\TODO 废弃，将用另一个重载版本
		*/
		static bool gmeModelToSLPK(const gmeModel* gme_model, const std::string &slpk_path, std::string *err_str = nullptr);
		
		/*!
			\brief gmeModel转i3s(slpk)接口

			\param gme_model 模型
			\param slpk_path slpk文件存储路径(包含文件后缀“.slpk”)。
			\param slpk_sr slpk文件空间参考规则。
			\param transformation 实现了 CS_transformation.transform(...) 方法的子类指针，用于将 gme_model 中的坐标转换为符合 slpk_sr 规则的坐标，为空则不转换。
			\param err_str 转换未成功时的错误信息。

			\TODO
				1. 目前gmeModel仅支持结构体模型、钻孔柱模型和三维剖面模型。
		*/
		static bool gmeModelToSLPK(const gmeModel* gme_model, const std::string &slpk_path, const SLPK_SR slpk_sr, CS_transformation *transformation = nullptr, std::string *err_str = nullptr);

		/*!
			\brief 根据地形图和颜色图生成slpk文件

			\param dem_pic_path 地形图路径，地形图为16位的png格式图片，且长宽相等，长、宽各比颜色图多1个像素。
			\param horizontal_resolution 地形图的水平分辨率
			\param z_unit 地形图中像素值对应的米制单位(例如，0.1m/pixel)
			\param color_pic_path 颜色图路径，颜色图为rgba四通道32位的png格式图片，且长宽相等，均为2的倍数。
			\param slpk_path 生成的slpk文件的保存位置。
			\param err_str 转换失败的错误信息。

			\note 运用条件苛刻，不通用，慎用
			\TODO: 支持tiff格式的地形图，支持长宽不相等的图片，支持长、宽不是2的倍数的图片。
		*/
		static bool rasterToSLPK(const std::string &dem_pic_path, const double horizontal_resolution, const double z_unit, const std::string &color_pic_path, const std::string &slpk_path, std::string *err_str = nullptr);
		
		/*!
			\brief 根据地形图数据和颜色图数据生成slpk文件(数据由外部自行解析得到)

			\param size_w_h 地形图的尺寸(w=width, h=height)
			\param dem_data 地形图的高程数据。
			\param horizontal_resolution 地形图的水平分辨率
			\param color_data 颜色图数据，要求每个像素为三通道24位(3Byte)，且其图片尺寸的w和h各比地形图尺寸少1个像素。
			\param slpk_path 生成的slpk文件的保存位置。
			\param err_str 转换失败的错误信息。

			\note 未测试，慎用
			\TODO: 支持tiff格式的地形图，支持长宽不相等的图片，支持长、宽不是2的倍数的图片。
		*/
		//static bool rasterToSLPK(const std::pair<int, int> &size_w_h, const std::vector<double> &dem_data, const double horizontal_resolution, const std::vector<char> &color_data, const std::string &slpk_path, std::string *err_str = nullptr);
		
		// TODO: 实现分治算法才能使用 -- LH.2021.02.25 15:51 recorded.
		static bool rasterToSLPK(const DEMData &dem_data, const ImageData &color_data, const std::string &slpk_path, std::string *err_str = nullptr);

	private:
	};
}

