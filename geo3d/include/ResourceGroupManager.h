#ifndef _ResourceGroupManager_H__
#define _ResourceGroupManager_H__

#include "ThreadDefine.h"
#include "Common.h"
#include "DataStream.h"
#include "ogResource.h"
#include "ScriptLoader.h"
#include "Archive.h"
#include "s3d_IteratorWrapper.h"
#include <ctime>
// If X11/Xlib.h gets included before this header (for example it happens when
// including wxWidgets and FLTK), Status is defined as an int which we don't
// want as we have an enum named Status.
#ifdef Status
#undef Status
#endif

namespace Smart3dMap {

	/** \addtogroup Core
	*  @{
	*/
	/** \addtogroup Resources
	*  @{
	*/
	/** This abstract class defines an interface which is called back during
        resource group loading to indicate the progress of the load. 
	@remarks
		Resource group loading is in 2 phases - creating resources from 
		declarations (which includes parsing scripts), and loading
		resources. Note that you don't necessarily have to have both; it
		is quite possible to just parse all the scripts for a group (see
		ResourceGroupManager::initialiseResourceGroup, but not to 
		load the resource group. 
		The sequence of events is (* signifies a repeating item):
		<ul>
		<li>resourceGroupScriptingStarted</li>
		<li>scriptParseStarted (*)</li>
        <li>scriptParseEnded (*)</li>
		<li>resourceGroupScriptingEnded</li>
		<li>resourceGroupLoadStarted</li>
		<li>resourceLoadStarted (*)</li>
        <li>resourceLoadEnded (*)</li>
        <li>worldGeometryStageStarted (*)</li>
        <li>worldGeometryStageEnded (*)</li>
		<li>resourceGroupLoadEnded</li>
		<li>resourceGroupPrepareStarted</li>
		<li>resourcePrepareStarted (*)</li>
        <li>resourcePrepareEnded (*)</li>
		<li>resourceGroupPrepareEnded</li>
		</ul>
    @note
        If CORE_THREAD_SUPPORT is 1, this class is thread-safe.

    */
    class _ThreadExport ResourceGroupListener
    {
    public:
        virtual ~ResourceGroupListener() {}

		/** This event is fired when a resource group begins parsing scripts.
		@note
			Remember that if you are loading resources through ResourceBackgroundQueue,
			these callbacks will occur in the background thread, so you should
			not perform any thread-unsafe actions in this callback if that's the
			case (check the group name / script name).
		@param groupName The name of the group 
		@param scriptCount The number of scripts which will be parsed
		*/
		virtual void resourceGroupScriptingStarted(const OC::String& groupName, size_t scriptCount) = 0;
		/** This event is fired when a script is about to be parsed.
			@param scriptName Name of the to be parsed
			@param skipThisScript A boolean passed by reference which is by default set to 
			false. If the event sets this to true, the script will be skipped and not
			parsed. Note that in this case the scriptParseEnded event will not be raised
			for this script.
		*/
		virtual void scriptParseStarted(const OC::String& scriptName, bool& skipThisScript) = 0;

		/** This event is fired when the script has been fully parsed.
		*/
		virtual void scriptParseEnded(const OC::String& scriptName, bool skipped) = 0;
		/** This event is fired when a resource group finished parsing scripts. */
		virtual void resourceGroupScriptingEnded(const OC::String& groupName) = 0;

		/** This event is fired  when a resource group begins preparing.
		@param groupName The name of the group being prepared
		@param resourceCount The number of resources which will be prepared, including
            a number of stages required to prepare any linked world geometry
		*/
		virtual void resourceGroupPrepareStarted(const OC::String& groupName, size_t resourceCount)
                { (void)groupName; (void)resourceCount; }

		/** This event is fired when a declared resource is about to be prepared. 
		@param resource Weak reference to the resource prepared.
		*/
		virtual void resourcePrepareStarted(const ResourcePtr& resource)
                { (void)resource; }

        /** This event is fired when the resource has been prepared. 
        */
        virtual void resourcePrepareEnded(void) {}
        /** This event is fired when a stage of preparing linked world geometry 
            is about to start. The number of stages required will have been 
            included in the resourceCount passed in resourceGroupLoadStarted.
        @param description Text description of what was just prepared
        */
        virtual void worldGeometryPrepareStageStarted(const OC::String& description)
        { (void)description; }

        /** This event is fired when a stage of preparing linked world geometry 
            has been completed. The number of stages required will have been 
            included in the resourceCount passed in resourceGroupLoadStarted.
        @param description Text description of what was just prepared
        */
        virtual void worldGeometryPrepareStageEnded(void) {}
        /** This event is fired when a resource group finished preparing. */
        virtual void resourceGroupPrepareEnded(const OC::String& groupName)
        { (void)groupName; }

		/** This event is fired  when a resource group begins loading.
		@param groupName The name of the group being loaded
		@param resourceCount The number of resources which will be loaded, including
            a number of stages required to load any linked world geometry
		*/
		virtual void resourceGroupLoadStarted(const OC::String& groupName, size_t resourceCount) = 0;
		/** This event is fired when a declared resource is about to be loaded. 
		@param resource Weak reference to the resource loaded.
		*/
		virtual void resourceLoadStarted(const ResourcePtr& resource) = 0;
        /** This event is fired when the resource has been loaded. 
        */
        virtual void resourceLoadEnded(void) = 0;
        /** This event is fired when a stage of loading linked world geometry 
            is about to start. The number of stages required will have been 
            included in the resourceCount passed in resourceGroupLoadStarted.
        @param description Text description of what was just loaded
        */
        virtual void worldGeometryStageStarted(const OC::String& description) = 0;
        /** This event is fired when a stage of loading linked world geometry 
            has been completed. The number of stages required will have been 
            included in the resourceCount passed in resourceGroupLoadStarted.
        @param description Text description of what was just loaded
        */
        virtual void worldGeometryStageEnded(void) = 0;
        /** This event is fired when a resource group finished loading. */
        virtual void resourceGroupLoadEnded(const OC::String& groupName) = 0;
    };

