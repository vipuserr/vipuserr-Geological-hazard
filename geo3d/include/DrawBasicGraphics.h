#pragma once
#include "OGBasDef.h"
#include "OGContainer.h"

//--------------- ����ͼ�λ��� ---------------//
namespace Smart3dMap
{
	class OG_FRAME_DLL DrawBasicGraphics
	{
	public:
		DrawBasicGraphics();
		~DrawBasicGraphics();

	public:
		//��ͼ�λ��� -- ��һ��ɫ
		
		/** @iTtype 0 ���Ƶ�������
		 *          1 ����ÿ�������ӵ���
		 *          2 �����������Ӹ������
		 *          3 �����������Ӹ�����ߣ�����β����
		 *          4 �����������Ӹ���Ķ����
		 *          5 ����ÿ�������ӵ�������
		 *          6 ���Ƶ����ĵ�
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

		//���ƶ�����
		static Container* DrawLinesLayer(__in vector<vector<gme_vector3d>>& vLines,
										 __in int iType = 2,
										 __in gme_color4 color = gme_color4(1.0,0.0,0.0),
										 __in double dSize = 5.0,
										 __in const std::string& layerName = "",
										 __in Container* parentContiner = NULL);

		//������
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

