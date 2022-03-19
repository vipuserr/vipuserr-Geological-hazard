#pragma once

#include "s3dGMdlDBEngineExp.h"
#include "gmeDef.h"
#include <ctime>

namespace Smart3dMap {
	/// 三维地质模型的元数据。执行标准：“三维地质模型元数据（DD2019-12）”。
	class OG_GME_API gmeModelMetadata {
	public:
		gmeModelMetadata();
		virtual ~gmeModelMetadata();

	public:
		/// 标识信息。描述三维地质模型的基本信息。
		class OG_GME_API MDIdentification {
		public:
			MDIdentification();
			virtual ~MDIdentification();

			/// 摘要。关于三维地质模型的概要性描述，如模型覆盖范围、模型的特点及模型相关内容的简要说明等。
			GString GetAbstract() const { return abstract_; };
			void SetAbstract(const GString& str) { abstract_ = str; }
			/// 所属项目。当前地质模型所属的项目（项目来源）。
			GString GetProject() const { return project_; }
			void SetProject(const GString& project) { project_ = project; };
			/// 地理标识符。三维地质模型空间定位名称的标识。说明模型空间范围约定俗成的或众所周知的地名或地理范围，如地名、行政区划名称、工作区名称等。
			GString GetGeoGrahpicIdentifier() const { return geographicIdentifier_; }
			void SetGeoGrahpicIdentifier(const GString& v) { geographicIdentifier_ = v; }
			/// 专题类型。地质模型专业或专题内容的类别代码。
			GString GetTopicCategory() const { return topicCategory_; }
			void SetTopicCategory(const GString& v) { topicCategory_ = v; }
			/// 模型地质时代。地质模型所表达的地质时代范围。
			GString GetModelGeoAge() const { return modelGeologicalAge_; }
			void SetModelGeoAge(const GString& v) { modelGeologicalAge_ = v; }
			/// 模型类型。三维地质模型的类型。
			GString GetModelType() const { return modelType_; }
			void SetModelType(const GString& v) { modelType_ = v; }
			/// 目的。三维地质模型的应用目的及作用。
			GString GetPurpose() const { return purpose_; }
			void SetPurpose(const GString& v) { purpose_ = v; };
			/// 数据浏览网址。可供浏览当前数据的网络地址。
			GString GetBrowseURL() const { return browseUrl_; }
			void SetBrowseURL(const GString& v) { browseUrl_ = v; };
			/// 水平分辨率。模型数据的水平精度说明，如在水平面上数据源的比例尺等。
			GString GetHScale() const { return horizontalAccuracy_; }
			void SetHScale(const GString& v) { horizontalAccuracy_ = v; }
			/// 垂直分辨率。模型数据的垂直精度说明，如在垂向上数据源的比例尺等。
			GString GetVScale() const { return verticalAccuracy_; }
			void SetVScale(const GString& v) { verticalAccuracy_ = v; }
			/// 关键词。描述主题的通用词、形式化词或短语。
			GString GetKeywords() const { return keywords_; }
			void SetKeywords(const GString& v) { keywords_ = v; }
			/// 三维地质模型覆盖的地理范围。
			/// 西边经度。模型覆盖范围最西边的经度坐标，单位为十进制度。
			double GetWestLongitude() const { return westBoundLongitude_; }
			void SetWestLongitude(double v) { westBoundLongitude_ = v; }
			/// 东边经度。模型覆盖范围最东边的经度坐标，单位为十进制度。
			double GetEastLongitude() const { return eastBoundLongitude_; }
			void SetEastLongitude(double v) { eastBoundLongitude_ = v; }
			/// 南边纬度。模型覆盖范围最南边的纬度坐标，单位为十进制度。
			double GetSouthLatitude() const { return southBoundLatitude_; }
			void SetSouthLatitude(double v) { southBoundLatitude_ = v; }
			/// 北边纬度。模型覆盖范围最北边的纬度坐标，单位为十进制度。
			double GetNorthLatitude() const { return northBoundLatitude_; }
			void SetNorthLatitude(double v) { northBoundLatitude_ = v; }
			/// 模型数据的高程或深度信息。
			/// 最小垂向坐标值。数据集中最小高程或深度。
			double GetMinZValue() const { return minimumZValue_; }
			void SetMinZValue(double v) { minimumZValue_ = v; }
			/// 最大垂向坐标值。数据集中最大高程或深度。
			double GetMaxZValue() const { return maximumZValue_; }
			void SetMaxZValue(double v) { maximumZValue_ = v; }
			/// 垂向计量单位。高程或深度值的计量单位。
			GString GetUnitOfZMeasure() const { return unitOfZMeasure_; }
			void SetUnitOfZMeasure(const GString& v) { unitOfZMeasure_ = v; }
			/// 模型文件分发的格式信息。
			/// 格式名称。模型分发者提供的数据交换格式名称。
			GString GetModelFileFormatName() const { return modelFileFormatName_; }
			void SetModelFileFormatName(const GString& v) { modelFileFormatName_ = v; }
			/// 格式版本。数据格式的版本号。
			GString GetModelFileFormatVersion() const { return modelFileFormatVersion_; }
			void SetModelFileFormatVersion(const GString& v) { modelFileFormatVersion_ = v; }
			/// 文件大小。文件大小（单位：MB）。
			double GetModelFileSize() const { return modelFileSize_; }
			void SetModelFileSize(double v) { modelFileSize_ = v; }

