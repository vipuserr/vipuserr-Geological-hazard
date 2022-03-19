#pragma once

#include <QDialog>
#include <QStandardItem>
#include <QAction>
#include <QMenu>
#include"ui_qgsstylemanagerdialogbase.h"
#include "qgshelp.h"
#include "qgsstylemodel.h"
#include "qgis_gui.h"
#include "s3dmqgsdialog_global.h"
#include"OgSingleton.h"
class QgsStyle;
class QgsTemporaryCursorOverride;
class QgsMessageBar;
using namespace Smart3dMap;
class S3DMQGSDIALOG_EXPORT S3dmCheckableStyleModel : public QgsStyleProxyModel
{
	Q_OBJECT
public:
	explicit S3dmCheckableStyleModel(QgsStyleModel *sourceModel, QObject *parent = nullptr, bool readOnly = false);
	explicit S3dmCheckableStyleModel(QgsStyle *style, QObject *parent = nullptr, bool readOnly = false);

	void setCheckable(bool checkable);
	void setCheckTag(const QString &tag);

	Qt::ItemFlags flags(const QModelIndex &index) const override;
	QVariant data(const QModelIndex &index, int role) const override;
	bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;

private:

	QgsStyle *mStyle = nullptr;
	bool mCheckable = false;
	QString mCheckTag;
	bool mReadOnly = false;
};
class S3DMQGSDIALOG_EXPORT S3dmStyleManagerDialog : public QDialog, private Ui::QgsStyleManagerDialogBase
{
	Q_OBJECT
public:
	static S3dmStyleManagerDialog* getSingletonPtr();
protected:
	~S3dmStyleManagerDialog();
	S3dmStyleManagerDialog(QgsStyle *style, QWidget *parent SIP_TRANSFERTHIS = nullptr, Qt::WindowFlags flags = Qt::WindowFlags(),
		bool readOnly = false);
	static QString addColorRampStatic(QWidget *parent, QgsStyle *style,
		QString RampType = QString());
	void setFavoritesGroupVisible(bool show);
	void setSmartGroupsVisible(bool show);
	void setBaseStyleName(const QString &name);
protected slots:
	void activate();
	void addItem();
	void editItem();
	void removeItem();
	void exportItemsSVG();
	void exportItemsPNG();
	void exportSelectedItemsImages(const QString &dir, const QString &format, QSize size);
	void exportItems();
	void importItems();
	void populateList();
	void onFinished();
	void onClose();
	void showHelp();
	Q_DECL_DEPRECATED void itemChanged(QStandardItem *item) SIP_DEPRECATED;
	void groupChanged(const QModelIndex &);
	void groupRenamed(QStandardItem *item);
	int addTag();
	int addSmartgroup();
	void removeGroup();
	void tagSymbolsAction();
	void editSmartgroupAction();
	Q_DECL_DEPRECATED void regrouped(QStandardItem *) SIP_DEPRECATED;
	void filterSymbols(const QString &filter);
	void symbolSelected(const QModelIndex &);
	void selectedSymbolsChanged(const QItemSelection &selected, const QItemSelection &deselected);
	void grouptreeContextMenu(QPoint);
	void listitemsContextMenu(QPoint);
protected slots:
	bool addColorRamp(QAction *action);
	void addFavoriteSelectedSymbols();
	void removeFavoriteSelectedSymbols();
	void tagSelectedSymbols(bool newTag = false);
	void detagSelectedSymbols();

protected:
	Q_DECL_DEPRECATED void populateTypes() SIP_DEPRECATED;
	void populateGroups();
	Q_DECL_DEPRECATED void setSymbolsChecked(const QStringList &) SIP_DEPRECATED;
	Q_DECL_DEPRECATED void populateSymbols(const QStringList &symbolNames, bool checkable = false) SIP_DEPRECATED;
	Q_DECL_DEPRECATED void populateColorRamps(const QStringList &colorRamps, bool checkable = false) SIP_DEPRECATED;
	int currentItemType();
	QString currentItemName();
	bool addSymbol(int symbolType = -1);
	bool addColorRamp();
	bool editSymbol();
	bool editColorRamp();
	Q_DECL_DEPRECATED bool removeSymbol() SIP_DEPRECATED;
	Q_DECL_DEPRECATED bool removeColorRamp() SIP_DEPRECATED;
	void enableSymbolInputs(bool);
	void enableGroupInputs(bool);
	void enableItemsForGroupingMode(bool);
	void setBold(QStandardItem *);
private slots:
	void tabItemType_currentChanged(int);
	void copyItemsToDefault();
	void copyItem();
	void pasteItem();
private:
	int selectedItemType();
	bool allTypesSelected() const;

	struct ItemDetails
	{
		QgsStyle::StyleEntity entityType;
		QgsSymbol::SymbolType symbolType;
		QString name;
	};
	QList< ItemDetails > selectedItems();
	static int copyItems(const QList< ItemDetails > &items, QgsStyle *src, QgsStyle *dst,
		QWidget *parentWidget, std::unique_ptr<QgsTemporaryCursorOverride> &cursorOverride,
		bool isImport, const QStringList &importTags, bool addToFavorites, bool ignoreSourceTags);
	QgsMessageBar *mMessageBar = nullptr;
	QgsStyle *mStyle = nullptr;
	S3dmCheckableStyleModel *mModel = nullptr;
	QString mStyleFilename;
	bool mModified = false;
	bool mGroupingMode = false;
	QStringList mTagList;
	QMenu *mGroupMenu = nullptr;
	QMenu *mGroupListMenu = nullptr;
	QMenu *mGroupTreeContextMenu = nullptr;
	QMenu *mMenuBtnAddItemColorRamp = nullptr;
	QMenu *mMenuBtnAddItemAll = nullptr;
	QMenu *mMenuBtnAddItemLabelSettings = nullptr;

	QAction *mActionCopyToDefault = nullptr;

	QAction *mActionCopyItem = nullptr;
	QAction *mActionPasteItem = nullptr;

	int mBlockGroupUpdates = 0;

	bool mReadOnly = false;
	bool mFavoritesGroupVisible = true;
	bool mSmartGroupVisible = true;
	QString mBaseName;

	bool addTextFormat();
	bool editTextFormat();

	bool addLabelSettings(QgsWkbTypes::GeometryType type);
	bool editLabelSettings();
	friend class QgsStyleExportImportDialog;
};
