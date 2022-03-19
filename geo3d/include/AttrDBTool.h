#pragma once

#include <string>
#include <vector>
#include <map>

#include "s3dAttDBEngine_exp.h"
#include "s3d_AttrDBDef.h"

namespace Smart3dMap
{

	class S3D_ATT_DBENGINE_API AttrDBTool
	{
	public:
		static AttrDBTool* getSingletonPtr();
	protected:
		AttrDBTool();
		virtual ~AttrDBTool();

	protected:
		// 此函数为过渡函数，当直接使用配置而不用解析时，将删。 -- LH.2021.09.02 11:28 added.
		//static std::string parseBaseSqlConfig(BaseSqlConfig base_sql_config);


	public:
		// 档案来源单位表 Bas_DocOrganization
		static void setAttribute(long attri_name, long value, Bas_DocOrganization *result);
		static void setAttribute(long attri_name, double value, Bas_DocOrganization *result);
		static void setAttribute(long attri_name, std::string value, Bas_DocOrganization *result);

		// 项目登记表 Bas_PrjRegistration
		static void setAttribute(long attri_name, long value, Bas_PrjRegistration *result);
		static void setAttribute(long attri_name, double value, Bas_PrjRegistration *result);
		static void setAttribute(long attri_name, std::string value, Bas_PrjRegistration *result);

		// 点位信息表 Bas_PntStdInfo
		static void setAttribute(long attri_name, long value, Bas_PntStdInfo *result);
		static void setAttribute(long attri_name, double value, Bas_PntStdInfo *result);
		static void setAttribute(long attri_name, std::string value, Bas_PntStdInfo *result);

		// 钻孔登记审核表 HoleRegister
		static void setAttribute(long attri_name, long value, HoleRegister *result);
		static void setAttribute(long attri_name, double value, HoleRegister *result);
		static void setAttribute(long attri_name, std::string value, HoleRegister *result);

		// 钻孔基本信息表 HoleInfo
		static void setAttribute(long attri_name, long value, HoleInfo *result);
		static void setAttribute(long attri_name, double value, HoleInfo *result);
		static void setAttribute(long attri_name, std::string value, HoleInfo *result);

		// 钻孔测斜表 HoleInclinat
		static void setAttribute(long attri_name, long value, HoleInclinat *result);
		static void setAttribute(long attri_name, double value, HoleInclinat *result);
		static void setAttribute(long attri_name, std::string value, HoleInclinat *result);

		// 测井基本情况表 HoleLogging
		static void setAttribute(long attri_name, long value, HoleLogging *result);
		static void setAttribute(long attri_name, double value, HoleLogging *result);
		static void setAttribute(long attri_name, std::string value, HoleLogging *result);

		// 标准地层用虚拟钻孔基本信息表 StdStrat_VHole
		static void setAttribute(long attri_name, long value, StdStrat_VHole *result);
		static void setAttribute(long attri_name, double value, StdStrat_VHole *result);
		static void setAttribute(long attri_name, std::string value, StdStrat_VHole *result);

		// 标准地层用虚拟钻孔分层信息表 StdStrat_VHolelLayer
		static void setAttribute(long attri_name, long value, StdStrat_VHolelLayer *result);
		static void setAttribute(long attri_name, double value, StdStrat_VHolelLayer *result);
		static void setAttribute(long attri_name, std::string value, StdStrat_VHolelLayer *result);

		// 探槽观测点信息表 HoleDetect
		static void setAttribute(long attri_name, long value, HoleDetect *result);
		static void setAttribute(long attri_name, double value, HoleDetect *result);
		static void setAttribute(long attri_name, std::string value, HoleDetect *result);

		// 浅井探槽岩性分层描述表 HoleWellSlotLayer
		static void setAttribute(long attri_name, long value, HoleWellSlotLayer *result);
		static void setAttribute(long attri_name, double value, HoleWellSlotLayer *result);
		static void setAttribute(long attri_name, std::string value, HoleWellSlotLayer *result);

		// 电（磁）法勘探线参数表 PhyElecline
		static void setAttribute(long attri_name, long value, PhyElecline *result);
		static void setAttribute(long attri_name, double value, PhyElecline *result);
		static void setAttribute(long attri_name, std::string value, PhyElecline *result);

		// 地震勘探线参数表 PhyEardeteline
		static void setAttribute(long attri_name, long value, PhyEardeteline *result);
		static void setAttribute(long attri_name, double value, PhyEardeteline *result);
		static void setAttribute(long attri_name, std::string value, PhyEardeteline *result);

