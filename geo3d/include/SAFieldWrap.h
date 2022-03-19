#pragma once

#include "s3dAttDBEngine_exp.h"

#include "SQLAPI.h"
#include "DbTool.h"

using namespace std;

class SACommandWrap;

class S3D_ATT_DBENGINE_API SAFieldWrap : public SAField
{
	friend class SACommandWrap;

public:
	SAFieldWrap(SACommandWrap* pCmd, SAField& fd);
	virtual ~SAFieldWrap();

	SAString asString() const;
	SAString asBytes() const;
	SAString asLongBinary() const;
	SAString asLongChar() const;
	SAString asBLob() const;
	SAString asCLob() const;

	const SAString &Name() const;

protected:
	static eSAClient ms_clientType;
	static SAString ms_str;

private:

	// 禁用拷贝构造和赋值构造
	SAFieldWrap(const SAFieldWrap&) = delete;
	SAFieldWrap& operator=(const SAFieldWrap&) = delete;
};