		private:
			// 摘要
			GString abstract_;
			// 所属项目
			GString project_;
			// 地理标识符
			GString geographicIdentifier_;
			// 专题类型
			GString topicCategory_;
			// 模型地质时代
			GString modelGeologicalAge_;
			// 模型类型
			GString modelType_;
			// 目的
			GString purpose_;
			// 数据浏览网址
			GString browseUrl_;
			// 水平分辨率
			GString horizontalAccuracy_;
			// 垂直分辨率
			GString verticalAccuracy_;
			// 关键词
			GString keywords_;
			// 三维地质模型覆盖的地理范围
			// 西边经度
			double westBoundLongitude_;
			// 东边经度
			double eastBoundLongitude_;
			// 南边纬度
			double southBoundLatitude_;
			// 北边纬度
			double northBoundLatitude_;
			// 模型数据的高程或深度信息
			// 最小垂向坐标值
			double minimumZValue_;
			// 最大垂向坐标值
			double maximumZValue_;
			// 垂向计量单位
			GString unitOfZMeasure_;
			// 模型文件分发的格式信息
			// 格式名称
			GString modelFileFormatName_;
			// 格式版本
			GString modelFileFormatVersion_;
			// 文件大小
			double modelFileSize_;
		};

		/// 内容信息。描述当前三维地质模型的要素类、属性、地质体等相关的内容信息。
		class OG_GME_API  MDContent {
		public:
			MDContent();
			virtual ~MDContent();

			/// 地质要素类及属性列表。模型文件中，所包含的地质要素类及属性列表，属性列表只需列出属性名称即可。
			GString GetGeoFclsAttrInfo() const { return geoFeatureClassAndAttributeList_; }
			void SetGeoFclsAttrInfo(const GString& v) { geoFeatureClassAndAttributeList_ = v; }
			/// 地质体分类类型。描述建模过程中，地质体是按何种方式进行分类的，如按岩性分类、按地层时代分类、按属性分类等。
			GString GetGeoBodyClassificationType() const { return geoBodyClassificationType_; }
			void SetGeoBodyClassificationType(const GString& v) { geoBodyClassificationType_ = v; }
			/// 地质体数量。可区分的三维地质体的数量。
			int GetGeoBodyCount() const { return geoBodyCount_; }
			void SetGeoBodyCount(int n) { geoBodyCount_ = n; }
			/// 时空数据模型描述。描述时空数据模型的相关信息，如时空数据模型的类型（快照模型、切片模型等），时空数据模型表达的时间范围，作用等。
			GString GetSTDataModelDescription() const { return spatiotemporalDataModelDescription_; }
			void SetSTDataModelDescription(const GString& v) { spatiotemporalDataModelDescription_ = v; }

		private:
			// 地质要素类及属性列表
			GString geoFeatureClassAndAttributeList_;
			// 地质体分类类型
			GString geoBodyClassificationType_;
			// 地质体数量
			int geoBodyCount_;
			// 时空数据模型描述
			GString spatiotemporalDataModelDescription_;
		};

