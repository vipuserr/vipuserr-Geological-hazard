#pragma once

#include "ogtreectrl_global.h"
#include "qtreeview.h"
#include "qstandarditemmodel.h"
#include "qgsmaplayer.h"
#include "qicon.h"
#include "qmessagebox.h"
#include "qfile.h"
#include "qevent.h"
#include "qpoint.h"
#include <map>
#include <string>

#include "OGContainer.h"
#include "OGElement.h"

namespace Smart3dMap
{
	typedef QStandardItem* HandleItem;//句柄
	//树节点的全部信息
	typedef struct TreeNode {
		std::string			strFatherCode;			//父节点编码
		HandleItem		hFather;					    //父节点句柄

		std::string			strNodeCode; 			//节点编码
		std::string			strNodeName;			//节点名称
		HandleItem      hNode;						//节点句柄

		int					strIconIndex;				//记录节点图标索引
		int					strNodeIndex;			//记录节点位置索引
		int					layNode;					//记录节点在父节点下的行数
		bool				isSelected;					//记录节点是否被选中
		
		TreeNode()
		{
			strFatherCode = "";
			hFather = NULL;
			strNodeCode = "";
			strNodeName = "";
			hNode = NULL;
			strIconIndex = -1;
			strNodeIndex = -1;
			layNode = 0;
			isSelected = false;
		}
	}TreeNode;
	//树绑定的图层信息
	typedef struct LayerInfo
	{
		std::string					strLayerCode;//图层编码
		std::string					strLayerName;//图层名称
		std::string					strLayerPath;//图层路径
		QgsMapLayer*			ptrLayer;//图层指针
		Container*					ptrContainer;//数据层基类
		Element*					ptrElement;//元素基类
		LayerInfo()
		{
			strLayerCode = "";
			strLayerName = "";
			strLayerPath = "";
			ptrLayer = NULL;
			ptrContainer = NULL;
			ptrElement = NULL;
		}
	}LayerInfo;

	class OGTREECTRL_EXPORT OGTreeCtrl : public QTreeView
	{
		Q_OBJECT

	public:
		explicit OGTreeCtrl(QWidget *parent = nullptr);
		~OGTreeCtrl();

	public:
		std::string createRootNode(std::string strNodeName, int imageIndex = -1, std::string strCode = "");//设置根节点
		std::string addChildNode(std::string strFatherCode, std::string strNodeName, int imageIndex = -1, std::string strCode = "");//添加子节点
		std::string insertChildNode(std::string strFatherCode, std::string strNodeName, int layer, int imageIndex = -1, std::string strCode = "");//插入子节点
		bool deleteNode(std::string strNodeCode);																	//删除节点
		bool upNodeMove(std::string strNodeCode);																//上移节点
		bool downNodeMove(std::string strNodeCode);														//下移节点
		TreeNode* rootTreeNode();																								//根节点信息
		TreeNode* currentTreeNode();																						//当前节点信息
		LayerInfo* currentLayerInfo();																							//当前图层信息
		TreeNode* getTreeNode(std::string strNodeCode);													//获取指定节点结构信息
		LayerInfo* getLayerInfo(std::string strNodeCode);														//获取指定节点图层信息
		void createTree(std::vector<TreeNode>* treeInfo);													//由树节点信息生成一棵树
		void setHeaderLabels(std::string headerName);															//设置树的表头
		void setTreeNodeIcon(std::string strNodeCode, int imageIndex);							//设置节点图标
		void setTreeNodeName(std::string strNodeCode, std::string strNodeName);		//设置节点名称
		void setTreeNodeCheck(std::string strNodeCode, bool checkState);						//设置节点选中
		void loadTreeStyleSheet(std::string sheetFileName);													//加载树的样式
		
		
	private slots:
		void treeItemPressed(const QModelIndex& index);//鼠标按压事件
		void treeItemChanged(QStandardItem* item);//节点属性改变事件
		//void treeItemLeftClicked(const QModelIndex& index);//鼠标左键点击事件
		//void treeItemRightClicked(const QPoint &pos);//鼠标右键点击事件
	
	protected:
		virtual void dropEvent(QDropEvent* event) override;//拖动放置事件
		//virtual void leftButtonClicked(const QModelIndex& index);//鼠标左键点击事件
		//virtual void rightButtonClicked(const QPoint &pos);//鼠标右键点击事件
	
	private:	
		std::string createResCode(std::string resName);//生成资源编码
		QPixmap getIcon(int index);//获取图标
		void deleteChildrenInfo(std::string strNodeCode);//删除所有孩子节点的信息
		void clearTreeNode(TreeNode& nodeInfo);//清除节点的树结构信息
		void clearLayerInfo(LayerInfo& layerInfo);//清除节点的图层信息
		QStandardItem* copyTreeNode(QStandardItem* treeNode);//树节点复制
		void updateDragInfo(std::string strDragNodeCode, std::string strDropNodeCode);//更新拖动信息
		void checkAllChild(QStandardItem* item, bool check);//全选所有子节点
		void checkChildChanged(QStandardItem * item);//子节点选中时父节点变化函数
		Qt::CheckState checkSibling(QStandardItem * item);//判断兄弟节点选中情况

	public:
		std::map<std::string, TreeNode> mTreeInfo;//树结构信息
		std::map<std::string, LayerInfo> mLayerInfo;//绑定图层信息
		QStandardItemModel* mTreeModel;//树模型
		QModelIndex mItemIndex;//记录当前选中节点
		QModelIndex mCheckIndex;//记录当前勾选节点
		bool mIsCheckable;//设置添加复选框

		int mItemState;//节点状态
	};
}

