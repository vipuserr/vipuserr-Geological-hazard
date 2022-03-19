#pragma once
#include "s3dqtapp_global.h"
#include <string>

#include "qgspallabeling.h"
#include "qgsvectorlayerlabeling.h"
#include "qgsrulebasedlabeling.h"

namespace Smart3dMap
{

	//��һע������
	class S3DQTAPP_EXPORT SimpleLabelAttr
	{
	public:
		std::string						fieldName;//��ʾ�ֶ�
		double							size;//��С
		QgsUnitTypes::RenderUnit		sizeUnit;//��С��λ
		QColor							clr;//��ɫ
		QFont							font;//����
		double							offsetX;//ƫ��x
		double							offsetY;//ƫ��y
		QgsUnitTypes::RenderUnit		offsetUnit;//ƫ�Ƶ�λ
		QgsTextFormat::TextOrientation  textOrient;//������ʾ����
		bool							centroidWhole;//�ڷ�Χ����ʾ
		std::string						wrapChar;//�����ַ�

		SimpleLabelAttr()
		{
			fieldName = "";
			size = 2;
			sizeUnit = QgsUnitTypes::RenderUnit::RenderMillimeters;
			clr = QColor(0, 0, 0);
			font = QFont(QStringLiteral("Times"));
			offsetX = 0;
			offsetY = 0;
			offsetUnit = QgsUnitTypes::RenderUnit::RenderMillimeters;
			textOrient = QgsTextFormat::TextOrientation::HorizontalOrientation;
			centroidWhole = true;
			wrapChar = "\n";
		}


	};

	//����ע������
	class S3DQTAPP_EXPORT RuleLabelAttr
	{
	public:
		SimpleLabelAttr   m_Settings;
		//���˹��򣺽��ṩ �ֶ� = value ����ʽ����   "\"type\" = '11'"
		std::string			m_filterField;//�����ֶ�
		QVariant		m_filterValue;//����ֵ��Int��LongLong��Double��String��Date
	};



	//ע����
	class S3DQTAPP_EXPORT S3dmLabels
	{
	public:
		enum S3dmLabelType
		{
			SimpleLabel = 0,
			RuleLabel = 1
		};
	public:

		S3dmLabels();
		virtual ~S3dmLabels();

		S3dmLabels(const S3dmLabels& label);
		S3dmLabels& operator=(const S3dmLabels& label);


		//����ע�����ͣ���һע�ǻ��ǹ���ע��
		void setType(S3dmLabelType type) { m_Type = type; }
		S3dmLabelType getType() { return m_Type; }


		//������ʾ����
		void setHide(bool hide) { m_Hide = hide; }
		bool getHide() { return m_Hide; }


		//���õ�һע�ǣ���ͬһͼ�������Ҫ��ʹ��ͬһ��ע��
		void setSimpleLabel(SimpleLabelAttr& attr);
		SimpleLabelAttr& getSimpleLabel() { return m_SimpleLabelAttr; }


		//���ù���ע�ǣ������ݹ����Ҫ�����ò�ͬ��ע��
		void setRuleLabel(QList<RuleLabelAttr>& attrs);
		//��ȡ����ע��
		QList<RuleLabelAttr>& getRuLes() { return m_RuleLabelAttrs; };




	private:
		friend class S3dmVectorLayer;

		//����QGS��һע����ʽ
		QgsVectorLayerSimpleLabeling* getQgsSimpleLabel();
		//����QGS������ʽ
		QgsRuleBasedLabeling*	getQgsRuleLabel();

		void LabelAttr2QgsSettings(SimpleLabelAttr& attr, QgsPalLayerSettings& qgsSetting);

		//��һ��ע
		SimpleLabelAttr				    m_SimpleLabelAttr;
		//�����ע
		QList<RuleLabelAttr>			m_RuleLabelAttrs;

		bool							m_Hide; //ע���Ƿ���ʾ����
		S3dmLabelType					m_Type; //ע������
	};


}
