#ifndef _OGGEO3DMSGIDDEF_H
#define _OGGEO3DMSGIDDEF_H

#include <string>
using namespace std;

//��ͷ�ļ���Ҫ�������ܲ��������ϢID��

//���彻��ѡ����ͻظ���λ�ò�ѯ�Ի������Ϣ
//WPARAM wParam,  ���괮��ĸ���
//LPARAM lParam,  ���괮��ָ��
//���괮���췽ʽ���£�
//WPARAM wParam  = 1, Ϊ��������ѯMSG_QUERY_BYPNT,�������ѡ�������׵�����
//WPARAM wParam  = 2, Ϊ��Բ�β�ѯMSG_QUERY_BYCYCLE,��һ������ΪԲ�����꣬
//					   �ڶ��������X��Yֵ������Բ�İ뾶
//WPARAM wParam  = n, (n>=3), Ϊ�������ֲ�ѯ��ʽ,����ѡ������ı߽����괮
#define WM_TOOL_QUERY_COMMON	    (0x0400+0x9010)	//
#define WM_LAYER_QUERY_ADVANCED	    (0x0400+0x9006)	//
#define WM_GET_OPENEND_LAYERLIST	(0x0400+0x9007)	// ID��Ҫ�޸�



//////////////����Ҫ��ͼ��WM_USER + 1000 ~ WM_USER + 2000////////////////////////////////////////////
#define WM_SET_CURDBSNO	 (WM_USER + 1000)	//����ͼ�����õ�ǰ�����ű���,wParam:��ǰ�����ű��У�long��
#define WM_CHANGE_DBS	 (WM_USER + 1001)   //�������ű������õ�ǰ��ͼ,wParam:��ǰ�����ű��У�long��
#define WM_ZOOM_DBS		 (WM_USER + 1002)   //���ŵ�ͼ,wParam:��С��Ŵ�long�ͣ�1Ϊ�Ŵ�0Ϊ��С
#define WM_RESTOR_DBS	 (WM_USER + 1003)   //��λ��ͼ
#define WM_PRE_WND		 (WM_USER + 1004)   //��һ������

#define WM_GET_DBSSTATE   (WM_USER + 1005)  //��õ�ǰͼ���Ƿ�� wParam , BOOL��ָ�룬TREUΪ�򿪣�FALSE
											//Ϊ�رջ����������
#define WM_SET_DBSVALUE   (WM_USER + 1006)  //���õ�ͼ���л���ֵ   wParam , long��ָ�룬�洢�л���ֵ��lParam
											//��ֵ�ĸ���
#define WM_GET_MSDSTATE   (WM_USER + 1007)  //

#define	WM_GET_PRODUCT_LIST (WM_USER + 1008)  //��ȡ��Ʒ�б�

#define WM_DISP_DBS			  (WM_USER + 6000)
#define WM_DISP				  (WM_USER + 4000)
#define WM_SET_RELTFILEPATH	  (WM_USER + 7000)
#define WM_GET_RELTFILEPATH	  (WM_USER + 7001)
#define WM_GET_PROJECT_PATH	  (WM_USER + 7002)			//��ȡ��Ŀ·��

#define CMD_2D_TOOL_RECT_INFO	(WM_USER+0x9000)		//����TOOL
#define CMD_2D_TOOL_LIN_INFO	(WM_USER+0x9002)		//��·TOOL
#define CMD_2D_TOOL_REG_INFO	(WM_USER+0x9001)		//�����TOOL
#define CMD_2D_TOOL_CIR_INFO	(WM_USER+0x9003)		//Բ��TOOL
#define CMD_2D_TOOL_MAPLAY_INFO	(WM_USER+0x9004)		//����Ҫ��TOOL

const string	CMD_CONTAINER_LBUTTON_UP_GET_CUR_SEL_LAYER = "��ȡ��ǰѡ��ͼ��";

#endif //_OGGEO3DMSGIDDEF_H