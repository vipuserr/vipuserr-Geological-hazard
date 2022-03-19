 #pragma once
#include <osg/ref_ptr>
#include <osg/Geode>
#include <osg/Vec3>
#include <osg/Vec4>
#include <osg/Material>
using namespace osg;

#include "OGBasDef.h"

class OG_FRAME_DLL LineSign
{
public:
	LineSign(void);
	~LineSign(void);

	enum LineType
	{
		LT_LINE = 1,
		LT_TRIPYRAMID = 2,
		LT_RECTPYRAMID = 3,
		LT_PIPE = 4,
		LT_TEXTURE = 5
	};

	enum LineShape
	{
		LS_SOLID = 1,
		LS_POINT = 2,
		LS_DOTTEDLINE = 3,
	};

	void SetColor(Vec4 col); 
	void SetLineShape(LineShape lineShape);
	void SetPosition(int number, Vec3* posList);
	void SetTexture(std::string textureName);
	void SetLineStripple(int factor, unsigned short pattern);
	osg::Geode* Show(LineType type=LT_LINE, float width=1);

protected:
	osg::Geode* ShowLine();
    osg::ref_ptr<osg::Geode> ShowTriPyramidLine();
	osg::ref_ptr<osg::Geode> ShowRectPyramidLine();
	osg::ref_ptr<osg::Geode> ShowPipeLine();
	osg::ref_ptr<osg::Geode> ShowTextureLine();
	osg::ref_ptr<osg::Geode> ShowAxis();

private:
	Vec4 m_col;
	LineShape m_lineShape;
	LineType m_lineType;
	float m_width;
	int m_num;
	Vec3* m_pPosList;
	std::string m_textName;
	int m_factor;
	unsigned short m_pattern;

	//Material* m_pMaterial;


};
