#pragma once
#include "s3dqtapp_global.h"
#include "qgssinglesymbolrenderer.h"
#include "qgscategorizedsymbolrenderer.h"
#include "qgsgraduatedsymbolrenderer.h"
#include "qgsnullsymbolrenderer.h"
enum S3dmStyleType
{
	SingleSymbol = 1,//��ɫ��ʽ
	CategoriedSymbol = 2,//�ּ���ʽ
	GraduatedSymbol = 3, //������ʽ
	NullSymbol = 4 //����ʽ
};

class S3DQTAPP_EXPORT S3dmStyle
{
public:
	enum SingleRenderType
	{
		COLOR = 0,//��ɫ��Ⱦ
		PATTERN = 1//ͼ����Ⱦ
	};
public:
	S3dmStyle(QgsWkbTypes::GeometryType geomType);

	void setType(S3dmStyleType style) { m_Type = style; }
	S3dmStyleType type() { return m_Type; }

	virtual void getSingleSymbolRender(QgsSingleSymbolRenderer* render)=0;
	virtual void getCategoriedSymbolRender(QgsCategorizedSymbolRenderer* render)=0;
	virtual void getGraduatedSymbolRender(QgsGraduatedSymbolRenderer* render)=0;

protected:
	S3dmStyleType						m_Type; //��ʽ�����ͣ�����ѡ��һ
	SingleRenderType					m_RenderType;//��һ��Ⱦ����
};

//1�������ʽ---��ɫ��Բ��
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
	double						opacity;//͸����
	Shape						fillStyle;//���ͼ��
	QColor						fillColor;//�����ɫ
	double						fillSize; //�ߴ�
	QgsUnitTypes::RenderUnit	fillSizeUnit;//�ߴ絥λ
	QColor						borderColor;//�߿���ɫ
	Qt::PenStyle				borderStyle;//�߿���ʽ
	double						borderWidth;//�߿���
	QgsUnitTypes::RenderUnit borderWidthUnit;//�߿��ȵ�λ
	double						rotation;//��ת����

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
//1�������ʽ---ͼ��
class S3DQTAPP_EXPORT PntPatternAttr
{
public:
	std::string					patternName;//ͼ��·��
	double						width;//ͼ�����
	double						height;//ͼ���߶�
	QgsUnitTypes::RenderUnit	sizeUnit;//��ߵ�λ

	QColor						fillColor;//�����ɫ(����ɫ)

	QColor						borderColor;//�߿���ɫ
	double						borderWidth;//�߿���
	QgsUnitTypes::RenderUnit	borderWidthUnit;//�߿��ȵ�λ
	double						opacity;//͸����
	double						rotation;//ͼ����ת�Ƕ�:0-360

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
//2����ּ���ʽ
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
//3���㽥����ʽ
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
	
	//1������ʽ������������ʽѡ����һ
	//��һ��ʽ����ɫ
	void setSimpleSymbol(PntColorAttr& pntColorAttr);
	//Svg��ʽ��ͼ��
	void setPatternSymbol(PntPatternAttr& pntPatternAttr);

	//2���ּ���ʽ
	void setCategorySymbol(PntCategoryAttr& cateAttr);

	//3��������ʽ
	void setGraduatedSymbol(PntGraduatedAttr& gradAttr);

	//4.����ʽ
	void setNullSymbol();

	virtual void getSingleSymbolRender(QgsSingleSymbolRenderer* render);
	virtual void getCategoriedSymbolRender(QgsCategorizedSymbolRenderer* render);
	virtual void getGraduatedSymbolRender(QgsGraduatedSymbolRenderer* render);

private:
	PntColorAttr		m_pntColorAttr;//����ɫ
	PntPatternAttr		m_pntPatternAttr;//��ͼ��
	PntCategoryAttr		m_CateAttr;
	PntGraduatedAttr	m_GradAttr;
};


//1���߼���ʽ---��ɫ
class S3DQTAPP_EXPORT LineColorAttr
{
public:
	double						opacity;//͸����
	QColor						color;//��ɫ
	Qt::PenStyle				style;//������
	double						width;//�߿�
	QgsUnitTypes::RenderUnit	widthUnit;//�߿�λ

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
//2���߷ּ���ʽ
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
//3���߽�����ʽ
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
	
	//1������ʽ
	//��һ��ʽ����ɫ
	void setSimpleSymbol(LineColorAttr& simpleSymbol);

	//2���ּ���ʽ
	void setCategorySymbol(LineCategoryAttr& cateAttr);

	//3.������ʽ
	void setGraduatedSymbol(LineGraduatedAttr& gradAttr);

	//4.����ʽ
	void setNullSymbol();

	virtual void getSingleSymbolRender(QgsSingleSymbolRenderer* render);
	virtual void getCategoriedSymbolRender(QgsCategorizedSymbolRenderer* render);
	virtual void getGraduatedSymbolRender(QgsGraduatedSymbolRenderer* render);
private:
	LineColorAttr			m_ColorAttr;
	LineCategoryAttr		m_CateAttr;
	LineGraduatedAttr		m_GradAttr;
};



//1��������ʽ---��ɫ
class S3DQTAPP_EXPORT RegColorAttr
{
public:
	QColor				fillColor;//�����ɫ

	Qt::PenStyle		borderStyle;//�߿���ʽ
	QColor				borderColor;//�߿���ɫ
	double				borderWidth;//�߿���
	QgsUnitTypes::RenderUnit borderWidthUnit;//�߿��ȵ�λ

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
//1��������ʽ---ͼ��
class S3DQTAPP_EXPORT RegPatternAttr
{
public:
	std::string					patternName;//ͼ������
	QColor						patternColor;//ͼ������ɫ
	double						patternWidth;//ͼ�����
	QgsUnitTypes::RenderUnit	patternWidthUnit;//ͼ����ȵ�λ
	double						rotation;//ͼ����ת�Ƕ�:0-360

	double						opacity;//͸����

	QColor						borderColor;//�߿���ɫ
	double						borderWidth;//�߿���
	QgsUnitTypes::RenderUnit	borderWidthUnit;//�߿��ȵ�λ

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
//2�����ּ���ʽ
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
//3����������ʽ
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

	//1������ʽ������������ʽѡ����һ
	//��һ��ʽ����ɫ
	//�ⲿnew��this�ͷ�ʱ�Զ��ͷ�
	void setSimpleSymbol(RegColorAttr& simpleSymbol);
	//Svg��ʽ��ͼ��
	void setPatternSymbol(RegPatternAttr& patternSymbol);
	//QgsSymbol
	//void setQgsSymbol(QgsFillSymbol* fillSymbol);


	//2���ּ���ʽ
	void setCategorySymbol(RegCategoryAttr& cateAttr);

	//3.������ʽ
	void setGraduatedSymbol(RegGraduatedAttr& gradAttr);

	//4.����ʽ
	void setNullSymbol();

	virtual void getSingleSymbolRender(QgsSingleSymbolRenderer* render);
	virtual void getCategoriedSymbolRender(QgsCategorizedSymbolRenderer* render);
	virtual void getGraduatedSymbolRender(QgsGraduatedSymbolRenderer* render);

private:
	RegColorAttr		m_regColorAttr;//����ɫ
	RegPatternAttr		m_regPatternAttr;//��ͼ��

	RegCategoryAttr		m_CateAttr;//����
	RegGraduatedAttr	m_GradAttr;//�ּ�
};