	/**
	 @remarks	This class allows users to override resource loading behavior.
				By overriding this class' methods, you can change how resources
				are loaded and the behavior for resource name collisions.
	*/
	class ResourceLoadingListener
	{
	public:
		virtual ~ResourceLoadingListener() {}

		/** This event is called when a resource beings loading. */
		virtual DataStreamPtr resourceLoading(const OC::String &name, const OC::String &group, Resource *resource) = 0;

		/** This event is called when a resource stream has been opened, but not processed yet. 
		@remarks
			You may alter the stream if you wish or alter the incoming pointer to point at
			another stream if you wish.
		*/
		virtual void resourceStreamOpened(const OC::String &name, const OC::String &group, Resource *resource, DataStreamPtr& dataStream) = 0;

		/** This event is called when a resource collides with another existing one in a resource manager
		  */
		virtual bool resourceCollision(Resource *resource, ResourceManager *resourceManager) = 0;
	};

    /** This singleton class manages the list of resource groups, and notifying
        the various resource managers of their obligations to load / unload
        resources in a group. It also provides facilities to monitor resource
        loading per group (to do progress bars etc), provided the resources 
        that are required are pre-registered.
    @par
        Defining new resource groups,  and declaring the resources you intend to
        use in advance is optional, however it is a very useful feature. In addition, 
		if a ResourceManager supports the definition of resources through scripts, 
		then this is the class which drives the locating of the scripts and telling
		the ResourceManager to parse them. 
	@par
		There are several states that a resource can be in (the concept, not the
		object instance in this case):
		<ol>
		<li><b>Undefined</b>. Nobody knows about this resource yet. It might be
		in the filesystem, but Ogre is oblivious to it at the moment - there 
		is no Resource instance. This might be because it's never been declared
		(either in a script, or using ResourceGroupManager::declareResource), or
		it may have previously been a valid Resource instance but has been 
		removed, either individually through ResourceManager::remove or as a group
		through ResourceGroupManager::clearResourceGroup.</li>
		<li><b>Declared</b>. Ogre has some forewarning of this resource, either
		through calling ResourceGroupManager::declareResource, or by declaring
		the resource in a script file which is on one of the resource locations
		which has been defined for a group. There is still no instance of Resource,
		but Ogre will know to create this resource when 
		ResourceGroupManager::initialiseResourceGroup is called (which is automatic
		if you declare the resource group before Root::initialise).</li>
		<li><b>Unloaded</b>. There is now a Resource instance for this resource, 
		although it is not loaded. This means that code which looks for this
		named resource will find it, but the Resource is not using a lot of memory
		because it is in an unloaded state. A Resource can get into this state
		by having just been created by ResourceGroupManager::initialiseResourceGroup 
		(either from a script, or from a call to declareResource), by 
		being created directly from code (ResourceManager::create), or it may 
		have previously been loaded and has been unloaded, either individually
		through Resource::unload, or as a group through ResourceGroupManager::unloadResourceGroup.</li>
		<li><b>Loaded</b>The Resource instance is fully loaded. This may have
		happened implicitly because something used it, or it may have been 
		loaded as part of a group.</li>
		</ol>
		@see ResourceGroupManager::declareResource
		@see ResourceGroupManager::initialiseResourceGroup
		@see ResourceGroupManager::loadResourceGroup
		@see ResourceGroupManager::unloadResourceGroup
		@see ResourceGroupManager::clearResourceGroup
    */
    class _ThreadExport ResourceGroupManager : public ResourceAlloc
    {
    public:
		CORE_AUTO_MUTEX // public to allow external locking
		/// Default resource group name
		static OC::String DEFAULT_RESOURCE_GROUP_NAME;
        /// Internal resource group name (should be used by OGRE internal only)
        static OC::String INTERNAL_RESOURCE_GROUP_NAME;
		/// Special resource group name which causes resource group to be automatically determined based on searching for the resource in all groups.
		static OC::String AUTODETECT_RESOURCE_GROUP_NAME;
		/// The number of reference counts held per resource by the resource system
		static size_t RESOURCE_SYSTEM_NUM_REFERENCE_COUNTS;
        /// Nested struct defining a resource declaration
        struct ResourceDeclaration
        {
            OC::String resourceName;
            OC::String resourceType;
            ManualResourceLoader* loader;
			NameValuePairList parameters;
        };
        /// List of resource declarations
        typedef list<ResourceDeclaration> ResourceDeclarationList;
		typedef map<OC::String, ResourceManager*> ResourceManagerMap;
		typedef MapIterator<ResourceManagerMap> ResourceManagerIterator;
		/// Resource location entry
		struct ResourceLocation
		{
			/// Pointer to the archive which is the destination
			CoreArchive* archive;
			/// Whether this location was added recursively
			bool recursive;
		};
		/// List of possible file locations
		typedef list<ResourceLocation*> LocationList;

