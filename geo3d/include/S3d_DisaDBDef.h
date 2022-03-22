#ifndef __S3D_DISADBDEF_H__
#define __S3D_DISADBDEF_H__


#include <string>
#include"s3d_DisaDbTblFldDef_exp.h"


using namespace std;

namespace Smart3dMap
{
	//滑坡及隐患调查表
	class S3D_DIS_DBENGINE_API  LandSliderHazard 
	{
	public:
		string mc ;       //名称
		string tybh ;     //统一编号
		string xsbh ;     //县市编号
		string ywbh ;     //野外编号
		string wwxcbh ;   //五万详查编号
		string wzs ;      //省
		string wzds ;     //市
		string wzx ;      //县
		string wzxz ;     //乡镇
		string wzc ;      //村
		string wzz ;      //组
		double jd ;//经度
		double wd ;//维度
		double x ;//x坐标
		double y ;//y坐标
		string hplx ;//滑坡类型
		string dcyx ;//底层岩性
		string xpgzlx ;//斜坡构造类型
		string qzmlx ;//潜在面类型
		string mqwdzt ;//目前稳定状态
		string ydxs ;//运动形式
		string tzfs ;//拓展方式
		string hpnd ;//滑坡年代
		int sjn;//年
		int sjy;//月
		int sjr;//日
		int sjs;//时
		int sjf;//分
		float ycqx1;//岩层倾向
		float ycqx2;
		float ycqx3;
		float ycqj1;//岩层倾角
		float ycqj2;
		float ycqj3;
		float dcqx1;//断层倾向
		float dcqx2;
		float dcqx3;
		float dcqj1;//断层倾角
		float dcqj2;
		float dcqj3;
		float jlqx1;//节理倾向
		float jlqx2;
		float jlqx3;
		float jlqj1;//节理倾角
		float jlqj2;
		float jlqj3;
		string yfys;
		string hppimxt;//滑坡平面形态
		string hppomxt;//滑坡剖面形态
		float hppd;//滑坡坡度
		float hppx;//滑坡坡向
		bool stgh;//实体勾绘*
		double qygc;//前缘高程
		double hygc;//后缘高程
		double hpcd;//滑坡长度
		double hpkd;//滑坡宽度
		double hphd;//滑坡厚度
		double hpmj;//滑坡面积
		double hptj;//滑坡体积
		string gmdj;//规模等级
		long swrs;//死亡人数
		long wxrs;//威胁人数
		double zjss;//直接损失
		double wxcc;//威胁财产
		string zqdj;//灾情等级
		string xqdj;//险情等级
		string wxdx;//威胁对象
		long rkhs;//人口户数
		long etrs;//0-14 岁人
		long qnrs;//15-59 岁人
		long lnrs;//60 岁及以上人
		long gzlxfwj;//结构类型房屋间
		long gzlxgjgj;//结构类型钢结构间
		long gzlxghj;//结构类型钢混间
		long gzlxzhj;//结构类型砖混间
		long gzlxzmj;// 结构类型砖木间
		long gzlxtpj;//结构类型土坯间
		string gzlxqt;//结构类型其他
		long jzytxx;//建筑用途学校
		long jzytyy;//建筑用途医院
		long jzytks;//建筑用途矿山座
		long jzytgc;//建筑用途工厂座
		double jzytgl;//建筑用途公路条
		double jzyttl;//建筑用途铁路条
		long gcsslxsk;//工程设施类型库座
		long gcsslxdz;//工程设施类型电站座
		double gcsslxsdx;//工程设施类型输电线路
		double gcsslxtxx;//工程设施类型通讯线路
		string gcsslxqt;//工程设施类型其他
		bool fzcs;//防治措施*
		string fzlx;//防治类型
		string fzcsjy;//防治措施建议
		bool ygd;//遥感点*
		bool kcd;//勘查点*
		bool chd;//测绘点*
		bool qcqfd;//群测群防点*
		string fxdj;//风险等级
		string dzgz;//地质构造
		string bjtj;//边界条件
		string bxtzjhdls;//变形特征及活动历史
		string whdx;//危害对象
		string whxms;//危害性描述
		string bcxms;//补充性描述
		string slpimt;//矢量平面图
		string slpomt;//矢量剖面图
		long tbsjn;//填表日期年
		long tbsjy;//填表日期月
		long tbsjr;//填表日期日
		string tbr;//填表人
		string shr;//审核人
		string dcfzr;//调查负责人
		long rkrs;   //人口人数
	};
}
#endif