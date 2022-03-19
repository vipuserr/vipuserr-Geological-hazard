 #pragma once


#include "OGStringUtil.h"

//using namespace std;
namespace Smart3dMap {
    // ����VECTOR������-�ⲿ�������ͷŶ���
	template<class T>
	class VectorManager
	{
	public:		
		typedef std::vector<T> ObjectList;
	    typedef VectorIterator<ObjectList> ObjectIterator;
	public:
		VectorManager()
		{
		}
		virtual ~VectorManager()
		{
			removeAll();
		}
		// ���		
		virtual void add(T& object)
		{
			mObjects.push_back(object);
		}		
		// ��ȡ
		virtual T getAt(size_t index)
		{
			assert(index < mObjects.size() && "OGObject index out of bounds!");
			return mObjects[index];
		}
		// �Ƿ�Ϊ��
		virtual bool isEmpty(void)
		{
			return getNum() > 0;
		}
		// ����		
		virtual void setAt(size_t index, const T& object)
		{	
			assert(index < mObjects.size() && "OGObject index out of bounds!");
			ObjectList::iterator i = mObjects.begin() + index;
			*i = object;			
		}

		// ɾ��
		virtual void remove(size_t index)
		{			
			assert(index < mObjects.size() && "OGObject index out of bounds!");			
			ObjectList::iterator i = mObjects.begin() + index;
			mObjects.erase(i);
		}

		// ɾ������
		virtual void removeAll(void)
		{			
			mObjects.clear();
		}		
		// ȡ����
		virtual const size_t getNum(void) const
		{
			return static_cast<size_t>(mObjects.size());
		}
		// ���ٻ�ȡ�б�
		ObjectList getList(void){
			return mObjects;
		}
		// ���ص�����
        ObjectIterator getIterator(void) {
            return ObjectIterator(mObjects.begin(), mObjects.end());
        }
	protected:		
		ObjectList mObjects;	
	};

	// MAP���������->�����ڼ򵥶������
	template<class Key, class T>
	class MapManager
	{
	public:	
		typedef std::map<Key, T> ObjectList;
	    typedef MapIterator<ObjectList> ObjectIterator;
		MapManager()
		{
		}
		virtual ~MapManager()
		{
			removeAll();
		}
		// ���
		virtual bool add(const Key& key, const T& object)
		{			
			ObjectList::iterator i = mObjects.find(key);
			// �Ѿ�������ֱ�ӷ���
			if(i != mObjects.end())
				return false;
			mObjects[key] = object; 
			return true;
		}		
		// ��ȡ
		virtual bool get(const Key& key, T& object)
		{
			ObjectList::iterator i = mObjects.find(key);
			if(i == mObjects.end())
				return false;
			
			object = i->second;
			return true;
		}
		// ��ȡ
		virtual T get(const Key& key)
		{
			T object;
			ObjectList::iterator i = mObjects.find(key);
			if(i == mObjects.end())
				return object;
			
			object = i->second;
			return object;
		}
		// ɾ��
		virtual void remove(const T& object)
		{			
			ObjectList::iterator i = mObjects.begin();
			for( ; i != mObjects.end(); ++i)
			{				
				if (i->second == object)
				{					
					mObjects.erase(i);
				    break;
				}				
			}
		}
		// ɾ��
		virtual void removeByKey(const Key& key)
		{
			ObjectList::iterator i = mObjects.find(key);
			if(i != mObjects.end())
			{				
				mObjects.erase(i);
			}
		}		
		// ɾ������
		virtual void removeAll(void)
		{			
			mObjects.clear();
		}	
		// �Ƿ�Ϊ��
		virtual bool isEmpty(void)
		{
			return getNum() > 0;
		}
		// ȡ���������
		virtual const size_t getNum(void) const
		{
			return static_cast<size_t>(mObjects.size());
		}
		// ���ض��������
        ObjectIterator getIterator(void) {
            return ObjectIterator(mObjects.begin(), mObjects.end());
        }
	
	protected:		
		ObjectList mObjects;
	};

