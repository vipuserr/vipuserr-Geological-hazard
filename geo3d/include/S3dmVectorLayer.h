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
		//����һ��ͼ��ָ�룬��ָ����Ҫ�������ͷ�
		//�����Ѵ��ڵ�shp�ļ�,����type��S3dmVectorLayerָ�룬��ָ��ָ���Ӧ����
		static S3dmVectorLayer*  newLayerObject(S3dmLayerType& type, std::string file);
		//����һ��ͼ��ָ�룬��ָ����Ҫ�������ͷ�
		//����QgsVectorLayer,����type��S3dmVectorLayerָ�룬��ָ��ָ���Ӧ����
		static S3dmVectorLayer* newLayerObject(S3dmLayerType& type, QgsVectorLayer* layer);

		//�����յ�Shp�ļ�
		static QgsVectorLayer* creatEmptyLayer(const std::string & fullPathFile, const S3dmLayerType & type, std::vector<QgsField>& fields);

		//�����ֶ�
		void setFields(gmeFields& fields) { m_Fields = fields; }
		gmeFields& getFields() { return m_Fields; }
		//���ü�¼�������ͼ��εĸ���һ��
		void setRecords(gmeRecordSet& records) { m_Records = records; }
		gmeRecordSet& getRecords() { return m_Records; }
		//����ֶ�
		void addFields(gmeFields& fields);
		//��Ӽ�¼
		void addRecords(gmeRecordSet& records);
		//ɾ���ֶ�
		void deleteField(GString fieldName);
		void deleteField(int fieldIndex);
		//ɾ����¼,������¼�����ԣ���գ���δ�����Ӧ��Ҫ��
		void deleteRecord(int index);


		//����ע����ʽ
		void setLabels(S3dmLabels& label) { m_Lables = label; }
		S3dmLabels& getLabels() { return m_Lables; }


		//����QgsVectorLayer
		virtual QgsVectorLayer* layer();

		virtual void updateLayer();
		virtual void updateStyle(); //��������ʽ
		void updateLabel();//������ע��
		virtual void updateFeature();//�����¼��κ�����

		//�������ͣ��㡢�ߡ��棩
		S3dmLayerType type();

		bool save(std::string output);
		void setIsNeedRelease(bool isNeedRelease) { m_IsNewLayer = isNeedRelease; };

		virtual ~S3dmVectorLayer();
	protected:
		//�ڴ漶��ʸ���ļ�
		S3dmVectorLayer(S3dmLayerType type);
		//�����Ѵ��ڵ�shp�ļ�
		S3dmVectorLayer(std::string file);
		S3dmVectorLayer(QgsVectorLayer* layer, bool isNeedRelease = false);

	protected:
		void readShpInfo();

		QgsVectorLayer*		m_Layer;
		bool				m_IsNewLayer; //��ʶQGSVectorLayer�Ƿ����ڲ�new�ģ�����ǣ�����Ҫ�ͷ�

		//�ֶε�˳��ͼ�¼��˳����뱣��һ��
		gmeFields			m_Fields;//�ֶ�
		gmeRecordSet		m_Records;//��¼
		//ע��
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

		//ͼ����£�����д��ͼ�����Ҫ���ø���ͼ�㺯��
		virtual void updateLayer(); //����������Ϣ
		virtual void updateStyle(); //��������ʽ
		virtual void updateFeature();//�����¼��κ�����

		//�����ü��Σ�����������
		void setPnts(std::vector<gme_vector2d>& pnts);
		std::vector<gme_vector2d>& getPnts() { return m_Pnts; }

		//����Ҫ����ʽ
		void setStyle(S3dmPointStyle& style) { m_Styles = style; }
		S3dmPointStyle& getStyle() { return m_Styles; }

	private:
		void readShpInfo();

		std::vector<gme_vector2d>	m_Pnts;//����
		S3dmPointStyle			m_Styles;
	};


	class S3DQTAPP_EXPORT S3dmLineLayer :public S3dmVectorLayer
	{
	public:
		S3dmLineLayer();
		S3dmLineLayer(std::string file);
		S3dmLineLayer(QgsVectorLayer* layer, bool isNeedRelease = false);
		~S3dmLineLayer();

		//ͼ����£�����д��ͼ�����Ҫ���ø���ͼ�㺯��
		virtual void updateLayer();
		virtual void updateStyle(); //��������ʽ
		virtual void updateFeature();//�����¼��κ�����

		//�����ü��Σ�����������
		void setLines(std::vector<std::vector<gme_vector2d>>& lines) { m_Lines = lines; };
		std::vector<std::vector<gme_vector2d>>& getLines() { return m_Lines; }
		//�����
		void addLines(std::vector<std::vector<gme_vector2d>>& lines);
		//ɾ����
		void deleteLine(int idx);
		//�޸���
		void updateLine(int idx, std::vector<gme_vector2d>& line);

		//����Ҫ����ʽ
		void setStyle(S3dmLineStyle& style) { m_Styles = style; }
		S3dmLineStyle& getStyle() { return m_Styles; }
	private:
		void readShpInfo();

		std::vector<std::vector<gme_vector2d>> m_Lines;
		S3dmLineStyle				 m_Styles;
	};

	typedef std::vector<gme_vector2d> Reg;//�����
	typedef std::vector<Reg> S3dmReg; //���пն��ķ����������һ�����к���һ��������Ϊ����Reg��

	class S3DQTAPP_EXPORT S3dmRegLayer :public S3dmVectorLayer
	{
	public:
		S3dmRegLayer();
		S3dmRegLayer(std::string file);
		S3dmRegLayer(QgsVectorLayer* layer, bool isNeedRelease = false);
		~S3dmRegLayer();

		//ͼ����£�����д��ͼ�����Ҫ���ø���ͼ�㺯��
		virtual void updateLayer();
		virtual void updateStyle(); //��������ʽ
		virtual void updateFeature();//�����¼��κ�����

		//�����ü��Σ�����������
		void setRegs(std::vector<S3dmReg>& regs) { m_Regs = regs; }
		std::vector<S3dmReg>& getRegs() { return m_Regs; }
		//�����
		void addRegs(std::vector<S3dmReg>& regs);
		//ɾ����
		void deleteReg(int idx);
		//�޸���
		void updateReg(int idx, S3dmReg& reg);



		//����Ҫ����ʽ
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
