#pragma once
#include "s3dqtapp_global.h"
#include "qgssinglesymbolrenderer.h"
#include "qgscategorizedsymbolrenderer.h"
#include "qgsgraduatedsymbolrenderer.h"
#include "qgsnullsymbolrenderer.h"
enum S3dmStyleType
{
	SingleSymbol = 1,//颜色样式
	CategoriedSymbol = 2,//分级样式
	GraduatedSymbol = 3, //渐变样式
	NullSymbol = 4 //无样式
};

class S3DQTAPP_EXPORT S3dmStyle
{
public:
	enum SingleRenderType
	{
		COLOR = 0,//颜色渲染
		PATTERN = 1//图案渲染
	};
public:
	S3dmStyle(QgsWkbTypes::GeometryType geomType);

	void setType(S3dmStyleType style) { m_Type = style; }
	S3dmStyleType type() { return m_Type; }

	virtual void getSingleSymbolRender(QgsSingleSymbolRenderer* render)=0;
	virtual void getCategoriedSymbolRender(QgsCategorizedSymbolRenderer* render)=0;
	virtual void getGraduatedSymbolRender(QgsGraduatedSymbolRenderer* render)=0;

protected:
	S3dmStyleType						m_Type; //样式的类型，三者选其一
	SingleRenderType					m_RenderType;//单一渲染类型
};

//1、点简单样式---颜色（圆）
class S3DQTAPP_EXPORT PntColorAttr
{
public:
	enum Shape
	{
		SQUARE = 0,
		CIRCLE = 1,
		CROSS = 2,
	};
public:
	double						opacity;//透明度
	Shape						fillStyle;//填充图形
	QColor						fillColor;//填充颜色
	double						fillSize; //尺寸
	QgsUnitTypes::RenderUnit	fillSizeUnit;//尺寸单位
	QColor						borderColor;//边框颜色
	Qt::PenStyle				borderStyle;//边框样式
	double						borderWidth;//边框宽度
	QgsUnitTypes::RenderUnit borderWidthUnit;//边框宽度单位
	double						rotation;//旋转度数

	PntColorAttr()
	{
		opacity = 1;
		fillStyle = Shape::CIRCLE;
		fillColor = QColor(255, 255, 255);
		fillSize = 1;
		fillSizeUnit = QgsUnitTypes::RenderUnit::RenderMillimeters;
		borderColor = QColor(0, 0, 0);
		borderStyle = Qt::PenStyle::SolidLine;
		borderWidth = 1;
		borderWidthUnit = QgsUnitTypes::RenderUnit::RenderMillimeters;
		rotation = 0.0;

	}

	void getMarkerSymbol(QgsMarkerSymbol* symbol);

};
//1、点简单样式---图案
class S3DQTAPP_EXPORT PntPatternAttr
{
public:
	std::string					patternName;//图案路径
	double						width;//图案宽度
	double						height;//图案高度
	QgsUnitTypes::RenderUnit	sizeUnit;//宽高单位

	QColor						fillColor;//填充颜色(背景色)

	QColor						borderColor;//边框颜色
	double						borderWidth;//边框宽度
	QgsUnitTypes::RenderUnit	borderWidthUnit;//边框宽度单位
	double						opacity;//透明度
	double						rotation;//图案旋转角度:0-360

	PntPatternAttr()
	{
		opacity = 1;
		patternName = "";
		width = 6;
		height = 6;
		sizeUnit = QgsUnitTypes::RenderUnit::RenderMillimeters;
		fillColor = QColor(255, 255, 255);
		borderColor = QColor(0, 0, 0);
		borderWidth = 1;
		borderWidthUnit = QgsUnitTypes::RenderUnit::RenderMillimeters;
		rotation = 0;
	}

	void getMarkerSymbol(QgsMarkerSymbol*& symbol);
};
//2、点分级样式
class S3DQTAPP_EXPORT PntCategoryAttr
{
public:
	void setFieldName(std::string fieldName) { m_fieldName = fieldName; }
	std::string getFieldName() { return m_fieldName; }

	void addColorRender(QVariant fieldVal, PntColorAttr& singleAttr);
	void addPatternRender(QVariant fieldVal, PntPatternAttr& patternAttr);
	//void addQgsSymbolRender(QVariant fieldVal, QgsMarkerSymbol*  symbol);

	void clearRender();

	void getCategoryRender(std::map<QVariant, QgsRendererCategory>& cates);
	void setCategoryRender(const std::map<QVariant, QgsRendererCategory>& cates);
private:
	std::string								   m_fieldName = "";
	std::map<QVariant, QgsRendererCategory> m_categoryRenderList;
};
//3、点渐变样式
class S3DQTAPP_EXPORT PntGraduatedAttr
{
public:
	void setFieldName(std::string fieldName) { m_fieldName = fieldName; }
	std::string getFieldName() { return m_fieldName; }

