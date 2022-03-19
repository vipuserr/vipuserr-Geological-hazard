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
		// �˺���Ϊ���ɺ�������ֱ��ʹ�����ö����ý���ʱ����ɾ�� -- LH.2021.09.02 11:28 added.
		//static std::string parseBaseSqlConfig(BaseSqlConfig base_sql_config);


	public:
		// ������Դ��λ�� Bas_DocOrganization
		static void setAttribute(long attri_name, long value, Bas_DocOrganization *result);
		static void setAttribute(long attri_name, double value, Bas_DocOrganization *result);
		static void setAttribute(long attri_name, std::string value, Bas_DocOrganization *result);

		// ��Ŀ�ǼǱ� Bas_PrjRegistration
		static void setAttribute(long attri_name, long value, Bas_PrjRegistration *result);
		static void setAttribute(long attri_name, double value, Bas_PrjRegistration *result);
		static void setAttribute(long attri_name, std::string value, Bas_PrjRegistration *result);

		// ��λ��Ϣ�� Bas_PntStdInfo
		static void setAttribute(long attri_name, long value, Bas_PntStdInfo *result);
		static void setAttribute(long attri_name, double value, Bas_PntStdInfo *result);
		static void setAttribute(long attri_name, std::string value, Bas_PntStdInfo *result);

		// ��׵Ǽ���˱� HoleRegister
		static void setAttribute(long attri_name, long value, HoleRegister *result);
		static void setAttribute(long attri_name, double value, HoleRegister *result);
		static void setAttribute(long attri_name, std::string value, HoleRegister *result);

		// ��׻�����Ϣ�� HoleInfo
		static void setAttribute(long attri_name, long value, HoleInfo *result);
		static void setAttribute(long attri_name, double value, HoleInfo *result);
		static void setAttribute(long attri_name, std::string value, HoleInfo *result);

		// ��ײ�б�� HoleInclinat
		static void setAttribute(long attri_name, long value, HoleInclinat *result);
		static void setAttribute(long attri_name, double value, HoleInclinat *result);
		static void setAttribute(long attri_name, std::string value, HoleInclinat *result);

		// �⾮��������� HoleLogging
		static void setAttribute(long attri_name, long value, HoleLogging *result);
		static void setAttribute(long attri_name, double value, HoleLogging *result);
		static void setAttribute(long attri_name, std::string value, HoleLogging *result);

		// ��׼�ز���������׻�����Ϣ�� StdStrat_VHole
		static void setAttribute(long attri_name, long value, StdStrat_VHole *result);
		static void setAttribute(long attri_name, double value, StdStrat_VHole *result);
		static void setAttribute(long attri_name, std::string value, StdStrat_VHole *result);

		// ��׼�ز���������׷ֲ���Ϣ�� StdStrat_VHolelLayer
		static void setAttribute(long attri_name, long value, StdStrat_VHolelLayer *result);
		static void setAttribute(long attri_name, double value, StdStrat_VHolelLayer *result);
		static void setAttribute(long attri_name, std::string value, StdStrat_VHolelLayer *result);

		// ̽�۹۲����Ϣ�� HoleDetect
		static void setAttribute(long attri_name, long value, HoleDetect *result);
		static void setAttribute(long attri_name, double value, HoleDetect *result);
		static void setAttribute(long attri_name, std::string value, HoleDetect *result);

		// ǳ��̽�����Էֲ������� HoleWellSlotLayer
		static void setAttribute(long attri_name, long value, HoleWellSlotLayer *result);
		static void setAttribute(long attri_name, double value, HoleWellSlotLayer *result);
		static void setAttribute(long attri_name, std::string value, HoleWellSlotLayer *result);

		// �磨�ţ�����̽�߲����� PhyElecline
		static void setAttribute(long attri_name, long value, PhyElecline *result);
		static void setAttribute(long attri_name, double value, PhyElecline *result);
		static void setAttribute(long attri_name, std::string value, PhyElecline *result);

		// ����̽�߲����� PhyEardeteline
		static void setAttribute(long attri_name, long value, PhyEardeteline *result);
		static void setAttribute(long attri_name, double value, PhyEardeteline *result);
		static void setAttribute(long attri_name, std::string value, PhyEardeteline *result);

		// ��̽��λ��׼����Ϣ�� PhyStdPnt
		static void setAttribute(long attri_name, long value, PhyStdPnt *result);
		static void setAttribute(long attri_name, double value, PhyStdPnt *result);
		static void setAttribute(long attri_name, std::string value, PhyStdPnt *result);

		// ��׼�ز�汾�� hole_stdStratVer
		static void setAttribute(long attri_name, long value, hole_stdStratVer *result);
		static void setAttribute(long attri_name, double value, hole_stdStratVer *result);
		static void setAttribute(long attri_name, std::string value, hole_stdStratVer *result);

		// ��׼�ز������� hole_stdStratDesc
		static void setAttribute(long attri_name, long value, hole_stdStratDesc *result);
		static void setAttribute(long attri_name, double value, hole_stdStratDesc *result);
		static void setAttribute(long attri_name, std::string value, hole_stdStratDesc *result);

		// ��׷ֲ�� HoleLayer
		static void setAttribute(long attri_name, long value, HoleLayer *result);
		static void setAttribute(long attri_name, double value, HoleLayer *result);
		static void setAttribute(long attri_name, std::string value, HoleLayer *result);

		// ���ԭʼ�ֲ�� HoleOrigLayer
		static void setAttribute(long attri_name, long value, HoleOrigLayer *result);
		static void setAttribute(long attri_name, double value, HoleOrigLayer *result);
		static void setAttribute(long attri_name, std::string value, HoleOrigLayer *result);

		// ֹˮ�ṹ�� HoleWaterSeal
		static void setAttribute(long attri_name, long value, HoleWaterSeal *result);
		static void setAttribute(long attri_name, double value, HoleWaterSeal *result);
		static void setAttribute(long attri_name, std::string value, HoleWaterSeal *result);

		// �����ṹ�� HoleGravelPack
		static void setAttribute(long attri_name, long value, HoleGravelPack *result);
		static void setAttribute(long attri_name, double value, HoleGravelPack *result);
		static void setAttribute(long attri_name, std::string value, HoleGravelPack *result);

		// ���ܽṹ�� HoleWellPipe
		static void setAttribute(long attri_name, long value, HoleWellPipe *result);
		static void setAttribute(long attri_name, double value, HoleWellPipe *result);
		static void setAttribute(long attri_name, std::string value, HoleWellPipe *result);

		// �׾��仯�� HoleAperture
		static void setAttribute(long attri_name, long value, HoleAperture *result);
		static void setAttribute(long attri_name, double value, HoleAperture *result);
		static void setAttribute(long attri_name, std::string value, HoleAperture *result);

		// ��׼���������¼�� EgStdPenetration
		static void setAttribute(long attri_name, long value, EgStdPenetration *result);
		static void setAttribute(long attri_name, double value, EgStdPenetration *result);
		static void setAttribute(long attri_name, std::string value, EgStdPenetration *result);

		// ������̽�����¼�� EgStaticPenetration
		static void setAttribute(long attri_name, long value, EgStaticPenetration *result);
		static void setAttribute(long attri_name, double value, EgStaticPenetration *result);
		static void setAttribute(long attri_name, std::string value, EgStaticPenetration *result);

		// ���Ͷ�����̽ʵ���¼�� EgMotDetect
		static void setAttribute(long attri_name, long value, EgMotDetect *result);
		static void setAttribute(long attri_name, double value, EgMotDetect *result);
		static void setAttribute(long attri_name, std::string value, EgMotDetect *result);

		// ���Ͷ�����̽ʵ���¼�� LightEgMotDetect
		static void setAttribute(long attri_name, long value, LightEgMotDetect *result);
		static void setAttribute(long attri_name, double value, LightEgMotDetect *result);
		static void setAttribute(long attri_name, std::string value, LightEgMotDetect *result);

		// ʮ�ְ���������¼�� EgShear
		static void setAttribute(long attri_name, long value, EgShear *result);
		static void setAttribute(long attri_name, double value, EgShear *result);
		static void setAttribute(long attri_name, std::string value, EgShear *result);

		// ���ٲ��Լ�¼�� EgWaveSpeed
		static void setAttribute(long attri_name, long value, EgWaveSpeed *result);
		static void setAttribute(long attri_name, double value, EgWaveSpeed *result);
		static void setAttribute(long attri_name, std::string value, EgWaveSpeed *result);

		// ��ѹʵ��ɹ��� EgPMT
		static void setAttribute(long attri_name, long value, EgPMT *result);
		static void setAttribute(long attri_name, double value, EgPMT *result);
		static void setAttribute(long attri_name, std::string value, EgPMT *result);

		// �غ�����ɹ��� EgLoadTest
		static void setAttribute(long attri_name, long value, EgLoadTest *result);
		static void setAttribute(long attri_name, double value, EgLoadTest *result);
		static void setAttribute(long attri_name, std::string value, EgLoadTest *result);

		// ��ˮ����ɹ��� HYPumpExp
		static void setAttribute(long attri_name, long value, HYPumpExp *result);
		static void setAttribute(long attri_name, double value, HYPumpExp *result);
		static void setAttribute(long attri_name, std::string value, HYPumpExp *result);

		// ��ˮ�������Ϣ�� HYPumpExpSec
		static void setAttribute(long attri_name, long value, HYPumpExpSec *result);
		static void setAttribute(long attri_name, double value, HYPumpExpSec *result);
		static void setAttribute(long attri_name, std::string value, HYPumpExpSec *result);

		// ��ˮʵ��������ݱ� HYPumpDropOff
		static void setAttribute(long attri_name, long value, HYPumpDropOff *result);
		static void setAttribute(long attri_name, double value, HYPumpDropOff *result);
		static void setAttribute(long attri_name, std::string value, HYPumpDropOff *result);

		// ��ˮˮλ�۲��¼�� HYPumpLevelOb
		static void setAttribute(long attri_name, long value, HYPumpLevelOb *result);
		static void setAttribute(long attri_name, double value, HYPumpLevelOb *result);
		static void setAttribute(long attri_name, std::string value, HYPumpLevelOb *result);

		// ��ˮλ�۲��¼�� HYStaticWaterLevel
		static void setAttribute(long attri_name, long value, HYStaticWaterLevel *result);
		static void setAttribute(long attri_name, double value, HYStaticWaterLevel *result);
		static void setAttribute(long attri_name, std::string value, HYStaticWaterLevel *result);

		// �ָ�ˮλ�۲��¼�� HYRevieWaterLevel
		static void setAttribute(long attri_name, long value, HYRevieWaterLevel *result);
		static void setAttribute(long attri_name, double value, HYRevieWaterLevel *result);
		static void setAttribute(long attri_name, std::string value, HYRevieWaterLevel *result);

		// עˮ����۲��¼�� HYWaterInjectOb
		static void setAttribute(long attri_name, long value, HYWaterInjectOb *result);
		static void setAttribute(long attri_name, double value, HYWaterInjectOb *result);
		static void setAttribute(long attri_name, std::string value, HYWaterInjectOb *result);

		// �ع�ʵ��ɹ��� HYRechargeExp
		static void setAttribute(long attri_name, long value, HYRechargeExp *result);
		static void setAttribute(long attri_name, double value, HYRechargeExp *result);
		static void setAttribute(long attri_name, std::string value, HYRechargeExp *result);

		// �ع��������Ϣ�� HYRechargeExpSect
		static void setAttribute(long attri_name, long value, HYRechargeExpSect *result);
		static void setAttribute(long attri_name, double value, HYRechargeExpSect *result);
		static void setAttribute(long attri_name, std::string value, HYRechargeExpSect *result);

		// �ع������������ݱ� HYRechargeExpLift
		static void setAttribute(long attri_name, long value, HYRechargeExpLift *result);
		static void setAttribute(long attri_name, double value, HYRechargeExpLift *result);
		static void setAttribute(long attri_name, std::string value, HYRechargeExpLift *result);

		// �ع�����۲��¼�� HYRechargeExpOb
		static void setAttribute(long attri_name, long value, HYRechargeExpOb *result);
		static void setAttribute(long attri_name, double value, HYRechargeExpOb *result);
		static void setAttribute(long attri_name, std::string value, HYRechargeExpOb *result);

		// ����Ӧʵ��ɹ��� HYThermalRes
		static void setAttribute(long attri_name, long value, HYThermalRes *result);
		static void setAttribute(long attri_name, double value, HYThermalRes *result);
		static void setAttribute(long attri_name, std::string value, HYThermalRes *result);

		// ����Ӧ������¹۲��¼�� HYThernakResOb
		static void setAttribute(long attri_name, long value, HYThernakResOb *result);
		static void setAttribute(long attri_name, double value, HYThernakResOb *result);
		static void setAttribute(long attri_name, std::string value, HYThernakResOb *result);

		// ��ˮ����ɹ��� HYWaterSeepageExp
		static void setAttribute(long attri_name, long value, HYWaterSeepageExp *result);
		static void setAttribute(long attri_name, double value, HYWaterSeepageExp *result);
		static void setAttribute(long attri_name, std::string value, HYWaterSeepageExp *result);

		// ��ˮ����۲��¼�� HYWaterSeepageExpOb
		static void setAttribute(long attri_name, long value, HYWaterSeepageExpOb *result);
		static void setAttribute(long attri_name, double value, HYWaterSeepageExpOb *result);
		static void setAttribute(long attri_name, std::string value, HYWaterSeepageExpOb *result);

		// �����Ʒ���ձ� SCMixSampCompare
		static void setAttribute(long attri_name, long value, SCMixSampCompare *result);
		static void setAttribute(long attri_name, double value, SCMixSampCompare *result);
		static void setAttribute(long attri_name, std::string value, SCMixSampCompare *result);

		// ��ʯ��Ʒ��������� SCRockSample
		static void setAttribute(long attri_name, long value, SCRockSample *result);
		static void setAttribute(long attri_name, double value, SCRockSample *result);
		static void setAttribute(long attri_name, std::string value, SCRockSample *result);

		// ������Ʒ��������� SCSoilSample
		static void setAttribute(long attri_name, long value, SCSoilSample *result);
		static void setAttribute(long attri_name, double value, SCSoilSample *result);
		static void setAttribute(long attri_name, std::string value, SCSoilSample *result);

		// ˮ���������Ʒ��������� SCWaterSediment
		static void setAttribute(long attri_name, long value, SCWaterSediment *result);
		static void setAttribute(long attri_name, double value, SCWaterSediment *result);
		static void setAttribute(long attri_name, std::string value, SCWaterSediment *result);

		// ��������״��Ʒ�ֲ������� SCSedimentColumn
		static void setAttribute(long attri_name, long value, SCSedimentColumn *result);
		static void setAttribute(long attri_name, double value, SCSedimentColumn *result);
		static void setAttribute(long attri_name, std::string value, SCSedimentColumn *result);

		// ����������Ʒ��������� SCAtmosSample
		static void setAttribute(long attri_name, long value, SCAtmosSample *result);
		static void setAttribute(long attri_name, double value, SCAtmosSample *result);
		static void setAttribute(long attri_name, std::string value, SCAtmosSample *result);

		// ˮ����������� SCWaterSample
		static void setAttribute(long attri_name, long value, SCWaterSample *result);
		static void setAttribute(long attri_name, double value, SCWaterSample *result);
		static void setAttribute(long attri_name, std::string value, SCWaterSample *result);

		// ˮ��������Ʒ��������� SCWaterSuspend
		static void setAttribute(long attri_name, long value, SCWaterSuspend *result);
		static void setAttribute(long attri_name, double value, SCWaterSuspend *result);
		static void setAttribute(long attri_name, std::string value, SCWaterSuspend *result);

		// ��ֲ����Ʒ��������� SCAnimalPlant
		static void setAttribute(long attri_name, long value, SCAnimalPlant *result);
		static void setAttribute(long attri_name, double value, SCAnimalPlant *result);
		static void setAttribute(long attri_name, std::string value, SCAnimalPlant *result);

		// ��ʯ������ѧʵ��ɹ��� INRockPhysics
		static void setAttribute(long attri_name, long value, INRockPhysics *result);
		static void setAttribute(long attri_name, double value, INRockPhysics *result);
		static void setAttribute(long attri_name, std::string value, INRockPhysics *result);

		// ��������ʵ��ɹ��� INGeotechnicalExp
		static void setAttribute(long attri_name, long value, INGeotechnicalExp *result);
		static void setAttribute(long attri_name, double value, INGeotechnicalExp *result);
		static void setAttribute(long attri_name, std::string value, INGeotechnicalExp *result);

		// ��ѹ�̽�ʵ��ɹ��� INConsolidatl
		static void setAttribute(long attri_name, long value, INConsolidatl *result);
		static void setAttribute(long attri_name, double value, INConsolidatl *result);
		static void setAttribute(long attri_name, std::string value, INConsolidatl *result);

		// �޲���ѹ������ɹ��� INUnconfined
		static void setAttribute(long attri_name, long value, INUnconfined *result);
		static void setAttribute(long attri_name, double value, INUnconfined *result);
		static void setAttribute(long attri_name, std::string value, INUnconfined *result);

		// ����ʵ��ɹ��� INThreeaxis
		static void setAttribute(long attri_name, long value, INThreeaxis *result);
		static void setAttribute(long attri_name, double value, INThreeaxis *result);
		static void setAttribute(long attri_name, std::string value, INThreeaxis *result);

		// ֱ��ʵ��ɹ��� INDirectShear
		static void setAttribute(long attri_name, long value, INDirectShear *result);
		static void setAttribute(long attri_name, double value, INDirectShear *result);
		static void setAttribute(long attri_name, std::string value, INDirectShear *result);

		// ������ʵ��ɹ��� INDynamicThaxis
		static void setAttribute(long attri_name, long value, INDynamicThaxis *result);
		static void setAttribute(long attri_name, double value, INDynamicThaxis *result);
		static void setAttribute(long attri_name, std::string value, INDynamicThaxis *result);

		// �ҿ�����ɹ��� INRockMineIdent
		static void setAttribute(long attri_name, long value, INRockMineIdent *result);
		static void setAttribute(long attri_name, double value, INRockMineIdent *result);
		static void setAttribute(long attri_name, std::string value, INRockMineIdent *result);

		// ճ����ȫ�ң���������ɹ��� INClayMineralIdent
		static void setAttribute(long attri_name, long value, INClayMineralIdent *result);
		static void setAttribute(long attri_name, double value, INClayMineralIdent *result);
		static void setAttribute(long attri_name, std::string value, INClayMineralIdent *result);

		// ���ȷ����ɹ��� INGranularityIdent
		static void setAttribute(long attri_name, long value, INGranularityIdent *result);
		static void setAttribute(long attri_name, double value, INGranularityIdent *result);
		static void setAttribute(long attri_name, std::string value, INGranularityIdent *result);

		// ������ʵ��ɹ��� INThermophysical
		static void setAttribute(long attri_name, long value, INThermophysical *result);
		static void setAttribute(long attri_name, double value, INThermophysical *result);
		static void setAttribute(long attri_name, std::string value, INThermophysical *result);

		// ͬλ�ز���ɹ��� INIsotope
		static void setAttribute(long attri_name, long value, INIsotope *result);
		static void setAttribute(long attri_name, double value, INIsotope *result);
		static void setAttribute(long attri_name, std::string value, INIsotope *result);

		// �͹����ɹ��� INLuminescence
		static void setAttribute(long attri_name, long value, INLuminescence *result);
		static void setAttribute(long attri_name, double value, INLuminescence *result);
		static void setAttribute(long attri_name, std::string value, INLuminescence *result);

		// �߷���ϱ� INPollenCombinat
		static void setAttribute(long attri_name, long value, INPollenCombinat *result);
		static void setAttribute(long attri_name, double value, INPollenCombinat *result);
		static void setAttribute(long attri_name, std::string value, INPollenCombinat *result);

		// ��ʯ��ϱ� INFossilCombinat
		static void setAttribute(long attri_name, long value, INFossilCombinat *result);
		static void setAttribute(long attri_name, double value, INFossilCombinat *result);
		static void setAttribute(long attri_name, std::string value, INFossilCombinat *result);

		// ��ʯ�������ݱ� INFossilIdent
		static void setAttribute(long attri_name, long value, INFossilIdent *result);
		static void setAttribute(long attri_name, double value, INFossilIdent *result);
		static void setAttribute(long attri_name, std::string value, INFossilIdent *result);

		// �ŵشŲ��Գɹ��� INPaleomagnetic
		static void setAttribute(long attri_name, long value, INPaleomagnetic *result);
		static void setAttribute(long attri_name, double value, INPaleomagnetic *result);
		static void setAttribute(long attri_name, std::string value, INPaleomagnetic *result);

		// ˮ��ʴ�Է��� INWaterCausticity
		static void setAttribute(long attri_name, long value, INWaterCausticity *result);
		static void setAttribute(long attri_name, double value, INWaterCausticity *result);
		static void setAttribute(long attri_name, std::string value, INWaterCausticity *result);

		// ����ʴ�Է��� INSoilCausticity
		static void setAttribute(long attri_name, long value, INSoilCausticity *result);
		static void setAttribute(long attri_name, double value, INSoilCausticity *result);
		static void setAttribute(long attri_name, std::string value, INSoilCausticity *result);

		// ����ѧ�������ݱ� INGeochemicalIdent
		static void setAttribute(long attri_name, long value, INGeochemicalIdent *result);
		static void setAttribute(long attri_name, double value, INGeochemicalIdent *result);
		static void setAttribute(long attri_name, std::string value, INGeochemicalIdent *result);

		// ���������������Է��� Tyrxfxsj
		static void setAttribute(long attri_name, long value, Tyrxfxsj *result);
		static void setAttribute(long attri_name, double value, Tyrxfxsj *result);
		static void setAttribute(long attri_name, std::string value, Tyrxfxsj *result);

		// ��������ʯRQDʵ�� Ysrqdsj
		static void setAttribute(long attri_name, long value, Ysrqdsj *result);
		static void setAttribute(long attri_name, double value, Ysrqdsj *result);
		static void setAttribute(long attri_name, std::string value, Ysrqdsj *result);

		// ��ʯ��ѹǿ�ȱ� Yskyqd
		static void setAttribute(long attri_name, long value, Yskyqd *result);
		static void setAttribute(long attri_name, double value, Yskyqd *result);
		static void setAttribute(long attri_name, std::string value, Yskyqd *result);

		// �ֳ��������ɹ��� INSceneExpIdent
		static void setAttribute(long attri_name, long value, INSceneExpIdent *result);
		static void setAttribute(long attri_name, double value, INSceneExpIdent *result);
		static void setAttribute(long attri_name, std::string value, INSceneExpIdent *result);

		// ���������������� GeoEnvMonitorDivice
		static void setAttribute(long attri_name, long value, GeoEnvMonitorDivice *result);
		static void setAttribute(long attri_name, double value, GeoEnvMonitorDivice *result);
		static void setAttribute(long attri_name, std::string value, GeoEnvMonitorDivice *result);

		// ����ˮλˮ�¼�����ݱ� GeoEnvMonitoLevelTemp
		static void setAttribute(long attri_name, long value, GeoEnvMonitoLevelTemp *result);
		static void setAttribute(long attri_name, double value, GeoEnvMonitoLevelTemp *result);
		static void setAttribute(long attri_name, std::string value, GeoEnvMonitoLevelTemp *result);

		// ���߲۷�������������ݱ� GeoEnvWeirMonitoFlow
		static void setAttribute(long attri_name, long value, GeoEnvWeirMonitoFlow *result);
		static void setAttribute(long attri_name, double value, GeoEnvWeirMonitoFlow *result);
		static void setAttribute(long attri_name, std::string value, GeoEnvWeirMonitoFlow *result);

		// �����������ݱ� GeoEnvMonitoSectPnt
		static void setAttribute(long attri_name, long value, GeoEnvMonitoSectPnt *result);
		static void setAttribute(long attri_name, double value, GeoEnvMonitoSectPnt *result);
		static void setAttribute(long attri_name, std::string value, GeoEnvMonitoSectPnt *result);

		// ����ˮ������������ݱ� GeoEnvWaterExtract
		static void setAttribute(long attri_name, long value, GeoEnvWaterExtract *result);
		static void setAttribute(long attri_name, double value, GeoEnvWaterExtract *result);
		static void setAttribute(long attri_name, std::string value, GeoEnvWaterExtract *result);

		// �������������ݱ� GeoEnvLandSubsidence
		static void setAttribute(long attri_name, long value, GeoEnvLandSubsidence *result);
		static void setAttribute(long attri_name, double value, GeoEnvLandSubsidence *result);
		static void setAttribute(long attri_name, std::string value, GeoEnvLandSubsidence *result);

		// ��϶ˮѹ��������ݱ� GeoEnvPoreWater
		static void setAttribute(long attri_name, long value, GeoEnvPoreWater *result);
		static void setAttribute(long attri_name, double value, GeoEnvPoreWater *result);
		static void setAttribute(long attri_name, std::string value, GeoEnvPoreWater *result);

		// ��Ӧ��������ݱ� GeoEnvGroundStress
		static void setAttribute(long attri_name, long value, GeoEnvGroundStress *result);
		static void setAttribute(long attri_name, double value, GeoEnvGroundStress *result);
		static void setAttribute(long attri_name, std::string value, GeoEnvGroundStress *result);

		// ������������ݱ� GeoEnvRainFall
		static void setAttribute(long attri_name, long value, GeoEnvRainFall *result);
		static void setAttribute(long attri_name, double value, GeoEnvRainFall *result);
		static void setAttribute(long attri_name, std::string value, GeoEnvRainFall *result);

		// ������������ݱ� GeoEnvEvaporation
		static void setAttribute(long attri_name, long value, GeoEnvEvaporation *result);
		static void setAttribute(long attri_name, double value, GeoEnvEvaporation *result);
		static void setAttribute(long attri_name, std::string value, GeoEnvEvaporation *result);

	};
}


