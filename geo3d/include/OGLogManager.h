#pragma once

#include <string>
#include <fstream>
#include <map>
#include <vector>

#include "OGBasDef.h"

#pragma warning(disable : 4786)


namespace Smart3dMap {

// ��LogMessageLevel + LoggingLevel >= KERNEL_LOG_THRESHOLD ��ʾ����Ϣ������¼����־��
#define KERNEL_LOG_THRESHOLD 4

/** ��־�ļ�����Ҫ�̶�
*/
enum LoggingLevel
{
	LL_LOW = 1,			// ��
	LL_NORMAL = 2,		// ��
	LL_BOREME = 3		// ��
};

/** ��־�н�д����Ϣ����Ҫ�̶�
*/
enum LogMessageLevel
{
	LML_TRIVIAL = 1,	// ��
	LML_NORMAL = 2,		// ��
	LML_CRITICAL = 3	// ��
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
	/** ���캯�� - ��LogManager���е���.
	*/
	Log( const std::string& name, bool debugOutput = true, bool suppressFileOutput = false);
	
	/** ��������
	*/
	~Log();
	
	/** ����Ϣд��Log�ļ��͵�����Ϣ�У�Ĭ����־�ļ�ΪG3D.log
	*/
	void logMessage(
		const std::string& message,
		LogMessageLevel lml = LML_NORMAL, 
		bool maskDebug = false);
	
    /** ������־�ļ�����Ҫ�̶�
	*/
	void setLogDetail(LoggingLevel ll);
};

    /** Log������
	*/
class OG_FRAME_DLL LogListener
{
public:
	/** ����Ϣ��Ҫ�����ʱ����logϵͳ���е���
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

        /// �������ɷ��ʵ�������Log�б�
        LogList mLogs;

        /// ��Ϣ�������Ĭ��Log����
        Log* mDefaultLog;

		/// ������ע����ⲿ��־����LogListener�б�
		LogListenerList mListeners;

    public:
		// ��ȡ��־������
		static LogManager& getSingleton(void);
		static LogManager* getSingletonPtr(void);

		/** ���һ���µ���־������
		*/
		void addListener( LogListener * listener );
		
		/** ɾ����־������
		*/
		void removeListener( LogListener * listener );

        /** ����һ������������־�ļ�
            @������name
                ��������־����
            @������defaultLog 
                ָ���Ƿ�ΪĬ��Log�ļ�
				ע����һ����������־�ļ�ΪĬ����־�ļ�
            @������debuggerOutput 
                ���Ϊtrue����ֻ����־�ļ��������Ϣ��������Դ����������Ϣ
            @������suppressFileOutput 
                ���Ϊtrue���򲻻ᴴ��һ��ʵ�ʵ�Log�ļ������Ҳ���д�ļ���
				���д�����ʱ��Ӧע��һ��LogListener���Ա������Ϣ���ᶪʧ��
        */
        Log* createLog( const std::string& name, bool defaultLog = false, bool debuggerOutput = true, 
			bool suppressFileOutput = false);

        /** ͨ�����ƻ�ȡLog����
        */
        Log* getLog( const std::string& name);

        /** ����Ĭ��Log�����ָ��
        */
        Log* getDefaultLog();

        /** ��ָ��Log��ΪĬ��Log�ļ�
		@����ֵ��
			ǰһ��Ĭ��Log��ָ��
        */
        Log* setDefaultLog(Log* newLog);

        /** ��Log�ļ��е�����Ϣ
			@������message
				д��Log�ļ��е���Ϣ����
			@������lml
				Log��Ϣ��Ҫ�̶�
			@������maskDebug
				�Ƿ���Ϣ��������Դ����У�Ĭ��Ϊ�����
        */
        void logMessage( const std::string& message, LogMessageLevel lml = LML_NORMAL, 
            bool maskDebug = false);

        /** ��Ĭ��Log�ļ��е�����Ϣ
        */
        void logMessage( LogMessageLevel lml, const std::string& message,  
			bool maskDebug = false) { logMessage(message, lml, maskDebug); }

		/** ����Ĭ��Log�ļ�����Ҫ�̶�
        */
        void setLogDetail(LoggingLevel ll);

};
}