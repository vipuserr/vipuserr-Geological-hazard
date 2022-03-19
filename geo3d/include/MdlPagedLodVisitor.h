#pragma once

#ifndef _PagedLodVisitor_CLASS__
#define _PagedLodVisitor_CLASS__

//Lod�ڵ�����������ڸ��ڵ��ȡgmeMdl*�����lod�ڵ���

#include <osg/NodeVisitor>
#include "gmeEntity.h"

class OG_FRAME_DLL MdlPagedLodVisitor : public osg::NodeVisitor
{
public:
	MdlPagedLodVisitor(const std::string& strUrl = "");
	~MdlPagedLodVisitor();

	virtual void apply(osg::PagedLOD& plod);

	//����geode�ڵ�
	void CvtGmeMdlGroup(osg::PagedLOD& plod, std::vector<std::string>& vecNo, osg::Vec3 offset);

	//��ȡ����������url
	bool ProGetEligibleUrl(osg::PagedLOD& plod, vector<std::string>& vecNo, osg::Vec3 offset);

	void SetOperateType(int iNoType = 0);
	void SetCurEyePos(osg::Vec3d eyePos);        //��ǰeye��λ��
	void SetFrustumBox(gme_rect_3d frustumBox);  //��׶�巶Χ

	osg::ref_ptr<osg::Geode>& GetPagedLodGeode();

public: //0
	std::vector<std::string>& GetPagedLodUrl();

protected:
	/* 0 ��ȡ�ýڵ���PagedLod ����������url
	 * 1 ����geode�ڵ�
	 */
	int m_OperaType;

	osg::ref_ptr<osg::Geode> m_lodGeode;
	std::string m_fileUrl;
	osg::Vec3 m_offset;

	int m_CurrentLevel;  //��ǰ�ڵ�㼶

	gme_rect_3d m_frustumBox;  //��׶�巶Χ
	osg::Vec3d m_curEyePos;    //��ǰ�ӵ��λ��
	std::list<std::pair<std::string, gme_vector2f>> m_LodInfoList;  //lodUrl+range

	std::vector<gme_vector2f> m_vecLodRange;


protected: //0
	std::vector<std::string> m_vecLodUrl;

};

#endif