    protected:
		/// map of resource types (strings) to ResourceManagers, used to notify them to load / unload group contents
        ResourceManagerMap mResourceManagerMap;

		/// map of loading order (Real) to ScriptLoader, used to order script parsing
		
		typedef multimap<Real, ScriptLoader*> ScriptLoaderOrderMap;
		ScriptLoaderOrderMap mScriptLoaderOrderMap;

		typedef vector<ResourceGroupListener*> ResourceGroupListenerList;
        ResourceGroupListenerList mResourceGroupListenerList;

		ResourceLoadingListener *mLoadingListener;

        /// Resource index entry, resourcename->location 
        typedef map<OC::String, CoreArchive*> ResourceLocationIndex;

		/// List of resources which can be loaded / unloaded
		typedef list<ResourcePtr> LoadUnloadResourceList;
		/// Resource group entry
		struct ResourceGroup
		{
			enum Status
			{
				UNINITIALSED = 0,
				INITIALISING = 1,
				INITIALISED = 2,
				LOADING = 3,
				LOADED = 4
			};
			/// General mutex for dealing with group content
			CORE_AUTO_MUTEX
			/// Status-specific mutex, separate from content-changing mutex
			CORE_MUTEX(statusMutex)
			/// Group name
			OC::String name;
			/// Group status
			Status groupStatus;
			/// List of possible locations to search
			LocationList locationList;
			/// Index of resource names to locations, built for speedy access (case sensitive archives)
			ResourceLocationIndex resourceIndexCaseSensitive;
            /// Index of resource names to locations, built for speedy access (case insensitive archives)
            ResourceLocationIndex resourceIndexCaseInsensitive;
			/// Pre-declared resources, ready to be created
			ResourceDeclarationList resourceDeclarations;
			/// Created resources which are ready to be loaded / unloaded
			// Group by loading order of the type (defined by ResourceManager)
			// (e.g. skeletons and materials before meshes)
			typedef map<Real, LoadUnloadResourceList*> LoadResourceOrderMap;
			LoadResourceOrderMap loadResourceOrderMap;
            /// Linked world geometry, as passed to setWorldGeometry
            OC::String worldGeometry;
            /// Scene manager to use with linked world geometry
//SceneManager* worldGeometrySceneManager;
			// in global pool flag - if true the resource will be loaded even a different	group was requested in the load method as a parameter.
			bool inGlobalPool;

			void addToIndex(const OC::String& filename, CoreArchive* arch);
			void removeFromIndex(const OC::String& filename, CoreArchive* arch);
			void removeFromIndex(CoreArchive* arch);

		};
        /// map from resource group names to groups
        typedef map<OC::String, ResourceGroup*> ResourceGroupMap;
        ResourceGroupMap mResourceGroupMap;

        /// Group name for world resources
        OC::String mWorldGroupName;

		/** Parses all the available scripts found in the resource locations
		for the given group, for all ResourceManagers.
		@remarks
			Called as part of initialiseResourceGroup
		*/
		void parseResourceGroupScripts(ResourceGroup* grp);
		/** Create all the pre-declared resources.
		@remarks
			Called as part of initialiseResourceGroup
		*/
		void createDeclaredResources(ResourceGroup* grp);
		/** Adds a created resource to a group. */
		void addCreatedResource(ResourcePtr& res, ResourceGroup& group);
		/** Get resource group */
		ResourceGroup* getResourceGroup(const OC::String& name);
		/** Drops contents of a group, leave group there, notify ResourceManagers. */
		void dropGroupContents(ResourceGroup* grp);
		/** Delete a group for shutdown - don't notify ResourceManagers. */
		void deleteGroup(ResourceGroup* grp);
		/// Internal find method for auto groups
		ResourceGroup* findGroupContainingResourceImpl(const OC::String& filename);
		/// Internal event firing method
		void fireResourceGroupScriptingStarted(const OC::String& groupName, size_t scriptCount);
		/// Internal event firing method
		void fireScriptStarted(const OC::String& scriptName, bool &skipScript);
        /// Internal event firing method
        void fireScriptEnded(const OC::String& scriptName, bool skipped);
		/// Internal event firing method
		void fireResourceGroupScriptingEnded(const OC::String& groupName);
        /// Internal event firing method
		void fireResourceGroupLoadStarted(const OC::String& groupName, size_t resourceCount);
        /// Internal event firing method
        void fireResourceLoadStarted(const ResourcePtr& resource);
		/// Internal event firing method
		void fireResourceLoadEnded(void);
		/// Internal event firing method
		void fireResourceGroupLoadEnded(const OC::String& groupName);
        /// Internal event firing method
		void fireResourceGroupPrepareStarted(const OC::String& groupName, size_t resourceCount);
        /// Internal event firing method
        void fireResourcePrepareStarted(const ResourcePtr& resource);
		/// Internal event firing method
		void fireResourcePrepareEnded(void);
		/// Internal event firing method
		void fireResourceGroupPrepareEnded(const OC::String& groupName);

		/// Stored current group - optimisation for when bulk loading a group
		ResourceGroup* mCurrentGroup;
	public:
        ResourceGroupManager();
        virtual ~ResourceGroupManager();

