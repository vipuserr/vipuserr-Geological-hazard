#ifndef __Common_H__
#define __Common_H__
// Common stuff

#include "ThreadDefine.h"
#include "MemoryCategory.h"
#include "ogstl_headers.h"

#if defined ( CORE_GCC_VISIBILITY )
#   pragma GCC visibility push(default)
#endif

#include <utility>
#include <sstream>

#if defined ( CORE_GCC_VISIBILITY )
#   pragma GCC visibility pop
#endif

namespace Smart3dMap {
	/** \addtogroup Core
	*  @{
	*/
	/** \addtogroup General
	*  @{
	*/

	/// Fast general hashing algorithm
	uint32 _ThreadExport FastHash (const char * data, int len, uint32 hashSoFar = 0);
	/// Combine hashes with same style as boost::hash_combine
	template <typename T>
	uint32 HashCombine (uint32 hashSoFar, const T& data)
	{
		return FastHash((const char*)&data, sizeof(T), hashSoFar);
	}

	/** A hashed vector.
	*/
	template <typename T>
	class HashedVector
	{
	public:
		typedef std::vector<T, STLAllocator<T, GeneralAllocPolicy> > VectorImpl;
	protected:
		VectorImpl mList;
		mutable uint32 mListHash;
		mutable bool mListHashDirty;

		void addToHash(const T& newPtr) const
		{
			mListHash = FastHash((const char*)&newPtr, sizeof(T), mListHash);
		}
		void recalcHash() const
		{
			mListHash = 0;
			for (const_iterator i = mList.begin(); i != mList.end(); ++i)
				addToHash(*i);
			mListHashDirty = false;
			
		}

	public:
		typedef typename VectorImpl::value_type value_type;
		typedef typename VectorImpl::pointer pointer;
		typedef typename VectorImpl::reference reference;
		typedef typename VectorImpl::const_reference const_reference;
		typedef typename VectorImpl::size_type size_type;
		typedef typename VectorImpl::difference_type difference_type;
		typedef typename VectorImpl::iterator iterator;
		typedef typename VectorImpl::const_iterator const_iterator;
		typedef typename VectorImpl::reverse_iterator reverse_iterator;
		typedef typename VectorImpl::const_reverse_iterator const_reverse_iterator;

		void dirtyHash()
		{
			mListHashDirty = true;
		}
		bool isHashDirty() const
		{
			return mListHashDirty;
		}

		iterator begin() 
		{ 
			// we have to assume that hash needs recalculating on non-const
			dirtyHash();
			return mList.begin(); 
		}
		iterator end() { return mList.end(); }
		const_iterator begin() const { return mList.begin(); }
		const_iterator end() const { return mList.end(); }
		reverse_iterator rbegin() 
		{ 
			// we have to assume that hash needs recalculating on non-const
			dirtyHash();
			return mList.rbegin(); 
		}
		reverse_iterator rend() { return mList.rend(); }
		const_reverse_iterator rbegin() const { return mList.rbegin(); }
		const_reverse_iterator rend() const { return mList.rend(); }
		size_type size() const { return mList.size(); }
		size_type max_size() const { return mList.max_size(); }
		size_type capacity() const { return mList.capacity(); }
		bool empty() const { return mList.empty(); }
		reference operator[](size_type n) 
		{ 
			// we have to assume that hash needs recalculating on non-const
			dirtyHash();
			return mList[n]; 
		}
		const_reference operator[](size_type n) const { return mList[n]; }
		reference at(size_type n) 
		{ 
			// we have to assume that hash needs recalculating on non-const
			dirtyHash();
			return mList.const_iterator(n); 
		}
		const_reference at(size_type n) const { return mList.at(n); }
		HashedVector() : mListHash(0), mListHashDirty(false) {}
		HashedVector(size_type n) : mList(n), mListHash(0), mListHashDirty(n > 0) {}
		HashedVector(size_type n, const T& t) : mList(n, t), mListHash(0), mListHashDirty(n > 0) {}
		HashedVector(const HashedVector<T>& rhs) 
			: mList(rhs.mList), mListHash(rhs.mListHash), mListHashDirty(rhs.mListHashDirty) {}

		template <class InputIterator>
		HashedVector(InputIterator a, InputIterator b)
			: mList(a, b), mListHashDirty(false)
		{
			dirtyHash();
		}

		~HashedVector() {}
		HashedVector<T>& operator=(const HashedVector<T>& rhs)
		{
			mList = rhs.mList;
			mListHash = rhs.mListHash;
			mListHashDirty = rhs.mListHashDirty;
			return *this;
		}

