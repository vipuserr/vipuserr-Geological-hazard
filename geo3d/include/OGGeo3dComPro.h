#pragma  once




#include "OGCommDef.h"
#include <string>
using namespace std;

namespace OG
{

	//��ȡ��ִ���ļ���·��,
	void OG_FRAME_DLL GetSysExePath(char *syspath);
	//�����ļ�����·����
	bool OG_FRAME_DLL AbstractPath(const char *szPathFileName, char *szPath);
	//�����ļ�����·����
	bool OG_FRAME_DLL AbstractFileName(const char *szPathFileName, char *szFileName);
	bool OG_FRAME_DLL AbstractFileName2(const char *szPathFileName, char *szFileName);
	void OG_FRAME_DLL replaceCharBySeperator(std::string& strName, const std::string& strSrc, const std::string& strSeperator);

	//���·����ڴ�
	OG_FRAME_DLL void*  ReAllocBuf(void* pBuf, long lOrgSize, long lAddSize);
	//ȡ��Ψһ�ַ���
	std::string  OG_FRAME_DLL _geoGetUniqueString(std::string strVal);

	//����ң��Ӱ������һ��������
	void OG_FRAME_DLL getMatNameByRsImage(string& strRsImage, string& strRsMatName);

	

}
