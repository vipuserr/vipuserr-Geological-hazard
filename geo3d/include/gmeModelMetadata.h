#pragma once

#include "s3dGMdlDBEngineExp.h"
#include "gmeDef.h"
#include <ctime>

namespace Smart3dMap {
	/// ��ά����ģ�͵�Ԫ���ݡ�ִ�б�׼������ά����ģ��Ԫ���ݣ�DD2019-12������
	class OG_GME_API gmeModelMetadata {
	public:
		gmeModelMetadata();
		virtual ~gmeModelMetadata();

	public:
		/// ��ʶ��Ϣ��������ά����ģ�͵Ļ�����Ϣ��
		class OG_GME_API MDIdentification {
		public:
			MDIdentification();
			virtual ~MDIdentification();

			/// ժҪ��������ά����ģ�͵ĸ�Ҫ����������ģ�͸��Ƿ�Χ��ģ�͵��ص㼰ģ��������ݵļ�Ҫ˵���ȡ�
			GString GetAbstract() const { return abstract_; };
			void SetAbstract(const GString& str) { abstract_ = str; }
			/// ������Ŀ����ǰ����ģ����������Ŀ����Ŀ��Դ����
			GString GetProject() const { return project_; }
			void SetProject(const GString& project) { project_ = project; };
			/// �����ʶ������ά����ģ�Ϳռ䶨λ���Ƶı�ʶ��˵��ģ�Ϳռ䷶ΧԼ���׳ɵĻ�������֪�ĵ��������Χ��������������������ơ����������Ƶȡ�
			GString GetGeoGrahpicIdentifier() const { return geographicIdentifier_; }
			void SetGeoGrahpicIdentifier(const GString& v) { geographicIdentifier_ = v; }
			/// ר�����͡�����ģ��רҵ��ר�����ݵ������롣
			GString GetTopicCategory() const { return topicCategory_; }
			void SetTopicCategory(const GString& v) { topicCategory_ = v; }
			/// ģ�͵���ʱ��������ģ�������ĵ���ʱ����Χ��
			GString GetModelGeoAge() const { return modelGeologicalAge_; }
			void SetModelGeoAge(const GString& v) { modelGeologicalAge_ = v; }
			/// ģ�����͡���ά����ģ�͵����͡�
			GString GetModelType() const { return modelType_; }
			void SetModelType(const GString& v) { modelType_ = v; }
			/// Ŀ�ġ���ά����ģ�͵�Ӧ��Ŀ�ļ����á�
			GString GetPurpose() const { return purpose_; }
			void SetPurpose(const GString& v) { purpose_ = v; };
			/// ���������ַ���ɹ������ǰ���ݵ������ַ��
			GString GetBrowseURL() const { return browseUrl_; }
			void SetBrowseURL(const GString& v) { browseUrl_ = v; };
			/// ˮƽ�ֱ��ʡ�ģ�����ݵ�ˮƽ����˵��������ˮƽ��������Դ�ı����ߵȡ�
			GString GetHScale() const { return horizontalAccuracy_; }
			void SetHScale(const GString& v) { horizontalAccuracy_ = v; }
			/// ��ֱ�ֱ��ʡ�ģ�����ݵĴ�ֱ����˵�������ڴ���������Դ�ı����ߵȡ�
			GString GetVScale() const { return verticalAccuracy_; }
			void SetVScale(const GString& v) { verticalAccuracy_ = v; }
			/// �ؼ��ʡ����������ͨ�ôʡ���ʽ���ʻ���
			GString GetKeywords() const { return keywords_; }
			void SetKeywords(const GString& v) { keywords_ = v; }
			/// ��ά����ģ�͸��ǵĵ���Χ��
			/// ���߾��ȡ�ģ�͸��Ƿ�Χ�����ߵľ������꣬��λΪʮ���ƶȡ�
			double GetWestLongitude() const { return westBoundLongitude_; }
			void SetWestLongitude(double v) { westBoundLongitude_ = v; }
			/// ���߾��ȡ�ģ�͸��Ƿ�Χ��ߵľ������꣬��λΪʮ���ƶȡ�
			double GetEastLongitude() const { return eastBoundLongitude_; }
			void SetEastLongitude(double v) { eastBoundLongitude_ = v; }
			/// �ϱ�γ�ȡ�ģ�͸��Ƿ�Χ���ϱߵ�γ�����꣬��λΪʮ���ƶȡ�
			double GetSouthLatitude() const { return southBoundLatitude_; }
			void SetSouthLatitude(double v) { southBoundLatitude_ = v; }
			/// ����γ�ȡ�ģ�͸��Ƿ�Χ��ߵ�γ�����꣬��λΪʮ���ƶȡ�
			double GetNorthLatitude() const { return northBoundLatitude_; }
			void SetNorthLatitude(double v) { northBoundLatitude_ = v; }
			/// ģ�����ݵĸ̻߳������Ϣ��
			/// ��С��������ֵ�����ݼ�����С�̻߳���ȡ�
			double GetMinZValue() const { return minimumZValue_; }
			void SetMinZValue(double v) { minimumZValue_ = v; }
			/// ���������ֵ�����ݼ������̻߳���ȡ�
			double GetMaxZValue() const { return maximumZValue_; }
			void SetMaxZValue(double v) { maximumZValue_ = v; }
			/// ���������λ���̻߳����ֵ�ļ�����λ��
			GString GetUnitOfZMeasure() const { return unitOfZMeasure_; }
			void SetUnitOfZMeasure(const GString& v) { unitOfZMeasure_ = v; }
			/// ģ���ļ��ַ��ĸ�ʽ��Ϣ��
			/// ��ʽ���ơ�ģ�ͷַ����ṩ�����ݽ�����ʽ���ơ�
			GString GetModelFileFormatName() const { return modelFileFormatName_; }
			void SetModelFileFormatName(const GString& v) { modelFileFormatName_ = v; }
			/// ��ʽ�汾�����ݸ�ʽ�İ汾�š�
			GString GetModelFileFormatVersion() const { return modelFileFormatVersion_; }
			void SetModelFileFormatVersion(const GString& v) { modelFileFormatVersion_ = v; }
			/// �ļ���С���ļ���С����λ��MB����
			double GetModelFileSize() const { return modelFileSize_; }
			void SetModelFileSize(double v) { modelFileSize_ = v; }

