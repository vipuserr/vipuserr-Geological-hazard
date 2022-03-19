/////////////////////////////////////////////////////////////////////////////
//                                                                         //
//  This source file is part of Cug Geo3DModeling Team                  //
//  Copyright (c) 2017-08 by The Cug Geo3DModeling Team . All Rights Reserved    //
//                                                                         //
//  Filename: gm_aux_test.h												   //
//  Author  : Cug Geo3DModeling Team											   //
//  Modifier: Cug Geo3DModeling Team											   //
//																		   //
/////////////////////////////////////////////////////////////////////////////

#pragma once


#include "s3d_KerAuxExp.h"

namespace Smart3dMap
{
	class S3D_KERAUX_EXP aux_test
	{
	public:
		aux_test(){}
		virtual ~aux_test(){}

	public:
		static void writeLog(const char* strLog, string strName = "");
		
		static void writeLog_NoTime(string loginfo, string strName = "");
		static string stopwritelog();
		static void writeErrorLog(const char* strLog);
		static void getcurtime(string& strTime);
	public:
		static FILE *m_fp;
	};
}
