#ifndef _SINGLETON_H__
#define _SINGLETON_H__

#pragma warning (disable : 4311)
#pragma warning (disable : 4312)
#pragma warning (disable : 4661)

#include "ogUtilityDefine.h"

namespace Smart3dMap {
    template <typename T> class Singleton
    {
	private:
		/** \brief Explicit private copy constructor. This is a forbidden operation.*/
		Singleton(const Singleton<T> &);

		/** \brief Private operator= . This is a forbidden operation. */
		Singleton& operator=(const Singleton<T> &);
	public:
        static T* ms_Singleton;
		Singleton(void)
		{
			ms_Singleton = static_cast< T* >( this );
		}
		~Singleton( void )
		{}
		static T& getSingleton( void )
		{	return ( *ms_Singleton); }
		static T* getSingletonPtr( void )
		{	return ms_Singleton; }

    };
	/** @} */
	/** @} */

}
#if defined ( CORE_GCC_VISIBILITY )
#   pragma GCC visibility pop
#endif

#endif
