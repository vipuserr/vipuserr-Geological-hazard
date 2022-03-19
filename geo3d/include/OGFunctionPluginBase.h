 
#pragma once


#include "OGPluginBase.h"


namespace Smart3dMap {	
	// ������ת��Ϊ��
	inline POINT PARAM_TO_POINT(LPARAM lParam) {POINT pt; pt.x = LOWORD(lParam); pt.y = HIWORD(lParam); return pt; }

	class OG_FRAME_DLL FunctionPluginBase : public PluginBase
	{
	public:
		FunctionPluginBase();
		virtual ~FunctionPluginBase();

		virtual long onLButtonDown(OGWorkContext* pContext, WPARAM wParam, LPARAM lParam) { return 1; };

		virtual long onLButtonUp(OGWorkContext* pContext, WPARAM wParam, LPARAM lParam) { return 1; };

		virtual long onRButtonUp(OGWorkContext* pContext, WPARAM wParam, LPARAM lParam) { return 1; };

		virtual long onMouseMove(OGWorkContext* pContext, WPARAM wParam, LPARAM lParam) { return 1; };

		virtual long onKeyDown(OGWorkContext* pContext, WPARAM wParam, LPARAM lParam) { return 1; };

		virtual long onMouseWheel(OGWorkContext* pContext, WPARAM wParam, LPARAM lParam) { return 1; };

		virtual long onRButtonDblClk(OGWorkContext* pContext, WPARAM wParam, LPARAM lParam) { return 1; };

		virtual long onRButtonDown(OGWorkContext* pContext, WPARAM wParam, LPARAM lParam) { return 1; };

		virtual long onLButtonDblClk(OGWorkContext* pContext, WPARAM wParam, LPARAM lParam) { return 1; };

		virtual long onCommond(OGWorkContext* pContext, WPARAM wParam, LPARAM lParam) { return 1; };

		virtual BOOL begin(LPARAM lParam = 1) { return 1; };

		virtual BOOL end(LPARAM lParam = 1) { return 1; };

		virtual BOOL defaultWndProc(OGWorkContext* pContext, UINT nMsg, __int64 wParam, __int64 lParam) { return 1; };
		
		virtual void renderGraph(OGWorkContext* pContext) { };

		virtual void renderGraph2D(OGWorkContext* pContext) { };

		virtual void setup() { };		
	};


	
	// ���ܲ��������
	class OG_FRAME_DLL PluginFuncManager
	{
	private:
		PluginFuncManager();
		virtual ~PluginFuncManager();		
			
	public:
		typedef std::map<string, FunctionPluginBase*> FunctionPluginList;		
		typedef MapIterator<FunctionPluginList> FunctionPluginIterator;		

		// ��Ӳ������
		BOOL addFunctionPlugin(FunctionPluginBase* pFunctionPlugin);
		FunctionPluginBase*	getFunctionPlugin(const string& strName);
		// ɾ���������
		void removeFunctionPlugin(FunctionPluginBase* pFunctionPlugin);
		void removeFunctionPlugin(const string& strName);
		// ȡ���༭�������
		const size_t getNumFunctionPlugins(void);

		// ֱ����������Ĺ�����
		// ���� 0 �ɹ� 
		// ���� 1 ʧ��
		// ���� 2 δ�ҵ���Ӧ�Ĺ�����
		long executePluginFunc(const string& strPluginsName, 
			UINT nFuncPosition, WPARAM wParam, LPARAM lParam);

		long executePluginFunc(FunctionPluginBase* pFunctionPlugin, 
			UINT nFuncPosition, WPARAM wParam, LPARAM lParam);	

		long executePluginFunc(const string& strPluginsName, 
			const string& funcName, WPARAM wParam, LPARAM lParam);

		// ���ر༭����б������
        FunctionPluginIterator getFunctionPluginIterator(void) 
		{
            return FunctionPluginIterator(mFunctionPlugins.begin(), mFunctionPlugins.end());
        }
		
		static PluginFuncManager& getSingleton(void);
        static PluginFuncManager* getSingletonPtr(void);

	protected:

		FunctionPluginList mFunctionPlugins;	
	};
}