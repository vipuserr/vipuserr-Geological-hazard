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

		// ������ϵͳ���ݿ⡣���ָ����ID��prjId��С��1���򴴽�һ���¹��̣��������¹��̵�ID�����򱣴湤�̣������ع��̵�ԭʼID��
		// ����ֵ������0ʱ��ʾ����򴴽�����ʧ�ܡ�
		int saveToSysDB(int prjId);
		bool readFromSysDB(int prjId);

		std::string		m_Name;//��������
		std::string		m_Directory;//����Ŀ¼
		std::string		m_Authors;//��������
		std::string		m_Date;//���̴���ʱ��
		std::string		m_Desc;//��������
		std::string		m_CoordSys;//���̲ο�ϵ
		std::string		m_Unit;//��λ
		double		m_Xmin, m_Xmax, m_Ymin, m_Ymax, m_Zmin, m_Zmax;//ģ�ͷ�Χ
		int			m_StdStratVer;//��׼�ز�汾

		// ���ݿ����Ӳ���
		DB_CONN_INFO m_AttConInfo;		//�������ݿ����
		DB_CONN_INFO m_ModelConInfo;	//ģ�����ݿ����
		DB_CONN_INFO m_SpatialConInfo;  //�ռ����ݿ����

	private:
		bool FetchSysDBInfo(int id, DB_CONN_INFO& dbInfo) const;
	};

}

