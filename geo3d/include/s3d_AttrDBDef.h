#ifndef __S3D_ATTRDEF_H__
#define __S3D_ATTRDEF_H__

#include <vector>
#include <string>
#include <unordered_map>

#include <gme_vector2.h>
#include <gme_vector3.h>
#include <gme_vector4.h>

namespace Smart3dMap
{
	typedef unsigned long ulong;
	typedef unsigned int uint;
	typedef unsigned short ushort;

	//标准地层描述表-基类 *
	struct  s3d_BaseLayer
	{
	public:
		long m_stdID;                 //* 标准地层版本ID		int		FK
		std::string m_stratName;      //地层名称（例如：第四纪）
		std::string m_strStratOrder;  //地层分级编号（如1-1-1）varchar
		std::string m_stratCode;      //地层编码（Q1,J2,①）	varchar
		std::string m_stratCode2;     //地层编码2（用于地层合并整理）	varchar
		int m_stratType;              //地层类型				int
		uint m_rgbColor;              //地层颜色				int
		std::string m_stratPatternNo; // 图案号				text (注意)
		uint m_stratPatternClrNo;     //地层图案颜色号
		float m_patternHeight;        // 图案高度				Float
		float m_patternWidth;         // 图案宽度				Float
		float m_fillDir;              // 图案旋转方向			Float
		std::string m_clrMatName;     //颜色材质
		std::string m_texMatName;     //纹理材质
		//以下内存使用
		std::string m_stratLevel;    //地层级别编码（例如：010200）
		std::string m_oriStratLevel; //更新后的地层编码(无须用户传入)
		int m_nLayerIndex;           //该层对应的标准地层索引号：0,1,2，...
		int m_stratRepeatNum;        //该层重复出现的次数

		long ID;					//* 标准地层分层记录ID	int			PK -- LH.2021.08.30 20:22 added.

		s3d_BaseLayer()
		{
			m_stdID = 1;
			m_stratName = "";
			m_strStratOrder = "";
			m_stratCode = "";
			m_stratCode2 = "";
			m_stratType = 0;  //地层类型(决定地层的连接方式)
			m_rgbColor = 255; //地层颜色(第一个字节为0，后三个字节分别为rgb)
			m_stratPatternNo = "";
			m_stratPatternClrNo = 255;
			m_patternHeight = 32;
			m_patternWidth = 32;
			m_fillDir = 0;
			m_clrMatName = ""; //颜色材质
			m_texMatName = ""; //纹理材质
			m_stratLevel = "";
			m_oriStratLevel = "";
			m_nLayerIndex = -1;
			m_stratRepeatNum = 1;
		}

		bool operator<(const s3d_BaseLayer &obj) const
		{
			if (m_oriStratLevel != obj.m_oriStratLevel)
				return (m_oriStratLevel < obj.m_oriStratLevel);
			else
				return false;
		}
	};

	//钻孔标准分层表-基类 *
	struct  s3d_BoreHoleLayer
	{
	public:
		int m_nHoleID;               //* 钻孔ID
		double m_dTop;               //层顶标高
		double m_dBottom;            //层底标高
		std::string m_stratName;     //地层名称（例如：第四纪全新世）
		std::string m_stratCode;     //* 地层编码
		std::string m_stratLevel;    //地层级别编码（例如：010200）        来自标准地层描述表 -- LH.2021.08.05 10:48 comment added.
		std::string m_oriStratLevel; //更新后的地层编码(无须用户传入)
		std::string m_strStratOrder; //地层顺序                            来自标准地层描述表 -- LH.2021.08.05 10:48 comment added.
		uint m_rgbColor;             //颜色                                来自标准地层描述表 -- LH.2021.08.05 10:48 comment added.
		char m_LayerType;            //分层类型：1存在/2最后一层/0缺失/3延展存在/4延展缺失

		char m_cLayerFlag;     //该层的存在标志：1真实层/0虚拟缺失层
		char m_bUsed;          //是否已经遍历
		int m_stratRepeatNum;  //该层重复出现的次数
		int m_nLayerIndex;     //该层对应的标准地层索引号：0,1,2，...
		std::string m_strYtmc; //岩土名称
		std::string m_strDzsd; //地质时代
		std::string m_strDcms; //地层描述

		s3d_BoreHoleLayer()
		{
			m_nHoleID = 0;     //钻孔内部ID
			m_dTop = 0.0;      //层顶标高
			m_dBottom = 0.0;   //层底标高
			m_stratName = "";  //地层名称（例如：第四纪全新世）
			m_stratCode = "";  //地层编码（例如：Qh）
			m_stratLevel = ""; //地层级别编码（例如：010200）
			m_oriStratLevel = "";
			m_strStratOrder = ""; //地层顺序
			m_rgbColor = 0;       //颜色
			m_LayerType = 0;      //分层类型：1存在/2最后一层/3缺失/4延展存在/5延展缺失
			m_cLayerFlag = 1;     //该层的存在标志：1真实层/0虚拟缺失层
			m_bUsed = 0;          //是否已经遍历
			m_stratRepeatNum = 1; //该层重复出现的次数
			m_nLayerIndex = -1;   //该层对应的标准地层索引号：0,1,2，...
			m_strYtmc = "";       //岩土名称
			m_strDzsd = "";       //地质时代
			m_strDcms = "";
		}
	};

	//钻孔基本信息表-基类
	struct  s3d_BoreHole
	{
	public:
		int m_PrjID;                                //*项目ID			int
		int m_nHoleID;                              //* 钻孔ID			int PK
		std::string m_strHoleCode;                  //* 钻孔编码		varchar
		double m_dx;                                //* X				double
		double m_dy;                                //* Y				double
		double m_dHoleTop;                          //* 孔口标高		double
		double m_dHoleBott;                         //*孔底标高 = 孔口标高-孔深 double
		char m_cExFlg;                              //存在标志：1存在/0不存在
		char m_cHoleType;                           //* 钻孔类型		int（0虚拟孔、1真实孔）
		short m_holeLevel;                          //钻孔级别			int
		std::vector<s3d_BoreHoleLayer> m_LayerList; //钻孔所有分层列表

		s3d_BoreHole()
		{
			m_dx = 0.0;         //X坐标
			m_dy = 0.0;         //Y坐标
			m_PrjID = 0;        //项目ID
			m_nHoleID = 0;      //钻孔内部ID
			m_strHoleCode = ""; //钻孔编码
			m_dHoleTop = 0.0;   //孔口标高
			m_dHoleBott = 0.0;  //孔底标高
			m_cExFlg = 1;       //存在标志：1存在/0不存在
			m_cHoleType = 1;    //钻孔类型：1真实孔/0虚拟孔
			m_holeLevel = 1;
			m_LayerList.reserve(0); //钻孔所有分层列表
		}
	};

	// 档案来源单位表 *
	struct  Bas_DocOrganization
	{
	public:
		long OrgnID;               //* 单位ID    int
		std::string OrgnCode;      // 单位代号    varchar
		std::string OrgnName;      //* 单位名称    varchar
		std::string OrgnCharge;    // 单位负责人    varchar
		std::string OrgnDuty;      // 单位职责    varchar
		std::string OrgnTelNo;     // 单位电话    varchar
		std::string DocAdminName;  // 档案管理员姓名    varchar
		std::string DocAdminTelNo; // 档案管理员电话    varchar
		std::string OrgnAddr;      // 详细地址    varchar
		std::string OrgnCity;      // 城市    varchar
		std::string OrgnDist;      // 行政区    varchar
		std::string OrgnCountry;   // 国家    varchar
		std::string OrgnZipCode;   // 邮政编码    varchar
	};

	// 项目登记表 *
	struct  Bas_PrjRegistration
	{
	public:
		long PrjID;                 //* 项目ID    int
		std::string PrjCode;        // 项目编号    varchar
		std::string PrjName;        //* 项目(报告)名称    varchar
		std::string PrjRelUrl;      // 项目关联资料Url    varchar
		long OrgnID;                //* 单位ID    int
		std::string BatchNo;        // 资料批次    varchar
		std::string PrjType;        // 项目类型    varchar
		std::string ProType;        // 专业类别    varchar
		std::string PrjStatus;      // 项目运行状况    varchar
		std::string DocDelivStatus; // 档案汇交状况    varchar
		std::string PrjCharge;      // 项目负责人    varchar
		std::string PrjChargeTelNo; // 项目负责人电话    varchar
		std::string PrjOrgn;        // 项目承担单位    varchar
		std::string PrjStartTime;   // 项目起始日期    date
		std::string PrjEndTime;     // 项目完成日期    date
		std::string PrjRegister;    // 登记人    varchar
		std::string PrjRegistUnit;  // 登记单位    varchar
		std::string PrjRegistDate;  // 登记日期    date
	};

	// 点位信息表 *
	struct  Bas_PntStdInfo
	{
	public:
		long PntID;                       //* 标准点位ID    int
		double X;                         //* 标准化X(m)    double
		double Y;                         //* 标准化Y(m)    double
		double Z;                         //* 标准化高程(m)    double
		std::string stdCoorSys;           // 标准化坐标系    varchar
		std::string stdElDatum;           // 标准化高程基准    varchar
		long PrjId;                       //* 项目ID    int
		std::string OriPntCode;           //* 原始点编号    varchar
		long IsVirtualPnt;                //* 是否虚拟点    int
		long IsMonitorPnt;                //* 是否监测点    int
		std::string Class1_Name;          //* 一级分类名    varchar
		std::string Class2_Name;          //* 二级分类名    varchar
		double OriPnt_X;                  //* X    double
		double OriPnt_Y;                  //* Y    double
		double OriPnt_Z;                  //* 高程    double
		double OriPnt_Logitude;           // 经度    double
		double OriPnt_Latitude;           // 纬度    double
		std::string OriPnt_PlaneCoordSys; // 平面坐标系    varchar
		std::string OriPnt_EleDatum;      // 高程基准    varchar
		std::string OriPnt_DDADC;         // 地理位置    varchar
		std::string SCHAMAA;              // 标准图幅名称    varchar
		std::string SCHAMAC;              // 标准图幅编号    varchar
	};

	// 钻孔登记审核表 *
	struct  HoleRegister
	{
	public:
		long HoleRegID;               //* 钻孔登记ID    int
		long PntID;                   //* 点ID    int
		std::string HoleCode;         //* 钻孔编号    varchar
		long HoleCls1;                //* 钻孔大类    int
		long HoleCls2;                //* 钻孔亚类    int
		long HoleProperty;            //* 钻孔性质    int
		double HoleDepth;             //* 孔深(m)    double
		long LayerNum;                // 分层数量(个)    int
		long SoilSampNum;             // 土样数量(个)    int
		long RockSampNum;             // 岩样数量(个)    int
		long WaterSampNum;            // 水样数量(个)    int
		long PenetrationTimes;        // 标贯次数(个)    int
		std::string IsWavelocityHole; // 是否为波速孔    varchar
		std::string HasPump;          // 是否进行抽水试验    varchar
		std::string OtherInsit;       // 其他原位试验情况    varchar
		std::string RegDate;          // 登记日期    date
		std::string Register;         // 登记人    varchar
		std::string _Memo;            // 备注    varchar
		long AuditStatus;             // 审核状态    int
		long SelectStatus;            // 选用状态    int
		std::string Auditor;          // 审核人    varchar
		std::string AuditTime;        // 审核时间    date
		std::string AuditOrg;         // 审核单位    varchar
	};

	// 钻孔基本信息表 *
	struct  HoleInfo : public s3d_BoreHole
	{
	public:
		std::string HoleCategory;    // 钻孔类别    varchar
		long PntID;                  //* 点ID    int
		int HoleUsage;               // 钻孔用途			int（取土、静探、标贯...）
		std::string PrjName;         //* 项目名称			varchar
		double SWCJAR;               // 初见水位埋深			double
		double SWDDBU;               // 稳定水位埋深			double
		float TKACA;                 // 开孔直径(mm)			float
		float TKACB;                 // 终孔直径(mm)			float
		float HoleTopDiam;           // 井口外径(mm)			float
		float HoleBtmDiam;           // 井底外径(mm)			float
		float TKCBCL;                // 成井深度(m)			float
		float HoleHeight;            // 井台高度(m)			float
		float HoleSlope;             // 井（孔）斜(度)		float
		std::string HoleEquip;       // 施工设备			varchar
		std::string TKALD;           // 施工单位			varchar
		std::string SWBBND;          // 机长				varchar
		std::string HoleRecorder;    // 编录员			varchar
		std::string StartDate;       // 开工日期			date
		std::string EndDate;         // 完工日期			date
		std::string InputOrgn;       // 录入单位			varchar
		std::string Inputer;         // 录入员			varchar
		std::string InputDate;       // 录入日期			date
		std::string PlaneMap;        // 平面位置示意图	varchar
		std::string SectMap;         // 剖面示意图		varchar
		std::string ScenePhoto;      // 现场照片（视频）	varchar
		std::string ConstructRecord; // 施工记录			varchar
		std::string _Memo;           // 备注				varchar

		double HoleDepth; //* 孔深(m)			double

		HoleInfo() : s3d_BoreHole()
		{
			HoleUsage = 0;
			PrjName = "";
			SWCJAR = 0.0;
			SWDDBU = 0.0;
			TKACA = 0.0;
			TKACB = 0.0;
			HoleTopDiam = 0.0;
			HoleBtmDiam = 0.0;
			TKCBCL = 0.0;
			HoleHeight = 0.0;
			HoleSlope = 0.0;
			HoleEquip = "";
			TKALD = "";
			SWBBND = "";
			HoleRecorder = "";
			StartDate = "";
			EndDate = "";
			InputOrgn = "";
			Inputer = "";
			InputDate = "";
			PlaneMap = "";
			SectMap = "";
			ScenePhoto = "";
			ConstructRecord = "";
			_Memo = "";
		}
	};

	// 钻孔测斜表
	struct  HoleInclinat
	{
	public:
		long HoleID;         //* 钻孔ID    int
		double MeasureDepth; //* 测点深度    double
		double AzimuthAngle; //* 方位角    double
		double DipAngle;     //* 倾角    double
	};

	// 测井基本情况表
	struct  HoleLogging
	{
	public:
		long LoggingID;         //* 测井id    int
		long HoleID;            //* 钻孔ID    int
		std::string DeviceName; // 仪器名称    varchar
		std::string DeviceType; // 仪器型号    varchar
		float StartDepth;       //* 探测起始深度(m)    float
		float EndDepth;         //* 探测终止深度(m)    float
		float SampleGap;        //* 采样间隔(m)    float
		std::string LoggingDoc; // 测井数据文档    varchar
		std::string TKALD;      // 施工单位    varchar
		std::string _Operator;  // 操作人    varchar
		std::string DetectDate; // 探测日期    date
		std::string Inputer;    // 录入员    varchar
		std::string InputOrgn;  // 录入单位    varchar
		std::string InputDate;  // 录入日期    date
	};

	// 标准地层用虚拟钻孔基本信息表
	struct  StdStrat_VHole
	{
	public:
		long VIRHOLEID;            //* 虚拟孔ID    int
		std::string VIRHOLENO;     //* 虚拟孔号    varchar
		double X;                  //* X    double
		double Y;                  //* Y    double
		double Z;                  // Z    double
		double VIRHOLEDEPTH;       //* 孔深    double
		std::string PlaneCoordSys; //* 平面坐标系    varchar
		std::string InputOrgn;     // 录入单位    varchar
		std::string Inputer;       // 录入员    varchar
		std::string InputDate;     // 录入日期    date
	};

	// 标准地层用虚拟钻孔分层信息表
	struct  StdStrat_VHolelLayer
	{
	public:
		long VIRHOLELAYERID;       //* 虚拟分层ID    int
		long VIRHOLEID;            //* 虚拟孔ID    int
		std::string VIRHOLENO;     // 虚拟孔号    varchar
		long LAYERNO;              //* 分层序号    int
		std::string VIRLAYERCODE;  //* 虚拟层编码    varchar
		std::string GEOCODE;       //* 地质代号    varchar
		std::string DDCDIA;        // 地质时代    varchar
		std::string CauseType;     // 成因类型    varchar
		std::string YSEB;          // 岩土名称    varchar
		double LayerDepth;         // 分层深度    double
		double LayerThick;         // 分层厚度    double
		std::string YSHB;          // 岩土颜色    varchar
		std::string EngTrait;      // 工程性状    varchar
		std::string WateryTrait;   // 含水性状    varchar
		std::string GCKLT;         // 岩性描述    varchar
		long LAYERID;              // 分层号ID    int
		double LAYERTOPDEPTH;      // 原始层顶深度    double
		double BOTTOMDEPTH;        // 原始层底深度    double
		double TOPELEVATION;       // 原始分层厚度    double
		std::string FieldLayerNum; // 野外分层号    varchar
		std::string HOLECODE;      // 地层来源钻孔编号    varchar
		std::string PrjCode;       // 地层来源钻孔的项目统一编号    varchar
	};

	// 探槽观测点信息表
	struct  HoleDetect
	{
	public:
		long DetectID;               //* 探槽观测点ID    int
		std::string DetectNo;        // 探槽观测点编号    varchar
		std::string PrjCode;         // 项目统一编号    varchar
		float Distance;              // 与起始点距离(m)    float
		float Orientation;           // 位于起始点方位(度)    float
		long PntID;                  //* 点ID    int
		std::string GCEABC;          // 野外编号    varchar
		std::string SWBCBC;          // 探井目的    varchar
		std::string ExploreType;     // 勘探类型    varchar
		float ExploreDepth;          // 勘探深度    float
		float GCJDBN;                // 开挖体积    float
		float SWEGAB;                // 水位埋深(m)    float
		std::string GCKBBA;          // 地形地貌    varchar
		std::string GeoCondit;       // 地质条件    varchar
		std::string HydroCondit;     // 水文地质条件    varchar
		std::string EngCondit;       // 工程地质条件    varchar
		std::string HJY;             // 环境地质问题    varchar
		std::string EcoEnvCondit;    // 生态环境状况    varchar
		std::string GCIAEB;          // 土地利用现状    varchar
		std::string SWDCG;           // 沿途观测    varchar
		std::string TKALD;           // 施工单位    varchar
		std::string Technician;      // 技术员    varchar
		std::string DetectDate;      // 勘探日期    date
		std::string InputOrgn;       // 录入单位    varchar
		std::string Inputer;         // 录入员    varchar
		std::string InputDate;       // 录入日期    date
		std::string SWLBAB;          // 平面示意图    varchar
		std::string SWLBAA;          // 剖面示意图    varchar
		std::string ScenePhoto;      // 现场照片    varchar
		std::string ConstructRecord; // 施工记录    varchar
		std::string _Memo;           // 备注    varchar
	};

	// 浅井探槽岩性分层描述表
	struct  HoleWellSlotLayer
	{
	public:
		long WallSlotLayerID;     //* 井槽分层ID    int
		std::string FieldLayerNo; // 野外分层号    varchar
		std::string GCEABC;       // 野外编号    varchar
		std::string PrjCode;      // 项目编号    varchar
		long DetectID;            //* 探槽观测点ID    int
		double TopDepth;          //* 层顶深度(m)    double
		double BottomDepth;       //* 层底深度(m)    double
		double TopElevation;      // 层顶高程(m)    double
		double BottomElevation;   // 层底高程(m)    double
		double LayerThick;        // 分层厚度(m)    double
		std::string GeoCode;      // 地质代号    varchar
		std::string DDCDIA;       // 地质时代    varchar
		std::string CauseType;    // 成因类型    varchar
		std::string YSEB;         // 岩土名称    varchar
		std::string YSHB;         // 岩土颜色    varchar
		std::string EngTrait;     // 工程性状    varchar
		std::string WateryTrait;  // 含水性状    varchar
		std::string GCKLT;        // 岩性描述    varchar
	};

	// 电（磁）法勘探线参数表
	struct  PhyElecline
	{
	public:
		long EleclineID;          //* 电(磁)法测线ID    int
		std::string LineCode;     // 测线号    varchar
		float DotPitch;           // 点距(m)    float
		long DetedotCount;        // 测点数    int
		float DetelineLength;     // 测线长度(km)    float
		float DatelineOrient;     // 测线方位(度)    float
		std::string _Device;      // 仪器    varchar
		std::string DeviceType;   // 装置类型    varchar
		float RecdisDist;         // 收发距(m)    float
		float _Frequency;         // 频率(Hz)    float
		float LaunchBoxArea;      // 发射框面积(m2)    float
		float RecboxArea;         // 接收线框面积(m2)    float
		float AntennaFre;         // 天线频率(Hz)    float
		float AntennaDist;        // 天线间距(m)    float
		long PrjId;               //* 项目ID    int
		std::string DetectMethod; // 探测方法    varchar
		std::string TKALD;        // 施工单位    varchar
		std::string _Operator;    // 操作人    varchar
		std::string Checker;      // 检查人    varchar
		std::string StartDate;    // 起始日期    date
		std::string EndDate;      // 完成日期    date
		long OrigDocID;           // 原始数据文档ID    int
		long DrrorDocID;          // 误差文档ID    int
		std::string ParaDocID;    // 参数文档ID    varchar
		long resultDocID;         // 成果数据文档ID    int
		std::string Inputer;      // 录入员    varchar
		std::string InputOrgn;    // 录入单位    varchar
		std::string InputDate;    // 录入日期    date
	};

