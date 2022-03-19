#ifndef _ogStateSetManipulator_CLASS__
#define _ogStateSetManipulator_CLASS__

#include "Og3DRE_Def.h"

namespace Smart3dMap
{
	class _OG3D_RENDERENGINE_DLL ogStateSetManipulator :public osgGA::GUIEventHandler
	{
	public:

		ogStateSetManipulator(C3DRenderEngine* pRenderEngine, osg::StateSet* stateset = 0);

		virtual const char* className() const { return "my_StateSetManipulator"; }
		virtual void setStateSet(osg::StateSet*);
		virtual osg::StateSet * getStateSet();
		virtual const osg::StateSet * getStateSet() const;
		virtual bool handle(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& us);


		void setMaximumNumOfTextureUnits(unsigned int i) { _maxNumOfTextureUnits = i; }
		unsigned int getMaximumNumOfTextureUnits() const { return _maxNumOfTextureUnits; }

		void setBackfaceEnabled(bool newbackface);
		bool getBackfaceEnabled() const { return _backface; };

		void setLightingEnabled(bool newlighting);
		bool getLightingEnabled() const { return _lighting; };

		void setTextureEnabled(bool newtexture);
		bool getTextureEnabled() const { return _texture; };

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

		virtual ~ogStateSetManipulator();

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
		C3DRenderEngine* m_pRenderEngine;
	};
}

#endif