		// 物探点位标准化信息表 PhyStdPnt
		static void setAttribute(long attri_name, long value, PhyStdPnt *result);
		static void setAttribute(long attri_name, double value, PhyStdPnt *result);
		static void setAttribute(long attri_name, std::string value, PhyStdPnt *result);

		// 标准地层版本表 hole_stdStratVer
		static void setAttribute(long attri_name, long value, hole_stdStratVer *result);
		static void setAttribute(long attri_name, double value, hole_stdStratVer *result);
		static void setAttribute(long attri_name, std::string value, hole_stdStratVer *result);

		// 标准地层描述表 hole_stdStratDesc
		static void setAttribute(long attri_name, long value, hole_stdStratDesc *result);
		static void setAttribute(long attri_name, double value, hole_stdStratDesc *result);
		static void setAttribute(long attri_name, std::string value, hole_stdStratDesc *result);

		// 钻孔分层表 HoleLayer
		static void setAttribute(long attri_name, long value, HoleLayer *result);
		static void setAttribute(long attri_name, double value, HoleLayer *result);
		static void setAttribute(long attri_name, std::string value, HoleLayer *result);

		// 钻孔原始分层表 HoleOrigLayer
		static void setAttribute(long attri_name, long value, HoleOrigLayer *result);
		static void setAttribute(long attri_name, double value, HoleOrigLayer *result);
		static void setAttribute(long attri_name, std::string value, HoleOrigLayer *result);

		// 止水结构表 HoleWaterSeal
		static void setAttribute(long attri_name, long value, HoleWaterSeal *result);
		static void setAttribute(long attri_name, double value, HoleWaterSeal *result);
		static void setAttribute(long attri_name, std::string value, HoleWaterSeal *result);

		// 填砾结构表 HoleGravelPack
		static void setAttribute(long attri_name, long value, HoleGravelPack *result);
		static void setAttribute(long attri_name, double value, HoleGravelPack *result);
		static void setAttribute(long attri_name, std::string value, HoleGravelPack *result);

		// 井管结构表 HoleWellPipe
		static void setAttribute(long attri_name, long value, HoleWellPipe *result);
		static void setAttribute(long attri_name, double value, HoleWellPipe *result);
		static void setAttribute(long attri_name, std::string value, HoleWellPipe *result);

		// 孔径变化表 HoleAperture
		static void setAttribute(long attri_name, long value, HoleAperture *result);
		static void setAttribute(long attri_name, double value, HoleAperture *result);
		static void setAttribute(long attri_name, std::string value, HoleAperture *result);

		// 标准贯入试验记录表 EgStdPenetration
		static void setAttribute(long attri_name, long value, EgStdPenetration *result);
		static void setAttribute(long attri_name, double value, EgStdPenetration *result);
		static void setAttribute(long attri_name, std::string value, EgStdPenetration *result);

		// 静力触探试验记录表 EgStaticPenetration
		static void setAttribute(long attri_name, long value, EgStaticPenetration *result);
		static void setAttribute(long attri_name, double value, EgStaticPenetration *result);
		static void setAttribute(long attri_name, std::string value, EgStaticPenetration *result);

		// 重型动力触探实验记录表 EgMotDetect
		static void setAttribute(long attri_name, long value, EgMotDetect *result);
		static void setAttribute(long attri_name, double value, EgMotDetect *result);
		static void setAttribute(long attri_name, std::string value, EgMotDetect *result);

		// 轻型动力触探实验记录表 LightEgMotDetect
		static void setAttribute(long attri_name, long value, LightEgMotDetect *result);
		static void setAttribute(long attri_name, double value, LightEgMotDetect *result);
		static void setAttribute(long attri_name, std::string value, LightEgMotDetect *result);

		// 十字板剪切试验记录表 EgShear
		static void setAttribute(long attri_name, long value, EgShear *result);
		static void setAttribute(long attri_name, double value, EgShear *result);
		static void setAttribute(long attri_name, std::string value, EgShear *result);

		// 波速测试记录表 EgWaveSpeed
		static void setAttribute(long attri_name, long value, EgWaveSpeed *result);
		static void setAttribute(long attri_name, double value, EgWaveSpeed *result);
		static void setAttribute(long attri_name, std::string value, EgWaveSpeed *result);

