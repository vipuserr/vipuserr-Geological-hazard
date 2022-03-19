#pragma once

#include "s3d_qgsmaptool_global.h"
#include <qgsattributes.h>
#include <qgsgeometry.h>
#include <qgsmaptooladvanceddigitizing.h>
#include <qgssnapindicator.h>
#include <qgsvertexmarker.h>
#include <qgsvertexeditor.h>
#include <s3d_KerGeoTopo.h>

#include "qgsgeometryvalidator.h"
#include "qgslockedfeature.h"
#include "QgsMapToolSelectHandlerExt.h"

using namespace Smart3dMap;

#define AVD_EDIT  1 // 高级编辑

using namespace std;
using gme_line2d = vector<gme_vector2d>;

struct SectVertex
{
	SectVertex() : fid(0), vertexId(0) {};
	SectVertex(QgsVectorLayer* layer, QgsFeatureId fid, int vertexId)
		: layer(layer)
		, fid(fid)
		, vertexId(vertexId)
	{}

	bool operator==(const SectVertex &other) const
	{
		return layer == other.layer && fid == other.fid && vertexId == other.vertexId;
	}
	bool operator!=(const SectVertex &other) const
	{
		return !operator==(other);
	}
	QgsVectorLayer* layer = nullptr;
	QgsFeatureId fid;
	int vertexId;
};

uint qHash(const SectVertex& v);

class S3D_QGSMAPTOOL_EXPORT SectVertexTool : public QgsMapToolAdvancedDigitizing
{
	Q_OBJECT

public:
	enum VertexToolMode
	{
		ActiveLayer,
		AllLayers
	};
	Q_ENUM(VertexToolMode)
		VertexToolMode mMode = ActiveLayer;

	enum HighlightMode
	{
		ModeReset, //!< Reset any current selection
		ModeAdd, //!< Add to current selection
		ModeSubtract, //!< Remove from current selection
	};
	using VertexEdits = QHash<QgsVectorLayer*, QHash<QgsFeatureId, QgsGeometry>>;
	/**
	 * Temporarily override snapping config and snap to vertices and edges
	   of any editable vector layer, to allow selection of vertex for editing
	   (if snapped to edge, it would offer creation of a new vertex there).
	*/
	QgsPointLocator::Match snapToEditableLayer(QgsMapMouseEvent* e);
	/**
	 * Tries to find a match in polygon interiors. This is useful for mouse move
	 * events to keep features highlighted to see their area.
	*/
	QgsPointLocator::Match snapToPolygonInterior(QgsMapMouseEvent* e);
	/**
	 * Returns a list of all matches at the given map point. That is a concatenation
	 * of all vertex, edge and area matches (vertex/edge matches using standard search tolerance).
	 * Layer is only searched if it is editable.
	*/
	QList<QgsPointLocator::Match> findEditableLayerMatches(const QgsPointXY &mapPoint, QgsVectorLayer *layer);

	SectVertexTool(QgsMapCanvas* canvas, QgsAdvancedDigitizingDockWidget* cadDock, VertexToolMode mode = VertexToolMode::ActiveLayer);
	~SectVertexTool() override;

	// 鼠标左键按下
	void cadCanvasPressEvent(QgsMapMouseEvent* e) override;
	// 鼠标左键双击
	void canvasDoubleClickEvent(QgsMapMouseEvent* e) override;
	// 鼠标释放
	void cadCanvasReleaseEvent(QgsMapMouseEvent* e) override;
	// 鼠标移动
	void cadCanvasMoveEvent(QgsMapMouseEvent* e) override;
	// 键盘按下
	void keyPressEvent(QKeyEvent* e) override;
	// 激活
	void activate() override;
	void deactivate() override;
	// 删除顶点
	void deleteVertex();
	// 缓存选中的几何
	QgsGeometry cachedGeometry(const QgsVectorLayer* layer, QgsFeatureId fid);

