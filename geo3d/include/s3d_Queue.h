#pragma once

#include <s3d_KerMathDef.h>

namespace Smart3dMap
{

	//队列操作类
	class LIB_GMKERMATH_EXP s3d_QueueCls
	{
	public:
		s3d_QueueCls(int num);
		virtual ~s3d_QueueCls();
	public:
		int	 InitialQueue();
		int	 ResetQueue();
		void ReleaseQueue();
		int  AddElement(int idx);
		int	 DelElement();
		bool IsEmpty();
		bool IsFull();
		int	 GetQueueNum();
		int	 GetElement(int idx);
		int  GetElementNum();
	private:
		int		  m_Head;
		int		  m_End;
		int		  m_Num;
		int		* m_pDatas;
	};

}
