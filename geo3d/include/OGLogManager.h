#pragma once

#include <string>
#include <fstream>
#include <map>
#include <vector>

#include "OGBasDef.h"

#pragma warning(disable : 4786)


namespace Smart3dMap {

// 当LogMessageLevel + LoggingLevel >= KERNEL_LOG_THRESHOLD 表示此信息将被记录在日志中
#define KERNEL_LOG_THRESHOLD 4

/** 日志文件的重要程度
*/
enum LoggingLevel
{
	LL_LOW = 1,			// 低
	LL_NORMAL = 2,		// 中
	LL_BOREME = 3		// 高
};

/** 日志中将写入信息的重要程度
*/
enum LogMessageLevel
{
	LML_TRIVIAL = 1,	// 低
	LML_NORMAL = 2,		// 中
	LML_CRITICAL = 3	// 高
};

class OG_FRAME_DLL Log  
{
protected:
	std::ofstream	mfpLog;
	LoggingLevel	mLogLevel;
	bool			mDebugOut;
	bool			mSuppressFile;
	std::string		mName;
	
public:
	/** 构造函数 - 由LogManager进行调用.
	*/
	Log( const std::string& name, bool debugOutput = true, bool suppressFileOutput = false);
	
	/** 析构函数
	*/
	~Log();
	
	/** 将信息写入Log文件和调试信息中，默认日志文件为G3D.log
	*/
	void logMessage(
		const std::string& message,
		LogMessageLevel lml = LML_NORMAL, 
		bool maskDebug = false);
	
    /** 设置日志文件的重要程度
	*/
	void setLogDetail(LoggingLevel ll);
};

    /** Log监听器
	*/
class OG_FRAME_DLL LogListener
{
public:
	/** 当信息需要输出的时候，由log系统进行调用
	*/
	virtual void write( const std::string& name,
						const std::string& message, 
						LogMessageLevel lml = LML_NORMAL, 
						bool maskDebug = false ) = 0;
	virtual ~LogListener();
};

class OG_FRAME_DLL LogManager
{
public:
	friend class Log;

private:
		LogManager();
		~LogManager();


protected:
	void _routeMessage(	const std::string& name,
							const std::string& message, 
							LogMessageLevel lml = LML_NORMAL, 
							bool maskDebug = false );

        typedef std::map<std::string, Log*, std::less<std::string> >	LogList;
		typedef std::vector<LogListener*>								LogListenerList;

        /// 管理器可访问到的所用Log列表
        LogList mLogs;

        /// 信息输出到的默认Log对象
        Log* mDefaultLog;

		/// 所有已注册的外部日志监听LogListener列表
		LogListenerList mListeners;

    public:
		// 获取日志管理器
		static LogManager& getSingleton(void);
		static LogManager* getSingletonPtr(void);

		/** 添加一个新的日志监听器
		*/
		void addListener( LogListener * listener );
		
		/** 删除日志监听器
		*/
		void removeListener( LogListener * listener );

        /** 创建一个给定名称日志文件
            @参数：name
                给定的日志名称
            @参数：defaultLog 
                指定是否为默认Log文件
				注：第一个创建的日志文件为默认日志文件
            @参数：debuggerOutput 
                如果为true，则不只向日志文件中输出信息，还向调试窗口中输出信息
            @参数：suppressFileOutput 
                如果为true，则不会创建一个实际的Log文件，并且不会写文件；
				进行此设置时，应注册一个LogListener，以便输出信息不会丢失。
        */
        Log* createLog( const std::string& name, bool defaultLog = false, bool debuggerOutput = true, 
			bool suppressFileOutput = false);

        /** 通过名称获取Log对象
        */
        Log* getLog( const std::string& name);

        /** 返回默认Log对象的指针
        */
        Log* getDefaultLog();

        /** 将指定Log设为默认Log文件
		@返回值：
			前一个默认Log的指针
        */
        Log* setDefaultLog(Log* newLog);

        /** 向Log文件中导入信息
			@参数：message
				写入Log文件中的信息内容
			@参数：lml
				Log信息重要程度
			@参数：maskDebug
				是否将信息输出至调试窗口中，默认为不输出
        */
        void logMessage( const std::string& message, LogMessageLevel lml = LML_NORMAL, 
            bool maskDebug = false);

        /** 向默认Log文件中导入信息
        */
        void logMessage( LogMessageLevel lml, const std::string& message,  
			bool maskDebug = false) { logMessage(message, lml, maskDebug); }

		/** 设置默认Log文件的重要程度
        */
        void setLogDetail(LoggingLevel ll);

};
}