		private:
			// ժҪ
			GString abstract_;
			// ������Ŀ
			GString project_;
			// �����ʶ��
			GString geographicIdentifier_;
			// ר������
			GString topicCategory_;
			// ģ�͵���ʱ��
			GString modelGeologicalAge_;
			// ģ������
			GString modelType_;
			// Ŀ��
			GString purpose_;
			// ���������ַ
			GString browseUrl_;
			// ˮƽ�ֱ���
			GString horizontalAccuracy_;
			// ��ֱ�ֱ���
			GString verticalAccuracy_;
			// �ؼ���
			GString keywords_;
			// ��ά����ģ�͸��ǵĵ���Χ
			// ���߾���
			double westBoundLongitude_;
			// ���߾���
			double eastBoundLongitude_;
			// �ϱ�γ��
			double southBoundLatitude_;
			// ����γ��
			double northBoundLatitude_;
			// ģ�����ݵĸ̻߳������Ϣ
			// ��С��������ֵ
			double minimumZValue_;
			// ���������ֵ
			double maximumZValue_;
			// ���������λ
			GString unitOfZMeasure_;
			// ģ���ļ��ַ��ĸ�ʽ��Ϣ
			// ��ʽ����
			GString modelFileFormatName_;
			// ��ʽ�汾
			GString modelFileFormatVersion_;
			// �ļ���С
			double modelFileSize_;
		};

		/// ������Ϣ��������ǰ��ά����ģ�͵�Ҫ���ࡢ���ԡ����������ص�������Ϣ��
		class OG_GME_API  MDContent {
		public:
			MDContent();
			virtual ~MDContent();