	void addColorRender(double lowerValue, double upperValue, PntColorAttr& singleAttr);
	void addPatternRender(double lowerValue, double upperValue, PntPatternAttr& patternAttr);
	//void addQgsSymbolRender(double lowerValue, double upperValue, QgsMarkerSymbol & symbol);

	void deleteRender(double lowerValue, double upperValue);
	void clearRender();

	void getGraduatedRender(QgsRangeList& qgsRangeList);
private:
	std::string	m_fieldName = "";
	QgsRangeList m_graduateRenderList;
};

class S3DQTAPP_EXPORT S3dmPointStyle:public S3dmStyle
{
	friend class S3dmVectorCateStyleDialog;
	friend class S3dmVectorClassStyleDialog;
public:
	S3dmPointStyle();
	
	//1、简单样式：以下三种样式选择其一
	//单一样式：颜色
	void setSimpleSymbol(PntColorAttr& pntColorAttr);
	//Svg样式：图案
	void setPatternSymbol(PntPatternAttr& pntPatternAttr);

	//2、分级样式
	void setCategorySymbol(PntCategoryAttr& cateAttr);

	//3、渐变样式
	void setGraduatedSymbol(PntGraduatedAttr& gradAttr);

	//4.无样式
	void setNullSymbol();

	virtual void getSingleSymbolRender(QgsSingleSymbolRenderer* render);
	virtual void getCategoriedSymbolRender(QgsCategorizedSymbolRenderer* render);
	virtual void getGraduatedSymbolRender(QgsGraduatedSymbolRenderer* render);

private:
	PntColorAttr		m_pntColorAttr;//区颜色
	PntPatternAttr		m_pntPatternAttr;//区图案
	PntCategoryAttr		m_CateAttr;
	PntGraduatedAttr	m_GradAttr;
};


//1、线简单样式---颜色
class S3DQTAPP_EXPORT LineColorAttr
{
public:
	double						opacity;//透明度
	QColor						color;//颜色
	Qt::PenStyle				style;//线类型
	double						width;//线宽
	QgsUnitTypes::RenderUnit	widthUnit;//线宽单位

	LineColorAttr()
	{
		opacity = 1;
		color = QColor(0, 0, 0);
		style = Qt::PenStyle::SolidLine;
		width = 0.2;
		widthUnit = QgsUnitTypes::RenderUnit::RenderMillimeters;
	}

	void getLineSymbol(QgsLineSymbol* symbol);
};
//2、线分级样式
class S3DQTAPP_EXPORT LineCategoryAttr
{
public:
	void setFieldName(std::string fieldName) { m_fieldName = fieldName; }
	std::string getFieldName() { return m_fieldName; }

	void addColorRender(QVariant fieldVal, LineColorAttr& singleAttr);
	//void addQgsSymbolRender(QVariant fieldVal, QgsLineSymbol& symbol);

	void clearRender();

	void getCategoryRender(std::map<QVariant, QgsRendererCategory>& cates);
	void setCategoryRender(const std::map<QVariant, QgsRendererCategory>& cates);
private:
	std::string								   m_fieldName = "";
	std::map<QVariant, QgsRendererCategory> m_categoryRenderList;
};
//3、线渐变样式
class S3DQTAPP_EXPORT LineGraduatedAttr
{
public:
	void setFieldName(std::string fieldName) { m_fieldName = fieldName; }
	std::string getFieldName() { return m_fieldName; }

	void addColorRender(double lowerValue, double upperValue, LineColorAttr& singleAttr);
	//void addQgsSymbolRender(double lowerValue, double upperValue, QgsLineSymbol& symbol);

	void deleteRender(double lowerValue, double upperValue);
	void clearRender();

	void getGraduatedRender(QgsRangeList& grads);
private:
	std::string	m_fieldName = "";
	QgsRangeList m_graduateRenderList;
};

class S3DQTAPP_EXPORT S3dmLineStyle :public S3dmStyle
{
	friend class S3dmVectorCateStyleDialog;
	friend class S3dmVectorClassStyleDialog;
public:
	S3dmLineStyle();
	
	//1、简单样式
	//单一样式：颜色
	void setSimpleSymbol(LineColorAttr& simpleSymbol);

	//2、分级样式
	void setCategorySymbol(LineCategoryAttr& cateAttr);

	//3.渐变样式
	void setGraduatedSymbol(LineGraduatedAttr& gradAttr);

	//4.无样式
	void setNullSymbol();

	virtual void getSingleSymbolRender(QgsSingleSymbolRenderer* render);
	virtual void getCategoriedSymbolRender(QgsCategorizedSymbolRenderer* render);
	virtual void getGraduatedSymbolRender(QgsGraduatedSymbolRenderer* render);
private:
	LineColorAttr			m_ColorAttr;
	LineCategoryAttr		m_CateAttr;
	LineGraduatedAttr		m_GradAttr;
};



