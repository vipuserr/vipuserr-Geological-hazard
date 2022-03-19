#ifndef __DataStream_H__
#define __DataStream_H__

#include "SharedPtr.h"
#include <istream>
#include <osgDB/fstream>

namespace Smart3dMap {
	
	/** Template version of cache based on static array.
	 'cacheSize' defines size of cache in bytes. */
	template <size_t cacheSize>
	class StaticCache
	{
	protected:
		/// Static buffer
		char mBuffer[cacheSize];
		
		/// Number of bytes valid in cache (written from the beginning of static buffer)
		size_t mValidBytes;
		/// Current read position
		size_t mPos;
		
	public:
		/// Constructor
		StaticCache()
		{
			mValidBytes = 0;
			mPos = 0;
		}
		
		/** Cache data pointed by 'buf'. If 'count' is greater than cache size, we cache only last bytes.
		 Returns number of bytes written to cache. */
		size_t cacheData(const void* buf, size_t count)
		{
			assert(avail() == 0 && "It is assumed that you cache data only after you have read everything.");
			
			if (count < cacheSize)
			{
				// number of bytes written is less than total size of cache
				if (count + mValidBytes <= cacheSize)
				{
					// just append
					memcpy(mBuffer + mValidBytes, buf, count);
					mValidBytes += count;
				}
				else
				{
					size_t begOff = count - (cacheSize - mValidBytes);
					// override old cache content in the beginning
					memmove(mBuffer, mBuffer + begOff, mValidBytes - begOff);
					// append new data
					memcpy(mBuffer + cacheSize - count, buf, count);
					mValidBytes = cacheSize;
				}
				mPos = mValidBytes;
				return count;
			}
			else
			{
				// discard all
				memcpy(mBuffer, (const char*)buf + count - cacheSize, cacheSize);
				mValidBytes = mPos = cacheSize;
				return cacheSize;
			}
		}
		/** Read data from cache to 'buf' (maximum 'count' bytes). Returns number of bytes read from cache. */
		size_t read(void* buf, size_t count)
		{
			size_t rb = avail();
			rb = (rb < count) ? rb : count;
			memcpy(buf, mBuffer + mPos, rb);
			mPos += rb;
			return rb;
		}
		
		/** Step back in cached stream by 'count' bytes. Returns 'true' if cache contains resulting position. */
		bool rewind(size_t count)
		{
			if (mPos < count)
			{
				clear();
				return false;
			}
			else
			{
				mPos -= count;
				return true;
			}
		}
		/** Step forward in cached stream by 'count' bytes. Returns 'true' if cache contains resulting position. */
		bool ff(size_t count)
		{
			if (avail() < count)
			{
				clear();
				return false;
			}
			else
			{
				mPos += count;
				return true;
			}
		}
		
		/** Returns number of bytes available for reading in cache after rewinding. */
		size_t avail() const
		{
			return mValidBytes - mPos;
		}
		
		/** Clear the cache */
		void clear()
		{
			mValidBytes = 0;
			mPos = 0;
		}
	};
	
	class _ThreadExport DataStream : public StreamAlloc
	{
	public:
		enum AccessMode
		{
			READ = 1, 
			WRITE = 2
		};
	protected:
		/// The name (e.g. resource name) that can be used to identify the source fot his data (optional)
		OC::String mName;		
        /// Size of the data in the stream (may be 0 if size cannot be determined)
        size_t mSize;
		/// What type of access is allowed (AccessMode)
		uint16 mAccess;

        #define CORE_STREAM_TEMP_SIZE 128
	public:
		/// Constructor for creating unnamed streams
        DataStream(uint16 accessMode = READ) : mSize(0), mAccess(accessMode) {}
		/// Constructor for creating named streams
		DataStream(const OC::String& name, uint16 accessMode = READ) 
			: mName(name), mSize(0), mAccess(accessMode) {}
		/// Returns the name of the stream, if it has one.
		const OC::String& getName(void) { return mName; }
		/// Gets the access mode of the stream
		uint16 getAccessMode() const { return mAccess; }
		/** Reports whether this stream is readable. */
		virtual bool isReadable() const { return (mAccess & READ) != 0; }
		/** Reports whether this stream is writeable. */
		virtual bool isWriteable() const { return (mAccess & WRITE) != 0; }
        virtual ~DataStream() {}
		// Streaming operators
        template<typename T> DataStream& operator>>(T& val);
		/** Read the requisite number of bytes from the stream, 
			stopping at the end of the file.
		@param buf Reference to a buffer pointer
		@param count Number of bytes to read
		@return The number of bytes read
		*/
		virtual size_t read(void* buf, size_t count) = 0;
		/** Write the requisite number of bytes from the stream (only applicable to 
			streams that are not read-only)
		@param buf Pointer to a buffer containing the bytes to write
		@param count Number of bytes to write
		@return The number of bytes written
		*/
		virtual size_t write(const void* buf, size_t count)
		{
                        (void)buf;
                        (void)count;
			// default to not supported
			return 0;
		}