			/// ����Ҫ���༰�����б�ģ���ļ��У��������ĵ���Ҫ���༰�����б������б�ֻ���г��������Ƽ��ɡ�
			GString GetGeoFclsAttrInfo() const { return geoFeatureClassAndAttributeList_; }
			void SetGeoFclsAttrInfo(const GString& v) { geoFeatureClassAndAttributeList_ = v; }
			/// ������������͡�������ģ�����У��������ǰ����ַ�ʽ���з���ģ��簴���Է��ࡢ���ز�ʱ�����ࡢ�����Է���ȡ�
			GString GetGeoBodyClassificationType() const { return geoBodyClassificationType_; }
			void SetGeoBodyClassificationType(const GString& v) { geoBodyClassificationType_ = v; }
			/// �����������������ֵ���ά�������������
			int GetGeoBodyCount() const { return geoBodyCount_; }
			void SetGeoBodyCount(int n) { geoBodyCount_ = n; }
			/// ʱ������ģ������������ʱ������ģ�͵������Ϣ����ʱ������ģ�͵����ͣ�����ģ�͡���Ƭģ�͵ȣ���ʱ������ģ�ͱ���ʱ�䷶Χ�����õȡ�
			GString GetSTDataModelDescription() const { return spatiotemporalDataModelDescription_; }
			void SetSTDataModelDescription(const GString& v) { spatiotemporalDataModelDescription_ = v; }

		private:
			// ����Ҫ���༰�����б�
			GString geoFeatureClassAndAttributeList_;
			// �������������
			GString geoBodyClassificationType_;
			// ����������
			int geoBodyCount_;
			// ʱ������ģ������
			GString spatiotemporalDataModelDescription_;
		};

		/// ģ��������Ϣ���ṩ����ģ�����������������Ϣ���罨ģʹ�õ�����Դ����ģʹ�õ�����Ͳ��õĽ�ģ�����ȡ�
		class OG_GME_API  MQModelQuality {
		public:
			MQModelQuality();
			virtual ~MQModelQuality();

