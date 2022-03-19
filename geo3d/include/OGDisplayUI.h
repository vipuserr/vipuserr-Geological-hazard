 #pragma once

#include "OGPluginBase.h"
#include "OGUIBase.h"



namespace Smart3dMap {
	class COGDisplayUI :
		public Smart3dMap::COGListener,
		public CUIBase
	{
	public:
		COGDisplayUI(HWND hWnd);
		virtual ~COGDisplayUI(void);
	public:
		bool		CanSelected(long x,long y);
		bool		SelectTitle(long x,long y);
		virtual		long	onLButtonUp(WPARAM wParam, LPARAM lParam);
		virtual     long	onLButtonDown(WPARAM wParam, LPARAM lParam);
		virtual     long	onMouseMove(WPARAM wParam, LPARAM lParam);
		virtual		long	onUIMoveing(const POINT& newPos,const SIZE& newSize);
		virtual		long	onUIMoved(POINT& newPos,SIZE& newSize);
	protected:
		POINT		mPos;//�������
		SIZE		mSize;//��С
		bool		mPicked;//ʰȡ��
		POINT		mSPos;//�ƶ���ʼ��
		SIZE		mTitleSize;//�����С
	};
}

