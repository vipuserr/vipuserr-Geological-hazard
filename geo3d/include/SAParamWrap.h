#pragma once

#include "s3dAttDBEngine_exp.h"
#include "SQLAPI.h"

class SACommandWrap;

class S3D_ATT_DBENGINE_API SAParamWrap : public SAParam
{
	friend class SACommandWrap;

public:
	SAParamWrap(SACommandWrap* pCmd, SAParam& pa);
	virtual ~SAParamWrap();

	SAString& setAsString();

protected:
	static eSAClient ms_clientType;
	static SAString ms_str;

private:
	// 禁用拷贝构造和赋值构造
	SAParamWrap(const SAParamWrap&) = delete;
	SAParamWrap& operator=(const SAParamWrap&) = delete;
};