			/// ����˵����ģ�͵�������Ϣ���������շ�ʽ�����ձ����й���ģ���������϶������յȼ��ȡ�
			GString GetAcceptanceDescription() const { return acceptanceDescription_; }
			void SetAcceptanceDescription(const GString& v) { acceptanceDescription_ = v; }
			/// �����ܶȼ��ֲ�����ģ����Դ���ܶȼ��ֲ����˵�������ܶ��Ƿ�ﵽҪ�󣬷ֲ��Ƿ���Ⱥ���ȡ�
			GString GetDataDistributionInfo() const { return dataDistribution_; }
			void SetDataDistributionInfo(const GString& v) { dataDistribution_ = v; };
			/// �����Ϣ����ģ������ʹ�õ����������������͡�����ܶȡ���׿ռ�ֲ��������ױ껯�淶�������Ϣ��˵����
			GString GetBoreholeInfo() const { return boreholeInformation_; }
			void SetBoreholeInfo(const GString& v) { boreholeInformation_ = v; }
			/// ������Ϣ�����뽨ģ�ĵ�������ĸ������ֲ����ܶȵ������Ϣ��������
			GString GetSectionInfo() const { return sectionInformation_; }
			void SetSectionInfo(const GString& v) { sectionInformation_ = v; }
			/// ·�ߵ��ʵ��顣�ر�·�ߣ�ʵ�����棬·�����棨�������棩�Լ���Ӧ��������
			GString GetGeoRouteSurvey() const { return geologicalRouteSurvey_; }
			void SetGeoRouteSurvey(const GString& v) { geologicalRouteSurvey_ = v; }
			/// ƽ�����ͼ���ر��ƽ��������ݣ������㣬��״��ƽ�����ͼ�ȡ�
			GString GetGeologicaMapInfo() const { return geologicalMap_; }
			void SetGeologicalMapInfo(const GString& v) { geologicalMap_ = v; }
			/// �����������ݡ���������������ݣ��縲�Ƿ�Χ�������������ݡ�
			GString GetGeophysicalDataInfo() const { return geophysicalData_; }
			void SetGeophysicalDataInfo(const GString& v) { geophysicalData_ = v; }
			/// ����ѧ���ݡ�����ѧ������ݣ������ѧ�������ݡ���̽�쳣���ݵȡ�
			GString GetGeochemicalDataInfo() const { return geochemicalData_; }
			void SetGeochemicalDataInfo(const GString& v) { geochemicalData_ = v; }
			/// �������ݡ�����������Դ����ȸ��ߡ�ɢ�㡢����ȣ��������ݾ��ȣ���10�׵ȸ��ߣ�ɢ���ܶȵ�˵����
			GString GetDEMDataInfo() const { return demData_; }
			void SetDEMDataInfo(const GString& v) { demData_ = v; }
			/// ң��Ӱ��ң��Ӱ����Դ��ң��Ӱ�񾫶ȵ���Ϣ��������ң��Ӱ��ֱ��ʡ�
			GString GetRSImageDataInfo() const { return remoteSensingImageData_; }
			void SetRSImageDataInfo(const GString& v) { remoteSensingImageData_ = v; }
			/// ��̽���̡������ɵ��ʿ�̽����ʩ�����γɵ�ģ�����ݣ��羮̽����̽����̽�ȹ���ʩ��ģ�ͣ��������������ӵ�ģ�͵���Ϣ������
			GString GetEngineeringDataInfo() const { return explorationEngineeringModel_; }
			void SetEngineeringDataInfo(const GString& v) { explorationEngineeringModel_ = v; }
			/// �������̡����в�Ӱ�����ģ�����ݾ��ȵĸ���ģ�����ݣ��繹������ģ�͡��ر���ģ�͵������Ϣ������
			GString GetAuxiliaryEngineeringDataInfo() const { return auxiliaryEngineeringModel_; }
			void SetAuxiliaryEngineeringDataInfo(const GString& v) { auxiliaryEngineeringModel_ = v; }
			/// �������ݡ���ģ�����У�ʹ�õ��ĳ�4.2.1-4.2.10��������֮��������������ݣ��ڴ�һ��˵����
			GString GetOtherDataInfo() const { return otherData_; }
			void SetOtherDataInfo(const GString& v) { otherData_ = v; }
			/// ��ģ���ߡ���ģʱ���õĹ���������ơ��汾�����������Ϣ��
			GString GetModelingTool() const { return modelingTool_; }
			void SetModelingTool(const GString& v) { modelingTool_ = v; }
			/// ��ģ��������ģ���õķ����������潨ģ������Զ���ģ����ģ���õ���ѧģ�ͣ���������������ֵ������������
			GString GetModelingMethod() const { return modelingMethod_; }
			void SetModelingMethod(const GString& v) { modelingMethod_ = v; }
			/// ���ݴ������ݲɼ������ݴ������ݸ��µĹ淶����Ҫ�󣩣���ģ��ز��������ݴ�����̵�˵����Ϣ��
			GString GetDataProcessingFlow() const { return dataProcessingFlow_; }
			void SetDataProcessingFlow(const GString& v) { dataProcessingFlow_ = v; }
			/// ��չ���ӡ����ڽ�ģ�����������չ���ӡ�
			GString GetExtendLink() const { return extendLink_; }
			void SetExtendLink(const GString& v) { extendLink_ = v; }
			/// ��ģ��λ����Ա������ģ�͵ĵ�λ����ģ��Ա��Ϣ��
			GString GetModelingOrganization() const { return modelingUnit_; }
			void SetModelingOrganization(const GString& v) { modelingUnit_ = v; }
			/// ��ȷ������������ά����ģ�͵Ĳ�ȷ���������������罨ģ���ݲ�ȷ��������������ģ���߼�һ���Լ��顢����ģ�Ϳռ�ṹ��ȷ���ԡ�����ģ�����Բ�ȷ���ԡ�����ģ�����۲�ȷ���Եȡ�
			GString GetUncertaintyInfo() const { return uncertaintyDescription_; }
			void SetUncertaintyInfo(const GString& v) { uncertaintyDescription_ = v; }

