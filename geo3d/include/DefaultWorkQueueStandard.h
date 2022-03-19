#ifndef __OCDefaultWorkQueueStandard_H__
#define __OCDefaultWorkQueueStandard_H__

#include "WorkQueue.h"


class WorkQueueThread : public OpenThreads::Thread
{
public:
	WorkQueueThread(Smart3dMap::DefaultWorkQueueBase* q): mQueue(q)
	{

	}

	virtual ~WorkQueueThread()
	{

	}
	
	void operator()()
	{
		mQueue->_threadMain();
	}

	virtual void run()
	{
		mQueue->_threadMain();
	}

protected:
	bool _done;
	Smart3dMap::DefaultWorkQueueBase* mQueue;
};

namespace Smart3dMap
{
	/** Implementation of a general purpose request / response style background work queue.
	@remarks
		This default implementation of a work queue starts a thread pool and 
		provides queues to process requests. 
	*/
	class _ThreadExport DefaultWorkQueue : public DefaultWorkQueueBase
	{
	public:

		DefaultWorkQueue(const OC::String& name = OC::StringUtil::BLANK);
		virtual ~DefaultWorkQueue(); 

		/// Main function for each thread spawned.
		virtual void _threadMain();

		/// @copydoc WorkQueue::shutdown
		virtual void shutdown();

		/// @copydoc WorkQueue::startup
		virtual void startup(bool forceRestart = true);

	protected:
		/** To be called by a separate thread; will return immediately if there
			are items in the queue, or suspend the thread until new items are added
			otherwise.
		*/
		virtual void waitForNextRequest();

		/// Notify that a thread has registered itself with the render system
		virtual void notifyThreadRegistered();

		virtual void notifyWorkers();

		size_t mNumThreadsRegisteredWithRS;
		/// Init notification mutex (must lock before waiting on initCondition)
		CORE_MUTEX(mInitMutex);
		/// Synchroniser token to wait / notify on thread init 
		CORE_THREAD_SYNCHRONISER(mInitSync);

		CORE_THREAD_SYNCHRONISER(mRequestCondition);

		typedef std::vector<WorkQueueThread*> WorkerThreadList;
		WorkerThreadList mWorkers;
	};

}

#endif