		/// 模型质量信息。提供地质模型质量的相关描述信息，如建模使用的数据源，建模使用的软件和采用的建模方法等。
		class OG_GME_API  MQModelQuality {
		public:
			MQModelQuality();
			virtual ~MQModelQuality();

			/// 验收说明。模型的验收信息，例如验收方式、验收报告中关于模型质量的认定、验收等级等。
			GString GetAcceptanceDescription() const { return acceptanceDescription_; }
			void SetAcceptanceDescription(const GString& v) { acceptanceDescription_ = v; }
			/// 数据密度及分布。建模数据源的密度及分布情况说明，如密度是否达到要求，分布是否均匀合理等。
			GString GetDataDistributionInfo() const { return dataDistribution_; }
			void SetDataDistributionInfo(const GString& v) { dataDistribution_ = v; };
			/// 钻孔信息。建模过程中使用的钻孔数量、钻孔类型、钻孔密度、钻孔空间分布情况、钻孔标化规范等相关信息的说明。
			GString GetBoreholeInfo() const { return boreholeInformation_; }
			void SetBoreholeInfo(const GString& v) { boreholeInformation_ = v; }
			/// 剖面信息。参与建模的地质剖面的个数、分布、密度等相关信息的描述。
			GString GetSectionInfo() const { return sectionInformation_; }
			void SetSectionInfo(const GString& v) { sectionInformation_ = v; }
			/// 路线地质调查。地表路线，实测剖面，路线剖面（信手剖面）以及相应的描述。
			GString GetGeoRouteSurvey() const { return geologicalRouteSurvey_; }
			void SetGeoRouteSurvey(const GString& v) { geologicalRouteSurvey_ = v; }
			/// 平面地质图。地表的平面地质数据，如调查点，产状，平面地质图等。
			GString GetGeologicaMapInfo() const { return geologicalMap_; }
			void SetGeologicalMapInfo(const GString& v) { geologicalMap_ = v; }
			/// 地球物理数据。地球物理相关数据，如覆盖范围、地球物理场数据。
			GString GetGeophysicalDataInfo() const { return geophysicalData_; }
			void SetGeophysicalDataInfo(const GString& v) { geophysicalData_ = v; }
			/// 地球化学数据。地球化学相关数据，如地球化学化验数据、化探异常数据等。
			GString GetGeochemicalDataInfo() const { return geochemicalData_; }
			void SetGeochemicalDataInfo(const GString& v) { geochemicalData_ = v; }
			/// 地形数据。地形数据来源：如等高线、散点、剖面等；地形数据精度：如10米等高线，散点密度等说明。
			GString GetDEMDataInfo() const { return demData_; }
			void SetDEMDataInfo(const GString& v) { demData_ = v; }
			/// 遥感影像。遥感影像来源、遥感影像精度等信息描述，如遥感影像分辨率。
			GString GetRSImageDataInfo() const { return remoteSensingImageData_; }
			void SetRSImageDataInfo(const GString& v) { remoteSensingImageData_ = v; }
			/// 勘探工程。所有由地质勘探工程施工所形成的模型数据，如井探、硐探、槽探等工程施工模型，如巷道、隧道、坑道模型的信息描述。
			GString GetEngineeringDataInfo() const { return explorationEngineeringModel_; }
			void SetEngineeringDataInfo(const GString& v) { explorationEngineeringModel_ = v; }
			/// 辅助工程。所有不影响地质模型数据精度的辅助模型数据，如构建筑物模型、地表景观模型等相关信息描述。
			GString GetAuxiliaryEngineeringDataInfo() const { return auxiliaryEngineeringModel_; }
			void SetAuxiliaryEngineeringDataInfo(const GString& v) { auxiliaryEngineeringModel_ = v; }
			/// 其他数据。建模过程中，使用到的除4.2.1-4.2.10所列数据之外的其他类型数据，在此一并说明。
			GString GetOtherDataInfo() const { return otherData_; }
			void SetOtherDataInfo(const GString& v) { otherData_ = v; }
			/// 建模工具。建模时采用的工具软件名称、版本及相关描述信息。
			GString GetModelingTool() const { return modelingTool_; }
			void SetModelingTool(const GString& v) { modelingTool_ = v; }
			/// 建模方法。建模采用的方法，如剖面建模、钻孔自动建模；建模采用的数学模型，拓扑推理方法、插值方法等描述。
			GString GetModelingMethod() const { return modelingMethod_; }
			void SetModelingMethod(const GString& v) { modelingMethod_ = v; }
			/// 数据处理。数据采集，数据处理，数据更新的规范（或要求），建模相关参数，数据处理过程等说明信息。
			GString GetDataProcessingFlow() const { return dataProcessingFlow_; }
			void SetDataProcessingFlow(const GString& v) { dataProcessingFlow_ = v; }
			/// 扩展链接。关于建模工具软件的扩展链接。
			GString GetExtendLink() const { return extendLink_; }
			void SetExtendLink(const GString& v) { extendLink_ = v; }
			/// 建模单位及人员。创建模型的单位及建模人员信息。
			GString GetModelingOrganization() const { return modelingUnit_; }
			void SetModelingOrganization(const GString& v) { modelingUnit_ = v; }
			/// 不确定性描述。三维地质模型的不确定性总体描述，如建模数据不确定性特征、地质模型逻辑一致性检验、地质模型空间结构不确定性、地质模型属性不确定性、地质模型主观不确定性等。
			GString GetUncertaintyInfo() const { return uncertaintyDescription_; }
			void SetUncertaintyInfo(const GString& v) { uncertaintyDescription_ = v; }