	//! data structure for validation of one geometry of a vector layer
	struct GeometryValidation
	{
		SectVertexTool* tool = nullptr;            //!< Pointer to the parent vertex tool (for connections / canvas)
		QgsVectorLayer* layer = nullptr;            //!< Pointer to the layer of the validated geometry (for reporojection)
		QgsGeometryValidator* validator = nullptr;  //!< Object that does validation. Non-null if active
		QList<QgsVertexMarker*> errorMarkers;      //!< Markers created by validation
		QString errors;                             //!< Full error text from validation

		void start(QgsGeometry &geom, SectVertexTool* tool, QgsVectorLayer* l);  //!< Start validation
		void addError(QgsGeometry::Error e);  //!< Add another error to the validation
		void cleanup(); //!< Delete everything
	};
	//! data structure to keep validation details
	QHash<QPair<QgsVectorLayer*, QgsFeatureId>, GeometryValidation> mValidations;

	// 尖灭点
	void GetPinchPoint(QVector<QgsPointXY>& pinchPoints);
	// 取出钻孔轨迹线的横坐标
	QSet<double> mHoleLineX;
	void GetXOfHoleLine();
	// 弧段相交检测
	bool ArcIntersectionDetect();
	bool CheckIntersection();

	// 拓扑类对象，以支持自定义编辑
	void               ReleaseTopolObj();
	void               CreateTopolObj();
	void			   UpdateTopolObj();
	void               TopolObjUpdateRegionLayer();
	void               TopolObjUpdateRegionLayer1();
	void			   UpdateRegion();
	void               TopolObjToTempLineLayerGreen();
	void               TopolObjToTempLineLayerRed();
	void			   GetModifiedRegionNos();
	void			   GetNewRegByRegNo(const string& strNo, s3d_2DRgn& regData, QgsPolygonXY& qgsPolygon);
	void			   GetNewRegByRegNo1(const string& strNo, s3d_2DRgn& regData, QgsPolygonXY& qgsPolygon);
	void               SmoothArc();
	void               SmoothWholeArcOverpot();
	void               SmoothPartArc();
	void			   DeleteVertexOnArc(QSet<QgsPoint> pts);
	s3d_2DRgnTopo*     mTopolObj;
	gme_vector2d       mPointBefore;
	gme_vector2d       mPointAfter; // 移动之前和移动之后的点
	QMap<string, QgsFeatureId>	  mModRegNoToFeaId;   // 当前修改的地层编号与要素ID的映射关系
	QMap<string, s3d_2DRgn>		  mRegNoToRegData; // 地层编号与几何数据数据的映射关系
	QMap<string, QgsAttributes>   mRegNoToAttr;
	QSet<SectVertex>			  mMovingVertices;
	vector<int>					  mCurArcIds;  // 当前选中的点所在的弧段id集合

private:
	void removeTemporaryRubberBands();
	void setHighlightedVertices(const QList<SectVertex>& listVertices, HighlightMode mode = ModeReset);
	void deleteVertexEditorSelection();
	QList<QgsPointLocator::Match> layerVerticesSnappedToPoint(QgsVectorLayer* layer, const QgsPointXY& mapPoint);
	void rangeMethodMoveEvent(QgsMapMouseEvent* e);
	void updateFeatureBand(const QgsPointLocator::Match& m);
	void initSelectionRubberBand();
	void updateSelectionRubberBand(QgsMapMouseEvent* e);
	void updateVertexBand(const QgsPointLocator::Match& m);
	QList<SectVertex> verticesInRange(QgsVectorLayer* layer, QgsFeatureId fid, int vertexId0, int vertexId1, bool longWay);
	void mouseMoveNotDragging(QgsMapMouseEvent* e);
	// 检测鼠标是否靠近线条的端点
	bool isNearEndpointMarker(const QgsPointXY& mapPoint);
	bool isMatchAtEndpoint(const QgsPointLocator::Match& match);
	QgsPointXY positionForEndpointMarker(const QgsPointLocator::Match& match);
	bool matchEdgeCenterTest(const QgsPointLocator::Match& m, const QgsPointXY& mapPoint, QgsPointXY* edgeCenterPtr = nullptr);
	void startDraggingAddVertex(const QgsPointLocator::Match& m);
	void startDraggingMoveVertex(const QgsPointLocator::Match& m);
	QSet<SectVertex> findCoincidentVertices(const QSet<SectVertex>& vertices);
	void buildDragBandsForVertices(const QSet<SectVertex>& movingVertices, const QgsPointXY& dragVertexMapPoint);
	void onCachedGeometryChanged(QgsFeatureId fid, const QgsGeometry& geom);
	void onCachedGeometryDeleted(QgsFeatureId fid);
	void clearGeometryCache();
	void validateGeometry(QgsVectorLayer* layer, QgsFeatureId featureId);
	void buildExtraVertices(const QSet<SectVertex>& vertices, const QgsPointXY& anchorPoint, QgsVectorLayer* anchorLayer);
	void showAttribute();
	void updateLockedFeatureVertices();
	void mouseMoveDraggingVertex(QgsMapMouseEvent* e);
	void moveDragBands(const QgsPointXY& mapPoint);
	QList<QgsVectorLayer*> editableVectorLayers();
	void stopSelectionRubberBand();
	void moveVertex(const QgsPointXY& mapPoint, const QgsPointLocator::Match* mapPointMatch);
	void stopDragging();
	QgsPoint matchToLayerPoint(const QgsVectorLayer* destLayer, const QgsPointXY& mapPoint, const QgsPointLocator::Match* match);
	void addExtraVerticesToEdits(VertexEdits& edits, const QgsPointXY& mapPoint, QgsVectorLayer* dragLayer, const QgsPoint& layerPoint);
	void setHighlightedVerticesVisible(bool visible);
	void clearDragBands();
	// 保存编辑
	void applyEditsToLayers(VertexEdits& edits);
	void startDraggingAddVertexAtEndpoint(const QgsPointXY& mapPoint);
	void addDragBand(const QgsPointXY& v1, const QgsPointXY& v2);
	void addDragStraightBand(QgsVectorLayer* layer, QgsPointXY v0, QgsPointXY v1, bool moving0, bool moving1, const QgsPointXY& mapPoint);
	void startDragging(QgsMapMouseEvent* e);
	QgsGeometry cachedGeometryForVertex(const SectVertex &vertex);
	int adjacentVertexIndexToEndpoint(const QgsGeometry& geom, int vertexIndex);

