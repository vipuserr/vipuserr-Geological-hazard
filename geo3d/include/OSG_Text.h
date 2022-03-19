#pragma once

#ifndef _osgText_CLASS__
#define _osgText_CLASS__

#include "OGBasDef.h"
#include <osgText/TextBase>

/* ������
 *	1���ı����Խṹ��
 *  2�����ֽṹ��
 */
namespace Smart3dMap
{
	//�ı�����
	struct OG_FRAME_DLL TextProperties
	{
		std::string          fontFile;        //�����ļ�
		std::pair<int, int>  fontResolution;  //����ֱ���
		float                characterSize;	  //�ַ���С
		osg::Vec4            color;			  //������ɫ

		TextProperties() :
			fontFile("simhei.ttf"),
			fontResolution(40, 40),
			characterSize(0.0f),
			color(1.0f, 1.0f, 1.0f, 1.0f)
		{
		}
	};

	//���ֽṹ�壬���ڻ�����ά����
	struct OG_FRAME_DLL sTextInfo
	{
		enum Text_type
		{
			WORLD_TEXT = 0x1000,
			TEXTURE_TEXT
		};

		Text_type		type;										//��������
		std::string		font;										//����
		std::string		strContent;									//����
		const wchar_t*	wchContent;									//����
		float			characterSize;								//���ָ߶�
		float			aspectRatio;								//���ָ߿��
		bool			autoRotateToScreen;							//�Զ�������Ļ
		osg::Vec4		color;										//��ɫ
		osg::Vec2		positionXY;									//HUD���ֶ�άλ��
		osg::Vec3		positionXYZ;								//������������άλ��
		std::pair<int, int>  fontResolution;						//����ֱ���(���)
		osgText::TextBase::Layout enLayerOut;						//���������ʽ
		osgText::TextBase::CharacterSizeMode enCharacterSizeMode;	//���ִ�Сģʽ
		osgText::TextBase::AlignmentType alignmentType;				//��������
		osgText::TextBase::AxisAlignment enAxisAlignment;			//���ַ���

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