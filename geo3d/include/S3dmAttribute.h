#pragma once
#include "s3dqtapp_global.h"
#include "gmeStru.h"
#include "qgsfield.h"
#include "qgsattributes.h"
#include <string>

using namespace std;

//*******************************************************************
//Class Name:S3dmAttribute
//Summary: Qgs�����Ժ��ֶ���S3dm�����Ժ��ֶε��໥ת��
//Author:zhuyh
//Date:2021-06-06  16:05
//********************************************************************

namespace Smart3dMap {
	class S3DQTAPP_EXPORT S3dmAttribute
	{
	public:
		//Qgs��Field��S3dm��Field�໥ת��
		static void QgsFld2S3dmFld(QgsField* qgsFld, gmeField& s3dmFld);
		static void S3dmFld2QgsFld(gmeField* s3dmFld, QgsField& qgsFld);

		static void QgsType2gmeType(const QVariant::Type& type, gmeFieldValue::gmeType& s3dmType);
		static void gmeType2QgsType(const gmeFieldValue::gmeType& type, QVariant::Type& qgsType);

		//Qgs��Attr��S3dm��gmeFieldValue�໥ת��
		static void QgsAttr2S3dmAttr(QgsAttributes* attrs, gmeFieldValues& s3dmAttrs);
		static void QgsAttr2S3dmAttr(QVariant* attr, gmeFieldValue& s3dmAttr);
		static void S3dmAttr2QgsAttr(gmeFieldValues* s3dmAttrs, QgsAttributes& attrs);
		static void S3dmAttr2QgsAttr(gmeFieldValue* s3dmAttr, QVariant& attr);
		//��һ����¼�и����ֶ�����ȡ�ֶ�ֵ
		static void getS3dmFldValueByName(std::string fieldName, gmeRecord *record, gmeFieldValue& fldVal);
	};
}