	// 地震勘探线参数表
	struct  PhyEardeteline
	{
	public:
		long EardetelineID;       //* 地震测线ID    int
		std::string LineCode;     // 测线号    varchar
		float RoadDist;           // 道间距(m)    float
		long RecTime;             // 接收道数(道)    int
		long FlipcoverTime;       // 水平覆盖次数(次)    int
		long SampleGap;           // 采样间隔(s)    int
		float RecordLength;       // 记录长度    float
		float BombDist;           // 炮间距(m)    float
		float DffsetDist;         // 偏移距(m)    float
		float RecuLength;         // 迭代段长(m)    float
		float TriangleMaxlen;     // 三角形最大边长(m)    float
		long PrjId;               //* 项目ID    int
		std::string DetectMethod; // 探测方法    varchar
		std::string TKALD;        // 施工单位    varchar
		std::string _Operator;    // 操作人    varchar
		std::string Checker;      // 检查人    varchar
		std::string StartDate;    // 起始日期    date
		std::string EndDate;      // 完成日期    date
		long OrigDocID;           // 原始数据文档ID    int
		long DrrorDocID;          // 误差文档ID    int
		std::string ParaDocID;    // 参数文档ID    varchar
		long resultDocID;         // 成果数据文档ID    int
		std::string Inputer;      // 录入员    varchar
		std::string InputOrgn;    // 录入单位    varchar
		std::string InputDate;    // 录入日期    date
	};

	// 物探点位标准化信息表
	struct  PhyStdPnt
	{
	public:
		long StdPntID;                //* 标准测点ID    int
		std::string PntNo;            // 点号    varchar
		double STKCAF;                //* 标准化X    double
		double STKCAG;                //* 标准化Y    double
		double SGCJCBJ;               //* 标准化高程(m)    double
		std::string StdPlaneCoordSys; // 标准化平面坐标系    varchar
		std::string stdElDatum;       // 标准化高程基准    varchar
		double Longitude;             // 经度(°)    double
		double Latitude;              // 纬度(°)    double
		double TKCAF;                 // X    double
		double TKCAG;                 // Y    double
		double GCJCBJ;                // 高程(m)    double
		std::string PlaneCoordSys;    // 平面坐标系    varchar
		std::string EleDatum;         // 高程基准    varchar
		std::string LineCode;         // 测线号    varchar
		long PrjId;                   //* 项目ID    int
		long PrjCode;                 // 项目统一编号    int
		std::string DetectMethod;     // 探测方法    varchar
		std::string TKALD;            // 施工单位    varchar
		std::string _Operator;        // 操作人    varchar
		std::string Checker;          // 检查人    varchar
		std::string StartDate;        // 起始日期    date
		std::string EndDate;          // 完成日期    date
		long OrigDocID;               // 原始数据文档ID    int
		long DrrorDocID;              // 误差文档ID    int
		std::string ParaDocID;        // 参数文档ID    varchar
		long resultDocID;             // 成果数据文档ID    int
		std::string Inputer;          // 录入员    varchar
		std::string InputOrgn;        // 录入单位    varchar
		std::string InputDate;        // 录入日期    date
	};

	// 标准地层版本表 *
	struct  hole_stdStratVer
	{
	public:
		long StdStratVerID;          //* 标准地层版本    int
		std::string StdStratName; //* 标准地层名称    varchar
		std::string ProType;      // 专业类别    varchar
		std::string ProCode;      // 专业代码    varchar
		std::string ProName;      // 专业名称    varchar
		std::string StdAuthor;    // 标准作者    varchar
		long StratLevelNum;       // 地层级别数    int
		std::string _Memo;        // 备注    varchar
	};

	// 标准地层描述表 *
	struct  hole_stdStratDesc : public s3d_BaseLayer
	{
	public:
		std::string m_strYtmc;     //岩土名称
		std::string m_strDzcy;     //地层成因				varchar
		std::string m_strDzsd;     //地质时代				varchar
		std::string m_strDcms;     //地层描述				varchar
		std::string DecayRate;     // 风化程度    varchar	added.
		std::string CauseCode;     // 成因代码				varchar
		std::string GeoCode;       // 地层代号				varchar
		std::string EngTrait;      // 工程性状				varchar
		std::string WateryTrait;   // 含水性状				varchar
		int FieldLayerID;          // 野外分层ID			int
		std::string FieldLayerNum; // 野外分层号			varchar
		std::string YSHB;          // 岩土颜色				varchar
		std::string _Memo;         // 备注					varchar
	};

	// 钻孔分层表 *
	struct  HoleLayer : public s3d_BoreHoleLayer
	{
	public:
		long ID;			   // * 钻孔分层记录ID	int
		int StdStratID;            // 标准分层ID
		std::string GCKUPE;        // 成因类型
		std::string GeoCode;       // 地质代号
		std::string YSHB;          // 岩土颜色
		std::string EngTrait;      // 工程性状
		std::string WateryTrait;   // 含水性状
		int FieldLayerID;          // 野外分层ID
		std::string FieldLayerNum; // 野外分层号

	};

	// 钻孔原始分层表
	struct  HoleOrigLayer
	{
	public:
		long FieldLayerID;         //* 野外分层号ID    int
		std::string FieldLayerNum; //* 野外分层号    varchar
		long HoleID;               //* 钻孔ID    int
		std::string GeoCode;       //* 地质代号    varchar
		std::string DDCDIA;        //* 地质时代    varchar
		std::string CauseType;     //* 成因类型    varchar
		double TopDepth;           //* 层顶深度    double
		double BottomDepth;        //* 层底深度    double
		double TopElevation;       // 层顶高程    double
		double BottomElevation;    // 层底高程    double
		double LayerThick;         //* 分层厚度    double
		std::string YSEB;          //* 岩土名称    varchar
		std::string YSHB;          //* 岩土颜色    varchar
		std::string EngTrait;      //* 工程性状    varchar
		std::string WateryTrait;   //* 含水性状    varchar
		std::string GCKLT;         //* 岩性描述    varchar
	};

	// 止水结构表
	struct  HoleWaterSeal
	{
	public:
		long WaterSealID;            // 止水ID    int
		long HoleID;                 // 钻孔ID    int
		double SWCEA;                // 止水深度(m)    double
		std::string SWCEB;           // 止水方法    varchar
		std::string SealingMaterial; // 止水材料    varchar
	};

	// 填砾结构表
	struct  HoleGravelPack
	{
	public:
		long GravelPackID;         // 填砾ID    int
		long HoleID;               // 钻孔ID    int
		double SWCDH;              // 填砾顶深度(m)    double
		double SWCGBD;             // 填砾底深度(m)    double
		double SWCGBC;             // 填砾厚度(m)    double
		std::string SWCDF;         // 砾料类型    varchar
		std::string GravelSpecify; // 砾料规格    varchar
	};

	// 井管结构表
	struct  HoleWellPipe
	{
	public:
		long WellPipeID;              // 井管ID    int
		long HoleID;                  // 钻孔ID    int
		double TKACE;                 // 变径深度(m)    double
		double HoleTopDiam;           // 井口外径(mm)    double
		std::string SWCCB;            // 井管类型    varchar
		std::string WellPipeMaterial; // 井管材质    varchar
	};

	// 孔径变化表
	struct  HoleAperture
	{
	public:
		long ApertureID; // 孔径ID    int
		long HoleID;     // 钻孔ID    int
		float TKACE;     // 变径深度(m)    float
		float SWCL;      // 钻孔直径(mm)    float
	};

	// 标准贯入试验记录表
	struct  EgStdPenetration : public Bas_PntStdInfo
	{
	public:
		long StdPenetratID;         //* 标贯记录ID    int
		std::string TCDH;           //* 试验层位    varchar
		float StartDepth;           //* 起深度(m)    float
		float EndDepth;             //* 止深度(m)    float
		long PntID;                 //* 点ID    int
		std::string TestNo;         // 试验编号    varchar
		std::string TestType;       // 试验类型    varchar
		int HammerNum;             // 锤击数    int
		float HitMeasNum;            // 实测标贯击数(击/30cm)    float
		float PoleLength;           // 杆长(m)    float
		float RodCorrectFactor;     // 杆长校正系数    float
		float HitCorrectNum;         // 校正后标贯击数(击/30cm)    float
		std::string GeoCode;        // 地质代号    varchar
		std::string TCMC;           // 土层名称    varchar
		std::string NOTE;           // 备注    varchar
		std::string TestEquipModel; // 试验设备及型号    varchar
		std::string TestStartDate;  // 试验开始日期    date
		std::string TestEndDate;    // 试验完成日期    date
		std::string TestOrgn;       // 试验单位    varchar
		std::string _Operator;      // 操作人    varchar
		std::string Technician;     // 现场技术员    varchar
		std::string Inputer;        // 录入员    varchar
		std::string InputOrgn;      // 录入单位    varchar
		std::string InputDate;      // 录入日期    date
	};

	// 静力触探试验记录表
	struct  EgStaticPenetration : public Bas_PntStdInfo
	{
	public:
		long StaticContactID;       //* 静探试验ID    int
		std::string TCDH;           //* 试验层位    varchar
		float StartDepth;           //* 起深度    float
		float EndDepth;             //* 止深度    float
		long PntID;                 //* 点ID    int
		std::string TestNo;         // 试验编号    varchar
		std::string TestType;       // 试验类型    varchar
		std::string ProbeType;      // 探头类型    varchar
		float GCEBCJ;               // 锥尖阻力    float
		float GCEBCK;               // 侧壁摩阻力    float
		float GCEBCM;               // 比贯入阻力    float
		float GCDLAK;               // 孔隙水压力    float
		float FrictionRatio;        // 摩阻比    float
		std::string GeoCode;        // 地质代号    varchar
		std::string TCMC;           // 土层名称    varchar
		std::string NOTE;           // 备注    varchar
		std::string TestEquipModel; // 试验设备及型号    varchar
		std::string TestStartDate;  // 试验开始日期    date
		std::string TestEndDate;    // 试验完成日期    date
		std::string TestOrgn;       // 试验单位    varchar
		std::string _Operator;      // 操作人    varchar
		std::string Technician;     // 现场技术员    varchar
		std::string Inputer;        // 录入员    varchar
		std::string InputOrgn;      // 录入单位    varchar
		std::string InputDate;      // 录入日期    date
	};

	// 重型动力触探实验记录表
	struct  EgMotDetect : public Bas_PntStdInfo
	{
	public:
		long MotDetectID;           //* 动探记录ID    int
		std::string TestHorizon;    //* 试验层位    varchar
		float StartDepth;           //* 起深度    float
		float EndDepth;             //* 止深度    float
		long PntID;                 //* 点ID    int
		std::string TestNo;         // 试验编号    varchar
		std::string TestType;       // 试验类型    varchar
		std::string SoundType;      // 触探类型    varchar
		double HammerNum;           // 实测锤击数    double
		double PoleLength;          // 杆长    double
		float RodCorrectFactor;     // 杆长校正系数    float
		float SWEGAB;               // 地下水位埋深    float
		float GCBAF;                // 粘粒含量    float
		double HitCorrectNum;       // 修正后锤击数    double
		float PenetratCorrect;      // 修正后贯入度    float
		std::string GeoCode;        // 地质代号    varchar
		std::string TCMC;           // 土层名称    varchar
		std::string NOTE;           // 备注    varchar
		std::string TestEquipModel; // 试验设备及型号    varchar
		std::string TestStartDate;  // 试验开始日期    date
		std::string TestEndDate;    // 试验完成日期    date
		std::string TestOrgn;       // 试验单位    varchar
		std::string _Operator;      // 操作人    varchar
		std::string Technician;     // 现场技术员    varchar
		std::string Inputer;        // 录入员    varchar
		std::string InputOrgn;      // 录入单位    varchar
		std::string InputDate;      // 录入日期    date
	};

	// 轻型动力触探实验记录表
	struct  LightEgMotDetect : public Bas_PntStdInfo
	{
	public:
		long MotDetectID;           //* 动探记录ID    int
		std::string TestHorizon;    //* 试验层位    varchar
		float StartDepth;           //* 起深度    float
		float EndDepth;             //* 止深度    float
		long PntID;                 //* 点ID    int
		std::string TestNo;         // 试验编号    varchar
		std::string TestType;       // 试验类型    varchar
		std::string SoundType;      // 触探类型    varchar
		double HammerNum;           // 实测锤击数    double
		double PoleLength;          // 杆长    double
		float RodCorrectFactor;     // 杆长校正系数    float
		float SWEGAB;               // 地下水位埋深    float
		float GCBAF;                // 粘粒含量    float
		long HitCorrectNum;         // 修正后锤击数    int
		float PenetratCorrect;      // 修正后贯入度    float
		std::string GeoCode;        // 地质代号    varchar
		std::string TCMC;           // 土层名称    varchar
		std::string NOTE;           // 备注    varchar
		std::string TestEquipModel; // 试验设备及型号    varchar
		std::string TestStartDate;  // 试验开始日期    date
		std::string TestEndDate;    // 试验完成日期    date
		std::string TestOrgn;       // 试验单位    varchar
		std::string _Operator;      // 操作人    varchar
		std::string Technician;     // 现场技术员    varchar
		std::string Inputer;        // 录入员    varchar
		std::string InputOrgn;      // 录入单位    varchar
		std::string InputDate;      // 录入日期    date
	};

	// 十字板剪切试验记录表
	struct  EgShear : public Bas_PntStdInfo
	{
	public:
		long CrossPlateID;          //* 十字板试验ID    int
		std::string TCDH;           //* 试验层位    varchar
		float StartDepth;           //* 起深度(m)    float
		float EndDepth;             //* 止深度(m)    float
		long PntID;                 //* 点ID    int
		std::string TestNo;         // 试验编号    varchar
		std::string TestType;       // 试验类型    varchar
		float GCDMAM;               // 原状土抗剪强度    float
		float GCDMAO;               // 重塑土抗剪强度    float
		float GCBFOA;               // 粘聚力    float
		float GCDKCS;               // 残余强度    float
		float GCBFI;                // 灵敏度    float
		std::string GeoCode;        // 地质代号    varchar
		std::string TCMC;           // 土层名称    varchar
		std::string NOTE;           // 备注    varchar
		std::string TestEquipModel; // 试验设备及型号    varchar
		std::string TestStartDate;  // 试验开始日期    date
		std::string TestEndDate;    // 试验完成日期    date
		std::string TestOrgn;       // 试验单位    varchar
		std::string _Operator;      // 操作人    varchar
		std::string Technician;     // 现场技术员    varchar
		std::string Inputer;        // 录入员    varchar
		std::string InputOrgn;      // 录入单位    varchar
		std::string InputDate;      // 录入日期    date
	};

	// 波速测试记录表
	struct  EgWaveSpeed : public Bas_PntStdInfo
	{
	public:
		long WaveSpeedID;           //* 波速记录ID    int
		std::string TCDH;           //* 试验层位    varchar
		float StartDepth;           //* 起深度(m)    float
		float EndDepth;             //* 止深度(m)    float
		long PntID;                 //* 点ID    int
		std::string TestNo;         // 试验编号    varchar
		std::string TestType;       // 试验类型    varchar
		std::string TestMethod;     // 试验方法    varchar
		float SwvMax;               // 最大剪切波速(m/s)    float
		float SwvMin;               // 最小剪切波速(m/s)    float
		float SwvAver;              // 平均剪切波速(m/s)    float
		float GCEBHD;               // 压缩波速    float
		float ZBBS;                 // 纵波波速    float
		std::string GCEBHF;         // 场地类别    varchar
		std::string GCEBHA;         // 波速试验类型    varchar
		std::string GeoCode;        // 地质代号    varchar
		std::string TCMC;           // 土层名称    varchar
		std::string NOTE;           // 备注    varchar
		std::string TestEquipModel; // 试验设备及型号    varchar
		std::string TestStartDate;  // 试验开始日期    date
		std::string TestEndDate;    // 试验完成日期    date
		std::string TestOrgn;       // 试验单位    varchar
		std::string _Operator;      // 操作人    varchar
		std::string Technician;     // 现场技术员    varchar
		std::string Inputer;        // 录入员    varchar
		std::string InputOrgn;      // 录入单位    varchar
		std::string InputDate;      // 录入日期    date
	};

	// 旁压实验成果表
	struct  EgPMT : public Bas_PntStdInfo
	{
	public:
		long PMTID;                 //* 旁压试验ID    int
		std::string TCDH;           //* 试验层位    varchar
		float StartDepth;           //* 起深度(m)    float
		float EndDepth;             //* 止深度(m)    float
		long PntID;                 //* 点ID    int
		std::string TestNo;         // 试验编号    varchar
		std::string TestType;       // 试验类型    varchar
		std::string PressStage;     // 加压级数    varchar
		float PressRampUp;          // 加压增量(kPa)    float
		float PipeDist;             // 量管水面离孔口距离(m)    float
		float HydroStaticPress;     // 静水压力(kPa)    float
		float InitialPress;         // 初始压力(kPa)    float
		float UltimatePress;        // 极限压力(kPa)    float
		float PlasticPress;         // 临塑压力(kPa)    float
		float CharactValue;         // 地基承载力特征值(kPa)    float
		float SidePressModule;      // 旁压模量(MPa)    float
		float GCDKBA;               // 变形模量(MPa)    float
		float SidePressDP;          // 旁压变形参数(MPa)    float
		float EarthPressure;        // 土压力(kPa)    float
		float SidePressHorizontal;  // 旁压水平侧压力(kPa)    float
		float GcebbaUltimate;       // 地基承载力(极限法)(kPa)    float
		float GcebbaPlastic;        // 地基承载力(临塑法)(kPa)    float
		float GCDKCR;               // 不排水抗剪强度(kPa)    float
		float SidepressCoeffice;    // 侧压力系数    float
		float GCDLAK;               // 孔隙水压力(kPa)    float
		std::string GeoCode;        // 地质代号    varchar
		std::string TCMC;           // 土层名称    varchar
		std::string NOTE;           // 备注    varchar
		std::string SWDDAH;         // 观测时间    date
		long GCEFAV;                // 序号    int
		float GCECHD;               // 压力(kPa)    float
		float ExpandVolume;         // 扩张体积(cm3)    float
		float WaterLevelValue;      // 量管水位值(cm)    float
		float WaterDropValue;       // 量管水位下降值(cm)    float
		std::string TestEquipModel; // 试验设备及型号    varchar
		std::string TestStartDate;  // 试验开始日期    date
		std::string TestEndDate;    // 试验完成日期    date
		std::string TestOrgn;       // 试验单位    varchar
		std::string _Operator;      // 操作人    varchar
		std::string Technician;     // 现场技术员    varchar
		std::string Inputer;        // 录入员    varchar
		std::string InputOrgn;      // 录入单位    varchar
		std::string InputDate;      // 录入日期    date
	};

	// 载荷试验成果表
	struct  EgLoadTest : public Bas_PntStdInfo
	{
	public:
		long LoadTestID;               //* 载荷试验ID    int
		std::string TCDH;              //* 试验层位    varchar
		float StartDepth;              //* 起深度(m)    float
		float EndDepth;                //* 止深度(m)    float
		long PntID;                    //* 点ID    int
		std::string TestNo;            // 试验编号    varchar
		std::string TestType;          // 试验类型    varchar
		std::string GCEBAM;            // 承压板形状    varchar
		float GCEBAB;                  // 承压板面积    float
		float BoardHeadDiam;           // 板头直径(m)    float
		std::string SettleObservEquip; // 沉降观测仪器    varchar
		std::string TestBedLithology;  // 试验层岩性    varchar
		std::string LoadTestType;      // 载荷试验类型    varchar
		std::string LoadEquipModel;    // 加荷设备及型号    varchar
		std::string LoadMethod;        // 加荷方式    varchar
		std::string StabilityStd;      // 稳定标准    varchar
		std::string TestDuration;      // 试验时长    varchar
		float TestLayerPoisson;        // 试验层泊松比    float
		float SWEGAB;                  // 地下水位埋深(m)    float
		float GCEBAF;                  // 试验点界限应力(MPa)    float
		float GCEBAG;                  // 试验点极限应力(MPa)    float
		float GCEBBA;                  // 地基承载力(kPa)    float
		float GCDKBA;                  // 变形模量(MPa)    float
		float GCDKCR;                  // 不排水抗剪强度(kPa)    float
		float GCDLBD;                  // 固结系数    float
		float OrigCurveIntercept;      // 原始曲线截距    float
		float OrigCurveSlope;          // 原始曲线斜率    float
		float CorrectCurveSlope;       // 修正曲线斜率    float
		float YSKYZ;                   // 岩石抗压道（MPa）    float
		std::string GeoCode;           // 地质代号    varchar
		std::string TCMC;              // 土层名称    varchar
		std::string NOTE;              // 备注    varchar
		std::string GCEABB;            // 样品编号    varchar
		std::string SWBCF;             // 样品类型    varchar
		float MoistureContent;         // 天然含水量    float
		float NaturalSeverity;         // 天然重度    float
		float DHABCU;                  // 饱和度    float
		float NaturalHoleRatio;        // 天然孔隙比    float
		float GCDDD;                   // 液限    float
		float GCDDF;                   // 液性指数    float
		float GCDDE;                   // 塑性指数    float
		float GCDLAC;                  // 压缩系数    float
		float QDZS;                    // 强度指数    float
		std::string SWDDAH;            // 观测时间    date
		float GCECHD;                  // 压力(kPa)    float
		float GCGFAI;                  // 沉降量(mm)    float
		float SettleChange;            // 沉降变化量(mm)    float
		float SettleCorrectValue;      // 沉降校正值(mm)    float
		float SettleCorrectNum;        // 校正后沉降量(mm)    float
		std::string TestEquipModel;    // 试验设备及型号    varchar
		std::string TestStartDate;     // 试验开始日期    date
		std::string TestEndDate;       // 试验完成日期    date
		long TestNumber;               // 试验个数    int
		std::string TestOrgn;          // 试验单位    varchar
		std::string _Operator;         // 操作人    varchar
		std::string Technician;        // 现场技术员    varchar
		std::string Inputer;           // 录入员    varchar
		std::string InputOrgn;         // 录入单位    varchar
		std::string InputDate;         // 录入日期    date
	};

