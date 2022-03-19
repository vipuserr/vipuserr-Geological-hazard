#pragma once

#ifndef _osgViewerScalarBar_CLASS__
#define _osgViewerScalarBar_CLASS__

#include "OGBasDef.h"
#include "OSG_Text.h"

#include <osgSim/ScalarBar>
#include <osgSim/ScalarsToColors>
#include <osgSim/ColorRange>

/**
 * ������״ͼ�����Ƶ���
 * ��osgԴ��osgSim::ScalarBar��Ļ����ϣ�������֧������title���Զ���̶ȳ�Ҫ��ʾ�Ŀ̶�ֵ*/

class OG_FRAME_DLL OSGViewScalarBar :public osg::Geode
{
public:
	enum Orientation
	{
		HORIZONTAL,
		VERTICAL
	};

	struct ScalarPrinter : public osg::Referenced
	{
		virtual std::string printScalar(float scalar);
	};

	OSGViewScalarBar();

	OSGViewScalarBar(int numColors, int numLabels,
		std::vector<std::wstring> numberMark,
		osgSim::ScalarsToColors* stc,
		const std::wstring& wt,
		Orientation orientation = HORIZONTAL,
		float aspectRatio = 0.25,
		ScalarPrinter* sp = new ScalarPrinter);


	OSGViewScalarBar(const OSGViewScalarBar& rhs, const osg::CopyOp& co);

	void setTextProperties(const TextProperties& tp);
	
	const TextProperties& getTextProperties() const;
	
	void update();

protected:
	virtual ~OSGViewScalarBar();
	
	void createDrawables();//����ı����߻��ƺ���

	int m_numColors;
	int m_numLabels;
	
	float m_width;
	float m_aspectRatio;

	osg::Vec3    m_position;
	std::wstring m_wtitle;  //֧������

	Orientation		m_orientation;
	TextProperties  m_textProperties;
	
	osg::ref_ptr<ScalarPrinter> m_sp;
	osg::ref_ptr<osgSim::ScalarsToColors> m_stc;
	
	//�����osgSim::ScalarBarԴ�����ӵĲ��֣������Զ���̶ȳ��ϵĿ̶�ֵ
	std::vector<std::wstring>   m_vecNumWStringMark;
};

#endif