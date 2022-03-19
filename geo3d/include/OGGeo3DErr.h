#pragma once

//****************************ϵͳ�������***********************************//
#define GEO3D_SUCCESS				000000001L			//�ɹ�
#define INVALID_VALUE				1.70141e+038		//ʧ��
 
//ERΪError����д
/*
�������Ϊ9λ�����֣��������Σ��京�����£�
(1) 1-3λ����ʾϵͳ���ô������ͣ��������£�
100�������ڴ�������
200���������ݿ���ʴ���
300����������ִ�д���
400�������ļ���������

(2) 4-6λΪ����������רҵ����(�����DdPubDef.h)

(3) 7-9λΪ�����ţ���001��999����
*/

//������뷽ʽ��100���������ͣ���100������רҵ����001�������룩

//---------------------------------����궨��--------------------------------//

//ϵͳ����(100+000)
#define ER_MEM_NEWMEM						-100000001L			//�ڴ����ʧ��
#define ERR_ALLOC_MEM						ER_MEM_NEWMEM		//�����ڴ����
//ϵͳ����(200+000)
#define ER_SQL								-200000001L			//SQL���ִ��ʧ��
#define ER_CONNECT							-200000002L			//����Դ����ʧ��
#define ERR_GET_BLOB						-200000003L			//���±���BLOB����ʧ��
//ϵͳ����(300+000)
#define ER_PARAMETERIN						-300000001L			//���������Ƿ�
#define ER_RESULTOUT						-300000002L			//����ִ�н���Ƿ�
#define ERR_INITDLG							-300000003L			//��ʼ���Ի���ʧ��
#define ERR_DEBUG							-300000004L			//���Դ���
#define ERR_GET_REG_NUM						-300000005L			//ȡ����Ŀ����
#define ERR_GET_PNT_NUM						-300000006L			//ȡ����Ŀ����
#define ERR_LIMIT_INVALID					-300000007L			//�����limit condition
#define ERR_INPUT_PARAM						-300000008L			//������������
#define ERR_OPER_CANCEL						-300000009L			//�������û�ȡ��

//����ģ�����(101+100)
#define ER_BASEGEO_NONAME					-200100001L			//����û�ҵ�
#define ER_BASEGEO_NOOWNER					-200100002L			//�û���û�ҵ�
#define ER_BASEGEO_NODATA					-200100003L			//û��ȡ������
#define ERR_EXECUTE_SQL						ER_SQL				//ִ��SQL����ʧ��
#define ERR_GET_TABLENAME					ER_BASEGEO_NONAME	//ȡ������ʧ��
#define ERR_GET_NODATA						ER_BASEGEO_NODATA	//û��ȡ������
//��רҵģ�����(200+300)
#define ERR_BOREHOLE_UNIQUECODE				-200300001L			//��ױ��벻Ψһ
#define ERR_SAMPLE_TYPE						-200300002L			//�������Ʒ����
#define ERR_ENGNO_UNIQUECODE                -200300003L         //��̽���̱��벻Ψһ

//��רҵģ�����(300+310)
#define ERR_HOLETYPE						-300310001L			//������������
#define ERR_GETHOLEMNG						-300310002L			//���������ݹ�����ʧ��
#define ERR_GETSTRATMNG						-300310003L			//��ȡ�ֲ��׼������ʧ��
#define ERR_NOT_ENOUGH_HOLE					-300310004L			//��׸�����������
#define ERR_GET_COMCHARTAPP					-300310005L			//���ͨ��ͼ��Ӧ�ö���ʧ��
#define ERR_STRAT_VERSION					-300310006L			//����ĵز�汾��
#define ERR_MAX_STRAT_LEVEL					-300310007L			//�ز�汾�����ز㼶�����
#define ERR_STRAT_INFO						-300310008L			//û��ȡ���ز���Ϣ
#define ERR_CREATE_PRITIN_MODEL				-300310009L			//������TINʧ��
#define ERR_MAPGIS_AREA_TYPE				-300310010L			//mapgis���������Ͳ���
#define ERR_GET_ATTSTRU						-300310011L			//ȡ���������Խṹ����
#define ERR_GET_MAP_ELEMENT_NUM				-300310012L			//ȡ��������ͼԪ��������
#define ERR_MAPGIS_AREA_TOPO				-300310013L			//mapgis���������˹�ϵ����
#define ERR_APPEND_TIN_PNT					-300310014L			//��TIN��������������
#define ERR_SET_TIN_AREA_MAP_PARAM			-300310015L			//����TIN��������ͼ��������
#define ERR_CREATE_TIN_NET					-300310016L			//TIN��������������������
#define ERR_GET_MAP_ELEMENT					-300310017L			//ȡͼԪ����
#define ERR_INTERP_TIN						-300310018L			//TIN����ֵ����
#define ERR_COORD_TRANS						-300310019L			//����ͶӰ�任����

//��Ŀ����ģ�����
#define ER_PRJ_INITFAIL						-300830001L			//û�ҵ��û����ҵĹ��̵������Ϣ
#define ER_PRJ_NOFOUND						-200830002L			//û�ҵ��û����ҵĹ��̵������Ϣ

//add by hws
//�Ի�����Ϣ
#define ER_ID_OK						IDOK
#define ER_ID_CANCEL					IDCANCEL
													
