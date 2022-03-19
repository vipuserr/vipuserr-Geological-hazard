#pragma once

#include <vector>
#include "OGBasDef.h"

#pragma warning(disable : 4786) //ȥ��vectorǶ�������ľ���
#pragma warning(disable : 4251) //ȥ���ɽṹ���������ľ���
#pragma warning(disable : 4275) //ȥ����GRIDCTRL�����ľ���
#pragma warning(disable : 4103)
#pragma warning(disable : 4244)
#pragma warning(disable : 4018)
 
class CDatDictOper;
typedef class CDatDictOper* CBaseInfoMngObj;
//----------------------------ҵ���߼�ͳ�Ʒ����ṹ-----------------------------//
typedef struct StatParam_Stru {
	long				lNum;		//������
	double				dMax;		//���ֵ
	double				dMin;		//��Сֵ
	double				dAvg;		//������ֵ
	double				dVar;		//��������
	double				dMid;		//��λ��
	double				dDif;		//����ϵ��
}StatParam,*LPSTATPARAM;

//���Ƶ����ͺ궨��
#define CTRL_PNT_TYPE_STRAT				0					//�ز�����ϵĿ��Ƶ�
#define CTRL_PNT_TYPE_HOLE				1					//��׹켣���ϵĿ��Ƶ�
#define CTRL_PNT_TYPE_SECT				2					//����߽����ϵĿ��Ƶ�
#define CTRL_PNT_TYPE_FAULT				3					//�ϲ��ϵĿ��Ƶ�
#define CTRL_PNT_TYPE_PINCH				4					//�ز����Ŀ��Ƶ�

#define STRAT_CODE_LEN		(20+1)//�ز��ų���

#define PROJ_STRIPNO_SH		21

//-----------------------------------------------------------------------------
// �ͷ���Դ�ĺ�
//-----------------------------------------------------------------------------
#define GME_SAFE_DELETE(p)       { if(p) { delete (p);     (p)=NULL; } }
#define SAFE_DELETE_ARRAY(p) { if(p) { delete[] (p);   (p)=NULL; } }
#define SAFE_RELEASE(p)      { if(p) { (p)->Release(); (p)=NULL; } }
#define SAFE_DELETE_BYTE_ARRAY(p) { if(p) { delete[] (char*)(p);   (p)=NULL; } }

//������ͺ궨��
#define ALL_BORE_HOLE					DZ			//�����������
#define BR_BORE_HOLE					DJY			//����������
#define Q_BORE_HOLE						DDS			//���ļ͵������
#define HD_BORE_HOLE					DSW			//ˮ�ĵ������
#define RSEG_BORE_HOLE					DGC			//�������̵������
#define REG_BORE_HOLE					DGCQZK		//���򹤳̵������
//��׷ֲ�ԭʼ���ݱ�ͨ���ֶγ���
#define  LEN_DSAC                        (20+1)    //ʱ��ϵ
#define  LEN_DSAD                        (20+1)    //ʱ��ͳ
#define  LEN_DCDH                        (20+1)    //�ز����
#define  LEN_TKALA                       (20+1)  //�׺�
#define  LEN_YXTZ                        (2048+1)//��������

//----------------------------ͨ�����ݱ��ֶγ���-----------------------------//
#define LEN_BOREHOLE_CODE			16		//��ױ��볤��
#define LEN_TABLE_DEPT				16		//���ݱ��е�λ�����ֶγ���
#define LEN_TABLE_NOTE				128		//���ݱ��б�ע�ֶγ���
#define LEN_STRAT_LEVEL				12		//�ز㼶����볤��
#define LEN_SAMPLE_CODE				16		//��Ʒ���볤��
#define LEN_SAMPLE_NAME				16		//��Ʒ���Ƴ���
#define LEN_PERSON_NAME				16		//���ݱ��������ֶγ���
#define LEN_FAULT_CODE				16		//�ϲ���볤��
//--------------------------------����������ݱ��ֶγ���---------------------//
#define LEN_HOLEATT_SITE			64	//��׿�λ
#define LEN_HOLEATT_DIST			32	//��������
#define LEN_HOLEATT_TOWN            32	//����
#define LEN_HOLEATT_DATSRC          64	//������Դ


