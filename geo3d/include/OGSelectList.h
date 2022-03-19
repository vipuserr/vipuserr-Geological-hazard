 // OGSelectList.h: interface for the SelectList class.
//
//////////////////////////////////////////////////////////////////////

#pragma once 

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include "OGManagerWrappers.h"

namespace Smart3dMap {
	
	// 选择集
	class OG_FRAME_DLL SelectList :  public VectorManager<OGObject*>
	{
	public:
		enum MergeStrategy {
			///
			MS_MergeNormal=0,
			///
			MS_XORWithList,
			///
			MS_RemoveFromList
		};
		
		SelectList();
		virtual ~SelectList();

		bool exists(OGObject* obj);
		void merge(const SelectList& other, const MergeStrategy strategy = MS_MergeNormal);
	};

	class OG_FRAME_DLL SelectListManager : public PtrMapManager<string, SelectList>
	{
	public:
		SelectListManager();
		virtual ~SelectListManager();

		void setActiveSelectList(SelectList* selList);
		SelectList* getActiveSelectList(void);

		enum ListAdjustment 
		{ 
			LA_ReplaceList,   // Totally replace the active list with the given items.
			LA_XORWithList,   // If one of the given items is in the active list take
				              // it out, otherwise add it to the active list.
			LA_AddToList,     // Add the items to the list
			LA_RemoveFromList // Remove the items from the list
		};

		// 选择
		void select(OGObject* object, ListAdjustment la = LA_AddToList);

		// 不选择
		void unSelect(OGObject* object, ListAdjustment la = LA_AddToList);

	private:
		SelectList* mActiveSelectList;
	};

}