		private:
			// ����˵��
			GString acceptanceDescription_;
			// �����ܶȼ��ֲ�
			GString dataDistribution_;
			// �����Ϣ
			GString boreholeInformation_;
			// ������Ϣ
			GString sectionInformation_;
			// ·�ߵ��ʵ���
			GString geologicalRouteSurvey_;
			// ƽ�����ͼ
			GString geologicalMap_;
			// ������������
			GString geophysicalData_;
			// ����ѧ����
			GString geochemicalData_;
			// ��������
			GString demData_;
			// ң��Ӱ��
			GString remoteSensingImageData_;
			// ��̽����
			GString explorationEngineeringModel_;
			// ��������
			GString auxiliaryEngineeringModel_;
			// ��������
			GString otherData_;
			// ��ģ����
			GString modelingTool_;
			// ��ģ����
			GString modelingMethod_;
			// ���ݴ���
			GString dataProcessingFlow_;
			// ��չ����
			GString extendLink_;
			// ��ģ��λ����Ա
			GString modelingUnit_;
			// ��ȷ��������
			GString uncertaintyDescription_;
		};

		/// �ռ����ϵ��Ϣ����ά����ģ�Ͳ��õĿռ����ϵ����Ϣ��
		class OG_GME_API  RSReferenceSystem {
		public:
			RSReferenceSystem();
			virtual ~RSReferenceSystem();

			/// ���ơ����ڵ����ʶ�Ŀռ����ϵ���ơ�
			GString GetRefSysName() const { return refSysName_; }
			void SetRefSysName(const GString& v) { refSysName_ = v; }
			/// �������ϵ���ơ��������ϵ���ơ�
			GString GetCoodRSID() const { return coodRSID_; }
			void SetCoodRSID(const GString& v) { coodRSID_ = v; };
			/// ����ϵ���͡�����ϵ�������ơ�
			GString GetCoodType() const { return coodType_; }
			void SetCoodType(const GString& v) { coodType_ = v; }
			/// ����ϵ���ơ�����ϵ���ơ�
			GString GetCoodSID() const { return coodSID_; }
			void SetCoodSID(const GString& v) { coodSID_ = v; }
			/// ͶӰ�������й�ͶӰ���������˵����
			GString GetProjParameter() const { return projParameter_; }
			void SetProjParameter(const GString& v) { projParameter_ = v; }
			/// �����������ϵ���ơ������������ϵ���ơ�
			GString GetVerRSID() const { return verRSID_; }
			void SetVerSRID(const GString& v) { verRSID_ = v; }

		private:
			// ����
			GString refSysName_;
			// �������ϵ����
			GString coodRSID_;
			// ����ϵ����
			GString coodType_;
			// ����ϵ����
			GString coodSID_;
			// ͶӰ����
			GString projParameter_;
			// �����������ϵ����
			GString verRSID_;
		};

		/// �ַ���Ϣ���ṩ��ά����ģ�ͷַ��Լ���ȡ��Ϣ��Ʒ��������Ϣ��
		class OG_GME_API  MDDistribution {
		public:
			MDDistribution();
			virtual ~MDDistribution();

