  #pragma once
#include "OGBasDef.h"


namespace Smart3dMap {

	//������Ϣ������Smart3dMap������¼�������ʱ�õ�
	//Event������Ӧ�ó���������

	#define OG_MSG_DATABASE_UPDATE				0xEE00E000			// ���ݿ�����˸���
	#define OG_MSG_DATABASE_CHANGE_USER		0xEE00E001			// ���ݿ��û�����	

	#define OG_MSG_LAYER_ADD					0xEE00E100			// ��Ӳ�ʱ, lParam�а�����ָ��COGLayer*����ָ��
	#define OG_MSG_LAYER_DIALOG_ADD			0xEE00E101			// �Ի�����Ӳ�	
		
	#define OG_MSG_LAYER_DIALOG_ADD_CHILD		0xEE00E102			// �Ի��������ͼ��	
	#define OG_MSG_LAYER_ADD_CHILD				0xEE00E103			// �����ͼ��
	#define OG_MSG_LAYER_REMOVE_CHILD		    0xEE00E104			// ɾ����ͼ��

    #define OG_MSG_LAYER_DELETE				0xEE00E105			// ɾ��һ����
	#define OG_MSG_LAYER_UPDATE				0xEE00E106			// �����
	#define OG_MSG_LAYER_ORDER_CHANGED			0xEE00E107			// ���ڹ������е�����˳�����ı�
    #define OG_MSG_LAYER_DBCLICK               0xEE00E108			// ��˫��
	#define OG_MSG_LAYER_ELEMENT_DBCLICK       0xEE00E109			// ��Ԫ��˫��
	#define OG_MSG_LAYER_EMPTY					0xEE00E110			// ��ղ�Ԫ��	
	#define OG_MSG_LAYER_RENAME				0xEE00E111			// ����������
	#define OG_MSG_LAYER_ACTIVATE				0xEE00E112			// �л�����ͼ��
	#define OG_MSG_LAYER_DEACTIVATE			0xEE00E113			// �л�����ͼ��
    #define OG_MSG_LAYER_ACTIVITY_CHANGED		0xEE00E114			// ����ɼ�
	#define OG_MSG_LAYER_VISABLE				0xEE00E115			// ����ͼ��
	#define OG_MSG_LAYER_INVISIBLE				0xEE00E116			// ����ɼ�
	#define OG_MSG_LAYER_VISIBILITY_CHANGED	0xEE00E117			// ����ɼ�	
	#define OG_MSG_LAYER_ELEMENT_VISIBILITY_CHANGED	0xEE00E118	// ��Ԫ�ظı�
	
    #define OG_MSG_LAYER_PROPERTY				0xEE00E119			// ��Ԫ��
	#define OG_MSG_LAYER_ELEMENT_PROPERTY		0xEE00E120			// ��Ԫ��
	
	
	#define OG_MSG_ENTITY_ADD					0xEE00F000
	#define OG_MSG_ENTITY_DELETE				0xEE00F001
	#define OG_MSG_ENTITY_UPDATE				0xEE00F002
	#define	OG_MSG_ENTITY_VIEW_PROP_DICTIONARY 0xEE00F003			// �鿴ʵ��ļ��β����ֵ�. lParam  ָ��C3DEntity��ָ��
	#define OG_MSG_FEATURE_ADD					0xEE00F100
	#define OG_MSG_FEATURE_UPDATE				0xEE00F101
	#define OG_MSG_FEATURE_DELETE				0xEE00F102
	#define OG_MSG_FEATURE_CLASS_ADD			0xEE00F200
	#define OG_MSG_FEATURE_CLASS_UPDATE		0xEE00F201
	#define OG_MSG_FEATURE_CLASS_DELETE		0xEE00F202
	#define	OG_MSG_FEATURE_VIEW_PROP_DICTIONARY 0xEE00F203			// �鿴Ҫ�ص�������Ϣ�������ֵ䣩. lParam  ָ��FEATUREID��ָ��
	
    #define	OG_MSG_VIEW_PROP_DICTIONARY        0xEE00F204			// �鿴������Ϣ�������ֵ䣩. lParam��ָ��PRAMADIC��ָ��
	#define	OG_MSG_EMPTY_PROP_DICTIONARY       0xEE00F205			// ��ղ����ֵ�
    #define OG_MSG_VIEW_MODIFY_PROP_DICTIONARY	0xEE00F206			// ��ղ����ֵ�

