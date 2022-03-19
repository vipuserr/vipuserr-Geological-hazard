 // OGSeachLight.h: interface for the SeachLight class.
//
//////////////////////////////////////////////////////////////////////

#pragma once

#if _MSC_VER > 1000
#pragma once
#endif 

#include "OGBasDef.h"
#include "OGFrameListener.h"
#include <list>

namespace Smart3dMap
{
	struct LightInfo
	{
		Light* light;
		Vector3 Pos;//相机坐标系中的位置
		Vector3 Dir;//相机坐标系中的方位
	};

	typedef std::list<LightInfo*> LightInfoList;

	class OG_FRAME_DLL SeachLight : public FrameListener
	{
	public:
		SeachLight();
		virtual ~SeachLight();
		void		addLight(Light* light,Vector3 Positon,Vector3 Direction);
		void		setCamera(Smart3dMap::Camera* camera);
		Smart3dMap::Camera*		getCamera();

		LightInfoList*	getAllLight(); 
		Light*		getLight(const string& name);

		void        detachLight(const string& name);

		void		start();
		void		end();
		void		clear();
	protected:
		bool		frameStarted(const FrameEvent& evt);
        bool		frameEnded(const FrameEvent& evt);
	private:
		LightInfoList		mLightList;
		Smart3dMap::Camera			*mCamera;
		bool			mbEnd;
	};

}

