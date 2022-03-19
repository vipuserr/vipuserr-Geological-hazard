#ifndef __MemoryNedPooling_H__
#define __MemoryNedPooling_H__


#define CORE_MEMORY_ALLOCATOR 4
#define CORE_MEMORY_ALLOCATOR_NEDPOOLING 4

#if CORE_MEMORY_ALLOCATOR == CORE_MEMORY_ALLOCATOR_NEDPOOLING

#include "ThreadDefine.h"
#include "ogstl_headers.h"
#include "ogPlatform.h"

namespace Smart3dMap
{
	/** \addtogroup Core
	*  @{
	*/
	/** \addtogroup Memory
	*  @{
	*/
	/** Non-templated utility class just to hide nedmalloc.
	*/
	class _ThreadExport NedPoolingImpl
	{
	public:
		static void* allocBytes(size_t count, 
			const char* file, int line, const char* func);
		static void deallocBytes(void* ptr);
		static void* allocBytesAligned(size_t align, size_t count, 
			const char* file, int line, const char* func);
		static void deallocBytesAligned(size_t align, void* ptr);

	};

	/**	An allocation policy for use with AllocatedObject and 
	STLAllocator. This is the class that actually does the allocation
	and deallocation of physical memory, and is what you will want to 
	provide a custom version of if you wish to change how memory is allocated.
	@par
	This allocation policy uses nedmalloc 
		(http://nedprod.com/programs/portable/nedmalloc/index.html). 
	*/
	class NedPoolingPolicy
	{
	public:
		static inline void* allocateBytes(size_t count, 
			const char* file = 0, int line = 0, const char* func = 0)
		{
			return NedPoolingImpl::allocBytes(count, file, line, func);
		}
		static inline void deallocateBytes(void* ptr)
		{
			NedPoolingImpl::deallocBytes(ptr);
		}
		/// Get the maximum size of a single allocation
		static inline size_t getMaxAllocationSize()
		{
			return (std::numeric_limits<size_t>::max)();
		}

	private:
		// No instantiation
		NedPoolingPolicy()
		{ }
	};


	/**	An allocation policy for use with AllocatedObject and 
	STLAllocator, which aligns memory at a given boundary (which should be
	a power of 2). This is the class that actually does the allocation
	and deallocation of physical memory, and is what you will want to 
	provide a custom version of if you wish to change how memory is allocated.
	@par
	This allocation policy uses nedmalloc 
		(http://nedprod.com/programs/portable/nedmalloc/index.html). 
	@note
		template parameter Alignment equal to zero means use default
		platform dependent alignment.
	*/
	template <size_t Alignment = 0>
	class NedPoolingAlignedPolicy
	{
	public:
		// compile-time check alignment is available.
		typedef int IsValidAlignment
			[Alignment <= 128 && ((Alignment & (Alignment-1)) == 0) ? +1 : -1];

		static inline void* allocateBytes(size_t count, 
			const char* file = 0, int line = 0, const char* func = 0)
		{
			return NedPoolingImpl::allocBytesAligned(Alignment, count, file, line, func);
		}

		static inline void deallocateBytes(void* ptr)
		{
			NedPoolingImpl::deallocBytesAligned(Alignment, ptr);
		}

		/// Get the maximum size of a single allocation
		static inline size_t getMaxAllocationSize()
		{
			return (std::numeric_limits<size_t>::max)();
		}
	private:
		// no instantiation allowed
		NedPoolingAlignedPolicy()
		{ }
	};




	/** @} */
	/** @} */

}// namespace Smart3dMap

#endif 

#endif // __MemoryNedPooling_H__

