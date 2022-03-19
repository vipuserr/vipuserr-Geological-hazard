 // OGUserDefinedObject.h: interface for the R3DUserDefinedObject class.
//
//////////////////////////////////////////////////////////////////////

#pragma once

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include "OGBasDef.h"



namespace Smart3dMap {

	
    class OG_FRAME_DLL UserDefinedObject
    {
    public:
		UserDefinedObject(){}
        virtual ~UserDefinedObject() {}

		virtual long getTypeID(void) const{return 0;}

        virtual const string& getTypeName(void) const 
		{
			static string sName("Unspecified");
			return sName;
		}
        
    };

	class OG_FRAME_DLL OGUserDefinedObject : public UserDefinedObject  
	{
	public:
		OGUserDefinedObject();
		~OGUserDefinedObject();

		virtual long getTypeID(void) const { return 0; }

		virtual const string& getTypeName(void) const { return mTypeName; }
		virtual void setTypeName(const string& name) { mTypeName = name; }

		/*
		*/
		virtual long getEffectUseIndex() const { return mEffectUseIndex; }
		virtual void setEffectUseIndex(long index) { mEffectUseIndex = index; }
		
	private:
		string	mTypeName;
		long	mEffectUseIndex;

	};

}

