#pragma once

#include <string>

#include "s3d_projectmanagerlib_global.h"
#include "s3dSqlsBase.h"

namespace Smart3dMap {

	class S3D_PROJECTMANAGERLIB_EXPORT ProjectAttr
	{
	public:
		ProjectAttr();
		~ProjectAttr();
	public:
		bool save(std::string url);
		bool read(std::string url);

		// 保存至系统数据库。如果指定的ID（prjId）小于1，则创建一个新工程，并返回新工程的ID；否则保存工程，并返回工程的原始ID。
		// 返回值不大于0时表示保存或创建工程失败。
		int saveToSysDB(int prjId);
		bool readFromSysDB(int prjId);

		std::string		m_Name;//工程名称
		std::string		m_Directory;//工程目录
		std::string		m_Authors;//工程作者
		std::string		m_Date;//工程创建时间
		std::string		m_Desc;//工程描述
		std::string		m_CoordSys;//工程参考系
		std::string		m_Unit;//单位
		double		m_Xmin, m_Xmax, m_Ymin, m_Ymax, m_Zmin, m_Zmax;//模型范围
		int			m_StdStratVer;//标准地层版本

		// 数据库连接参数
		DB_CONN_INFO m_AttConInfo;		//属性数据库参数
		DB_CONN_INFO m_ModelConInfo;	//模型数据库参数
		DB_CONN_INFO m_SpatialConInfo;  //空间数据库参数

	private:
		bool FetchSysDBInfo(int id, DB_CONN_INFO& dbInfo) const;
	};

}

