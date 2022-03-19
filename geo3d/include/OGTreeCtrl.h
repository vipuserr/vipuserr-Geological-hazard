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
	typedef QStandardItem* HandleItem;//���
	//���ڵ��ȫ����Ϣ
	typedef struct TreeNode {
		std::string			strFatherCode;			//���ڵ����
		HandleItem		hFather;					    //���ڵ���

		std::string			strNodeCode; 			//�ڵ����
		std::string			strNodeName;			//�ڵ�����
		HandleItem      hNode;						//�ڵ���

		int					strIconIndex;				//��¼�ڵ�ͼ������
		int					strNodeIndex;			//��¼�ڵ�λ������
		int					layNode;					//��¼�ڵ��ڸ��ڵ��µ�����
		bool				isSelected;					//��¼�ڵ��Ƿ�ѡ��
		
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
	//���󶨵�ͼ����Ϣ
	typedef struct LayerInfo
	{
		std::string					strLayerCode;//ͼ�����
		std::string					strLayerName;//ͼ������
		std::string					strLayerPath;//ͼ��·��
		QgsMapLayer*			ptrLayer;//ͼ��ָ��
		Container*					ptrContainer;//���ݲ����
		Element*					ptrElement;//Ԫ�ػ���
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
		std::string createRootNode(std::string strNodeName, int imageIndex = -1, std::string strCode = "");//���ø��ڵ�
		std::string addChildNode(std::string strFatherCode, std::string strNodeName, int imageIndex = -1, std::string strCode = "");//����ӽڵ�
		std::string insertChildNode(std::string strFatherCode, std::string strNodeName, int layer, int imageIndex = -1, std::string strCode = "");//�����ӽڵ�
		bool deleteNode(std::string strNodeCode);																	//ɾ���ڵ�
		bool upNodeMove(std::string strNodeCode);																//���ƽڵ�
		bool downNodeMove(std::string strNodeCode);														//���ƽڵ�
		TreeNode* rootTreeNode();																								//���ڵ���Ϣ
		TreeNode* currentTreeNode();																						//��ǰ�ڵ���Ϣ
		LayerInfo* currentLayerInfo();																							//��ǰͼ����Ϣ
		TreeNode* getTreeNode(std::string strNodeCode);													//��ȡָ���ڵ�ṹ��Ϣ
		LayerInfo* getLayerInfo(std::string strNodeCode);														//��ȡָ���ڵ�ͼ����Ϣ
		void createTree(std::vector<TreeNode>* treeInfo);													//�����ڵ���Ϣ����һ����
		void setHeaderLabels(std::string headerName);															//�������ı�ͷ
		void setTreeNodeIcon(std::string strNodeCode, int imageIndex);							//���ýڵ�ͼ��
		void setTreeNodeName(std::string strNodeCode, std::string strNodeName);		//���ýڵ�����
		void setTreeNodeCheck(std::string strNodeCode, bool checkState);						//���ýڵ�ѡ��
		void loadTreeStyleSheet(std::string sheetFileName);													//����������ʽ
		
		
	private slots:
		void treeItemPressed(const QModelIndex& index);//��갴ѹ�¼�
		void treeItemChanged(QStandardItem* item);//�ڵ����Ըı��¼�
		//void treeItemLeftClicked(const QModelIndex& index);//����������¼�
		//void treeItemRightClicked(const QPoint &pos);//����Ҽ�����¼�
	
	protected:
		virtual void dropEvent(QDropEvent* event) override;//�϶������¼�
		//virtual void leftButtonClicked(const QModelIndex& index);//����������¼�
		//virtual void rightButtonClicked(const QPoint &pos);//����Ҽ�����¼�
	
	private:	
		std::string createResCode(std::string resName);//������Դ����
		QPixmap getIcon(int index);//��ȡͼ��
		void deleteChildrenInfo(std::string strNodeCode);//ɾ�����к��ӽڵ����Ϣ
		void clearTreeNode(TreeNode& nodeInfo);//����ڵ�����ṹ��Ϣ
		void clearLayerInfo(LayerInfo& layerInfo);//����ڵ��ͼ����Ϣ
		QStandardItem* copyTreeNode(QStandardItem* treeNode);//���ڵ㸴��
		void updateDragInfo(std::string strDragNodeCode, std::string strDropNodeCode);//�����϶���Ϣ
		void checkAllChild(QStandardItem* item, bool check);//ȫѡ�����ӽڵ�
		void checkChildChanged(QStandardItem * item);//�ӽڵ�ѡ��ʱ���ڵ�仯����
		Qt::CheckState checkSibling(QStandardItem * item);//�ж��ֵܽڵ�ѡ�����

	public:
		std::map<std::string, TreeNode> mTreeInfo;//���ṹ��Ϣ
		std::map<std::string, LayerInfo> mLayerInfo;//��ͼ����Ϣ
		QStandardItemModel* mTreeModel;//��ģ��
		QModelIndex mItemIndex;//��¼��ǰѡ�нڵ�
		QModelIndex mCheckIndex;//��¼��ǰ��ѡ�ڵ�
		bool mIsCheckable;//������Ӹ�ѡ��

		int mItemState;//�ڵ�״̬
	};
}

