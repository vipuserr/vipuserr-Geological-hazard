#pragma once
#include "s3d_baseapplib_global.h"
#include "gmeEntity.h"
#include "gmeMdl.h"
#include <vector>

namespace Smart3dMap
{
	class S3D_BASEAPPLIB_EXPORT S3d_ModelCut
	{
	public:
		bool cutSectionModel(Smart3dMap::gmeSurface* pSurf, std::vector<std::pair<std::string, std::vector<Smart3dMap::gmeEntity*>>>& entitys, Smart3dMap::gmeModel* sectionMdl);
		bool cutEntityBySurf(Smart3dMap::gmeSurface* pSurf, std::vector<std::pair<std::string, std::vector<Smart3dMap::gmeEntity*>>>& entitys, Smart3dMap::gmeModel* model1, Smart3dMap::gmeModel* model2, vector<gme_vector2d>* polylin = nullptr);
		bool cutEntityByEntity(Smart3dMap::gmeEntity* cutEnt, std::vector<std::pair<std::string, std::vector<Smart3dMap::gmeEntity*>>>& entitys, Smart3dMap::gmeModel* model1, Smart3dMap::gmeModel* model2);


		bool getGmeModel(Smart3dMap::gmeStorageDB& storageDB, const int& model_id, Smart3dMap::gmeModel* mdl);
		void getCutSurf(Smart3dMap::gmeSurface& surf, const std::vector<gme_vector2d>& pnts, const Smart3dMap::gme_rect_3d& mdlBox);
		void getCutEntity(Smart3dMap::gmeEntity& ent, const std::vector<gme_vector2d>& pnts, const double& height, const Smart3dMap::gme_rect_3d& mdlBox);
		void pntSet2gmeSurface(vector<gme_vector3d>& points, Smart3dMap::gmeSurface & outSurf);
		//entitys里边可能存在gmeModel中surf转换的gmeEntity，需要释放
		void getEntityList(std::vector<std::pair<std::string, std::vector<Smart3dMap::gmeEntity*>>>& entitys, Smart3dMap::gmeModel* mdl);
		void releaseEntityList(std::vector<std::pair<std::string, std::vector<Smart3dMap::gmeEntity*>>>& entitys);
		
		//根据剖面取出拐点,该接口还需完善 --zhuyh-20211117
		void getBreakPointBySection(std::vector<gme_vector2d>& pnts , Smart3dMap::gmeModel * sectionMdl);
		//剖面图添加虚拟钻孔
		bool sectionAddVirHole(std::vector<gme_vector3d>& pnts, Smart3dMap::gmeModel* sectionMdl, Smart3dMap::gmeModel* model);
	};
}