	public:
        /** Create a resource group.
        @remarks
            A resource group allows you to define a set of resources that can 
            be loaded / unloaded as a unit. For example, it might be all the 
            resources used for the level of a game. There is always one predefined
            resource group called ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME, 
			which is typically used to hold all resources which do not need to 
			be unloaded until shutdown. There is another predefined resource
            group called ResourceGroupManager::INTERNAL_RESOURCE_GROUP_NAME too,
            which should be used by OGRE internal only, the resources created
            in this group aren't supposed to modify, unload or remove by user.
            You can create additional ones so that you can control the life of
            your resources in whichever way you wish.
			There is one other predefined value, 
			ResourceGroupManager::AUTODETECT_RESOURCE_GROUP_NAME; using this 
			causes the group name to be derived at load time by searching for 
			the resource in the resource locations of each group in turn.
        @par
            Once you have defined a resource group, resources which will be loaded
			as part of it are defined in one of 3 ways:
			<ol>
			<li>Manually through declareResource(); this is useful for scripted
				declarations since it is entirely generalised, and does not 
				create Resource instances right away</li>
			<li>Through the use of scripts; some ResourceManager subtypes have
				script formats (e.g. .material, .overlay) which can be used
				to declare resources</li>
			<li>By calling ResourceManager::create to create a resource manually.
			This resource will go on the list for it's group and will be loaded
			and unloaded with that group</li>
			</ol>
			You must remember to call initialiseResourceGroup if you intend to use
			the first 2 types.
        @param name The name to give the resource group.
		@param inGlobalPool if true the resource will be loaded even a different
			group was requested in the load method as a parameter.
        */
        void createResourceGroup(const OC::String& name, const bool inGlobalPool = true);


        /** Initialises a resource group.
		@remarks
			After creating a resource group, adding some resource locations, and
			perhaps pre-declaring some resources using declareResource(), but 
			before you need to use the resources in the group, you 
			should call this method to initialise the group. By calling this,
			you are triggering the following processes:
			<ol>
			<li>Scripts for all resource types which support scripting are
				parsed from the resource locations, and resources within them are
				created (but not loaded yet).</li>
			<li>Creates all the resources which have just pre-declared using
			declareResource (again, these are not loaded yet)</li>
			</ol>
			So what this essentially does is create a bunch of unloaded Resource entries
			in the respective ResourceManagers based on scripts, and resources
			you've pre-declared. That means that code looking for these resources
			will find them, but they won't be taking up much memory yet, until
			they are either used, or they are loaded in bulk using loadResourceGroup.
			Loading the resource group in bulk is entirely optional, but has the 
			advantage of coming with progress reporting as resources are loaded.
		@par
			Failure to call this method means that loadResourceGroup will do 
			nothing, and any resources you define in scripts will not be found.
			Similarly, once you have called this method you won't be able to
			pick up any new scripts or pre-declared resources, unless you
			call clearResourceGroup, set up declared resources, and call this
			method again.
		@note 
			When you call Root::initialise, all resource groups that have already been
			created are automatically initialised too. Therefore you do not need to 
			call this method for groups you define and set up before you call 
			Root::initialise. However, since one of the most useful features of 
			resource groups is to set them up after the main system initialisation
			has occurred (e.g. a group per game level), you must remember to call this
			method for the groups you create after this.

		@param name The name of the resource group to initialise
		*/
		void initialiseResourceGroup(const OC::String& name);

		/** Initialise all resource groups which are yet to be initialised.
		@see ResourceGroupManager::intialiseResourceGroup
		*/
		void initialiseAllResourceGroups(void);

		/** Prepares a resource group.
        @remarks
			Prepares any created resources which are part of the named group.
			Note that resources must have already been created by calling
			ResourceManager::create, or declared using declareResource() or
			in a script (such as .material and .overlay). The latter requires
			that initialiseResourceGroup has been called. 
		
			When this method is called, this class will callback any ResourceGroupListeners
			which have been registered to update them on progress. 
        @param name The name of the resource group to prepare.
		@param prepareMainResources If true, prepares normal resources associated 
			with the group (you might want to set this to false if you wanted
			to just prepare world geometry in bulk)
		@param prepareWorldGeom If true, prepares any linked world geometry
			@see ResourceGroupManager::linkWorldGeometryToResourceGroup
        */
        void prepareResourceGroup(const OC::String& name, bool prepareMainResources = true, 
			bool prepareWorldGeom = true);

		/** Loads a resource group.
        @remarks
			Loads any created resources which are part of the named group.
			Note that resources must have already been created by calling
			ResourceManager::create, or declared using declareResource() or
			in a script (such as .material and .overlay). The latter requires
			that initialiseResourceGroup has been called. 
		
			When this method is called, this class will callback any ResourceGroupListeners
			which have been registered to update them on progress. 
        @param name The name of the resource group to load.
		@param loadMainResources If true, loads normal resources associated 
			with the group (you might want to set this to false if you wanted
			to just load world geometry in bulk)
		@param loadWorldGeom If true, loads any linked world geometry
			@see ResourceGroupManager::linkWorldGeometryToResourceGroup
        */
        void loadResourceGroup(const OC::String& name, bool loadMainResources = true, 
			bool loadWorldGeom = true);

        /** Unloads a resource group.
        @remarks
            This method unloads all the resources that have been declared as
            being part of the named resource group. Note that these resources
            will still exist in their respective ResourceManager classes, but
            will be in an unloaded state. If you want to remove them entirely,
            you should use clearResourceGroup or destroyResourceGroup.
        @param name The name to of the resource group to unload.
        @param reloadableOnly If set to true, only unload the resource that is
            reloadable. Because some resources isn't reloadable, they will be
            unloaded but can't load them later. Thus, you might not want to them
            unloaded. Or, you might unload all of them, and then populate them
            manually later.
            @see Resource::isReloadable for resource is reloadable.
        */
        void unloadResourceGroup(const OC::String& name, bool reloadableOnly = true);

