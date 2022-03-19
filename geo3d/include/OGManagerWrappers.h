 #pragma once


#include "OGStringUtil.h"

//using namespace std;
namespace Smart3dMap {
    // 对象VECTOR管理器-外部创建和释放对象
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
		// 添加		
		virtual void add(T& object)
		{
			mObjects.push_back(object);
		}		
		// 获取
		virtual T getAt(size_t index)
		{
			assert(index < mObjects.size() && "OGObject index out of bounds!");
			return mObjects[index];
		}
		// 是否为空
		virtual bool isEmpty(void)
		{
			return getNum() > 0;
		}
		// 设置		
		virtual void setAt(size_t index, const T& object)
		{	
			assert(index < mObjects.size() && "OGObject index out of bounds!");
			ObjectList::iterator i = mObjects.begin() + index;
			*i = object;			
		}

		// 删除
		virtual void remove(size_t index)
		{			
			assert(index < mObjects.size() && "OGObject index out of bounds!");			
			ObjectList::iterator i = mObjects.begin() + index;
			mObjects.erase(i);
		}

		// 删除所有
		virtual void removeAll(void)
		{			
			mObjects.clear();
		}		
		// 取个数
		virtual const size_t getNum(void) const
		{
			return static_cast<size_t>(mObjects.size());
		}
		// 快速获取列表
		ObjectList getList(void){
			return mObjects;
		}
		// 返回迭代器
        ObjectIterator getIterator(void) {
            return ObjectIterator(mObjects.begin(), mObjects.end());
        }
	protected:		
		ObjectList mObjects;	
	};

	// MAP对象管理器->适宜于简单对象管理
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
		// 添加
		virtual bool add(const Key& key, const T& object)
		{			
			ObjectList::iterator i = mObjects.find(key);
			// 已经存在则直接返回
			if(i != mObjects.end())
				return false;
			mObjects[key] = object; 
			return true;
		}		
		// 获取
		virtual bool get(const Key& key, T& object)
		{
			ObjectList::iterator i = mObjects.find(key);
			if(i == mObjects.end())
				return false;
			
			object = i->second;
			return true;
		}
		// 获取
		virtual T get(const Key& key)
		{
			T object;
			ObjectList::iterator i = mObjects.find(key);
			if(i == mObjects.end())
				return object;
			
			object = i->second;
			return object;
		}
		// 删除
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
		// 删除
		virtual void removeByKey(const Key& key)
		{
			ObjectList::iterator i = mObjects.find(key);
			if(i != mObjects.end())
			{				
				mObjects.erase(i);
			}
		}		
		// 删除所有
		virtual void removeAll(void)
		{			
			mObjects.clear();
		}	
		// 是否为空
		virtual bool isEmpty(void)
		{
			return getNum() > 0;
		}
		// 取出对象个数
		virtual const size_t getNum(void) const
		{
			return static_cast<size_t>(mObjects.size());
		}
		// 返回对象迭代器
        ObjectIterator getIterator(void) {
            return ObjectIterator(mObjects.begin(), mObjects.end());
        }
	
	protected:		
		ObjectList mObjects;
	};

	// MAP对象指针管理器模板, 适宜于复杂对象管理, 管理器负责创建和释放对象
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
		// 创建
		virtual T* create(const Key& key)
		{
			ObjectList::iterator i = mObjects.find(key);
			// 已经存在则直接返回该指针
			if(i != mObjects.end())
				return i->second;
			
			T* pObject = new T;			
			mObjects[key] = pObject;
			return pObject;
		}		
		//获取
		virtual T* get(const Key& key)
		{
			ObjectList::iterator i = mObjects.find(key);
			if(i == mObjects.end())
				return NULL;
			
			T* pObject = i->second;
			return pObject;
		}
		// 删除
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
		// 删除
		virtual void removeByKey(const Key& key)
		{
			ObjectList::iterator i = mObjects.find(key);
			if(i != mObjects.end())
			{
				OG_DELETE(i->second);
				mObjects.erase(i);
			}
		}		
		// 删除所有
		virtual void removeAll(void)
		{
			ObjectList::iterator i = mObjects.begin();
			for( ; i != mObjects.end(); ++i)
			{
				OG_DELETE(i->second);
			}
			mObjects.clear();
		}
		// 是否为空
		virtual bool isEmpty(void)
		{
			return getNum() > 0;
		}
		// 取出对象个数
		virtual const size_t getNum(void) const
		{
			return static_cast<size_t>(mObjects.size());
		}
		// 返回对象迭代器
        ObjectIterator getIterator(void) {
            return ObjectIterator(mObjects.begin(), mObjects.end());
        }
	
	protected:		
		ObjectList mObjects;	
	};	

	// 产品管理器
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
		// 添加产品工厂		
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

		// 获取产品工厂
		TFactory* getFactory(const OGGUID& guid)
		{
			// 检索工厂
			// 查找对应的类工厂
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
		
		// 获取产品工厂迭代器
		FactoryIterator getFactoryIterator(void){
			return FactoryIterator(mFactories.begin(), mFactories.end());
		}

		// 创建（生产）产品
		// 参数: name: 工具名称 type: 产品类型
		TProduct* create(const OGGUID& guid)
		{
			static unsigned long  s_NextGeneratedNameExt = 0;

			// Generate a name
			OC::StringUtil::StrStreamType str;
			str << "Unnamed_" << s_NextGeneratedNameExt++;
			string name = str.str();
			return create(name, guid);		
		}
		
		// 创建（生产）产品
		// 参数: name: 工具名称 type: 产品类型
		virtual TProduct* create(const string& name, 
			const OGGUID& guid)
		{	
			ProductList::iterator i = mProducts.find(name);
			TProduct* pProduct = 0;
			if (i == mProducts.end())
			{
				// 检索工厂
				// 查找对应的类工厂
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
		// 取出对象个数
		virtual const size_t getNum(void) const
		{
			return static_cast<size_t>(mProducts.size());
		}	

		// 产品是否存在
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

		// 获取产品
		virtual TProduct* get(const string& name)
		{
			ProductList::iterator i = mProducts.find(name);
			if (i == mProducts.end())
			{
				//2009-4-23  找不到不再抛出异常

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
		
		// 获取某类型产品列表
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
		
		// 获取所有产品列表 ~ Fast access to ProductList
		virtual const ProductList& getList(void) const
		{
			return mProducts;
		}
		
		// 销毁产品
		virtual void destroy(TProduct* pProduct)
		{			
			destroy(pProduct->getHandle());
		}
		
		// 销毁产品
		virtual void destroy(const string& name)
		{
			ProductList::iterator i = mProducts.find(name);
			if (i != mProducts.end())
			{
				destroyImpl(name);			
				mProducts.erase(i);
			}			
		}
		
		// 销毁一类产品
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
		// 销毁所有产品
		virtual void destroyAll(void)
		{
			ProductList::iterator i = mProducts.begin();
			for (; i != mProducts.end(); ++i)
			{			
				destroyImpl(i->first);
			}
			mProducts.clear();
		}	

		// 获取产品迭代器		
		ProductIterator getProductIterator(void){
			return ProductIterator(mProducts.begin(), mProducts.end());
		}	
	
	private:
		// 销毁产品 内部调用
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
		FactoryList mFactories; // 工厂列表		
		ProductList mProducts; // 产品列表
	};	 

} // namespace Smart3dMap