		private:
			// 验收说明
			GString acceptanceDescription_;
			// 数据密度及分布
			GString dataDistribution_;
			// 钻孔信息
			GString boreholeInformation_;
			// 剖面信息
			GString sectionInformation_;
			// 路线地质调查
			GString geologicalRouteSurvey_;
			// 平面地质图
			GString geologicalMap_;
			// 地球物理数据
			GString geophysicalData_;
			// 地球化学数据
			GString geochemicalData_;
			// 地形数据
			GString demData_;
			// 遥感影像
			GString remoteSensingImageData_;
			// 勘探工程
			GString explorationEngineeringModel_;
			// 辅助工程
			GString auxiliaryEngineeringModel_;
			// 其他数据
			GString otherData_;
			// 建模工具
			GString modelingTool_;
			// 建模方法
			GString modelingMethod_;
			// 数据处理
			GString dataProcessingFlow_;
			// 扩展链接
			GString extendLink_;
			// 建模单位及人员
			GString modelingUnit_;
			// 不确定性描述
			GString uncertaintyDescription_;
		};

		/// 空间参照系信息。三维地质模型采用的空间参照系的信息。
		class OG_GME_API  RSReferenceSystem {
		public:
			RSReferenceSystem();
			virtual ~RSReferenceSystem();

			/// 名称。基于地理标识的空间参照系名称。
			GString GetRefSysName() const { return refSysName_; }
			void SetRefSysName(const GString& v) { refSysName_ = v; }
			/// 坐标参照系名称。坐标参照系名称。
			GString GetCoodRSID() const { return coodRSID_; }
			void SetCoodRSID(const GString& v) { coodRSID_ = v; };
			/// 坐标系类型。坐标系类型名称。
			GString GetCoodType() const { return coodType_; }
			void SetCoodType(const GString& v) { coodType_ = v; }
			/// 坐标系名称。坐标系名称。
			GString GetCoodSID() const { return coodSID_; }
			void SetCoodSID(const GString& v) { coodSID_ = v; }
			/// 投影参数。有关投影坐标参数的说明。
			GString GetProjParameter() const { return projParameter_; }
			void SetProjParameter(const GString& v) { projParameter_ = v; }
			/// 垂向坐标参照系名称。垂向坐标参照系名称。
			GString GetVerRSID() const { return verRSID_; }
			void SetVerSRID(const GString& v) { verRSID_ = v; }

		private:
			// 名称
			GString refSysName_;
			// 坐标参照系名称
			GString coodRSID_;
			// 坐标系类型
			GString coodType_;
			// 坐标系名称
			GString coodSID_;
			// 投影参数
			GString projParameter_;
			// 垂向坐标参照系名称
			GString verRSID_;
		};

		/// 分发信息。提供三维地质模型分发以及获取信息产品方法的信息。
		class OG_GME_API  MDDistribution {
		public:
			MDDistribution();
			virtual ~MDDistribution();

