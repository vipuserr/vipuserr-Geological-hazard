 #ifndef __TiXMLPrerequisites_H__
#define __TiXMLPrerequisites_H__

#include "ogUtilityDefine.h"

#ifdef _MSC_VER
#pragma warning( push )
#pragma warning( disable : 4103 )
#pragma warning( disable : 4251 )
#pragma warning( disable : 4530 )
#pragma warning( disable : 4616 )
#pragma warning( disable : 4786 )
#endif

class TiXmlDocument;
class TiXmlElement;
class TiXmlComment;
class TiXmlUnknown;
class TiXmlAttribute;
class TiXmlText;
class TiXmlDeclaration;
class TiXmlParsingData;

const int TIXML_MAJOR_VERSION = 2;
const int TIXML_MINOR_VERSION = 4;
const int TIXML_PATCH_VERSION = 2;

#define TIXML_USE_STL


#endif