		/** Get a single line from the stream.
		@remarks
			The delimiter character is not included in the data
			returned, and it is skipped over so the next read will occur
			after it. The buffer contents will include a
			terminating character.
        @note
            If you used this function, you <b>must</b> open the stream in <b>binary mode</b>,
            otherwise, it'll produce unexpected results.
		@param buf Reference to a buffer pointer
		@param maxCount The maximum length of data to be read, excluding the terminating character
		@param delim The delimiter to stop at
		@return The number of bytes read, excluding the terminating character
		*/
		virtual size_t readLine(char* buf, size_t maxCount, const OC::String& delim = "\n");
		
	    /** Returns a OC::String containing the next line of data, optionally 
		    trimmed for whitespace. 
	    @remarks
		    This is a convenience method for text streams only, allowing you to 
		    retrieve a OC::String object containing the next line of data. The data
		    is read up to the next newline character and the result trimmed if
		    required.
        @note
            If you used this function, you <b>must</b> open the stream in <b>binary mode</b>,
            otherwise, it'll produce unexpected results.
	    @param 
		    trimAfter If true, the line is trimmed for whitespace (as in 
		    OC::String.trim(true,true))
	    */
	    virtual OC::String getLine( bool trimAfter = true );

	    /** Returns a OC::String containing the entire stream. 
	    @remarks
		    This is a convenience method for text streams only, allowing you to 
		    retrieve a OC::String object containing all the data in the stream.
	    */
	    virtual OC::String getAsString(void);

		/** Skip a single line from the stream.
        @note
            If you used this function, you <b>must</b> open the stream in <b>binary mode</b>,
            otherwise, it'll produce unexpected results.
		@param delim The delimiter(s) to stop at
		@return The number of bytes skipped
		*/
		virtual size_t skipLine(const OC::String& delim = "\n");

		/** Skip a defined number of bytes. This can also be a negative value, in which case
		the file pointer rewinds a defined number of bytes. */
		virtual void skip(long count) = 0;
	
		/** Repositions the read point to a specified byte.
	    */
	    virtual void seek( size_t pos ) = 0;
		
		/** Returns the current byte offset from beginning */
	    virtual size_t tell(void) const = 0;

		/** Returns true if the stream has reached the end.
	    */
	    virtual bool eof(void) const = 0;

		/** Returns the total size of the data to be read from the stream, 
			or 0 if this is indeterminate for this stream. 
		*/
        size_t size(void) const { return mSize; }

        /** Close the stream; this makes further operations invalid. */
		virtual void close(void) = 0;
		

	};

	/** Shared pointer to allow data streams to be passed around without
		worrying about deallocation
	*/
	typedef SharedPtr<DataStream> DataStreamPtr;

	/// List of DataStream items
	typedef std::list<DataStreamPtr> DataStreamList;
	/// Shared pointer to list of DataStream items
	typedef SharedPtr<DataStreamList> DataStreamListPtr;

	/** Common subclass of DataStream for handling data from chunks of memory.
	*/
	class _ThreadExport MemoryDataStream : public DataStream
	{
	protected:
        /// Pointer to the start of the data area
	    uchar* mData;
        /// Pointer to the current position in the memory
	    uchar* mPos;
        /// Pointer to the end of the memory
	    uchar* mEnd;
        /// Do we delete the memory on close
		bool mFreeOnClose;			
	public:
		MemoryDataStream(OC::StringStream* s, bool freeOnClose = true, bool readOnly = false);
		
		/** Wrap an existing memory chunk in a stream.
		@param pMem Pointer to the existing memory
		@param size The size of the memory chunk in bytes
		@param freeOnClose If true, the memory associated will be destroyed
			when the stream is destroyed. Note: it's important that if you set
			this option to true, that you allocated the memory using OGRE_ALLOC_T
			with a category of MEMCATEGORY_GENERAL ensure the freeing of memory 
			matches up.
		@param readOnly Whether to make the stream on this memory read-only once created
		*/
		MemoryDataStream(void* pMem, size_t size, bool freeOnClose = false, bool readOnly = false);
		