//----------------------------�ֲ��������ݱ��ֶγ���-------------------------//
#define LEN_LAYERATT_ROCK_TYPE		64		//�ֲ�������ʯ����
#define LEN_LAYERATT_ROCK_DESC		512		//�ֲ�������ʯ����
#define LEN_LAYERATT_STRU			32		//������
#define LEN_LAYERATT_SEDI			16		//������
#define LEN_LAYERATT_SEDI_NAME      16		//����ѧ����
#define LEN_LAYERATT_SOIL_NAME		16		//����ѧ����
//----------------------------ͨ���ֶ����ƺ궨��-----------------------------//
#define FLD_HOLE_ID                  "HoleID"   //���ID��
#define FLD_HOLE_CODE				 "HoleCode" //��ױ���
#define FLD_HOLE_X                   "X"        //X����
#define FLD_HOLE_Y                   "Y"        //Y����
#define FLD_HOLE_HEIGHT				 "Height"	//��ױ��
#define FLD_HOLE_DEPTH				 "Depth"	//������
#define FLD_HOLE_TYPE                "Type"		//�������
#define FLD_HOLE_FLAG				 "KNumber"	//�Ƿ��ǽ������ݣ�>0��������
#define FLD_HOLE_FILE_NO             "FileNo"	//������


#define FLDCH_HOLE_ID                "���ID��"
#define FLDCH_HOLE_CODE				 "��ױ���"
#define FLDCH_HOLE_X                 "X����"
#define FLDCH_HOLE_Y                 "Y����"
#define FLDCH_HOLE_HEIGHT			 "��ױ��"
#define FLDCH_HOLE_DEPTH			 "������"
#define FLDCH_HOLE_TYPE				 "�������"
#define FLDCH_HOLE_FLAG				 "�Ƿ����"

#define FLD_HOLE_LEVEL               "HoleLevel" //��׼���
#define FLD_HOLE_WATER_LEVEL         "WATERLEVEL"//���ˮλ
#define FLD_HOLE_START_DATE          "STARTDATE" //��׿�������
#define FLD_HOLE_END_DATE			 "ENDDATE"   //����깤����
#define FLD_HOLE_ENGINEER	         "Engineer"  //��׹���ʦ
#define FLD_HOLE_ATTRIBUTE			 "ATTRIBUTE" //�������
#define FLD_HOLE_NOTE				 "Note"      //��ױ�ע
#define FLD_HOLE_NO                  "HoleNo"    //��ױ��
#define FLD_LAYER_NO                 "LayerNo"   //�ֲ���
#define FLD_SOIL_NO                  "SoilNo"    //�������
#define FLD_HOLE_LONGITUDE           "Longitude" //����
#define FLD_HOLE_LATITUDE            "Latitude"  //γ��
#define FLDCH_HOLE_LEVEL             "��׼���" 
#define FLDCH_HOLE_WATER_LEVEL       "���ˮλ" 
#define FLDCH_HOLE_START_DATE        "��׿�������" 
#define FLDCH_HOLE_END_DATE			 "����깤����" 
#define FLDCH_HOLE_ENGINEER	         "��׹���ʦ" 
#define FLDCH_HOLE_ATTRIBUTE		 "�������" 
#define FLDCH_HOLE_NOTE				 "��ױ�ע" 
#define FLDCH_HOLE_NO                "��ױ��"  
#define FLDCH_LAYER_NO               "�ֲ���" 
#define FLDCH_SOIL_NO                "�������"  
#define FLDCH_HOLE_LONGITUDE         "����" 
#define FLDCH_HOLE_LATITUDE          "γ��" 

#define FLD_STRATVER_ID				 "StdStratID"//��׼�ز�汾��
#define FLD_STRATDESC_LEVEL			 "StratLevel"//��׼�ز�ز㼶�����
#define FLD_STRATDESC_TOPDEPTH		 "TopDepth" //�ز㶥�����
#define FLD_STRATDESC_BTMDEPTH		 "BtmDepth" //�ز�װ����
#define FLD_STRATDESC_THICKNESS		 "Thickness"//�ز���
#define FLD_SOIL_ID                  "SoilID"   //����ID��
#define FLD_PRO_ID                   "ProID"     //רҵ����
#define FLD_ROCK_TYPE                "RockType"  //��ʯ����
#define FLD_ROCK_DESC                "RockDesc"  //��ʯ����

