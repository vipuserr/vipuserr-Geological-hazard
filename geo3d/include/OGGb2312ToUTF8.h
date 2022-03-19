#pragma once

#include <iostream>

class CGb2312ToUTF8
{
public:
	CGb2312ToUTF8(void);
	~CGb2312ToUTF8(void);

	//osgEarth显示中文标注需要用到的转换函数
	void unicodeToUTF8(const std::wstring &src, std::string& result);
	void gb2312ToUnicode(const std::string& src, std::wstring& result);
	void gb2312ToUtf8(const std::string& src, std::string& result);
};
