///////////////////////////////////////////////////////////////////////////
//
//  This source file is part of Cug Geo3DModeling Team
//  Copyright (c) 2008-2009 by The Cug Geo3DModeling Team . All Rights Reserved
//
///////////////////////////////////////////////////////////////////////////
//
//  Filename: gm_string_ext.h
//  Author  : Cug Geo3DModeling Team 
//  Modifier: Cug Geo3DModeling Team  
//  Created : 
//  Purpose : value_convert class
//	Reference : 
//
///////////////////////////////////////////////////////////////////////////
#ifndef _GM_VALUE_CONVERT_H_
#define _GM_VALUE_CONVERT_H_

#include "s3d_KerAuxExp.h"
#include "s3d_common_file.h"
#include "gme_vector3.h"

namespace Smart3dMap
{
	class S3D_KERAUX_EXP string_ext
	{
	public:
		string_ext( void ) { }
		~string_ext( void ) { }

	public:
        // multibyte version
		static bool		to_bool( string value );

		static int		to_int ( string value );// base = 10
		
		static long     to_long ( string value );// base = 10

		static dword    to_dword ( string value );// base = 16

		static float	to_float( string value );

		static double	to_double( string value );

		static interior_index  to_int64( string value );// base = 16

        static wstring  to_wstring ( string value );

		static time_t    to_time_in_seconds( string value);

#ifndef _UNICODE
		static void     to_vector3_array ( string value, std::vector< vector3<double> >& vec3_array );
#endif //_UNICODE

	public:
		static string	from_bool( bool value );

		static string   from_int ( int value );// base = 10

		static string   from_long ( long value );

		static string   from_dword ( dword value );// base = 16

		static string	from_float( float value );

		static string	from_double( double value );

		static string   from_int64 ( interior_index value );// base = 16

		static string   from_wstring ( wstring value );

	public:
        // unicode version
		static bool		wto_bool( wstring value );

		static int		wto_int( wstring value );

		static dword	wto_dword( wstring value );

		static float	wto_float( wstring value );

		static double	wto_double( wstring value );

		static interior_index	wto_int64( wstring value );

	public:
		// w from
		static wstring	wfrom_bool( bool value );

		static wstring	wfrom_int( int value );

		static wstring	wfrom_dword( dword value );

		static wstring	wfrom_float( float value );

		static wstring	wfrom_double( double value );

		static wstring	wfrom_int64( interior_index value );
	};

}

#endif // _GM_VALUE_CONVERT_H_