			/// ������Ϣ���ṩ���ݵ�������Դ��Ϣ����ʹ��URL��ַ��DOI������
			GString GetOnlineInfo() const { return onlineInformation_; }
			void SetOnlineInfo(const GString& v) { onlineInformation_ = v; };
			/// ����˵�����ַ����ṩ�ķַ�����˵����Ϣ��
			GString GetOrderingInstruction() const { return orderingInstructions_; }
			void SetOrderingInstruction(const GString& v) { orderingInstructions_ = v; }
			/// ��ϵ��λ���ơ�
			GString GetOrganizationName() const { return organizationName_; }
			void SetOrganizationName(const GString& v) { organizationName_ = v; };
			/// ��ϸ��ַ������λ�õ���ϸ��ַ������·�������ƺŵȡ�
			GString GetAddress() const { return address_; }
			void SetAddress(const GString& v) { address_ = v; }
			/// �绰���绰���롣
			GString GetPhone() const { return phone_; }
			void SetPhone(const GString& v) { phone_ = v; }
			/// �����ʼ���ַ������λ�ṩ���ݶ�������ĵ����ʼ���ַ��
			GString GetEMail() const { return eMail_; }
			void SetEMail(const GString& v) { eMail_ = v; }
			/// �������ơ��ַ����ṩ���ݼ��Ľ������ơ�
			GString GetMediumName() const { return mediumName_; }
			void SetMediumName(const GString& v) { mediumName_ = v; }
			/// ����˵�����ַ����ʼ�����ʽ����������˵����
			GString GetMediumNote() const { return mediumNote_; }
			void SetMediumNote(const GString& v) { mediumNote_ = v; }
			/// ʹ�����ơ�ʹ�����ݼ�ʱ�漰��˽Ȩ��֪ʶ��Ȩ�ı��������κ��ض���Լ�������ƻ�ע�����
			GString GetUseConstraints() const { return useConstraints_; }
			void SetUseConstraints(const GString& v) { useConstraints_ = v; }
			/// ��ȫ�ȼ������ڹ��Ұ�ȫ�����ܻ��������ǣ������ݼ���ȫ���Ƶ����ơ�
			GString GetSecurityClassification() const { return securityClassification_; }
			void SetSecurityClassification(const GString& v) { securityClassification_ = v; }

		private:
			// ������Ϣ
			GString onlineInformation_;
			// ����˵��
			GString orderingInstructions_;
			// ��ϵ��λ����
			GString organizationName_;
			// ��ϸ��ַ
			GString address_;
			// �绰
			GString phone_;
			// �����ʼ���ַ
			GString eMail_;
			// ��������
			GString mediumName_;
			// ����˵��
			GString mediumNote_;
			// ʹ������
			GString useConstraints_;
			// ��ȫ�ȼ�
			GString securityClassification_;
		};

	public:
		/// ���ݿ��¼ID
		int GetModelId() const;
		void SetModelId(int id);
		/// Ԫ���ݵ����ơ�
		GString GetTitle() const;
		void SetTitle(const GString& title);
		/// Ԫ���ݵķ�������
		tm GetDateStamp() const;
		void SetDateStamp(const tm& t);
		/// Ԫ����ʹ�õ�����
		GString GetLanguage() const;
		void SetLanguage(const GString& lan);
		/// Ԫ���ݲ��õ��ַ������׼
		GString GetCharSet() const;
		void SetCharSet(const GString& charSet);
		/// ִ�е�Ԫ���ݱ�׼����
		GString GetStandardName() const;
		void SetStandardName(const GString& name);
		/// ��ʶ��Ϣ
		const MDIdentification& GetIdentification() const;
		MDIdentification& GetIdentification();
		/// ������Ϣ
		const MDContent& GetContent() const;
		MDContent& GetContent();
		/// ģ��������Ϣ
		const MQModelQuality& GetQualityInfo() const;
		MQModelQuality& GetQualityInfo();
		/// �ռ����ϵ��Ϣ
		const RSReferenceSystem& GetSRS() const;
		RSReferenceSystem& GetSRS();
		/// �ַ���Ϣ
		const MDDistribution& GetDistributionInfo() const;
		MDDistribution& GetDistributionInfo();

	private:
		// ���ݿ��¼��ID��
		int id_;
		// Ԫ���ݵ�����
		GString metadataTitle_;
		// Ԫ���ݵķ�������
		tm dateStamp_;
		// Ԫ����ʹ�õ�����
		GString language_;
		// Ԫ���ݲ��õ��ַ������׼
		GString characterSet_;
		// ִ�е�Ԫ���ݱ�׼����
		GString metadataStandardName_;
		// ��ʶ��Ϣ
		MDIdentification identification_;
		// ������Ϣ
		MDContent content_;
		// ģ��������Ϣ
		MQModelQuality qualitiy_;
		// �ռ����ϵ��Ϣ
		RSReferenceSystem srs_;
		// �ַ���Ϣ
		MDDistribution distribution_;
	};
}

