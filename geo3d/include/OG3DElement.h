 #pragma once 

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include "OGUserDefinedObject.h"
#include "OGElement.h"
#include "s3d_SimpleMesh.h"
#include "OgFactoryObj.h"
#include "SceneNode.h"


namespace Smart3dMap {
	const string STR_SET_ELE_DISPSTYLE_DOT = "点模式";
	const string STR_SET_ELE_DISPSTYLE_LINE = "线框模式";
	const string STR_SET_ELE_DISPSTYLE_SOLID = "实体模式";


	class OG3DLayer;
	class OG3DElementManager;

	class OG_FRAME_DLL OG3DElement : public Element, public UserDefinedObject
	{
	public:
		// 根据给定的场景节点和要素生成渲染实体列表
		OG3DElement(const string& name);
		virtual ~OG3DElement();

		/** 继承Element */
		// 载入
		virtual bool load(DataElement* element);
		virtual bool save(DataElement* element);
		// 载入
		virtual bool load(SuperMesh& mesh){return 1;}
		virtual bool load(string& strMeshName){return 1;}


		virtual void onExecute(const string& func, WPARAM wParam, LPARAM lParam);
		virtual void registerFunctions(void);

		virtual void setVisible(bool visible);
		virtual bool isVisible(void) const;	

		virtual void select(bool select = true);		
		/** 继承完毕*/




		// 载入
		virtual bool loadStart(DataElement* element);
		virtual bool loadFinish(void);

		// 
		virtual bool initFinish(const Vector3& position = Vector3(0,0,0));


		// 销毁
		virtual void destroy(void);

		// 取得要素
		OG3DLayer* getFeatureNode(void);

		
		// 取得场景节点
		osg::ref_ptr<osg::Group> getSceneNode(void) const;
		
        // 取得管理器
		OG3DElementManager* getManager(void) const;

		// 获取MovableObject		
		virtual MovableObject* getMovableObject(void) const;
		virtual void setMovableObject(MovableObject* movable);

		// 是否启用透明
		virtual bool isAlphaEnabled(void) const;
		virtual void setAlphaEnabled(bool bEnabled);

		// 透明度
		virtual void setTransparency(Real transparency);
		virtual Real getTransparency(void) const;

		// 设置远距离
		virtual void setRenderingDistance(Real dist);
		virtual Real getRenderingDistance(void) const;

		// 以下接口维护编辑对象的位置,方向等
		virtual void setPosition(const Vector3& pos, bool world = true, bool checkPartition = true);
		virtual void setPosition(Real x,Real y,Real z); 

		/** Attempts to set the object's orientation in world space. Object can snap itself as necessary
		*/
		virtual void setOrientation(const Smart3dMap::Quaternion& orientation, bool world = true, bool checkPartition = true);

		/** Translate the object in world space
		*/
		virtual void translate(const Vector3& trans, bool checkPartition = true);

		/** Returns the objects position in parent's space
		*/
		virtual const Vector3 getPosition(void) const;

		/** Returns the object's position in world space
		*/
		virtual const Vector3 getWorldPosition(void) const;

		/** Returns the object's orientation in world space
		*/
		virtual const Smart3dMap::Quaternion getWorldOrientation(void) const;

		/** Returns the object's orientation
		*/
		virtual const Smart3dMap::Quaternion getOrientation(void) const;

		/** Returns the object's World Matrix
		*/ 
		virtual void getWorldTransforms(Matrix4* xform) const;

		/** Returns the object's direction in world space
		*/
		virtual Vector3 getWorldDirection(void) const;

		/** Returns the object's world axis aligned bounding box
		Derived classes should override this and return a true AABB if they have one
		*/
		virtual AxisAlignedBox getWorldBoundingBox(void) const;

		//virtual void rotate(const Vector3& axis, const Radian &rad);
		
		virtual void rotate(const Smart3dMap::Quaternion& rot);

		/** Scale by Vector3
		*/
		virtual void setScale(const Vector3& scale);

		/** Scale by Vector3
		*/
		virtual void setScale(Real x, Real y, Real z);

		/** Gets the scaling factor of this OG3DElement.
        */
        virtual const Vector3 & getScale(void) const;

		/** Scales the node, combining it's current scale with the passed in scaling factor. 
        */
		virtual void scale(const Vector3& scale);

		/** Scales the node, combining it's current scale with the passed in scaling factor. 
        */
        virtual void scale(Real x, Real y, Real z);

		bool getCollidable() const { return mCollidable; }

		/**
		*/
		void setCollidable(bool collidable) { mCollidable = collidable; }

		/** Called when an object is going to begin moving
		*/
		virtual void startMoving() {};

		/** Called when an object is finished moving
		*/
		virtual void finishMoving() {};

	    /** The editor calls this when objects should start "running". Example: particle system.
		*/
		virtual void startSimulation() {}

		/** The editor calls this when objects should stop "running". Example: particle system.
		*/
		virtual void endSimulation() {}
		void checkCurrentPartition();
		
		/** This can be used to set what should be returned by getSelection()
		in the case where we want some other object to be selected when we're clicked by the user
		see getSelection for more details
		*/
		void setAlternativeSelection(OG3DElement* object) { mAlternateSelection = object; }

		/** When the user clicks on this object, sometimes the object should return its parent or some other objects
		in the case of compound objects (like TreeGameObject) so this function can be overridden to return a different object
		*/
		OG3DElement* getSelection();

		/* UserDefinedObject */
		long getTypeID(void) const;
        const string& getTypeName(void) const;

		virtual void onDbClick(void);
		virtual void onPropertyDialog(void);

		// Smart3dMap数据关联
		const OG_Mdl_ID& get3DMdl(void);
		void set3DMdl(const OG_Mdl_ID& oid);

		const std::string& get3DMdlstrUrl(void);
		void set3DMdlstrUrl(const std::string& strUrl);
		//
		virtual void focus();

		virtual void reload(void);
		void setFillMode(Smart3dMap::PolygonMode renderDetail);
		
		virtual void updateNode();
		

	protected:
	    virtual void onCreate(void);

	private:
		// 用对象名称创建场景接点
		void createSceneNode(void);
		void destroySceneNode(void);

	public:
		virtual void setModelType(long mModelType);
		virtual long getModelType();
	protected:
		long				mModelType;

	protected:	
		bool mCollidable; //whether collidable when in simulation mode 
		osg::ref_ptr<CSceneNode> mSceneNode;	
// 		osg::ref_ptr<osg::Group> mSceneNode;	
		osg::MatrixTransform* mSceneTriNode;
		bool mAlphaEnabled;
		Real mTransparency;
		OG3DElement* mAlternateSelection;
		MovableObject* mMovable;

		OG_Mdl_ID mMdlID;
		std::string mStrUrl;
	};

	typedef std::vector<OG3DElement*> OG3DElementList;


	class OG_FRAME_DLL OG3DElementFactory : public FactoryObj<OG3DElement>
	{
	};

}
