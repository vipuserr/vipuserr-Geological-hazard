#pragma once

#include "s3d_KerObbtDef.h"

// gmArrayPool :A dynamic linear array. (It is written by J. Shewchuk)
//�ڴ�ع���ָ�������ݿ��ָ�����飬 ÿ���������ͬ�Ĺ̶������Ķ��������ÿ����������Ѱַ���е��ض����� �����ЧλѰַ��������Ŀ���������ϵ�λ�ڿ���Ѱַ�˶���
//��---����----�ֽ�
class LIB_GMKEROBBT_EXP gmArrayPool {
public:
	gmArrayPool(int sizeofobject, int log2objperblk=512);
	~gmArrayPool();

public:
	void* operator[](int objIdx);	// ����ָ����и��������Ķ����ָ�룬�������Ŀ��в����ڣ��򷵻�0��
	void* lookup(int objIdx);// ����ָ����и��������Ķ����ָ�룬�������Ŀ��в����ڣ��򷵻�0��

public:
	void restart(); //�ڴ��״̬����
	void poolinitparam(int sizeofobject, int log2objperblk); //��ʼ���ڴ�صĲ���
	char* getblock(int objectindex);//���أ��������������и�����������Ŀ�ָ��(objectindexָ���������������ǿ�����)
	int newindex(void **newptr);	//���ڴ����Ϊ�¶������ռ䣬�����ض���������š�
	

public:
	unsigned long totalmemorybytes;//�����ڴ�����ӽ���(����toparray��toparray[i]������ڴ��ܺ�)
	char **toparray;		//�ڴ��еĿ�ָ��
	int toparrayblocks;		//�ڴ��еĿ����
	long objects;			//����Ķ�������
	int objectbytes;		//ÿ��������ֽ���
	int objectsperblock;	//ÿһ���еĶ�����
	int log2objectsperblock;//ÿһ���еĶ���������2Ϊ�׶��� ?
	int objectsperblockmark;//ÿһ���еĶ�����-1?
};
