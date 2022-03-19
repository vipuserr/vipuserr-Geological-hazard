#ifndef __FileSystem_H__
#define __FileSystem_H__

#include "Archive.h"
#include "ArchiveFactory.h"

namespace Smart3dMap {

	/** \addtogroup Core
	*  @{
	*/
	/** \addtogroup Resources
	*  @{
	*/
	/** Specialisation of the Archive class to allow reading of files from 
        filesystem folders / directories.
    */
    class _ThreadExport FileSystemArchive : public CoreArchive 
    {
    protected:
        /** Utility method to retrieve all files in a directory matching pattern.
        @param pattern File pattern
        @param recursive Whether to cascade down directories
        @param dirs Set to true if you want the directories to be listed
            instead of files
        @param simpleList Populated if retrieving a simple list
        @param detailList Populated if retrieving a detailed list
        @param currentDir The current directory relative to the base of the 
            archive, for file naming
        */
        void findFiles(const OC::String& pattern, bool recursive, bool dirs,
            OC::StringVector* simpleList, FileInfoList* detailList) const;

		CORE_AUTO_MUTEX
    public:
        FileSystemArchive(const OC::String& name, const OC::String& archType );
        ~FileSystemArchive();

        /// @copydoc Archive::isCaseSensitive
        bool isCaseSensitive(void) const;

        /// @copydoc Archive::load
        void load();
        /// @copydoc Archive::unload
        void unload();

        /// @copydoc Archive::open
        DataStreamPtr open(const OC::String& filename, bool readOnly = true) const;

		/// @copydoc Archive::create
		DataStreamPtr create(const OC::String& filename) const;

		/// @copydoc Archive::delete
		void remove(const OC::String& filename) const;

		/// @copydoc Archive::list
        StringVectorPtr list(bool recursive = true, bool dirs = false);

        /// @copydoc Archive::listFileInfo
        FileInfoListPtr listFileInfo(bool recursive = true, bool dirs = false);

        /// @copydoc Archive::find
        StringVectorPtr find(const OC::String& pattern, bool recursive = true,
            bool dirs = false);

        /// @copydoc Archive::findFileInfo
        FileInfoListPtr findFileInfo(const OC::String& pattern, bool recursive = true,
            bool dirs = false) const;

        /// @copydoc Archive::exists
        bool exists(const OC::String& filename);

		/// @copydoc Archive::getModifiedTime
		time_t getModifiedTime(const OC::String& filename);

		/// Set whether filesystem enumeration will include hidden files or not.
		/// This should be called prior to declaring and/or initializing filesystem
		/// resource locations. The default is true (ignore hidden files).
		static void setIgnoreHidden(bool ignore)
		{
			msIgnoreHidden = ignore;
		}

		/// Get whether hidden files are ignored during filesystem enumeration.
		static bool getIgnoreHidden()
		{
			return msIgnoreHidden;
		}

		static bool msIgnoreHidden;
    };

    /** Specialisation of ArchiveFactory for FileSystem files. */
    //class _OgrePrivate FileSystemArchiveFactory : public ArchiveFactory
    class _ThreadExport FileSystemArchiveFactory : public ArchiveFactory
    {
    public:
        virtual ~FileSystemArchiveFactory() {}
        /// @copydoc FactoryObj::getType
        const OC::String& getType(void) const;
        /// @copydoc FactoryObj::createInstance
        CoreArchive *createInstance( const OC::String& name ) 
        {
            return new FileSystemArchive(name, "FileSystem");
        }
        /// @copydoc FactoryObj::destroyInstance
        void destroyInstance( CoreArchive* arch) { delete arch; }
    };

	/** @} */
	/** @} */

}

#endif