	#define OG_MSG_SUBFRAME_ADD				0xEE00F300			// ����һ���µ���ͼӦ�ÿ�� lParam  ָ��CSubFrame��ָ��
	#define OG_MSG_SUBFRAME_STATE_ADD			0xEE00F400			// ����һ���µ���ͼӦ��״̬ wParam  ״̬�� DWORD ֵ, lParam  ָ��CSubFrame��ָ��

	#define OG_MSG_SOLUTION_ADD				0xEE00F500			// �����µĽ������, lParam ָ��ProjectConfigFileHeader*���͵�ָ��

	#define OG_MSG_TERRAIN_ACTIVE				0xEE00F600			// ���õ���Ϊ��ǰ���� , lParam ָ��CTerrainPluginBase*���͵�ָ��

	#define OG_MSG_LOCAL_ENTITY_ADD			0xEE00F700
	#define OG_MSG_LOCAL_ENTITY_DELETE			0xEE00F701
	#define OG_MSG_LOCAL_ENTITY_UPDATE			0xEE00F702
	#define OG_MSG_LOCAL_CONTAINER_ADD			0xEE00F703
	#define OG_MSG_LOCAL_CONTAINER_DELETE		0xEE00F704
	#define OG_MSG_LOCAL_CONTAINER_UPDATE		0xEE00F705
	#define OG_MSG_LOCAL_3DLOCATE				0xEE00F706	//��ά������λ
	#define OG_MSG_LOCAL_3DLOC_DISP_COORDSTR	0xEE00F707	//��ʾ������λ����
	#define OG_MSG_TELL_WORKSPACCE_ACTIVE_VIEW	0xEE00F708 //������ͼ
	#define OG_MSG_GET_PRO_USERTABLE_CHINESE	0xEE00F709 //������ͼ




	//containerMsg
				// ����������Ϣ
		#define OG_MSG_CONTAINER_CREATE				0x0000E100	// ��Ӳ�ʱ, lParam�а�����ָ��Container*����ָ��
		#define OG_MSG_CONTAINER_ADD					0x0000E101	// ��Ӳ�ʱ, lParam�а�����ָ��Container*����ָ��
		#define OG_MSG_CONTAINER_REMOVE				0x0000E102	// ɾ��һ����
		#define OG_MSG_CONTAINER_DESTROY				0x0000E103	// ɾ��һ����
		#define OG_MSG_CONTAINER_EMPTY					0x0000E104	// ��ղ�Ԫ��	
		#define OG_MSG_CONTAINER_NAME_CHANGED			0x0000E105	// ����������
		#define OG_MSG_CONTAINER_REM_DEST_ALL_CHILDREN	0x0000E106	// ɾ��������
			
		#define OG_MSG_CONTAINER_UPDATE				0x0000E107	// �����
		#define OG_MSG_CONTAINER_DBCLICK				0x0000E109	// ��˫��
		#define OG_MSG_ELEMENT_DBCLICK		0x0000E110	// ��Ԫ��˫��
			
		#define OG_MSG_CONTAINER_SELECT_CHANGED		0x0000E111	// ��������ɼ��ı�
		#define OG_MSG_CONTAINER_VISIBILITY_CHANGED	0x0000E112	// �����ɼ��ı�
		#define OG_MSG_ELEMENT_VISIBILITY_CHANGED 0x0000E113	// ��Ԫ�ظı�
		#define OG_MSG_ACTIVE_CONTAINER_CHANGED		0x0000E114 // ��ǰ�����仯
			
		#define OG_MSG_CONTAINER_FREEZE_CHANGED		0x0000E115 // ����freeze�仯
		#define OG_MSG_ELEMENT_FREEZE_CHANGED 0x0000E116 // ����Ԫ��freeze�仯
			
		#define OG_MSG_CONTAINER_LOCK_CHANGED			0x0000E117 // ����lock�仯
		#define OG_MSG_ELEMENT_LOCK_CHANGED	0x0000E118 // ����lock�仯
			
		#define OG_MSG_ELEMENT_NAME_CHANGED	0x0000E119	// ��Ԫ����������
			
