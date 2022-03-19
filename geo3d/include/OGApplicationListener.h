 // OGApplicationListener.h: interface for the ApplicationListener class.
//
//////////////////////////////////////////////////////////////////////

#pragma once

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000





namespace Smart3dMap
{
	class OG_FRAME_DLL ApplicationListener  
	{
	public:
		ApplicationListener(){}
		virtual ~ApplicationListener(){}

		virtual void onInitialise() = 0;

		virtual void onShutdown() = 0;
	};

}