	// 抽水试验成果表
	struct  HYPumpExp : public Bas_PntStdInfo
	{
	public:
		long PumpTestID;               //* 抽水试验ID    int
		std::string SWDAE;             // 抽水试验编号    varchar
		std::string TestCategory;      // 试验类型    varchar
		std::string LandNum;           // 落程数量    varchar
		long PumpHoleNum;              // 抽水孔数量    int
		long ObHoleNum;                // 观测孔数量    int
		std::string SWDDAA;            // 试验开始时间    date
		std::string PumpEndTime;       // 抽水结束时间    date
		std::string SWDDAB;            // 试验结束时间    date
		std::string StableDuration;    // 水位稳定延续时间(min)    varchar
		std::string PumpEquipModel;    // 抽水设备及型号    varchar
		std::string WaterLevelObInst;  // 水位观测仪器    varchar
		std::string WaterVolumeObInst; // 水量观测仪器    varchar
		std::string WaterTempObInst;   // 水温观测仪器    varchar
		std::string TestHorizon;       // 试验层位    varchar
		std::string AquiferLithology;  // 试验含水层岩性    varchar
		float SWDDBY;                  // 最大涌水量(m3/d)    float
		float DrawDownMax;             // 最大降深(m)    float
		float MaxInfluRadius;          // 最大影响半径(m)    float
		float CalculDrawDown;          // 推算降深(m)    float
		float _Diameter;               // 统一换算管径(mm)    float
		float EsWaterInflow;           // 推算涌水量(m3/d)    float
		float EsInfluRadius;           // 推算影响半径(m)    float
		float SWGGAA;                  // 平均渗透系数(m/d)    float
		float SWGGAO;                  // 平均导水系数(m2/d)    float
		float SWGGAL;                  // 平均储水系数    float
		float SWAEFG;                  // 平均给水度    float
		float SWGGBE;                  // 平均越流系数    float
		std::string PlanePosMap;       // 平面位置示意图    varchar
		std::string ProfileMap;        // 剖面示意图    varchar
		std::string FieldImage;        // 野外照片(视频)    varchar
		std::string RecordCard;        // 记录卡片(记录)    varchar
		std::string TestOrgn;          // 试验单位    varchar
		std::string JJDAC;             // 记录人    varchar
		std::string _Observer;         // 观测人    varchar
		std::string Inputer;           // 录入员    varchar
		std::string InputOrgn;         // 录入单位    varchar
		std::string InputDate;         // 录入日期    date
		std::string _Memo;             // 备注    varchar
	};

	// 抽水试验段信息表
	struct  HYPumpExpSec : public Bas_PntStdInfo
	{
	public:
		long SectionID;              //* 试验段ID    int
		std::string TestSectNum;     // 试验段编号    varchar
		std::string SWDAE;           // 试验编号    varchar
		float FilterTopDepth;        // 试验段滤管顶深度(m)    float
		float FilterBottomDepth;     // 试验段滤管底深度(m)    float
		float FilterDiam;            // 试验段滤管外径(mm)    float
		float WateryTopDepth;        // 试验段含水层顶深度(m)    float
		float WateryBottomDepth;     // 试验段含水层底深度(m)    float
		float WateryThickness;       // 试验段含水层厚度(m)    float
		std::string SectHorizon;     // 试验段层位    varchar
		std::string WateryLithology; // 试验段含水层岩性    varchar
		long PntID;                  //* 点ID    int
		std::string PumpTestHoleNo;  // 抽水试验孔号    varchar
		std::string TestHoleType;    // 试验孔类型    varchar
		float PumpHoleDist;          // 与抽水孔距离(m)    float
		float BeforePumpDepth;       // 抽水前静水位埋深(m)    float
		float AfterPumpDepth;        // 抽水后静水位埋深(m)    float
		long SectNum;                // 试验段数量    int
		float AitsTotalThick;        // 试验段含水层总厚度(m)    float
		float SectionDiam;           // 过水断面等效外径(mm)    float
	};

	// 抽水实验落程数据表
	struct  HYPumpDropOff : public Bas_PntStdInfo
	{
	public:
		long DropOffID;              //* 落程ID    int
		std::string SWDDBG;          // 落程编号    varchar
		std::string SWDAE;           // 试验编号    varchar
		std::string StartTime;       // 落程开始时间    date
		std::string EndTime;         // 落程结束时间    date
		std::string SustainTime;     // 落程延续时间    varchar
		std::string StableStartTime; // 水位稳定起始时间    date
		std::string StableTime;      // 水位稳定时长(分钟)    varchar
		float WaterDropDepth;        // 稳定水位降深(m)    float
		float StableInflow;          // 稳定涌水量(m3/d)    float
		float SWGGAA;                // 渗透系数    float
		float InfluRadius;           // 影响半径    float
		float HydraCoeffic;          // 导水系数    float
		float StoreCoeffic;          // 储水系数    float
		float WaterSupply;           // 给水度    float
		float LeapfrogCoeffic;       // 越流系数    float
		long PntID;                  //* 点ID    int
		std::string PumpTestHoleNo;  // 抽水试验孔号    varchar
		std::string TestHoleType;    // 试验孔类型    varchar
		float PumpHoleDist;          // 与抽水孔距离(m)    float
		float BeforePumpDepth;       // 抽水前静水位埋深(m)    float
		float AfterPumpDepth;        // 抽水后静水位埋深(m)    float
		long SectNum;                // 试验段数量    int
		float AitsTotalThick;        // 试验段含水层总厚度(m)    float
		float SectionDiam;           // 过水断面等效外径(mm)    float
	};

	// 抽水水位观测记录表
	struct  HYPumpLevelOb : public Bas_PntStdInfo
	{
	public:
		long DyWaterLevelID;        //* 动水位ID    int
		long DropOffID;             // 落程ID    int
		std::string SWDDBG;         // 落程编号    varchar
		std::string SWDAE;          // 试验编号    varchar
		std::string SWDDAH;         // 观测时间    date
		std::string PumpDuration;   // 抽水延续时间(min)    varchar
		float SWEGAB;               // 水位埋深(m)    float
		float SWDDBH;               // 水位降深(m)    float
		float WaterInFlowM;         // 涌水量(m3/d)    float
		float WaterInFlowL;         // 涌水量(L/s)    float
		float SWADET;               // 水温(℃)    float
		float SWADBB;               // 气温(℃)    float
		bool Is_Stable;             // 是否稳定    bool
		std::string _Memo;          // 备注    varchar
		long PntID;                 //* 点ID    int
		std::string PumpTestHoleNo; // 抽水试验孔号    varchar
		std::string TestHoleType;   // 试验孔类型    varchar
		float PumpHoleDist;         // 与抽水孔距离(m)    float
		float BeforePumpDepth;      // 抽水前静水位埋深(m)    float
		float AfterPumpDepth;       // 抽水后静水位埋深(m)    float
		long SectNum;               // 试验段数量    int
		float AitsTotalThick;       // 试验段含水层总厚度(m)    float
		float SectionDiam;          // 过水断面等效外径(mm)    float
	};

	// 静水位观测记录表
	struct  HYStaticWaterLevel : public Bas_PntStdInfo
	{
	public:
		long StaWaterLevelID;       //* 静水位ID    int
		std::string SWDAE;          // 试验编号    varchar
		std::string SWDDAH;         // 观测时间    date
		std::string SWDDAI;         // 延续时间(min)    varchar
		float SWEGAB;               // 水位埋深(m)    float
		float SWADET;               // 水温(℃)    float
		float SWADBB;               // 气温(℃)    float
		bool Is_Stable;             // 是否稳定    bool
		std::string _Memo;          // 备注    varchar
		long PntID;                 //* 点ID    int
		std::string PumpTestHoleNo; // 抽水试验孔号    varchar
		std::string TestHoleType;   // 试验孔类型    varchar
		float PumpHoleDist;         // 与抽水孔距离(m)    float
		float BeforePumpDepth;      // 抽水前静水位埋深(m)    float
		float AfterPumpDepth;       // 抽水后静水位埋深(m)    float
		long SectNum;               // 试验段数量    int
		float AitsTotalThick;       // 试验段含水层总厚度(m)    float
		float SectionDiam;          // 过水断面等效外径(mm)    float
	};

	// 恢复水位观测记录表
	struct  HYRevieWaterLevel : public Bas_PntStdInfo
	{
	public:
		long ReWaterLevelID;          //* 恢复水位ID    int
		std::string SWDAE;            // 试验编号    varchar
		std::string SWDDBG;           // 落程编号    varchar
		std::string SWDDAH;           // 观测时间    date
		std::string RecoveryDuration; // 恢复延续时间(min)    varchar
		float SWEGAB;                 // 水位埋深(m)    float
		float SWDDBH;                 // 水位降深(m)    float
		float SWADET;                 // 水温(℃)    float
		float SWADBB;                 // 气温(℃)    float
		bool Is_Stable;               // 是否稳定    bool
		std::string _Memo;            // 备注    varchar
		long PntID;                   //* 点ID    int
		std::string PumpTestHoleNo;   // 抽水试验孔号    varchar
		std::string TestHoleType;     // 试验孔类型    varchar
		float PumpHoleDist;           // 与抽水孔距离(m)    float
		float BeforePumpDepth;        // 抽水前静水位埋深(m)    float
		float AfterPumpDepth;         // 抽水后静水位埋深(m)    float
		long SectNum;                 // 试验段数量    int
		float AitsTotalThick;         // 试验段含水层总厚度(m)    float
		float SectionDiam;            // 过水断面等效外径(mm)    float
	};

	// 注水试验观测记录表
	struct  HYWaterInjectOb : public Bas_PntStdInfo
	{
	public:
		long WaterInjectLevelID;       //* 注水水位ID    int
		long PrjID;                    // 项目ID    int
		std::string PrjCode;           // 项目编号    varchar
		std::string SWDDAH;            // 观测时间    date
		std::string SWDDAI;            // 延续时间(分钟)    varchar
		float SWEGAB;                  // 水位埋深(m)    float
		float WaterHeadValue;          // 水头值(m)    float
		float WaterInjectVolume;       // 注水量(L)    float
		float InjectionFlow;           // 注入流量(L/min)    float
		bool Is_Stable;                // 是否稳定    bool
		std::string WaterInjectNO;     // 注水试验编号    varchar
		long PntID;                    //* 点ID    int
		std::string WaterInjectHoleNo; // 注水试验孔号    varchar
		std::string TestMethod;        // 试验方法    varchar
		std::string WaterVolumeObInst; // 水量观测仪器    varchar
		std::string WaterLevelObInst;  // 水位观测仪器    varchar
		std::string SWDDAA;            // 试验开始时间    date
		std::string SWDDAB;            // 试验结束时间    date
		std::string FlowStableTime;    // 流量稳定时间    date
		float SWDACD;                  // 试验段起始深度(m)    float
		float SWDACE;                  // 试验段终止深度(m)    float
		float SectionLength;           // 试验段长度(m)    float
		float Innerdiameter;           // 套管内径(mm)    float
		float BuryDepth_Before;        // 注水前静水位埋深(m)    float
		float BuryDepth_After;         // 注水后静水位埋深(m)    float
		float SWGGAA;                  // 渗透系数(m/d)    float
		float HyConductivity;          // 导水系数(m2/d)    float
		std::string PlanePosMap;       // 平面位置示意图    varchar
		std::string ProfileMap;        // 剖面示意图    varchar
		std::string FieldImage;        // 野外照片(视频)    varchar
		std::string RecordCard;        // 记录卡片(记录)    varchar
		std::string TestOrgn;          // 试验单位    varchar
		std::string JJDAC;             // 记录人    varchar
		std::string _Observer;         // 观测人    varchar
		std::string Inputer;           // 录入员    varchar
		std::string InputOrgn;         // 录入单位    varchar
		std::string InputDate;         // 录入日期    date
		std::string _Memo;             // 备注    varchar
	};

	// 回灌实验成果表
	struct  HYRechargeExp : public Bas_PntStdInfo
	{
	public:
		long RechargeExpID;            //* 回灌试验ID    int
		long PntID;                    //* 点ID    int
		std::string RechargeExpNo;     // 回灌试验编号    varchar
		long PrjID;                    // 项目ID    int
		std::string PrjCode;           // 项目编号    varchar
		std::string TestCategory;      // 试验类型    varchar
		long LiftNum;                  // 升程数量    int
		long RefillHoleNum;            // 回灌孔数量    int
		long ObHoleNum;                // 观测孔数量    int
		std::string SWDDAA;            // 试验开始时间    date
		std::string EndTime;           // 回灌结束时间    date
		std::string SWDDAB;            // 试验结束时间    date
		std::string StableDuration;    // 水位稳定延续时间(min)    varchar
		std::string WaterLevelObInst;  // 水位观测仪器    varchar
		std::string WaterVolumeObInst; // 水量观测仪器    varchar
		std::string WaterTempObInst;   // 水温观测仪器    varchar
		std::string TestHorizon;       // 试验层位    varchar
		std::string TestBedLithology;  // 试验层岩性    varchar
		float MaxVolume;               // 最大回灌量(m3/d)    float
		float MaRise;                  // 最大水位升幅(m)    float
		float MaxInfluRadius;          // 最大影响半径(m)    float
		float SWGGAA;                  // 平均渗透系数(m/d)    float
		float SWGGAO;                  // 平均导水系数(m2/d)    float
		float SWGGAL;                  // 平均储水系数    float
		float SWAEFG;                  // 平均给水度    float
		float SWGGBE;                  // 平均越流系数    float
		float AvgRechargeRate;         // 平均回灌率    float
		std::string PlanePosMap;       // 平面位置示意图    varchar
		std::string ProfileMap;        // 剖面示意图    varchar
		std::string FieldImage;        // 野外照片(视频)    varchar
		std::string RecordCard;        // 记录卡片(记录)    varchar
		std::string TestOrgn;          // 试验单位    varchar
		std::string JJDAC;             // 记录人    varchar
		std::string _Observer;         // 观测人    varchar
		std::string Inputer;           // 录入员    varchar
		std::string InputOrgn;         // 录入单位    varchar
		std::string InputDate;         // 录入日期    date
		std::string _Memo;             // 备注    varchar
	};

	// 回灌试验段信息表
	struct  HYRechargeExpSect : public Bas_PntStdInfo
	{
	public:
		long SectionID;                //* 试验段ID    int
		std::string TestSectNum;       // 试验段编号    varchar
		float FilterTopDepth;          // 试验段滤管顶深度(m)    float
		float FilterBottomDepth;       // 试验段滤管底深度(m)    float
		float FilterDiam;              // 试验段滤管外径(mm)    float
		float WateryTopDepth;          // 试验段含水层顶深度(m)    float
		float WateryBottomDepth;       // 试验段含水层底深度(m)    float
		float WateryThickness;         // 试验段含水层厚度(m)    float
		std::string SectHorizon;       // 试验段层位    varchar
		std::string WateryLithology;   // 试验段含水层岩性    varchar
		std::string RechargeExpNo;     // 回灌试验编号    varchar
		long PntID;                    //* 点ID    int
		std::string RechargeExpHoleNo; // 回灌试验孔号    varchar
		std::string TestHoleType;      // 试验孔类型    varchar
		float RechargeHoleDist;        // 与回灌孔距离(m)    float
		float BuryDepth_Before;        // 回灌前静水位埋深(m)    float
		float BuryDepth_After;         // 回灌后静水位埋深(m)    float
		long SectNum;                  // 试验段数量    int
		float TotalThickness;          // 试验段含水层总厚度(m)    float
		float EodowpSection;           // 过水断面等效外径(mm)    float
	};

	// 回灌试验升程数据表
	struct  HYRechargeExpLift : public Bas_PntStdInfo
	{
	public:
		long LiftID;                   //* 升程ID    int
		std::string LiftNo;            // 升程编号    varchar
		std::string StartTime;         // 升程开始时间    date
		std::string Endtime;           // 升程结束时间    date
		std::string StableStartTime;   // 水位稳定起始时间    date
		std::string StableTime;        // 水位稳定时长(分钟)    varchar
		float StaWaterLevelrise;       // 稳定水位回升(m)    float
		float StaRechargeVolume;       // 稳定回灌量(m3/d)    float
		float InfluRadius;             // 影响半径    float
		float SWGGAA;                  // 渗透系数    float
		float HydraCoeffic;            // 导水系数    float
		float StoreCoeffic;            // 储水系数    float
		float WaterSupply;             // 给水度    float
		float LeapfrogCoeffic;         // 越流系数    float
		std::string RechargeExpNo;     // 回灌试验编号    varchar
		long PntID;                    //* 点ID    int
		std::string RechargeExpHoleNo; // 回灌试验孔号    varchar
		std::string TestHoleType;      // 试验孔类型    varchar
		float RechargeHoleDist;        // 与回灌孔距离(m)    float
		float BuryDepth_Before;        // 回灌前静水位埋深(m)    float
		float BuryDepth_After;         // 回灌后静水位埋深(m)    float
		long SectNum;                  // 试验段数量    int
		float TotalThickness;          // 试验段含水层总厚度(m)    float
		float EodowpSection;           // 过水断面等效外径(mm)    float
	};

	// 回灌试验观测记录表
	struct  HYRechargeExpOb : public Bas_PntStdInfo
	{
	public:
		long DyWaterLevelID;           //* 回灌动水位ID    int
		long LiftID;                   // 升程ID    int
		std::string LiftNo;            // 升程编号    varchar
		std::string PrjCode;           // 项目统一编号    varchar
		std::string SWDDAH;            // 观测时间    date
		std::string RechargeDuration;  // 回灌延续时间(min)    varchar
		float SWEGAB;                  // 水位埋深(m)    float
		float WaterLevelrise;          // 水位回升(m)    float
		float SWIFCBM;                 // 回灌量(m3/d)    float
		float SWIFCBL;                 // 回灌量(L/s)    float
		float SWADET;                  // 水温(℃)    float
		float SWADBB;                  // 气温(℃)    float
		bool Is_Stable;                // 是否稳定    bool
		std::string _Memo;             // 备注    varchar
		std::string RechargeExpNo;     // 回灌试验编号    varchar
		long PntID;                    //* 点ID    int
		std::string RechargeExpHoleNo; // 回灌试验孔号    varchar
		std::string TestHoleType;      // 试验孔类型    varchar
		float RechargeHoleDist;        // 与回灌孔距离(m)    float
		float BuryDepth_Before;        // 回灌前静水位埋深(m)    float
		float BuryDepth_After;         // 回灌后静水位埋深(m)    float
		long SectNum;                  // 试验段数量    int
		float TotalThickness;          // 试验段含水层总厚度(m)    float
		float EodowpSection;           // 过水断面等效外径(mm)    float
	};

	// 热响应实验成果表
	struct  HYThermalRes : public Bas_PntStdInfo
	{
	public:
		long ThermalResID;          //* 热响应试验ID    int
		long PntID;                 //* 点ID    int
		std::string GCEBAN;         // 试验编号    varchar
		std::string TestHorizon;    // 试验层位    varchar
		long ObHoleNum;             // 观测孔数量    int
		float SWADER;               // 最低温度    float
		float SWADEQ;               // 最高温度    float
		float SWGGAU;               // 试验影响半径    float
		float GCDGAF;               // 平均导热系数    float
		float GCEBAS;               // 热扩散率    float
		float GCDGAE;               // 比热容    float
		std::string TestEquipModel; // 试验仪器及型号    varchar
		std::string SWDDAA;         // 试验开始日期    date
		std::string SWDDAB;         // 试验结束日期    date
		std::string PlanePosMap;    // 平面位置示意图    varchar
		std::string ProfileMap;     // 剖面示意图    varchar
		std::string FieldImage;     // 野外照片(视频)    varchar
		std::string RecordCard;     // 记录卡片(记录)    varchar
		std::string TestOrgn;       // 试验单位    varchar
		std::string Technician;     // 现场技术员    varchar
		std::string Inputer;        // 录入员    varchar
		std::string InputOrgn;      // 录入单位    varchar
		std::string InputDate;      // 录入日期    date
		std::string _Memo;          // 备注    varchar
	};

