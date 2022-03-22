#pragma once
#include "s3dAttDBEngine_exp.h"
#include <string>
#include <vector>
#include <map>

namespace Smart3dMap
{
	/*--------------------------------------- 数据字典表 -------------------------------------------*/
	// 数据模型表 *
	#define SYSDICT_TABLE "sysdict_Mdl"
	#define SYS_TBL_CATEGORY_DATAMDLID		"dataMdlID"   //类型ID int
	#define SYS_TBL_CATEGORY_DATAMDLNAME	"dataMdlName" //类型名称 text
	#define SYS_TBL_CATEGORY_DATAMDLNAMEC	"dataMdlNameC"//类型中文名 text

	// 内部表信息 *
	#define SYSDICT_TABLEFLD "sysdict_MdlTbl"
	#define SYS_DICT_TBL_INNERTBLID			"innerTblID"   //内部表ID int
	#define SYS_DICT_TBL_INNERTBLNAME		"innerTblName" //内部表名称 text
	#define SYS_DICT_TBL_USERTBLNAME		"userTblName"  //用户表名称 text
	#define SYS_DICT_TBL_INNERTBLNAMEC		"innerTblNameC"//内部表中文名 text
	#define SYS_DICT_TBL_IS_REQUIRED		"is_required"  //是否必选 bool
	#define SYS_DICT_TBL_DATAMDLID			"dataMdlID"    //数据模型ID int
	#define SYS_DICT_TBL_TBLIDENTITY		"tblIdentity" //表标识（实验表、其他表等）

	// 内部表结构 *
	#define SYSDICT_FIELDENUM "sysdict_MdlTblFld"
	#define SYS_DICT_FLD_INNERTBLID			"innerTblID"	//内部表ID int 
	#define SYS_DICT_FLD_INNERFLDID			"innerFldID"	//内部字段ID int
	#define SYS_DICT_FLD_INERFLDNAME		"innerFldName"  //内部字段名 text
	#define SYS_DICT_FLD_USERTBLFLDNAME		"userTblFldName"//用户字段名 text
	#define SYS_DICT_FLD_INNERFLDTYPE		"innerFldType"  //内部字段类型 text（唯一确定各个字符串的名字）//整型、字符串型、布尔型、单精度型、双精度型、日期型			
	#define SYS_DICT_FLD_INERFLDNAMEC		"innerFldNameC" //内部字段中文名 text
	#define SYS_DICT_FLD_IS_REQUIRED		"is_required"   //是否必选 bool
	#define	SYS_DICT_FLD_FLDIDENTITY		"fldIdentity"	//字段标识（实验字段、其他字段等）	

	// 字段枚举表 *
	#define SYSDICT_TABLETYPE "sysdict_MdlTblFldEnum"
	#define SYS_DICT_ENUM_INNERTBLID		"innerTblID"		//内部表ID int
	#define SYS_DICT_ENUM_INNERFLDID		"InnerFldID"		//内部表字段ID int
	#define SYS_DICT_ENUM_INNERFLDENUMVALUE	"InnerFldEnumValue" //内部表字段枚举值 int
	#define SYS_DICT_ENUM_INNERENUMSTRING	"InnerEnumString"   //内部表字段枚举值语义 text


	typedef enum s3d_TBLIDENTITY
	{
		TEST_TBL, // 实验表 -- LH.2021.08.30 20:01 added.
		OTHER_TBL//其他表
	}TBLTYPE;

	typedef enum s3d_FLDIDENTITY
	{
		EXPERI_ATTR, //试验属性 -- 实验表的double型数据
		OTHER_ATTR, //其他属性
	}FLDTYPE;

	typedef enum DataType
	{
		Integer, // int
		Double, // float or double
		String, // string
		DateTime // string in C++, and Date in DB.
	}DataType;

	// 数据模型表 *
	class S3D_ATT_DBENGINE_API sysdict_Mdl
	{
	public:
		std::string dataMdlName;  //类型名称 text
		std::string dataMdlNameC; //类型中文名 text
		int dataMdlID;            //类型ID int
	};
	// 内部表信息 *
	class S3D_ATT_DBENGINE_API sysdict_MdlTbl
	{
	public:
		std::string		innerTblName;  //内部表名称 text
		std::string		innerTblNameC; //内部表中文名 text
		std::string		userTblName;   //用户表名称 text
		bool			is_required;    //是否必选 bool
		s3d_TBLIDENTITY tblIdentity;	//表标识（实验表、其他表等）int
		int				innerTblID;     //内部表ID int
		int				dataMdlID;      //数据模型ID int
	};
	enum FieldMacro;
	// 内部字段结构 *
	class S3D_ATT_DBENGINE_API sysdict_MdlTblFld
	{
	public:
		std::string		 innerFldName;   //内部字段名 text
		std::string		 innerFldNameC;  //内部字段中文名 text
		std::string		 userTblFldName; //用户字段名 text
		DataType		 innerFldType;   //内部字段类型 text（唯一确定各个字符串的名字）
		bool			 is_required;    //是否必选 bool
		s3d_FLDIDENTITY  fldIdentity;	 //字段标识（实验字段、其他字段等）int	
		FieldMacro		 fldEnum;		 //字段枚举值（获取数据可用）
		int				 length;		 //长度（主要用于varchar的长度）
		int				 precision;		 //精度
		int				 innerFldID;     //内部字段ID int
		int				 innerTblID;     //内部表ID int
	};
	// 字段枚举表 *
	class S3D_ATT_DBENGINE_API sysdict_MdlTblFldEnum
	{
	public:
		int innerTblID;              //内部表ID int
		int InnerFldID;              //内部表字段ID int
		int InnerFldEnumValue;       //内部表字段枚举值 int
		std::string InnerEnumString; //内部表字段枚举值语义 text
	};

	//该类为抽象类，每一种需要配置数据字典的专题数据库结构需要继承该类并实现forceInitDbMap
	class S3D_ATT_DBENGINE_API DbTblFldDef
	{
	protected:
		DbTblFldDef();
		virtual ~DbTblFldDef()=0;
		virtual void forceInitDbMap();//强制初始化,给s3dMdlContainer赋值
	public:

		struct s3dTblInfo
		{
			sysdict_MdlTbl tbl;
			std::vector<sysdict_MdlTblFld> flds;
		};

		struct s3dDbMdlInfo
		{
			sysdict_Mdl mdl;
			std::vector<s3dTblInfo> tbls;
		};


		void getsysMdlContainer(std::vector<s3dDbMdlInfo>& mdlInfos);
		void getsysdict_Mdls(std::vector<sysdict_Mdl>& mdls);
		void getsysdict_MdlTbls(std::vector<sysdict_MdlTbl>& tbls);
		void getsysdict_MflTblFlds(std::vector<sysdict_MdlTblFld>& flds);

		//根据表英文名获取表中文名
		std::string getInnerTblNameC(const std::string& innerTblName);
		//根据字段英文名获取字段中文名
		std::string getInnerFldNameC(const std::string& innerTblName, const std::string& innerFldName);

	private:
		void initDbMap();
		
	protected:
		std::vector<s3dDbMdlInfo> s3dMdlContainer;
	};
}
