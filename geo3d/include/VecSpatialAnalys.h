#ifndef VECSPATIALANALYS_H
#define VECSPATIALANALYS_H

#include "Geo3dSpatialAnalysDef.h"
#include"gmeStru.h"
#include"gme_Pointer.h"
#include"gmeEntity.h"
#include"s3d_GeomDefine.h"
#include<vector>
using namespace std;
using namespace Smart3dMap;
class QGisS3dGeoTrans;
class VECSPATIALANALYS_EXPORT VecSpatialAnalys
{
public:
	enum EndCapStyle//�����˵���ʽ
	{
		CapRound = 1, //Բ��
		CapFlat, //��ƽ
		CapSquare, //����
	};
	enum JoinStyle//������ʽ
	{
		JoinStyleRound = 1, //Բ��
		JoinStyleMiter, //���
		JoinStyleBevel, //б��
	};
	VecSpatialAnalys();
	virtual ~VecSpatialAnalys();

	//�ü� ����������Ҫ�ؽ��пռ伸������
	void Intersection(const vector<s3d_Point*> &inputVec, const gme_rect_2d &dRect, vector<s3d_Point*>& outVec);
	// ����:     �ü����ε�ͼ�Σ������ڵı�����������
	//InputVec         In      ����ü��ļ���ͼ���б�
	//dRect             In      �ü����η�Χ

	void Intersection(const vector<s3d_Point*> &inputVec, const vector<gme_vector2d> &dPolygon, vector<s3d_Point*>& outVec);
	// ����:     ����βü����ε�ͼ�Σ��ڲã�
	//InputVec         In      ����ü��ļ���ͼ���б�
	//dPolygon          In      �ü���Χ����β��գ�

	void Intersection(const vector<s3d_Polyline*> &inputVec, const gme_rect_2d &dRect, vector<s3d_Polyline*> &outVec);
	// ����:     �ü�������ͼ�Σ������ڵı�����������
	//InputVec         In      ����ü��ļ���ͼ���б�
	//dRect             In      �ü����η�Χ

	void Intersection(const vector<s3d_Polyline*> &InputVec, const vector<gme_vector2d> &dPolygon, vector<s3d_Polyline*>&outVec);
	// ����:     ����βü�������ͼ�Σ��ڲã�
	//InputVec         In      ����ü��ļ���ͼ���б�
	//dPolygon          In      �ü���Χ����β��գ�

	void Intersection(const vector<s3d_Polygon*> &InputVec, const gme_rect_2d &dRect, vector<s3d_Polygon*>&outVec);
	// ����:     �ü�������ͼ�Σ��ڲã�
	//InputVec         In      ����ü��ļ���ͼ���б�
	//dRect             In      �ü���Χ

	void Intersection(const vector<s3d_Polygon*> &inputVec, const vector<gme_vector2d> &dPolygon, vector<s3d_Polygon*>&outVec);
	// ����:     �ü�������ͼ�Σ��ڲã�
	//InputVec         In      ����ü��ļ���ͼ���б�
	//dPolygon          In      �ü���Χ����β��գ�

	void Intersection(const vector<s3d_Polygon*> &inputVec, const vector<s3d_Polygon*> &inputVec1, vector<s3d_Polygon*>&outVec);
	// ����:     �ü�������ͼ�Σ��ڲã�
	//InputVec         In      ����ü��ļ���ͼ���б�
	//inputVec1          In      �ü���Χ

	//͹��:����������͹��
	/*���㷨��������ͼ���е�ÿ��Ҫ�ص�͹����
		��鿴����С�߽缸��ͼ�Ρ��㷨���˽⺭������ͼ���Ҫ�ط����Ӽ���͹�����㷽����*/
	void  convexHull(const vector < s3d_Point*> &inputVec, s3d_Polygon*& outPolygon);
	void  convexHull(const vector<s3d_Polyline*> &inputVec, s3d_Polygon*& outPolygon);
	void  convexHull(const vector<s3d_Polygon*> &inputVec, s3d_Polygon*& outPolygon);
	void  convexHull(s3d_GeomBase* inputVec, s3d_Polygon*& outGeoBase);