		// 旁压实验成果表 EgPMT
		static void setAttribute(long attri_name, long value, EgPMT *result);
		static void setAttribute(long attri_name, double value, EgPMT *result);
		static void setAttribute(long attri_name, std::string value, EgPMT *result);

		// 载荷试验成果表 EgLoadTest
		static void setAttribute(long attri_name, long value, EgLoadTest *result);
		static void setAttribute(long attri_name, double value, EgLoadTest *result);
		static void setAttribute(long attri_name, std::string value, EgLoadTest *result);

		// 抽水试验成果表 HYPumpExp
		static void setAttribute(long attri_name, long value, HYPumpExp *result);
		static void setAttribute(long attri_name, double value, HYPumpExp *result);
		static void setAttribute(long attri_name, std::string value, HYPumpExp *result);

		// 抽水试验段信息表 HYPumpExpSec
		static void setAttribute(long attri_name, long value, HYPumpExpSec *result);
		static void setAttribute(long attri_name, double value, HYPumpExpSec *result);
		static void setAttribute(long attri_name, std::string value, HYPumpExpSec *result);

		// 抽水实验落程数据表 HYPumpDropOff
		static void setAttribute(long attri_name, long value, HYPumpDropOff *result);
		static void setAttribute(long attri_name, double value, HYPumpDropOff *result);
		static void setAttribute(long attri_name, std::string value, HYPumpDropOff *result);

		// 抽水水位观测记录表 HYPumpLevelOb
		static void setAttribute(long attri_name, long value, HYPumpLevelOb *result);
		static void setAttribute(long attri_name, double value, HYPumpLevelOb *result);
		static void setAttribute(long attri_name, std::string value, HYPumpLevelOb *result);

		// 静水位观测记录表 HYStaticWaterLevel
		static void setAttribute(long attri_name, long value, HYStaticWaterLevel *result);
		static void setAttribute(long attri_name, double value, HYStaticWaterLevel *result);
		static void setAttribute(long attri_name, std::string value, HYStaticWaterLevel *result);

		// 恢复水位观测记录表 HYRevieWaterLevel
		static void setAttribute(long attri_name, long value, HYRevieWaterLevel *result);
		static void setAttribute(long attri_name, double value, HYRevieWaterLevel *result);
		static void setAttribute(long attri_name, std::string value, HYRevieWaterLevel *result);

		// 注水试验观测记录表 HYWaterInjectOb
		static void setAttribute(long attri_name, long value, HYWaterInjectOb *result);
		static void setAttribute(long attri_name, double value, HYWaterInjectOb *result);
		static void setAttribute(long attri_name, std::string value, HYWaterInjectOb *result);

		// 回灌实验成果表 HYRechargeExp
		static void setAttribute(long attri_name, long value, HYRechargeExp *result);
		static void setAttribute(long attri_name, double value, HYRechargeExp *result);
		static void setAttribute(long attri_name, std::string value, HYRechargeExp *result);

		// 回灌试验段信息表 HYRechargeExpSect
		static void setAttribute(long attri_name, long value, HYRechargeExpSect *result);
		static void setAttribute(long attri_name, double value, HYRechargeExpSect *result);
		static void setAttribute(long attri_name, std::string value, HYRechargeExpSect *result);

		// 回灌试验升程数据表 HYRechargeExpLift
		static void setAttribute(long attri_name, long value, HYRechargeExpLift *result);
		static void setAttribute(long attri_name, double value, HYRechargeExpLift *result);
		static void setAttribute(long attri_name, std::string value, HYRechargeExpLift *result);

		// 回灌试验观测记录表 HYRechargeExpOb
		static void setAttribute(long attri_name, long value, HYRechargeExpOb *result);
		static void setAttribute(long attri_name, double value, HYRechargeExpOb *result);
		static void setAttribute(long attri_name, std::string value, HYRechargeExpOb *result);

		// 热响应实验成果表 HYThermalRes
		static void setAttribute(long attri_name, long value, HYThermalRes *result);
		static void setAttribute(long attri_name, double value, HYThermalRes *result);
		static void setAttribute(long attri_name, std::string value, HYThermalRes *result);

		// 热响应试验地温观测记录表 HYThernakResOb
		static void setAttribute(long attri_name, long value, HYThernakResOb *result);
		static void setAttribute(long attri_name, double value, HYThernakResOb *result);
		static void setAttribute(long attri_name, std::string value, HYThernakResOb *result);