		/** Unload all resources which are not referenced by any other object.
		@remarks
			This method behaves like unloadResourceGroup, except that it only
			unloads resources in the group which are not in use, ie not referenced
			by other objects. This allows you to free up some memory selectively
			whilst still keeping the group around (and the resources present,
			just not using much memory).
		@param name The name of the group to check for unreferenced resources
		@param reloadableOnly If true (the default), only unloads resources
			which can be subsequently automatically reloaded
		*/
		void unloadUnreferencedResourcesInGroup(const OC::String& name, 
			bool reloadableOnly = true);

		/** Clears a resource group. 
		@remarks
			This method unloads all resources in the group, but in addition it
			removes all those resources from their ResourceManagers, and then 
			clears all the members from the list. That means after calling this
			method, there are no resources declared as part of the named group
			any more. Resource locations still persist though.
        @param name The name to of the resource group to clear.
		*/
		void clearResourceGroup(const OC::String& name);
        
        /** Destroys a resource group, clearing it first, destroying the resources
            which are part of it, and then removing it from
            the list of resource groups. 
        @param name The name of the resource group to destroy.
        */
        void destroyResourceGroup(const OC::String& name);

		/** Checks the status of a resource group.
		@remarks
			Looks at the state of a resource group.
			If initialiseResourceGroup has been called for the resource
			group return true, otherwise return false.
		@param name The name to of the resource group to access.
		*/
		bool isResourceGroupInitialised(const OC::String& name);

		/** Checks the status of a resource group.
		@remarks
			Looks at the state of a resource group.
			If loadResourceGroup has been called for the resource
			group return true, otherwise return false.
		@param name The name to of the resource group to access.
		*/
		bool isResourceGroupLoaded(const OC::String& name);

		/*** Verify if a resource group exists
		@param name The name of the resource group to look for
		*/
		bool resourceGroupExists(const OC::String& name);

        /** Method to add a resource location to for a given resource group. 
        @remarks
            Resource locations are places which are searched to load resource files.
            When you choose to load a file, or to search for valid files to load, 
            the resource locations are used.
        @param name The name of the resource location; probably a directory, zip file, URL etc.
        @param locType The codename for the resource type, which must correspond to the 
            Archive factory which is providing the implementation.
        @param resGroup The name of the resource group for which this location is
            to apply. ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME is the 
			default group which always exists, and can
            be used for resources which are unlikely to be unloaded until application
            shutdown. Otherwise it must be the name of a group; if it
            has not already been created with createResourceGroup then it is created
            automatically.
        @param recursive Whether subdirectories will be searched for files when using 
			a pattern match (such as *.material), and whether subdirectories will be
			indexed. This can slow down initial loading of the archive and searches.
			When opening a resource you still need to use the fully qualified name, 
			this allows duplicate names in alternate paths.
        */
        void addResourceLocation(const OC::String& name, const OC::String& locType, 
            const OC::String& resGroup = DEFAULT_RESOURCE_GROUP_NAME, bool recursive = false);
        /** Removes a resource location from the search path. */ 
        void removeResourceLocation(const OC::String& name, 
			const OC::String& resGroup = DEFAULT_RESOURCE_GROUP_NAME);
        /** Verify if a resource location exists for the given group. */ 
		bool resourceLocationExists(const OC::String& name, 
			const OC::String& resGroup = DEFAULT_RESOURCE_GROUP_NAME);

        /** Declares a resource to be a part of a resource group, allowing you 
            to load and unload it as part of the group.
        @remarks
            By declaring resources before you attempt to use them, you can 
            more easily control the loading and unloading of those resources
            by their group. Declaring them also allows them to be enumerated, 
            which means events can be raised to indicate the loading progress
            (@see ResourceGroupListener). Note that another way of declaring
			resources is to use a script specific to the resource type, if
			available (e.g. .material).
		@par
			Declared resources are not created as Resource instances (and thus
			are not available through their ResourceManager) until initialiseResourceGroup
			is called, at which point all declared resources will become created 
			(but unloaded) Resource instances, along with any resources declared
			in scripts in resource locations associated with the group.
        @param name The resource name. 
        @param resourceType The type of the resource. Ogre comes preconfigured with 
            a number of resource types: 
            <ul>
            <li>Font</li>
            <li>GpuProgram</li>
            <li>HighLevelGpuProgram</li>
            <li>Material</li>
            <li>Mesh</li>
            <li>Skeleton</li>
            <li>Texture</li>
            </ul>
            .. but more can be added by plugin ResourceManager classes.
        @param groupName The name of the group to which it will belong.
		@param loadParameters A list of name / value pairs which supply custom
			parameters to the resource which will be required before it can 
			be loaded. These are specific to the resource type.
        */
        void declareResource(const OC::String& name, const OC::String& resourceType,
            const OC::String& groupName = DEFAULT_RESOURCE_GROUP_NAME,
			const NameValuePairList& loadParameters = NameValuePairList());
        /** Declares a resource to be a part of a resource group, allowing you
            to load and unload it as part of the group.
        @remarks
            By declaring resources before you attempt to use them, you can
            more easily control the loading and unloading of those resources
            by their group. Declaring them also allows them to be enumerated,
            which means events can be raised to indicate the loading progress
            (@see ResourceGroupListener). Note that another way of declaring
            resources is to use a script specific to the resource type, if
            available (e.g. .material).
        @par
            Declared resources are not created as Resource instances (and thus
            are not available through their ResourceManager) until initialiseResourceGroup
            is called, at which point all declared resources will become created
            (but unloaded) Resource instances, along with any resources declared
            in scripts in resource locations associated with the group.
        @param name The resource name.
        @param resourceType The type of the resource. Ogre comes preconfigured with
            a number of resource types:
            <ul>
            <li>Font</li>
            <li>GpuProgram</li>
            <li>HighLevelGpuProgram</li>
            <li>Material</li>
            <li>Mesh</li>
            <li>Skeleton</li>
            <li>Texture</li>
            </ul>
            .. but more can be added by plugin ResourceManager classes.
        @param groupName The name of the group to which it will belong.
        @param loader Pointer to a ManualResourceLoader implementation which will
            be called when the Resource wishes to load. If supplied, the resource
            is manually loaded, otherwise it'll loading from file automatic.
            @note We don't support declare manually loaded resource without loader
                here, since it's meaningless.
        @param loadParameters A list of name / value pairs which supply custom
            parameters to the resource which will be required before it can
            be loaded. These are specific to the resource type.
        */
        void declareResource(const OC::String& name, const OC::String& resourceType,
            const OC::String& groupName, ManualResourceLoader* loader,
            const NameValuePairList& loadParameters = NameValuePairList());
        /** Undeclare a resource.
		@remarks
			Note that this will not cause it to be unloaded
            if it is already loaded, nor will it destroy a resource which has 
			already been created if initialiseResourceGroup has been called already.
			Only unloadResourceGroup / clearResourceGroup / destroyResourceGroup 
			will do that. 
        @param name The name of the resource. 
		@param groupName The name of the group this resource was declared in. 
        */
        void undeclareResource(const OC::String& name, const OC::String& groupName);

