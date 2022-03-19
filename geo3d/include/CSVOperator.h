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
		\brief CSV文件写入类
	*/
	class CSVWriter
	{

	public:
		/*
			\brief 构造函数，无默认构造函数

			\param file_path 要写入的csv文件路径(包括文件)，文件存在与否不重要，注意：若存在，则覆盖。
			\param col_name_list 列名列表，若不需要列名，则用下一个构造函数
			\param seperator 列分隔符，默认','
		*/
		CSVWriter(const std::string &file_path, const std::vector< std::string > &col_name_list, const char seperator = ',');
		/*
			\brief 构造函数，无默认构造函数

			\param file_path 要写入的csv文件路径(包括文件)，文件存在与否不重要，注意：若存在，则覆盖。
			\param col_num 列数量，表示csv文件中一行数据的个数
			\param seperator 列分隔符，默认','
		*/
		CSVWriter(const std::string &file_path, const int col_num, const char seperator = ',');
		~CSVWriter();

	public:
		/*
			\brief 将多组数据输出到csv文件

			\param data_list 两层容器，第一层容器代表行数据容器(一行数据)，第二层代表列数据容器(某行的一个单元数据)。
							说明：第二层容器内的数据个数可以不固定

		*/
		// 
		void write(const std::vector< std::vector<std::string> > &data_list);

	public:
		/*
			\brief 输出流运算符重载+模板，实现"ofstream"对象允许的数据类型的流插入操作。
					说明：数据代表一个单元格数据，一行未满则写入当前行，行满则自动换行，并写入新行的首单元。
		*/
		template<class DType>
		CSVWriter &operator<<(const DType &data);

	private:
		std::string m_file_path; // 输出文件名
		char m_separator; // 列分隔符
		std::ofstream m_out_file_stream; // 输出文件流对象，对象构造时打开，对象析构时关闭。
		std::vector< std::string > m_col_name_list; // 列名列表 // TODO: 应该没什么用，可以不用保存为类成员
		int m_col_num; // 列数量，表示csv文件中一行数据的个数
		int m_seek; // 数据写入位置指针，用于判断是换行还是...
	};

	
}