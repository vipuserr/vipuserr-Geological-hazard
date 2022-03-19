#pragma once
#include "OGBasDef.h"
#include "OGContainer.h"

//--------------- 基础图形绘制 ---------------//
namespace Smart3dMap
{
	class OG_FRAME_DLL DrawBasicGraphics
	{
	public:
		DrawBasicGraphics();
		~DrawBasicGraphics();

	public:
		//简单图形绘制 -- 单一颜色
		
		/** @iTtype 0 绘制单独的球
		 *          1 绘制每两点连接的线
		 *          2 绘制依次连接各点的线
		 *          3 绘制依次连接各点的线，且首尾相连
		 *          4 绘制依次连接各点的多边形
		 *          5 绘制每三点连接的三角形
		 *          6 绘制单独的点
		 *         ...
		 */
		static osg::ref_ptr<osg::Geode> DrawSimpleGraphics(__in vector<gme_vector3d>& vPoints,
														  __in int iType,
														  __in double dSize,
														  __in gme_color4& color,
														  __in Vector3 offset);

		static Container* DrawBasicGraphicsLayer(__in vector<gme_vector3d>& vPoints,
												 __in int iType,
												 __in gme_color4 color = gme_color4(1.0, 0.0, 0.0),
												 __in double dSize = 5.0,
												 __in const std::string& layerName = "",
												 __in Container* parentContiner = NULL);
		
		static Container* DrawBasicGraphicsLayer(__in vector<gme_vector2d>& vPoints,
												 __in int iType,
												 __in gme_color4 color = gme_color4(1.0, 0.0, 0.0),
												 __in double dSize = 5.0,
												 __in const std::string& layerName = "",
												 __in Container* parentContiner = NULL);

		//绘制多条线
		static Container* DrawLinesLayer(__in vector<vector<gme_vector3d>>& vLines,
										 __in int iType = 2,
										 __in gme_color4 color = gme_color4(1.0,0.0,0.0),
										 __in double dSize = 5.0,
										 __in const std::string& layerName = "",
										 __in Container* parentContiner = NULL);

		//绘制面
		static osg::ref_ptr<osg::Node> DrawSurface(__in vector<gme_vector3d>& vPoints,
												   __in vector<gme_triangle>& vecTriangleIndex,
												   __in gme_color4& color,
												   __in Vector3 offset);

		static Container* DrawSurfaceLayer(__in vector<gme_vector3d>& vPoints,
										   __in vector<gme_triangle>& vTriangleIndex,
										   __in gme_color4 color = gme_color4(1.0, 0.0, 0.0),
										   __in const std::string& layerName = "",
										   __in Container* parentContiner = NULL);
	};

}

