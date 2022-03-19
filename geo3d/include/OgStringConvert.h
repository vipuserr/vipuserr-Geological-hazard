#pragma once

#include "OGBasDef.h"
#include "OGGenericUtils.h"


namespace Smart3dMap {


    class OG_FRAME_DLL ogStringConvert
    {
    public:

        /** Converts a Real to a string. */
        static string toString(Real val, unsigned short precision = 6, 
            unsigned short width = 0, char fill = ' ', 
            std::ios::fmtflags flags = std::ios::fmtflags(0) );
        /** Converts a Radian to a string. */
        static string toString(Radian val, unsigned short precision = 6, 
            unsigned short width = 0, char fill = ' ', 
            std::ios::fmtflags flags = std::ios::fmtflags(0) )
        {
            return "";//toString(val.valueAngleUnits(), precision, width, fill, flags);
        }
        /** Converts a Degree to a string. */
        static string toString(Degree val, unsigned short precision = 6, 
            unsigned short width = 0, char fill = ' ', 
            std::ios::fmtflags flags = std::ios::fmtflags(0) )
        {
            return "";//toString(val.valueAngleUnits(), precision, width, fill, flags);
        }
        /** Converts an int to a string. */
        static string toString(int val, unsigned short width = 0, 
            char fill = ' ', 
            std::ios::fmtflags flags = std::ios::fmtflags(0) );

		static string toString(unsigned int val, unsigned short width = 0,
			char fill = ' ',
			std::ios::fmtflags flags = std::ios::fmtflags(0));

		/** Converts a size_t to a string. */
        static string toString(size_t val, 
            unsigned short width = 0, char fill = ' ', 
            std::ios::fmtflags flags = std::ios::fmtflags(0) );
        /** Converts an unsigned long to a string. */
        static string toString(unsigned long val, 
            unsigned short width = 0, char fill = ' ', 
            std::ios::fmtflags flags = std::ios::fmtflags(0) );

        /** Converts a long to a string. */
        static string toString(long val, 
            unsigned short width = 0, char fill = ' ', 
            std::ios::fmtflags flags = std::ios::fmtflags(0) );
        /** Converts a boolean to a string. 
        @param yesNo If set to true, result is 'yes' or 'no' instead of 'true' or 'false'
        */
        static string toString(bool val, bool yesNo = false);
		/** Converts a Vector2 to a string. 
        @remarks
            Format is "x y" (i.e. 2x Real values, space delimited)
        */
        static string toString(const Vector2& val);
        /** Converts a Vector3 to a string. 
        @remarks
            Format is "x y z" (i.e. 3x Real values, space delimited)
        */
        static string toString(const Vector3& val);
		/** Converts a Vector4 to a string. 
        @remarks
            Format is "x y z w" (i.e. 4x Real values, space delimited)
        */
        static string toString(const Vector4& val);
        /** Converts a Matrix3 to a string. 
        @remarks
            Format is "00 01 02 10 11 12 20 21 22" where '01' means row 0 column 1 etc.
        */
        static string toString(const Smart3dMap::Matrix3& val);
        /** Converts a Matrix4 to a string. 
        @remarks
            Format is "00 01 02 03 10 11 12 13 20 21 22 23 30 31 32 33" where 
            '01' means row 0 column 1 etc.
        */
        static string toString(const Matrix4& val);
        /** Converts a Quaternion to a string. 
        @remarks
            Format is "w x y z" (i.e. 4x Real values, space delimited)
        */
        static string toString(const Smart3dMap::Quaternion& val);
        /** Converts a ColourValue to a string. 
        @remarks
            Format is "r g b a" (i.e. 4x Real values, space delimited). 
        */
        static string toString(const ColourValue& val);
        /** Converts a StringVector to a string.
        @remarks
            Strings must not contain spaces since space is used as a delimiter in
            the output.
        */
        static string toString(const StringVector& val);

