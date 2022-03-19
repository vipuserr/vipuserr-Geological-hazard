#pragma once
#include "s3dmqgsdialog_global.h"
#include <QDialog>
#include "QEvent.h"
#include "ui_DBSelectorDialog.h"

#include <gmeDef.h>
#include <s3dSqlsBase.h>

namespace Smart3dMap {

	class S3DMQGSDIALOG_EXPORT DBSelectorDialog : public QDialog, private Ui::DBSelectorDialog
	{
		Q_OBJECT

	public:
		static bool GetDBConParam(DB_APP_TYPE appType, GME_LinkType& linkType, std::string& dbName, std::string& serverName, std::string& portNo, std::string& userName, std::string& password, int& sysDBId, bool onlySysDB = false);

	private:
		DBSelectorDialog(DB_APP_TYPE appType, bool onlySysDB, QWidget* parent = nullptr);
		~DBSelectorDialog();

	public:
		void GetDatabaseConfig(GME_LinkType& linkType, std::string& dbName, std::string& serverName, std::string& portNo, std::string& userName, std::string& password, int& sysDBId);

	private:
		bool DBConTest();
		void AppendSQLiteFileFilter(QString& filters);
		void AppendAccessFileFilter(QString& filters);
		void AppendLocalFileFilter(QString& filters);

		//本地数据库是否只显示本地文件连接
		void LocalDBIsOnlyLocalFile(bool isFile);

	public Q_SLOTS:
	    virtual void accept() override;

	private Q_SLOTS:
		void OnDBTypeChanged(bool checked);
		void OnSysDBSelected(int index);
		void OnOpenLocalDBFile(bool checked);
		void OnLocalDBTypeSelected(int index);
	private:
		bool onlySysDB_;
		DB_APP_TYPE appType_;
		//数据库连接参数
		GME_LinkType linkType_;
		std::string dbName_;
		std::string serverName_;
		int portNo_;
		std::string userName_;
		std::string password_;
		int sysDBId_;
	};
}