		// 渗水试验成果表 HYWaterSeepageExp
		static void setAttribute(long attri_name, long value, HYWaterSeepageExp *result);
		static void setAttribute(long attri_name, double value, HYWaterSeepageExp *result);
		static void setAttribute(long attri_name, std::string value, HYWaterSeepageExp *result);

		// 渗水试验观测记录表 HYWaterSeepageExpOb
		static void setAttribute(long attri_name, long value, HYWaterSeepageExpOb *result);
		static void setAttribute(long attri_name, double value, HYWaterSeepageExpOb *result);
		static void setAttribute(long attri_name, std::string value, HYWaterSeepageExpOb *result);

		// 混合样品对照表 SCMixSampCompare
		static void setAttribute(long attri_name, long value, SCMixSampCompare *result);
		static void setAttribute(long attri_name, double value, SCMixSampCompare *result);
		static void setAttribute(long attri_name, std::string value, SCMixSampCompare *result);

		// 岩石样品基本情况表 SCRockSample
		static void setAttribute(long attri_name, long value, SCRockSample *result);
		static void setAttribute(long attri_name, double value, SCRockSample *result);
		static void setAttribute(long attri_name, std::string value, SCRockSample *result);

		// 土壤样品基本情况表 SCSoilSample
		static void setAttribute(long attri_name, long value, SCSoilSample *result);
		static void setAttribute(long attri_name, double value, SCSoilSample *result);
		static void setAttribute(long attri_name, std::string value, SCSoilSample *result);

		// 水体沉积物样品基本情况表 SCWaterSediment
		static void setAttribute(long attri_name, long value, SCWaterSediment *result);
		static void setAttribute(long attri_name, double value, SCWaterSediment *result);
		static void setAttribute(long attri_name, std::string value, SCWaterSediment *result);

		// 沉积物柱状样品分层描述表 SCSedimentColumn
		static void setAttribute(long attri_name, long value, SCSedimentColumn *result);
		static void setAttribute(long attri_name, double value, SCSedimentColumn *result);
		static void setAttribute(long attri_name, std::string value, SCSedimentColumn *result);

		// 大气沉降样品基本情况表 SCAtmosSample
		static void setAttribute(long attri_name, long value, SCAtmosSample *result);
		static void setAttribute(long attri_name, double value, SCAtmosSample *result);
		static void setAttribute(long attri_name, std::string value, SCAtmosSample *result);

		// 水样基本情况表 SCWaterSample
		static void setAttribute(long attri_name, long value, SCWaterSample *result);
		static void setAttribute(long attri_name, double value, SCWaterSample *result);
		static void setAttribute(long attri_name, std::string value, SCWaterSample *result);

		// 水悬浮物样品基本情况表 SCWaterSuspend
		static void setAttribute(long attri_name, long value, SCWaterSuspend *result);
		static void setAttribute(long attri_name, double value, SCWaterSuspend *result);
		static void setAttribute(long attri_name, std::string value, SCWaterSuspend *result);

		// 动植物样品基本情况表 SCAnimalPlant
		static void setAttribute(long attri_name, long value, SCAnimalPlant *result);
		static void setAttribute(long attri_name, double value, SCAnimalPlant *result);
		static void setAttribute(long attri_name, std::string value, SCAnimalPlant *result);

		// 岩石物理力学实验成果表 INRockPhysics
		static void setAttribute(long attri_name, long value, INRockPhysics *result);
		static void setAttribute(long attri_name, double value, INRockPhysics *result);
		static void setAttribute(long attri_name, std::string value, INRockPhysics *result);

		// 常规土工实验成果表 INGeotechnicalExp
		static void setAttribute(long attri_name, long value, INGeotechnicalExp *result);
		static void setAttribute(long attri_name, double value, INGeotechnicalExp *result);
		static void setAttribute(long attri_name, std::string value, INGeotechnicalExp *result);

		// 高压固结实验成果表 INConsolidatl
		static void setAttribute(long attri_name, long value, INConsolidatl *result);
		static void setAttribute(long attri_name, double value, INConsolidatl *result);
		static void setAttribute(long attri_name, std::string value, INConsolidatl *result);

		// 无侧限压缩试验成果表 INUnconfined
		static void setAttribute(long attri_name, long value, INUnconfined *result);
		static void setAttribute(long attri_name, double value, INUnconfined *result);
		static void setAttribute(long attri_name, std::string value, INUnconfined *result);

		// 三轴实验成果表 INThreeaxis
		static void setAttribute(long attri_name, long value, INThreeaxis *result);
		static void setAttribute(long attri_name, double value, INThreeaxis *result);
		static void setAttribute(long attri_name, std::string value, INThreeaxis *result);