	//��ֵ�����㷨������ͼ����ȡ����ͼ��Ҫ��֮��򲿷��ص���Ҫ�ء� �ڵ���ͼ���в����ص�Ҫ�ص�����ͼ��Ҫ�ؽ�������ЩҪ�صı߽���зָ���ҽ���������ͼ��Ҫ��֮��Ĳ��֡�
	//���㷨������ͼ����ȡ����ͼ��Ҫ��֮��򲿷��ص���Ҫ�ء� �ڵ���ͼ���в����ص�Ҫ�ص�����ͼ��Ҫ�ؽ�������ЩҪ�صı߽���зָ���ҽ���������ͼ��Ҫ��֮��Ĳ��֡�
	//���ܲ���������޸�Ҫ�ص�����򳤶ȵ����ԣ��������޸�����ֵ������������Դ���Ϊ���ԣ�������ֶ�������Щ���ԡ�
	//������Ĳ�ֵ���㣺����� ����� ��͵� �ߺ��� �ߺ��� �����
	void difference(const vector<s3d_Point*> &inputVec1, const vector<s3d_Polygon*> &inputVec2, vector<s3d_Point*> &outVec);
	void difference(const vector<s3d_Point*> &inputVec1, const vector<s3d_Polyline*> &inputVec2, vector<s3d_Point*>&outVec);
	void difference(const vector<s3d_Point*> &inputVec1, const vector<s3d_Point*> &inputVec2, vector<s3d_Point*> &outVec);
	void difference(const vector<s3d_Polyline*> &inputVec1, const vector<s3d_Polygon*> &inputVec2, vector<s3d_Polyline*> &outVec);
	void difference(const vector<s3d_Polyline*> &inputVec1, const vector<s3d_Polyline*> &inputVec2, vector<s3d_Polyline*>&outVec);
	void difference(const vector<s3d_Polygon*> &inputVec1, const vector<s3d_Polygon*> &inputVec2, vector<s3d_Polygon*> &outVec);

	void  GetCenter(const s3d_GeomBase * pGeo, gme_vector2d &outV2d);
	void  GetCenter(const vector<s3d_GeomBase*> &inputVec, gme_vector2d &outV2d);
	// ����:     �����ε�����
	double  GetArea(const s3d_Polygon * pPolygon);
	// ����:     �����������

	double  GetDistance(const s3d_GeomBase * pLGeo, const s3d_GeomBase * pRGeo);
	// ����:     ��������Ҫ�ؼ�ľ��볤��

	void Buffer(const s3d_GeomBase * pGeo,  s3d_Polygon *&outPolygon,double distance=10, int segments = 5
		, EndCapStyle endCapStyle = EndCapStyle::CapRound, JoinStyle joinStyle = JoinStyle::JoinStyleRound, double miterLimit = 2);
	// ����:     ����㡢�ߡ��滺����
	//����˵����segments �߶� miterLimit ������� distance�������

	void simplify(const vector<s3d_Polygon*> &inputVec,vector<s3d_Polygon*> &outVec, double tolerance=1);
	void simplify(const vector<s3d_Polyline*> &inputVec,vector<s3d_Polyline*> &outVec, double tolerance=1);

	void SplitPolygon(const vector<s3d_Polygon*> &inputVec, const vector<s3d_Polyline*> &dLinVec, vector<s3d_Polygon*>&outVec);
	// ����:     �ö����߷ָ�����
	//InputVec         In      ����ָ�ļ���ͼ���б�
	//dLinVec          In      �ָ����б�

	void SplitPolygon(const vector<s3d_Polygon*> &inputVec, const s3d_Polyline* pLin, vector<s3d_Polygon*> &outVec);
	// ����:     ��һ�����߷ָ���
	//InputVec         In      ����ָ�ļ���ͼ�ε��б�
	//dLinVec          In      �ָ����б�

	void SplitLin(const s3d_Polyline* pLin1, const s3d_Polyline* pLin2, vector<s3d_Polyline*> &outVec);
	// ����:     ��pLin2�ָ�pLin1
	//InputVec         In      ����ָ�ļ���ͼ���б�
	//dLinVec          In      �ָ����б�


	void Smooth(const vector<gme_vector2d> &inputVec,  vector<gme_vector2d> &outVec,int iterations = 5, double offset = 0.25);
	// ����:     ƽ������


	void   Smooth(const s3d_GeomBase * pGeo, s3d_GeomBase *outGeoBase, int iterations = 5, double offset = 0.25);
	// ����:     ƽ������



	void  Combine(const s3d_Polygon* pFirst, const s3d_Polygon* pSecond, vector<s3d_Polygon*>& outPolygon);
	// ����:     �ϲ������

	void  Combine(const vector<s3d_Polygon*> pFirst, const vector<s3d_Polygon*> pSecond, vector<s3d_Polygon*>& outPolygon);
	// ����:     �ϲ������

	
	void release(s3d_GeomBase * pGeo);
	void release(vector<s3d_GeomBase*> &geoVec);
private:
	QGisS3dGeoTrans *m_trans;
};
#endif // VECSPATIALANALYS_H