		/** Open a single resource by name and return a DataStream
		 	pointing at the source of the data.
		@param resourceName The name of the resource to locate.
			Even if resource locations are added recursively, you
			must provide a fully qualified name to this method. You 
			can find out the matching fully qualified names by using the
			find() method if you need to.
		@param groupName The name of the resource group; this determines which 
			locations are searched. 
		@param searchGroupsIfNotFound If true, if the resource is not found in 
			the group specified, other groups will be searched. If you're
			loading a real Resource using this option, you <strong>must</strong>
			also provide the resourceBeingLoaded parameter to enable the 
			group membership to be changed
		@param resourceBeingLoaded Optional pointer to the resource being 
			loaded, which you should supply if you want
		@return Shared pointer to data stream containing the data, will be
			destroyed automatically when no longer referenced
		*/
		DataStreamPtr openResource(const OC::String& resourceName, 
			const OC::String& groupName = DEFAULT_RESOURCE_GROUP_NAME,
			bool searchGroupsIfNotFound = true, Resource* resourceBeingLoaded = 0);

		/** Open all resources matching a given pattern (which can contain
			the character '*' as a wildcard), and return a collection of 
			DataStream objects on them.
		@param pattern The pattern to look for. If resource locations have been
			added recursively, subdirectories will be searched too so this
			does not need to be fully qualified.
		@param groupName The resource group; this determines which locations
			are searched.
		@return Shared pointer to a data stream list , will be
			destroyed automatically when no longer referenced
		*/
		DataStreamListPtr openResources(const OC::String& pattern, 
			const OC::String& groupName = DEFAULT_RESOURCE_GROUP_NAME);
		
        /** List all file or directory names in a resource group.
        @note
        This method only returns filenames, you can also retrieve other
        information using listFileInfo.
        @param groupName The name of the group
        @param dirs If true, directory names will be returned instead of file names
        @return A list of filenames matching the criteria, all are fully qualified
        */
        StringVectorPtr listResourceNames(const OC::String& groupName, bool dirs = false);

        /** List all files in a resource group with accompanying information.
        @param groupName The name of the group
        @param dirs If true, directory names will be returned instead of file names
        @return A list of structures detailing quite a lot of information about
        all the files in the archive.
        */
        FileInfoListPtr listResourceFileInfo(const OC::String& groupName, bool dirs = false);

        /** Find all file or directory names matching a given pattern in a
            resource group.
        @note
        This method only returns filenames, you can also retrieve other
        information using findFileInfo.
        @param groupName The name of the group
        @param pattern The pattern to search for; wildcards (*) are allowed
        @param dirs Set to true if you want the directories to be listed
            instead of files
        @return A list of filenames matching the criteria, all are fully qualified
        */
        StringVectorPtr findResourceNames(const OC::String& groupName, const OC::String& pattern,
            bool dirs = false);

        /** Find out if the named file exists in a group. 
        @param group The name of the resource group
        @param filename Fully qualified name of the file to test for
        */
        bool resourceExists(const OC::String& group, const OC::String& filename);

        /** Find out if the named file exists in a group. 
        @param group Pointer to the resource group
        @param filename Fully qualified name of the file to test for
        */
        bool resourceExists(ResourceGroup* group, const OC::String& filename);
		
        /** Find out if the named file exists in any group. 
        @param filename Fully qualified name of the file to test for
        */
        bool resourceExistsInAnyGroup(const OC::String& filename);

		/** Find the group in which a resource exists.
		@param filename Fully qualified name of the file the resource should be
			found as
		@return Name of the resource group the resource was found in. An
			exception is thrown if the group could not be determined.
		*/
		const OC::String& findGroupContainingResource(const OC::String& filename);

