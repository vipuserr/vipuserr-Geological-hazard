#ifndef _G2DTOOL_DEF_H
#define _G2DTOOL_DEF_H

#include <windows.h>
#include <vector>
#include <string>
using namespace std;

#include "gmeStru.h"
#include "OGMessageListener.h"
#include "OGGeo3dMsgIDDef.h"

namespace Smart3dMap
{

	//����\Tool
	#define G2DTOOL_CREATE			0xFFFFE010	//����Tool, wParamΪG2DToolParam *, lParamָ����������,Ҳ�������������Ϣ
	#define G2DTOOL_PIPE			0xFFFFE011	//������Ϣ�ܵ�����, ����ͬ��
	#define G2DTOOL_PNTORECT		0xFFFFE012	//������/���ι���, ����ͬ��
	#define G2DTOOL_LIN				0xFFFFE013	//������·����, ����ͬ��
	#define G2DTOOL_REG				0xFFFFE014	//��������ι���, ����ͬ��
	#define G2DTOOL_CIRCLE			0xFFFFE015	//����Բ�ι���, ����ͬ��
	#define G2DTOOL_MAPLAY			0xFFFFE016	//��������Ҫ�ع���, ����ͬ��
	#define G2DTOOL_LINELAY			0xFFFFE019	//������·Ҫ�ع���, 
	#define G2DTOOL_POINTLAY		0xFFFFE022	//������Ҫ�ع���, ����ͬ��

	#define G2DTOOL_MAPLAY_DLG		0xFFFFE017	//����Ҫ�ع��ߣ����Ի����û�ѡ����������ͬ��
	#define G2DTOOL_LIN_DLG			0xFFFFE018	//��·���ߣ����Ի����û�ѡ���ߣ�����ͬ��
	#define G2DTOOL_PNT_DLG			0xFFFFE023	//�㹤�ߣ����Ի����û�ѡ���ߣ�����ͬ��
	#define G2DTOOL_RELEASE			0xFFFFE000	//ͨ����Ϣ�ͷŵ�ǰTool
	#define G2DTOOL_ACTIVE			0xFFFFE001	//�ڲ���Ϣ�����ڼ���Tool���� zj 2012.3.17

	//���õ�ǰTool����
	#define G2DTOOL_PARAM			0xFFFFE020	//wParamΪG2DToolParam *, lParamΪDWORD
	#define G2DTOOL_PARAM_GET		0xFFFFE021	//wParamΪG2DToolParam *, lParamΪDWORD *

	//Tool���Ʋ������öԻ���
	#define G2DTOOL_CONFIG			0xFFFFE025	//�����������öԻ���, �޲���

	//��ȡ��ǰTool������Ϣ
	#define G2DTOOL_GETTOOL			0xFFFFE030	//wParam Ϊ CG2DBaseTool **, lParam����

	//���λ����Ϣ
	#define G2DTOOL_MOUSEMOVE_POS	0xFFFFE210	//����ƶ�ʱ���ⷢ���߼�����,wParamΪ��ǰ�����, lParamΪ gme_vector2d *
	#define G2DTOOL_LBTNDOWN_POS	0xFFFFE211	//������ʱ���ⷢ���߼�����,wParamΪ��ǰ�����, lParamΪ gme_vector2d *

	//���ƶ����
	#define G2DTOOL_DRAWREGEAGE		0xFFFFE220	//���ƶ����,wParamΪ��ǰ�����, lParamΪ gme_vector2d *
	#define G2DTOOL_DRAWREGEAGE2	0xFFFFE221	//���ƶ����(���),wParamΪ��ǰ�����, lParamΪ gme_vector2d *

	//��˸��Ϣ
	#define G2DTOOL_FLASH_LAY		0xFFFFE222	//��˸��Ϣ��wParam��˸�ı�־��1��ʾ����2��ʾ�ߣ�3��ʾ�㣩, lParamΪ DOT

	//Tool��ɺ󷵻���Ϣ�ţ��������ʹ�÷�������
	#define G2DTOOL_PIPE_INFO		0xFFFFE049	//�ܵ���Ϣ, wParam Ϊ MsgParam *, lParam Ϊ DWORD

	//Toolȡ��ʱ�㲥��Ϣ
	#define G2DTOOL_CANCEL			0xFFFFE060	//Toolȡ��ʱ���ⷢ��֪ͨ,wParamΪTool����,lParamΪlFuncID