	// 拖动顶点的方式
	enum DraggingVertexType
	{
		NotDragging,
		MovingVertex,
		AddingVertex,
		AddingEndpoint,
	};
	DraggingVertexType mDraggingVertexType = NotDragging;

	/**
	*  list of SectVertex instances of further vertices that are dragged together with
	*  the main vertex (mDraggingVertex) - either topologically connected points
	*  (if topo editing is allowed) or the ones coming from the highlight
	*/
	QList<SectVertex> mDraggingExtraVertices;

	/**
	*  companion array to mDraggingExtraVertices: for each vertex in mDraggingExtraVertices
	*  this is offset (in units of the layer) of the vertex from the position of the main
	*  vertex (mDraggingVertex)
	*/
	QList<QgsVector> mDraggingExtraVerticesOffset;

	//! SectVertex instance or None
	unique_ptr<SectVertex> mMouseAtEndpoint;

	/**
	*  keeps information about previously used snap match
	*  to stick with the same highlighted feature next time if there are more options
	*/
	unique_ptr<QgsPointLocator::Match> mLastSnap;

	//! Locked feature for the vertex editor
	unique_ptr<QgsLockedFeature> mLockedFeature;
	//! highlight of locked feature vertices (but not selected)
	QList<QgsVertexMarker*> mLockedFeatureVerticesMarkers;

	//! the rubberband for rectangle selection visualization
	unique_ptr<QgsRubberBand> mSelectionRubberBand;
	//! Initial point (in screen coordinates) when using rectangle selection
	unique_ptr<QPoint> mSelectionRubberBandStartPos;
	//! Starting vertex when using range selection (null if not yet selected)
	unique_ptr<SectVertex> mRangeSelectionFirstVertex;

