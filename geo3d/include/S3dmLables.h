#pragma once
#include "s3dqtapp_global.h"
#include <string>

#include "qgspallabeling.h"
#include "qgsvectorlayerlabeling.h"
#include "qgsrulebasedlabeling.h"

using namespace std;

enum S3dmRenderUnit
{
	RenderMillimeters = 0, //毫米
	RenderMapUnits, //地图单位
	RenderPixels, //像素
	RenderPercentage, //百分比
	RenderPoints, //点
	RenderInches, //英寸
	RenderUnknownUnit, //!< Mixed or unknown units
	RenderMetersInMapUnits, //比例尺
};

class S3DQTAPP_EXPORT LabelSettings
{
public:
	LabelSettings();

	//设置显示的字段
	void setField(string fieldName);
	//设置大小
	void setSize(double size);
	double getSize();
	//设置大小单位
	void setSizeUnit(S3dmRenderUnit unit);
	//设置字体
	void setFont(const QFont& font);
	//设置偏移
	void setOffset(double offsetX, double offsetY);
	//设置偏移单位
	void setOffsetUnit(S3dmRenderUnit unit);
	//设置换行字符
	void setWrapChar(string ch);
	//设置文字显示方向
	void setOrientation(QgsTextFormat::TextOrientation);
	//设置注记位置
	void setPlaceMent();

	QgsPalLayerSettings* settings() { return &m_labelSettings; };
private:
	QgsPalLayerSettings m_labelSettings;
};

class S3DQTAPP_EXPORT RuleLabelSettings
{
public:
	LabelSettings   m_Settings;
	//过滤规则：仅提供 字段 = value 的形式，如   "\"type\" = '11'"
	string			m_filterField;//过滤字段
	string			m_filterValue;//过滤值
};

class S3DQTAPP_EXPORT S3dmLables
{
public:

	S3dmLables();
	virtual ~S3dmLables();
	
	//设置注记类型：单一注记还是规则注记
	void setType(int type) { m_Type = type; };
	int getType() { return m_Type; };

	//设置显示隐藏
	void setHide(bool hide) { m_Hide = hide; };
	bool getHide() { return m_Hide; };

	//设置单一注记，即同一图层的所有要素使用同一个注记
	void setSimpleLabel(LabelSettings* settings) { m_SimpleLabelSetting = *settings; };

	//设置规则注记，即根据规则对要素设置不同的注记
	void setRuleLabel(QList<RuleLabelSettings>* settings) { m_RuleLabelSetting = *settings; };
	//添加规则注记
	void addRuleLabel(RuleLabelSettings* label);
	//删除注记
	void deleteRuleLabel(int index);
	//获取注记
	const RuleLabelSettings* getRule(int index) { return &(m_RuleLabelSetting.at(index)); };
	//获取所有注记
	QList<RuleLabelSettings>* getRuLes() { return &m_RuleLabelSetting; };


	//返回单一注记样式
	QgsVectorLayerSimpleLabeling* getSimpleLabel();
	//返回规则样式
	QgsRuleBasedLabeling*	getRuleLabel();

	void test();

private:
	//单一标注
	LabelSettings m_SimpleLabelSetting;
	//规则标注
	QList<RuleLabelSettings> m_RuleLabelSetting;

	QgsVectorLayerSimpleLabeling*	m_SimpleLabel;
	QgsRuleBasedLabeling*			m_RuleLabel;

	bool				m_Hide; //注记是否显示隐藏
	int					m_Type; //注记类型：0-单一注记  1-规则注记
};

