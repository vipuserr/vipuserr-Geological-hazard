#pragma once

#include "s3dAttDBEngine_exp.h"

#include "SQLAPI.h"
#include "SAFieldWrap.h"
#include "SAParamWrap.h"

class S3D_ATT_DBENGINE_API SACommandWrap : public SACommand
{
	friend class SAFieldWrap;
	friend class SAParamWrap;

public:
	SACommandWrap();
	SACommandWrap(
		SAConnection* pCon,
		const SAString& sCmd = SAString(),
		eSACommandType eCmdType = SA_CmdUnknown
	);
	virtual ~SACommandWrap();

	void setConnection(SAConnection* pCon);

	void setCommandText(const SAString& sSQL, eSACommandType eCmdType = SA_CmdUnknown);
	void setCommandText(const string& sSQL, eSACommandType eCmdType = SA_CmdUnknown);
	void setCommandText(const char* sSQL, eSACommandType eCmdType = SA_CmdUnknown);
	SAString CommandText() const;

	SAParamWrap& Param(int nParamByID);
	SAParamWrap& Param(const SAString& sParamByName);
	SAParamWrap& Param(const string& sParamByName);
	SAParamWrap& Param(const char* sParamByName);
	SACommandWrap& operator<<(const SAString& value);
	SACommandWrap& operator<<(const string& value);
	SACommandWrap& operator<<(const SAChar* value);
	SACommandWrap& operator<<(const SABytes& value);
	SACommandWrap& operator<<(const SANull& null);

	SAFieldWrap& Field(int nField) SQLAPI_THROW(SAException);
	SAFieldWrap& Field(const SAString& sField) SQLAPI_THROW(SAException);
	SAFieldWrap& Field(const string& sField) SQLAPI_THROW(SAException);
	SAFieldWrap& Field(const char* sField) SQLAPI_THROW(SAException);
	SAFieldWrap& operator[](const SAString &sField) SQLAPI_THROW(SAException);
	SAFieldWrap& operator[](int nField) SQLAPI_THROW(SAException);

	void Execute() SQLAPI_THROW(SAException);

	void setClientType(const eSAClient clientType);
	const eSAClient ClientType() const;

protected:
	static eSAClient ms_clientType;
	void ConvertSqlEncoding();

	SAFieldWrap* m_pFieldWrap;
	SAParamWrap* m_pParamWrap;

private:
	// 禁用拷贝构造和赋值构造
	SACommandWrap(const SACommandWrap&);
	SACommandWrap& operator =(const SACommandWrap&);
};