        /** Find all files or directories matching a given pattern in a group
            and get some detailed information about them.
        @param group The name of the resource group
        @param pattern The pattern to search for; wildcards (*) are allowed
        @param dirs Set to true if you want the directories to be listed
            instead of files
        @return A list of file information structures for all files matching 
        the criteria.
        */
        FileInfoListPtr findResourceFileInfo(const OC::String& group, const OC::String& pattern,
            bool dirs = false);

		/** Retrieve the modification time of a given file */
		time_t resourceModifiedTime(const OC::String& group, const OC::String& filename); 
        /** List all resource locations in a resource group.
        @param groupName The name of the group
        @return A list of resource locations matching the criteria
        */
        StringVectorPtr listResourceLocations(const OC::String& groupName);

        /** Find all resource location names matching a given pattern in a
            resource group.
        @param groupName The name of the group
        @param pattern The pattern to search for; wildcards (*) are allowed
        @return A list of resource locations matching the criteria
        */
        StringVectorPtr findResourceLocation(const OC::String& groupName, const OC::String& pattern);

		/** Retrieve the modification time of a given file */
		time_t resourceModifiedTime(ResourceGroup* group, const OC::String& filename); 

		/** Create a new resource file in a given group.
		@remarks
			This method creates a new file in a resource group and passes you back a 
			writeable stream. 
		@param filename The name of the file to create
		@param groupName The name of the group in which to create the file
		@param overwrite If true, an existing file will be overwritten, if false
			an error will occur if the file already exists
		@param locationPattern If the resource group contains multiple locations, 
			then usually the file will be created in the first writable location. If you 
			want to be more specific, you can include a location pattern here and 
			only locations which match that pattern (as determined by OC::StringUtil::match)
			will be considered candidates for creation.
		*/
		DataStreamPtr createResource(const OC::String& filename, const OC::String& groupName = DEFAULT_RESOURCE_GROUP_NAME, 
			bool overwrite = false, const OC::String& locationPattern = OC::StringUtil::BLANK);

		/** Delete a single resource file.
		@param filename The name of the file to delete. 
		@param groupName The name of the group in which to search
		@param locationPattern If the resource group contains multiple locations, 
			then usually first matching file found in any location will be deleted. If you 
			want to be more specific, you can include a location pattern here and 
			only locations which match that pattern (as determined by OC::StringUtil::match)
			will be considered candidates for deletion.
		*/
		void deleteResource(const OC::String& filename, const OC::String& groupName = DEFAULT_RESOURCE_GROUP_NAME, 
			const OC::String& locationPattern = OC::StringUtil::BLANK);

		/** Delete all matching resource files.
		@param filePattern The pattern (see OC::StringUtil::match) of the files to delete. 
		@param groupName The name of the group in which to search
		@param locationPattern If the resource group contains multiple locations, 
			then usually all matching files in any location will be deleted. If you 
			want to be more specific, you can include a location pattern here and 
			only locations which match that pattern (as determined by OC::StringUtil::match)
			will be considered candidates for deletion.
		*/
		void deleteMatchingResources(const OC::String& filePattern, const OC::String& groupName = DEFAULT_RESOURCE_GROUP_NAME, 
			const OC::String& locationPattern = OC::StringUtil::BLANK);

		/** Adds a ResourceGroupListener which will be called back during 
            resource loading events. 
        */
        void addResourceGroupListener(ResourceGroupListener* l);
        /** Removes a ResourceGroupListener */
        void removeResourceGroupListener(ResourceGroupListener* l);

        /** Sets the resource group that 'world' resources will use.
        @remarks
            This is the group which should be used by SceneManagers implementing
            world geometry when looking for their resources. Defaults to the 
            DEFAULT_RESOURCE_GROUP_NAME but this can be altered.
        */
        void setWorldResourceGroupName(const OC::String& groupName) {mWorldGroupName = groupName;}

        /// Gets the resource group that 'world' resources will use.
        const OC::String& getWorldResourceGroupName(void) const { return mWorldGroupName; }

        /** Associates some world geometry with a resource group, causing it to 
            be loaded / unloaded with the resource group.
        @remarks
            You would use this method to essentially defer a call to 
            SceneManager::setWorldGeometry to the time when the resource group
            is loaded. The advantage of this is that compatible scene managers 
            will include the estimate of the number of loading stages for that
            world geometry when the resource group begins loading, allowing you
            to include that in a loading progress report. 
        @param group The name of the resource group
        @param worldGeometry The parameter which should be passed to setWorldGeometry
        @param sceneManager The SceneManager which should be called
        */
 //       void linkWorldGeometryToResourceGroup(const OC::String& group, 
 //           const OC::String& worldGeometry, SceneManager* sceneManager);

        /** Clear any link to world geometry from a resource group.
        @remarks
            Basically undoes a previous call to linkWorldGeometryToResourceGroup.
        */
        void unlinkWorldGeometryFromResourceGroup(const OC::String& group);

			/** Checks the status of a resource group.
		@remarks
			Looks at the state of a resource group.
			If loadResourceGroup has been called for the resource
			group return true, otherwise return false.
		@param name The name to of the resource group to access.
		*/
		bool isResourceGroupInGlobalPool(const OC::String& name);

        /** Shutdown all ResourceManagers, performed as part of clean-up. */
        void shutdownAll(void);


