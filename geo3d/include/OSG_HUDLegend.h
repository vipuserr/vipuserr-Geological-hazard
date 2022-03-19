#pragma once

#ifndef _osgHUDLegend_CLASS__
#define _osgHUDLegend_CLASS__

#include "OGBasDef.h"
#include "OSG_Text.h"
#include <osg/ImageUtils>

//块状图例
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
	osg::ref_ptr<osg::Camera> createHUDCamera();//最终生成块状图例

public:
	sTextInfo			   m_title;
	osg::ImageList		   m_imageList;
	std::vector<sTextInfo> m_textArray;
	std::vector<osg::Vec4> m_colorArray;
	std::vector<osg::Vec2> m_startPointArray;
	
private:
	RECT m_bbox;
	int	 m_BlockNum;//图例块的个数
	int	 m_width;
	int	 m_height;
	int	 m_screenWidth;
	int	 m_screenHeight;
};


//条带状图例
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
	int m_iColorNum;		//颜色数
	int m_iLabelNum;		//标尺数
	int m_iScreenWidth;		//屏幕的宽度
	int m_iScreenHeight;	//屏幕的高度

	float m_fminValue;		//标尺最小值
	float m_fMaxValue;		//标尺最大值
	float m_fRatio;			//宽高比
	float m_fTextSize;		//注记大小

	bool m_bIsVertical;		//是否垂直显示
	wchar_t* m_wstrTitle;	//图例标题(支持中文)
	std::string m_strTitle;	//图例标题
	
	osg::Vec4 m_textColor;	//注记颜色
	osg::Vec2 m_positionXY;	//条状图例的位置

	std::vector<osg::Vec4> m_colorArray;	//色表
	std::vector<std::wstring> m_vecNumMark;	//刻度尺上的刻度值
};

/*
//图例参数
struct OG_FRAME_DLL ScalarBarParam
{
	int iColorNum;		//颜色数
	int iLabelNum;		//标尺数
	int iScreenWidth;	//屏幕的宽度
	int iScreenHeight;	//屏幕的高度

	float fminValue;	//标尺最小值
	float fMaxValue;	//标尺最大值
	float fyxRatio;		//宽高比
	float fTextSize;	//注记大小

	bool bIsVertical;		//是否垂直显示
	wchar_t* wstrTitle;	    //图例标题(支持中文)
	std::string strTitle;	//图例标题

	osg::Vec4 textColor;	//注记颜色
	osg::Vec2 positionXY;	//条状图例的位置

	std::vector<osg::Vec4> colorArray;	//色表
	std::vector<std::wstring> vecNumMark;	//刻度尺上的刻度值

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