#pragma once

#include "s3d_KerObbtDef.h"

// gmArrayPool :A dynamic linear array. (It is written by J. Shewchuk)
//内存池管理指向多个数据块的指针数组， 每个块包含相同的固定数量的对象，数组的每个索引都会寻址池中的特定对象。 最高有效位寻址包含对象的块的索引，较低位在块中寻址此对象。
//块---对象----字节
class LIB_GMKEROBBT_EXP gmArrayPool {
public:
	gmArrayPool(int sizeofobject, int log2objperblk=512);
	~gmArrayPool();

public:
	void* operator[](int objIdx);	// 返回指向具有给定索引的对象的指针，如果对象的块尚不存在，则返回0。
	void* lookup(int objIdx);// 返回指向具有给定索引的对象的指针，如果对象的块尚不存在，则返回0。

public:
	void restart(); //内存池状态重置
	void poolinitparam(int sizeofobject, int log2objperblk); //初始化内存池的参数
	char* getblock(int objectindex);//返回（创建）包含具有给定索引对象的块指针(objectindex指对象索引，而不是块索引)
	int newindex(void **newptr);	//从内存池中为新对象分配空间，并返回对象的索引号。
	

public:
	unsigned long totalmemorybytes;//分配内存的总子节数(包括toparray和toparray[i]分配的内存总和)
	char **toparray;		//内存中的块指针
	int toparrayblocks;		//内存中的块个数
	long objects;			//分配的对象数量
	int objectbytes;		//每个对象的字节数
	int objectsperblock;	//每一块中的对象数
	int log2objectsperblock;//每一块中的对象数的以2为底对数 ?
	int objectsperblockmark;//每一块中的对象数-1?
};
