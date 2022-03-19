 #pragma once

#include "OGMessageListener.h"
#include "OGElementManager.h"




	namespace Smart3dMap
	{
		//Ԫ������
		//----------------------------------------------------------	
		const string STR_OPEN_ELEMENT			= "��";
		const string STR_CLOSE_ELEMENT			= "�ر�";
		const string STR_DEL_ELEMENT			= "ɾ���ڵ�";
		const string STR_RELT_ELEMENT			= "��������";
		const string STR_DEL_RELT_ELEMENT		= "ɾ������";
		const string STR_SET_RULE_VALUE			= "������ʾ��ֵ";
		const string STR_PROPERTY_ELEMENT		= "����";

		class OG_FRAME_DLL OG2DElement :public Element, public Smart3dMap::COGListener
		{
		public:	
			OG2DElement(const string& name, const OGGUID& guid);
			virtual	~OG2DElement();


			// -------------------------ԭ��ܱ��ֲ���ĺ���--------------------------
		public:

			//����ӳ��
			virtual void DoCommand(UINT nID, WPARAM wParam, LPARAM lParam) {}

			//��Ϣ��Ӧ����
			virtual void onExecute(const string& name, WPARAM wParam, LPARAM lParam);

			//��Ϣע�ắ��
			virtual void registerFunctions(void);
			
			//��������/ɾ������
			virtual long ReltElement(){ return 0; }
			virtual long ReltElement(char *pFilePath){ return 0; }
			virtual long BeforeDelRelt(){ return 1; }
			virtual long DelRelt(){ return 1; }
			virtual long DispElement(long myDC){ return 1; }

			//��Ϣ��Ӧ
			virtual long OnMessagePro(long nMsg, __int64 wParam, __int64 lParam);

			//���������ӿ����������ʵ����,������������ܺ����ٵ��û���ӿ�,��ʵ�ֻ���Խ��Ĳ���

			//����˶��������Ĺ����ռ��������״̬�ı䶯��
			virtual void setVisible(bool visible);

			//ɾ�������ٽڵ�ָ��
			virtual long DelteElement(BOOL bPrompt = TRUE);


			// ���á���ȡ��ʾ����
			virtual void getRuleRange(double &dMaxSize, double &dMinSize){ }
			virtual void setRuleRange(double dMaxSize,double dMinSize){ }

			// [11/7/2012 lt] ���á���ȡ��ǰ��ͼ����ʾ��Χ
			virtual void getDataRect(double&xMin, double&yMin, double&xMax, double&ymax){ }

			// [11/7/2012 lt] �����Ƿ��Զ���ʾ�ı��
			virtual void setAutoVisFlag(bool& bFlag){ }
			virtual void getAutoVisFlag(bool& bFlag){ }
		private:
			
		};
}
		