#pragma once
#include "s3d_geommaplib_global.h"
#include "G2DToolDef.h"
#include "gmeStru.h"

class IsoMapProto {
public:
	enum IsoType {
		TOP_ELEVATION = 0,    //�㶥��ߵ�ֵ��
		BOTTOM_ELEVATION = 1, //��ױ�ߵ�ֵ��
		THICK = 2,            //�Ⱥ���
		DEPTH_BOTTOM = 3,     //��������ֵ��
		SAND_CONTENT = 4      //��ɰ�ʵ�ֵ��
	};

	enum GridBoundary {
		REG_BOUNDARY = 0,     //���ݻ����������߽�
		POINT_BOUNDARY = 1    //���ݺ�ѡ��ز�����ݵ���ֵ�������߽�
	};

	enum GridMethod {
		IDW = 0               //������Ȩ��
	};

	int       m_iDbHoleId;                    //������ݿ�ID
	int       m_iCurrentLevel;                //�ز㼶��
	int		  m_iStdStratVer;                  //��׼�ز�汾
	int       m_iSampleRow;                   //��ϡ����
	int       m_iSampleCol;                   //��ϡ����
	int       m_iSampleNum;                   //��ϡ������������
	int       m_iDbMapId;                     //���ڱ������ɵķ���ͼ��Ŀ���ά��ͼ���ݿ��ID
	bool      m_bUseSample;                   //�Ƿ�ʹ�ó�ϡ
	bool      m_bUseHull;                     //�Ƿ�ʹ��͹��
	bool      m_bUseWhite;                    //�Ƿ�ʹ��դ��׻�
	bool      m_bUseZLimit;                   //������ֵ���Ƿ�Լ���õ���ֵ
	double    m_dZMin;                        //������ֵ������Լ������ֵ����Сֵ
	double    m_dZMax;                        //������ֵ������Լ������ֵ�����ֵ
	double    m_dIsoSpace;                    //���ɵ�ֵ�߼��
	IsoType  m_eIsoType;                     //��ֵ������
	GridMethod          m_eGridMethod;       //���ɸ����Ĳ�ֵ�����������ɼ������룩
	GridBoundary        m_eGridBoundary;     //���ɸ����ı߽�
	std::string          m_sIsoMapName;       //���ɵ�ֵ��ͼ��
	vector<string>	     m_vSelectLayerCodes; //ѡ�еز�ı���
	Smart3dMap::RegDots	 m_vHoleRgnDots;      //�߽緶Χ
	
	IsoMapProto() {
		m_iDbHoleId = 0;
		m_iCurrentLevel = 0;
		m_iSampleRow = 20;
		m_iSampleCol = 20;
		m_iSampleNum = 1;
		m_iDbMapId = 0;
		m_bUseSample = false;
		m_bUseHull = false;
		m_bUseWhite = false;
		m_bUseZLimit = false;
		m_dZMin = 0;
		m_dZMax = 0;
		m_dIsoSpace = 1.00;
		m_sIsoMapName = "��ֵ��ͼ";
		m_eIsoType = IsoType::BOTTOM_ELEVATION;
		m_eGridBoundary = GridBoundary::REG_BOUNDARY;
		m_eGridMethod = GridMethod::IDW;
	}
};