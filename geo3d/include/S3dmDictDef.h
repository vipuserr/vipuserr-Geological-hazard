#pragma once

//zhuyh-2021-07-12
//字典表结构定义


#include <string>
using namespace std;


struct S3dmSysDictTableCategory
{
	int dataMdlID; //类型id
	std::string dataMdlName; //类型名称
	std::string dataMdlNameC;//中文名
};
struct S3dmSysDictTable
{
	int				innerTblID; //表id
	std::string		innerTblName; //程序使用的表名，即内部表名
	std::string		userTblName;  // 用户使用的表名
	std::string		innerTblNameC;//别名
	bool			is_required; //是否必选
	int				dataMdlID; //类别Id
};

struct S3dmSysDictTableField
{
	int				innerFldID; //字段id
	int				innerTblID;//表id
	std::string		innerFldName;
	std::string		userTblFldName;
	std::string		innerFldType;//数据类型
	std::string		innerFldNameC;//别名
	bool			is_required; //是否必选
};
