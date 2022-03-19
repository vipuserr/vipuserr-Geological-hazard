
#pragma once


/*=========================基本文件读写操作=======================*/
// ------------------ 打开文件 ------------------- //
//参数：filename ----> 文件名
//		mode --------> 打开方式("r"-读/"w"-写)
//返回值: 成功返回文件句柄，失败返回NULL
HANDLE _OpenFile(char* filename, char *mode, DWORD dwCreationDisposition = OPEN_ALWAYS);

// ------------ 关闭文件 ----------- //
//参数：hFile ----> 文件句柄
//返回值:成功--1，失败--其他
long _CloseFile(HANDLE hFile);

// --------------------- 文件指针偏移 ---------------------- //
//参数：hFile -------> 文件句柄
//		lOffset ------> 文件指针偏移量
//		lMovMethod ---> 文件指针偏移的相对位置
//返回值:成功--1，失败--其他
long _Seek(HANDLE hFile, long lOffset, long lMovMethod);
//获取当前的文件指针偏移位置
long _GetFilePointer(HANDLE hFile);

//判断是否到文件结尾
BOOL _IsEOF(HANDLE hFile);

// ---------------------- 读取文件数据 ------------------------- //
//参数：hFile -------> 文件句柄
//		vpBuffer ----> 数据缓冲区
//		lBytesNum ---> 待读取数据的字节数
//返回值:成功--字节数，失败-- -1.
long _ReadFileF(HANDLE hFile,void* lpBuffer,long lBytesNum);
// ------------------------- 读取文件数据 ---------------------- //
//参数：vpBuffer ----> 数据缓冲区
//		lCount ------> 待读取数据结构的个数
//		lSize -------> 待读取数据结构的大小
//		hFile -------> 文件句柄
//返回值:成功--字节数，失败-- -1.
long _ReadFile(HANDLE hFile,void* lpBuffer,long lSize,long lCount);
//从文件读字符串
long _ReadStr(HANDLE hFile,void* vpBuffer,char separator='\0');



// ------------------------- 向文件写数据 ------------------------ //
//参数：hFile -------> 文件句柄
//		vpBuffer ----> 数据缓冲区
//		lBytesNum ---> 待写数据的字节数
//返回值:成功--字节数，失败-- -1.
long _WriteFileF(HANDLE hFile,void* lpBuffer,long lBytesNum);
// ---------------------------- 向文件写数据 --------------------------- //
//参数: vpBuffer -------> 待写的数据buf
//		lSize ----------> 待写的数据buf的单元的个数
//		lCount ---------> 待写的数据buf的单元大小
//		HANDLE --------> 待写的文件句柄
//返回值:成功--字节数，失败-- -1.
long _WriteFile(HANDLE hFile,void* lpBuffer,long lSize,long lCount);
//向文件写字符串
long _WriteStr(HANDLE hFile,void* vpBuffer);
