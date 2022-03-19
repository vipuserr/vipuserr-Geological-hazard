#pragma once
#include "s3dqtapp_global.h"
#include <string>

#include "qgspallabeling.h"
#include "qgsvectorlayerlabeling.h"
#include "qgsrulebasedlabeling.h"

using namespace std;

enum S3dmRenderUnit
{
	RenderMillimeters = 0, //����
	RenderMapUnits, //��ͼ��λ
	RenderPixels, //����
	RenderPercentage, //�ٷֱ�
	RenderPoints, //��
	RenderInches, //Ӣ��
	RenderUnknownUnit, //!< Mixed or unknown units
	RenderMetersInMapUnits, //������
};

class S3DQTAPP_EXPORT LabelSettings
{
public:
	LabelSettings();

	//������ʾ���ֶ�
	void setField(string fieldName);
	//���ô�С
	void setSize(double size);
	double getSize();
	//���ô�С��λ
	void setSizeUnit(S3dmRenderUnit unit);
	//��������
	void setFont(const QFont& font);
	//����ƫ��
	void setOffset(double offsetX, double offsetY);
	//����ƫ�Ƶ�λ
	void setOffsetUnit(S3dmRenderUnit unit);
	//���û����ַ�
	void setWrapChar(string ch);
	//����������ʾ����
	void setOrientation(QgsTextFormat::TextOrientation);
	//����ע��λ��
	void setPlaceMent();

	QgsPalLayerSettings* settings() { return &m_labelSettings; };
private:
	QgsPalLayerSettings m_labelSettings;
};

class S3DQTAPP_EXPORT RuleLabelSettings
{
public:
	LabelSettings   m_Settings;
	//���˹��򣺽��ṩ �ֶ� = value ����ʽ����   "\"type\" = '11'"
	string			m_filterField;//�����ֶ�
	string			m_filterValue;//����ֵ
};

class S3DQTAPP_EXPORT S3dmLables
{
public:

	S3dmLables();
	virtual ~S3dmLables();
	
	//����ע�����ͣ���һע�ǻ��ǹ���ע��
	void setType(int type) { m_Type = type; };
	int getType() { return m_Type; };

	//������ʾ����
	void setHide(bool hide) { m_Hide = hide; };
	bool getHide() { return m_Hide; };

	//���õ�һע�ǣ���ͬһͼ�������Ҫ��ʹ��ͬһ��ע��
	void setSimpleLabel(LabelSettings* settings) { m_SimpleLabelSetting = *settings; };

	//���ù���ע�ǣ������ݹ����Ҫ�����ò�ͬ��ע��
	void setRuleLabel(QList<RuleLabelSettings>* settings) { m_RuleLabelSetting = *settings; };
	//��ӹ���ע��
	void addRuleLabel(RuleLabelSettings* label);
	//ɾ��ע��
	void deleteRuleLabel(int index);
	//��ȡע��
	const RuleLabelSettings* getRule(int index) { return &(m_RuleLabelSetting.at(index)); };
	//��ȡ����ע��
	QList<RuleLabelSettings>* getRuLes() { return &m_RuleLabelSetting; };


	//���ص�һע����ʽ
	QgsVectorLayerSimpleLabeling* getSimpleLabel();
	//���ع�����ʽ
	QgsRuleBasedLabeling*	getRuleLabel();

	void test();

private:
	//��һ��ע
	LabelSettings m_SimpleLabelSetting;
	//�����ע
	QList<RuleLabelSettings> m_RuleLabelSetting;

	QgsVectorLayerSimpleLabeling*	m_SimpleLabel;
	QgsRuleBasedLabeling*			m_RuleLabel;

	bool				m_Hide; //ע���Ƿ���ʾ����
	int					m_Type; //ע�����ͣ�0-��һע��  1-����ע��
};

