#pragma once

#ifndef _osgText_CLASS__
#define _osgText_CLASS__

#include "OGBasDef.h"
#include <osgText/TextBase>

/* 包括：
 *	1、文本属性结构体
 *  2、文字结构体
 */
namespace Smart3dMap
{
	//文本属性
	struct OG_FRAME_DLL TextProperties
	{
		std::string          fontFile;        //字体文件
		std::pair<int, int>  fontResolution;  //字体分辨率
		float                characterSize;	  //字符大小
		osg::Vec4            color;			  //字体颜色

		TextProperties() :
			fontFile("simhei.ttf"),
			fontResolution(40, 40),
			characterSize(0.0f),
			color(1.0f, 1.0f, 1.0f, 1.0f)
		{
		}
	};

	//文字结构体，用于绘制三维文字
	struct OG_FRAME_DLL sTextInfo
	{
		enum Text_type
		{
			WORLD_TEXT = 0x1000,
			TEXTURE_TEXT
		};

		Text_type		type;										//文字类型
		std::string		font;										//字体
		std::string		strContent;									//内容
		const wchar_t*	wchContent;									//内容
		float			characterSize;								//文字高度
		float			aspectRatio;								//文字高宽比
		bool			autoRotateToScreen;							//自动朝向屏幕
		osg::Vec4		color;										//颜色
		osg::Vec2		positionXY;									//HUD文字二维位置
		osg::Vec3		positionXYZ;								//世界中文字三维位置
		std::pair<int, int>  fontResolution;						//字体分辨率(宽高)
		osgText::TextBase::Layout enLayerOut;						//文字输出格式
		osgText::TextBase::CharacterSizeMode enCharacterSizeMode;	//文字大小模式
		osgText::TextBase::AlignmentType alignmentType;				//对齐类型
		osgText::TextBase::AxisAlignment enAxisAlignment;			//文字方向

		osg::ref_ptr<osg::Drawable> createText();

		sTextInfo() :
			type(WORLD_TEXT),
			font("simhei.ttf"),
			strContent(""),
			wchContent(L""),
			characterSize(1.0f),
			aspectRatio(1.0f),
			autoRotateToScreen(true),
			color(1.0f, 0.0f, 0.0f, 1.0f),
			positionXY(0.0f, 0.0f),
			positionXYZ(0.0f, 0.0f, 0.0f),
			fontResolution(500, 500),
			enLayerOut(osgText::TextBase::LEFT_TO_RIGHT),
			enCharacterSizeMode(osgText::TextBase::OBJECT_COORDS),
			alignmentType(osgText::TextBase::BASE_LINE),
			enAxisAlignment(osgText::TextBase::SCREEN)
		{
		}
	};
}

#endif