	// 热响应试验地温观测记录表
	struct  HYThernakResOb : public Bas_PntStdInfo
	{
	public:
		long GeoTempObID;       //* 地温观测记录ID    int
		std::string SWDDAH;     // 观测时间    date
		float GCKUGF;           // 深度(m)    float
		float SWADET;           // 温度    float
		std::string _Observer;  // 观测人    varchar
		std::string JJDAC;      // 记录人    varchar
		std::string TestHoleNo; // 试验孔号    varchar
		std::string GCEBAN;     // 试验编号    varchar
		long PntID;             //* 点ID    int
		float TKACC;            // 孔深    float
		float SWDAAX;           // 与主孔距离    float
	};

	// 渗水试验成果表
	struct  HYWaterSeepageExp : public Bas_PntStdInfo
	{
	public:
		long WaterSeepageExpID;         //* 渗水试验ID    int
		std::string WaterSeepageExpNo;  // 渗水试验编号    varchar
		long PntID;                     //* 点ID    int
		std::string WaterSeepageHoleNo; // 渗水试验孔号    varchar
		std::string TestMethod;         // 试验方法    varchar
		std::string TestHorizon;        // 试验层位    varchar
		std::string TestBedLithology;   // 试验层岩性    varchar
		float GCEBAI;                   // 试坑直径    float
		float SWDAAU;                   // 试坑底面积    float
		float GCEBAJ;                   // 试坑深度    float
		float GCEBA;                    // 内环直径    float
		float GCEBAK;                   // 外环直径    float
		float GCGDJ;                    // 渗透深度    float
		float SWGGBR;                   // 水层厚度    float
		float SWDAAV;                   // 毛细高度    float
		long SWDDAI;                    // 累计延续时间    int
		float SWDAAW;                   // 稳定流量    float
		float SWGGAA;                   // 渗透系数    float
		std::string LithologyDesc;      // 包气带岩性描述    varchar
		std::string SWDDAA;             // 试验开始时间    date
		std::string SWDDAB;             // 试验结束时间    date
		std::string PlanePosMap;        // 平面位置示意图    varchar
		std::string ProfileMap;         // 剖面示意图    varchar
		std::string FieldImage;         // 野外照片(视频)    varchar
		std::string RecordCard;         // 记录卡片(记录)    varchar
		std::string TestOrgn;           // 试验单位    varchar
		std::string JJDAC;              // 记录人    varchar
		std::string _Observer;          // 观测人    varchar
		std::string Inputer;            // 录入员    varchar
		std::string InputOrgn;          // 录入单位    varchar
		std::string InputDate;          // 录入日期    date
		std::string TKDAE;              // 天气    varchar
		std::string _Memo;              // 备注    varchar
	};

	// 渗水试验观测记录表
	struct  HYWaterSeepageExpOb : public Bas_PntStdInfo
	{
	public:
		long WaterSeepageExpObID;      //* 渗水观测记录ID    int
		long PntID;                    //* 点ID    int
		std::string WaterSeepageExpNo; // 渗水试验编号    varchar
		std::string SWDDAH;            // 观测时间    date
		float SWDDAI;                  // 延续时间    float
		float SWGCAK;                  // 渗水体积    float
		float SWGCAA;                  // 渗透流量    float
		bool Is_Stable;                // 是否稳定    bool
		std::string _Memo;             // 备注    varchar
	};

	// 混合样品对照表
	struct  SCMixSampCompare : public Bas_PntStdInfo
	{
	public:
		long MixSampleID;           //* 混合样品id    int
		std::string MixSampleNo;    // 混合样品编号    varchar
		long OriSampleID;           // 原始样品ID    int
		std::string OriSampleNo;    // 原始样品编号    varchar
		std::string PrjCode;        // 项目统一编号    varchar
		std::string GCEABB;         // 样品编号    varchar
		long PntID;                 //* 点ID    int
		std::string SWBCF;          // 样品类型    varchar
		std::string IsMixSample;    // 混合样    varchar
		std::string PntType;        // 点类型    varchar
		std::string SecondCode;     // 样品二次编码    varchar
		float SampleVolume;         // 样品体积    float
		std::string GCEABM;         // 野外命名    varchar
		float GCEAAL;               // 样品重量(kg)    float
		std::string SampleLength;   // 样品长度(cm)    varchar
		std::string PretreatMethod; // 预处理方法    varchar
		std::string TestContent;    // 测试内容    varchar
		std::string PlanePosMap;    // 平面位置示意图    varchar
		std::string ProfileMap;     // 剖面示意图    varchar
		std::string FieldImage;     // 野外照片(视频)    varchar
		std::string RecordCard;     // 记录卡片(记录)    varchar
		std::string SampleOrgn;     // 采样单位    varchar
		std::string SWFOMW;         // 采样人    varchar
		std::string GCEABJ;         // 采样日期    date
		std::string Inputer;        // 录入员    varchar
		std::string InputOrgn;      // 录入单位    varchar
		std::string InputDate;      // 录入日期    date
	};

	// 岩石样品基本情况表
	struct  SCRockSample : public Bas_PntStdInfo
	{
	public:
		long RockID;                 //* 岩样ID    int
		std::string SampleBagNo;     // 样品袋号    varchar
		std::string SampleColor;     // 样品颜色    varchar
		std::string GCKLT;           // 岩性描述    varchar
		std::string MineralContent;  // 矿物成分及含量    varchar
		std::string RockFormat;      // 岩层倾向    varchar
		std::string StratumDip;      // 岩层倾角    varchar
		std::string JointFissure;    // 节理裂隙    varchar
		std::string MineralizatType; // 矿化类型    varchar
		std::string AlteratType;     // 蚀变类型    varchar
		std::string KarstType;       // 岩溶类型    varchar
		std::string _Memo;           // 备注    varchar
		std::string GCEABB;          // 样品编号    varchar
		long PntID;                  //* 点ID    int
		std::string SWBCF;           // 样品类型    varchar
		std::string IsMixSample;     // 混合样    varchar
		std::string PntType;         // 点类型    varchar
		std::string SecondCode;      // 样品二次编码    varchar
		float SampleVolume;          // 样品体积    float
		std::string GCEABM;          // 野外命名    varchar
		float GCEAAL;                // 样品重量(kg)    float
		std::string SampleLength;    // 样品长度(cm)    varchar
		std::string PretreatMethod;  // 预处理方法    varchar
		std::string TestContent;     // 测试内容    varchar
		std::string PlanePosMap;     // 平面位置示意图    varchar
		std::string ProfileMap;      // 剖面示意图    varchar
		std::string FieldImage;      // 野外照片(视频)    varchar
		std::string RecordCard;      // 记录卡片(记录)    varchar
		std::string SampleOrgn;      // 采样单位    varchar
		std::string SWFOMW;          // 采样人    varchar
		std::string GCEABJ;          // 采样日期    date
		std::string Inputer;         // 录入员    varchar
		std::string InputOrgn;       // 录入单位    varchar
		std::string InputDate;       // 录入日期    date
	};

	// 土壤样品基本情况表
	struct  SCSoilSample : public Bas_PntStdInfo
	{
	public:
		long SoilID;                //* 土壤样ID    int
		std::string SampleBagNo;    // 样品袋号    varchar
		std::string CombinedSampID; // 组合样数    varchar
		std::string CauseType;      // 成因类型    varchar
		std::string SampleColor;    // 样品颜色    varchar
		std::string GCKLT;          // 岩性描述    varchar
		float CoarsesandContent;    // 粗砂含量    float
		float FinesandContent;      // 细砂含量    float
		float ClayContent;          // 粘土含量    float
		std::string _Pollution;     // 污染    varchar
		std::string _Erosion;       // 侵蚀    varchar
		std::string _Salted;        // 盐渍    varchar
		std::string _Crop;          // 农作物    varchar
		std::string _Culture;       // 养殖物    varchar
		std::string FamousProduct;  // 名优特产品    varchar
		std::string SoilUsing;      // 土地利用    varchar
		std::string MarkPos;        // 标记位置    varchar
		std::string SWFGAA;         // 采样层位    varchar
		std::string _Memo;          // 备注    varchar
		std::string GCEABB;         // 样品编号    varchar
		long PntID;                 //* 点ID    int
		std::string SWBCF;          // 样品类型    varchar
		std::string IsMixSample;    // 混合样    varchar
		std::string PntType;        // 点类型    varchar
		std::string SecondCode;     // 样品二次编码    varchar
		float SampleVolume;         // 样品体积    float
		std::string GCEABM;         // 野外命名    varchar
		float GCEAAL;               // 样品重量(kg)    float
		std::string SampleLength;   // 样品长度(cm)    varchar
		std::string PretreatMethod; // 预处理方法    varchar
		std::string TestContent;    // 测试内容    varchar
		std::string PlanePosMap;    // 平面位置示意图    varchar
		std::string ProfileMap;     // 剖面示意图    varchar
		std::string FieldImage;     // 野外照片(视频)    varchar
		std::string RecordCard;     // 记录卡片(记录)    varchar
		std::string SampleOrgn;     // 采样单位    varchar
		std::string SWFOMW;         // 采样人    varchar
		std::string GCEABJ;         // 采样日期    date
		std::string Inputer;        // 录入员    varchar
		std::string InputOrgn;      // 录入单位    varchar
		std::string InputDate;      // 录入日期    date
	};

	// 水体沉积物样品基本情况表
	struct  SCWaterSediment : public Bas_PntStdInfo
	{
	public:
		long WaterSedimentID;       //* 沉积物样ID    int
		std::string SampleBagNo;    // 样品袋号    varchar
		std::string WaterName;      // 水体名称    varchar
		std::string SampleSite;     // 采样部位    varchar
		float SWNCAH;               // 水深(m)    float
		std::string CauseType;      // 成因类型    varchar
		std::string SampleColor;    // 样品颜色    varchar
		std::string GCKLT;          // 岩性描述    varchar
		float CoarsesandContent;    // 粗砂含量(%)    float
		float FinesandContent;      // 细砂含量(%)    float
		float ClayContent;          // 粘土含量(%)    float
		float OrganicContent;       // 有机物含量(%)    float
		std::string BioRemain;      // 生物残骸    varchar
		std::string _Pollute;       // 污染情况    varchar
		std::string _Memo;          // 备注    varchar
		std::string GCEABB;         // 样品编号    varchar
		long PntID;                 //* 点ID    int
		std::string SWBCF;          // 样品类型    varchar
		std::string IsMixSample;    // 混合样    varchar
		std::string PntType;        // 点类型    varchar
		std::string SecondCode;     // 样品二次编码    varchar
		float SampleVolume;         // 样品体积    float
		std::string GCEABM;         // 野外命名    varchar
		float GCEAAL;               // 样品重量(kg)    float
		std::string SampleLength;   // 样品长度(cm)    varchar
		std::string PretreatMethod; // 预处理方法    varchar
		std::string TestContent;    // 测试内容    varchar
		std::string PlanePosMap;    // 平面位置示意图    varchar
		std::string ProfileMap;     // 剖面示意图    varchar
		std::string FieldImage;     // 野外照片(视频)    varchar
		std::string RecordCard;     // 记录卡片(记录)    varchar
		std::string SampleOrgn;     // 采样单位    varchar
		std::string SWFOMW;         // 采样人    varchar
		std::string GCEABJ;         // 采样日期    date
		std::string Inputer;        // 录入员    varchar
		std::string InputOrgn;      // 录入单位    varchar
		std::string InputDate;      // 录入日期    date
	};

	// 沉积物柱状样品分层描述表
	struct  SCSedimentColumn : public Bas_PntStdInfo
	{
	public:
		long ColumnID;              //* 柱状样分层ID    int
		std::string FieldLayerNum;  // 野外分层号    varchar
		float LayerDepth;           //* 分层深度(m)    float
		float LayerThickness;       // 层厚(m)    float
		std::string GCKLQ;          // 岩性名称    varchar
		std::string LayerDesc;      // 分层描述    varchar
		std::string GCEABB;         // 样品编号    varchar
		long PntID;                 //* 点ID    int
		std::string SWBCF;          // 样品类型    varchar
		std::string IsMixSample;    // 混合样    varchar
		std::string PntType;        // 点类型    varchar
		std::string SecondCode;     // 样品二次编码    varchar
		float SampleVolume;         // 样品体积    float
		std::string GCEABM;         // 野外命名    varchar
		float GCEAAL;               // 样品重量(kg)    float
		std::string SampleLength;   // 样品长度(cm)    varchar
		std::string PretreatMethod; // 预处理方法    varchar
		std::string TestContent;    // 测试内容    varchar
		std::string PlanePosMap;    // 平面位置示意图    varchar
		std::string ProfileMap;     // 剖面示意图    varchar
		std::string FieldImage;     // 野外照片(视频)    varchar
		std::string RecordCard;     // 记录卡片(记录)    varchar
		std::string SampleOrgn;     // 采样单位    varchar
		std::string SWFOMW;         // 采样人    varchar
		std::string GCEABJ;         // 采样日期    date
		std::string Inputer;        // 录入员    varchar
		std::string InputOrgn;      // 录入单位    varchar
		std::string InputDate;      // 录入日期    date
	};

	// 大气沉降样品基本情况表
	struct  SCAtmosSample : public Bas_PntStdInfo
	{
	public:
		long AtmodepositID;         //* 大气沉降样ID    int
		std::string SampleBagNo;    // 样品袋号(缸号)    varchar
		std::string SampleColor;    // 样品颜色    varchar
		std::string DustfallType;   // 降尘类型    varchar
		std::string _Precipitat;    // 降水情况    varchar
		float _Depth;               // 离地高度(m)    float
		std::string _Surround;      // 周围环境    varchar
		std::string _Memo;          // 备注    varchar
		std::string GCEABB;         // 样品编号    varchar
		long PntID;                 //* 点ID    int
		std::string SWBCF;          // 样品类型    varchar
		std::string IsMixSample;    // 混合样    varchar
		std::string PntType;        // 点类型    varchar
		std::string SecondCode;     // 样品二次编码    varchar
		float SampleVolume;         // 样品体积    float
		std::string GCEABM;         // 野外命名    varchar
		float GCEAAL;               // 样品重量(kg)    float
		std::string SampleLength;   // 样品长度(cm)    varchar
		std::string PretreatMethod; // 预处理方法    varchar
		std::string TestContent;    // 测试内容    varchar
		std::string PlanePosMap;    // 平面位置示意图    varchar
		std::string ProfileMap;     // 剖面示意图    varchar
		std::string FieldImage;     // 野外照片(视频)    varchar
		std::string RecordCard;     // 记录卡片(记录)    varchar
		std::string SampleOrgn;     // 采样单位    varchar
		std::string SWFOMW;         // 采样人    varchar
		std::string GCEABJ;         // 采样日期    date
		std::string Inputer;        // 录入员    varchar
		std::string InputOrgn;      // 录入单位    varchar
		std::string InputDate;      // 录入日期    date
	};

	// 水样基本情况表
	struct  SCWaterSample : public Bas_PntStdInfo
	{
	public:
		long WaterSampleID;         //* 水样ID    int
		std::string WaterName;      // 水体名称    varchar
		std::string SampleSite;     // 采样部位    varchar
		float SWNCAH;               // 水深(m)    float
		float SWEGAB;               // 水位埋深(m)    float
		float Welldepth;            // 井深(m)    float
		float SWADET;               // 水温(℃)    float
		std::string WaterColor;     // 水色    varchar
		std::string WaterSmelly;    // 水臭    varchar
		float PKJFP;                // 浊度    float
		float PH;                   // pH值    float
		std::string BottomProduct;  // 底积物    varchar
		std::string _Pollution;     // 污染    varchar
		std::string _Use;           // 用途    varchar
		std::string _Mark;          // 标记    varchar
		std::string _Memo;          // 备注    varchar
		std::string GCEABB;         // 样品编号    varchar
		long PntID;                 //* 点ID    int
		std::string SWBCF;          // 样品类型    varchar
		std::string IsMixSample;    // 混合样    varchar
		std::string PntType;        // 点类型    varchar
		std::string SecondCode;     // 样品二次编码    varchar
		float SampleVolume;         // 样品体积    float
		std::string GCEABM;         // 野外命名    varchar
		float GCEAAL;               // 样品重量(kg)    float
		std::string SampleLength;   // 样品长度(cm)    varchar
		std::string PretreatMethod; // 预处理方法    varchar
		std::string TestContent;    // 测试内容    varchar
		std::string PlanePosMap;    // 平面位置示意图    varchar
		std::string ProfileMap;     // 剖面示意图    varchar
		std::string FieldImage;     // 野外照片(视频)    varchar
		std::string RecordCard;     // 记录卡片(记录)    varchar
		std::string SampleOrgn;     // 采样单位    varchar
		std::string SWFOMW;         // 采样人    varchar
		std::string GCEABJ;         // 采样日期    date
		std::string Inputer;        // 录入员    varchar
		std::string InputOrgn;      // 录入单位    varchar
		std::string InputDate;      // 录入日期    date
	};

	// 水悬浮物样品基本情况表
	struct  SCWaterSuspend : public Bas_PntStdInfo
	{
	public:
		long SuspendID;             //* 水悬物样ID    int
		std::string SampleBagNo;    // 样品袋号    varchar
		std::string WaterName;      // 水体名称    varchar
		std::string SampleSite;     // 采样部位    varchar
		float SWNCAH;               // 水深(m)    float
		std::string SampleColor;    // 样品颜色    varchar
		std::string _Memo;          // 备注    varchar
		std::string GCEABB;         // 样品编号    varchar
		long PntID;                 //* 点ID    int
		std::string SWBCF;          // 样品类型    varchar
		std::string IsMixSample;    // 混合样    varchar
		std::string PntType;        // 点类型    varchar
		std::string SecondCode;     // 样品二次编码    varchar
		float SampleVolume;         // 样品体积    float
		std::string GCEABM;         // 野外命名    varchar
		float GCEAAL;               // 样品重量(kg)    float
		std::string SampleLength;   // 样品长度(cm)    varchar
		std::string PretreatMethod; // 预处理方法    varchar
		std::string TestContent;    // 测试内容    varchar
		std::string PlanePosMap;    // 平面位置示意图    varchar
		std::string ProfileMap;     // 剖面示意图    varchar
		std::string FieldImage;     // 野外照片(视频)    varchar
		std::string RecordCard;     // 记录卡片(记录)    varchar
		std::string SampleOrgn;     // 采样单位    varchar
		std::string SWFOMW;         // 采样人    varchar
		std::string GCEABJ;         // 采样日期    date
		std::string Inputer;        // 录入员    varchar
		std::string InputOrgn;      // 录入单位    varchar
		std::string InputDate;      // 录入日期    date
	};

	// 动植物样品基本情况表
	struct  SCAnimalPlant : public Bas_PntStdInfo
	{
	public:
		long AnimalSampID;          //* 动(植)样ID    int
		std::string AniPlantType;   // 动(植)物类型    varchar
		std::string AniPlantName;   // 动(植)物名称    varchar
		std::string SampleSite;     // 采样部位    varchar
		std::string SampleColor;    // 样品颜色    varchar
		std::string _Storage;       // 样品储存    varchar
		std::string _Process;       // 样品加工    varchar
		std::string GCKBBA;         // 地貌    varchar
		std::string SoilCauseType;  // 土壤成因类型    varchar
		std::string _Memo;          // 备注    varchar
		std::string GCEABB;         // 样品编号    varchar
		long PntID;                 //* 点ID    int
		std::string SWBCF;          // 样品类型    varchar
		std::string IsMixSample;    // 混合样    varchar
		std::string PntType;        // 点类型    varchar
		std::string SecondCode;     // 样品二次编码    varchar
		float SampleVolume;         // 样品体积    float
		std::string GCEABM;         // 野外命名    varchar
		float GCEAAL;               // 样品重量(kg)    float
		std::string SampleLength;   // 样品长度(cm)    varchar
		std::string PretreatMethod; // 预处理方法    varchar
		std::string TestContent;    // 测试内容    varchar
		std::string PlanePosMap;    // 平面位置示意图    varchar
		std::string ProfileMap;     // 剖面示意图    varchar
		std::string FieldImage;     // 野外照片(视频)    varchar
		std::string RecordCard;     // 记录卡片(记录)    varchar
		std::string SampleOrgn;     // 采样单位    varchar
		std::string SWFOMW;         // 采样人    varchar
		std::string GCEABJ;         // 采样日期    date
		std::string Inputer;        // 录入员    varchar
		std::string InputOrgn;      // 录入单位    varchar
		std::string InputDate;      // 录入日期    date
	};

