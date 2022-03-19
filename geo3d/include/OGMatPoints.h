 #pragma once

#include "OGBasDef.h"
#include <osg/Vec3>
#include <osg/Vec4>
#include <string>
#include <osg/ref_ptr>
#include <osg/Group>
#include <vector>
#include <osgText/Text>

using namespace osg;

class OG_FRAME_DLL Points
{
public:
	enum NoteType
	{
		NT_NORMAL = 0,
		NT_UP = 1,
		NT_DOWN = 2
	};

	struct Note
	{
		NoteType type;
		//std::string text;
		std::string text;
		Note & operator=(const Note &n)
		{
			type = n.type;
			text = n.text;

			return *this;
		}
	};

	struct WNote
	{
		NoteType type;
		//std::string text;
		std::wstring text;
		WNote & operator=(const WNote &n)
		{
			type = n.type;
			text = n.text;

			return *this;
		}
	};

public:
	Points(void);
	~Points(void);

	// 点图形设置
	void SetWidth(float width);
	void SetPointMaterial(std::string matName);

	// 坐标位置
	void SetPosition(int num, Vec3* posList);

	// 注记设置
	void SetFontType(std::string fontType);
	void SetCharacterSize(float normalSize, float upSize, float downSize);
	void SetTextRotationDegree(float rotDegree);
	void SetTextColor(osg::Vec4 color);
	void SetTextBackdropColor(osg::Vec4 outColor);
	void SetDrawModeMask(unsigned int drawmode);
	void SetTexts(std::vector<std::string>& textList);
	void SetTexts(std::vector<std::wstring>& textList);

	// 显示点图形及注记
	osg::ref_ptr<osg::Group> Show(bool bPic, bool bText);

protected:
	// 解析文本文件
	void ParseSingleNote(std::string text, Note& note, bool& end, std::string& nextText,Note& nextNote);
	void ParseSingleNote(std::wstring text, WNote& note, bool& end, std::wstring& nextText, WNote& nextNote);
	//osg::ref_ptr<osg::Geode> ShowText(std::vector<Note>& textList, Vec3 startPos, float radious);
	osg::ref_ptr<osg::Geode> ParseText(std::string text, osg::Vec3& startPos, float radious);
    osg::ref_ptr<osg::Geode> ParseText(std::wstring text, osg::Vec3& startPos, float radious);

	osg::ref_ptr<osg::Geode> ShowMultiText(std::vector<Note>& textList, Vec3 startPos, float radious);
	osg::ref_ptr<osg::Geode> ShowMultiText(std::vector<WNote>& textList, Vec3 startPos, float radious);

	//osg::ref_ptr<osg::Group> showPointWithMat();
	osg::Drawable* createSquareGeo(const osg::Vec3& corner);
protected:
	float m_width;
	int m_num;
	Vec3* m_posList;
	Vec3 m_offset;
	std::string m_matName;

	std::string m_fontType;
	float m_normalSize;
	float m_upSize;
	float m_downSize;
	float m_rotDegree;
	osg::Vec4 m_textColor;
	bool m_bDrawOuterColor;
	osg::Vec4 m_textOuterColor;
	bool m_bDrawBB;
	unsigned int m_drawMode;
	std::vector<std::string> m_textList;
	std::vector<std::wstring> m_wtextList;
	//std::vector<wchar_t*> m_wcharTextList;
	std::vector<osg::ref_ptr<Geode>> m_NoteGeodeList;
	std::vector<osg::ref_ptr<osgText::Text>> m_noteTextList;

};


