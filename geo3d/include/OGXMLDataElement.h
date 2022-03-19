 #pragma once


#include "OGDataElement.h"

class TiXmlElement;

namespace Smart3dMap 
{
	class OG_FRAME_DLL XMLDataElement : public DataElement
	{
	public:
		XMLDataElement(TiXmlElement* element);
		XMLDataElement(const string& name);
		virtual ~XMLDataElement();


	public:
		virtual DataElement* createChild(const string& name);
		virtual DataElement* getFirstChild(const string& name);
		virtual DataElement* getNextSibling();
		virtual DataElement* getParent();

		//取出关键信息...
		virtual string getType(string& strType);
		virtual string getName(string& strName);
		virtual string getCaption(string& strCaption);
		virtual string getIconName(string& strIconName);
		virtual string getUrl(string& strUrl);

		//设置关键信息...
		virtual void setType(string strType);
		virtual void setName(string strName);
		virtual void setCaption(string strCaption);
		virtual void setIconName(string strIconName);
		virtual void setUrl(string strUrl);

		//获取节点属性
		virtual int getAttributeInt(const string& name, int defaultVal =0) const;
		virtual unsigned int getAttributeUnsignedInt(const string& name, unsigned int defaultVal =0) const;
		virtual long getAttributeLong(const string& name, long defaultVal =0) const;
		virtual unsigned long getAttributeUnsignedLong(const string& name, unsigned long defaultVal =0) const;
		virtual float getAttributeFloat(const string& name, float defaultVal=0.0f) const;
		virtual string getAttributeString(const string& name, string& defaultVal = string("") ) const;
		virtual string getAttributeString(const string& name, const char* defaultVal) const;
		virtual bool getAttributeBool(const string& name, bool defaultVal = true) const;
		virtual Vector3 getAttributeVector3(const string& name, const Vector3& defaultValue = Vector3(0,0,0)) const;
		virtual Smart3dMap::Matrix3 getAttributeMatrix3(const string& name, const Smart3dMap::Matrix3& defaultValue) const;
		virtual Matrix4 getAttributeMatrix4(const string& name, const Matrix4& defaultValue) const;			
		virtual Smart3dMap::Quaternion getAttributeQuaternion(const string& name, const Smart3dMap::Quaternion& defaultValue) const;
		virtual ColourValue getAttributeColourValue(const string& name, const ColourValue& defaultValue) const;
//		virtual DataStreamPtr getAttributeDataStream(const string& name) const;

		//设置节点属性
		virtual void setAttribute(const string& name, int val);
		virtual void setAttribute(const string& name, unsigned int val);
		virtual void setAttribute(const string& name, long val);
		virtual void setAttribute(const string& name, unsigned long val);
		virtual void setAttribute(const string& name, const __int64& val);
		virtual void setAttribute(const string& name, float val);
		virtual void setAttribute(const string& name, const char* val);
		virtual void setAttribute(const string& name, string& val);
		virtual void setAttribute(const string& name, const string& val);
		virtual void setAttribute(const string& name, bool val);
		virtual void setAttribute(const string& name, const Vector3& val);
		virtual void setAttribute(const string& name, const Smart3dMap::Matrix3& val);
		virtual void setAttribute(const string& name, const Matrix4& val);			
		virtual void setAttribute(const string& name, const Smart3dMap::Quaternion& val);
		virtual void setAttribute(const string& name, const ColourValue& val);
//		virtual void setAttribute(const string& name, const DataStreamPtr& val);
	
		//判断节点内是否为空
		virtual bool getIsEmpty() const;

	protected:
		TiXmlElement* mElement;
		bool mOwnsElement;
	};
}
