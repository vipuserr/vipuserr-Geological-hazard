#pragma once

#include "s3d_geomodelanalylib_global.h"
#include "DummyHoleProtoStru.h"


class S3D_GEOMODELANALYLIB_EXPORT S3d_GeoModelAnalyLib
{
public:
	static S3d_GeoModelAnalyLib* getSingletonPtr();
   

	//��ά�������
	void excuteBufferAnaly();
	//��������ײ����
	void excuteCollisionAnaly();

	//ģ�Ϳ��Ŷ���֤
	void excuteModelReliability();
	
	//��άģ���и�
	void excuteModelCut();
	//ģ���и�ܲ��
	void excuteModelCutPlaneCut(); //ƽ���и�
	void excuteModelCutLineCut();//�����и�
	void excuteModelCutAnyPlaneCut();//����ƽ���и�
	void excuteModelCutCombineCut();//���ӿ���
	void excuteModelCutTunnelCut();//���ģ��
	void excuteModelCutDummyHole();//�������
	
	void excuteDynamicCut();//��̬����


	//����ģ�����������������
	void excuteBatchVHole();
	//ģ�ͱ༭
	void excuteModelEdit();
	//ģ�ͱ�ը
	void excuteModelExplosion();
	//��ά������������
	void excute3DSceneCoord();
	//ģ��ʰȡ
	void excuteModelPick();
	//��׷ֲ�ʰȡ
	void excuteHoleLayerInfoPick();
	//��׿׾�����
	void excuteHoleSize(__int64 og3dLayer);
	//�������ó�������
	void excuteSceneScaleBySlide();
	//�������ó�������
	void excuteSceneScaleByEnter();
	//��άģʽ�л�
	void excuteModeSwitch();
	//����͸����
	void excuteSceneTranspar();
	//��������ɫ
	void excuteSceneBackground();
	//ģ�Ͱ�Χ��
	void excuteModelBox();
	//ģ����ת����
	void excuteMdlRotateSwitch();
	//ģ�͸�λ
	void excuteMdlResetPos();
	//OSG����ϵ
	void excuteOSGAXIS();
	//��պ�
	void excuteSkyBox();
	//��ʾ������ģ��
	void excuteShowOtherMdl();
	//��άģ�ͼ���޸�
	void excuteMdlCheckRevise();
	//��������
	void excuteSceneRoaming();
	//���涯��
	void excuteSurfaceAnimation();

	//grpc -- �����������
	void excuteProtoDummyHole(DummyHoleProto& dummyholeProto);

	//�ӱ�����ˮ�б�
	void excuteUnderWaterJudgeForm();

private:
	S3d_GeoModelAnalyLib();
	~S3d_GeoModelAnalyLib();

private:
	__int64 m_parentWidget;

};