        /** Internal method for registering a ResourceManager (which should be
            a singleton). Creators of plugins can register new ResourceManagers
            this way if they wish.
		@remarks
			ResourceManagers that wish to parse scripts must also call 
			_registerScriptLoader.
        @param resourceType OC::String identifying the resource type, must be unique.
        @param rm Pointer to the ResourceManager instance.
        */
        void _registerResourceManager(const OC::String& resourceType, ResourceManager* rm);

        /** Internal method for unregistering a ResourceManager.
		@remarks
			ResourceManagers that wish to parse scripts must also call 
			_unregisterScriptLoader.
        @param resourceType OC::String identifying the resource type.
        */
        void _unregisterResourceManager(const OC::String& resourceType);

		/** Get an iterator over the registered resource managers.
		*/
		ResourceManagerIterator getResourceManagerIterator()
		{ return ResourceManagerIterator(
			mResourceManagerMap.begin(), mResourceManagerMap.end()); }

        /** Internal method for registering a ScriptLoader.
		@remarks ScriptLoaders parse scripts when resource groups are initialised.
        @param su Pointer to the ScriptLoader instance.
        */
       void _registerScriptLoader(ScriptLoader* su);

        /** Internal method for unregistering a ScriptLoader.
        @param su Pointer to the ScriptLoader instance.
        */
        void _unregisterScriptLoader(ScriptLoader* su);

		/** Method used to directly query for registered script loaders.
		@param pattern The specific script pattern (e.g. *.material) the script loader handles
		*/
		ScriptLoader *_findScriptLoader(const OC::String &pattern);

		/** Internal method for getting a registered ResourceManager.
		@param resourceType OC::String identifying the resource type.
		*/
		ResourceManager* _getResourceManager(const OC::String& resourceType);

		/** Internal method called by ResourceManager when a resource is created.
		@param res Weak reference to resource
		*/
		void _notifyResourceCreated(ResourcePtr& res);

		/** Internal method called by ResourceManager when a resource is removed.
		@param res Weak reference to resource
		*/
		void _notifyResourceRemoved(ResourcePtr& res);

		/** Internal method to notify the group manager that a resource has
			changed group (only applicable for autodetect group) */
		void _notifyResourceGroupChanged(const OC::String& oldGroup, Resource* res);

		/** Internal method called by ResourceManager when all resources 
			for that manager are removed.
		@param manager Pointer to the manager for which all resources are being removed
		*/
		void _notifyAllResourcesRemoved(ResourceManager* manager);

        /** Notify this manager that one stage of world geometry loading has been 
            started.
        @remarks
            Custom SceneManagers which load custom world geometry should call this 
            method the number of times equal to the value they return from 
            SceneManager::estimateWorldGeometry while loading their geometry.
        */
        void _notifyWorldGeometryStageStarted(const OC::String& description);
        /** Notify this manager that one stage of world geometry loading has been 
            completed.
        @remarks
            Custom SceneManagers which load custom world geometry should call this 
            method the number of times equal to the value they return from 
            SceneManager::estimateWorldGeometry while loading their geometry.
        */
        void _notifyWorldGeometryStageEnded(void);

		/** Get a list of the currently defined resource groups. 
		@note This method intentionally returns a copy rather than a reference in
			order to avoid any contention issues in multithreaded applications.
		@return A copy of list of currently defined groups.
		*/
		OC::StringVector getResourceGroups(void);
		/** Get the list of resource declarations for the specified group name. 
		@note This method intentionally returns a copy rather than a reference in
			order to avoid any contention issues in multithreaded applications.
		@param groupName The name of the group
		@return A copy of list of currently defined resources.
		*/
		ResourceDeclarationList getResourceDeclarationList(const OC::String& groupName);

		/** Get the list of resource locations for the specified group name.
		@param groupName The name of the group
		@return The list of resource locations associated with the given group.
		*/		
		const LocationList& getResourceLocationList(const OC::String& groupName);

		/// Sets a new loading listener
		void setLoadingListener(ResourceLoadingListener *listener);
		/// Returns the current loading listener
		ResourceLoadingListener *getLoadingListener();

		/** Override standard Smart3dMap::Singleton retrieval.
        @remarks
        Why do we do this? Well, it's because the Smart3dMap::Singleton
        implementation is in a .h file, which means it gets compiled
        into anybody who includes it. This is needed for the
        Smart3dMap::Singleton template to work, but we actually only want it
        compiled into the implementation of the class based on the
        Smart3dMap::Singleton, not all of them. If we don't change this, we get
        link errors when trying to use the Smart3dMap::Singleton-based class from
        an outside dll.
        @par
        This method just delegates to the template version anyway,
        but the implementation stays in this single compilation unit,
        preventing link errors.
        */
        //static ResourceGroupManager& getSingleton(void);
        /** Override standard Smart3dMap::Singleton retrieval.
        @remarks
        Why do we do this? Well, it's because the Smart3dMap::Singleton
        implementation is in a .h file, which means it gets compiled
        into anybody who includes it. This is needed for the
        Smart3dMap::Singleton template to work, but we actually only want it
        compiled into the implementation of the class based on the
        Smart3dMap::Singleton, not all of them. If we don't change this, we get
        link errors when trying to use the Smart3dMap::Singleton-based class from
        an outside dll.
        @par
        This method just delegates to the template version anyway,
        but the implementation stays in this single compilation unit,
        preventing link errors.
        */
		static ResourceGroupManager* getSingletonPtr(void);
		static ResourceGroupManager& getSingleton(void);

    };
	/** @} */
	/** @} */
}

#endif
