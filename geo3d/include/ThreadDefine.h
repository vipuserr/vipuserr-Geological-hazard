#ifndef __OGThreadDefine_H__
#define __OGThreadDefine_H__

#if defined(_MSC_VER)
#ifndef OGTHREAD_EXPORTS
#define _ThreadExport  __declspec(dllimport)
#else
#define _ThreadExport  __declspec(dllexport)
#endif
#else
#define _ThreadExport
#endif

#include <OpenThreads/Mutex>
#include <OpenThreads/Thread>
#include <OpenThreads/Block>
#include <OpenThreads/ReadWriteMutex>
#include <OpenThreads/ReentrantMutex>
#include <OpenThreads/ScopedLock>
#include "ogStringUtil.h"


typedef unsigned char uchar;

namespace Smart3dMap
{
    template<class T> class SharedPtr;
    class WorkQueue;
    typedef float Real;
    typedef		unsigned __int32				uint32;
    typedef unsigned short uint16;
    typedef unsigned char uint8;
}

#define CORE_AUTO_MUTEX_NAME mutex
#define CORE_AUTO_MUTEX mutable OpenThreads::ReentrantMutex CORE_AUTO_MUTEX_NAME;
#define CORE_LOCK_AUTO_MUTEX OpenThreads::ScopedLock<OpenThreads::ReentrantMutex> coreAutoMutexLock(CORE_AUTO_MUTEX_NAME);

// like CORE_AUTO_MUTEX but mutex held by pointer
#define CORE_AUTO_SHARED_MUTEX mutable OpenThreads::ReentrantMutex *CORE_AUTO_MUTEX_NAME;
#define CORE_LOCK_AUTO_SHARED_MUTEX assert(CORE_AUTO_MUTEX_NAME); OpenThreads::ScopedLock<OpenThreads::ReentrantMutex> coreAutoMutexLock(*CORE_AUTO_MUTEX_NAME);
#define CORE_NEW_AUTO_SHARED_MUTEX assert(!CORE_AUTO_MUTEX_NAME); CORE_AUTO_MUTEX_NAME = new OpenThreads::ReentrantMutex();
#define CORE_DELETE_AUTO_SHARED_MUTEX assert(CORE_AUTO_MUTEX_NAME); delete CORE_AUTO_MUTEX_NAME;
#define CORE_COPY_AUTO_SHARED_MUTEX(from) assert(!CORE_AUTO_MUTEX_NAME); CORE_AUTO_MUTEX_NAME = from;
#define CORE_SET_AUTO_SHARED_MUTEX_NULL CORE_AUTO_MUTEX_NAME = 0;
#define CORE_MUTEX_CONDITIONAL(mutex) if (mutex)
#define CORE_THREAD_SYNCHRONISER(sync) OpenThreads::Condition sync;
#define CORE_THREAD_WAIT(sync, mutex, lock) sync.wait(&mutex);
#define CORE_THREAD_NOTIFY_ONE(sync) sync.signal(); 
#define CORE_THREAD_NOTIFY_ALL(sync) sync.broadcast(); 
// Read-write mutex
#define CORE_RW_MUTEX(name) mutable OpenThreads::ReadWriteMutex name;
#define CORE_LOCK_RW_MUTEX_READ(name) OpenThreads::ScopedReadLock corenameLock(name);
#define CORE_LOCK_RW_MUTEX_WRITE(name) OpenThreads::ScopedWriteLock corenameLock(name);
// Thread objects and related functions
#define CORE_THREAD_TYPE OpenThreads::Thread

/*
#define CORE_THREAD_CREATE(name, worker) OpenThreads::Thread* name = CORE_NEW_T(boost::thread, MEMCATEGORY_GENERAL)(worker);
#define CORE_THREAD_DESTROY(name) CORE_DELETE_T(name, thread, MEMCATEGORY_GENERAL)
#define CORE_THREAD_HARDWARE_CONCURRENCY boost::thread::hardware_concurrency()
#define CORE_THREAD_CURRENT_ID boost::this_thread::get_id()
#define CORE_THREAD_WORKER_INHERIT
// Utility
#define CORE_THREAD_SLEEP(ms) boost::this_thread::sleep(boost::posix_time::millisec(ms));
*/

#define CORE_MUTEX(name) OpenThreads::ReentrantMutex name;
#define CORE_STATIC_MUTEX(name) static OpenThreads::ReentrantMutex name;
#define CORE_STATIC_MUTEX_INSTANCE(name) OpenThreads::ReentrantMutex name;
#define CORE_LOCK_MUTEX(name) OpenThreads::ScopedLock<OpenThreads::ReentrantMutex> exclusive(name);
#define CORE_LOCK_MUTEX_NAMED(mutexName, lockName) OpenThreads::ScopedLock<OpenThreads::ReentrantMutex> lockName(mutexName);

#endif