//1、区简单样式---颜色
class S3DQTAPP_EXPORT RegColorAttr
{
public:
	QColor				fillColor;//填充颜色

	Qt::PenStyle		borderStyle;//边框样式
	QColor				borderColor;//边框颜色
	double				borderWidth;//边框宽度
	QgsUnitTypes::RenderUnit borderWidthUnit;//边框宽度单位

	RegColorAttr()
	{
		fillColor = QColor(255, 255, 255);
		borderColor = QColor(0, 0, 0);
		borderStyle = Qt::PenStyle::SolidLine;
		borderWidth = 0.2;
		borderWidthUnit = QgsUnitTypes::RenderUnit::RenderMillimeters;
	}

	void getFillSymbol(QgsFillSymbol* symbol);

};
//1、区简单样式---图案
class S3DQTAPP_EXPORT RegPatternAttr
{
public:
	std::string					patternName;//图案名称
	QColor						patternColor;//图案背景色
	double						patternWidth;//图案宽度
	QgsUnitTypes::RenderUnit	patternWidthUnit;//图案宽度单位
	double						rotation;//图案旋转角度:0-360

	double						opacity;//透明度

	QColor						borderColor;//边框颜色
	double						borderWidth;//边框宽度
	QgsUnitTypes::RenderUnit	borderWidthUnit;//边框宽度单位

	RegPatternAttr()
	{
		opacity = 1;
		patternName = "";
		patternColor = QColor(255, 0, 0);
		borderColor = QColor(0, 255, 0);
		borderWidth = 1;
		borderWidthUnit = QgsUnitTypes::RenderUnit::RenderMillimeters;
		patternWidth = 10;
		patternWidthUnit = QgsUnitTypes::RenderUnit::RenderMillimeters;
		rotation = 0;
	}
	
	void getFillSymbol(QgsFillSymbol*& symbol);
};
//2、区分级样式
class S3DQTAPP_EXPORT RegCategoryAttr
{
public:
	RegCategoryAttr();

	void setFieldName(std::string fieldName) { m_fieldName = fieldName; }
	std::string getFieldName() { return m_fieldName; }

	void addColorRender(QVariant fieldVal, RegColorAttr& singleAttr);
	void addPatternRender(QVariant fieldVal, RegPatternAttr& patternAttr);
	//void addQgsSymbolRender(QVariant fieldVal, QgsFillSymbol* symbol);

	void clearRender();

	void getCategoryRender(std::map<QVariant, QgsRendererCategory>& cates);
	void setCategoryRender(std::map<QVariant, QgsRendererCategory>& cates);

private:
	std::string								    m_fieldName = "";
	std::map<QVariant, QgsRendererCategory>		m_categoryRenderList;
};
//3、区渐变样式
class S3DQTAPP_EXPORT RegGraduatedAttr
{
public:
	void setFieldName(std::string fieldName) { m_fieldName = fieldName; }
	std::string getFieldName() { return m_fieldName; }

	void addColorRender(double lowerValue, double upperValue, RegColorAttr& singleAttr);
	void addPatternRender(double lowerValue, double upperValue, RegPatternAttr& patternAttr);
	//void addQgsSymbolRender(double lowerValue, double upperValue, QgsFillSymbol* symbol);

	void deleteRender(double lowerValue, double upperValue);
	void clearRender();

	void getGraduatedRender(QgsRangeList& grads);
private:
	std::string	m_fieldName = "";
	QgsRangeList m_graduateRenderList;
};

class S3DQTAPP_EXPORT S3dmRegStyle:public S3dmStyle
{
	friend class S3dmVectorCateStyleDialog;
	friend class S3dmVectorClassStyleDialog;
public:
	S3dmRegStyle();

	//1、简单样式：以下两种样式选择其一
	//单一样式：颜色
	//外部new，this释放时自动释放
	void setSimpleSymbol(RegColorAttr& simpleSymbol);
	//Svg样式：图案
	void setPatternSymbol(RegPatternAttr& patternSymbol);
	//QgsSymbol
	//void setQgsSymbol(QgsFillSymbol* fillSymbol);


	//2、分级样式
	void setCategorySymbol(RegCategoryAttr& cateAttr);

	//3.渐变样式
	void setGraduatedSymbol(RegGraduatedAttr& gradAttr);

	//4.无样式
	void setNullSymbol();

	virtual void getSingleSymbolRender(QgsSingleSymbolRenderer* render);
	virtual void getCategoriedSymbolRender(QgsCategorizedSymbolRenderer* render);
	virtual void getGraduatedSymbolRender(QgsGraduatedSymbolRenderer* render);

private:
	RegColorAttr		m_regColorAttr;//区颜色
	RegPatternAttr		m_regPatternAttr;//区图案

	RegCategoryAttr		m_CateAttr;//分类
	RegGraduatedAttr	m_GradAttr;//分级
};