			/// 在线信息。提供数据的在线资源信息，可使用URL地址或DOI描述。
			GString GetOnlineInfo() const { return onlineInformation_; }
			void SetOnlineInfo(const GString& v) { onlineInformation_ = v; };
			/// 订购说明。分发方提供的分发订购说明信息。
			GString GetOrderingInstruction() const { return orderingInstructions_; }
			void SetOrderingInstruction(const GString& v) { orderingInstructions_ = v; }
			/// 联系单位名称。
			GString GetOrganizationName() const { return organizationName_; }
			void SetOrganizationName(const GString& v) { organizationName_ = v; };
			/// 详细地址。所在位置的详细地址，包括路名、门牌号等。
			GString GetAddress() const { return address_; }
			void SetAddress(const GString& v) { address_ = v; }
			/// 电话。电话号码。
			GString GetPhone() const { return phone_; }
			void SetPhone(const GString& v) { phone_ = v; }
			/// 电子邮件地址。负责单位提供数据订购服务的电子邮件地址。
			GString GetEMail() const { return eMail_; }
			void SetEMail(const GString& v) { eMail_ = v; }
			/// 介质名称。分发方提供数据集的介质名称。
			GString GetMediumName() const { return mediumName_; }
			void SetMediumName(const GString& v) { mediumName_ = v; }
			/// 介质说明。分发介质技术格式、数据量的说明。
			GString GetMediumNote() const { return mediumNote_; }
			void SetMediumNote(const GString& v) { mediumNote_ = v; }
			/// 使用限制。使用数据集时涉及隐私权、知识产权的保护、或任何特定的约束、限制或注意事项。
			GString GetUseConstraints() const { return useConstraints_; }
			void SetUseConstraints(const GString& v) { useConstraints_ = v; }
			/// 安全等级。出于国家安全、保密或其它考虑，对数据集安全限制的名称。
			GString GetSecurityClassification() const { return securityClassification_; }
			void SetSecurityClassification(const GString& v) { securityClassification_ = v; }

		private:
			// 在线信息
			GString onlineInformation_;
			// 订购说明
			GString orderingInstructions_;
			// 联系单位名称
			GString organizationName_;
			// 详细地址
			GString address_;
			// 电话
			GString phone_;
			// 电子邮件地址
			GString eMail_;
			// 介质名称
			GString mediumName_;
			// 介质说明
			GString mediumNote_;
			// 使用限制
			GString useConstraints_;
			// 安全等级
			GString securityClassification_;
		};

	public:
		/// 数据库记录ID
		int GetModelId() const;
		void SetModelId(int id);
		/// 元数据的名称。
		GString GetTitle() const;
		void SetTitle(const GString& title);
		/// 元数据的发布日期
		tm GetDateStamp() const;
		void SetDateStamp(const tm& t);
		/// 元数据使用的语言
		GString GetLanguage() const;
		void SetLanguage(const GString& lan);
		/// 元数据采用的字符编码标准
		GString GetCharSet() const;
		void SetCharSet(const GString& charSet);
		/// 执行的元数据标准名称
		GString GetStandardName() const;
		void SetStandardName(const GString& name);
		/// 标识信息
		const MDIdentification& GetIdentification() const;
		MDIdentification& GetIdentification();
		/// 内容信息
		const MDContent& GetContent() const;
		MDContent& GetContent();
		/// 模型质量信息
		const MQModelQuality& GetQualityInfo() const;
		MQModelQuality& GetQualityInfo();
		/// 空间参照系信息
		const RSReferenceSystem& GetSRS() const;
		RSReferenceSystem& GetSRS();
		/// 分发信息
		const MDDistribution& GetDistributionInfo() const;
		MDDistribution& GetDistributionInfo();

	private:
		// 数据库记录的ID。
		int id_;
		// 元数据的名称
		GString metadataTitle_;
		// 元数据的发布日期
		tm dateStamp_;
		// 元数据使用的语言
		GString language_;
		// 元数据采用的字符编码标准
		GString characterSet_;
		// 执行的元数据标准名称
		GString metadataStandardName_;
		// 标识信息
		MDIdentification identification_;
		// 内容信息
		MDContent content_;
		// 模型质量信息
		MQModelQuality qualitiy_;
		// 空间参照系信息
		RSReferenceSystem srs_;
		// 分发信息
		MDDistribution distribution_;
	};
}

