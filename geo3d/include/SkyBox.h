#ifndef __SKY_BOX__H_
#define __SKY_BOX__H_

#include "osg_headers.h"
#include "Og3DRE_Def.h"

namespace Smart3dMap
{
	class _OG3D_RENDERENGINE_DLL CSkyBox : public osg::MatrixTransform
	{
	public:
		CSkyBox(void);
		~CSkyBox(void);

		void loadCubeMap();
		osg::TextureCubeMap* getCubeMap();

	private:
		osg::ref_ptr<osg::TextureCubeMap> mTextureCubeMap;
	};
}


#endif
