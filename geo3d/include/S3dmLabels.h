#pragma once
#include "s3dqtapp_global.h"
#include <string>

#include "qgspallabeling.h"
#include "qgsvectorlayerlabeling.h"
#include "qgsrulebasedlabeling.h"

namespace Smart3dMap
{

	//单一注记属性
	class S3DQTAPP_EXPORT SimpleLabelAttr
	{
	public:
		std::string						fieldName;//显示字段
		double							size;//大小
		QgsUnitTypes::RenderUnit		sizeUnit;//大小单位
		QColor							clr;//颜色
		QFont							font;//字体
		double							offsetX;//偏移x
		double							offsetY;//偏移y
		QgsUnitTypes::RenderUnit		offsetUnit;//偏移单位
		QgsTextFormat::TextOrientation  textOrient;//文字显示方向
		bool							centroidWhole;//在范围内显示
		std::string						wrapChar;//换行字符

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

	//规则注记属性
	class S3DQTAPP_EXPORT RuleLabelAttr
	{
	public:
		SimpleLabelAttr   m_Settings;
		//过滤规则：仅提供 字段 = value 的形式，如   "\"type\" = '11'"
		std::string			m_filterField;//过滤字段
		QVariant		m_filterValue;//过滤值：Int、LongLong、Double、String、Date
	};



	//注记类
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


		//设置注记类型：单一注记还是规则注记
		void setType(S3dmLabelType type) { m_Type = type; }
		S3dmLabelType getType() { return m_Type; }


		//设置显示隐藏
		void setHide(bool hide) { m_Hide = hide; }
		bool getHide() { return m_Hide; }


		//设置单一注记，即同一图层的所有要素使用同一个注记
		void setSimpleLabel(SimpleLabelAttr& attr);
		SimpleLabelAttr& getSimpleLabel() { return m_SimpleLabelAttr; }


		//设置规则注记，即根据规则对要素设置不同的注记
		void setRuleLabel(QList<RuleLabelAttr>& attrs);
		//获取规则注记
		QList<RuleLabelAttr>& getRuLes() { return m_RuleLabelAttrs; };




	private:
		friend class S3dmVectorLayer;

		//返回QGS单一注记样式
		QgsVectorLayerSimpleLabeling* getQgsSimpleLabel();
		//返回QGS规则样式
		QgsRuleBasedLabeling*	getQgsRuleLabel();

		void LabelAttr2QgsSettings(SimpleLabelAttr& attr, QgsPalLayerSettings& qgsSetting);

		//单一标注
		SimpleLabelAttr				    m_SimpleLabelAttr;
		//规则标注
		QList<RuleLabelAttr>			m_RuleLabelAttrs;

		bool							m_Hide; //注记是否显示隐藏
		S3dmLabelType					m_Type; //注记类型
	};


}
