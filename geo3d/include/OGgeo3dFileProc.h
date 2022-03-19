
#pragma once


/*=========================�����ļ���д����=======================*/
// ------------------ ���ļ� ------------------- //
//������filename ----> �ļ���
//		mode --------> �򿪷�ʽ("r"-��/"w"-д)
//����ֵ: �ɹ������ļ������ʧ�ܷ���NULL
HANDLE _OpenFile(char* filename, char *mode, DWORD dwCreationDisposition = OPEN_ALWAYS);

// ------------ �ر��ļ� ----------- //
//������hFile ----> �ļ����
//����ֵ:�ɹ�--1��ʧ��--����
long _CloseFile(HANDLE hFile);

// --------------------- �ļ�ָ��ƫ�� ---------------------- //
//������hFile -------> �ļ����
//		lOffset ------> �ļ�ָ��ƫ����
//		lMovMethod ---> �ļ�ָ��ƫ�Ƶ����λ��
//����ֵ:�ɹ�--1��ʧ��--����
long _Seek(HANDLE hFile, long lOffset, long lMovMethod);
//��ȡ��ǰ���ļ�ָ��ƫ��λ��
long _GetFilePointer(HANDLE hFile);

//�ж��Ƿ��ļ���β
BOOL _IsEOF(HANDLE hFile);

// ---------------------- ��ȡ�ļ����� ------------------------- //
//������hFile -------> �ļ����
//		vpBuffer ----> ���ݻ�����
//		lBytesNum ---> ����ȡ���ݵ��ֽ���
//����ֵ:�ɹ�--�ֽ�����ʧ��-- -1.
long _ReadFileF(HANDLE hFile,void* lpBuffer,long lBytesNum);
// ------------------------- ��ȡ�ļ����� ---------------------- //
//������vpBuffer ----> ���ݻ�����
//		lCount ------> ����ȡ���ݽṹ�ĸ���
//		lSize -------> ����ȡ���ݽṹ�Ĵ�С
//		hFile -------> �ļ����
//����ֵ:�ɹ�--�ֽ�����ʧ��-- -1.
long _ReadFile(HANDLE hFile,void* lpBuffer,long lSize,long lCount);
//���ļ����ַ���
long _ReadStr(HANDLE hFile,void* vpBuffer,char separator='\0');



// ------------------------- ���ļ�д���� ------------------------ //
//������hFile -------> �ļ����
//		vpBuffer ----> ���ݻ�����
//		lBytesNum ---> ��д���ݵ��ֽ���
//����ֵ:�ɹ�--�ֽ�����ʧ��-- -1.
long _WriteFileF(HANDLE hFile,void* lpBuffer,long lBytesNum);
// ---------------------------- ���ļ�д���� --------------------------- //
//����: vpBuffer -------> ��д������buf
//		lSize ----------> ��д������buf�ĵ�Ԫ�ĸ���
//		lCount ---------> ��д������buf�ĵ�Ԫ��С
//		HANDLE --------> ��д���ļ����
//����ֵ:�ɹ�--�ֽ�����ʧ��-- -1.
long _WriteFile(HANDLE hFile,void* lpBuffer,long lSize,long lCount);
//���ļ�д�ַ���
long _WriteStr(HANDLE hFile,void* vpBuffer);