	// MAP����ָ�������ģ��, �����ڸ��Ӷ������, ���������𴴽����ͷŶ���
	template<class Key, class T>
	class PtrMapManager
	{
	public:		
		typedef std::map<Key, T*> ObjectList;
	    typedef MapIterator<ObjectList> ObjectIterator;
	public:
		PtrMapManager()
		{
		}
		virtual ~PtrMapManager()
		{
			removeAll();
		}
		// ����
		virtual T* create(const Key& key)
		{
			ObjectList::iterator i = mObjects.find(key);
			// �Ѿ�������ֱ�ӷ��ظ�ָ��
			if(i != mObjects.end())
				return i->second;
			
			T* pObject = new T;			
			mObjects[key] = pObject;
			return pObject;
		}		
		//��ȡ
		virtual T* get(const Key& key)
		{
			ObjectList::iterator i = mObjects.find(key);
			if(i == mObjects.end())
				return NULL;
			
			T* pObject = i->second;
			return pObject;
		}
		// ɾ��
		virtual void remove(T* pObject)
		{			
			ObjectList::iterator i = mObjects.begin();
			for( ; i != mObjects.end(); ++i)
			{				
				if (i->second == pObject)
				{
					OG_DELETE(i->second);
					mObjects.erase(i);
				    break;
				}				
			}
		}
		// ɾ��
		virtual void removeByKey(const Key& key)
		{
			ObjectList::iterator i = mObjects.find(key);
			if(i != mObjects.end())
			{
				OG_DELETE(i->second);
				mObjects.erase(i);
			}
		}		
		// ɾ������
		virtual void removeAll(void)
		{
			ObjectList::iterator i = mObjects.begin();
			for( ; i != mObjects.end(); ++i)
			{
				OG_DELETE(i->second);
			}
			mObjects.clear();
		}
		// �Ƿ�Ϊ��
		virtual bool isEmpty(void)
		{
			return getNum() > 0;
		}
		// ȡ���������
		virtual const size_t getNum(void) const
		{
			return static_cast<size_t>(mObjects.size());
		}
		// ���ض��������
        ObjectIterator getIterator(void) {
            return ObjectIterator(mObjects.begin(), mObjects.end());
        }
	
	protected:		
		ObjectList mObjects;	
	};	

	// ��Ʒ������
	template<class TProduct, class TFactory>	
	class ProductManager
	{
    public:
		typedef std::map<string, TProduct*> ProductList;
		typedef MapIterator<ProductList> ProductIterator;
		
		typedef std::map<OGGUID, TFactory*> FactoryList;
		typedef MapIterator<FactoryList> FactoryIterator;

	public:
		ProductManager()
		{
		}

		virtual ~ProductManager()
		{
			destroyAll();
		}		
		// ��Ӳ�Ʒ����		
		virtual void addFactory(TFactory* pFactory)
		{
			OGGUID guid = pFactory->getType();
			FactoryList::iterator it = mFactories.find(guid);
			if (it != mFactories.end())
			{
				// Factory not found
				//OGRE_EXCEPT(Exception::ERR_ITEM_NOT_FOUND, "Cannot find an Product factory "
				//	" to deal with product" + guid, "ProductManager::addProductFactory");
			}
			
			mFactories[pFactory->getType()] = pFactory;		
		}

		// ��ȡ��Ʒ����
		TFactory* getFactory(const OGGUID& guid)
		{
			// ��������
			// ���Ҷ�Ӧ���๤��
			FactoryList::iterator it = mFactories.find(guid);
			if (it == mFactories.end())
			{
				// Factory not found
				//OGRE_EXCEPT(Exception::ERR_ITEM_NOT_FOUND, "Cannot find an Product factory "
				//	" to deal with Product" + guid, "ProductManager::createProduct");
				//return 0;
			} 
			return it->second;			
		}
		
		// ��ȡ��Ʒ����������
		FactoryIterator getFactoryIterator(void){
			return FactoryIterator(mFactories.begin(), mFactories.end());
		}

		// ��������������Ʒ
		// ����: name: �������� type: ��Ʒ����
		TProduct* create(const OGGUID& guid)
		{
			static unsigned long  s_NextGeneratedNameExt = 0;

			// Generate a name
			OC::StringUtil::StrStreamType str;
			str << "Unnamed_" << s_NextGeneratedNameExt++;
			string name = str.str();
			return create(name, guid);		
		}
		