	// 岩石物理力学实验成果表
	struct  INRockPhysics : public Bas_PntStdInfo
	{
	public:
		long RockTestID;            //* 岩石试验ID    int
		std::string TCDH;           //* 采样层位    varchar
		float StartDepth;           //* 取样顶深度    float
		float EndDepth;             //* 取样底深度    float
		long PntID;                 //* 点ID    int
		std::string TCMC;           // 土层名称    varchar
		std::string GeoCode;        // 地质代号    varchar
		std::string TestNo;         //     varchar
		std::string TestType;       // 试验类型    varchar
		float GCBHKY;               // 饱和抗压强度(MPa)    float
		float GCGZKY;               // 干燥抗压强度(MPa)    float
		float _Saturated;           // 饱和抗拉强度(MPa)    float
		float _dry;                 // 干燥抗拉强度(MPa)    float
		float GCCBG;                // 软化系数    float
		float GCBFOA;               // 内聚力(MPa)    float
		float GCDMAC;               // 内摩擦角(度)    float
		float MaximumStress;        // 最大正应力(MPa)    float
		float GCDKBB;               // 弹性模量(MPa)    float
		float GCDLAH;               // 泊松比    float
		float BlockDensity;         // 块体密度(g/cm3)    float
		float GCDAO;                // 颗粒密度(g/cm3)    float
		float GCDBB;                // 孔隙率(%)    float
		float SatWaterRate;         // 饱和吸水率(%)    float
		std::string GCEABB;         // 样品编号    varchar
		std::string SWBCF;          // 样品类型    varchar
		std::string IsMixSample;    // 混合样    varchar
		std::string PntType;        // 点类型    varchar
		std::string SecondCode;     // 样品二次编码    varchar
		float SampleVolume;         // 样品体积    float
		std::string GCEABM;         // 野外命名    varchar
		float GCEAAL;               // 样品重量(kg)    float
		std::string SampleLength;   // 样品长度(cm)    varchar
		std::string PretreatMethod; // 预处理方法    varchar
		std::string TestContent;    // 测试内容    varchar
		std::string PlanePosMap;    // 平面位置示意图    varchar
		std::string ProfileMap;     // 剖面示意图    varchar
		std::string FieldImage;     // 野外照片(视频)    varchar
		std::string RecordCard;     // 记录卡片(记录)    varchar
		std::string SampleOrgn;     // 采样单位    varchar
		std::string SWFOMW;         // 采样人    varchar
		std::string GCEABJ;         // 采样日期    date
		std::string Inputer;        // 录入员    varchar
		std::string InputOrgn;      // 录入单位    varchar
		std::string InputDate;      // 录入日期    date
		std::string GCEABD;         // 室内编号    varchar
		std::string TestEquip;      // 试验仪器    varchar
		std::string TestMethod;     // 试验方法    varchar
		std::string TestBased;      // 检验依据    varchar
		std::string GCEAJC;         // 试验单位    varchar
		std::string SWFGAM;         // 收样日期    date
		std::string SWFGAN;         // 报告日期    date
		std::string GCEAJD;         // 校对    varchar
		std::string Auditor;        // 审核    varchar
		std::string TestLeader;     // 试验负责人    varchar
		std::string _Report;        // 原始测试分析报告    varchar
	};

	// 常规土工实验成果表 *
	struct  INGeotechnicalExp : public Bas_PntStdInfo
	{
	public:
		long GeotechnicalID;        //* 土工ID    int
		float StartDepth;           //* 取样顶深度    float
		float EndDepth;             //* 取样底深度    float
		long PntID;                 //* 点ID    int
		std::string TCDH;           //* 采样层位    varchar
		std::string TCMC;           // 土层名称    varchar
		std::string GeoCode;        // 地质代号    varchar
		std::string TestNo;         //     varchar
		std::string TestType;       // 试验类型    varchar
		float ZD;                   // 重度    float
		float GZD;                  // 干重度    float
		float GCDAL;                // 湿密度(g/cm3)    float
		float GCDAE;                // 干密度(g/cm3)    float
		float BZ;                   // 比重    float
		float GCDCAO;               // 含水率(%)    float
		float GCDBB;                // 孔隙比    float
		float DHABCU;               // 饱和度(%)    float
		float SoilGravity;          // 土粒比重    float
		float GCDDD;                // 液限(%)    float
		float GCDDC;                // 塑限(%)    float
		float GCDDE;                // 塑性指数    float
		float GCDDF;                // 液性指数    float
		float CureCoefficient;      // 曲率系数    float
		float GCKBCQ;               // 不均匀系数    float
		float EffectParticleSize;   // 有效粒径(mm)    float
		float GCDLAC;               // 压缩系数(MPa-1)    float
		float XQGJYL;               // 先期固结压力    float
		float YSZS;                 // 压缩指数    float
		float HTZS;                 // 回弹指数    float
		float GCBFOA;               // （天然快剪）粘聚力(kPa)    float
		float GCDMAC;               // （天然快剪）内摩擦角(度)    float
		float GJKJNJL;              // 固结快剪粘聚力    float
		float GJKJNMCJ;             // 固结快剪内摩擦角    float
		float MJNJL;                // 慢剪粘聚力    float
		float MJNMCJ;               // 慢剪内摩擦角    float
		float GCDEAF;               // 自由膨胀率(%)    float
		float TOC;                  // 有机质含量(%)    float
		float FineGrained;          // 细粒土含水率(%)    float
		float SWGGAC;               // 垂向渗透系数(cm/s)    float
		float SWGGAB;               // 水平渗透系数(cm/s)    float
		float UnderWaterAngle;      // 水下休止角(坡角)(度)    float
		float UpWaterAngle;         // 水上休止角坡角(度)    float
		float YZ;                   // 原状(QU)    float
		float CS;                   // 重塑(QU_)    float
		float LMD;                  // 灵敏度    float
		float QT1;                  // 液限（100g锥）    float
		float QT2;                  // 塑性（100g锥）    float
		float SZUUNJL;              // 三轴UU法粘聚力©    float
		float SZUUNMCJ;             // 三轴UU法内摩擦角(Φ)    float
		float SZUUNJL_;             // 三轴UU法粘聚力(C1)    float
		float SZCUNJL;              // 三轴CU法粘聚力(C)    float
		float SZCUNMCJ;             // 三轴CU法内摩擦角(Φ)    float
		float SZCUNJL_;             // 三轴CU法粘聚力(C_)    float
		float SZCUNMCJ_;            // 三轴CU法内摩擦角(Φ_)    float
		float GCDKBD1;              // 压缩模量1(MPa)    float
		float GCDKBD2;              // 压缩模量2(MPa)    float
		float GCDKBD3;              // 压缩模量3(MPa)    float
		float GCDKBD4;              // 压缩模量4(MPa)    float
		float GCDKBD5;              // 压缩模量5(MPa)    float
		float GCDKBD6;              // 压缩模量6(MPa)    float
		float GCDKBD7;              // 压缩模量7(MPa)    float
		float GCDKBD8;              // 压缩模量8(MPa)    float
		float GCDKBD9;              // 压缩模量9(MPa)    float
		float GCDKBD10;             // 压缩模量10(MPa)    float
		float GJXS1;                // 固结系数1(KPa)    float
		float GJXS2;                // 固结系数2(KPa)    float
		float GJXS3;                // 固结系数3(KPa)    float
		float GJXS4;                // 固结系数4(KPa)    float
		float GJXS5;                // 固结系数5(KPa)    float
		float GJXS6;                // 固结系数6(KPa)    float
		float GJXS7;                // 固结系数7(KPa)    float
		float GJXS8;                // 固结系数8(KPa)    float
		float GJXS9;                // 固结系数9(KPa)    float
		float GJXS10;               // 固结系数10(KPa)    float
		float KLZC1;                // 颗粒组成1(%)    float
		float KLZC2;                // 颗粒组成2(%)    float
		float KLZC3;                // 颗粒组成3(%)    float
		float KLZC4;                // 颗粒组成4(%)    float
		float KLZC5;                // 颗粒组成5(%)    float
		float KLZC6;                // 颗粒组成6(%)    float
		float KLZC7;                // 颗粒组成7(%)    float
		float KLZC8;                // 颗粒组成8(%)    float
		float KLZC9;                // 颗粒组成9(%)    float
		float KLZC10;               // 颗粒组成10(%)    float
		float KLZC11;               // 颗粒组成11(%)    float
		float KLZC12;               // 颗粒组成12(%)    float
		float KLZC13;               // 颗粒组成13(%)    float
		float KLZC14;               // 颗粒组成14(%)    float
		float KLZC15;               // 颗粒组成15(%)    float
		std::string GCEABB;         // 样品编号    varchar
		std::string SWBCF;          // 样品类型    varchar
		std::string IsMixSample;    // 混合样    varchar
		std::string PntType;        // 点类型    varchar
		std::string SecondCode;     // 样品二次编码    varchar
		float SampleVolume;         // 样品体积    float
		std::string GCEABM;         // 野外命名    varchar
		float GCEAAL;               // 样品重量(kg)    float
		std::string SampleLength;   // 样品长度(cm)    varchar
		std::string PretreatMethod; // 预处理方法    varchar
		std::string TestContent;    // 测试内容    varchar
		std::string PlanePosMap;    // 平面位置示意图    varchar
		std::string ProfileMap;     // 剖面示意图    varchar
		std::string FieldImage;     // 野外照片(视频)    varchar
		std::string RecordCard;     // 记录卡片(记录)    varchar
		std::string SampleOrgn;     // 采样单位    varchar
		std::string SWFOMW;         // 采样人    varchar
		std::string GCEABJ;         // 采样日期    date
		std::string Inputer;        // 录入员    varchar
		std::string InputOrgn;      // 录入单位    varchar
		std::string InputDate;      // 录入日期    date
		std::string GCEABD;         // 室内编号    varchar
		std::string GCEABL;         // 室内名称    varchar
		std::string TestEquip;      // 试验仪器    varchar
		std::string TestMethod;     // 试验方法    varchar
		std::string TestBased;      // 检验依据    varchar
		std::string GCEAJC;         // 试验单位    varchar
		std::string SWFGAM;         // 收样日期    date
		std::string SWFGAN;         // 报告日期    date
		std::string GCEAJD;         // 校对    varchar
		std::string Auditor;        // 审核    varchar
		std::string TestLeader;     // 试验负责人    varchar
		std::string _Report;        // 原始测试分析报告    varchar
	};

	// 高压固结实验成果表 *
	struct  INConsolidatl : public Bas_PntStdInfo
	{
	public:
		long ConsolidatID;          //* 高压固结ID    int
		float StartDepth;           //* 取样顶深度    float
		float EndDepth;             //* 取样底深度    float
		long PntID;                 //* 点ID    int
		std::string TCDH;           //* 采样层位    varchar
		std::string TCMC;           // 土层名称    varchar
		std::string GeoCode;        // 地质代号    varchar
		std::string TestNo;         //     varchar
		std::string TestType;       // 试验类型    varchar
		float GCDLAF;               // 先期固结压力(kPa)    float
		float CompressIndex;        // 压缩指数    float
		float ReboundIndex;         // 回弹指数    float
		float ConsolidatPressure;   // 固结压力(kPa)    float
		float GCDBB;                // 孔隙比    float
		float GCDKBD;               // 压缩模量    float
		float GCDLAC;               // 压缩系数    float
		float VerticalConsolidat;   // 竖向固结系数    float
		float HorizontalConsolidat; // 水平固结系数    float
		std::string GCEABB;         // 样品编号    varchar
		std::string SWBCF;          // 样品类型    varchar
		std::string IsMixSample;    // 混合样    varchar
		std::string PntType;        // 点类型    varchar
		std::string SecondCode;     // 样品二次编码    varchar
		float SampleVolume;         // 样品体积    float
		std::string GCEABM;         // 野外命名    varchar
		float GCEAAL;               // 样品重量(kg)    float
		std::string SampleLength;   // 样品长度(cm)    varchar
		std::string PretreatMethod; // 预处理方法    varchar
		std::string TestContent;    // 测试内容    varchar
		std::string PlanePosMap;    // 平面位置示意图    varchar
		std::string ProfileMap;     // 剖面示意图    varchar
		std::string FieldImage;     // 野外照片(视频)    varchar
		std::string RecordCard;     // 记录卡片(记录)    varchar
		std::string SampleOrgn;     // 采样单位    varchar
		std::string SWFOMW;         // 采样人    varchar
		std::string GCEABJ;         // 采样日期    date
		std::string Inputer;        // 录入员    varchar
		std::string InputOrgn;      // 录入单位    varchar
		std::string InputDate;      // 录入日期    date
		std::string GCEABD;         // 室内编号    varchar
		std::string TestEquip;      // 试验仪器    varchar
		std::string TestMethod;     // 试验方法    varchar
		std::string TestBased;      // 检验依据    varchar
		std::string GCEAJC;         // 试验单位    varchar
		std::string SWFGAM;         // 收样日期    date
		std::string SWFGAN;         // 报告日期    date
		std::string GCEAJD;         // 校对    varchar
		std::string Auditor;        // 审核    varchar
		std::string TestLeader;     // 试验负责人    varchar
		std::string _Report;        // 原始测试分析报告    varchar
	};

	// 无侧限压缩试验成果表
	struct  INUnconfined : public Bas_PntStdInfo
	{
	public:
		long UnconfinedID;          //* 无侧限ID    int
		float StartDepth;           //* 取样顶深度    float
		float EndDepth;             //* 取样底深度    float
		long PntID;                 //* 点ID    int
		std::string TCDH;           //* 采样层位    varchar
		std::string TCMC;           // 土层名称    varchar
		std::string GeoCode;        // 地质代号    varchar
		std::string TestNo;         //     varchar
		std::string TestType;       // 试验类型    varchar
		float GCDMAM;               // 原状土无侧限抗压强度(kPa)    float
		float GCDMAO;               // 重塑土无侧限抗压强度(kPa)    float
		float GCDKCR;               // 不排水抗剪强度(kPa)    float
		float GCBFI;                // 灵敏度    float
		std::string GCEABB;         // 样品编号    varchar
		std::string SWBCF;          // 样品类型    varchar
		std::string IsMixSample;    // 混合样    varchar
		std::string PntType;        // 点类型    varchar
		std::string SecondCode;     // 样品二次编码    varchar
		float SampleVolume;         // 样品体积    float
		std::string GCEABM;         // 野外命名    varchar
		float GCEAAL;               // 样品重量(kg)    float
		std::string SampleLength;   // 样品长度(cm)    varchar
		std::string PretreatMethod; // 预处理方法    varchar
		std::string TestContent;    // 测试内容    varchar
		std::string PlanePosMap;    // 平面位置示意图    varchar
		std::string ProfileMap;     // 剖面示意图    varchar
		std::string FieldImage;     // 野外照片(视频)    varchar
		std::string RecordCard;     // 记录卡片(记录)    varchar
		std::string SampleOrgn;     // 采样单位    varchar
		std::string SWFOMW;         // 采样人    varchar
		std::string GCEABJ;         // 采样日期    date
		std::string Inputer;        // 录入员    varchar
		std::string InputOrgn;      // 录入单位    varchar
		std::string InputDate;      // 录入日期    date
		std::string GCEABD;         // 室内编号    varchar
		std::string TestEquip;      // 试验仪器    varchar
		std::string TestMethod;     // 试验方法    varchar
		std::string TestBased;      // 检验依据    varchar
		std::string GCEAJC;         // 试验单位    varchar
		std::string SWFGAM;         // 收样日期    date
		std::string SWFGAN;         // 报告日期    date
		std::string GCEAJD;         // 校对    varchar
		std::string Auditor;        // 审核    varchar
		std::string TestLeader;     // 试验负责人    varchar
		std::string _Report;        // 原始测试分析报告    varchar
	};

	// 三轴实验成果表
	struct  INThreeaxis : public Bas_PntStdInfo
	{
	public:
		long ThreeaxisID;           //* 三轴ID    int
		float StartDepth;           //* 取样顶深度    float
		float EndDepth;             //* 取样底深度    float
		long PntID;                 //* 点ID    int
		std::string TCDH;           //* 采样层位    varchar
		std::string TCMC;           // 土层名称    varchar
		std::string GeoCode;        // 地质代号    varchar
		std::string TestNo;         //     varchar
		std::string TestType;       // 试验类型    varchar
		float GCBFOA;               // 粘聚力(kPa)    float
		float FrictionAngle;        // 摩擦角(度)    float
		float EffectCohes;          // 有效粘聚力(kPa)    float
		float EffectFrictAngle;     // 有效摩擦角(度)    float
		std::string GCEABB;         // 样品编号    varchar
		std::string SWBCF;          // 样品类型    varchar
		std::string IsMixSample;    // 混合样    varchar
		std::string PntType;        // 点类型    varchar
		std::string SecondCode;     // 样品二次编码    varchar
		float SampleVolume;         // 样品体积    float
		std::string GCEABM;         // 野外命名    varchar
		float GCEAAL;               // 样品重量(kg)    float
		std::string SampleLength;   // 样品长度(cm)    varchar
		std::string PretreatMethod; // 预处理方法    varchar
		std::string TestContent;    // 测试内容    varchar
		std::string PlanePosMap;    // 平面位置示意图    varchar
		std::string ProfileMap;     // 剖面示意图    varchar
		std::string FieldImage;     // 野外照片(视频)    varchar
		std::string RecordCard;     // 记录卡片(记录)    varchar
		std::string SampleOrgn;     // 采样单位    varchar
		std::string SWFOMW;         // 采样人    varchar
		std::string GCEABJ;         // 采样日期    date
		std::string Inputer;        // 录入员    varchar
		std::string InputOrgn;      // 录入单位    varchar
		std::string InputDate;      // 录入日期    date
		std::string GCEABD;         // 室内编号    varchar
		std::string TestEquip;      // 试验仪器    varchar
		std::string TestMethod;     // 试验方法    varchar
		std::string TestBased;      // 检验依据    varchar
		std::string GCEAJC;         // 试验单位    varchar
		std::string SWFGAM;         // 收样日期    date
		std::string SWFGAN;         // 报告日期    date
		std::string GCEAJD;         // 校对    varchar
		std::string Auditor;        // 审核    varchar
		std::string TestLeader;     // 试验负责人    varchar
		std::string _Report;        // 原始测试分析报告    varchar
	};

	// 直剪实验成果表
	struct  INDirectShear : public Bas_PntStdInfo
	{
	public:
		long DirectShearID;         //* 直剪ID    int
		float StartDepth;           //* 取样顶深度    float
		float EndDepth;             //* 取样底深度    float
		long PntID;                 //* 点ID    int
		std::string TCDH;           //* 采样层位    varchar
		std::string TCMC;           // 土层名称    varchar
		std::string GeoCode;        // 地质代号    varchar
		std::string TestNo;         //     varchar
		std::string TestType;       // 试验类型    varchar
		float MaxVerticalPress;     // 最大垂直压力(kPa)    float
		float Sheer1;               // 剪应力τ100(kPa)    float
		float Sheer2;               // 剪应力τ200(kPa)    float
		float Sheer3;               // 剪应力τ300(kPa)    float
		float Sheer4;               // 剪应力τ400(kPa)    float
		float GCBFOA;               // 粘聚力(kPa)    float
		float GCDMAC;               // 内摩擦角(度)    float
		std::string GCEABB;         // 样品编号    varchar
		std::string SWBCF;          // 样品类型    varchar
		std::string IsMixSample;    // 混合样    varchar
		std::string PntType;        // 点类型    varchar
		std::string SecondCode;     // 样品二次编码    varchar
		float SampleVolume;         // 样品体积    float
		std::string GCEABM;         // 野外命名    varchar
		float GCEAAL;               // 样品重量(kg)    float
		std::string SampleLength;   // 样品长度(cm)    varchar
		std::string PretreatMethod; // 预处理方法    varchar
		std::string TestContent;    // 测试内容    varchar
		std::string PlanePosMap;    // 平面位置示意图    varchar
		std::string ProfileMap;     // 剖面示意图    varchar
		std::string FieldImage;     // 野外照片(视频)    varchar
		std::string RecordCard;     // 记录卡片(记录)    varchar
		std::string SampleOrgn;     // 采样单位    varchar
		std::string SWFOMW;         // 采样人    varchar
		std::string GCEABJ;         // 采样日期    date
		std::string Inputer;        // 录入员    varchar
		std::string InputOrgn;      // 录入单位    varchar
		std::string InputDate;      // 录入日期    date
		std::string GCEABD;         // 室内编号    varchar
		std::string TestEquip;      // 试验仪器    varchar
		std::string TestMethod;     // 试验方法    varchar
		std::string TestBased;      // 检验依据    varchar
		std::string GCEAJC;         // 试验单位    varchar
		std::string SWFGAM;         // 收样日期    date
		std::string SWFGAN;         // 报告日期    date
		std::string GCEAJD;         // 校对    varchar
		std::string Auditor;        // 审核    varchar
		std::string TestLeader;     // 试验负责人    varchar
		std::string _Report;        // 原始测试分析报告    varchar
	};

