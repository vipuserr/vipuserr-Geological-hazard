#ifndef __GM_KRIGING_INTERP_H_
#define __GM_KRIGING_INTERP_H_

#include <Windows.h>




#ifndef _GM_KRIGING_INTERP_DLL
#define __GM_KRIGING_INTERP_EXP  __declspec(dllimport) 
#else
#define __GM_KRIGING_INTERP_EXP  __declspec(dllexport)
#endif

namespace Smart3dMap
{


}

#ifndef _GM_KRIGING_INTERP_DLL
#pragma comment(lib, "s3dKerInterpKrig.lib")
#endif


#endif /* #ifndef __GM_KRIGING_INTERP_H_ */