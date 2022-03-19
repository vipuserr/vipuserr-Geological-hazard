#pragma once
#include "s3dqtapp_global.h"
#include <vector>
#include <string>
#include "gme_vector3.h"
#include "gmeStru.h"



namespace Smart3dMap
{
	class S3dmRasterLayer_cpp;
	class S3DQTAPP_EXPORT S3dmRasterLayer
	{
	public:
		S3dmRasterLayer(std::string url);
		~S3dmRasterLayer();

		bool getDemTiffData(int& rows, int& cols, std::vector<gme_vector3d>& pnts, gme_rect_2d& extent);

		/* rows:获取栅格行
		   cols:获取栅格列
		   xinterval:获取栅格行间距
		   yinterval:获取栅格列间距
		   leftTop:获取栅格左上角点
		   attrVals:获取栅格所有波段值，值索引为0时指左上角（从上往下）
		   getExtent:获取栅格范围
		*/
		bool getTiffData(int& rows, int& cols, double &xinterval, double &yinterval, gme_vector2d &leftTop, std::map<int, std::vector<double>>& attrVals, gme_rect_2d& getExtent);
	private:
	    S3dmRasterLayer_cpp* m_ToolCls;
	};
}
