#pragma once

#ifndef _PagedLodVisitor_CLASS__
#define _PagedLodVisitor_CLASS__

//Lod节点访问器，用于根节点获取gmeMdl*添加至lod节点中

#include <osg/NodeVisitor>
#include "gmeEntity.h"

class OG_FRAME_DLL MdlPagedLodVisitor : public osg::NodeVisitor
{
public:
	MdlPagedLodVisitor(const std::string& strUrl = "");
	~MdlPagedLodVisitor();

	virtual void apply(osg::PagedLOD& plod);

	//构建geode节点
	void CvtGmeMdlGroup(osg::PagedLOD& plod, std::vector<std::string>& vecNo, osg::Vec3 offset);

	//获取符合条件的url
	bool ProGetEligibleUrl(osg::PagedLOD& plod, vector<std::string>& vecNo, osg::Vec3 offset);

	void SetOperateType(int iNoType = 0);
	void SetCurEyePos(osg::Vec3d eyePos);        //当前eye的位置
	void SetFrustumBox(gme_rect_3d frustumBox);  //视锥体范围

	osg::ref_ptr<osg::Geode>& GetPagedLodGeode();

public: //0
	std::vector<std::string>& GetPagedLodUrl();

protected:
	/* 0 获取该节点下PagedLod 符合条件的url
	 * 1 构建geode节点
	 */
	int m_OperaType;

	osg::ref_ptr<osg::Geode> m_lodGeode;
	std::string m_fileUrl;
	osg::Vec3 m_offset;

	int m_CurrentLevel;  //当前节点层级

	gme_rect_3d m_frustumBox;  //视锥体范围
	osg::Vec3d m_curEyePos;    //当前视点的位置
	std::list<std::pair<std::string, gme_vector2f>> m_LodInfoList;  //lodUrl+range

	std::vector<gme_vector2f> m_vecLodRange;


protected: //0
	std::vector<std::string> m_vecLodUrl;

};

#endif