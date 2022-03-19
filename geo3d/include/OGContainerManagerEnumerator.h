 // OGContainerManagerEnumerator.h: interface for the ContainerManagerEnumerator class.
//
//////////////////////////////////////////////////////////////////////

#pragma once 

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include "OGContainerManager.h"

namespace Smart3dMap { 


    /** Enumerates the ContainerManager classes available to applications.
        @remarks
            As described in the ContainerManager class, ContainerManagers are responsible
            for organising the scene and issuing rendering commands to the
            RenderSystem. Certain scene types can benefit from different
            rendering approaches, and it is intended that subclasses will
            be created to special case this.
        @par
            In order to give applications easy access to these implementations,
            this class has a number of methods to create or retrieve a ContainerManager
            which is appropriate to the scene type. 
		@par
			ContainerManagers are created by ContainerManagerFactory instances. New factories
			for new types of ContainerManager can be registered with this class to make
			them available to clients.
		@par
			Note that you can still plug in your own custom ContainerManager without
			using a factory, should you choose, it's just not as flexible that way.
			Just instantiate your own ContainerManager manually and use it directly.
    */ 
    class OG_FRAME_DLL ContainerManagerEnumerator
    {
	public:
		/// Scene manager instances, indexed by instance name
		typedef std::map<string, ContainerManager*> Instances;
		/// List of available scene manager types as meta data
		typedef std::vector<const ContainerManagerMetaData*> MetaDataList;
    private:
		/// Scene manager factories
		typedef std::list<ContainerManagerFactory*> Factories;
		Factories mFactories;
		Instances mInstances;
		/// Stored separately to allow iteration
		MetaDataList mMetaDataList;
		/// Factory for default scene manager
		DefaultContainerManagerFactory mDefaultFactory;
		/// Count of creations for auto-naming
		unsigned long mInstanceCreateCount;
		/// Currently assigned render system
    private:
        ContainerManagerEnumerator();
        ~ContainerManagerEnumerator();

	public:
		/** Register a new ContainerManagerFactory. 
		@remarks
			Plugins should call this to register as new ContainerManager providers.
		*/
		void addFactory(ContainerManagerFactory* fact);

		/** Remove a ContainerManagerFactory. 
		*/
		void removeFactory(ContainerManagerFactory* fact);

		/** Get more information about a given type of ContainerManager.
		@remarks
			The metadata returned tells you a few things about a given type 
			of ContainerManager, which can be created using a factory that has been
			registered already. 
		@param typeName The type name of the ContainerManager you want to enquire on.
			If you don't know the typeName already, you can iterate over the 
			metadata for all types using getMetaDataIterator.
		*/
		const ContainerManagerMetaData* getMetaData(const string& typeName) const;

		typedef ConstVectorIterator<MetaDataList> MetaDataIterator;
		/** Iterate over all types of ContainerManager available for construction, 
			providing some information about each one.
		*/
		MetaDataIterator getMetaDataIterator(void) const;

		/** Create a ContainerManager instance of a given type.
		@remarks
			You can use this method to create a ContainerManager instance of a 
			given specific type. You may know this type already, or you may
			have discovered it by looking at the results from getMetaDataIterator.
		@note
			This method throws an exception if the named type is not found.
		@param typeName string identifying a unique ContainerManager type
		@param instanceName Optional name to given the new instance that is
			created. If you leave this blank, an auto name will be assigned.
		*/
		ContainerManager* createContainerManager(const string& typeName, 
			const string& instanceName);

		/** Destroy an instance of a ContainerManager. */
		void destroyContainerManager(ContainerManager* sm);

		/** Get an existing ContainerManager instance that has already been created,
			identified by the instance name.
		@param instanceName The name of the instance to retrieve.
		*/
		ContainerManager* getContainerManager(const string& instanceName) const;

		typedef MapIterator<Instances> ContainerManagerIterator;
		/** Get an iterator over all the existing ContainerManager instances. */
		ContainerManagerIterator getContainerManagerIterator(void);

        /// Utility method to control shutdown of the managers
        void shutdownAll(void);
        /** Override standard Singleton retrieval.
        @remarks
        Why do we do this? Well, it's because the Singleton
        implementation is in a .h file, which means it gets compiled
        into anybody who includes it. This is needed for the
        Singleton template to work, but we actually only want it
        compiled into the implementation of the class based on the
        Singleton, not all of them. If we don't change this, we get
        link errors when trying to use the Singleton-based class from
        an outside dll.
        @par
        This method just delegates to the template version anyway,
        but the implementation stays in this single compilation unit,
        preventing link errors.
        */
        static ContainerManagerEnumerator& getSingleton(void);
        /** Override standard Singleton retrieval.
        @remarks
        Why do we do this? Well, it's because the Singleton
        implementation is in a .h file, which means it gets compiled
        into anybody who includes it. This is needed for the
        Singleton template to work, but we actually only want it
        compiled into the implementation of the class based on the
        Singleton, not all of them. If we don't change this, we get
        link errors when trying to use the Singleton-based class from
        an outside dll.
        @par
        This method just delegates to the template version anyway,
        but the implementation stays in this single compilation unit,
        preventing link errors.
        */
        static ContainerManagerEnumerator* getSingletonPtr(void);

    };

}
	

