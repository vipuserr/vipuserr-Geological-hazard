// OGGenericUtils.h: interface for the GenericUtils class.
//
//////////////////////////////////////////////////////////////////////

#pragma once

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "OGBasDef.h"


namespace Smart3dMap {

	class OG_FRAME_DLL GenericUtils
	{
	public:
		/** Find the file by using og's resource system.
		if file found returns true and modifies the value of
		filename to include the relative path to the file.
		*/
		static bool findFilePath(string& filename);

		/** Remove all invalid characters from a filename (not path,
		just filename)
		*/
		static string cleanFileName(const string& fileName);

		static const string& getUniqueNameByTime(const string& baseName);


		static double calculateRenderingDistance(const AxisAlignedBox& box);

		static void focusPoint(RenderWindow* pRenderWindow, const Vector3& point, float dis = 200, Degree deg = Degree(45));
		static void focusSceneNode(RenderWindow* pRenderWindow, const SceneNode* node, bool byAABB = true, float dis = 200, Degree deg = Degree(45));
	};
}