		void reserve(size_t t) { mList.reserve(t); }
		reference front() 
		{ 
			// we have to assume that hash needs recalculating on non-const
			dirtyHash();
			return mList.front(); 
		}
		const_reference front() const { return mList.front(); }
		reference back()  
		{ 
			// we have to assume that hash needs recalculating on non-const
			dirtyHash();
			return mList.back(); 
		}
		const_reference back() const { return mList.back(); }
		void push_back(const T& t)
		{ 
			mList.push_back(t);
			// Quick progressive hash add
			if (!isHashDirty())
				addToHash(t);
		}
		void pop_back()
		{
			mList.pop_back();
			dirtyHash();
		}
		void swap(HashedVector<T>& rhs)
		{
			mList.swap(rhs.mList);
			dirtyHash();
		}
		iterator insert(iterator pos, const T& t)
		{
			bool recalc = (pos != end());
			iterator ret = mList.insert(pos, t);
			if (recalc)
				dirtyHash();
			else
				addToHash(t);
			return ret;
		}

		template <class InputIterator>
		void insert(iterator pos,
			InputIterator f, InputIterator l)
		{
			mList.insert(pos, f, l);
			dirtyHash();
		}

		void insert(iterator pos, size_type n, const T& x)
		{
			mList.insert(pos, n, x);
			dirtyHash();
		}

		iterator erase(iterator pos)
		{
			iterator ret = mList.erase(pos);
			dirtyHash();
			return ret;
		}
		iterator erase(iterator first, iterator last)
		{
			iterator ret = mList.erase(first, last);
			dirtyHash();
			return ret;
		}
		void clear()
		{
			mList.clear();
			mListHash = 0;
			mListHashDirty = false;
		}

		void resize(size_type n, const T& t = T())
		{
			bool recalc = false;
			if (n != size())
				recalc = true;

			mList.resize(n, t);
			if (recalc)
				dirtyHash();
		}

		bool operator==(const HashedVector<T>& b)
		{ return mListHash == b.mListHash; }

		bool operator<(const HashedVector<T>& b)
		{ return mListHash < b.mListHash; }


		/// Get the hash value
		uint32 getHash() const 
		{ 
			if (isHashDirty())
				recalcHash();

			return mListHash; 
		}
	public:



	};

	class Light;
	typedef HashedVector<Light*> LightList;



    typedef std::map<OC::String, bool> UnaryOptionList;
    typedef std::map<OC::String, OC::String> BinaryOptionList;

	/// Name / value parameter pair (first = name, second = value)
	typedef std::map<OC::String, OC::String> NameValuePairList;

	/// Utility class to generate a sequentially numbered series of names
	class _ThreadExport NameGenerator
	{
	protected:
		OC::String mPrefix;
		unsigned long long int mNext;
		CORE_AUTO_MUTEX
	public:
		NameGenerator(const NameGenerator& rhs)
			: mPrefix(rhs.mPrefix), mNext(rhs.mNext) {}
		
		NameGenerator(const OC::String& prefix) : mPrefix(prefix), mNext(1) {}

		/// Generate a new name
		OC::String generate()
		{
			CORE_LOCK_AUTO_MUTEX
			std::ostringstream s;
			s << mPrefix << mNext++;
			return s.str();
		}

		/// Reset the internal counter
		void reset()
		{
			CORE_LOCK_AUTO_MUTEX
			mNext = 1ULL;
		}

		/// Manually set the internal counter (use caution)
		void setNext(unsigned long long int val)
		{
			CORE_LOCK_AUTO_MUTEX
			mNext = val;
		}

		/// Get the internal counter
		unsigned long long int getNext() const
		{
			// lock even on get because 64-bit may not be atomic read
			CORE_LOCK_AUTO_MUTEX
			return mNext;
		}




	};

	/** Template class describing a simple pool of items.
	*/
	template <typename T>
	class Pool
	{
	protected:
		typedef typename std::list<T> ItemList;
		ItemList mItems;
		CORE_AUTO_MUTEX
	public:
		Pool() {} 
		virtual ~Pool() {}

		/** Get the next item from the pool.
		@return pair indicating whether there was a free item, and the item if so
		*/
		virtual std::pair<bool, T> removeItem()
		{
			CORE_LOCK_AUTO_MUTEX
			std::pair<bool, T> ret;
			if (mItems.empty())
			{
				ret.first = false;
			}
			else
			{
				ret.first = true;
				ret.second = mItems.front();
				mItems.pop_front();
			}
			return ret;
		}

		/** Add a new item to the pool. 
		*/
		virtual void addItem(const T& i)
		{
			CORE_LOCK_AUTO_MUTEX
			mItems.push_front(i);
		}
		/// Clear the pool
		virtual void clear()
		{
			CORE_LOCK_AUTO_MUTEX
			mItems.clear();
		}



	};
	/** @} */
	/** @} */
}

#endif
