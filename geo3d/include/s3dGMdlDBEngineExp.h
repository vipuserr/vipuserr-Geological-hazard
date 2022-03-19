#ifndef _S3D_GMDLDBENGINE_EXP_H
#define _S3D_GMDLDBENGINE_EXP_H

#ifdef OG_GME_EXPORT
#define OG_GME_API __declspec(dllexport)
#else
#define OG_GME_API __declspec(dllimport)
#endif
#ifndef OG_GME_EXPORT
#pragma comment(lib, "S3dDBEngineMdl.lib")
#endif


#endif