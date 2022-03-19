#pragma once
#include <osgViewer/Viewer>
#include <osgDB/ReadFile>
#include <osgGA/GUIEventAdapter>
#include <osgGA/GUIActionAdapter>
#include <osgViewer/ViewerEventHandlers>
#include <osgGA/StateSetManipulator>
#include <osgGA/TrackballManipulator>
#include <osgFX/Scribe>

#include "OGBasDef.h"

using namespace osg;
class  C3DRenderEngine;

namespace Smart3dMap
{
	class PickHandler:public osgGA::GUIEventHandler
	{
	public:
		PickHandler::PickHandler():lastselect(0),IsPick(false),m_ModelPick(false),pSelectNode(0),m_CovertCoord(0),m_DoublePick(true){}
		PickHandler::~PickHandler(){}
		virtual bool PickHandler::handle(const osgGA::GUIEventAdapter& ea,osgGA::GUIActionAdapter& aa);
		void pick(float x,float y);
		Node* pickNode(float x,float y,const osgGA::GUIEventAdapter& mEventAdapter);
		osg::Vec3d* CovertCoord(float x,float y,const osgGA::GUIEventAdapter& mEventAdapter);

		osg::ref_ptr<osgUtil::PolytopeIntersector> getPolytopeIntersector(
			const osgGA::GUIEventAdapter& aEventAdapter,
			const double& aWidth,
			const double& aHeight);
	private:
		osg::Node* lastselect;
		osgViewer::Viewer* m_viewer;
		bool IsPick;
		bool m_ModelPick;
		bool m_CovertCoord;
		bool m_DoublePick;
		osg::Node* pSelectNode;
		osg::Vec3d* plocalCoord;

	public:
		void setStartPick(bool pIsStartPcik){m_ModelPick = pIsStartPcik;}
		bool getStartPick(){return m_ModelPick;}

		void setCovertCoordMode(bool p_CovertCoord){m_CovertCoord = p_CovertCoord;}
		bool getCovertCoordMode(){return m_CovertCoord;}

		void setDoublePickMode(bool p_DoublePick){m_DoublePick = p_DoublePick;}
		bool getDoublePickMode(){return m_DoublePick;} 

		osg::Vec3d* getLocalCoord(){return plocalCoord;}

	public:

	};

	class og_manipulator:public osgGA::TrackballManipulator
	{
	public:
		og_manipulator(void* pRenderEngine = NULL){
			m_pRenderEngine = pRenderEngine;
			setAllowThrow(false);
		}
		~og_manipulator(){}
		virtual void setByMatrix( const osg::Matrixd& matrix ){};
		virtual void setByInverseMatrix( const osg::Matrixd& matrix ){}
	
		virtual bool handle( const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& us );


	/*	bool changePosittion(osg::Vec3 delta);*/
	private:
		osg::Quat _rotation;
		double _ZoomFactor;
		void* m_pRenderEngine;
	};


	//g ¼üÇÐ»»£ºFILL-->FILL+LINE-->LINE-->POINT
	class  OG_FRAME_DLL my_StateSetManipulator : public osgGA::GUIEventHandler
	{
	public:

		my_StateSetManipulator(void* pRenderEngine, osg::StateSet* stateset=0);

		virtual const char* className() const { return "my_StateSetManipulator"; }
		virtual void setStateSet(osg::StateSet*);
		virtual osg::StateSet * getStateSet();
		virtual const osg::StateSet * getStateSet() const;
		virtual bool handle(const osgGA::GUIEventAdapter& ea,osgGA::GUIActionAdapter& us);        


		void setMaximumNumOfTextureUnits(unsigned int i) { _maxNumOfTextureUnits = i; }
		unsigned int getMaximumNumOfTextureUnits() const { return _maxNumOfTextureUnits; }

		void setBackfaceEnabled(bool newbackface);
		bool getBackfaceEnabled() const {return _backface;};

		void setLightingEnabled(bool newlighting);
		bool getLightingEnabled() const {return _lighting;};

		void setTextureEnabled(bool newtexture);
		bool getTextureEnabled() const {return _texture;};

		void setPolygonMode(osg::PolygonMode::Mode newpolygonmode);
		osg::PolygonMode::Mode getPolygonMode() const;

		void cyclePolygonMode();

		void setKeyEventToggleBackfaceCulling(int key) { _keyEventToggleBackfaceCulling = key; }
		int getKeyEventToggleBackfaceCulling() const { return _keyEventToggleBackfaceCulling; }

		void setKeyEventToggleLighting(int key) { _keyEventToggleLighting = key; }
		int getKeyEventToggleLighting() const { return _keyEventToggleLighting; }

		void setKeyEventToggleTexturing(int key) { _keyEventToggleTexturing = key; }
		int getKeyEventToggleTexturing() const { return _keyEventToggleTexturing; }

		void setKeyEventCyclePolygonMode(int key) { _keyEventCyclePolygonMode = key; }
		int getKeyEventCyclePolygonMode() const { return _keyEventCyclePolygonMode; }

	protected:

		virtual ~my_StateSetManipulator();

		void clone();

		osg::ref_ptr<osg::StateSet> _stateset;

		bool _initialized;
		bool _backface;
		bool _lighting;
		bool _texture;
		bool _scribe;
		unsigned int _maxNumOfTextureUnits;

		int _keyEventToggleBackfaceCulling;
		int _keyEventToggleLighting;
		int _keyEventToggleTexturing;
		int _keyEventCyclePolygonMode;
		
		osg::PolygonMode* getOrCreatePolygonMode();
		osgFX::Scribe* getScribeNode();
		
		osg::ref_ptr<osgFX::Scribe> m_pScribe;
		void* m_pRenderEngine;
	};

}

