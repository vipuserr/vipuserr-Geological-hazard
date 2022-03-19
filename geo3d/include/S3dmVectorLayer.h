#pragma once

#include "s3dqtapp_global.h"
#include "gmeStru.h"
#include "S3dmLabels.h"
#include "S3dmStyle.h"
#include <qgsfield.h>
#include <qgsproject.h>

#include <string>

class QgsVectorLayer;

enum S3dmLayerType
{
	S3DM_PNT = 1,
	S3DM_LINE = 2,
	S3DM_REG = 3,
	S3DM_UNKNOW = 4
};

namespace Smart3dMap
{
	class S3DQTAPP_EXPORT S3dmVectorLayer {
	public:
		//创建一个图层指针，该指针需要调用着释放
		//传入已存在的shp文件,传出type和S3dmVectorLayer指针，该指针指向对应子类
		static S3dmVectorLayer*  newLayerObject(S3dmLayerType& type, std::string file);
		//创建一个图层指针，该指针需要调用着释放
		//传入QgsVectorLayer,传出type和S3dmVectorLayer指针，该指针指向对应子类
		static S3dmVectorLayer* newLayerObject(S3dmLayerType& type, QgsVectorLayer* layer);

		//创建空的Shp文件
		static QgsVectorLayer* creatEmptyLayer(const std::string & fullPathFile, const S3dmLayerType & type, std::vector<QgsField>& fields);

		//设置字段
		void setFields(gmeFields& fields) { m_Fields = fields; }
		gmeFields& getFields() { return m_Fields; }
		//设置记录，数量和几何的个数一样
		void setRecords(gmeRecordSet& records) { m_Records = records; }
		gmeRecordSet& getRecords() { return m_Records; }
		//添加字段
		void addFields(gmeFields& fields);
		//添加记录
		void addRecords(gmeRecordSet& records);
		//删除字段
		void deleteField(GString fieldName);
		void deleteField(int fieldIndex);
		//删除记录,仅将记录（属性）清空，并未清除对应的要素
		void deleteRecord(int index);


		//设置注记样式
		void setLabels(S3dmLabels& label) { m_Lables = label; }
		S3dmLabels& getLabels() { return m_Lables; }


		//返回QgsVectorLayer
		virtual QgsVectorLayer* layer();

		virtual void updateLayer();
		virtual void updateStyle(); //仅更新样式
		void updateLabel();//仅更新注记
		virtual void updateFeature();//仅更新几何和属性

		//返回类型（点、线、面）
		S3dmLayerType type();

		bool save(std::string output);
		void setIsNeedRelease(bool isNeedRelease) { m_IsNewLayer = isNeedRelease; };

		virtual ~S3dmVectorLayer();
	protected:
		//内存级的矢量文件
		S3dmVectorLayer(S3dmLayerType type);
		//传入已存在的shp文件
		S3dmVectorLayer(std::string file);
		S3dmVectorLayer(QgsVectorLayer* layer, bool isNeedRelease = false);

	protected:
		void readShpInfo();

		QgsVectorLayer*		m_Layer;
		bool				m_IsNewLayer; //标识QGSVectorLayer是否是内部new的，如果是，则需要释放

		//字段的顺序和记录的顺序必须保持一致
		gmeFields			m_Fields;//字段
		gmeRecordSet		m_Records;//记录
		//注记
		S3dmLabels			m_Lables;
	private:
		S3dmLayerType		m_Type;
	};


	class S3DQTAPP_EXPORT S3dmPntLayer :public S3dmVectorLayer
	{
	public:
		S3dmPntLayer();
		S3dmPntLayer(std::string file);
		S3dmPntLayer(QgsVectorLayer* layer, bool isNeedRelease = false);
		virtual ~S3dmPntLayer();

		//图层更新：数据写入图层后需要调用更新图层函数
		virtual void updateLayer(); //更新所有信息
		virtual void updateStyle(); //仅更新样式
		virtual void updateFeature();//仅更新几何和属性

		//先设置几何，再设置属性
		void setPnts(std::vector<gme_vector2d>& pnts);
		std::vector<gme_vector2d>& getPnts() { return m_Pnts; }

		//设置要素样式
		void setStyle(S3dmPointStyle& style) { m_Styles = style; }
		S3dmPointStyle& getStyle() { return m_Styles; }

	private:
		void readShpInfo();

		std::vector<gme_vector2d>	m_Pnts;//几何
		S3dmPointStyle			m_Styles;
	};


	class S3DQTAPP_EXPORT S3dmLineLayer :public S3dmVectorLayer
	{
	public:
		S3dmLineLayer();
		S3dmLineLayer(std::string file);
		S3dmLineLayer(QgsVectorLayer* layer, bool isNeedRelease = false);
		~S3dmLineLayer();

		//图层更新：数据写入图层后需要调用更新图层函数
		virtual void updateLayer();
		virtual void updateStyle(); //仅更新样式
		virtual void updateFeature();//仅更新几何和属性

		//先设置几何，再设置属性
		void setLines(std::vector<std::vector<gme_vector2d>>& lines) { m_Lines = lines; };
		std::vector<std::vector<gme_vector2d>>& getLines() { return m_Lines; }
		//添加线
		void addLines(std::vector<std::vector<gme_vector2d>>& lines);
		//删除线
		void deleteLine(int idx);
		//修改线
		void updateLine(int idx, std::vector<gme_vector2d>& line);

		//设置要素样式
		void setStyle(S3dmLineStyle& style) { m_Styles = style; }
		S3dmLineStyle& getStyle() { return m_Styles; }
	private:
		void readShpInfo();

		std::vector<std::vector<gme_vector2d>> m_Lines;
		S3dmLineStyle				 m_Styles;
	};

	typedef std::vector<gme_vector2d> Reg;//封闭区
	typedef std::vector<Reg> S3dmReg; //含有空洞的封闭区（假如一个区中含有一个洞，即为两个Reg）

	class S3DQTAPP_EXPORT S3dmRegLayer :public S3dmVectorLayer
	{
	public:
		S3dmRegLayer();
		S3dmRegLayer(std::string file);
		S3dmRegLayer(QgsVectorLayer* layer, bool isNeedRelease = false);
		~S3dmRegLayer();

		//图层更新：数据写入图层后需要调用更新图层函数
		virtual void updateLayer();
		virtual void updateStyle(); //仅更新样式
		virtual void updateFeature();//仅更新几何和属性

		//先设置几何，再设置属性
		void setRegs(std::vector<S3dmReg>& regs) { m_Regs = regs; }
		std::vector<S3dmReg>& getRegs() { return m_Regs; }
		//添加区
		void addRegs(std::vector<S3dmReg>& regs);
		//删除区
		void deleteReg(int idx);
		//修改区
		void updateReg(int idx, S3dmReg& reg);



		//设置要素样式
		void setStyle(S3dmRegStyle& style) { m_Styles = style; }
		S3dmRegStyle& getStyle() { return m_Styles; };

	private:
		void readShpInfo();
		void readShpStyle();

		void readSimpleStyle(QgsSymbol* symbol);


		std::vector<S3dmReg>			m_Regs;
		S3dmRegStyle			m_Styles;
	};


	class S3DQTAPP_EXPORT S3dmQgsProject
	{
	public:
		S3dmQgsProject(QgsProject* prj);
		virtual ~S3dmQgsProject();

		void saveProject(QString qgsPath);

		QgsRectangle extent();
		void getLayerList(QList<QgsMapLayer*>& layerList);

	private:
		void getLayerList(std::vector<QgsMapLayer*>& layerList);
	private:
		QgsProject* m_qgsPrj;

	};
}
