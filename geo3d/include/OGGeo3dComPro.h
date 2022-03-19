#pragma  once




#include "OGCommDef.h"
#include <string>
using namespace std;

namespace OG
{

	//获取可执行文件的路径,
	void OG_FRAME_DLL GetSysExePath(char *syspath);
	//分离文件名和路径名
	bool OG_FRAME_DLL AbstractPath(const char *szPathFileName, char *szPath);
	//分离文件名和路径名
	bool OG_FRAME_DLL AbstractFileName(const char *szPathFileName, char *szFileName);
	bool OG_FRAME_DLL AbstractFileName2(const char *szPathFileName, char *szFileName);
	void OG_FRAME_DLL replaceCharBySeperator(std::string& strName, const std::string& strSrc, const std::string& strSeperator);

	//重新分配内存
	OG_FRAME_DLL void*  ReAllocBuf(void* pBuf, long lOrgSize, long lAddSize);
	//取出唯一字符串
	std::string  OG_FRAME_DLL _geoGetUniqueString(std::string strVal);

	//根据遥感影像生成一个材质名
	void OG_FRAME_DLL getMatNameByRsImage(string& strRsImage, string& strRsMatName);

	

}
