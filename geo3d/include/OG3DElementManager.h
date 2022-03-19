#pragma once

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include "OG3DElement.h"
#include "OGManagerWrappers.h"


namespace Smart3dMap {

	class PartitionManager
	{
	public:
		PartitionManager(){}
		~PartitionManager(){}

	};

	// 几何管理器
	class OG_FRAME_DLL OG3DElementManager : public ProductManager<OG3DElement, OG3DElementFactory>
	{
	public:
		OG3DElementManager();
		~OG3DElementManager();

		void setSceneManager(SceneManager* sceneMgr);

		// 获取SceneManager
		SceneManager* getSceneManager(void) const;


		// override create
		OG3DElement* create(const OGGUID& guid);		
		OG3DElement* create(const string& name, const OGGUID& guid);

		/** Called when first initializing but prior to having initial properties set on this manager via setProperty
		*/
		virtual bool initStart(const string& worldName, 
			SceneManagerWrapper* sceneMgr, PartitionManager* partitionMgr);
		
		/** Called after having initial properties set on this manager
		*/
		virtual bool initFinish(void);

		// 
		virtual bool save(const string& worldName);

		// 根据Movable快速反向查询FeatureId
		bool get3DMdl(MovableObject* movable, string& fName);

		/** Sets the fixed height which is used when fixed height is enabled and moveObjects is called
		*/
		virtual void setFixedHeight(float fixedHeight);

		/** Gets the fixed height 
		*/
		virtual float getFixedHeight(void) const;

		/** Sets whether fixed height is enabled
		*/
		virtual void setFixedHeightEnabled(bool enabled);

		/** Gets whether fixed height is enabled
		*/
		virtual bool getFixedHeightEnabled(void) const;
		
		// 取中心
		Vector3 getAveragedCenter(OG3DElementList& objects);
		
		/** Clones (copies and pastes) a list of objects to the position provided
		*/
		virtual void cloneObjects(OG3DElementList& objects, 
			OG3DElementList& clonedObjects);
		
		/** Calls start moving on objects
		*/
		virtual void startMovingObjects(OG3DElementList& objects);
		
		/** Calls finish moving on objects
		*/
		virtual void finishMovingObjects(OG3DElementList& objects);
		
		/** Rotates a list of objects
		*/
		virtual void rotateObjects(OG3DElementList& objects, const Smart3dMap::Quaternion& rot);
		
		/** Translates a list of objects by the vector provided
		*/
		virtual void translateObjects(OG3DElementList& objects, const Vector3& translate);
		

		virtual void moveObjects(OG3DElementList& objects, const Vector3& position);		

		/** The editor calls this when objects should start "running". Example: particle system.
		*/
		virtual void startSimulation(void);

		/** The editor calls this when objects should stop "running". Example: particle system.
		*/
		virtual void endSimulation(void);

		/** Casts a ray into the scene and gets the closest intersection point if one was hit
		If objectCollide is true, will include objects when finding intersection
		If worldColide is true, will include world geometry when finding intersection
		If collision found and objectCollide is true, object will be the closest object collided
		Returns whether an intersection was found
		*/		
		//virtual bool rayCollide(const Smart3dMap::Ray& ray, 
		//	bool objectCollide, bool worldCollide, OG3DElement*& collidedObject, 
		//	Vector3& intersection = Vector3(Vector3::ZERO));		

		//virtual bool rayCollide(const Smart3dMap::Ray& ray, 
		//	bool objectCollide, bool worldCollide, OG3DElement*& collidedObject, 
		//	OG3DElementList& ignoreObjects, Vector3& intersection = Vector3(Vector3::ZERO));

		/** Casts a ray into the scene and gets the list of collision infos for objects that were collided
		*/
// 		virtual bool rayCollideObjects(const Smart3dMap::Ray& ray, 
// 			CollisionInfoList& collisionInfos);

		/** Casts a ray into the scene and gets world intersection if one was hit
		Returns true if intersection found
		*/
		//virtual bool rayCollideWorld(const Smart3dMap::Ray& ray, 
		//	Vector3& intersectionPoint);

		/** Performs collision detection of object against nearby objects, 
		filling the collision infos array. 
		Velocity is used to determine bounds used to search for nearby objects
		*/
// 		virtual void collisionDetect(OG3DElement& object, 
// 			CollisionInfoList& collisionInfos, Vector3& velocity);

		/** Select the objects in the object list which should display 
		some sort of indication that the object is selected
		*/ 
		virtual void selectObject(OG3DElement* object);

		/** Un-select objects
		*/
		virtual void unselectObject(OG3DElement* object);

		/** Returns whether simulation is currently running
		*/
		bool getSimulating() const { return mSimulating; }

		/** Returns whether we're currently being run in an editor
		*/
		bool getEditing() const { return mEditing; }


		SceneManager* getSceneManager(void);
		
		virtual PartitionManager* getPartitionManager() const { return mPartitionMgr; }
	private:	
		void destroyImpl(const string& name);
		
		SceneManagerWrapper* mSceneManagerWrapper;
		SceneManager* mSceneManager;
		PartitionManager* mPartitionMgr;
		Real mFixedHeight;
		bool mFixedHeightEnabled;
		bool mEditing;
		bool mSimulating;
	};
}


