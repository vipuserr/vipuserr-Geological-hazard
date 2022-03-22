#pragma once
#include "s3dAttDBEngine_exp.h"
#include <string>
#include <vector>
#include <map>

namespace Smart3dMap
{
	/*--------------------------------------- �����ֵ�� -------------------------------------------*/
	// ����ģ�ͱ� *
	#define SYSDICT_TABLE "sysdict_Mdl"
	#define SYS_TBL_CATEGORY_DATAMDLID		"dataMdlID"   //����ID int
	#define SYS_TBL_CATEGORY_DATAMDLNAME	"dataMdlName" //�������� text
	#define SYS_TBL_CATEGORY_DATAMDLNAMEC	"dataMdlNameC"//���������� text

	// �ڲ�����Ϣ *
	#define SYSDICT_TABLEFLD "sysdict_MdlTbl"
	#define SYS_DICT_TBL_INNERTBLID			"innerTblID"   //�ڲ���ID int
	#define SYS_DICT_TBL_INNERTBLNAME		"innerTblName" //�ڲ������� text
	#define SYS_DICT_TBL_USERTBLNAME		"userTblName"  //�û������� text
	#define SYS_DICT_TBL_INNERTBLNAMEC		"innerTblNameC"//�ڲ��������� text
	#define SYS_DICT_TBL_IS_REQUIRED		"is_required"  //�Ƿ��ѡ bool
	#define SYS_DICT_TBL_DATAMDLID			"dataMdlID"    //����ģ��ID int
	#define SYS_DICT_TBL_TBLIDENTITY		"tblIdentity" //���ʶ��ʵ���������ȣ�

	// �ڲ���ṹ *
	#define SYSDICT_FIELDENUM "sysdict_MdlTblFld"
	#define SYS_DICT_FLD_INNERTBLID			"innerTblID"	//�ڲ���ID int 
	#define SYS_DICT_FLD_INNERFLDID			"innerFldID"	//�ڲ��ֶ�ID int
	#define SYS_DICT_FLD_INERFLDNAME		"innerFldName"  //�ڲ��ֶ��� text
	#define SYS_DICT_FLD_USERTBLFLDNAME		"userTblFldName"//�û��ֶ��� text
	#define SYS_DICT_FLD_INNERFLDTYPE		"innerFldType"  //�ڲ��ֶ����� text��Ψһȷ�������ַ��������֣�//���͡��ַ����͡������͡��������͡�˫�����͡�������			
	#define SYS_DICT_FLD_INERFLDNAMEC		"innerFldNameC" //�ڲ��ֶ������� text
	#define SYS_DICT_FLD_IS_REQUIRED		"is_required"   //�Ƿ��ѡ bool
	#define	SYS_DICT_FLD_FLDIDENTITY		"fldIdentity"	//�ֶα�ʶ��ʵ���ֶΡ������ֶεȣ�	

	// �ֶ�ö�ٱ� *
	#define SYSDICT_TABLETYPE "sysdict_MdlTblFldEnum"
	#define SYS_DICT_ENUM_INNERTBLID		"innerTblID"		//�ڲ���ID int
	#define SYS_DICT_ENUM_INNERFLDID		"InnerFldID"		//�ڲ����ֶ�ID int
	#define SYS_DICT_ENUM_INNERFLDENUMVALUE	"InnerFldEnumValue" //�ڲ����ֶ�ö��ֵ int
	#define SYS_DICT_ENUM_INNERENUMSTRING	"InnerEnumString"   //�ڲ����ֶ�ö��ֵ���� text


	typedef enum s3d_TBLIDENTITY
	{
		TEST_TBL, // ʵ��� -- LH.2021.08.30 20:01 added.
		OTHER_TBL//������
	}TBLTYPE;

	typedef enum s3d_FLDIDENTITY
	{
		EXPERI_ATTR, //�������� -- ʵ����double������
		OTHER_ATTR, //��������
	}FLDTYPE;

	typedef enum DataType
	{
		Integer, // int
		Double, // float or double
		String, // string
		DateTime // string in C++, and Date in DB.
	}DataType;

	// ����ģ�ͱ� *
	class S3D_ATT_DBENGINE_API sysdict_Mdl
	{
	public:
		std::string dataMdlName;  //�������� text
		std::string dataMdlNameC; //���������� text
		int dataMdlID;            //����ID int
	};
	// �ڲ�����Ϣ *
	class S3D_ATT_DBENGINE_API sysdict_MdlTbl
	{
	public:
		std::string		innerTblName;  //�ڲ������� text
		std::string		innerTblNameC; //�ڲ��������� text
		std::string		userTblName;   //�û������� text
		bool			is_required;    //�Ƿ��ѡ bool
		s3d_TBLIDENTITY tblIdentity;	//���ʶ��ʵ���������ȣ�int
		int				innerTblID;     //�ڲ���ID int
		int				dataMdlID;      //����ģ��ID int
	};
	enum FieldMacro;
	// �ڲ��ֶνṹ *
	class S3D_ATT_DBENGINE_API sysdict_MdlTblFld
	{
	public:
		std::string		 innerFldName;   //�ڲ��ֶ��� text
		std::string		 innerFldNameC;  //�ڲ��ֶ������� text
		std::string		 userTblFldName; //�û��ֶ��� text
		DataType		 innerFldType;   //�ڲ��ֶ����� text��Ψһȷ�������ַ��������֣�
		bool			 is_required;    //�Ƿ��ѡ bool
		s3d_FLDIDENTITY  fldIdentity;	 //�ֶα�ʶ��ʵ���ֶΡ������ֶεȣ�int	
		FieldMacro		 fldEnum;		 //�ֶ�ö��ֵ����ȡ���ݿ��ã�
		int				 length;		 //���ȣ���Ҫ����varchar�ĳ��ȣ�
		int				 precision;		 //����
		int				 innerFldID;     //�ڲ��ֶ�ID int
		int				 innerTblID;     //�ڲ���ID int
	};
	// �ֶ�ö�ٱ� *
	class S3D_ATT_DBENGINE_API sysdict_MdlTblFldEnum
	{
	public:
		int innerTblID;              //�ڲ���ID int
		int InnerFldID;              //�ڲ����ֶ�ID int
		int InnerFldEnumValue;       //�ڲ����ֶ�ö��ֵ int
		std::string InnerEnumString; //�ڲ����ֶ�ö��ֵ���� text
	};

	//����Ϊ�����࣬ÿһ����Ҫ���������ֵ��ר�����ݿ�ṹ��Ҫ�̳и��ಢʵ��forceInitDbMap
	class S3D_ATT_DBENGINE_API DbTblFldDef
	{
	protected:
		DbTblFldDef();
		virtual ~DbTblFldDef()=0;
		virtual void forceInitDbMap();//ǿ�Ƴ�ʼ��,��s3dMdlContainer��ֵ
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

		//���ݱ�Ӣ������ȡ��������
		std::string getInnerTblNameC(const std::string& innerTblName);
		//�����ֶ�Ӣ������ȡ�ֶ�������
		std::string getInnerFldNameC(const std::string& innerTblName, const std::string& innerFldName);

	private:
		void initDbMap();
		
	protected:
		std::vector<s3dDbMdlInfo> s3dMdlContainer;
	};
}
