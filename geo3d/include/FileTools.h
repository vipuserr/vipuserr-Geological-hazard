#pragma once

#include "s3d_projectmanagerlib_global.h"

#include "QFileInfo"
#include "QDir"
#include "string.h"

using namespace std;

class S3D_PROJECTMANAGERLIB_EXPORT FileTools
{
	
public:
	//�ж��ļ��Ƿ����
	static bool isFileExist(string fileUrl);

	//�ж��ļ����Ƿ����
	static bool isFolderExist(string folderUrl);

	//�����ļ�
	static bool copyFileToPath(QString sourceDir, QString toDir, bool coverFileIfExist);

	//��ȡ��Ч���ļ���·���������ļ��У��ж��Ƿ���ڣ�������ڣ�����һ�������ڵ��ļ��У�
	static std::string getValidFolderPath(std::string folder);

	//�������·�� ����ȡ����ڹ��̵�·����ֻ�������ڹ����ļ��µ��ļ�
	static QString getRealitivePath(QString absolutePath);

	//�ж��ļ��Ƿ��ڸù����ļ�����
	static bool FileIsProjectFile(QString file);

	//��ȡ�ļ������ƣ�������׺
	static QString getFileName(QString file);

	//��ȡ�ļ����ڵ��ļ���
	static QString getFileFolder(QString file);

	//������../../�������ŵ����·������ɾ���·������C:/Code/../a.png -->C:/a.png
	static QString real_path_2_absolute_path(QString realPath);

};