	//��ȡTool�Ľ����Ϣ
	#define G2DTOOL_GET_DOTLIST		0xFFFFE080	//��ȡ���б�, 
	#define G2DTOOL_GET_RECTLIST 	0xFFFFE081	//��ȡ�����б�
	#define G2DTOOL_GET_LINLIST		0xFFFFE082	//��ȡ���б�
	#define G2DTOOL_GET_REGLIST		0xFFFFE083	//���������(ͨ�ã��Ƽ�)
	#define G2DTOOL_GET_CIRLIST		0xFFFFE084	//Բ������
	#define G2DTOOL_GET_MAPLAY		0xFFFFE085	//����Ҫ������
	#define G2DTOOL_GET_REGLIST2	0xFFFFE086	//���������,�Զ�����ͶӰ����(ͨ�ã��Ƽ�)

	#define MSG_DRAW_INTERACTOR_RANGE		(WM_USER+0x20121010)	//����Ȧ����Χ



		enum G2DQueryType
		{
			G2D_COMM_QUERY = 0,	//ͨ�ò�ѯ��ͨ����꽻������ʽѡ��Χ
			G2D_DIS_QUERY = 1,	//����ȥ��ѯ
			G2D_MAPORRECT_QUERY = 2,	//��Χ����ͼ����ѯ
			G2D_SYN_QUERY = 3,	//�ۺϲ�ѯ
		};

		//������������
		enum G2DToolType
		{
			G2DTT_PIPE = 0,		//Pipeֻ������Ϣת��
			G2DTT_PNT_RECT = 1,	//��
			G2DTT_LIN = 2,		//��
			G2DTT_REG = 3,		//�����
			G2DTT_CIR = 4,		//Բ��
			G2DTT_MAPLAY = 5,	//����Ҫ��
			G2DTT_MAPLAY_DLG = 6,//����Ҫ��(���Ի���)
			G2DTT_LIN_DLG = 7,	//��·(���Ի���)
			G2DTT_LINELAY = 8,	//��·Ҫ��
			G2DTT_POINTLAY = 9,	//��Ҫ��
			G2DTT_PNTLAY_DLG = 10//��Ҫ��(���Ի���)
		};

		//��������ģʽ
		enum G2DToolMode
		{
			G2DTM_SINGLE = 0,	//����ʹ�ã�������ɺ��ͷ�Tool
			G2DTM_RETAIN = 1	//�������ʹ�ã���ʾ�ڽ�����ɺ󻹿��Լ�������
		};

		//Tool��������
		typedef struct G2DTOOL_PARAM_STRUCT
		{
			G2DToolType	m_Type;			//���Tool����
			G2DToolMode	m_Mode;			//��ѡ��Toolģʽ������ʹ�á��������ʹ�ã�
			COGListener	*m_pListener;	//��ѡ��ָ����������Tool��ɺ���Ϣ���Ͷ�����this������ָ����㲥
			long		m_lFuncID;		//���ָ���ط���Ϣ��
			string		m_strFuncID;		//���ָ���ط���Ϣ��
			long		m_lFuncCurID;	//��ѡ������������ʵʱ��Ϣ
			BOOL		m_bCalcBuf;		//��ѡ����·���߿�����
			WPARAM		m_wParam;		//��ѡ�������ɵ����߽���
			LPARAM		m_lParam;		//��ѡ�������ɵ����߽���

			G2DTOOL_PARAM_STRUCT()
			{
				m_Type = G2DTT_PNT_RECT;
				m_Mode = G2DTM_SINGLE;
				m_pListener = 0;
				m_strFuncID = "";
				m_lFuncID = -1;
				m_lFuncCurID = 0;
				m_bCalcBuf = FALSE;
				m_wParam = 0;
				m_lParam = 0;
			}
		}G2DToolParam;



		//Tool�ڲ��������Ͷ���
		typedef	std::vector<gme_vector2d>	LinDots;	//��
		typedef	std::vector<gme_vector2d>	RegDots;	//��
		typedef	std::vector<gme_vector2d>	DotList;	//���б�
		typedef	std::vector<gme_rect_2d>	RectList;	//�����б�
		typedef	std::vector<LinDots>		LinList;	//���б�
		typedef	std::vector<RegDots>		RegList;	//������б�
		typedef	std::vector<gme_circle>		CircleList;	//Բ�б�
}
#endif	//_G2DTOOL_DEF_H