	// 当前正在被移动的顶点
	unique_ptr<SectVertex> mDraggingVertex;
	// 缓存选中的几何
	QHash<const QgsVectorLayer*, QHash<QgsFeatureId, QgsGeometry>> mCache;
	// 被选中的顶点
	QList<SectVertex> mSelectedVertices;
	// 当拖动顶点时，高亮显示捕捉到的其他顶点
	unique_ptr<QgsSnapIndicator> mSnapIndicator;
	// 被选中顶点的高亮符号
	QList<QgsVertexMarker*> mSelectedVerticesMarkers;
	// 当鼠标移动到线条的端点时，会显示一个+号，提醒用户是否需要追加一个顶点
	QgsVertexMarker* mEndpointMarker = nullptr;
	unique_ptr<QgsPointXY> mEndpointMarkerCenter;
	// 当鼠标靠近一条线段时，线段中间会显示一个加号，提醒用户是否需要添加一个中点
	QgsVertexMarker* mEdgeCenterMarker = nullptr;
	// 高亮显示鼠标悬停的整个要素
	QgsRubberBand* mFeatureBand = nullptr;
	// 高亮显示鼠标悬停的要素的顶点
	QgsRubberBand* mFeatureBandMarkers = nullptr;
	// 用来高亮显示的源图层
	const QgsVectorLayer* mFeatureBandLayer = nullptr;
	// 用来高亮显示要素所对应的要素ID
	QgsFeatureId mFeatureBandFid = 0;
	// 当鼠标靠近顶点时，高亮显示该顶点
	QgsRubberBand* mVertexBand = nullptr;
	// 当鼠标靠近边时，高亮显示该边
	QgsRubberBand* mEdgeBand = nullptr;
	// 顶点选择方式
	enum VertexSelectionMethod
	{
		SelectionNormal,   // 默认。点击顶点：开始移动；按住shift点击顶点：选择顶点；拉框：选中框内的所有顶点
		SelectionRange,    // 范围选择。第一次点击顶点，选择起始点，下一次点击顶点，选择终止顶点
	};

	VertexSelectionMethod mSelectionMethod = SelectionNormal;

	/**
	*  markers for points used only for moving standalone point geoetry
	*  (there are no adjacent vertices so it is not used in mDragBands)
	*/
	QList<QgsVertexMarker*> mDragPointMarkers;
	/**
	*  companion array to mDragPointMarkers: for each marker it keeps offset
	*  (in map units) from the position of the main vertex
	*/
	QList<QgsVector> mDragPointMarkersOffset;

	// 直线段
	struct StraightBand
	{
		QgsRubberBand* band = nullptr;       //!< Pointer to the actual rubber band
		QgsPointXY p0, p1;                     //!< What are the original positions of points (in map units)
		bool moving0, moving1;               //!< Which points of the band are moving with mouse cursor
		QgsVector offset0, offset1;          //!< If the point is moving, what is the offset from the mouse cursor
	};
	QList<StraightBand> mDragStraightBands;

	// 环形线段
	struct CircularBand
	{
		QgsRubberBand* band = nullptr;        //!< Pointer to the actual rubber band
		QgsPointXY p0, p1, p2;                  //!< What are the original positions of points (in map units)
		bool moving0, moving1, moving2;       //!< Which points of the band are moving with mouse cursor
		QgsVector offset0, offset1, offset2;  //!< If the point is moving, what is the offset from the mouse cursor

		//! update geometry of the rubber band band on the current mouse cursor position (in map units)
		void updateRubberBand(const QgsPointXY &mapPoint);
	};
	QList<CircularBand> mDragCircularBands;
	unique_ptr<QgsMapToolSelectHandlerExt> mSelectionHandler;

private slots:
	void selectFeatures(Qt::KeyboardModifiers modifiers);
	void deleteSelected(QgsMapLayer* layer, bool checkFeaturesVisible);
	QgsPointXY snapPoint(QgsMapMouseEvent* e);
	void setSelectionMode(QgsMapToolSelectHandlerExt::SelectionMode selectionMode);
};
