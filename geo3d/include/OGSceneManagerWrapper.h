 #pragma once



namespace Smart3dMap
{
	/** 
	*/
	class OG_FRAME_DLL SceneManagerWrapper
	{
	public:

		/** 
		*/
		SceneManagerWrapper(SceneManager* mgr);

		/** 
		*/
		virtual ~SceneManagerWrapper();

		/** 
		*/
		virtual SceneManager* getSceneManager() const { return mSceneMgr; }

		/** 
		*/
//		virtual RaySceneQueryResult& executeRaySceneQuery(const Smart3dMap::Ray& ray, bool entities, bool worldGeometry);

		/** 
		*/
		virtual void setEntitiesQueryFlag(uint32 flag) { mEntitiesQueryFlag = flag; }

		/** 
		*/
		virtual void setWorldGeometryQueryFlag(uint32 flag) { mWorldGeometryQueryFlag = flag; }

	protected:

		SceneManager* mSceneMgr;
		//RaySceneQuery* mRayQuery;
		uint32 mEntitiesQueryFlag;
		uint32 mWorldGeometryQueryFlag;

	};
}




