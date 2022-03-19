#ifndef _I_ARCHIVE_H_
#define _I_ARCHIVE_H_

#include "Og3DRE_Def.h"

namespace Smart3dMap
{
	class _OG3D_RENDERENGINE_DLL ogArchive :public osgDB::Archive
	{
	public:
		ogArchive();
		ogArchive(const ogArchive& eh,const osg::CopyOp& copyop=osg::CopyOp::SHALLOW_COPY){}
		virtual ~ogArchive();

		META_Object(Smart3dMap,ogArchive);

		OC::String getArchiveFileName() const;
		void setArchiveFileName(OC::String name){mArchiveFileName = name;}

		OC::String getMasterFileName() const;
		void setMasterFileName(OC::String name){mMasterFileName = name;}

		virtual bool acceptsExtension(const OC::String& extension) const { return true; }
		virtual void close(){}
		virtual bool fileExists(const OC::String& filename) const{return false;}
		virtual bool getFileNames(osgDB::Archive::FileNameList& fileNameList) const{return false;}
		virtual osgDB::FileType getFileType(const OC::String& filename) const{return osgDB::FILE_NOT_FOUND;}

		virtual osgDB::ReaderWriter::ReadResult readObject(const OC::String& /*fileName*/, const osgDB::ReaderWriter::Options* =NULL) const{return osgDB::ReaderWriter::ReadResult::NOT_IMPLEMENTED;}
		virtual osgDB::ReaderWriter::ReadResult readImage(const OC::String& /*fileName*/,const osgDB::ReaderWriter::Options* =NULL) const{return osgDB::ReaderWriter::ReadResult::NOT_IMPLEMENTED;}
		virtual osgDB::ReaderWriter::ReadResult readHeightField(const OC::String& /*fileName*/,const osgDB::ReaderWriter::Options* =NULL) const{return osgDB::ReaderWriter::ReadResult::NOT_IMPLEMENTED;}
		virtual osgDB::ReaderWriter::ReadResult readNode(const OC::String& /*fileName*/, const osgDB::ReaderWriter::Options* =NULL) const;
		virtual osgDB::ReaderWriter::ReadResult readShader(const OC::String& /*fileName*/, const osgDB::ReaderWriter::Options* =NULL) const{return osgDB::ReaderWriter::ReadResult::NOT_IMPLEMENTED;}

        virtual osgDB::ReaderWriter::ReadResult readRest(const OC::String& /*fileName*/, const osgDB::ReaderWriter::Options* = NULL) const;

		virtual osgDB::ReaderWriter::WriteResult writeObject(const osg::Object& /*obj*/, const OC::String& /*fileName*/,const osgDB::ReaderWriter::Options* =NULL) const{return osgDB::ReaderWriter::WriteResult::NOT_IMPLEMENTED;}
		virtual osgDB::ReaderWriter::WriteResult writeImage(const osg::Image& /*image*/, const OC::String& /*fileName*/,const osgDB::ReaderWriter::Options* =NULL) const{return osgDB::ReaderWriter::WriteResult::NOT_IMPLEMENTED;}
		virtual osgDB::ReaderWriter::WriteResult writeHeightField(const osg::HeightField& /*heightField*/, const OC::String& /*fileName*/,const osgDB::ReaderWriter::Options* =NULL) const{return osgDB::ReaderWriter::WriteResult::NOT_IMPLEMENTED;}
		virtual osgDB::ReaderWriter::WriteResult writeNode(const osg::Node& /*node*/, const OC::String& /*fileName*/,const osgDB::ReaderWriter::Options* =NULL) const{return osgDB::ReaderWriter::WriteResult::NOT_IMPLEMENTED;}
		virtual osgDB::ReaderWriter::WriteResult writeShader(const osg::Shader& /*shader*/, const OC::String& /*fileName*/,const osgDB::ReaderWriter::Options* =NULL) const{return osgDB::ReaderWriter::WriteResult::NOT_IMPLEMENTED;}
	protected:
		OC::String													mMasterFileName;
		OC::String													mArchiveFileName;
	};
}


#endif