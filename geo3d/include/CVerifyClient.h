#pragma once

#ifdef GM_VERIFYCLIENT_LIB
#define GM_VERIFYCLIENT_EXP __declspec(dllexport)
#else
#define GM_VERIFYCLIENT_EXP __declspec(dllimport)
#endif


class GM_VERIFYCLIENT_EXP CVerifyClient
{
public:
	CVerifyClient();
	virtual ~CVerifyClient();


public:
	int Verify();
	static	bool mbVerifyClient;
};


#ifndef GM_VERIFYCLIENT_LIB
#pragma comment(lib, "OgClientVerify.lib")
#endif

