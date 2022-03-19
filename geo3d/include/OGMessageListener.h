#pragma once 
 


#include <vector>
#include <string>
using namespace std;

#include "ogUtilityDefine.h"

namespace Smart3dMap
{
	//��������
	class _UtilityExport COGListener
	{
	public:
		COGListener();
		virtual ~COGListener();

	public:
		//ע����Ϣ���� (��������麯������Ӧ������һ��)
		virtual void registerIntMsg(){ }
		virtual void registerStrMsg(){ }

		//�ַ���������Ϣ����
		virtual long OnMessagePro(std::string msg, __int64 wParam, __int64 lParam) {return 1;}
		//����������Ϣ����
		virtual long OnMessagePro(long msg, __int64 wParam, __int64 lParam) {return 1;}

		std::vector<long> getIntMsgList(){return m_lMsgList;}
		std::vector<std::string> getStrMsgList(){return m_strMsgList;}

	protected:
		void appendMsgItem(long lMsgItem);
		void appendMsgItem(std::string strMsgItem);

	private:
		std::vector<long> m_lMsgList;
		std::vector<std::string> m_strMsgList;
	};

	long _UtilityExport OGSendMessage(long msg, __int64 wParam, __int64 lParam);
	long _UtilityExport OGSendMessage(std::string msg, __int64 wParam, __int64 lParam);


}