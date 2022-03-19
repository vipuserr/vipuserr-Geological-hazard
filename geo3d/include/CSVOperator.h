#pragma once

#include <vector>
#include <string>
#include <fstream>

#include "s3d_baseapplib_global.h"
#include "s3d_AttrDBDef.h"

namespace Smart3dMap
{
	class S3D_BASEAPPLIB_EXPORT CSVOperator
	{
	public:
		// for testing.
		static void writeHoleInfosToCSV(const std::string &file_path, const std::vector<HoleInfo> &hole_list);
	};

	/*
		\brief CSV�ļ�д����
	*/
	class CSVWriter
	{

	public:
		/*
			\brief ���캯������Ĭ�Ϲ��캯��

			\param file_path Ҫд���csv�ļ�·��(�����ļ�)���ļ����������Ҫ��ע�⣺�����ڣ��򸲸ǡ�
			\param col_name_list �����б�������Ҫ������������һ�����캯��
			\param seperator �зָ�����Ĭ��','
		*/
		CSVWriter(const std::string &file_path, const std::vector< std::string > &col_name_list, const char seperator = ',');
		/*
			\brief ���캯������Ĭ�Ϲ��캯��

			\param file_path Ҫд���csv�ļ�·��(�����ļ�)���ļ����������Ҫ��ע�⣺�����ڣ��򸲸ǡ�
			\param col_num ����������ʾcsv�ļ���һ�����ݵĸ���
			\param seperator �зָ�����Ĭ��','
		*/
		CSVWriter(const std::string &file_path, const int col_num, const char seperator = ',');
		~CSVWriter();

	public:
		/*
			\brief ���������������csv�ļ�

			\param data_list ������������һ��������������������(һ������)���ڶ����������������(ĳ�е�һ����Ԫ����)��
							˵�����ڶ��������ڵ����ݸ������Բ��̶�

		*/
		// 
		void write(const std::vector< std::vector<std::string> > &data_list);

	public:
		/*
			\brief ��������������+ģ�壬ʵ��"ofstream"����������������͵������������
					˵�������ݴ���һ����Ԫ�����ݣ�һ��δ����д�뵱ǰ�У��������Զ����У���д�����е��׵�Ԫ��
		*/
		template<class DType>
		CSVWriter &operator<<(const DType &data);

	private:
		std::string m_file_path; // ����ļ���
		char m_separator; // �зָ���
		std::ofstream m_out_file_stream; // ����ļ������󣬶�����ʱ�򿪣���������ʱ�رա�
		std::vector< std::string > m_col_name_list; // �����б� // TODO: Ӧ��ûʲô�ã����Բ��ñ���Ϊ���Ա
		int m_col_num; // ����������ʾcsv�ļ���һ�����ݵĸ���
		int m_seek; // ����д��λ��ָ�룬�����ж��ǻ��л���...
	};

	
}