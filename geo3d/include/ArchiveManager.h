#ifndef _ArchiveManager_H__
#define _ArchiveManager_H__


#include "ResourceManager.h"
#include "ArchiveFactory.h"

namespace Smart3dMap {

	/** \addtogroup Core
	*  @{
	*/
	/** \addtogroup Resources
	*  @{
	*/
    /** This class manages the available ArchiveFactory plugins. 
    */
    class _ThreadExport ArchiveManager : public ArchiveAlloc
    {
	private:
        /** Default constructor - should never get called by a client app.
        */
        ArchiveManager();
        /** Default destructor.
        */
        virtual ~ArchiveManager();

	public:
		static ArchiveManager& getSingleton(void);
		static ArchiveManager* getSingletonPtr(void);

    protected:
        typedef std::map<OC::String, ArchiveFactory*> ArchiveFactoryMap;
        /// Factories available to create archives, indexed by archive type (OC::String identifier e.g. 'Zip')
        ArchiveFactoryMap mArchFactories;
        /// Currently loaded archives
        typedef map<OC::String, CoreArchive*> ArchiveMap;
        ArchiveMap mArchives;


	public:
        /** Opens an archive for file reading.
            @remarks
                The archives are created using class factories within
                extension libraries.
            @param filename
                The filename that will be opened
            @param refLibrary
                The library that contains the data-handling code
            @return
                If the function succeeds, a valid pointer to an Archive
                object is returned.
            @par
                If the function fails, an exception is thrown.
        */
        CoreArchive* load( const OC::String& filename, const OC::String& archiveType);

		/** Unloads an archive.
		@remarks
			You must ensure that this archive is not being used before removing it.
		*/
		void unload(CoreArchive* arch);
		/** Unloads an archive by name.
		@remarks
			You must ensure that this archive is not being used before removing it.
		*/
		void unload(const OC::String& filename);
		typedef MapIterator<ArchiveMap> ArchiveMapIterator;
		/** Get an iterator over the Archives in this Manager. */
		ArchiveMapIterator getArchiveIterator(void);

        /** Adds a new ArchiveFactory to the list of available factories.
            @remarks
                Plugin developers who add new archive codecs need to call
                this after defining their ArchiveFactory subclass and
                Archive subclasses for their archive type.
        */
        void addArchiveFactory(ArchiveFactory* factory);
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
//        static ArchiveManager& getSingleton(void);
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
    };
	

}

#endif
