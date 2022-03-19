 #pragma once 



#include "OGBasDef.h"


namespace Smart3dMap 
{
	const string TREE_NODE_TYPE = "�ڵ�����";
	const string TREE_NODE_NAME = "�ڵ�����";
	const string TREE_NODE_CAPTION = "�ڵ����";
	const string TREE_NODE_URL = "�ڵ�URL";
	const string TREE_NODE_ICON = "�ڵ�Icon����";

	class OG_FRAME_DLL DataElement
	{
	public:
		DataElement() {}
		virtual ~DataElement() {}

	public:
		virtual DataElement* createChild(const string& name) = 0;
		virtual DataElement* getFirstChild(const string& name) = 0;
		virtual DataElement* getNextSibling() = 0;
		virtual DataElement* getParent() = 0;

		//ȡ���ؼ���Ϣ...
		virtual string getType(string& strType) = 0;
		virtual string getName(string& strName) = 0;
		virtual string getCaption(string& strCaption) = 0;
		virtual string getIconName(string& strIconName) = 0;
		virtual string getUrl(string& strUrl) = 0;

		//���ùؼ���Ϣ...
		virtual void setType(string strType) = 0;
		virtual void setName(string strName) = 0;
		virtual void setCaption(string strCaption) = 0;
		virtual void setIconName(string strIconName) = 0;
		virtual void setUrl(string strUrl) = 0;

		//��ȡ�ڵ�����
		virtual int getAttributeInt(const string& name, int defaultVal = 0) const = 0;
		virtual unsigned int getAttributeUnsignedInt(const string& name, unsigned int defaultVal = 0) const = 0;
		virtual long getAttributeLong(const string& name, long defaultVal = 0) const = 0;
		virtual unsigned long getAttributeUnsignedLong(const string& name, unsigned long defaultVal = 0) const = 0;
		virtual float getAttributeFloat(const string& name, float defaultVal = 0.0f) const = 0;
		virtual string getAttributeString(const string& name, string& defaultVal=(string&)string("") ) const = 0;
		virtual string getAttributeString(const string& name, const char* defaultVal) const = 0;
		virtual bool getAttributeBool(const string& name, bool defaultVal = true) const = 0;
		virtual Vector3 getAttributeVector3(const string& name, const Vector3& defaultValue = Vector3(0,0,0)) const = 0;
		virtual Smart3dMap::Matrix3 getAttributeMatrix3(const string& name, const Smart3dMap::Matrix3& defaultValue) const = 0;
		virtual Matrix4 getAttributeMatrix4(const string& name, const Matrix4& defaultValue) const = 0;			
		virtual Smart3dMap::Quaternion getAttributeQuaternion(const string& name, const Smart3dMap::Quaternion& defaultValue) const = 0;
		virtual ColourValue getAttributeColourValue(const string& name, const ColourValue& defaultValue) const = 0;
//		virtual DataStreamPtr getAttributeDataStream(const string& name) const = 0;

		//���ýڵ�����
		virtual void setAttribute(const string& name, int val) = 0;
		virtual void setAttribute(const string& name, unsigned int val) = 0;
		virtual void setAttribute(const string& name, long val) = 0;
		virtual void setAttribute(const string& name, unsigned long val) = 0;
		virtual void setAttribute(const string& name, const __int64& val) = 0;
		virtual void setAttribute(const string& name, float val) = 0;
		virtual void setAttribute(const string& name, const string& val) = 0;
		virtual void setAttribute(const string& name, const char* val) = 0;
		virtual void setAttribute(const string& name, bool val) = 0;
		virtual void setAttribute(const string& name, const Vector3& val) = 0;
		virtual void setAttribute(const string& name, const Smart3dMap::Matrix3& val) = 0;
		virtual void setAttribute(const string& name, const Matrix4& val) = 0;			
		virtual void setAttribute(const string& name, const Smart3dMap::Quaternion& val) = 0;
		virtual void setAttribute(const string& name, const ColourValue& val) = 0;
//		virtual void setAttribute(const string& name, const DataStreamPtr& val) = 0;
	
		//�жϽڵ����Ƿ�Ϊ��
		virtual bool getIsEmpty() const = 0;
	};

}