		// ��������������Ʒ
		// ����: name: �������� type: ��Ʒ����
		virtual TProduct* create(const string& name, 
			const OGGUID& guid)
		{	
			ProductList::iterator i = mProducts.find(name);
			TProduct* pProduct = 0;
			if (i == mProducts.end())
			{
				// ��������
				// ���Ҷ�Ӧ���๤��
				FactoryList::iterator it = mFactories.find(guid);
				if (it == mFactories.end())
				{
					// Factory not found
					//OGRE_EXCEPT(Exception::ERR_ITEM_NOT_FOUND, "Cannot find an Product factory"
					//	" to deal with Product" + name, "ProductManager::create");
					//return NULL;
				}
				
  				pProduct = it->second->createInstance(name);				
				mProducts[name] = pProduct;				
			}
			else
			{
				pProduct = i->second;
			}			
			return pProduct;
		}
		// ȡ���������
		virtual const size_t getNum(void) const
		{
			return static_cast<size_t>(mProducts.size());
		}	

		// ��Ʒ�Ƿ����
		virtual bool exists(const string& name)
		{
			ProductList::iterator i = mProducts.find(name);
			if (i == mProducts.end())
			{
				return false;
			}
			else
			{
				return true;
			}		 
		}

		// ��ȡ��Ʒ
		virtual TProduct* get(const string& name)
		{
			ProductList::iterator i = mProducts.find(name);
			if (i == mProducts.end())
			{
				//2009-4-23  �Ҳ��������׳��쳣

				//Product not found
// 				OGRE_EXCEPT( Exception::ERR_ITEM_NOT_FOUND, 
// 					"Cannot find Product with name " + name,
// 					"getProduct");					
				return NULL;
			}
			else
			{
				return i->second;
			}		 
		}
		
		// ��ȡĳ���Ͳ�Ʒ�б�
		virtual void getList(ProductList& Products, const OGGUID& guid)
		{		
			ProductList::iterator i = mProducts.begin();
			for (; i != mProducts.end(); ++i)
			{
				if (i->second->isKindOf(guid))
				{
					Products.insert(ProductList::value_type(i->first, i->second));
				}
			}
		}
		
		// ��ȡ���в�Ʒ�б� ~ Fast access to ProductList
		virtual const ProductList& getList(void) const
		{
			return mProducts;
		}
		
		// ���ٲ�Ʒ
		virtual void destroy(TProduct* pProduct)
		{			
			destroy(pProduct->getHandle());
		}
		
		// ���ٲ�Ʒ
		virtual void destroy(const string& name)
		{
			ProductList::iterator i = mProducts.find(name);
			if (i != mProducts.end())
			{
				destroyImpl(name);			
				mProducts.erase(i);
			}			
		}
		
		// ����һ���Ʒ
		virtual void destroyList(const OGGUID& guid)
		{
			ProductList::iterator i = mProducts.begin();
			for (; i != mProducts.end(); ++i)
			{
				if (i->second->isKindOf(guid))
				{
					destroyImpl(i->first);
					mProducts.erase(i);
				}
			}
		}		
		// �������в�Ʒ
		virtual void destroyAll(void)
		{
			ProductList::iterator i = mProducts.begin();
			for (; i != mProducts.end(); ++i)
			{			
				destroyImpl(i->first);
			}
			mProducts.clear();
		}	

		// ��ȡ��Ʒ������		
		ProductIterator getProductIterator(void){
			return ProductIterator(mProducts.begin(), mProducts.end());
		}	
	
	private:
		// ���ٲ�Ʒ �ڲ�����
		virtual void destroyImpl(const string& name)
		{
			// Find in list
			ProductList::iterator i = mProducts.find(name);		
			if (i != mProducts.end())
			{
				// Find factory to destroy
				FactoryList::iterator fit = mFactories.find(i->second->getClassName());
				if (fit == mFactories.end())
				{
					// Factory not found
					//OGRE_EXCEPT(Exception::ERR_ITEM_NOT_FOUND, "Cannot find an Product factory "
					//	"to deal with Product of type " + i->second->getClassName(), "~ProductManager");
				}
				fit->second->destroyInstance(i->second);				
			}
		}	
		
	protected:		
		FactoryList mFactories; // �����б�		
		ProductList mProducts; // ��Ʒ�б�
	};	 

} // namespace Smart3dMap