	// 动三轴实验成果表
	struct  INDynamicThaxis : public Bas_PntStdInfo
	{
	public:
		long DynamicThaxisID;       //* 动三轴ID    int
		float StartDepth;           //* 取样顶深度    float
		float EndDepth;             //* 取样底深度    float
		long PntID;                 //* 点ID    int
		std::string TCDH;           //* 采样层位    varchar
		std::string TCMC;           // 土层名称    varchar
		std::string GeoCode;        // 地质代号    varchar
		std::string TestNo;         //     varchar
		std::string TestType;       // 试验类型    varchar
		float _DGCDKBB;             // 动弹性模量(MPa)    float
		float DyShearModule;        // 动剪切模量(MPa)    float
		float _Dampratio;           // 阻尼比    float
		float _DDampratio;          // 动阻尼比    float
		float _DGCBFOA;             // 动粘聚力(kPa)    float
		float _DGCDMAC;             // 动内摩擦角(度)    float
		std::string GCEABB;         // 样品编号    varchar
		std::string SWBCF;          // 样品类型    varchar
		std::string IsMixSample;    // 混合样    varchar
		std::string PntType;        // 点类型    varchar
		std::string SecondCode;     // 样品二次编码    varchar
		float SampleVolume;         // 样品体积    float
		std::string GCEABM;         // 野外命名    varchar
		float GCEAAL;               // 样品重量(kg)    float
		std::string SampleLength;   // 样品长度(cm)    varchar
		std::string PretreatMethod; // 预处理方法    varchar
		std::string TestContent;    // 测试内容    varchar
		std::string PlanePosMap;    // 平面位置示意图    varchar
		std::string ProfileMap;     // 剖面示意图    varchar
		std::string FieldImage;     // 野外照片(视频)    varchar
		std::string RecordCard;     // 记录卡片(记录)    varchar
		std::string SampleOrgn;     // 采样单位    varchar
		std::string SWFOMW;         // 采样人    varchar
		std::string GCEABJ;         // 采样日期    date
		std::string Inputer;        // 录入员    varchar
		std::string InputOrgn;      // 录入单位    varchar
		std::string InputDate;      // 录入日期    date
		std::string GCEABD;         // 室内编号    varchar
		std::string TestEquip;      // 试验仪器    varchar
		std::string TestMethod;     // 试验方法    varchar
		std::string TestBased;      // 检验依据    varchar
		std::string GCEAJC;         // 试验单位    varchar
		std::string SWFGAM;         // 收样日期    date
		std::string SWFGAN;         // 报告日期    date
		std::string GCEAJD;         // 校对    varchar
		std::string Auditor;        // 审核    varchar
		std::string TestLeader;     // 试验负责人    varchar
		std::string _Report;        // 原始测试分析报告    varchar
	};

	// 岩矿鉴定成果表
	struct  INRockMineIdent : public Bas_PntStdInfo
	{
	public:
		long RockMineidentID;        //* 岩矿鉴定ID    int
		float StartDepth;            //* 取样顶深度    float
		float EndDepth;              //* 取样底深度    float
		long PntID;                  //* 点ID    int
		std::string TCDH;            //* 采样层位    varchar
		std::string TCMC;            // 土层名称    varchar
		std::string GeoCode;         // 地质代号    varchar
		std::string TestNo;          //     varchar
		std::string TestType;        // 试验类型    varchar
		std::string _Structure;      // 结构    varchar
		std::string _Construct;      // 构造    varchar
		std::string _Cement;         // 胶结物    varchar
		std::string IdentificatDesc; // 鉴定描述    varchar
		std::string _Ingredient;     // 成份    varchar
		float _Content;              // 含量(%)    float
		std::string GCEABB;          // 样品编号    varchar
		std::string SWBCF;           // 样品类型    varchar
		std::string IsMixSample;     // 混合样    varchar
		std::string PntType;         // 点类型    varchar
		std::string SecondCode;      // 样品二次编码    varchar
		float SampleVolume;          // 样品体积    float
		std::string GCEABM;          // 野外命名    varchar
		float GCEAAL;                // 样品重量(kg)    float
		std::string SampleLength;    // 样品长度(cm)    varchar
		std::string PretreatMethod;  // 预处理方法    varchar
		std::string TestContent;     // 测试内容    varchar
		std::string PlanePosMap;     // 平面位置示意图    varchar
		std::string ProfileMap;      // 剖面示意图    varchar
		std::string FieldImage;      // 野外照片(视频)    varchar
		std::string RecordCard;      // 记录卡片(记录)    varchar
		std::string SampleOrgn;      // 采样单位    varchar
		std::string SWFOMW;          // 采样人    varchar
		std::string GCEABJ;          // 采样日期    date
		std::string Inputer;         // 录入员    varchar
		std::string InputOrgn;       // 录入单位    varchar
		std::string InputDate;       // 录入日期    date
		std::string GCEABD;          // 室内编号    varchar
		std::string IndoorName;      // 室内名称    varchar
		std::string TestEquip;       // 试验仪器    varchar
		std::string TestMethod;      // 试验方法    varchar
		std::string TestBased;       // 检验依据    varchar
		std::string GCEAJC;          // 试验单位    varchar
		std::string SWFGAM;          // 收样日期    date
		std::string SWFGAN;          // 报告日期    date
		std::string GCEAJD;          // 校对    varchar
		std::string Auditor;         // 审核    varchar
		std::string TestLeader;      // 试验负责人    varchar
		std::string _Report;         // 原始测试分析报告    varchar
	};

	// 粘土（全岩）矿物鉴定成果表
	struct  INClayMineralIdent : public Bas_PntStdInfo
	{
	public:
		long ClayMineralID;         //* 粘土矿物ID    int
		float StartDepth;           //* 取样顶深度    float
		float EndDepth;             //* 取样底深度    float
		long PntID;                 //* 点ID    int
		std::string TCDH;           //* 采样层位    varchar
		std::string TCMC;           // 土层名称    varchar
		std::string GeoCode;        // 地质代号    varchar
		std::string TestNo;         //     varchar
		std::string TestType;       // 试验类型    varchar
		float Quartz;               // 石英(%)    float
		float Potashfeldspar;       // 钾长石(%)    float
		float Plagioclase;          // 斜长石(%)    float
		float Calcite;              // 方解石(%)    float
		float Rocksalt;             // 石盐(%)    float
		float Hornblende;           // 角闪石(%)    float
		float ClayMineral;          // 粘土矿物(%)    float
		float Smectite;             // 蒙皂石(%)    float
		float ISmixedmineral;       // I/S混层矿物(%)    float
		float SWHABO;               // 伊利石(%)    float
		float SWHABP;               // 高岭石(%)    float
		float SWHAAX;               // 绿泥石(%)    float
		float ISmixlayerratio;      // 混层比I/S    float
		float CSmixlayerratio;      // 混层比C/S    float
		std::string GCEABB;         // 样品编号    varchar
		std::string SWBCF;          // 样品类型    varchar
		std::string IsMixSample;    // 混合样    varchar
		std::string PntType;        // 点类型    varchar
		std::string SecondCode;     // 样品二次编码    varchar
		float SampleVolume;         // 样品体积    float
		std::string GCEABM;         // 野外命名    varchar
		float GCEAAL;               // 样品重量(kg)    float
		std::string SampleLength;   // 样品长度(cm)    varchar
		std::string PretreatMethod; // 预处理方法    varchar
		std::string TestContent;    // 测试内容    varchar
		std::string PlanePosMap;    // 平面位置示意图    varchar
		std::string ProfileMap;     // 剖面示意图    varchar
		std::string FieldImage;     // 野外照片(视频)    varchar
		std::string RecordCard;     // 记录卡片(记录)    varchar
		std::string SampleOrgn;     // 采样单位    varchar
		std::string SWFOMW;         // 采样人    varchar
		std::string GCEABJ;         // 采样日期    date
		std::string Inputer;        // 录入员    varchar
		std::string InputOrgn;      // 录入单位    varchar
		std::string InputDate;      // 录入日期    date
		std::string GCEABD;         // 室内编号    varchar
		std::string TestEquip;      // 试验仪器    varchar
		std::string TestMethod;     // 试验方法    varchar
		std::string TestBased;      // 检验依据    varchar
		std::string GCEAJC;         // 试验单位    varchar
		std::string SWFGAM;         // 收样日期    date
		std::string SWFGAN;         // 报告日期    date
		std::string GCEAJD;         // 校对    varchar
		std::string Auditor;        // 审核    varchar
		std::string TestLeader;     // 试验负责人    varchar
		std::string _Report;        // 原始测试分析报告    varchar
	};

	// 粒度分析成果表
	struct  INGranularityIdent : public Bas_PntStdInfo
	{
	public:
		long GranularityID;         //* 粒度ID    int
		float StartDepth;           //* 取样顶深度    float
		float EndDepth;             //* 取样底深度    float
		long PntID;                 //* 点ID    int
		std::string TCDH;           //* 采样层位    varchar
		std::string TCMC;           // 土层名称    varchar
		std::string GeoCode;        // 地质代号    varchar
		std::string TestNo;         //     varchar
		std::string TestType;       // 试验类型    varchar
		float _Content;             // 含量    float
		float GCCABB;               // 砾石    float
		float GCCABC;               // 砂(%)    float
		float GCCABD;               // 粉砂(%)    float
		float GCCABE;               // 粘土(%)    float
		float GCCABG;               // 平均粒径    float
		float GCCABH;               // 分选系数    float
		float GCCABI;               // 偏态    float
		float GCCABJ;               // 峰态    float
		float GCCABF;               // 中值粒径    float
		std::string SedimentType;   // 沉积物分类    varchar
		std::string GCEABB;         // 样品编号    varchar
		std::string SWBCF;          // 样品类型    varchar
		std::string IsMixSample;    // 混合样    varchar
		std::string PntType;        // 点类型    varchar
		std::string SecondCode;     // 样品二次编码    varchar
		float SampleVolume;         // 样品体积    float
		std::string GCEABM;         // 野外命名    varchar
		float GCEAAL;               // 样品重量(kg)    float
		std::string SampleLength;   // 样品长度(cm)    varchar
		std::string PretreatMethod; // 预处理方法    varchar
		std::string TestContent;    // 测试内容    varchar
		std::string PlanePosMap;    // 平面位置示意图    varchar
		std::string ProfileMap;     // 剖面示意图    varchar
		std::string FieldImage;     // 野外照片(视频)    varchar
		std::string RecordCard;     // 记录卡片(记录)    varchar
		std::string SampleOrgn;     // 采样单位    varchar
		std::string SWFOMW;         // 采样人    varchar
		std::string GCEABJ;         // 采样日期    date
		std::string Inputer;        // 录入员    varchar
		std::string InputOrgn;      // 录入单位    varchar
		std::string InputDate;      // 录入日期    date
		std::string GCEABD;         // 室内编号    varchar
		std::string TestEquip;      // 试验仪器    varchar
		std::string TestMethod;     // 试验方法    varchar
		std::string TestBased;      // 检验依据    varchar
		std::string GCEAJC;         // 试验单位    varchar
		std::string SWFGAM;         // 收样日期    date
		std::string SWFGAN;         // 报告日期    date
		std::string GCEAJD;         // 校对    varchar
		std::string Auditor;        // 审核    varchar
		std::string TestLeader;     // 试验负责人    varchar
		std::string _Report;        // 原始测试分析报告    varchar
	};

	// 热物性实验成果表
	struct  INThermophysical : public Bas_PntStdInfo
	{
	public:
		long ThermophysicalID;      //* 热物性ID    int
		float StartDepth;           //* 取样顶深度    float
		float EndDepth;             //* 取样底深度    float
		long PntID;                 //* 点ID    int
		std::string TCDH;           //* 采样层位    varchar
		std::string TCMC;           // 土层名称    varchar
		std::string GeoCode;        // 地质代号    varchar
		std::string TestNo;         //     varchar
		std::string TestType;       // 试验类型    varchar
		float GCDGAF;               // 导热系数    float
		float GCDGAE;               //* 比热(J/(kg℃))    float
		float SWDEAH;               // 热扩散系数    float
		float SYEFAB;               // 自然密度(g/cm3)    float
		float GCDCAO;               // 含水率(%)    float
		float GCDBB;                // 孔隙率(%)    float
		float DHABCU;               // 饱和度(%)    float
		std::string GCEABD;         // 室内编号    varchar
		std::string TestEquip;      // 试验仪器    varchar
		std::string TestMethod;     // 试验方法    varchar
		std::string TestBased;      // 检验依据    varchar
		std::string GCEAJC;         // 试验单位    varchar
		std::string SWFGAM;         // 收样日期    date
		std::string SWFGAN;         // 报告日期    date
		std::string GCEAJD;         // 校对    varchar
		std::string Auditor;        // 审核    varchar
		std::string TestLeader;     // 试验负责人    varchar
		std::string _Report;        // 原始测试分析报告    varchar
		std::string GCEABB;         // 样品编号    varchar
		std::string SWBCF;          // 样品类型    varchar
		std::string IsMixSample;    // 混合样    varchar
		std::string PntType;        // 点类型    varchar
		std::string SecondCode;     // 样品二次编码    varchar
		float SampleVolume;         // 样品体积    float
		std::string GCEABM;         // 野外命名    varchar
		float GCEAAL;               // 样品重量(kg)    float
		std::string SampleLength;   // 样品长度(cm)    varchar
		std::string PretreatMethod; // 预处理方法    varchar
		std::string TestContent;    // 测试内容    varchar
		std::string PlanePosMap;    // 平面位置示意图    varchar
		std::string ProfileMap;     // 剖面示意图    varchar
		std::string FieldImage;     // 野外照片(视频)    varchar
		std::string RecordCard;     // 记录卡片(记录)    varchar
		std::string SampleOrgn;     // 采样单位    varchar
		std::string SWFOMW;         // 采样人    varchar
		std::string GCEABJ;         // 采样日期    date
		std::string Inputer;        // 录入员    varchar
		std::string InputOrgn;      // 录入单位    varchar
		std::string InputDate;      // 录入日期    date
	};

	// 同位素测年成果表
	struct  INIsotope : public Bas_PntStdInfo
	{
	public:
		long IsotopeID;             //* 同位素ID    int
		float StartDepth;           //* 取样顶深度    float
		float EndDepth;             //* 取样底深度    float
		long PntID;                 //* 点ID    int
		std::string TCDH;           //* 采样层位    varchar
		std::string TCMC;           // 土层名称    varchar
		std::string GeoCode;        // 地质代号    varchar
		std::string TestNo;         //     varchar
		std::string TestType;       // 试验类型    varchar
		std::string Isotope;        // 同位素    varchar
		float YJDCBH;               // 丰度    float
		long TestAge;               // 测试年龄    int
		std::string AgeUnit;        // 年龄单位    varchar
		std::string GCEABD;         // 室内编号    varchar
		std::string TestEquip;      // 试验仪器    varchar
		std::string TestMethod;     // 试验方法    varchar
		std::string TestBased;      // 检验依据    varchar
		std::string GCEAJC;         // 试验单位    varchar
		std::string SWFGAM;         // 收样日期    date
		std::string SWFGAN;         // 报告日期    date
		std::string GCEAJD;         // 校对    varchar
		std::string Auditor;        // 审核    varchar
		std::string TestLeader;     // 试验负责人    varchar
		std::string _Report;        // 原始测试分析报告    varchar
		std::string GCEABB;         // 样品编号    varchar
		std::string SWBCF;          // 样品类型    varchar
		std::string IsMixSample;    // 混合样    varchar
		std::string PntType;        // 点类型    varchar
		std::string SecondCode;     // 样品二次编码    varchar
		float SampleVolume;         // 样品体积    float
		std::string GCEABM;         // 野外命名    varchar
		float GCEAAL;               // 样品重量(kg)    float
		std::string SampleLength;   // 样品长度(cm)    varchar
		std::string PretreatMethod; // 预处理方法    varchar
		std::string TestContent;    // 测试内容    varchar
		std::string PlanePosMap;    // 平面位置示意图    varchar
		std::string ProfileMap;     // 剖面示意图    varchar
		std::string FieldImage;     // 野外照片(视频)    varchar
		std::string RecordCard;     // 记录卡片(记录)    varchar
		std::string SampleOrgn;     // 采样单位    varchar
		std::string SWFOMW;         // 采样人    varchar
		std::string GCEABJ;         // 采样日期    date
		std::string Inputer;        // 录入员    varchar
		std::string InputOrgn;      // 录入单位    varchar
		std::string InputDate;      // 录入日期    date
	};

	// 释光测年成果表
	struct  INLuminescence : public Bas_PntStdInfo
	{
	public:
		long LuminescenceID;        //* 释光ID    int
		float StartDepth;           //* 取样顶深度    float
		float EndDepth;             //* 取样底深度    float
		long PntID;                 //* 点ID    int
		std::string TCDH;           //* 采样层位    varchar
		std::string TCMC;           // 土层名称    varchar
		std::string GeoCode;        // 地质代号    varchar
		std::string TestNo;         //     varchar
		std::string TestType;       // 试验类型    varchar
		std::string DateMethod;     // 测年方法    varchar
		long TestAge;               // 测试年龄    int
		std::string AgeUnit;        // 年龄单位    varchar
		std::string _Memo;          // 备注    varchar
		std::string GCEABB;         // 样品编号    varchar
		std::string SWBCF;          // 样品类型    varchar
		std::string IsMixSample;    // 混合样    varchar
		std::string PntType;        // 点类型    varchar
		std::string SecondCode;     // 样品二次编码    varchar
		float SampleVolume;         // 样品体积    float
		std::string GCEABM;         // 野外命名    varchar
		float GCEAAL;               // 样品重量(kg)    float
		std::string SampleLength;   // 样品长度(cm)    varchar
		std::string PretreatMethod; // 预处理方法    varchar
		std::string TestContent;    // 测试内容    varchar
		std::string PlanePosMap;    // 平面位置示意图    varchar
		std::string ProfileMap;     // 剖面示意图    varchar
		std::string FieldImage;     // 野外照片(视频)    varchar
		std::string RecordCard;     // 记录卡片(记录)    varchar
		std::string SampleOrgn;     // 采样单位    varchar
		std::string SWFOMW;         // 采样人    varchar
		std::string GCEABJ;         // 采样日期    date
		std::string Inputer;        // 录入员    varchar
		std::string InputOrgn;      // 录入单位    varchar
		std::string InputDate;      // 录入日期    date
		std::string GCEABD;         // 室内编号    varchar
		std::string TestEquip;      // 试验仪器    varchar
		std::string TestMethod;     // 试验方法    varchar
		std::string TestBased;      // 检验依据    varchar
		std::string GCEAJC;         // 试验单位    varchar
		std::string SWFGAM;         // 收样日期    date
		std::string SWFGAN;         // 报告日期    date
		std::string GCEAJD;         // 校对    varchar
		std::string Auditor;        // 审核    varchar
		std::string TestLeader;     // 试验负责人    varchar
		std::string _Report;        // 原始测试分析报告    varchar
	};

	// 孢粉组合表
	struct  INPollenCombinat : public Bas_PntStdInfo
	{
	public:
		long PollenCombinatID;        //* 孢粉组合ID    int
		float StartDepth;             //* 取样顶深度    float
		float EndDepth;               //* 取样底深度    float
		long PntID;                   //* 点ID    int
		std::string TCDH;             //* 采样层位    varchar
		std::string TCMC;             // 土层名称    varchar
		std::string GeoCode;          // 地质代号    varchar
		std::string TestNo;           //     varchar
		std::string TestType;         // 试验类型    varchar
		std::string PollenCombinat;   // 孢粉组合    varchar
		std::string ClimateCharacter; // 古植被古气候特征    varchar
		std::string DDCDIA;           // 地质时代    varchar
		std::string PlantName;        // 植物名称    varchar
		long GrainNum;                // 粒数    int
		float _Content;               // 含量    float
		std::string GCEABB;           // 样品编号    varchar
		std::string SWBCF;            // 样品类型    varchar
		std::string IsMixSample;      // 混合样    varchar
		std::string PntType;          // 点类型    varchar
		std::string SecondCode;       // 样品二次编码    varchar
		float SampleVolume;           // 样品体积    float
		std::string GCEABM;           // 野外命名    varchar
		float GCEAAL;                 // 样品重量(kg)    float
		std::string SampleLength;     // 样品长度(cm)    varchar
		std::string PretreatMethod;   // 预处理方法    varchar
		std::string TestContent;      // 测试内容    varchar
		std::string PlanePosMap;      // 平面位置示意图    varchar
		std::string ProfileMap;       // 剖面示意图    varchar
		std::string FieldImage;       // 野外照片(视频)    varchar
		std::string RecordCard;       // 记录卡片(记录)    varchar
		std::string SampleOrgn;       // 采样单位    varchar
		std::string SWFOMW;           // 采样人    varchar
		std::string GCEABJ;           // 采样日期    date
		std::string Inputer;          // 录入员    varchar
		std::string InputOrgn;        // 录入单位    varchar
		std::string InputDate;        // 录入日期    date
		std::string GCEABD;           // 室内编号    varchar
		std::string TestEquip;        // 试验仪器    varchar
		std::string TestMethod;       // 试验方法    varchar
		std::string TestBased;        // 检验依据    varchar
		std::string GCEAJC;           // 试验单位    varchar
		std::string SWFGAM;           // 收样日期    date
		std::string SWFGAN;           // 报告日期    date
		std::string GCEAJD;           // 校对    varchar
		std::string Auditor;          // 审核    varchar
		std::string TestLeader;       // 试验负责人    varchar
		std::string _Report;          // 原始测试分析报告    varchar
	};

