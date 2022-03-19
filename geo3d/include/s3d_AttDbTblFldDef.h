#ifndef S3d_ATTDBTBLFLDDEF__
#define S3d_ATTDBTBLFLDDEF__


#include "s3dAttDBEngine_exp.h"
#include <string>
#include <vector>
#include <map>
#include "s3d_AttrDBDef.h"
#include "s3d_DbTblFldDef.h"

namespace Smart3dMap
{
//共用宏
#define UNION_MACRO_PNT_ID "PntID"  //点ID
#define UNION_MACRO_START_DEPTH "StartDepth"  //起始深度
#define UNION_MACRO_END_DEPTH "EndDepth"	  //终止深度
#define UNION_MACRO_TCDH	"TCDH"			 //层位、图层代号
#define UNION_MACRO_TCMC	"TCMC"			//土层名称
#define UNION_MACRO_GEOCODE "GeoCode"		//地质代号

#define UNION_MACRO_PRJID	"PrjId"			//项目id
#define UNION_MACRO_PRJCODE  "PrjCode"		//项目编号
#define UNION_MACRO_TESTNO	"TestNo"		//试验编号
#define UNION_MACRO_TESTTYPE "TestType"		//试验类型
#define UNION_MACRO_NOTE	"NOTE"		    //备注


/*---------------------------------------基础信息表-------------------------------------------*/
#define BASEINFO_MDL_CLASS "基础信息表类"

//档案来源单位表
#define TBL_DOCORGN_TBL "Bas_DocOrganization"
#define TBL_DOCORGN_FLD_ORGNID						"OrgnID"				//* 单位ID	int PK
#define TBL_DOCORGN_FLD_ORGNCODE					"OrgnCode"				// 单位代号	varchar
#define TBL_DOCORGN_FLD_ORGNNAME					"OrgnName"				//* 单位名称	varchar
#define TBL_DOCORGN_FLD_ORGNCHARGE					"OrgnCharge"			// 单位负责人	varchar
#define TBL_DOCORGN_FLD_ORGNDUTY					"OrgnDuty"				// 单位职责	varchar
#define TBL_DOCORGN_FLD_ORGNTELNO					"OrgnTelNo"				// 单位电话	varchar
#define TBL_DOCORGN_FLD_DOCADMINNAME				"DocAdminName"			// 档案管理员姓名	varchar
#define TBL_DOCORGN_FLD_DOCADMINTELNO				"DocAdminTelNo"			// 档案管理员电话	varchar
#define TBL_DOCORGN_FLD_ORGNADDR					"OrgnAddr"				// 详细地址	varchar
#define TBL_DOCORGN_FLD_ORGNCITY					"OrgnCity"				// 城市	varchar
#define TBL_DOCORGN_FLD_ORGNDIST					"OrgnDist"				// 行政区	varchar
#define TBL_DOCORGN_FLD_ORGNCOUNTRY					"OrgnCountry"			// 国家	varchar
#define TBL_DOCORGN_FLD_ORGNZIPCODE					"OrgnZipCode"			// 邮政编码	varchar


//项目登记表*
#define TBL_PROJ_TBL "Bas_PrjRegistration"
#define TBL_PROJ_FLD_PRJID				UNION_MACRO_PRJID				//* 项目ID			int		PK
#define TBL_PROJ_FLD_PKIAA				UNION_MACRO_PRJCODE			// 项目编号		varchar
#define TBL_PROJ_FLD_PRJNAME			"PrjName"			//* 项目(报告)名称	varchar
#define TBL_PROJ_FLD_PRJRELURL			"PrjRelUrl"			// 项目关联资料Url	varchar
#define TBL_PROJ_FLD_ORGNID				"OrgnID"			// 单位ID			int FK->TBL_DOCORGN_TBL
#define TBL_PROJ_FLD_BATCHNO			"BatchNo"			// 资料批次			varchar
#define TBL_PROJ_FLD_PRJTYPE			"PrjType"			// 项目类型			varchar
#define TBL_PROJ_FLD_PROTYPE			"ProType"			// 专业类别			varchar
#define TBL_PROJ_FLD_PRJSTATUS			"PrjStatus"			// 项目运行状况		varchar
#define TBL_PROJ_FLD_DOCDELIVSTATUS		"DocDelivStatus"	// 档案汇交状况		varchar
#define TBL_PROJ_FLD_PRJCHARGE			"PrjCharge"			// 项目负责人		varchar
#define TBL_PROJ_FLD_PRJCHARGETELNO		"PrjChargeTelNo"	// 项目负责人电话	varchar
#define TBL_PROJ_FLD_PRJORGN			"PrjOrgn"			// 项目承担单位		varchar
#define TBL_PROJ_FLD_PRJSTARTTIME		"PrjStartTime"		// 项目起始日期		Date
#define TBL_PROJ_FLD_PRJENDTIME			"PrjEndTime"		// 项目完成日期		Date
#define TBL_PROJ_FLD_PRJREGISTER		"PrjRegister"		// 登记人			varchar
#define TBL_PROJ_FLD_PRJREGISTUNIT		"PrjRegistUnit"		// 登记单位			varchar
#define TBL_PROJ_FLD_PRJREGISTDATE		"PrjRegistDate"		// 登记日期			Date


//点位信息表 *
#define TBL_PNTSTD_TBL "Bas_PntStdInfo"
#define TBL_PNTSTD_FLD_STDPNTID					UNION_MACRO_PNT_ID		//* 标准点位ID		int PK
#define TBL_PNTSTD_FLD_X						"X"						//* 标准化X(m)		double
#define TBL_PNTSTD_FLD_Y						"Y"						//* 标准化Y(m)		double
#define TBL_PNTSTD_FLD_Z						"Z"						//* 标准化高程(m)	double
#define TBL_PNTSTD_FLD_STDCOORSYS				"stdCoorSys"			// 标准化坐标系		varchar
#define TBL_PNTSTD_FLD_STDELDATUM				"stdElDatum"			// 标准化高程基准		varchar
#define TBL_PNTSTD_FLD_PRJID					UNION_MACRO_PRJID		//* 项目ID			int
//from 点位原始信息表
#define TBL_PNTORIG_FLD_PNTNO					"OriPntCode"			// 原始点编号			    varchar
#define TBL_PNTORIG_FLD_ISVIRTUALPNT			"IsVirtualPnt"			// 是否虚拟点		int
#define TBL_PNTORIG_FLD_ISMONITORPNT			"IsMonitorPnt"			// 是否监测点		int
#define TBL_PNTORIG_FLD_CLASS1_NAME				"Class1_Name"			// 一级分类名		varchar
#define TBL_PNTORIG_FLD_CLASS2_NAME				"Class2_Name"			// 二级分类名		varchar
#define TBL_PNTORIG_FLD_X						"OriPnt_X"						// X				double
#define TBL_PNTORIG_FLD_Y						"OriPnt_Y"						// Y				double
#define TBL_PNTORIG_FLD_Z						"OriPnt_Z"						// 高程				double
#define TBL_PNTORIG_FLD_CHAHBA					"OriPnt_Logitude"				// 经度				double
#define TBL_PNTORIG_FLD_CHAHBB					"OriPnt_Latitude"				// 纬度				double
#define TBL_PNTORIG_FLD_PLANECOORDSYS			"OriPnt_PlaneCoordSys"			// 平面坐标系		varchar
#define TBL_PNTORIG_FLD_ELEDATUM				"OriPnt_EleDatum"				// 高程基准			varchar
#define TBL_PNTORIG_FLD_DDADC					"OriPnt_DDADC"					// 地理位置			varchar
#define TBL_PNTORIG_FLD_SCHAMAA					"SCHAMAA"						// 标准图幅名称		varchar
#define TBL_PNTORIG_FLD_SCHAMAC					"SCHAMAC"						// 标准图幅编号		varchar

/*----------------------------------------------------钻孔基本信息类------------------------------------------------*/
#define HOLEBASEINFO_MDL_CLASS "钻孔基本信息表类"
	//钻孔登记审核表* 
#define TBL_HOLEREGISTER_TBL "HoleRegister"
#define TBL_HOLEREGISTER_FLD_HOLEREGID					"HoleRegID"				//* 钻孔登记ID		int PK
#define TBL_HOLEREGISTER_FLD_PNTID						UNION_MACRO_PNT_ID		//* 点ID				int FK->TBL_PNTSTD_TBL
#define TBL_HOLEREGISTER_FLD_HOLECODE					"HoleCode"				//* 钻孔编号			varchar
#define TBL_HOLEREGISTER_FLD_HOLECLS1					"HoleCls1"				//* 钻孔大类			varchar->int
#define TBL_HOLEREGISTER_FLD_HOLECLS2					"HoleCls2"				//* 钻孔亚类			varchar->int
#define TBL_HOLEREGISTER_FLD_HOLEPROPERTY				"HoleProperty"			//* 钻孔性质			varchar(实测、收集)->int
#define TBL_HOLEREGISTER_FLD_HOLEDEPTH					"HoleDepth"				//* 孔深(m)			double
#define TBL_HOLEREGISTER_FLD_LAYERNUM					"LayerNum"				// 分层数量(个)		int
#define TBL_HOLEREGISTER_FLD_SOILSAMPNUM				"SoilSampNum"			// 土样数量(个)		int
#define TBL_HOLEREGISTER_FLD_ROCKSAMPNUM				"RockSampNum"			// 岩样数量(个)		int
#define TBL_HOLEREGISTER_FLD_WATERSAMPNUM				"WaterSampNum"			// 水样数量(个)		int
#define TBL_HOLEREGISTER_FLD_PENETRATIONTIMES			"PenetrationTimes"		// 标贯次数(个)		int
#define TBL_HOLEREGISTER_FLD_ISWAVELOCITYHOLE			"IsWavelocityHole"		// 是否为波速孔		varchar
#define TBL_HOLEREGISTER_FLD_HASPUMP					"HasPump"				// 是否进行抽水试验	varchar
#define TBL_HOLEREGISTER_FLD_OTHERINSIT					"OtherInsit"			// 其他原位试验情况	varchar
#define TBL_HOLEREGISTER_FLD_REGDATE					"RegDate"				// 登记日期			date
#define TBL_HOLEREGISTER_FLD_REGISTER					"Register"				// 登记人			varchar
#define TBL_HOLEREGISTER_FLD_MEMO						"_Memo"					// 备注				varchar
#define TBL_HOLEREGISTER_FLD_AUDITSTATUS				"AuditStatus"			// 审核状态		varchar->int
#define TBL_HOLEREGISTER_FLD_SELECTSTATUS				"SelectStatus"			// 选用状态		varchar->int
#define TBL_HOLEREGISTER_FLD_AUDITOR					"Auditor"				// 审核人		varchar
#define TBL_HOLEREGISTER_FLD_AUDITTIME					"AuditTime"				// 审核时间		date
#define TBL_HOLEREGISTER_FLD_AUDITORG					"AuditOrg"				// 审核单位		varchar


//钻孔基本信息表 *
#define TBL_HOLE_TBL "HoleInfo"
#define TBL_HOLE_FLD_HOLEID				"HoleID"			//* 钻孔ID			int PK
#define TBL_HOLE_FLD_HOLECODE			"HoleCode"			//* 钻孔编码			varchar
#define TBL_HOLE_FLD_DEPTH				"HoleDepth"			//* 孔深(m)			double
#define TBL_HOLE_FLD_TYPE				"HoleType"			//* 钻孔类型			int（虚拟孔、真实孔）
#define TBL_HOLE_FLD_CATEGORY			"HoleCategory"		// 钻孔类别			varchar
#define TBL_HOLE_FLD_LEVEL				"HoleLevel"			// 钻孔级别			int
#define TBL_HOLE_FLD_USAGE				"HoleUsage"			// 钻孔用途			int（取土、静探、标贯...）
#define TBL_HOLE_FLD_PNTID				UNION_MACRO_PNT_ID	//* 点ID				int
#define TBL_HOLE_FLD_PRJNAME			"PrjName"			//* 项目名称			varchar
#define TBL_HOLE_FLD_SWCJAR				"SWCJAR"			// 初见水位埋深			double
#define TBL_HOLE_FLD_SWDDBU				"SWDDBU"			// 稳定水位埋深			double
#define TBL_HOLE_FLD_TKACA				"TKACA"				// 开孔直径(mm)			float
#define TBL_HOLE_FLD_TKACB				"TKACB"				// 终孔直径(mm)			float
#define TBL_HOLE_FLD_HOLETOPDIAM		"HoleTopDiam"		// 井口外径(mm)			float
#define TBL_HOLE_FLD_HOLEBTMDIAM		"HoleBtmDiam"		// 井底外径(mm)			float
#define TBL_HOLE_FLD_TKCBCL				"TKCBCL"			// 成井深度(m)			float
#define TBL_HOLE_FLD_HOLEHEIGHT			"HoleHeight"		// 井台高度(m)			float
#define TBL_HOLE_FLD_HOLESLOPE			"HoleSlope"			// 井（孔）斜(度)		float
#define TBL_HOLE_FLD_HOLEEQUIP			"HoleEquip"			// 施工设备			varchar
#define TBL_HOLE_FLD_TKALD				"TKALD"				// 施工单位			varchar
#define TBL_HOLE_FLD_SWBBND				"SWBBND"			// 机长				varchar
#define TBL_HOLE_FLD_HOLERECORDER		"HoleRecorder"		// 编录员			varchar
#define TBL_HOLE_FLD_STARTDATE			"StartDate"			// 开工日期			date
#define TBL_HOLE_FLD_ENDDATE			"EndDate"			// 完工日期			date
#define TBL_HOLE_FLD_INPUTORGN			"InputOrgn"			// 录入单位			varchar
#define TBL_HOLE_FLD_INPUTER			"Inputer"			// 录入员			varchar
#define TBL_HOLE_FLD_INPUTDATE			"InputDate"			// 录入日期			date
#define TBL_HOLE_FLD_PLANEMAP			"PlaneMap"			// 平面位置示意图	varchar
#define TBL_HOLE_FLD_SECTMAP			"SectMap"			// 剖面示意图		varchar
#define TBL_HOLE_FLD_SCENEPHOTO			"ScenePhoto"		// 现场照片（视频）	varchar
#define TBL_HOLE_FLD_CONSTRUCTRECORD	"ConstructRecord"	// 施工记录			varchar
#define TBL_HOLE_FLD_MEMO				"_Memo"				// 备注				varchar

//钻孔测斜表
#define TBL_INCLINAT_TBL "HoleInclinat"
#define TBL_INCLINAT_FLD_HOLEID					"HoleID"			//* 钻孔ID		int FP
#define TBL_INCLINAT_FLD_MEASUREDEPTH			"MeasureDepth"		//* 测点深度		Double
#define TBL_INCLINAT_FLD_AZIMUTHANGLE			"AzimuthAngle"		//* 方位角		Double
#define TBL_INCLINAT_FLD_DIPANGLE				"DipAngle"			//* 倾角			Double


//测井基本情况表 
#define TBL_LOGGING_TBL "HoleLogging"
#define TBL_LOGGING_FLD_LOGGINGID				"LoggingID"			//* 测井id			int PK
#define TBL_LOGGING_FLD_HOLEID					"HoleID"			//* 钻孔ID			int FK
#define TBL_LOGGING_FLD_DEVICENAME				"DeviceName"		// 仪器名称			varchar
#define TBL_LOGGING_FLD_DEVICETYPE				"DeviceType"		// 仪器型号			varchar
#define TBL_LOGGING_FLD_STARTDEPTH				"StartDepth"		//* 探测起始深度(m)	float
#define TBL_LOGGING_FLD_ENDDEPTH				"EndDepth"			//* 探测终止深度(m)	float
#define TBL_LOGGING_FLD_SAMPLEGAP				"SampleGap"			//* 采样间隔(m)		float
#define TBL_LOGGING_FLD_LOGGINGDOC				"LoggingDoc"		// 测井数据文档		varchar
#define TBL_LOGGING_FLD_TKALD					"TKALD"				// 施工单位			varchar
#define TBL_LOGGING_FLD_OPERATOR				"_Operator"			// 操作人			varchar
#define TBL_LOGGING_FLD_DETECTDATE				"DetectDate"		// 探测日期			date
#define TBL_LOGGING_FLD_INPUTER					"Inputer"			// 录入员			varchar
#define TBL_LOGGING_FLD_INPUTORGN				"InputOrgn"			// 录入单位			varchar
#define TBL_LOGGING_FLD_INPUTDATE				"InputDate"			// 录入日期			date



/*------------------------------------------虚拟钻孔---------------------------------------------*/
#define VIRHOLE_BASEINFO_MDL_CLASS "虚拟钻孔表类"
//标准地层用虚拟钻孔基本信息表
#define TBL_VIRHOLE_TBL "StdStrat_VHole"
#define TBL_VIRHOLE_FLD_VIRHOLEID				"VIRHOLEID"			//* 虚拟孔ID		int
#define TBL_VIRHOLE_FLD_VIRHOLENO				"VIRHOLENO"			//* 虚拟孔号		varchar
#define TBL_VIRHOLE_FLD_X						"X"					//* X			double
#define TBL_VIRHOLE_FLD_Y						"Y"					//* Y			double
#define TBL_VIRHOLE_FLD_Z						"Z"					// Z			double
#define TBL_VIRHOLE_FLD_VIRHOLEDEPTH			"VIRHOLEDEPTH"		//* 孔深			double
#define TBL_VIRHOLE_FLD_PLANECOSYS				"PlaneCoordSys"		//* 平面坐标系	varchar
#define TBL_VIRHOLE_FLD_REGISTRATUNIT			"InputOrgn"			// 录入单位		varchar
#define TBL_VIRHOLE_FLD_REGISTER				"Inputer"			// 录入员		varchar
#define TBL_VIRHOLE_FLD_REGISTRATDATE			"InputDate"			// 录入日期		date


//标准地层用虚拟钻孔分层信息表
#define TBL_VIRHOLELAYER_TBL "StdStrat_VHolelLayer"
#define TBL_VIRHOLELAYER_FLD_VIRHOLELAYERID	"VIRHOLELAYERID"	//* 虚拟分层ID		int PK
#define TBL_VIRHOLELAYER_FLD_VIRHOLEID		"VIRHOLEID"			//* 虚拟孔ID			int FK
#define TBL_VIRHOLELAYER_FLD_VIRHOLENO		"VIRHOLENO"			// 虚拟孔号			varchar
#define TBL_VIRHOLELAYER_FLD_LAYERNO		"LAYERNO"			//* 分层序号			int
#define TBL_VIRHOLELAYER_FLD_VIRLAYERCODE	"VIRLAYERCODE"		//* 虚拟层编码		varchar
#define TBL_VIRHOLELAYER_FLD_GEOCODE		"GEOCODE"			//* 地质代号			varchar
#define TBL_VIRHOLELAYER_FLD_DDCDIA			"DDCDIA"			// 地质时代			varchar
#define TBL_VIRHOLELAYER_FLD_GCKUPE			"CauseType"			// 成因类型			varchar
#define TBL_VIRHOLELAYER_FLD_YSEB			"YSEB"				// 岩土名称			varchar
#define TBL_VIRHOLELAYER_FLD_LAYERDEPTH		"LayerDepth"		// 分层深度			double
#define TBL_VIRHOLELAYER_FLD_LAYERTHICKNESS	"LayerThick"		// 分层厚度			double
#define TBL_VIRHOLELAYER_FLD_YSHB			"YSHB"				// 岩土颜色			varchar
#define TBL_VIRHOLELAYER_FLD_ENGTRAIT		"EngTrait"			// 工程性状			varchar
#define TBL_VIRHOLELAYER_FLD_WATERTRAIT		"WateryTrait"		// 含水性状			varchar
#define TBL_VIRHOLELAYER_FLD_GCKLT		  	"GCKLT"				// 岩性描述			varchar
#define TBL_VIRHOLELAYER_FLD_LAYERID	  	"LAYERID"			// 分层号ID			int
#define TBL_VIRHOLELAYER_FLD_LAYERTOPDEPTH	"LAYERTOPDEPTH"		// 原始层顶深度		double
#define TBL_VIRHOLELAYER_FLD_BOTTOMDEPTH  	"BOTTOMDEPTH"		// 原始层底深度		double
#define TBL_VIRHOLELAYER_FLD_TOPELEVATION 	"TOPELEVATION"		// 原始分层厚度		double
#define TBL_VIRHOLELAYER_FLD_FIELDLAYERNUM	"FieldLayerNum"		// 野外分层号		varchar
#define TBL_VIRHOLELAYER_FLD_HOLECODE	  	"HOLECODE"			// 地层来源钻孔编号			varchar
#define TBL_VIRHOLELAYER_FLD_PKIAA		  	UNION_MACRO_PRJCODE	// 地层来源钻孔的项目统一编号	varchar



/*------------------------------------------- 浅井探槽类--------------------------------------*/
#define WELLSLOT_MDL_CLASS "浅井探槽表类"
	//探槽观测点信息表
#define TBL_WELLSLOT_TBL "HoleDetect"
#define TBL_WELLSLOT_FLD_DETECTID			"DetectID"		//* 探槽观测点ID						int PK
#define TBL_WELLSLOT_FLD_DETECTNO			"DetectNo"		// 探槽观测点编号						varchar
#define TBL_WELLSLOT_FLD_PKIAA				UNION_MACRO_PRJCODE	// 项目统一编号						varchar
#define TBL_WELLSLOT_FLD_DISTANCE			"Distance"		// 与起始点距离(m)					float
#define TBL_WELLSLOT_FLD_ORIENTATION		"Orientation"	// 位于起始点方位(度)					float
//from 浅井探槽基本信息表
#define TBL_WELLSLOT_FLD_PNTID				"PntID"				//* 点ID					int FK
#define TBL_WELLSLOT_FLD_GCEABC				"GCEABC"			// 野外编号				varchar
#define TBL_WELLSLOT_FLD_SWBCBC				"SWBCBC"			// 探井目的				varchar
#define TBL_WELLSLOT_FLD_EXPLORETYPE		"ExploreType"		// 勘探类型				varchar
#define TBL_WELLSLOT_FLD_EXPLOREDEPTH		"ExploreDepth"		// 勘探深度				float
#define TBL_WELLSLOT_FLD_GCJDBN				"GCJDBN"			// 开挖体积				float
#define TBL_WELLSLOT_FLD_SWEGAB				"SWEGAB"			// 水位埋深(m)			float
#define TBL_WELLSLOT_FLD_GCKBBA				"GCKBBA"			// 地形地貌				varchar
#define TBL_WELLSLOT_FLD_GEOCONDIT			"GeoCondit"			// 地质条件				varchar
#define TBL_WELLSLOT_FLD_HYDROCONDIT		"HydroCondit"		// 水文地质条件			varchar
#define TBL_WELLSLOT_FLD_ENGCONDIT			"EngCondit"			// 工程地质条件			varchar
#define TBL_WELLSLOT_FLD_HJY				"HJY"				// 环境地质问题			varchar
#define TBL_WELLSLOT_FLD_ECOENVCONDIT		"EcoEnvCondit"		// 生态环境状况			varchar
#define TBL_WELLSLOT_FLD_GCIAEB				"GCIAEB"			// 土地利用现状			varchar
#define TBL_WELLSLOT_FLD_SWDCG				"SWDCG"				// 沿途观测				varchar
#define TBL_WELLSLOT_FLD_TKALD				"TKALD"				// 施工单位				varchar
#define TBL_WELLSLOT_FLD_TECHNICIAN			"Technician"		// 技术员				varchar
#define TBL_WELLSLOT_FLD_DETECTDATE			"DetectDate"		// 勘探日期				date
#define TBL_WELLSLOT_FLD_INPUTORGN			"InputOrgn"			// 录入单位				varchar
#define TBL_WELLSLOT_FLD_INPUTER			"Inputer"			// 录入员				varchar
#define TBL_WELLSLOT_FLD_INPUTDATE			"InputDate"			// 录入日期				date
#define TBL_WELLSLOT_FLD_SWLBAB				"SWLBAB"			// 平面示意图			varchar
#define TBL_WELLSLOT_FLD_SWLBAA				"SWLBAA"			// 剖面示意图			varchar
#define TBL_WELLSLOT_FLD_SCENEPHOTO			"ScenePhoto"		// 现场照片				varchar
#define TBL_WELLSLOT_FLD_CONSTRUCTRECORD	"ConstructRecord"	// 施工记录				varchar
#define TBL_WELLSLOT_FLD_MEMO				"_Memo"				// 备注					varchar

//浅井探槽岩性分层描述表
#define TBL_WALLSLOTLAYER_TBL "HoleWellSlotLayer"
#define TBL_WALLSLOTLAYER_FLD_WALLSLOTLAYERID		"WallSlotLayerID"		//* 井槽分层ID		int PK
#define TBL_WALLSLOTLAYER_FLD_FIELDLAYERNO			"FieldLayerNo"			// 野外分层号		varchar
#define TBL_WALLSLOTLAYER_FLD_GCEABC				"GCEABC"				// 野外编号			varchar
#define TBL_WALLSLOTLAYER_FLD_PKIAA					UNION_MACRO_PRJCODE		// 项目编号		varchar
#define TBL_WALLSLOTLAYER_FLD_DETECTID				"DetectID"				//* 探槽观测点ID		int
#define TBL_WALLSLOTLAYER_FLD_TOPDEPTH				"TopDepth"				//* 层顶深度(m)		double
#define TBL_WALLSLOTLAYER_FLD_BOTTOMDEPTH			"BottomDepth"			//* 层底深度(m)		double
#define TBL_WALLSLOTLAYER_FLD_TOPELEVATION			"TopElevation"			// 层顶高程(m)		double
#define TBL_WALLSLOTLAYER_FLD_BOTTOMELEVATION		"BottomElevation"		// 层底高程(m)		double
#define TBL_WALLSLOTLAYER_FLD_LAYERTHICK			"LayerThick"			// 分层厚度(m)		double
#define TBL_WALLSLOTLAYER_FLD_GEOCODE				"GeoCode"				// 地质代号			varchar
#define TBL_WALLSLOTLAYER_FLD_DDCDIA				"DDCDIA"				// 地质时代			varchar
#define TBL_WALLSLOTLAYER_FLD_GCKUPE				"CauseType"				// 成因类型			varchar
#define TBL_WALLSLOTLAYER_FLD_YSEB					"YSEB"					// 岩土名称			varchar
#define TBL_WALLSLOTLAYER_FLD_YSHB					"YSHB"					// 岩土颜色			varchar
#define TBL_WALLSLOTLAYER_FLD_ENGTRAIT				"EngTrait"				// 工程性状			varchar
#define TBL_WALLSLOTLAYER_FLD_WATERYTRAIT			"WateryTrait"			// 含水性状			varchar
#define TBL_WALLSLOTLAYER_FLD_GCKLT					"GCKLT"					// 岩性描述			varchar


/*----------------------------------------物探点线类--------------------------------*/
#define LINE_MDL_CLASS "物探点线表类"
	//电（磁）法勘探线参数表
#define TBL_ELECLINE_TBL "PhyElecline"
#define TBL_ELECLINE_FLD_ELECLINEID			"EleclineID"		//* 电(磁)法测线ID	 int PK
#define TBL_ELECLINE_FLD_LINECODE			"LineCode"			// 测线号			varchar
#define TBL_ELECLINE_FLD_DOTPITCH			"DotPitch"			// 点距(m)			float
#define TBL_ELECLINE_FLD_DETEDOTCOUNT		"DetedotCount"		// 测点数			int
#define TBL_ELECLINE_FLD_DETELINELENGTH		"DetelineLength"	// 测线长度(km)		float
#define TBL_ELECLINE_FLD_DATELINEORIENT		"DatelineOrient"	// 测线方位(度)		float
#define TBL_ELECLINE_FLD__DEVICE			"_Device"			// 仪器				varchar
#define TBL_ELECLINE_FLD_DEVICETYPE			"DeviceType"		// 装置类型			varchar
#define TBL_ELECLINE_FLD_RECDISDIST			"RecdisDist"		// 收发距(m)		float
#define TBL_ELECLINE_FLD__FREQUENCY			"_Frequency"		// 频率(Hz)			float
#define TBL_ELECLINE_FLD_LAUNCHBOXAREA		"LaunchBoxArea"		// 发射框面积(m2)	float
#define TBL_ELECLINE_FLD_RECBOXAREA			"RecboxArea"		// 接收线框面积(m2)	float
#define TBL_ELECLINE_FLD_ANTENNAFRE			"AntennaFre"		// 天线频率(Hz)		float
#define TBL_ELECLINE_FLD_ANTENNADIST		"AntennaDist"		// 天线间距(m)		float
// from 物探测线基本情况表
#define TBL_ELECLINE_FLD_FLD_PRJID				UNION_MACRO_PRJID	//* 项目ID				int FK
#define TBL_ELECLINE_FLD_FLD_DETECTMETHOD		"DetectMethod"		// 探测方法				varchar
#define TBL_ELECLINE_FLD_FLD_TKALD				"TKALD"				// 施工单位				varchar
#define TBL_ELECLINE_FLD_FLD_OPERATOR			"_Operator"			// 操作人				varchar
#define TBL_ELECLINE_FLD_FLD_CHECKER			"Checker"			// 检查人				varchar
#define TBL_ELECLINE_FLD_FLD_STARTDATE			"StartDate"			// 起始日期				date
#define TBL_ELECLINE_FLD_FLD_ENDDATE			"EndDate"			// 完成日期				date
#define TBL_ELECLINE_FLD_FLD_ORIGDOCID			"OrigDocID"			// 原始数据文档ID		int
#define TBL_ELECLINE_FLD_FLD_DRRORDOCID			"DrrorDocID"		// 误差文档ID			int
#define TBL_ELECLINE_FLD_FLD_PARADOCID			"ParaDocID"			// 参数文档ID			varchar
#define TBL_ELECLINE_FLD_FLD_RESULTDOCID		"resultDocID"		// 成果数据文档ID		int
#define TBL_ELECLINE_FLD_FLD_INPUTER			"Inputer"			// 录入员				varchar
#define TBL_ELECLINE_FLD_FLD_INPUTORGN			"InputOrgn"			// 录入单位				varchar
#define TBL_ELECLINE_FLD_FLD_INPUTDATE			"InputDate"			// 录入日期				date


//地震勘探线参数表
#define TBL_EARDETELINE_TBL "PhyEardeteline"
#define TBL_EARDETELINE_FLD_EARDETELINEID		"EardetelineID"		//* 地震测线ID		int PK
#define TBL_EARDETELINE_FLD_LINECODE			"LineCode"			// 测线号			varchar
#define TBL_EARDETELINE_FLD_ROADDIST			"RoadDist"			// 道间距(m)		float
#define TBL_EARDETELINE_FLD_RECTIME				"RecTime"			// 接收道数(道)		int
#define TBL_EARDETELINE_FLD_FLIPCOVERTIME		"FlipcoverTime"		// 水平覆盖次数(次)	int
#define TBL_EARDETELINE_FLD_SAMPLEGAP			"SampleGap"			// 采样间隔(s)		int
#define TBL_EARDETELINE_FLD_RECORDLENGTH		"RecordLength"		// 记录长度			float
#define TBL_EARDETELINE_FLD_BOMBDIST			"BombDist"			// 炮间距(m)		float
#define TBL_EARDETELINE_FLD_DFFSETDIST			"DffsetDist"		// 偏移距(m)		float
#define TBL_EARDETELINE_FLD_RECULENGTH			"RecuLength"		// 迭代段长(m)		float
#define TBL_EARDETELINE_FLD_TRIANGLEMAXLEN		"TriangleMaxlen"	// 三角形最大边长(m) float
// from 物探测线基本情况表
#define TBL_EARDETELINE_FLD_PRJID				UNION_MACRO_PRJID	//* 项目ID				int FK
#define TBL_EARDETELINE_FLD_DETECTMETHOD		"DetectMethod"		// 探测方法				varchar
#define TBL_EARDETELINE_FLD_TKALD				"TKALD"				// 施工单位				varchar
#define TBL_EARDETELINE_FLD_OPERATOR			"_Operator"			// 操作人				varchar
#define TBL_EARDETELINE_FLD_CHECKER				"Checker"			// 检查人				varchar
#define TBL_EARDETELINE_FLD_STARTDATE			"StartDate"			// 起始日期				date
#define TBL_EARDETELINE_FLD_ENDDATE				"EndDate"			// 完成日期				date
#define TBL_EARDETELINE_FLD_ORIGDOCID			"OrigDocID"			// 原始数据文档ID		int
#define TBL_EARDETELINE_FLD_DRRORDOCID			"DrrorDocID"		// 误差文档ID			int
#define TBL_EARDETELINE_FLD_PARADOCID			"ParaDocID"			// 参数文档ID			varchar
#define TBL_EARDETELINE_FLD_RESULTDOCID			"resultDocID"		// 成果数据文档ID		int
#define TBL_EARDETELINE_FLD_INPUTER				"Inputer"			// 录入员				varchar
#define TBL_EARDETELINE_FLD_INPUTORGN			"InputOrgn"			// 录入单位				varchar
#define TBL_EARDETELINE_FLD_INPUTDATE			"InputDate"			// 录入日期				date



//物探点位标准化信息表
#define TBL_STDPNT_TBL "PhyStdPnt"
#define TBL_STDPNT_FLD_STDPNTID			"StdPntID"			//* 标准测点ID		int PK
#define TBL_STDPNT_FLD_PNTNO			"PntNo"				// 点号				varchar
#define TBL_STDPNT_FLD_STKCAF			"STKCAF"			//* 标准化X			double
#define TBL_STDPNT_FLD_STKCAG			"STKCAG"			//* 标准化Y			double
#define TBL_STDPNT_FLD_SGCJCBJ			"SGCJCBJ"			//* 标准化高程(m)	double
#define TBL_STDPNT_FLD_STDPLANECOORDSYS	"StdPlaneCoordSys"	// 标准化平面坐标系	varchar
#define TBL_STDPNT_FLD_STDELDATUM		"stdElDatum"		// 标准化高程基准	varchar
//from 物探点位信息表
#define TBL_STDPNT_FLD_LONGITUDE		"Longitude"		// 经度(°)			double
#define TBL_STDPNT_FLD_LATITUDE			"Latitude"		// 纬度(°)			double
#define TBL_STDPNT_FLD_TKCAF			"TKCAF"			// X				double
#define TBL_STDPNT_FLD_TKCAG			"TKCAG"			// Y				double
#define TBL_STDPNT_FLD_GCJCBJ			"GCJCBJ"		// 高程(m)			double
#define TBL_STDPNT_FLD_PLANECOORDSYS	"PlaneCoordSys"	// 平面坐标系		varchar
#define TBL_STDPNT_FLD_ELEDATUM			"EleDatum"		// 高程基准			varchar
// from 物探测线基本情况表
#define TBL_STDPNT_FLD_LINECODE			"LineCode"			// 测线号			varchar
#define TBL_STDPNT_FLD_PRJID			UNION_MACRO_PRJID	//* 项目ID				int FK
#define TBL_STDPNT_FLD_PKIAA			UNION_MACRO_PRJCODE	// 项目统一编号		varcharint FK
#define TBL_STDPNT_FLD_DETECTMETHOD		"DetectMethod"		// 探测方法				varchar
#define TBL_STDPNT_FLD_TKALD			"TKALD"				// 施工单位				varchar
#define TBL_STDPNT_FLD_OPERATOR			"_Operator"			// 操作人				varchar
#define TBL_STDPNT_FLD_CHECKER			"Checker"			// 检查人				varchar
#define TBL_STDPNT_FLD_STARTDATE		"StartDate"			// 起始日期				date
#define TBL_STDPNT_FLD_ENDDATE			"EndDate"			// 完成日期				date
#define TBL_STDPNT_FLD_ORIGDOCID		"OrigDocID"			// 原始数据文档ID		int
#define TBL_STDPNT_FLD_DRRORDOCID		"DrrorDocID"		// 误差文档ID			int
#define TBL_STDPNT_FLD_PARADOCID		"ParaDocID"			// 参数文档ID			varchar
#define TBL_STDPNT_FLD_RESULTDOCID		"resultDocID"		// 成果数据文档ID		int
#define TBL_STDPNT_FLD_INPUTER			"Inputer"			// 录入员				varchar
#define TBL_STDPNT_FLD_INPUTORGN		"InputOrgn"			// 录入单位				varchar
#define TBL_STDPNT_FLD_INPUTDATE		"InputDate"			// 录入日期				date


/*----------------------------------------钻孔分层类-----------------------------------*/
#define STDSTRATVER_MDL_CLASS "钻孔分层类表"
	//标准地层版本表 *
#define TBL_STDSTRATVER_TBL "hole_stdStratVer"
#define TBL_STDSTRATVER_FLD_STDSTRATID		"StdStratID"		//* 标准地层版本		int
#define TBL_STDSTRATVER_FLD_STDSTRATNAME	"StdStratName"		//* 标准地层名称		varchar
#define TBL_STDSTRATVER_FLD_PROTYPE			"ProType"			// 专业类别			varchar
#define TBL_STDSTRATVER_FLD_PROCODE			"ProCode"			// 专业代码			varchar
#define TBL_STDSTRATVER_FLD_PRONAME			"ProName"			// 专业名称			varchar
#define TBL_STDSTRATVER_FLD_STDAUTHOR		"StdAuthor"			// 标准作者			varchar
#define TBL_STDSTRATVER_FLD_STRATLEVNUM		"StratLevelNum"		// 地层级别数		int
#define TBL_STDSTRATVER_FLD_MEMO			"_Memo"				// 备注				varchar


//标准地层描述表 *
#define TBL_STDSTRAT_TBL "hole_stdStratDesc"
#define TBL_STDSTRAT_FLD_ROWID				"ID"			//* 标准地层分层记录ID	int			PK
#define TBL_STDSTRAT_FLD_STDSTRATID			"StdStratID"	//* 标准地层版本ID		int			FK
#define TBL_STDSTRAT_FLD_STRATLEVEL			"StratOrder"	//* 地层分级编号(如1-1-1) varchar
#define TBL_STDSTRAT_FLD_STRATNAME			"StratName"		//* 地层名称				varchar
#define TBL_STDSTRAT_FLD_STRATCODE			"StratCode"		//* 地层编码（Q1,J2,①）	varchar
#define TBL_STDSTRAT_FLD_STRATCODE2			"StratCode2"	// 地层编码2（用于地层合并整理）	varchar
#define TBL_STDSTRAT_FLD_STRATTYPE			"StratType"		//* 地层类型				int
#define TBL_STDSTRAT_FLD_STRATCLR			"StratClr"		//* 地层颜色				int
#define TBL_STDSTRAT_FLD_PATTERNNO			"PatternNo"		//* 图案名称				text (注意)
#define TBL_STDSTRAT_FLD_PATTERNCLR			"PatternClr"	//* 图案颜色				int
#define TBL_STDSTRAT_FLD_PATTERNHEIGHT		"PatternHeight"	// 图案高度				Float
#define TBL_STDSTRAT_FLD_PATTERNWIDTH		"PatternWidth"	// 图案宽度				Float
#define TBL_STDSTRAT_FLD_FILLDIR			"FillDir"		// 图案旋转方向			Float
#define TBL_STDSTRAT_FLD_STRATDESC			"StratDesc"		//* 地层描述				varchar
#define TBL_STDSTRAT_FLD_CAUSECODE			"CauseCode"		// 成因代码				varchar
#define TBL_STDSTRAT_FLD_DECAYRATE			"DecayRate"		//风化程度				varchar
#define TBL_STDSTRAT_FLD_CAUSETYPE			"CauseType"		// 地层成因				varchar
#define TBL_STDSTRAT_FLD_AGENO				"AgeNo"			// 地质时代				varchar
#define TBL_STDSTRAT_FLD_GEOCODE			"GeoCode"		// 地层代号				varchar
#define TBL_STDSTRAT_FLD_ENGTRAIT			"EngTrait"		// 工程性状				varchar
#define TBL_STDSTRAT_FLD_WATERYTRAIT		"WateryTrait"	// 含水性状				varchar
#define TBL_STDSTRAT_FLD_FIELDLAYERID		"FieldLayerID"	// 野外分层ID			int
#define TBL_STDSTRAT_FLD_FIELDLAYERNUM		"FieldLayerNum"	// 野外分层号			varchar
#define TBL_STDSTRAT_FLD_YSEB				"YSEB"			// 岩土名称				varchar
#define TBL_STDSTRAT_FLD_YSHB				"YSHB"			// 岩土颜色				varchar
#define TBL_STDSTRAT_FLD__MEMO				"_Memo"			// 备注					varchar

//钻孔分层表 *
#define TBL_HOLELAYER_TBL "HoleLayer"
#define TBL_HOLELAYER_FLD_ROWID				"ID"			//* 钻孔分层记录ID	int			PK
#define TBL_HOLELAYER_FLD_HOLEID			"HoleID"			//* 钻孔ID		int
#define TBL_HOLELAYER_FLD_STDSTRATID		"StdStratID"		//* 标准地层版本ID	int
#define TBL_HOLELAYER_FLD_STRATCODE		"StratCode"			//* 地层编码		varchar
#define TBL_HOLELAYER_FLD_STRATNAME		"StratName"			//* 地层名称			varchar
#define TBL_HOLELAYER_FLD_TOPDEPTH		"TopDepth"			//* 层顶埋深		double
#define TBL_HOLELAYER_FLD_BTMDEPTH		"BtmDepth"			//* 层底埋深		double
#define TBL_HOLELAYER_FLD_GCKLT			"GCKLT"				//* 地层描述		varchar
#define TBL_HOLELAYER_FLD_DDCDIA			"DDCDIA"			// 地质时代		varchar
#define TBL_HOLELAYER_FLD_GCKUPE			"GCKUPE"			// 成因类型		varchar
#define TBL_HOLELAYER_FLD_GEOCODE		"GeoCode"			// 地质代号			varchar
#define TBL_HOLELAYER_FLD_YSEB			"YSEB"				// 岩土名称			varchar
#define TBL_HOLELAYER_FLD_YSHB			"YSHB"				// 岩土颜色			varchar
#define TBL_HOLELAYER_FLD_ENGTRAIT		"EngTrait"			// 工程性状			varchar
#define TBL_HOLELAYER_FLD_WATERYTRAIT	"WateryTrait"		// 含水性状			varchar
#define TBL_HOLELAYER_FLD_FIELDLAYERID	"FieldLayerID"		// 野外分层ID		int
#define TBL_HOLELAYER_FLD_FIELDLAYERNUM	"FieldLayerNum"		// 野外分层号		varchar


//钻孔原始分层表 
#define TBL_ORIGLAYER_TBL "HoleOrigLayer"
#define TBL_ORIGLAYER_FLD_FIELDLAYERID		"FieldLayerID"		//* 野外分层号ID		int PK
#define TBL_ORIGLAYER_FLD_FIELDLAYERNUM		"FieldLayerNum"		//* 野外分层号		varchar
#define TBL_ORIGLAYER_FLD_HOLEID			"HoleID"			//* 钻孔ID			int FK
#define TBL_ORIGLAYER_FLD_GEOCODE			"GeoCode"			//* 地质代号			varchar
#define TBL_ORIGLAYER_FLD_DDCDIA			"DDCDIA"			//* 地质时代			varchar
#define TBL_ORIGLAYER_FLD_GCKUPE			"CauseType"			//* 成因类型			varchar
#define TBL_ORIGLAYER_FLD_TOPDEPTH			"TopDepth"			//* 层顶深度			double
#define TBL_ORIGLAYER_FLD_BOTTOMDEPTH		"BottomDepth"		//* 层底深度			double
#define TBL_ORIGLAYER_FLD_TOPELEVATION		"TopElevation"		// 层顶高程			double
#define TBL_ORIGLAYER_FLD_BOTTOMELEVATION	"BottomElevation"	// 层底高程			double
#define TBL_ORIGLAYER_FLD_LAYERTHICK		"LayerThick"		//* 分层厚度			double
#define TBL_ORIGLAYER_FLD_YSEB				"YSEB"				//* 岩土名称			varchar
#define TBL_ORIGLAYER_FLD_YSHB				"YSHB"				//* 岩土颜色			varchar
#define TBL_ORIGLAYER_FLD_ENGTRAIT			"EngTrait"			//* 工程性状			varchar
#define TBL_ORIGLAYER_FLD_WATERYTRAIT		"WateryTrait"		//* 含水性状			varchar
#define TBL_ORIGLAYER_FLD_GCKLT				"GCKLT"				//* 岩性描述			varchar




/*----------------------------------------钻孔结构类-----------------------------------*/
#define HOLEPACK_MDL_CLASS "钻孔结构类表"
	//止水结构表
#define TBL_WATERSEAL_TBL "HoleWaterSeal"
#define TBL_WATERSEAL_FLD_WATERSEALID		"WaterSealID"		// 止水ID		int
#define TBL_WATERSEAL_FLD_HOLEID			"HoleID"			// 钻孔ID		int
#define TBL_WATERSEAL_FLD_SWCEA				"SWCEA"				// 止水深度(m)	double
#define TBL_WATERSEAL_FLD_SWCEB				"SWCEB"				// 止水方法		varchar
#define TBL_WATERSEAL_FLD_SEALINGMATERIAL	"SealingMaterial"	// 止水材料		varchar

//填砾结构表
#define TBL_GRAVELPACK_TBL "HoleGravelPack"
#define TBL_GRAVELPACK_FLD_GRAVELPACKID		"GravelPackID"		// 填砾ID			int		
#define TBL_GRAVELPACK_FLD_HOLEID			"HoleID"			// 钻孔ID			int
#define TBL_GRAVELPACK_FLD_SWCDH			"SWCDH"				// 填砾顶深度(m)	double		
#define TBL_GRAVELPACK_FLD_SWCGBD			"SWCGBD"			// 填砾底深度(m)	double		
#define TBL_GRAVELPACK_FLD_SWCGBC			"SWCGBC"			// 填砾厚度(m)		double	
#define TBL_GRAVELPACK_FLD_SWCDF			"SWCDF"				// 砾料类型			varchar
#define TBL_GRAVELPACK_FLD_GRAVELSPECIFY	"GravelSpecify"		// 砾料规格			varchar

//井管结构表
#define TBL_WELLPIPE_TBL "HoleWellPipe"
#define TBL_WELLPIPE_FLD_WELLPIPEID			"WellPipeID"		// 井管ID			int
#define TBL_WELLPIPE_FLD_HOLEID				"HoleID"			// 钻孔ID			int
#define TBL_WELLPIPE_FLD_TKACE				"TKACE"				// 变径深度(m)		double
#define TBL_WELLPIPE_FLD_HOLETOPDIAM		"HoleTopDiam"		// 井口外径(mm)		double
#define TBL_WELLPIPE_FLD_SWCCB				"SWCCB"				// 井管类型			varchar
#define TBL_WELLPIPE_FLD_WELLPIPEMATERIAL	"WellPipeMaterial"	// 井管材质			varchar

//孔径变化表
#define TBL_APERTURE_TBL "HoleAperture"
#define TBL_APERTURE_FLD_APERTUREID			"ApertureID"		// 孔径ID			int
#define TBL_APERTURE_FLD_HOLEID				"HoleID"			// 钻孔ID			int
#define TBL_APERTURE_FLD_TKACE				"TKACE"				// 变径深度(m)		Float
#define TBL_APERTURE_FLD_SWCL				"SWCL"				// 钻孔直径(mm)		Float



/*----------------------------------------现场力学试验（原位测试）类-----------------------------------*/
#define EGYWCS_MDL_CLASS "现场力学试验（原位测试）表类"

	//标准贯入试验记录表
#define TBL_EGSTDPENETRATION_TBL "EgStdPenetration"
#define TBL_EGSTDPENETRATION_FLD_STDPENETRATID			"StdPenetratID"		    //* 标贯记录ID				int
#define TBL_EGSTDPENETRATION_FLD_TESTHORIZON			UNION_MACRO_TCDH		//* 试验层位					varchar
#define TBL_EGSTDPENETRATION_FLD_STARTDEPTH				UNION_MACRO_START_DEPTH	//* 起深度(m)				float
#define TBL_EGSTDPENETRATION_FLD_ENDDEPTH				UNION_MACRO_END_DEPTH	//* 止深度(m)				float
#define TBL_EGSTDPENETRATION_FLD_PNTID					UNION_MACRO_PNT_ID		//* 点ID						int  FK
#define TBL_EGSTDPENETRATION_FLD_INSITUTESTNO			UNION_MACRO_TESTNO		// 试验编号					varchar
#define TBL_EGSTDPENETRATION_FLD_TESTCATEGORY			UNION_MACRO_TESTTYPE	// 试验类型					varchar
#define TBL_EGSTDPENETRATION_FLD_HAMMERNUM				"HammerNum"				// 锤击数					int
#define TBL_EGSTDPENETRATION_FLD_HITMEASNUM				"HitMeasNum"			// 实测标贯击数(击/30cm)	float
#define TBL_EGSTDPENETRATION_FLD_POLELENGTH				"PoleLength"			// 杆长(m)					float
#define TBL_EGSTDPENETRATION_FLD_RODCORRECTFACTOR		"RodCorrectFactor"		// 杆长校正系数				float
#define TBL_EGSTDPENETRATION_FLD_HITCORRECTNUM			"HitCorrectNum"			// 校正后标贯击数(击/30cm)	float
#define TBL_EGSTDPENETRATION_FLD_GEOCODE				UNION_MACRO_GEOCODE		//地质代号					varchar
#define TBL_EGSTDPENETRATION_FLD_TCMC					UNION_MACRO_TCMC		// 土层名称					varchar
#define TBL_EGSTDPENETRATION_FLD__MEMO					UNION_MACRO_NOTE		// 备注						varchar
// from 原位测试基本情况表 * -- LH.2021.08.30 added.
#define TBL_EGSTDPENETRATION_FLD_TEST_EQUIPMODEL		"TestEquipModel"		// 试验设备及型号		Varchar		
#define TBL_EGSTDPENETRATION_FLD_TESTSTARTDATE			"TestStartDate"			// 试验开始日期		Date	
#define TBL_EGSTDPENETRATION_FLD_TESTENDDATE			"TestEndDate"			// 试验完成日期		Date	
#define TBL_EGSTDPENETRATION_FLD_TESTORGN				"TestOrgn"				// 试验单位			Varchar
#define TBL_EGSTDPENETRATION_FLD_OPERATOR				"_Operator"				// 操作人			Varchar
#define TBL_EGSTDPENETRATION_FLD_TECHNICIAN				"Technician"			// 现场技术员		Varchar	
#define TBL_EGSTDPENETRATION_FLD_INPUTER				"Inputer"				// 录入员			Varchar
#define TBL_EGSTDPENETRATION_FLD_INPUTORGN				"InputOrgn"				// 录入单位			Varchar
#define TBL_EGSTDPENETRATION_FLD_INPUTDATE				"InputDate"				// 录入日期			date


//静力触探试验记录表
#define TBL_EGSTATICPENETRATION_TBL "EgStaticPenetration"
#define TBL_EGSTATICPENETRATION_FLD_STATICCONTACTID		"StaticContactID"			//* 静探试验ID			int PK
#define TBL_EGSTATICPENETRATION_FLD_TESTHORIZON			UNION_MACRO_TCDH			//* 试验层位				varchar
#define TBL_EGSTATICPENETRATION_FLD_STARTDEPTH			UNION_MACRO_START_DEPTH		//* 起深度				float
#define TBL_EGSTATICPENETRATION_FLD_ENDDEPTH			UNION_MACRO_END_DEPTH		//* 止深度				float
#define TBL_EGSTATICPENETRATION_FLD_PNTID				UNION_MACRO_PNT_ID			//* 点ID				int  FK
#define TBL_EGSTATICPENETRATION_FLD_INSITUTESTNO		UNION_MACRO_TESTNO			// 试验编号			varchar
#define TBL_EGSTATICPENETRATION_FLD_TESTCATEGORY		UNION_MACRO_TESTTYPE		// 试验类型				varchar
#define TBL_EGSTATICPENETRATION_FLD_PROBETYPE			"ProbeType"				// 探头类型				varchar		
#define TBL_EGSTATICPENETRATION_FLD_GCEBCJ				"GCEBCJ"				// 锥尖阻力				float
#define TBL_EGSTATICPENETRATION_FLD_GCEBCK				"GCEBCK"				// 侧壁摩阻力			float
#define TBL_EGSTATICPENETRATION_FLD_GCEBCM				"GCEBCM"				// 比贯入阻力			float
#define TBL_EGSTATICPENETRATION_FLD_GCDLAK				"GCDLAK"				// 孔隙水压力			float
#define TBL_EGSTATICPENETRATION_FLD_FRICTIONRATIO		"FrictionRatio"			// 摩阻比				float
#define TBL_EGSTATICPENETRATION_FLD_GEOCODE				UNION_MACRO_GEOCODE		//地质代号					varchar
#define TBL_EGSTATICPENETRATION_FLD_TCMC				UNION_MACRO_TCMC		// 土层名称					varchar
#define TBL_EGSTATICPENETRATION_FLD__MEMO				UNION_MACRO_NOTE		// 备注					varchar
// from 原位测试基本情况表 * -- LH.2021.08.30 added.
#define TBL_EGSTATICPENETRATION_FLD_TEST_EQUIPMODEL		"TestEquipModel"		// 试验设备及型号	Varchar		
#define TBL_EGSTATICPENETRATION_FLD_TESTSTARTDATE		"TestStartDate"			// 试验开始日期		Date	
#define TBL_EGSTATICPENETRATION_FLD_TESTENDDATE			"TestEndDate"			// 试验完成日期		Date	
#define TBL_EGSTATICPENETRATION_FLD_TESTORGN			"TestOrgn"				// 试验单位			Varchar
#define TBL_EGSTATICPENETRATION_FLD_OPERATOR			"_Operator"				// 操作人			Varchar
#define TBL_EGSTATICPENETRATION_FLD_TECHNICIAN			"Technician"			// 现场技术员		Varchar	
#define TBL_EGSTATICPENETRATION_FLD_INPUTER				"Inputer"				// 录入员			Varchar
#define TBL_EGSTATICPENETRATION_FLD_INPUTORGN			"InputOrgn"				// 录入单位			Varchar
#define TBL_EGSTATICPENETRATION_FLD_INPUTDATE			"InputDate"				// 录入日期			date

//重型动力触探实验记录表
#define TBL_MOTDETECT_TBL "EgMotDetect"
#define TBL_MOTDETECT_FLD_MOTDETECTID			"MotDetectID"					//* 动探记录ID				int PK
#define TBL_MOTDETECT_FLD_TESTHORIZON			"TestHorizon"					//* 试验层位					Varchar
#define TBL_MOTDETECT_FLD_STARTDEPTH			UNION_MACRO_START_DEPTH			//* 起深度					Float
#define TBL_MOTDETECT_FLD_ENDDEPTH				UNION_MACRO_END_DEPTH			//* 止深度					Float
#define TBL_MOTDETECT_FLD_PNTID					UNION_MACRO_PNT_ID				//* 点ID				int  FK
#define TBL_MOTDETECT_FLD_INSITUTESTNO			UNION_MACRO_TESTNO			// 试验编号				Varchar
#define TBL_MOTDETECT_FLD_TESTCATEGORY			UNION_MACRO_TESTTYPE		// 试验类型					varchar
#define TBL_MOTDETECT_FLD_SOUNDTYPE				"SoundType"				// 触探类型					Varchar
#define TBL_MOTDETECT_FLD_HAMMERNUM				"HammerNum"				// 实测锤击数				double
#define TBL_MOTDETECT_FLD_POLELENGTH			"PoleLength"			// 杆长						double
#define TBL_MOTDETECT_FLD_RODCORRECTFACTOR		"RodCorrectFactor"		// 杆长校正系数				Float
#define TBL_MOTDETECT_FLD_SWEGAB				"SWEGAB"				// 地下水位埋深				float
#define TBL_MOTDETECT_FLD_GCBAF					"GCBAF"					// 粘粒含量					float
#define TBL_MOTDETECT_FLD_HITCORRECTNUM			"HitCorrectNum"			// 修正后锤击数				double -- LH.2021.09.02 09:56 type changed.
#define TBL_MOTDETECT_FLD_PENETRATCORRECT		"PenetratCorrect"		// 修正后贯入度				float
#define TBL_MOTDETECT_FLD_GEOCODE				UNION_MACRO_GEOCODE		//地质代号					varchar
#define TBL_MOTDETECT_FLD_TCMC					UNION_MACRO_TCMC				// 土层名称					varchar
#define TBL_MOTDETECT_FLD__MEMO					UNION_MACRO_NOTE				// 备注					varchar
// from 原位测试基本情况表 * -- LH.2021.08.30 added.
#define TBL_MOTDETECT_FLD_TEST_EQUIPMODEL		"TestEquipModel"	// 试验设备及型号	Varchar		
#define TBL_MOTDETECT_FLD_TESTSTARTDATE			"TestStartDate"		// 试验开始日期		Date	
#define TBL_MOTDETECT_FLD_TESTENDDATE			"TestEndDate"		// 试验完成日期		Date	
#define TBL_MOTDETECT_FLD_TESTORGN				"TestOrgn"			// 试验单位			Varchar
#define TBL_MOTDETECT_FLD_OPERATOR				"_Operator"			// 操作人			Varchar
#define TBL_MOTDETECT_FLD_TECHNICIAN			"Technician"		// 现场技术员		Varchar	
#define TBL_MOTDETECT_FLD_INPUTER				"Inputer"			// 录入员			Varchar
#define TBL_MOTDETECT_FLD_INPUTORGN				"InputOrgn"			// 录入单位			Varchar
#define TBL_MOTDETECT_FLD_INPUTDATE				"InputDate"			// 录入日期			date

//轻型动力触探实验记录表
#define TBL_LIGHTMOTDETECT_TBL "LightEgMotDetect"
#define TBL_LIGHTMOTDETECT_FLD_MOTDETECTID		 "MotDetectID"				//* 动探记录ID				int PK
#define TBL_LIGHTMOTDETECT_FLD_TESTHORIZON		 "TestHorizon"				//* 试验层位					Varchar
#define TBL_LIGHTMOTDETECT_FLD_STARTDEPTH		 UNION_MACRO_START_DEPTH	//* 起深度					Float
#define TBL_LIGHTMOTDETECT_FLD_ENDDEPTH			 UNION_MACRO_END_DEPTH		//* 止深度					Float
#define TBL_LIGHTMOTDETECT_FLD_PNTID			 UNION_MACRO_PNT_ID			//* 点ID				int  FK
#define TBL_LIGHTMOTDETECT_FLD_INSITUTESTNO		 UNION_MACRO_TESTNO			// 试验编号				Varchar
#define TBL_LIGHTMOTDETECT_FLD_TESTCATEGORY		 UNION_MACRO_TESTTYPE		// 试验类型					varchar
#define TBL_LIGHTMOTDETECT_FLD_SOUNDTYPE		 "SoundType"				// 触探类型					Varchar		
#define TBL_LIGHTMOTDETECT_FLD_HAMMERNUM		 "HammerNum"				// 实测锤击数				double
#define TBL_LIGHTMOTDETECT_FLD_POLELENGTH		 "PoleLength"				// 杆长						double
#define TBL_LIGHTMOTDETECT_FLD_RODCORRECTFACTOR	 "RodCorrectFactor"			// 杆长校正系数				Float
#define TBL_LIGHTMOTDETECT_FLD_SWEGAB			 "SWEGAB"					// 地下水位埋深				float
#define TBL_LIGHTMOTDETECT_FLD_GCBAF			 "GCBAF"					// 粘粒含量					float
#define TBL_LIGHTMOTDETECT_FLD_HITCORRECTNUM	 "HitCorrectNum"			// 修正后锤击数				int
#define TBL_LIGHTMOTDETECT_FLD_PENETRATCORRECT	 "PenetratCorrect"			// 修正后贯入度				float
#define TBL_LIGHTMOTDETECT_FLD_GEOCODE  		 UNION_MACRO_GEOCODE		//地质代号					varchar
#define TBL_LIGHTMOTDETECT_FLD_TCMC				 UNION_MACRO_TCMC			// 土层名称					varchar
#define TBL_LIGHTMOTDETECT_FLD__MEMO			 UNION_MACRO_NOTE			// 备注					varchar
// from 原位测试基本情况表 * -- LH.2021.08.30 added.
#define TBL_LIGHTMOTDETECT_FLD_TEST_EQUIPMODEL	 "TestEquipModel"			// 试验设备及型号		Varchar		
#define TBL_LIGHTMOTDETECT_FLD_TESTSTARTDATE	 "TestStartDate"			// 试验开始日期		Date	
#define TBL_LIGHTMOTDETECT_FLD_TESTENDDATE		 "TestEndDate"				// 试验完成日期		Date	
#define TBL_LIGHTMOTDETECT_FLD_TESTORGN			 "TestOrgn"					// 试验单位			Varchar
#define TBL_LIGHTMOTDETECT_FLD_OPERATOR			 "_Operator"				// 操作人			Varchar
#define TBL_LIGHTMOTDETECT_FLD_TECHNICIAN		 "Technician"				// 现场技术员		Varchar	
#define TBL_LIGHTMOTDETECT_FLD_INPUTER			 "Inputer"					// 录入员			Varchar
#define TBL_LIGHTMOTDETECT_FLD_INPUTORGN		 "InputOrgn"				// 录入单位			Varchar
#define TBL_LIGHTMOTDETECT_FLD_INPUTDATE		 "InputDate"				// 录入日期			date

//十字板剪切试验记录表
#define TBL_EGSHEAR_TBL "EgShear"
#define TBL_EGSHEAR_FLD_CROSSPLATEID		"CrossPlateID"				//* 十字板试验ID				int PK
#define TBL_EGSHEAR_FLD_TESTHORIZON			UNION_MACRO_TCDH			//* 试验层位					varchar
#define TBL_EGSHEAR_FLD_STARTDEPTH			UNION_MACRO_START_DEPTH			//* 起深度(m)				float
#define TBL_EGSHEAR_FLD_ENDDEPTH			UNION_MACRO_END_DEPTH			//* 止深度(m)				float		
#define TBL_EGSHEAR_FLD_PNTID				UNION_MACRO_PNT_ID				//* 点ID				int  FK
#define TBL_EGSHEAR_FLD_INSITUTESTNO		UNION_MACRO_TESTNO			// 试验编号				Varchar
#define TBL_EGSHEAR_FLD_TESTCATEGORY		UNION_MACRO_TESTTYPE		// 试验类型					varchar
#define TBL_EGSHEAR_FLD_GCDMAM				"GCDMAM"			// 原状土抗剪强度			Float
#define TBL_EGSHEAR_FLD_GCDMAO				"GCDMAO"			// 重塑土抗剪强度			Float
#define TBL_EGSHEAR_FLD_GCBFOA				"GCBFOA"			// 粘聚力					Float
#define TBL_EGSHEAR_FLD_GCDKCS				"GCDKCS"			// 残余强度					Float
#define TBL_EGSHEAR_FLD_GCBFI				"GCBFI"				// 灵敏度					Float
#define TBL_EGSHEAR_FLD_GEOCODE  		    UNION_MACRO_GEOCODE		//地质代号					varchar
#define TBL_EGSHEAR_FLD_TCMC				UNION_MACRO_TCMC	// 土层名称					varchar
#define TBL_EGSHEAR_FLD__MEMO				UNION_MACRO_NOTE	// 备注					varchar
// from 原位测试基本情况表 * -- LH.2021.08.30 added.
#define TBL_EGSHEAR_FLD_TEST_EQUIPMODEL		"TestEquipModel"	// 试验设备及型号	Varchar		
#define TBL_EGSHEAR_FLD_TESTSTARTDATE		"TestStartDate"		// 试验开始日期		Date	
#define TBL_EGSHEAR_FLD_TESTENDDATE			"TestEndDate"		// 试验完成日期		Date	
#define TBL_EGSHEAR_FLD_TESTORGN			"TestOrgn"			// 试验单位			Varchar
#define TBL_EGSHEAR_FLD_OPERATOR			"_Operator"			// 操作人			Varchar
#define TBL_EGSHEAR_FLD_TECHNICIAN			"Technician"		// 现场技术员		Varchar	
#define TBL_EGSHEAR_FLD_INPUTER				"Inputer"			// 录入员			Varchar
#define TBL_EGSHEAR_FLD_INPUTORGN			"InputOrgn"			// 录入单位			Varchar
#define TBL_EGSHEAR_FLD_INPUTDATE			"InputDate"			// 录入日期			date

//波速测试记录表
#define TBL_WAVESPEED_TBL "EgWaveSpeed"
#define TBL_WAVESPEED_FLD_WAVESPEEDID		"WaveSpeedID"		//* 波速记录ID				int PK
#define TBL_WAVESPEED_FLD_TESTHORIZON		UNION_MACRO_TCDH		//* 试验层位					varchar
#define TBL_WAVESPEED_FLD_STARTDEPTH		UNION_MACRO_START_DEPTH			//* 起深度(m)				float
#define TBL_WAVESPEED_FLD_ENDDEPTH			UNION_MACRO_END_DEPTH			//* 止深度(m)				float		
#define TBL_WAVESPEED_FLD_PNTID				UNION_MACRO_PNT_ID				//* 点ID				int  FK
#define TBL_WAVESPEED_FLD_INSITUTESTNO		UNION_MACRO_TESTNO			// 试验编号				Varchar
#define TBL_WAVESPEED_FLD_TESTCATEGORY		UNION_MACRO_TESTTYPE		// 试验类型					varchar
#define TBL_WAVESPEED_FLD_TESTMETHOD		"TestMethod"		// 试验方法					varchar
#define TBL_WAVESPEED_FLD_SWVMAX			"SwvMax"			// 最大剪切波速(m/s)		float
#define TBL_WAVESPEED_FLD_SWVMIN			"SwvMin"			// 最小剪切波速(m/s)		float
#define TBL_WAVESPEED_FLD_SWVAVER			"SwvAver"			// 平均剪切波速(m/s)		float
#define TBL_WAVESPEED_FLD_GCEBHD			"GCEBHD"			// 压缩波速					float
#define TBL_WAVESPEED_FLD_ZBBS				"ZBBS"				//纵波波速					float
#define TBL_WAVESPEED_FLD_GCEBHF			"GCEBHF"			// 场地类别					varchar
#define TBL_WAVESPEED_FLD_GCEBHA			"GCEBHA"			// 波速试验类型				varchar
#define TBL_WAVESPEED_FLD_GEOCODE  		    UNION_MACRO_GEOCODE		//地质代号					varchar
#define TBL_WAVESPEED_FLD_TCMC				UNION_MACRO_TCMC	// 土层名称					varchar
#define TBL_WAVESPEED_FLD__MEMO				UNION_MACRO_NOTE	// 备注					varchar
// from 原位测试基本情况表 * -- LH.2021.08.30 added.
#define TBL_WAVESPEED_FLD_TEST_EQUIPMODEL	"TestEquipModel"	// 试验设备及型号	Varchar		
#define TBL_WAVESPEED_FLD_TESTSTARTDATE		"TestStartDate"		// 试验开始日期		Date	
#define TBL_WAVESPEED_FLD_TESTENDDATE		"TestEndDate"		// 试验完成日期		Date	
#define TBL_WAVESPEED_FLD_TESTORGN			"TestOrgn"			// 试验单位			Varchar
#define TBL_WAVESPEED_FLD_OPERATOR			"_Operator"			// 操作人			Varchar
#define TBL_WAVESPEED_FLD_TECHNICIAN		"Technician"		// 现场技术员		Varchar	
#define TBL_WAVESPEED_FLD_INPUTER			"Inputer"			// 录入员			Varchar
#define TBL_WAVESPEED_FLD_INPUTORGN			"InputOrgn"			// 录入单位			Varchar
#define TBL_WAVESPEED_FLD_INPUTDATE			"InputDate"			// 录入日期			date

//旁压实验成果表
#define TBL_PMT_TBL "EgPMT"
#define TBL_PMT_FLD_PMTID						"PMTID"						//* 旁压试验ID				int PK
#define TBL_PMT_FLD_TESTHORIZON					UNION_MACRO_TCDH			//* 试验层位					varchar
#define TBL_PMT_FLD_STARTDEPTH					UNION_MACRO_START_DEPTH		//* 起深度(m)				float
#define TBL_PMT_FLD_ENDDEPTH					UNION_MACRO_END_DEPTH		//* 止深度(m)				float	
#define TBL_PMT_FLD_PNTID						UNION_MACRO_PNT_ID			//* 点ID				int  FK
#define TBL_PMT_FLD_INSITUTESTNO				UNION_MACRO_TESTNO				// 试验编号				varchar
#define TBL_PMT_FLD_TESTCATEGORY				UNION_MACRO_TESTTYPE			// 试验类型					varchar
#define TBL_PMT_FLD_PRESSSTAGE					"PressStage"			// 加压级数					varchar
#define TBL_PMT_FLD_PRESSRAMPUP					"PressRampUp"			// 加压增量(kPa)			float
#define TBL_PMT_FLD_PIPEDIST					"PipeDist"				// 量管水面离孔口距离(m)	float
#define TBL_PMT_FLD_HYDROSTATICPRESS			"HydroStaticPress"		// 静水压力(kPa)			float
#define TBL_PMT_FLD_INITIALPRESS				"InitialPress"			// 初始压力(kPa)			float
#define TBL_PMT_FLD_ULTIMATEPRESS				"UltimatePress"			// 极限压力(kPa)			float
#define TBL_PMT_FLD_PLASTICPRESS				"PlasticPress"			// 临塑压力(kPa)			float
#define TBL_PMT_FLD_CHARACTVALUE				"CharactValue"			// 地基承载力特征值(kPa)	float
#define TBL_PMT_FLD_SIDEPRESSMODULE				"SidePressModule"		// 旁压模量(MPa)			float
#define TBL_PMT_FLD_GCDKBA						"GCDKBA"				// 变形模量(MPa)			float
#define TBL_PMT_FLD_SIDEPRESSDP					"SidePressDP"			// 旁压变形参数(MPa)		float
#define TBL_PMT_FLD_EARTHPRESSURE				"EarthPressure"			// 土压力(kPa)				float
#define TBL_PMT_FLD_SIDEPRESSHORIZONTAL			"SidePressHorizontal"	// 旁压水平侧压力(kPa)		float
#define TBL_PMT_FLD_GCEBBAULTIMATE				"GcebbaUltimate"		// 地基承载力(极限法)(kPa)	float
#define TBL_PMT_FLD_GCEBBAPLASTIC				"GcebbaPlastic"			// 地基承载力(临塑法)(kPa)	float
#define TBL_PMT_FLD_GCDKCR						"GCDKCR"				// 不排水抗剪强度(kPa)		float
#define TBL_PMT_FLD_SIDEPRESSCOEFFICE			"SidepressCoeffice"		// 侧压力系数				float
#define TBL_PMT_FLD_GCDLAK						"GCDLAK"				// 孔隙水压力(kPa)			float
#define TBL_PMT_FLD_GEOCODE  					UNION_MACRO_GEOCODE		//地质代号					varchar
#define TBL_PMT_FLD_TCMC						UNION_MACRO_TCMC		// 土层名称					varchar
#define TBL_PMT_FLD__MEMO						UNION_MACRO_NOTE		// 备注					varchar
// from 旁压观测记录表 -- LH.2021.08.30 added.
#define TBL_PMT_FLD_SWDDAH						"SWDDAH"				// 观测时间				date
#define TBL_PMT_FLD_GCEFAV						"GCEFAV"				// 序号					int
#define TBL_PMT_FLD_GCECHD						"GCECHD"				// 压力(kPa)				float
#define TBL_PMT_FLD_EXPANDVOLUME				"ExpandVolume"			// 扩张体积(cm3)			float
#define TBL_PMT_FLD_WATERLEVELVALUE				"WaterLevelValue"		// 量管水位值(cm)		float
#define TBL_PMT_FLD_WATERDROPVALUE				"WaterDropValue"		// 量管水位下降值(cm)		float
// from 原位测试基本情况表 * -- LH.2021.08.30 added.
#define TBL_PMT_FLD_TEST_EQUIPMODEL				"TestEquipModel"		// 试验设备及型号		Varchar		
#define TBL_PMT_FLD_TESTSTARTDATE				"TestStartDate"			// 试验开始日期		Date	
#define TBL_PMT_FLD_TESTENDDATE					"TestEndDate"			// 试验完成日期		Date	
#define TBL_PMT_FLD_TESTORGN					"TestOrgn"				// 试验单位			Varchar
#define TBL_PMT_FLD_OPERATOR					"_Operator"				// 操作人			Varchar
#define TBL_PMT_FLD_TECHNICIAN					"Technician"			// 现场技术员		Varchar	
#define TBL_PMT_FLD_INPUTER						"Inputer"				// 录入员			Varchar
#define TBL_PMT_FLD_INPUTORGN					"InputOrgn"				// 录入单位			Varchar
#define TBL_PMT_FLD_INPUTDATE					"InputDate"				// 录入日期			date

//载荷试验成果表
#define TBL_LOADTEST_TBL "EgLoadTest"
#define TBL_LOADTEST_FLD_LOADTESTID				"LoadTestID"				//* 载荷试验ID				int pk
#define TBL_LOADTEST_FLD_TESTHORIZON			UNION_MACRO_TCDH			//* 试验层位				varchar
#define TBL_LOADTEST_FLD_STARTDEPTH				UNION_MACRO_START_DEPTH		//* 起深度(m)				float
#define TBL_LOADTEST_FLD_ENDDEPTH				UNION_MACRO_END_DEPTH		//* 止深度(m)				float
#define TBL_LOADTEST_FLD_PNTID					UNION_MACRO_PNT_ID			//* 点ID					int  FK
#define TBL_LOADTEST_FLD_INSITUTESTNO			UNION_MACRO_TESTNO			// 试验编号					varchar
#define TBL_LOADTEST_FLD_TESTCATEGORY			UNION_MACRO_TESTTYPE		// 试验类型					varchar
#define TBL_LOADTEST_FLD_GCEBAM					"GCEBAM"					// 承压板形状				varchar
#define TBL_LOADTEST_FLD_GCEBAB					"GCEBAB"					// 承压板面积				float
#define TBL_LOADTEST_FLD_BOARDHEADDIAM			"BoardHeadDiam"				// 板头直径(m)				float
#define TBL_LOADTEST_FLD_SETTLEOBSERVEQUIP		"SettleObservEquip"			// 沉降观测仪器				varchar
#define TBL_LOADTEST_FLD_TESTBEDLITHOLOGY		"TestBedLithology"			// 试验层岩性				varchar
#define TBL_LOADTEST_FLD_LOADTESTTYPE			"LoadTestType"				// 载荷试验类型				varchar
#define TBL_LOADTEST_FLD_LOADEQUIPMODEL			"LoadEquipModel"			// 加荷设备及型号			varchar
#define TBL_LOADTEST_FLD_LOADMETHOD				"LoadMethod"				// 加荷方式					varchar
#define TBL_LOADTEST_FLD_STABILITYSTD			"StabilityStd"				// 稳定标准					varchar
#define TBL_LOADTEST_FLD_TESTDURATION			"TestDuration"				// 试验时长					varchar
#define TBL_LOADTEST_FLD_TESTLAYERPOISSON		"TestLayerPoisson"			// 试验层泊松比				float
#define TBL_LOADTEST_FLD_SWEGAB					"SWEGAB"					// 地下水位埋深(m)			float
#define TBL_LOADTEST_FLD_GCEBAF					"GCEBAF"					// 试验点界限应力(MPa)		float
#define TBL_LOADTEST_FLD_GCEBAG					"GCEBAG"					// 试验点极限应力(MPa)		float
#define TBL_LOADTEST_FLD_GCEBBA					"GCEBBA"					// 地基承载力(kPa)			float
#define TBL_LOADTEST_FLD_GCDKBA					"GCDKBA"					// 变形模量(MPa)			float
#define TBL_LOADTEST_FLD_GCDKCR					"GCDKCR"					// 不排水抗剪强度(kPa)		float
#define TBL_LOADTEST_FLD_GCDLBD					"GCDLBD"					// 固结系数					float
#define TBL_LOADTEST_FLD_ORIGCURVEINTERCEPT		"OrigCurveIntercept"		// 原始曲线截距				float
#define TBL_LOADTEST_FLD_ORIGCURVESLOPE			"OrigCurveSlope"			// 原始曲线斜率				float
#define TBL_LOADTEST_FLD_CORRECTCURVESLOPE		"CorrectCurveSlope"			// 修正曲线斜率				float
#define TBL_LOADTEST_FLD_YSKYZ					"YSKYZ"						// 岩石抗压道（MPa）				float
#define TBL_LOADTEST_FLD_GEOCODE  				UNION_MACRO_GEOCODE			//地质代号					varchar
#define TBL_LOADTEST_FLD_TCMC					UNION_MACRO_TCMC			// 土层名称					varchar
#define TBL_LOADTEST_FLD__MEMO					UNION_MACRO_NOTE			// 备注					varchar
// from 载荷试验样品试验数据表 -- LH.2021.08.30 added.
#define TBL_LOADTEST_FLD_GCEABB					"GCEABB"					// 样品编号						varchar
#define TBL_LOADTEST_FLD_SWBCF					"SWBCF"						// 样品类型						varchar
#define TBL_LOADTEST_FLD_MOISTURECONTENT		"MoistureContent"			// 天然含水量					float
#define TBL_LOADTEST_FLD_NATURALSEVERITY		"NaturalSeverity"			// 天然重度						float
#define TBL_LOADTEST_FLD_DHABCU					"DHABCU"					// 饱和度						float
#define TBL_LOADTEST_FLD_NATURALHOLERATIO		"NaturalHoleRatio"			// 天然孔隙比					float
#define TBL_LOADTEST_FLD_GCDDD					"GCDDD"						// 液限							float
#define TBL_LOADTEST_FLD_GCDDF					"GCDDF"						// 液性指数						float
#define TBL_LOADTEST_FLD_GCDDE					"GCDDE"						// 塑性指数						float
#define TBL_LOADTEST_FLD_GCDLAC					"GCDLAC"					// 压缩系数						float
#define TBL_LOADTEST_FLD_QDZS					"QDZS"						// 强度指数						float
// from 载荷试验观测记录表 -- LH.2021.08.30 added.
#define TBL_LOADTEST_FLD_SWDDAH					"SWDDAH"					// 观测时间					date
#define TBL_LOADTEST_FLD_GCECHD					"GCECHD"					// 压力(kPa)				float
#define TBL_LOADTEST_FLD_GCGFAI					"GCGFAI"					// 沉降量(mm)				float
#define TBL_LOADTEST_FLD_SETTLECHANGE			"SettleChange"				// 沉降变化量(mm)			float
#define TBL_LOADTEST_FLD_SETTLECORRECTVALUE		"SettleCorrectValue"		// 沉降校正值(mm)			float
#define TBL_LOADTEST_FLD_SETTLECORRECTNUM		"SettleCorrectNum"			// 校正后沉降量(mm)			float
// from 原位测试基本情况表 * -- LH.2021.08.30 added.
#define TBL_LOADTEST_FLD_TEST_EQUIPMODEL		"TestEquipModel"			// 试验设备及型号	Varchar		
#define TBL_LOADTEST_FLD_TESTSTARTDATE			"TestStartDate"				// 试验开始日期		Date	
#define TBL_LOADTEST_FLD_TESTENDDATE			"TestEndDate"				// 试验完成日期		Date
#define TBL_LOADTEST_FLD_TESTNUMBER				"TestNumber"				// 试验个数			int
#define TBL_LOADTEST_FLD_TESTORGN				"TestOrgn"					// 试验单位			Varchar
#define TBL_LOADTEST_FLD_OPERATOR				"_Operator"					// 操作人			Varchar
#define TBL_LOADTEST_FLD_TECHNICIAN				"Technician"				// 现场技术员		Varchar	
#define TBL_LOADTEST_FLD_INPUTER				"Inputer"					// 录入员			Varchar
#define TBL_LOADTEST_FLD_INPUTORGN				"InputOrgn"					// 录入单位			Varchar
#define TBL_LOADTEST_FLD_INPUTDATE				"InputDate"					// 录入日期			date

/*-----------------------------------现场水理物理实验类-------------------------------*/
#define EGPUMPING_MDL_CLASS "现场水理物理实验表类"
	//抽水试验成果表
#define TBL_EGPUMPINGTEST_TBL "HYPumpExp"
#define TBL_EGPUMPINGTEST_FLD_PUMPTESTID			"PumpTestID"		//* 抽水试验ID					int
#define TBL_EGPUMPINGTEST_FLD_SWDAE					"SWDAE"				// 抽水试验编号					Varchar
#define TBL_EGPUMPINGTEST_FLD_TESTCATEGORY			"TestCategory"		// 试验类型						varchar
#define TBL_EGPUMPINGTEST_FLD_LANDNUM				"LandNum"			// 落程数量						varchar
#define TBL_EGPUMPINGTEST_FLD_PUMPHOLENUM			"PumpHoleNum"		// 抽水孔数量					int
#define TBL_EGPUMPINGTEST_FLD_OBHOLENUM				"ObHoleNum"			// 观测孔数量					int
#define TBL_EGPUMPINGTEST_FLD_SWDDAA				"SWDDAA"			// 试验开始时间					date
#define TBL_EGPUMPINGTEST_FLD_PUMPENDTIME			"PumpEndTime"		// 抽水结束时间					date
#define TBL_EGPUMPINGTEST_FLD_SWDDAB				"SWDDAB"			// 试验结束时间					date
#define TBL_EGPUMPINGTEST_FLD_STABLEDURATION		"StableDuration"	// 水位稳定延续时间(min)		varchar
#define TBL_EGPUMPINGTEST_FLD_PUMPEQUIPMODEL		"PumpEquipModel"	// 抽水设备及型号				varchar
#define TBL_EGPUMPINGTEST_FLD_WATERLEVELOBINST		"WaterLevelObInst"	// 水位观测仪器					varchar
#define TBL_EGPUMPINGTEST_FLD_WATERVOLUMEOBINST		"WaterVolumeObInst"	// 水量观测仪器					varchar
#define TBL_EGPUMPINGTEST_FLD_WATERTEMPOBINST		"WaterTempObInst"	// 水温观测仪器					varchar
#define TBL_EGPUMPINGTEST_FLD_TESTHORIZON			"TestHorizon"		// 试验层位						varchar
#define TBL_EGPUMPINGTEST_FLD_AQUIFERLITHOLOGY		"AquiferLithology"	// 试验含水层岩性				varchar
#define TBL_EGPUMPINGTEST_FLD_SWDDBY				"SWDDBY"			// 最大涌水量(m3/d)				float
#define TBL_EGPUMPINGTEST_FLD_DRAWDOWNMAX			"DrawDownMax"		// 最大降深(m)					float
#define TBL_EGPUMPINGTEST_FLD_MAXINFLURADIUS		"MaxInfluRadius"	// 最大影响半径(m)				float
#define TBL_EGPUMPINGTEST_FLD_CALCULDRAWDOWN		"CalculDrawDown"	// 推算降深(m)					float
#define TBL_EGPUMPINGTEST_FLD__DIAMETER				"_Diameter"			// 统一换算管径(mm)				float
#define TBL_EGPUMPINGTEST_FLD_ESWATERINFLOW			"EsWaterInflow"		// 推算涌水量(m3/d)				float
#define TBL_EGPUMPINGTEST_FLD_ESINFLURADIUS			"EsInfluRadius"		// 推算影响半径(m)				float
#define TBL_EGPUMPINGTEST_FLD_SWGGAA				"SWGGAA"			// 平均渗透系数(m/d)			float
#define TBL_EGPUMPINGTEST_FLD_SWGGAO				"SWGGAO"			// 平均导水系数(m2/d)			float
#define TBL_EGPUMPINGTEST_FLD_SWGGAL				"SWGGAL"			// 平均储水系数					float
#define TBL_EGPUMPINGTEST_FLD_SWAEFG				"SWAEFG"			// 平均给水度					float
#define TBL_EGPUMPINGTEST_FLD_SWGGBE				"SWGGBE"			// 平均越流系数					float
#define TBL_EGPUMPINGTEST_FLD_PLANEPOSMAP			"PlanePosMap"		// 平面位置示意图				varchar
#define TBL_EGPUMPINGTEST_FLD_PROFILEMAP			"ProfileMap"		// 剖面示意图					varchar
#define TBL_EGPUMPINGTEST_FLD_FIELDIMAGE			"FieldImage"		// 野外照片(视频)				varchar
#define TBL_EGPUMPINGTEST_FLD_RECORDCARD			"RecordCard"		// 记录卡片(记录)				varchar
#define TBL_EGPUMPINGTEST_FLD_TESTORGN				"TestOrgn"			// 试验单位						varchar
#define TBL_EGPUMPINGTEST_FLD_JJDAC					"JJDAC"				// 记录人						varchar
#define TBL_EGPUMPINGTEST_FLD__OBSERVER				"_Observer"			// 观测人						varchar
#define TBL_EGPUMPINGTEST_FLD_INPUTER				"Inputer"			// 录入员						varchar
#define TBL_EGPUMPINGTEST_FLD_INPUTORGN				"InputOrgn"			// 录入单位 					varchar
#define TBL_EGPUMPINGTEST_FLD_INPUTDATE				"InputDate"			// 录入日期						date
#define TBL_EGPUMPINGTEST_FLD_MEMO					"_Memo"				// 备注							varchar

//抽水试验段信息表
#define TBL_HYPUMPEXPSEC_TBL "HYPumpExpSec"
#define TBL_HYPUMPEXPSEC_FLD_SECTIONID			"SectionID"			//* 试验段ID						int
#define TBL_HYPUMPEXPSEC_FLD_TESTSECTNUM		"TestSectNum"		// 试验段编号					Varchar
#define TBL_HYPUMPEXPSEC_FLD_SWDAE				"SWDAE"				// 试验编号						Varchar
#define TBL_HYPUMPEXPSEC_FLD_FILTERTOPDEPTH		"FilterTopDepth"	// 试验段滤管顶深度(m)			float
#define TBL_HYPUMPEXPSEC_FLD_FILTERBOTTOMDEPTH	"FilterBottomDepth"	// 试验段滤管底深度(m)			float
#define TBL_HYPUMPEXPSEC_FLD_FILTERDIAM			"FilterDiam"		// 试验段滤管外径(mm)			float
#define TBL_HYPUMPEXPSEC_FLD_WATERYTOPDEPTH		"WateryTopDepth"	// 试验段含水层顶深度(m)		float
#define TBL_HYPUMPEXPSEC_FLD_WATERYBOTTOMDEPTH	"WateryBottomDepth"	// 试验段含水层底深度(m)		float
#define TBL_HYPUMPEXPSEC_FLD_WATERYTHICKNESS	"WateryThickness"	// 试验段含水层厚度(m)			float
#define TBL_HYPUMPEXPSEC_FLD_SECTHORIZON		"SectHorizon"		// 试验段层位					varchar
#define TBL_HYPUMPEXPSEC_FLD_WATERYLITHOLOGY	"WateryLithology"	// 试验段含水层岩性				varchar
//from 抽水试验钻孔信息表
#define TBL_HYPUMPEXPSEC_FLD_PNTID				UNION_MACRO_PNT_ID	//* 点ID							int
#define TBL_HYPUMPEXPSEC_FLD_PUMPTESTHOLENO		"PumpTestHoleNo"	// 抽水试验孔号					Varchar
#define TBL_HYPUMPEXPSEC_FLD_TESTHOLETYPE		"TestHoleType"		// 试验孔类型					Varchar
#define TBL_HYPUMPEXPSEC_FLD_PUMPHOLEDIST		"PumpHoleDist"		// 与抽水孔距离(m)				Float
#define TBL_HYPUMPEXPSEC_FLD_BEFOREPUMPDEPTH	"BeforePumpDepth"	// 抽水前静水位埋深(m)			Float
#define TBL_HYPUMPEXPSEC_FLD_AFTERPUMPDEPTH		"AfterPumpDepth"	// 抽水后静水位埋深(m)			Float
#define TBL_HYPUMPEXPSEC_FLD_SECTNUM			"SectNum"			// 试验段数量					int
#define TBL_HYPUMPEXPSEC_FLD_AITSTOTALTHICK		"AitsTotalThick"	// 试验段含水层总厚度(m)		float
#define TBL_HYPUMPEXPSEC_FLD_SECTIONDIAM		"SectionDiam"		// 过水断面等效外径(mm)			float


//抽水实验落程数据表
#define TBL_HYPUMPEXPDROPOFF_TBL "HYPumpDropOff"
#define TBL_HYPUMPEXPFROPOFF_FLD_DROPOFFID			"DropOffID"			//* 落程ID				int
#define TBL_HYPUMPEXPFROPOFF_FLD_SWDDBG				"SWDDBG"			// 落程编号				varchar
#define TBL_HYPUMPEXPFROPOFF_FLD_SWDAE				"SWDAE"				// 试验编号				varchar
#define TBL_HYPUMPEXPFROPOFF_FLD_STARTTIME			"StartTime"			// 落程开始时间			date
#define TBL_HYPUMPEXPFROPOFF_FLD_ENDTIME			"EndTime"			// 落程结束时间			date
#define TBL_HYPUMPEXPFROPOFF_FLD_SUSTAINTIME		"SustainTime"		// 落程延续时间			varchar
#define TBL_HYPUMPEXPFROPOFF_FLD_STABLESTARTTIME	"StableStartTime"	// 水位稳定起始时间		date
#define TBL_HYPUMPEXPFROPOFF_FLD_STABLETIME			"StableTime"		// 水位稳定时长(分钟)	varchar
#define TBL_HYPUMPEXPFROPOFF_FLD_WATERDROPDEPTH		"WaterDropDepth"	// 稳定水位降深(m)		float
#define TBL_HYPUMPEXPFROPOFF_FLD_STABLEINFLOW		"StableInflow"		// 稳定涌水量(m3/d)		float
#define TBL_HYPUMPEXPFROPOFF_FLD_SWGGAA				"SWGGAA"			// 渗透系数				float
#define TBL_HYPUMPEXPFROPOFF_FLD_INFLURADIUS		"InfluRadius"		// 影响半径				float
#define TBL_HYPUMPEXPFROPOFF_FLD_HYDRACOEFFIC		"HydraCoeffic"		// 导水系数				float
#define TBL_HYPUMPEXPFROPOFF_FLD_STORECOEFFIC		"StoreCoeffic"		// 储水系数				float
#define TBL_HYPUMPEXPFROPOFF_FLD_WATERSUPPLY		"WaterSupply"		// 给水度				float
#define TBL_HYPUMPEXPFROPOFF_FLD_LEAPFROGCOEFFIC	"LeapfrogCoeffic"	// 越流系数				float
//from 抽水试验钻孔信息表
#define TBL_HYPUMPEXPFROPOFF_FLD_PNTID				UNION_MACRO_PNT_ID		//* 点ID							int
#define TBL_HYPUMPEXPFROPOFF_FLD_PUMPTESTHOLENO		"PumpTestHoleNo"		// 抽水试验孔号					Varchar
#define TBL_HYPUMPEXPFROPOFF_FLD_TESTHOLETYPE		"TestHoleType"		// 试验孔类型					Varchar
#define TBL_HYPUMPEXPFROPOFF_FLD_PUMPHOLEDIST		"PumpHoleDist"		// 与抽水孔距离(m)				Float
#define TBL_HYPUMPEXPFROPOFF_FLD_BEFOREPUMPDEPTH	"BeforePumpDepth"	// 抽水前静水位埋深(m)			Float
#define TBL_HYPUMPEXPFROPOFF_FLD_AFTERPUMPDEPTH		"AfterPumpDepth"		// 抽水后静水位埋深(m)			Float
#define TBL_HYPUMPEXPFROPOFF_FLD_SECTNUM			"SectNum"			// 试验段数量					int
#define TBL_HYPUMPEXPFROPOFF_FLD_AITSTOTALTHICK		"AitsTotalThick"		// 试验段含水层总厚度(m)		float
#define TBL_HYPUMPEXPFROPOFF_FLD_SECTIONDIAM		"SectionDiam"		// 过水断面等效外径(mm)			float

//抽水水位观测记录表
#define TBL_HYPUMPLEVELOB_TBL "HYPumpLevelOb"
#define TBL_HYPUMPLEVELOB_FLD_DYWATERLEVELID	"DyWaterLevelID"	//* 动水位ID				int
#define TBL_HYPUMPLEVELOB_FLD_DROPOFFID			"DropOffID"			// 落程ID				int
#define TBL_HYPUMPLEVELOB_FLD_SWDDBG			"SWDDBG"			// 落程编号				varchar
#define TBL_HYPUMPLEVELOB_FLD_SWDAE				"SWDAE"				// 试验编号				varchar
#define TBL_HYPUMPLEVELOB_FLD_SWDDAH			"SWDDAH"			// 观测时间				date
#define TBL_HYPUMPLEVELOB_FLD_PUMPDURATION		"PumpDuration"		// 抽水延续时间(min)	varchar
#define TBL_HYPUMPLEVELOB_FLD_SWEGAB			"SWEGAB"			// 水位埋深(m)			float
#define TBL_HYPUMPLEVELOB_FLD_SWDDBH			"SWDDBH"			// 水位降深(m)			float
#define TBL_HYPUMPLEVELOB_FLD_WATERINFLOWM		"WaterInFlowM"		// 涌水量(m3/d)			float
#define TBL_HYPUMPLEVELOB_FLD_WATERINFLOWL		"WaterInFlowL"		// 涌水量(L/s)			float
#define TBL_HYPUMPLEVELOB_FLD_SWADET			"SWADET"			// 水温(℃)				float
#define TBL_HYPUMPLEVELOB_FLD_SWADBB			"SWADBB"			// 气温(℃)				float
#define TBL_HYPUMPLEVELOB_FLD_IS_STABLE			"Is_Stable"			// 是否稳定				bool
#define TBL_HYPUMPLEVELOB_FLD_MEMO				"_Memo"				// 备注					varchar
//from 抽水试验钻孔信息表
#define TBL_HYPUMPLEVELOB_FLD_PNTID				UNION_MACRO_PNT_ID		//* 点ID							int
#define TBL_HYPUMPLEVELOB_FLD_PUMPTESTHOLENO	"PumpTestHoleNo"		// 抽水试验孔号					Varchar
#define TBL_HYPUMPLEVELOB_FLD_TESTHOLETYPE		"TestHoleType"		// 试验孔类型					Varchar
#define TBL_HYPUMPLEVELOB_FLD_PUMPHOLEDIST		"PumpHoleDist"		// 与抽水孔距离(m)				Float
#define TBL_HYPUMPLEVELOB_FLD_BEFOREPUMPDEPTH	"BeforePumpDepth"	// 抽水前静水位埋深(m)			Float
#define TBL_HYPUMPLEVELOB_FLD_AFTERPUMPDEPTH	"AfterPumpDepth"		// 抽水后静水位埋深(m)			Float
#define TBL_HYPUMPLEVELOB_FLD_SECTNUM			"SectNum"			// 试验段数量					int
#define TBL_HYPUMPLEVELOB_FLD_AITSTOTALTHICK	"AitsTotalThick"		// 试验段含水层总厚度(m)		float
#define TBL_HYPUMPLEVELOB_FLD_SECTIONDIAM		"SectionDiam"		// 过水断面等效外径(mm)			float

//静水位观测记录表
#define TBL_HYSTATICWATERLEVEL_TBL "HYStaticWaterLevel"
#define TBL_HYSTATICWATERLEVEL_FLD_STAWATERLEVELID	"StaWaterLevelID"	//* 静水位ID				int
#define TBL_HYSTATICWATERLEVEL_FLD_SWDAE			"SWDAE"				// 试验编号				varchar
#define TBL_HYSTATICWATERLEVEL_FLD_SWDDAH			"SWDDAH"			// 观测时间				date
#define TBL_HYSTATICWATERLEVEL_FLD_SWDDAI			"SWDDAI"			// 延续时间(min)		varchar
#define TBL_HYSTATICWATERLEVEL_FLD_SWEGAB			"SWEGAB"			// 水位埋深(m)			float
#define TBL_HYSTATICWATERLEVEL_FLD_SWADET			"SWADET"			// 水温(℃)				float
#define TBL_HYSTATICWATERLEVEL_FLD_SWADBB			"SWADBB"			// 气温(℃)				float
#define TBL_HYSTATICWATERLEVEL_FLD_IS_STABLE		"Is_Stable"			// 是否稳定				bool
#define TBL_HYSTATICWATERLEVEL_FLD_MEMO				"_Memo"				// 备注					varchar
//from 抽水试验钻孔信息表
#define TBL_HYSTATICWATERLEVEL_FLD_PNTID			UNION_MACRO_PNT_ID		//* 点ID							int
#define TBL_HYSTATICWATERLEVEL_FLD_PUMPTESTHOLENO	"PumpTestHoleNo"		// 抽水试验孔号					Varchar
#define TBL_HYSTATICWATERLEVEL_FLD_TESTHOLETYPE		"TestHoleType"			// 试验孔类型					Varchar
#define TBL_HYSTATICWATERLEVEL_FLD_PUMPHOLEDIST		"PumpHoleDist"			// 与抽水孔距离(m)				Float
#define TBL_HYSTATICWATERLEVEL_FLD_BEFOREPUMPDEPTH	"BeforePumpDepth"		// 抽水前静水位埋深(m)			Float
#define TBL_HYSTATICWATERLEVEL_FLD_AFTERPUMPDEPTH	"AfterPumpDepth"		// 抽水后静水位埋深(m)			Float
#define TBL_HYSTATICWATERLEVEL_FLD_SECTNUM			"SectNum"				// 试验段数量					int
#define TBL_HYSTATICWATERLEVEL_FLD_AITSTOTALTHICK	"AitsTotalThick"		// 试验段含水层总厚度(m)		float
#define TBL_HYSTATICWATERLEVEL_FLD_SECTIONDIAM		"SectionDiam"			// 过水断面等效外径(mm)			float

//恢复水位观测记录表
#define TBL_HYREVIEWATERLEVEL_TBL "HYRevieWaterLevel"
#define TBL_HYREVIEWATERLEVEL_FLD_REWATERLEVELID	"ReWaterLevelID"	//* 恢复水位ID				int
#define TBL_HYREVIEWATERLEVEL_FLD_SWDAE				"SWDAE"				// 试验编号					varchar
#define TBL_HYREVIEWATERLEVEL_FLD_SWDDBG			"SWDDBG"			// 落程编号					varchar
#define TBL_HYREVIEWATERLEVEL_FLD_SWDDAH			"SWDDAH"			// 观测时间					date
#define TBL_HYREVIEWATERLEVEL_FLD_RECOVERYDURATION	"RecoveryDuration"	// 恢复延续时间(min)		varchar
#define TBL_HYREVIEWATERLEVEL_FLD_SWEGAB			"SWEGAB"			// 水位埋深(m)				float
#define TBL_HYREVIEWATERLEVEL_FLD_SWDDBH			"SWDDBH"			// 水位降深(m)				float
#define TBL_HYREVIEWATERLEVEL_FLD_SWADET			"SWADET"			// 水温(℃)					float
#define TBL_HYREVIEWATERLEVEL_FLD_SWADBB			"SWADBB"			// 气温(℃)					float
#define TBL_HYREVIEWATERLEVEL_FLD_IS_STABLE			"Is_Stable"			// 是否稳定					bool
#define TBL_HYREVIEWATERLEVEL_FLD__MEMO				"_Memo"				// 备注						varchar
//from 抽水试验钻孔信息表
#define TBL_HYREVIEWATERLEVEL_FLD_PNTID				UNION_MACRO_PNT_ID		//* 点ID							int
#define TBL_HYREVIEWATERLEVEL_FLD_PUMPTESTHOLENO	"PumpTestHoleNo"		// 抽水试验孔号					Varchar
#define TBL_HYREVIEWATERLEVEL_FLD_TESTHOLETYPE		"TestHoleType"			// 试验孔类型					Varchar
#define TBL_HYREVIEWATERLEVEL_FLD_PUMPHOLEDIST		"PumpHoleDist"			// 与抽水孔距离(m)				Float
#define TBL_HYREVIEWATERLEVEL_FLD_BEFOREPUMPDEPTH	"BeforePumpDepth"		// 抽水前静水位埋深(m)			Float
#define TBL_HYREVIEWATERLEVEL_FLD_AFTERPUMPDEPTH	"AfterPumpDepth"		// 抽水后静水位埋深(m)			Float
#define TBL_HYREVIEWATERLEVEL_FLD_SECTNUM			"SectNum"				// 试验段数量					int
#define TBL_HYREVIEWATERLEVEL_FLD_AITSTOTALTHICK	"AitsTotalThick"		// 试验段含水层总厚度(m)		float
#define TBL_HYREVIEWATERLEVEL_FLD_SECTIONDIAM		"SectionDiam"			// 过水断面等效外径(mm)			float


//注水试验观测记录表
#define TBL_HYWATERINJECTOB_TBL "HYWaterInjectOb"
#define TBL_HYWATERINJECTOB_FLD_WATERINJECTLEVELID	"WaterInjectLevelID"		//* 注水水位ID				int
#define TBL_HYWATERINJECTOB_FLD_PRJID				UNION_MACRO_PRJID						// 项目ID				int
#define TBL_HYWATERINJECTOB_FLD_PKIAA				UNION_MACRO_PRJCODE					// 项目编号			varchar
#define TBL_HYWATERINJECTOB_FLD_SWDDAH				"SWDDAH"					// 观测时间					date
#define TBL_HYWATERINJECTOB_FLD_SWDDAI				"SWDDAI"					// 延续时间(分钟)			varchar
#define TBL_HYWATERINJECTOB_FLD_SWEGAB				"SWEGAB"					// 水位埋深(m)				float
#define TBL_HYWATERINJECTOB_FLD_WATERHEADVALUE		"WaterHeadValue"			// 水头值(m)				float
#define TBL_HYWATERINJECTOB_FLD_WATERINJECTVOLUME	"WaterInjectVolume"			// 注水量(L)				float
#define TBL_HYWATERINJECTOB_FLD_INJECTIONFLOW		"InjectionFlow"				// 注入流量(L/min)			float
#define TBL_HYWATERINJECTOB_FLD_IS_STABLE			"Is_Stable"					// 是否稳定					bool
//from 注水试验成果表
#define TBL_HYWATERINJECTOB_FLD_WATERINJECTNO		"WaterInjectNO"			// 注水试验编号					varchar
#define TBL_HYWATERINJECTOB_FLD_PNTID				UNION_MACRO_PNT_ID		//* 点ID							int
#define TBL_HYWATERINJECTOB_FLD_TNO					"WaterInjectHoleNo"		// 注水试验孔号					varchar
#define TBL_HYWATERINJECTOB_FLD_TESTMETHOD			"TestMethod"			// 试验方法						varchar
#define TBL_HYWATERINJECTOB_FLD_WATERVOLUMEOBINST	"WaterVolumeObInst"		// 水量观测仪器					varchar
#define TBL_HYWATERINJECTOB_FLD_WaterLevelObInst	"WaterLevelObInst"		// 水位观测仪器					varchar
#define TBL_HYWATERINJECTOB_FLD_STARTTIME			"SWDDAA"				// 试验开始时间					date
#define TBL_HYWATERINJECTOB_FLD_ENDTIME				"SWDDAB"				// 试验结束时间					date
#define TBL_HYWATERINJECTOB_FLD_FLOWSTABLETIME		"FlowStableTime"		// 流量稳定时间					date
#define TBL_HYWATERINJECTOB_FLD_SWDACD				"SWDACD"				// 试验段起始深度(m)			float
#define TBL_HYWATERINJECTOB_FLD_SWDACE				"SWDACE"				// 试验段终止深度(m)			float
#define TBL_HYWATERINJECTOB_FLD_TESTL				"SectionLength"			// 试验段长度(m)				float
#define TBL_HYWATERINJECTOB_FLD_INNERDIAMETER		"Innerdiameter"			// 套管内径(mm)					float
#define TBL_HYWATERINJECTOB_FLD_BURYDEPTH_BEFORE	"BuryDepth_Before"		// 注水前静水位埋深(m)			float
#define TBL_HYWATERINJECTOB_FLD_BURYDEPTH_AFTER		"BuryDepth_After"		// 注水后静水位埋深(m)			float
#define TBL_HYWATERINJECTOB_FLD_SWGGAA				"SWGGAA"				// 渗透系数(m/d)				float
#define TBL_HYWATERINJECTOB_FLD_HYCONDUCTIVITY		"HyConductivity"		// 导水系数(m2/d)				float
#define TBL_HYWATERINJECTOB_FLD_PLANEPOSMAP			"PlanePosMap"			// 平面位置示意图				varchar
#define TBL_HYWATERINJECTOB_FLD_PROFILEMAP			"ProfileMap"			// 剖面示意图					varchar
#define TBL_HYWATERINJECTOB_FLD_FIELDIMAGE			"FieldImage"			// 野外照片(视频)				varchar
#define TBL_HYWATERINJECTOB_FLD_RECORDCARD			"RecordCard"			// 记录卡片(记录)				varchar
#define TBL_HYWATERINJECTOB_FLD_TESTORGN			"TestOrgn"				// 试验单位						varchar
#define TBL_HYWATERINJECTOB_FLD_JJDAC				"JJDAC"					// 记录人						varchar
#define TBL_HYWATERINJECTOB_FLD__OBSERVER			"_Observer"				// 观测人						varchar
#define TBL_HYWATERINJECTOB_FLD_INPUTER				"Inputer"				// 录入员						varchar
#define TBL_HYWATERINJECTOB_FLD_INPUTORGN			"InputOrgn"				// 录入单位 					varchar
#define TBL_HYWATERINJECTOB_FLD_INPUTDATE			"InputDate"				// 录入日期						date
#define TBL_HYWATERINJECTOB_FLD__MEMO				"_Memo"					// 备注							varchar


//回灌实验成果表
#define TBL_HYRECHARGEEXP_TBL "HYRechargeExp"
#define TBL_HYRECHARGEEXP_FLD_RECHARGEEXPID		"RechargeExpID"				//* 回灌试验ID			int
#define TBL_HYRECHARGEEXP_FLD_PNTID				UNION_MACRO_PNT_ID			//* 点ID			int
#define TBL_HYRECHARGEEXP_FLD_RECHARGEEXPNO		"RechargeExpNo"				// 回灌试验编号			varchar
#define TBL_HYRECHARGEEXP_FLD_PRJID				UNION_MACRO_PRJID			// 项目ID				int
#define TBL_HYRECHARGEEXP_FLD_PKIAA				UNION_MACRO_PRJCODE			// 项目编号			varchar
#define TBL_HYRECHARGEEXP_FLD_TESTCATEGORY		"TestCategory"				// 试验类型				varchar
#define TBL_HYRECHARGEEXP_FLD_LIFTNUM			"LiftNum"					// 升程数量				int
#define TBL_HYRECHARGEEXP_FLD_REFILLHOLENUM		"RefillHoleNum"				// 回灌孔数量			int
#define TBL_HYRECHARGEEXP_FLD_OBHOLENUM			"ObHoleNum"					// 观测孔数量			int
#define TBL_HYRECHARGEEXP_FLD_SWDDAA			"SWDDAA"					// 试验开始时间			date
#define TBL_HYRECHARGEEXP_FLD_ENDTIME			"EndTime"					// 回灌结束时间			date
#define TBL_HYRECHARGEEXP_FLD_SWDDAB			"SWDDAB"					// 试验结束时间			date
#define TBL_HYRECHARGEEXP_FLD_STABLEDURATION	"StableDuration"			// 水位稳定延续时间(min) varchar
#define TBL_HYRECHARGEEXP_FLD_WATERLEVELOBINST	"WaterLevelObInst"			// 水位观测仪器			varchar
#define TBL_HYRECHARGEEXP_FLD_WATERVOLUMEOBINST	"WaterVolumeObInst"			// 水量观测仪器			varchar
#define TBL_HYRECHARGEEXP_FLD_WATERTEMPOBINST	"WaterTempObInst"			// 水温观测仪器			varchar
#define TBL_HYRECHARGEEXP_FLD_TESTHORIZON		"TestHorizon"				// 试验层位				varchar
#define TBL_HYRECHARGEEXP_FLD_TESTBEDLITHOLOGY	"TestBedLithology"			// 试验层岩性			varchar
#define TBL_HYRECHARGEEXP_FLD_MAXVOLUME			"MaxVolume"					// 最大回灌量(m3/d)		float
#define TBL_HYRECHARGEEXP_FLD_MARISE			"MaRise"					// 最大水位升幅(m)		float
#define TBL_HYRECHARGEEXP_FLD_MAXINFLURADIUS	"MaxInfluRadius"			// 最大影响半径(m)		float
#define TBL_HYRECHARGEEXP_FLD_SWGGAA			"SWGGAA"					// 平均渗透系数(m/d)	float
#define TBL_HYRECHARGEEXP_FLD_SWGGAO			"SWGGAO"					// 平均导水系数(m2/d)	float
#define TBL_HYRECHARGEEXP_FLD_SWGGAL			"SWGGAL"					// 平均储水系数			float
#define TBL_HYRECHARGEEXP_FLD_SWAEFG			"SWAEFG"					// 平均给水度			float
#define TBL_HYRECHARGEEXP_FLD_SWGGBE			"SWGGBE"					// 平均越流系数			float
#define TBL_HYRECHARGEEXP_FLD_AVGRECHARGERATE	"AvgRechargeRate"			// 平均回灌率			float
#define TBL_HYRECHARGEEXP_FLD_PLANEPOSMAP		"PlanePosMap"				// 平面位置示意图		varchar
#define TBL_HYRECHARGEEXP_FLD_PROFILEMAP		"ProfileMap"				// 剖面示意图			varchar
#define TBL_HYRECHARGEEXP_FLD_FIELDIMAGE		"FieldImage"				// 野外照片(视频)		varchar
#define TBL_HYRECHARGEEXP_FLD_RECORDCARD		"RecordCard"				// 记录卡片(记录)		varchar
#define TBL_HYRECHARGEEXP_FLD_TESTORGN			"TestOrgn"					// 试验单位				varchar
#define TBL_HYRECHARGEEXP_FLD_JJDAC				"JJDAC"						// 记录人				varchar
#define TBL_HYRECHARGEEXP_FLD_OBSERVER			"_Observer"					// 观测人				varchar
#define TBL_HYRECHARGEEXP_FLD_INPUTER			"Inputer"					// 录入员				varchar
#define TBL_HYRECHARGEEXP_FLD_INPUTORGN			"InputOrgn"					// 录入单位				varchar
#define TBL_HYRECHARGEEXP_FLD_INPUTDATE			"InputDate"					// 录入日期				date
#define TBL_HYRECHARGEEXP_FLD_MEMO				"_Memo"						// 备注					varchar

//回灌试验段信息表
#define TBL_HYRECHARGEEXPSECT_TBL "HYRechargeExpSect"
#define TBL_HYRECHARGEEXPSECT_FLD_SECTIONID				"SectionID"					//* 试验段ID						int
#define TBL_HYRECHARGEEXPSECT_FLD_TESTSECTNUM			"TestSectNum"				// 试验段编号					varchar
#define TBL_HYRECHARGEEXPSECT_FLD_FILTERTOPDEPTH		"FilterTopDepth"			// 试验段滤管顶深度(m)			float
#define TBL_HYRECHARGEEXPSECT_FLD_FILTERBOTTOMDEPTH		"FilterBottomDepth"			// 试验段滤管底深度(m)			float
#define TBL_HYRECHARGEEXPSECT_FLD_FILTERDIAM			"FilterDiam"				// 试验段滤管外径(mm)			float
#define TBL_HYRECHARGEEXPSECT_FLD_WATERYTOPDEPTH		"WateryTopDepth"			// 试验段含水层顶深度(m)		float
#define TBL_HYRECHARGEEXPSECT_FLD_WATERYBOTTOMDEPTH		"WateryBottomDepth"			// 试验段含水层底深度(m)		float
#define TBL_HYRECHARGEEXPSECT_FLD_WATERYTHICKNESS		"WateryThickness"			// 试验段含水层厚度(m)			float
#define TBL_HYRECHARGEEXPSECT_FLD_SECTHORIZON			"SectHorizon"				// 试验段层位					varchar
#define TBL_HYRECHARGEEXPSECT_FLD_WATERYLITHOLOGY		"WateryLithology"			// 试验段含水层岩性				varchar
//from 回灌实验钻孔信息表
#define TBL_HYRECHARGEEXPSECT_FLD_RECHARGEEXPNO			"RechargeExpNo"				// 回灌试验编号			varchar
#define TBL_HYRECHARGEEXPSECT_FLD_PNTID					UNION_MACRO_PNT_ID			//* 点ID					int
#define TBL_HYRECHARGEEXPSECT_FLD_RECHARGEEXPHOLENO		"RechargeExpHoleNo"			// 回灌试验孔号			varchar
#define TBL_HYRECHARGEEXPSECT_FLD_TESTHOLETYPE			"TestHoleType"				// 试验孔类型			varchar
#define TBL_HYRECHARGEEXPSECT_FLD_RECHARGEHOLEDIST		"RechargeHoleDist"			// 与回灌孔距离(m)		float
#define TBL_HYRECHARGEEXPSECT_FLD_BURYDEPTH_BEFORE		"BuryDepth_Before"			// 回灌前静水位埋深(m)	float
#define TBL_HYRECHARGEEXPSECT_FLD_BURYDEPTH_AFTER		"BuryDepth_After"			// 回灌后静水位埋深(m)	float
#define TBL_HYRECHARGEEXPSECT_FLD_SECTNUM				"SectNum"					// 试验段数量			int
#define TBL_HYRECHARGEEXPSECT_FLD_TOTALTHICKNESS		"TotalThickness"			// 试验段含水层总厚度(m) float
#define TBL_HYRECHARGEEXPSECT_FLD_EODOWPSECTION			"EodowpSection"				// 过水断面等效外径(mm)	 float

//回灌试验升程数据表
#define TBL_HYRECHARGEEXPLIFT_TBL "HYRechargeExpLift"
#define TBL_HYRECHARGEEXPLIFT_FLD_LIFTID				"LiftID"						//* 升程ID						int
#define TBL_HYRECHARGEEXPLIFT_FLD_LIFTNO				"LiftNo"						// 升程编号						varchar
#define TBL_HYRECHARGEEXPLIFT_FLD_STARTTIME				"StartTime"						// 升程开始时间					date
#define TBL_HYRECHARGEEXPLIFT_FLD_ENDTIME				"Endtime"						// 升程结束时间					date
#define TBL_HYRECHARGEEXPLIFT_FLD_STABLESTARTTIME		"StableStartTime"				// 水位稳定起始时间				date
#define TBL_HYRECHARGEEXPLIFT_FLD_STABLETIME			"StableTime"					// 水位稳定时长(分钟)			varchar
#define TBL_HYRECHARGEEXPLIFT_FLD_STAWATERLEVELRISE		"StaWaterLevelrise"				// 稳定水位回升(m)				float
#define TBL_HYRECHARGEEXPLIFT_FLD_STARECHARGEVOLUME		"StaRechargeVolume"				// 稳定回灌量(m3/d)				float
#define TBL_HYRECHARGEEXPLIFT_FLD_INFLURADIUS			"InfluRadius"					// 影响半径						float
#define TBL_HYRECHARGEEXPLIFT_FLD_SWGGAA				"SWGGAA"						// 渗透系数						float
#define TBL_HYRECHARGEEXPLIFT_FLD_HYDRACOEFFIC			"HydraCoeffic"					// 导水系数						float
#define TBL_HYRECHARGEEXPLIFT_FLD_STORECOEFFIC			"StoreCoeffic"					// 储水系数						float
#define TBL_HYRECHARGEEXPLIFT_FLD_WATERSUPPLY			"WaterSupply"					// 给水度						float
#define TBL_HYRECHARGEEXPLIFT_FLD_LEAPFROGCOEFFIC		"LeapfrogCoeffic"				// 越流系数						float
//from 回灌实验钻孔信息表
#define TBL_HYRECHARGEEXPLIFT_FLD_RECHARGEEXPNO			"RechargeExpNo"				// 回灌试验编号			varchar
#define TBL_HYRECHARGEEXPLIFT_FLD_PNTID					UNION_MACRO_PNT_ID			//* 点ID					int
#define TBL_HYRECHARGEEXPLIFT_FLD_RECHARGEEXPHOLENO		"RechargeExpHoleNo"			// 回灌试验孔号			varchar
#define TBL_HYRECHARGEEXPLIFT_FLD_TESTHOLETYPE			"TestHoleType"				// 试验孔类型			varchar
#define TBL_HYRECHARGEEXPLIFT_FLD_RECHARGEHOLEDIST		"RechargeHoleDist"			// 与回灌孔距离(m)		float
#define TBL_HYRECHARGEEXPLIFT_FLD_BURYDEPTH_BEFORE		"BuryDepth_Before"			// 回灌前静水位埋深(m)	float
#define TBL_HYRECHARGEEXPLIFT_FLD_BURYDEPTH_AFTER		"BuryDepth_After"			// 回灌后静水位埋深(m)	float
#define TBL_HYRECHARGEEXPLIFT_FLD_SECTNUM				"SectNum"					// 试验段数量			int
#define TBL_HYRECHARGEEXPLIFT_FLD_TOTALTHICKNESS		"TotalThickness"			// 试验段含水层总厚度(m) float
#define TBL_HYRECHARGEEXPLIFT_FLD_EODOWPSECTION			"EodowpSection"				// 过水断面等效外径(mm)	 float

//回灌试验观测记录表
#define TBL_HYRECHARGEEXPOB_TBL "HYRechargeExpOb"
#define TBL_HYRECHARGEEXPOB_FLD_DYWATERLEVELID		"DyWaterLevelID"				//* 回灌动水位ID					int
#define TBL_HYRECHARGEEXPOB_FLD_LIFTID				"LiftID"						// 升程ID						int
#define TBL_HYRECHARGEEXPOB_FLD_LIFTNO				"LiftNo"						// 升程编号						varchar
#define TBL_HYRECHARGEEXPOB_FLD_PKIAA				UNION_MACRO_PRJCODE				// 项目统一编号					varchar
#define TBL_HYRECHARGEEXPOB_FLD_SWDDAH				"SWDDAH"						// 观测时间						date
#define TBL_HYRECHARGEEXPOB_FLD_RECHARGEDURATION	"RechargeDuration"				// 回灌延续时间(min)			varchar
#define TBL_HYRECHARGEEXPOB_FLD_SWEGAB				"SWEGAB"						// 水位埋深(m)					float
#define TBL_HYRECHARGEEXPOB_FLD_WATERLEVELRISE		"WaterLevelrise"				// 水位回升(m)					float
#define TBL_HYRECHARGEEXPOB_FLD_SWIFCBM				"SWIFCBM"						// 回灌量(m3/d)					float
#define TBL_HYRECHARGEEXPOB_FLD_SWIFCBL				"SWIFCBL"						// 回灌量(L/s)					float
#define TBL_HYRECHARGEEXPOB_FLD_SWADET				"SWADET"						// 水温(℃)						float
#define TBL_HYRECHARGEEXPOB_FLD_SWADBB				"SWADBB"						// 气温(℃)						float
#define TBL_HYRECHARGEEXPOB_FLD_IS_STABLE			"Is_Stable"						// 是否稳定						bool
#define TBL_HYRECHARGEEXPOB_FLD_MEMO				"_Memo"							// 备注							varchar
//from 回灌实验钻孔信息表
#define TBL_HYRECHARGEEXPOB_FLD_RECHARGEEXPNO			"RechargeExpNo"				// 回灌试验编号			varchar
#define TBL_HYRECHARGEEXPOB_FLD_PNTID					UNION_MACRO_PNT_ID			//* 点ID					int
#define TBL_HYRECHARGEEXPOB_FLD_RECHARGEEXPHOLENO		"RechargeExpHoleNo"			// 回灌试验孔号			varchar
#define TBL_HYRECHARGEEXPOB_FLD_TESTHOLETYPE			"TestHoleType"				// 试验孔类型			varchar
#define TBL_HYRECHARGEEXPOB_FLD_RECHARGEHOLEDIST		"RechargeHoleDist"			// 与回灌孔距离(m)		float
#define TBL_HYRECHARGEEXPOB_FLD_BURYDEPTH_BEFORE		"BuryDepth_Before"			// 回灌前静水位埋深(m)	float
#define TBL_HYRECHARGEEXPOB_FLD_BURYDEPTH_AFTER			"BuryDepth_After"			// 回灌后静水位埋深(m)	float
#define TBL_HYRECHARGEEXPOB_FLD_SECTNUM					"SectNum"					// 试验段数量			int
#define TBL_HYRECHARGEEXPOB_FLD_TOTALTHICKNESS			"TotalThickness"			// 试验段含水层总厚度(m) float
#define TBL_HYRECHARGEEXPOB_FLD_EODOWPSECTION			"EodowpSection"				// 过水断面等效外径(mm)	 float

//热响应实验成果表
#define TBL_HYTHERMALRES_TBL "HYThermalRes"
#define TBL_HYTHERMALRES_FLD_THERMALRESID		"ThermalResID"			//* 热响应试验ID				int
#define TBL_HYTHERMALRES_FLD_PNTID				UNION_MACRO_PNT_ID		//* 点ID					int
#define TBL_HYTHERMALRES_FLD_GCEBAN				"GCEBAN"				// 试验编号					varchar
#define TBL_HYTHERMALRES_FLD_TESTHORIZON		"TestHorizon"			// 试验层位					varchar
#define TBL_HYTHERMALRES_FLD_OBHOLENUM			"ObHoleNum"				// 观测孔数量				int
#define TBL_HYTHERMALRES_FLD_SWADER				"SWADER"				// 最低温度					float
#define TBL_HYTHERMALRES_FLD_SWADEQ				"SWADEQ"				// 最高温度					float
#define TBL_HYTHERMALRES_FLD_SWGGAU				"SWGGAU"				// 试验影响半径				float
#define TBL_HYTHERMALRES_FLD_GCDGAF				"GCDGAF"				// 平均导热系数				float
#define TBL_HYTHERMALRES_FLD_GCEBAS				"GCEBAS"				// 热扩散率					float
#define TBL_HYTHERMALRES_FLD_GCDGAE				"GCDGAE"				// 比热容					float
#define TBL_HYTHERMALRES_FLD_TESTEQUIPMODEL		"TestEquipModel"		// 试验仪器及型号			varchar
#define TBL_HYTHERMALRES_FLD_SWDDAA				"SWDDAA"				// 试验开始日期				date
#define TBL_HYTHERMALRES_FLD_SWDDAB				"SWDDAB"				// 试验结束日期				date
#define TBL_HYTHERMALRES_FLD_PLANEPOSMAP		"PlanePosMap"			// 平面位置示意图			varchar
#define TBL_HYTHERMALRES_FLD_PROFILEMAP			"ProfileMap"			// 剖面示意图				varchar
#define TBL_HYTHERMALRES_FLD_FIELDIMAGE			"FieldImage"			// 野外照片(视频)			varchar
#define TBL_HYTHERMALRES_FLD_RECORDCARD			"RecordCard"			// 记录卡片(记录)			varchar
#define TBL_HYTHERMALRES_FLD_TESTORGN			"TestOrgn"				// 试验单位					varchar
#define TBL_HYTHERMALRES_FLD_TECHNICIAN			"Technician"			// 现场技术员				varchar
#define TBL_HYTHERMALRES_FLD_INPUTER			"Inputer"				// 录入员					varchar
#define TBL_HYTHERMALRES_FLD_INPUTORGN			"InputOrgn"				// 录入单位					varchar
#define TBL_HYTHERMALRES_FLD_INPUTDATE			"InputDate"				// 录入日期					date
#define TBL_HYTHERMALRES_FLD_MEMO				"_Memo"					// 备注						varchar

//热响应试验地温观测记录表
#define TBL_HYRHERNAKRES_OB_TBL "HYThernakResOb"
#define TBL_HYRHERNAKRES_OB_FLD_GEOTEMPOBID	"GeoTempObID"				//* 地温观测记录ID		int
#define TBL_HYRHERNAKRES_OB_FLD_SWDDAH			"SWDDAH"				// 观测时间				date
#define TBL_HYRHERNAKRES_OB_FLD_GCKUGF			"GCKUGF"				// 深度(m)				float
#define TBL_HYRHERNAKRES_OB_FLD_SWADET			"SWADET"				// 温度					float
#define TBL_HYRHERNAKRES_OB_FLD_OBSERVER		"_Observer"				// 观测人				varchar
#define TBL_HYRHERNAKRES_OB_FLD_JJDAC			"JJDAC"					// 记录人				varchar
//from 热响应实验钻孔信息表
#define TBL_HYRHERNAKRES_OB_FLD_TESTHOLENO		"TestHoleNo"			// 试验孔号				varchar
#define TBL_HYRHERNAKRES_OB_FLD_GCEBAN			"GCEBAN"				// 试验编号				varchar
#define TBL_HYRHERNAKRES_OB_FLD_PNTID			"PntID"					//* 点ID					int
#define TBL_HYRHERNAKRES_OB_FLD_TKACC			"TKACC"					// 孔深					float
#define TBL_HYRHERNAKRES_OB_FLD_SWDAAX			"SWDAAX"				// 与主孔距离			float

//渗水试验成果表
#define TBL_HYWATERSEEPAGEEXP_TBL "HYWaterSeepageExp"
#define TBL_HYWATERSEEPAGEEXP_FLD_WATERSEEPAGEEXPID		"WaterSeepageExpID"		//* 渗水试验ID		int
#define TBL_HYWATERSEEPAGEEXP_FLD_WATERSEEPAGEEXPNO		"WaterSeepageExpNo"		// 渗水试验编号		varchar
#define TBL_HYWATERSEEPAGEEXP_FLD_PNTID					"PntID"					//* 点ID				int
#define TBL_HYWATERSEEPAGEEXP_FLD_WATERSEEPAGEHOLENO	"WaterSeepageHoleNo"	// 渗水试验孔号		varchar
#define TBL_HYWATERSEEPAGEEXP_FLD_TESTMETHOD			"TestMethod"			// 试验方法			varchar
#define TBL_HYWATERSEEPAGEEXP_FLD_TESTHORIZON			"TestHorizon"			// 试验层位			varchar
#define TBL_HYWATERSEEPAGEEXP_FLD_TESTBEDLITHOLOGY		"TestBedLithology"		// 试验层岩性		varchar
#define TBL_HYWATERSEEPAGEEXP_FLD_GCEBAI				"GCEBAI"				// 试坑直径			float
#define TBL_HYWATERSEEPAGEEXP_FLD_SWDAAU				"SWDAAU"				// 试坑底面积		float
#define TBL_HYWATERSEEPAGEEXP_FLD_GCEBAJ				"GCEBAJ"				// 试坑深度			float
#define TBL_HYWATERSEEPAGEEXP_FLD_GCEBA					"GCEBA"					// 内环直径			float
#define TBL_HYWATERSEEPAGEEXP_FLD_GCEBAK				"GCEBAK"				// 外环直径			float
#define TBL_HYWATERSEEPAGEEXP_FLD_GCGDJ					"GCGDJ"					// 渗透深度			float
#define TBL_HYWATERSEEPAGEEXP_FLD_SWGGBR				"SWGGBR"				// 水层厚度			float
#define TBL_HYWATERSEEPAGEEXP_FLD_SWDAAV				"SWDAAV"				// 毛细高度			float
#define TBL_HYWATERSEEPAGEEXP_FLD_SWDDAI				"SWDDAI"				// 累计延续时间		int
#define TBL_HYWATERSEEPAGEEXP_FLD_SWDAAW				"SWDAAW"				// 稳定流量			float
#define TBL_HYWATERSEEPAGEEXP_FLD_SWGGAA				"SWGGAA"				// 渗透系数			float
#define TBL_HYWATERSEEPAGEEXP_FLD_LITHOLOGYDESC			"LithologyDesc"			// 包气带岩性描述	varchar
#define TBL_HYWATERSEEPAGEEXP_FLD_SWDDAA				"SWDDAA"				// 试验开始时间		date
#define TBL_HYWATERSEEPAGEEXP_FLD_SWDDAB				"SWDDAB"				// 试验结束时间		date
#define TBL_HYWATERSEEPAGEEXP_FLD_PLANEPOSMAP			"PlanePosMap"			// 平面位置示意图	varchar
#define TBL_HYWATERSEEPAGEEXP_FLD_PROFILEMAP			"ProfileMap"			// 剖面示意图		varchar
#define TBL_HYWATERSEEPAGEEXP_FLD_FIELDIMAGE			"FieldImage"			// 野外照片(视频)	varchar
#define TBL_HYWATERSEEPAGEEXP_FLD_RECORDCARD			"RecordCard"			// 记录卡片(记录)	varchar
#define TBL_HYWATERSEEPAGEEXP_FLD_TESTORGN				"TestOrgn"				// 试验单位			varchar
#define TBL_HYWATERSEEPAGEEXP_FLD_JJDAC					"JJDAC"					// 记录人			varchar
#define TBL_HYWATERSEEPAGEEXP_FLD__OBSERVER				"_Observer"				// 观测人			varchar
#define TBL_HYWATERSEEPAGEEXP_FLD_INPUTER				"Inputer"				// 录入员			varchar
#define TBL_HYWATERSEEPAGEEXP_FLD_INPUTORGN				"InputOrgn"				// 录入单位 		varchar
#define TBL_HYWATERSEEPAGEEXP_FLD_INPUTDATE				"InputDate"				// 录入日期			date
#define TBL_HYWATERSEEPAGEEXP_FLD_TKDAE					"TKDAE"					// 天气				varchar
#define TBL_HYWATERSEEPAGEEXP_FLD_MEMO					"_Memo"					// 备注				varchar


//渗水试验观测记录表
#define TBL_HYWATERSEEPAGEEXPOB_TBL "HYWaterSeepageExpOb"
#define TBL_HYWATERSEEPAGEEXPOB_FLD_WATERSEEPAGEEXPOBID		"WaterSeepageExpObID"	//* 渗水观测记录ID	int
#define TBL_HYWATERSEEPAGEEXPOB_FLD_PNTID							UNION_MACRO_PNT_ID		//* 点ID					int
#define TBL_HYWATERSEEPAGEEXPOB_FLD_WATERSEEPAGEEXPNO		"WaterSeepageExpNo"		// 渗水试验编号		varchar
#define TBL_HYWATERSEEPAGEEXPOB_FLD_SWDDAH					"SWDDAH"				// 观测时间			date
#define TBL_HYWATERSEEPAGEEXPOB_FLD_SWDDAI					"SWDDAI"				// 延续时间			float
#define TBL_HYWATERSEEPAGEEXPOB_FLD_SWGCAK					"SWGCAK"				// 渗水体积			float
#define TBL_HYWATERSEEPAGEEXPOB_FLD_SWGCAA					"SWGCAA"				// 渗透流量			float
#define TBL_HYWATERSEEPAGEEXPOB_FLD_IS_STABLE				"Is_Stable"				// 是否稳定			bool
#define TBL_HYWATERSEEPAGEEXPOB_FLD_MEMO					"_Memo"					// 备注				varchar



/*---------------------------------------------------------样品采集类-----------------------------------------------------------*/
#define SCSAMPCOLLECT_MDL_CLASS "样品采集表类"
	//混合样品对照表 -- LH.2021.08.31 changed.
#define TBL_SCMIXSAMPCOMPARE_TBL "SCMixSampCompare"
#define TBL_SCMIXSAMPCOMPARE_FLD_MIXSAMPLEID		"MixSampleID"	//* 混合样品id		int
#define TBL_SCMIXSAMPCOMPARE_FLD_MIXSAMPLENO		"MixSampleNo"	// 混合样品编号		varchar
#define TBL_SCMIXSAMPCOMPARE_FLD_ORISAMPLEID		"OriSampleID"	// 原始样品ID		int
#define TBL_SCMIXSAMPCOMPARE_FLD_ORISAMPLENO		"OriSampleNo"	// 原始样品编号		varchar
#define TBL_SCMIXSAMPCOMPARE_FLD_PKIAA				UNION_MACRO_PRJCODE	// 项目统一编号		varchar
// from 样品信息表 *
#define TBL_SCMIXSAMPCOMPARE_FLD_GCEABB				"GCEABB"			// 样品编号			varchar
#define TBL_SCMIXSAMPCOMPARE_FLD_PNTID				UNION_MACRO_PNT_ID  //* 点ID				int		FK
#define TBL_SCMIXSAMPCOMPARE_FLD_SWBCF				"SWBCF"				// 样品类型			varchar
#define TBL_SCMIXSAMPCOMPARE_FLD_ISMIXSAMPLE		"IsMixSample"		// 混合样			varchar
#define TBL_SCMIXSAMPCOMPARE_FLD_PNTTYPE			"PntType"			// 点类型			varchar
#define TBL_SCMIXSAMPCOMPARE_FLD_SECONDCODE			"SecondCode"		// 样品二次编码		varchar
#define TBL_SCMIXSAMPCOMPARE_FLD_SAMPLEVOLUME		"SampleVolume"		// 样品体积			float
#define TBL_SCMIXSAMPCOMPARE_FLD_GCEABM				"GCEABM"			// 野外命名			varchar
#define TBL_SCMIXSAMPCOMPARE_FLD_GCEAAL				"GCEAAL"			// 样品重量(kg)		float
#define TBL_SCMIXSAMPCOMPARE_FLD_SAMPLELENGTH		"SampleLength"		// 样品长度(cm)		varchar
#define TBL_SCMIXSAMPCOMPARE_FLD_PRETREATMETHOD		"PretreatMethod"	// 预处理方法		varchar
#define TBL_SCMIXSAMPCOMPARE_FLD_TESTCONTENT		"TestContent"		// 测试内容			varchar
#define TBL_SCMIXSAMPCOMPARE_FLD_PLANEPOSMAP		"PlanePosMap"		// 平面位置示意图		varchar
#define TBL_SCMIXSAMPCOMPARE_FLD_PROFILEMAP			"ProfileMap"		// 剖面示意图		varchar
#define TBL_SCMIXSAMPCOMPARE_FLD_FIELDIMAGE			"FieldImage"		// 野外照片(视频)		varchar
#define TBL_SCMIXSAMPCOMPARE_FLD_RECORDCARD			"RecordCard"		// 记录卡片(记录)		varchar
#define TBL_SCMIXSAMPCOMPARE_FLD_SAMPLEORGN			"SampleOrgn"		// 采样单位			varchar
#define TBL_SCMIXSAMPCOMPARE_FLD_SWFOMW				"SWFOMW"			// 采样人			varchar
#define TBL_SCMIXSAMPCOMPARE_FLD_GCEABJ				"GCEABJ"			// 采样日期			date
#define TBL_SCMIXSAMPCOMPARE_FLD_INPUTER			"Inputer"			// 录入员			varchar
#define TBL_SCMIXSAMPCOMPARE_FLD_INPUTORGN			"InputOrgn"			// 录入单位			varchar
#define TBL_SCMIXSAMPCOMPARE_FLD_INPUTDATE			"InputDate"			// 录入日期			date


//岩石样品基本情况表
#define TBL_SCROCKSAMPLE_TBL "SCRockSample"
#define TBL_SCROCKSAMPLE_FLD_ROCKID				"RockID"			//* 岩样ID			int
#define TBL_SCROCKSAMPLE_FLD_SAMPLEBAGNO		"SampleBagNo"		// 样品袋号			varchar
#define TBL_SCROCKSAMPLE_FLD_SAMPLECOLOR		"SampleColor"		// 样品颜色			varchar
#define TBL_SCROCKSAMPLE_FLD_GCKLT				"GCKLT"				// 岩性描述			varchar
#define TBL_SCROCKSAMPLE_FLD_MINERALCONTENT		"MineralContent"	// 矿物成分及含量	varchar
#define TBL_SCROCKSAMPLE_FLD_ROCKFORMAT			"RockFormat"		// 岩层倾向			varchar
#define TBL_SCROCKSAMPLE_FLD_STRATUMDIP			"StratumDip"		// 岩层倾角			varchar
#define TBL_SCROCKSAMPLE_FLD_JOINTFISSURE		"JointFissure"		// 节理裂隙			varchar
#define TBL_SCROCKSAMPLE_FLD_MINERALIZATTYPE	"MineralizatType"	// 矿化类型			varchar
#define TBL_SCROCKSAMPLE_FLD_ALTERATTYPE		"AlteratType"		// 蚀变类型			varchar
#define TBL_SCROCKSAMPLE_FLD_KARSTTYPE			"KarstType"			// 岩溶类型			varchar
#define TBL_SCROCKSAMPLE_FLD_MEMO				"_Memo"				// 备注				varchar
// from 样品信息表 *
#define TBL_SCROCKSAMPLE_FLD_GCEABB				"GCEABB"			// 样品编号			varchar
#define TBL_SCROCKSAMPLE_FLD_PNTID				UNION_MACRO_PNT_ID  //* 点ID				int		FK
#define TBL_SCROCKSAMPLE_FLD_SWBCF				"SWBCF"				// 样品类型			varchar
#define TBL_SCROCKSAMPLE_FLD_ISMIXSAMPLE		"IsMixSample"		// 混合样			varchar
#define TBL_SCROCKSAMPLE_FLD_PNTTYPE			"PntType"			// 点类型			varchar
#define TBL_SCROCKSAMPLE_FLD_SECONDCODE			"SecondCode"		// 样品二次编码		varchar
#define TBL_SCROCKSAMPLE_FLD_SAMPLEVOLUME		"SampleVolume"		// 样品体积			float
#define TBL_SCROCKSAMPLE_FLD_GCEABM				"GCEABM"			// 野外命名			varchar
#define TBL_SCROCKSAMPLE_FLD_GCEAAL				"GCEAAL"			// 样品重量(kg)		float
#define TBL_SCROCKSAMPLE_FLD_SAMPLELENGTH		"SampleLength"		// 样品长度(cm)		varchar
#define TBL_SCROCKSAMPLE_FLD_PRETREATMETHOD		"PretreatMethod"	// 预处理方法		varchar
#define TBL_SCROCKSAMPLE_FLD_TESTCONTENT		"TestContent"		// 测试内容			varchar
#define TBL_SCROCKSAMPLE_FLD_PLANEPOSMAP		"PlanePosMap"		// 平面位置示意图		varchar
#define TBL_SCROCKSAMPLE_FLD_PROFILEMAP			"ProfileMap"		// 剖面示意图		varchar
#define TBL_SCROCKSAMPLE_FLD_FIELDIMAGE			"FieldImage"		// 野外照片(视频)		varchar
#define TBL_SCROCKSAMPLE_FLD_RECORDCARD			"RecordCard"		// 记录卡片(记录)		varchar
#define TBL_SCROCKSAMPLE_FLD_SAMPLEORGN			"SampleOrgn"		// 采样单位			varchar
#define TBL_SCROCKSAMPLE_FLD_SWFOMW				"SWFOMW"			// 采样人			varchar
#define TBL_SCROCKSAMPLE_FLD_GCEABJ				"GCEABJ"			// 采样日期			date
#define TBL_SCROCKSAMPLE_FLD_INPUTER			"Inputer"			// 录入员			varchar
#define TBL_SCROCKSAMPLE_FLD_INPUTORGN			"InputOrgn"			// 录入单位			varchar
#define TBL_SCROCKSAMPLE_FLD_INPUTDATE			"InputDate"			// 录入日期			date


//土壤样品基本情况表
#define TBL_SCSOILSAMPLE_TBL "SCSoilSample"
#define TBL_SCSOILSAMPLE_FLD_SOILID				"SoilID"			//* 土壤样ID			int
#define TBL_SCSOILSAMPLE_FLD_SAMPLEBAGNO		"SampleBagNo"		// 样品袋号			varchar
#define TBL_SCSOILSAMPLE_FLD_COMBINEDSAMPID		"CombinedSampID"	// 组合样数			varchar
#define TBL_SCSOILSAMPLE_FLD_GCKUPE				"CauseType"			// 成因类型			varchar
#define TBL_SCSOILSAMPLE_FLD_SAMPLECOLOR		"SampleColor"		// 样品颜色			varchar
#define TBL_SCSOILSAMPLE_FLD_GCKLT				"GCKLT"				// 岩性描述			varchar
#define TBL_SCSOILSAMPLE_FLD_COARSESANDCONTENT	"CoarsesandContent"	// 粗砂含量			float
#define TBL_SCSOILSAMPLE_FLD_FINESANDCONTENT	"FinesandContent"	// 细砂含量			float
#define TBL_SCSOILSAMPLE_FLD_CLAYCONTENT		"ClayContent"		// 粘土含量			float
#define TBL_SCSOILSAMPLE_FLD__POLLUTION			"_Pollution"		// 污染				varchar
#define TBL_SCSOILSAMPLE_FLD__EROSION			"_Erosion"			// 侵蚀				varchar
#define TBL_SCSOILSAMPLE_FLD__SALTED			"_Salted"			// 盐渍				varchar
#define TBL_SCSOILSAMPLE_FLD__CROP				"_Crop"				// 农作物			varchar
#define TBL_SCSOILSAMPLE_FLD__CULTURE			"_Culture"			// 养殖物			varchar
#define TBL_SCSOILSAMPLE_FLD_FAMOUSPRODUCT		"FamousProduct"		// 名优特产品		varchar
#define TBL_SCSOILSAMPLE_FLD_SOILUSING			"SoilUsing"			// 土地利用			varchar
#define TBL_SCSOILSAMPLE_FLD_MARKPOS			"MarkPos"			// 标记位置			varchar
#define TBL_SCSOILSAMPLE_FLD_SWFGAA				"SWFGAA"			// 采样层位			varchar
#define TBL_SCSOILSAMPLE_FLD_MEMO				"_Memo"				// 备注				varchar
// from 样品信息表 *
#define TBL_SCSOILSAMPLE_FLD_GCEABB				"GCEABB"			// 样品编号			varchar
#define TBL_SCSOILSAMPLE_FLD_PNTID				UNION_MACRO_PNT_ID  //* 点ID				int		FK
#define TBL_SCSOILSAMPLE_FLD_SWBCF				"SWBCF"				// 样品类型			varchar
#define TBL_SCSOILSAMPLE_FLD_ISMIXSAMPLE		"IsMixSample"		// 混合样			varchar
#define TBL_SCSOILSAMPLE_FLD_PNTTYPE			"PntType"			// 点类型			varchar
#define TBL_SCSOILSAMPLE_FLD_SECONDCODE			"SecondCode"		// 样品二次编码		varchar
#define TBL_SCSOILSAMPLE_FLD_SAMPLEVOLUME		"SampleVolume"		// 样品体积			float
#define TBL_SCSOILSAMPLE_FLD_GCEABM				"GCEABM"			// 野外命名			varchar
#define TBL_SCSOILSAMPLE_FLD_GCEAAL				"GCEAAL"			// 样品重量(kg)		float
#define TBL_SCSOILSAMPLE_FLD_SAMPLELENGTH		"SampleLength"		// 样品长度(cm)		varchar
#define TBL_SCSOILSAMPLE_FLD_PRETREATMETHOD		"PretreatMethod"	// 预处理方法		varchar
#define TBL_SCSOILSAMPLE_FLD_TESTCONTENT		"TestContent"		// 测试内容			varchar
#define TBL_SCSOILSAMPLE_FLD_PLANEPOSMAP		"PlanePosMap"		// 平面位置示意图		varchar
#define TBL_SCSOILSAMPLE_FLD_PROFILEMAP			"ProfileMap"		// 剖面示意图		varchar
#define TBL_SCSOILSAMPLE_FLD_FIELDIMAGE			"FieldImage"		// 野外照片(视频)		varchar
#define TBL_SCSOILSAMPLE_FLD_RECORDCARD			"RecordCard"		// 记录卡片(记录)		varchar
#define TBL_SCSOILSAMPLE_FLD_SAMPLEORGN			"SampleOrgn"		// 采样单位			varchar
#define TBL_SCSOILSAMPLE_FLD_SWFOMW				"SWFOMW"			// 采样人			varchar
#define TBL_SCSOILSAMPLE_FLD_GCEABJ				"GCEABJ"			// 采样日期			date
#define TBL_SCSOILSAMPLE_FLD_INPUTER			"Inputer"			// 录入员			varchar
#define TBL_SCSOILSAMPLE_FLD_INPUTORGN			"InputOrgn"			// 录入单位			varchar
#define TBL_SCSOILSAMPLE_FLD_INPUTDATE			"InputDate"			// 录入日期			date

//水体沉积物样品基本情况表
#define TBL_SCWATERSEDIMENT_TBL "SCWaterSediment"
#define TBL_SCWATERSEDIMENT_FLD_WATERSEDIMENTID			"WaterSedimentID"		//* 沉积物样ID		int
#define TBL_SCWATERSEDIMENT_FLD_SAMPLEBAGNO				"SampleBagNo"			// 样品袋号			varchar
#define TBL_SCWATERSEDIMENT_FLD_WATERNAME				"WaterName"				// 水体名称			varchar
#define TBL_SCWATERSEDIMENT_FLD_SAMPLESITE				"SampleSite"			// 采样部位			varchar
#define TBL_SCWATERSEDIMENT_FLD_SWNCAH					"SWNCAH"				// 水深(m)			float
#define TBL_SCWATERSEDIMENT_FLD_GCKUPE					"CauseType"				// 成因类型			varchar
#define TBL_SCWATERSEDIMENT_FLD_SAMPLECOLOR				"SampleColor"			// 样品颜色			varchar
#define TBL_SCWATERSEDIMENT_FLD_GCKLT					"GCKLT"					// 岩性描述			varchar
#define TBL_SCWATERSEDIMENT_FLD_COARSESANDCONTENT		"CoarsesandContent"		// 粗砂含量(%)		float
#define TBL_SCWATERSEDIMENT_FLD_FINESANDCONTENT			"FinesandContent"		// 细砂含量(%)		float
#define TBL_SCWATERSEDIMENT_FLD_CLAYCONTENT				"ClayContent"			// 粘土含量(%)		float
#define TBL_SCWATERSEDIMENT_FLD_ORGANICCONTENT			"OrganicContent"		// 有机物含量(%)	float
#define TBL_SCWATERSEDIMENT_FLD_BIOREMAIN				"BioRemain"				// 生物残骸			varchar
#define TBL_SCWATERSEDIMENT_FLD_POLLUTE					"_Pollute"				// 污染情况			varchar
#define TBL_SCWATERSEDIMENT_FLD_MEMO					"_Memo"					// 备注				varchar
// from 样品信息表 *
#define TBL_SCWATERSEDIMENT_FLD_GCEABB				"GCEABB"			// 样品编号			varchar
#define TBL_SCWATERSEDIMENT_FLD_PNTID				UNION_MACRO_PNT_ID  //* 点ID				int		FK
#define TBL_SCWATERSEDIMENT_FLD_SWBCF				"SWBCF"				// 样品类型			varchar
#define TBL_SCWATERSEDIMENT_FLD_ISMIXSAMPLE			"IsMixSample"		// 混合样			varchar
#define TBL_SCWATERSEDIMENT_FLD_PNTTYPE				"PntType"			// 点类型			varchar
#define TBL_SCWATERSEDIMENT_FLD_SECONDCODE			"SecondCode"		// 样品二次编码		varchar
#define TBL_SCWATERSEDIMENT_FLD_SAMPLEVOLUME		"SampleVolume"		// 样品体积			float
#define TBL_SCWATERSEDIMENT_FLD_GCEABM				"GCEABM"			// 野外命名			varchar
#define TBL_SCWATERSEDIMENT_FLD_GCEAAL				"GCEAAL"			// 样品重量(kg)		float
#define TBL_SCWATERSEDIMENT_FLD_SAMPLELENGTH		"SampleLength"		// 样品长度(cm)		varchar
#define TBL_SCWATERSEDIMENT_FLD_PRETREATMETHOD		"PretreatMethod"	// 预处理方法		varchar
#define TBL_SCWATERSEDIMENT_FLD_TESTCONTENT			"TestContent"		// 测试内容			varchar
#define TBL_SCWATERSEDIMENT_FLD_PLANEPOSMAP			"PlanePosMap"		// 平面位置示意图		varchar
#define TBL_SCWATERSEDIMENT_FLD_PROFILEMAP			"ProfileMap"		// 剖面示意图		varchar
#define TBL_SCWATERSEDIMENT_FLD_FIELDIMAGE			"FieldImage"		// 野外照片(视频)		varchar
#define TBL_SCWATERSEDIMENT_FLD_RECORDCARD			"RecordCard"		// 记录卡片(记录)		varchar
#define TBL_SCWATERSEDIMENT_FLD_SAMPLEORGN			"SampleOrgn"		// 采样单位			varchar
#define TBL_SCWATERSEDIMENT_FLD_SWFOMW				"SWFOMW"			// 采样人			varchar
#define TBL_SCWATERSEDIMENT_FLD_GCEABJ				"GCEABJ"			// 采样日期			date
#define TBL_SCWATERSEDIMENT_FLD_INPUTER				"Inputer"			// 录入员			varchar
#define TBL_SCWATERSEDIMENT_FLD_INPUTORGN			"InputOrgn"			// 录入单位			varchar
#define TBL_SCWATERSEDIMENT_FLD_INPUTDATE			"InputDate"			// 录入日期			date


//沉积物柱状样品分层描述表
#define TBL_SCSEDIMENTCOLUMN_TBL "SCSedimentColumn"
#define TBL_SCSEDIMENTCOLUMN_FLD_COLUMNID			"ColumnID"				//* 柱状样分层ID		int
#define TBL_SCSEDIMENTCOLUMN_FLD_FIELDLAYERNUM		"FieldLayerNum"			// 野外分层号		varchar
#define TBL_SCSEDIMENTCOLUMN_FLD_LAYERDEPTH			"LayerDepth"			//* 分层深度(m)		float
#define TBL_SCSEDIMENTCOLUMN_FLD_LAYERTHICKNESS		"LayerThickness"		// 层厚(m)			float
#define TBL_SCSEDIMENTCOLUMN_FLD_GCKLQ				"GCKLQ"					// 岩性名称			varchar
#define TBL_SCSEDIMENTCOLUMN_FLD_LAYERDESC			"LayerDesc"				// 分层描述			varchar
// from 样品信息表 *
#define TBL_SCSEDIMENTCOLUMN_FLD_GCEABB				"GCEABB"			// 样品编号			varchar
#define TBL_SCSEDIMENTCOLUMN_FLD_PNTID				UNION_MACRO_PNT_ID  //* 点ID				int		FK
#define TBL_SCSEDIMENTCOLUMN_FLD_SWBCF				"SWBCF"				// 样品类型			varchar
#define TBL_SCSEDIMENTCOLUMN_FLD_ISMIXSAMPLE		"IsMixSample"		// 混合样			varchar
#define TBL_SCSEDIMENTCOLUMN_FLD_PNTTYPE			"PntType"			// 点类型			varchar
#define TBL_SCSEDIMENTCOLUMN_FLD_SECONDCODE			"SecondCode"		// 样品二次编码		varchar
#define TBL_SCSEDIMENTCOLUMN_FLD_SAMPLEVOLUME		"SampleVolume"		// 样品体积			float
#define TBL_SCSEDIMENTCOLUMN_FLD_GCEABM				"GCEABM"			// 野外命名			varchar
#define TBL_SCSEDIMENTCOLUMN_FLD_GCEAAL				"GCEAAL"			// 样品重量(kg)		float
#define TBL_SCSEDIMENTCOLUMN_FLD_SAMPLELENGTH		"SampleLength"		// 样品长度(cm)		varchar
#define TBL_SCSEDIMENTCOLUMN_FLD_PRETREATMETHOD		"PretreatMethod"	// 预处理方法		varchar
#define TBL_SCSEDIMENTCOLUMN_FLD_TESTCONTENT		"TestContent"		// 测试内容			varchar
#define TBL_SCSEDIMENTCOLUMN_FLD_PLANEPOSMAP		"PlanePosMap"		// 平面位置示意图		varchar
#define TBL_SCSEDIMENTCOLUMN_FLD_PROFILEMAP			"ProfileMap"		// 剖面示意图		varchar
#define TBL_SCSEDIMENTCOLUMN_FLD_FIELDIMAGE			"FieldImage"		// 野外照片(视频)		varchar
#define TBL_SCSEDIMENTCOLUMN_FLD_RECORDCARD			"RecordCard"		// 记录卡片(记录)		varchar
#define TBL_SCSEDIMENTCOLUMN_FLD_SAMPLEORGN			"SampleOrgn"		// 采样单位			varchar
#define TBL_SCSEDIMENTCOLUMN_FLD_SWFOMW				"SWFOMW"			// 采样人			varchar
#define TBL_SCSEDIMENTCOLUMN_FLD_GCEABJ				"GCEABJ"			// 采样日期			date
#define TBL_SCSEDIMENTCOLUMN_FLD_INPUTER			"Inputer"			// 录入员			varchar
#define TBL_SCSEDIMENTCOLUMN_FLD_INPUTORGN			"InputOrgn"			// 录入单位			varchar
#define TBL_SCSEDIMENTCOLUMN_FLD_INPUTDATE			"InputDate"			// 录入日期			date




//大气沉降样品基本情况表
#define TBL_SCATMOSSAMPLE_TBL "SCAtmosSample"
#define TBL_SCATMOSSAMPLE_FLD_ATMODEPOSITID		"AtmodepositID"				//* 大气沉降样ID		int
#define TBL_SCATMOSSAMPLE_FLD_SAMPLEBAGNO		"SampleBagNo"				// 样品袋号(缸号)	varchar
#define TBL_SCATMOSSAMPLE_FLD_SAMPLECOLOR		"SampleColor"				// 样品颜色			varchar
#define TBL_SCATMOSSAMPLE_FLD_DUSTFALLTYPE		"DustfallType"				// 降尘类型			varchar
#define TBL_SCATMOSSAMPLE_FLD__PRECIPITAT		"_Precipitat"				// 降水情况			varchar
#define TBL_SCATMOSSAMPLE_FLD__DEPTH			"_Depth"					// 离地高度(m)		float
#define TBL_SCATMOSSAMPLE_FLD__SURROUND			"_Surround"					// 周围环境			varchar
#define TBL_SCATMOSSAMPLE_FLD__MEMO				"_Memo"						// 备注				varchar
// from 样品信息表 *
#define TBL_SCATMOSSAMPLE_FLD_GCEABB			"GCEABB"			// 样品编号			varchar
#define TBL_SCATMOSSAMPLE_FLD_PNTID				UNION_MACRO_PNT_ID  //* 点ID				int		FK
#define TBL_SCATMOSSAMPLE_FLD_SWBCF				"SWBCF"				// 样品类型			varchar
#define TBL_SCATMOSSAMPLE_FLD_ISMIXSAMPLE		"IsMixSample"		// 混合样			varchar
#define TBL_SCATMOSSAMPLE_FLD_PNTTYPE			"PntType"			// 点类型			varchar
#define TBL_SCATMOSSAMPLE_FLD_SECONDCODE		"SecondCode"		// 样品二次编码		varchar
#define TBL_SCATMOSSAMPLE_FLD_SAMPLEVOLUME		"SampleVolume"		// 样品体积			float
#define TBL_SCATMOSSAMPLE_FLD_GCEABM			"GCEABM"			// 野外命名			varchar
#define TBL_SCATMOSSAMPLE_FLD_GCEAAL			"GCEAAL"			// 样品重量(kg)		float
#define TBL_SCATMOSSAMPLE_FLD_SAMPLELENGTH		"SampleLength"		// 样品长度(cm)		varchar
#define TBL_SCATMOSSAMPLE_FLD_PRETREATMETHOD	"PretreatMethod"	// 预处理方法		varchar
#define TBL_SCATMOSSAMPLE_FLD_TESTCONTENT		"TestContent"		// 测试内容			varchar
#define TBL_SCATMOSSAMPLE_FLD_PLANEPOSMAP		"PlanePosMap"		// 平面位置示意图		varchar
#define TBL_SCATMOSSAMPLE_FLD_PROFILEMAP		"ProfileMap"		// 剖面示意图		varchar
#define TBL_SCATMOSSAMPLE_FLD_FIELDIMAGE		"FieldImage"		// 野外照片(视频)		varchar
#define TBL_SCATMOSSAMPLE_FLD_RECORDCARD		"RecordCard"		// 记录卡片(记录)		varchar
#define TBL_SCATMOSSAMPLE_FLD_SAMPLEORGN		"SampleOrgn"		// 采样单位			varchar
#define TBL_SCATMOSSAMPLE_FLD_SWFOMW			"SWFOMW"			// 采样人			varchar
#define TBL_SCATMOSSAMPLE_FLD_GCEABJ			"GCEABJ"			// 采样日期			date
#define TBL_SCATMOSSAMPLE_FLD_INPUTER			"Inputer"			// 录入员			varchar
#define TBL_SCATMOSSAMPLE_FLD_INPUTORGN			"InputOrgn"			// 录入单位			varchar
#define TBL_SCATMOSSAMPLE_FLD_INPUTDATE			"InputDate"			// 录入日期			date


//水样基本情况表
#define TBL_SCWATERSAMPLE_TBL "SCWaterSample"
#define TBL_SCWATERSAMPLE_FLD_WATERSAMPLEID	"WaterSampleID"			//* 水样ID		int
#define TBL_SCWATERSAMPLE_FLD_WATERNAME		"WaterName"				// 水体名称		varchar
#define TBL_SCWATERSAMPLE_FLD_SAMPLESITE	"SampleSite"			// 采样部位		varchar
#define TBL_SCWATERSAMPLE_FLD_SWNCAH		"SWNCAH"				// 水深(m)		float
#define TBL_SCWATERSAMPLE_FLD_SWEGAB		"SWEGAB"				// 水位埋深(m)	float
#define TBL_SCWATERSAMPLE_FLD_WELLDEPTH		"Welldepth"				// 井深(m)		float
#define TBL_SCWATERSAMPLE_FLD_SWADET		"SWADET"				// 水温(℃)		float
#define TBL_SCWATERSAMPLE_FLD_WATERCOLOR	"WaterColor"			// 水色			varchar
#define TBL_SCWATERSAMPLE_FLD_WATERSMELLY	"WaterSmelly"			// 水臭			varchar
#define TBL_SCWATERSAMPLE_FLD_PKJFP			"PKJFP"					// 浊度			float
#define TBL_SCWATERSAMPLE_FLD_PH			"PH"					// pH值			float
#define TBL_SCWATERSAMPLE_FLD_BOTTOMPRODUCT	"BottomProduct"			// 底积物		varchar
#define TBL_SCWATERSAMPLE_FLD__POLLUTION	"_Pollution"			// 污染			varchar
#define TBL_SCWATERSAMPLE_FLD__USE			"_Use"					// 用途			varchar
#define TBL_SCWATERSAMPLE_FLD__MARK			"_Mark"					// 标记			varchar
#define TBL_SCWATERSAMPLE_FLD__MEMO			"_Memo"					// 备注			varchar
// from 样品信息表 *
#define TBL_SCWATERSAMPLE_FLD_GCEABB			"GCEABB"			// 样品编号			varchar
#define TBL_SCWATERSAMPLE_FLD_PNTID				UNION_MACRO_PNT_ID  //* 点ID				int		FK
#define TBL_SCWATERSAMPLE_FLD_SWBCF				"SWBCF"				// 样品类型			varchar
#define TBL_SCWATERSAMPLE_FLD_ISMIXSAMPLE		"IsMixSample"		// 混合样			varchar
#define TBL_SCWATERSAMPLE_FLD_PNTTYPE			"PntType"			// 点类型			varchar
#define TBL_SCWATERSAMPLE_FLD_SECONDCODE		"SecondCode"		// 样品二次编码		varchar
#define TBL_SCWATERSAMPLE_FLD_SAMPLEVOLUME		"SampleVolume"		// 样品体积			float
#define TBL_SCWATERSAMPLE_FLD_GCEABM			"GCEABM"			// 野外命名			varchar
#define TBL_SCWATERSAMPLE_FLD_GCEAAL			"GCEAAL"			// 样品重量(kg)		float
#define TBL_SCWATERSAMPLE_FLD_SAMPLELENGTH		"SampleLength"		// 样品长度(cm)		varchar
#define TBL_SCWATERSAMPLE_FLD_PRETREATMETHOD	"PretreatMethod"	// 预处理方法		varchar
#define TBL_SCWATERSAMPLE_FLD_TESTCONTENT		"TestContent"		// 测试内容			varchar
#define TBL_SCWATERSAMPLE_FLD_PLANEPOSMAP		"PlanePosMap"		// 平面位置示意图		varchar
#define TBL_SCWATERSAMPLE_FLD_PROFILEMAP		"ProfileMap"		// 剖面示意图		varchar
#define TBL_SCWATERSAMPLE_FLD_FIELDIMAGE		"FieldImage"		// 野外照片(视频)		varchar
#define TBL_SCWATERSAMPLE_FLD_RECORDCARD		"RecordCard"		// 记录卡片(记录)		varchar
#define TBL_SCWATERSAMPLE_FLD_SAMPLEORGN		"SampleOrgn"		// 采样单位			varchar
#define TBL_SCWATERSAMPLE_FLD_SWFOMW			"SWFOMW"			// 采样人			varchar
#define TBL_SCWATERSAMPLE_FLD_GCEABJ			"GCEABJ"			// 采样日期			date
#define TBL_SCWATERSAMPLE_FLD_INPUTER			"Inputer"			// 录入员			varchar
#define TBL_SCWATERSAMPLE_FLD_INPUTORGN			"InputOrgn"			// 录入单位			varchar
#define TBL_SCWATERSAMPLE_FLD_INPUTDATE			"InputDate"			// 录入日期			date


//水悬浮物样品基本情况表
#define TBL_SCWATERSUSPEND_TBL "SCWaterSuspend"
#define TBL_SCWATERSUSPEND_FLD_SUSPENDID	"SuspendID"			//* 水悬物样ID		int
#define TBL_SCWATERSUSPEND_FLD_SAMPLEBAGNO	"SampleBagNo"		// 样品袋号			varchar
#define TBL_SCWATERSUSPEND_FLD_WATERNAME	"WaterName"			// 水体名称			varchar
#define TBL_SCWATERSUSPEND_FLD_SAMPLESITE	"SampleSite"		// 采样部位			varchar
#define TBL_SCWATERSUSPEND_FLD_SWNCAH		"SWNCAH"			// 水深(m)			float
#define TBL_SCWATERSUSPEND_FLD_SAMPLECOLOR	"SampleColor"		// 样品颜色			varchar
#define TBL_SCWATERSUSPEND_FLD__MEMO		"_Memo"				// 备注				varchar
// from 样品信息表 *
#define TBL_SCWATERSUSPEND_FLD_GCEABB			"GCEABB"			// 样品编号			varchar
#define TBL_SCWATERSUSPEND_FLD_PNTID			UNION_MACRO_PNT_ID  //* 点ID				int		FK
#define TBL_SCWATERSUSPEND_FLD_SWBCF			"SWBCF"				// 样品类型			varchar
#define TBL_SCWATERSUSPEND_FLD_ISMIXSAMPLE		"IsMixSample"		// 混合样			varchar
#define TBL_SCWATERSUSPEND_FLD_PNTTYPE			"PntType"			// 点类型			varchar
#define TBL_SCWATERSUSPEND_FLD_SECONDCODE		"SecondCode"		// 样品二次编码		varchar
#define TBL_SCWATERSUSPEND_FLD_SAMPLEVOLUME		"SampleVolume"		// 样品体积			float
#define TBL_SCWATERSUSPEND_FLD_GCEABM			"GCEABM"			// 野外命名			varchar
#define TBL_SCWATERSUSPEND_FLD_GCEAAL			"GCEAAL"			// 样品重量(kg)		float
#define TBL_SCWATERSUSPEND_FLD_SAMPLELENGTH		"SampleLength"		// 样品长度(cm)		varchar
#define TBL_SCWATERSUSPEND_FLD_PRETREATMETHOD	"PretreatMethod"	// 预处理方法		varchar
#define TBL_SCWATERSUSPEND_FLD_TESTCONTENT		"TestContent"		// 测试内容			varchar
#define TBL_SCWATERSUSPEND_FLD_PLANEPOSMAP		"PlanePosMap"		// 平面位置示意图		varchar
#define TBL_SCWATERSUSPEND_FLD_PROFILEMAP		"ProfileMap"		// 剖面示意图		varchar
#define TBL_SCWATERSUSPEND_FLD_FIELDIMAGE		"FieldImage"		// 野外照片(视频)		varchar
#define TBL_SCWATERSUSPEND_FLD_RECORDCARD		"RecordCard"		// 记录卡片(记录)		varchar
#define TBL_SCWATERSUSPEND_FLD_SAMPLEORGN		"SampleOrgn"		// 采样单位			varchar
#define TBL_SCWATERSUSPEND_FLD_SWFOMW			"SWFOMW"			// 采样人			varchar
#define TBL_SCWATERSUSPEND_FLD_GCEABJ			"GCEABJ"			// 采样日期			date
#define TBL_SCWATERSUSPEND_FLD_INPUTER			"Inputer"			// 录入员			varchar
#define TBL_SCWATERSUSPEND_FLD_INPUTORGN		"InputOrgn"			// 录入单位			varchar
#define TBL_SCWATERSUSPEND_FLD_INPUTDATE		"InputDate"			// 录入日期			date

//动植物样品基本情况表
#define TBL_SCANIMALPLANT_TBL "SCAnimalPlant"
#define TBL_SCANIMALPLANT_FLD_ANIMALSAMPID		"AnimalSampID"		//* 动(植)样ID		int
#define TBL_SCANIMALPLANT_FLD_ANIPLANTTYPE		"AniPlantType"		// 动(植)物类型		varchar
#define TBL_SCANIMALPLANT_FLD_ANIPLANTNAME		"AniPlantName"		// 动(植)物名称		varchar
#define TBL_SCANIMALPLANT_FLD_SAMPLESITE		"SampleSite"		// 采样部位			varchar
#define TBL_SCANIMALPLANT_FLD_SAMPLECOLOR		"SampleColor"		// 样品颜色			varchar
#define TBL_SCANIMALPLANT_FLD__STORAGE			"_Storage"			// 样品储存			varchar
#define TBL_SCANIMALPLANT_FLD__PROCESS			"_Process"			// 样品加工			varchar
#define TBL_SCANIMALPLANT_FLD_GCKBBA			"GCKBBA"			// 地貌				varchar
#define TBL_SCANIMALPLANT_FLD_SOILCAUSETYPE		"SoilCauseType"		// 土壤成因类型		varchar
#define TBL_SCANIMALPLANT_FLD__MEMO				"_Memo"				// 备注				varchar
// from 样品信息表 *
#define TBL_SCANIMALPLANT_FLD_GCEABB			"GCEABB"			// 样品编号			varchar
#define TBL_SCANIMALPLANT_FLD_PNTID				UNION_MACRO_PNT_ID  //* 点ID				int		FK
#define TBL_SCANIMALPLANT_FLD_SWBCF				"SWBCF"				// 样品类型			varchar
#define TBL_SCANIMALPLANT_FLD_ISMIXSAMPLE		"IsMixSample"		// 混合样			varchar
#define TBL_SCANIMALPLANT_FLD_PNTTYPE			"PntType"			// 点类型			varchar
#define TBL_SCANIMALPLANT_FLD_SECONDCODE		"SecondCode"		// 样品二次编码		varchar
#define TBL_SCANIMALPLANT_FLD_SAMPLEVOLUME		"SampleVolume"		// 样品体积			float
#define TBL_SCANIMALPLANT_FLD_GCEABM			"GCEABM"			// 野外命名			varchar
#define TBL_SCANIMALPLANT_FLD_GCEAAL			"GCEAAL"			// 样品重量(kg)		float
#define TBL_SCANIMALPLANT_FLD_SAMPLELENGTH		"SampleLength"		// 样品长度(cm)		varchar
#define TBL_SCANIMALPLANT_FLD_PRETREATMETHOD	"PretreatMethod"	// 预处理方法		varchar
#define TBL_SCANIMALPLANT_FLD_TESTCONTENT		"TestContent"		// 测试内容			varchar
#define TBL_SCANIMALPLANT_FLD_PLANEPOSMAP		"PlanePosMap"		// 平面位置示意图		varchar
#define TBL_SCANIMALPLANT_FLD_PROFILEMAP		"ProfileMap"		// 剖面示意图		varchar
#define TBL_SCANIMALPLANT_FLD_FIELDIMAGE		"FieldImage"		// 野外照片(视频)		varchar
#define TBL_SCANIMALPLANT_FLD_RECORDCARD		"RecordCard"		// 记录卡片(记录)		varchar
#define TBL_SCANIMALPLANT_FLD_SAMPLEORGN		"SampleOrgn"		// 采样单位			varchar
#define TBL_SCANIMALPLANT_FLD_SWFOMW			"SWFOMW"			// 采样人			varchar
#define TBL_SCANIMALPLANT_FLD_GCEABJ			"GCEABJ"			// 采样日期			date
#define TBL_SCANIMALPLANT_FLD_INPUTER			"Inputer"			// 录入员			varchar
#define TBL_SCANIMALPLANT_FLD_INPUTORGN			"InputOrgn"			// 录入单位			varchar
#define TBL_SCANIMALPLANT_FLD_INPUTDATE			"InputDate"			// 录入日期			date

/*------------------------------------------室内力学测试类---------------------------------------------*/
#define INWATERSUSPEND_MDL_CLASS "室内力学测试表类"
	//岩石物理力学实验成果表 -- LH.2021.08.31 changed.
#define TBL_INROCKPHYSICS_TBL "INRockPhysics"
#define TBL_INROCKPHYSICS_FLD_ROCKTESTID		"RockTestID"				//* 岩石试验ID				int PK
#define TBL_INROCKPHYSICS_FLD_SWFGAA			UNION_MACRO_TCDH			//* 采样层位			varchar
#define TBL_INROCKPHYSICS_FLD_TOPDEPTH			UNION_MACRO_START_DEPTH		//* 取样顶深度		float
#define TBL_INROCKPHYSICS_FLD_BOTTOMDEPTH		UNION_MACRO_END_DEPTH		//* 取样底深度		float
#define TBL_INROCKPHYSICS_FLD_PNTID				UNION_MACRO_PNT_ID			//* 点ID				int		FK
#define TBL_INROCKPHYSICS_FLD_TCMC			UNION_MACRO_TCMC			// 土层名称		varchar 
#define TBL_INROCKPHYSICS_FLD_GEOCODE			UNION_MACRO_GEOCODE			// 地质代号			varchar
#define TBL_INROCKPHYSICS_FLD_TESTNO			UNION_MACRO_TESTNO			//	试验编号			varchar
#define TBL_INROCKPHYSICS_FLD_TESTCATEGORY		UNION_MACRO_TESTTYPE		//  试验类型			varchar
#define TBL_INROCKPHYSICS_FLD_GCBHKY			"GCBHKY"			// 饱和抗压强度(MPa)		float
#define TBL_INROCKPHYSICS_FLD_GCGZKY			"GCGZKY"			// 干燥抗压强度(MPa)		float
#define TBL_INROCKPHYSICS_FLD__SATURATED		"_Saturated"		// 饱和抗拉强度(MPa)		float
#define TBL_INROCKPHYSICS_FLD__DRY				"_dry"				// 干燥抗拉强度(MPa)		float
#define TBL_INROCKPHYSICS_FLD_GCCBG				"GCCBG"				// 软化系数					float
#define TBL_INROCKPHYSICS_FLD_GCBFOA			"GCBFOA"			// 内聚力(MPa)				float
#define TBL_INROCKPHYSICS_FLD_GCDMAC			"GCDMAC"			// 内摩擦角(度)				float
#define TBL_INROCKPHYSICS_FLD_MAXIMUMSTRESS		"MaximumStress"		// 最大正应力(MPa)			float
#define TBL_INROCKPHYSICS_FLD_GCDKBB			"GCDKBB"			// 弹性模量(MPa)			float
#define TBL_INROCKPHYSICS_FLD_GCDLAH			"GCDLAH"			// 泊松比					float
#define TBL_INROCKPHYSICS_FLD_BLOCKDENSITY		"BlockDensity"		// 块体密度(g/cm3)			float
#define TBL_INROCKPHYSICS_FLD_GCDAO				"GCDAO"				// 颗粒密度(g/cm3)			float
#define TBL_INROCKPHYSICS_FLD_GCDBB				"GCDBB"				// 孔隙率(%)				float
#define TBL_INROCKPHYSICS_FLD_SATWATERRATE		"SatWaterRate"		// 饱和吸水率(%)			float
// from 样品信息表 *
#define TBL_INROCKPHYSICS_FLD_GCEABB			"GCEABB"			// 样品编号			varchar
#define TBL_INROCKPHYSICS_FLD_SWBCF				"SWBCF"				// 样品类型			varchar
#define TBL_INROCKPHYSICS_FLD_ISMIXSAMPLE		"IsMixSample"		// 混合样			varchar
#define TBL_INROCKPHYSICS_FLD_PNTTYPE			"PntType"			// 点类型			varchar
#define TBL_INROCKPHYSICS_FLD_SECONDCODE		"SecondCode"		// 样品二次编码		varchar
#define TBL_INROCKPHYSICS_FLD_SAMPLEVOLUME		"SampleVolume"		// 样品体积			float
#define TBL_INROCKPHYSICS_FLD_GCEABM			"GCEABM"			// 野外命名			varchar
#define TBL_INROCKPHYSICS_FLD_GCEAAL			"GCEAAL"			// 样品重量(kg)		float
#define TBL_INROCKPHYSICS_FLD_SAMPLELENGTH		"SampleLength"		// 样品长度(cm)		varchar
#define TBL_INROCKPHYSICS_FLD_PRETREATMETHOD	"PretreatMethod"	// 预处理方法		varchar
#define TBL_INROCKPHYSICS_FLD_TESTCONTENT		"TestContent"		// 测试内容			varchar
#define TBL_INROCKPHYSICS_FLD_PLANEPOSMAP		"PlanePosMap"		// 平面位置示意图		varchar
#define TBL_INROCKPHYSICS_FLD_PROFILEMAP		"ProfileMap"		// 剖面示意图		varchar
#define TBL_INROCKPHYSICS_FLD_FIELDIMAGE		"FieldImage"		// 野外照片(视频)		varchar
#define TBL_INROCKPHYSICS_FLD_RECORDCARD		"RecordCard"		// 记录卡片(记录)		varchar
#define TBL_INROCKPHYSICS_FLD_SAMPLEORGN		"SampleOrgn"		// 采样单位			varchar
#define TBL_INROCKPHYSICS_FLD_SWFOMW			"SWFOMW"			// 采样人			varchar
#define TBL_INROCKPHYSICS_FLD_GCEABJ			"GCEABJ"			// 采样日期			date
#define TBL_INROCKPHYSICS_FLD_INPUTER			"Inputer"			// 录入员			varchar
#define TBL_INROCKPHYSICS_FLD_INPUTORGN			"InputOrgn"			// 录入单位			varchar
#define TBL_INROCKPHYSICS_FLD_INPUTDATE			"InputDate"			// 录入日期			date
// from 室内测试分析基本情况表
#define TBL_INROCKPHYSICS_FLD_GCEABD			"GCEABD"			// 室内编号				varchar
#define TBL_INROCKPHYSICS_FLD_TESTEQUIP			"TestEquip"			// 试验仪器				varchar
#define TBL_INROCKPHYSICS_FLD_TESTMETHOD		"TestMethod"		// 试验方法				varchar
#define TBL_INROCKPHYSICS_FLD_TESTBASED			"TestBased"			// 检验依据				varchar
#define TBL_INROCKPHYSICS_FLD_GCEAJC			"GCEAJC"			// 试验单位				varchar
#define TBL_INROCKPHYSICS_FLD_SWFGAM			"SWFGAM"			// 收样日期				date
#define TBL_INROCKPHYSICS_FLD_SWFGAN			"SWFGAN"			// 报告日期				date
#define TBL_INROCKPHYSICS_FLD_GCEAJD			"GCEAJD"			// 校对					varchar
#define TBL_INROCKPHYSICS_FLD_AUDITOR			"Auditor"			// 审核					varchar
#define TBL_INROCKPHYSICS_FLD_TESTLEADER		"TestLeader"		// 试验负责人			varchar
#define TBL_INROCKPHYSICS_FLD__REPORT			"_Report"			// 原始测试分析报告		varchar


//常规土工实验成果表 -- LH.2021.08.31 changed.
#define TBL_INGEOTECHNICALEXP_TBL "INGeotechnicalExp"
#define TBL_INGEOTECHNICALEXP_FLD_GEOTECHNICALID		"GeotechnicalID"			//* 土工ID						int PK
#define TBL_INGEOTECHNICALEXP_FLD_TOPDEPTH				UNION_MACRO_START_DEPTH		//* 取样顶深度		float
#define TBL_INGEOTECHNICALEXP_FLD_BOTTOMDEPTH			UNION_MACRO_END_DEPTH		//* 取样底深度		float
#define TBL_INGEOTECHNICALEXP_FLD_PNTID					UNION_MACRO_PNT_ID			//* 点ID				int
#define TBL_INGEOTECHNICALEXP_FLD_SWFGAA				UNION_MACRO_TCDH			//* 采样层位			varchar
#define TBL_INGEOTECHNICALEXP_FLD_TCMC					UNION_MACRO_TCMC			// 土层名称						varchar
#define TBL_INGEOTECHNICALEXP_FLD_GEOCODE				UNION_MACRO_GEOCODE			// 地质代号						varchar
#define TBL_INGEOTECHNICALEXP_FLD_TESTNO				UNION_MACRO_TESTNO			//	试验编号			varchar
#define TBL_INGEOTECHNICALEXP_FLD_TESTCATEGORY			UNION_MACRO_TESTTYPE		//  试验类型			varchar
#define TBL_INGEOTECHNICALEXP_FLD_ZD					"ZD"					// 重度								float
#define TBL_INGEOTECHNICALEXP_FLD_GZD					"GZD"					// 干重度							float
#define TBL_INGEOTECHNICALEXP_FLD_GCDAL					"GCDAL"					// 湿密度(g/cm3)				float
#define TBL_INGEOTECHNICALEXP_FLD_GCDAE					"GCDAE"					// 干密度(g/cm3)				float
#define TBL_INGEOTECHNICALEXP_FLD_BZ					"BZ"					// 比重						float
#define TBL_INGEOTECHNICALEXP_FLD_GCDCAO				"GCDCAO"				// 含水率(%)					float
#define TBL_INGEOTECHNICALEXP_FLD_GCDBB					"GCDBB"					// 孔隙比						float
#define TBL_INGEOTECHNICALEXP_FLD_DHABCU				"DHABCU"				// 饱和度(%)					float
#define TBL_INGEOTECHNICALEXP_FLD_SOILGRAVITY			"SoilGravity"			// 土粒比重						float
#define TBL_INGEOTECHNICALEXP_FLD_GCDDD					"GCDDD"					// 液限(%)						float
#define TBL_INGEOTECHNICALEXP_FLD_GCDDC					"GCDDC"					// 塑限(%)						float
#define TBL_INGEOTECHNICALEXP_FLD_GCDDE					"GCDDE"					// 塑性指数						float
#define TBL_INGEOTECHNICALEXP_FLD_GCDDF					"GCDDF"					// 液性指数						float
#define TBL_INGEOTECHNICALEXP_FLD_CURECOEFFICIENT		"CureCoefficient"		// 曲率系数						float
#define TBL_INGEOTECHNICALEXP_FLD_GCKBCQ				"GCKBCQ"				// 不均匀系数					float
#define TBL_INGEOTECHNICALEXP_FLD_EFFECTPARTICLESIZE	"EffectParticleSize"	// 有效粒径(mm)					float
#define TBL_INGEOTECHNICALEXP_FLD_GCDLAC				"GCDLAC"				// 压缩系数(MPa-1)				float
#define TBL_INGEOTECHNICALEXP_FLD_XQGJYL				"XQGJYL"				// 先期固结压力				float
#define TBL_INGEOTECHNICALEXP_FLD_YSZS					"YSZS"					// 压缩指数				float		
#define TBL_INGEOTECHNICALEXP_FLD_HTZS					"HTZS"					// 回弹指数				float		
#define TBL_INGEOTECHNICALEXP_FLD_						"GCBFOA"				// （天然快剪）粘聚力(kPa)					float
#define TBL_INGEOTECHNICALEXP_FLD_GCDMAC				"GCDMAC"				// （天然快剪）内摩擦角(度)					float
#define TBL_INGEOTECHNICALEXP_FLD_GJKJNJL				"GJKJNJL"				// 固结快剪粘聚力				float
#define TBL_INGEOTECHNICALEXP_FLD_GJKJNMCJ				"GJKJNMCJ"				// 固结快剪内摩擦角				float
#define TBL_INGEOTECHNICALEXP_FLD_MJNJL					"MJNJL"		 			// 慢剪粘聚力						float
#define TBL_INGEOTECHNICALEXP_FLD_MJNMCJ				"MJNMCJ"				// 慢剪内摩擦角						float
#define TBL_INGEOTECHNICALEXP_FLD_GCDEAF				"GCDEAF"				// 自由膨胀率(%)				float
#define TBL_INGEOTECHNICALEXP_FLD_TOC					"TOC"					// 有机质含量(%)				float
#define TBL_INGEOTECHNICALEXP_FLD_FINEGRAINED			"FineGrained"			// 细粒土含水率(%)				float
#define TBL_INGEOTECHNICALEXP_FLD_SWGGAC				"SWGGAC"				// 垂向渗透系数(cm/s)			float
#define TBL_INGEOTECHNICALEXP_FLD_SWGGAB				"SWGGAB"				// 水平渗透系数(cm/s)			float
#define TBL_INGEOTECHNICALEXP_FLD_UNDERWATERANGLE		"UnderWaterAngle"		// 水下休止角(坡角)(度)			float
#define TBL_INGEOTECHNICALEXP_FLD_UPWATERANGLE			"UpWaterAngle"			// 水上休止角坡角(度)			float
#define TBL_INGEOTECHNICALEXP_FLD_YZ					"YZ"					// 原状(QU)			float
#define TBL_INGEOTECHNICALEXP_FLD_CS					"CS"					// 重塑(QU_)			float
#define TBL_INGEOTECHNICALEXP_FLD_LMD					"LMD"					// 灵敏度			float
#define TBL_INGEOTECHNICALEXP_FLD_QT1					"QT1"					// 液限（100g锥）			float
#define TBL_INGEOTECHNICALEXP_FLD_QT2					"QT2"					// 塑性（100g锥）			float
#define TBL_INGEOTECHNICALEXP_FLD_SZUUNJL					"SZUUNJL"				// 三轴UU法粘聚力©			float
#define TBL_INGEOTECHNICALEXP_FLD_SZUUNMCJ					"SZUUNMCJ"				// 三轴UU法内摩擦角(Φ)			float
#define TBL_INGEOTECHNICALEXP_FLD_SZUUNJL_					"SZUUNJL_"				// 三轴UU法粘聚力(C1)			float
#define TBL_INGEOTECHNICALEXP_FLD_SZCUNJL					"SZCUNJL"				// 三轴CU法粘聚力(C)			float
#define TBL_INGEOTECHNICALEXP_FLD_SZCUNMCJ					"SZCUNMCJ"				// 三轴CU法内摩擦角(Φ)			float
#define TBL_INGEOTECHNICALEXP_FLD_SZCUNJL_					"SZCUNJL_"				// 三轴CU法粘聚力(C_)			float
#define TBL_INGEOTECHNICALEXP_FLD_SZCUNMCJ_					"SZCUNMCJ_"				// 三轴CU法内摩擦角(Φ_)			float
#define TBL_INGEOTECHNICALEXP_FLD_GCDKBD1				"GCDKBD1"				// 压缩模量1(MPa)				float
#define TBL_INGEOTECHNICALEXP_FLD_GCDKBD2				"GCDKBD2"				// 压缩模量2(MPa)				float
#define TBL_INGEOTECHNICALEXP_FLD_GCDKBD3				"GCDKBD3"				// 压缩模量3(MPa)				float
#define TBL_INGEOTECHNICALEXP_FLD_GCDKBD4				"GCDKBD4"				// 压缩模量4(MPa)				float
#define TBL_INGEOTECHNICALEXP_FLD_GCDKBD5				"GCDKBD5"				// 压缩模量5(MPa)				float
#define TBL_INGEOTECHNICALEXP_FLD_GCDKBD6				"GCDKBD6"				// 压缩模量6(MPa)				float
#define TBL_INGEOTECHNICALEXP_FLD_GCDKBD7				"GCDKBD7"				// 压缩模量7(MPa)				float
#define TBL_INGEOTECHNICALEXP_FLD_GCDKBD8				"GCDKBD8"				// 压缩模量8(MPa)				float
#define TBL_INGEOTECHNICALEXP_FLD_GCDKBD9				"GCDKBD9"				// 压缩模量9(MPa)				float
#define TBL_INGEOTECHNICALEXP_FLD_GCDKBD10				"GCDKBD10"				// 压缩模量10(MPa)				float
#define TBL_INGEOTECHNICALEXP_FLD_GJXS1					"GJXS1"					// 固结系数1(KPa)				float
#define TBL_INGEOTECHNICALEXP_FLD_GJXS2					"GJXS2"					// 固结系数2(KPa)				float
#define TBL_INGEOTECHNICALEXP_FLD_GJXS3					"GJXS3"					// 固结系数3(KPa)				float
#define TBL_INGEOTECHNICALEXP_FLD_GJXS4					"GJXS4"					// 固结系数4(KPa)				float
#define TBL_INGEOTECHNICALEXP_FLD_GJXS5					"GJXS5"					// 固结系数5(KPa)				float
#define TBL_INGEOTECHNICALEXP_FLD_GJXS6					"GJXS6"					// 固结系数6(KPa)				float
#define TBL_INGEOTECHNICALEXP_FLD_GJXS7					"GJXS7"					// 固结系数7(KPa)				float
#define TBL_INGEOTECHNICALEXP_FLD_GJXS8					"GJXS8"					// 固结系数8(KPa)				float
#define TBL_INGEOTECHNICALEXP_FLD_GJXS9					"GJXS9"					// 固结系数9(KPa)				float
#define TBL_INGEOTECHNICALEXP_FLD_GJXS10				"GJXS10"				// 固结系数10(KPa)				float
#define TBL_INGEOTECHNICALEXP_FLD_KLZC1					"KLZC1"					// 颗粒组成1(%)			float
#define TBL_INGEOTECHNICALEXP_FLD_KLZC2					"KLZC2"					// 颗粒组成2(%)					float
#define TBL_INGEOTECHNICALEXP_FLD_KLZC3					"KLZC3"					// 颗粒组成3(%)					float
#define TBL_INGEOTECHNICALEXP_FLD_KLZC4					"KLZC4"					// 颗粒组成4(%)					float
#define TBL_INGEOTECHNICALEXP_FLD_KLZC5					"KLZC5"					// 颗粒组成5(%)					float
#define TBL_INGEOTECHNICALEXP_FLD_KLZC6					"KLZC6"					// 颗粒组成6(%)					float
#define TBL_INGEOTECHNICALEXP_FLD_KLZC7					"KLZC7"					// 颗粒组成7(%)					float
#define TBL_INGEOTECHNICALEXP_FLD_KLZC8					"KLZC8"					// 颗粒组成8(%)					float
#define TBL_INGEOTECHNICALEXP_FLD_KLZC9					"KLZC9"					// 颗粒组成9(%)					float
#define TBL_INGEOTECHNICALEXP_FLD_KLZC10				"KLZC10"				// 颗粒组成10(%)					float
#define TBL_INGEOTECHNICALEXP_FLD_KLZC11				"KLZC11"				// 颗粒组成11(%)					float
#define TBL_INGEOTECHNICALEXP_FLD_KLZC12				"KLZC12"				// 颗粒组成12(%)					float
#define TBL_INGEOTECHNICALEXP_FLD_KLZC13				"KLZC13"				// 颗粒组成13(%)					float
#define TBL_INGEOTECHNICALEXP_FLD_KLZC14				"KLZC14"				// 颗粒组成14(%)					float
#define TBL_INGEOTECHNICALEXP_FLD_KLZC15				"KLZC15"				// 颗粒组成15(%)					float
// from 样品信息表 *
#define TBL_INGEOTECHNICALEXP_FLD_GCEABB				"GCEABB"			// 样品编号			varchar
#define TBL_INGEOTECHNICALEXP_FLD_SWBCF					"SWBCF"				// 样品类型			varchar
#define TBL_INGEOTECHNICALEXP_FLD_ISMIXSAMPLE			"IsMixSample"		// 混合样			varchar
#define TBL_INGEOTECHNICALEXP_FLD_PNTTYPE				"PntType"			// 点类型			varchar
#define TBL_INGEOTECHNICALEXP_FLD_SECONDCODE			"SecondCode"		// 样品二次编码		varchar
#define TBL_INGEOTECHNICALEXP_FLD_SAMPLEVOLUME			"SampleVolume"		// 样品体积			float
#define TBL_INGEOTECHNICALEXP_FLD_GCEABM				"GCEABM"			// 野外命名			varchar
#define TBL_INGEOTECHNICALEXP_FLD_GCEAAL				"GCEAAL"			// 样品重量(kg)		float
#define TBL_INGEOTECHNICALEXP_FLD_SAMPLELENGTH			"SampleLength"		// 样品长度(cm)		varchar
#define TBL_INGEOTECHNICALEXP_FLD_PRETREATMETHOD		"PretreatMethod"	// 预处理方法		varchar
#define TBL_INGEOTECHNICALEXP_FLD_TESTCONTENT			"TestContent"		// 测试内容			varchar
#define TBL_INGEOTECHNICALEXP_FLD_PLANEPOSMAP			"PlanePosMap"		// 平面位置示意图	varchar
#define TBL_INGEOTECHNICALEXP_FLD_PROFILEMAP			"ProfileMap"		// 剖面示意图		varchar
#define TBL_INGEOTECHNICALEXP_FLD_FIELDIMAGE			"FieldImage"		// 野外照片(视频)	varchar
#define TBL_INGEOTECHNICALEXP_FLD_RECORDCARD			"RecordCard"		// 记录卡片(记录)	varchar
#define TBL_INGEOTECHNICALEXP_FLD_SAMPLEORGN			"SampleOrgn"		// 采样单位			varchar
#define TBL_INGEOTECHNICALEXP_FLD_SWFOMW				"SWFOMW"			// 采样人			varchar
#define TBL_INGEOTECHNICALEXP_FLD_GCEABJ				"GCEABJ"			// 采样日期			date
#define TBL_INGEOTECHNICALEXP_FLD_INPUTER				"Inputer"			// 录入员			varchar
#define TBL_INGEOTECHNICALEXP_FLD_INPUTORGN				"InputOrgn"			// 录入单位			varchar
#define TBL_INGEOTECHNICALEXP_FLD_INPUTDATE				"InputDate"			// 录入日期			date	
// from 室内测试分析基本情况表
#define TBL_INGEOTECHNICALEXP_FLD_GCEABD				"GCEABD"				// 室内编号				varchar
#define TBL_INGEOTECHNICALEXP_FLD_GCEABL				"GCEABL"				// 室内名称						varchar
#define TBL_INGEOTECHNICALEXP_FLD_TESTEQUIP				"TestEquip"				// 试验仪器				varchar
#define TBL_INGEOTECHNICALEXP_FLD_TESTMETHOD			"TestMethod"			// 试验方法				varchar
#define TBL_INGEOTECHNICALEXP_FLD_TESTBASED				"TestBased"				// 检验依据				varchar
#define TBL_INGEOTECHNICALEXP_FLD_GCEAJC				"GCEAJC"				// 试验单位				varchar
#define TBL_INGEOTECHNICALEXP_FLD_SWFGAM				"SWFGAM"				// 收样日期				date
#define TBL_INGEOTECHNICALEXP_FLD_SWFGAN				"SWFGAN"				// 报告日期				date
#define TBL_INGEOTECHNICALEXP_FLD_GCEAJD				"GCEAJD"				// 校对					varchar
#define TBL_INGEOTECHNICALEXP_FLD_AUDITOR				"Auditor"				// 审核					varchar
#define TBL_INGEOTECHNICALEXP_FLD_TESTLEADER			"TestLeader"			// 试验负责人			varchar
#define TBL_INGEOTECHNICALEXP_FLD__REPORT				"_Report"				// 原始测试分析报告		varchar	


//高压固结实验成果表 -- LH.2021.08.31 changed.
#define TBL_INCONSOLIDATL_TBL "INConsolidatl"
#define TBL_INCONSOLIDATL_FLD_CONSOLIDATID			"ConsolidatID"				//* 高压固结ID					int
#define TBL_INCONSOLIDATL_FLD_TOPDEPTH				UNION_MACRO_START_DEPTH		//* 取样顶深度		float
#define TBL_INCONSOLIDATL_FLD_BOTTOMDEPTH			UNION_MACRO_END_DEPTH		//* 取样底深度		float
#define TBL_INCONSOLIDATL_FLD_PNTID					UNION_MACRO_PNT_ID			//* 点ID				int
#define TBL_INCONSOLIDATL_FLD_SWFGAA				UNION_MACRO_TCDH			//* 采样层位			varchar
#define TBL_INCONSOLIDATL_FLD_TCMC					UNION_MACRO_TCMC			//  土层名称						varchar
#define TBL_INCONSOLIDATL_FLD_GEOCODE				UNION_MACRO_GEOCODE			//  地质代号						varchar
#define TBL_INCONSOLIDATL_FLD_TESTNO				UNION_MACRO_TESTNO			//	试验编号			varchar
#define TBL_INCONSOLIDATL_FLD_TESTCATEGORY			UNION_MACRO_TESTTYPE		//  试验类型			varchar
#define TBL_INCONSOLIDATL_FLD_GCDLAF				"GCDLAF"					// 先期固结压力(kPa)				float
#define TBL_INCONSOLIDATL_FLD_COMPRESSINDEX			"CompressIndex"				// 压缩指数						float
#define TBL_INCONSOLIDATL_FLD_REBOUNDINDEX			"ReboundIndex"				// 回弹指数						float
// from 固结系数测试成果表 *
#define TBL_INCONSOLIDATL_FLD_CONSOLIDATPRESSURE	"ConsolidatPressure"		// 固结压力(kPa)				float
#define TBL_INCONSOLIDATL_FLD_GCDBB					"GCDBB"						// 孔隙比						float
#define TBL_INCONSOLIDATL_FLD_GCDKBD				"GCDKBD"					// 压缩模量						float
#define TBL_INCONSOLIDATL_FLD_GCDLAC				"GCDLAC"					// 压缩系数						float
#define TBL_INCONSOLIDATL_FLD_VERTICALCONSOLIDAT	"VerticalConsolidat"		// 竖向固结系数					float
#define TBL_INCONSOLIDATL_FLD_HORIZONTALCONSOLIDAT	"HorizontalConsolidat"		// 水平固结系数					float
// from 样品信息表 *
#define TBL_INCONSOLIDATL_FLD_GCEABB				"GCEABB"			// 样品编号			varchar
#define TBL_INCONSOLIDATL_FLD_SWBCF					"SWBCF"				// 样品类型			varchar
#define TBL_INCONSOLIDATL_FLD_ISMIXSAMPLE			"IsMixSample"		// 混合样			varchar
#define TBL_INCONSOLIDATL_FLD_PNTTYPE				"PntType"			// 点类型			varchar
#define TBL_INCONSOLIDATL_FLD_SECONDCODE			"SecondCode"		// 样品二次编码		varchar
#define TBL_INCONSOLIDATL_FLD_SAMPLEVOLUME			"SampleVolume"		// 样品体积			float
#define TBL_INCONSOLIDATL_FLD_GCEABM				"GCEABM"			// 野外命名			varchar
#define TBL_INCONSOLIDATL_FLD_GCEAAL				"GCEAAL"			// 样品重量(kg)		float
#define TBL_INCONSOLIDATL_FLD_SAMPLELENGTH			"SampleLength"		// 样品长度(cm)		varchar
#define TBL_INCONSOLIDATL_FLD_PRETREATMETHOD		"PretreatMethod"	// 预处理方法		varchar
#define TBL_INCONSOLIDATL_FLD_TESTCONTENT			"TestContent"		// 测试内容			varchar
#define TBL_INCONSOLIDATL_FLD_PLANEPOSMAP			"PlanePosMap"		// 平面位置示意图	varchar
#define TBL_INCONSOLIDATL_FLD_PROFILEMAP			"ProfileMap"		// 剖面示意图		varchar
#define TBL_INCONSOLIDATL_FLD_FIELDIMAGE			"FieldImage"		// 野外照片(视频)	varchar
#define TBL_INCONSOLIDATL_FLD_RECORDCARD			"RecordCard"		// 记录卡片(记录)	varchar
#define TBL_INCONSOLIDATL_FLD_SAMPLEORGN			"SampleOrgn"		// 采样单位			varchar
#define TBL_INCONSOLIDATL_FLD_SWFOMW				"SWFOMW"			// 采样人			varchar
#define TBL_INCONSOLIDATL_FLD_GCEABJ				"GCEABJ"			// 采样日期			date
#define TBL_INCONSOLIDATL_FLD_INPUTER				"Inputer"			// 录入员			varchar
#define TBL_INCONSOLIDATL_FLD_INPUTORGN				"InputOrgn"			// 录入单位			varchar
#define TBL_INCONSOLIDATL_FLD_INPUTDATE				"InputDate"			// 录入日期			date
// from 室内测试分析基本情况表
#define TBL_INCONSOLIDATL_FLD_GCEABD			"GCEABD"			// 室内编号				varchar
#define TBL_INCONSOLIDATL_FLD_TESTEQUIP			"TestEquip"			// 试验仪器				varchar
#define TBL_INCONSOLIDATL_FLD_TESTMETHOD		"TestMethod"		// 试验方法				varchar
#define TBL_INCONSOLIDATL_FLD_TESTBASED			"TestBased"			// 检验依据				varchar
#define TBL_INCONSOLIDATL_FLD_GCEAJC			"GCEAJC"			// 试验单位				varchar
#define TBL_INCONSOLIDATL_FLD_SWFGAM			"SWFGAM"			// 收样日期				date
#define TBL_INCONSOLIDATL_FLD_SWFGAN			"SWFGAN"			// 报告日期				date
#define TBL_INCONSOLIDATL_FLD_GCEAJD			"GCEAJD"			// 校对					varchar
#define TBL_INCONSOLIDATL_FLD_AUDITOR			"Auditor"			// 审核					varchar
#define TBL_INCONSOLIDATL_FLD_TESTLEADER		"TestLeader"		// 试验负责人			varchar
#define TBL_INCONSOLIDATL_FLD__REPORT			"_Report"			// 原始测试分析报告		varchar



//无侧限压缩试验成果表 -- LH.2021.08.31 changed.
#define TBL_INUNCONFINED_TBL "INUnconfined"
#define TBL_INUNCONFINED_FLD_UNCONFINEDID				"UnconfinedID"			//* 无侧限ID			int
#define TBL_INUNCONFINED_FLD_TOPDEPTH					UNION_MACRO_START_DEPTH		//* 取样顶深度		float
#define TBL_INUNCONFINED_FLD_BOTTOMDEPTH				UNION_MACRO_END_DEPTH		//* 取样底深度		float
#define TBL_INUNCONFINED_FLD_PNTID						UNION_MACRO_PNT_ID			//* 点ID				int
#define TBL_INUNCONFINED_FLD_SWFGAA						UNION_MACRO_TCDH			//* 采样层位			varchar
#define TBL_INUNCONFINED_FLD_TCMC						UNION_MACRO_TCMC			//  土层名称			varchar
#define TBL_INUNCONFINED_FLD_GEOCODE					UNION_MACRO_GEOCODE			//  地质代号			varchar
#define TBL_INUNCONFINED_FLD_TESTNO						UNION_MACRO_TESTNO			//	试验编号			varchar
#define TBL_INUNCONFINED_FLD_TESTCATEGORY				UNION_MACRO_TESTTYPE		//  试验类型			varchar
#define TBL_INUNCONFINED_FLD_GCDMAM						"GCDMAM"				// 原状土无侧限抗压强度(kPa)	float
#define TBL_INUNCONFINED_FLD_GCDMAO						"GCDMAO"				// 重塑土无侧限抗压强度(kPa)	float
#define TBL_INUNCONFINED_FLD_GCDKCR						"GCDKCR"				// 不排水抗剪强度(kPa)			float
#define TBL_INUNCONFINED_FLD_GCBFI						"GCBFI"					// 灵敏度						float
// from 样品信息表
#define TBL_INUNCONFINED_FLD_GCEABB					"GCEABB"			// 样品编号			varchar
#define TBL_INUNCONFINED_FLD_SWBCF					"SWBCF"				// 样品类型			varchar
#define TBL_INUNCONFINED_FLD_ISMIXSAMPLE			"IsMixSample"		// 混合样			varchar
#define TBL_INUNCONFINED_FLD_PNTTYPE				"PntType"			// 点类型			varchar
#define TBL_INUNCONFINED_FLD_SECONDCODE				"SecondCode"		// 样品二次编码		varchar
#define TBL_INUNCONFINED_FLD_SAMPLEVOLUME			"SampleVolume"		// 样品体积			float
#define TBL_INUNCONFINED_FLD_GCEABM					"GCEABM"			// 野外命名			varchar
#define TBL_INUNCONFINED_FLD_GCEAAL					"GCEAAL"			// 样品重量(kg)		float
#define TBL_INUNCONFINED_FLD_SAMPLELENGTH			"SampleLength"		// 样品长度(cm)		varchar
#define TBL_INUNCONFINED_FLD_PRETREATMETHOD			"PretreatMethod"	// 预处理方法		varchar
#define TBL_INUNCONFINED_FLD_TESTCONTENT			"TestContent"		// 测试内容			varchar
#define TBL_INUNCONFINED_FLD_PLANEPOSMAP			"PlanePosMap"		// 平面位置示意图	varchar
#define TBL_INUNCONFINED_FLD_PROFILEMAP				"ProfileMap"		// 剖面示意图		varchar
#define TBL_INUNCONFINED_FLD_FIELDIMAGE				"FieldImage"		// 野外照片(视频)	varchar
#define TBL_INUNCONFINED_FLD_RECORDCARD				"RecordCard"		// 记录卡片(记录)	varchar
#define TBL_INUNCONFINED_FLD_SAMPLEORGN				"SampleOrgn"		// 采样单位			varchar
#define TBL_INUNCONFINED_FLD_SWFOMW					"SWFOMW"			// 采样人			varchar
#define TBL_INUNCONFINED_FLD_GCEABJ					"GCEABJ"			// 采样日期			date
#define TBL_INUNCONFINED_FLD_INPUTER				"Inputer"			// 录入员			varchar
#define TBL_INUNCONFINED_FLD_INPUTORGN				"InputOrgn"			// 录入单位			varchar
#define TBL_INUNCONFINED_FLD_INPUTDATE				"InputDate"			// 录入日期			date
// from 室内测试分析基本情况表
#define TBL_INUNCONFINED_FLD_GCEABD						"GCEABD"				// 室内编号				varchar
#define TBL_INUNCONFINED_FLD_TESTEQUIP					"TestEquip"				// 试验仪器				varchar
#define TBL_INUNCONFINED_FLD_TESTMETHOD					"TestMethod"			// 试验方法				varchar
#define TBL_INUNCONFINED_FLD_TESTBASED					"TestBased"				// 检验依据				varchar
#define TBL_INUNCONFINED_FLD_GCEAJC						"GCEAJC"				// 试验单位				varchar
#define TBL_INUNCONFINED_FLD_SWFGAM						"SWFGAM"				// 收样日期				date
#define TBL_INUNCONFINED_FLD_SWFGAN						"SWFGAN"				// 报告日期				date
#define TBL_INUNCONFINED_FLD_GCEAJD						"GCEAJD"				// 校对					varchar
#define TBL_INUNCONFINED_FLD_AUDITOR					"Auditor"				// 审核					varchar
#define TBL_INUNCONFINED_FLD_TESTLEADER					"TestLeader"			// 试验负责人			varchar
#define TBL_INUNCONFINED_FLD__REPORT					"_Report"				// 原始测试分析报告		varchar



//三轴实验成果表 -- LH.2021.08.31 changed.
#define TBL_INTHREEAXIS_TBL "INThreeaxis"
#define TBL_INTHREEAXIS_FLD_THREEAXISID				"ThreeaxisID"				//* 三轴ID						int
#define TBL_INTHREEAXIS_FLD_TOPDEPTH				UNION_MACRO_START_DEPTH		//* 取样顶深度		float
#define TBL_INTHREEAXIS_FLD_BOTTOMDEPTH				UNION_MACRO_END_DEPTH		//* 取样底深度		float
#define TBL_INTHREEAXIS_FLD_PNTID					UNION_MACRO_PNT_ID			//* 点ID				int
#define TBL_INTHREEAXIS_FLD_SWFGAA					UNION_MACRO_TCDH			//* 采样层位			varchar
#define TBL_INTHREEAXIS_FLD_TCMC					UNION_MACRO_TCMC			//  土层名称			varchar
#define TBL_INTHREEAXIS_FLD_GEOCODE					UNION_MACRO_GEOCODE			//  地质代号			varchar
#define TBL_INTHREEAXIS_FLD_TESTNO					UNION_MACRO_TESTNO			//	试验编号			varchar
#define TBL_INTHREEAXIS_FLD_TESTCATEGORY			UNION_MACRO_TESTTYPE		//  试验类型			varchar
#define TBL_INTHREEAXIS_FLD_GCBFOA					"GCBFOA"				// 粘聚力(kPa)					float
#define TBL_INTHREEAXIS_FLD_FRICTIONANGLE			"FrictionAngle"			// 摩擦角(度)					float
#define TBL_INTHREEAXIS_FLD_EFFECTCOHES				"EffectCohes"			// 有效粘聚力(kPa)				float
#define TBL_INTHREEAXIS_FLD_EFFECTFRICTANGLE		"EffectFrictAngle"		// 有效摩擦角(度)				float
// from 样品信息表 *
#define TBL_INTHREEAXIS_FLD_GCEABB					"GCEABB"			// 样品编号			varchar
#define TBL_INTHREEAXIS_FLD_SWBCF					"SWBCF"				// 样品类型			varchar
#define TBL_INTHREEAXIS_FLD_ISMIXSAMPLE				"IsMixSample"		// 混合样			varchar
#define TBL_INTHREEAXIS_FLD_PNTTYPE					"PntType"			// 点类型			varchar
#define TBL_INTHREEAXIS_FLD_SECONDCODE				"SecondCode"		// 样品二次编码		varchar
#define TBL_INTHREEAXIS_FLD_SAMPLEVOLUME			"SampleVolume"		// 样品体积			float
#define TBL_INTHREEAXIS_FLD_GCEABM					"GCEABM"			// 野外命名			varchar
#define TBL_INTHREEAXIS_FLD_GCEAAL					"GCEAAL"			// 样品重量(kg)		float
#define TBL_INTHREEAXIS_FLD_SAMPLELENGTH			"SampleLength"		// 样品长度(cm)		varchar
#define TBL_INTHREEAXIS_FLD_PRETREATMETHOD			"PretreatMethod"	// 预处理方法		varchar
#define TBL_INTHREEAXIS_FLD_TESTCONTENT				"TestContent"		// 测试内容			varchar
#define TBL_INTHREEAXIS_FLD_PLANEPOSMAP				"PlanePosMap"		// 平面位置示意图	varchar
#define TBL_INTHREEAXIS_FLD_PROFILEMAP				"ProfileMap"		// 剖面示意图		varchar
#define TBL_INTHREEAXIS_FLD_FIELDIMAGE				"FieldImage"		// 野外照片(视频)	varchar
#define TBL_INTHREEAXIS_FLD_RECORDCARD				"RecordCard"		// 记录卡片(记录)	varchar
#define TBL_INTHREEAXIS_FLD_SAMPLEORGN				"SampleOrgn"		// 采样单位			varchar
#define TBL_INTHREEAXIS_FLD_SWFOMW					"SWFOMW"			// 采样人			varchar
#define TBL_INTHREEAXIS_FLD_GCEABJ					"GCEABJ"			// 采样日期			date
#define TBL_INTHREEAXIS_FLD_INPUTER					"Inputer"			// 录入员			varchar
#define TBL_INTHREEAXIS_FLD_INPUTORGN				"InputOrgn"			// 录入单位			varchar
#define TBL_INTHREEAXIS_FLD_INPUTDATE				"InputDate"			// 录入日期			date
// from 室内测试分析基本情况表
#define TBL_INTHREEAXIS_FLD_GCEABD					"GCEABD"				// 室内编号				varchar
#define TBL_INTHREEAXIS_FLD_TESTEQUIP				"TestEquip"				// 试验仪器				varchar
#define TBL_INTHREEAXIS_FLD_TESTMETHOD				"TestMethod"			// 试验方法				varchar
#define TBL_INTHREEAXIS_FLD_TESTBASED				"TestBased"				// 检验依据				varchar
#define TBL_INTHREEAXIS_FLD_GCEAJC					"GCEAJC"				// 试验单位				varchar
#define TBL_INTHREEAXIS_FLD_SWFGAM					"SWFGAM"				// 收样日期				date
#define TBL_INTHREEAXIS_FLD_SWFGAN					"SWFGAN"				// 报告日期				date
#define TBL_INTHREEAXIS_FLD_GCEAJD					"GCEAJD"				// 校对					varchar
#define TBL_INTHREEAXIS_FLD_AUDITOR					"Auditor"				// 审核					varchar
#define TBL_INTHREEAXIS_FLD_TESTLEADER				"TestLeader"			// 试验负责人			varchar
#define TBL_INTHREEAXIS_FLD__REPORT					"_Report"				// 原始测试分析报告		varchar



//直剪实验成果表 -- LH.2021.08.31 changed.
#define TBL_INDIRECTSHEAR_TBL "INDirectShear"
#define TBL_INDIRECTSHEAR_FLD_DIRECTSHEARID			"DirectShearID"			//* 直剪ID						int
#define TBL_INDIRECTSHEAR_FLD_TOPDEPTH				UNION_MACRO_START_DEPTH		//* 取样顶深度		float
#define TBL_INDIRECTSHEAR_FLD_BOTTOMDEPTH			UNION_MACRO_END_DEPTH		//* 取样底深度		float
#define TBL_INDIRECTSHEAR_FLD_PNTID					UNION_MACRO_PNT_ID			//* 点ID				int
#define TBL_INDIRECTSHEAR_FLD_SWFGAA				UNION_MACRO_TCDH			//* 采样层位			varchar
#define TBL_INDIRECTSHEAR_FLD_TCMC					UNION_MACRO_TCMC			//  土层名称			varchar
#define TBL_INDIRECTSHEAR_FLD_GEOCODE				UNION_MACRO_GEOCODE			//  地质代号			varchar
#define TBL_INDIRECTSHEAR_FLD_TESTNO				UNION_MACRO_TESTNO			//	试验编号			varchar
#define TBL_INDIRECTSHEAR_FLD_TESTCATEGORY			UNION_MACRO_TESTTYPE		//  试验类型			varchar
#define TBL_INDIRECTSHEAR_FLD_MAXVERTICALPRESS		"MaxVerticalPress"		// 最大垂直压力(kPa)			float
#define TBL_INDIRECTSHEAR_FLD_SHEER1				"Sheer1"				// 剪应力τ100(kPa)				float
#define TBL_INDIRECTSHEAR_FLD_SHEER2				"Sheer2"				// 剪应力τ200(kPa)				float
#define TBL_INDIRECTSHEAR_FLD_SHEER3				"Sheer3"				// 剪应力τ300(kPa)				float
#define TBL_INDIRECTSHEAR_FLD_SHEER4				"Sheer4"				// 剪应力τ400(kPa)				float
#define TBL_INDIRECTSHEAR_FLD_GCBFOA				"GCBFOA"				// 粘聚力(kPa)					float
#define TBL_INDIRECTSHEAR_FLD_GCDMAC				"GCDMAC"				// 内摩擦角(度)					float
// from 样品信息表 *
#define TBL_INDIRECTSHEAR_FLD_GCEABB					"GCEABB"			// 样品编号			varchar
#define TBL_INDIRECTSHEAR_FLD_SWBCF						"SWBCF"				// 样品类型			varchar
#define TBL_INDIRECTSHEAR_FLD_ISMIXSAMPLE				"IsMixSample"		// 混合样			varchar
#define TBL_INDIRECTSHEAR_FLD_PNTTYPE					"PntType"			// 点类型			varchar
#define TBL_INDIRECTSHEAR_FLD_SECONDCODE				"SecondCode"		// 样品二次编码		varchar
#define TBL_INDIRECTSHEAR_FLD_SAMPLEVOLUME				"SampleVolume"		// 样品体积			float
#define TBL_INDIRECTSHEAR_FLD_GCEABM					"GCEABM"			// 野外命名			varchar
#define TBL_INDIRECTSHEAR_FLD_GCEAAL					"GCEAAL"			// 样品重量(kg)		float
#define TBL_INDIRECTSHEAR_FLD_SAMPLELENGTH				"SampleLength"		// 样品长度(cm)		varchar
#define TBL_INDIRECTSHEAR_FLD_PRETREATMETHOD			"PretreatMethod"	// 预处理方法		varchar
#define TBL_INDIRECTSHEAR_FLD_TESTCONTENT				"TestContent"		// 测试内容			varchar
#define TBL_INDIRECTSHEAR_FLD_PLANEPOSMAP				"PlanePosMap"		// 平面位置示意图	varchar
#define TBL_INDIRECTSHEAR_FLD_PROFILEMAP				"ProfileMap"		// 剖面示意图		varchar
#define TBL_INDIRECTSHEAR_FLD_FIELDIMAGE				"FieldImage"		// 野外照片(视频)	varchar
#define TBL_INDIRECTSHEAR_FLD_RECORDCARD				"RecordCard"		// 记录卡片(记录)	varchar
#define TBL_INDIRECTSHEAR_FLD_SAMPLEORGN				"SampleOrgn"		// 采样单位			varchar
#define TBL_INDIRECTSHEAR_FLD_SWFOMW					"SWFOMW"			// 采样人			varchar
#define TBL_INDIRECTSHEAR_FLD_GCEABJ					"GCEABJ"			// 采样日期			date
#define TBL_INDIRECTSHEAR_FLD_INPUTER					"Inputer"			// 录入员			varchar
#define TBL_INDIRECTSHEAR_FLD_INPUTORGN					"InputOrgn"			// 录入单位			varchar
#define TBL_INDIRECTSHEAR_FLD_INPUTDATE					"InputDate"			// 录入日期			date
// from 室内测试分析基本情况表
#define TBL_INDIRECTSHEAR_FLD_GCEABD				"GCEABD"				// 室内编号				varchar
#define TBL_INDIRECTSHEAR_FLD_TESTEQUIP				"TestEquip"				// 试验仪器				varchar
#define TBL_INDIRECTSHEAR_FLD_TESTMETHOD			"TestMethod"			// 试验方法				varchar
#define TBL_INDIRECTSHEAR_FLD_TESTBASED				"TestBased"				// 检验依据				varchar
#define TBL_INDIRECTSHEAR_FLD_GCEAJC				"GCEAJC"				// 试验单位				varchar
#define TBL_INDIRECTSHEAR_FLD_SWFGAM				"SWFGAM"				// 收样日期				date
#define TBL_INDIRECTSHEAR_FLD_SWFGAN				"SWFGAN"				// 报告日期				date
#define TBL_INDIRECTSHEAR_FLD_GCEAJD				"GCEAJD"				// 校对					varchar
#define TBL_INDIRECTSHEAR_FLD_AUDITOR				"Auditor"				// 审核					varchar
#define TBL_INDIRECTSHEAR_FLD_TESTLEADER			"TestLeader"			// 试验负责人			varchar
#define TBL_INDIRECTSHEAR_FLD__REPORT				"_Report"				// 原始测试分析报告		varchar


//动三轴实验成果表 -- LH.2021.08.31 changed.
#define TBL_INDYNAMICTHAXIS_TBL "INDynamicThaxis"
#define TBL_INDYNAMICTHAXIS_FLD_DYNAMICTHAXISID			"DynamicThaxisID"		//* 动三轴ID						int
#define TBL_INDYNAMICTHAXIS_FLD_TOPDEPTH				UNION_MACRO_START_DEPTH		//* 取样顶深度		float
#define TBL_INDYNAMICTHAXIS_FLD_BOTTOMDEPTH				UNION_MACRO_END_DEPTH		//* 取样底深度		float
#define TBL_INDYNAMICTHAXIS_FLD_PNTID					UNION_MACRO_PNT_ID			//* 点ID				int
#define TBL_INDYNAMICTHAXIS_FLD_SWFGAA					UNION_MACRO_TCDH			//* 采样层位			varchar
#define TBL_INDYNAMICTHAXIS_FLD_TCMC					UNION_MACRO_TCMC			//  土层名称			varchar
#define TBL_INDYNAMICTHAXIS_FLD_GEOCODE					UNION_MACRO_GEOCODE			//  地质代号			varchar
#define TBL_INDYNAMICTHAXIS_FLD_TESTNO					UNION_MACRO_TESTNO			//	试验编号			varchar
#define TBL_INDYNAMICTHAXIS_FLD_TESTCATEGORY			UNION_MACRO_TESTTYPE		//  试验类型			varchar					varchar
#define TBL_INDYNAMICTHAXIS_FLD_DGCDKBB					"_DGCDKBB"				// 动弹性模量(MPa)				float
#define TBL_INDYNAMICTHAXIS_FLD_DYSHEARMODULE			"DyShearModule"			// 动剪切模量(MPa)				float
#define TBL_INDYNAMICTHAXIS_FLD_DAMPRATIO				"_Dampratio"			//  阻尼比						float
#define TBL_INDYNAMICTHAXIS_FLD_DDAMPRATIO				"_DDampratio"			//  动阻尼比						float
#define TBL_INDYNAMICTHAXIS_FLD_DGCBFOA					"_DGCBFOA"				//  动粘聚力(kPa)				float
#define TBL_INDYNAMICTHAXIS_FLD_DGCDMAC					"_DGCDMAC"				//  动内摩擦角(度)				float
// from 样品信息表 *
#define TBL_INDYNAMICTHAXIS_FLD_GCEABB					"GCEABB"			// 样品编号			varchar
#define TBL_INDYNAMICTHAXIS_FLD_SWBCF					"SWBCF"				// 样品类型			varchar
#define TBL_INDYNAMICTHAXIS_FLD_ISMIXSAMPLE				"IsMixSample"		// 混合样			varchar
#define TBL_INDYNAMICTHAXIS_FLD_PNTTYPE					"PntType"			// 点类型			varchar
#define TBL_INDYNAMICTHAXIS_FLD_SECONDCODE				"SecondCode"		// 样品二次编码		varchar
#define TBL_INDYNAMICTHAXIS_FLD_SAMPLEVOLUME			"SampleVolume"		// 样品体积			float
#define TBL_INDYNAMICTHAXIS_FLD_GCEABM					"GCEABM"			// 野外命名			varchar
#define TBL_INDYNAMICTHAXIS_FLD_GCEAAL					"GCEAAL"			// 样品重量(kg)		float
#define TBL_INDYNAMICTHAXIS_FLD_SAMPLELENGTH			"SampleLength"		// 样品长度(cm)		varchar
#define TBL_INDYNAMICTHAXIS_FLD_PRETREATMETHOD			"PretreatMethod"	// 预处理方法		varchar
#define TBL_INDYNAMICTHAXIS_FLD_TESTCONTENT				"TestContent"		// 测试内容			varchar
#define TBL_INDYNAMICTHAXIS_FLD_PLANEPOSMAP				"PlanePosMap"		// 平面位置示意图	varchar
#define TBL_INDYNAMICTHAXIS_FLD_PROFILEMAP				"ProfileMap"		// 剖面示意图		varchar
#define TBL_INDYNAMICTHAXIS_FLD_FIELDIMAGE				"FieldImage"		// 野外照片(视频)	varchar
#define TBL_INDYNAMICTHAXIS_FLD_RECORDCARD				"RecordCard"		// 记录卡片(记录)	varchar
#define TBL_INDYNAMICTHAXIS_FLD_SAMPLEORGN				"SampleOrgn"		// 采样单位			varchar
#define TBL_INDYNAMICTHAXIS_FLD_SWFOMW					"SWFOMW"			// 采样人			varchar
#define TBL_INDYNAMICTHAXIS_FLD_GCEABJ					"GCEABJ"			// 采样日期			date
#define TBL_INDYNAMICTHAXIS_FLD_INPUTER					"Inputer"			// 录入员			varchar
#define TBL_INDYNAMICTHAXIS_FLD_INPUTORGN				"InputOrgn"			// 录入单位			varchar
#define TBL_INDYNAMICTHAXIS_FLD_INPUTDATE				"InputDate"			// 录入日期			date
// from 室内测试分析基本情况表
#define TBL_INDYNAMICTHAXIS_FLD_GCEABD					"GCEABD"				// 室内编号				varchar
#define TBL_INDYNAMICTHAXIS_FLD_TESTEQUIP				"TestEquip"				// 试验仪器				varchar
#define TBL_INDYNAMICTHAXIS_FLD_TESTMETHOD				"TestMethod"			// 试验方法				varchar
#define TBL_INDYNAMICTHAXIS_FLD_TESTBASED				"TestBased"				// 检验依据				varchar
#define TBL_INDYNAMICTHAXIS_FLD_GCEAJC					"GCEAJC"				// 试验单位				varchar
#define TBL_INDYNAMICTHAXIS_FLD_SWFGAM					"SWFGAM"				// 收样日期				date
#define TBL_INDYNAMICTHAXIS_FLD_SWFGAN					"SWFGAN"				// 报告日期				date
#define TBL_INDYNAMICTHAXIS_FLD_GCEAJD					"GCEAJD"				// 校对					varchar
#define TBL_INDYNAMICTHAXIS_FLD_AUDITOR					"Auditor"				// 审核					varchar
#define TBL_INDYNAMICTHAXIS_FLD_TESTLEADER				"TestLeader"			// 试验负责人			varchar
#define TBL_INDYNAMICTHAXIS_FLD__REPORT					"_Report"				// 原始测试分析报告		varchar


/*------------------------------------------室内物理化学测试类---------------------------------------------*/
#define INPHYCHEMI_MDL_CLASS "室内物理化学测试表类"
	//岩矿鉴定成果表 -- LH.2021.08.31 changed.
#define TBL_INROCKMINEIDENT_TBL "INRockMineIdent"
#define TBL_INROCKMINEIDENT_FLD_ROCKMINEIDENTID			"RockMineidentID"	//* 岩矿鉴定ID				int
#define TBL_INROCKMINEIDENT_FLD_TOPDEPTH				UNION_MACRO_START_DEPTH		//* 取样顶深度		float
#define TBL_INROCKMINEIDENT_FLD_BOTTOMDEPTH				UNION_MACRO_END_DEPTH		//* 取样底深度		float
#define TBL_INROCKMINEIDENT_FLD_PNTID					UNION_MACRO_PNT_ID			//* 点ID				int
#define TBL_INROCKMINEIDENT_FLD_SWFGAA					UNION_MACRO_TCDH			//* 采样层位			varchar
#define TBL_INROCKMINEIDENT_FLD_TCMC					UNION_MACRO_TCMC			//  土层名称			varchar
#define TBL_INROCKMINEIDENT_FLD_GEOCODE					UNION_MACRO_GEOCODE			//  地质代号			varchar
#define TBL_INROCKMINEIDENT_FLD_TESTNO					UNION_MACRO_TESTNO			//	试验编号			varchar
#define TBL_INROCKMINEIDENT_FLD_TESTCATEGORY			UNION_MACRO_TESTTYPE		//  试验类型			varchar	
#define TBL_INROCKMINEIDENT_FLD_STRUCTURE				"_Structure"		// 结构						varchar
#define TBL_INROCKMINEIDENT_FLD_CONSTRUCT				"_Construct"		// 构造						varchar
#define TBL_INROCKMINEIDENT_FLD_CEMENT					"_Cement"			// 胶结物					varchar
#define TBL_INROCKMINEIDENT_FLD_IDENTIFICATDESC			"IdentificatDesc"	// 鉴定描述					varchar
// from 岩矿成分分析数据表
#define TBL_INROCKMINEIDENT_FLD_INGREDIENT				"_Ingredient"		// 成份						varchar
#define TBL_INROCKMINEIDENT_FLD_CONTENT					"_Content"			// 含量(%)					float																  
// from 样品信息表 *
#define TBL_INROCKMINEIDENT_FLD_GCEABB					"GCEABB"			// 样品编号			varchar
#define TBL_INROCKMINEIDENT_FLD_SWBCF					"SWBCF"				// 样品类型			varchar
#define TBL_INROCKMINEIDENT_FLD_ISMIXSAMPLE				"IsMixSample"		// 混合样			varchar
#define TBL_INROCKMINEIDENT_FLD_PNTTYPE					"PntType"			// 点类型			varchar
#define TBL_INROCKMINEIDENT_FLD_SECONDCODE				"SecondCode"		// 样品二次编码		varchar
#define TBL_INROCKMINEIDENT_FLD_SAMPLEVOLUME			"SampleVolume"		// 样品体积			float
#define TBL_INROCKMINEIDENT_FLD_GCEABM					"GCEABM"			// 野外命名			varchar
#define TBL_INROCKMINEIDENT_FLD_GCEAAL					"GCEAAL"			// 样品重量(kg)		float
#define TBL_INROCKMINEIDENT_FLD_SAMPLELENGTH			"SampleLength"		// 样品长度(cm)		varchar
#define TBL_INROCKMINEIDENT_FLD_PRETREATMETHOD			"PretreatMethod"	// 预处理方法		varchar
#define TBL_INROCKMINEIDENT_FLD_TESTCONTENT				"TestContent"		// 测试内容			varchar
#define TBL_INROCKMINEIDENT_FLD_PLANEPOSMAP				"PlanePosMap"		// 平面位置示意图	varchar
#define TBL_INROCKMINEIDENT_FLD_PROFILEMAP				"ProfileMap"		// 剖面示意图		varchar
#define TBL_INROCKMINEIDENT_FLD_FIELDIMAGE				"FieldImage"		// 野外照片(视频)	varchar
#define TBL_INROCKMINEIDENT_FLD_RECORDCARD				"RecordCard"		// 记录卡片(记录)	varchar
#define TBL_INROCKMINEIDENT_FLD_SAMPLEORGN				"SampleOrgn"		// 采样单位			varchar
#define TBL_INROCKMINEIDENT_FLD_SWFOMW					"SWFOMW"			// 采样人			varchar
#define TBL_INROCKMINEIDENT_FLD_GCEABJ					"GCEABJ"			// 采样日期			date
#define TBL_INROCKMINEIDENT_FLD_INPUTER					"Inputer"			// 录入员			varchar
#define TBL_INROCKMINEIDENT_FLD_INPUTORGN				"InputOrgn"			// 录入单位			varchar
#define TBL_INROCKMINEIDENT_FLD_INPUTDATE				"InputDate"			// 录入日期			date
// from 室内测试分析基本情况表
#define TBL_INROCKMINEIDENT_FLD_GCEABD					"GCEABD"			// 室内编号				varchar
#define TBL_INROCKMINEIDENT_FLD_INDOORNAME				"IndoorName"		// 室内名称				varchar
#define TBL_INROCKMINEIDENT_FLD_TESTEQUIP				"TestEquip"			// 试验仪器				varchar
#define TBL_INROCKMINEIDENT_FLD_TESTMETHOD				"TestMethod"		// 试验方法				varchar
#define TBL_INROCKMINEIDENT_FLD_TESTBASED				"TestBased"			// 检验依据				varchar
#define TBL_INROCKMINEIDENT_FLD_GCEAJC					"GCEAJC"			// 试验单位				varchar
#define TBL_INROCKMINEIDENT_FLD_SWFGAM					"SWFGAM"			// 收样日期				date
#define TBL_INROCKMINEIDENT_FLD_SWFGAN					"SWFGAN"			// 报告日期				date
#define TBL_INROCKMINEIDENT_FLD_GCEAJD					"GCEAJD"			// 校对					varchar
#define TBL_INROCKMINEIDENT_FLD_AUDITOR					"Auditor"			// 审核					varchar
#define TBL_INROCKMINEIDENT_FLD_TESTLEADER				"TestLeader"		// 试验负责人			varchar
#define TBL_INROCKMINEIDENT_FLD__REPORT					"_Report"			// 原始测试分析报告		varchar		


//粘土（全岩）矿物鉴定成果表 -- LH.2021.08.31 changed.
#define TBL_INCLAYMINERALIDENT_TBL "INClayMineralIdent"
#define TBL_INCLAYMINERALIDENT_FLD_CLAYMINERALID			"ClayMineralID"		//* 粘土矿物ID				int
#define TBL_INCLAYMINERALIDENT_FLD_TOPDEPTH					UNION_MACRO_START_DEPTH		//* 取样顶深度		float
#define TBL_INCLAYMINERALIDENT_FLD_BOTTOMDEPTH				UNION_MACRO_END_DEPTH		//* 取样底深度		float
#define TBL_INCLAYMINERALIDENT_FLD_PNTID					UNION_MACRO_PNT_ID			//* 点ID				int
#define TBL_INCLAYMINERALIDENT_FLD_SWFGAA					UNION_MACRO_TCDH			//* 采样层位			varchar
#define TBL_INCLAYMINERALIDENT_FLD_TCMC						UNION_MACRO_TCMC			//  土层名称			varchar
#define TBL_INCLAYMINERALIDENT_FLD_GEOCODE					UNION_MACRO_GEOCODE			//  地质代号			varchar
#define TBL_INCLAYMINERALIDENT_FLD_TESTNO					UNION_MACRO_TESTNO			//	试验编号			varchar
#define TBL_INCLAYMINERALIDENT_FLD_TESTCATEGORY				UNION_MACRO_TESTTYPE		//  试验类型			varchar	
#define TBL_INCLAYMINERALIDENT_FLD_QUARTZ					"Quartz"			// 石英(%)					float
#define TBL_INCLAYMINERALIDENT_FLD_POTASHFELDSPAR			"Potashfeldspar"	// 钾长石(%)				float
#define TBL_INCLAYMINERALIDENT_FLD_PLAGIOCLASE				"Plagioclase"		// 斜长石(%)				float
#define TBL_INCLAYMINERALIDENT_FLD_CALCITE					"Calcite"			// 方解石(%)				float
#define TBL_INCLAYMINERALIDENT_FLD_ROCKSALT					"Rocksalt"			// 石盐(%)					float
#define TBL_INCLAYMINERALIDENT_FLD_HORNBLENDE				"Hornblende"		// 角闪石(%)				float
#define TBL_INCLAYMINERALIDENT_FLD_CLAYMINERAL				"ClayMineral"		// 粘土矿物(%)				float
#define TBL_INCLAYMINERALIDENT_FLD_SMECTITE					"Smectite"			// 蒙皂石(%)				float
#define TBL_INCLAYMINERALIDENT_FLD_ISMIXEDMINERAL			"ISmixedmineral"	// I/S混层矿物(%)			float
#define TBL_INCLAYMINERALIDENT_FLD_SWHABO					"SWHABO"			// 伊利石(%)				float
#define TBL_INCLAYMINERALIDENT_FLD_SWHABP					"SWHABP"			// 高岭石(%)				float
#define TBL_INCLAYMINERALIDENT_FLD_SWHAAX					"SWHAAX"			// 绿泥石(%)				float
#define TBL_INCLAYMINERALIDENT_FLD_ISMIXLAYERRATIO			"ISmixlayerratio"	// 混层比I/S				float
#define TBL_INCLAYMINERALIDENT_FLD_CSMIXLAYERRATIO			"CSmixlayerratio"	// 混层比C/S				float
// from 样品信息表 *
#define TBL_INCLAYMINERALIDENT_FLD_GCEABB					"GCEABB"			// 样品编号			varchar
#define TBL_INCLAYMINERALIDENT_FLD_SWBCF					"SWBCF"				// 样品类型			varchar
#define TBL_INCLAYMINERALIDENT_FLD_ISMIXSAMPLE				"IsMixSample"		// 混合样			varchar
#define TBL_INCLAYMINERALIDENT_FLD_PNTTYPE					"PntType"			// 点类型			varchar
#define TBL_INCLAYMINERALIDENT_FLD_SECONDCODE				"SecondCode"		// 样品二次编码		varchar
#define TBL_INCLAYMINERALIDENT_FLD_SAMPLEVOLUME				"SampleVolume"		// 样品体积			float
#define TBL_INCLAYMINERALIDENT_FLD_GCEABM					"GCEABM"			// 野外命名			varchar
#define TBL_INCLAYMINERALIDENT_FLD_GCEAAL					"GCEAAL"			// 样品重量(kg)		float
#define TBL_INCLAYMINERALIDENT_FLD_SAMPLELENGTH				"SampleLength"		// 样品长度(cm)		varchar
#define TBL_INCLAYMINERALIDENT_FLD_PRETREATMETHOD			"PretreatMethod"	// 预处理方法		varchar
#define TBL_INCLAYMINERALIDENT_FLD_TESTCONTENT				"TestContent"		// 测试内容			varchar
#define TBL_INCLAYMINERALIDENT_FLD_PLANEPOSMAP				"PlanePosMap"		// 平面位置示意图	varchar
#define TBL_INCLAYMINERALIDENT_FLD_PROFILEMAP				"ProfileMap"		// 剖面示意图		varchar
#define TBL_INCLAYMINERALIDENT_FLD_FIELDIMAGE				"FieldImage"		// 野外照片(视频)	varchar
#define TBL_INCLAYMINERALIDENT_FLD_RECORDCARD				"RecordCard"		// 记录卡片(记录)	varchar
#define TBL_INCLAYMINERALIDENT_FLD_SAMPLEORGN				"SampleOrgn"		// 采样单位			varchar
#define TBL_INCLAYMINERALIDENT_FLD_SWFOMW					"SWFOMW"			// 采样人			varchar
#define TBL_INCLAYMINERALIDENT_FLD_GCEABJ					"GCEABJ"			// 采样日期			date
#define TBL_INCLAYMINERALIDENT_FLD_INPUTER					"Inputer"			// 录入员			varchar
#define TBL_INCLAYMINERALIDENT_FLD_INPUTORGN				"InputOrgn"			// 录入单位			varchar
#define TBL_INCLAYMINERALIDENT_FLD_INPUTDATE				"InputDate"			// 录入日期			date
// from 室内测试分析基本情况表
#define TBL_INCLAYMINERALIDENT_FLD_GCEABD					"GCEABD"			// 室内编号				varchar
#define TBL_INCLAYMINERALIDENT_FLD_TESTEQUIP				"TestEquip"			// 试验仪器				varchar
#define TBL_INCLAYMINERALIDENT_FLD_TESTMETHOD				"TestMethod"		// 试验方法				varchar
#define TBL_INCLAYMINERALIDENT_FLD_TESTBASED				"TestBased"			// 检验依据				varchar
#define TBL_INCLAYMINERALIDENT_FLD_GCEAJC					"GCEAJC"			// 试验单位				varchar
#define TBL_INCLAYMINERALIDENT_FLD_SWFGAM					"SWFGAM"			// 收样日期				date
#define TBL_INCLAYMINERALIDENT_FLD_SWFGAN					"SWFGAN"			// 报告日期				date
#define TBL_INCLAYMINERALIDENT_FLD_GCEAJD					"GCEAJD"			// 校对					varchar
#define TBL_INCLAYMINERALIDENT_FLD_AUDITOR					"Auditor"			// 审核					varchar
#define TBL_INCLAYMINERALIDENT_FLD_TESTLEADER				"TestLeader"		// 试验负责人			varchar
#define TBL_INCLAYMINERALIDENT_FLD__REPORT					"_Report"			// 原始测试分析报告		varchar

//粒度分析成果表 -- LH.2021.08.31 changed.
#define TBL_INGRANULARITYIDENT_TBL "INGranularityIdent"
#define TBL_INGRANULARITYIDENT_FLD_GRANULARITYID	"GranularityID"	//* 粒度ID			int
#define TBL_INGRANULARITYIDENT_FLD_TOPDEPTH			UNION_MACRO_START_DEPTH		//* 取样顶深度		float
#define TBL_INGRANULARITYIDENT_FLD_BOTTOMDEPTH		UNION_MACRO_END_DEPTH		//* 取样底深度		float
#define TBL_INGRANULARITYIDENT_FLD_PNTID			UNION_MACRO_PNT_ID			//* 点ID				int
#define TBL_INGRANULARITYIDENT_FLD_SWFGAA			UNION_MACRO_TCDH			//* 采样层位			varchar
#define TBL_INGRANULARITYIDENT_FLD_TCMC				UNION_MACRO_TCMC			//  土层名称			varchar
#define TBL_INGRANULARITYIDENT_FLD_GEOCODE			UNION_MACRO_GEOCODE			//  地质代号			varchar
#define TBL_INGRANULARITYIDENT_FLD_TESTNO			UNION_MACRO_TESTNO			//	试验编号			varchar
#define TBL_INGRANULARITYIDENT_FLD_TESTCATEGORY		UNION_MACRO_TESTTYPE		//  试验类型			varchar	
#define TBL_INGRANULARITYIDENT_FLD__CONTENT			"_Content"		// 含量				float
#define TBL_INGRANULARITYIDENT_FLD_GCCABB			"GCCABB"		// 砾石				float
#define TBL_INGRANULARITYIDENT_FLD_GCCABC			"GCCABC"		// 砂(%)				float
#define TBL_INGRANULARITYIDENT_FLD_GCCABD			"GCCABD"		// 粉砂(%)			float
#define TBL_INGRANULARITYIDENT_FLD_GCCABE			"GCCABE"		// 粘土(%)			float
#define TBL_INGRANULARITYIDENT_FLD_GCCABG			"GCCABG"		// 平均粒径			float
#define TBL_INGRANULARITYIDENT_FLD_GCCABH			"GCCABH"		// 分选系数			float
#define TBL_INGRANULARITYIDENT_FLD_GCCABI			"GCCABI"		// 偏态				float
#define TBL_INGRANULARITYIDENT_FLD_GCCABJ			"GCCABJ"		// 峰态				float
#define TBL_INGRANULARITYIDENT_FLD_GCCABF			"GCCABF"		// 中值粒径			float
#define TBL_INGRANULARITYIDENT_FLD_SEDIMENTTYPE		"SedimentType"	// 沉积物分类		varchar
// from 样品信息表 *
#define TBL_INGRANULARITYIDENT_FLD_GCEABB					"GCEABB"			// 样品编号			varchar
#define TBL_INGRANULARITYIDENT_FLD_SWBCF					"SWBCF"				// 样品类型			varchar
#define TBL_INGRANULARITYIDENT_FLD_ISMIXSAMPLE				"IsMixSample"		// 混合样			varchar
#define TBL_INGRANULARITYIDENT_FLD_PNTTYPE					"PntType"			// 点类型			varchar
#define TBL_INGRANULARITYIDENT_FLD_SECONDCODE				"SecondCode"		// 样品二次编码		varchar
#define TBL_INGRANULARITYIDENT_FLD_SAMPLEVOLUME				"SampleVolume"		// 样品体积			float
#define TBL_INGRANULARITYIDENT_FLD_GCEABM					"GCEABM"			// 野外命名			varchar
#define TBL_INGRANULARITYIDENT_FLD_GCEAAL					"GCEAAL"			// 样品重量(kg)		float
#define TBL_INGRANULARITYIDENT_FLD_SAMPLELENGTH				"SampleLength"		// 样品长度(cm)		varchar
#define TBL_INGRANULARITYIDENT_FLD_PRETREATMETHOD			"PretreatMethod"	// 预处理方法		varchar
#define TBL_INGRANULARITYIDENT_FLD_TESTCONTENT				"TestContent"		// 测试内容			varchar
#define TBL_INGRANULARITYIDENT_FLD_PLANEPOSMAP				"PlanePosMap"		// 平面位置示意图	varchar
#define TBL_INGRANULARITYIDENT_FLD_PROFILEMAP				"ProfileMap"		// 剖面示意图		varchar
#define TBL_INGRANULARITYIDENT_FLD_FIELDIMAGE				"FieldImage"		// 野外照片(视频)	varchar
#define TBL_INGRANULARITYIDENT_FLD_RECORDCARD				"RecordCard"		// 记录卡片(记录)	varchar
#define TBL_INGRANULARITYIDENT_FLD_SAMPLEORGN				"SampleOrgn"		// 采样单位			varchar
#define TBL_INGRANULARITYIDENT_FLD_SWFOMW					"SWFOMW"			// 采样人			varchar
#define TBL_INGRANULARITYIDENT_FLD_GCEABJ					"GCEABJ"			// 采样日期			date
#define TBL_INGRANULARITYIDENT_FLD_INPUTER					"Inputer"			// 录入员			varchar
#define TBL_INGRANULARITYIDENT_FLD_INPUTORGN				"InputOrgn"			// 录入单位			varchar
#define TBL_INGRANULARITYIDENT_FLD_INPUTDATE				"InputDate"			// 录入日期			date
// from 室内测试分析基本情况表
#define TBL_INGRANULARITYIDENT_FLD_GCEABD			"GCEABD"		// 室内编号				varchar
#define TBL_INGRANULARITYIDENT_FLD_TESTEQUIP		"TestEquip"		// 试验仪器				varchar
#define TBL_INGRANULARITYIDENT_FLD_TESTMETHOD		"TestMethod"	// 试验方法				varchar
#define TBL_INGRANULARITYIDENT_FLD_TESTBASED		"TestBased"		// 检验依据				varchar
#define TBL_INGRANULARITYIDENT_FLD_GCEAJC			"GCEAJC"		// 试验单位				varchar
#define TBL_INGRANULARITYIDENT_FLD_SWFGAM			"SWFGAM"		// 收样日期				date
#define TBL_INGRANULARITYIDENT_FLD_SWFGAN			"SWFGAN"		// 报告日期				date
#define TBL_INGRANULARITYIDENT_FLD_GCEAJD			"GCEAJD"		// 校对					varchar
#define TBL_INGRANULARITYIDENT_FLD_AUDITOR			"Auditor"		// 审核					varchar
#define TBL_INGRANULARITYIDENT_FLD_TESTLEADER		"TestLeader"	// 试验负责人			varchar
#define TBL_INGRANULARITYIDENT_FLD__REPORT			"_Report"		// 原始测试分析报告		varchar

//热物性实验成果表 -- LH.2021.08.31 changed.
#define TBL_INTHERMOPHYSICAL_TBL "INThermophysical"
#define TBL_INTHERMOPHYSICAL_FLD_THERMOPHYSICALID		"ThermophysicalID"			//* 热物性ID				int
#define TBL_INTHERMOPHYSICAL_FLD_TOPDEPTH				UNION_MACRO_START_DEPTH		//* 取样顶深度		float
#define TBL_INTHERMOPHYSICAL_FLD_BOTTOMDEPTH			UNION_MACRO_END_DEPTH		//* 取样底深度		float
#define TBL_INTHERMOPHYSICAL_FLD_PNTID					UNION_MACRO_PNT_ID			//* 点ID				int
#define TBL_INTHERMOPHYSICAL_FLD_SWFGAA					UNION_MACRO_TCDH			//* 采样层位			varchar
#define TBL_INTHERMOPHYSICAL_FLD_TCMC					UNION_MACRO_TCMC			//  土层名称			varchar
#define TBL_INTHERMOPHYSICAL_FLD_GEOCODE				UNION_MACRO_GEOCODE			//  地质代号			varchar
#define TBL_INTHERMOPHYSICAL_FLD_TESTNO					UNION_MACRO_TESTNO			//	试验编号			varchar
#define TBL_INTHERMOPHYSICAL_FLD_TESTCATEGORY			UNION_MACRO_TESTTYPE		//  试验类型			varchar	
#define TBL_INTHERMOPHYSICAL_FLD_GCDGAF					"GCDGAF"					// 导热系数				float
#define TBL_INTHERMOPHYSICAL_FLD_GCDGAE					"GCDGAE"					// 比热(J/(kg*℃))	   float
#define TBL_INTHERMOPHYSICAL_FLD_SWDEAH					"SWDEAH"					// 热扩散系数			float
#define TBL_INTHERMOPHYSICAL_FLD_SYEFAB					"SYEFAB"					// 自然密度(g/cm3)		float
#define TBL_INTHERMOPHYSICAL_FLD_GCDCAO					"GCDCAO"					// 含水率(%)			float
#define TBL_INTHERMOPHYSICAL_FLD_GCDBB					"GCDBB"						// 孔隙率(%)			float
#define TBL_INTHERMOPHYSICAL_FLD_DHABCU					"DHABCU"					// 饱和度(%)			float
// from 室内测试分析基本情况表
#define TBL_INTHERMOPHYSICAL_FLD_GCEABD					"GCEABD"					// 室内编号				varchar
#define TBL_INTHERMOPHYSICAL_FLD_TESTEQUIP				"TestEquip"					// 试验仪器				varchar
#define TBL_INTHERMOPHYSICAL_FLD_TESTMETHOD				"TestMethod"				// 试验方法				varchar
#define TBL_INTHERMOPHYSICAL_FLD_TESTBASED				"TestBased"					// 检验依据				varchar
#define TBL_INTHERMOPHYSICAL_FLD_GCEAJC					"GCEAJC"					// 试验单位				varchar
#define TBL_INTHERMOPHYSICAL_FLD_SWFGAM					"SWFGAM"					// 收样日期				date
#define TBL_INTHERMOPHYSICAL_FLD_SWFGAN					"SWFGAN"					// 报告日期				date
#define TBL_INTHERMOPHYSICAL_FLD_GCEAJD					"GCEAJD"					// 校对					varchar
#define TBL_INTHERMOPHYSICAL_FLD_AUDITOR				"Auditor"					// 审核					varchar
#define TBL_INTHERMOPHYSICAL_FLD_TESTLEADER				"TestLeader"				// 试验负责人			varchar
#define TBL_INTHERMOPHYSICAL_FLD__REPORT				"_Report"					// 原始测试分析报告		varchar
// from 样品信息表 *
#define TBL_INTHERMOPHYSICAL_FLD_GCEABB					"GCEABB"			// 样品编号			varchar
#define TBL_INTHERMOPHYSICAL_FLD_SWBCF					"SWBCF"				// 样品类型			varchar
#define TBL_INTHERMOPHYSICAL_FLD_ISMIXSAMPLE			"IsMixSample"		// 混合样			varchar
#define TBL_INTHERMOPHYSICAL_FLD_PNTTYPE				"PntType"			// 点类型			varchar
#define TBL_INTHERMOPHYSICAL_FLD_SECONDCODE				"SecondCode"		// 样品二次编码		varchar
#define TBL_INTHERMOPHYSICAL_FLD_SAMPLEVOLUME			"SampleVolume"		// 样品体积			float
#define TBL_INTHERMOPHYSICAL_FLD_GCEABM					"GCEABM"			// 野外命名			varchar
#define TBL_INTHERMOPHYSICAL_FLD_GCEAAL					"GCEAAL"			// 样品重量(kg)		float
#define TBL_INTHERMOPHYSICAL_FLD_SAMPLELENGTH			"SampleLength"		// 样品长度(cm)		varchar
#define TBL_INTHERMOPHYSICAL_FLD_PRETREATMETHOD			"PretreatMethod"	// 预处理方法		varchar
#define TBL_INTHERMOPHYSICAL_FLD_TESTCONTENT			"TestContent"		// 测试内容			varchar
#define TBL_INTHERMOPHYSICAL_FLD_PLANEPOSMAP			"PlanePosMap"		// 平面位置示意图	varchar
#define TBL_INTHERMOPHYSICAL_FLD_PROFILEMAP				"ProfileMap"		// 剖面示意图		varchar
#define TBL_INTHERMOPHYSICAL_FLD_FIELDIMAGE				"FieldImage"		// 野外照片(视频)	varchar
#define TBL_INTHERMOPHYSICAL_FLD_RECORDCARD				"RecordCard"		// 记录卡片(记录)	varchar
#define TBL_INTHERMOPHYSICAL_FLD_SAMPLEORGN				"SampleOrgn"		// 采样单位			varchar
#define TBL_INTHERMOPHYSICAL_FLD_SWFOMW					"SWFOMW"			// 采样人			varchar
#define TBL_INTHERMOPHYSICAL_FLD_GCEABJ					"GCEABJ"			// 采样日期			date
#define TBL_INTHERMOPHYSICAL_FLD_INPUTER				"Inputer"			// 录入员			varchar
#define TBL_INTHERMOPHYSICAL_FLD_INPUTORGN				"InputOrgn"			// 录入单位			varchar
#define TBL_INTHERMOPHYSICAL_FLD_INPUTDATE				"InputDate"			// 录入日期			date

//同位素测年成果表 -- LH.2021.08.31 changed.
#define TBL_INISOTOPE_TBL "INIsotope"
#define TBL_INISOTOPE_FLD_IsotopeID			"IsotopeID"			//* 同位素ID				int
#define TBL_INISOTOPE_FLD_TOPDEPTH			UNION_MACRO_START_DEPTH		//* 取样顶深度		float
#define TBL_INISOTOPE_FLD_BOTTOMDEPTH		UNION_MACRO_END_DEPTH		//* 取样底深度		float
#define TBL_INISOTOPE_FLD_PNTID				UNION_MACRO_PNT_ID			//* 点ID				int
#define TBL_INISOTOPE_FLD_SWFGAA			UNION_MACRO_TCDH			//* 采样层位			varchar
#define TBL_INISOTOPE_FLD_TCMC				UNION_MACRO_TCMC			//  土层名称			varchar
#define TBL_INISOTOPE_FLD_GEOCODE			UNION_MACRO_GEOCODE			//  地质代号			varchar
#define TBL_INISOTOPE_FLD_TESTNO			UNION_MACRO_TESTNO			//	试验编号			varchar
#define TBL_INISOTOPE_FLD_TESTCATEGORY		UNION_MACRO_TESTTYPE		//  试验类型			varchar	
#define TBL_INISOTOPE_FLD_Isotope			"Isotope"			// 同位素				varchar
#define TBL_INISOTOPE_FLD_YJDCBH			"YJDCBH"			// 丰度					float
#define TBL_INISOTOPE_FLD_TestAge			"TestAge"			// 测试年龄				int
#define TBL_INISOTOPE_FLD_AgeUnit			"AgeUnit"			// 年龄单位				varchar
// from 室内测试分析基本情况表
#define TBL_INISOTOPE_FLD_GCEABD			"GCEABD"			// 室内编号				varchar
#define TBL_INISOTOPE_FLD_TESTEQUIP			"TestEquip"			// 试验仪器				varchar
#define TBL_INISOTOPE_FLD_TESTMETHOD		"TestMethod"		// 试验方法				varchar
#define TBL_INISOTOPE_FLD_TESTBASED			"TestBased"			// 检验依据				varchar
#define TBL_INISOTOPE_FLD_GCEAJC			"GCEAJC"			// 试验单位				varchar
#define TBL_INISOTOPE_FLD_SWFGAM			"SWFGAM"			// 收样日期				date
#define TBL_INISOTOPE_FLD_SWFGAN			"SWFGAN"			// 报告日期				date
#define TBL_INISOTOPE_FLD_GCEAJD			"GCEAJD"			// 校对					varchar
#define TBL_INISOTOPE_FLD_AUDITOR			"Auditor"			// 审核					varchar
#define TBL_INISOTOPE_FLD_TESTLEADER		"TestLeader"		// 试验负责人			varchar
#define TBL_INISOTOPE_FLD__REPORT			"_Report"			// 原始测试分析报告		varchar
// from 样品信息表 *
#define TBL_INISOTOPE_FLD_GCEABB					"GCEABB"			// 样品编号			varchar
#define TBL_INISOTOPE_FLD_SWBCF						"SWBCF"				// 样品类型			varchar
#define TBL_INISOTOPE_FLD_ISMIXSAMPLE				"IsMixSample"		// 混合样			varchar
#define TBL_INISOTOPE_FLD_PNTTYPE					"PntType"			// 点类型			varchar
#define TBL_INISOTOPE_FLD_SECONDCODE				"SecondCode"		// 样品二次编码		varchar
#define TBL_INISOTOPE_FLD_SAMPLEVOLUME				"SampleVolume"		// 样品体积			float
#define TBL_INISOTOPE_FLD_GCEABM					"GCEABM"			// 野外命名			varchar
#define TBL_INISOTOPE_FLD_GCEAAL					"GCEAAL"			// 样品重量(kg)		float
#define TBL_INISOTOPE_FLD_SAMPLELENGTH				"SampleLength"		// 样品长度(cm)		varchar
#define TBL_INISOTOPE_FLD_PRETREATMETHOD			"PretreatMethod"	// 预处理方法		varchar
#define TBL_INISOTOPE_FLD_TESTCONTENT				"TestContent"		// 测试内容			varchar
#define TBL_INISOTOPE_FLD_PLANEPOSMAP				"PlanePosMap"		// 平面位置示意图	varchar
#define TBL_INISOTOPE_FLD_PROFILEMAP				"ProfileMap"		// 剖面示意图		varchar
#define TBL_INISOTOPE_FLD_FIELDIMAGE				"FieldImage"		// 野外照片(视频)	varchar
#define TBL_INISOTOPE_FLD_RECORDCARD				"RecordCard"		// 记录卡片(记录)	varchar
#define TBL_INISOTOPE_FLD_SAMPLEORGN				"SampleOrgn"		// 采样单位			varchar
#define TBL_INISOTOPE_FLD_SWFOMW					"SWFOMW"			// 采样人			varchar
#define TBL_INISOTOPE_FLD_GCEABJ					"GCEABJ"			// 采样日期			date
#define TBL_INISOTOPE_FLD_INPUTER					"Inputer"			// 录入员			varchar
#define TBL_INISOTOPE_FLD_INPUTORGN					"InputOrgn"			// 录入单位			varchar
#define TBL_INISOTOPE_FLD_INPUTDATE					"InputDate"			// 录入日期			date


//释光测年成果表 -- LH.2021.08.31 changed.
#define TBL_INLUMINESCENCE_TBL "INLuminescence"
#define TBL_INLUMINESCENCE_FLD_LUMINESCENCEID	"LuminescenceID"	//* 释光ID				int
#define TBL_INLUMINESCENCE_FLD_TOPDEPTH				UNION_MACRO_START_DEPTH		//* 取样顶深度		float
#define TBL_INLUMINESCENCE_FLD_BOTTOMDEPTH			UNION_MACRO_END_DEPTH		//* 取样底深度		float
#define TBL_INLUMINESCENCE_FLD_PNTID					UNION_MACRO_PNT_ID			//* 点ID				int
#define TBL_INLUMINESCENCE_FLD_SWFGAA				UNION_MACRO_TCDH			//* 采样层位			varchar
#define TBL_INLUMINESCENCE_FLD_TCMC					UNION_MACRO_TCMC			//  土层名称			varchar
#define TBL_INLUMINESCENCE_FLD_GEOCODE				UNION_MACRO_GEOCODE			//  地质代号			varchar
#define TBL_INLUMINESCENCE_FLD_TESTNO				UNION_MACRO_TESTNO			//	试验编号			varchar
#define TBL_INLUMINESCENCE_FLD_TESTCATEGORY			UNION_MACRO_TESTTYPE		//  试验类型			varchar	
#define TBL_INLUMINESCENCE_FLD_DATEMETHOD		"DateMethod"				// 测年方法				varchar
#define TBL_INLUMINESCENCE_FLD_TESTAGE			"TestAge"					// 测试年龄				int
#define TBL_INLUMINESCENCE_FLD_AGEUNIT			"AgeUnit"					// 年龄单位				varchar
#define TBL_INLUMINESCENCE_FLD_MEMO				"_Memo"						// 备注					varchar
// from 样品信息表 *
#define TBL_INLUMINESCENCE_FLD_GCEABB					"GCEABB"			// 样品编号			varchar
#define TBL_INLUMINESCENCE_FLD_SWBCF					"SWBCF"				// 样品类型			varchar
#define TBL_INLUMINESCENCE_FLD_ISMIXSAMPLE				"IsMixSample"		// 混合样			varchar
#define TBL_INLUMINESCENCE_FLD_PNTTYPE					"PntType"			// 点类型			varchar
#define TBL_INLUMINESCENCE_FLD_SECONDCODE				"SecondCode"		// 样品二次编码		varchar
#define TBL_INLUMINESCENCE_FLD_SAMPLEVOLUME				"SampleVolume"		// 样品体积			float
#define TBL_INLUMINESCENCE_FLD_GCEABM					"GCEABM"			// 野外命名			varchar
#define TBL_INLUMINESCENCE_FLD_GCEAAL					"GCEAAL"			// 样品重量(kg)		float
#define TBL_INLUMINESCENCE_FLD_SAMPLELENGTH				"SampleLength"		// 样品长度(cm)		varchar
#define TBL_INLUMINESCENCE_FLD_PRETREATMETHOD			"PretreatMethod"	// 预处理方法		varchar
#define TBL_INLUMINESCENCE_FLD_TESTCONTENT				"TestContent"		// 测试内容			varchar
#define TBL_INLUMINESCENCE_FLD_PLANEPOSMAP				"PlanePosMap"		// 平面位置示意图	varchar
#define TBL_INLUMINESCENCE_FLD_PROFILEMAP				"ProfileMap"		// 剖面示意图		varchar
#define TBL_INLUMINESCENCE_FLD_FIELDIMAGE				"FieldImage"		// 野外照片(视频)	varchar
#define TBL_INLUMINESCENCE_FLD_RECORDCARD				"RecordCard"		// 记录卡片(记录)	varchar
#define TBL_INLUMINESCENCE_FLD_SAMPLEORGN				"SampleOrgn"		// 采样单位			varchar
#define TBL_INLUMINESCENCE_FLD_SWFOMW					"SWFOMW"			// 采样人			varchar
#define TBL_INLUMINESCENCE_FLD_GCEABJ					"GCEABJ"			// 采样日期			date
#define TBL_INLUMINESCENCE_FLD_INPUTER					"Inputer"			// 录入员			varchar
#define TBL_INLUMINESCENCE_FLD_INPUTORGN				"InputOrgn"			// 录入单位			varchar
#define TBL_INLUMINESCENCE_FLD_INPUTDATE				"InputDate"			// 录入日期			date
// from 室内测试分析基本情况表
#define TBL_INLUMINESCENCE_FLD_GCEABD					"GCEABD"			// 室内编号				varchar
#define TBL_INLUMINESCENCE_FLD_TESTEQUIP				"TestEquip"			// 试验仪器				varchar
#define TBL_INLUMINESCENCE_FLD_TESTMETHOD				"TestMethod"		// 试验方法				varchar
#define TBL_INLUMINESCENCE_FLD_TESTBASED				"TestBased"			// 检验依据				varchar
#define TBL_INLUMINESCENCE_FLD_GCEAJC					"GCEAJC"			// 试验单位				varchar
#define TBL_INLUMINESCENCE_FLD_SWFGAM					"SWFGAM"			// 收样日期				date
#define TBL_INLUMINESCENCE_FLD_SWFGAN					"SWFGAN"			// 报告日期				date
#define TBL_INLUMINESCENCE_FLD_GCEAJD					"GCEAJD"			// 校对					varchar
#define TBL_INLUMINESCENCE_FLD_AUDITOR					"Auditor"			// 审核					varchar
#define TBL_INLUMINESCENCE_FLD_TESTLEADER				"TestLeader"		// 试验负责人			varchar
#define TBL_INLUMINESCENCE_FLD__REPORT					"_Report"			// 原始测试分析报告		varchar


//孢粉组合表 -- LH.2021.08.31 changed.
#define TBL_INPOLLENCOMBINAT_TBL "INPollenCombinat"
#define TBL_INPOLLENCOMBINAT_FLD_POLLENCOMBINATID		"PollenCombinatID"		//* 孢粉组合ID			int
#define TBL_INPOLLENCOMBINAT_FLD_TOPDEPTH				UNION_MACRO_START_DEPTH		//* 取样顶深度		float
#define TBL_INPOLLENCOMBINAT_FLD_BOTTOMDEPTH			UNION_MACRO_END_DEPTH		//* 取样底深度		float
#define TBL_INPOLLENCOMBINAT_FLD_PNTID					UNION_MACRO_PNT_ID			//* 点ID				int
#define TBL_INPOLLENCOMBINAT_FLD_SWFGAA					UNION_MACRO_TCDH			//* 采样层位			varchar
#define TBL_INPOLLENCOMBINAT_FLD_TCMC					UNION_MACRO_TCMC			//  土层名称			varchar
#define TBL_INPOLLENCOMBINAT_FLD_GEOCODE				UNION_MACRO_GEOCODE			//  地质代号			varchar
#define TBL_INPOLLENCOMBINAT_FLD_TESTNO					UNION_MACRO_TESTNO			//	试验编号			varchar
#define TBL_INPOLLENCOMBINAT_FLD_TESTCATEGORY			UNION_MACRO_TESTTYPE		//  试验类型			varchar	
#define TBL_INPOLLENCOMBINAT_FLD_POLLENCOMBINAT			"PollenCombinat"		// 孢粉组合				varchar
#define TBL_INPOLLENCOMBINAT_FLD_CLIMATECHARACTER		"ClimateCharacter"		// 古植被古气候特征		varchar
#define TBL_INPOLLENCOMBINAT_FLD_DDCDIA					"DDCDIA"				// 地质时代				varchar
// from 孢粉鉴定数据表
#define TBL_INPOLLENCOMBINAT_FLD_PLANTNAME					"PlantName"			// 植物名称			varchar
#define TBL_INPOLLENCOMBINAT_FLD_GRAINNUM					"GrainNum"			// 粒数				int
#define TBL_INPOLLENCOMBINAT_FLD_CONTENT					"_Content"			// 含量				float	
// from 样品信息表 *
#define TBL_INPOLLENCOMBINAT_FLD_GCEABB					"GCEABB"			// 样品编号			varchar
#define TBL_INPOLLENCOMBINAT_FLD_SWBCF					"SWBCF"				// 样品类型			varchar
#define TBL_INPOLLENCOMBINAT_FLD_ISMIXSAMPLE			"IsMixSample"		// 混合样			varchar
#define TBL_INPOLLENCOMBINAT_FLD_PNTTYPE				"PntType"			// 点类型			varchar
#define TBL_INPOLLENCOMBINAT_FLD_SECONDCODE				"SecondCode"		// 样品二次编码		varchar
#define TBL_INPOLLENCOMBINAT_FLD_SAMPLEVOLUME			"SampleVolume"		// 样品体积			float
#define TBL_INPOLLENCOMBINAT_FLD_GCEABM					"GCEABM"			// 野外命名			varchar
#define TBL_INPOLLENCOMBINAT_FLD_GCEAAL					"GCEAAL"			// 样品重量(kg)		float
#define TBL_INPOLLENCOMBINAT_FLD_SAMPLELENGTH			"SampleLength"		// 样品长度(cm)		varchar
#define TBL_INPOLLENCOMBINAT_FLD_PRETREATMETHOD			"PretreatMethod"	// 预处理方法		varchar
#define TBL_INPOLLENCOMBINAT_FLD_TESTCONTENT			"TestContent"		// 测试内容			varchar
#define TBL_INPOLLENCOMBINAT_FLD_PLANEPOSMAP			"PlanePosMap"		// 平面位置示意图	varchar
#define TBL_INPOLLENCOMBINAT_FLD_PROFILEMAP				"ProfileMap"		// 剖面示意图		varchar
#define TBL_INPOLLENCOMBINAT_FLD_FIELDIMAGE				"FieldImage"		// 野外照片(视频)	varchar
#define TBL_INPOLLENCOMBINAT_FLD_RECORDCARD				"RecordCard"		// 记录卡片(记录)	varchar
#define TBL_INPOLLENCOMBINAT_FLD_SAMPLEORGN				"SampleOrgn"		// 采样单位			varchar
#define TBL_INPOLLENCOMBINAT_FLD_SWFOMW					"SWFOMW"			// 采样人			varchar
#define TBL_INPOLLENCOMBINAT_FLD_GCEABJ					"GCEABJ"			// 采样日期			date
#define TBL_INPOLLENCOMBINAT_FLD_INPUTER				"Inputer"			// 录入员			varchar
#define TBL_INPOLLENCOMBINAT_FLD_INPUTORGN				"InputOrgn"			// 录入单位			varchar
#define TBL_INPOLLENCOMBINAT_FLD_INPUTDATE				"InputDate"			// 录入日期			date
// from 室内测试分析基本情况表
#define TBL_INPOLLENCOMBINAT_FLD_GCEABD					"GCEABD"			// 室内编号				varchar
#define TBL_INPOLLENCOMBINAT_FLD_TESTEQUIP				"TestEquip"			// 试验仪器				varchar
#define TBL_INPOLLENCOMBINAT_FLD_TESTMETHOD				"TestMethod"		// 试验方法				varchar
#define TBL_INPOLLENCOMBINAT_FLD_TESTBASED				"TestBased"			// 检验依据				varchar
#define TBL_INPOLLENCOMBINAT_FLD_GCEAJC					"GCEAJC"			// 试验单位				varchar
#define TBL_INPOLLENCOMBINAT_FLD_SWFGAM					"SWFGAM"			// 收样日期				date
#define TBL_INPOLLENCOMBINAT_FLD_SWFGAN					"SWFGAN"			// 报告日期				date
#define TBL_INPOLLENCOMBINAT_FLD_GCEAJD					"GCEAJD"			// 校对					varchar
#define TBL_INPOLLENCOMBINAT_FLD_AUDITOR				"Auditor"			// 审核					varchar
#define TBL_INPOLLENCOMBINAT_FLD_TESTLEADER				"TestLeader"		// 试验负责人			varchar
#define TBL_INPOLLENCOMBINAT_FLD__REPORT				"_Report"			// 原始测试分析报告		varchar



//化石组合表 -- LH.2021.08.31 changed.
#define TBL_INFOSSILCOMBINAT_TBL "INFossilCombinat"
#define TBL_INFOSSILCOMBINAT_FLD_FOSSILCOMBINATID		"FossilCombinatID"			//* 化石组合ID		int
#define TBL_INFOSSILCOMBINAT_FLD_TOPDEPTH				UNION_MACRO_START_DEPTH		//* 取样顶深度		float
#define TBL_INFOSSILCOMBINAT_FLD_BOTTOMDEPTH			UNION_MACRO_END_DEPTH		//* 取样底深度		float
#define TBL_INFOSSILCOMBINAT_FLD_PNTID					UNION_MACRO_PNT_ID			//* 点ID				int
#define TBL_INFOSSILCOMBINAT_FLD_SWFGAA					UNION_MACRO_TCDH			//* 采样层位			varchar
#define TBL_INFOSSILCOMBINAT_FLD_TCMC					UNION_MACRO_TCMC			//  土层名称			varchar
#define TBL_INFOSSILCOMBINAT_FLD_GEOCODE				UNION_MACRO_GEOCODE			//  地质代号			varchar
#define TBL_INFOSSILCOMBINAT_FLD_TESTNO					UNION_MACRO_TESTNO			//	试验编号			varchar
#define TBL_INFOSSILCOMBINAT_FLD_TESTCATEGORY			UNION_MACRO_TESTTYPE		//  试验类型			varchar	
#define TBL_INFOSSILCOMBINAT_FLD_FOSSILCOMBINAT			"FossilCombinat"			// 化石组合			varchar
#define TBL_INFOSSILCOMBINAT_FLD_CLIMATECHARACTER		"ClimateCharacter"			// 古化石古气候特征	varchar
#define TBL_INFOSSILCOMBINAT_FLD_DDCDIA					"DDCDIA"					// 地质时代			varchar
// from 样品信息表 *
#define TBL_INFOSSILCOMBINAT_FLD_GCEABB					"GCEABB"			// 样品编号			varchar
#define TBL_INFOSSILCOMBINAT_FLD_SWBCF					"SWBCF"				// 样品类型			varchar
#define TBL_INFOSSILCOMBINAT_FLD_ISMIXSAMPLE			"IsMixSample"		// 混合样			varchar
#define TBL_INFOSSILCOMBINAT_FLD_PNTTYPE				"PntType"			// 点类型			varchar
#define TBL_INFOSSILCOMBINAT_FLD_SECONDCODE				"SecondCode"		// 样品二次编码		varchar
#define TBL_INFOSSILCOMBINAT_FLD_SAMPLEVOLUME			"SampleVolume"		// 样品体积			float
#define TBL_INFOSSILCOMBINAT_FLD_GCEABM					"GCEABM"			// 野外命名			varchar
#define TBL_INFOSSILCOMBINAT_FLD_GCEAAL					"GCEAAL"			// 样品重量(kg)		float
#define TBL_INFOSSILCOMBINAT_FLD_SAMPLELENGTH			"SampleLength"		// 样品长度(cm)		varchar
#define TBL_INFOSSILCOMBINAT_FLD_PRETREATMETHOD			"PretreatMethod"	// 预处理方法		varchar
#define TBL_INFOSSILCOMBINAT_FLD_TESTCONTENT			"TestContent"		// 测试内容			varchar
#define TBL_INFOSSILCOMBINAT_FLD_PLANEPOSMAP			"PlanePosMap"		// 平面位置示意图	varchar
#define TBL_INFOSSILCOMBINAT_FLD_PROFILEMAP				"ProfileMap"		// 剖面示意图		varchar
#define TBL_INFOSSILCOMBINAT_FLD_FIELDIMAGE				"FieldImage"		// 野外照片(视频)	varchar
#define TBL_INFOSSILCOMBINAT_FLD_RECORDCARD				"RecordCard"		// 记录卡片(记录)	varchar
#define TBL_INFOSSILCOMBINAT_FLD_SAMPLEORGN				"SampleOrgn"		// 采样单位			varchar
#define TBL_INFOSSILCOMBINAT_FLD_SWFOMW					"SWFOMW"			// 采样人			varchar
#define TBL_INFOSSILCOMBINAT_FLD_GCEABJ					"GCEABJ"			// 采样日期			date
#define TBL_INFOSSILCOMBINAT_FLD_INPUTER				"Inputer"			// 录入员			varchar
#define TBL_INFOSSILCOMBINAT_FLD_INPUTORGN				"InputOrgn"			// 录入单位			varchar
#define TBL_INFOSSILCOMBINAT_FLD_INPUTDATE				"InputDate"			// 录入日期			date
// from 室内测试分析基本情况表
#define TBL_INFOSSILCOMBINAT_FLD_GCEABD				"GCEABD"					// 室内编号				varchar
#define TBL_INFOSSILCOMBINAT_FLD_TESTEQUIP			"TestEquip"					// 试验仪器				varchar
#define TBL_INFOSSILCOMBINAT_FLD_TESTMETHOD			"TestMethod"				// 试验方法				varchar
#define TBL_INFOSSILCOMBINAT_FLD_TESTBASED			"TestBased"					// 检验依据				varchar
#define TBL_INFOSSILCOMBINAT_FLD_GCEAJC				"GCEAJC"					// 试验单位				varchar
#define TBL_INFOSSILCOMBINAT_FLD_SWFGAM				"SWFGAM"					// 收样日期				date
#define TBL_INFOSSILCOMBINAT_FLD_SWFGAN				"SWFGAN"					// 报告日期				date
#define TBL_INFOSSILCOMBINAT_FLD_GCEAJD				"GCEAJD"					// 校对					varchar
#define TBL_INFOSSILCOMBINAT_FLD_AUDITOR			"Auditor"					// 审核					varchar
#define TBL_INFOSSILCOMBINAT_FLD_TESTLEADER			"TestLeader"				// 试验负责人			varchar
#define TBL_INFOSSILCOMBINAT_FLD__REPORT			"_Report"					// 原始测试分析报告		varchar

//化石鉴定数据表 -- LH.2021.08.31 changed.
#define TBL_INFOSSILIDENT_TBL "INFossilIdent"
#define TBL_INFOSSILIDENT_FLD_FOSSILID			"FossilID"					//* 化石ID		int
#define TBL_INFOSSILIDENT_FLD_TOPDEPTH			UNION_MACRO_START_DEPTH		//* 取样顶深度		float
#define TBL_INFOSSILIDENT_FLD_BOTTOMDEPTH		UNION_MACRO_END_DEPTH		//* 取样底深度		float
#define TBL_INFOSSILIDENT_FLD_PNTID				UNION_MACRO_PNT_ID			//* 点ID				int
#define TBL_INFOSSILIDENT_FLD_SWFGAA			UNION_MACRO_TCDH			//* 采样层位			varchar
#define TBL_INFOSSILIDENT_FLD_TCMC				UNION_MACRO_TCMC			//  土层名称			varchar
#define TBL_INFOSSILIDENT_FLD_GEOCODE			UNION_MACRO_GEOCODE			//  地质代号			varchar
#define TBL_INFOSSILIDENT_FLD_TESTNO			UNION_MACRO_TESTNO			//	试验编号			varchar
#define TBL_INFOSSILIDENT_FLD_TESTCATEGORY		UNION_MACRO_TESTTYPE		//  试验类型			varchar	
#define TBL_INFOSSILIDENT_FLD_FOSSILNAME		"FossilName"				// 化石名称		varchar
#define TBL_INFOSSILIDENT_FLD_QUANTITY			"_Quantity"					// 数量			int
#define TBL_INFOSSILIDENT_FLD__ONTENT			"_Content"					// 含量			float
// from 室内测试分析基本情况表
#define TBL_INFOSSILIDENT_FLD_GCEABD			"GCEABD"					// 室内编号				varchar
#define TBL_INFOSSILIDENT_FLD_TESTEQUIP			"TestEquip"					// 试验仪器				varchar
#define TBL_INFOSSILIDENT_FLD_TESTMETHOD		"TestMethod"				// 试验方法				varchar
#define TBL_INFOSSILIDENT_FLD_TESTBASED			"TestBased"					// 检验依据				varchar
#define TBL_INFOSSILIDENT_FLD_GCEAJC			"GCEAJC"					// 试验单位				varchar
#define TBL_INFOSSILIDENT_FLD_SWFGAM			"SWFGAM"					// 收样日期				date
#define TBL_INFOSSILIDENT_FLD_SWFGAN			"SWFGAN"					// 报告日期				date
#define TBL_INFOSSILIDENT_FLD_GCEAJD			"GCEAJD"					// 校对					varchar
#define TBL_INFOSSILIDENT_FLD_AUDITOR			"Auditor"					// 审核					varchar
#define TBL_INFOSSILIDENT_FLD_TESTLEADER		"TestLeader"				// 试验负责人			varchar
#define TBL_INFOSSILIDENT_FLD__REPORT			"_Report"					// 原始测试分析报告		varchar
// from 样品信息表 *
#define TBL_INFOSSILIDENT_FLD_GCEABB					"GCEABB"			// 样品编号			varchar
#define TBL_INFOSSILIDENT_FLD_SWBCF						"SWBCF"				// 样品类型			varchar
#define TBL_INFOSSILIDENT_FLD_ISMIXSAMPLE				"IsMixSample"		// 混合样			varchar
#define TBL_INFOSSILIDENT_FLD_PNTTYPE					"PntType"			// 点类型			varchar
#define TBL_INFOSSILIDENT_FLD_SECONDCODE				"SecondCode"		// 样品二次编码		varchar
#define TBL_INFOSSILIDENT_FLD_SAMPLEVOLUME				"SampleVolume"		// 样品体积			float
#define TBL_INFOSSILIDENT_FLD_GCEABM					"GCEABM"			// 野外命名			varchar
#define TBL_INFOSSILIDENT_FLD_GCEAAL					"GCEAAL"			// 样品重量(kg)		float
#define TBL_INFOSSILIDENT_FLD_SAMPLELENGTH				"SampleLength"		// 样品长度(cm)		varchar
#define TBL_INFOSSILIDENT_FLD_PRETREATMETHOD			"PretreatMethod"	// 预处理方法		varchar
#define TBL_INFOSSILIDENT_FLD_TESTCONTENT				"TestContent"		// 测试内容			varchar
#define TBL_INFOSSILIDENT_FLD_PLANEPOSMAP				"PlanePosMap"		// 平面位置示意图	varchar
#define TBL_INFOSSILIDENT_FLD_PROFILEMAP				"ProfileMap"		// 剖面示意图		varchar
#define TBL_INFOSSILIDENT_FLD_FIELDIMAGE				"FieldImage"		// 野外照片(视频)	varchar
#define TBL_INFOSSILIDENT_FLD_RECORDCARD				"RecordCard"		// 记录卡片(记录)	varchar
#define TBL_INFOSSILIDENT_FLD_SAMPLEORGN				"SampleOrgn"		// 采样单位			varchar
#define TBL_INFOSSILIDENT_FLD_SWFOMW					"SWFOMW"			// 采样人			varchar
#define TBL_INFOSSILIDENT_FLD_GCEABJ					"GCEABJ"			// 采样日期			date
#define TBL_INFOSSILIDENT_FLD_INPUTER					"Inputer"			// 录入员			varchar
#define TBL_INFOSSILIDENT_FLD_INPUTORGN					"InputOrgn"			// 录入单位			varchar
#define TBL_INFOSSILIDENT_FLD_INPUTDATE					"InputDate"			// 录入日期			date


//古地磁测试成果表 -- LH.2021.08.31 changed.
#define TBL_INPALEOMAGNETIC_TBL "INPaleomagnetic"
#define TBL_INPALEOMAGNETIC_FLD_PALEOMAGNETICID			"PaleomagneticID"		//* 古地磁ID		int
#define TBL_INPALEOMAGNETIC_FLD_TOPDEPTH				UNION_MACRO_START_DEPTH		//* 取样顶深度		float
#define TBL_INPALEOMAGNETIC_FLD_BOTTOMDEPTH				UNION_MACRO_END_DEPTH		//* 取样底深度		float
#define TBL_INPALEOMAGNETIC_FLD_PNTID					UNION_MACRO_PNT_ID			//* 点ID				int
#define TBL_INPALEOMAGNETIC_FLD_SWFGAA					UNION_MACRO_TCDH			//* 采样层位			varchar
#define TBL_INPALEOMAGNETIC_FLD_TCMC					UNION_MACRO_TCMC			//  土层名称			varchar
#define TBL_INPALEOMAGNETIC_FLD_GEOCODE					UNION_MACRO_GEOCODE			//  地质代号			varchar
#define TBL_INPALEOMAGNETIC_FLD_TESTNO					UNION_MACRO_TESTNO			//	试验编号			varchar
#define TBL_INPALEOMAGNETIC_FLD_TESTCATEGORY			UNION_MACRO_TESTTYPE		//  试验类型			varchar	
#define TBL_INPALEOMAGNETIC_FLD_POLAREVENT				"PolarEvent"			// 极性事件		varchar
#define TBL_INPALEOMAGNETIC_FLD_POLARCOLUMN				"PolarColumn"			// 极性柱		varchar
#define TBL_INPALEOMAGNETIC_FLD_MAGNETICDECLINAT		"Magneticdeclinat"		// 磁偏角		float
#define TBL_INPALEOMAGNETIC_FLD_LAYERAGEUNIT			"LayerAgeUnit"			// 年代地层单位	varchar
// from 样品信息表 *
#define TBL_INPALEOMAGNETIC_FLD_GCEABB					"GCEABB"			// 样品编号			varchar
#define TBL_INPALEOMAGNETIC_FLD_SWBCF					"SWBCF"				// 样品类型			varchar
#define TBL_INPALEOMAGNETIC_FLD_ISMIXSAMPLE				"IsMixSample"		// 混合样			varchar
#define TBL_INPALEOMAGNETIC_FLD_PNTTYPE					"PntType"			// 点类型			varchar
#define TBL_INPALEOMAGNETIC_FLD_SECONDCODE				"SecondCode"		// 样品二次编码		varchar
#define TBL_INPALEOMAGNETIC_FLD_SAMPLEVOLUME			"SampleVolume"		// 样品体积			float
#define TBL_INPALEOMAGNETIC_FLD_GCEABM					"GCEABM"			// 野外命名			varchar
#define TBL_INPALEOMAGNETIC_FLD_GCEAAL					"GCEAAL"			// 样品重量(kg)		float
#define TBL_INPALEOMAGNETIC_FLD_SAMPLELENGTH			"SampleLength"		// 样品长度(cm)		varchar
#define TBL_INPALEOMAGNETIC_FLD_PRETREATMETHOD			"PretreatMethod"	// 预处理方法		varchar
#define TBL_INPALEOMAGNETIC_FLD_TESTCONTENT				"TestContent"		// 测试内容			varchar
#define TBL_INPALEOMAGNETIC_FLD_PLANEPOSMAP				"PlanePosMap"		// 平面位置示意图	varchar
#define TBL_INPALEOMAGNETIC_FLD_PROFILEMAP				"ProfileMap"		// 剖面示意图		varchar
#define TBL_INPALEOMAGNETIC_FLD_FIELDIMAGE				"FieldImage"		// 野外照片(视频)	varchar
#define TBL_INPALEOMAGNETIC_FLD_RECORDCARD				"RecordCard"		// 记录卡片(记录)	varchar
#define TBL_INPALEOMAGNETIC_FLD_SAMPLEORGN				"SampleOrgn"		// 采样单位			varchar
#define TBL_INPALEOMAGNETIC_FLD_SWFOMW					"SWFOMW"			// 采样人			varchar
#define TBL_INPALEOMAGNETIC_FLD_GCEABJ					"GCEABJ"			// 采样日期			date
#define TBL_INPALEOMAGNETIC_FLD_INPUTER					"Inputer"			// 录入员			varchar
#define TBL_INPALEOMAGNETIC_FLD_INPUTORGN				"InputOrgn"			// 录入单位			varchar
#define TBL_INPALEOMAGNETIC_FLD_INPUTDATE				"InputDate"			// 录入日期			date
// from 室内测试分析基本情况表
#define TBL_INPALEOMAGNETIC_FLD_GCEABD					"GCEABD"				// 室内编号				varchar
#define TBL_INPALEOMAGNETIC_FLD_TESTEQUIP				"TestEquip"				// 试验仪器				varchar
#define TBL_INPALEOMAGNETIC_FLD_TESTMETHOD				"TestMethod"			// 试验方法				varchar
#define TBL_INPALEOMAGNETIC_FLD_TESTBASED				"TestBased"				// 检验依据				varchar
#define TBL_INPALEOMAGNETIC_FLD_GCEAJC					"GCEAJC"				// 试验单位				varchar
#define TBL_INPALEOMAGNETIC_FLD_SWFGAM					"SWFGAM"				// 收样日期				date
#define TBL_INPALEOMAGNETIC_FLD_SWFGAN					"SWFGAN"				// 报告日期				date
#define TBL_INPALEOMAGNETIC_FLD_GCEAJD					"GCEAJD"				// 校对					varchar
#define TBL_INPALEOMAGNETIC_FLD_AUDITOR					"Auditor"				// 审核					varchar
#define TBL_INPALEOMAGNETIC_FLD_TESTLEADER				"TestLeader"			// 试验负责人			varchar
#define TBL_INPALEOMAGNETIC_FLD__REPORT					"_Report"				// 原始测试分析报告		varchar

//水腐蚀性分析 -- LH.2021.08.31 changed.
#define TBL_INWATERCAUSTICITY_TBL "INWaterCausticity"
#define TBL_INWATERCAUSTICITY_FLD_WATERCAUSTICITYID		"WaterCausticityID"			//* 水腐蚀ID				int
#define TBL_INWATERCAUSTICITY_FLD_TOPDEPTH				UNION_MACRO_START_DEPTH		//* 取样顶深度		float
#define TBL_INWATERCAUSTICITY_FLD_BOTTOMDEPTH			UNION_MACRO_END_DEPTH		//* 取样底深度		float
#define TBL_INWATERCAUSTICITY_FLD_PNTID					UNION_MACRO_PNT_ID			//* 点ID				int
#define TBL_INWATERCAUSTICITY_FLD_SWFGAA				UNION_MACRO_TCDH			//* 采样层位			varchar
#define TBL_INWATERCAUSTICITY_FLD_TCMC					UNION_MACRO_TCMC			//  土层名称			varchar
#define TBL_INWATERCAUSTICITY_FLD_GEOCODE				UNION_MACRO_GEOCODE			//  地质代号			varchar
#define TBL_INWATERCAUSTICITY_FLD_TESTNO				UNION_MACRO_TESTNO			//	试验编号			varchar
#define TBL_INWATERCAUSTICITY_FLD_TESTCATEGORY			UNION_MACRO_TESTTYPE		//  试验类型			varchar	
#define TBL_INWATERCAUSTICITY_FLD_KNA					"NAK"					//	K+、Na+				float
#define TBL_INWATERCAUSTICITY_FLD_SWFHFA				"SWFHFA"				// Ca2+(mg/L)			float
#define TBL_INWATERCAUSTICITY_FLD_SWFHFB				"SWFHFB"				// Mg2+(mg/L)			float
#define TBL_INWATERCAUSTICITY_FLD_NH4				"NH4"				// NH4+(mg/L)			float
#define TBL_INWATERCAUSTICITY_FLD_NO3				"NO3"					// NO3-(mg/L)			float
#define TBL_INWATERCAUSTICITY_FLD_SWFHFF				"SWFHFF"				// Cl-(mg/L)			float
#define TBL_INWATERCAUSTICITY_FLD_SWFHFG				"SWFHFG"				// SO42-(mg/L)			float
#define TBL_INWATERCAUSTICITY_FLD_SWFHFI				"SWFHFI"				// CO32-(mmol/L)		float
#define TBL_INWATERCAUSTICITY_FLD_SWFHFH				"SWFHFH"				// HCO3-(mmol/L)		float
#define TBL_INWATERCAUSTICITY_FLD_CL					"CL"					// CL-(mmol/L)			float
#define TBL_INWATERCAUSTICITY_FLD_ZJD					"ZJD"					// 总碱度(mg/L)			float
#define TBL_INWATERCAUSTICITY_FLD_CAUSTIC				"Caustic"				// 苛性碱OH-(mg/L)		float
#define TBL_INWATERCAUSTICITY_FLD_SWFHE					"SWFHE"					// 矿化度(mg/L)			float
#define TBL_INWATERCAUSTICITY_FLD_LZZL					"LZHD"					// 离子总量				float
#define TBL_INWATERCAUSTICITY_FLD_RJXGTZL				"RJXGTZL"				// 溶解性固体总量（mg/L） float
#define TBL_INWATERCAUSTICITY_FLD_PH					"PH"					// pH					float
#define TBL_INWATERCAUSTICITY_FLD_SWFHI					"SWFHI"					// 侵蚀CO2(mg/L)			float
#define TBL_INWATERCAUSTICITY_FLD_SWFHG					"SWFHG"					// 游离CO2(mg/L) 		float
#define TBL_INWATERCAUSTICITY_FLD_ZYD					"ZYD"					// 总硬度		 		float
#define TBL_INWATERCAUSTICITY_FLD_ZSYD					"ZSYD"					// 暂时硬度		 		float
#define TBL_INWATERCAUSTICITY_FLD_YJYD					"YJYD"					// 永久硬度		 		float
#define TBL_INWATERCAUSTICITY_FLD_FYD					"FYD"					// 负硬度		 		float
#define TBL_INWATERCAUSTICITY_FLD_HNTJG					"HNTJG"					// 混凝土结构		 	varchar
#define TBL_INWATERCAUSTICITY_FLD_GJ	  				"GJ"					// 钢筋		 			varchar
// from 样品信息表 *
#define TBL_INWATERCAUSTICITY_FLD_GCEABB					"GCEABB"			// 样品编号			varchar
#define TBL_INWATERCAUSTICITY_FLD_SWBCF						"SWBCF"				// 样品类型			varchar
#define TBL_INWATERCAUSTICITY_FLD_ISMIXSAMPLE				"IsMixSample"		// 混合样			varchar
#define TBL_INWATERCAUSTICITY_FLD_PNTTYPE					"PntType"			// 点类型			varchar
#define TBL_INWATERCAUSTICITY_FLD_SECONDCODE				"SecondCode"		// 样品二次编码		varchar
#define TBL_INWATERCAUSTICITY_FLD_SAMPLEVOLUME				"SampleVolume"		// 样品体积			float
#define TBL_INWATERCAUSTICITY_FLD_GCEABM					"GCEABM"			// 野外命名			varchar
#define TBL_INWATERCAUSTICITY_FLD_GCEAAL					"GCEAAL"			// 样品重量(kg)		float
#define TBL_INWATERCAUSTICITY_FLD_SAMPLELENGTH				"SampleLength"		// 样品长度(cm)		varchar
#define TBL_INWATERCAUSTICITY_FLD_PRETREATMETHOD			"PretreatMethod"	// 预处理方法		varchar
#define TBL_INWATERCAUSTICITY_FLD_TESTCONTENT				"TestContent"		// 测试内容			varchar
#define TBL_INWATERCAUSTICITY_FLD_PLANEPOSMAP				"PlanePosMap"		// 平面位置示意图	varchar
#define TBL_INWATERCAUSTICITY_FLD_PROFILEMAP				"ProfileMap"		// 剖面示意图		varchar
#define TBL_INWATERCAUSTICITY_FLD_FIELDIMAGE				"FieldImage"		// 野外照片(视频)	varchar
#define TBL_INWATERCAUSTICITY_FLD_RECORDCARD				"RecordCard"		// 记录卡片(记录)	varchar
#define TBL_INWATERCAUSTICITY_FLD_SAMPLEORGN				"SampleOrgn"		// 采样单位			varchar
#define TBL_INWATERCAUSTICITY_FLD_SWFOMW					"SWFOMW"			// 采样人			varchar
#define TBL_INWATERCAUSTICITY_FLD_GCEABJ					"GCEABJ"			// 采样日期			date
#define TBL_INWATERCAUSTICITY_FLD_INPUTER					"Inputer"			// 录入员			varchar
#define TBL_INWATERCAUSTICITY_FLD_INPUTORGN					"InputOrgn"			// 录入单位			varchar
#define TBL_INWATERCAUSTICITY_FLD_INPUTDATE					"InputDate"			// 录入日期			date
// from 室内测试分析基本情况表
#define TBL_INWATERCAUSTICITY_FLD_GCEABD				"GCEABD"				// 室内编号				varchar
#define TBL_INWATERCAUSTICITY_FLD_TESTEQUIP				"TestEquip"				// 试验仪器				varchar
#define TBL_INWATERCAUSTICITY_FLD_TESTMETHOD			"TestMethod"			// 试验方法				varchar
#define TBL_INWATERCAUSTICITY_FLD_TESTBASED				"TestBased"				// 检验依据				varchar
#define TBL_INWATERCAUSTICITY_FLD_GCEAJC				"GCEAJC"				// 试验单位				varchar
#define TBL_INWATERCAUSTICITY_FLD_SWFGAM				"SWFGAM"				// 收样日期				date
#define TBL_INWATERCAUSTICITY_FLD_SWFGAN				"SWFGAN"				// 报告日期				date
#define TBL_INWATERCAUSTICITY_FLD_GCEAJD				"GCEAJD"				// 校对					varchar
#define TBL_INWATERCAUSTICITY_FLD_AUDITOR				"Auditor"				// 审核					varchar
#define TBL_INWATERCAUSTICITY_FLD_TESTLEADER			"TestLeader"			// 试验负责人			varchar
#define TBL_INWATERCAUSTICITY_FLD__REPORT				"_Report"				// 原始测试分析报告		varchar

//土腐蚀性分析 -- LH.2021.08.31 changed.
#define TBL_INSOILCAUSTICITY_TBL "INSoilCausticity"
#define TBL_INSOILCAUSTICITY_FLD_SOILCORROSIONID		"SoilCorrosionID"			//* 土腐蚀ID				int
#define TBL_INSOILCAUSTICITY_FLD_TOPDEPTH				UNION_MACRO_START_DEPTH		//* 取样顶深度		float
#define TBL_INSOILCAUSTICITY_FLD_BOTTOMDEPTH			UNION_MACRO_END_DEPTH		//* 取样底深度		float
#define TBL_INSOILCAUSTICITY_FLD_PNTID					UNION_MACRO_PNT_ID			//* 点ID				int
#define TBL_INSOILCAUSTICITY_FLD_SWFGAA					UNION_MACRO_TCDH			//* 采样层位			varchar
#define TBL_INSOILCAUSTICITY_FLD_TCMC					UNION_MACRO_TCMC			//  土层名称			varchar
#define TBL_INSOILCAUSTICITY_FLD_GEOCODE				UNION_MACRO_GEOCODE			//  地质代号			varchar
#define TBL_INSOILCAUSTICITY_FLD_TESTNO					UNION_MACRO_TESTNO			//	试验编号			varchar
#define TBL_INSOILCAUSTICITY_FLD_TESTCATEGORY			UNION_MACRO_TESTTYPE		//  试验类型			varchar	
#define TBL_INSOILCAUSTICITY_FLD_SWFHFA					"SWFHFA"				// Ca2+(mg/kg)			float
#define TBL_INSOILCAUSTICITY_FLD_SWFHFB					"SWFHFB"				// Mg2+(mg/kg)			float
#define TBL_INSOILCAUSTICITY_FLD_SWFHFF					"SWFHFF"				// Cl-(mg/kg)			float
#define TBL_INSOILCAUSTICITY_FLD_SWFHFG					"SWFHFG"				// SO42-(mg/kg)			float
#define TBL_INSOILCAUSTICITY_FLD_SWFHFH					"SWFHFH"				// HCO3-(mg/kg)			float
#define TBL_INSOILCAUSTICITY_FLD_SWFHFI					"SWFHFI"				// CO32-(mg/kg)			float
#define TBL_INSOILCAUSTICITY_FLD_SWFHFJ					"SWFHFJ"				// NH4+ (mg/kg)			float
#define TBL_INSOILCAUSTICITY_FLD_PH						"PH"					// pH					float
#define TBL_INSOILCAUSTICITY_FLD_KWAAJG					"KWAAJG"				// Eh(mV)				float
#define TBL_INSOILCAUSTICITY_FLD_RESISTIVITY			"Resistivity"			// 电阻率(Ω·m)			 float
#define TBL_INSOILCAUSTICITY_FLD_POLARIZATDENSITY		"Polarizatdensity"		// 极化电流密度 (mA/cm2) float
#define TBL_INSOILCAUSTICITY_FLD_MASSLOSS				"Massloss"				// 质量损失(g)			 float
#define TBL_INSOILCAUSTICITY_FLD_HNTJG					"HNTJG"					// 混凝土结构		 	varchar
#define TBL_INSOILCAUSTICITY_FLD_GJ	  					"GJ"					// 钢筋		 			varchar
#define TBL_INSOILCAUSTICITY_FLD_GJG	  				"GJG"					// 钢结构	 			varchar
// from 样品信息表 *
#define TBL_INSOILCAUSTICITY_FLD_GCEABB					"GCEABB"			// 样品编号			varchar
#define TBL_INSOILCAUSTICITY_FLD_SWBCF					"SWBCF"				// 样品类型			varchar
#define TBL_INSOILCAUSTICITY_FLD_ISMIXSAMPLE			"IsMixSample"		// 混合样			varchar
#define TBL_INSOILCAUSTICITY_FLD_PNTTYPE				"PntType"			// 点类型			varchar
#define TBL_INSOILCAUSTICITY_FLD_SECONDCODE				"SecondCode"		// 样品二次编码		varchar
#define TBL_INSOILCAUSTICITY_FLD_SAMPLEVOLUME			"SampleVolume"		// 样品体积			float
#define TBL_INSOILCAUSTICITY_FLD_GCEABM					"GCEABM"			// 野外命名			varchar
#define TBL_INSOILCAUSTICITY_FLD_GCEAAL					"GCEAAL"			// 样品重量(kg)		float
#define TBL_INSOILCAUSTICITY_FLD_SAMPLELENGTH			"SampleLength"		// 样品长度(cm)		varchar
#define TBL_INSOILCAUSTICITY_FLD_PRETREATMETHOD			"PretreatMethod"	// 预处理方法		varchar
#define TBL_INSOILCAUSTICITY_FLD_TESTCONTENT			"TestContent"		// 测试内容			varchar
#define TBL_INSOILCAUSTICITY_FLD_PLANEPOSMAP			"PlanePosMap"		// 平面位置示意图	varchar
#define TBL_INSOILCAUSTICITY_FLD_PROFILEMAP				"ProfileMap"		// 剖面示意图		varchar
#define TBL_INSOILCAUSTICITY_FLD_FIELDIMAGE				"FieldImage"		// 野外照片(视频)	varchar
#define TBL_INSOILCAUSTICITY_FLD_RECORDCARD				"RecordCard"		// 记录卡片(记录)	varchar
#define TBL_INSOILCAUSTICITY_FLD_SAMPLEORGN				"SampleOrgn"		// 采样单位			varchar
#define TBL_INSOILCAUSTICITY_FLD_SWFOMW					"SWFOMW"			// 采样人			varchar
#define TBL_INSOILCAUSTICITY_FLD_GCEABJ					"GCEABJ"			// 采样日期			date
#define TBL_INSOILCAUSTICITY_FLD_INPUTER				"Inputer"			// 录入员			varchar
#define TBL_INSOILCAUSTICITY_FLD_INPUTORGN				"InputOrgn"			// 录入单位			varchar
#define TBL_INSOILCAUSTICITY_FLD_INPUTDATE				"InputDate"			// 录入日期			date
// from 室内测试分析基本情况表
#define TBL_INSOILCAUSTICITY_FLD_GCEABD					"GCEABD"				// 室内编号				varchar
#define TBL_INSOILCAUSTICITY_FLD_TESTEQUIP				"TestEquip"				// 试验仪器				varchar
#define TBL_INSOILCAUSTICITY_FLD_TESTMETHOD				"TestMethod"			// 试验方法				varchar
#define TBL_INSOILCAUSTICITY_FLD_TESTBASED				"TestBased"				// 检验依据				varchar
#define TBL_INSOILCAUSTICITY_FLD_GCEAJC					"GCEAJC"				// 试验单位				varchar
#define TBL_INSOILCAUSTICITY_FLD_SWFGAM					"SWFGAM"				// 收样日期				date
#define TBL_INSOILCAUSTICITY_FLD_SWFGAN					"SWFGAN"				// 报告日期				date
#define TBL_INSOILCAUSTICITY_FLD_GCEAJD					"GCEAJD"				// 校对					varchar
#define TBL_INSOILCAUSTICITY_FLD_AUDITOR				"Auditor"				// 审核					varchar
#define TBL_INSOILCAUSTICITY_FLD_TESTLEADER				"TestLeader"			// 试验负责人			varchar
#define TBL_INSOILCAUSTICITY_FLD__REPORT				"_Report"				// 原始测试分析报告		varchar

//地球化学分析数据表 -- LH.2021.08.31 changed.
#define TBL_INGEOCHEMICALIDENT_TBL "INGeochemicalIdent"
#define TBL_INGEOCHEMICALIDENT_FLD_CHEANALYSISID		"CheanalysisID"		//* 化学分析ID			int
#define TBL_INGEOCHEMICALIDENT_FLD_TOPDEPTH				UNION_MACRO_START_DEPTH		//* 取样顶深度		float
#define TBL_INGEOCHEMICALIDENT_FLD_BOTTOMDEPTH			UNION_MACRO_END_DEPTH		//* 取样底深度		float
#define TBL_INGEOCHEMICALIDENT_FLD_PNTID				UNION_MACRO_PNT_ID			//* 点ID				int
#define TBL_INGEOCHEMICALIDENT_FLD_SWFGAA				UNION_MACRO_TCDH			//* 采样层位			varchar
#define TBL_INGEOCHEMICALIDENT_FLD_TCMC					UNION_MACRO_TCMC			//  土层名称			varchar
#define TBL_INGEOCHEMICALIDENT_FLD_GEOCODE				UNION_MACRO_GEOCODE			//  地质代号			varchar
#define TBL_INGEOCHEMICALIDENT_FLD_TESTNO				UNION_MACRO_TESTNO			//	试验编号			varchar
#define TBL_INGEOCHEMICALIDENT_FLD_TESTCATEGORY			UNION_MACRO_TESTTYPE		//  试验类型			varchar	
#define TBL_INGEOCHEMICALIDENT_FLD_ANALYSISINDEX		"AnalysisIndex"		// 分析指标			varchar
#define TBL_INGEOCHEMICALIDENT_FLD_CHEMICALCODE			"ChemicalCode"		// 化学代号			varchar
#define TBL_INGEOCHEMICALIDENT_FLD_NUMERICALUNIT		"NumericalUnit"		// 数值单位			varchar
#define TBL_INGEOCHEMICALIDENT_FLD_ANALYSISRESULT		"AnalysisResult"	// 分析结果			varchar
// from 样品信息表 *
#define TBL_INGEOCHEMICALIDENT_FLD_GCEABB					"GCEABB"			// 样品编号			varchar
#define TBL_INGEOCHEMICALIDENT_FLD_SWBCF					"SWBCF"				// 样品类型			varchar
#define TBL_INGEOCHEMICALIDENT_FLD_ISMIXSAMPLE				"IsMixSample"		// 混合样			varchar
#define TBL_INGEOCHEMICALIDENT_FLD_PNTTYPE					"PntType"			// 点类型			varchar
#define TBL_INGEOCHEMICALIDENT_FLD_SECONDCODE				"SecondCode"		// 样品二次编码		varchar
#define TBL_INGEOCHEMICALIDENT_FLD_SAMPLEVOLUME				"SampleVolume"		// 样品体积			float
#define TBL_INGEOCHEMICALIDENT_FLD_GCEABM					"GCEABM"			// 野外命名			varchar
#define TBL_INGEOCHEMICALIDENT_FLD_GCEAAL					"GCEAAL"			// 样品重量(kg)		float
#define TBL_INGEOCHEMICALIDENT_FLD_SAMPLELENGTH				"SampleLength"		// 样品长度(cm)		varchar
#define TBL_INGEOCHEMICALIDENT_FLD_PRETREATMETHOD			"PretreatMethod"	// 预处理方法		varchar
#define TBL_INGEOCHEMICALIDENT_FLD_TESTCONTENT				"TestContent"		// 测试内容			varchar
#define TBL_INGEOCHEMICALIDENT_FLD_PLANEPOSMAP				"PlanePosMap"		// 平面位置示意图	varchar
#define TBL_INGEOCHEMICALIDENT_FLD_PROFILEMAP				"ProfileMap"		// 剖面示意图		varchar
#define TBL_INGEOCHEMICALIDENT_FLD_FIELDIMAGE				"FieldImage"		// 野外照片(视频)	varchar
#define TBL_INGEOCHEMICALIDENT_FLD_RECORDCARD				"RecordCard"		// 记录卡片(记录)	varchar
#define TBL_INGEOCHEMICALIDENT_FLD_SAMPLEORGN				"SampleOrgn"		// 采样单位			varchar
#define TBL_INGEOCHEMICALIDENT_FLD_SWFOMW					"SWFOMW"			// 采样人			varchar
#define TBL_INGEOCHEMICALIDENT_FLD_GCEABJ					"GCEABJ"			// 采样日期			date
#define TBL_INGEOCHEMICALIDENT_FLD_INPUTER					"Inputer"			// 录入员			varchar
#define TBL_INGEOCHEMICALIDENT_FLD_INPUTORGN				"InputOrgn"			// 录入单位			varchar
#define TBL_INGEOCHEMICALIDENT_FLD_INPUTDATE				"InputDate"			// 录入日期			date
// from 室内测试分析基本情况表
#define TBL_INGEOCHEMICALIDENT_FLD_GCEABD				"GCEABD"			// 室内编号				varchar
#define TBL_INGEOCHEMICALIDENT_FLD_TESTEQUIP			"TestEquip"			// 试验仪器				varchar
#define TBL_INGEOCHEMICALIDENT_FLD_TESTMETHOD			"TestMethod"		// 试验方法				varchar
#define TBL_INGEOCHEMICALIDENT_FLD_TESTBASED			"TestBased"			// 检验依据				varchar
#define TBL_INGEOCHEMICALIDENT_FLD_GCEAJC				"GCEAJC"			// 试验单位				varchar
#define TBL_INGEOCHEMICALIDENT_FLD_SWFGAM				"SWFGAM"			// 收样日期				date
#define TBL_INGEOCHEMICALIDENT_FLD_SWFGAN				"SWFGAN"			// 报告日期				date
#define TBL_INGEOCHEMICALIDENT_FLD_GCEAJD				"GCEAJD"			// 校对					varchar
#define TBL_INGEOCHEMICALIDENT_FLD_AUDITOR				"Auditor"			// 审核					varchar
#define TBL_INGEOCHEMICALIDENT_FLD_TESTLEADER			"TestLeader"		// 试验负责人			varchar
#define TBL_INGEOCHEMICALIDENT_FLD__REPORT				"_Report"			// 原始测试分析报告		varchar

// 工勘孔土的易溶性分析 -- LH.2021.08.31 11:24 added.
#define TBL_TYRXFXSJ_TBL "Tyrxfxsj"
#define TBL_TYRXFXSJ_FLD_TYRXFXSJID				"TyrxfxsjID"		//* ID					int
#define TBL_TYRXFXSJ_FLD_TOPDEPTH				UNION_MACRO_START_DEPTH		//* 取样顶深度		float
#define TBL_TYRXFXSJ_FLD_BOTTOMDEPTH			UNION_MACRO_END_DEPTH		//* 取样底深度		float
#define TBL_TYRXFXSJ_FLD_PNTID					UNION_MACRO_PNT_ID			//* 点ID				int
#define TBL_TYRXFXSJ_FLD_SWFGAA					UNION_MACRO_TCDH			//* 采样层位			varchar
#define TBL_TYRXFXSJ_FLD_TCMC					UNION_MACRO_TCMC			//  土层名称			varchar
#define TBL_TYRXFXSJ_FLD_GEOCODE				UNION_MACRO_GEOCODE			//  地质代号			varchar
#define TBL_TYRXFXSJ_FLD_TESTNO					UNION_MACRO_TESTNO			//	试验编号			varchar
#define TBL_TYRXFXSJ_FLD_TESTCATEGORY			UNION_MACRO_TESTTYPE		//  试验类型			varchar	
#define TBL_TYRXFXSJ_FLD_FXDATE					"FXDATE"			// 分析日期			varchar
#define TBL_TYRXFXSJ_FLD_NAK					"NAK"				// K+和Na+易溶性	double
#define TBL_TYRXFXSJ_FLD_CA						"CA"				// Ca2+易溶性			double
#define TBL_TYRXFXSJ_FLD_MG						"MG"				// Mg2+易溶性			double
#define TBL_TYRXFXSJ_FLD_CO3					"CO3"				// CO32-易溶性		double
#define TBL_TYRXFXSJ_FLD_HCO3					"HCO3"				// HCO32-易溶性		double
#define TBL_TYRXFXSJ_FLD_SO4					"SO4"				// SO42-易溶性		double
#define TBL_TYRXFXSJ_FLD_CL						"CL"				// Cl-易溶性			double
#define TBL_TYRXFXSJ_FLD_YD						"YD"				// 硬度易溶性			double
#define TBL_TYRXFXSJ_FLD_LZZL					"LZZL"				// 离子总量				double
#define TBL_TYRXFXSJ_FLD_PH						"PH"				// PH值					double
// from 样品信息表 *
#define TBL_TYRXFXSJ_FLD_GCEABB					"GCEABB"			// 样品编号			varchar
#define TBL_TYRXFXSJ_FLD_SWBCF					"SWBCF"				// 样品类型			varchar
#define TBL_TYRXFXSJ_FLD_ISMIXSAMPLE			"IsMixSample"		// 混合样			varchar
#define TBL_TYRXFXSJ_FLD_PNTTYPE				"PntType"			// 点类型			varchar
#define TBL_TYRXFXSJ_FLD_SECONDCODE				"SecondCode"		// 样品二次编码		varchar
#define TBL_TYRXFXSJ_FLD_SAMPLEVOLUME			"SampleVolume"		// 样品体积			float
#define TBL_TYRXFXSJ_FLD_GCEABM					"GCEABM"			// 野外命名			varchar
#define TBL_TYRXFXSJ_FLD_GCEAAL					"GCEAAL"			// 样品重量(kg)		float
#define TBL_TYRXFXSJ_FLD_SAMPLELENGTH			"SampleLength"		// 样品长度(cm)		varchar
#define TBL_TYRXFXSJ_FLD_PRETREATMETHOD			"PretreatMethod"	// 预处理方法		varchar
#define TBL_TYRXFXSJ_FLD_TESTCONTENT			"TestContent"		// 测试内容			varchar
#define TBL_TYRXFXSJ_FLD_PLANEPOSMAP			"PlanePosMap"		// 平面位置示意图	varchar
#define TBL_TYRXFXSJ_FLD_PROFILEMAP				"ProfileMap"		// 剖面示意图		varchar
#define TBL_TYRXFXSJ_FLD_FIELDIMAGE				"FieldImage"		// 野外照片(视频)	varchar
#define TBL_TYRXFXSJ_FLD_RECORDCARD				"RecordCard"		// 记录卡片(记录)	varchar
#define TBL_TYRXFXSJ_FLD_SAMPLEORGN				"SampleOrgn"		// 采样单位			varchar
#define TBL_TYRXFXSJ_FLD_SWFOMW					"SWFOMW"			// 采样人			varchar
#define TBL_TYRXFXSJ_FLD_GCEABJ					"GCEABJ"			// 采样日期			date
#define TBL_TYRXFXSJ_FLD_INPUTER				"Inputer"			// 录入员			varchar
#define TBL_TYRXFXSJ_FLD_INPUTORGN				"InputOrgn"			// 录入单位			varchar
#define TBL_TYRXFXSJ_FLD_INPUTDATE				"InputDate"			// 录入日期			date
// from 室内测试分析基本情况表
#define TBL_TYRXFXSJ_FLD_GCEABD					"GCEABD"			// 室内编号				varchar
#define TBL_TYRXFXSJ_FLD_TESTEQUIP				"TestEquip"			// 试验仪器				varchar
#define TBL_TYRXFXSJ_FLD_TESTMETHOD				"TestMethod"		// 试验方法				varchar
#define TBL_TYRXFXSJ_FLD_TESTBASED				"TestBased"			// 检验依据				varchar
#define TBL_TYRXFXSJ_FLD_GCEAJC					"GCEAJC"			// 试验单位				varchar
#define TBL_TYRXFXSJ_FLD_SWFGAM					"SWFGAM"			// 收样日期				date
#define TBL_TYRXFXSJ_FLD_SWFGAN					"SWFGAN"			// 报告日期				date
#define TBL_TYRXFXSJ_FLD_GCEAJD					"GCEAJD"			// 校对					varchar
#define TBL_TYRXFXSJ_FLD_AUDITOR				"Auditor"			// 审核					varchar
#define TBL_TYRXFXSJ_FLD_TESTLEADER				"TestLeader"		// 试验负责人			varchar
#define TBL_TYRXFXSJ_FLD__REPORT				"_Report"			// 原始测试分析报告		varchar

// 工勘孔岩石RQD实验 -- LH.2021.08.31 11:24 added.
#define TBL_YSRQDSJ_TBL "Ysrqdsj"
#define TBL_YSRQDSJ_FLD_TESTID					"TestID"			//* 测试ID				int
#define TBL_YSRQDSJ_FLD_TOPDEPTH				UNION_MACRO_START_DEPTH		//* 取样顶深度		float
#define TBL_YSRQDSJ_FLD_BOTTOMDEPTH				UNION_MACRO_END_DEPTH		//* 取样底深度		float
#define TBL_YSRQDSJ_FLD_PNTID					UNION_MACRO_PNT_ID			//* 点ID				int
#define TBL_YSRQDSJ_FLD_SWFGAA					UNION_MACRO_TCDH			//* 采样层位			varchar
#define TBL_YSRQDSJ_FLD_TCMC					UNION_MACRO_TCMC			//  土层名称			varchar
#define TBL_YSRQDSJ_FLD_GEOCODE					UNION_MACRO_GEOCODE			//  地质代号			varchar
#define TBL_YSRQDSJ_FLD_TESTNO					UNION_MACRO_TESTNO			//	试验编号			varchar
#define TBL_YSRQDSJ_FLD_TESTCATEGORY			UNION_MACRO_TESTTYPE		//  试验类型			varchar	
#define TBL_YSRQDSJ_FLD_TESTVAL					"TestVal"					// 岩石RQD				double
#define TBL_YSRQDSJ_FLD__MEMO					"_Memo"						// 备注					varchar
// from 样品信息表 *
#define TBL_YSRQDSJ_FLD_GCEABB					"GCEABB"			// 样品编号			varchar
#define TBL_YSRQDSJ_FLD_SWBCF					"SWBCF"				// 样品类型			varchar
#define TBL_YSRQDSJ_FLD_ISMIXSAMPLE				"IsMixSample"		// 混合样			varchar
#define TBL_YSRQDSJ_FLD_PNTTYPE					"PntType"			// 点类型			varchar
#define TBL_YSRQDSJ_FLD_SECONDCODE				"SecondCode"		// 样品二次编码		varchar
#define TBL_YSRQDSJ_FLD_SAMPLEVOLUME			"SampleVolume"		// 样品体积			float
#define TBL_YSRQDSJ_FLD_GCEABM					"GCEABM"			// 野外命名			varchar
#define TBL_YSRQDSJ_FLD_GCEAAL					"GCEAAL"			// 样品重量(kg)		float
#define TBL_YSRQDSJ_FLD_SAMPLELENGTH			"SampleLength"		// 样品长度(cm)		varchar
#define TBL_YSRQDSJ_FLD_PRETREATMETHOD			"PretreatMethod"	// 预处理方法		varchar
#define TBL_YSRQDSJ_FLD_TESTCONTENT				"TestContent"		// 测试内容			varchar
#define TBL_YSRQDSJ_FLD_PLANEPOSMAP				"PlanePosMap"		// 平面位置示意图	varchar
#define TBL_YSRQDSJ_FLD_PROFILEMAP				"ProfileMap"		// 剖面示意图		varchar
#define TBL_YSRQDSJ_FLD_FIELDIMAGE				"FieldImage"		// 野外照片(视频)	varchar
#define TBL_YSRQDSJ_FLD_RECORDCARD				"RecordCard"		// 记录卡片(记录)	varchar
#define TBL_YSRQDSJ_FLD_SAMPLEORGN				"SampleOrgn"		// 采样单位			varchar
#define TBL_YSRQDSJ_FLD_SWFOMW					"SWFOMW"			// 采样人			varchar
#define TBL_YSRQDSJ_FLD_GCEABJ					"GCEABJ"			// 采样日期			date
#define TBL_YSRQDSJ_FLD_INPUTER					"Inputer"			// 录入员			varchar
#define TBL_YSRQDSJ_FLD_INPUTORGN				"InputOrgn"			// 录入单位			varchar
#define TBL_YSRQDSJ_FLD_INPUTDATE				"InputDate"			// 录入日期			date
// from 室内测试分析基本情况表
#define TBL_YSRQDSJ_FLD_GCEABD			"GCEABD"			// 室内编号			varchar
#define TBL_YSRQDSJ_FLD_TESTEQUIP		"TestEquip"			// 试验仪器				varchar
#define TBL_YSRQDSJ_FLD_TESTMETHOD		"TestMethod"		// 试验方法				varchar
#define TBL_YSRQDSJ_FLD_TESTBASED		"TestBased"			// 检验依据				varchar
#define TBL_YSRQDSJ_FLD_GCEAJC			"GCEAJC"			// 试验单位				varchar
#define TBL_YSRQDSJ_FLD_SWFGAM			"SWFGAM"			// 收样日期				date
#define TBL_YSRQDSJ_FLD_SWFGAN			"SWFGAN"			// 报告日期				date
#define TBL_YSRQDSJ_FLD_GCEAJD			"GCEAJD"			// 校对					varchar
#define TBL_YSRQDSJ_FLD_AUDITOR			"Auditor"			// 审核					varchar
#define TBL_YSRQDSJ_FLD_TESTLEADER		"TestLeader"		// 试验负责人			varchar
#define TBL_YSRQDSJ_FLD__REPORT			"_Report"			// 原始测试分析报告		varchar

//岩石抗压强度表
#define TBL_STRENEGTH_ROCK_TBL "Yskyqd"
#define TBL_STRENEGTH_ROCK_FLD_TESTID				"TestID"			//* 测试ID				int
#define TBL_STRENEGTH_ROCK_FLD_TOPDEPTH				UNION_MACRO_START_DEPTH		//* 取样顶深度		float
#define TBL_STRENEGTH_ROCK_FLD_BOTTOMDEPTH			UNION_MACRO_END_DEPTH		//* 取样底深度		float
#define TBL_STRENEGTH_ROCK_FLD_PNTID				UNION_MACRO_PNT_ID			//* 点ID				int
#define TBL_STRENEGTH_ROCK_FLD_SWFGAA				UNION_MACRO_TCDH			//* 采样层位			varchar
#define TBL_STRENEGTH_ROCK_FLD_TCMC					UNION_MACRO_TCMC			//  土层名称			varchar
#define TBL_STRENEGTH_ROCK_FLD_GEOCODE				UNION_MACRO_GEOCODE			//  地质代号			varchar
#define TBL_STRENEGTH_ROCK_FLD_TESTNO				UNION_MACRO_TESTNO			//	试验编号			varchar
#define TBL_STRENEGTH_ROCK_FLD_TESTCATEGORY			UNION_MACRO_TESTTYPE		//  试验类型			varchar	
#define TBL_STRENEGTH_ROCK_FLD_TESTSTATUS			"TestStatus"				//试样状态			varchar
#define TBL_STRENEGTH_ROCK_FLD_SPECIFICATION		"TestSpecification"			//试样规格			varchar
#define TBL_STRENEGTH_ROCK_FLD_TESTAREA				"TestArea"					//试样面积(mm)			double
#define TBL_STRENEGTH_ROCK_FLD_TOTALDESTORYPOWER	"TotalDestoryPower"			//总破坏力(KN)			double
#define TBL_STRENEGTH_ROCK_FLD_COMPRESSIVESTRENGTH				"CompressiveStrength"					//抗压强度(MPa)			double
#define TBL_STRENEGTH_ROCK_FLD_CORRECTEDVALUE		"CorrectedValue"			//修正值(MPa)			double
#define TBL_STRENEGTH_ROCK_FLD_HDRATIO				"HDRatio"					//高径比(H/D)			double
#define TBL_STRENEGTH_ROCK_FLD__MEMO				"_Memo"						// 备注					varchar
// from 样品信息表 *
#define TBL_STRENEGTH_ROCK_FLD_GCEABB					"GCEABB"			// 样品编号			varchar
#define TBL_STRENEGTH_ROCK_FLD_SWBCF					"SWBCF"				// 样品类型			varchar
#define TBL_STRENEGTH_ROCK_FLD_ISMIXSAMPLE				"IsMixSample"		// 混合样			varchar
#define TBL_STRENEGTH_ROCK_FLD_PNTTYPE					"PntType"			// 点类型			varchar
#define TBL_STRENEGTH_ROCK_FLD_SECONDCODE				"SecondCode"		// 样品二次编码		varchar
#define TBL_STRENEGTH_ROCK_FLD_SAMPLEVOLUME				"SampleVolume"		// 样品体积			float
#define TBL_STRENEGTH_ROCK_FLD_GCEABM					"GCEABM"			// 野外命名			varchar
#define TBL_STRENEGTH_ROCK_FLD_GCEAAL					"GCEAAL"			// 样品重量(kg)		float
#define TBL_STRENEGTH_ROCK_FLD_SAMPLELENGTH				"SampleLength"		// 样品长度(cm)		varchar
#define TBL_STRENEGTH_ROCK_FLD_PRETREATMETHOD			"PretreatMethod"	// 预处理方法		varchar
#define TBL_STRENEGTH_ROCK_FLD_TESTCONTENT				"TestContent"		// 测试内容			varchar
#define TBL_STRENEGTH_ROCK_FLD_PLANEPOSMAP				"PlanePosMap"		// 平面位置示意图	varchar
#define TBL_STRENEGTH_ROCK_FLD_PROFILEMAP				"ProfileMap"		// 剖面示意图		varchar
#define TBL_STRENEGTH_ROCK_FLD_FIELDIMAGE				"FieldImage"		// 野外照片(视频)	varchar
#define TBL_STRENEGTH_ROCK_FLD_RECORDCARD				"RecordCard"		// 记录卡片(记录)	varchar
#define TBL_STRENEGTH_ROCK_FLD_SAMPLEORGN				"SampleOrgn"		// 采样单位			varchar
#define TBL_STRENEGTH_ROCK_FLD_SWFOMW					"SWFOMW"			// 采样人			varchar
#define TBL_STRENEGTH_ROCK_FLD_GCEABJ					"GCEABJ"			// 采样日期			date
#define TBL_STRENEGTH_ROCK_FLD_INPUTER					"Inputer"			// 录入员			varchar
#define TBL_STRENEGTH_ROCK_FLD_INPUTORGN				"InputOrgn"			// 录入单位			varchar
#define TBL_STRENEGTH_ROCK_FLD_INPUTDATE				"InputDate"			// 录入日期			date
// from 室内测试分析基本情况表
#define TBL_STRENEGTH_ROCK_FLD_GCEABD			"GCEABD"			// 室内编号			varchar
#define TBL_STRENEGTH_ROCK_FLD_TESTEQUIP		"TestEquip"			// 试验仪器				varchar
#define TBL_STRENEGTH_ROCK_FLD_TESTMETHOD		"TestMethod"		// 试验方法				varchar
#define TBL_STRENEGTH_ROCK_FLD_TESTBASED		"TestBased"			// 检验依据				varchar
#define TBL_STRENEGTH_ROCK_FLD_GCEAJC			"GCEAJC"			// 试验单位				varchar
#define TBL_STRENEGTH_ROCK_FLD_SWFGAM			"SWFGAM"			// 收样日期				date
#define TBL_STRENEGTH_ROCK_FLD_SWFGAN			"SWFGAN"			// 报告日期				date
#define TBL_STRENEGTH_ROCK_FLD_GCEAJD			"GCEAJD"			// 校对					varchar
#define TBL_STRENEGTH_ROCK_FLD_AUDITOR			"Auditor"			// 审核					varchar
#define TBL_STRENEGTH_ROCK_FLD_TESTLEADER		"TestLeader"		// 试验负责人			varchar
#define TBL_STRENEGTH_ROCK_FLD__REPORT			"_Report"			// 原始测试分析报告		varchar


/*------------------------------------------现场测试分析类---------------------------------------------*/
#define INSCENEEXP_MDL_CLASS "现场测试分析表类"
	//现场监测分析成果表
#define TBL_INSCENEEXPIDENT_TBL "INSceneExpIdent"
#define TBL_INSCENEEXPIDENT_FLD_SCENEEXPIDENTID		"SceneExpIdentID"	//* 现场检测记录ID	int
#define TBL_INSCENEEXPIDENT_FLD_TOPDEPTH			UNION_MACRO_START_DEPTH		//* 检测顶深度		float
#define TBL_INSCENEEXPIDENT_FLD_BOTTOMDEPTH			UNION_MACRO_END_DEPTH		//* 检测底深度		float
#define TBL_INSCENEEXPIDENT_FLD_PNTID				UNION_MACRO_PNT_ID			//* 点ID				int
#define TBL_INSCENEEXPIDENT_FLD_SWFGAA				UNION_MACRO_TCDH			//* 采样层位			varchar
#define TBL_INSCENEEXPIDENT_FLD_TCMC				UNION_MACRO_TCMC			//  土层名称			varchar
#define TBL_INSCENEEXPIDENT_FLD_GEOCODE				UNION_MACRO_GEOCODE			//  地质代号			varchar
#define TBL_INSCENEEXPIDENT_FLD_PNTNO				"PntNo"				// 点号				varchar
#define TBL_INSCENEEXPIDENT_FLD_PKIAA				UNION_MACRO_PRJCODE		// 项目编号		varchar
#define TBL_INSCENEEXPIDENT_FLD_DETECTIONTYPE		"DetectionType"		// 检测类型			varchar
#define TBL_INSCENEEXPIDENT_FLD_TESTEQUIP			"TestEquip"			// 检测仪器			varchar
#define TBL_INSCENEEXPIDENT_FLD_DETECTLEVEL			"DetectLevel"		// 检测层位			varchar
#define TBL_INSCENEEXPIDENT_FLD_TESTORGN			"TestOrgn"			// 检测单位			varchar
#define TBL_INSCENEEXPIDENT_FLD_TESTDATE			"TestDate"			// 检测日期			date
#define TBL_INSCENEEXPIDENT_FLD_INSPECTOR			"Inspector"			// 检测人			varchar
#define TBL_INSCENEEXPIDENT_FLD_DETECTINDEX			"DetectIndex"		// 检测指标			varchar
#define TBL_INSCENEEXPIDENT_FLD_CHEMICALCODE		"ChemicalCode"		// 化学代号			varchar
#define TBL_INSCENEEXPIDENT_FLD_NUMERICALUNIT		"NumericalUnit"		// 数值单位			varchar
#define TBL_INSCENEEXPIDENT_FLD_TESTRESULT			"TestResult"		// 检测结果			varchar


/*------------------------------------------地质环境监测类---------------------------------------------*/
#define GEOENVMONITOR_MDL_CLASS "地质环境监测表类"
	//监测仪器基本情况表
#define TBL_GEOENVMONITORDIVICE_TBL "GeoEnvMonitorDivice"
#define TBL_GEOENVMONITORDIVICE_FLD_MONITOREQUIPID		"MonitorEquipID"			//* 监测仪器ID			int
#define TBL_GEOENVMONITORDIVICE_FLD_EQUIPMENTNAME		"EquipmentName"				// 仪器名称				varchar
#define TBL_GEOENVMONITORDIVICE_FLD_EQUIPFACTORYCODE	"EquipFactoryCode"			// 仪器出厂编码			varchar
#define TBL_GEOENVMONITORDIVICE_FLD_EQUIPFACTORYNAME	"EquipFactoryName"			// 仪器生产厂家			varchar
#define TBL_GEOENVMONITORDIVICE_FLD_MONITORINGINDEX		"MonitoringIndex"			// 监测指标				varchar
#define TBL_GEOENVMONITORDIVICE_FLD_PLACEDEPTH			"PlaceDepth"				// 放置深度				float
#define TBL_GEOENVMONITORDIVICE_FLD_COLLECTINTERVAL		"CollectInterval"			// 数据采集间隔			varchar
#define TBL_GEOENVMONITORDIVICE_FLD_COLLECTINTERVALUNIT	"CollectIntervalUnit"		// 间隔时间单位			varchar
#define TBL_GEOENVMONITORDIVICE_FLD_PROTECTEQUIP		"ProtectEquip"				// 保护装置				varchar
#define TBL_GEOENVMONITORDIVICE_FLD_ISCALIBRATE			"IsCalibrate"				// 是否较准				bool
#define TBL_GEOENVMONITORDIVICE_FLD_CALIBRATETYPE		"CalibrateType"				// 较准方式				varchar
#define TBL_GEOENVMONITORDIVICE_FLD_EQUIPSYSERROR		"EquipSysError"				// 仪器系统误差			varchar
#define TBL_GEOENVMONITORDIVICE_FLD_EQUIPFETCHTIME		"EquipFetchTime"			// 仪器取出时间			date
#define TBL_GEOENVMONITORDIVICE_FLD_EQUIPFETCHREASON	"EquipFetchReason"			// 仪器取出原因			varchar
#define TBL_GEOENVMONITORDIVICE_FLD_RUNNINGSTATE		"RunningState"				// 运行状态				varchar
#define TBL_GEOENVMONITORDIVICE_FLD_FIELDINSTALLIMAGE	"FieldInstallImage"			// 现场安装影像			varchar
#define TBL_GEOENVMONITORDIVICE_FLD_FIELDCALIBRATIMAGE	"FieldCalibratImage"		// 现场较准影像			varchar
//from 监测点基础信息表
#define TBL_GEOENVMONITORDIVICE_FLD_PNTID				UNION_MACRO_PNT_ID	//* 点ID					int
#define TBL_GEOENVMONITORDIVICE_FLD_MONITORPNTTYPE		"MonitorPntType"	// 监测点类型			varchar
#define TBL_GEOENVMONITORDIVICE_FLD_MONITOROBJ			"MonitorObj"		// 监测对象				varchar
#define TBL_GEOENVMONITORDIVICE_FLD_MONITORCONTENT		"MonitorContent"	// 监测内容				varchar
#define TBL_GEOENVMONITORDIVICE_FLD_MONITORTYPE			"MonitorType"		// 监测方式				varchar
#define TBL_GEOENVMONITORDIVICE_FLD_MONITORSETDATE		"MonitorSetDate"	// 监测点设置日期		date
#define TBL_GEOENVMONITORDIVICE_FLD_PLANEPOSMAP			"PlanePosMap"		// 平面位置示意图		varchar
#define TBL_GEOENVMONITORDIVICE_FLD_PROFILEMAP			"ProfileMap"		// 剖面示意图			varchar
#define TBL_GEOENVMONITORDIVICE_FLD_MONITORDATADOCID	"MonitorDataDocID"	// 监测数据文档ID		varchar
#define TBL_GEOENVMONITORDIVICE_FLD_MONITORPNTIMAGE		"MonitorPntImage"	// 监测点照片(视频)		varchar
#define TBL_GEOENVMONITORDIVICE_FLD_RECORDCARD			"RecordCard"		// 记录卡片(记录)		varchar
#define TBL_GEOENVMONITORDIVICE_FLD_MONITOROGRN			"MonitorOgrn"		// 监测单位				varchar
#define TBL_GEOENVMONITORDIVICE_FLD_CHARGE				"Charge"			// 负责人				varchar
#define TBL_GEOENVMONITORDIVICE_FLD_INPUTER				"Inputer"			// 录入单位				varchar
#define TBL_GEOENVMONITORDIVICE_FLD_INPUTORGN			"InputOrgn"			// 录入员				varchar
#define TBL_GEOENVMONITORDIVICE_FLD_INPUTDATE			"InputDate"			// 录入日期				date


//地下水位水温监测数据表
#define TBL_GEOENVMONITOLEVELTEMP_TBL "GeoEnvMonitoLevelTemp"
#define TBL_GEOENVMONITOLEVELTEMP_FLD_LEVELTEMPID		"LevelTempID"	//* 水位水温监测ID		int
#define TBL_GEOENVMONITOLEVELTEMP_FLD_MONITORDATE		"MonitorDate"	// 监测时间				date
#define TBL_GEOENVMONITOLEVELTEMP_FLD_TKDAE				"TKDAE"			// 天气					varchar
#define TBL_GEOENVMONITOLEVELTEMP_FLD_SWEGAB			"SWEGAB"		// 水位埋深				float
#define TBL_GEOENVMONITOLEVELTEMP_FLD_GCKUGF			"GCKUGF"		// 深度					float
#define TBL_GEOENVMONITOLEVELTEMP_FLD_SWADET			"SWADET"		// 水温					float
#define TBL_GEOENVMONITOLEVELTEMP_FLD_SWADBB			"SWADBB"		// 气温					float
//from 监测点基础信息表
#define TBL_GEOENVMONITOLEVELTEMP_FLD_PNTID				UNION_MACRO_PNT_ID	//* 点ID					int
#define TBL_GEOENVMONITOLEVELTEMP_FLD_MONITORPNTTYPE	"MonitorPntType"	// 监测点类型			varchar
#define TBL_GEOENVMONITOLEVELTEMP_FLD_MONITOROBJ		"MonitorObj"		// 监测对象				varchar
#define TBL_GEOENVMONITOLEVELTEMP_FLD_MONITORCONTENT	"MonitorContent"	// 监测内容				varchar
#define TBL_GEOENVMONITOLEVELTEMP_FLD_MONITORTYPE		"MonitorType"		// 监测方式				varchar
#define TBL_GEOENVMONITOLEVELTEMP_FLD_MONITORSETDATE	"MonitorSetDate"	// 监测点设置日期		date
#define TBL_GEOENVMONITOLEVELTEMP_FLD_PLANEPOSMAP		"PlanePosMap"		// 平面位置示意图		varchar
#define TBL_GEOENVMONITOLEVELTEMP_FLD_PROFILEMAP		"ProfileMap"		// 剖面示意图			varchar
#define TBL_GEOENVMONITOLEVELTEMP_FLD_MONITORDATADOCID	"MonitorDataDocID"	// 监测数据文档ID		varchar
#define TBL_GEOENVMONITOLEVELTEMP_FLD_MONITORPNTIMAGE	"MonitorPntImage"	// 监测点照片(视频)		varchar
#define TBL_GEOENVMONITOLEVELTEMP_FLD_RECORDCARD		"RecordCard"		// 记录卡片(记录)		varchar
#define TBL_GEOENVMONITOLEVELTEMP_FLD_MONITOROGRN		"MonitorOgrn"		// 监测单位				varchar
#define TBL_GEOENVMONITOLEVELTEMP_FLD_CHARGE			"Charge"			// 负责人				varchar
#define TBL_GEOENVMONITOLEVELTEMP_FLD_INPUTER			"Inputer"			// 录入单位				varchar
#define TBL_GEOENVMONITOLEVELTEMP_FLD_INPUTORGN			"InputOrgn"			// 录入员				varchar
#define TBL_GEOENVMONITOLEVELTEMP_FLD_INPUTDATE			"InputDate"			// 录入日期				date

//（堰槽法）流量监测数据表
#define TBL_GEOENVWEIRMONITOFLOW_TBL "GeoEnvWeirMonitoFlow"
#define TBL_GEOENVWEIRMONITOFLOW_FLD_WEIRMONITOFLOWID		"WeirMonitoFlowID"	//* 堰槽流量监测ID		int
#define TBL_GEOENVWEIRMONITOFLOW_FLD_MONITORDATE			"MonitorDate"		// 监测时间				date
#define TBL_GEOENVWEIRMONITOFLOW_FLD_WEIRTYPE				"WeirType"			// 堰槽类型				varchar
#define TBL_GEOENVWEIRMONITOFLOW_FLD_WEIRREADING			"WeirReading"		// 堰槽读数				float
#define TBL_GEOENVWEIRMONITOFLOW_FLD_FLOWUNIT				"FlowUnit"			// 流量单位				varchar
#define TBL_GEOENVWEIRMONITOFLOW_FLD__FLOW					"_Flow"				// 流量					float
//from 监测点基础信息表
#define TBL_GEOENVWEIRMONITOFLOW_FLD_PNTID				UNION_MACRO_PNT_ID	//* 点ID					int
#define TBL_GEOENVWEIRMONITOFLOW_FLD_MONITORPNTTYPE		"MonitorPntType"	// 监测点类型			varchar
#define TBL_GEOENVWEIRMONITOFLOW_FLD_MONITOROBJ			"MonitorObj"		// 监测对象				varchar
#define TBL_GEOENVWEIRMONITOFLOW_FLD_MONITORCONTENT		"MonitorContent"	// 监测内容				varchar
#define TBL_GEOENVWEIRMONITOFLOW_FLD_MONITORTYPE		"MonitorType"		// 监测方式				varchar
#define TBL_GEOENVWEIRMONITOFLOW_FLD_MONITORSETDATE		"MonitorSetDate"	// 监测点设置日期		date
#define TBL_GEOENVWEIRMONITOFLOW_FLD_PLANEPOSMAP		"PlanePosMap"		// 平面位置示意图		varchar
#define TBL_GEOENVWEIRMONITOFLOW_FLD_PROFILEMAP			"ProfileMap"		// 剖面示意图			varchar
#define TBL_GEOENVWEIRMONITOFLOW_FLD_MONITORDATADOCID	"MonitorDataDocID"	// 监测数据文档ID		varchar
#define TBL_GEOENVWEIRMONITOFLOW_FLD_MONITORPNTIMAGE	"MonitorPntImage"	// 监测点照片(视频)		varchar
#define TBL_GEOENVWEIRMONITOFLOW_FLD_RECORDCARD			"RecordCard"		// 记录卡片(记录)		varchar
#define TBL_GEOENVWEIRMONITOFLOW_FLD_MONITOROGRN		"MonitorOgrn"		// 监测单位				varchar
#define TBL_GEOENVWEIRMONITOFLOW_FLD_CHARGE				"Charge"			// 负责人				varchar
#define TBL_GEOENVWEIRMONITOFLOW_FLD_INPUTER			"Inputer"			// 录入单位				varchar
#define TBL_GEOENVWEIRMONITOFLOW_FLD_INPUTORGN			"InputOrgn"			// 录入员				varchar
#define TBL_GEOENVWEIRMONITOFLOW_FLD_INPUTDATE			"InputDate"			// 录入日期				date

//监测断面测点数据表
#define TBL_GEOENVMONITOSECTPNT_TBL "GeoEnvMonitoSectPnt"
#define TBL_GEOENVMONITOSECTPNT_FLD_TESTFLOWPNTID				"TestFlowPntID"			//* 测流点ID			int
#define TBL_GEOENVMONITOSECTPNT_FLD_TESTFLOWPNTNO				"TestFlowPntNo"			// 测流点编号		varchar
#define TBL_GEOENVMONITOSECTPNT_FLD_DISTANCE					"Distance"				// 与起始点距离		float
#define TBL_GEOENVMONITOSECTPNT_FLD_TESTPNTDEPTH				"TestPntDepth"			// 测点深度			float
#define TBL_GEOENVMONITOSECTPNT_FLD_EQUIPREADING				"EquipReading"			// 仪器读数			float
#define TBL_GEOENVMONITOSECTPNT_FLD_MEASUREUNIT					"MeasureUnit"			// 计量单位			varchar
#define TBL_GEOENVMONITOSECTPNT_FLD_FLOWRATE					"FlowRate"				// 流速				float
#define TBL_GEOENVMONITOSECTPNT_FLD_FLOWRATEUNIT				"FlowRateUnit"			// 流速单位			varchar
#define TBL_GEOENVMONITOSECTPNT_FLD_SECTIONAREA					"SectionArea"			// 代表断面面积		float
#define TBL_GEOENVMONITOSECTPNT_FLD_SECTIONWATERFLOW			"SectionWaterflow"		// 代表断面流量		float
//from（流速法）流量监测数据表
#define TBL_GEOENVMONITOSECTPNT_FLD_MONITORDATE					"MonitorDate"			// 监测时间				date
#define TBL_GEOENVMONITOSECTPNT_FLD_MONITORFLOWEQUIP			"MonitorFlowEquip"		// 测流仪器				varchar
#define TBL_GEOENVMONITOSECTPNT_FLD_DEVICETYPE					"DeviceType"			// 仪器型号				varchar
#define TBL_GEOENVMONITOSECTPNT_FLD_SECTIONWIDTH				"SectionWidth"			// 断面宽度				float
#define TBL_GEOENVMONITOSECTPNT_FLD_AVERAGEVELOCITY				"AverageVelocity"		// 平均流速				float
#define TBL_GEOENVMONITOSECTPNT_FLD_VELOCITYUNIT				"VelocityUnit"			// 流速单位				varchar
#define TBL_GEOENVMONITOSECTPNT_FLD_AVERAGEFLOW					"Averageflow"			// 平均流量				float
#define TBL_GEOENVMONITOSECTPNT_FLD_FLOWUNIT					"FlowUnit"				// 流量单位				varchar
//from 监测点基础信息表
#define TBL_GEOENVMONITOSECTPNT_FLD_PNTID				UNION_MACRO_PNT_ID	//* 点ID					int
#define TBL_GEOENVMONITOSECTPNT_FLD_MONITORPNTTYPE		"MonitorPntType"	// 监测点类型			varchar
#define TBL_GEOENVMONITOSECTPNT_FLD_MONITOROBJ			"MonitorObj"		// 监测对象				varchar
#define TBL_GEOENVMONITOSECTPNT_FLD_MONITORCONTENT		"MonitorContent"	// 监测内容				varchar
#define TBL_GEOENVMONITOSECTPNT_FLD_MONITORTYPE			"MonitorType"		// 监测方式				varchar
#define TBL_GEOENVMONITOSECTPNT_FLD_MONITORSETDATE		"MonitorSetDate"	// 监测点设置日期		date
#define TBL_GEOENVMONITOSECTPNT_FLD_PLANEPOSMAP			"PlanePosMap"		// 平面位置示意图		varchar
#define TBL_GEOENVMONITOSECTPNT_FLD_PROFILEMAP			"ProfileMap"		// 剖面示意图			varchar
#define TBL_GEOENVMONITOSECTPNT_FLD_MONITORDATADOCID	"MonitorDataDocID"	// 监测数据文档ID		varchar
#define TBL_GEOENVMONITOSECTPNT_FLD_MONITORPNTIMAGE		"MonitorPntImage"	// 监测点照片(视频)		varchar
#define TBL_GEOENVMONITOSECTPNT_FLD_RECORDCARD			"RecordCard"		// 记录卡片(记录)		varchar
#define TBL_GEOENVMONITOSECTPNT_FLD_MONITOROGRN			"MonitorOgrn"		// 监测单位				varchar
#define TBL_GEOENVMONITOSECTPNT_FLD_CHARGE				"Charge"			// 负责人				varchar
#define TBL_GEOENVMONITOSECTPNT_FLD_INPUTER				"Inputer"			// 录入单位				varchar
#define TBL_GEOENVMONITOSECTPNT_FLD_INPUTORGN			"InputOrgn"			// 录入员				varchar
#define TBL_GEOENVMONITOSECTPNT_FLD_INPUTDATE			"InputDate"			// 录入日期				date


//地下水开采量监测数据表
#define TBL_GEOENVWATEREXTRACT_TBL "GeoEnvWaterExtract"
#define TBL_GEOENVWATEREXTRACT_FLD_EXPLOITATMONITORID	"ExploitatMonitorID"	//* 开采量监测ID		int
#define TBL_GEOENVWATEREXTRACT_FLD_MONITORDATE			"MonitorDate"			// 监测时间			date
#define TBL_GEOENVWATEREXTRACT_FLD_EQUIPREADING			"EquipReading"			// 仪器读数			float
#define TBL_GEOENVWATEREXTRACT_FLD_EXPLOITATION			"Exploitation"			// 开采量			float
#define TBL_GEOENVWATEREXTRACT_FLD_EXPLOITATIONUINT		"exploitationUint"		// 开采量单位		varchar
//from 监测点基础信息表
#define TBL_GEOENVWATEREXTRACT_FLD_PNTID				UNION_MACRO_PNT_ID	//* 点ID					int
#define TBL_GEOENVWATEREXTRACT_FLD_MONITORPNTTYPE		"MonitorPntType"	// 监测点类型			varchar
#define TBL_GEOENVWATEREXTRACT_FLD_MONITOROBJ			"MonitorObj"		// 监测对象				varchar
#define TBL_GEOENVWATEREXTRACT_FLD_MONITORCONTENT		"MonitorContent"	// 监测内容				varchar
#define TBL_GEOENVWATEREXTRACT_FLD_MONITORTYPE			"MonitorType"		// 监测方式				varchar
#define TBL_GEOENVWATEREXTRACT_FLD_MONITORSETDATE		"MonitorSetDate"	// 监测点设置日期		date
#define TBL_GEOENVWATEREXTRACT_FLD_PLANEPOSMAP			"PlanePosMap"		// 平面位置示意图		varchar
#define TBL_GEOENVWATEREXTRACT_FLD_PROFILEMAP			"ProfileMap"		// 剖面示意图			varchar
#define TBL_GEOENVWATEREXTRACT_FLD_MONITORDATADOCID		"MonitorDataDocID"	// 监测数据文档ID		varchar
#define TBL_GEOENVWATEREXTRACT_FLD_MONITORPNTIMAGE		"MonitorPntImage"	// 监测点照片(视频)		varchar
#define TBL_GEOENVWATEREXTRACT_FLD_RECORDCARD			"RecordCard"		// 记录卡片(记录)		varchar
#define TBL_GEOENVWATEREXTRACT_FLD_MONITOROGRN			"MonitorOgrn"		// 监测单位				varchar
#define TBL_GEOENVWATEREXTRACT_FLD_CHARGE				"Charge"			// 负责人				varchar
#define TBL_GEOENVWATEREXTRACT_FLD_INPUTER				"Inputer"			// 录入单位				varchar
#define TBL_GEOENVWATEREXTRACT_FLD_INPUTORGN			"InputOrgn"			// 录入员				varchar
#define TBL_GEOENVWATEREXTRACT_FLD_INPUTDATE			"InputDate"			// 录入日期				date

//地面沉降监测数据表
#define TBL_GEOENVLANDSUBSIDENCE_TBL "GeoEnvLandSubsidence"
#define TBL_GEOENVLANDSUBSIDENCE_FLD_SUBSIDENCEID			"SubsidenceID"			//* 沉降监测ID		int
#define TBL_GEOENVLANDSUBSIDENCE_FLD_MONITORDATE			"MonitorDate"			// 监测时间			date
#define TBL_GEOENVLANDSUBSIDENCE_FLD_GCJCBJ					"GCJCBJ"				// 高程				double
#define TBL_GEOENVLANDSUBSIDENCE_FLD_GCJCBJSYS				"GCJCBJSys"				// 高程系统			varchar
#define TBL_GEOENVLANDSUBSIDENCE_FLD_SETTLEMENT				"Settlement"			// 沉降量			double
//from 监测点基础信息表
#define TBL_GEOENVLANDSUBSIDENCE_FLD_PNTID				UNION_MACRO_PNT_ID	//* 点ID					int
#define TBL_GEOENVLANDSUBSIDENCE_FLD_MONITORPNTTYPE		"MonitorPntType"	// 监测点类型			varchar
#define TBL_GEOENVLANDSUBSIDENCE_FLD_MONITOROBJ			"MonitorObj"		// 监测对象				varchar
#define TBL_GEOENVLANDSUBSIDENCE_FLD_MONITORCONTENT		"MonitorContent"	// 监测内容				varchar
#define TBL_GEOENVLANDSUBSIDENCE_FLD_MONITORTYPE		"MonitorType"		// 监测方式				varchar
#define TBL_GEOENVLANDSUBSIDENCE_FLD_MONITORSETDATE		"MonitorSetDate"	// 监测点设置日期		date
#define TBL_GEOENVLANDSUBSIDENCE_FLD_PLANEPOSMAP		"PlanePosMap"		// 平面位置示意图		varchar
#define TBL_GEOENVLANDSUBSIDENCE_FLD_PROFILEMAP			"ProfileMap"		// 剖面示意图			varchar
#define TBL_GEOENVLANDSUBSIDENCE_FLD_MONITORDATADOCID	"MonitorDataDocID"	// 监测数据文档ID		varchar
#define TBL_GEOENVLANDSUBSIDENCE_FLD_MONITORPNTIMAGE	"MonitorPntImage"	// 监测点照片(视频)		varchar
#define TBL_GEOENVLANDSUBSIDENCE_FLD_RECORDCARD			"RecordCard"		// 记录卡片(记录)		varchar
#define TBL_GEOENVLANDSUBSIDENCE_FLD_MONITOROGRN		"MonitorOgrn"		// 监测单位				varchar
#define TBL_GEOENVLANDSUBSIDENCE_FLD_CHARGE				"Charge"			// 负责人				varchar
#define TBL_GEOENVLANDSUBSIDENCE_FLD_INPUTER			"Inputer"			// 录入单位				varchar
#define TBL_GEOENVLANDSUBSIDENCE_FLD_INPUTORGN			"InputOrgn"			// 录入员				varchar
#define TBL_GEOENVLANDSUBSIDENCE_FLD_INPUTDATE			"InputDate"			// 录入日期				date


//孔隙水压力监测数据表
#define TBL_GEOENVPOREWATER_TBL "GeoEnvPoreWater"
#define TBL_GEOENVPOREWATER_FLD_POREWATERID		"PoreWaterID"			//* 孔隙水压监测ID	int
#define TBL_GEOENVPOREWATER_FLD_MONITORDATE		"MonitorDate"			// 监测时间			date
#define TBL_GEOENVPOREWATER_FLD_GCKUGF			"GCKUGF"				// 深度				float
#define TBL_GEOENVPOREWATER_FLD_EQUIPREADING	"EquipReading"			// 仪器读数			float
#define TBL_GEOENVPOREWATER_FLD_WATERPRESSURE	"WaterPressure"			// 水压				float
//from 监测点基础信息表
#define TBL_GEOENVPOREWATER_FLD_PNTID				UNION_MACRO_PNT_ID	//* 点ID					int
#define TBL_GEOENVPOREWATER_FLD_MONITORPNTTYPE		"MonitorPntType"	// 监测点类型			varchar
#define TBL_GEOENVPOREWATER_FLD_MONITOROBJ			"MonitorObj"		// 监测对象				varchar
#define TBL_GEOENVPOREWATER_FLD_MONITORCONTENT		"MonitorContent"	// 监测内容				varchar
#define TBL_GEOENVPOREWATER_FLD_MONITORTYPE			"MonitorType"		// 监测方式				varchar
#define TBL_GEOENVPOREWATER_FLD_MONITORSETDATE		"MonitorSetDate"	// 监测点设置日期		date
#define TBL_GEOENVPOREWATER_FLD_PLANEPOSMAP			"PlanePosMap"		// 平面位置示意图		varchar
#define TBL_GEOENVPOREWATER_FLD_PROFILEMAP			"ProfileMap"		// 剖面示意图			varchar
#define TBL_GEOENVPOREWATER_FLD_MONITORDATADOCID	"MonitorDataDocID"	// 监测数据文档ID		varchar
#define TBL_GEOENVPOREWATER_FLD_MONITORPNTIMAGE		"MonitorPntImage"	// 监测点照片(视频)		varchar
#define TBL_GEOENVPOREWATER_FLD_RECORDCARD			"RecordCard"		// 记录卡片(记录)		varchar
#define TBL_GEOENVPOREWATER_FLD_MONITOROGRN			"MonitorOgrn"		// 监测单位				varchar
#define TBL_GEOENVPOREWATER_FLD_CHARGE				"Charge"			// 负责人				varchar
#define TBL_GEOENVPOREWATER_FLD_INPUTER				"Inputer"			// 录入单位				varchar
#define TBL_GEOENVPOREWATER_FLD_INPUTORGN			"InputOrgn"			// 录入员				varchar
#define TBL_GEOENVPOREWATER_FLD_INPUTDATE			"InputDate"			// 录入日期				date

//地应力监测数据表
#define TBL_GEOENVGROUNDSTRESS_TBL "GeoEnvGroundStress"
#define TBL_GEOENVGROUNDSTRESS_FLD_GROUNDSTRESSID	"GroundStressID"	//* 地应力监测ID		int
#define TBL_GEOENVGROUNDSTRESS_FLD_MONITORDATE		"MonitorDate"		// 监测时间			date
#define TBL_GEOENVGROUNDSTRESS_FLD_GCKUGF			"GCKUGF"			// 深度				float
#define TBL_GEOENVGROUNDSTRESS_FLD_EQUIPREADING		"EquipReading"		// 仪器读数			float
#define TBL_GEOENVGROUNDSTRESS_FLD_STRESSVALUE		"StressValue"		// 应力值			float
//from 监测点基础信息表
#define TBL_GEOENVGROUNDSTRESS_FLD_PNTID				UNION_MACRO_PNT_ID	//* 点ID					int
#define TBL_GEOENVGROUNDSTRESS_FLD_MONITORPNTTYPE		"MonitorPntType"	// 监测点类型			varchar
#define TBL_GEOENVGROUNDSTRESS_FLD_MONITOROBJ			"MonitorObj"		// 监测对象				varchar
#define TBL_GEOENVGROUNDSTRESS_FLD_MONITORCONTENT		"MonitorContent"	// 监测内容				varchar
#define TBL_GEOENVGROUNDSTRESS_FLD_MONITORTYPE			"MonitorType"		// 监测方式				varchar
#define TBL_GEOENVGROUNDSTRESS_FLD_MONITORSETDATE		"MonitorSetDate"	// 监测点设置日期		date
#define TBL_GEOENVGROUNDSTRESS_FLD_PLANEPOSMAP			"PlanePosMap"		// 平面位置示意图		varchar
#define TBL_GEOENVGROUNDSTRESS_FLD_PROFILEMAP			"ProfileMap"		// 剖面示意图			varchar
#define TBL_GEOENVGROUNDSTRESS_FLD_MONITORDATADOCID		"MonitorDataDocID"	// 监测数据文档ID		varchar
#define TBL_GEOENVGROUNDSTRESS_FLD_MONITORPNTIMAGE		"MonitorPntImage"	// 监测点照片(视频)		varchar
#define TBL_GEOENVGROUNDSTRESS_FLD_RECORDCARD			"RecordCard"		// 记录卡片(记录)		varchar
#define TBL_GEOENVGROUNDSTRESS_FLD_MONITOROGRN			"MonitorOgrn"		// 监测单位				varchar
#define TBL_GEOENVGROUNDSTRESS_FLD_CHARGE				"Charge"			// 负责人				varchar
#define TBL_GEOENVGROUNDSTRESS_FLD_INPUTER				"Inputer"			// 录入单位				varchar
#define TBL_GEOENVGROUNDSTRESS_FLD_INPUTORGN			"InputOrgn"			// 录入员				varchar
#define TBL_GEOENVGROUNDSTRESS_FLD_INPUTDATE			"InputDate"			// 录入日期				date

//降雨量监测数据表
#define TBL_GEOENVRAINFALL_TBL "GeoEnvRainFall"
#define TBL_GEOENVRAINFALL_FLD_RAINFALLID			"RainFallID"		//* 降雨量监测ID			int
#define TBL_GEOENVRAINFALL_FLD_MONITORDATE			"MonitorDate"		// 监测时间				date
#define TBL_GEOENVRAINFALL_FLD_EQUIPREADING			"EquipReading"		// 仪器读数				float
#define TBL_GEOENVRAINFALL_FLD_COUNTUNIT			"CountUnit"			// 计数单位				varchar
#define TBL_GEOENVRAINFALL_FLD_TIMEINTERVAL			"TimeInterval"		// 时间间隔				double
#define TBL_GEOENVRAINFALL_FLD_RAINFALL				"RainFall"			// 降雨量				double
#define TBL_GEOENVRAINFALL_FLD_RAINFALLUNIT			"RainFallUnit"		// 降雨量单位			varchar
//from 监测点基础信息表
#define TBL_GEOENVRAINFALL_FLD_PNTID				UNION_MACRO_PNT_ID	//* 点ID					int
#define TBL_GEOENVRAINFALL_FLD_MONITORPNTTYPE		"MonitorPntType"	// 监测点类型			varchar
#define TBL_GEOENVRAINFALL_FLD_MONITOROBJ			"MonitorObj"		// 监测对象				varchar
#define TBL_GEOENVRAINFALL_FLD_MONITORCONTENT		"MonitorContent"	// 监测内容				varchar
#define TBL_GEOENVRAINFALL_FLD_MONITORTYPE			"MonitorType"		// 监测方式				varchar
#define TBL_GEOENVRAINFALL_FLD_MONITORSETDATE		"MonitorSetDate"	// 监测点设置日期		date
#define TBL_GEOENVRAINFALL_FLD_PLANEPOSMAP			"PlanePosMap"		// 平面位置示意图		varchar
#define TBL_GEOENVRAINFALL_FLD_PROFILEMAP			"ProfileMap"		// 剖面示意图			varchar
#define TBL_GEOENVRAINFALL_FLD_MONITORDATADOCID		"MonitorDataDocID"	// 监测数据文档ID		varchar
#define TBL_GEOENVRAINFALL_FLD_MONITORPNTIMAGE		"MonitorPntImage"	// 监测点照片(视频)		varchar
#define TBL_GEOENVRAINFALL_FLD_RECORDCARD			"RecordCard"		// 记录卡片(记录)		varchar
#define TBL_GEOENVRAINFALL_FLD_MONITOROGRN			"MonitorOgrn"		// 监测单位				varchar
#define TBL_GEOENVRAINFALL_FLD_CHARGE				"Charge"			// 负责人				varchar
#define TBL_GEOENVRAINFALL_FLD_INPUTER				"Inputer"			// 录入单位				varchar
#define TBL_GEOENVRAINFALL_FLD_INPUTORGN			"InputOrgn"			// 录入员				varchar
#define TBL_GEOENVRAINFALL_FLD_INPUTDATE			"InputDate"			// 录入日期				date

//蒸发量监测数据表
#define TBL_GEOENVEVAPORATION_TBL "GeoEnvEvaporation"
#define TBL_GEOENVEVAPORATION_FLD_EVAPORATIONID			"EvaporationID"		//* 蒸发量监测ID		int
#define TBL_GEOENVEVAPORATION_FLD_MONITORDATE			"MonitorDate"		// 监测时间			date
#define TBL_GEOENVEVAPORATION_FLD_EQUIPREADING			"EquipReading"		// 仪器读数			float
#define TBL_GEOENVEVAPORATION_FLD_COUNTUNIT				"CountUnit"			// 计数单位			varchar
#define TBL_GEOENVEVAPORATION_FLD_TIMEINTERVAL			"TimeInterval"		// 时间间隔			double
#define TBL_GEOENVEVAPORATION_FLD_EVAPORATION			"Evaporation"		// 蒸发量			double
#define TBL_GEOENVEVAPORATION_FLD_EVAPORATEUNIT			"EvaporateUnit"		// 蒸发量单位		varchar
//from 监测点基础信息表
#define TBL_GEOENVEVAPORATION_FLD_PNTID					UNION_MACRO_PNT_ID	//* 点ID					int
#define TBL_GEOENVEVAPORATION_FLD_MONITORPNTTYPE		"MonitorPntType"	// 监测点类型			varchar
#define TBL_GEOENVEVAPORATION_FLD_MONITOROBJ			"MonitorObj"		// 监测对象				varchar
#define TBL_GEOENVEVAPORATION_FLD_MONITORCONTENT		"MonitorContent"	// 监测内容				varchar
#define TBL_GEOENVEVAPORATION_FLD_MONITORTYPE			"MonitorType"		// 监测方式				varchar
#define TBL_GEOENVEVAPORATION_FLD_MONITORSETDATE		"MonitorSetDate"	// 监测点设置日期		date
#define TBL_GEOENVEVAPORATION_FLD_PLANEPOSMAP			"PlanePosMap"		// 平面位置示意图		varchar
#define TBL_GEOENVEVAPORATION_FLD_PROFILEMAP			"ProfileMap"		// 剖面示意图			varchar
#define TBL_GEOENVEVAPORATION_FLD_MONITORDATADOCID		"MonitorDataDocID"	// 监测数据文档ID		varchar
#define TBL_GEOENVEVAPORATION_FLD_MONITORPNTIMAGE		"MonitorPntImage"	// 监测点照片(视频)		varchar
#define TBL_GEOENVEVAPORATION_FLD_RECORDCARD			"RecordCard"		// 记录卡片(记录)		varchar
#define TBL_GEOENVEVAPORATION_FLD_MONITOROGRN			"MonitorOgrn"		// 监测单位				varchar
#define TBL_GEOENVEVAPORATION_FLD_CHARGE				"Charge"			// 负责人				varchar
#define TBL_GEOENVEVAPORATION_FLD_INPUTER				"Inputer"			// 录入单位				varchar
#define TBL_GEOENVEVAPORATION_FLD_INPUTORGN				"InputOrgn"			// 录入员				varchar
#define TBL_GEOENVEVAPORATION_FLD_INPUTDATE				"InputDate"			// 录入日期				date

typedef enum FieldMacro
{
	// 档案来源单位表
	enum_int_TBL_DOCORGN_FLD_ORGNID,        // 单位ID int
	enum_str_TBL_DOCORGN_FLD_ORGNCODE,      // 单位代号 varchar
	enum_str_TBL_DOCORGN_FLD_ORGNNAME,      // 单位名称 varchar
	enum_str_TBL_DOCORGN_FLD_ORGNCHARGE,    // 单位负责人 varchar
	enum_str_TBL_DOCORGN_FLD_ORGNDUTY,      // 单位职责 varchar
	enum_str_TBL_DOCORGN_FLD_ORGNTELNO,     // 单位电话 varchar
	enum_str_TBL_DOCORGN_FLD_DOCADMINNAME,  // 档案管理员姓名 varchar
	enum_str_TBL_DOCORGN_FLD_DOCADMINTELNO, // 档案管理员电话 varchar
	enum_str_TBL_DOCORGN_FLD_ORGNADDR,      // 详细地址 varchar
	enum_str_TBL_DOCORGN_FLD_ORGNCITY,      // 城市 varchar
	enum_str_TBL_DOCORGN_FLD_ORGNDIST,      // 行政区 varchar
	enum_str_TBL_DOCORGN_FLD_ORGNCOUNTRY,   // 国家 varchar
	enum_str_TBL_DOCORGN_FLD_ORGNZIPCODE,   // 邮政编码 varchar
	// 项目登记表
	enum_int_TBL_PROJ_FLD_PRJID,          // 项目ID int
	enum_str_TBL_PROJ_FLD_PKIAA,          // 项目编号 varchar
	enum_str_TBL_PROJ_FLD_PRJNAME,        // 项目(报告)名称 varchar
	enum_str_TBL_PROJ_FLD_PRJRELURL,      // 项目关联资料Url varchar
	enum_int_TBL_PROJ_FLD_ORGNID,         // 单位ID int
	enum_str_TBL_PROJ_FLD_BATCHNO,        // 资料批次 varchar
	enum_str_TBL_PROJ_FLD_PRJTYPE,        // 项目类型 varchar
	enum_str_TBL_PROJ_FLD_PROTYPE,        // 专业类别 varchar
	enum_str_TBL_PROJ_FLD_PRJSTATUS,      // 项目运行状况 varchar
	enum_str_TBL_PROJ_FLD_DOCDELIVSTATUS, // 档案汇交状况 varchar
	enum_str_TBL_PROJ_FLD_PRJCHARGE,      // 项目负责人 varchar
	enum_str_TBL_PROJ_FLD_PRJCHARGETELNO, // 项目负责人电话 varchar
	enum_str_TBL_PROJ_FLD_PRJORGN,        // 项目承担单位 varchar
	enum_str_TBL_PROJ_FLD_PRJSTARTTIME,   // 项目起始日期 date
	enum_str_TBL_PROJ_FLD_PRJENDTIME,     // 项目完成日期 date
	enum_str_TBL_PROJ_FLD_PRJREGISTER,    // 登记人 varchar
	enum_str_TBL_PROJ_FLD_PRJREGISTUNIT,  // 登记单位 varchar
	enum_str_TBL_PROJ_FLD_PRJREGISTDATE,  // 登记日期 date
	// 点位信息表
	enum_int_TBL_PNTSTD_FLD_STDPNTID,       // 标准点位ID int
	enum_double_TBL_PNTSTD_FLD_X,           // 标准化X(m) double
	enum_double_TBL_PNTSTD_FLD_Y,           // 标准化Y(m) double
	enum_double_TBL_PNTSTD_FLD_Z,           // 标准化高程(m) double
	enum_str_TBL_PNTSTD_FLD_STDCOORSYS,     // 标准化坐标系 varchar
	enum_str_TBL_PNTSTD_FLD_STDELDATUM,     // 标准化高程基准 varchar
	enum_int_TBL_PNTSTD_FLD_PRJID,          // 项目ID int
	enum_str_TBL_PNTORIG_FLD_PNTNO,         // 原始点编号 varchar
	enum_int_TBL_PNTORIG_FLD_ISVIRTUALPNT,  // 是否虚拟点 int
	enum_int_TBL_PNTORIG_FLD_ISMONITORPNT,  // 是否监测点 int
	enum_str_TBL_PNTORIG_FLD_CLASS1_NAME,   // 一级分类名 varchar
	enum_str_TBL_PNTORIG_FLD_CLASS2_NAME,   // 二级分类名 varchar
	enum_double_TBL_PNTORIG_FLD_X,          // X double
	enum_double_TBL_PNTORIG_FLD_Y,          // Y double
	enum_double_TBL_PNTORIG_FLD_Z,          // 高程 double
	enum_double_TBL_PNTORIG_FLD_CHAHBA,     // 经度 double
	enum_double_TBL_PNTORIG_FLD_CHAHBB,     // 纬度 double
	enum_str_TBL_PNTORIG_FLD_PLANECOORDSYS, // 平面坐标系 varchar
	enum_str_TBL_PNTORIG_FLD_ELEDATUM,      // 高程基准 varchar
	enum_str_TBL_PNTORIG_FLD_DDADC,         // 地理位置 varchar
	enum_str_TBL_PNTORIG_FLD_SCHAMAA,       // 标准图幅名称 varchar
	enum_str_TBL_PNTORIG_FLD_SCHAMAC,       // 标准图幅编号 varchar
	// 钻孔登记审核表
	enum_int_TBL_HOLEREGISTER_FLD_HOLEREGID,        // 钻孔登记ID int
	enum_int_TBL_HOLEREGISTER_FLD_PNTID,            // 点ID int
	enum_str_TBL_HOLEREGISTER_FLD_HOLECODE,         // 钻孔编号 varchar
	enum_int_TBL_HOLEREGISTER_FLD_HOLECLS1,         // 钻孔大类 int
	enum_int_TBL_HOLEREGISTER_FLD_HOLECLS2,         // 钻孔亚类 int
	enum_int_TBL_HOLEREGISTER_FLD_HOLEPROPERTY,     // 钻孔性质 int
	enum_double_TBL_HOLEREGISTER_FLD_HOLEDEPTH,     // 孔深(m) double
	enum_int_TBL_HOLEREGISTER_FLD_LAYERNUM,         // 分层数量(个) int
	enum_int_TBL_HOLEREGISTER_FLD_SOILSAMPNUM,      // 土样数量(个) int
	enum_int_TBL_HOLEREGISTER_FLD_ROCKSAMPNUM,      // 岩样数量(个) int
	enum_int_TBL_HOLEREGISTER_FLD_WATERSAMPNUM,     // 水样数量(个) int
	enum_int_TBL_HOLEREGISTER_FLD_PENETRATIONTIMES, // 标贯次数(个) int
	enum_str_TBL_HOLEREGISTER_FLD_ISWAVELOCITYHOLE, // 是否为波速孔 varchar
	enum_str_TBL_HOLEREGISTER_FLD_HASPUMP,          // 是否进行抽水试验 varchar
	enum_str_TBL_HOLEREGISTER_FLD_OTHERINSIT,       // 其他原位试验情况 varchar
	enum_str_TBL_HOLEREGISTER_FLD_REGDATE,          // 登记日期 date
	enum_str_TBL_HOLEREGISTER_FLD_REGISTER,         // 登记人 varchar
	enum_str_TBL_HOLEREGISTER_FLD_MEMO,             // 备注 varchar
	enum_int_TBL_HOLEREGISTER_FLD_AUDITSTATUS,      // 审核状态 int
	enum_int_TBL_HOLEREGISTER_FLD_SELECTSTATUS,     // 选用状态 int
	enum_str_TBL_HOLEREGISTER_FLD_AUDITOR,          // 审核人 varchar
	enum_str_TBL_HOLEREGISTER_FLD_AUDITTIME,        // 审核时间 date
	enum_str_TBL_HOLEREGISTER_FLD_AUDITORG,         // 审核单位 varchar
	// 钻孔基本信息表
	enum_int_TBL_HOLE_FLD_HOLEID,          // 钻孔ID int
	enum_str_TBL_HOLE_FLD_HOLECODE,        // 钻孔编码 varchar
	enum_double_TBL_HOLE_FLD_DEPTH,        // 孔深(m) double
	enum_int_TBL_HOLE_FLD_TYPE,            // 钻孔类型 int
	enum_str_TBL_HOLE_FLD_CATEGORY,        // 钻孔类别 varchar
	enum_int_TBL_HOLE_FLD_LEVEL,           // 钻孔级别 int
	enum_int_TBL_HOLE_FLD_USAGE,           // 钻孔用途 int
	enum_int_TBL_HOLE_FLD_PNTID,           // 点ID int
	enum_str_TBL_HOLE_FLD_PRJNAME,         // 项目名称 varchar
	enum_double_TBL_HOLE_FLD_SWCJAR,       // 初见水位埋深 double
	enum_double_TBL_HOLE_FLD_SWDDBU,       // 稳定水位埋深 double
	enum_double_TBL_HOLE_FLD_TKACA,        // 开孔直径(mm) float
	enum_double_TBL_HOLE_FLD_TKACB,        // 终孔直径(mm) float
	enum_double_TBL_HOLE_FLD_HOLETOPDIAM,  // 井口外径(mm) float
	enum_double_TBL_HOLE_FLD_HOLEBTMDIAM,  // 井底外径(mm) float
	enum_double_TBL_HOLE_FLD_TKCBCL,       // 成井深度(m) float
	enum_double_TBL_HOLE_FLD_HOLEHEIGHT,   // 井台高度(m) float
	enum_double_TBL_HOLE_FLD_HOLESLOPE,    // 井（孔）斜(度) float
	enum_str_TBL_HOLE_FLD_HOLEEQUIP,       // 施工设备 varchar
	enum_str_TBL_HOLE_FLD_TKALD,           // 施工单位 varchar
	enum_str_TBL_HOLE_FLD_SWBBND,          // 机长 varchar
	enum_str_TBL_HOLE_FLD_HOLERECORDER,    // 编录员 varchar
	enum_str_TBL_HOLE_FLD_STARTDATE,       // 开工日期 date
	enum_str_TBL_HOLE_FLD_ENDDATE,         // 完工日期 date
	enum_str_TBL_HOLE_FLD_INPUTORGN,       // 录入单位 varchar
	enum_str_TBL_HOLE_FLD_INPUTER,         // 录入员 varchar
	enum_str_TBL_HOLE_FLD_INPUTDATE,       // 录入日期 date
	enum_str_TBL_HOLE_FLD_PLANEMAP,        // 平面位置示意图 varchar
	enum_str_TBL_HOLE_FLD_SECTMAP,         // 剖面示意图 varchar
	enum_str_TBL_HOLE_FLD_SCENEPHOTO,      // 现场照片（视频） varchar
	enum_str_TBL_HOLE_FLD_CONSTRUCTRECORD, // 施工记录 varchar
	enum_str_TBL_HOLE_FLD_MEMO,            // 备注 varchar
	// 钻孔测斜表
	enum_int_TBL_INCLINAT_FLD_HOLEID,          // 钻孔ID int
	enum_double_TBL_INCLINAT_FLD_MEASUREDEPTH, // 测点深度 double
	enum_double_TBL_INCLINAT_FLD_AZIMUTHANGLE, // 方位角 double
	enum_double_TBL_INCLINAT_FLD_DIPANGLE,     // 倾角 double
	// 测井基本情况表
	enum_int_TBL_LOGGING_FLD_LOGGINGID,     // 测井id int
	enum_int_TBL_LOGGING_FLD_HOLEID,        // 钻孔ID int
	enum_str_TBL_LOGGING_FLD_DEVICENAME,    // 仪器名称 varchar
	enum_str_TBL_LOGGING_FLD_DEVICETYPE,    // 仪器型号 varchar
	enum_double_TBL_LOGGING_FLD_STARTDEPTH, // 探测起始深度(m) float
	enum_double_TBL_LOGGING_FLD_ENDDEPTH,   // 探测终止深度(m) float
	enum_double_TBL_LOGGING_FLD_SAMPLEGAP,  // 采样间隔(m) float
	enum_str_TBL_LOGGING_FLD_LOGGINGDOC,    // 测井数据文档 varchar
	enum_str_TBL_LOGGING_FLD_TKALD,         // 施工单位 varchar
	enum_str_TBL_LOGGING_FLD_OPERATOR,      // 操作人 varchar
	enum_str_TBL_LOGGING_FLD_DETECTDATE,    // 探测日期 date
	enum_str_TBL_LOGGING_FLD_INPUTER,       // 录入员 varchar
	enum_str_TBL_LOGGING_FLD_INPUTORGN,     // 录入单位 varchar
	enum_str_TBL_LOGGING_FLD_INPUTDATE,     // 录入日期 date
	// 标准地层用虚拟钻孔基本信息表
	enum_int_TBL_VIRHOLE_FLD_VIRHOLEID,       // 虚拟孔ID int
	enum_str_TBL_VIRHOLE_FLD_VIRHOLENO,       // 虚拟孔号 varchar
	enum_double_TBL_VIRHOLE_FLD_X,            // X double
	enum_double_TBL_VIRHOLE_FLD_Y,            // Y double
	enum_double_TBL_VIRHOLE_FLD_Z,            // Z double
	enum_double_TBL_VIRHOLE_FLD_VIRHOLEDEPTH, // 孔深 double
	enum_str_TBL_VIRHOLE_FLD_PLANECOSYS,      // 平面坐标系 varchar
	enum_str_TBL_VIRHOLE_FLD_REGISTRATUNIT,   // 录入单位 varchar
	enum_str_TBL_VIRHOLE_FLD_REGISTER,        // 录入员 varchar
	enum_str_TBL_VIRHOLE_FLD_REGISTRATDATE,   // 录入日期 date
	// 标准地层用虚拟钻孔分层信息表
	enum_int_TBL_VIRHOLELAYER_FLD_VIRHOLELAYERID,    // 虚拟分层ID int
	enum_int_TBL_VIRHOLELAYER_FLD_VIRHOLEID,         // 虚拟孔ID int
	enum_str_TBL_VIRHOLELAYER_FLD_VIRHOLENO,         // 虚拟孔号 varchar
	enum_int_TBL_VIRHOLELAYER_FLD_LAYERNO,           // 分层序号 int
	enum_str_TBL_VIRHOLELAYER_FLD_VIRLAYERCODE,      // 虚拟层编码 varchar
	enum_str_TBL_VIRHOLELAYER_FLD_GEOCODE,           // 地质代号 varchar
	enum_str_TBL_VIRHOLELAYER_FLD_DDCDIA,            // 地质时代 varchar
	enum_str_TBL_VIRHOLELAYER_FLD_GCKUPE,            // 成因类型 varchar
	enum_str_TBL_VIRHOLELAYER_FLD_YSEB,              // 岩土名称 varchar
	enum_double_TBL_VIRHOLELAYER_FLD_LAYERDEPTH,     // 分层深度 double
	enum_double_TBL_VIRHOLELAYER_FLD_LAYERTHICKNESS, // 分层厚度 double
	enum_str_TBL_VIRHOLELAYER_FLD_YSHB,              // 岩土颜色 varchar
	enum_str_TBL_VIRHOLELAYER_FLD_ENGTRAIT,          // 工程性状 varchar
	enum_str_TBL_VIRHOLELAYER_FLD_WATERTRAIT,        // 含水性状 varchar
	enum_str_TBL_VIRHOLELAYER_FLD_GCKLT,             // 岩性描述 varchar
	enum_int_TBL_VIRHOLELAYER_FLD_LAYERID,           // 分层号ID int
	enum_double_TBL_VIRHOLELAYER_FLD_LAYERTOPDEPTH,  // 原始层顶深度 double
	enum_double_TBL_VIRHOLELAYER_FLD_BOTTOMDEPTH,    // 原始层底深度 double
	enum_double_TBL_VIRHOLELAYER_FLD_TOPELEVATION,   // 原始分层厚度 double
	enum_str_TBL_VIRHOLELAYER_FLD_FIELDLAYERNUM,     // 野外分层号 varchar
	enum_str_TBL_VIRHOLELAYER_FLD_HOLECODE,          // 地层来源钻孔编号 varchar
	enum_str_TBL_VIRHOLELAYER_FLD_PKIAA,             // 地层来源钻孔的项目统一编号 varchar
	// 探槽观测点信息表
	enum_int_TBL_WELLSLOT_FLD_DETECTID,        // 探槽观测点ID int
	enum_str_TBL_WELLSLOT_FLD_DETECTNO,        // 探槽观测点编号 varchar
	enum_str_TBL_WELLSLOT_FLD_PKIAA,           // 项目统一编号 varchar
	enum_double_TBL_WELLSLOT_FLD_DISTANCE,     // 与起始点距离(m) float
	enum_double_TBL_WELLSLOT_FLD_ORIENTATION,  // 位于起始点方位(度) float
	enum_int_TBL_WELLSLOT_FLD_PNTID,           // 点ID int
	enum_str_TBL_WELLSLOT_FLD_GCEABC,          // 野外编号 varchar
	enum_str_TBL_WELLSLOT_FLD_SWBCBC,          // 探井目的 varchar
	enum_str_TBL_WELLSLOT_FLD_EXPLORETYPE,     // 勘探类型 varchar
	enum_double_TBL_WELLSLOT_FLD_EXPLOREDEPTH, // 勘探深度 float
	enum_double_TBL_WELLSLOT_FLD_GCJDBN,       // 开挖体积 float
	enum_double_TBL_WELLSLOT_FLD_SWEGAB,       // 水位埋深(m) float
	enum_str_TBL_WELLSLOT_FLD_GCKBBA,          // 地形地貌 varchar
	enum_str_TBL_WELLSLOT_FLD_GEOCONDIT,       // 地质条件 varchar
	enum_str_TBL_WELLSLOT_FLD_HYDROCONDIT,     // 水文地质条件 varchar
	enum_str_TBL_WELLSLOT_FLD_ENGCONDIT,       // 工程地质条件 varchar
	enum_str_TBL_WELLSLOT_FLD_HJY,             // 环境地质问题 varchar
	enum_str_TBL_WELLSLOT_FLD_ECOENVCONDIT,    // 生态环境状况 varchar
	enum_str_TBL_WELLSLOT_FLD_GCIAEB,          // 土地利用现状 varchar
	enum_str_TBL_WELLSLOT_FLD_SWDCG,           // 沿途观测 varchar
	enum_str_TBL_WELLSLOT_FLD_TKALD,           // 施工单位 varchar
	enum_str_TBL_WELLSLOT_FLD_TECHNICIAN,      // 技术员 varchar
	enum_str_TBL_WELLSLOT_FLD_DETECTDATE,      // 勘探日期 date
	enum_str_TBL_WELLSLOT_FLD_INPUTORGN,       // 录入单位 varchar
	enum_str_TBL_WELLSLOT_FLD_INPUTER,         // 录入员 varchar
	enum_str_TBL_WELLSLOT_FLD_INPUTDATE,       // 录入日期 date
	enum_str_TBL_WELLSLOT_FLD_SWLBAB,          // 平面示意图 varchar
	enum_str_TBL_WELLSLOT_FLD_SWLBAA,          // 剖面示意图 varchar
	enum_str_TBL_WELLSLOT_FLD_SCENEPHOTO,      // 现场照片 varchar
	enum_str_TBL_WELLSLOT_FLD_CONSTRUCTRECORD, // 施工记录 varchar
	enum_str_TBL_WELLSLOT_FLD_MEMO,            // 备注 varchar
	// 浅井探槽岩性分层描述表
	enum_int_TBL_WALLSLOTLAYER_FLD_WALLSLOTLAYERID,    // 井槽分层ID int
	enum_str_TBL_WALLSLOTLAYER_FLD_FIELDLAYERNO,       // 野外分层号 varchar
	enum_str_TBL_WALLSLOTLAYER_FLD_GCEABC,             // 野外编号 varchar
	enum_str_TBL_WALLSLOTLAYER_FLD_PKIAA,              // 项目编号 varchar
	enum_int_TBL_WALLSLOTLAYER_FLD_DETECTID,           // 探槽观测点ID int
	enum_double_TBL_WALLSLOTLAYER_FLD_TOPDEPTH,        // 层顶深度(m) double
	enum_double_TBL_WALLSLOTLAYER_FLD_BOTTOMDEPTH,     // 层底深度(m) double
	enum_double_TBL_WALLSLOTLAYER_FLD_TOPELEVATION,    // 层顶高程(m) double
	enum_double_TBL_WALLSLOTLAYER_FLD_BOTTOMELEVATION, // 层底高程(m) double
	enum_double_TBL_WALLSLOTLAYER_FLD_LAYERTHICK,      // 分层厚度(m) double
	enum_str_TBL_WALLSLOTLAYER_FLD_GEOCODE,            // 地质代号 varchar
	enum_str_TBL_WALLSLOTLAYER_FLD_DDCDIA,             // 地质时代 varchar
	enum_str_TBL_WALLSLOTLAYER_FLD_GCKUPE,             // 成因类型 varchar
	enum_str_TBL_WALLSLOTLAYER_FLD_YSEB,               // 岩土名称 varchar
	enum_str_TBL_WALLSLOTLAYER_FLD_YSHB,               // 岩土颜色 varchar
	enum_str_TBL_WALLSLOTLAYER_FLD_ENGTRAIT,           // 工程性状 varchar
	enum_str_TBL_WALLSLOTLAYER_FLD_WATERYTRAIT,        // 含水性状 varchar
	enum_str_TBL_WALLSLOTLAYER_FLD_GCKLT,              // 岩性描述 varchar
	// 电（磁）法勘探线参数表
	enum_int_TBL_ELECLINE_FLD_ELECLINEID,        // 电(磁)法测线ID int
	enum_str_TBL_ELECLINE_FLD_LINECODE,          // 测线号 varchar
	enum_double_TBL_ELECLINE_FLD_DOTPITCH,       // 点距(m) float
	enum_int_TBL_ELECLINE_FLD_DETEDOTCOUNT,      // 测点数 int
	enum_double_TBL_ELECLINE_FLD_DETELINELENGTH, // 测线长度(km) float
	enum_double_TBL_ELECLINE_FLD_DATELINEORIENT, // 测线方位(度) float
	enum_str_TBL_ELECLINE_FLD__DEVICE,           // 仪器 varchar
	enum_str_TBL_ELECLINE_FLD_DEVICETYPE,        // 装置类型 varchar
	enum_double_TBL_ELECLINE_FLD_RECDISDIST,     // 收发距(m) float
	enum_double_TBL_ELECLINE_FLD__FREQUENCY,     // 频率(Hz) float
	enum_double_TBL_ELECLINE_FLD_LAUNCHBOXAREA,  // 发射框面积(m2) float
	enum_double_TBL_ELECLINE_FLD_RECBOXAREA,     // 接收线框面积(m2) float
	enum_double_TBL_ELECLINE_FLD_ANTENNAFRE,     // 天线频率(Hz) float
	enum_double_TBL_ELECLINE_FLD_ANTENNADIST,    // 天线间距(m) float
	enum_int_TBL_ELECLINE_FLD_FLD_PRJID,         // 项目ID int
	enum_str_TBL_ELECLINE_FLD_FLD_DETECTMETHOD,  // 探测方法 varchar
	enum_str_TBL_ELECLINE_FLD_FLD_TKALD,         // 施工单位 varchar
	enum_str_TBL_ELECLINE_FLD_FLD_OPERATOR,      // 操作人 varchar
	enum_str_TBL_ELECLINE_FLD_FLD_CHECKER,       // 检查人 varchar
	enum_str_TBL_ELECLINE_FLD_FLD_STARTDATE,     // 起始日期 date
	enum_str_TBL_ELECLINE_FLD_FLD_ENDDATE,       // 完成日期 date
	enum_int_TBL_ELECLINE_FLD_FLD_ORIGDOCID,     // 原始数据文档ID int
	enum_int_TBL_ELECLINE_FLD_FLD_DRRORDOCID,    // 误差文档ID int
	enum_str_TBL_ELECLINE_FLD_FLD_PARADOCID,     // 参数文档ID varchar
	enum_int_TBL_ELECLINE_FLD_FLD_RESULTDOCID,   // 成果数据文档ID int
	enum_str_TBL_ELECLINE_FLD_FLD_INPUTER,       // 录入员 varchar
	enum_str_TBL_ELECLINE_FLD_FLD_INPUTORGN,     // 录入单位 varchar
	enum_str_TBL_ELECLINE_FLD_FLD_INPUTDATE,     // 录入日期 date
	// 地震勘探线参数表
	enum_int_TBL_EARDETELINE_FLD_EARDETELINEID,     // 地震测线ID int
	enum_str_TBL_EARDETELINE_FLD_LINECODE,          // 测线号 varchar
	enum_double_TBL_EARDETELINE_FLD_ROADDIST,       // 道间距(m) float
	enum_int_TBL_EARDETELINE_FLD_RECTIME,           // 接收道数(道) int
	enum_int_TBL_EARDETELINE_FLD_FLIPCOVERTIME,     // 水平覆盖次数(次) int
	enum_int_TBL_EARDETELINE_FLD_SAMPLEGAP,         // 采样间隔(s) int
	enum_double_TBL_EARDETELINE_FLD_RECORDLENGTH,   // 记录长度 float
	enum_double_TBL_EARDETELINE_FLD_BOMBDIST,       // 炮间距(m) float
	enum_double_TBL_EARDETELINE_FLD_DFFSETDIST,     // 偏移距(m) float
	enum_double_TBL_EARDETELINE_FLD_RECULENGTH,     // 迭代段长(m) float
	enum_double_TBL_EARDETELINE_FLD_TRIANGLEMAXLEN, // 三角形最大边长(m) float
	enum_int_TBL_EARDETELINE_FLD_PRJID,             // 项目ID int
	enum_str_TBL_EARDETELINE_FLD_DETECTMETHOD,      // 探测方法 varchar
	enum_str_TBL_EARDETELINE_FLD_TKALD,             // 施工单位 varchar
	enum_str_TBL_EARDETELINE_FLD_OPERATOR,          // 操作人 varchar
	enum_str_TBL_EARDETELINE_FLD_CHECKER,           // 检查人 varchar
	enum_str_TBL_EARDETELINE_FLD_STARTDATE,         // 起始日期 date
	enum_str_TBL_EARDETELINE_FLD_ENDDATE,           // 完成日期 date
	enum_int_TBL_EARDETELINE_FLD_ORIGDOCID,         // 原始数据文档ID int
	enum_int_TBL_EARDETELINE_FLD_DRRORDOCID,        // 误差文档ID int
	enum_str_TBL_EARDETELINE_FLD_PARADOCID,         // 参数文档ID varchar
	enum_int_TBL_EARDETELINE_FLD_RESULTDOCID,       // 成果数据文档ID int
	enum_str_TBL_EARDETELINE_FLD_INPUTER,           // 录入员 varchar
	enum_str_TBL_EARDETELINE_FLD_INPUTORGN,         // 录入单位 varchar
	enum_str_TBL_EARDETELINE_FLD_INPUTDATE,         // 录入日期 date
	// 物探点位标准化信息表
	enum_int_TBL_STDPNT_FLD_STDPNTID,         // 标准测点ID int
	enum_str_TBL_STDPNT_FLD_PNTNO,            // 点号 varchar
	enum_double_TBL_STDPNT_FLD_STKCAF,        // 标准化X double
	enum_double_TBL_STDPNT_FLD_STKCAG,        // 标准化Y double
	enum_double_TBL_STDPNT_FLD_SGCJCBJ,       // 标准化高程(m) double
	enum_str_TBL_STDPNT_FLD_STDPLANECOORDSYS, // 标准化平面坐标系 varchar
	enum_str_TBL_STDPNT_FLD_STDELDATUM,       // 标准化高程基准 varchar
	enum_double_TBL_STDPNT_FLD_LONGITUDE,     // 经度(°) double
	enum_double_TBL_STDPNT_FLD_LATITUDE,      // 纬度(°) double
	enum_double_TBL_STDPNT_FLD_TKCAF,         // X double
	enum_double_TBL_STDPNT_FLD_TKCAG,         // Y double
	enum_double_TBL_STDPNT_FLD_GCJCBJ,        // 高程(m) double
	enum_str_TBL_STDPNT_FLD_PLANECOORDSYS,    // 平面坐标系 varchar
	enum_str_TBL_STDPNT_FLD_ELEDATUM,         // 高程基准 varchar
	enum_str_TBL_STDPNT_FLD_LINECODE,         // 测线号 varchar
	enum_int_TBL_STDPNT_FLD_PRJID,            // 项目ID int
	enum_int_TBL_STDPNT_FLD_PKIAA,            // 项目统一编号 int
	enum_str_TBL_STDPNT_FLD_DETECTMETHOD,     // 探测方法 varchar
	enum_str_TBL_STDPNT_FLD_TKALD,            // 施工单位 varchar
	enum_str_TBL_STDPNT_FLD_OPERATOR,         // 操作人 varchar
	enum_str_TBL_STDPNT_FLD_CHECKER,          // 检查人 varchar
	enum_str_TBL_STDPNT_FLD_STARTDATE,        // 起始日期 date
	enum_str_TBL_STDPNT_FLD_ENDDATE,          // 完成日期 date
	enum_int_TBL_STDPNT_FLD_ORIGDOCID,        // 原始数据文档ID int
	enum_int_TBL_STDPNT_FLD_DRRORDOCID,       // 误差文档ID int
	enum_str_TBL_STDPNT_FLD_PARADOCID,        // 参数文档ID varchar
	enum_int_TBL_STDPNT_FLD_RESULTDOCID,      // 成果数据文档ID int
	enum_str_TBL_STDPNT_FLD_INPUTER,          // 录入员 varchar
	enum_str_TBL_STDPNT_FLD_INPUTORGN,        // 录入单位 varchar
	enum_str_TBL_STDPNT_FLD_INPUTDATE,        // 录入日期 date
	// 标准地层版本表
	enum_int_TBL_STDSTRATVER_FLD_STDSTRATID,   // 标准地层版本 int
	enum_str_TBL_STDSTRATVER_FLD_STDSTRATNAME, // 标准地层名称 varchar
	enum_str_TBL_STDSTRATVER_FLD_PROTYPE,      // 专业类别 varchar
	enum_str_TBL_STDSTRATVER_FLD_PROCODE,      // 专业代码 varchar
	enum_str_TBL_STDSTRATVER_FLD_PRONAME,      // 专业名称 varchar
	enum_str_TBL_STDSTRATVER_FLD_STDAUTHOR,    // 标准作者 varchar
	enum_int_TBL_STDSTRATVER_FLD_STRATLEVNUM,  // 地层级别数 int
	enum_str_TBL_STDSTRATVER_FLD_MEMO,         // 备注 varchar
	// 标准地层描述表
	enum_int_TBL_STDSTRAT_FLD_ROWID,            //* 标准地层分层记录ID int
	enum_int_TBL_STDSTRAT_FLD_STDSTRATID,       // 标准地层版本ID int
	enum_str_TBL_STDSTRAT_FLD_STRATLEVEL,       // 地层分级编号 varchar
	enum_str_TBL_STDSTRAT_FLD_STRATNAME,        // 地层名称 varchar
	enum_str_TBL_STDSTRAT_FLD_STRATCODE,        // 地层编码（Q1,J2,①） varchar
	enum_str_TBL_STDSTRAT_FLD_STRATCODE2,       // 地层编码2（用于地层合并整理） varchar
	enum_int_TBL_STDSTRAT_FLD_STRATTYPE,        // 地层类型 int
	enum_int_TBL_STDSTRAT_FLD_STRATCLR,         // 地层颜色 int
	enum_str_TBL_STDSTRAT_FLD_PATTERNNO,        // 图案号 text
	enum_int_TBL_STDSTRAT_FLD_PATTERNCLR,       // 图案颜色 int
	enum_double_TBL_STDSTRAT_FLD_PATTERNHEIGHT, // 图案高度 float
	enum_double_TBL_STDSTRAT_FLD_PATTERNWIDTH,  // 图案宽度 float
	enum_double_TBL_STDSTRAT_FLD_FILLDIR,       // 图案旋转方向 float
	enum_str_TBL_STDSTRAT_FLD_STRATDESC,        // 地层描述 varchar
	enum_str_TBL_STDSTRAT_FLD_CAUSECODE,        // 成因代码 varchar
	enum_str_TBL_STDSTRAT_FLD_DECAYRATE,        // 风化程度 varchar
	enum_str_TBL_STDSTRAT_FLD_CAUSETYPE,        // 地层成因 varchar
	enum_str_TBL_STDSTRAT_FLD_AGENO,            // 地质时代 varchar
	enum_str_TBL_STDSTRAT_FLD_GEOCODE,          // 地层代号 varchar
	enum_str_TBL_STDSTRAT_FLD_ENGTRAIT,         // 工程性状 varchar
	enum_str_TBL_STDSTRAT_FLD_WATERYTRAIT,      // 含水性状 varchar
	enum_int_TBL_STDSTRAT_FLD_FIELDLAYERID,     // 野外分层ID int
	enum_str_TBL_STDSTRAT_FLD_FIELDLAYERNUM,    // 野外分层号 varchar
	enum_str_TBL_STDSTRAT_FLD_YSEB,             // 岩土名称 varchar
	enum_str_TBL_STDSTRAT_FLD_YSHB,             // 岩土颜色 varchar
	enum_str_TBL_STDSTRAT_FLD__MEMO,            // 备注 varchar
	// 钻孔分层表
	enum_int_TBL_HOLELAYER_FLD_ROWID,		  // *钻孔分层记录ID int
	enum_int_TBL_HOLELAYER_FLD_HOLEID,        // 钻孔ID int
	enum_int_TBL_HOLELAYER_FLD_STDSTRATID,    // 标准地层版本ID int
	enum_str_TBL_HOLELAYER_FLD_STRATCODE,     // 地层编码 varchar
	enum_str_TBL_HOLELAYER_FLD_STRATNAME,     // 地层名称 varchar
	enum_double_TBL_HOLELAYER_FLD_TOPDEPTH,   // 层顶埋深 double
	enum_double_TBL_HOLELAYER_FLD_BTMDEPTH,   // 层底埋深 double
	enum_str_TBL_HOLELAYER_FLD_GCKLT,         // 地层描述 varchar
	enum_str_TBL_HOLELAYER_FLD_DDCDIA,        // 地质时代 varchar
	enum_str_TBL_HOLELAYER_FLD_GCKUPE,        // 成因类型 varchar
	enum_str_TBL_HOLELAYER_FLD_GEOCODE,       // 地质代号 varchar
	enum_str_TBL_HOLELAYER_FLD_YSEB,          // 岩土名称 varchar
	enum_str_TBL_HOLELAYER_FLD_YSHB,          // 岩土颜色 varchar
	enum_str_TBL_HOLELAYER_FLD_ENGTRAIT,      // 工程性状 varchar
	enum_str_TBL_HOLELAYER_FLD_WATERYTRAIT,   // 含水性状 varchar
	enum_int_TBL_HOLELAYER_FLD_FIELDLAYERID,  // 野外分层ID int
	enum_str_TBL_HOLELAYER_FLD_FIELDLAYERNUM, // 野外分层号 varchar
	// 钻孔原始分层表
	enum_int_TBL_ORIGLAYER_FLD_FIELDLAYERID,       // 野外分层号ID int
	enum_str_TBL_ORIGLAYER_FLD_FIELDLAYERNUM,      // 野外分层号 varchar
	enum_int_TBL_ORIGLAYER_FLD_HOLEID,             // 钻孔ID int
	enum_str_TBL_ORIGLAYER_FLD_GEOCODE,            // 地质代号 varchar
	enum_str_TBL_ORIGLAYER_FLD_DDCDIA,             // 地质时代 varchar
	enum_str_TBL_ORIGLAYER_FLD_GCKUPE,             // 成因类型 varchar
	enum_double_TBL_ORIGLAYER_FLD_TOPDEPTH,        // 层顶深度 double
	enum_double_TBL_ORIGLAYER_FLD_BOTTOMDEPTH,     // 层底深度 double
	enum_double_TBL_ORIGLAYER_FLD_TOPELEVATION,    // 层顶高程 double
	enum_double_TBL_ORIGLAYER_FLD_BOTTOMELEVATION, // 层底高程 double
	enum_double_TBL_ORIGLAYER_FLD_LAYERTHICK,      // 分层厚度 double
	enum_str_TBL_ORIGLAYER_FLD_YSEB,               // 岩土名称 varchar
	enum_str_TBL_ORIGLAYER_FLD_YSHB,               // 岩土颜色 varchar
	enum_str_TBL_ORIGLAYER_FLD_ENGTRAIT,           // 工程性状 varchar
	enum_str_TBL_ORIGLAYER_FLD_WATERYTRAIT,        // 含水性状 varchar
	enum_str_TBL_ORIGLAYER_FLD_GCKLT,              // 岩性描述 varchar
	// 止水结构表
	enum_int_TBL_WATERSEAL_FLD_WATERSEALID,     // 止水ID int
	enum_int_TBL_WATERSEAL_FLD_HOLEID,          // 钻孔ID int
	enum_double_TBL_WATERSEAL_FLD_SWCEA,        // 止水深度(m) double
	enum_str_TBL_WATERSEAL_FLD_SWCEB,           // 止水方法 varchar
	enum_str_TBL_WATERSEAL_FLD_SEALINGMATERIAL, // 止水材料 varchar
	// 填砾结构表
	enum_int_TBL_GRAVELPACK_FLD_GRAVELPACKID,  // 填砾ID int
	enum_int_TBL_GRAVELPACK_FLD_HOLEID,        // 钻孔ID int
	enum_double_TBL_GRAVELPACK_FLD_SWCDH,      // 填砾顶深度(m) double
	enum_double_TBL_GRAVELPACK_FLD_SWCGBD,     // 填砾底深度(m) double
	enum_double_TBL_GRAVELPACK_FLD_SWCGBC,     // 填砾厚度(m) double
	enum_str_TBL_GRAVELPACK_FLD_SWCDF,         // 砾料类型 varchar
	enum_str_TBL_GRAVELPACK_FLD_GRAVELSPECIFY, // 砾料规格 varchar
	// 井管结构表
	enum_int_TBL_WELLPIPE_FLD_WELLPIPEID,       // 井管ID int
	enum_int_TBL_WELLPIPE_FLD_HOLEID,           // 钻孔ID int
	enum_double_TBL_WELLPIPE_FLD_TKACE,         // 变径深度(m) double
	enum_double_TBL_WELLPIPE_FLD_HOLETOPDIAM,   // 井口外径(mm) double
	enum_str_TBL_WELLPIPE_FLD_SWCCB,            // 井管类型 varchar
	enum_str_TBL_WELLPIPE_FLD_WELLPIPEMATERIAL, // 井管材质 varchar
	// 孔径变化表
	enum_int_TBL_APERTURE_FLD_APERTUREID, // 孔径ID int
	enum_int_TBL_APERTURE_FLD_HOLEID,     // 钻孔ID int
	enum_double_TBL_APERTURE_FLD_TKACE,   // 变径深度(m) float
	enum_double_TBL_APERTURE_FLD_SWCL,    // 钻孔直径(mm) float
	// 标准贯入试验记录表
	enum_int_TBL_EGSTDPENETRATION_FLD_STDPENETRATID,       // 标贯记录ID int
	enum_str_TBL_EGSTDPENETRATION_FLD_TESTHORIZON,         // 试验层位 varchar
	enum_double_TBL_EGSTDPENETRATION_FLD_STARTDEPTH,       // 起深度(m) float
	enum_double_TBL_EGSTDPENETRATION_FLD_ENDDEPTH,         // 止深度(m) float
	enum_int_TBL_EGSTDPENETRATION_FLD_PNTID,               // 点ID int
	enum_str_TBL_EGSTDPENETRATION_FLD_INSITUTESTNO,        // 试验编号 varchar
	enum_str_TBL_EGSTDPENETRATION_FLD_TESTCATEGORY,        // 试验类型 varchar
	enum_int_TBL_EGSTDPENETRATION_FLD_HAMMERNUM,           // 锤击数 int
	enum_double_TBL_EGSTDPENETRATION_FLD_HITMEASNUM,       // 实测标贯击数(击/30cm) float
	enum_double_TBL_EGSTDPENETRATION_FLD_POLELENGTH,       // 杆长(m) float
	enum_double_TBL_EGSTDPENETRATION_FLD_RODCORRECTFACTOR, // 杆长校正系数 float
	enum_double_TBL_EGSTDPENETRATION_FLD_HITCORRECTNUM,       // 校正后标贯击数(击/30cm) float
	enum_str_TBL_EGSTDPENETRATION_FLD_GEOCODE,             // 地质代号 varchar
	enum_str_TBL_EGSTDPENETRATION_FLD_TCMC,                // 土层名称 varchar
	enum_str_TBL_EGSTDPENETRATION_FLD__MEMO,               // 备注 varchar
	enum_str_TBL_EGSTDPENETRATION_FLD_TEST_EQUIPMODEL,     // 试验设备及型号 varchar
	enum_str_TBL_EGSTDPENETRATION_FLD_TESTSTARTDATE,       // 试验开始日期 date
	enum_str_TBL_EGSTDPENETRATION_FLD_TESTENDDATE,         // 试验完成日期 date
	enum_str_TBL_EGSTDPENETRATION_FLD_TESTORGN,            // 试验单位 varchar
	enum_str_TBL_EGSTDPENETRATION_FLD_OPERATOR,            // 操作人 varchar
	enum_str_TBL_EGSTDPENETRATION_FLD_TECHNICIAN,          // 现场技术员 varchar
	enum_str_TBL_EGSTDPENETRATION_FLD_INPUTER,             // 录入员 varchar
	enum_str_TBL_EGSTDPENETRATION_FLD_INPUTORGN,           // 录入单位 varchar
	enum_str_TBL_EGSTDPENETRATION_FLD_INPUTDATE,           // 录入日期 date
	// 静力触探试验记录表
	enum_int_TBL_EGSTATICPENETRATION_FLD_STATICCONTACTID,  // 静探试验ID int
	enum_str_TBL_EGSTATICPENETRATION_FLD_TESTHORIZON,      // 试验层位 varchar
	enum_double_TBL_EGSTATICPENETRATION_FLD_STARTDEPTH,    // 起深度 float
	enum_double_TBL_EGSTATICPENETRATION_FLD_ENDDEPTH,      // 止深度 float
	enum_int_TBL_EGSTATICPENETRATION_FLD_PNTID,            // 点ID int
	enum_str_TBL_EGSTATICPENETRATION_FLD_INSITUTESTNO,     // 试验编号 varchar
	enum_str_TBL_EGSTATICPENETRATION_FLD_TESTCATEGORY,     // 试验类型 varchar
	enum_str_TBL_EGSTATICPENETRATION_FLD_PROBETYPE,        // 探头类型 varchar
	enum_double_TBL_EGSTATICPENETRATION_FLD_GCEBCJ,        // 锥尖阻力 float
	enum_double_TBL_EGSTATICPENETRATION_FLD_GCEBCK,        // 侧壁摩阻力 float
	enum_double_TBL_EGSTATICPENETRATION_FLD_GCEBCM,        // 比贯入阻力 float
	enum_double_TBL_EGSTATICPENETRATION_FLD_GCDLAK,        // 孔隙水压力 float
	enum_double_TBL_EGSTATICPENETRATION_FLD_FRICTIONRATIO, // 摩阻比 float
	enum_str_TBL_EGSTATICPENETRATION_FLD_GEOCODE,          // 地质代号 varchar
	enum_str_TBL_EGSTATICPENETRATION_FLD_TCMC,             // 土层名称 varchar
	enum_str_TBL_EGSTATICPENETRATION_FLD__MEMO,            // 备注 varchar
	enum_str_TBL_EGSTATICPENETRATION_FLD_TEST_EQUIPMODEL,  // 试验设备及型号 varchar
	enum_str_TBL_EGSTATICPENETRATION_FLD_TESTSTARTDATE,    // 试验开始日期 date
	enum_str_TBL_EGSTATICPENETRATION_FLD_TESTENDDATE,      // 试验完成日期 date
	enum_str_TBL_EGSTATICPENETRATION_FLD_TESTORGN,         // 试验单位 varchar
	enum_str_TBL_EGSTATICPENETRATION_FLD_OPERATOR,         // 操作人 varchar
	enum_str_TBL_EGSTATICPENETRATION_FLD_TECHNICIAN,       // 现场技术员 varchar
	enum_str_TBL_EGSTATICPENETRATION_FLD_INPUTER,          // 录入员 varchar
	enum_str_TBL_EGSTATICPENETRATION_FLD_INPUTORGN,        // 录入单位 varchar
	enum_str_TBL_EGSTATICPENETRATION_FLD_INPUTDATE,        // 录入日期 date
	// 重型动力触探实验记录表
	enum_int_TBL_MOTDETECT_FLD_MOTDETECTID,         // 动探记录ID int
	enum_str_TBL_MOTDETECT_FLD_TESTHORIZON,         // 试验层位 varchar
	enum_double_TBL_MOTDETECT_FLD_STARTDEPTH,       // 起深度 float
	enum_double_TBL_MOTDETECT_FLD_ENDDEPTH,         // 止深度 float
	enum_int_TBL_MOTDETECT_FLD_PNTID,               // 点ID int
	enum_str_TBL_MOTDETECT_FLD_INSITUTESTNO,        // 试验编号 varchar
	enum_str_TBL_MOTDETECT_FLD_TESTCATEGORY,        // 试验类型 varchar
	enum_str_TBL_MOTDETECT_FLD_SOUNDTYPE,           // 触探类型 varchar
	enum_double_TBL_MOTDETECT_FLD_HAMMERNUM,        // 实测锤击数 double
	enum_double_TBL_MOTDETECT_FLD_POLELENGTH,       // 杆长 double
	enum_double_TBL_MOTDETECT_FLD_RODCORRECTFACTOR, // 杆长校正系数 float
	enum_double_TBL_MOTDETECT_FLD_SWEGAB,           // 地下水位埋深 float
	enum_double_TBL_MOTDETECT_FLD_GCBAF,            // 粘粒含量 float
	enum_double_TBL_MOTDETECT_FLD_HITCORRECTNUM,    // 修正后锤击数 double
	enum_double_TBL_MOTDETECT_FLD_PENETRATCORRECT,  // 修正后贯入度 float
	enum_str_TBL_MOTDETECT_FLD_GEOCODE,             // 地质代号 varchar
	enum_str_TBL_MOTDETECT_FLD_TCMC,                // 土层名称 varchar
	enum_str_TBL_MOTDETECT_FLD__MEMO,               // 备注 varchar
	enum_str_TBL_MOTDETECT_FLD_TEST_EQUIPMODEL,     // 试验设备及型号 varchar
	enum_str_TBL_MOTDETECT_FLD_TESTSTARTDATE,       // 试验开始日期 date
	enum_str_TBL_MOTDETECT_FLD_TESTENDDATE,         // 试验完成日期 date
	enum_str_TBL_MOTDETECT_FLD_TESTORGN,            // 试验单位 varchar
	enum_str_TBL_MOTDETECT_FLD_OPERATOR,            // 操作人 varchar
	enum_str_TBL_MOTDETECT_FLD_TECHNICIAN,          // 现场技术员 varchar
	enum_str_TBL_MOTDETECT_FLD_INPUTER,             // 录入员 varchar
	enum_str_TBL_MOTDETECT_FLD_INPUTORGN,           // 录入单位 varchar
	enum_str_TBL_MOTDETECT_FLD_INPUTDATE,           // 录入日期 date
	// 轻型动力触探实验记录表
	enum_int_TBL_LIGHTMOTDETECT_FLD_MOTDETECTID,         // 动探记录ID int
	enum_str_TBL_LIGHTMOTDETECT_FLD_TESTHORIZON,         // 试验层位 varchar
	enum_double_TBL_LIGHTMOTDETECT_FLD_STARTDEPTH,       // 起深度 float
	enum_double_TBL_LIGHTMOTDETECT_FLD_ENDDEPTH,         // 止深度 float
	enum_int_TBL_LIGHTMOTDETECT_FLD_PNTID,               // 点ID int
	enum_str_TBL_LIGHTMOTDETECT_FLD_INSITUTESTNO,        // 试验编号 varchar
	enum_str_TBL_LIGHTMOTDETECT_FLD_TESTCATEGORY,        // 试验类型 varchar
	enum_str_TBL_LIGHTMOTDETECT_FLD_SOUNDTYPE,           // 触探类型 varchar
	enum_double_TBL_LIGHTMOTDETECT_FLD_HAMMERNUM,        // 实测锤击数 double
	enum_double_TBL_LIGHTMOTDETECT_FLD_POLELENGTH,       // 杆长 double
	enum_double_TBL_LIGHTMOTDETECT_FLD_RODCORRECTFACTOR, // 杆长校正系数 float
	enum_double_TBL_LIGHTMOTDETECT_FLD_SWEGAB,           // 地下水位埋深 float
	enum_double_TBL_LIGHTMOTDETECT_FLD_GCBAF,            // 粘粒含量 float
	enum_int_TBL_LIGHTMOTDETECT_FLD_HITCORRECTNUM,       // 修正后锤击数 int
	enum_double_TBL_LIGHTMOTDETECT_FLD_PENETRATCORRECT,  // 修正后贯入度 float
	enum_str_TBL_LIGHTMOTDETECT_FLD_GEOCODE,             // 地质代号 varchar
	enum_str_TBL_LIGHTMOTDETECT_FLD_TCMC,                // 土层名称 varchar
	enum_str_TBL_LIGHTMOTDETECT_FLD__MEMO,               // 备注 varchar
	enum_str_TBL_LIGHTMOTDETECT_FLD_TEST_EQUIPMODEL,     // 试验设备及型号 varchar
	enum_str_TBL_LIGHTMOTDETECT_FLD_TESTSTARTDATE,       // 试验开始日期 date
	enum_str_TBL_LIGHTMOTDETECT_FLD_TESTENDDATE,         // 试验完成日期 date
	enum_str_TBL_LIGHTMOTDETECT_FLD_TESTORGN,            // 试验单位 varchar
	enum_str_TBL_LIGHTMOTDETECT_FLD_OPERATOR,            // 操作人 varchar
	enum_str_TBL_LIGHTMOTDETECT_FLD_TECHNICIAN,          // 现场技术员 varchar
	enum_str_TBL_LIGHTMOTDETECT_FLD_INPUTER,             // 录入员 varchar
	enum_str_TBL_LIGHTMOTDETECT_FLD_INPUTORGN,           // 录入单位 varchar
	enum_str_TBL_LIGHTMOTDETECT_FLD_INPUTDATE,           // 录入日期 date
	// 十字板剪切试验记录表
	enum_int_TBL_EGSHEAR_FLD_CROSSPLATEID,    // 十字板试验ID int
	enum_str_TBL_EGSHEAR_FLD_TESTHORIZON,     // 试验层位 varchar
	enum_double_TBL_EGSHEAR_FLD_STARTDEPTH,   // 起深度(m) float
	enum_double_TBL_EGSHEAR_FLD_ENDDEPTH,     // 止深度(m) float
	enum_int_TBL_EGSHEAR_FLD_PNTID,           // 点ID int
	enum_str_TBL_EGSHEAR_FLD_INSITUTESTNO,    // 试验编号 varchar
	enum_str_TBL_EGSHEAR_FLD_TESTCATEGORY,    // 试验类型 varchar
	enum_double_TBL_EGSHEAR_FLD_GCDMAM,       // 原状土抗剪强度 float
	enum_double_TBL_EGSHEAR_FLD_GCDMAO,       // 重塑土抗剪强度 float
	enum_double_TBL_EGSHEAR_FLD_GCBFOA,       // 粘聚力 float
	enum_double_TBL_EGSHEAR_FLD_GCDKCS,       // 残余强度 float
	enum_double_TBL_EGSHEAR_FLD_GCBFI,        // 灵敏度 float
	enum_str_TBL_EGSHEAR_FLD_GEOCODE,         // 地质代号 varchar
	enum_str_TBL_EGSHEAR_FLD_TCMC,            // 土层名称 varchar
	enum_str_TBL_EGSHEAR_FLD__MEMO,           // 备注 varchar
	enum_str_TBL_EGSHEAR_FLD_TEST_EQUIPMODEL, // 试验设备及型号 varchar
	enum_str_TBL_EGSHEAR_FLD_TESTSTARTDATE,   // 试验开始日期 date
	enum_str_TBL_EGSHEAR_FLD_TESTENDDATE,     // 试验完成日期 date
	enum_str_TBL_EGSHEAR_FLD_TESTORGN,        // 试验单位 varchar
	enum_str_TBL_EGSHEAR_FLD_OPERATOR,        // 操作人 varchar
	enum_str_TBL_EGSHEAR_FLD_TECHNICIAN,      // 现场技术员 varchar
	enum_str_TBL_EGSHEAR_FLD_INPUTER,         // 录入员 varchar
	enum_str_TBL_EGSHEAR_FLD_INPUTORGN,       // 录入单位 varchar
	enum_str_TBL_EGSHEAR_FLD_INPUTDATE,       // 录入日期 date
	// 波速测试记录表
	enum_int_TBL_WAVESPEED_FLD_WAVESPEEDID,     // 波速记录ID int
	enum_str_TBL_WAVESPEED_FLD_TESTHORIZON,     // 试验层位 varchar
	enum_double_TBL_WAVESPEED_FLD_STARTDEPTH,   // 起深度(m) float
	enum_double_TBL_WAVESPEED_FLD_ENDDEPTH,     // 止深度(m) float
	enum_int_TBL_WAVESPEED_FLD_PNTID,           // 点ID int
	enum_str_TBL_WAVESPEED_FLD_INSITUTESTNO,    // 试验编号 varchar
	enum_str_TBL_WAVESPEED_FLD_TESTCATEGORY,    // 试验类型 varchar
	enum_str_TBL_WAVESPEED_FLD_TESTMETHOD,      // 试验方法 varchar
	enum_double_TBL_WAVESPEED_FLD_SWVMAX,       // 最大剪切波速(m/s) float
	enum_double_TBL_WAVESPEED_FLD_SWVMIN,       // 最小剪切波速(m/s) float
	enum_double_TBL_WAVESPEED_FLD_SWVAVER,      // 平均剪切波速(m/s) float
	enum_double_TBL_WAVESPEED_FLD_GCEBHD,       // 压缩波速 float
	enum_double_TBL_WAVESPEED_FLD_ZBBS,         // 纵波波速 float
	enum_str_TBL_WAVESPEED_FLD_GCEBHF,          // 场地类别 varchar
	enum_str_TBL_WAVESPEED_FLD_GCEBHA,          // 波速试验类型 varchar
	enum_str_TBL_WAVESPEED_FLD_GEOCODE,         // 地质代号 varchar
	enum_str_TBL_WAVESPEED_FLD_TCMC,            // 土层名称 varchar
	enum_str_TBL_WAVESPEED_FLD__MEMO,           // 备注 varchar
	enum_str_TBL_WAVESPEED_FLD_TEST_EQUIPMODEL, // 试验设备及型号 varchar
	enum_str_TBL_WAVESPEED_FLD_TESTSTARTDATE,   // 试验开始日期 date
	enum_str_TBL_WAVESPEED_FLD_TESTENDDATE,     // 试验完成日期 date
	enum_str_TBL_WAVESPEED_FLD_TESTORGN,        // 试验单位 varchar
	enum_str_TBL_WAVESPEED_FLD_OPERATOR,        // 操作人 varchar
	enum_str_TBL_WAVESPEED_FLD_TECHNICIAN,      // 现场技术员 varchar
	enum_str_TBL_WAVESPEED_FLD_INPUTER,         // 录入员 varchar
	enum_str_TBL_WAVESPEED_FLD_INPUTORGN,       // 录入单位 varchar
	enum_str_TBL_WAVESPEED_FLD_INPUTDATE,       // 录入日期 date
	// 旁压实验成果表
	enum_int_TBL_PMT_FLD_PMTID,                  // 旁压试验ID int
	enum_str_TBL_PMT_FLD_TESTHORIZON,            // 试验层位 varchar
	enum_double_TBL_PMT_FLD_STARTDEPTH,          // 起深度(m) float
	enum_double_TBL_PMT_FLD_ENDDEPTH,            // 止深度(m) float
	enum_int_TBL_PMT_FLD_PNTID,                  // 点ID int
	enum_str_TBL_PMT_FLD_INSITUTESTNO,           // 试验编号 varchar
	enum_str_TBL_PMT_FLD_TESTCATEGORY,           // 试验类型 varchar
	enum_str_TBL_PMT_FLD_PRESSSTAGE,             // 加压级数 varchar
	enum_double_TBL_PMT_FLD_PRESSRAMPUP,         // 加压增量(kPa) float
	enum_double_TBL_PMT_FLD_PIPEDIST,            // 量管水面离孔口距离(m) float
	enum_double_TBL_PMT_FLD_HYDROSTATICPRESS,    // 静水压力(kPa) float
	enum_double_TBL_PMT_FLD_INITIALPRESS,        // 初始压力(kPa) float
	enum_double_TBL_PMT_FLD_ULTIMATEPRESS,       // 极限压力(kPa) float
	enum_double_TBL_PMT_FLD_PLASTICPRESS,        // 临塑压力(kPa) float
	enum_double_TBL_PMT_FLD_CHARACTVALUE,        // 地基承载力特征值(kPa) float
	enum_double_TBL_PMT_FLD_SIDEPRESSMODULE,     // 旁压模量(MPa) float
	enum_double_TBL_PMT_FLD_GCDKBA,              // 变形模量(MPa) float
	enum_double_TBL_PMT_FLD_SIDEPRESSDP,         // 旁压变形参数(MPa) float
	enum_double_TBL_PMT_FLD_EARTHPRESSURE,       // 土压力(kPa) float
	enum_double_TBL_PMT_FLD_SIDEPRESSHORIZONTAL, // 旁压水平侧压力(kPa) float
	enum_double_TBL_PMT_FLD_GCEBBAULTIMATE,      // 地基承载力(极限法)(kPa) float
	enum_double_TBL_PMT_FLD_GCEBBAPLASTIC,       // 地基承载力(临塑法)(kPa) float
	enum_double_TBL_PMT_FLD_GCDKCR,              // 不排水抗剪强度(kPa) float
	enum_double_TBL_PMT_FLD_SIDEPRESSCOEFFICE,   // 侧压力系数 float
	enum_double_TBL_PMT_FLD_GCDLAK,              // 孔隙水压力(kPa) float
	enum_str_TBL_PMT_FLD_GEOCODE,                // 地质代号 varchar
	enum_str_TBL_PMT_FLD_TCMC,                   // 土层名称 varchar
	enum_str_TBL_PMT_FLD__MEMO,                  // 备注 varchar
	enum_str_TBL_PMT_FLD_SWDDAH,                 // 观测时间 date
	enum_int_TBL_PMT_FLD_GCEFAV,                 // 序号 int
	enum_double_TBL_PMT_FLD_GCECHD,              // 压力(kPa) float
	enum_double_TBL_PMT_FLD_EXPANDVOLUME,        // 扩张体积(cm3) float
	enum_double_TBL_PMT_FLD_WATERLEVELVALUE,     // 量管水位值(cm) float
	enum_double_TBL_PMT_FLD_WATERDROPVALUE,      // 量管水位下降值(cm) float
	enum_str_TBL_PMT_FLD_TEST_EQUIPMODEL,        // 试验设备及型号 varchar
	enum_str_TBL_PMT_FLD_TESTSTARTDATE,          // 试验开始日期 date
	enum_str_TBL_PMT_FLD_TESTENDDATE,            // 试验完成日期 date
	enum_str_TBL_PMT_FLD_TESTORGN,               // 试验单位 varchar
	enum_str_TBL_PMT_FLD_OPERATOR,               // 操作人 varchar
	enum_str_TBL_PMT_FLD_TECHNICIAN,             // 现场技术员 varchar
	enum_str_TBL_PMT_FLD_INPUTER,                // 录入员 varchar
	enum_str_TBL_PMT_FLD_INPUTORGN,              // 录入单位 varchar
	enum_str_TBL_PMT_FLD_INPUTDATE,              // 录入日期 date
	// 载荷试验成果表
	enum_int_TBL_LOADTEST_FLD_LOADTESTID,            // 载荷试验ID int
	enum_str_TBL_LOADTEST_FLD_TESTHORIZON,           // 试验层位 varchar
	enum_double_TBL_LOADTEST_FLD_STARTDEPTH,         // 起深度(m) float
	enum_double_TBL_LOADTEST_FLD_ENDDEPTH,           // 止深度(m) float
	enum_int_TBL_LOADTEST_FLD_PNTID,                 // 点ID int
	enum_str_TBL_LOADTEST_FLD_INSITUTESTNO,          // 试验编号 varchar
	enum_str_TBL_LOADTEST_FLD_TESTCATEGORY,          // 试验类型 varchar
	enum_str_TBL_LOADTEST_FLD_GCEBAM,                // 承压板形状 varchar
	enum_double_TBL_LOADTEST_FLD_GCEBAB,             // 承压板面积 float
	enum_double_TBL_LOADTEST_FLD_BOARDHEADDIAM,      // 板头直径(m) float
	enum_str_TBL_LOADTEST_FLD_SETTLEOBSERVEQUIP,     // 沉降观测仪器 varchar
	enum_str_TBL_LOADTEST_FLD_TESTBEDLITHOLOGY,      // 试验层岩性 varchar
	enum_str_TBL_LOADTEST_FLD_LOADTESTTYPE,          // 载荷试验类型 varchar
	enum_str_TBL_LOADTEST_FLD_LOADEQUIPMODEL,        // 加荷设备及型号 varchar
	enum_str_TBL_LOADTEST_FLD_LOADMETHOD,            // 加荷方式 varchar
	enum_str_TBL_LOADTEST_FLD_STABILITYSTD,          // 稳定标准 varchar
	enum_str_TBL_LOADTEST_FLD_TESTDURATION,          // 试验时长 varchar
	enum_double_TBL_LOADTEST_FLD_TESTLAYERPOISSON,   // 试验层泊松比 float
	enum_double_TBL_LOADTEST_FLD_SWEGAB,             // 地下水位埋深(m) float
	enum_double_TBL_LOADTEST_FLD_GCEBAF,             // 试验点界限应力(MPa) float
	enum_double_TBL_LOADTEST_FLD_GCEBAG,             // 试验点极限应力(MPa) float
	enum_double_TBL_LOADTEST_FLD_GCEBBA,             // 地基承载力(kPa) float
	enum_double_TBL_LOADTEST_FLD_GCDKBA,             // 变形模量(MPa) float
	enum_double_TBL_LOADTEST_FLD_GCDKCR,             // 不排水抗剪强度(kPa) float
	enum_double_TBL_LOADTEST_FLD_GCDLBD,             // 固结系数 float
	enum_double_TBL_LOADTEST_FLD_ORIGCURVEINTERCEPT, // 原始曲线截距 float
	enum_double_TBL_LOADTEST_FLD_ORIGCURVESLOPE,     // 原始曲线斜率 float
	enum_double_TBL_LOADTEST_FLD_CORRECTCURVESLOPE,  // 修正曲线斜率 float
	enum_double_TBL_LOADTEST_FLD_YSKYZ,              // 岩石抗压道（MPa） float
	enum_str_TBL_LOADTEST_FLD_GEOCODE,               // 地质代号 varchar
	enum_str_TBL_LOADTEST_FLD_TCMC,                  // 土层名称 varchar
	enum_str_TBL_LOADTEST_FLD__MEMO,                 // 备注 varchar
	enum_str_TBL_LOADTEST_FLD_GCEABB,                // 样品编号 varchar
	enum_str_TBL_LOADTEST_FLD_SWBCF,                 // 样品类型 varchar
	enum_double_TBL_LOADTEST_FLD_MOISTURECONTENT,    // 天然含水量 float
	enum_double_TBL_LOADTEST_FLD_NATURALSEVERITY,    // 天然重度 float
	enum_double_TBL_LOADTEST_FLD_DHABCU,             // 饱和度 float
	enum_double_TBL_LOADTEST_FLD_NATURALHOLERATIO,   // 天然孔隙比 float
	enum_double_TBL_LOADTEST_FLD_GCDDD,              // 液限 float
	enum_double_TBL_LOADTEST_FLD_GCDDF,              // 液性指数 float
	enum_double_TBL_LOADTEST_FLD_GCDDE,              // 塑性指数 float
	enum_double_TBL_LOADTEST_FLD_GCDLAC,             // 压缩系数 float
	enum_double_TBL_LOADTEST_FLD_QDZS,               // 强度指数 float
	enum_str_TBL_LOADTEST_FLD_SWDDAH,                // 观测时间 date
	enum_double_TBL_LOADTEST_FLD_GCECHD,             // 压力(kPa) float
	enum_double_TBL_LOADTEST_FLD_GCGFAI,             // 沉降量(mm) float
	enum_double_TBL_LOADTEST_FLD_SETTLECHANGE,       // 沉降变化量(mm) float
	enum_double_TBL_LOADTEST_FLD_SETTLECORRECTVALUE, // 沉降校正值(mm) float
	enum_double_TBL_LOADTEST_FLD_SETTLECORRECTNUM,   // 校正后沉降量(mm) float
	enum_str_TBL_LOADTEST_FLD_TEST_EQUIPMODEL,       // 试验设备及型号 varchar
	enum_str_TBL_LOADTEST_FLD_TESTSTARTDATE,         // 试验开始日期 date
	enum_str_TBL_LOADTEST_FLD_TESTENDDATE,           // 试验完成日期 date
	enum_int_TBL_LOADTEST_FLD_TESTNUMBER,            // 试验个数 int
	enum_str_TBL_LOADTEST_FLD_TESTORGN,              // 试验单位 varchar
	enum_str_TBL_LOADTEST_FLD_OPERATOR,              // 操作人 varchar
	enum_str_TBL_LOADTEST_FLD_TECHNICIAN,            // 现场技术员 varchar
	enum_str_TBL_LOADTEST_FLD_INPUTER,               // 录入员 varchar
	enum_str_TBL_LOADTEST_FLD_INPUTORGN,             // 录入单位 varchar
	enum_str_TBL_LOADTEST_FLD_INPUTDATE,             // 录入日期 date
	// 抽水试验成果表
	enum_int_TBL_EGPUMPINGTEST_FLD_PUMPTESTID,        // 抽水试验ID int
	enum_str_TBL_EGPUMPINGTEST_FLD_SWDAE,             // 抽水试验编号 varchar
	enum_str_TBL_EGPUMPINGTEST_FLD_TESTCATEGORY,      // 试验类型 varchar
	enum_str_TBL_EGPUMPINGTEST_FLD_LANDNUM,           // 落程数量 varchar
	enum_int_TBL_EGPUMPINGTEST_FLD_PUMPHOLENUM,       // 抽水孔数量 int
	enum_int_TBL_EGPUMPINGTEST_FLD_OBHOLENUM,         // 观测孔数量 int
	enum_str_TBL_EGPUMPINGTEST_FLD_SWDDAA,            // 试验开始时间 date
	enum_str_TBL_EGPUMPINGTEST_FLD_PUMPENDTIME,       // 抽水结束时间 date
	enum_str_TBL_EGPUMPINGTEST_FLD_SWDDAB,            // 试验结束时间 date
	enum_str_TBL_EGPUMPINGTEST_FLD_STABLEDURATION,    // 水位稳定延续时间(min) varchar
	enum_str_TBL_EGPUMPINGTEST_FLD_PUMPEQUIPMODEL,    // 抽水设备及型号 varchar
	enum_str_TBL_EGPUMPINGTEST_FLD_WATERLEVELOBINST,  // 水位观测仪器 varchar
	enum_str_TBL_EGPUMPINGTEST_FLD_WATERVOLUMEOBINST, // 水量观测仪器 varchar
	enum_str_TBL_EGPUMPINGTEST_FLD_WATERTEMPOBINST,   // 水温观测仪器 varchar
	enum_str_TBL_EGPUMPINGTEST_FLD_TESTHORIZON,       // 试验层位 varchar
	enum_str_TBL_EGPUMPINGTEST_FLD_AQUIFERLITHOLOGY,  // 试验含水层岩性 varchar
	enum_double_TBL_EGPUMPINGTEST_FLD_SWDDBY,         // 最大涌水量(m3/d) float
	enum_double_TBL_EGPUMPINGTEST_FLD_DRAWDOWNMAX,    // 最大降深(m) float
	enum_double_TBL_EGPUMPINGTEST_FLD_MAXINFLURADIUS, // 最大影响半径(m) float
	enum_double_TBL_EGPUMPINGTEST_FLD_CALCULDRAWDOWN, // 推算降深(m) float
	enum_double_TBL_EGPUMPINGTEST_FLD__DIAMETER,      // 统一换算管径(mm) float
	enum_double_TBL_EGPUMPINGTEST_FLD_ESWATERINFLOW,  // 推算涌水量(m3/d) float
	enum_double_TBL_EGPUMPINGTEST_FLD_ESINFLURADIUS,  // 推算影响半径(m) float
	enum_double_TBL_EGPUMPINGTEST_FLD_SWGGAA,         // 平均渗透系数(m/d) float
	enum_double_TBL_EGPUMPINGTEST_FLD_SWGGAO,         // 平均导水系数(m2/d) float
	enum_double_TBL_EGPUMPINGTEST_FLD_SWGGAL,         // 平均储水系数 float
	enum_double_TBL_EGPUMPINGTEST_FLD_SWAEFG,         // 平均给水度 float
	enum_double_TBL_EGPUMPINGTEST_FLD_SWGGBE,         // 平均越流系数 float
	enum_str_TBL_EGPUMPINGTEST_FLD_PLANEPOSMAP,       // 平面位置示意图 varchar
	enum_str_TBL_EGPUMPINGTEST_FLD_PROFILEMAP,        // 剖面示意图 varchar
	enum_str_TBL_EGPUMPINGTEST_FLD_FIELDIMAGE,        // 野外照片(视频) varchar
	enum_str_TBL_EGPUMPINGTEST_FLD_RECORDCARD,        // 记录卡片(记录) varchar
	enum_str_TBL_EGPUMPINGTEST_FLD_TESTORGN,          // 试验单位 varchar
	enum_str_TBL_EGPUMPINGTEST_FLD_JJDAC,             // 记录人 varchar
	enum_str_TBL_EGPUMPINGTEST_FLD__OBSERVER,         // 观测人 varchar
	enum_str_TBL_EGPUMPINGTEST_FLD_INPUTER,           // 录入员 varchar
	enum_str_TBL_EGPUMPINGTEST_FLD_INPUTORGN,         // 录入单位 varchar
	enum_str_TBL_EGPUMPINGTEST_FLD_INPUTDATE,         // 录入日期 date
	enum_str_TBL_EGPUMPINGTEST_FLD_MEMO,              // 备注 varchar
	// 抽水试验段信息表
	enum_int_TBL_HYPUMPEXPSEC_FLD_SECTIONID,            // 试验段ID int
	enum_str_TBL_HYPUMPEXPSEC_FLD_TESTSECTNUM,          // 试验段编号 varchar
	enum_str_TBL_HYPUMPEXPSEC_FLD_SWDAE,                // 试验编号 varchar
	enum_double_TBL_HYPUMPEXPSEC_FLD_FILTERTOPDEPTH,    // 试验段滤管顶深度(m) float
	enum_double_TBL_HYPUMPEXPSEC_FLD_FILTERBOTTOMDEPTH, // 试验段滤管底深度(m) float
	enum_double_TBL_HYPUMPEXPSEC_FLD_FILTERDIAM,        // 试验段滤管外径(mm) float
	enum_double_TBL_HYPUMPEXPSEC_FLD_WATERYTOPDEPTH,    // 试验段含水层顶深度(m) float
	enum_double_TBL_HYPUMPEXPSEC_FLD_WATERYBOTTOMDEPTH, // 试验段含水层底深度(m) float
	enum_double_TBL_HYPUMPEXPSEC_FLD_WATERYTHICKNESS,   // 试验段含水层厚度(m) float
	enum_str_TBL_HYPUMPEXPSEC_FLD_SECTHORIZON,          // 试验段层位 varchar
	enum_str_TBL_HYPUMPEXPSEC_FLD_WATERYLITHOLOGY,      // 试验段含水层岩性 varchar
	enum_int_TBL_HYPUMPEXPSEC_FLD_PNTID,                // 点ID int
	enum_str_TBL_HYPUMPEXPSEC_FLD_PUMPTESTHOLENO,       // 抽水试验孔号 varchar
	enum_str_TBL_HYPUMPEXPSEC_FLD_TESTHOLETYPE,         // 试验孔类型 varchar
	enum_double_TBL_HYPUMPEXPSEC_FLD_PUMPHOLEDIST,      // 与抽水孔距离(m) float
	enum_double_TBL_HYPUMPEXPSEC_FLD_BEFOREPUMPDEPTH,   // 抽水前静水位埋深(m) float
	enum_double_TBL_HYPUMPEXPSEC_FLD_AFTERPUMPDEPTH,    // 抽水后静水位埋深(m) float
	enum_int_TBL_HYPUMPEXPSEC_FLD_SECTNUM,              // 试验段数量 int
	enum_double_TBL_HYPUMPEXPSEC_FLD_AITSTOTALTHICK,    // 试验段含水层总厚度(m) float
	enum_double_TBL_HYPUMPEXPSEC_FLD_SECTIONDIAM,       // 过水断面等效外径(mm) float
	// 抽水实验落程数据表
	enum_int_TBL_HYPUMPEXPFROPOFF_FLD_DROPOFFID,          // 落程ID int
	enum_str_TBL_HYPUMPEXPFROPOFF_FLD_SWDDBG,             // 落程编号 varchar
	enum_str_TBL_HYPUMPEXPFROPOFF_FLD_SWDAE,              // 试验编号 varchar
	enum_str_TBL_HYPUMPEXPFROPOFF_FLD_STARTTIME,          // 落程开始时间 date
	enum_str_TBL_HYPUMPEXPFROPOFF_FLD_ENDTIME,            // 落程结束时间 date
	enum_str_TBL_HYPUMPEXPFROPOFF_FLD_SUSTAINTIME,        // 落程延续时间 varchar
	enum_str_TBL_HYPUMPEXPFROPOFF_FLD_STABLESTARTTIME,    // 水位稳定起始时间 date
	enum_str_TBL_HYPUMPEXPFROPOFF_FLD_STABLETIME,         // 水位稳定时长(分钟) varchar
	enum_double_TBL_HYPUMPEXPFROPOFF_FLD_WATERDROPDEPTH,  // 稳定水位降深(m) float
	enum_double_TBL_HYPUMPEXPFROPOFF_FLD_STABLEINFLOW,    // 稳定涌水量(m3/d) float
	enum_double_TBL_HYPUMPEXPFROPOFF_FLD_SWGGAA,          // 渗透系数 float
	enum_double_TBL_HYPUMPEXPFROPOFF_FLD_INFLURADIUS,     // 影响半径 float
	enum_double_TBL_HYPUMPEXPFROPOFF_FLD_HYDRACOEFFIC,    // 导水系数 float
	enum_double_TBL_HYPUMPEXPFROPOFF_FLD_STORECOEFFIC,    // 储水系数 float
	enum_double_TBL_HYPUMPEXPFROPOFF_FLD_WATERSUPPLY,     // 给水度 float
	enum_double_TBL_HYPUMPEXPFROPOFF_FLD_LEAPFROGCOEFFIC, // 越流系数 float
	enum_int_TBL_HYPUMPEXPFROPOFF_FLD_PNTID,              // 点ID int
	enum_str_TBL_HYPUMPEXPFROPOFF_FLD_PUMPTESTHOLENO,     // 抽水试验孔号 varchar
	enum_str_TBL_HYPUMPEXPFROPOFF_FLD_TESTHOLETYPE,       // 试验孔类型 varchar
	enum_double_TBL_HYPUMPEXPFROPOFF_FLD_PUMPHOLEDIST,    // 与抽水孔距离(m) float
	enum_double_TBL_HYPUMPEXPFROPOFF_FLD_BEFOREPUMPDEPTH, // 抽水前静水位埋深(m) float
	enum_double_TBL_HYPUMPEXPFROPOFF_FLD_AFTERPUMPDEPTH,  // 抽水后静水位埋深(m) float
	enum_int_TBL_HYPUMPEXPFROPOFF_FLD_SECTNUM,            // 试验段数量 int
	enum_double_TBL_HYPUMPEXPFROPOFF_FLD_AITSTOTALTHICK,  // 试验段含水层总厚度(m) float
	enum_double_TBL_HYPUMPEXPFROPOFF_FLD_SECTIONDIAM,     // 过水断面等效外径(mm) float
	// 抽水水位观测记录表
	enum_int_TBL_HYPUMPLEVELOB_FLD_DYWATERLEVELID,     // 动水位ID int
	enum_int_TBL_HYPUMPLEVELOB_FLD_DROPOFFID,          // 落程ID int
	enum_str_TBL_HYPUMPLEVELOB_FLD_SWDDBG,             // 落程编号 varchar
	enum_str_TBL_HYPUMPLEVELOB_FLD_SWDAE,              // 试验编号 varchar
	enum_str_TBL_HYPUMPLEVELOB_FLD_SWDDAH,             // 观测时间 date
	enum_str_TBL_HYPUMPLEVELOB_FLD_PUMPDURATION,       // 抽水延续时间(min) varchar
	enum_double_TBL_HYPUMPLEVELOB_FLD_SWEGAB,          // 水位埋深(m) float
	enum_double_TBL_HYPUMPLEVELOB_FLD_SWDDBH,          // 水位降深(m) float
	enum_double_TBL_HYPUMPLEVELOB_FLD_WATERINFLOWM,    // 涌水量(m3/d) float
	enum_double_TBL_HYPUMPLEVELOB_FLD_WATERINFLOWL,    // 涌水量(L/s) float
	enum_double_TBL_HYPUMPLEVELOB_FLD_SWADET,          // 水温(℃) float
	enum_double_TBL_HYPUMPLEVELOB_FLD_SWADBB,          // 气温(℃) float
	enum_int_TBL_HYPUMPLEVELOB_FLD_IS_STABLE,          // 是否稳定 bool
	enum_str_TBL_HYPUMPLEVELOB_FLD_MEMO,               // 备注 varchar
	enum_int_TBL_HYPUMPLEVELOB_FLD_PNTID,              // 点ID int
	enum_str_TBL_HYPUMPLEVELOB_FLD_PUMPTESTHOLENO,     // 抽水试验孔号 varchar
	enum_str_TBL_HYPUMPLEVELOB_FLD_TESTHOLETYPE,       // 试验孔类型 varchar
	enum_double_TBL_HYPUMPLEVELOB_FLD_PUMPHOLEDIST,    // 与抽水孔距离(m) float
	enum_double_TBL_HYPUMPLEVELOB_FLD_BEFOREPUMPDEPTH, // 抽水前静水位埋深(m) float
	enum_double_TBL_HYPUMPLEVELOB_FLD_AFTERPUMPDEPTH,  // 抽水后静水位埋深(m) float
	enum_int_TBL_HYPUMPLEVELOB_FLD_SECTNUM,            // 试验段数量 int
	enum_double_TBL_HYPUMPLEVELOB_FLD_AITSTOTALTHICK,  // 试验段含水层总厚度(m) float
	enum_double_TBL_HYPUMPLEVELOB_FLD_SECTIONDIAM,     // 过水断面等效外径(mm) float
	// 静水位观测记录表
	enum_int_TBL_HYSTATICWATERLEVEL_FLD_STAWATERLEVELID,    // 静水位ID int
	enum_str_TBL_HYSTATICWATERLEVEL_FLD_SWDAE,              // 试验编号 varchar
	enum_str_TBL_HYSTATICWATERLEVEL_FLD_SWDDAH,             // 观测时间 date
	enum_str_TBL_HYSTATICWATERLEVEL_FLD_SWDDAI,             // 延续时间(min) varchar
	enum_double_TBL_HYSTATICWATERLEVEL_FLD_SWEGAB,          // 水位埋深(m) float
	enum_double_TBL_HYSTATICWATERLEVEL_FLD_SWADET,          // 水温(℃) float
	enum_double_TBL_HYSTATICWATERLEVEL_FLD_SWADBB,          // 气温(℃) float
	enum_int_TBL_HYSTATICWATERLEVEL_FLD_IS_STABLE,          // 是否稳定 bool
	enum_str_TBL_HYSTATICWATERLEVEL_FLD_MEMO,               // 备注 varchar
	enum_int_TBL_HYSTATICWATERLEVEL_FLD_PNTID,              // 点ID int
	enum_str_TBL_HYSTATICWATERLEVEL_FLD_PUMPTESTHOLENO,     // 抽水试验孔号 varchar
	enum_str_TBL_HYSTATICWATERLEVEL_FLD_TESTHOLETYPE,       // 试验孔类型 varchar
	enum_double_TBL_HYSTATICWATERLEVEL_FLD_PUMPHOLEDIST,    // 与抽水孔距离(m) float
	enum_double_TBL_HYSTATICWATERLEVEL_FLD_BEFOREPUMPDEPTH, // 抽水前静水位埋深(m) float
	enum_double_TBL_HYSTATICWATERLEVEL_FLD_AFTERPUMPDEPTH,  // 抽水后静水位埋深(m) float
	enum_int_TBL_HYSTATICWATERLEVEL_FLD_SECTNUM,            // 试验段数量 int
	enum_double_TBL_HYSTATICWATERLEVEL_FLD_AITSTOTALTHICK,  // 试验段含水层总厚度(m) float
	enum_double_TBL_HYSTATICWATERLEVEL_FLD_SECTIONDIAM,     // 过水断面等效外径(mm) float
	// 恢复水位观测记录表
	enum_int_TBL_HYREVIEWATERLEVEL_FLD_REWATERLEVELID,     // 恢复水位ID int
	enum_str_TBL_HYREVIEWATERLEVEL_FLD_SWDAE,              // 试验编号 varchar
	enum_str_TBL_HYREVIEWATERLEVEL_FLD_SWDDBG,             // 落程编号 varchar
	enum_str_TBL_HYREVIEWATERLEVEL_FLD_SWDDAH,             // 观测时间 date
	enum_str_TBL_HYREVIEWATERLEVEL_FLD_RECOVERYDURATION,   // 恢复延续时间(min) varchar
	enum_double_TBL_HYREVIEWATERLEVEL_FLD_SWEGAB,          // 水位埋深(m) float
	enum_double_TBL_HYREVIEWATERLEVEL_FLD_SWDDBH,          // 水位降深(m) float
	enum_double_TBL_HYREVIEWATERLEVEL_FLD_SWADET,          // 水温(℃) float
	enum_double_TBL_HYREVIEWATERLEVEL_FLD_SWADBB,          // 气温(℃) float
	enum_int_TBL_HYREVIEWATERLEVEL_FLD_IS_STABLE,          // 是否稳定 bool
	enum_str_TBL_HYREVIEWATERLEVEL_FLD__MEMO,              // 备注 varchar
	enum_int_TBL_HYREVIEWATERLEVEL_FLD_PNTID,              // 点ID int
	enum_str_TBL_HYREVIEWATERLEVEL_FLD_PUMPTESTHOLENO,     // 抽水试验孔号 varchar
	enum_str_TBL_HYREVIEWATERLEVEL_FLD_TESTHOLETYPE,       // 试验孔类型 varchar
	enum_double_TBL_HYREVIEWATERLEVEL_FLD_PUMPHOLEDIST,    // 与抽水孔距离(m) float
	enum_double_TBL_HYREVIEWATERLEVEL_FLD_BEFOREPUMPDEPTH, // 抽水前静水位埋深(m) float
	enum_double_TBL_HYREVIEWATERLEVEL_FLD_AFTERPUMPDEPTH,  // 抽水后静水位埋深(m) float
	enum_int_TBL_HYREVIEWATERLEVEL_FLD_SECTNUM,            // 试验段数量 int
	enum_double_TBL_HYREVIEWATERLEVEL_FLD_AITSTOTALTHICK,  // 试验段含水层总厚度(m) float
	enum_double_TBL_HYREVIEWATERLEVEL_FLD_SECTIONDIAM,     // 过水断面等效外径(mm) float
	// 注水试验观测记录表
	enum_int_TBL_HYWATERINJECTOB_FLD_WATERINJECTLEVELID,   // 注水水位ID int
	enum_int_TBL_HYWATERINJECTOB_FLD_PRJID,                // 项目ID int
	enum_str_TBL_HYWATERINJECTOB_FLD_PKIAA,                // 项目编号 varchar
	enum_str_TBL_HYWATERINJECTOB_FLD_SWDDAH,               // 观测时间 date
	enum_str_TBL_HYWATERINJECTOB_FLD_SWDDAI,               // 延续时间(分钟) varchar
	enum_double_TBL_HYWATERINJECTOB_FLD_SWEGAB,            // 水位埋深(m) float
	enum_double_TBL_HYWATERINJECTOB_FLD_WATERHEADVALUE,    // 水头值(m) float
	enum_double_TBL_HYWATERINJECTOB_FLD_WATERINJECTVOLUME, // 注水量(L) float
	enum_double_TBL_HYWATERINJECTOB_FLD_INJECTIONFLOW,     // 注入流量(L/min) float
	enum_int_TBL_HYWATERINJECTOB_FLD_IS_STABLE,            // 是否稳定 bool
	enum_str_TBL_HYWATERINJECTOB_FLD_WATERINJECTNO,        // 注水试验编号 varchar
	enum_int_TBL_HYWATERINJECTOB_FLD_PNTID,                // 点ID int
	enum_str_TBL_HYWATERINJECTOB_FLD_TNO,                  // 注水试验孔号 varchar
	enum_str_TBL_HYWATERINJECTOB_FLD_TESTMETHOD,           // 试验方法 varchar
	enum_str_TBL_HYWATERINJECTOB_FLD_WATERVOLUMEOBINST,    // 水量观测仪器 varchar
	enum_str_TBL_HYWATERINJECTOB_FLD_WaterLevelObInst,     // 水位观测仪器 varchar
	enum_str_TBL_HYWATERINJECTOB_FLD_STARTTIME,            // 试验开始时间 date
	enum_str_TBL_HYWATERINJECTOB_FLD_ENDTIME,              // 试验结束时间 date
	enum_str_TBL_HYWATERINJECTOB_FLD_FLOWSTABLETIME,       // 流量稳定时间 date
	enum_double_TBL_HYWATERINJECTOB_FLD_SWDACD,            // 试验段起始深度(m) float
	enum_double_TBL_HYWATERINJECTOB_FLD_SWDACE,            // 试验段终止深度(m) float
	enum_double_TBL_HYWATERINJECTOB_FLD_TESTL,             // 试验段长度(m) float
	enum_double_TBL_HYWATERINJECTOB_FLD_INNERDIAMETER,     // 套管内径(mm) float
	enum_double_TBL_HYWATERINJECTOB_FLD_BURYDEPTH_BEFORE,  // 注水前静水位埋深(m) float
	enum_double_TBL_HYWATERINJECTOB_FLD_BURYDEPTH_AFTER,   // 注水后静水位埋深(m) float
	enum_double_TBL_HYWATERINJECTOB_FLD_SWGGAA,            // 渗透系数(m/d) float
	enum_double_TBL_HYWATERINJECTOB_FLD_HYCONDUCTIVITY,    // 导水系数(m2/d) float
	enum_str_TBL_HYWATERINJECTOB_FLD_PLANEPOSMAP,          // 平面位置示意图 varchar
	enum_str_TBL_HYWATERINJECTOB_FLD_PROFILEMAP,           // 剖面示意图 varchar
	enum_str_TBL_HYWATERINJECTOB_FLD_FIELDIMAGE,           // 野外照片(视频) varchar
	enum_str_TBL_HYWATERINJECTOB_FLD_RECORDCARD,           // 记录卡片(记录) varchar
	enum_str_TBL_HYWATERINJECTOB_FLD_TESTORGN,             // 试验单位 varchar
	enum_str_TBL_HYWATERINJECTOB_FLD_JJDAC,                // 记录人 varchar
	enum_str_TBL_HYWATERINJECTOB_FLD__OBSERVER,            // 观测人 varchar
	enum_str_TBL_HYWATERINJECTOB_FLD_INPUTER,              // 录入员 varchar
	enum_str_TBL_HYWATERINJECTOB_FLD_INPUTORGN,            // 录入单位 varchar
	enum_str_TBL_HYWATERINJECTOB_FLD_INPUTDATE,            // 录入日期 date
	enum_str_TBL_HYWATERINJECTOB_FLD__MEMO,                // 备注 varchar
	// 回灌实验成果表
	enum_int_TBL_HYRECHARGEEXP_FLD_RECHARGEEXPID,      // 回灌试验ID int
	enum_int_TBL_HYRECHARGEEXP_FLD_PNTID,              // 点ID int
	enum_str_TBL_HYRECHARGEEXP_FLD_RECHARGEEXPNO,      // 回灌试验编号 varchar
	enum_int_TBL_HYRECHARGEEXP_FLD_PRJID,              // 项目ID int
	enum_str_TBL_HYRECHARGEEXP_FLD_PKIAA,              // 项目编号 varchar
	enum_str_TBL_HYRECHARGEEXP_FLD_TESTCATEGORY,       // 试验类型 varchar
	enum_int_TBL_HYRECHARGEEXP_FLD_LIFTNUM,            // 升程数量 int
	enum_int_TBL_HYRECHARGEEXP_FLD_REFILLHOLENUM,      // 回灌孔数量 int
	enum_int_TBL_HYRECHARGEEXP_FLD_OBHOLENUM,          // 观测孔数量 int
	enum_str_TBL_HYRECHARGEEXP_FLD_SWDDAA,             // 试验开始时间 date
	enum_str_TBL_HYRECHARGEEXP_FLD_ENDTIME,            // 回灌结束时间 date
	enum_str_TBL_HYRECHARGEEXP_FLD_SWDDAB,             // 试验结束时间 date
	enum_str_TBL_HYRECHARGEEXP_FLD_STABLEDURATION,     // 水位稳定延续时间(min) varchar
	enum_str_TBL_HYRECHARGEEXP_FLD_WATERLEVELOBINST,   // 水位观测仪器 varchar
	enum_str_TBL_HYRECHARGEEXP_FLD_WATERVOLUMEOBINST,  // 水量观测仪器 varchar
	enum_str_TBL_HYRECHARGEEXP_FLD_WATERTEMPOBINST,    // 水温观测仪器 varchar
	enum_str_TBL_HYRECHARGEEXP_FLD_TESTHORIZON,        // 试验层位 varchar
	enum_str_TBL_HYRECHARGEEXP_FLD_TESTBEDLITHOLOGY,   // 试验层岩性 varchar
	enum_double_TBL_HYRECHARGEEXP_FLD_MAXVOLUME,       // 最大回灌量(m3/d) float
	enum_double_TBL_HYRECHARGEEXP_FLD_MARISE,          // 最大水位升幅(m) float
	enum_double_TBL_HYRECHARGEEXP_FLD_MAXINFLURADIUS,  // 最大影响半径(m) float
	enum_double_TBL_HYRECHARGEEXP_FLD_SWGGAA,          // 平均渗透系数(m/d) float
	enum_double_TBL_HYRECHARGEEXP_FLD_SWGGAO,          // 平均导水系数(m2/d) float
	enum_double_TBL_HYRECHARGEEXP_FLD_SWGGAL,          // 平均储水系数 float
	enum_double_TBL_HYRECHARGEEXP_FLD_SWAEFG,          // 平均给水度 float
	enum_double_TBL_HYRECHARGEEXP_FLD_SWGGBE,          // 平均越流系数 float
	enum_double_TBL_HYRECHARGEEXP_FLD_AVGRECHARGERATE, // 平均回灌率 float
	enum_str_TBL_HYRECHARGEEXP_FLD_PLANEPOSMAP,        // 平面位置示意图 varchar
	enum_str_TBL_HYRECHARGEEXP_FLD_PROFILEMAP,         // 剖面示意图 varchar
	enum_str_TBL_HYRECHARGEEXP_FLD_FIELDIMAGE,         // 野外照片(视频) varchar
	enum_str_TBL_HYRECHARGEEXP_FLD_RECORDCARD,         // 记录卡片(记录) varchar
	enum_str_TBL_HYRECHARGEEXP_FLD_TESTORGN,           // 试验单位 varchar
	enum_str_TBL_HYRECHARGEEXP_FLD_JJDAC,              // 记录人 varchar
	enum_str_TBL_HYRECHARGEEXP_FLD_OBSERVER,           // 观测人 varchar
	enum_str_TBL_HYRECHARGEEXP_FLD_INPUTER,            // 录入员 varchar
	enum_str_TBL_HYRECHARGEEXP_FLD_INPUTORGN,          // 录入单位 varchar
	enum_str_TBL_HYRECHARGEEXP_FLD_INPUTDATE,          // 录入日期 date
	enum_str_TBL_HYRECHARGEEXP_FLD_MEMO,               // 备注 varchar
	// 回灌试验段信息表
	enum_int_TBL_HYRECHARGEEXPSECT_FLD_SECTIONID,            // 试验段ID int
	enum_str_TBL_HYRECHARGEEXPSECT_FLD_TESTSECTNUM,          // 试验段编号 varchar
	enum_double_TBL_HYRECHARGEEXPSECT_FLD_FILTERTOPDEPTH,    // 试验段滤管顶深度(m) float
	enum_double_TBL_HYRECHARGEEXPSECT_FLD_FILTERBOTTOMDEPTH, // 试验段滤管底深度(m) float
	enum_double_TBL_HYRECHARGEEXPSECT_FLD_FILTERDIAM,        // 试验段滤管外径(mm) float
	enum_double_TBL_HYRECHARGEEXPSECT_FLD_WATERYTOPDEPTH,    // 试验段含水层顶深度(m) float
	enum_double_TBL_HYRECHARGEEXPSECT_FLD_WATERYBOTTOMDEPTH, // 试验段含水层底深度(m) float
	enum_double_TBL_HYRECHARGEEXPSECT_FLD_WATERYTHICKNESS,   // 试验段含水层厚度(m) float
	enum_str_TBL_HYRECHARGEEXPSECT_FLD_SECTHORIZON,          // 试验段层位 varchar
	enum_str_TBL_HYRECHARGEEXPSECT_FLD_WATERYLITHOLOGY,      // 试验段含水层岩性 varchar
	enum_str_TBL_HYRECHARGEEXPSECT_FLD_RECHARGEEXPNO,        // 回灌试验编号 varchar
	enum_int_TBL_HYRECHARGEEXPSECT_FLD_PNTID,                // 点ID int
	enum_str_TBL_HYRECHARGEEXPSECT_FLD_RECHARGEEXPHOLENO,    // 回灌试验孔号 varchar
	enum_str_TBL_HYRECHARGEEXPSECT_FLD_TESTHOLETYPE,         // 试验孔类型 varchar
	enum_double_TBL_HYRECHARGEEXPSECT_FLD_RECHARGEHOLEDIST,  // 与回灌孔距离(m) float
	enum_double_TBL_HYRECHARGEEXPSECT_FLD_BURYDEPTH_BEFORE,  // 回灌前静水位埋深(m) float
	enum_double_TBL_HYRECHARGEEXPSECT_FLD_BURYDEPTH_AFTER,   // 回灌后静水位埋深(m) float
	enum_int_TBL_HYRECHARGEEXPSECT_FLD_SECTNUM,              // 试验段数量 int
	enum_double_TBL_HYRECHARGEEXPSECT_FLD_TOTALTHICKNESS,    // 试验段含水层总厚度(m) float
	enum_double_TBL_HYRECHARGEEXPSECT_FLD_EODOWPSECTION,     // 过水断面等效外径(mm) float
	// 回灌试验升程数据表
	enum_int_TBL_HYRECHARGEEXPLIFT_FLD_LIFTID,               // 升程ID int
	enum_str_TBL_HYRECHARGEEXPLIFT_FLD_LIFTNO,               // 升程编号 varchar
	enum_str_TBL_HYRECHARGEEXPLIFT_FLD_STARTTIME,            // 升程开始时间 date
	enum_str_TBL_HYRECHARGEEXPLIFT_FLD_ENDTIME,              // 升程结束时间 date
	enum_str_TBL_HYRECHARGEEXPLIFT_FLD_STABLESTARTTIME,      // 水位稳定起始时间 date
	enum_str_TBL_HYRECHARGEEXPLIFT_FLD_STABLETIME,           // 水位稳定时长(分钟) varchar
	enum_double_TBL_HYRECHARGEEXPLIFT_FLD_STAWATERLEVELRISE, // 稳定水位回升(m) float
	enum_double_TBL_HYRECHARGEEXPLIFT_FLD_STARECHARGEVOLUME, // 稳定回灌量(m3/d) float
	enum_double_TBL_HYRECHARGEEXPLIFT_FLD_INFLURADIUS,       // 影响半径 float
	enum_double_TBL_HYRECHARGEEXPLIFT_FLD_SWGGAA,            // 渗透系数 float
	enum_double_TBL_HYRECHARGEEXPLIFT_FLD_HYDRACOEFFIC,      // 导水系数 float
	enum_double_TBL_HYRECHARGEEXPLIFT_FLD_STORECOEFFIC,      // 储水系数 float
	enum_double_TBL_HYRECHARGEEXPLIFT_FLD_WATERSUPPLY,       // 给水度 float
	enum_double_TBL_HYRECHARGEEXPLIFT_FLD_LEAPFROGCOEFFIC,   // 越流系数 float
	enum_str_TBL_HYRECHARGEEXPLIFT_FLD_RECHARGEEXPNO,        // 回灌试验编号 varchar
	enum_int_TBL_HYRECHARGEEXPLIFT_FLD_PNTID,                // 点ID int
	enum_str_TBL_HYRECHARGEEXPLIFT_FLD_RECHARGEEXPHOLENO,    // 回灌试验孔号 varchar
	enum_str_TBL_HYRECHARGEEXPLIFT_FLD_TESTHOLETYPE,         // 试验孔类型 varchar
	enum_double_TBL_HYRECHARGEEXPLIFT_FLD_RECHARGEHOLEDIST,  // 与回灌孔距离(m) float
	enum_double_TBL_HYRECHARGEEXPLIFT_FLD_BURYDEPTH_BEFORE,  // 回灌前静水位埋深(m) float
	enum_double_TBL_HYRECHARGEEXPLIFT_FLD_BURYDEPTH_AFTER,   // 回灌后静水位埋深(m) float
	enum_int_TBL_HYRECHARGEEXPLIFT_FLD_SECTNUM,              // 试验段数量 int
	enum_double_TBL_HYRECHARGEEXPLIFT_FLD_TOTALTHICKNESS,    // 试验段含水层总厚度(m) float
	enum_double_TBL_HYRECHARGEEXPLIFT_FLD_EODOWPSECTION,     // 过水断面等效外径(mm) float
	// 回灌试验观测记录表
	enum_int_TBL_HYRECHARGEEXPOB_FLD_DYWATERLEVELID,      // 回灌动水位ID int
	enum_int_TBL_HYRECHARGEEXPOB_FLD_LIFTID,              // 升程ID int
	enum_str_TBL_HYRECHARGEEXPOB_FLD_LIFTNO,              // 升程编号 varchar
	enum_str_TBL_HYRECHARGEEXPOB_FLD_PKIAA,               // 项目统一编号 varchar
	enum_str_TBL_HYRECHARGEEXPOB_FLD_SWDDAH,              // 观测时间 date
	enum_str_TBL_HYRECHARGEEXPOB_FLD_RECHARGEDURATION,    // 回灌延续时间(min) varchar
	enum_double_TBL_HYRECHARGEEXPOB_FLD_SWEGAB,           // 水位埋深(m) float
	enum_double_TBL_HYRECHARGEEXPOB_FLD_WATERLEVELRISE,   // 水位回升(m) float
	enum_double_TBL_HYRECHARGEEXPOB_FLD_SWIFCBM,          // 回灌量(m3/d) float
	enum_double_TBL_HYRECHARGEEXPOB_FLD_SWIFCBL,          // 回灌量(L/s) float
	enum_double_TBL_HYRECHARGEEXPOB_FLD_SWADET,           // 水温(℃) float
	enum_double_TBL_HYRECHARGEEXPOB_FLD_SWADBB,           // 气温(℃) float
	enum_int_TBL_HYRECHARGEEXPOB_FLD_IS_STABLE,           // 是否稳定 bool
	enum_str_TBL_HYRECHARGEEXPOB_FLD_MEMO,                // 备注 varchar
	enum_str_TBL_HYRECHARGEEXPOB_FLD_RECHARGEEXPNO,       // 回灌试验编号 varchar
	enum_int_TBL_HYRECHARGEEXPOB_FLD_PNTID,               // 点ID int
	enum_str_TBL_HYRECHARGEEXPOB_FLD_RECHARGEEXPHOLENO,   // 回灌试验孔号 varchar
	enum_str_TBL_HYRECHARGEEXPOB_FLD_TESTHOLETYPE,        // 试验孔类型 varchar
	enum_double_TBL_HYRECHARGEEXPOB_FLD_RECHARGEHOLEDIST, // 与回灌孔距离(m) float
	enum_double_TBL_HYRECHARGEEXPOB_FLD_BURYDEPTH_BEFORE, // 回灌前静水位埋深(m) float
	enum_double_TBL_HYRECHARGEEXPOB_FLD_BURYDEPTH_AFTER,  // 回灌后静水位埋深(m) float
	enum_int_TBL_HYRECHARGEEXPOB_FLD_SECTNUM,             // 试验段数量 int
	enum_double_TBL_HYRECHARGEEXPOB_FLD_TOTALTHICKNESS,   // 试验段含水层总厚度(m) float
	enum_double_TBL_HYRECHARGEEXPOB_FLD_EODOWPSECTION,    // 过水断面等效外径(mm) float
	// 热响应实验成果表
	enum_int_TBL_HYTHERMALRES_FLD_THERMALRESID,   // 热响应试验ID int
	enum_int_TBL_HYTHERMALRES_FLD_PNTID,          // 点ID int
	enum_str_TBL_HYTHERMALRES_FLD_GCEBAN,         // 试验编号 varchar
	enum_str_TBL_HYTHERMALRES_FLD_TESTHORIZON,    // 试验层位 varchar
	enum_int_TBL_HYTHERMALRES_FLD_OBHOLENUM,      // 观测孔数量 int
	enum_double_TBL_HYTHERMALRES_FLD_SWADER,      // 最低温度 float
	enum_double_TBL_HYTHERMALRES_FLD_SWADEQ,      // 最高温度 float
	enum_double_TBL_HYTHERMALRES_FLD_SWGGAU,      // 试验影响半径 float
	enum_double_TBL_HYTHERMALRES_FLD_GCDGAF,      // 平均导热系数 float
	enum_double_TBL_HYTHERMALRES_FLD_GCEBAS,      // 热扩散率 float
	enum_double_TBL_HYTHERMALRES_FLD_GCDGAE,      // 比热容 float
	enum_str_TBL_HYTHERMALRES_FLD_TESTEQUIPMODEL, // 试验仪器及型号 varchar
	enum_str_TBL_HYTHERMALRES_FLD_SWDDAA,         // 试验开始日期 date
	enum_str_TBL_HYTHERMALRES_FLD_SWDDAB,         // 试验结束日期 date
	enum_str_TBL_HYTHERMALRES_FLD_PLANEPOSMAP,    // 平面位置示意图 varchar
	enum_str_TBL_HYTHERMALRES_FLD_PROFILEMAP,     // 剖面示意图 varchar
	enum_str_TBL_HYTHERMALRES_FLD_FIELDIMAGE,     // 野外照片(视频) varchar
	enum_str_TBL_HYTHERMALRES_FLD_RECORDCARD,     // 记录卡片(记录) varchar
	enum_str_TBL_HYTHERMALRES_FLD_TESTORGN,       // 试验单位 varchar
	enum_str_TBL_HYTHERMALRES_FLD_TECHNICIAN,     // 现场技术员 varchar
	enum_str_TBL_HYTHERMALRES_FLD_INPUTER,        // 录入员 varchar
	enum_str_TBL_HYTHERMALRES_FLD_INPUTORGN,      // 录入单位 varchar
	enum_str_TBL_HYTHERMALRES_FLD_INPUTDATE,      // 录入日期 date
	enum_str_TBL_HYTHERMALRES_FLD_MEMO,           // 备注 varchar
	// 热响应试验地温观测记录表
	enum_int_TBL_HYRHERNAKRES_OB_FLD_GEOTEMPOBID, // 地温观测记录ID int
	enum_str_TBL_HYRHERNAKRES_OB_FLD_SWDDAH,      // 观测时间 date
	enum_double_TBL_HYRHERNAKRES_OB_FLD_GCKUGF,   // 深度(m) float
	enum_double_TBL_HYRHERNAKRES_OB_FLD_SWADET,   // 温度 float
	enum_str_TBL_HYRHERNAKRES_OB_FLD_OBSERVER,    // 观测人 varchar
	enum_str_TBL_HYRHERNAKRES_OB_FLD_JJDAC,       // 记录人 varchar
	enum_str_TBL_HYRHERNAKRES_OB_FLD_TESTHOLENO,  // 试验孔号 varchar
	enum_str_TBL_HYRHERNAKRES_OB_FLD_GCEBAN,      // 试验编号 varchar
	enum_int_TBL_HYRHERNAKRES_OB_FLD_PNTID,       // 点ID int
	enum_double_TBL_HYRHERNAKRES_OB_FLD_TKACC,    // 孔深 float
	enum_double_TBL_HYRHERNAKRES_OB_FLD_SWDAAX,   // 与主孔距离 float
	// 渗水试验成果表
	enum_int_TBL_HYWATERSEEPAGEEXP_FLD_WATERSEEPAGEEXPID,  // 渗水试验ID int
	enum_str_TBL_HYWATERSEEPAGEEXP_FLD_WATERSEEPAGEEXPNO,  // 渗水试验编号 varchar
	enum_int_TBL_HYWATERSEEPAGEEXP_FLD_PNTID,              // 点ID int
	enum_str_TBL_HYWATERSEEPAGEEXP_FLD_WATERSEEPAGEHOLENO, // 渗水试验孔号 varchar
	enum_str_TBL_HYWATERSEEPAGEEXP_FLD_TESTMETHOD,         // 试验方法 varchar
	enum_str_TBL_HYWATERSEEPAGEEXP_FLD_TESTHORIZON,        // 试验层位 varchar
	enum_str_TBL_HYWATERSEEPAGEEXP_FLD_TESTBEDLITHOLOGY,   // 试验层岩性 varchar
	enum_double_TBL_HYWATERSEEPAGEEXP_FLD_GCEBAI,          // 试坑直径 float
	enum_double_TBL_HYWATERSEEPAGEEXP_FLD_SWDAAU,          // 试坑底面积 float
	enum_double_TBL_HYWATERSEEPAGEEXP_FLD_GCEBAJ,          // 试坑深度 float
	enum_double_TBL_HYWATERSEEPAGEEXP_FLD_GCEBA,           // 内环直径 float
	enum_double_TBL_HYWATERSEEPAGEEXP_FLD_GCEBAK,          // 外环直径 float
	enum_double_TBL_HYWATERSEEPAGEEXP_FLD_GCGDJ,           // 渗透深度 float
	enum_double_TBL_HYWATERSEEPAGEEXP_FLD_SWGGBR,          // 水层厚度 float
	enum_double_TBL_HYWATERSEEPAGEEXP_FLD_SWDAAV,          // 毛细高度 float
	enum_int_TBL_HYWATERSEEPAGEEXP_FLD_SWDDAI,             // 累计延续时间 int
	enum_double_TBL_HYWATERSEEPAGEEXP_FLD_SWDAAW,          // 稳定流量 float
	enum_double_TBL_HYWATERSEEPAGEEXP_FLD_SWGGAA,          // 渗透系数 float
	enum_str_TBL_HYWATERSEEPAGEEXP_FLD_LITHOLOGYDESC,      // 包气带岩性描述 varchar
	enum_str_TBL_HYWATERSEEPAGEEXP_FLD_SWDDAA,             // 试验开始时间 date
	enum_str_TBL_HYWATERSEEPAGEEXP_FLD_SWDDAB,             // 试验结束时间 date
	enum_str_TBL_HYWATERSEEPAGEEXP_FLD_PLANEPOSMAP,        // 平面位置示意图 varchar
	enum_str_TBL_HYWATERSEEPAGEEXP_FLD_PROFILEMAP,         // 剖面示意图 varchar
	enum_str_TBL_HYWATERSEEPAGEEXP_FLD_FIELDIMAGE,         // 野外照片(视频) varchar
	enum_str_TBL_HYWATERSEEPAGEEXP_FLD_RECORDCARD,         // 记录卡片(记录) varchar
	enum_str_TBL_HYWATERSEEPAGEEXP_FLD_TESTORGN,           // 试验单位 varchar
	enum_str_TBL_HYWATERSEEPAGEEXP_FLD_JJDAC,              // 记录人 varchar
	enum_str_TBL_HYWATERSEEPAGEEXP_FLD__OBSERVER,          // 观测人 varchar
	enum_str_TBL_HYWATERSEEPAGEEXP_FLD_INPUTER,            // 录入员 varchar
	enum_str_TBL_HYWATERSEEPAGEEXP_FLD_INPUTORGN,          // 录入单位 varchar
	enum_str_TBL_HYWATERSEEPAGEEXP_FLD_INPUTDATE,          // 录入日期 date
	enum_str_TBL_HYWATERSEEPAGEEXP_FLD_TKDAE,              // 天气 varchar
	enum_str_TBL_HYWATERSEEPAGEEXP_FLD_MEMO,               // 备注 varchar
	// 渗水试验观测记录表
	enum_int_TBL_HYWATERSEEPAGEEXPOB_FLD_WATERSEEPAGEEXPOBID, // 渗水观测记录ID int
	enum_int_TBL_HYWATERSEEPAGEEXPOB_FLD_PNTID,               // 点ID int
	enum_str_TBL_HYWATERSEEPAGEEXPOB_FLD_WATERSEEPAGEEXPNO,   // 渗水试验编号 varchar
	enum_str_TBL_HYWATERSEEPAGEEXPOB_FLD_SWDDAH,              // 观测时间 date
	enum_double_TBL_HYWATERSEEPAGEEXPOB_FLD_SWDDAI,           // 延续时间 float
	enum_double_TBL_HYWATERSEEPAGEEXPOB_FLD_SWGCAK,           // 渗水体积 float
	enum_double_TBL_HYWATERSEEPAGEEXPOB_FLD_SWGCAA,           // 渗透流量 float
	enum_int_TBL_HYWATERSEEPAGEEXPOB_FLD_IS_STABLE,           // 是否稳定 bool
	enum_str_TBL_HYWATERSEEPAGEEXPOB_FLD_MEMO,                // 备注 varchar
	// 混合样品对照表
	enum_int_TBL_SCMIXSAMPCOMPARE_FLD_MIXSAMPLEID,     // 混合样品id int
	enum_str_TBL_SCMIXSAMPCOMPARE_FLD_MIXSAMPLENO,     // 混合样品编号 varchar
	enum_int_TBL_SCMIXSAMPCOMPARE_FLD_ORISAMPLEID,     // 原始样品ID int
	enum_str_TBL_SCMIXSAMPCOMPARE_FLD_ORISAMPLENO,     // 原始样品编号 varchar
	enum_str_TBL_SCMIXSAMPCOMPARE_FLD_PKIAA,           // 项目统一编号 varchar
	enum_str_TBL_SCMIXSAMPCOMPARE_FLD_GCEABB,          // 样品编号 varchar
	enum_int_TBL_SCMIXSAMPCOMPARE_FLD_PNTID,           // 点ID int
	enum_str_TBL_SCMIXSAMPCOMPARE_FLD_SWBCF,           // 样品类型 varchar
	enum_str_TBL_SCMIXSAMPCOMPARE_FLD_ISMIXSAMPLE,     // 混合样 varchar
	enum_str_TBL_SCMIXSAMPCOMPARE_FLD_PNTTYPE,         // 点类型 varchar
	enum_str_TBL_SCMIXSAMPCOMPARE_FLD_SECONDCODE,      // 样品二次编码 varchar
	enum_double_TBL_SCMIXSAMPCOMPARE_FLD_SAMPLEVOLUME, // 样品体积 float
	enum_str_TBL_SCMIXSAMPCOMPARE_FLD_GCEABM,          // 野外命名 varchar
	enum_double_TBL_SCMIXSAMPCOMPARE_FLD_GCEAAL,       // 样品重量(kg) float
	enum_str_TBL_SCMIXSAMPCOMPARE_FLD_SAMPLELENGTH,    // 样品长度(cm) varchar
	enum_str_TBL_SCMIXSAMPCOMPARE_FLD_PRETREATMETHOD,  // 预处理方法 varchar
	enum_str_TBL_SCMIXSAMPCOMPARE_FLD_TESTCONTENT,     // 测试内容 varchar
	enum_str_TBL_SCMIXSAMPCOMPARE_FLD_PLANEPOSMAP,     // 平面位置示意图 varchar
	enum_str_TBL_SCMIXSAMPCOMPARE_FLD_PROFILEMAP,      // 剖面示意图 varchar
	enum_str_TBL_SCMIXSAMPCOMPARE_FLD_FIELDIMAGE,      // 野外照片(视频) varchar
	enum_str_TBL_SCMIXSAMPCOMPARE_FLD_RECORDCARD,      // 记录卡片(记录) varchar
	enum_str_TBL_SCMIXSAMPCOMPARE_FLD_SAMPLEORGN,      // 采样单位 varchar
	enum_str_TBL_SCMIXSAMPCOMPARE_FLD_SWFOMW,          // 采样人 varchar
	enum_str_TBL_SCMIXSAMPCOMPARE_FLD_GCEABJ,          // 采样日期 date
	enum_str_TBL_SCMIXSAMPCOMPARE_FLD_INPUTER,         // 录入员 varchar
	enum_str_TBL_SCMIXSAMPCOMPARE_FLD_INPUTORGN,       // 录入单位 varchar
	enum_str_TBL_SCMIXSAMPCOMPARE_FLD_INPUTDATE,       // 录入日期 date
	// 岩石样品基本情况表
	enum_int_TBL_SCROCKSAMPLE_FLD_ROCKID,          // 岩样ID int
	enum_str_TBL_SCROCKSAMPLE_FLD_SAMPLEBAGNO,     // 样品袋号 varchar
	enum_str_TBL_SCROCKSAMPLE_FLD_SAMPLECOLOR,     // 样品颜色 varchar
	enum_str_TBL_SCROCKSAMPLE_FLD_GCKLT,           // 岩性描述 varchar
	enum_str_TBL_SCROCKSAMPLE_FLD_MINERALCONTENT,  // 矿物成分及含量 varchar
	enum_str_TBL_SCROCKSAMPLE_FLD_ROCKFORMAT,      // 岩层倾向 varchar
	enum_str_TBL_SCROCKSAMPLE_FLD_STRATUMDIP,      // 岩层倾角 varchar
	enum_str_TBL_SCROCKSAMPLE_FLD_JOINTFISSURE,    // 节理裂隙 varchar
	enum_str_TBL_SCROCKSAMPLE_FLD_MINERALIZATTYPE, // 矿化类型 varchar
	enum_str_TBL_SCROCKSAMPLE_FLD_ALTERATTYPE,     // 蚀变类型 varchar
	enum_str_TBL_SCROCKSAMPLE_FLD_KARSTTYPE,       // 岩溶类型 varchar
	enum_str_TBL_SCROCKSAMPLE_FLD_MEMO,            // 备注 varchar
	enum_str_TBL_SCROCKSAMPLE_FLD_GCEABB,          // 样品编号 varchar
	enum_int_TBL_SCROCKSAMPLE_FLD_PNTID,           // 点ID int
	enum_str_TBL_SCROCKSAMPLE_FLD_SWBCF,           // 样品类型 varchar
	enum_str_TBL_SCROCKSAMPLE_FLD_ISMIXSAMPLE,     // 混合样 varchar
	enum_str_TBL_SCROCKSAMPLE_FLD_PNTTYPE,         // 点类型 varchar
	enum_str_TBL_SCROCKSAMPLE_FLD_SECONDCODE,      // 样品二次编码 varchar
	enum_double_TBL_SCROCKSAMPLE_FLD_SAMPLEVOLUME, // 样品体积 float
	enum_str_TBL_SCROCKSAMPLE_FLD_GCEABM,          // 野外命名 varchar
	enum_double_TBL_SCROCKSAMPLE_FLD_GCEAAL,       // 样品重量(kg) float
	enum_str_TBL_SCROCKSAMPLE_FLD_SAMPLELENGTH,    // 样品长度(cm) varchar
	enum_str_TBL_SCROCKSAMPLE_FLD_PRETREATMETHOD,  // 预处理方法 varchar
	enum_str_TBL_SCROCKSAMPLE_FLD_TESTCONTENT,     // 测试内容 varchar
	enum_str_TBL_SCROCKSAMPLE_FLD_PLANEPOSMAP,     // 平面位置示意图 varchar
	enum_str_TBL_SCROCKSAMPLE_FLD_PROFILEMAP,      // 剖面示意图 varchar
	enum_str_TBL_SCROCKSAMPLE_FLD_FIELDIMAGE,      // 野外照片(视频) varchar
	enum_str_TBL_SCROCKSAMPLE_FLD_RECORDCARD,      // 记录卡片(记录) varchar
	enum_str_TBL_SCROCKSAMPLE_FLD_SAMPLEORGN,      // 采样单位 varchar
	enum_str_TBL_SCROCKSAMPLE_FLD_SWFOMW,          // 采样人 varchar
	enum_str_TBL_SCROCKSAMPLE_FLD_GCEABJ,          // 采样日期 date
	enum_str_TBL_SCROCKSAMPLE_FLD_INPUTER,         // 录入员 varchar
	enum_str_TBL_SCROCKSAMPLE_FLD_INPUTORGN,       // 录入单位 varchar
	enum_str_TBL_SCROCKSAMPLE_FLD_INPUTDATE,       // 录入日期 date
	// 土壤样品基本情况表
	enum_int_TBL_SCSOILSAMPLE_FLD_SOILID,               // 土壤样ID int
	enum_str_TBL_SCSOILSAMPLE_FLD_SAMPLEBAGNO,          // 样品袋号 varchar
	enum_str_TBL_SCSOILSAMPLE_FLD_COMBINEDSAMPID,       // 组合样数 varchar
	enum_str_TBL_SCSOILSAMPLE_FLD_GCKUPE,               // 成因类型 varchar
	enum_str_TBL_SCSOILSAMPLE_FLD_SAMPLECOLOR,          // 样品颜色 varchar
	enum_str_TBL_SCSOILSAMPLE_FLD_GCKLT,                // 岩性描述 varchar
	enum_double_TBL_SCSOILSAMPLE_FLD_COARSESANDCONTENT, // 粗砂含量 float
	enum_double_TBL_SCSOILSAMPLE_FLD_FINESANDCONTENT,   // 细砂含量 float
	enum_double_TBL_SCSOILSAMPLE_FLD_CLAYCONTENT,       // 粘土含量 float
	enum_str_TBL_SCSOILSAMPLE_FLD__POLLUTION,           // 污染 varchar
	enum_str_TBL_SCSOILSAMPLE_FLD__EROSION,             // 侵蚀 varchar
	enum_str_TBL_SCSOILSAMPLE_FLD__SALTED,              // 盐渍 varchar
	enum_str_TBL_SCSOILSAMPLE_FLD__CROP,                // 农作物 varchar
	enum_str_TBL_SCSOILSAMPLE_FLD__CULTURE,             // 养殖物 varchar
	enum_str_TBL_SCSOILSAMPLE_FLD_FAMOUSPRODUCT,        // 名优特产品 varchar
	enum_str_TBL_SCSOILSAMPLE_FLD_SOILUSING,            // 土地利用 varchar
	enum_str_TBL_SCSOILSAMPLE_FLD_MARKPOS,              // 标记位置 varchar
	enum_str_TBL_SCSOILSAMPLE_FLD_SWFGAA,               // 采样层位 varchar
	enum_str_TBL_SCSOILSAMPLE_FLD_MEMO,                 // 备注 varchar
	enum_str_TBL_SCSOILSAMPLE_FLD_GCEABB,               // 样品编号 varchar
	enum_int_TBL_SCSOILSAMPLE_FLD_PNTID,                // 点ID int
	enum_str_TBL_SCSOILSAMPLE_FLD_SWBCF,                // 样品类型 varchar
	enum_str_TBL_SCSOILSAMPLE_FLD_ISMIXSAMPLE,          // 混合样 varchar
	enum_str_TBL_SCSOILSAMPLE_FLD_PNTTYPE,              // 点类型 varchar
	enum_str_TBL_SCSOILSAMPLE_FLD_SECONDCODE,           // 样品二次编码 varchar
	enum_double_TBL_SCSOILSAMPLE_FLD_SAMPLEVOLUME,      // 样品体积 float
	enum_str_TBL_SCSOILSAMPLE_FLD_GCEABM,               // 野外命名 varchar
	enum_double_TBL_SCSOILSAMPLE_FLD_GCEAAL,            // 样品重量(kg) float
	enum_str_TBL_SCSOILSAMPLE_FLD_SAMPLELENGTH,         // 样品长度(cm) varchar
	enum_str_TBL_SCSOILSAMPLE_FLD_PRETREATMETHOD,       // 预处理方法 varchar
	enum_str_TBL_SCSOILSAMPLE_FLD_TESTCONTENT,          // 测试内容 varchar
	enum_str_TBL_SCSOILSAMPLE_FLD_PLANEPOSMAP,          // 平面位置示意图 varchar
	enum_str_TBL_SCSOILSAMPLE_FLD_PROFILEMAP,           // 剖面示意图 varchar
	enum_str_TBL_SCSOILSAMPLE_FLD_FIELDIMAGE,           // 野外照片(视频) varchar
	enum_str_TBL_SCSOILSAMPLE_FLD_RECORDCARD,           // 记录卡片(记录) varchar
	enum_str_TBL_SCSOILSAMPLE_FLD_SAMPLEORGN,           // 采样单位 varchar
	enum_str_TBL_SCSOILSAMPLE_FLD_SWFOMW,               // 采样人 varchar
	enum_str_TBL_SCSOILSAMPLE_FLD_GCEABJ,               // 采样日期 date
	enum_str_TBL_SCSOILSAMPLE_FLD_INPUTER,              // 录入员 varchar
	enum_str_TBL_SCSOILSAMPLE_FLD_INPUTORGN,            // 录入单位 varchar
	enum_str_TBL_SCSOILSAMPLE_FLD_INPUTDATE,            // 录入日期 date
	// 水体沉积物样品基本情况表
	enum_int_TBL_SCWATERSEDIMENT_FLD_WATERSEDIMENTID,      // 沉积物样ID int
	enum_str_TBL_SCWATERSEDIMENT_FLD_SAMPLEBAGNO,          // 样品袋号 varchar
	enum_str_TBL_SCWATERSEDIMENT_FLD_WATERNAME,            // 水体名称 varchar
	enum_str_TBL_SCWATERSEDIMENT_FLD_SAMPLESITE,           // 采样部位 varchar
	enum_double_TBL_SCWATERSEDIMENT_FLD_SWNCAH,            // 水深(m) float
	enum_str_TBL_SCWATERSEDIMENT_FLD_GCKUPE,               // 成因类型 varchar
	enum_str_TBL_SCWATERSEDIMENT_FLD_SAMPLECOLOR,          // 样品颜色 varchar
	enum_str_TBL_SCWATERSEDIMENT_FLD_GCKLT,                // 岩性描述 varchar
	enum_double_TBL_SCWATERSEDIMENT_FLD_COARSESANDCONTENT, // 粗砂含量(%) float
	enum_double_TBL_SCWATERSEDIMENT_FLD_FINESANDCONTENT,   // 细砂含量(%) float
	enum_double_TBL_SCWATERSEDIMENT_FLD_CLAYCONTENT,       // 粘土含量(%) float
	enum_double_TBL_SCWATERSEDIMENT_FLD_ORGANICCONTENT,    // 有机物含量(%) float
	enum_str_TBL_SCWATERSEDIMENT_FLD_BIOREMAIN,            // 生物残骸 varchar
	enum_str_TBL_SCWATERSEDIMENT_FLD_POLLUTE,              // 污染情况 varchar
	enum_str_TBL_SCWATERSEDIMENT_FLD_MEMO,                 // 备注 varchar
	enum_str_TBL_SCWATERSEDIMENT_FLD_GCEABB,               // 样品编号 varchar
	enum_int_TBL_SCWATERSEDIMENT_FLD_PNTID,                // 点ID int
	enum_str_TBL_SCWATERSEDIMENT_FLD_SWBCF,                // 样品类型 varchar
	enum_str_TBL_SCWATERSEDIMENT_FLD_ISMIXSAMPLE,          // 混合样 varchar
	enum_str_TBL_SCWATERSEDIMENT_FLD_PNTTYPE,              // 点类型 varchar
	enum_str_TBL_SCWATERSEDIMENT_FLD_SECONDCODE,           // 样品二次编码 varchar
	enum_double_TBL_SCWATERSEDIMENT_FLD_SAMPLEVOLUME,      // 样品体积 float
	enum_str_TBL_SCWATERSEDIMENT_FLD_GCEABM,               // 野外命名 varchar
	enum_double_TBL_SCWATERSEDIMENT_FLD_GCEAAL,            // 样品重量(kg) float
	enum_str_TBL_SCWATERSEDIMENT_FLD_SAMPLELENGTH,         // 样品长度(cm) varchar
	enum_str_TBL_SCWATERSEDIMENT_FLD_PRETREATMETHOD,       // 预处理方法 varchar
	enum_str_TBL_SCWATERSEDIMENT_FLD_TESTCONTENT,          // 测试内容 varchar
	enum_str_TBL_SCWATERSEDIMENT_FLD_PLANEPOSMAP,          // 平面位置示意图 varchar
	enum_str_TBL_SCWATERSEDIMENT_FLD_PROFILEMAP,           // 剖面示意图 varchar
	enum_str_TBL_SCWATERSEDIMENT_FLD_FIELDIMAGE,           // 野外照片(视频) varchar
	enum_str_TBL_SCWATERSEDIMENT_FLD_RECORDCARD,           // 记录卡片(记录) varchar
	enum_str_TBL_SCWATERSEDIMENT_FLD_SAMPLEORGN,           // 采样单位 varchar
	enum_str_TBL_SCWATERSEDIMENT_FLD_SWFOMW,               // 采样人 varchar
	enum_str_TBL_SCWATERSEDIMENT_FLD_GCEABJ,               // 采样日期 date
	enum_str_TBL_SCWATERSEDIMENT_FLD_INPUTER,              // 录入员 varchar
	enum_str_TBL_SCWATERSEDIMENT_FLD_INPUTORGN,            // 录入单位 varchar
	enum_str_TBL_SCWATERSEDIMENT_FLD_INPUTDATE,            // 录入日期 date
	// 沉积物柱状样品分层描述表
	enum_int_TBL_SCSEDIMENTCOLUMN_FLD_COLUMNID,          // 柱状样分层ID int
	enum_str_TBL_SCSEDIMENTCOLUMN_FLD_FIELDLAYERNUM,     // 野外分层号 varchar
	enum_double_TBL_SCSEDIMENTCOLUMN_FLD_LAYERDEPTH,     // 分层深度(m) float
	enum_double_TBL_SCSEDIMENTCOLUMN_FLD_LAYERTHICKNESS, // 层厚(m) float
	enum_str_TBL_SCSEDIMENTCOLUMN_FLD_GCKLQ,             // 岩性名称 varchar
	enum_str_TBL_SCSEDIMENTCOLUMN_FLD_LAYERDESC,         // 分层描述 varchar
	enum_str_TBL_SCSEDIMENTCOLUMN_FLD_GCEABB,            // 样品编号 varchar
	enum_int_TBL_SCSEDIMENTCOLUMN_FLD_PNTID,             // 点ID int
	enum_str_TBL_SCSEDIMENTCOLUMN_FLD_SWBCF,             // 样品类型 varchar
	enum_str_TBL_SCSEDIMENTCOLUMN_FLD_ISMIXSAMPLE,       // 混合样 varchar
	enum_str_TBL_SCSEDIMENTCOLUMN_FLD_PNTTYPE,           // 点类型 varchar
	enum_str_TBL_SCSEDIMENTCOLUMN_FLD_SECONDCODE,        // 样品二次编码 varchar
	enum_double_TBL_SCSEDIMENTCOLUMN_FLD_SAMPLEVOLUME,   // 样品体积 float
	enum_str_TBL_SCSEDIMENTCOLUMN_FLD_GCEABM,            // 野外命名 varchar
	enum_double_TBL_SCSEDIMENTCOLUMN_FLD_GCEAAL,         // 样品重量(kg) float
	enum_str_TBL_SCSEDIMENTCOLUMN_FLD_SAMPLELENGTH,      // 样品长度(cm) varchar
	enum_str_TBL_SCSEDIMENTCOLUMN_FLD_PRETREATMETHOD,    // 预处理方法 varchar
	enum_str_TBL_SCSEDIMENTCOLUMN_FLD_TESTCONTENT,       // 测试内容 varchar
	enum_str_TBL_SCSEDIMENTCOLUMN_FLD_PLANEPOSMAP,       // 平面位置示意图 varchar
	enum_str_TBL_SCSEDIMENTCOLUMN_FLD_PROFILEMAP,        // 剖面示意图 varchar
	enum_str_TBL_SCSEDIMENTCOLUMN_FLD_FIELDIMAGE,        // 野外照片(视频) varchar
	enum_str_TBL_SCSEDIMENTCOLUMN_FLD_RECORDCARD,        // 记录卡片(记录) varchar
	enum_str_TBL_SCSEDIMENTCOLUMN_FLD_SAMPLEORGN,        // 采样单位 varchar
	enum_str_TBL_SCSEDIMENTCOLUMN_FLD_SWFOMW,            // 采样人 varchar
	enum_str_TBL_SCSEDIMENTCOLUMN_FLD_GCEABJ,            // 采样日期 date
	enum_str_TBL_SCSEDIMENTCOLUMN_FLD_INPUTER,           // 录入员 varchar
	enum_str_TBL_SCSEDIMENTCOLUMN_FLD_INPUTORGN,         // 录入单位 varchar
	enum_str_TBL_SCSEDIMENTCOLUMN_FLD_INPUTDATE,         // 录入日期 date
	// 大气沉降样品基本情况表
	enum_int_TBL_SCATMOSSAMPLE_FLD_ATMODEPOSITID,   // 大气沉降样ID int
	enum_str_TBL_SCATMOSSAMPLE_FLD_SAMPLEBAGNO,     // 样品袋号(缸号) varchar
	enum_str_TBL_SCATMOSSAMPLE_FLD_SAMPLECOLOR,     // 样品颜色 varchar
	enum_str_TBL_SCATMOSSAMPLE_FLD_DUSTFALLTYPE,    // 降尘类型 varchar
	enum_str_TBL_SCATMOSSAMPLE_FLD__PRECIPITAT,     // 降水情况 varchar
	enum_double_TBL_SCATMOSSAMPLE_FLD__DEPTH,       // 离地高度(m) float
	enum_str_TBL_SCATMOSSAMPLE_FLD__SURROUND,       // 周围环境 varchar
	enum_str_TBL_SCATMOSSAMPLE_FLD__MEMO,           // 备注 varchar
	enum_str_TBL_SCATMOSSAMPLE_FLD_GCEABB,          // 样品编号 varchar
	enum_int_TBL_SCATMOSSAMPLE_FLD_PNTID,           // 点ID int
	enum_str_TBL_SCATMOSSAMPLE_FLD_SWBCF,           // 样品类型 varchar
	enum_str_TBL_SCATMOSSAMPLE_FLD_ISMIXSAMPLE,     // 混合样 varchar
	enum_str_TBL_SCATMOSSAMPLE_FLD_PNTTYPE,         // 点类型 varchar
	enum_str_TBL_SCATMOSSAMPLE_FLD_SECONDCODE,      // 样品二次编码 varchar
	enum_double_TBL_SCATMOSSAMPLE_FLD_SAMPLEVOLUME, // 样品体积 float
	enum_str_TBL_SCATMOSSAMPLE_FLD_GCEABM,          // 野外命名 varchar
	enum_double_TBL_SCATMOSSAMPLE_FLD_GCEAAL,       // 样品重量(kg) float
	enum_str_TBL_SCATMOSSAMPLE_FLD_SAMPLELENGTH,    // 样品长度(cm) varchar
	enum_str_TBL_SCATMOSSAMPLE_FLD_PRETREATMETHOD,  // 预处理方法 varchar
	enum_str_TBL_SCATMOSSAMPLE_FLD_TESTCONTENT,     // 测试内容 varchar
	enum_str_TBL_SCATMOSSAMPLE_FLD_PLANEPOSMAP,     // 平面位置示意图 varchar
	enum_str_TBL_SCATMOSSAMPLE_FLD_PROFILEMAP,      // 剖面示意图 varchar
	enum_str_TBL_SCATMOSSAMPLE_FLD_FIELDIMAGE,      // 野外照片(视频) varchar
	enum_str_TBL_SCATMOSSAMPLE_FLD_RECORDCARD,      // 记录卡片(记录) varchar
	enum_str_TBL_SCATMOSSAMPLE_FLD_SAMPLEORGN,      // 采样单位 varchar
	enum_str_TBL_SCATMOSSAMPLE_FLD_SWFOMW,          // 采样人 varchar
	enum_str_TBL_SCATMOSSAMPLE_FLD_GCEABJ,          // 采样日期 date
	enum_str_TBL_SCATMOSSAMPLE_FLD_INPUTER,         // 录入员 varchar
	enum_str_TBL_SCATMOSSAMPLE_FLD_INPUTORGN,       // 录入单位 varchar
	enum_str_TBL_SCATMOSSAMPLE_FLD_INPUTDATE,       // 录入日期 date
	// 水样基本情况表
	enum_int_TBL_SCWATERSAMPLE_FLD_WATERSAMPLEID,   // 水样ID int
	enum_str_TBL_SCWATERSAMPLE_FLD_WATERNAME,       // 水体名称 varchar
	enum_str_TBL_SCWATERSAMPLE_FLD_SAMPLESITE,      // 采样部位 varchar
	enum_double_TBL_SCWATERSAMPLE_FLD_SWNCAH,       // 水深(m) float
	enum_double_TBL_SCWATERSAMPLE_FLD_SWEGAB,       // 水位埋深(m) float
	enum_double_TBL_SCWATERSAMPLE_FLD_WELLDEPTH,    // 井深(m) float
	enum_double_TBL_SCWATERSAMPLE_FLD_SWADET,       // 水温(℃) float
	enum_str_TBL_SCWATERSAMPLE_FLD_WATERCOLOR,      // 水色 varchar
	enum_str_TBL_SCWATERSAMPLE_FLD_WATERSMELLY,     // 水臭 varchar
	enum_double_TBL_SCWATERSAMPLE_FLD_PKJFP,        // 浊度 float
	enum_double_TBL_SCWATERSAMPLE_FLD_PH,           // pH值 float
	enum_str_TBL_SCWATERSAMPLE_FLD_BOTTOMPRODUCT,   // 底积物 varchar
	enum_str_TBL_SCWATERSAMPLE_FLD__POLLUTION,      // 污染 varchar
	enum_str_TBL_SCWATERSAMPLE_FLD__USE,            // 用途 varchar
	enum_str_TBL_SCWATERSAMPLE_FLD__MARK,           // 标记 varchar
	enum_str_TBL_SCWATERSAMPLE_FLD__MEMO,           // 备注 varchar
	enum_str_TBL_SCWATERSAMPLE_FLD_GCEABB,          // 样品编号 varchar
	enum_int_TBL_SCWATERSAMPLE_FLD_PNTID,           // 点ID int
	enum_str_TBL_SCWATERSAMPLE_FLD_SWBCF,           // 样品类型 varchar
	enum_str_TBL_SCWATERSAMPLE_FLD_ISMIXSAMPLE,     // 混合样 varchar
	enum_str_TBL_SCWATERSAMPLE_FLD_PNTTYPE,         // 点类型 varchar
	enum_str_TBL_SCWATERSAMPLE_FLD_SECONDCODE,      // 样品二次编码 varchar
	enum_double_TBL_SCWATERSAMPLE_FLD_SAMPLEVOLUME, // 样品体积 float
	enum_str_TBL_SCWATERSAMPLE_FLD_GCEABM,          // 野外命名 varchar
	enum_double_TBL_SCWATERSAMPLE_FLD_GCEAAL,       // 样品重量(kg) float
	enum_str_TBL_SCWATERSAMPLE_FLD_SAMPLELENGTH,    // 样品长度(cm) varchar
	enum_str_TBL_SCWATERSAMPLE_FLD_PRETREATMETHOD,  // 预处理方法 varchar
	enum_str_TBL_SCWATERSAMPLE_FLD_TESTCONTENT,     // 测试内容 varchar
	enum_str_TBL_SCWATERSAMPLE_FLD_PLANEPOSMAP,     // 平面位置示意图 varchar
	enum_str_TBL_SCWATERSAMPLE_FLD_PROFILEMAP,      // 剖面示意图 varchar
	enum_str_TBL_SCWATERSAMPLE_FLD_FIELDIMAGE,      // 野外照片(视频) varchar
	enum_str_TBL_SCWATERSAMPLE_FLD_RECORDCARD,      // 记录卡片(记录) varchar
	enum_str_TBL_SCWATERSAMPLE_FLD_SAMPLEORGN,      // 采样单位 varchar
	enum_str_TBL_SCWATERSAMPLE_FLD_SWFOMW,          // 采样人 varchar
	enum_str_TBL_SCWATERSAMPLE_FLD_GCEABJ,          // 采样日期 date
	enum_str_TBL_SCWATERSAMPLE_FLD_INPUTER,         // 录入员 varchar
	enum_str_TBL_SCWATERSAMPLE_FLD_INPUTORGN,       // 录入单位 varchar
	enum_str_TBL_SCWATERSAMPLE_FLD_INPUTDATE,       // 录入日期 date
	// 水悬浮物样品基本情况表
	enum_int_TBL_SCWATERSUSPEND_FLD_SUSPENDID,       // 水悬物样ID int
	enum_str_TBL_SCWATERSUSPEND_FLD_SAMPLEBAGNO,     // 样品袋号 varchar
	enum_str_TBL_SCWATERSUSPEND_FLD_WATERNAME,       // 水体名称 varchar
	enum_str_TBL_SCWATERSUSPEND_FLD_SAMPLESITE,      // 采样部位 varchar
	enum_double_TBL_SCWATERSUSPEND_FLD_SWNCAH,       // 水深(m) float
	enum_str_TBL_SCWATERSUSPEND_FLD_SAMPLECOLOR,     // 样品颜色 varchar
	enum_str_TBL_SCWATERSUSPEND_FLD__MEMO,           // 备注 varchar
	enum_str_TBL_SCWATERSUSPEND_FLD_GCEABB,          // 样品编号 varchar
	enum_int_TBL_SCWATERSUSPEND_FLD_PNTID,           // 点ID int
	enum_str_TBL_SCWATERSUSPEND_FLD_SWBCF,           // 样品类型 varchar
	enum_str_TBL_SCWATERSUSPEND_FLD_ISMIXSAMPLE,     // 混合样 varchar
	enum_str_TBL_SCWATERSUSPEND_FLD_PNTTYPE,         // 点类型 varchar
	enum_str_TBL_SCWATERSUSPEND_FLD_SECONDCODE,      // 样品二次编码 varchar
	enum_double_TBL_SCWATERSUSPEND_FLD_SAMPLEVOLUME, // 样品体积 float
	enum_str_TBL_SCWATERSUSPEND_FLD_GCEABM,          // 野外命名 varchar
	enum_double_TBL_SCWATERSUSPEND_FLD_GCEAAL,       // 样品重量(kg) float
	enum_str_TBL_SCWATERSUSPEND_FLD_SAMPLELENGTH,    // 样品长度(cm) varchar
	enum_str_TBL_SCWATERSUSPEND_FLD_PRETREATMETHOD,  // 预处理方法 varchar
	enum_str_TBL_SCWATERSUSPEND_FLD_TESTCONTENT,     // 测试内容 varchar
	enum_str_TBL_SCWATERSUSPEND_FLD_PLANEPOSMAP,     // 平面位置示意图 varchar
	enum_str_TBL_SCWATERSUSPEND_FLD_PROFILEMAP,      // 剖面示意图 varchar
	enum_str_TBL_SCWATERSUSPEND_FLD_FIELDIMAGE,      // 野外照片(视频) varchar
	enum_str_TBL_SCWATERSUSPEND_FLD_RECORDCARD,      // 记录卡片(记录) varchar
	enum_str_TBL_SCWATERSUSPEND_FLD_SAMPLEORGN,      // 采样单位 varchar
	enum_str_TBL_SCWATERSUSPEND_FLD_SWFOMW,          // 采样人 varchar
	enum_str_TBL_SCWATERSUSPEND_FLD_GCEABJ,          // 采样日期 date
	enum_str_TBL_SCWATERSUSPEND_FLD_INPUTER,         // 录入员 varchar
	enum_str_TBL_SCWATERSUSPEND_FLD_INPUTORGN,       // 录入单位 varchar
	enum_str_TBL_SCWATERSUSPEND_FLD_INPUTDATE,       // 录入日期 date
	// 动植物样品基本情况表
	enum_int_TBL_SCANIMALPLANT_FLD_ANIMALSAMPID,    // 动(植)样ID int
	enum_str_TBL_SCANIMALPLANT_FLD_ANIPLANTTYPE,    // 动(植)物类型 varchar
	enum_str_TBL_SCANIMALPLANT_FLD_ANIPLANTNAME,    // 动(植)物名称 varchar
	enum_str_TBL_SCANIMALPLANT_FLD_SAMPLESITE,      // 采样部位 varchar
	enum_str_TBL_SCANIMALPLANT_FLD_SAMPLECOLOR,     // 样品颜色 varchar
	enum_str_TBL_SCANIMALPLANT_FLD__STORAGE,        // 样品储存 varchar
	enum_str_TBL_SCANIMALPLANT_FLD__PROCESS,        // 样品加工 varchar
	enum_str_TBL_SCANIMALPLANT_FLD_GCKBBA,          // 地貌 varchar
	enum_str_TBL_SCANIMALPLANT_FLD_SOILCAUSETYPE,   // 土壤成因类型 varchar
	enum_str_TBL_SCANIMALPLANT_FLD__MEMO,           // 备注 varchar
	enum_str_TBL_SCANIMALPLANT_FLD_GCEABB,          // 样品编号 varchar
	enum_int_TBL_SCANIMALPLANT_FLD_PNTID,           // 点ID int
	enum_str_TBL_SCANIMALPLANT_FLD_SWBCF,           // 样品类型 varchar
	enum_str_TBL_SCANIMALPLANT_FLD_ISMIXSAMPLE,     // 混合样 varchar
	enum_str_TBL_SCANIMALPLANT_FLD_PNTTYPE,         // 点类型 varchar
	enum_str_TBL_SCANIMALPLANT_FLD_SECONDCODE,      // 样品二次编码 varchar
	enum_double_TBL_SCANIMALPLANT_FLD_SAMPLEVOLUME, // 样品体积 float
	enum_str_TBL_SCANIMALPLANT_FLD_GCEABM,          // 野外命名 varchar
	enum_double_TBL_SCANIMALPLANT_FLD_GCEAAL,       // 样品重量(kg) float
	enum_str_TBL_SCANIMALPLANT_FLD_SAMPLELENGTH,    // 样品长度(cm) varchar
	enum_str_TBL_SCANIMALPLANT_FLD_PRETREATMETHOD,  // 预处理方法 varchar
	enum_str_TBL_SCANIMALPLANT_FLD_TESTCONTENT,     // 测试内容 varchar
	enum_str_TBL_SCANIMALPLANT_FLD_PLANEPOSMAP,     // 平面位置示意图 varchar
	enum_str_TBL_SCANIMALPLANT_FLD_PROFILEMAP,      // 剖面示意图 varchar
	enum_str_TBL_SCANIMALPLANT_FLD_FIELDIMAGE,      // 野外照片(视频) varchar
	enum_str_TBL_SCANIMALPLANT_FLD_RECORDCARD,      // 记录卡片(记录) varchar
	enum_str_TBL_SCANIMALPLANT_FLD_SAMPLEORGN,      // 采样单位 varchar
	enum_str_TBL_SCANIMALPLANT_FLD_SWFOMW,          // 采样人 varchar
	enum_str_TBL_SCANIMALPLANT_FLD_GCEABJ,          // 采样日期 date
	enum_str_TBL_SCANIMALPLANT_FLD_INPUTER,         // 录入员 varchar
	enum_str_TBL_SCANIMALPLANT_FLD_INPUTORGN,       // 录入单位 varchar
	enum_str_TBL_SCANIMALPLANT_FLD_INPUTDATE,       // 录入日期 date
	// 岩石物理力学实验成果表
	enum_int_TBL_INROCKPHYSICS_FLD_ROCKTESTID,       // 岩石试验ID int
	enum_str_TBL_INROCKPHYSICS_FLD_SWFGAA,           // 采样层位 varchar
	enum_double_TBL_INROCKPHYSICS_FLD_TOPDEPTH,      // 取样顶深度 float
	enum_double_TBL_INROCKPHYSICS_FLD_BOTTOMDEPTH,   // 取样底深度 float
	enum_int_TBL_INROCKPHYSICS_FLD_PNTID,            // 点ID int
	enum_str_TBL_INROCKPHYSICS_FLD_TCMC,             // 土层名称 varchar
	enum_str_TBL_INROCKPHYSICS_FLD_GEOCODE,          // 地质代号 varchar
	enum_str_TBL_INROCKPHYSICS_FLD_TESTNO,           //  varchar
	enum_str_TBL_INROCKPHYSICS_FLD_TESTCATEGORY,     // 试验类型 varchar
	enum_double_TBL_INROCKPHYSICS_FLD_GCBHKY,        // 饱和抗压强度(MPa) float
	enum_double_TBL_INROCKPHYSICS_FLD_GCGZKY,        // 干燥抗压强度(MPa) float
	enum_double_TBL_INROCKPHYSICS_FLD__SATURATED,    // 饱和抗拉强度(MPa) float
	enum_double_TBL_INROCKPHYSICS_FLD__DRY,          // 干燥抗拉强度(MPa) float
	enum_double_TBL_INROCKPHYSICS_FLD_GCCBG,         // 软化系数 float
	enum_double_TBL_INROCKPHYSICS_FLD_GCBFOA,        // 内聚力(MPa) float
	enum_double_TBL_INROCKPHYSICS_FLD_GCDMAC,        // 内摩擦角(度) float
	enum_double_TBL_INROCKPHYSICS_FLD_MAXIMUMSTRESS, // 最大正应力(MPa) float
	enum_double_TBL_INROCKPHYSICS_FLD_GCDKBB,        // 弹性模量(MPa) float
	enum_double_TBL_INROCKPHYSICS_FLD_GCDLAH,        // 泊松比 float
	enum_double_TBL_INROCKPHYSICS_FLD_BLOCKDENSITY,  // 块体密度(g/cm3) float
	enum_double_TBL_INROCKPHYSICS_FLD_GCDAO,         // 颗粒密度(g/cm3) float
	enum_double_TBL_INROCKPHYSICS_FLD_GCDBB,         // 孔隙率(%) float
	enum_double_TBL_INROCKPHYSICS_FLD_SATWATERRATE,  // 饱和吸水率(%) float
	enum_str_TBL_INROCKPHYSICS_FLD_GCEABB,           // 样品编号 varchar
	enum_str_TBL_INROCKPHYSICS_FLD_SWBCF,            // 样品类型 varchar
	enum_str_TBL_INROCKPHYSICS_FLD_ISMIXSAMPLE,      // 混合样 varchar
	enum_str_TBL_INROCKPHYSICS_FLD_PNTTYPE,          // 点类型 varchar
	enum_str_TBL_INROCKPHYSICS_FLD_SECONDCODE,       // 样品二次编码 varchar
	enum_double_TBL_INROCKPHYSICS_FLD_SAMPLEVOLUME,  // 样品体积 float
	enum_str_TBL_INROCKPHYSICS_FLD_GCEABM,           // 野外命名 varchar
	enum_double_TBL_INROCKPHYSICS_FLD_GCEAAL,        // 样品重量(kg) float
	enum_str_TBL_INROCKPHYSICS_FLD_SAMPLELENGTH,     // 样品长度(cm) varchar
	enum_str_TBL_INROCKPHYSICS_FLD_PRETREATMETHOD,   // 预处理方法 varchar
	enum_str_TBL_INROCKPHYSICS_FLD_TESTCONTENT,      // 测试内容 varchar
	enum_str_TBL_INROCKPHYSICS_FLD_PLANEPOSMAP,      // 平面位置示意图 varchar
	enum_str_TBL_INROCKPHYSICS_FLD_PROFILEMAP,       // 剖面示意图 varchar
	enum_str_TBL_INROCKPHYSICS_FLD_FIELDIMAGE,       // 野外照片(视频) varchar
	enum_str_TBL_INROCKPHYSICS_FLD_RECORDCARD,       // 记录卡片(记录) varchar
	enum_str_TBL_INROCKPHYSICS_FLD_SAMPLEORGN,       // 采样单位 varchar
	enum_str_TBL_INROCKPHYSICS_FLD_SWFOMW,           // 采样人 varchar
	enum_str_TBL_INROCKPHYSICS_FLD_GCEABJ,           // 采样日期 date
	enum_str_TBL_INROCKPHYSICS_FLD_INPUTER,          // 录入员 varchar
	enum_str_TBL_INROCKPHYSICS_FLD_INPUTORGN,        // 录入单位 varchar
	enum_str_TBL_INROCKPHYSICS_FLD_INPUTDATE,        // 录入日期 date
	enum_str_TBL_INROCKPHYSICS_FLD_GCEABD,           // 室内编号 varchar
	enum_str_TBL_INROCKPHYSICS_FLD_TESTEQUIP,        // 试验仪器 varchar
	enum_str_TBL_INROCKPHYSICS_FLD_TESTMETHOD,       // 试验方法 varchar
	enum_str_TBL_INROCKPHYSICS_FLD_TESTBASED,        // 检验依据 varchar
	enum_str_TBL_INROCKPHYSICS_FLD_GCEAJC,           // 试验单位 varchar
	enum_str_TBL_INROCKPHYSICS_FLD_SWFGAM,           // 收样日期 date
	enum_str_TBL_INROCKPHYSICS_FLD_SWFGAN,           // 报告日期 date
	enum_str_TBL_INROCKPHYSICS_FLD_GCEAJD,           // 校对 varchar
	enum_str_TBL_INROCKPHYSICS_FLD_AUDITOR,          // 审核 varchar
	enum_str_TBL_INROCKPHYSICS_FLD_TESTLEADER,       // 试验负责人 varchar
	enum_str_TBL_INROCKPHYSICS_FLD__REPORT,          // 原始测试分析报告 varchar
	// 常规土工实验成果表
	enum_int_TBL_INGEOTECHNICALEXP_FLD_GEOTECHNICALID,        // 土工ID int
	enum_double_TBL_INGEOTECHNICALEXP_FLD_TOPDEPTH,           // 取样顶深度 float
	enum_double_TBL_INGEOTECHNICALEXP_FLD_BOTTOMDEPTH,        // 取样底深度 float
	enum_int_TBL_INGEOTECHNICALEXP_FLD_PNTID,                 // 点ID int
	enum_str_TBL_INGEOTECHNICALEXP_FLD_SWFGAA,                // 采样层位 varchar
	enum_str_TBL_INGEOTECHNICALEXP_FLD_TCMC,                  // 土层名称 varchar
	enum_str_TBL_INGEOTECHNICALEXP_FLD_GEOCODE,               // 地质代号 varchar
	enum_str_TBL_INGEOTECHNICALEXP_FLD_TESTNO,                //  varchar
	enum_str_TBL_INGEOTECHNICALEXP_FLD_TESTCATEGORY,          // 试验类型 varchar
	enum_double_TBL_INGEOTECHNICALEXP_FLD_ZD,                 // 重度 float
	enum_double_TBL_INGEOTECHNICALEXP_FLD_GZD,                // 干重度 float
	enum_double_TBL_INGEOTECHNICALEXP_FLD_GCDAL,              // 湿密度(g/cm3) float
	enum_double_TBL_INGEOTECHNICALEXP_FLD_GCDAE,              // 干密度(g/cm3) float
	enum_double_TBL_INGEOTECHNICALEXP_FLD_BZ,                 // 比重 float
	enum_double_TBL_INGEOTECHNICALEXP_FLD_GCDCAO,             // 含水率(%) float
	enum_double_TBL_INGEOTECHNICALEXP_FLD_GCDBB,              // 孔隙比 float
	enum_double_TBL_INGEOTECHNICALEXP_FLD_DHABCU,             // 饱和度(%) float
	enum_double_TBL_INGEOTECHNICALEXP_FLD_SOILGRAVITY,        // 土粒比重 float
	enum_double_TBL_INGEOTECHNICALEXP_FLD_GCDDD,              // 液限(%) float
	enum_double_TBL_INGEOTECHNICALEXP_FLD_GCDDC,              // 塑限(%) float
	enum_double_TBL_INGEOTECHNICALEXP_FLD_GCDDE,              // 塑性指数 float
	enum_double_TBL_INGEOTECHNICALEXP_FLD_GCDDF,              // 液性指数 float
	enum_double_TBL_INGEOTECHNICALEXP_FLD_CURECOEFFICIENT,    // 曲率系数 float
	enum_double_TBL_INGEOTECHNICALEXP_FLD_GCKBCQ,             // 不均匀系数 float
	enum_double_TBL_INGEOTECHNICALEXP_FLD_EFFECTPARTICLESIZE, // 有效粒径(mm) float
	enum_double_TBL_INGEOTECHNICALEXP_FLD_GCDLAC,             // 压缩系数(MPa-1) float
	enum_double_TBL_INGEOTECHNICALEXP_FLD_XQGJYL,             // 先期固结压力 float
	enum_double_TBL_INGEOTECHNICALEXP_FLD_YSZS,               // 压缩指数 float
	enum_double_TBL_INGEOTECHNICALEXP_FLD_HTZS,               // 回弹指数 float
	enum_double_TBL_INGEOTECHNICALEXP_FLD_,                   // （天然快剪）粘聚力(kPa) float
	enum_double_TBL_INGEOTECHNICALEXP_FLD_GCDMAC,             // （天然快剪）内摩擦角(度) float
	enum_double_TBL_INGEOTECHNICALEXP_FLD_GJKJNJL,            // 固结快剪粘聚力 float
	enum_double_TBL_INGEOTECHNICALEXP_FLD_GJKJNMCJ,           // 固结快剪内摩擦角 float
	enum_double_TBL_INGEOTECHNICALEXP_FLD_MJNJL,              // 慢剪粘聚力 float
	enum_double_TBL_INGEOTECHNICALEXP_FLD_MJNMCJ,             // 慢剪内摩擦角 float
	enum_double_TBL_INGEOTECHNICALEXP_FLD_GCDEAF,             // 自由膨胀率(%) float
	enum_double_TBL_INGEOTECHNICALEXP_FLD_TOC,                // 有机质含量(%) float
	enum_double_TBL_INGEOTECHNICALEXP_FLD_FINEGRAINED,        // 细粒土含水率(%) float
	enum_double_TBL_INGEOTECHNICALEXP_FLD_SWGGAC,             // 垂向渗透系数(cm/s) float
	enum_double_TBL_INGEOTECHNICALEXP_FLD_SWGGAB,             // 水平渗透系数(cm/s) float
	enum_double_TBL_INGEOTECHNICALEXP_FLD_UNDERWATERANGLE,    // 水下休止角(坡角)(度) float
	enum_double_TBL_INGEOTECHNICALEXP_FLD_UPWATERANGLE,       // 水上休止角坡角(度) float
	enum_double_TBL_INGEOTECHNICALEXP_FLD_YZ,                 // 原状(QU) float
	enum_double_TBL_INGEOTECHNICALEXP_FLD_CS,                 // 重塑(QU_) float
	enum_double_TBL_INGEOTECHNICALEXP_FLD_LMD,                // 灵敏度 float
	enum_double_TBL_INGEOTECHNICALEXP_FLD_QT1,                // 液限（100g锥） float
	enum_double_TBL_INGEOTECHNICALEXP_FLD_QT2,                // 塑性（100g锥） float
	enum_double_TBL_INGEOTECHNICALEXP_FLD_SZUUNJL,            // 三轴UU法粘聚力© float
	enum_double_TBL_INGEOTECHNICALEXP_FLD_SZUUNMCJ,           // 三轴UU法内摩擦角(Φ) float
	enum_double_TBL_INGEOTECHNICALEXP_FLD_SZUUNJL_,           // 三轴UU法粘聚力(C1) float
	enum_double_TBL_INGEOTECHNICALEXP_FLD_SZCUNJL,            // 三轴CU法粘聚力(C) float
	enum_double_TBL_INGEOTECHNICALEXP_FLD_SZCUNMCJ,           // 三轴CU法内摩擦角(Φ) float
	enum_double_TBL_INGEOTECHNICALEXP_FLD_SZCUNJL_,           // 三轴CU法粘聚力(C_) float
	enum_double_TBL_INGEOTECHNICALEXP_FLD_SZCUNMCJ_,          // 三轴CU法内摩擦角(Φ_) float
	enum_double_TBL_INGEOTECHNICALEXP_FLD_GCDKBD1,            // 压缩模量1(MPa) float
	enum_double_TBL_INGEOTECHNICALEXP_FLD_GCDKBD2,            // 压缩模量2(MPa) float
	enum_double_TBL_INGEOTECHNICALEXP_FLD_GCDKBD3,            // 压缩模量3(MPa) float
	enum_double_TBL_INGEOTECHNICALEXP_FLD_GCDKBD4,            // 压缩模量4(MPa) float
	enum_double_TBL_INGEOTECHNICALEXP_FLD_GCDKBD5,            // 压缩模量5(MPa) float
	enum_double_TBL_INGEOTECHNICALEXP_FLD_GCDKBD6,            // 压缩模量6(MPa) float
	enum_double_TBL_INGEOTECHNICALEXP_FLD_GCDKBD7,            // 压缩模量7(MPa) float
	enum_double_TBL_INGEOTECHNICALEXP_FLD_GCDKBD8,            // 压缩模量8(MPa) float
	enum_double_TBL_INGEOTECHNICALEXP_FLD_GCDKBD9,            // 压缩模量9(MPa) float
	enum_double_TBL_INGEOTECHNICALEXP_FLD_GCDKBD10,           // 压缩模量10(MPa) float
	enum_double_TBL_INGEOTECHNICALEXP_FLD_GJXS1,              // 固结系数1(KPa) float
	enum_double_TBL_INGEOTECHNICALEXP_FLD_GJXS2,              // 固结系数2(KPa) float
	enum_double_TBL_INGEOTECHNICALEXP_FLD_GJXS3,              // 固结系数3(KPa) float
	enum_double_TBL_INGEOTECHNICALEXP_FLD_GJXS4,              // 固结系数4(KPa) float
	enum_double_TBL_INGEOTECHNICALEXP_FLD_GJXS5,              // 固结系数5(KPa) float
	enum_double_TBL_INGEOTECHNICALEXP_FLD_GJXS6,              // 固结系数6(KPa) float
	enum_double_TBL_INGEOTECHNICALEXP_FLD_GJXS7,              // 固结系数7(KPa) float
	enum_double_TBL_INGEOTECHNICALEXP_FLD_GJXS8,              // 固结系数8(KPa) float
	enum_double_TBL_INGEOTECHNICALEXP_FLD_GJXS9,              // 固结系数9(KPa) float
	enum_double_TBL_INGEOTECHNICALEXP_FLD_GJXS10,             // 固结系数10(KPa) float
	enum_double_TBL_INGEOTECHNICALEXP_FLD_KLZC1,              // 颗粒组成1(%) float
	enum_double_TBL_INGEOTECHNICALEXP_FLD_KLZC2,              // 颗粒组成2(%) float
	enum_double_TBL_INGEOTECHNICALEXP_FLD_KLZC3,              // 颗粒组成3(%) float
	enum_double_TBL_INGEOTECHNICALEXP_FLD_KLZC4,              // 颗粒组成4(%) float
	enum_double_TBL_INGEOTECHNICALEXP_FLD_KLZC5,              // 颗粒组成5(%) float
	enum_double_TBL_INGEOTECHNICALEXP_FLD_KLZC6,              // 颗粒组成6(%) float
	enum_double_TBL_INGEOTECHNICALEXP_FLD_KLZC7,              // 颗粒组成7(%) float
	enum_double_TBL_INGEOTECHNICALEXP_FLD_KLZC8,              // 颗粒组成8(%) float
	enum_double_TBL_INGEOTECHNICALEXP_FLD_KLZC9,              // 颗粒组成9(%) float
	enum_double_TBL_INGEOTECHNICALEXP_FLD_KLZC10,             // 颗粒组成10(%) float
	enum_double_TBL_INGEOTECHNICALEXP_FLD_KLZC11,             // 颗粒组成11(%) float
	enum_double_TBL_INGEOTECHNICALEXP_FLD_KLZC12,             // 颗粒组成12(%) float
	enum_double_TBL_INGEOTECHNICALEXP_FLD_KLZC13,             // 颗粒组成13(%) float
	enum_double_TBL_INGEOTECHNICALEXP_FLD_KLZC14,             // 颗粒组成14(%) float
	enum_double_TBL_INGEOTECHNICALEXP_FLD_KLZC15,             // 颗粒组成15(%) float
	enum_str_TBL_INGEOTECHNICALEXP_FLD_GCEABB,                // 样品编号 varchar
	enum_str_TBL_INGEOTECHNICALEXP_FLD_SWBCF,                 // 样品类型 varchar
	enum_str_TBL_INGEOTECHNICALEXP_FLD_ISMIXSAMPLE,           // 混合样 varchar
	enum_str_TBL_INGEOTECHNICALEXP_FLD_PNTTYPE,               // 点类型 varchar
	enum_str_TBL_INGEOTECHNICALEXP_FLD_SECONDCODE,            // 样品二次编码 varchar
	enum_double_TBL_INGEOTECHNICALEXP_FLD_SAMPLEVOLUME,       // 样品体积 float
	enum_str_TBL_INGEOTECHNICALEXP_FLD_GCEABM,                // 野外命名 varchar
	enum_double_TBL_INGEOTECHNICALEXP_FLD_GCEAAL,             // 样品重量(kg) float
	enum_str_TBL_INGEOTECHNICALEXP_FLD_SAMPLELENGTH,          // 样品长度(cm) varchar
	enum_str_TBL_INGEOTECHNICALEXP_FLD_PRETREATMETHOD,        // 预处理方法 varchar
	enum_str_TBL_INGEOTECHNICALEXP_FLD_TESTCONTENT,           // 测试内容 varchar
	enum_str_TBL_INGEOTECHNICALEXP_FLD_PLANEPOSMAP,           // 平面位置示意图 varchar
	enum_str_TBL_INGEOTECHNICALEXP_FLD_PROFILEMAP,            // 剖面示意图 varchar
	enum_str_TBL_INGEOTECHNICALEXP_FLD_FIELDIMAGE,            // 野外照片(视频) varchar
	enum_str_TBL_INGEOTECHNICALEXP_FLD_RECORDCARD,            // 记录卡片(记录) varchar
	enum_str_TBL_INGEOTECHNICALEXP_FLD_SAMPLEORGN,            // 采样单位 varchar
	enum_str_TBL_INGEOTECHNICALEXP_FLD_SWFOMW,                // 采样人 varchar
	enum_str_TBL_INGEOTECHNICALEXP_FLD_GCEABJ,                // 采样日期 date
	enum_str_TBL_INGEOTECHNICALEXP_FLD_INPUTER,               // 录入员 varchar
	enum_str_TBL_INGEOTECHNICALEXP_FLD_INPUTORGN,             // 录入单位 varchar
	enum_str_TBL_INGEOTECHNICALEXP_FLD_INPUTDATE,             // 录入日期 date
	enum_str_TBL_INGEOTECHNICALEXP_FLD_GCEABD,                // 室内编号 varchar
	enum_str_TBL_INGEOTECHNICALEXP_FLD_GCEABL,                // 室内名称 varchar
	enum_str_TBL_INGEOTECHNICALEXP_FLD_TESTEQUIP,             // 试验仪器 varchar
	enum_str_TBL_INGEOTECHNICALEXP_FLD_TESTMETHOD,            // 试验方法 varchar
	enum_str_TBL_INGEOTECHNICALEXP_FLD_TESTBASED,             // 检验依据 varchar
	enum_str_TBL_INGEOTECHNICALEXP_FLD_GCEAJC,                // 试验单位 varchar
	enum_str_TBL_INGEOTECHNICALEXP_FLD_SWFGAM,                // 收样日期 date
	enum_str_TBL_INGEOTECHNICALEXP_FLD_SWFGAN,                // 报告日期 date
	enum_str_TBL_INGEOTECHNICALEXP_FLD_GCEAJD,                // 校对 varchar
	enum_str_TBL_INGEOTECHNICALEXP_FLD_AUDITOR,               // 审核 varchar
	enum_str_TBL_INGEOTECHNICALEXP_FLD_TESTLEADER,            // 试验负责人 varchar
	enum_str_TBL_INGEOTECHNICALEXP_FLD__REPORT,               // 原始测试分析报告 varchar
	// 高压固结实验成果表
	enum_int_TBL_INCONSOLIDATL_FLD_CONSOLIDATID,            // 高压固结ID int
	enum_double_TBL_INCONSOLIDATL_FLD_TOPDEPTH,             // 取样顶深度 float
	enum_double_TBL_INCONSOLIDATL_FLD_BOTTOMDEPTH,          // 取样底深度 float
	enum_int_TBL_INCONSOLIDATL_FLD_PNTID,                   // 点ID int
	enum_str_TBL_INCONSOLIDATL_FLD_SWFGAA,                  // 采样层位 varchar
	enum_str_TBL_INCONSOLIDATL_FLD_TCMC,                    // 土层名称 varchar
	enum_str_TBL_INCONSOLIDATL_FLD_GEOCODE,                 // 地质代号 varchar
	enum_str_TBL_INCONSOLIDATL_FLD_TESTNO,                  //  varchar
	enum_str_TBL_INCONSOLIDATL_FLD_TESTCATEGORY,            // 试验类型 varchar
	enum_double_TBL_INCONSOLIDATL_FLD_GCDLAF,               // 先期固结压力(kPa) float
	enum_double_TBL_INCONSOLIDATL_FLD_COMPRESSINDEX,        // 压缩指数 float
	enum_double_TBL_INCONSOLIDATL_FLD_REBOUNDINDEX,         // 回弹指数 float
	enum_double_TBL_INCONSOLIDATL_FLD_CONSOLIDATPRESSURE,   // 固结压力(kPa) float
	enum_double_TBL_INCONSOLIDATL_FLD_GCDBB,                // 孔隙比 float
	enum_double_TBL_INCONSOLIDATL_FLD_GCDKBD,               // 压缩模量 float
	enum_double_TBL_INCONSOLIDATL_FLD_GCDLAC,               // 压缩系数 float
	enum_double_TBL_INCONSOLIDATL_FLD_VERTICALCONSOLIDAT,   // 竖向固结系数 float
	enum_double_TBL_INCONSOLIDATL_FLD_HORIZONTALCONSOLIDAT, // 水平固结系数 float
	enum_str_TBL_INCONSOLIDATL_FLD_GCEABB,                  // 样品编号 varchar
	enum_str_TBL_INCONSOLIDATL_FLD_SWBCF,                   // 样品类型 varchar
	enum_str_TBL_INCONSOLIDATL_FLD_ISMIXSAMPLE,             // 混合样 varchar
	enum_str_TBL_INCONSOLIDATL_FLD_PNTTYPE,                 // 点类型 varchar
	enum_str_TBL_INCONSOLIDATL_FLD_SECONDCODE,              // 样品二次编码 varchar
	enum_double_TBL_INCONSOLIDATL_FLD_SAMPLEVOLUME,         // 样品体积 float
	enum_str_TBL_INCONSOLIDATL_FLD_GCEABM,                  // 野外命名 varchar
	enum_double_TBL_INCONSOLIDATL_FLD_GCEAAL,               // 样品重量(kg) float
	enum_str_TBL_INCONSOLIDATL_FLD_SAMPLELENGTH,            // 样品长度(cm) varchar
	enum_str_TBL_INCONSOLIDATL_FLD_PRETREATMETHOD,          // 预处理方法 varchar
	enum_str_TBL_INCONSOLIDATL_FLD_TESTCONTENT,             // 测试内容 varchar
	enum_str_TBL_INCONSOLIDATL_FLD_PLANEPOSMAP,             // 平面位置示意图 varchar
	enum_str_TBL_INCONSOLIDATL_FLD_PROFILEMAP,              // 剖面示意图 varchar
	enum_str_TBL_INCONSOLIDATL_FLD_FIELDIMAGE,              // 野外照片(视频) varchar
	enum_str_TBL_INCONSOLIDATL_FLD_RECORDCARD,              // 记录卡片(记录) varchar
	enum_str_TBL_INCONSOLIDATL_FLD_SAMPLEORGN,              // 采样单位 varchar
	enum_str_TBL_INCONSOLIDATL_FLD_SWFOMW,                  // 采样人 varchar
	enum_str_TBL_INCONSOLIDATL_FLD_GCEABJ,                  // 采样日期 date
	enum_str_TBL_INCONSOLIDATL_FLD_INPUTER,                 // 录入员 varchar
	enum_str_TBL_INCONSOLIDATL_FLD_INPUTORGN,               // 录入单位 varchar
	enum_str_TBL_INCONSOLIDATL_FLD_INPUTDATE,               // 录入日期 date
	enum_str_TBL_INCONSOLIDATL_FLD_GCEABD,                  // 室内编号 varchar
	enum_str_TBL_INCONSOLIDATL_FLD_TESTEQUIP,               // 试验仪器 varchar
	enum_str_TBL_INCONSOLIDATL_FLD_TESTMETHOD,              // 试验方法 varchar
	enum_str_TBL_INCONSOLIDATL_FLD_TESTBASED,               // 检验依据 varchar
	enum_str_TBL_INCONSOLIDATL_FLD_GCEAJC,                  // 试验单位 varchar
	enum_str_TBL_INCONSOLIDATL_FLD_SWFGAM,                  // 收样日期 date
	enum_str_TBL_INCONSOLIDATL_FLD_SWFGAN,                  // 报告日期 date
	enum_str_TBL_INCONSOLIDATL_FLD_GCEAJD,                  // 校对 varchar
	enum_str_TBL_INCONSOLIDATL_FLD_AUDITOR,                 // 审核 varchar
	enum_str_TBL_INCONSOLIDATL_FLD_TESTLEADER,              // 试验负责人 varchar
	enum_str_TBL_INCONSOLIDATL_FLD__REPORT,                 // 原始测试分析报告 varchar
	// 无侧限压缩试验成果表
	enum_int_TBL_INUNCONFINED_FLD_UNCONFINEDID,    // 无侧限ID int
	enum_double_TBL_INUNCONFINED_FLD_TOPDEPTH,     // 取样顶深度 float
	enum_double_TBL_INUNCONFINED_FLD_BOTTOMDEPTH,  // 取样底深度 float
	enum_int_TBL_INUNCONFINED_FLD_PNTID,           // 点ID int
	enum_str_TBL_INUNCONFINED_FLD_SWFGAA,          // 采样层位 varchar
	enum_str_TBL_INUNCONFINED_FLD_TCMC,            // 土层名称 varchar
	enum_str_TBL_INUNCONFINED_FLD_GEOCODE,         // 地质代号 varchar
	enum_str_TBL_INUNCONFINED_FLD_TESTNO,          //  varchar
	enum_str_TBL_INUNCONFINED_FLD_TESTCATEGORY,    // 试验类型 varchar
	enum_double_TBL_INUNCONFINED_FLD_GCDMAM,       // 原状土无侧限抗压强度(kPa) float
	enum_double_TBL_INUNCONFINED_FLD_GCDMAO,       // 重塑土无侧限抗压强度(kPa) float
	enum_double_TBL_INUNCONFINED_FLD_GCDKCR,       // 不排水抗剪强度(kPa) float
	enum_double_TBL_INUNCONFINED_FLD_GCBFI,        // 灵敏度 float
	enum_str_TBL_INUNCONFINED_FLD_GCEABB,          // 样品编号 varchar
	enum_str_TBL_INUNCONFINED_FLD_SWBCF,           // 样品类型 varchar
	enum_str_TBL_INUNCONFINED_FLD_ISMIXSAMPLE,     // 混合样 varchar
	enum_str_TBL_INUNCONFINED_FLD_PNTTYPE,         // 点类型 varchar
	enum_str_TBL_INUNCONFINED_FLD_SECONDCODE,      // 样品二次编码 varchar
	enum_double_TBL_INUNCONFINED_FLD_SAMPLEVOLUME, // 样品体积 float
	enum_str_TBL_INUNCONFINED_FLD_GCEABM,          // 野外命名 varchar
	enum_double_TBL_INUNCONFINED_FLD_GCEAAL,       // 样品重量(kg) float
	enum_str_TBL_INUNCONFINED_FLD_SAMPLELENGTH,    // 样品长度(cm) varchar
	enum_str_TBL_INUNCONFINED_FLD_PRETREATMETHOD,  // 预处理方法 varchar
	enum_str_TBL_INUNCONFINED_FLD_TESTCONTENT,     // 测试内容 varchar
	enum_str_TBL_INUNCONFINED_FLD_PLANEPOSMAP,     // 平面位置示意图 varchar
	enum_str_TBL_INUNCONFINED_FLD_PROFILEMAP,      // 剖面示意图 varchar
	enum_str_TBL_INUNCONFINED_FLD_FIELDIMAGE,      // 野外照片(视频) varchar
	enum_str_TBL_INUNCONFINED_FLD_RECORDCARD,      // 记录卡片(记录) varchar
	enum_str_TBL_INUNCONFINED_FLD_SAMPLEORGN,      // 采样单位 varchar
	enum_str_TBL_INUNCONFINED_FLD_SWFOMW,          // 采样人 varchar
	enum_str_TBL_INUNCONFINED_FLD_GCEABJ,          // 采样日期 date
	enum_str_TBL_INUNCONFINED_FLD_INPUTER,         // 录入员 varchar
	enum_str_TBL_INUNCONFINED_FLD_INPUTORGN,       // 录入单位 varchar
	enum_str_TBL_INUNCONFINED_FLD_INPUTDATE,       // 录入日期 date
	enum_str_TBL_INUNCONFINED_FLD_GCEABD,          // 室内编号 varchar
	enum_str_TBL_INUNCONFINED_FLD_TESTEQUIP,       // 试验仪器 varchar
	enum_str_TBL_INUNCONFINED_FLD_TESTMETHOD,      // 试验方法 varchar
	enum_str_TBL_INUNCONFINED_FLD_TESTBASED,       // 检验依据 varchar
	enum_str_TBL_INUNCONFINED_FLD_GCEAJC,          // 试验单位 varchar
	enum_str_TBL_INUNCONFINED_FLD_SWFGAM,          // 收样日期 date
	enum_str_TBL_INUNCONFINED_FLD_SWFGAN,          // 报告日期 date
	enum_str_TBL_INUNCONFINED_FLD_GCEAJD,          // 校对 varchar
	enum_str_TBL_INUNCONFINED_FLD_AUDITOR,         // 审核 varchar
	enum_str_TBL_INUNCONFINED_FLD_TESTLEADER,      // 试验负责人 varchar
	enum_str_TBL_INUNCONFINED_FLD__REPORT,         // 原始测试分析报告 varchar
	// 三轴实验成果表
	enum_int_TBL_INTHREEAXIS_FLD_THREEAXISID,         // 三轴ID int
	enum_double_TBL_INTHREEAXIS_FLD_TOPDEPTH,         // 取样顶深度 float
	enum_double_TBL_INTHREEAXIS_FLD_BOTTOMDEPTH,      // 取样底深度 float
	enum_int_TBL_INTHREEAXIS_FLD_PNTID,               // 点ID int
	enum_str_TBL_INTHREEAXIS_FLD_SWFGAA,              // 采样层位 varchar
	enum_str_TBL_INTHREEAXIS_FLD_TCMC,                // 土层名称 varchar
	enum_str_TBL_INTHREEAXIS_FLD_GEOCODE,             // 地质代号 varchar
	enum_str_TBL_INTHREEAXIS_FLD_TESTNO,              //  varchar
	enum_str_TBL_INTHREEAXIS_FLD_TESTCATEGORY,        // 试验类型 varchar
	enum_double_TBL_INTHREEAXIS_FLD_GCBFOA,           // 粘聚力(kPa) float
	enum_double_TBL_INTHREEAXIS_FLD_FRICTIONANGLE,    // 摩擦角(度) float
	enum_double_TBL_INTHREEAXIS_FLD_EFFECTCOHES,      // 有效粘聚力(kPa) float
	enum_double_TBL_INTHREEAXIS_FLD_EFFECTFRICTANGLE, // 有效摩擦角(度) float
	enum_str_TBL_INTHREEAXIS_FLD_GCEABB,              // 样品编号 varchar
	enum_str_TBL_INTHREEAXIS_FLD_SWBCF,               // 样品类型 varchar
	enum_str_TBL_INTHREEAXIS_FLD_ISMIXSAMPLE,         // 混合样 varchar
	enum_str_TBL_INTHREEAXIS_FLD_PNTTYPE,             // 点类型 varchar
	enum_str_TBL_INTHREEAXIS_FLD_SECONDCODE,          // 样品二次编码 varchar
	enum_double_TBL_INTHREEAXIS_FLD_SAMPLEVOLUME,     // 样品体积 float
	enum_str_TBL_INTHREEAXIS_FLD_GCEABM,              // 野外命名 varchar
	enum_double_TBL_INTHREEAXIS_FLD_GCEAAL,           // 样品重量(kg) float
	enum_str_TBL_INTHREEAXIS_FLD_SAMPLELENGTH,        // 样品长度(cm) varchar
	enum_str_TBL_INTHREEAXIS_FLD_PRETREATMETHOD,      // 预处理方法 varchar
	enum_str_TBL_INTHREEAXIS_FLD_TESTCONTENT,         // 测试内容 varchar
	enum_str_TBL_INTHREEAXIS_FLD_PLANEPOSMAP,         // 平面位置示意图 varchar
	enum_str_TBL_INTHREEAXIS_FLD_PROFILEMAP,          // 剖面示意图 varchar
	enum_str_TBL_INTHREEAXIS_FLD_FIELDIMAGE,          // 野外照片(视频) varchar
	enum_str_TBL_INTHREEAXIS_FLD_RECORDCARD,          // 记录卡片(记录) varchar
	enum_str_TBL_INTHREEAXIS_FLD_SAMPLEORGN,          // 采样单位 varchar
	enum_str_TBL_INTHREEAXIS_FLD_SWFOMW,              // 采样人 varchar
	enum_str_TBL_INTHREEAXIS_FLD_GCEABJ,              // 采样日期 date
	enum_str_TBL_INTHREEAXIS_FLD_INPUTER,             // 录入员 varchar
	enum_str_TBL_INTHREEAXIS_FLD_INPUTORGN,           // 录入单位 varchar
	enum_str_TBL_INTHREEAXIS_FLD_INPUTDATE,           // 录入日期 date
	enum_str_TBL_INTHREEAXIS_FLD_GCEABD,              // 室内编号 varchar
	enum_str_TBL_INTHREEAXIS_FLD_TESTEQUIP,           // 试验仪器 varchar
	enum_str_TBL_INTHREEAXIS_FLD_TESTMETHOD,          // 试验方法 varchar
	enum_str_TBL_INTHREEAXIS_FLD_TESTBASED,           // 检验依据 varchar
	enum_str_TBL_INTHREEAXIS_FLD_GCEAJC,              // 试验单位 varchar
	enum_str_TBL_INTHREEAXIS_FLD_SWFGAM,              // 收样日期 date
	enum_str_TBL_INTHREEAXIS_FLD_SWFGAN,              // 报告日期 date
	enum_str_TBL_INTHREEAXIS_FLD_GCEAJD,              // 校对 varchar
	enum_str_TBL_INTHREEAXIS_FLD_AUDITOR,             // 审核 varchar
	enum_str_TBL_INTHREEAXIS_FLD_TESTLEADER,          // 试验负责人 varchar
	enum_str_TBL_INTHREEAXIS_FLD__REPORT,             // 原始测试分析报告 varchar
	// 直剪实验成果表
	enum_int_TBL_INDIRECTSHEAR_FLD_DIRECTSHEARID,       // 直剪ID int
	enum_double_TBL_INDIRECTSHEAR_FLD_TOPDEPTH,         // 取样顶深度 float
	enum_double_TBL_INDIRECTSHEAR_FLD_BOTTOMDEPTH,      // 取样底深度 float
	enum_int_TBL_INDIRECTSHEAR_FLD_PNTID,               // 点ID int
	enum_str_TBL_INDIRECTSHEAR_FLD_SWFGAA,              // 采样层位 varchar
	enum_str_TBL_INDIRECTSHEAR_FLD_TCMC,                // 土层名称 varchar
	enum_str_TBL_INDIRECTSHEAR_FLD_GEOCODE,             // 地质代号 varchar
	enum_str_TBL_INDIRECTSHEAR_FLD_TESTNO,              //  varchar
	enum_str_TBL_INDIRECTSHEAR_FLD_TESTCATEGORY,        // 试验类型 varchar
	enum_double_TBL_INDIRECTSHEAR_FLD_MAXVERTICALPRESS, // 最大垂直压力(kPa) float
	enum_double_TBL_INDIRECTSHEAR_FLD_SHEER1,           // 剪应力τ100(kPa) float
	enum_double_TBL_INDIRECTSHEAR_FLD_SHEER2,           // 剪应力τ200(kPa) float
	enum_double_TBL_INDIRECTSHEAR_FLD_SHEER3,           // 剪应力τ300(kPa) float
	enum_double_TBL_INDIRECTSHEAR_FLD_SHEER4,           // 剪应力τ400(kPa) float
	enum_double_TBL_INDIRECTSHEAR_FLD_GCBFOA,           // 粘聚力(kPa) float
	enum_double_TBL_INDIRECTSHEAR_FLD_GCDMAC,           // 内摩擦角(度) float
	enum_str_TBL_INDIRECTSHEAR_FLD_GCEABB,              // 样品编号 varchar
	enum_str_TBL_INDIRECTSHEAR_FLD_SWBCF,               // 样品类型 varchar
	enum_str_TBL_INDIRECTSHEAR_FLD_ISMIXSAMPLE,         // 混合样 varchar
	enum_str_TBL_INDIRECTSHEAR_FLD_PNTTYPE,             // 点类型 varchar
	enum_str_TBL_INDIRECTSHEAR_FLD_SECONDCODE,          // 样品二次编码 varchar
	enum_double_TBL_INDIRECTSHEAR_FLD_SAMPLEVOLUME,     // 样品体积 float
	enum_str_TBL_INDIRECTSHEAR_FLD_GCEABM,              // 野外命名 varchar
	enum_double_TBL_INDIRECTSHEAR_FLD_GCEAAL,           // 样品重量(kg) float
	enum_str_TBL_INDIRECTSHEAR_FLD_SAMPLELENGTH,        // 样品长度(cm) varchar
	enum_str_TBL_INDIRECTSHEAR_FLD_PRETREATMETHOD,      // 预处理方法 varchar
	enum_str_TBL_INDIRECTSHEAR_FLD_TESTCONTENT,         // 测试内容 varchar
	enum_str_TBL_INDIRECTSHEAR_FLD_PLANEPOSMAP,         // 平面位置示意图 varchar
	enum_str_TBL_INDIRECTSHEAR_FLD_PROFILEMAP,          // 剖面示意图 varchar
	enum_str_TBL_INDIRECTSHEAR_FLD_FIELDIMAGE,          // 野外照片(视频) varchar
	enum_str_TBL_INDIRECTSHEAR_FLD_RECORDCARD,          // 记录卡片(记录) varchar
	enum_str_TBL_INDIRECTSHEAR_FLD_SAMPLEORGN,          // 采样单位 varchar
	enum_str_TBL_INDIRECTSHEAR_FLD_SWFOMW,              // 采样人 varchar
	enum_str_TBL_INDIRECTSHEAR_FLD_GCEABJ,              // 采样日期 date
	enum_str_TBL_INDIRECTSHEAR_FLD_INPUTER,             // 录入员 varchar
	enum_str_TBL_INDIRECTSHEAR_FLD_INPUTORGN,           // 录入单位 varchar
	enum_str_TBL_INDIRECTSHEAR_FLD_INPUTDATE,           // 录入日期 date
	enum_str_TBL_INDIRECTSHEAR_FLD_GCEABD,              // 室内编号 varchar
	enum_str_TBL_INDIRECTSHEAR_FLD_TESTEQUIP,           // 试验仪器 varchar
	enum_str_TBL_INDIRECTSHEAR_FLD_TESTMETHOD,          // 试验方法 varchar
	enum_str_TBL_INDIRECTSHEAR_FLD_TESTBASED,           // 检验依据 varchar
	enum_str_TBL_INDIRECTSHEAR_FLD_GCEAJC,              // 试验单位 varchar
	enum_str_TBL_INDIRECTSHEAR_FLD_SWFGAM,              // 收样日期 date
	enum_str_TBL_INDIRECTSHEAR_FLD_SWFGAN,              // 报告日期 date
	enum_str_TBL_INDIRECTSHEAR_FLD_GCEAJD,              // 校对 varchar
	enum_str_TBL_INDIRECTSHEAR_FLD_AUDITOR,             // 审核 varchar
	enum_str_TBL_INDIRECTSHEAR_FLD_TESTLEADER,          // 试验负责人 varchar
	enum_str_TBL_INDIRECTSHEAR_FLD__REPORT,             // 原始测试分析报告 varchar
	// 动三轴实验成果表
	enum_int_TBL_INDYNAMICTHAXIS_FLD_DYNAMICTHAXISID,  // 动三轴ID int
	enum_double_TBL_INDYNAMICTHAXIS_FLD_TOPDEPTH,      // 取样顶深度 float
	enum_double_TBL_INDYNAMICTHAXIS_FLD_BOTTOMDEPTH,   // 取样底深度 float
	enum_int_TBL_INDYNAMICTHAXIS_FLD_PNTID,            // 点ID int
	enum_str_TBL_INDYNAMICTHAXIS_FLD_SWFGAA,           // 采样层位 varchar
	enum_str_TBL_INDYNAMICTHAXIS_FLD_TCMC,             // 土层名称 varchar
	enum_str_TBL_INDYNAMICTHAXIS_FLD_GEOCODE,          // 地质代号 varchar
	enum_str_TBL_INDYNAMICTHAXIS_FLD_TESTNO,           //  varchar
	enum_str_TBL_INDYNAMICTHAXIS_FLD_TESTCATEGORY,     // 试验类型 varchar
	enum_double_TBL_INDYNAMICTHAXIS_FLD_DGCDKBB,       // 动弹性模量(MPa) float
	enum_double_TBL_INDYNAMICTHAXIS_FLD_DYSHEARMODULE, // 动剪切模量(MPa) float
	enum_double_TBL_INDYNAMICTHAXIS_FLD_DAMPRATIO,     // 阻尼比 float
	enum_double_TBL_INDYNAMICTHAXIS_FLD_DDAMPRATIO,    // 动阻尼比 float
	enum_double_TBL_INDYNAMICTHAXIS_FLD_DGCBFOA,       // 动粘聚力(kPa) float
	enum_double_TBL_INDYNAMICTHAXIS_FLD_DGCDMAC,       // 动内摩擦角(度) float
	enum_str_TBL_INDYNAMICTHAXIS_FLD_GCEABB,           // 样品编号 varchar
	enum_str_TBL_INDYNAMICTHAXIS_FLD_SWBCF,            // 样品类型 varchar
	enum_str_TBL_INDYNAMICTHAXIS_FLD_ISMIXSAMPLE,      // 混合样 varchar
	enum_str_TBL_INDYNAMICTHAXIS_FLD_PNTTYPE,          // 点类型 varchar
	enum_str_TBL_INDYNAMICTHAXIS_FLD_SECONDCODE,       // 样品二次编码 varchar
	enum_double_TBL_INDYNAMICTHAXIS_FLD_SAMPLEVOLUME,  // 样品体积 float
	enum_str_TBL_INDYNAMICTHAXIS_FLD_GCEABM,           // 野外命名 varchar
	enum_double_TBL_INDYNAMICTHAXIS_FLD_GCEAAL,        // 样品重量(kg) float
	enum_str_TBL_INDYNAMICTHAXIS_FLD_SAMPLELENGTH,     // 样品长度(cm) varchar
	enum_str_TBL_INDYNAMICTHAXIS_FLD_PRETREATMETHOD,   // 预处理方法 varchar
	enum_str_TBL_INDYNAMICTHAXIS_FLD_TESTCONTENT,      // 测试内容 varchar
	enum_str_TBL_INDYNAMICTHAXIS_FLD_PLANEPOSMAP,      // 平面位置示意图 varchar
	enum_str_TBL_INDYNAMICTHAXIS_FLD_PROFILEMAP,       // 剖面示意图 varchar
	enum_str_TBL_INDYNAMICTHAXIS_FLD_FIELDIMAGE,       // 野外照片(视频) varchar
	enum_str_TBL_INDYNAMICTHAXIS_FLD_RECORDCARD,       // 记录卡片(记录) varchar
	enum_str_TBL_INDYNAMICTHAXIS_FLD_SAMPLEORGN,       // 采样单位 varchar
	enum_str_TBL_INDYNAMICTHAXIS_FLD_SWFOMW,           // 采样人 varchar
	enum_str_TBL_INDYNAMICTHAXIS_FLD_GCEABJ,           // 采样日期 date
	enum_str_TBL_INDYNAMICTHAXIS_FLD_INPUTER,          // 录入员 varchar
	enum_str_TBL_INDYNAMICTHAXIS_FLD_INPUTORGN,        // 录入单位 varchar
	enum_str_TBL_INDYNAMICTHAXIS_FLD_INPUTDATE,        // 录入日期 date
	enum_str_TBL_INDYNAMICTHAXIS_FLD_GCEABD,           // 室内编号 varchar
	enum_str_TBL_INDYNAMICTHAXIS_FLD_TESTEQUIP,        // 试验仪器 varchar
	enum_str_TBL_INDYNAMICTHAXIS_FLD_TESTMETHOD,       // 试验方法 varchar
	enum_str_TBL_INDYNAMICTHAXIS_FLD_TESTBASED,        // 检验依据 varchar
	enum_str_TBL_INDYNAMICTHAXIS_FLD_GCEAJC,           // 试验单位 varchar
	enum_str_TBL_INDYNAMICTHAXIS_FLD_SWFGAM,           // 收样日期 date
	enum_str_TBL_INDYNAMICTHAXIS_FLD_SWFGAN,           // 报告日期 date
	enum_str_TBL_INDYNAMICTHAXIS_FLD_GCEAJD,           // 校对 varchar
	enum_str_TBL_INDYNAMICTHAXIS_FLD_AUDITOR,          // 审核 varchar
	enum_str_TBL_INDYNAMICTHAXIS_FLD_TESTLEADER,       // 试验负责人 varchar
	enum_str_TBL_INDYNAMICTHAXIS_FLD__REPORT,          // 原始测试分析报告 varchar
	// 岩矿鉴定成果表
	enum_int_TBL_INROCKMINEIDENT_FLD_ROCKMINEIDENTID, // 岩矿鉴定ID int
	enum_double_TBL_INROCKMINEIDENT_FLD_TOPDEPTH,     // 取样顶深度 float
	enum_double_TBL_INROCKMINEIDENT_FLD_BOTTOMDEPTH,  // 取样底深度 float
	enum_int_TBL_INROCKMINEIDENT_FLD_PNTID,           // 点ID int
	enum_str_TBL_INROCKMINEIDENT_FLD_SWFGAA,          // 采样层位 varchar
	enum_str_TBL_INROCKMINEIDENT_FLD_TCMC,            // 土层名称 varchar
	enum_str_TBL_INROCKMINEIDENT_FLD_GEOCODE,         // 地质代号 varchar
	enum_str_TBL_INROCKMINEIDENT_FLD_TESTNO,          //  varchar
	enum_str_TBL_INROCKMINEIDENT_FLD_TESTCATEGORY,    // 试验类型 varchar
	enum_str_TBL_INROCKMINEIDENT_FLD_STRUCTURE,       // 结构 varchar
	enum_str_TBL_INROCKMINEIDENT_FLD_CONSTRUCT,       // 构造 varchar
	enum_str_TBL_INROCKMINEIDENT_FLD_CEMENT,          // 胶结物 varchar
	enum_str_TBL_INROCKMINEIDENT_FLD_IDENTIFICATDESC, // 鉴定描述 varchar
	enum_str_TBL_INROCKMINEIDENT_FLD_INGREDIENT,      // 成份 varchar
	enum_double_TBL_INROCKMINEIDENT_FLD_CONTENT,      // 含量(%) float
	enum_str_TBL_INROCKMINEIDENT_FLD_GCEABB,          // 样品编号 varchar
	enum_str_TBL_INROCKMINEIDENT_FLD_SWBCF,           // 样品类型 varchar
	enum_str_TBL_INROCKMINEIDENT_FLD_ISMIXSAMPLE,     // 混合样 varchar
	enum_str_TBL_INROCKMINEIDENT_FLD_PNTTYPE,         // 点类型 varchar
	enum_str_TBL_INROCKMINEIDENT_FLD_SECONDCODE,      // 样品二次编码 varchar
	enum_double_TBL_INROCKMINEIDENT_FLD_SAMPLEVOLUME, // 样品体积 float
	enum_str_TBL_INROCKMINEIDENT_FLD_GCEABM,          // 野外命名 varchar
	enum_double_TBL_INROCKMINEIDENT_FLD_GCEAAL,       // 样品重量(kg) float
	enum_str_TBL_INROCKMINEIDENT_FLD_SAMPLELENGTH,    // 样品长度(cm) varchar
	enum_str_TBL_INROCKMINEIDENT_FLD_PRETREATMETHOD,  // 预处理方法 varchar
	enum_str_TBL_INROCKMINEIDENT_FLD_TESTCONTENT,     // 测试内容 varchar
	enum_str_TBL_INROCKMINEIDENT_FLD_PLANEPOSMAP,     // 平面位置示意图 varchar
	enum_str_TBL_INROCKMINEIDENT_FLD_PROFILEMAP,      // 剖面示意图 varchar
	enum_str_TBL_INROCKMINEIDENT_FLD_FIELDIMAGE,      // 野外照片(视频) varchar
	enum_str_TBL_INROCKMINEIDENT_FLD_RECORDCARD,      // 记录卡片(记录) varchar
	enum_str_TBL_INROCKMINEIDENT_FLD_SAMPLEORGN,      // 采样单位 varchar
	enum_str_TBL_INROCKMINEIDENT_FLD_SWFOMW,          // 采样人 varchar
	enum_str_TBL_INROCKMINEIDENT_FLD_GCEABJ,          // 采样日期 date
	enum_str_TBL_INROCKMINEIDENT_FLD_INPUTER,         // 录入员 varchar
	enum_str_TBL_INROCKMINEIDENT_FLD_INPUTORGN,       // 录入单位 varchar
	enum_str_TBL_INROCKMINEIDENT_FLD_INPUTDATE,       // 录入日期 date
	enum_str_TBL_INROCKMINEIDENT_FLD_GCEABD,          // 室内编号 varchar
	enum_str_TBL_INROCKMINEIDENT_FLD_INDOORNAME,      // 室内名称 varchar
	enum_str_TBL_INROCKMINEIDENT_FLD_TESTEQUIP,       // 试验仪器 varchar
	enum_str_TBL_INROCKMINEIDENT_FLD_TESTMETHOD,      // 试验方法 varchar
	enum_str_TBL_INROCKMINEIDENT_FLD_TESTBASED,       // 检验依据 varchar
	enum_str_TBL_INROCKMINEIDENT_FLD_GCEAJC,          // 试验单位 varchar
	enum_str_TBL_INROCKMINEIDENT_FLD_SWFGAM,          // 收样日期 date
	enum_str_TBL_INROCKMINEIDENT_FLD_SWFGAN,          // 报告日期 date
	enum_str_TBL_INROCKMINEIDENT_FLD_GCEAJD,          // 校对 varchar
	enum_str_TBL_INROCKMINEIDENT_FLD_AUDITOR,         // 审核 varchar
	enum_str_TBL_INROCKMINEIDENT_FLD_TESTLEADER,      // 试验负责人 varchar
	enum_str_TBL_INROCKMINEIDENT_FLD__REPORT,         // 原始测试分析报告 varchar
	// 粘土（全岩）矿物鉴定成果表
	enum_int_TBL_INCLAYMINERALIDENT_FLD_CLAYMINERALID,      // 粘土矿物ID int
	enum_double_TBL_INCLAYMINERALIDENT_FLD_TOPDEPTH,        // 取样顶深度 float
	enum_double_TBL_INCLAYMINERALIDENT_FLD_BOTTOMDEPTH,     // 取样底深度 float
	enum_int_TBL_INCLAYMINERALIDENT_FLD_PNTID,              // 点ID int
	enum_str_TBL_INCLAYMINERALIDENT_FLD_SWFGAA,             // 采样层位 varchar
	enum_str_TBL_INCLAYMINERALIDENT_FLD_TCMC,               // 土层名称 varchar
	enum_str_TBL_INCLAYMINERALIDENT_FLD_GEOCODE,            // 地质代号 varchar
	enum_str_TBL_INCLAYMINERALIDENT_FLD_TESTNO,             //  varchar
	enum_str_TBL_INCLAYMINERALIDENT_FLD_TESTCATEGORY,       // 试验类型 varchar
	enum_double_TBL_INCLAYMINERALIDENT_FLD_QUARTZ,          // 石英(%) float
	enum_double_TBL_INCLAYMINERALIDENT_FLD_POTASHFELDSPAR,  // 钾长石(%) float
	enum_double_TBL_INCLAYMINERALIDENT_FLD_PLAGIOCLASE,     // 斜长石(%) float
	enum_double_TBL_INCLAYMINERALIDENT_FLD_CALCITE,         // 方解石(%) float
	enum_double_TBL_INCLAYMINERALIDENT_FLD_ROCKSALT,        // 石盐(%) float
	enum_double_TBL_INCLAYMINERALIDENT_FLD_HORNBLENDE,      // 角闪石(%) float
	enum_double_TBL_INCLAYMINERALIDENT_FLD_CLAYMINERAL,     // 粘土矿物(%) float
	enum_double_TBL_INCLAYMINERALIDENT_FLD_SMECTITE,        // 蒙皂石(%) float
	enum_double_TBL_INCLAYMINERALIDENT_FLD_ISMIXEDMINERAL,  // I/S混层矿物(%) float
	enum_double_TBL_INCLAYMINERALIDENT_FLD_SWHABO,          // 伊利石(%) float
	enum_double_TBL_INCLAYMINERALIDENT_FLD_SWHABP,          // 高岭石(%) float
	enum_double_TBL_INCLAYMINERALIDENT_FLD_SWHAAX,          // 绿泥石(%) float
	enum_double_TBL_INCLAYMINERALIDENT_FLD_ISMIXLAYERRATIO, // 混层比I/S float
	enum_double_TBL_INCLAYMINERALIDENT_FLD_CSMIXLAYERRATIO, // 混层比C/S float
	enum_str_TBL_INCLAYMINERALIDENT_FLD_GCEABB,             // 样品编号 varchar
	enum_str_TBL_INCLAYMINERALIDENT_FLD_SWBCF,              // 样品类型 varchar
	enum_str_TBL_INCLAYMINERALIDENT_FLD_ISMIXSAMPLE,        // 混合样 varchar
	enum_str_TBL_INCLAYMINERALIDENT_FLD_PNTTYPE,            // 点类型 varchar
	enum_str_TBL_INCLAYMINERALIDENT_FLD_SECONDCODE,         // 样品二次编码 varchar
	enum_double_TBL_INCLAYMINERALIDENT_FLD_SAMPLEVOLUME,    // 样品体积 float
	enum_str_TBL_INCLAYMINERALIDENT_FLD_GCEABM,             // 野外命名 varchar
	enum_double_TBL_INCLAYMINERALIDENT_FLD_GCEAAL,          // 样品重量(kg) float
	enum_str_TBL_INCLAYMINERALIDENT_FLD_SAMPLELENGTH,       // 样品长度(cm) varchar
	enum_str_TBL_INCLAYMINERALIDENT_FLD_PRETREATMETHOD,     // 预处理方法 varchar
	enum_str_TBL_INCLAYMINERALIDENT_FLD_TESTCONTENT,        // 测试内容 varchar
	enum_str_TBL_INCLAYMINERALIDENT_FLD_PLANEPOSMAP,        // 平面位置示意图 varchar
	enum_str_TBL_INCLAYMINERALIDENT_FLD_PROFILEMAP,         // 剖面示意图 varchar
	enum_str_TBL_INCLAYMINERALIDENT_FLD_FIELDIMAGE,         // 野外照片(视频) varchar
	enum_str_TBL_INCLAYMINERALIDENT_FLD_RECORDCARD,         // 记录卡片(记录) varchar
	enum_str_TBL_INCLAYMINERALIDENT_FLD_SAMPLEORGN,         // 采样单位 varchar
	enum_str_TBL_INCLAYMINERALIDENT_FLD_SWFOMW,             // 采样人 varchar
	enum_str_TBL_INCLAYMINERALIDENT_FLD_GCEABJ,             // 采样日期 date
	enum_str_TBL_INCLAYMINERALIDENT_FLD_INPUTER,            // 录入员 varchar
	enum_str_TBL_INCLAYMINERALIDENT_FLD_INPUTORGN,          // 录入单位 varchar
	enum_str_TBL_INCLAYMINERALIDENT_FLD_INPUTDATE,          // 录入日期 date
	enum_str_TBL_INCLAYMINERALIDENT_FLD_GCEABD,             // 室内编号 varchar
	enum_str_TBL_INCLAYMINERALIDENT_FLD_TESTEQUIP,          // 试验仪器 varchar
	enum_str_TBL_INCLAYMINERALIDENT_FLD_TESTMETHOD,         // 试验方法 varchar
	enum_str_TBL_INCLAYMINERALIDENT_FLD_TESTBASED,          // 检验依据 varchar
	enum_str_TBL_INCLAYMINERALIDENT_FLD_GCEAJC,             // 试验单位 varchar
	enum_str_TBL_INCLAYMINERALIDENT_FLD_SWFGAM,             // 收样日期 date
	enum_str_TBL_INCLAYMINERALIDENT_FLD_SWFGAN,             // 报告日期 date
	enum_str_TBL_INCLAYMINERALIDENT_FLD_GCEAJD,             // 校对 varchar
	enum_str_TBL_INCLAYMINERALIDENT_FLD_AUDITOR,            // 审核 varchar
	enum_str_TBL_INCLAYMINERALIDENT_FLD_TESTLEADER,         // 试验负责人 varchar
	enum_str_TBL_INCLAYMINERALIDENT_FLD__REPORT,            // 原始测试分析报告 varchar
	// 粒度分析成果表
	enum_int_TBL_INGRANULARITYIDENT_FLD_GRANULARITYID,   // 粒度ID int
	enum_double_TBL_INGRANULARITYIDENT_FLD_TOPDEPTH,     // 取样顶深度 float
	enum_double_TBL_INGRANULARITYIDENT_FLD_BOTTOMDEPTH,  // 取样底深度 float
	enum_int_TBL_INGRANULARITYIDENT_FLD_PNTID,           // 点ID int
	enum_str_TBL_INGRANULARITYIDENT_FLD_SWFGAA,          // 采样层位 varchar
	enum_str_TBL_INGRANULARITYIDENT_FLD_TCMC,            // 土层名称 varchar
	enum_str_TBL_INGRANULARITYIDENT_FLD_GEOCODE,         // 地质代号 varchar
	enum_str_TBL_INGRANULARITYIDENT_FLD_TESTNO,          //  varchar
	enum_str_TBL_INGRANULARITYIDENT_FLD_TESTCATEGORY,    // 试验类型 varchar
	enum_double_TBL_INGRANULARITYIDENT_FLD__CONTENT,     // 含量 float
	enum_double_TBL_INGRANULARITYIDENT_FLD_GCCABB,       // 砾石 float
	enum_double_TBL_INGRANULARITYIDENT_FLD_GCCABC,       // 砂(%) float
	enum_double_TBL_INGRANULARITYIDENT_FLD_GCCABD,       // 粉砂(%) float
	enum_double_TBL_INGRANULARITYIDENT_FLD_GCCABE,       // 粘土(%) float
	enum_double_TBL_INGRANULARITYIDENT_FLD_GCCABG,       // 平均粒径 float
	enum_double_TBL_INGRANULARITYIDENT_FLD_GCCABH,       // 分选系数 float
	enum_double_TBL_INGRANULARITYIDENT_FLD_GCCABI,       // 偏态 float
	enum_double_TBL_INGRANULARITYIDENT_FLD_GCCABJ,       // 峰态 float
	enum_double_TBL_INGRANULARITYIDENT_FLD_GCCABF,       // 中值粒径 float
	enum_str_TBL_INGRANULARITYIDENT_FLD_SEDIMENTTYPE,    // 沉积物分类 varchar
	enum_str_TBL_INGRANULARITYIDENT_FLD_GCEABB,          // 样品编号 varchar
	enum_str_TBL_INGRANULARITYIDENT_FLD_SWBCF,           // 样品类型 varchar
	enum_str_TBL_INGRANULARITYIDENT_FLD_ISMIXSAMPLE,     // 混合样 varchar
	enum_str_TBL_INGRANULARITYIDENT_FLD_PNTTYPE,         // 点类型 varchar
	enum_str_TBL_INGRANULARITYIDENT_FLD_SECONDCODE,      // 样品二次编码 varchar
	enum_double_TBL_INGRANULARITYIDENT_FLD_SAMPLEVOLUME, // 样品体积 float
	enum_str_TBL_INGRANULARITYIDENT_FLD_GCEABM,          // 野外命名 varchar
	enum_double_TBL_INGRANULARITYIDENT_FLD_GCEAAL,       // 样品重量(kg) float
	enum_str_TBL_INGRANULARITYIDENT_FLD_SAMPLELENGTH,    // 样品长度(cm) varchar
	enum_str_TBL_INGRANULARITYIDENT_FLD_PRETREATMETHOD,  // 预处理方法 varchar
	enum_str_TBL_INGRANULARITYIDENT_FLD_TESTCONTENT,     // 测试内容 varchar
	enum_str_TBL_INGRANULARITYIDENT_FLD_PLANEPOSMAP,     // 平面位置示意图 varchar
	enum_str_TBL_INGRANULARITYIDENT_FLD_PROFILEMAP,      // 剖面示意图 varchar
	enum_str_TBL_INGRANULARITYIDENT_FLD_FIELDIMAGE,      // 野外照片(视频) varchar
	enum_str_TBL_INGRANULARITYIDENT_FLD_RECORDCARD,      // 记录卡片(记录) varchar
	enum_str_TBL_INGRANULARITYIDENT_FLD_SAMPLEORGN,      // 采样单位 varchar
	enum_str_TBL_INGRANULARITYIDENT_FLD_SWFOMW,          // 采样人 varchar
	enum_str_TBL_INGRANULARITYIDENT_FLD_GCEABJ,          // 采样日期 date
	enum_str_TBL_INGRANULARITYIDENT_FLD_INPUTER,         // 录入员 varchar
	enum_str_TBL_INGRANULARITYIDENT_FLD_INPUTORGN,       // 录入单位 varchar
	enum_str_TBL_INGRANULARITYIDENT_FLD_INPUTDATE,       // 录入日期 date
	enum_str_TBL_INGRANULARITYIDENT_FLD_GCEABD,          // 室内编号 varchar
	enum_str_TBL_INGRANULARITYIDENT_FLD_TESTEQUIP,       // 试验仪器 varchar
	enum_str_TBL_INGRANULARITYIDENT_FLD_TESTMETHOD,      // 试验方法 varchar
	enum_str_TBL_INGRANULARITYIDENT_FLD_TESTBASED,       // 检验依据 varchar
	enum_str_TBL_INGRANULARITYIDENT_FLD_GCEAJC,          // 试验单位 varchar
	enum_str_TBL_INGRANULARITYIDENT_FLD_SWFGAM,          // 收样日期 date
	enum_str_TBL_INGRANULARITYIDENT_FLD_SWFGAN,          // 报告日期 date
	enum_str_TBL_INGRANULARITYIDENT_FLD_GCEAJD,          // 校对 varchar
	enum_str_TBL_INGRANULARITYIDENT_FLD_AUDITOR,         // 审核 varchar
	enum_str_TBL_INGRANULARITYIDENT_FLD_TESTLEADER,      // 试验负责人 varchar
	enum_str_TBL_INGRANULARITYIDENT_FLD__REPORT,         // 原始测试分析报告 varchar
	// 热物性实验成果表
	enum_int_TBL_INTHERMOPHYSICAL_FLD_THERMOPHYSICALID, // 热物性ID int
	enum_double_TBL_INTHERMOPHYSICAL_FLD_TOPDEPTH,      // 取样顶深度 float
	enum_double_TBL_INTHERMOPHYSICAL_FLD_BOTTOMDEPTH,   // 取样底深度 float
	enum_int_TBL_INTHERMOPHYSICAL_FLD_PNTID,            // 点ID int
	enum_str_TBL_INTHERMOPHYSICAL_FLD_SWFGAA,           // 采样层位 varchar
	enum_str_TBL_INTHERMOPHYSICAL_FLD_TCMC,             // 土层名称 varchar
	enum_str_TBL_INTHERMOPHYSICAL_FLD_GEOCODE,          // 地质代号 varchar
	enum_str_TBL_INTHERMOPHYSICAL_FLD_TESTNO,           //  varchar
	enum_str_TBL_INTHERMOPHYSICAL_FLD_TESTCATEGORY,     // 试验类型 varchar
	enum_double_TBL_INTHERMOPHYSICAL_FLD_GCDGAF,        // 导热系数 float
	enum_double_TBL_INTHERMOPHYSICAL_FLD_GCDGAE,        // 比热(J/(kg℃)) float
	enum_double_TBL_INTHERMOPHYSICAL_FLD_SWDEAH,        // 热扩散系数 float
	enum_double_TBL_INTHERMOPHYSICAL_FLD_SYEFAB,        // 自然密度(g/cm3) float
	enum_double_TBL_INTHERMOPHYSICAL_FLD_GCDCAO,        // 含水率(%) float
	enum_double_TBL_INTHERMOPHYSICAL_FLD_GCDBB,         // 孔隙率(%) float
	enum_double_TBL_INTHERMOPHYSICAL_FLD_DHABCU,        // 饱和度(%) float
	enum_str_TBL_INTHERMOPHYSICAL_FLD_GCEABD,           // 室内编号 varchar
	enum_str_TBL_INTHERMOPHYSICAL_FLD_TESTEQUIP,        // 试验仪器 varchar
	enum_str_TBL_INTHERMOPHYSICAL_FLD_TESTMETHOD,       // 试验方法 varchar
	enum_str_TBL_INTHERMOPHYSICAL_FLD_TESTBASED,        // 检验依据 varchar
	enum_str_TBL_INTHERMOPHYSICAL_FLD_GCEAJC,           // 试验单位 varchar
	enum_str_TBL_INTHERMOPHYSICAL_FLD_SWFGAM,           // 收样日期 date
	enum_str_TBL_INTHERMOPHYSICAL_FLD_SWFGAN,           // 报告日期 date
	enum_str_TBL_INTHERMOPHYSICAL_FLD_GCEAJD,           // 校对 varchar
	enum_str_TBL_INTHERMOPHYSICAL_FLD_AUDITOR,          // 审核 varchar
	enum_str_TBL_INTHERMOPHYSICAL_FLD_TESTLEADER,       // 试验负责人 varchar
	enum_str_TBL_INTHERMOPHYSICAL_FLD__REPORT,          // 原始测试分析报告 varchar
	enum_str_TBL_INTHERMOPHYSICAL_FLD_GCEABB,           // 样品编号 varchar
	enum_str_TBL_INTHERMOPHYSICAL_FLD_SWBCF,            // 样品类型 varchar
	enum_str_TBL_INTHERMOPHYSICAL_FLD_ISMIXSAMPLE,      // 混合样 varchar
	enum_str_TBL_INTHERMOPHYSICAL_FLD_PNTTYPE,          // 点类型 varchar
	enum_str_TBL_INTHERMOPHYSICAL_FLD_SECONDCODE,       // 样品二次编码 varchar
	enum_double_TBL_INTHERMOPHYSICAL_FLD_SAMPLEVOLUME,  // 样品体积 float
	enum_str_TBL_INTHERMOPHYSICAL_FLD_GCEABM,           // 野外命名 varchar
	enum_double_TBL_INTHERMOPHYSICAL_FLD_GCEAAL,        // 样品重量(kg) float
	enum_str_TBL_INTHERMOPHYSICAL_FLD_SAMPLELENGTH,     // 样品长度(cm) varchar
	enum_str_TBL_INTHERMOPHYSICAL_FLD_PRETREATMETHOD,   // 预处理方法 varchar
	enum_str_TBL_INTHERMOPHYSICAL_FLD_TESTCONTENT,      // 测试内容 varchar
	enum_str_TBL_INTHERMOPHYSICAL_FLD_PLANEPOSMAP,      // 平面位置示意图 varchar
	enum_str_TBL_INTHERMOPHYSICAL_FLD_PROFILEMAP,       // 剖面示意图 varchar
	enum_str_TBL_INTHERMOPHYSICAL_FLD_FIELDIMAGE,       // 野外照片(视频) varchar
	enum_str_TBL_INTHERMOPHYSICAL_FLD_RECORDCARD,       // 记录卡片(记录) varchar
	enum_str_TBL_INTHERMOPHYSICAL_FLD_SAMPLEORGN,       // 采样单位 varchar
	enum_str_TBL_INTHERMOPHYSICAL_FLD_SWFOMW,           // 采样人 varchar
	enum_str_TBL_INTHERMOPHYSICAL_FLD_GCEABJ,           // 采样日期 date
	enum_str_TBL_INTHERMOPHYSICAL_FLD_INPUTER,          // 录入员 varchar
	enum_str_TBL_INTHERMOPHYSICAL_FLD_INPUTORGN,        // 录入单位 varchar
	enum_str_TBL_INTHERMOPHYSICAL_FLD_INPUTDATE,        // 录入日期 date
	// 同位素测年成果表
	enum_int_TBL_INISOTOPE_FLD_IsotopeID,       // 同位素ID int
	enum_double_TBL_INISOTOPE_FLD_TOPDEPTH,     // 取样顶深度 float
	enum_double_TBL_INISOTOPE_FLD_BOTTOMDEPTH,  // 取样底深度 float
	enum_int_TBL_INISOTOPE_FLD_PNTID,           // 点ID int
	enum_str_TBL_INISOTOPE_FLD_SWFGAA,          // 采样层位 varchar
	enum_str_TBL_INISOTOPE_FLD_TCMC,            // 土层名称 varchar
	enum_str_TBL_INISOTOPE_FLD_GEOCODE,         // 地质代号 varchar
	enum_str_TBL_INISOTOPE_FLD_TESTNO,          //  varchar
	enum_str_TBL_INISOTOPE_FLD_TESTCATEGORY,    // 试验类型 varchar
	enum_str_TBL_INISOTOPE_FLD_Isotope,         // 同位素 varchar
	enum_double_TBL_INISOTOPE_FLD_YJDCBH,       // 丰度 float
	enum_int_TBL_INISOTOPE_FLD_TestAge,         // 测试年龄 int
	enum_str_TBL_INISOTOPE_FLD_AgeUnit,         // 年龄单位 varchar
	enum_str_TBL_INISOTOPE_FLD_GCEABD,          // 室内编号 varchar
	enum_str_TBL_INISOTOPE_FLD_TESTEQUIP,       // 试验仪器 varchar
	enum_str_TBL_INISOTOPE_FLD_TESTMETHOD,      // 试验方法 varchar
	enum_str_TBL_INISOTOPE_FLD_TESTBASED,       // 检验依据 varchar
	enum_str_TBL_INISOTOPE_FLD_GCEAJC,          // 试验单位 varchar
	enum_str_TBL_INISOTOPE_FLD_SWFGAM,          // 收样日期 date
	enum_str_TBL_INISOTOPE_FLD_SWFGAN,          // 报告日期 date
	enum_str_TBL_INISOTOPE_FLD_GCEAJD,          // 校对 varchar
	enum_str_TBL_INISOTOPE_FLD_AUDITOR,         // 审核 varchar
	enum_str_TBL_INISOTOPE_FLD_TESTLEADER,      // 试验负责人 varchar
	enum_str_TBL_INISOTOPE_FLD__REPORT,         // 原始测试分析报告 varchar
	enum_str_TBL_INISOTOPE_FLD_GCEABB,          // 样品编号 varchar
	enum_str_TBL_INISOTOPE_FLD_SWBCF,           // 样品类型 varchar
	enum_str_TBL_INISOTOPE_FLD_ISMIXSAMPLE,     // 混合样 varchar
	enum_str_TBL_INISOTOPE_FLD_PNTTYPE,         // 点类型 varchar
	enum_str_TBL_INISOTOPE_FLD_SECONDCODE,      // 样品二次编码 varchar
	enum_double_TBL_INISOTOPE_FLD_SAMPLEVOLUME, // 样品体积 float
	enum_str_TBL_INISOTOPE_FLD_GCEABM,          // 野外命名 varchar
	enum_double_TBL_INISOTOPE_FLD_GCEAAL,       // 样品重量(kg) float
	enum_str_TBL_INISOTOPE_FLD_SAMPLELENGTH,    // 样品长度(cm) varchar
	enum_str_TBL_INISOTOPE_FLD_PRETREATMETHOD,  // 预处理方法 varchar
	enum_str_TBL_INISOTOPE_FLD_TESTCONTENT,     // 测试内容 varchar
	enum_str_TBL_INISOTOPE_FLD_PLANEPOSMAP,     // 平面位置示意图 varchar
	enum_str_TBL_INISOTOPE_FLD_PROFILEMAP,      // 剖面示意图 varchar
	enum_str_TBL_INISOTOPE_FLD_FIELDIMAGE,      // 野外照片(视频) varchar
	enum_str_TBL_INISOTOPE_FLD_RECORDCARD,      // 记录卡片(记录) varchar
	enum_str_TBL_INISOTOPE_FLD_SAMPLEORGN,      // 采样单位 varchar
	enum_str_TBL_INISOTOPE_FLD_SWFOMW,          // 采样人 varchar
	enum_str_TBL_INISOTOPE_FLD_GCEABJ,          // 采样日期 date
	enum_str_TBL_INISOTOPE_FLD_INPUTER,         // 录入员 varchar
	enum_str_TBL_INISOTOPE_FLD_INPUTORGN,       // 录入单位 varchar
	enum_str_TBL_INISOTOPE_FLD_INPUTDATE,       // 录入日期 date
	// 释光测年成果表
	enum_int_TBL_INLUMINESCENCE_FLD_LUMINESCENCEID,  // 释光ID int
	enum_double_TBL_INLUMINESCENCE_FLD_TOPDEPTH,     // 取样顶深度 float
	enum_double_TBL_INLUMINESCENCE_FLD_BOTTOMDEPTH,  // 取样底深度 float
	enum_int_TBL_INLUMINESCENCE_FLD_PNTID,           // 点ID int
	enum_str_TBL_INLUMINESCENCE_FLD_SWFGAA,          // 采样层位 varchar
	enum_str_TBL_INLUMINESCENCE_FLD_TCMC,            // 土层名称 varchar
	enum_str_TBL_INLUMINESCENCE_FLD_GEOCODE,         // 地质代号 varchar
	enum_str_TBL_INLUMINESCENCE_FLD_TESTNO,          //  varchar
	enum_str_TBL_INLUMINESCENCE_FLD_TESTCATEGORY,    // 试验类型 varchar
	enum_str_TBL_INLUMINESCENCE_FLD_DATEMETHOD,      // 测年方法 varchar
	enum_int_TBL_INLUMINESCENCE_FLD_TESTAGE,         // 测试年龄 int
	enum_str_TBL_INLUMINESCENCE_FLD_AGEUNIT,         // 年龄单位 varchar
	enum_str_TBL_INLUMINESCENCE_FLD_MEMO,            // 备注 varchar
	enum_str_TBL_INLUMINESCENCE_FLD_GCEABB,          // 样品编号 varchar
	enum_str_TBL_INLUMINESCENCE_FLD_SWBCF,           // 样品类型 varchar
	enum_str_TBL_INLUMINESCENCE_FLD_ISMIXSAMPLE,     // 混合样 varchar
	enum_str_TBL_INLUMINESCENCE_FLD_PNTTYPE,         // 点类型 varchar
	enum_str_TBL_INLUMINESCENCE_FLD_SECONDCODE,      // 样品二次编码 varchar
	enum_double_TBL_INLUMINESCENCE_FLD_SAMPLEVOLUME, // 样品体积 float
	enum_str_TBL_INLUMINESCENCE_FLD_GCEABM,          // 野外命名 varchar
	enum_double_TBL_INLUMINESCENCE_FLD_GCEAAL,       // 样品重量(kg) float
	enum_str_TBL_INLUMINESCENCE_FLD_SAMPLELENGTH,    // 样品长度(cm) varchar
	enum_str_TBL_INLUMINESCENCE_FLD_PRETREATMETHOD,  // 预处理方法 varchar
	enum_str_TBL_INLUMINESCENCE_FLD_TESTCONTENT,     // 测试内容 varchar
	enum_str_TBL_INLUMINESCENCE_FLD_PLANEPOSMAP,     // 平面位置示意图 varchar
	enum_str_TBL_INLUMINESCENCE_FLD_PROFILEMAP,      // 剖面示意图 varchar
	enum_str_TBL_INLUMINESCENCE_FLD_FIELDIMAGE,      // 野外照片(视频) varchar
	enum_str_TBL_INLUMINESCENCE_FLD_RECORDCARD,      // 记录卡片(记录) varchar
	enum_str_TBL_INLUMINESCENCE_FLD_SAMPLEORGN,      // 采样单位 varchar
	enum_str_TBL_INLUMINESCENCE_FLD_SWFOMW,          // 采样人 varchar
	enum_str_TBL_INLUMINESCENCE_FLD_GCEABJ,          // 采样日期 date
	enum_str_TBL_INLUMINESCENCE_FLD_INPUTER,         // 录入员 varchar
	enum_str_TBL_INLUMINESCENCE_FLD_INPUTORGN,       // 录入单位 varchar
	enum_str_TBL_INLUMINESCENCE_FLD_INPUTDATE,       // 录入日期 date
	enum_str_TBL_INLUMINESCENCE_FLD_GCEABD,          // 室内编号 varchar
	enum_str_TBL_INLUMINESCENCE_FLD_TESTEQUIP,       // 试验仪器 varchar
	enum_str_TBL_INLUMINESCENCE_FLD_TESTMETHOD,      // 试验方法 varchar
	enum_str_TBL_INLUMINESCENCE_FLD_TESTBASED,       // 检验依据 varchar
	enum_str_TBL_INLUMINESCENCE_FLD_GCEAJC,          // 试验单位 varchar
	enum_str_TBL_INLUMINESCENCE_FLD_SWFGAM,          // 收样日期 date
	enum_str_TBL_INLUMINESCENCE_FLD_SWFGAN,          // 报告日期 date
	enum_str_TBL_INLUMINESCENCE_FLD_GCEAJD,          // 校对 varchar
	enum_str_TBL_INLUMINESCENCE_FLD_AUDITOR,         // 审核 varchar
	enum_str_TBL_INLUMINESCENCE_FLD_TESTLEADER,      // 试验负责人 varchar
	enum_str_TBL_INLUMINESCENCE_FLD__REPORT,         // 原始测试分析报告 varchar
	// 孢粉组合表
	enum_int_TBL_INPOLLENCOMBINAT_FLD_POLLENCOMBINATID, // 孢粉组合ID int
	enum_double_TBL_INPOLLENCOMBINAT_FLD_TOPDEPTH,      // 取样顶深度 float
	enum_double_TBL_INPOLLENCOMBINAT_FLD_BOTTOMDEPTH,   // 取样底深度 float
	enum_int_TBL_INPOLLENCOMBINAT_FLD_PNTID,            // 点ID int
	enum_str_TBL_INPOLLENCOMBINAT_FLD_SWFGAA,           // 采样层位 varchar
	enum_str_TBL_INPOLLENCOMBINAT_FLD_TCMC,             // 土层名称 varchar
	enum_str_TBL_INPOLLENCOMBINAT_FLD_GEOCODE,          // 地质代号 varchar
	enum_str_TBL_INPOLLENCOMBINAT_FLD_TESTNO,           //  varchar
	enum_str_TBL_INPOLLENCOMBINAT_FLD_TESTCATEGORY,     // 试验类型 varchar
	enum_str_TBL_INPOLLENCOMBINAT_FLD_POLLENCOMBINAT,   // 孢粉组合 varchar
	enum_str_TBL_INPOLLENCOMBINAT_FLD_CLIMATECHARACTER, // 古植被古气候特征 varchar
	enum_str_TBL_INPOLLENCOMBINAT_FLD_DDCDIA,           // 地质时代 varchar
	enum_str_TBL_INPOLLENCOMBINAT_FLD_PLANTNAME,        // 植物名称 varchar
	enum_int_TBL_INPOLLENCOMBINAT_FLD_GRAINNUM,         // 粒数 int
	enum_double_TBL_INPOLLENCOMBINAT_FLD_CONTENT,       // 含量 float
	enum_str_TBL_INPOLLENCOMBINAT_FLD_GCEABB,           // 样品编号 varchar
	enum_str_TBL_INPOLLENCOMBINAT_FLD_SWBCF,            // 样品类型 varchar
	enum_str_TBL_INPOLLENCOMBINAT_FLD_ISMIXSAMPLE,      // 混合样 varchar
	enum_str_TBL_INPOLLENCOMBINAT_FLD_PNTTYPE,          // 点类型 varchar
	enum_str_TBL_INPOLLENCOMBINAT_FLD_SECONDCODE,       // 样品二次编码 varchar
	enum_double_TBL_INPOLLENCOMBINAT_FLD_SAMPLEVOLUME,  // 样品体积 float
	enum_str_TBL_INPOLLENCOMBINAT_FLD_GCEABM,           // 野外命名 varchar
	enum_double_TBL_INPOLLENCOMBINAT_FLD_GCEAAL,        // 样品重量(kg) float
	enum_str_TBL_INPOLLENCOMBINAT_FLD_SAMPLELENGTH,     // 样品长度(cm) varchar
	enum_str_TBL_INPOLLENCOMBINAT_FLD_PRETREATMETHOD,   // 预处理方法 varchar
	enum_str_TBL_INPOLLENCOMBINAT_FLD_TESTCONTENT,      // 测试内容 varchar
	enum_str_TBL_INPOLLENCOMBINAT_FLD_PLANEPOSMAP,      // 平面位置示意图 varchar
	enum_str_TBL_INPOLLENCOMBINAT_FLD_PROFILEMAP,       // 剖面示意图 varchar
	enum_str_TBL_INPOLLENCOMBINAT_FLD_FIELDIMAGE,       // 野外照片(视频) varchar
	enum_str_TBL_INPOLLENCOMBINAT_FLD_RECORDCARD,       // 记录卡片(记录) varchar
	enum_str_TBL_INPOLLENCOMBINAT_FLD_SAMPLEORGN,       // 采样单位 varchar
	enum_str_TBL_INPOLLENCOMBINAT_FLD_SWFOMW,           // 采样人 varchar
	enum_str_TBL_INPOLLENCOMBINAT_FLD_GCEABJ,           // 采样日期 date
	enum_str_TBL_INPOLLENCOMBINAT_FLD_INPUTER,          // 录入员 varchar
	enum_str_TBL_INPOLLENCOMBINAT_FLD_INPUTORGN,        // 录入单位 varchar
	enum_str_TBL_INPOLLENCOMBINAT_FLD_INPUTDATE,        // 录入日期 date
	enum_str_TBL_INPOLLENCOMBINAT_FLD_GCEABD,           // 室内编号 varchar
	enum_str_TBL_INPOLLENCOMBINAT_FLD_TESTEQUIP,        // 试验仪器 varchar
	enum_str_TBL_INPOLLENCOMBINAT_FLD_TESTMETHOD,       // 试验方法 varchar
	enum_str_TBL_INPOLLENCOMBINAT_FLD_TESTBASED,        // 检验依据 varchar
	enum_str_TBL_INPOLLENCOMBINAT_FLD_GCEAJC,           // 试验单位 varchar
	enum_str_TBL_INPOLLENCOMBINAT_FLD_SWFGAM,           // 收样日期 date
	enum_str_TBL_INPOLLENCOMBINAT_FLD_SWFGAN,           // 报告日期 date
	enum_str_TBL_INPOLLENCOMBINAT_FLD_GCEAJD,           // 校对 varchar
	enum_str_TBL_INPOLLENCOMBINAT_FLD_AUDITOR,          // 审核 varchar
	enum_str_TBL_INPOLLENCOMBINAT_FLD_TESTLEADER,       // 试验负责人 varchar
	enum_str_TBL_INPOLLENCOMBINAT_FLD__REPORT,          // 原始测试分析报告 varchar
	// 化石组合表
	enum_int_TBL_INFOSSILCOMBINAT_FLD_FOSSILCOMBINATID, // 化石组合ID int
	enum_double_TBL_INFOSSILCOMBINAT_FLD_TOPDEPTH,      // 取样顶深度 float
	enum_double_TBL_INFOSSILCOMBINAT_FLD_BOTTOMDEPTH,   // 取样底深度 float
	enum_int_TBL_INFOSSILCOMBINAT_FLD_PNTID,            // 点ID int
	enum_str_TBL_INFOSSILCOMBINAT_FLD_SWFGAA,           // 采样层位 varchar
	enum_str_TBL_INFOSSILCOMBINAT_FLD_TCMC,             // 土层名称 varchar
	enum_str_TBL_INFOSSILCOMBINAT_FLD_GEOCODE,          // 地质代号 varchar
	enum_str_TBL_INFOSSILCOMBINAT_FLD_TESTNO,           //  varchar
	enum_str_TBL_INFOSSILCOMBINAT_FLD_TESTCATEGORY,     // 试验类型 varchar
	enum_str_TBL_INFOSSILCOMBINAT_FLD_FOSSILCOMBINAT,   // 化石组合 varchar
	enum_str_TBL_INFOSSILCOMBINAT_FLD_CLIMATECHARACTER, // 古化石古气候特征 varchar
	enum_str_TBL_INFOSSILCOMBINAT_FLD_DDCDIA,           // 地质时代 varchar
	enum_str_TBL_INFOSSILCOMBINAT_FLD_GCEABB,           // 样品编号 varchar
	enum_str_TBL_INFOSSILCOMBINAT_FLD_SWBCF,            // 样品类型 varchar
	enum_str_TBL_INFOSSILCOMBINAT_FLD_ISMIXSAMPLE,      // 混合样 varchar
	enum_str_TBL_INFOSSILCOMBINAT_FLD_PNTTYPE,          // 点类型 varchar
	enum_str_TBL_INFOSSILCOMBINAT_FLD_SECONDCODE,       // 样品二次编码 varchar
	enum_double_TBL_INFOSSILCOMBINAT_FLD_SAMPLEVOLUME,  // 样品体积 float
	enum_str_TBL_INFOSSILCOMBINAT_FLD_GCEABM,           // 野外命名 varchar
	enum_double_TBL_INFOSSILCOMBINAT_FLD_GCEAAL,        // 样品重量(kg) float
	enum_str_TBL_INFOSSILCOMBINAT_FLD_SAMPLELENGTH,     // 样品长度(cm) varchar
	enum_str_TBL_INFOSSILCOMBINAT_FLD_PRETREATMETHOD,   // 预处理方法 varchar
	enum_str_TBL_INFOSSILCOMBINAT_FLD_TESTCONTENT,      // 测试内容 varchar
	enum_str_TBL_INFOSSILCOMBINAT_FLD_PLANEPOSMAP,      // 平面位置示意图 varchar
	enum_str_TBL_INFOSSILCOMBINAT_FLD_PROFILEMAP,       // 剖面示意图 varchar
	enum_str_TBL_INFOSSILCOMBINAT_FLD_FIELDIMAGE,       // 野外照片(视频) varchar
	enum_str_TBL_INFOSSILCOMBINAT_FLD_RECORDCARD,       // 记录卡片(记录) varchar
	enum_str_TBL_INFOSSILCOMBINAT_FLD_SAMPLEORGN,       // 采样单位 varchar
	enum_str_TBL_INFOSSILCOMBINAT_FLD_SWFOMW,           // 采样人 varchar
	enum_str_TBL_INFOSSILCOMBINAT_FLD_GCEABJ,           // 采样日期 date
	enum_str_TBL_INFOSSILCOMBINAT_FLD_INPUTER,          // 录入员 varchar
	enum_str_TBL_INFOSSILCOMBINAT_FLD_INPUTORGN,        // 录入单位 varchar
	enum_str_TBL_INFOSSILCOMBINAT_FLD_INPUTDATE,        // 录入日期 date
	enum_str_TBL_INFOSSILCOMBINAT_FLD_GCEABD,           // 室内编号 varchar
	enum_str_TBL_INFOSSILCOMBINAT_FLD_TESTEQUIP,        // 试验仪器 varchar
	enum_str_TBL_INFOSSILCOMBINAT_FLD_TESTMETHOD,       // 试验方法 varchar
	enum_str_TBL_INFOSSILCOMBINAT_FLD_TESTBASED,        // 检验依据 varchar
	enum_str_TBL_INFOSSILCOMBINAT_FLD_GCEAJC,           // 试验单位 varchar
	enum_str_TBL_INFOSSILCOMBINAT_FLD_SWFGAM,           // 收样日期 date
	enum_str_TBL_INFOSSILCOMBINAT_FLD_SWFGAN,           // 报告日期 date
	enum_str_TBL_INFOSSILCOMBINAT_FLD_GCEAJD,           // 校对 varchar
	enum_str_TBL_INFOSSILCOMBINAT_FLD_AUDITOR,          // 审核 varchar
	enum_str_TBL_INFOSSILCOMBINAT_FLD_TESTLEADER,       // 试验负责人 varchar
	enum_str_TBL_INFOSSILCOMBINAT_FLD__REPORT,          // 原始测试分析报告 varchar
	// 化石鉴定数据表
	enum_int_TBL_INFOSSILIDENT_FLD_FOSSILID,        // 化石ID int
	enum_double_TBL_INFOSSILIDENT_FLD_TOPDEPTH,     // 取样顶深度 float
	enum_double_TBL_INFOSSILIDENT_FLD_BOTTOMDEPTH,  // 取样底深度 float
	enum_int_TBL_INFOSSILIDENT_FLD_PNTID,           // 点ID int
	enum_str_TBL_INFOSSILIDENT_FLD_SWFGAA,          // 采样层位 varchar
	enum_str_TBL_INFOSSILIDENT_FLD_TCMC,            // 土层名称 varchar
	enum_str_TBL_INFOSSILIDENT_FLD_GEOCODE,         // 地质代号 varchar
	enum_str_TBL_INFOSSILIDENT_FLD_TESTNO,          //  varchar
	enum_str_TBL_INFOSSILIDENT_FLD_TESTCATEGORY,    // 试验类型 varchar
	enum_str_TBL_INFOSSILIDENT_FLD_FOSSILNAME,      // 化石名称 varchar
	enum_int_TBL_INFOSSILIDENT_FLD_QUANTITY,        // 数量 int
	enum_double_TBL_INFOSSILIDENT_FLD__ONTENT,      // 含量 float
	enum_str_TBL_INFOSSILIDENT_FLD_GCEABD,          // 室内编号 varchar
	enum_str_TBL_INFOSSILIDENT_FLD_TESTEQUIP,       // 试验仪器 varchar
	enum_str_TBL_INFOSSILIDENT_FLD_TESTMETHOD,      // 试验方法 varchar
	enum_str_TBL_INFOSSILIDENT_FLD_TESTBASED,       // 检验依据 varchar
	enum_str_TBL_INFOSSILIDENT_FLD_GCEAJC,          // 试验单位 varchar
	enum_str_TBL_INFOSSILIDENT_FLD_SWFGAM,          // 收样日期 date
	enum_str_TBL_INFOSSILIDENT_FLD_SWFGAN,          // 报告日期 date
	enum_str_TBL_INFOSSILIDENT_FLD_GCEAJD,          // 校对 varchar
	enum_str_TBL_INFOSSILIDENT_FLD_AUDITOR,         // 审核 varchar
	enum_str_TBL_INFOSSILIDENT_FLD_TESTLEADER,      // 试验负责人 varchar
	enum_str_TBL_INFOSSILIDENT_FLD__REPORT,         // 原始测试分析报告 varchar
	enum_str_TBL_INFOSSILIDENT_FLD_GCEABB,          // 样品编号 varchar
	enum_str_TBL_INFOSSILIDENT_FLD_SWBCF,           // 样品类型 varchar
	enum_str_TBL_INFOSSILIDENT_FLD_ISMIXSAMPLE,     // 混合样 varchar
	enum_str_TBL_INFOSSILIDENT_FLD_PNTTYPE,         // 点类型 varchar
	enum_str_TBL_INFOSSILIDENT_FLD_SECONDCODE,      // 样品二次编码 varchar
	enum_double_TBL_INFOSSILIDENT_FLD_SAMPLEVOLUME, // 样品体积 float
	enum_str_TBL_INFOSSILIDENT_FLD_GCEABM,          // 野外命名 varchar
	enum_double_TBL_INFOSSILIDENT_FLD_GCEAAL,       // 样品重量(kg) float
	enum_str_TBL_INFOSSILIDENT_FLD_SAMPLELENGTH,    // 样品长度(cm) varchar
	enum_str_TBL_INFOSSILIDENT_FLD_PRETREATMETHOD,  // 预处理方法 varchar
	enum_str_TBL_INFOSSILIDENT_FLD_TESTCONTENT,     // 测试内容 varchar
	enum_str_TBL_INFOSSILIDENT_FLD_PLANEPOSMAP,     // 平面位置示意图 varchar
	enum_str_TBL_INFOSSILIDENT_FLD_PROFILEMAP,      // 剖面示意图 varchar
	enum_str_TBL_INFOSSILIDENT_FLD_FIELDIMAGE,      // 野外照片(视频) varchar
	enum_str_TBL_INFOSSILIDENT_FLD_RECORDCARD,      // 记录卡片(记录) varchar
	enum_str_TBL_INFOSSILIDENT_FLD_SAMPLEORGN,      // 采样单位 varchar
	enum_str_TBL_INFOSSILIDENT_FLD_SWFOMW,          // 采样人 varchar
	enum_str_TBL_INFOSSILIDENT_FLD_GCEABJ,          // 采样日期 date
	enum_str_TBL_INFOSSILIDENT_FLD_INPUTER,         // 录入员 varchar
	enum_str_TBL_INFOSSILIDENT_FLD_INPUTORGN,       // 录入单位 varchar
	enum_str_TBL_INFOSSILIDENT_FLD_INPUTDATE,       // 录入日期 date
	// 古地磁测试成果表
	enum_int_TBL_INPALEOMAGNETIC_FLD_PALEOMAGNETICID,     // 古地磁ID int
	enum_double_TBL_INPALEOMAGNETIC_FLD_TOPDEPTH,         // 取样顶深度 float
	enum_double_TBL_INPALEOMAGNETIC_FLD_BOTTOMDEPTH,      // 取样底深度 float
	enum_int_TBL_INPALEOMAGNETIC_FLD_PNTID,               // 点ID int
	enum_str_TBL_INPALEOMAGNETIC_FLD_SWFGAA,              // 采样层位 varchar
	enum_str_TBL_INPALEOMAGNETIC_FLD_TCMC,                // 土层名称 varchar
	enum_str_TBL_INPALEOMAGNETIC_FLD_GEOCODE,             // 地质代号 varchar
	enum_str_TBL_INPALEOMAGNETIC_FLD_TESTNO,              //  varchar
	enum_str_TBL_INPALEOMAGNETIC_FLD_TESTCATEGORY,        // 试验类型 varchar
	enum_str_TBL_INPALEOMAGNETIC_FLD_POLAREVENT,          // 极性事件 varchar
	enum_str_TBL_INPALEOMAGNETIC_FLD_POLARCOLUMN,         // 极性柱 varchar
	enum_double_TBL_INPALEOMAGNETIC_FLD_MAGNETICDECLINAT, // 磁偏角 float
	enum_str_TBL_INPALEOMAGNETIC_FLD_LAYERAGEUNIT,        // 年代地层单位 varchar
	enum_str_TBL_INPALEOMAGNETIC_FLD_GCEABB,              // 样品编号 varchar
	enum_str_TBL_INPALEOMAGNETIC_FLD_SWBCF,               // 样品类型 varchar
	enum_str_TBL_INPALEOMAGNETIC_FLD_ISMIXSAMPLE,         // 混合样 varchar
	enum_str_TBL_INPALEOMAGNETIC_FLD_PNTTYPE,             // 点类型 varchar
	enum_str_TBL_INPALEOMAGNETIC_FLD_SECONDCODE,          // 样品二次编码 varchar
	enum_double_TBL_INPALEOMAGNETIC_FLD_SAMPLEVOLUME,     // 样品体积 float
	enum_str_TBL_INPALEOMAGNETIC_FLD_GCEABM,              // 野外命名 varchar
	enum_double_TBL_INPALEOMAGNETIC_FLD_GCEAAL,           // 样品重量(kg) float
	enum_str_TBL_INPALEOMAGNETIC_FLD_SAMPLELENGTH,        // 样品长度(cm) varchar
	enum_str_TBL_INPALEOMAGNETIC_FLD_PRETREATMETHOD,      // 预处理方法 varchar
	enum_str_TBL_INPALEOMAGNETIC_FLD_TESTCONTENT,         // 测试内容 varchar
	enum_str_TBL_INPALEOMAGNETIC_FLD_PLANEPOSMAP,         // 平面位置示意图 varchar
	enum_str_TBL_INPALEOMAGNETIC_FLD_PROFILEMAP,          // 剖面示意图 varchar
	enum_str_TBL_INPALEOMAGNETIC_FLD_FIELDIMAGE,          // 野外照片(视频) varchar
	enum_str_TBL_INPALEOMAGNETIC_FLD_RECORDCARD,          // 记录卡片(记录) varchar
	enum_str_TBL_INPALEOMAGNETIC_FLD_SAMPLEORGN,          // 采样单位 varchar
	enum_str_TBL_INPALEOMAGNETIC_FLD_SWFOMW,              // 采样人 varchar
	enum_str_TBL_INPALEOMAGNETIC_FLD_GCEABJ,              // 采样日期 date
	enum_str_TBL_INPALEOMAGNETIC_FLD_INPUTER,             // 录入员 varchar
	enum_str_TBL_INPALEOMAGNETIC_FLD_INPUTORGN,           // 录入单位 varchar
	enum_str_TBL_INPALEOMAGNETIC_FLD_INPUTDATE,           // 录入日期 date
	enum_str_TBL_INPALEOMAGNETIC_FLD_GCEABD,              // 室内编号 varchar
	enum_str_TBL_INPALEOMAGNETIC_FLD_TESTEQUIP,           // 试验仪器 varchar
	enum_str_TBL_INPALEOMAGNETIC_FLD_TESTMETHOD,          // 试验方法 varchar
	enum_str_TBL_INPALEOMAGNETIC_FLD_TESTBASED,           // 检验依据 varchar
	enum_str_TBL_INPALEOMAGNETIC_FLD_GCEAJC,              // 试验单位 varchar
	enum_str_TBL_INPALEOMAGNETIC_FLD_SWFGAM,              // 收样日期 date
	enum_str_TBL_INPALEOMAGNETIC_FLD_SWFGAN,              // 报告日期 date
	enum_str_TBL_INPALEOMAGNETIC_FLD_GCEAJD,              // 校对 varchar
	enum_str_TBL_INPALEOMAGNETIC_FLD_AUDITOR,             // 审核 varchar
	enum_str_TBL_INPALEOMAGNETIC_FLD_TESTLEADER,          // 试验负责人 varchar
	enum_str_TBL_INPALEOMAGNETIC_FLD__REPORT,             // 原始测试分析报告 varchar
	// 水腐蚀性分析
	enum_int_TBL_INWATERCAUSTICITY_FLD_WATERCAUSTICITYID, // 水腐蚀ID int
	enum_double_TBL_INWATERCAUSTICITY_FLD_TOPDEPTH,       // 取样顶深度 float
	enum_double_TBL_INWATERCAUSTICITY_FLD_BOTTOMDEPTH,    // 取样底深度 float
	enum_int_TBL_INWATERCAUSTICITY_FLD_PNTID,             // 点ID int
	enum_str_TBL_INWATERCAUSTICITY_FLD_SWFGAA,            // 采样层位 varchar
	enum_str_TBL_INWATERCAUSTICITY_FLD_TCMC,              // 土层名称 varchar
	enum_str_TBL_INWATERCAUSTICITY_FLD_GEOCODE,           // 地质代号 varchar
	enum_str_TBL_INWATERCAUSTICITY_FLD_TESTNO,            //  varchar
	enum_str_TBL_INWATERCAUSTICITY_FLD_TESTCATEGORY,      // 试验类型 varchar
	enum_double_TBL_INWATERCAUSTICITY_FLD_KNA,            //  float
	enum_double_TBL_INWATERCAUSTICITY_FLD_SWFHFA,         // Ca2+(mg/L) float
	enum_double_TBL_INWATERCAUSTICITY_FLD_SWFHFB,         // Mg2+(mg/L) float
	enum_double_TBL_INWATERCAUSTICITY_FLD_NH4,            // NH4+(mg/L) float
	enum_double_TBL_INWATERCAUSTICITY_FLD_NO3,            // NO3-(mg/L) float
	enum_double_TBL_INWATERCAUSTICITY_FLD_SWFHFF,         // Cl-(mg/L) float
	enum_double_TBL_INWATERCAUSTICITY_FLD_SWFHFG,         // SO42-(mg/L) float
	enum_double_TBL_INWATERCAUSTICITY_FLD_SWFHFI,         // CO32-(mmol/L) float
	enum_double_TBL_INWATERCAUSTICITY_FLD_SWFHFH,         // HCO3-(mmol/L) float
	enum_double_TBL_INWATERCAUSTICITY_FLD_CL,             // CL-(mmol/L) float
	enum_double_TBL_INWATERCAUSTICITY_FLD_ZJD,            // 总碱度(mg/L) float
	enum_double_TBL_INWATERCAUSTICITY_FLD_CAUSTIC,        // 苛性碱OH-(mg/L) float
	enum_double_TBL_INWATERCAUSTICITY_FLD_SWFHE,          // 矿化度(mg/L) float
	enum_double_TBL_INWATERCAUSTICITY_FLD_LZZL,           // 离子总量 float
	enum_double_TBL_INWATERCAUSTICITY_FLD_RJXGTZL,        // 溶解性固体总量（mg/L） float
	enum_double_TBL_INWATERCAUSTICITY_FLD_PH,             // pH float
	enum_double_TBL_INWATERCAUSTICITY_FLD_SWFHI,          // 侵蚀CO2(mg/L) float
	enum_double_TBL_INWATERCAUSTICITY_FLD_SWFHG,          // 游离CO2(mg/L) float
	enum_double_TBL_INWATERCAUSTICITY_FLD_ZYD,            // 总硬度 float
	enum_double_TBL_INWATERCAUSTICITY_FLD_ZSYD,           // 暂时硬度 float
	enum_double_TBL_INWATERCAUSTICITY_FLD_YJYD,           // 永久硬度 float
	enum_double_TBL_INWATERCAUSTICITY_FLD_FYD,            // 负硬度 float
	enum_str_TBL_INWATERCAUSTICITY_FLD_HNTJG,			  // 混凝土结构 varchar
	enum_str_TBL_INWATERCAUSTICITY_FLD_GJ,                // 钢筋 varchar
	enum_str_TBL_INWATERCAUSTICITY_FLD_GCEABB,            // 样品编号 varchar
	enum_str_TBL_INWATERCAUSTICITY_FLD_SWBCF,             // 样品类型 varchar
	enum_str_TBL_INWATERCAUSTICITY_FLD_ISMIXSAMPLE,       // 混合样 varchar
	enum_str_TBL_INWATERCAUSTICITY_FLD_PNTTYPE,           // 点类型 varchar
	enum_str_TBL_INWATERCAUSTICITY_FLD_SECONDCODE,        // 样品二次编码 varchar
	enum_double_TBL_INWATERCAUSTICITY_FLD_SAMPLEVOLUME,   // 样品体积 float
	enum_str_TBL_INWATERCAUSTICITY_FLD_GCEABM,            // 野外命名 varchar
	enum_double_TBL_INWATERCAUSTICITY_FLD_GCEAAL,         // 样品重量(kg) float
	enum_str_TBL_INWATERCAUSTICITY_FLD_SAMPLELENGTH,      // 样品长度(cm) varchar
	enum_str_TBL_INWATERCAUSTICITY_FLD_PRETREATMETHOD,    // 预处理方法 varchar
	enum_str_TBL_INWATERCAUSTICITY_FLD_TESTCONTENT,       // 测试内容 varchar
	enum_str_TBL_INWATERCAUSTICITY_FLD_PLANEPOSMAP,       // 平面位置示意图 varchar
	enum_str_TBL_INWATERCAUSTICITY_FLD_PROFILEMAP,        // 剖面示意图 varchar
	enum_str_TBL_INWATERCAUSTICITY_FLD_FIELDIMAGE,        // 野外照片(视频) varchar
	enum_str_TBL_INWATERCAUSTICITY_FLD_RECORDCARD,        // 记录卡片(记录) varchar
	enum_str_TBL_INWATERCAUSTICITY_FLD_SAMPLEORGN,        // 采样单位 varchar
	enum_str_TBL_INWATERCAUSTICITY_FLD_SWFOMW,            // 采样人 varchar
	enum_str_TBL_INWATERCAUSTICITY_FLD_GCEABJ,            // 采样日期 date
	enum_str_TBL_INWATERCAUSTICITY_FLD_INPUTER,           // 录入员 varchar
	enum_str_TBL_INWATERCAUSTICITY_FLD_INPUTORGN,         // 录入单位 varchar
	enum_str_TBL_INWATERCAUSTICITY_FLD_INPUTDATE,         // 录入日期 date
	enum_str_TBL_INWATERCAUSTICITY_FLD_GCEABD,            // 室内编号 varchar
	enum_str_TBL_INWATERCAUSTICITY_FLD_TESTEQUIP,         // 试验仪器 varchar
	enum_str_TBL_INWATERCAUSTICITY_FLD_TESTMETHOD,        // 试验方法 varchar
	enum_str_TBL_INWATERCAUSTICITY_FLD_TESTBASED,         // 检验依据 varchar
	enum_str_TBL_INWATERCAUSTICITY_FLD_GCEAJC,            // 试验单位 varchar
	enum_str_TBL_INWATERCAUSTICITY_FLD_SWFGAM,            // 收样日期 date
	enum_str_TBL_INWATERCAUSTICITY_FLD_SWFGAN,            // 报告日期 date
	enum_str_TBL_INWATERCAUSTICITY_FLD_GCEAJD,            // 校对 varchar
	enum_str_TBL_INWATERCAUSTICITY_FLD_AUDITOR,           // 审核 varchar
	enum_str_TBL_INWATERCAUSTICITY_FLD_TESTLEADER,        // 试验负责人 varchar
	enum_str_TBL_INWATERCAUSTICITY_FLD__REPORT,           // 原始测试分析报告 varchar
	// 土腐蚀性分析
	enum_int_TBL_INSOILCAUSTICITY_FLD_SOILCORROSIONID,     // 土腐蚀ID int
	enum_double_TBL_INSOILCAUSTICITY_FLD_TOPDEPTH,         // 取样顶深度 float
	enum_double_TBL_INSOILCAUSTICITY_FLD_BOTTOMDEPTH,      // 取样底深度 float
	enum_int_TBL_INSOILCAUSTICITY_FLD_PNTID,               // 点ID int
	enum_str_TBL_INSOILCAUSTICITY_FLD_SWFGAA,              // 采样层位 varchar
	enum_str_TBL_INSOILCAUSTICITY_FLD_TCMC,                // 土层名称 varchar
	enum_str_TBL_INSOILCAUSTICITY_FLD_GEOCODE,             // 地质代号 varchar
	enum_str_TBL_INSOILCAUSTICITY_FLD_TESTNO,              //  varchar
	enum_str_TBL_INSOILCAUSTICITY_FLD_TESTCATEGORY,        // 试验类型 varchar
	enum_double_TBL_INSOILCAUSTICITY_FLD_SWFHFA,           // Ca2+(mg/kg) float
	enum_double_TBL_INSOILCAUSTICITY_FLD_SWFHFB,           // Mg2+(mg/kg) float
	enum_double_TBL_INSOILCAUSTICITY_FLD_SWFHFF,           // Cl-(mg/kg) float
	enum_double_TBL_INSOILCAUSTICITY_FLD_SWFHFG,           // SO42-(mg/kg) float
	enum_double_TBL_INSOILCAUSTICITY_FLD_SWFHFH,           // HCO3-(mg/kg) float
	enum_double_TBL_INSOILCAUSTICITY_FLD_SWFHFI,           // CO32-(mg/kg) float
	enum_double_TBL_INSOILCAUSTICITY_FLD_SWFHFJ,           // NH4+ float
	enum_double_TBL_INSOILCAUSTICITY_FLD_PH,               // pH float
	enum_double_TBL_INSOILCAUSTICITY_FLD_KWAAJG,           // Eh(mV) float
	enum_double_TBL_INSOILCAUSTICITY_FLD_RESISTIVITY,      // 电阻率(Ω·m) float
	enum_double_TBL_INSOILCAUSTICITY_FLD_POLARIZATDENSITY, // 极化电流密度 float
	enum_double_TBL_INSOILCAUSTICITY_FLD_MASSLOSS,         // 质量损失(g) float
	enum_str_TBL_INSOILCAUSTICITY_FLD_HNTJG,            // 混凝土结构 varchar
	enum_str_TBL_INSOILCAUSTICITY_FLD_GJ,               // 钢筋 varchar
	enum_str_TBL_INSOILCAUSTICITY_FLD_GJG,              // 钢结构 varchar
	enum_str_TBL_INSOILCAUSTICITY_FLD_GCEABB,              // 样品编号 varchar
	enum_str_TBL_INSOILCAUSTICITY_FLD_SWBCF,               // 样品类型 varchar
	enum_str_TBL_INSOILCAUSTICITY_FLD_ISMIXSAMPLE,         // 混合样 varchar
	enum_str_TBL_INSOILCAUSTICITY_FLD_PNTTYPE,             // 点类型 varchar
	enum_str_TBL_INSOILCAUSTICITY_FLD_SECONDCODE,          // 样品二次编码 varchar
	enum_double_TBL_INSOILCAUSTICITY_FLD_SAMPLEVOLUME,     // 样品体积 float
	enum_str_TBL_INSOILCAUSTICITY_FLD_GCEABM,              // 野外命名 varchar
	enum_double_TBL_INSOILCAUSTICITY_FLD_GCEAAL,           // 样品重量(kg) float
	enum_str_TBL_INSOILCAUSTICITY_FLD_SAMPLELENGTH,        // 样品长度(cm) varchar
	enum_str_TBL_INSOILCAUSTICITY_FLD_PRETREATMETHOD,      // 预处理方法 varchar
	enum_str_TBL_INSOILCAUSTICITY_FLD_TESTCONTENT,         // 测试内容 varchar
	enum_str_TBL_INSOILCAUSTICITY_FLD_PLANEPOSMAP,         // 平面位置示意图 varchar
	enum_str_TBL_INSOILCAUSTICITY_FLD_PROFILEMAP,          // 剖面示意图 varchar
	enum_str_TBL_INSOILCAUSTICITY_FLD_FIELDIMAGE,          // 野外照片(视频) varchar
	enum_str_TBL_INSOILCAUSTICITY_FLD_RECORDCARD,          // 记录卡片(记录) varchar
	enum_str_TBL_INSOILCAUSTICITY_FLD_SAMPLEORGN,          // 采样单位 varchar
	enum_str_TBL_INSOILCAUSTICITY_FLD_SWFOMW,              // 采样人 varchar
	enum_str_TBL_INSOILCAUSTICITY_FLD_GCEABJ,              // 采样日期 date
	enum_str_TBL_INSOILCAUSTICITY_FLD_INPUTER,             // 录入员 varchar
	enum_str_TBL_INSOILCAUSTICITY_FLD_INPUTORGN,           // 录入单位 varchar
	enum_str_TBL_INSOILCAUSTICITY_FLD_INPUTDATE,           // 录入日期 date
	enum_str_TBL_INSOILCAUSTICITY_FLD_GCEABD,              // 室内编号 varchar
	enum_str_TBL_INSOILCAUSTICITY_FLD_TESTEQUIP,           // 试验仪器 varchar
	enum_str_TBL_INSOILCAUSTICITY_FLD_TESTMETHOD,          // 试验方法 varchar
	enum_str_TBL_INSOILCAUSTICITY_FLD_TESTBASED,           // 检验依据 varchar
	enum_str_TBL_INSOILCAUSTICITY_FLD_GCEAJC,              // 试验单位 varchar
	enum_str_TBL_INSOILCAUSTICITY_FLD_SWFGAM,              // 收样日期 date
	enum_str_TBL_INSOILCAUSTICITY_FLD_SWFGAN,              // 报告日期 date
	enum_str_TBL_INSOILCAUSTICITY_FLD_GCEAJD,              // 校对 varchar
	enum_str_TBL_INSOILCAUSTICITY_FLD_AUDITOR,             // 审核 varchar
	enum_str_TBL_INSOILCAUSTICITY_FLD_TESTLEADER,          // 试验负责人 varchar
	enum_str_TBL_INSOILCAUSTICITY_FLD__REPORT,             // 原始测试分析报告 varchar
	// 地球化学分析数据表
	enum_int_TBL_INGEOCHEMICALIDENT_FLD_CHEANALYSISID,   // 化学分析ID int
	enum_double_TBL_INGEOCHEMICALIDENT_FLD_TOPDEPTH,     // 取样顶深度 float
	enum_double_TBL_INGEOCHEMICALIDENT_FLD_BOTTOMDEPTH,  // 取样底深度 float
	enum_int_TBL_INGEOCHEMICALIDENT_FLD_PNTID,           // 点ID int
	enum_str_TBL_INGEOCHEMICALIDENT_FLD_SWFGAA,          // 采样层位 varchar
	enum_str_TBL_INGEOCHEMICALIDENT_FLD_TCMC,            // 土层名称 varchar
	enum_str_TBL_INGEOCHEMICALIDENT_FLD_GEOCODE,         // 地质代号 varchar
	enum_str_TBL_INGEOCHEMICALIDENT_FLD_TESTNO,          //  varchar
	enum_str_TBL_INGEOCHEMICALIDENT_FLD_TESTCATEGORY,    // 试验类型 varchar
	enum_str_TBL_INGEOCHEMICALIDENT_FLD_ANALYSISINDEX,   // 分析指标 varchar
	enum_str_TBL_INGEOCHEMICALIDENT_FLD_CHEMICALCODE,    // 化学代号 varchar
	enum_str_TBL_INGEOCHEMICALIDENT_FLD_NUMERICALUNIT,   // 数值单位 varchar
	enum_str_TBL_INGEOCHEMICALIDENT_FLD_ANALYSISRESULT,  // 分析结果 varchar
	enum_str_TBL_INGEOCHEMICALIDENT_FLD_GCEABB,          // 样品编号 varchar
	enum_str_TBL_INGEOCHEMICALIDENT_FLD_SWBCF,           // 样品类型 varchar
	enum_str_TBL_INGEOCHEMICALIDENT_FLD_ISMIXSAMPLE,     // 混合样 varchar
	enum_str_TBL_INGEOCHEMICALIDENT_FLD_PNTTYPE,         // 点类型 varchar
	enum_str_TBL_INGEOCHEMICALIDENT_FLD_SECONDCODE,      // 样品二次编码 varchar
	enum_double_TBL_INGEOCHEMICALIDENT_FLD_SAMPLEVOLUME, // 样品体积 float
	enum_str_TBL_INGEOCHEMICALIDENT_FLD_GCEABM,          // 野外命名 varchar
	enum_double_TBL_INGEOCHEMICALIDENT_FLD_GCEAAL,       // 样品重量(kg) float
	enum_str_TBL_INGEOCHEMICALIDENT_FLD_SAMPLELENGTH,    // 样品长度(cm) varchar
	enum_str_TBL_INGEOCHEMICALIDENT_FLD_PRETREATMETHOD,  // 预处理方法 varchar
	enum_str_TBL_INGEOCHEMICALIDENT_FLD_TESTCONTENT,     // 测试内容 varchar
	enum_str_TBL_INGEOCHEMICALIDENT_FLD_PLANEPOSMAP,     // 平面位置示意图 varchar
	enum_str_TBL_INGEOCHEMICALIDENT_FLD_PROFILEMAP,      // 剖面示意图 varchar
	enum_str_TBL_INGEOCHEMICALIDENT_FLD_FIELDIMAGE,      // 野外照片(视频) varchar
	enum_str_TBL_INGEOCHEMICALIDENT_FLD_RECORDCARD,      // 记录卡片(记录) varchar
	enum_str_TBL_INGEOCHEMICALIDENT_FLD_SAMPLEORGN,      // 采样单位 varchar
	enum_str_TBL_INGEOCHEMICALIDENT_FLD_SWFOMW,          // 采样人 varchar
	enum_str_TBL_INGEOCHEMICALIDENT_FLD_GCEABJ,          // 采样日期 date
	enum_str_TBL_INGEOCHEMICALIDENT_FLD_INPUTER,         // 录入员 varchar
	enum_str_TBL_INGEOCHEMICALIDENT_FLD_INPUTORGN,       // 录入单位 varchar
	enum_str_TBL_INGEOCHEMICALIDENT_FLD_INPUTDATE,       // 录入日期 date
	enum_str_TBL_INGEOCHEMICALIDENT_FLD_GCEABD,          // 室内编号 varchar
	enum_str_TBL_INGEOCHEMICALIDENT_FLD_TESTEQUIP,       // 试验仪器 varchar
	enum_str_TBL_INGEOCHEMICALIDENT_FLD_TESTMETHOD,      // 试验方法 varchar
	enum_str_TBL_INGEOCHEMICALIDENT_FLD_TESTBASED,       // 检验依据 varchar
	enum_str_TBL_INGEOCHEMICALIDENT_FLD_GCEAJC,          // 试验单位 varchar
	enum_str_TBL_INGEOCHEMICALIDENT_FLD_SWFGAM,          // 收样日期 date
	enum_str_TBL_INGEOCHEMICALIDENT_FLD_SWFGAN,          // 报告日期 date
	enum_str_TBL_INGEOCHEMICALIDENT_FLD_GCEAJD,          // 校对 varchar
	enum_str_TBL_INGEOCHEMICALIDENT_FLD_AUDITOR,         // 审核 varchar
	enum_str_TBL_INGEOCHEMICALIDENT_FLD_TESTLEADER,      // 试验负责人 varchar
	enum_str_TBL_INGEOCHEMICALIDENT_FLD__REPORT,         // 原始测试分析报告 varchar
	// 工勘孔土的易溶性分析
	enum_int_TBL_TYRXFXSJ_FLD_TYRXFXSJID,      // ID int
	enum_double_TBL_TYRXFXSJ_FLD_TOPDEPTH,     // 取样顶深度 float
	enum_double_TBL_TYRXFXSJ_FLD_BOTTOMDEPTH,  // 取样底深度 float
	enum_int_TBL_TYRXFXSJ_FLD_PNTID,           // 点ID int
	enum_str_TBL_TYRXFXSJ_FLD_SWFGAA,          // 采样层位 varchar
	enum_str_TBL_TYRXFXSJ_FLD_TCMC,            // 土层名称 varchar
	enum_str_TBL_TYRXFXSJ_FLD_GEOCODE,         // 地质代号 varchar
	enum_str_TBL_TYRXFXSJ_FLD_TESTNO,          //  varchar
	enum_str_TBL_TYRXFXSJ_FLD_TESTCATEGORY,    // 试验类型 varchar
	enum_str_TBL_TYRXFXSJ_FLD_FXDATE,          // 分析日期 varchar
	enum_double_TBL_TYRXFXSJ_FLD_NAK,          // K+和Na+易溶性 double
	enum_double_TBL_TYRXFXSJ_FLD_CA,           // Ca2+易溶性 double
	enum_double_TBL_TYRXFXSJ_FLD_MG,           // Mg2+易溶性 double
	enum_double_TBL_TYRXFXSJ_FLD_CO3,          // CO32-易溶性 double
	enum_double_TBL_TYRXFXSJ_FLD_HCO3,         // HCO32-易溶性 double
	enum_double_TBL_TYRXFXSJ_FLD_SO4,          // SO42-易溶性 double
	enum_double_TBL_TYRXFXSJ_FLD_CL,           // Cl-易溶性 double
	enum_double_TBL_TYRXFXSJ_FLD_YD,           // 硬度易溶性 double
	enum_double_TBL_TYRXFXSJ_FLD_LZZL,         // 离子总量 double
	enum_double_TBL_TYRXFXSJ_FLD_PH,           // PH值 double
	enum_str_TBL_TYRXFXSJ_FLD_GCEABB,          // 样品编号 varchar
	enum_str_TBL_TYRXFXSJ_FLD_SWBCF,           // 样品类型 varchar
	enum_str_TBL_TYRXFXSJ_FLD_ISMIXSAMPLE,     // 混合样 varchar
	enum_str_TBL_TYRXFXSJ_FLD_PNTTYPE,         // 点类型 varchar
	enum_str_TBL_TYRXFXSJ_FLD_SECONDCODE,      // 样品二次编码 varchar
	enum_double_TBL_TYRXFXSJ_FLD_SAMPLEVOLUME, // 样品体积 float
	enum_str_TBL_TYRXFXSJ_FLD_GCEABM,          // 野外命名 varchar
	enum_double_TBL_TYRXFXSJ_FLD_GCEAAL,       // 样品重量(kg) float
	enum_str_TBL_TYRXFXSJ_FLD_SAMPLELENGTH,    // 样品长度(cm) varchar
	enum_str_TBL_TYRXFXSJ_FLD_PRETREATMETHOD,  // 预处理方法 varchar
	enum_str_TBL_TYRXFXSJ_FLD_TESTCONTENT,     // 测试内容 varchar
	enum_str_TBL_TYRXFXSJ_FLD_PLANEPOSMAP,     // 平面位置示意图 varchar
	enum_str_TBL_TYRXFXSJ_FLD_PROFILEMAP,      // 剖面示意图 varchar
	enum_str_TBL_TYRXFXSJ_FLD_FIELDIMAGE,      // 野外照片(视频) varchar
	enum_str_TBL_TYRXFXSJ_FLD_RECORDCARD,      // 记录卡片(记录) varchar
	enum_str_TBL_TYRXFXSJ_FLD_SAMPLEORGN,      // 采样单位 varchar
	enum_str_TBL_TYRXFXSJ_FLD_SWFOMW,          // 采样人 varchar
	enum_str_TBL_TYRXFXSJ_FLD_GCEABJ,          // 采样日期 date
	enum_str_TBL_TYRXFXSJ_FLD_INPUTER,         // 录入员 varchar
	enum_str_TBL_TYRXFXSJ_FLD_INPUTORGN,       // 录入单位 varchar
	enum_str_TBL_TYRXFXSJ_FLD_INPUTDATE,       // 录入日期 date
	enum_str_TBL_TYRXFXSJ_FLD_GCEABD,          // 室内编号 varchar
	enum_str_TBL_TYRXFXSJ_FLD_TESTEQUIP,       // 试验仪器 varchar
	enum_str_TBL_TYRXFXSJ_FLD_TESTMETHOD,      // 试验方法 varchar
	enum_str_TBL_TYRXFXSJ_FLD_TESTBASED,       // 检验依据 varchar
	enum_str_TBL_TYRXFXSJ_FLD_GCEAJC,          // 试验单位 varchar
	enum_str_TBL_TYRXFXSJ_FLD_SWFGAM,          // 收样日期 date
	enum_str_TBL_TYRXFXSJ_FLD_SWFGAN,          // 报告日期 date
	enum_str_TBL_TYRXFXSJ_FLD_GCEAJD,          // 校对 varchar
	enum_str_TBL_TYRXFXSJ_FLD_AUDITOR,         // 审核 varchar
	enum_str_TBL_TYRXFXSJ_FLD_TESTLEADER,      // 试验负责人 varchar
	enum_str_TBL_TYRXFXSJ_FLD__REPORT,         // 原始测试分析报告 varchar
	// 工勘孔岩石RQD实验
	enum_int_TBL_YSRQDSJ_FLD_TESTID,          // 测试ID int
	enum_double_TBL_YSRQDSJ_FLD_TOPDEPTH,     // 取样顶深度 float
	enum_double_TBL_YSRQDSJ_FLD_BOTTOMDEPTH,  // 取样底深度 float
	enum_int_TBL_YSRQDSJ_FLD_PNTID,           // 点ID int
	enum_str_TBL_YSRQDSJ_FLD_SWFGAA,          // 采样层位 varchar
	enum_str_TBL_YSRQDSJ_FLD_TCMC,            // 土层名称 varchar
	enum_str_TBL_YSRQDSJ_FLD_GEOCODE,         // 地质代号 varchar
	enum_str_TBL_YSRQDSJ_FLD_TESTNO,          //  varchar
	enum_str_TBL_YSRQDSJ_FLD_TESTCATEGORY,    // 试验类型 varchar
	enum_double_TBL_YSRQDSJ_FLD_TESTVAL,      // 岩石RQD double
	enum_str_TBL_YSRQDSJ_FLD__MEMO,           // 备注 varchar
	enum_str_TBL_YSRQDSJ_FLD_GCEABB,          // 样品编号 varchar
	enum_str_TBL_YSRQDSJ_FLD_SWBCF,           // 样品类型 varchar
	enum_str_TBL_YSRQDSJ_FLD_ISMIXSAMPLE,     // 混合样 varchar
	enum_str_TBL_YSRQDSJ_FLD_PNTTYPE,         // 点类型 varchar
	enum_str_TBL_YSRQDSJ_FLD_SECONDCODE,      // 样品二次编码 varchar
	enum_double_TBL_YSRQDSJ_FLD_SAMPLEVOLUME, // 样品体积 float
	enum_str_TBL_YSRQDSJ_FLD_GCEABM,          // 野外命名 varchar
	enum_double_TBL_YSRQDSJ_FLD_GCEAAL,       // 样品重量(kg) float
	enum_str_TBL_YSRQDSJ_FLD_SAMPLELENGTH,    // 样品长度(cm) varchar
	enum_str_TBL_YSRQDSJ_FLD_PRETREATMETHOD,  // 预处理方法 varchar
	enum_str_TBL_YSRQDSJ_FLD_TESTCONTENT,     // 测试内容 varchar
	enum_str_TBL_YSRQDSJ_FLD_PLANEPOSMAP,     // 平面位置示意图 varchar
	enum_str_TBL_YSRQDSJ_FLD_PROFILEMAP,      // 剖面示意图 varchar
	enum_str_TBL_YSRQDSJ_FLD_FIELDIMAGE,      // 野外照片(视频) varchar
	enum_str_TBL_YSRQDSJ_FLD_RECORDCARD,      // 记录卡片(记录) varchar
	enum_str_TBL_YSRQDSJ_FLD_SAMPLEORGN,      // 采样单位 varchar
	enum_str_TBL_YSRQDSJ_FLD_SWFOMW,          // 采样人 varchar
	enum_str_TBL_YSRQDSJ_FLD_GCEABJ,          // 采样日期 date
	enum_str_TBL_YSRQDSJ_FLD_INPUTER,         // 录入员 varchar
	enum_str_TBL_YSRQDSJ_FLD_INPUTORGN,       // 录入单位 varchar
	enum_str_TBL_YSRQDSJ_FLD_INPUTDATE,       // 录入日期 date
	enum_str_TBL_YSRQDSJ_FLD_GCEABD,          // 室内编号 varchar
	enum_str_TBL_YSRQDSJ_FLD_TESTEQUIP,       // 试验仪器 varchar
	enum_str_TBL_YSRQDSJ_FLD_TESTMETHOD,      // 试验方法 varchar
	enum_str_TBL_YSRQDSJ_FLD_TESTBASED,       // 检验依据 varchar
	enum_str_TBL_YSRQDSJ_FLD_GCEAJC,          // 试验单位 varchar
	enum_str_TBL_YSRQDSJ_FLD_SWFGAM,          // 收样日期 date
	enum_str_TBL_YSRQDSJ_FLD_SWFGAN,          // 报告日期 date
	enum_str_TBL_YSRQDSJ_FLD_GCEAJD,          // 校对 varchar
	enum_str_TBL_YSRQDSJ_FLD_AUDITOR,         // 审核 varchar
	enum_str_TBL_YSRQDSJ_FLD_TESTLEADER,      // 试验负责人 varchar
	enum_str_TBL_YSRQDSJ_FLD__REPORT,         // 原始测试分析报告 varchar
	// 岩石抗压强度表
	enum_int_TBL_STRENEGTH_ROCK_FLD_TESTID,                 // 测试ID int
	enum_double_TBL_STRENEGTH_ROCK_FLD_TOPDEPTH,            // 取样顶深度 float
	enum_double_TBL_STRENEGTH_ROCK_FLD_BOTTOMDEPTH,         // 取样底深度 float
	enum_int_TBL_STRENEGTH_ROCK_FLD_PNTID,                  // 点ID int
	enum_str_TBL_STRENEGTH_ROCK_FLD_SWFGAA,                 // 采样层位 varchar
	enum_str_TBL_STRENEGTH_ROCK_FLD_TCMC,                   // 土层名称 varchar
	enum_str_TBL_STRENEGTH_ROCK_FLD_GEOCODE,                // 地质代号 varchar
	enum_str_TBL_STRENEGTH_ROCK_FLD_TESTNO,                 //  varchar
	enum_str_TBL_STRENEGTH_ROCK_FLD_TESTCATEGORY,           // 试验类型 varchar
	enum_str_TBL_STRENEGTH_ROCK_FLD_TESTSTATUS,             // 试样状态 varchar
	enum_str_TBL_STRENEGTH_ROCK_FLD_SPECIFICATION,          // 试样规格 varchar
	enum_double_TBL_STRENEGTH_ROCK_FLD_TESTAREA,            // 试样面积(mm) double
	enum_double_TBL_STRENEGTH_ROCK_FLD_TOTALDESTORYPOWER,   // 总破坏力(KN) double
	enum_double_TBL_STRENEGTH_ROCK_FLD_COMPRESSIVESTRENGTH, // 抗压强度(MPa) double
	enum_double_TBL_STRENEGTH_ROCK_FLD_CORRECTEDVALUE,      // 修正值(MPa) double
	enum_double_TBL_STRENEGTH_ROCK_FLD_HDRATIO,             // 高径比(H/D) double
	enum_str_TBL_STRENEGTH_ROCK_FLD__MEMO,                  // 备注 varchar
	enum_str_TBL_STRENEGTH_ROCK_FLD_GCEABB,                 // 样品编号 varchar
	enum_str_TBL_STRENEGTH_ROCK_FLD_SWBCF,                  // 样品类型 varchar
	enum_str_TBL_STRENEGTH_ROCK_FLD_ISMIXSAMPLE,            // 混合样 varchar
	enum_str_TBL_STRENEGTH_ROCK_FLD_PNTTYPE,                // 点类型 varchar
	enum_str_TBL_STRENEGTH_ROCK_FLD_SECONDCODE,             // 样品二次编码 varchar
	enum_double_TBL_STRENEGTH_ROCK_FLD_SAMPLEVOLUME,        // 样品体积 float
	enum_str_TBL_STRENEGTH_ROCK_FLD_GCEABM,                 // 野外命名 varchar
	enum_double_TBL_STRENEGTH_ROCK_FLD_GCEAAL,              // 样品重量(kg) float
	enum_str_TBL_STRENEGTH_ROCK_FLD_SAMPLELENGTH,           // 样品长度(cm) varchar
	enum_str_TBL_STRENEGTH_ROCK_FLD_PRETREATMETHOD,         // 预处理方法 varchar
	enum_str_TBL_STRENEGTH_ROCK_FLD_TESTCONTENT,            // 测试内容 varchar
	enum_str_TBL_STRENEGTH_ROCK_FLD_PLANEPOSMAP,            // 平面位置示意图 varchar
	enum_str_TBL_STRENEGTH_ROCK_FLD_PROFILEMAP,             // 剖面示意图 varchar
	enum_str_TBL_STRENEGTH_ROCK_FLD_FIELDIMAGE,             // 野外照片(视频) varchar
	enum_str_TBL_STRENEGTH_ROCK_FLD_RECORDCARD,             // 记录卡片(记录) varchar
	enum_str_TBL_STRENEGTH_ROCK_FLD_SAMPLEORGN,             // 采样单位 varchar
	enum_str_TBL_STRENEGTH_ROCK_FLD_SWFOMW,                 // 采样人 varchar
	enum_str_TBL_STRENEGTH_ROCK_FLD_GCEABJ,                 // 采样日期 date
	enum_str_TBL_STRENEGTH_ROCK_FLD_INPUTER,                // 录入员 varchar
	enum_str_TBL_STRENEGTH_ROCK_FLD_INPUTORGN,              // 录入单位 varchar
	enum_str_TBL_STRENEGTH_ROCK_FLD_INPUTDATE,              // 录入日期 date
	enum_str_TBL_STRENEGTH_ROCK_FLD_GCEABD,                 // 室内编号 varchar
	enum_str_TBL_STRENEGTH_ROCK_FLD_TESTEQUIP,              // 试验仪器 varchar
	enum_str_TBL_STRENEGTH_ROCK_FLD_TESTMETHOD,             // 试验方法 varchar
	enum_str_TBL_STRENEGTH_ROCK_FLD_TESTBASED,              // 检验依据 varchar
	enum_str_TBL_STRENEGTH_ROCK_FLD_GCEAJC,                 // 试验单位 varchar
	enum_str_TBL_STRENEGTH_ROCK_FLD_SWFGAM,                 // 收样日期 date
	enum_str_TBL_STRENEGTH_ROCK_FLD_SWFGAN,                 // 报告日期 date
	enum_str_TBL_STRENEGTH_ROCK_FLD_GCEAJD,                 // 校对 varchar
	enum_str_TBL_STRENEGTH_ROCK_FLD_AUDITOR,                // 审核 varchar
	enum_str_TBL_STRENEGTH_ROCK_FLD_TESTLEADER,             // 试验负责人 varchar
	enum_str_TBL_STRENEGTH_ROCK_FLD__REPORT,                // 原始测试分析报告 varchar
	// 现场监测分析成果表
	enum_int_TBL_INSCENEEXPIDENT_FLD_SCENEEXPIDENTID, // 现场检测记录ID int
	enum_double_TBL_INSCENEEXPIDENT_FLD_TOPDEPTH,     // 检测顶深度 float
	enum_double_TBL_INSCENEEXPIDENT_FLD_BOTTOMDEPTH,  // 检测底深度 float
	enum_int_TBL_INSCENEEXPIDENT_FLD_PNTID,           // 点ID int
	enum_str_TBL_INSCENEEXPIDENT_FLD_SWFGAA,          // 采样层位 varchar
	enum_str_TBL_INSCENEEXPIDENT_FLD_TCMC,            // 土层名称 varchar
	enum_str_TBL_INSCENEEXPIDENT_FLD_GEOCODE,         // 地质代号 varchar
	enum_str_TBL_INSCENEEXPIDENT_FLD_PNTNO,           // 点号 varchar
	enum_str_TBL_INSCENEEXPIDENT_FLD_PKIAA,           // 项目编号 varchar
	enum_str_TBL_INSCENEEXPIDENT_FLD_DETECTIONTYPE,   // 检测类型 varchar
	enum_str_TBL_INSCENEEXPIDENT_FLD_TESTEQUIP,       // 检测仪器 varchar
	enum_str_TBL_INSCENEEXPIDENT_FLD_DETECTLEVEL,     // 检测层位 varchar
	enum_str_TBL_INSCENEEXPIDENT_FLD_TESTORGN,        // 检测单位 varchar
	enum_str_TBL_INSCENEEXPIDENT_FLD_TESTDATE,        // 检测日期 date
	enum_str_TBL_INSCENEEXPIDENT_FLD_INSPECTOR,       // 检测人 varchar
	enum_str_TBL_INSCENEEXPIDENT_FLD_DETECTINDEX,     // 检测指标 varchar
	enum_str_TBL_INSCENEEXPIDENT_FLD_CHEMICALCODE,    // 化学代号 varchar
	enum_str_TBL_INSCENEEXPIDENT_FLD_NUMERICALUNIT,   // 数值单位 varchar
	enum_str_TBL_INSCENEEXPIDENT_FLD_TESTRESULT,      // 检测结果 varchar
	// 监测仪器基本情况表
	enum_int_TBL_GEOENVMONITORDIVICE_FLD_MONITOREQUIPID,      // 监测仪器ID int
	enum_str_TBL_GEOENVMONITORDIVICE_FLD_EQUIPMENTNAME,       // 仪器名称 varchar
	enum_str_TBL_GEOENVMONITORDIVICE_FLD_EQUIPFACTORYCODE,    // 仪器出厂编码 varchar
	enum_str_TBL_GEOENVMONITORDIVICE_FLD_EQUIPFACTORYNAME,    // 仪器生产厂家 varchar
	enum_str_TBL_GEOENVMONITORDIVICE_FLD_MONITORINGINDEX,     // 监测指标 varchar
	enum_double_TBL_GEOENVMONITORDIVICE_FLD_PLACEDEPTH,       // 放置深度 float
	enum_str_TBL_GEOENVMONITORDIVICE_FLD_COLLECTINTERVAL,     // 数据采集间隔 varchar
	enum_str_TBL_GEOENVMONITORDIVICE_FLD_COLLECTINTERVALUNIT, // 间隔时间单位 varchar
	enum_str_TBL_GEOENVMONITORDIVICE_FLD_PROTECTEQUIP,        // 保护装置 varchar
	enum_int_TBL_GEOENVMONITORDIVICE_FLD_ISCALIBRATE,         // 是否较准 bool
	enum_str_TBL_GEOENVMONITORDIVICE_FLD_CALIBRATETYPE,       // 较准方式 varchar
	enum_str_TBL_GEOENVMONITORDIVICE_FLD_EQUIPSYSERROR,       // 仪器系统误差 varchar
	enum_str_TBL_GEOENVMONITORDIVICE_FLD_EQUIPFETCHTIME,      // 仪器取出时间 date
	enum_str_TBL_GEOENVMONITORDIVICE_FLD_EQUIPFETCHREASON,    // 仪器取出原因 varchar
	enum_str_TBL_GEOENVMONITORDIVICE_FLD_RUNNINGSTATE,        // 运行状态 varchar
	enum_str_TBL_GEOENVMONITORDIVICE_FLD_FIELDINSTALLIMAGE,   // 现场安装影像 varchar
	enum_str_TBL_GEOENVMONITORDIVICE_FLD_FIELDCALIBRATIMAGE,  // 现场较准影像 varchar
	enum_int_TBL_GEOENVMONITORDIVICE_FLD_PNTID,               // 点ID int
	enum_str_TBL_GEOENVMONITORDIVICE_FLD_MONITORPNTTYPE,      // 监测点类型 varchar
	enum_str_TBL_GEOENVMONITORDIVICE_FLD_MONITOROBJ,          // 监测对象 varchar
	enum_str_TBL_GEOENVMONITORDIVICE_FLD_MONITORCONTENT,      // 监测内容 varchar
	enum_str_TBL_GEOENVMONITORDIVICE_FLD_MONITORTYPE,         // 监测方式 varchar
	enum_str_TBL_GEOENVMONITORDIVICE_FLD_MONITORSETDATE,      // 监测点设置日期 date
	enum_str_TBL_GEOENVMONITORDIVICE_FLD_PLANEPOSMAP,         // 平面位置示意图 varchar
	enum_str_TBL_GEOENVMONITORDIVICE_FLD_PROFILEMAP,          // 剖面示意图 varchar
	enum_str_TBL_GEOENVMONITORDIVICE_FLD_MONITORDATADOCID,    // 监测数据文档ID varchar
	enum_str_TBL_GEOENVMONITORDIVICE_FLD_MONITORPNTIMAGE,     // 监测点照片(视频) varchar
	enum_str_TBL_GEOENVMONITORDIVICE_FLD_RECORDCARD,          // 记录卡片(记录) varchar
	enum_str_TBL_GEOENVMONITORDIVICE_FLD_MONITOROGRN,         // 监测单位 varchar
	enum_str_TBL_GEOENVMONITORDIVICE_FLD_CHARGE,              // 负责人 varchar
	enum_str_TBL_GEOENVMONITORDIVICE_FLD_INPUTER,             // 录入单位 varchar
	enum_str_TBL_GEOENVMONITORDIVICE_FLD_INPUTORGN,           // 录入员 varchar
	enum_str_TBL_GEOENVMONITORDIVICE_FLD_INPUTDATE,           // 录入日期 date
	// 地下水位水温监测数据表
	enum_int_TBL_GEOENVMONITOLEVELTEMP_FLD_LEVELTEMPID,      // 水位水温监测ID int
	enum_str_TBL_GEOENVMONITOLEVELTEMP_FLD_MONITORDATE,      // 监测时间 date
	enum_str_TBL_GEOENVMONITOLEVELTEMP_FLD_TKDAE,            // 天气 varchar
	enum_double_TBL_GEOENVMONITOLEVELTEMP_FLD_SWEGAB,        // 水位埋深 float
	enum_double_TBL_GEOENVMONITOLEVELTEMP_FLD_GCKUGF,        // 深度 float
	enum_double_TBL_GEOENVMONITOLEVELTEMP_FLD_SWADET,        // 水温 float
	enum_double_TBL_GEOENVMONITOLEVELTEMP_FLD_SWADBB,        // 气温 float
	enum_int_TBL_GEOENVMONITOLEVELTEMP_FLD_PNTID,            // 点ID int
	enum_str_TBL_GEOENVMONITOLEVELTEMP_FLD_MONITORPNTTYPE,   // 监测点类型 varchar
	enum_str_TBL_GEOENVMONITOLEVELTEMP_FLD_MONITOROBJ,       // 监测对象 varchar
	enum_str_TBL_GEOENVMONITOLEVELTEMP_FLD_MONITORCONTENT,   // 监测内容 varchar
	enum_str_TBL_GEOENVMONITOLEVELTEMP_FLD_MONITORTYPE,      // 监测方式 varchar
	enum_str_TBL_GEOENVMONITOLEVELTEMP_FLD_MONITORSETDATE,   // 监测点设置日期 date
	enum_str_TBL_GEOENVMONITOLEVELTEMP_FLD_PLANEPOSMAP,      // 平面位置示意图 varchar
	enum_str_TBL_GEOENVMONITOLEVELTEMP_FLD_PROFILEMAP,       // 剖面示意图 varchar
	enum_str_TBL_GEOENVMONITOLEVELTEMP_FLD_MONITORDATADOCID, // 监测数据文档ID varchar
	enum_str_TBL_GEOENVMONITOLEVELTEMP_FLD_MONITORPNTIMAGE,  // 监测点照片(视频) varchar
	enum_str_TBL_GEOENVMONITOLEVELTEMP_FLD_RECORDCARD,       // 记录卡片(记录) varchar
	enum_str_TBL_GEOENVMONITOLEVELTEMP_FLD_MONITOROGRN,      // 监测单位 varchar
	enum_str_TBL_GEOENVMONITOLEVELTEMP_FLD_CHARGE,           // 负责人 varchar
	enum_str_TBL_GEOENVMONITOLEVELTEMP_FLD_INPUTER,          // 录入单位 varchar
	enum_str_TBL_GEOENVMONITOLEVELTEMP_FLD_INPUTORGN,        // 录入员 varchar
	enum_str_TBL_GEOENVMONITOLEVELTEMP_FLD_INPUTDATE,        // 录入日期 date
	// （堰槽法）流量监测数据表
	enum_int_TBL_GEOENVWEIRMONITOFLOW_FLD_WEIRMONITOFLOWID, // 堰槽流量监测ID int
	enum_str_TBL_GEOENVWEIRMONITOFLOW_FLD_MONITORDATE,      // 监测时间 date
	enum_str_TBL_GEOENVWEIRMONITOFLOW_FLD_WEIRTYPE,         // 堰槽类型 varchar
	enum_double_TBL_GEOENVWEIRMONITOFLOW_FLD_WEIRREADING,   // 堰槽读数 float
	enum_str_TBL_GEOENVWEIRMONITOFLOW_FLD_FLOWUNIT,         // 流量单位 varchar
	enum_double_TBL_GEOENVWEIRMONITOFLOW_FLD__FLOW,         // 流量 float
	enum_int_TBL_GEOENVWEIRMONITOFLOW_FLD_PNTID,            // 点ID int
	enum_str_TBL_GEOENVWEIRMONITOFLOW_FLD_MONITORPNTTYPE,   // 监测点类型 varchar
	enum_str_TBL_GEOENVWEIRMONITOFLOW_FLD_MONITOROBJ,       // 监测对象 varchar
	enum_str_TBL_GEOENVWEIRMONITOFLOW_FLD_MONITORCONTENT,   // 监测内容 varchar
	enum_str_TBL_GEOENVWEIRMONITOFLOW_FLD_MONITORTYPE,      // 监测方式 varchar
	enum_str_TBL_GEOENVWEIRMONITOFLOW_FLD_MONITORSETDATE,   // 监测点设置日期 date
	enum_str_TBL_GEOENVWEIRMONITOFLOW_FLD_PLANEPOSMAP,      // 平面位置示意图 varchar
	enum_str_TBL_GEOENVWEIRMONITOFLOW_FLD_PROFILEMAP,       // 剖面示意图 varchar
	enum_str_TBL_GEOENVWEIRMONITOFLOW_FLD_MONITORDATADOCID, // 监测数据文档ID varchar
	enum_str_TBL_GEOENVWEIRMONITOFLOW_FLD_MONITORPNTIMAGE,  // 监测点照片(视频) varchar
	enum_str_TBL_GEOENVWEIRMONITOFLOW_FLD_RECORDCARD,       // 记录卡片(记录) varchar
	enum_str_TBL_GEOENVWEIRMONITOFLOW_FLD_MONITOROGRN,      // 监测单位 varchar
	enum_str_TBL_GEOENVWEIRMONITOFLOW_FLD_CHARGE,           // 负责人 varchar
	enum_str_TBL_GEOENVWEIRMONITOFLOW_FLD_INPUTER,          // 录入单位 varchar
	enum_str_TBL_GEOENVWEIRMONITOFLOW_FLD_INPUTORGN,        // 录入员 varchar
	enum_str_TBL_GEOENVWEIRMONITOFLOW_FLD_INPUTDATE,        // 录入日期 date
	// 监测断面测点数据表
	enum_int_TBL_GEOENVMONITOSECTPNT_FLD_TESTFLOWPNTID,       // 测流点ID int
	enum_str_TBL_GEOENVMONITOSECTPNT_FLD_TESTFLOWPNTNO,       // 测流点编号 varchar
	enum_double_TBL_GEOENVMONITOSECTPNT_FLD_DISTANCE,         // 与起始点距离 float
	enum_double_TBL_GEOENVMONITOSECTPNT_FLD_TESTPNTDEPTH,     // 测点深度 float
	enum_double_TBL_GEOENVMONITOSECTPNT_FLD_EQUIPREADING,     // 仪器读数 float
	enum_str_TBL_GEOENVMONITOSECTPNT_FLD_MEASUREUNIT,         // 计量单位 varchar
	enum_double_TBL_GEOENVMONITOSECTPNT_FLD_FLOWRATE,         // 流速 float
	enum_str_TBL_GEOENVMONITOSECTPNT_FLD_FLOWRATEUNIT,        // 流速单位 varchar
	enum_double_TBL_GEOENVMONITOSECTPNT_FLD_SECTIONAREA,      // 代表断面面积 float
	enum_double_TBL_GEOENVMONITOSECTPNT_FLD_SECTIONWATERFLOW, // 代表断面流量 float
	enum_str_TBL_GEOENVMONITOSECTPNT_FLD_MONITORDATE,         // 监测时间 date
	enum_str_TBL_GEOENVMONITOSECTPNT_FLD_MONITORFLOWEQUIP,    // 测流仪器 varchar
	enum_str_TBL_GEOENVMONITOSECTPNT_FLD_DEVICETYPE,          // 仪器型号 varchar
	enum_double_TBL_GEOENVMONITOSECTPNT_FLD_SECTIONWIDTH,     // 断面宽度 float
	enum_double_TBL_GEOENVMONITOSECTPNT_FLD_AVERAGEVELOCITY,  // 平均流速 float
	enum_str_TBL_GEOENVMONITOSECTPNT_FLD_VELOCITYUNIT,        // 流速单位 varchar
	enum_double_TBL_GEOENVMONITOSECTPNT_FLD_AVERAGEFLOW,      // 平均流量 float
	enum_str_TBL_GEOENVMONITOSECTPNT_FLD_FLOWUNIT,            // 流量单位 varchar
	enum_int_TBL_GEOENVMONITOSECTPNT_FLD_PNTID,               // 点ID int
	enum_str_TBL_GEOENVMONITOSECTPNT_FLD_MONITORPNTTYPE,      // 监测点类型 varchar
	enum_str_TBL_GEOENVMONITOSECTPNT_FLD_MONITOROBJ,          // 监测对象 varchar
	enum_str_TBL_GEOENVMONITOSECTPNT_FLD_MONITORCONTENT,      // 监测内容 varchar
	enum_str_TBL_GEOENVMONITOSECTPNT_FLD_MONITORTYPE,         // 监测方式 varchar
	enum_str_TBL_GEOENVMONITOSECTPNT_FLD_MONITORSETDATE,      // 监测点设置日期 date
	enum_str_TBL_GEOENVMONITOSECTPNT_FLD_PLANEPOSMAP,         // 平面位置示意图 varchar
	enum_str_TBL_GEOENVMONITOSECTPNT_FLD_PROFILEMAP,          // 剖面示意图 varchar
	enum_str_TBL_GEOENVMONITOSECTPNT_FLD_MONITORDATADOCID,    // 监测数据文档ID varchar
	enum_str_TBL_GEOENVMONITOSECTPNT_FLD_MONITORPNTIMAGE,     // 监测点照片(视频) varchar
	enum_str_TBL_GEOENVMONITOSECTPNT_FLD_RECORDCARD,          // 记录卡片(记录) varchar
	enum_str_TBL_GEOENVMONITOSECTPNT_FLD_MONITOROGRN,         // 监测单位 varchar
	enum_str_TBL_GEOENVMONITOSECTPNT_FLD_CHARGE,              // 负责人 varchar
	enum_str_TBL_GEOENVMONITOSECTPNT_FLD_INPUTER,             // 录入单位 varchar
	enum_str_TBL_GEOENVMONITOSECTPNT_FLD_INPUTORGN,           // 录入员 varchar
	enum_str_TBL_GEOENVMONITOSECTPNT_FLD_INPUTDATE,           // 录入日期 date
	// 地下水开采量监测数据表
	enum_int_TBL_GEOENVWATEREXTRACT_FLD_EXPLOITATMONITORID, // 开采量监测ID int
	enum_str_TBL_GEOENVWATEREXTRACT_FLD_MONITORDATE,        // 监测时间 date
	enum_double_TBL_GEOENVWATEREXTRACT_FLD_EQUIPREADING,    // 仪器读数 float
	enum_double_TBL_GEOENVWATEREXTRACT_FLD_EXPLOITATION,    // 开采量 float
	enum_str_TBL_GEOENVWATEREXTRACT_FLD_EXPLOITATIONUINT,   // 开采量单位 varchar
	enum_int_TBL_GEOENVWATEREXTRACT_FLD_PNTID,              // 点ID int
	enum_str_TBL_GEOENVWATEREXTRACT_FLD_MONITORPNTTYPE,     // 监测点类型 varchar
	enum_str_TBL_GEOENVWATEREXTRACT_FLD_MONITOROBJ,         // 监测对象 varchar
	enum_str_TBL_GEOENVWATEREXTRACT_FLD_MONITORCONTENT,     // 监测内容 varchar
	enum_str_TBL_GEOENVWATEREXTRACT_FLD_MONITORTYPE,        // 监测方式 varchar
	enum_str_TBL_GEOENVWATEREXTRACT_FLD_MONITORSETDATE,     // 监测点设置日期 date
	enum_str_TBL_GEOENVWATEREXTRACT_FLD_PLANEPOSMAP,        // 平面位置示意图 varchar
	enum_str_TBL_GEOENVWATEREXTRACT_FLD_PROFILEMAP,         // 剖面示意图 varchar
	enum_str_TBL_GEOENVWATEREXTRACT_FLD_MONITORDATADOCID,   // 监测数据文档ID varchar
	enum_str_TBL_GEOENVWATEREXTRACT_FLD_MONITORPNTIMAGE,    // 监测点照片(视频) varchar
	enum_str_TBL_GEOENVWATEREXTRACT_FLD_RECORDCARD,         // 记录卡片(记录) varchar
	enum_str_TBL_GEOENVWATEREXTRACT_FLD_MONITOROGRN,        // 监测单位 varchar
	enum_str_TBL_GEOENVWATEREXTRACT_FLD_CHARGE,             // 负责人 varchar
	enum_str_TBL_GEOENVWATEREXTRACT_FLD_INPUTER,            // 录入单位 varchar
	enum_str_TBL_GEOENVWATEREXTRACT_FLD_INPUTORGN,          // 录入员 varchar
	enum_str_TBL_GEOENVWATEREXTRACT_FLD_INPUTDATE,          // 录入日期 date
	// 地面沉降监测数据表
	enum_int_TBL_GEOENVLANDSUBSIDENCE_FLD_SUBSIDENCEID,     // 沉降监测ID int
	enum_str_TBL_GEOENVLANDSUBSIDENCE_FLD_MONITORDATE,      // 监测时间 date
	enum_double_TBL_GEOENVLANDSUBSIDENCE_FLD_GCJCBJ,        // 高程 double
	enum_str_TBL_GEOENVLANDSUBSIDENCE_FLD_GCJCBJSYS,        // 高程系统 varchar
	enum_double_TBL_GEOENVLANDSUBSIDENCE_FLD_SETTLEMENT,    // 沉降量 double
	enum_int_TBL_GEOENVLANDSUBSIDENCE_FLD_PNTID,            // 点ID int
	enum_str_TBL_GEOENVLANDSUBSIDENCE_FLD_MONITORPNTTYPE,   // 监测点类型 varchar
	enum_str_TBL_GEOENVLANDSUBSIDENCE_FLD_MONITOROBJ,       // 监测对象 varchar
	enum_str_TBL_GEOENVLANDSUBSIDENCE_FLD_MONITORCONTENT,   // 监测内容 varchar
	enum_str_TBL_GEOENVLANDSUBSIDENCE_FLD_MONITORTYPE,      // 监测方式 varchar
	enum_str_TBL_GEOENVLANDSUBSIDENCE_FLD_MONITORSETDATE,   // 监测点设置日期 date
	enum_str_TBL_GEOENVLANDSUBSIDENCE_FLD_PLANEPOSMAP,      // 平面位置示意图 varchar
	enum_str_TBL_GEOENVLANDSUBSIDENCE_FLD_PROFILEMAP,       // 剖面示意图 varchar
	enum_str_TBL_GEOENVLANDSUBSIDENCE_FLD_MONITORDATADOCID, // 监测数据文档ID varchar
	enum_str_TBL_GEOENVLANDSUBSIDENCE_FLD_MONITORPNTIMAGE,  // 监测点照片(视频) varchar
	enum_str_TBL_GEOENVLANDSUBSIDENCE_FLD_RECORDCARD,       // 记录卡片(记录) varchar
	enum_str_TBL_GEOENVLANDSUBSIDENCE_FLD_MONITOROGRN,      // 监测单位 varchar
	enum_str_TBL_GEOENVLANDSUBSIDENCE_FLD_CHARGE,           // 负责人 varchar
	enum_str_TBL_GEOENVLANDSUBSIDENCE_FLD_INPUTER,          // 录入单位 varchar
	enum_str_TBL_GEOENVLANDSUBSIDENCE_FLD_INPUTORGN,        // 录入员 varchar
	enum_str_TBL_GEOENVLANDSUBSIDENCE_FLD_INPUTDATE,        // 录入日期 date
	// 孔隙水压力监测数据表
	enum_int_TBL_GEOENVPOREWATER_FLD_POREWATERID,      // 孔隙水压监测ID int
	enum_str_TBL_GEOENVPOREWATER_FLD_MONITORDATE,      // 监测时间 date
	enum_double_TBL_GEOENVPOREWATER_FLD_GCKUGF,        // 深度 float
	enum_double_TBL_GEOENVPOREWATER_FLD_EQUIPREADING,  // 仪器读数 float
	enum_double_TBL_GEOENVPOREWATER_FLD_WATERPRESSURE, // 水压 float
	enum_int_TBL_GEOENVPOREWATER_FLD_PNTID,            // 点ID int
	enum_str_TBL_GEOENVPOREWATER_FLD_MONITORPNTTYPE,   // 监测点类型 varchar
	enum_str_TBL_GEOENVPOREWATER_FLD_MONITOROBJ,       // 监测对象 varchar
	enum_str_TBL_GEOENVPOREWATER_FLD_MONITORCONTENT,   // 监测内容 varchar
	enum_str_TBL_GEOENVPOREWATER_FLD_MONITORTYPE,      // 监测方式 varchar
	enum_str_TBL_GEOENVPOREWATER_FLD_MONITORSETDATE,   // 监测点设置日期 date
	enum_str_TBL_GEOENVPOREWATER_FLD_PLANEPOSMAP,      // 平面位置示意图 varchar
	enum_str_TBL_GEOENVPOREWATER_FLD_PROFILEMAP,       // 剖面示意图 varchar
	enum_str_TBL_GEOENVPOREWATER_FLD_MONITORDATADOCID, // 监测数据文档ID varchar
	enum_str_TBL_GEOENVPOREWATER_FLD_MONITORPNTIMAGE,  // 监测点照片(视频) varchar
	enum_str_TBL_GEOENVPOREWATER_FLD_RECORDCARD,       // 记录卡片(记录) varchar
	enum_str_TBL_GEOENVPOREWATER_FLD_MONITOROGRN,      // 监测单位 varchar
	enum_str_TBL_GEOENVPOREWATER_FLD_CHARGE,           // 负责人 varchar
	enum_str_TBL_GEOENVPOREWATER_FLD_INPUTER,          // 录入单位 varchar
	enum_str_TBL_GEOENVPOREWATER_FLD_INPUTORGN,        // 录入员 varchar
	enum_str_TBL_GEOENVPOREWATER_FLD_INPUTDATE,        // 录入日期 date
	// 地应力监测数据表
	enum_int_TBL_GEOENVGROUNDSTRESS_FLD_GROUNDSTRESSID,   // 地应力监测ID int
	enum_str_TBL_GEOENVGROUNDSTRESS_FLD_MONITORDATE,      // 监测时间 date
	enum_double_TBL_GEOENVGROUNDSTRESS_FLD_GCKUGF,        // 深度 float
	enum_double_TBL_GEOENVGROUNDSTRESS_FLD_EQUIPREADING,  // 仪器读数 float
	enum_double_TBL_GEOENVGROUNDSTRESS_FLD_STRESSVALUE,   // 应力值 float
	enum_int_TBL_GEOENVGROUNDSTRESS_FLD_PNTID,            // 点ID int
	enum_str_TBL_GEOENVGROUNDSTRESS_FLD_MONITORPNTTYPE,   // 监测点类型 varchar
	enum_str_TBL_GEOENVGROUNDSTRESS_FLD_MONITOROBJ,       // 监测对象 varchar
	enum_str_TBL_GEOENVGROUNDSTRESS_FLD_MONITORCONTENT,   // 监测内容 varchar
	enum_str_TBL_GEOENVGROUNDSTRESS_FLD_MONITORTYPE,      // 监测方式 varchar
	enum_str_TBL_GEOENVGROUNDSTRESS_FLD_MONITORSETDATE,   // 监测点设置日期 date
	enum_str_TBL_GEOENVGROUNDSTRESS_FLD_PLANEPOSMAP,      // 平面位置示意图 varchar
	enum_str_TBL_GEOENVGROUNDSTRESS_FLD_PROFILEMAP,       // 剖面示意图 varchar
	enum_str_TBL_GEOENVGROUNDSTRESS_FLD_MONITORDATADOCID, // 监测数据文档ID varchar
	enum_str_TBL_GEOENVGROUNDSTRESS_FLD_MONITORPNTIMAGE,  // 监测点照片(视频) varchar
	enum_str_TBL_GEOENVGROUNDSTRESS_FLD_RECORDCARD,       // 记录卡片(记录) varchar
	enum_str_TBL_GEOENVGROUNDSTRESS_FLD_MONITOROGRN,      // 监测单位 varchar
	enum_str_TBL_GEOENVGROUNDSTRESS_FLD_CHARGE,           // 负责人 varchar
	enum_str_TBL_GEOENVGROUNDSTRESS_FLD_INPUTER,          // 录入单位 varchar
	enum_str_TBL_GEOENVGROUNDSTRESS_FLD_INPUTORGN,        // 录入员 varchar
	enum_str_TBL_GEOENVGROUNDSTRESS_FLD_INPUTDATE,        // 录入日期 date
	// 降雨量监测数据表
	enum_int_TBL_GEOENVRAINFALL_FLD_RAINFALLID,       // 降雨量监测ID int
	enum_str_TBL_GEOENVRAINFALL_FLD_MONITORDATE,      // 监测时间 date
	enum_double_TBL_GEOENVRAINFALL_FLD_EQUIPREADING,  // 仪器读数 float
	enum_str_TBL_GEOENVRAINFALL_FLD_COUNTUNIT,        // 计数单位 varchar
	enum_double_TBL_GEOENVRAINFALL_FLD_TIMEINTERVAL,  // 时间间隔 double
	enum_double_TBL_GEOENVRAINFALL_FLD_RAINFALL,      // 降雨量 double
	enum_str_TBL_GEOENVRAINFALL_FLD_RAINFALLUNIT,     // 降雨量单位 varchar
	enum_int_TBL_GEOENVRAINFALL_FLD_PNTID,            // 点ID int
	enum_str_TBL_GEOENVRAINFALL_FLD_MONITORPNTTYPE,   // 监测点类型 varchar
	enum_str_TBL_GEOENVRAINFALL_FLD_MONITOROBJ,       // 监测对象 varchar
	enum_str_TBL_GEOENVRAINFALL_FLD_MONITORCONTENT,   // 监测内容 varchar
	enum_str_TBL_GEOENVRAINFALL_FLD_MONITORTYPE,      // 监测方式 varchar
	enum_str_TBL_GEOENVRAINFALL_FLD_MONITORSETDATE,   // 监测点设置日期 date
	enum_str_TBL_GEOENVRAINFALL_FLD_PLANEPOSMAP,      // 平面位置示意图 varchar
	enum_str_TBL_GEOENVRAINFALL_FLD_PROFILEMAP,       // 剖面示意图 varchar
	enum_str_TBL_GEOENVRAINFALL_FLD_MONITORDATADOCID, // 监测数据文档ID varchar
	enum_str_TBL_GEOENVRAINFALL_FLD_MONITORPNTIMAGE,  // 监测点照片(视频) varchar
	enum_str_TBL_GEOENVRAINFALL_FLD_RECORDCARD,       // 记录卡片(记录) varchar
	enum_str_TBL_GEOENVRAINFALL_FLD_MONITOROGRN,      // 监测单位 varchar
	enum_str_TBL_GEOENVRAINFALL_FLD_CHARGE,           // 负责人 varchar
	enum_str_TBL_GEOENVRAINFALL_FLD_INPUTER,          // 录入单位 varchar
	enum_str_TBL_GEOENVRAINFALL_FLD_INPUTORGN,        // 录入员 varchar
	enum_str_TBL_GEOENVRAINFALL_FLD_INPUTDATE,        // 录入日期 date
	// 蒸发量监测数据表
	enum_int_TBL_GEOENVEVAPORATION_FLD_EVAPORATIONID,    // 蒸发量监测ID int
	enum_str_TBL_GEOENVEVAPORATION_FLD_MONITORDATE,      // 监测时间 date
	enum_double_TBL_GEOENVEVAPORATION_FLD_EQUIPREADING,  // 仪器读数 float
	enum_str_TBL_GEOENVEVAPORATION_FLD_COUNTUNIT,        // 计数单位 varchar
	enum_double_TBL_GEOENVEVAPORATION_FLD_TIMEINTERVAL,  // 时间间隔 double
	enum_double_TBL_GEOENVEVAPORATION_FLD_EVAPORATION,   // 蒸发量 double
	enum_str_TBL_GEOENVEVAPORATION_FLD_EVAPORATEUNIT,    // 蒸发量单位 varchar
	enum_int_TBL_GEOENVEVAPORATION_FLD_PNTID,            // 点ID int
	enum_str_TBL_GEOENVEVAPORATION_FLD_MONITORPNTTYPE,   // 监测点类型 varchar
	enum_str_TBL_GEOENVEVAPORATION_FLD_MONITOROBJ,       // 监测对象 varchar
	enum_str_TBL_GEOENVEVAPORATION_FLD_MONITORCONTENT,   // 监测内容 varchar
	enum_str_TBL_GEOENVEVAPORATION_FLD_MONITORTYPE,      // 监测方式 varchar
	enum_str_TBL_GEOENVEVAPORATION_FLD_MONITORSETDATE,   // 监测点设置日期 date
	enum_str_TBL_GEOENVEVAPORATION_FLD_PLANEPOSMAP,      // 平面位置示意图 varchar
	enum_str_TBL_GEOENVEVAPORATION_FLD_PROFILEMAP,       // 剖面示意图 varchar
	enum_str_TBL_GEOENVEVAPORATION_FLD_MONITORDATADOCID, // 监测数据文档ID varchar
	enum_str_TBL_GEOENVEVAPORATION_FLD_MONITORPNTIMAGE,  // 监测点照片(视频) varchar
	enum_str_TBL_GEOENVEVAPORATION_FLD_RECORDCARD,       // 记录卡片(记录) varchar
	enum_str_TBL_GEOENVEVAPORATION_FLD_MONITOROGRN,      // 监测单位 varchar
	enum_str_TBL_GEOENVEVAPORATION_FLD_CHARGE,           // 负责人 varchar
	enum_str_TBL_GEOENVEVAPORATION_FLD_INPUTER,          // 录入单位 varchar
	enum_str_TBL_GEOENVEVAPORATION_FLD_INPUTORGN,        // 录入员 varchar
	enum_str_TBL_GEOENVEVAPORATION_FLD_INPUTDATE         // 录入日期 date
} FieldMacro;


	//属性数据库的表和字段定义初始化类
	class S3D_ATT_DBENGINE_API s3d_AttDbTblFldDef :public DbTblFldDef
	{
	public:
		static s3d_AttDbTblFldDef* getSingletonPtr();
	
	public:
		 void forceInitDbMap() override;//强制初始化,给s3dMdlContainer赋值
	};

}
#endif // !S3d_ATTDBTBLFLDDEF__