        /** Converts a string to a Real. 
        @returns
            0.0 if the value could not be parsed, otherwise the Real version of the string.
        */
        static Real parseReal(const string& val, Real defaultValue = 0);
        /** Converts a string to a Angle. 
        @returns
            0.0 if the value could not be parsed, otherwise the Angle version of the string.
        */
  //      static inline Radian parseAngle(const string& val, Radian defaultValue = Radian(0)) {
		//	return Angle(parseReal(val, defaultValue.valueRadians()));
		//}
        /** Converts a string to a whole number. 
        @returns
            0.0 if the value could not be parsed, otherwise the numeric version of the string.
        */
        static int parseInt(const string& val, int defaultValue = 0);
        /** Converts a string to a whole number. 
        @returns
            0.0 if the value could not be parsed, otherwise the numeric version of the string.
        */
        static unsigned int parseUnsignedInt(const string& val, unsigned int defaultValue = 0);
        /** Converts a string to a whole number. 
        @returns
            0.0 if the value could not be parsed, otherwise the numeric version of the string.
        */
        static long parseLong(const string& val, long defaultValue = 0);
        /** Converts a string to a whole number. 
        @returns
            0.0 if the value could not be parsed, otherwise the numeric version of the string.
        */
        static unsigned long parseUnsignedLong(const string& val, unsigned long defaultValue = 0);
        /** Converts a string to a boolean. 
        @remarks
            Returns true if case-insensitive match of the start of the string
			matches "true", "yes" or "1", false otherwise.
        */
        static bool parseBool(const string& val, bool defaultValue = 0);
		/** Parses a Vector2 out of a string.
        @remarks
            Format is "x y" ie. 2 Real components, space delimited. Failure to parse returns
            Vector2::ZERO.
        */
		static Vector2 parseVector2(const string& val, const Vector2& defaultValue);
		/** Parses a Vector3 out of a string.
        @remarks
            Format is "x y z" ie. 3 Real components, space delimited. Failure to parse returns
            Vector3::ZERO.
        */
        static Vector3 parseVector3(const string& val, const Vector3& defaultValue=Vector3(0,0,0));
        /** Parses a Vector4 out of a string.
        @remarks
            Format is "x y z w" ie. 4 Real components, space delimited. Failure to parse returns
            Vector4::ZERO.
        */
        static Vector4 parseVector4(const string& val, const Vector4& defaultValue=Vector4(0,0,0,0));
        /** Parses a Matrix3 out of a string.
        @remarks
            Format is "00 01 02 10 11 12 20 21 22" where '01' means row 0 column 1 etc.
            Failure to parse returns Matrix3::IDENTITY.
        */
        static Smart3dMap::Matrix3 parseMatrix3(const string& val, const Smart3dMap::Matrix3& defaultValue);
        /** Parses a Matrix4 out of a string.
        @remarks
            Format is "00 01 02 03 10 11 12 13 20 21 22 23 30 31 32 33" where 
            '01' means row 0 column 1 etc. Failure to parse returns Matrix4::IDENTITY.
        */
        static Matrix4 parseMatrix4(const string& val, const Matrix4& defaultValue);
        /** Parses a Quaternion out of a string. 
        @remarks
            Format is "w x y z" (i.e. 4x Real values, space delimited). 
            Failure to parse returns Quaternion::IDENTITY.
        */
        static Smart3dMap::Quaternion parseQuaternion(const string& val, const Smart3dMap::Quaternion& defaultValue);
        /** Parses a ColourValue out of a string. 
        @remarks
            Format is "r g b a" (i.e. 4x Real values, space delimited), or "r g b" which implies
            an alpha value of 1.0 (opaque). Failure to parse returns ColourValue::Black.
        */
        static ColourValue parseColourValue(const string& val, const ColourValue& defaultValue=ColourValue(0,0,0,0));

        /** Pareses a StringVector from a string.
        @remarks
            Strings must not contain spaces since space is used as a delimiter in
            the output.
        */
        static StringVector parseStringVector(const string& val);
        /** Checks the string is a valid number value. */
        static bool isNumber(const string& val);
    };

	/** @} */
	/** @} */

}