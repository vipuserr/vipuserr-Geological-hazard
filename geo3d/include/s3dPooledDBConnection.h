#pragma once

#include "s3dDBEngineAux_exp.h"
#include <sqlapi/SQLAPI.h>
#include "s3dSqlsBase.h"

namespace Smart3dMap {

	/// @breif The pooled database connection will be automatically returned to the pool when the s3dPooledDBConnection object is destructed.
	class S3D_DBENGINE_AUX_API s3dPooledDBConnection {
	public:
		/// @brief Check valid database type.
		/// Only supports: MySQL, PostgreSQL, SQLite, for now.
		static bool IsSupported(SAClient_t client);
		/// @brief Open a pooled connection to a file database, for example a SQLite database.
		static s3dPooledDBConnection OpenConnection(SAClient_t client, const SAString& dbPath, const SAString& user = SAString(), const SAString& password = SAString(),
			SAConnection::StrEnc clientEnc = SAConnection::StrEnc::GBK, SAConnection::StrEnc serverEnc = SAConnection::StrEnc::SYSTEM_DEFAUTL);
		/// @brief Open a pooled connection to a network database, e.x. a database in MySQL server or PostgreSQL server.
		static s3dPooledDBConnection OpenConnection(SAClient_t client, const SAString& host, int port, const SAString& dbName, const SAString& user, const SAString& password,
			SAConnection::StrEnc clientEnc = SAConnection::StrEnc::GBK, SAConnection::StrEnc serverEnc = SAConnection::StrEnc::SYSTEM_DEFAUTL);
		static s3dPooledDBConnection OpenConnection(const DB_CONN_INFO& dbInfo,
			SAConnection::StrEnc clientEnc = SAConnection::StrEnc::GBK, SAConnection::StrEnc serverEnc = SAConnection::StrEnc::SYSTEM_DEFAUTL);

		static void ClearConnections(const SAString& dbPath, const SAString& user = SAString(), const SAString& password = SAString());
		static void ClearConnections(const SAString& host, int port, const SAString& dbName, const SAString& user, const SAString& password);

		/// @brief Open a non-pooled connection to a network database. The returned connection should be destroyed by the caller.
		static SAConnection* OpenANonPooledConnection(SAClient_t client, const SAString& host, int port, const SAString& dbName, const SAString& user, const SAString& password,
			SAConnection::StrEnc clientEnc = SAConnection::StrEnc::GBK, SAConnection::StrEnc serverEnc = SAConnection::StrEnc::SYSTEM_DEFAUTL);
		static SAConnection* OpenANonPooledConnection(const DB_CONN_INFO& dbInfo, 
			SAConnection::StrEnc clientEnc = SAConnection::StrEnc::GBK, SAConnection::StrEnc serverEnc = SAConnection::StrEnc::SYSTEM_DEFAUTL);

	public:
		s3dPooledDBConnection(SAConnection* dbCon = nullptr);
		s3dPooledDBConnection(s3dPooledDBConnection&& t);
		virtual ~s3dPooledDBConnection();
		s3dPooledDBConnection& operator=(s3dPooledDBConnection&& t);

		bool IsConnected() const;
		SAConnection* GetDBCon() const;
		/// @brief Explicitly release the connection to the pool.
		void Release();

	private:
		static SAClient_t GMELinkTypeToSAClient(GME_LinkType linkType);

	private:
		SAConnection* dbCon_;
	};
}
