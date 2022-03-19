 #pragma once

#include "OGBasDef.h"
#include "OgIteratorWrapper.h"


namespace Smart3dMap {	

	// ����������
	enum FunctionItemType
	{
		FIT_ITEM		= 0,
		FIT_GROUP		= 1,
		FIT_SEPARATOR	= 2,
	};

	// ������
	class OG_FRAME_DLL FunctionItem
	{
	public:	
		FunctionItem(void)
		{
			mType = (FIT_ITEM) ;
			mDescription = ("NONE") ;
			mName = ("NONE") ;
			mState = (false) ;
			mPosition = (-1) ;
			mFunction = ("NONE");
		}
			

		virtual ~FunctionItem(void) {};
		
		virtual	void clear(void) {}
		
		// ��/ȡ����
		void setName(const string& name) { mName = name; }
		const string& getName(void) const	{ return mName; }
		string getName(void)			{ return mName; }
		
		// ��/ȡ����
		void setDescription(const string& Description) { mDescription = Description; }
		const string& getDescription(void) const	{ return mDescription; }
		string getDescription(void)		{ return mDescription; }
		
		// ��/ȡ״̬
		void setState(bool b) 		{ mState = b; }
		bool getState(void)	const 		{ return mState; }
		void switchState(void) 			{ mState = !mState; }
		
		// ��/ȡλ��(���ܵ�ΨһUID,��ON_COMMAND��Ӧ)
		// ������UINT��ʾID,��size_t��ʾ����
		void setPosition(UINT pos)  		{ mPosition = pos; }
		UINT getPosition(void)	const 		{ return mPosition; }
		
		// ��/ȡ��������(��Ŀѡ��ʱ��Ӧ�����õĺ������� - ���ڹ���ӳ��)
		void setFunctionType(const string func_type)  		{ mFunction = func_type; }
		string getFunctionType(void)	const { return mFunction; }
		
		// ��/ȡ����������
		void setType(FunctionItemType t) 	{ mType = t; }
		FunctionItemType getType(void) 			{ return mType; }
		
	protected:
		FunctionItemType mType;        // ���	
		string			 mName;        // ��Ŀ����	
		bool			 mState;       // ״̬	
		UINT    		 mPosition;    // ID��	
		string			 mDescription; // ������Ϣ	
		string   		 mFunction;    // �������� - ������Ϣӳ��
	};
	
	// ������
	class OG_FRAME_DLL FunctionItemGroup : public FunctionItem
	{
		friend class FunctionItemManager;
	public:	
		FunctionItemGroup(FunctionItemManager* functionItemManager);
		virtual ~FunctionItemGroup();		
		
		// �����Ŀ
		FunctionItem* appendItem(FunctionItemType type, const string& newItemName);
		
		// ������Ŀ
		FunctionItem* insertItem(const string& name, 
			FunctionItemType type, const string& newItemName);
		
		// ɾ����Ŀ
		void removeItem(const string& name);
		
		// ɾ����Ŀ
		void removeItem(FunctionItem* item);

		// ɾ�������Ŀ(������ֱ�Ӻ���)
		void removeRangeItems(const string& from, const string& to);

		// ȡ��Ŀ
		FunctionItem* getItem(const string& name);		
		// �������кŲ��ҹ�����
		FunctionItem* getItem(UINT nRank);
		// ��ȡ��Ŀ
		FunctionItem* getItem(FunctionItemGroup* pItemGroup, UINT nRank);		
		// ������Ŀ
		size_t size(void);
		// ɾ�������ӹ���
		void clear(void);
		
		// ��ȡ������ָ��
		FunctionItemManager* getFunctionItemManager() { return mfunctionItemManager; }
		// �����ȡ
		FunctionItem* operator[] (size_t pos);
		
		typedef std::vector<FunctionItem*> FunctionItemList;
		typedef VectorIterator<FunctionItemList> FunctionItemIterator;

		FunctionItemIterator getFunctionItemIterator(void){
			return FunctionItemIterator(mfuncItems.begin(), mfuncItems.end());
		}	
	protected:			
		// �Զ����ɲ˵�
		void genMenu(HMENU hSubMenu, FunctionItemGroup* pGroup);
		// ȡ��Ŀ��id
		size_t getItemIndex(const string& name);
		
		FunctionItemList mfuncItems; // ������Ŀ	
		FunctionItemManager* mfunctionItemManager;
	};
	
	// ����������������,�Ӹ���̳м��ɴ�������
	// �����������Ĳ����..
	class OG_FRAME_DLL FunctionItemManager
	{	
	public:
		FunctionItemManager();
		virtual ~FunctionItemManager();
		// ���������:
		// ȡ����������
		string getItemName(UINT nID);
		// ȡ����������
		string getItemDescription(UINT nID);
		// ȡ����������
		string getItemFunctionType(UINT nID);
		// �л�������״̬(ѡ��/��ѡ��)
		void switchItemState(UINT nID);	
		
		// ֱ��ȡ������ָ��
		FunctionItem* getItem(const string& name);
		// ȡ��������ָ��
		FunctionItemGroup* getRootItem(void);
		// ȡ�����Ŀ��Ŀ
		static size_t getNumMaxItems(void);
		void setNumMaxItems(const size_t nNumMaxItems);		
		// ��Ӧ��Ϣ,ִ��Item�ж���ĺ���		
		virtual void onExecute(const string& name, WPARAM wParam, LPARAM lParam) = 0;
		// ������������ڴ˺��������д�빦���б�Ĺ���
		virtual void registerFunctions(void) = 0;
		virtual void unRegisterFunctions(void);
		// �˵����
		virtual HMENU getHMenu(void);
		virtual UINT _getNextMenuUINT();
	protected:
		virtual void genMenu(void);
		HMENU getMenu(void);
	private:		
		// ��DebugʱOutput���й�������Ϣ
		void dumpMenu(FunctionItemGroup* pItemGroup);		
	protected:
		FunctionItemGroup* mFuncItemGroup;  // ������һ��������		
		static size_t mNumMaxItems;  // �������
		UINT mItemPosition;
		HMENU mdynMenu;
	};
}
