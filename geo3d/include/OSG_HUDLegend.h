#pragma once

#ifndef _osgHUDLegend_CLASS__
#define _osgHUDLegend_CLASS__

#include "OGBasDef.h"
#include "OSG_Text.h"
#include <osg/ImageUtils>

//��״ͼ��
class OG_FRAME_DLL OSG_CHUDBlockLegend :public osg::Referenced
{
public:
	OSG_CHUDBlockLegend();
	~OSG_CHUDBlockLegend();

	const int getBlockNum();
	void setBlockNum(int num);

	const int getWidth();
	void setWidth(int width);

	const int getHeight();
	void setHeight(int height);

	const int getScreenWidth();
	void setScreenWidth(int width);

	const int getScreenHeight();
	void setScreenHeight(int height);

	const RECT getLegendBBOX();
	void setLegendBox(RECT box);

	void setTitle(sTextInfo title);
public:
	osg::ref_ptr<osg::Texture2D> createTexture2D(osg::ref_ptr<osg::Image> image);
	osg::ref_ptr<osg::Geode> createALegendGeode(int index);
	osg::ref_ptr<osg::Group> createLegendGroup();
	osg::ref_ptr<osg::Camera> createHUDCamera();//�������ɿ�״ͼ��

public:
	sTextInfo			   m_title;
	osg::ImageList		   m_imageList;
	std::vector<sTextInfo> m_textArray;
	std::vector<osg::Vec4> m_colorArray;
	std::vector<osg::Vec2> m_startPointArray;
	
private:
	RECT m_bbox;
	int	 m_BlockNum;//ͼ����ĸ���
	int	 m_width;
	int	 m_height;
	int	 m_screenWidth;
	int	 m_screenHeight;
};


//����״ͼ��
class OG_FRAME_DLL OSG_CHUDLineLegend :public osg::Referenced
{
public:
	OSG_CHUDLineLegend();
	~OSG_CHUDLineLegend();

	int getColorNum();
	void setColorNum(int num);

	int getLabelNum();
	void setLabelNum(int num);

	bool getIsVertical();
	void setIsVertical(bool isVertical);

	std::string getstrTitle();
	void setstrTitle(std::string title);

	const wchar_t* getWstrTitle();
	void setWstrTitle(wchar_t* title);

	float getMinValue();
	void setMinValue(float minValue);

	float getMaxValue();
	void setMaxValue(float maxValue);

	const std::vector<osg::Vec4>& getColorArray();
	void setColorArray(const std::vector<osg::Vec4>& colorArray);

	const std::vector<std::wstring>& getVecNumMark() { return m_vecNumMark; }
	void setVecNumMark(const std::vector<std::wstring>& vecNumMark) { m_vecNumMark = vecNumMark; }

	const float getRatio() { return m_fRatio; }
	void setRatio(float ratio) { m_fRatio = ratio; }

	const float getTextSize() { return m_fTextSize; }
	void setTextSize(float size) { m_fTextSize = size; }

	const osg::Vec4 getTextColor() { return m_textColor; }
	void setTextColor(osg::Vec4 color) { m_textColor = color; }

	const int getScreenWidth() { return m_iScreenWidth; }
	void setScreenWidth(int width) { m_iScreenWidth = width; }

	const int getScreenHeight() { return m_iScreenHeight; }
	void setScreenHeight(int height) { m_iScreenHeight = height; }

	const osg::Vec2 getPositionXY() { return m_positionXY; }
	void setPositionXY(osg::Vec2 position) { m_positionXY = position; }

	osg::ref_ptr<osg::Group> generateHUDLineLegend();
	
private:
	int m_iColorNum;		//��ɫ��
	int m_iLabelNum;		//�����
	int m_iScreenWidth;		//��Ļ�Ŀ��
	int m_iScreenHeight;	//��Ļ�ĸ߶�

	float m_fminValue;		//�����Сֵ
	float m_fMaxValue;		//������ֵ
	float m_fRatio;			//��߱�
	float m_fTextSize;		//ע�Ǵ�С

	bool m_bIsVertical;		//�Ƿ�ֱ��ʾ
	wchar_t* m_wstrTitle;	//ͼ������(֧������)
	std::string m_strTitle;	//ͼ������
	
	osg::Vec4 m_textColor;	//ע����ɫ
	osg::Vec2 m_positionXY;	//��״ͼ����λ��

	std::vector<osg::Vec4> m_colorArray;	//ɫ��
	std::vector<std::wstring> m_vecNumMark;	//�̶ȳ��ϵĿ̶�ֵ
};

/*
//ͼ������
struct OG_FRAME_DLL ScalarBarParam
{
	int iColorNum;		//��ɫ��
	int iLabelNum;		//�����
	int iScreenWidth;	//��Ļ�Ŀ��
	int iScreenHeight;	//��Ļ�ĸ߶�

	float fminValue;	//�����Сֵ
	float fMaxValue;	//������ֵ
	float fyxRatio;		//��߱�
	float fTextSize;	//ע�Ǵ�С

	bool bIsVertical;		//�Ƿ�ֱ��ʾ
	wchar_t* wstrTitle;	    //ͼ������(֧������)
	std::string strTitle;	//ͼ������

	osg::Vec4 textColor;	//ע����ɫ
	osg::Vec2 positionXY;	//��״ͼ����λ��

	std::vector<osg::Vec4> colorArray;	//ɫ��
	std::vector<std::wstring> vecNumMark;	//�̶ȳ��ϵĿ̶�ֵ

	ScalarBarParam()
	{
		iColorNum = 10;
		iLabelNum = 6;
		bIsVertical = false;
		if (bIsVertical)
		{
			positionXY.set(1300, 10);
		}
		else
		{
			positionXY.set(120, 10);
		}
		wstrTitle = L"";
		fminValue = 0.0f;
		fMaxValue = 1.0f;
		colorArray.clear();
		vecNumMark.clear();
		fyxRatio = 0.05f;
		fTextSize = 0.0f;
		textColor = osg::Vec4(1.0f, 1.0f, 1.0f, 1.0f);
	}
};
*/



#endif