 
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

			// 状态管理
		BOOL					addFrameState(StateHandle hState, OG_FRAME_STATE_INFO* pInfo);
		StateHandle				getFrameState();
		OG_FRAME_STATE_INFO*	getFrameStateInfo(StateHandle hState);
		
		BOOL					setFrameState(StateHandle hState, BOOL bCallEditFunc = TRUE);
		BOOL					setEditStatePluginInfo(OG_FRAME_STATE_INFO* pInfo);		

		FunctionPluginBase*		getActiveFunctionPlugin();		
		FunctionPluginBase*		getBackFunctionPluginForRender();		

		void					deleteAllStates();

		// 取出视图类型
		VIEW_TYPE				getViewType();
		HWND					getParentWnd();
		
		long					beginEdit();			// 开关编辑状态
		long					beginInteract();		// 开关用户交互状态
		long					endUserAction();		// 结束当前编辑或交互状态

		// 返回所有的状态，供遍历
		// 注：应改为迭代器
		size_t					getNumFrameStates(void);

		long					getAllState(FrameStateList& stateList);
		
		// 将编辑功能信息压栈, 不影响当前状态
		// 如果当前已经有编辑功能信息，则无操作
		BOOL					pushEditState();
		

		// 如果当前栈中存有编辑功能信息，则恢复，其它不操作
		BOOL					popEditState();
		

		// 取出当前处于顶部的编辑功能信息
		OG_FRAME_STATE_INFO*	topEditStateInfo();
		

		// 清空栈
		void					clearStateStack();
		
		//添加或删除一个UI对象

		long					AddUIBase(CUIBase* pUIBase);
		long					RemoveUIBase(CUIBase* pUIBase);
		long					RemoveAllUIBase();

		//添加删除交互对象
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
		//当前激活的交互对象
		CInputBase*				mActiveInput;
		//窗口存在的交互对象
		CInputSet				mInputObjectSet;

		bool m_brelFunctionPlugin;
	};
}