#ifndef _OGFEATUREMANAGER_H__
#define _OGFEATUREMANAGER_H__

#include "ResourceManager.h"
#include "ogFeature.h"

namespace Smart3dMap
{
    class _OG3D_RENDERENGINE_DLL ogFeatureManager: public ResourceManager
    {
    public:
        ogFeatureManager(CSceneNode* parent);
        ~ogFeatureManager();
        CSceneNode* getSceneNode(){return mSceneNode.get(); }

        FeaturePtr create(const OC::String& name, const OC::String& group = "ogFeatureManager",
            bool isManual = false, ManualResourceLoader* loader = 0,
            const NameValuePairList* createParams = 0);
        FeaturePtr getByName(const OC::String& name, const OC::String& groupName = ResourceGroupManager::AUTODETECT_RESOURCE_GROUP_NAME);
    protected:
        /// @copydoc ResourceManager::createImpl
        virtual Resource* createImpl(const OC::String& name, ResourceHandle handle,
            const OC::String& group, bool isManual, ManualResourceLoader* loader,
            const NameValuePairList* createParams);
    private:
        osg::ref_ptr<CSceneNode> mSceneNode;
        CORE_AUTO_MUTEX
    };
}

#endif // !_OGFEATUREMANAGER_H__




