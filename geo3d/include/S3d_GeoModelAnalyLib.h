#pragma once

#include "s3d_geomodelanalylib_global.h"
#include "DummyHoleProtoStru.h"


class S3D_GEOMODELANALYLIB_EXPORT S3d_GeoModelAnalyLib
{
public:
	static S3d_GeoModelAnalyLib* getSingletonPtr();
   

	//三维缓冲分析
	void excuteBufferAnaly();
	//地下室碰撞分析
	void excuteCollisionAnaly();

	//模型可信度验证
	void excuteModelReliability();
	
	//三维模型切割
	void excuteModelCut();
	//模型切割功能拆分
	void excuteModelCutPlaneCut(); //平面切割
	void excuteModelCutLineCut();//折线切割
	void excuteModelCutAnyPlaneCut();//任意平面切割
	void excuteModelCutCombineCut();//基坑开挖
	void excuteModelCutTunnelCut();//隧道模拟
	void excuteModelCutDummyHole();//虚拟钻孔
	
	void excuteDynamicCut();//动态剖切


	//根据模型批量生成虚拟钻孔
	void excuteBatchVHole();
	//模型编辑
	void excuteModelEdit();
	//模型爆炸
	void excuteModelExplosion();
	//三维场景坐标网格
	void excute3DSceneCoord();
	//模型拾取
	void excuteModelPick();
	//钻孔分层拾取
	void excuteHoleLayerInfoPick();
	//钻孔孔径设置
	void excuteHoleSize(__int64 og3dLayer);
	//滑动设置场景比例
	void excuteSceneScaleBySlide();
	//输入设置场景比例
	void excuteSceneScaleByEnter();
	//三维模式切换
	void excuteModeSwitch();
	//场景透明度
	void excuteSceneTranspar();
	//场景背景色
	void excuteSceneBackground();
	//模型包围盒
	void excuteModelBox();
	//模型旋转开关
	void excuteMdlRotateSwitch();
	//模型复位
	void excuteMdlResetPos();
	//OSG坐标系
	void excuteOSGAXIS();
	//天空盒
	void excuteSkyBox();
	//显示第三方模型
	void excuteShowOtherMdl();
	//三维模型检查修复
	void excuteMdlCheckRevise();
	//场景漫游
	void excuteSceneRoaming();
	//曲面动画
	void excuteSurfaceAnimation();

	//grpc -- 生成虚拟钻孔
	void excuteProtoDummyHole(DummyHoleProto& dummyholeProto);

	//河北地下水判别
	void excuteUnderWaterJudgeForm();

private:
	S3d_GeoModelAnalyLib();
	~S3d_GeoModelAnalyLib();

private:
	__int64 m_parentWidget;

};
