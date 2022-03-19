#pragma once

#include "s3d_projectmanagerlib_global.h"

#include "QFileInfo"
#include "QDir"
#include "string.h"

using namespace std;

class S3D_PROJECTMANAGERLIB_EXPORT FileTools
{
	
public:
	//判断文件是否存在
	static bool isFileExist(string fileUrl);

	//判断文件夹是否存在
	static bool isFolderExist(string folderUrl);

	//复制文件
	static bool copyFileToPath(QString sourceDir, QString toDir, bool coverFileIfExist);

	//获取有效的文件夹路径（传入文件夹，判断是否存在，如果存在，返回一个不存在的文件夹）
	static std::string getValidFolderPath(std::string folder);

	//传入绝对路径 ，获取相对于工程的路径，只适用于于工程文件下的文件
	static QString getRealitivePath(QString absolutePath);

	//判断文件是否在该工程文件夹下
	static bool FileIsProjectFile(QString file);

	//获取文件的名称，包括后缀
	static QString getFileName(QString file);

	//获取文件所在的文件夹
	static QString getFileFolder(QString file);

	//将含有../../这样符号的相对路径处理成绝对路径，如C:/Code/../a.png -->C:/a.png
	static QString real_path_2_absolute_path(QString realPath);

};