		// 直剪实验成果表 INDirectShear
		static void setAttribute(long attri_name, long value, INDirectShear *result);
		static void setAttribute(long attri_name, double value, INDirectShear *result);
		static void setAttribute(long attri_name, std::string value, INDirectShear *result);

		// 动三轴实验成果表 INDynamicThaxis
		static void setAttribute(long attri_name, long value, INDynamicThaxis *result);
		static void setAttribute(long attri_name, double value, INDynamicThaxis *result);
		static void setAttribute(long attri_name, std::string value, INDynamicThaxis *result);

		// 岩矿鉴定成果表 INRockMineIdent
		static void setAttribute(long attri_name, long value, INRockMineIdent *result);
		static void setAttribute(long attri_name, double value, INRockMineIdent *result);
		static void setAttribute(long attri_name, std::string value, INRockMineIdent *result);

		// 粘土（全岩）矿物鉴定成果表 INClayMineralIdent
		static void setAttribute(long attri_name, long value, INClayMineralIdent *result);
		static void setAttribute(long attri_name, double value, INClayMineralIdent *result);
		static void setAttribute(long attri_name, std::string value, INClayMineralIdent *result);

		// 粒度分析成果表 INGranularityIdent
		static void setAttribute(long attri_name, long value, INGranularityIdent *result);
		static void setAttribute(long attri_name, double value, INGranularityIdent *result);
		static void setAttribute(long attri_name, std::string value, INGranularityIdent *result);

		// 热物性实验成果表 INThermophysical
		static void setAttribute(long attri_name, long value, INThermophysical *result);
		static void setAttribute(long attri_name, double value, INThermophysical *result);
		static void setAttribute(long attri_name, std::string value, INThermophysical *result);

		// 同位素测年成果表 INIsotope
		static void setAttribute(long attri_name, long value, INIsotope *result);
		static void setAttribute(long attri_name, double value, INIsotope *result);
		static void setAttribute(long attri_name, std::string value, INIsotope *result);

		// 释光测年成果表 INLuminescence
		static void setAttribute(long attri_name, long value, INLuminescence *result);
		static void setAttribute(long attri_name, double value, INLuminescence *result);
		static void setAttribute(long attri_name, std::string value, INLuminescence *result);

		// 孢粉组合表 INPollenCombinat
		static void setAttribute(long attri_name, long value, INPollenCombinat *result);
		static void setAttribute(long attri_name, double value, INPollenCombinat *result);
		static void setAttribute(long attri_name, std::string value, INPollenCombinat *result);

		// 化石组合表 INFossilCombinat
		static void setAttribute(long attri_name, long value, INFossilCombinat *result);
		static void setAttribute(long attri_name, double value, INFossilCombinat *result);
		static void setAttribute(long attri_name, std::string value, INFossilCombinat *result);

		// 化石鉴定数据表 INFossilIdent
		static void setAttribute(long attri_name, long value, INFossilIdent *result);
		static void setAttribute(long attri_name, double value, INFossilIdent *result);
		static void setAttribute(long attri_name, std::string value, INFossilIdent *result);

		// 古地磁测试成果表 INPaleomagnetic
		static void setAttribute(long attri_name, long value, INPaleomagnetic *result);
		static void setAttribute(long attri_name, double value, INPaleomagnetic *result);
		static void setAttribute(long attri_name, std::string value, INPaleomagnetic *result);

		// 水腐蚀性分析 INWaterCausticity
		static void setAttribute(long attri_name, long value, INWaterCausticity *result);
		static void setAttribute(long attri_name, double value, INWaterCausticity *result);
		static void setAttribute(long attri_name, std::string value, INWaterCausticity *result);

		// 土腐蚀性分析 INSoilCausticity
		static void setAttribute(long attri_name, long value, INSoilCausticity *result);
		static void setAttribute(long attri_name, double value, INSoilCausticity *result);
		static void setAttribute(long attri_name, std::string value, INSoilCausticity *result);

		// 地球化学分析数据表 INGeochemicalIdent
		static void setAttribute(long attri_name, long value, INGeochemicalIdent *result);
		static void setAttribute(long attri_name, double value, INGeochemicalIdent *result);
		static void setAttribute(long attri_name, std::string value, INGeochemicalIdent *result);