		/** Wrap an existing memory chunk in a named stream.
		@param name The name to give the stream
		@param pMem Pointer to the existing memory
		@param size The size of the memory chunk in bytes
		@param freeOnClose If true, the memory associated will be destroyed
			when the stream is destroyed. Note: it's important that if you set
			this option to true, that you allocated the memory using OGRE_ALLOC_T
			with a category of MEMCATEGORY_GENERAL ensure the freeing of memory 
			matches up.
		@param readOnly Whether to make the stream on this memory read-only once created
		*/
		MemoryDataStream(const OC::String& name, void* pMem, size_t size, 
				bool freeOnClose = false, bool readOnly = false);

		/** Create a stream which pre-buffers the contents of another stream.
		@remarks
			This constructor can be used to intentionally read in the entire
			contents of another stream, copying them to the internal buffer
			and thus making them available in memory as a single unit.
		@param sourceStream Another DataStream which will provide the source
			of data
		@param freeOnClose If true, the memory associated will be destroyed
			when the stream is destroyed.
		@param readOnly Whether to make the stream on this memory read-only once created
		*/
		MemoryDataStream(DataStream& sourceStream, 
				bool freeOnClose = true, bool readOnly = false);
		
		/** Create a stream which pre-buffers the contents of another stream.
		@remarks
			This constructor can be used to intentionally read in the entire
			contents of another stream, copying them to the internal buffer
			and thus making them available in memory as a single unit.
		@param sourceStream Weak reference to another DataStream which will provide the source
			of data
		@param freeOnClose If true, the memory associated will be destroyed
			when the stream is destroyed.
		@param readOnly Whether to make the stream on this memory read-only once created
		*/
		MemoryDataStream(DataStreamPtr& sourceStream, 
				bool freeOnClose = true, bool readOnly = false);

		/** Create a named stream which pre-buffers the contents of 
			another stream.
		@remarks
			This constructor can be used to intentionally read in the entire
			contents of another stream, copying them to the internal buffer
			and thus making them available in memory as a single unit.
		@param name The name to give the stream
		@param sourceStream Another DataStream which will provide the source
			of data
		@param freeOnClose If true, the memory associated will be destroyed
			when the stream is destroyed.
		@param readOnly Whether to make the stream on this memory read-only once created
		*/
		MemoryDataStream(const OC::String& name, DataStream& sourceStream, 
				bool freeOnClose = true, bool readOnly = false);

        /** Create a named stream which pre-buffers the contents of 
        another stream.
        @remarks
        This constructor can be used to intentionally read in the entire
        contents of another stream, copying them to the internal buffer
        and thus making them available in memory as a single unit.
        @param name The name to give the stream
        @param sourceStream Another DataStream which will provide the source
        of data
        @param freeOnClose If true, the memory associated will be destroyed
        when the stream is destroyed.
		@param readOnly Whether to make the stream on this memory read-only once created
        */
        MemoryDataStream(const OC::String& name, const DataStreamPtr& sourceStream, 
            bool freeOnClose = true, bool readOnly = false);

        /** Create a stream with a brand new empty memory chunk.
		@param size The size of the memory chunk to create in bytes
		@param freeOnClose If true, the memory associated will be destroyed
			when the stream is destroyed.
		@param readOnly Whether to make the stream on this memory read-only once created
		*/
		MemoryDataStream(size_t size, bool freeOnClose = true, bool readOnly = false);
		/** Create a named stream with a brand new empty memory chunk.
		@param name The name to give the stream
		@param size The size of the memory chunk to create in bytes
		@param freeOnClose If true, the memory associated will be destroyed
			when the stream is destroyed.
		@param readOnly Whether to make the stream on this memory read-only once created
		*/
		MemoryDataStream(const OC::String& name, size_t size, 
				bool freeOnClose = true, bool readOnly = false);

		~MemoryDataStream();

		/** Get a pointer to the start of the memory block this stream holds. */
		uchar* getPtr(void) { return mData; }
		
		/** Get a pointer to the current position in the memory block this stream holds. */
		uchar* getCurrentPtr(void) { return mPos; }
		
		/** @copydoc DataStream::read
		*/
		size_t read(void* buf, size_t count);

		/** @copydoc DataStream::write
		*/
		size_t write(const void* buf, size_t count);

		/** @copydoc DataStream::readLine
		*/
		size_t readLine(char* buf, size_t maxCount, const OC::String& delim = "\n");
		
		/** @copydoc DataStream::skipLine
		*/
		size_t skipLine(const OC::String& delim = "\n");

		/** @copydoc DataStream::skip
		*/
		void skip(long count);
	