	// 化石组合表
	struct  INFossilCombinat : public Bas_PntStdInfo
	{
	public:
		long FossilCombinatID;        //* 化石组合ID    int
		float StartDepth;             //* 取样顶深度    float
		float EndDepth;               //* 取样底深度    float
		long PntID;                   //* 点ID    int
		std::string TCDH;             //* 采样层位    varchar
		std::string TCMC;             // 土层名称    varchar
		std::string GeoCode;          // 地质代号    varchar
		std::string TestNo;           //     varchar
		std::string TestType;         // 试验类型    varchar
		std::string FossilCombinat;   // 化石组合    varchar
		std::string ClimateCharacter; // 古化石古气候特征    varchar
		std::string DDCDIA;           // 地质时代    varchar
		std::string GCEABB;           // 样品编号    varchar
		std::string SWBCF;            // 样品类型    varchar
		std::string IsMixSample;      // 混合样    varchar
		std::string PntType;          // 点类型    varchar
		std::string SecondCode;       // 样品二次编码    varchar
		float SampleVolume;           // 样品体积    float
		std::string GCEABM;           // 野外命名    varchar
		float GCEAAL;                 // 样品重量(kg)    float
		std::string SampleLength;     // 样品长度(cm)    varchar
		std::string PretreatMethod;   // 预处理方法    varchar
		std::string TestContent;      // 测试内容    varchar
		std::string PlanePosMap;      // 平面位置示意图    varchar
		std::string ProfileMap;       // 剖面示意图    varchar
		std::string FieldImage;       // 野外照片(视频)    varchar
		std::string RecordCard;       // 记录卡片(记录)    varchar
		std::string SampleOrgn;       // 采样单位    varchar
		std::string SWFOMW;           // 采样人    varchar
		std::string GCEABJ;           // 采样日期    date
		std::string Inputer;          // 录入员    varchar
		std::string InputOrgn;        // 录入单位    varchar
		std::string InputDate;        // 录入日期    date
		std::string GCEABD;           // 室内编号    varchar
		std::string TestEquip;        // 试验仪器    varchar
		std::string TestMethod;       // 试验方法    varchar
		std::string TestBased;        // 检验依据    varchar
		std::string GCEAJC;           // 试验单位    varchar
		std::string SWFGAM;           // 收样日期    date
		std::string SWFGAN;           // 报告日期    date
		std::string GCEAJD;           // 校对    varchar
		std::string Auditor;          // 审核    varchar
		std::string TestLeader;       // 试验负责人    varchar
		std::string _Report;          // 原始测试分析报告    varchar
	};

	// 化石鉴定数据表
	struct  INFossilIdent : public Bas_PntStdInfo
	{
	public:
		long FossilID;              //* 化石ID    int
		float StartDepth;           //* 取样顶深度    float
		float EndDepth;             //* 取样底深度    float
		long PntID;                 //* 点ID    int
		std::string TCDH;           //* 采样层位    varchar
		std::string TCMC;           // 土层名称    varchar
		std::string GeoCode;        // 地质代号    varchar
		std::string TestNo;         //     varchar
		std::string TestType;       // 试验类型    varchar
		std::string FossilName;     // 化石名称    varchar
		long _Quantity;             // 数量    int
		float _Content;             // 含量    float
		std::string GCEABD;         // 室内编号    varchar
		std::string TestEquip;      // 试验仪器    varchar
		std::string TestMethod;     // 试验方法    varchar
		std::string TestBased;      // 检验依据    varchar
		std::string GCEAJC;         // 试验单位    varchar
		std::string SWFGAM;         // 收样日期    date
		std::string SWFGAN;         // 报告日期    date
		std::string GCEAJD;         // 校对    varchar
		std::string Auditor;        // 审核    varchar
		std::string TestLeader;     // 试验负责人    varchar
		std::string _Report;        // 原始测试分析报告    varchar
		std::string GCEABB;         // 样品编号    varchar
		std::string SWBCF;          // 样品类型    varchar
		std::string IsMixSample;    // 混合样    varchar
		std::string PntType;        // 点类型    varchar
		std::string SecondCode;     // 样品二次编码    varchar
		float SampleVolume;         // 样品体积    float
		std::string GCEABM;         // 野外命名    varchar
		float GCEAAL;               // 样品重量(kg)    float
		std::string SampleLength;   // 样品长度(cm)    varchar
		std::string PretreatMethod; // 预处理方法    varchar
		std::string TestContent;    // 测试内容    varchar
		std::string PlanePosMap;    // 平面位置示意图    varchar
		std::string ProfileMap;     // 剖面示意图    varchar
		std::string FieldImage;     // 野外照片(视频)    varchar
		std::string RecordCard;     // 记录卡片(记录)    varchar
		std::string SampleOrgn;     // 采样单位    varchar
		std::string SWFOMW;         // 采样人    varchar
		std::string GCEABJ;         // 采样日期    date
		std::string Inputer;        // 录入员    varchar
		std::string InputOrgn;      // 录入单位    varchar
		std::string InputDate;      // 录入日期    date
	};

	// 古地磁测试成果表
	struct  INPaleomagnetic : public Bas_PntStdInfo
	{
	public:
		long PaleomagneticID;       //* 古地磁ID    int
		float StartDepth;           //* 取样顶深度    float
		float EndDepth;             //* 取样底深度    float
		long PntID;                 //* 点ID    int
		std::string TCDH;           //* 采样层位    varchar
		std::string TCMC;           // 土层名称    varchar
		std::string GeoCode;        // 地质代号    varchar
		std::string TestNo;         //     varchar
		std::string TestType;       // 试验类型    varchar
		std::string PolarEvent;     // 极性事件    varchar
		std::string PolarColumn;    // 极性柱    varchar
		float Magneticdeclinat;     // 磁偏角    float
		std::string LayerAgeUnit;   // 年代地层单位    varchar
		std::string GCEABB;         // 样品编号    varchar
		std::string SWBCF;          // 样品类型    varchar
		std::string IsMixSample;    // 混合样    varchar
		std::string PntType;        // 点类型    varchar
		std::string SecondCode;     // 样品二次编码    varchar
		float SampleVolume;         // 样品体积    float
		std::string GCEABM;         // 野外命名    varchar
		float GCEAAL;               // 样品重量(kg)    float
		std::string SampleLength;   // 样品长度(cm)    varchar
		std::string PretreatMethod; // 预处理方法    varchar
		std::string TestContent;    // 测试内容    varchar
		std::string PlanePosMap;    // 平面位置示意图    varchar
		std::string ProfileMap;     // 剖面示意图    varchar
		std::string FieldImage;     // 野外照片(视频)    varchar
		std::string RecordCard;     // 记录卡片(记录)    varchar
		std::string SampleOrgn;     // 采样单位    varchar
		std::string SWFOMW;         // 采样人    varchar
		std::string GCEABJ;         // 采样日期    date
		std::string Inputer;        // 录入员    varchar
		std::string InputOrgn;      // 录入单位    varchar
		std::string InputDate;      // 录入日期    date
		std::string GCEABD;         // 室内编号    varchar
		std::string TestEquip;      // 试验仪器    varchar
		std::string TestMethod;     // 试验方法    varchar
		std::string TestBased;      // 检验依据    varchar
		std::string GCEAJC;         // 试验单位    varchar
		std::string SWFGAM;         // 收样日期    date
		std::string SWFGAN;         // 报告日期    date
		std::string GCEAJD;         // 校对    varchar
		std::string Auditor;        // 审核    varchar
		std::string TestLeader;     // 试验负责人    varchar
		std::string _Report;        // 原始测试分析报告    varchar
	};

	// 水腐蚀性分析
	struct  INWaterCausticity : public Bas_PntStdInfo
	{
	public:
		long WaterCausticityID;     //* 水腐蚀ID    int
		float StartDepth;           //* 取样顶深度    float
		float EndDepth;             //* 取样底深度    float
		long PntID;                 //* 点ID    int
		std::string TCDH;           //* 采样层位    varchar
		std::string TCMC;           // 土层名称    varchar
		std::string GeoCode;        // 地质代号    varchar
		std::string TestNo;         //     varchar
		std::string TestType;       // 试验类型    varchar
		float NAK;                  //     float
		float SWFHFA;               // Ca2+(mg/L)    float
		float SWFHFB;               // Mg2+(mg/L)    float
		float NH4;                  // NH4+(mg/L)    float
		float NO3;                  // NO3-(mg/L)    float
		float SWFHFF;               // Cl-(mg/L)    float
		float SWFHFG;               // SO42-(mg/L)    float
		float SWFHFI;               // CO32-(mmol/L)    float
		float SWFHFH;               // HCO3-(mmol/L)    float
		float CL;                   // CL-(mmol/L)    float
		float ZJD;                  // 总碱度(mg/L)    float
		float Caustic;              // 苛性碱OH-(mg/L)    float
		float SWFHE;                // 矿化度(mg/L)    float
		float LZHD;                 // 离子总量    float
		float RJXGTZL;              // 溶解性固体总量（mg/L）    float
		float PH;                   // pH    float
		float SWFHI;                // 侵蚀CO2(mg/L)    float
		float SWFHG;                // 游离CO2(mg/L)    float
		float ZYD;                  // 总硬度    float
		float ZSYD;                 // 暂时硬度    float
		float YJYD;                 // 永久硬度    float
		float FYD;                  // 负硬度    float
		std::string HNTJG;                // 混凝土结构    varchar
		std::string GJ;                   // 钢筋    varchar
		std::string GCEABB;         // 样品编号    varchar
		std::string SWBCF;          // 样品类型    varchar
		std::string IsMixSample;    // 混合样    varchar
		std::string PntType;        // 点类型    varchar
		std::string SecondCode;     // 样品二次编码    varchar
		float SampleVolume;         // 样品体积    float
		std::string GCEABM;         // 野外命名    varchar
		float GCEAAL;               // 样品重量(kg)    float
		std::string SampleLength;   // 样品长度(cm)    varchar
		std::string PretreatMethod; // 预处理方法    varchar
		std::string TestContent;    // 测试内容    varchar
		std::string PlanePosMap;    // 平面位置示意图    varchar
		std::string ProfileMap;     // 剖面示意图    varchar
		std::string FieldImage;     // 野外照片(视频)    varchar
		std::string RecordCard;     // 记录卡片(记录)    varchar
		std::string SampleOrgn;     // 采样单位    varchar
		std::string SWFOMW;         // 采样人    varchar
		std::string GCEABJ;         // 采样日期    date
		std::string Inputer;        // 录入员    varchar
		std::string InputOrgn;      // 录入单位    varchar
		std::string InputDate;      // 录入日期    date
		std::string GCEABD;         // 室内编号    varchar
		std::string TestEquip;      // 试验仪器    varchar
		std::string TestMethod;     // 试验方法    varchar
		std::string TestBased;      // 检验依据    varchar
		std::string GCEAJC;         // 试验单位    varchar
		std::string SWFGAM;         // 收样日期    date
		std::string SWFGAN;         // 报告日期    date
		std::string GCEAJD;         // 校对    varchar
		std::string Auditor;        // 审核    varchar
		std::string TestLeader;     // 试验负责人    varchar
		std::string _Report;        // 原始测试分析报告    varchar
	};

	// 土腐蚀性分析
	struct  INSoilCausticity : public Bas_PntStdInfo
	{
	public:
		long SoilCorrosionID;       //* 土腐蚀ID    int
		float StartDepth;           //* 取样顶深度    float
		float EndDepth;             //* 取样底深度    float
		long PntID;                 //* 点ID    int
		std::string TCDH;           //* 采样层位    varchar
		std::string TCMC;           // 土层名称    varchar
		std::string GeoCode;        // 地质代号    varchar
		std::string TestNo;         //     varchar
		std::string TestType;       // 试验类型    varchar
		float SWFHFA;               // Ca2+(mg/kg)    float
		float SWFHFB;               // Mg2+(mg/kg)    float
		float SWFHFF;               // Cl-(mg/kg)    float
		float SWFHFG;               // SO42-(mg/kg)    float
		float SWFHFH;               // HCO3-(mg/kg)    float
		float SWFHFI;               // CO32-(mg/kg)    float
		float SWFHFJ;               // NH4+    float
		float PH;                   // pH    float
		float KWAAJG;               // Eh(mV)    float
		float Resistivity;          // 电阻率(Ω·m)    float
		float Polarizatdensity;     // 极化电流密度    float
		float Massloss;             // 质量损失(g)    float
		std::string HNTJG;                // 混凝土结构    float
		std::string GJ;                   // 钢筋    float
		std::string GJG;                  // 钢结构    float
		std::string GCEABB;         // 样品编号    varchar
		std::string SWBCF;          // 样品类型    varchar
		std::string IsMixSample;    // 混合样    varchar
		std::string PntType;        // 点类型    varchar
		std::string SecondCode;     // 样品二次编码    varchar
		float SampleVolume;         // 样品体积    float
		std::string GCEABM;         // 野外命名    varchar
		float GCEAAL;               // 样品重量(kg)    float
		std::string SampleLength;   // 样品长度(cm)    varchar
		std::string PretreatMethod; // 预处理方法    varchar
		std::string TestContent;    // 测试内容    varchar
		std::string PlanePosMap;    // 平面位置示意图    varchar
		std::string ProfileMap;     // 剖面示意图    varchar
		std::string FieldImage;     // 野外照片(视频)    varchar
		std::string RecordCard;     // 记录卡片(记录)    varchar
		std::string SampleOrgn;     // 采样单位    varchar
		std::string SWFOMW;         // 采样人    varchar
		std::string GCEABJ;         // 采样日期    date
		std::string Inputer;        // 录入员    varchar
		std::string InputOrgn;      // 录入单位    varchar
		std::string InputDate;      // 录入日期    date
		std::string GCEABD;         // 室内编号    varchar
		std::string TestEquip;      // 试验仪器    varchar
		std::string TestMethod;     // 试验方法    varchar
		std::string TestBased;      // 检验依据    varchar
		std::string GCEAJC;         // 试验单位    varchar
		std::string SWFGAM;         // 收样日期    date
		std::string SWFGAN;         // 报告日期    date
		std::string GCEAJD;         // 校对    varchar
		std::string Auditor;        // 审核    varchar
		std::string TestLeader;     // 试验负责人    varchar
		std::string _Report;        // 原始测试分析报告    varchar
	};

	// 地球化学分析数据表
	struct  INGeochemicalIdent : public Bas_PntStdInfo
	{
	public:
		long CheanalysisID;         //* 化学分析ID    int
		float StartDepth;           //* 取样顶深度    float
		float EndDepth;             //* 取样底深度    float
		long PntID;                 //* 点ID    int
		std::string TCDH;           //* 采样层位    varchar
		std::string TCMC;           // 土层名称    varchar
		std::string GeoCode;        // 地质代号    varchar
		std::string TestNo;         //     varchar
		std::string TestType;       // 试验类型    varchar
		std::string AnalysisIndex;  // 分析指标    varchar
		std::string ChemicalCode;   // 化学代号    varchar
		std::string NumericalUnit;  // 数值单位    varchar
		std::string AnalysisResult; // 分析结果    varchar
		std::string GCEABB;         // 样品编号    varchar
		std::string SWBCF;          // 样品类型    varchar
		std::string IsMixSample;    // 混合样    varchar
		std::string PntType;        // 点类型    varchar
		std::string SecondCode;     // 样品二次编码    varchar
		float SampleVolume;         // 样品体积    float
		std::string GCEABM;         // 野外命名    varchar
		float GCEAAL;               // 样品重量(kg)    float
		std::string SampleLength;   // 样品长度(cm)    varchar
		std::string PretreatMethod; // 预处理方法    varchar
		std::string TestContent;    // 测试内容    varchar
		std::string PlanePosMap;    // 平面位置示意图    varchar
		std::string ProfileMap;     // 剖面示意图    varchar
		std::string FieldImage;     // 野外照片(视频)    varchar
		std::string RecordCard;     // 记录卡片(记录)    varchar
		std::string SampleOrgn;     // 采样单位    varchar
		std::string SWFOMW;         // 采样人    varchar
		std::string GCEABJ;         // 采样日期    date
		std::string Inputer;        // 录入员    varchar
		std::string InputOrgn;      // 录入单位    varchar
		std::string InputDate;      // 录入日期    date
		std::string GCEABD;         // 室内编号    varchar
		std::string TestEquip;      // 试验仪器    varchar
		std::string TestMethod;     // 试验方法    varchar
		std::string TestBased;      // 检验依据    varchar
		std::string GCEAJC;         // 试验单位    varchar
		std::string SWFGAM;         // 收样日期    date
		std::string SWFGAN;         // 报告日期    date
		std::string GCEAJD;         // 校对    varchar
		std::string Auditor;        // 审核    varchar
		std::string TestLeader;     // 试验负责人    varchar
		std::string _Report;        // 原始测试分析报告    varchar
	};

	// 工勘孔土的易溶性分析
	struct  Tyrxfxsj : public Bas_PntStdInfo
	{
	public:
		long TyrxfxsjID;            //* ID    int
		float StartDepth;           //* 取样顶深度    float
		float EndDepth;             //* 取样底深度    float
		long PntID;                 //* 点ID    int
		std::string TCDH;           //* 采样层位    varchar
		std::string TCMC;           // 土层名称    varchar
		std::string GeoCode;        // 地质代号    varchar
		std::string TestNo;         //     varchar
		std::string TestType;       // 试验类型    varchar
		std::string FXDATE;         // 分析日期    varchar
		double NAK;                 // K+和Na+易溶性    double
		double CA;                  // Ca2+易溶性    double
		double MG;                  // Mg2+易溶性    double
		double CO3;                 // CO32-易溶性    double
		double HCO3;                // HCO32-易溶性    double
		double SO4;                 // SO42-易溶性    double
		double CL;                  // Cl-易溶性    double
		double YD;                  // 硬度易溶性    double
		double LZZL;                // 离子总量    double
		double PH;                  // PH值    double
		std::string GCEABB;         // 样品编号    varchar
		std::string SWBCF;          // 样品类型    varchar
		std::string IsMixSample;    // 混合样    varchar
		std::string PntType;        // 点类型    varchar
		std::string SecondCode;     // 样品二次编码    varchar
		float SampleVolume;         // 样品体积    float
		std::string GCEABM;         // 野外命名    varchar
		float GCEAAL;               // 样品重量(kg)    float
		std::string SampleLength;   // 样品长度(cm)    varchar
		std::string PretreatMethod; // 预处理方法    varchar
		std::string TestContent;    // 测试内容    varchar
		std::string PlanePosMap;    // 平面位置示意图    varchar
		std::string ProfileMap;     // 剖面示意图    varchar
		std::string FieldImage;     // 野外照片(视频)    varchar
		std::string RecordCard;     // 记录卡片(记录)    varchar
		std::string SampleOrgn;     // 采样单位    varchar
		std::string SWFOMW;         // 采样人    varchar
		std::string GCEABJ;         // 采样日期    date
		std::string Inputer;        // 录入员    varchar
		std::string InputOrgn;      // 录入单位    varchar
		std::string InputDate;      // 录入日期    date
		std::string GCEABD;         // 室内编号    varchar
		std::string TestEquip;      // 试验仪器    varchar
		std::string TestMethod;     // 试验方法    varchar
		std::string TestBased;      // 检验依据    varchar
		std::string GCEAJC;         // 试验单位    varchar
		std::string SWFGAM;         // 收样日期    date
		std::string SWFGAN;         // 报告日期    date
		std::string GCEAJD;         // 校对    varchar
		std::string Auditor;        // 审核    varchar
		std::string TestLeader;     // 试验负责人    varchar
		std::string _Report;        // 原始测试分析报告    varchar
	};