		// 工勘孔土的易溶性分析 Tyrxfxsj
		static void setAttribute(long attri_name, long value, Tyrxfxsj *result);
		static void setAttribute(long attri_name, double value, Tyrxfxsj *result);
		static void setAttribute(long attri_name, std::string value, Tyrxfxsj *result);

		// 工勘孔岩石RQD实验 Ysrqdsj
		static void setAttribute(long attri_name, long value, Ysrqdsj *result);
		static void setAttribute(long attri_name, double value, Ysrqdsj *result);
		static void setAttribute(long attri_name, std::string value, Ysrqdsj *result);

		// 岩石抗压强度表 Yskyqd
		static void setAttribute(long attri_name, long value, Yskyqd *result);
		static void setAttribute(long attri_name, double value, Yskyqd *result);
		static void setAttribute(long attri_name, std::string value, Yskyqd *result);

		// 现场监测分析成果表 INSceneExpIdent
		static void setAttribute(long attri_name, long value, INSceneExpIdent *result);
		static void setAttribute(long attri_name, double value, INSceneExpIdent *result);
		static void setAttribute(long attri_name, std::string value, INSceneExpIdent *result);

		// 监测仪器基本情况表 GeoEnvMonitorDivice
		static void setAttribute(long attri_name, long value, GeoEnvMonitorDivice *result);
		static void setAttribute(long attri_name, double value, GeoEnvMonitorDivice *result);
		static void setAttribute(long attri_name, std::string value, GeoEnvMonitorDivice *result);

		// 地下水位水温监测数据表 GeoEnvMonitoLevelTemp
		static void setAttribute(long attri_name, long value, GeoEnvMonitoLevelTemp *result);
		static void setAttribute(long attri_name, double value, GeoEnvMonitoLevelTemp *result);
		static void setAttribute(long attri_name, std::string value, GeoEnvMonitoLevelTemp *result);

		// （堰槽法）流量监测数据表 GeoEnvWeirMonitoFlow
		static void setAttribute(long attri_name, long value, GeoEnvWeirMonitoFlow *result);
		static void setAttribute(long attri_name, double value, GeoEnvWeirMonitoFlow *result);
		static void setAttribute(long attri_name, std::string value, GeoEnvWeirMonitoFlow *result);

		// 监测断面测点数据表 GeoEnvMonitoSectPnt
		static void setAttribute(long attri_name, long value, GeoEnvMonitoSectPnt *result);
		static void setAttribute(long attri_name, double value, GeoEnvMonitoSectPnt *result);
		static void setAttribute(long attri_name, std::string value, GeoEnvMonitoSectPnt *result);

		// 地下水开采量监测数据表 GeoEnvWaterExtract
		static void setAttribute(long attri_name, long value, GeoEnvWaterExtract *result);
		static void setAttribute(long attri_name, double value, GeoEnvWaterExtract *result);
		static void setAttribute(long attri_name, std::string value, GeoEnvWaterExtract *result);

		// 地面沉降监测数据表 GeoEnvLandSubsidence
		static void setAttribute(long attri_name, long value, GeoEnvLandSubsidence *result);
		static void setAttribute(long attri_name, double value, GeoEnvLandSubsidence *result);
		static void setAttribute(long attri_name, std::string value, GeoEnvLandSubsidence *result);

		// 孔隙水压力监测数据表 GeoEnvPoreWater
		static void setAttribute(long attri_name, long value, GeoEnvPoreWater *result);
		static void setAttribute(long attri_name, double value, GeoEnvPoreWater *result);
		static void setAttribute(long attri_name, std::string value, GeoEnvPoreWater *result);

		// 地应力监测数据表 GeoEnvGroundStress
		static void setAttribute(long attri_name, long value, GeoEnvGroundStress *result);
		static void setAttribute(long attri_name, double value, GeoEnvGroundStress *result);
		static void setAttribute(long attri_name, std::string value, GeoEnvGroundStress *result);

		// 降雨量监测数据表 GeoEnvRainFall
		static void setAttribute(long attri_name, long value, GeoEnvRainFall *result);
		static void setAttribute(long attri_name, double value, GeoEnvRainFall *result);
		static void setAttribute(long attri_name, std::string value, GeoEnvRainFall *result);

		// 蒸发量监测数据表 GeoEnvEvaporation
		static void setAttribute(long attri_name, long value, GeoEnvEvaporation *result);
		static void setAttribute(long attri_name, double value, GeoEnvEvaporation *result);
		static void setAttribute(long attri_name, std::string value, GeoEnvEvaporation *result);

	};
}


