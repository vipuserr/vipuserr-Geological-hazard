#pragma once
#include "s3dAttDBEngine_exp.h"

#include "QObject"
#include "QString"

#include "SQLAPI.h"

#include <string>
#include <map>
#include <vector>

using namespace std;


class S3D_ATT_DBENGINE_API CreateAcsessDb
{
public:
	CreateAcsessDb(const QString& file);
	~CreateAcsessDb();

	bool CreateDbFile();
	bool ConnectNewDb();

	// tableName��׼�ֶ����ƣ�whereClauset�������
	bool CopyData(const string& tableName, const string& whereClause="");
	bool CopyDataRaw(const string& tableName, const string& whereClause="");

private:
	CreateAcsessDb();
	bool CreateTable(const string& tableName);
	bool CreateAllTable();

	QString			m_pNewMdbFile;
	string			m_pOldMdbFile;
	SAConnection*	m_pNewCon;
	SAConnection*	m_pOldCon;
};

