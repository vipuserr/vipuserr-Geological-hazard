 #pragma once


#include <osg/geometry>

//leo
class Ray
{

};

namespace Smart3dMap {

	class CInterSelectResult
	{
	public:
		MovableObject*	movable;
		Geometry*		geom;
		Vector3			localPos;
		Vector3			worldPos;

		CInterSelectResult()
		{
			geom=NULL;
			movable=NULL;
		};
	};
	
	typedef std::vector<CInterSelectResult*> CInterSelectResultList;

//	class PixelSceneQueryUtil;
	class OG_FRAME_DLL FunctionPlugin3D : public FunctionPluginBase
	{
	public:
		FunctionPlugin3D();
		virtual ~FunctionPlugin3D();
		
		//基类虚函数
		virtual long onLButtonDown(OGWorkContext* pContext, WPARAM wParam, LPARAM lParam);
		virtual long onLButtonUp(OGWorkContext* pContext, WPARAM wParam, LPARAM lParam);
		virtual long onRButtonUp(OGWorkContext* pContext, WPARAM wParam, LPARAM lParam);
		virtual long onMouseMove(OGWorkContext* pContext, WPARAM wParam, LPARAM lParam);
		virtual long onRButtonDblClk(OGWorkContext* pContext, WPARAM wParam, LPARAM lParam);
		virtual long onRButtonDown(OGWorkContext* pContext, WPARAM wParam, LPARAM lParam);
		virtual long onLButtonDblClk(OGWorkContext* pContext, WPARAM wParam, LPARAM lParam);

		//本类虚函数
		virtual long onLButtonDown(OGWorkContext* pContext, CInterSelectResultList& result) { return 1; }
		virtual long onLButtonUp(OGWorkContext* pContext, CInterSelectResultList& result) { return 1; }
		virtual long onRButtonUp(OGWorkContext* pContext, CInterSelectResultList& result) { return 1; }
		virtual long onMouseMove(OGWorkContext* pContext, CInterSelectResultList& result) { return 1; }
		virtual long onRButtonDblClk(OGWorkContext* pContext, CInterSelectResultList& result) { return 1; }
		virtual long onRButtonDown(OGWorkContext* pContext, CInterSelectResultList& result) { return 1; }
		virtual long onLButtonDblClk(OGWorkContext* pContext, CInterSelectResultList& result) { return 1; }

		virtual long StartPickUp(bool bSetMouseMovePickup = 0);
		virtual long StopPickUp();

	private:
		bool	get3DPointFromScreen(OGWorkContext* pContext, LPARAM param);
	    void	generateScreenMouseRay(OGWorkContext* pContext, CPoint& screenPoint, Ray& mouseRay);// 根据屏幕点生成鼠标射线
		void	DrawPickRect(CRect *rect);//绘制拾取矩形...
		void	ReleaseSelectList();

	protected:
		BOOL	mbMouseMoveHasPickOper;
		BOOL	mbPlugHasPickOper;

	private:
		CInterSelectResultList	mIntersectResult;
		SceneManager*			mSceneManager;
		CInterSelectResultList		mInterResList;
	public:
		BOOL			mbRectPick;
		CPoint			mRectStartPnt, mRectEndPnt;
		osg::Vec3		world_coord;
//		PixelSceneQueryUtil* mPixelSceneQueryUtil;
		
	};

	

}