#ifndef _ArchiveFactory_H__
#define _ArchiveFactory_H__

#include "FactoryObj.h"

namespace Smart3dMap {

	/** \addtogroup Core
	*  @{
	*/
	/** \addtogroup Resources
	*  @{
	*/
    /** Abstract factory class, archive codec plugins can register concrete
        subclasses of this.
        @remarks
            All access to 'archives' (collections of files, compressed or
            just folders, maybe even remote) is managed via the abstract
            Archive class. Plugins are expected to provide the
            implementation for the actual codec itself, but because a
            subclass of Archive has to be created for every archive, a
            factory class is required to create the appropriate subclass.
        @par
            So archive plugins create a subclass of Archive AND a subclass
            of ArchiveFactory which creates instances of the Archive
            subclass. See the 'Zip' and 'FileSystem' plugins for examples.
            Each Archive and ArchiveFactory subclass pair deal with a
            single archive type (identified by a OC::String).
    */
    class _ThreadExport ArchiveFactory : public FactoryObj< CoreArchive >, public ArchiveAlloc
    {
    public:
        virtual ~ArchiveFactory() {}
        // No methods, must just override all methods inherited from FactoryObj
    };
	/** @} */
	/** @} */

} // namespace

#endif
