 
#pragma once


#include "OGBasDef.h"
#include "OGFunctionPluginBase.h"

namespace Smart3dMap{
	class CUIBase;
	class CInputBase;

	typedef std::vector<StateHandle> FrameStateList;
	class OG_FRAME_DLL SubFrame : public OGObject
	{
		typedef	std::map<DWORD, OG_FRAME_STATE_INFO*>	STATE_INFO_MAP;
		typedef	std::stack<OG_FRAME_STATE_INFO*>		EditInfoStack;
		typedef std::vector<CUIBase*>					CUIList;
		typedef std::map<std::string,CInputBase*>			CInputSet;

		
		//typedef VectorIterator<FrameStateList> FrameStateIterator;
	public:
		SubFrame(Smart3dMap::Viewport* pViewport, HWND hWnd);
		~SubFrame();

		long					initilize(Smart3dMap::Viewport* pViewport, const string& strName, const string& strDescripition, VIEW_TYPE type);
		Smart3dMap::Viewport*				getFrameViewport();

			// ״̬����
		BOOL					addFrameState(StateHandle hState, OG_FRAME_STATE_INFO* pInfo);
		StateHandle				getFrameState();
		OG_FRAME_STATE_INFO*	getFrameStateInfo(StateHandle hState);
		
		BOOL					setFrameState(StateHandle hState, BOOL bCallEditFunc = TRUE);
		BOOL					setEditStatePluginInfo(OG_FRAME_STATE_INFO* pInfo);		

		FunctionPluginBase*		getActiveFunctionPlugin();		
		FunctionPluginBase*		getBackFunctionPluginForRender();		

		void					deleteAllStates();

		// ȡ����ͼ����
		VIEW_TYPE				getViewType();
		HWND					getParentWnd();
		
		long					beginEdit();			// ���ر༭״̬
		long					beginInteract();		// �����û�����״̬
		long					endUserAction();		// ������ǰ�༭�򽻻�״̬

		// �������е�״̬��������
		// ע��Ӧ��Ϊ������
		size_t					getNumFrameStates(void);

		long					getAllState(FrameStateList& stateList);
		
		// ���༭������Ϣѹջ, ��Ӱ�쵱ǰ״̬
		// �����ǰ�Ѿ��б༭������Ϣ�����޲���
		BOOL					pushEditState();
		

		// �����ǰջ�д��б༭������Ϣ����ָ�������������
		BOOL					popEditState();
		

		// ȡ����ǰ���ڶ����ı༭������Ϣ
		OG_FRAME_STATE_INFO*	topEditStateInfo();
		

		// ���ջ
		void					clearStateStack();
		
		//��ӻ�ɾ��һ��UI����

		long					AddUIBase(CUIBase* pUIBase);
		long					RemoveUIBase(CUIBase* pUIBase);
		long					RemoveAllUIBase();

		//���ɾ����������
		long					AddInputBase(CInputBase* pUIBase);
		long					RemoveInputBase(const std::string& sInputClsName);
		long					ActiveInputCls(const std::string& sInputClsName);
		bool					ExistInputBase(const std::string& sInputClsName);
		CInputBase*				GetActiveInput(){return mActiveInput;};

		long					RemoveAllInputCls();

		long					MsgProc(UINT Msg, WPARAM wParam, LPARAM lParam);
	public:
		void					setActiveFunctionPlugin(FunctionPluginBase* pFunctionPlugin);
		void					setReleaseFunctionPlugin(bool brelFunctionPlugin);				
		bool					getReleaseFunctionPlugin();
		
	private:
		VIEW_TYPE				mViewType;
		Smart3dMap::Viewport*				mViewport;
		STATE_INFO_MAP			mFrameStateMap;		
		FunctionPluginBase*		mActiveFunctionPlugin;		

		StateHandle				mhFrameState;
		EditInfoStack			mEditInfoStack;
		HWND                    mhWnd;
		CUIList					mUIList;
		//��ǰ����Ľ�������
		CInputBase*				mActiveInput;
		//���ڴ��ڵĽ�������
		CInputSet				mInputObjectSet;

		bool m_brelFunctionPlugin;
	};
}