#define FLDCH_STRATVER_ID			 "��׼�ز�汾��"
#define FLDCH_STRATDESC_LEVEL		 "��׼�ز�ز㼶�����"
#define FLDCH_STRATDESC_TOPDEPTH	 "�ز㶥�����" 
#define FLDCH_STRATDESC_BTMDEPTH	 "�ز�װ����" 
#define FLDCH_STRATDESC_THICKNESS	 "�ز���"
#define FLDCH_SOIL_ID                "����ID��"   
#define FLDCH_PRO_ID                 "רҵ����"     
#define FLDCH_ROCK_TYPE              "��ʯ����"  
#define FLDCH_ROCK_DESC              "��ʯ����"  



#define FLD_SOIL_TYPE                "SoilType"		//��������
#define FLD_SAMP_STARTDEP            "StartDep"		//��ʼ���
#define FLD_SAMP_ENDDEP              "EndDep"		//��ֹ���
#define FLD_SOIL_COLOR               "SoilColor"	//������ɫ

#define FLDCH_SOIL_TYPE              "��������"		
#define FLDCH_SAMP_STARTDEP          "��ʼ���"		
#define FLDCH_SAMP_ENDDEP            "��ֹ���"		
#define FLDCH_SOIL_COLOR             "������ɫ"


//���������׷ֲ�����
#define FLD_LAYERATT_ROCKLEN        "RockLen"   //�ҿ�о��       
#define FLD_LAYERATT_ROCKRATIO      "RockRatio" //������
#define FLD_LAYERATT_ANGLE          "Angle"     //��־����������н�	        
#define FLD_LAYERATT_TOPINTER       "TopInter"  //�ϲ�Ӵ���ϵ
#define FLD_LAYERATT_BTMINTER       "BtmInter"  //�²�Ӵ���ϵ
#define FLD_LAYERATT_DIR            "Dir"	    // ���� 
#define FLD_LAYERATT_TEND           "Tend"      // ����  
#define FLD_LAYERATT_OBLIQUITY      "Obliquity" //���

#define FLDCH_LAYERATT_ROCKLEN      "�ҿ�о��"
#define FLDCH_LAYERATT_ROCKRATIO    "������" 
#define FLDCH_LAYERATT_ANGLE        "��־����������н�"
#define FLDCH_LAYERATT_TOPINTER     "�ϲ�Ӵ���ϵ"
#define FLDCH_LAYERATT_BTMINTER     "�²�Ӵ���ϵ"
#define FLDCH_LAYERATT_DIR          "����"
#define FLDCH_LAYERATT_TEND         "����"
#define FLDCH_LAYERATT_OBLIQUITY    "���" 


//-------------------------��ά���Խ�ģ�Ի���--------------------//

#define ATT3D_BUILD_MODEL_DLG				0		//��ά���Խ�ģ�Ի���
#define CREATE_ISOLINE_DLG					1		//׷�ٵ�ֵ�߶Ի���

//------------------------- ͼ������-------------------------------//
#define CREATE_VER_CHART                    0       //����ֱ��ͼ
#define CREATE_PIE_CHART                    1       //���ɱ�ͼ
#define CREATE_CURV_CHART                   2       //��������ͼ




//��λ��ʾ����
#define HD_ESTAB_CODE_LEN		128						//��ʩ���볤��
#define DISP_DOT_CODE_LEN		HD_ESTAB_CODE_LEN		//��ʩ���볤��




typedef struct LinStrcT //�߽ṹ
{
	Vector2		*pLinDots;
	long		lDotNum;
}LinStrcT;

typedef struct CircleStrcT //Բ�ṹ
{
	Vector2		dOrgDot;
	double		dRadius;
}CircleStrcT;

typedef std::vector<Vector2> ToolRegDots;
typedef std::vector<Vector2> ToolLinDots;

 
#define STRAT_NAMELEN	40
#define STRAT_CODELEN	20
#define STRAT_NOLEN			 20    //�ز���ų���

#define FLDNAME_STRATCODE			"StratCode"		//�ز���
#define FLDNAME_STRATNO				"StratNo"		//�ز����
#define FLDNAME_STRATNAME			"StratName"		//�ز�����
