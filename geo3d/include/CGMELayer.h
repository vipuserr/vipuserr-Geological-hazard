#pragma once

#include "GmeCommonLayer.h"
#include "OG3DElement.h"
#include "OGFrameWork.h"
#include "OG3DLayerManager.h"
#include "OGGme3DLayerGuid.h"
#include "OG3DElementManager.h"
#include "layerplugin_geo3d_global.h"


//三维图层CGMELayer的缩放功能
//const string	FUNC_AddModel = "关联模型";
const string	FUNC_Legend = "图例开关";
const string	FUNC_DrawText = "注记开关";
const string	FUNC_SaveModel = "存储模型";

const string	FUNC_JumpToModel = "跳转显示";
const string	FUNC_ShowNormal = "显示法向";
const string	FUNC_ShowTriIDs = "显示三角形号";
const string	FUNC_ShowTriVertexIDs = "显示三角形顶点号";
const string	FUNC_layerTransparency = "图层透明度";

const string	FUNC_BuildIsoMap = "生成地层底面等值线";//不合适


namespace Smart3dMap
{
	class LAYERPLUGIN_GEO3D_EXPORT CGMELayer : public GmeCommonLayer
	{
	public:
		CGMELayer(const string& name, const OGGUID& guid);
		~CGMELayer();

		//命令映射
		virtual void registerFunctions(void);
		virtual void onExecute(const string& name, WPARAM wParam, LPARAM lParam);

		//消息响应
		virtual void registerIntMsg();
		virtual long OnMessagePro(long nMsg, __int64 wParam, __int64 lParam);

		virtual void registerStrMsg();
		virtual long OnMessagePro(string msg, __int64 wParam, __int64 lParam);

		//删除关联
		virtual long BeforeDelRelt();
		virtual long DelRelt();

		//删除图层
		virtual long BeforeDelLayer();
		virtual long DelLayer(BOOL bPrompt = TRUE);

		//从DataElement载入
		virtual bool load(DataElement* element);
		//保存到DataElement
		virtual bool save(DataElement* element);
		virtual void BeforeSave();

		//数据可见
		virtual void setVisible(bool visible, bool cascade = true);

	public:
		void setScaleFactor(osg::Vec3 factor);
		osg::Vec3 getScaleFactor();

		//注记
		osg::ref_ptr<osg::MatrixTransform> cvtGmeNote23DLayer();

		//未使用
		void MdlSave2GmeDB();

	protected:
		//未使用
		Container* GetLayerContainer(std::string enuFileFilter);
		Container* GetLayerContainer();
		Container* OpenThreedimensionFile(std::string strFilterCondition);


	};

	COMMON_LAYLER_FACTORY(CGMELayer, THREEDIMENSION_LAYER_GUID, "三维模型");
}