		#define OG_MSG_CONTAINER_ATTACH_OBJECT			0x0000E130	// ��Ԫ�ظı�
		#define OG_MSG_CONTAINER_DETACH_OBJECT			0x0000E131	// ��Ԫ�ظı�
		#define OG_MSG_CONTAINER_DETACH_ALL_OBJECTS	0x0000E132	// ��Ԫ�ظı�
		#define OG_MSG_CONTAINER_ORDER_CHANGED			0x0000E133	// ���ڹ������е�����˳�����ı�
		#define OG_MSG_ELEMENT_SELECT_CHANGED 0x0000E134 // ��Ԫ�ظı�
			
			
		#define OG_MSG_CONTAINER_SCALE_CHANGED 0x0000E135 // ����������ı�
		#define OG_MSG_ELEMENT_SCALE_CHANGED	0x0000E136 // Ԫ�ر��������ı�

		#define OG_MSG_CONTAINER_SPANDED 0x0000E137 // ��չ��������

		#define OG_MSG_CONTAINER_SCENE_DETAIL_LEVEL_CHANGED 0x0000E138 // ����ʾģʽ�ı�
		#define OG_MSG_ELEMENT_SCENE_DETAIL_LEVEL_CHANGED 0x0000E139   // Ԫ����ʾģʽ�ı�

		#define OG_MSG_CONTAINER_DISL_ALL 0x0000E140   // ��ʾ�������������ݲ�


		//����Ϣʵ�ֶ�άͼ�㴴�����ʱ֪ͨ��������ͬ�����������ռ��½��ʹ��
		//2008-12-02 
		#define	OG_MSG_CREATE_DATACENTER_NODE 0x0000E141			//���������ռ���	

		#define	OG_MSG_SET_DATACENTER_NODE_ALIASNAME 0x0000E142	//���ù����ռ���ı���		

		#define	OG_MSG_CHECK_DATACENTER_NODE_VALID 0x0000E143	//���ڵ㴴���Ƿ�Ϸ�
		//  [3/5/2015 Feng]
		#define	OG_MSG_ADD_ELEMENT_CHILD 0x0000E144	//�����ӽڵ�
		#define OG_MSG_ACTIVE_ElEMENT_CHANGED 0x0000E145 // ���û����Ԫ�ط����仯
		#define OG_MSG_EXPAND_CONTAINER_CHANGED 0x0000E146 // չ�����ڵ�
		#define OG_MSG_CHANGE_LAYER_ICON_HANDLE	0x0000E147 //�ı�ͼ��ͼ��, wParam ָ��Container*���͵�ָ�룬lParamΪint���ͣ���ʾICON�ı�ţ�������Ҫ�ı��ֵ��������ǰֵ
		#define OG_MSG_CHANGE_ELEMENT_ICON_HANDLE	0x0000E148 //�ı�Ԫ��ͼ��, wParam ָ��Element*���͵�ָ�룬lParamΪint���ͣ���ʾICON�ı�ţ�������Ҫ�ı��ֵ��������ǰֵ
		#define OG_MSG_ELEMENT_EDIT_CHANGED 0x0000E149  // ��Ԫ�ر༭״̬�ı�
	
 
	#define WM_GET_OPENEND_LAYERLIST	(WM_USER+0x9007)	//
//TwoDimenView Message
	const string STR_2DVIEW_RBUTTDOUBLECLICK_PRO = "��ά��ͼ��Ϣ�Ҽ�˫������";
	const string STR_2DVIEW_RBUTTDOWN_PRO = "��ά��ͼ��Ϣ�Ҽ����´���";
	const string STR_2DVIEW_RBUTT_PRO = "��ά��ͼ��Ϣ�Ҽ�����";

	const string STR_2DVIEW_LBUTTDOWN_PRO = "��ά��ͼ��Ϣ������´���";
	const string STR_2DVIEW_LBUTTUP_PRO = "��ά��ͼ��Ϣ���������";
	const string STR_2DVIEW_LBUTTSOUBLECLICK_PRO = "��ά��ͼ��Ϣ���˫������";
	const string STR_2DVIEW_ONPAINT_PRO = "��ά��ͼ��Ϣ�ػ洦��";

	const string STR_2DVIEW_ONMOUSEMOVE_PRO = "��ά��ͼ��Ϣ����ƶ�����";
	const string STR_2DVIEW_ONMOUSEWHEEL_PRO = "��ά��ͼ��Ϣ����м�����";

	const string STR_HISVIEW_RBUTTDOUBLECLICK_PRO = "��ά��״��ͼ��Ϣ�Ҽ�˫������";
	const string STR_HISVIEW_RBUTTDOWN_PRO = "��ά��״��ͼ��Ϣ�Ҽ����´���";
	const string STR_HISVIEW_RBUTT_PRO = "��ά��״��ͼ��Ϣ�Ҽ�����";

