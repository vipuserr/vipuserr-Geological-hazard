 #pragma once

#include "OGObject.h"
#include "OGFunctionItemManager.h"


namespace Smart3dMap {	

	
	//UI��������������
	class OG_FRAME_DLL CUIBase
	{
	public:
		CUIBase(HWND hWnd);
		virtual ~CUIBase();		
		
		// ȡ�ò���汾��Ϣ
		const string& getVersion();

		//������Ϣ����������1��ʾ�Ѿ�����ɹ����������ٴ���
		virtual long onLButtonDown(WPARAM wParam, LPARAM lParam) { return 0; };

		virtual long onLButtonUp(WPARAM wParam, LPARAM lParam) { return 0; };

		virtual long onRButtonUp(WPARAM wParam, LPARAM lParam) { return 0; };

		virtual long onMouseMove(WPARAM wParam, LPARAM lParam) { return 0; };

		virtual long onKeyDown(WPARAM wParam, LPARAM lParam) { return 0; };

		virtual long onMouseWheel(WPARAM wParam, LPARAM lParam) { return 0; };

		virtual long onRButtonDblClk(WPARAM wParam, LPARAM lParam) { return 0; };

		virtual long onRButtonDown(WPARAM wParam, LPARAM lParam) { return 0; };

		virtual long onLButtonDblClk(WPARAM wParam, LPARAM lParam) { return 0; };

		virtual long onCommond(WPARAM wParam, LPARAM lParam) { return 0; };
	protected:		
		string				mVersion;	// �汾		
		HWND				mhWnd;
	};

	//���������������
	class OG_FRAME_DLL CInputBase : public OGObject
	{
		public:
			CInputBase();
			CInputBase(HWND hWnd,SceneManager* SceneMgr, Smart3dMap::Camera* Camera);
			virtual ~CInputBase();		
		public:
			//������Ϣ
			virtual long onKeyDown(WPARAM wParam, LPARAM lParam);
			virtual long onKeyUp(WPARAM wParam, LPARAM lParam);
			virtual long onLButtonDblClk(WPARAM wParam, LPARAM lParam);
			virtual long onLButtonDown(WPARAM wParam, LPARAM lParam);
			virtual long onLButtonUp(WPARAM wParam, LPARAM lParam);
			virtual long onMButtonDblClk(WPARAM wParam, LPARAM lParam);
			virtual long onMButtonDown(WPARAM wParam, LPARAM lParam);
			virtual long onMButtonUp(WPARAM wParam, LPARAM lParam);
			virtual long onMouseMove(WPARAM wParam, LPARAM lParam);
			virtual long onMouseWheel(WPARAM wParam, LPARAM lParam);
			virtual long onRButtonDblClk(WPARAM wParam, LPARAM lParam);
			virtual long onRButtonDown(WPARAM wParam, LPARAM lParam);
			virtual long onRButtonUp(WPARAM wParam, LPARAM lParam);

			virtual void onActive();
			virtual void onDisActive();
			virtual void onSetup();
			//֪ͨ���λ���Ѿ��ı�
			virtual void notify(Vector3& Pos,Vector3& Dir);

			const string& getType() { return mType; }
			
			//��ȡ˵��
			const string& getDescription() { return mDescription; }
			//��λ
			virtual void reset();
			//���ð�Χ��
			virtual void setBoundingBox(const AxisAlignedBox& aabb);
			virtual void setAutoMode(bool autoMode);
			//������ת
			virtual void FlyTo(Vector3& Pos,DWORD dwFlyMode){};
			virtual void JumpTo(Vector3& Pos,DWORD dwFlyMode){};

			//����WM_SIZE��Ϣ
			virtual void onSize(WPARAM wParam, LPARAM lParam)
			{
				mClientWidth = LOWORD(lParam);
				mClientHeight = HIWORD(lParam);
			}
			
			void updateTargetWindow();

			//ȡ����
			SceneManager* getSceneManager() { return mSceneMgr; }
			Smart3dMap::Camera* getCamera() { return mCamera; }
			HWND getTargetWindowHandle() { return mTargetWindow; }

			//��Ϣ֪ͨ
			long _OnMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);

		protected:
			int mClientWidth; //���ڴ�С
			int mClientHeight; 
			string mType; //��������
			//string mDescription; //��������
			//string mInputClsName; //��������,Ҫ��Ψһ
			AxisAlignedBox		mAABox;

		protected:
			SceneManager* mSceneMgr;
			Smart3dMap::Camera* mCamera;
			HWND mTargetWindow;
			string				mVersion;	// �汾		
		
		protected:
			POINT getPoint(LPARAM lParam)
			{
				POINT pt;

				pt.x = LOWORD(lParam);  // horizontal position of cursor 
				pt.y = HIWORD(lParam);  // vertical position of cursor 
				
				return pt;
			}
	};


}