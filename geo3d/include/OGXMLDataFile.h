 #pragma once



//forward declaration
class TiXmlDocument;

namespace Smart3dMap 
{
	class OG_FRAME_DLL XMLDataFile
	{
	public:

		/** 
		*/
		XMLDataFile();

		/** 
		*/
		virtual ~XMLDataFile();

		/** 
		*/
		virtual bool load(const string& filePath);

		/** 
		*/
		virtual bool save(const string& filePath);

		/** 
		*/
		DataElement* getRootElement();

		/** 
		*/
		DataElement* createRootElement(const string& name);

	protected:

		TiXmlDocument* mDoc;
		XMLDataElement* mRootElement;

	};
}