	const string STR_HISVIEW_LBUTTDOWN_PRO = "��ά��״��ͼ��Ϣ������´���";
	const string STR_HISVIEW_LBUTTUP_PRO = "��ά��״��ͼ��Ϣ���������";
	const string STR_HISVIEW_LBUTTSOUBLECLICK_PRO = "��ά��״��ͼ��Ϣ���˫������";
	const string STR_HISVIEW_ONPAINT_PRO = "��ά��״��ͼ��Ϣ�ػ洦��";

	const string STR_HISVIEW_ONMOUSEMOVE_PRO = "��ά��״��ͼ��Ϣ����ƶ�����";
	const string STR_HISVIEW_ONMOUSEWHEEL_PRO = "��ά��״��ͼ��Ϣ����м�����";

	const string G2DVIEW_MAPGIS2DREALVIEWGET  ="��ά��ͼ��Ϣ��ȡ����";
	const string G2DVIEW_MAPGIS2DREGET  ="��ά��Ⱦ��ͼ��Ϣ��ȡ����";
	const string G2DVIEW_GET2DGISVIEWBASE  ="��ȡ2DGISBaseView";
	const string G2DVIEW_GETCURRENT2DTOOL  ="��ȡ�Ƿ����Tool";
	const string G2DVIEW_STOPCURRENT2DTOOL  ="����ֹͣ��ǰTool�Ĳ���";

	const string G2DHISVIEW_MAPGIS2DREALVIEWGET  ="��ά��״��ͼ��Ϣ��ȡ����";
	const string G2DHISVIEW_MAPGIS2DREGET  ="��ά��״��Ⱦ��ͼ��Ϣ��ȡ����";
	const string G2DHISVIEW_GET2DGISVIEWBASE  ="��ȡ��״2DGISBaseView";
	const string G2DHISVIEW_GETCURRENT2DTOOL  ="��ȡ��״�Ƿ����Tool";
	const string G2DHISVIEW_STOPCURRENT2DTOOL  ="������״ֹͣ��ǰTool�Ĳ���";

//DatabaseView Message
	const string STR_DBVIEW_RBUTTDOUBLECLICK_PRO = "������ͼ��Ϣ�Ҽ�˫������";
	const string STR_DBVIEW_RBUTTDOWN_PRO = "������ͼ��Ϣ�Ҽ����´���";
	const string STR_DBVIEW_RBUTTUP_PRO = "������ͼ��Ϣ�Ҽ�̧����";

	const string STR_DBVIEW_LBUTTDOWN_PRO = "������ͼ��Ϣ������´���";
	const string STR_DBVIEW_LBUTTUP_PRO = "������ͼ��Ϣ���������";
	const string STR_DBVIEW_LBUTTSOUBLECLICK_PRO = "������ͼ��Ϣ���˫������";
	const string STR_DBVIEW_ONPAINT_PRO = "������ͼ��Ϣ�ػ洦��";

	const string STR_DBVIEW_ONMOUSEMOVE_PRO = "������ͼ��Ϣ����ƶ�����";
	const string STR_DBVIEW_ONMOUSEWHEEL_PRO = "������ͼ��Ϣ����м�����";
	const string GDBVIEW_GETDBVIEWBASE = "��ȡ���ݿ���ͼ";

//ThreeDimensionView Message
	const string G3DVIEW_GETTHREECONTAINERVIEW  ="��ȡ��ά�зָ�����";
	const string G3DVIEW_GET3DGISGEOVIEW        ="��ȡ3DOGGeo3DView";
	const string G3DVIEW_GETPROJECTGISGEOVIEW   ="��ȡˮƽͶӰView";
	const string G3DVIEW_GETPLATFORMGISGEOVIEW  ="��ȡ��ֱͶӰView";
	const string G3DVIEW_3D_OPEN_T3DFILE        = "���ڵ���Ϣ_����άģ��";
	const string G3DVIEW_3D_CLOSE_T3DFILE       = "���ڵ���Ϣ_�ر�����ģ��";
	const string G3DVIEW_3D_DISP_T3DFILE        = "���ڵ���Ϣ_��ʾ����ģ��";	
	const string G3DVIEW_3D_DELETE_T3DFILE      = "���ڵ���Ϣ_�Ƴ�����ģ��";	
}