		/** @copydoc DataStream::seek
		*/
	    void seek( size_t pos );
		
		/** @copydoc DataStream::tell
		*/
	    size_t tell(void) const;

		/** @copydoc DataStream::eof
		*/
	    bool eof(void) const;

        /** @copydoc DataStream::close
        */
        void close(void);

		/** Sets whether or not to free the encapsulated memory on close. */
		void setFreeOnClose(bool free) { mFreeOnClose = free; }
	};

    /** Shared pointer to allow memory data streams to be passed around without
    worrying about deallocation
    */
    typedef SharedPtr<MemoryDataStream> MemoryDataStreamPtr;

    /** Common subclass of DataStream for handling data from 
		std::basic_istream.
	*/
	class _ThreadExport FileStreamDataStream : public DataStream
	{
	protected:
		/// Reference to source stream (read)
		std::istream* mInStream;
		/// Reference to source file stream (read-only)
		osgDB::ifstream* mFStreamRO;
		/// Reference to source file stream (read-write)
		std::fstream* mFStream;
        bool mFreeOnClose;	

		void determineAccess();
	public:
		/** Construct a read-only stream from an STL stream
        @param s Pointer to source stream
        @param freeOnClose Whether to delete the underlying stream on 
            destruction of this class
        */
		FileStreamDataStream(osgDB::ifstream* s, 
            bool freeOnClose = true);

		/** Construct a read-write stream from an STL stream
		@param s Pointer to source stream
		@param freeOnClose Whether to delete the underlying stream on 
		destruction of this class
		*/
		FileStreamDataStream(std::fstream* s, 
			bool freeOnClose = true);

		/** Construct named read-only stream from an STL stream
        @param name The name to give this stream
        @param s Pointer to source stream
        @param freeOnClose Whether to delete the underlying stream on 
            destruction of this class
        */
		FileStreamDataStream(const OC::String& name, 
            osgDB::ifstream* s, 
            bool freeOnClose = true);

		/** Construct named read-write stream from an STL stream
		@param name The name to give this stream
		@param s Pointer to source stream
		@param freeOnClose Whether to delete the underlying stream on 
		destruction of this class
		*/
		FileStreamDataStream(const OC::String& name, 
			std::fstream* s, 
			bool freeOnClose = true);

		/** Construct named read-only stream from an STL stream, and tell it the size
        @remarks
            This variant tells the class the size of the stream too, which 
            means this class does not need to seek to the end of the stream 
            to determine the size up-front. This can be beneficial if you have
            metadata about the contents of the stream already.
        @param name The name to give this stream
        @param s Pointer to source stream
        @param size Size of the stream contents in bytes
        @param freeOnClose Whether to delete the underlying stream on 
            destruction of this class. If you specify 'true' for this you
			must ensure that the stream was allocated using OGRE_NEW_T with 
			MEMCATEGRORY_GENERAL.
        */
		FileStreamDataStream(const OC::String& name, 
            osgDB::ifstream* s, 
            size_t size, 
            bool freeOnClose = true);

		/** Construct named read-write stream from an STL stream, and tell it the size
		@remarks
		This variant tells the class the size of the stream too, which 
		means this class does not need to seek to the end of the stream 
		to determine the size up-front. This can be beneficial if you have
		metadata about the contents of the stream already.
		@param name The name to give this stream
		@param s Pointer to source stream
		@param size Size of the stream contents in bytes
		@param freeOnClose Whether to delete the underlying stream on 
		destruction of this class. If you specify 'true' for this you
		must ensure that the stream was allocated using OGRE_NEW_T with 
		MEMCATEGRORY_GENERAL.
		*/
		FileStreamDataStream(const OC::String& name, 
			std::fstream* s, 
			size_t size, 
			bool freeOnClose = true);

		~FileStreamDataStream();

		/** @copydoc DataStream::read
		*/
		size_t read(void* buf, size_t count);

		/** @copydoc DataStream::write
		*/
		size_t write(const void* buf, size_t count);

		/** @copydoc DataStream::readLine
		*/
        size_t readLine(char* buf, size_t maxCount, const OC::String& delim = "\n");
		
		/** @copydoc DataStream::skip
		*/
		void skip(long count);
	
		/** @copydoc DataStream::seek
		*/
	    void seek( size_t pos );

		/** @copydoc DataStream::tell
		*/
		size_t tell(void) const;

		/** @copydoc DataStream::eof
		*/
	    bool eof(void) const;

        /** @copydoc DataStream::close
        */
        void close(void);
		
		
	};

	
	/** @} */
	/** @} */
}
#endif