	// 工勘孔岩石RQD实验
	struct  Ysrqdsj : public Bas_PntStdInfo
	{
	public:
		long TestID;                //* 测试ID    int
		float StartDepth;           //* 取样顶深度    float
		float EndDepth;             //* 取样底深度    float
		long PntID;                 //* 点ID    int
		std::string TCDH;           //* 采样层位    varchar
		std::string TCMC;           // 土层名称    varchar
		std::string GeoCode;        // 地质代号    varchar
		std::string TestNo;         //     varchar
		std::string TestType;       // 试验类型    varchar
		double TestVal;             // 岩石RQD    double
		std::string _Memo;          // 备注    varchar
		std::string GCEABB;         // 样品编号    varchar
		std::string SWBCF;          // 样品类型    varchar
		std::string IsMixSample;    // 混合样    varchar
		std::string PntType;        // 点类型    varchar
		std::string SecondCode;     // 样品二次编码    varchar
		float SampleVolume;         // 样品体积    float
		std::string GCEABM;         // 野外命名    varchar
		float GCEAAL;               // 样品重量(kg)    float
		std::string SampleLength;   // 样品长度(cm)    varchar
		std::string PretreatMethod; // 预处理方法    varchar
		std::string TestContent;    // 测试内容    varchar
		std::string PlanePosMap;    // 平面位置示意图    varchar
		std::string ProfileMap;     // 剖面示意图    varchar
		std::string FieldImage;     // 野外照片(视频)    varchar
		std::string RecordCard;     // 记录卡片(记录)    varchar
		std::string SampleOrgn;     // 采样单位    varchar
		std::string SWFOMW;         // 采样人    varchar
		std::string GCEABJ;         // 采样日期    date
		std::string Inputer;        // 录入员    varchar
		std::string InputOrgn;      // 录入单位    varchar
		std::string InputDate;      // 录入日期    date
		std::string GCEABD;         // 室内编号    varchar
		std::string TestEquip;      // 试验仪器    varchar
		std::string TestMethod;     // 试验方法    varchar
		std::string TestBased;      // 检验依据    varchar
		std::string GCEAJC;         // 试验单位    varchar
		std::string SWFGAM;         // 收样日期    date
		std::string SWFGAN;         // 报告日期    date
		std::string GCEAJD;         // 校对    varchar
		std::string Auditor;        // 审核    varchar
		std::string TestLeader;     // 试验负责人    varchar
		std::string _Report;        // 原始测试分析报告    varchar
	};

	// 岩石抗压强度表
	struct  Yskyqd : public Bas_PntStdInfo
	{
	public:
		long TestID;                   //* 测试ID    int
		float StartDepth;              //* 取样顶深度    float
		float EndDepth;                //* 取样底深度    float
		long PntID;                    //* 点ID    int
		std::string TCDH;              //* 采样层位    varchar
		std::string TCMC;              // 土层名称    varchar
		std::string GeoCode;           // 地质代号    varchar
		std::string TestNo;            //     varchar
		std::string TestType;          // 试验类型    varchar
		std::string TestStatus;        // 试样状态    varchar
		std::string TestSpecification; // 试样规格    varchar
		double TestArea;               // 试样面积(mm)    double
		double TotalDestoryPower;      // 总破坏力(KN)    double
		double CompressiveStrength;    // 抗压强度(MPa)    double
		double CorrectedValue;         // 修正值(MPa)    double
		double HDRatio;                // 高径比(H/D)    double
		std::string _Memo;             // 备注    varchar
		std::string GCEABB;            // 样品编号    varchar
		std::string SWBCF;             // 样品类型    varchar
		std::string IsMixSample;       // 混合样    varchar
		std::string PntType;           // 点类型    varchar
		std::string SecondCode;        // 样品二次编码    varchar
		float SampleVolume;            // 样品体积    float
		std::string GCEABM;            // 野外命名    varchar
		float GCEAAL;                  // 样品重量(kg)    float
		std::string SampleLength;      // 样品长度(cm)    varchar
		std::string PretreatMethod;    // 预处理方法    varchar
		std::string TestContent;       // 测试内容    varchar
		std::string PlanePosMap;       // 平面位置示意图    varchar
		std::string ProfileMap;        // 剖面示意图    varchar
		std::string FieldImage;        // 野外照片(视频)    varchar
		std::string RecordCard;        // 记录卡片(记录)    varchar
		std::string SampleOrgn;        // 采样单位    varchar
		std::string SWFOMW;            // 采样人    varchar
		std::string GCEABJ;            // 采样日期    date
		std::string Inputer;           // 录入员    varchar
		std::string InputOrgn;         // 录入单位    varchar
		std::string InputDate;         // 录入日期    date
		std::string GCEABD;            // 室内编号    varchar
		std::string TestEquip;         // 试验仪器    varchar
		std::string TestMethod;        // 试验方法    varchar
		std::string TestBased;         // 检验依据    varchar
		std::string GCEAJC;            // 试验单位    varchar
		std::string SWFGAM;            // 收样日期    date
		std::string SWFGAN;            // 报告日期    date
		std::string GCEAJD;            // 校对    varchar
		std::string Auditor;           // 审核    varchar
		std::string TestLeader;        // 试验负责人    varchar
		std::string _Report;           // 原始测试分析报告    varchar
	};

	// 现场监测分析成果表
	struct  INSceneExpIdent : public Bas_PntStdInfo
	{
	public:
		long SceneExpIdentID;      //* 现场检测记录ID    int
		float StartDepth;          //* 检测顶深度    float
		float EndDepth;            //* 检测底深度    float
		long PntID;                //* 点ID    int
		std::string TCDH;          //* 采样层位    varchar
		std::string TCMC;          // 土层名称    varchar
		std::string GeoCode;       // 地质代号    varchar
		std::string PntNo;         // 点号    varchar
		std::string PrjCode;       // 项目编号    varchar
		std::string DetectionType; // 检测类型    varchar
		std::string TestEquip;     // 检测仪器    varchar
		std::string DetectLevel;   // 检测层位    varchar
		std::string TestOrgn;      // 检测单位    varchar
		std::string TestDate;      // 检测日期    date
		std::string Inspector;     // 检测人    varchar
		std::string DetectIndex;   // 检测指标    varchar
		std::string ChemicalCode;  // 化学代号    varchar
		std::string NumericalUnit; // 数值单位    varchar
		std::string TestResult;    // 检测结果    varchar
	};

	// 监测仪器基本情况表
	struct  GeoEnvMonitorDivice : public Bas_PntStdInfo
	{
	public:
		long MonitorEquipID;             //* 监测仪器ID    int
		std::string EquipmentName;       // 仪器名称    varchar
		std::string EquipFactoryCode;    // 仪器出厂编码    varchar
		std::string EquipFactoryName;    // 仪器生产厂家    varchar
		std::string MonitoringIndex;     // 监测指标    varchar
		float PlaceDepth;                // 放置深度    float
		std::string CollectInterval;     // 数据采集间隔    varchar
		std::string CollectIntervalUnit; // 间隔时间单位    varchar
		std::string ProtectEquip;        // 保护装置    varchar
		bool IsCalibrate;                // 是否较准    bool
		std::string CalibrateType;       // 较准方式    varchar
		std::string EquipSysError;       // 仪器系统误差    varchar
		std::string EquipFetchTime;      // 仪器取出时间    date
		std::string EquipFetchReason;    // 仪器取出原因    varchar
		std::string RunningState;        // 运行状态    varchar
		std::string FieldInstallImage;   // 现场安装影像    varchar
		std::string FieldCalibratImage;  // 现场较准影像    varchar
		long PntID;                      //* 点ID    int
		std::string MonitorPntType;      // 监测点类型    varchar
		std::string MonitorObj;          // 监测对象    varchar
		std::string MonitorContent;      // 监测内容    varchar
		std::string MonitorType;         // 监测方式    varchar
		std::string MonitorSetDate;      // 监测点设置日期    date
		std::string PlanePosMap;         // 平面位置示意图    varchar
		std::string ProfileMap;          // 剖面示意图    varchar
		std::string MonitorDataDocID;    // 监测数据文档ID    varchar
		std::string MonitorPntImage;     // 监测点照片(视频)    varchar
		std::string RecordCard;          // 记录卡片(记录)    varchar
		std::string MonitorOgrn;         // 监测单位    varchar
		std::string Charge;              // 负责人    varchar
		std::string Inputer;             // 录入单位    varchar
		std::string InputOrgn;           // 录入员    varchar
		std::string InputDate;           // 录入日期    date
	};

	// 地下水位水温监测数据表
	struct  GeoEnvMonitoLevelTemp : public Bas_PntStdInfo
	{
	public:
		long LevelTempID;             //* 水位水温监测ID    int
		std::string MonitorDate;      // 监测时间    date
		std::string TKDAE;            // 天气    varchar
		float SWEGAB;                 // 水位埋深    float
		float GCKUGF;                 // 深度    float
		float SWADET;                 // 水温    float
		float SWADBB;                 // 气温    float
		long PntID;                   //* 点ID    int
		std::string MonitorPntType;   // 监测点类型    varchar
		std::string MonitorObj;       // 监测对象    varchar
		std::string MonitorContent;   // 监测内容    varchar
		std::string MonitorType;      // 监测方式    varchar
		std::string MonitorSetDate;   // 监测点设置日期    date
		std::string PlanePosMap;      // 平面位置示意图    varchar
		std::string ProfileMap;       // 剖面示意图    varchar
		std::string MonitorDataDocID; // 监测数据文档ID    varchar
		std::string MonitorPntImage;  // 监测点照片(视频)    varchar
		std::string RecordCard;       // 记录卡片(记录)    varchar
		std::string MonitorOgrn;      // 监测单位    varchar
		std::string Charge;           // 负责人    varchar
		std::string Inputer;          // 录入单位    varchar
		std::string InputOrgn;        // 录入员    varchar
		std::string InputDate;        // 录入日期    date
	};

	// （堰槽法）流量监测数据表
	struct  GeoEnvWeirMonitoFlow : public Bas_PntStdInfo
	{
	public:
		long WeirMonitoFlowID;        //* 堰槽流量监测ID    int
		std::string MonitorDate;      // 监测时间    date
		std::string WeirType;         // 堰槽类型    varchar
		float WeirReading;            // 堰槽读数    float
		std::string FlowUnit;         // 流量单位    varchar
		float _Flow;                  // 流量    float
		long PntID;                   //* 点ID    int
		std::string MonitorPntType;   // 监测点类型    varchar
		std::string MonitorObj;       // 监测对象    varchar
		std::string MonitorContent;   // 监测内容    varchar
		std::string MonitorType;      // 监测方式    varchar
		std::string MonitorSetDate;   // 监测点设置日期    date
		std::string PlanePosMap;      // 平面位置示意图    varchar
		std::string ProfileMap;       // 剖面示意图    varchar
		std::string MonitorDataDocID; // 监测数据文档ID    varchar
		std::string MonitorPntImage;  // 监测点照片(视频)    varchar
		std::string RecordCard;       // 记录卡片(记录)    varchar
		std::string MonitorOgrn;      // 监测单位    varchar
		std::string Charge;           // 负责人    varchar
		std::string Inputer;          // 录入单位    varchar
		std::string InputOrgn;        // 录入员    varchar
		std::string InputDate;        // 录入日期    date
	};

	// 监测断面测点数据表
	struct  GeoEnvMonitoSectPnt : public Bas_PntStdInfo
	{
	public:
		long TestFlowPntID;           //* 测流点ID    int
		std::string TestFlowPntNo;    // 测流点编号    varchar
		float Distance;               // 与起始点距离    float
		float TestPntDepth;           // 测点深度    float
		float EquipReading;           // 仪器读数    float
		std::string MeasureUnit;      // 计量单位    varchar
		float FlowRate;               // 流速    float
		std::string FlowRateUnit;     // 流速单位    varchar
		float SectionArea;            // 代表断面面积    float
		float SectionWaterflow;       // 代表断面流量    float
		std::string MonitorDate;      // 监测时间    date
		std::string MonitorFlowEquip; // 测流仪器    varchar
		std::string DeviceType;       // 仪器型号    varchar
		float SectionWidth;           // 断面宽度    float
		float AverageVelocity;        // 平均流速    float
		std::string VelocityUnit;     // 流速单位    varchar
		float Averageflow;            // 平均流量    float
		std::string FlowUnit;         // 流量单位    varchar
		long PntID;                   //* 点ID    int
		std::string MonitorPntType;   // 监测点类型    varchar
		std::string MonitorObj;       // 监测对象    varchar
		std::string MonitorContent;   // 监测内容    varchar
		std::string MonitorType;      // 监测方式    varchar
		std::string MonitorSetDate;   // 监测点设置日期    date
		std::string PlanePosMap;      // 平面位置示意图    varchar
		std::string ProfileMap;       // 剖面示意图    varchar
		std::string MonitorDataDocID; // 监测数据文档ID    varchar
		std::string MonitorPntImage;  // 监测点照片(视频)    varchar
		std::string RecordCard;       // 记录卡片(记录)    varchar
		std::string MonitorOgrn;      // 监测单位    varchar
		std::string Charge;           // 负责人    varchar
		std::string Inputer;          // 录入单位    varchar
		std::string InputOrgn;        // 录入员    varchar
		std::string InputDate;        // 录入日期    date
	};

	// 地下水开采量监测数据表
	struct  GeoEnvWaterExtract : public Bas_PntStdInfo
	{
	public:
		long ExploitatMonitorID;      //* 开采量监测ID    int
		std::string MonitorDate;      // 监测时间    date
		float EquipReading;           // 仪器读数    float
		float Exploitation;           // 开采量    float
		std::string exploitationUint; // 开采量单位    varchar
		long PntID;                   //* 点ID    int
		std::string MonitorPntType;   // 监测点类型    varchar
		std::string MonitorObj;       // 监测对象    varchar
		std::string MonitorContent;   // 监测内容    varchar
		std::string MonitorType;      // 监测方式    varchar
		std::string MonitorSetDate;   // 监测点设置日期    date
		std::string PlanePosMap;      // 平面位置示意图    varchar
		std::string ProfileMap;       // 剖面示意图    varchar
		std::string MonitorDataDocID; // 监测数据文档ID    varchar
		std::string MonitorPntImage;  // 监测点照片(视频)    varchar
		std::string RecordCard;       // 记录卡片(记录)    varchar
		std::string MonitorOgrn;      // 监测单位    varchar
		std::string Charge;           // 负责人    varchar
		std::string Inputer;          // 录入单位    varchar
		std::string InputOrgn;        // 录入员    varchar
		std::string InputDate;        // 录入日期    date
	};

	// 地面沉降监测数据表
	struct  GeoEnvLandSubsidence : public Bas_PntStdInfo
	{
	public:
		long SubsidenceID;            //* 沉降监测ID    int
		std::string MonitorDate;      // 监测时间    date
		double GCJCBJ;                // 高程    double
		std::string GCJCBJSys;        // 高程系统    varchar
		double Settlement;            // 沉降量    double
		long PntID;                   //* 点ID    int
		std::string MonitorPntType;   // 监测点类型    varchar
		std::string MonitorObj;       // 监测对象    varchar
		std::string MonitorContent;   // 监测内容    varchar
		std::string MonitorType;      // 监测方式    varchar
		std::string MonitorSetDate;   // 监测点设置日期    date
		std::string PlanePosMap;      // 平面位置示意图    varchar
		std::string ProfileMap;       // 剖面示意图    varchar
		std::string MonitorDataDocID; // 监测数据文档ID    varchar
		std::string MonitorPntImage;  // 监测点照片(视频)    varchar
		std::string RecordCard;       // 记录卡片(记录)    varchar
		std::string MonitorOgrn;      // 监测单位    varchar
		std::string Charge;           // 负责人    varchar
		std::string Inputer;          // 录入单位    varchar
		std::string InputOrgn;        // 录入员    varchar
		std::string InputDate;        // 录入日期    date
	};

	// 孔隙水压力监测数据表
	struct  GeoEnvPoreWater : public Bas_PntStdInfo
	{
	public:
		long PoreWaterID;             //* 孔隙水压监测ID    int
		std::string MonitorDate;      // 监测时间    date
		float GCKUGF;                 // 深度    float
		float EquipReading;           // 仪器读数    float
		float WaterPressure;          // 水压    float
		long PntID;                   //* 点ID    int
		std::string MonitorPntType;   // 监测点类型    varchar
		std::string MonitorObj;       // 监测对象    varchar
		std::string MonitorContent;   // 监测内容    varchar
		std::string MonitorType;      // 监测方式    varchar
		std::string MonitorSetDate;   // 监测点设置日期    date
		std::string PlanePosMap;      // 平面位置示意图    varchar
		std::string ProfileMap;       // 剖面示意图    varchar
		std::string MonitorDataDocID; // 监测数据文档ID    varchar
		std::string MonitorPntImage;  // 监测点照片(视频)    varchar
		std::string RecordCard;       // 记录卡片(记录)    varchar
		std::string MonitorOgrn;      // 监测单位    varchar
		std::string Charge;           // 负责人    varchar
		std::string Inputer;          // 录入单位    varchar
		std::string InputOrgn;        // 录入员    varchar
		std::string InputDate;        // 录入日期    date
	};

	// 地应力监测数据表
	struct  GeoEnvGroundStress : public Bas_PntStdInfo
	{
	public:
		long GroundStressID;          //* 地应力监测ID    int
		std::string MonitorDate;      // 监测时间    date
		float GCKUGF;                 // 深度    float
		float EquipReading;           // 仪器读数    float
		float StressValue;            // 应力值    float
		long PntID;                   //* 点ID    int
		std::string MonitorPntType;   // 监测点类型    varchar
		std::string MonitorObj;       // 监测对象    varchar
		std::string MonitorContent;   // 监测内容    varchar
		std::string MonitorType;      // 监测方式    varchar
		std::string MonitorSetDate;   // 监测点设置日期    date
		std::string PlanePosMap;      // 平面位置示意图    varchar
		std::string ProfileMap;       // 剖面示意图    varchar
		std::string MonitorDataDocID; // 监测数据文档ID    varchar
		std::string MonitorPntImage;  // 监测点照片(视频)    varchar
		std::string RecordCard;       // 记录卡片(记录)    varchar
		std::string MonitorOgrn;      // 监测单位    varchar
		std::string Charge;           // 负责人    varchar
		std::string Inputer;          // 录入单位    varchar
		std::string InputOrgn;        // 录入员    varchar
		std::string InputDate;        // 录入日期    date
	};

	// 降雨量监测数据表
	struct  GeoEnvRainFall : public Bas_PntStdInfo
	{
	public:
		long RainFallID;              //* 降雨量监测ID    int
		std::string MonitorDate;      // 监测时间    date
		float EquipReading;           // 仪器读数    float
		std::string CountUnit;        // 计数单位    varchar
		double TimeInterval;          // 时间间隔    double
		double RainFall;              // 降雨量    double
		std::string RainFallUnit;     // 降雨量单位    varchar
		long PntID;                   //* 点ID    int
		std::string MonitorPntType;   // 监测点类型    varchar
		std::string MonitorObj;       // 监测对象    varchar
		std::string MonitorContent;   // 监测内容    varchar
		std::string MonitorType;      // 监测方式    varchar
		std::string MonitorSetDate;   // 监测点设置日期    date
		std::string PlanePosMap;      // 平面位置示意图    varchar
		std::string ProfileMap;       // 剖面示意图    varchar
		std::string MonitorDataDocID; // 监测数据文档ID    varchar
		std::string MonitorPntImage;  // 监测点照片(视频)    varchar
		std::string RecordCard;       // 记录卡片(记录)    varchar
		std::string MonitorOgrn;      // 监测单位    varchar
		std::string Charge;           // 负责人    varchar
		std::string Inputer;          // 录入单位    varchar
		std::string InputOrgn;        // 录入员    varchar
		std::string InputDate;        // 录入日期    date
	};

	// 蒸发量监测数据表
	struct  GeoEnvEvaporation : public Bas_PntStdInfo
	{
	public:
		long EvaporationID;           //* 蒸发量监测ID    int
		std::string MonitorDate;      // 监测时间    date
		float EquipReading;           // 仪器读数    float
		std::string CountUnit;        // 计数单位    varchar
		double TimeInterval;          // 时间间隔    double
		double Evaporation;           // 蒸发量    double
		std::string EvaporateUnit;    // 蒸发量单位    varchar
		long PntID;                   //* 点ID    int
		std::string MonitorPntType;   // 监测点类型    varchar
		std::string MonitorObj;       // 监测对象    varchar
		std::string MonitorContent;   // 监测内容    varchar
		std::string MonitorType;      // 监测方式    varchar
		std::string MonitorSetDate;   // 监测点设置日期    date
		std::string PlanePosMap;      // 平面位置示意图    varchar
		std::string ProfileMap;       // 剖面示意图    varchar
		std::string MonitorDataDocID; // 监测数据文档ID    varchar
		std::string MonitorPntImage;  // 监测点照片(视频)    varchar
		std::string RecordCard;       // 记录卡片(记录)    varchar
		std::string MonitorOgrn;      // 监测单位    varchar
		std::string Charge;           // 负责人    varchar
		std::string Inputer;          // 录入单位    varchar
		std::string InputOrgn;        // 录入员    varchar
		std::string InputDate;        // 录入日期    date
	};


}

#endif