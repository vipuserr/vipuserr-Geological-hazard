#pragma once

//zhuyh-2021-07-12
//�ֵ��ṹ����


#include <string>
using namespace std;


struct S3dmSysDictTableCategory
{
	int dataMdlID; //����id
	std::string dataMdlName; //��������
	std::string dataMdlNameC;//������
};
struct S3dmSysDictTable
{
	int				innerTblID; //��id
	std::string		innerTblName; //����ʹ�õı��������ڲ�����
	std::string		userTblName;  // �û�ʹ�õı���
	std::string		innerTblNameC;//����
	bool			is_required; //�Ƿ��ѡ
	int				dataMdlID; //���Id
};

struct S3dmSysDictTableField
{
	int				innerFldID; //�ֶ�id
	int				innerTblID;//��id
	std::string		innerFldName;
	std::string		userTblFldName;
	std::string		innerFldType;//��������
	std::string		innerFldNameC;//����
	bool			is_required; //�Ƿ��ѡ
};
