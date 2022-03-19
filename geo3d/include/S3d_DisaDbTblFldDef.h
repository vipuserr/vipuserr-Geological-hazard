#ifndef __S3D_DISADBTBLFLDDEF__
#define __S3D_DISADBTBLFLDDEF__

#include "s3d_DisaDbTblFldDef_exp.h"
#include "s3d_DbTblFldDef.h"

namespace Smart3dMap
{
	//共用宏

/*----------------------------------调查表--------------------------------------*/
#define BASEINFO_HPYH_CLASS "调查表" 

//滑坡及隐患调查表//Landslide hazard
#define                 TBL_HPYHDCTB_TBL "LandSliderHazard"
#define                 FLD_HPYHDCTB_MC                                      "mc"                             //名称                                 
#define                 FLD_HPYHDCTB_TYBH                                   "tybh"                           //统一编号		PK		               	
#define                 FLD_HPYHDCTB_XSBH                                   "xsbh"                           //县市编号				               	
#define                 FLD_HPYHDCTB_YWBH                                   "ywbh"                           //野外编号				               	
#define                 FLD_HPYHDCTB_WWXCBH                                 "wwxcbh"                         //五万详查编号			               	
#define                 FLD_HPYHDCTB_WZS                                    "wzs"                            //省					               	
#define                 FLD_HPYHDCTB_WZDS                                   "wzds"                           //市					               	
#define                 FLD_HPYHDCTB_WZX                                    "wzx"                            //县					               	
#define                 FLD_HPYHDCTB_WZXZ                                   "wzxz"                           //乡镇					               	
#define                 FLD_HPYHDCTB_WZC                                    "wzc"                            //村					               	
#define                 FLD_HPYHDCTB_WZZ                                    "wzz"                            //组					               	
#define                 FLD_HPYHDCTB_JD                                      "jd"                            //经度					               	
#define                 FLD_HPYHDCTB_WD                                      "wd"                            //维度					               	
#define                 FLD_HPYHDCTB_X                                       "x"                             //x坐标				               	
#define                 FLD_HPYHDCTB_Y                                       "y"                             //y坐标				               	                                                                                                                              		                                                                                                                                           		               	
#define                 FLD_HPYHDCTB_XPGZLX                                  "xpgzlx"                        //斜坡构造类型			               	
#define                 FLD_HPYHDCTB_QZMLX                                   "qzmlx"                         //潜在面类型			               	
#define                 FLD_HPYHDCTB_MQWDZT                                  "mqwdzt"                        //目前稳定状态			               	
#define                 FLD_HPYHDCTB_YDXS                                    "ydxs"                          //运动形式				               	
#define                 FLD_HPYHDCTB_HPLX                                    "hplx"                          //滑坡类型				               	
#define                 FLD_HPYHDCTB_TZFS                                    "tzfs"                          //拓展方式		                        
#define                 FLD_HPYHDCTB_HPND                                    "hpnd"                          //滑坡年代				               	
#define                 FLD_HPYHDCTB_DCYX                                    "dcyx"                          //底层岩性				               	                                                                                                         				          
#define                 FLD_HPYHDCTB_SJN                                     "sjn"                           //年					               	
#define                 FLD_HPYHDCTB_SJY                                     "sjy"                           //月					               	
#define                 FLD_HPYHDCTB_SJR                                     "sjr"                           //日					               	
#define                 FLD_HPYHDCTB_SJS                                     "sjs"                           //时					               	
#define                 FLD_HPYHDCTB_SJF                                     "sjf"                           //分					               	
#define                 FLD_HPYHDCTB_YCQX1                                   "ycqx1"                         //岩层倾向1				               	
#define                 FLD_HPYHDCTB_YCQX2                                   "ycqx2"                         //岩层倾向2						               
#define                 FLD_HPYHDCTB_YCQX3                                   "ycqx3"                         //岩层倾向3						               
#define                 FLD_HPYHDCTB_YCQJ1                                   "ycqj1"                         //岩层倾角1				               	
#define                 FLD_HPYHDCTB_YCQJ2                                   "ycqj2"                         //岩层倾角2						               
#define                 FLD_HPYHDCTB_YCQJ3                                   "ycqj3"                         //岩层倾角3						               
#define                 FLD_HPYHDCTB_DCQX1                                   "dcqx1"                         //断层倾向1				               	
#define                 FLD_HPYHDCTB_DCQX2                                   "dcqx2"                         //断层倾向2						               
#define                 FLD_HPYHDCTB_DCQX3                                   "dcqx3"                         //断层倾向3						               
#define                 FLD_HPYHDCTB_DCQJ1                                   "dcqj1"                         //断层倾角1				               	
#define                 FLD_HPYHDCTB_DCQJ2                                   "dcqj2"                         //断层倾角2						               
#define                 FLD_HPYHDCTB_DCQJ3                                   "dcqj3"                         //断层倾角3						               
#define                 FLD_HPYHDCTB_JLQX1                                   "jlqx1"                         //节理倾向1				               	
#define                 FLD_HPYHDCTB_JLQX2                                   "jlqx2"                         //节理倾向2						               
#define                 FLD_HPYHDCTB_JLQX3                                   "jlqx3"                         //节理倾向3						               
#define                 FLD_HPYHDCTB_JLQJ1                                   "jlqj1"                         //节理倾角1				               	
#define                 FLD_HPYHDCTB_JLQJ2                                   "jlqj2"						 //节理倾角2 						               
#define                 FLD_HPYHDCTB_JLQJ3                                   "jlqj3"						 //节理倾角3						               
#define                 FLD_HPYHDCTB_YFYS                                    "yfys"							 //诱发因素 						               
#define                 FLD_HPYHDCTB_HPPIMXT                                 "hppimxt"                       //滑坡平面形态			               	
#define                 FLD_HPYHDCTB_HPPOMXT                                 "hppomxt"                       //滑坡剖面形态			               	
#define                 FLD_HPYHDCTB_HPPD                                    "hppd"                          //滑坡坡度				               	
#define                 FLD_HPYHDCTB_HPPX                                    "hppx"                          //滑坡坡向				               	
#define                 FLD_HPYHDCTB_STGH                                    "stgh"                          //实体勾绘				               	
#define                 FLD_HPYHDCTB_QYGC                                    "qygc"                          //前缘高程				               	
#define                 FLD_HPYHDCTB_HYGC                                    "hygc"                          //后缘高程				               	
#define                 FLD_HPYHDCTB_HPCD                                    "hpcd"                          //滑坡长度				               	
#define                 FLD_HPYHDCTB_HPKD                                    "hpkd"                          //滑坡宽度				               	
#define                 FLD_HPYHDCTB_HPHD                                    "hphd"                          //滑坡厚度				               	
#define                 FLD_HPYHDCTB_HPMJ                                    "hpmj"                          //滑坡面积				               	
#define                 FLD_HPYHDCTB_HPTJ                                    "hptj"                          //滑坡体积				               	
#define                 FLD_HPYHDCTB_GMDJ                                    "gmdj"                          //规模等级				               	
#define                 FLD_HPYHDCTB_SWRS                                    "swrs"                          //死亡人数				               	
#define                 FLD_HPYHDCTB_WXRS                                    "wxrs"                          //威胁人数				               	
#define                 FLD_HPYHDCTB_ZJSS                                    "zjss"                          //直接损失                             
#define                 FLD_HPYHDCTB_WXCC                                    "wxcc"                          //威胁财产				               	
#define                 FLD_HPYHDCTB_ZQDJ                                    "zqdj"                          //灾情等级				               	
#define                 FLD_HPYHDCTB_XQDJ                                    "xqdj"                          //险情等级				               	
#define                 FLD_HPYHDCTB_WXDX                                    "wxdx"                          //威胁对象				               	
#define                 FLD_HPYHDCTB_RKHS                                    "rkhs"                          //人口户数				               	
#define                 FLD_HPYHDCTB_ETRS                                    "etrs"                          //0-14 岁人			               	
#define                 FLD_HPYHDCTB_QNRS                                    "qnrs"                          //15-59 岁人			               	
#define                 FLD_HPYHDCTB_LNRS                                    "lnrs"                          //60 岁及以上人		               	
#define                 FLD_HPYHDCTB_GZLXFWJ                                 "gzlxfwj"                       //结构类型房屋间		               	
#define                 FLD_HPYHDCTB_GZLXGJGJ                                "gzlxgjgj"                      //结构类型钢结构间		               	
#define                 FLD_HPYHDCTB_GZLXGHJ                                 "gzlxghj"                       //结构类型钢混间		               	
#define                 FLD_HPYHDCTB_GZLXZHJ                                 "gzlxzhj"                       //结构类型砖混间		               	
#define                 FLD_HPYHDCTB_GZLXZMJ                                 "gzlxzmj"                       //结构类型砖木间		               	
#define                 FLD_HPYHDCTB_JGLXTPJ                                 "gzlxtpj"                       //结构类型土坯间		               	
#define                 FLD_HPYHDCTB_GZLXQT                                  "gzlxqt"                        //结构类型其他			               	
#define                 FLD_HPYHDCTB_JZYTXX                                  "jzytxx"                        //建筑用途学校个		               	
#define                 FLD_HPYHDCTB_JZYTYY                                  "jzytyy"                        //建筑用途医院个		               	
#define                 FLD_HPYHDCTB_JZYTKS                                  "jzytks"                        //建筑用途矿山座		               	
#define                 FLD_HPYHDCTB_JZYTGC                                  "jzytgc"                        //建筑用途工厂座		               	
#define                 FLD_HPYHDCTB_JZYTG1                                  "jzytgl"                        //建筑用途公路条		               	
#define                 FLD_HPYHDCTB_JZYTT1                                  "jzyttl"                        //建筑用途铁路条		               	
#define                 FLD_HPYHDCTB_GCSSLXSK                                "gcsslxsk"                      //工程设施类型库座		               	
#define                 FLD_HPYHDCTB_GCSSLXDZ                                "gcsslxdz"                      //工程设施类型电站座	               	
#define                 FLD_HPYHDCTB_GCSSLXSDX                               "gcsslxsdx"                     //工程设施类型输电线路	               	
#define                 FLD_HPYHDCTB_GCSSLXTXX                               "gcsslxtxx"                     //工程设施类型通讯线路	               	
#define                 FLD_HPYHDCTB_GCSSLXQT                                "gcsslxqt"                      //工程设施类型其他		               	
#define                 FLD_HPYHDCTB_FZCS                                    "fzcs"                          //防治措施				               	
#define                 FLD_HPYHDCTB_FZLX                                    "fzlx"                          //防治类型				               	
#define                 FLD_HPYHDCTB_FZCSJY                                  "fzcsjy"                        //防治措施建议			               	
#define                 FLD_HPYHDCTB_YGD                                     "ygd"                           //遥感点				               	
#define                 FLD_HPYHDCTB_KCD                                     "kcd"                           //勘查点				               	
#define                 FLD_HPYHDCTB_CHD                                     "chd"                           //测绘点				               	
#define                 FLD_HPYHDCTB_QCQFD                                   "qcqfd"                         //群测群防点			               	
#define                 FLD_HPYHDCTB_FXDJ                                    "fxdj"                          //风险等级				               	
#define                 FLD_HPYHDCTB_DZGZ                                    "dzgz"                          //地质构造				               	
#define                 FLD_HPYHDCTB_BJTJ                                    "bjtj"                          //边界条件				               	
#define                 FLD_HPYHDCTB_BXTZJHDLS                               "bxtzjhdls"                     //变形特征及活动历史	               	
#define                 FLD_HPYHDCTB_WHDX                                    "whdx"                          //危害对象				               	
#define                 FLD_HPYHDCTB_WHXMS                                   "whxms"                         //危害性描述			               	
#define                 FLD_HPYHDCTB_BCXMS                                   "bcxms"                         //补充性描述			               	
#define                 FLD_HPYHDCTB_SLPIMT                                   "slpmt"                        //矢量平面图			               	
#define                 FLD_HPYHDCTB_SLPOMT                                  "slpomt"                        //矢量剖面图			               	
#define                 FLD_HPYHDCTB_TBSJN                                   "tbsjn"                         //填表日期年			               	
#define                 FLD_HPYHDCTB_TBSJY                                   "tbsjy"                         //填表日期月			               	
#define                 FLD_HPYHDCTB_TBSJR                                   "tbsjr"                         //填表日期日			               	
#define                 FLD_HPYHDCTB_TBR                                     "tbr"                           //填表人				               	
#define                 FLD_HPYHDCTB_SHR                                     "shr"                           //审核人				               	
#define                 FLD_HPYHDCTB_DCFZR                                   "dcfzr"                         //调查负责人			               	
#define 		        FLD_HPYHDCTB_RKRS                                    "rkrs"                          //人口人数
/*----------------------------------其他调查表可在此写--------------------------------------*/
				   



//字段枚举
typedef enum FieldMacro
{
	ENUM_FLD_str_HPYHDCTB_MC,                              //名称         string              
	ENUM_FLD_str_HPYHDCTB_TYBH,                            //统一编号     string 
	ENUM_FLD_str_HPYHDCTB_XSBH,                            //县市编号     string 
	ENUM_FLD_str_HPYHDCTB_YWBH,                            //野外编号     string 
	ENUM_FLD_str_HPYHDCTB_WWXCBH,                          //五万详查编号 string 
	ENUM_FLD_str_HPYHDCTB_WZS,                             //省           string 
	ENUM_FLD_str_HPYHDCTB_WZDS,                            //市           string 
	ENUM_FLD_str_HPYHDCTB_WZX,                             //县           string 
	ENUM_FLD_str_HPYHDCTB_WZXZ,                            //乡镇         string  
	ENUM_FLD_str_HPYHDCTB_WZC,                             //村           string    
	ENUM_FLD_str_HPYHDCTB_WZZ,                             //组           string
	ENUM_FLD_dou_HPYHDCTB_JD,                              //经度         double
	ENUM_FLD_dou_HPYHDCTB_WD,                              //维度         double
	ENUM_FLD_dou_HPYHDCTB_X,                               //x坐标        double
	ENUM_FLD_dou_HPYHDCTB_Y,                               //y坐标        double
	ENUM_FLD_str_HPYHDCTB_XPGZLX,                          //斜坡构造类型 string
	ENUM_FLD_str_HPYHDCTB_QZMLX,                           //潜在面类型   string
	ENUM_FLD_str_HPYHDCTB_MQWDZT,                          //目前稳定状态 string 
	ENUM_FLD_str_HPYHDCTB_YDXS,                            //运动形式     string
	ENUM_FLD_str_HPYHDCTB_HPLX,                            //滑坡类型     string
	ENUM_FLD_str_HPYHDCTB_TZFS,                            //拓展方式     string
	ENUM_FLD_str_HPYHDCTB_HPND,                            //滑坡年代     string 
	ENUM_FLD_str_HPYHDCTB_DCYX,                            //底层岩性     string 
	ENUM_FLD_int_HPYHDCTB_SJN,                             //年            int
	ENUM_FLD_int_HPYHDCTB_SJY,                             //月            int
	ENUM_FLD_int_HPYHDCTB_SJR,                             //日            int
	ENUM_FLD_int_HPYHDCTB_SJS,                             //时            int
	ENUM_FLD_int_HPYHDCTB_SJF,                             //分            int
	ENUM_FLD_flo_HPYHDCTB_YCQX1,                           //岩层倾向1     float
	ENUM_FLD_flo_HPYHDCTB_YCQX2,                           //岩层倾向2 	   float	  
	ENUM_FLD_flo_HPYHDCTB_YCQX3,                           //岩层倾向3 	   float	  
	ENUM_FLD_flo_HPYHDCTB_YCQJ1,                           //岩层倾角1     float
	ENUM_FLD_flo_HPYHDCTB_YCQJ2,						   //岩层倾角2	   float			  
	ENUM_FLD_flo_HPYHDCTB_YCQJ3,						   //岩层倾角3	   float			  
	ENUM_FLD_flo_HPYHDCTB_DCQX1,                           //断层倾向1     float
	ENUM_FLD_flo_HPYHDCTB_DCQX2,						   //断层倾向2     float		  
	ENUM_FLD_flo_HPYHDCTB_DCQX3,						   //断层倾向3	   float	  
	ENUM_FLD_flo_HPYHDCTB_DCQJ1,                           //断层倾角1     float
	ENUM_FLD_flo_HPYHDCTB_DCQJ2,						   //断层倾角2	   float			  
	ENUM_FLD_flo_HPYHDCTB_DCQJ3,						   //断层倾角3	   float			  
	ENUM_FLD_flo_HPYHDCTB_JLQX1,                           //节理倾向1     float
	ENUM_FLD_flo_HPYHDCTB_JLQX2,						   //节理倾向2	   float 			  
	ENUM_FLD_flo_HPYHDCTB_JLQX3,						   //节理倾向3	   float			  
	ENUM_FLD_flo_HPYHDCTB_JLQJ1,                           //节理倾角1     float
	ENUM_FLD_flo_HPYHDCTB_JLQJ2,						   //节理倾角2	   float		  
	ENUM_FLD_flo_HPYHDCTB_JLQJ3,						   //节理倾角3	   float		  
	ENUM_FLD_str_HPYHDCTB_YFYS,							   //诱发因素 	   string		  
	ENUM_FLD_str_HPYHDCTB_HPPIMXT,                         //滑坡平面形态         string
	ENUM_FLD_str_HPYHDCTB_HPPOMXT,                         //滑坡剖面形态         string
	ENUM_FLD_flo_HPYHDCTB_HPPD,                            //滑坡坡度             float 
	ENUM_FLD_flo_HPYHDCTB_HPPX,                            //滑坡坡向             float 
	ENUM_FLD_bol_HPYHDCTB_STGH,                            //实体勾绘             bool*
	ENUM_FLD_dou_HPYHDCTB_QYGC,                            //前缘高程             double
	ENUM_FLD_dou_HPYHDCTB_HYGC,                            //后缘高程             double 
	ENUM_FLD_dou_HPYHDCTB_HPCD,                            //滑坡长度             double
	ENUM_FLD_dou_HPYHDCTB_HPKD,                            //滑坡宽度             double
	ENUM_FLD_dou_HPYHDCTB_HPHD,                            //滑坡厚度             double
	ENUM_FLD_dou_HPYHDCTB_HPMJ,                            //滑坡面积             double
	ENUM_FLD_dou_HPYHDCTB_HPTJ,                            //滑坡体积             double
	ENUM_FLD_str_HPYHDCTB_GMDJ,                            //规模等级             string
	ENUM_FLD_lon_HPYHDCTB_SWRS,                            //死亡人数             long
	ENUM_FLD_lon_HPYHDCTB_WXRS,                            //威胁人数             long
	ENUM_FLD_dou_HPYHDCTB_ZJSS,                            //直接损失	          double
	ENUM_FLD_dou_HPYHDCTB_WXCC,                            //威胁财产	          double 
	ENUM_FLD_str_HPYHDCTB_ZQDJ,                            //灾情等级	          string
	ENUM_FLD_str_HPYHDCTB_XQDJ,                            //险情等级	          string
	ENUM_FLD_str_HPYHDCTB_WXDX,                            //威胁对象 	          string
	ENUM_FLD_lon_HPYHDCTB_RKHS,                            //人口户数             long
	ENUM_FLD_lon_HPYHDCTB_ETRS,                            //0-14 岁人            long
	ENUM_FLD_lon_HPYHDCTB_QNRS,                            //15-59 岁人           long
	ENUM_FLD_lon_HPYHDCTB_LNRS,                            //60 岁及以上人        long
	ENUM_FLD_lon_HPYHDCTB_GZLXFWJ,                         //结构类型房屋间       long
	ENUM_FLD_lon_HPYHDCTB_GZLXGJGJ,	                       //结构类型钢结构间     long
	ENUM_FLD_lon_HPYHDCTB_GZLXGHJ, 	                       //结构类型钢混间       long
	ENUM_FLD_lon_HPYHDCTB_GZLXZHJ, 	                       //结构类型砖混间       long
	ENUM_FLD_lon_HPYHDCTB_GZLXZMJ, 	                       //结构类型砖木间       long
	ENUM_FLD_lon_HPYHDCTB_JGLXTPJ, 	                       //结构类型土坯间       long
	ENUM_FLD_str_HPYHDCTB_GZLXQT,  	                       //结构类型其他         string
	ENUM_FLD_lon_HPYHDCTB_JZYTXX,  	                       //建筑用途学校个       long
	ENUM_FLD_lon_HPYHDCTB_JZYTYY,  	                       //建筑用途医院个       long
	ENUM_FLD_lon_HPYHDCTB_JZYTKS,  	                       //建筑用途矿山座       long
	ENUM_FLD_lon_HPYHDCTB_JZYTGC,  	                       //建筑用途工厂座       long
	ENUM_FLD_dou_HPYHDCTB_JZYTG1,  	                       //建筑用途公路条       double
	ENUM_FLD_dou_HPYHDCTB_JZYTT1,  	                       //建筑用途铁路条       double
	ENUM_FLD_lon_HPYHDCTB_GCSSLXSK,	                       //工程设施类型库座     long
	ENUM_FLD_lon_HPYHDCTB_GCSSLXDZ,	                       //工程设施类型电站座   long
	ENUM_FLD_dou_HPYHDCTB_GCSSLXSDX,                       //工程设施类型输电线路 double
	ENUM_FLD_dou_HPYHDCTB_GCSSLXTXX,                       //工程设施类型通讯线路 double
	ENUM_FLD_str_HPYHDCTB_GCSSLXQT,                        //工程设施类型其他     string
	ENUM_FLD_bol_HPYHDCTB_FZCS,	                           //防治措施             bool*
	ENUM_FLD_str_HPYHDCTB_FZLX,	                           //防治类型             string
	ENUM_FLD_str_HPYHDCTB_FZCSJY,                          //防治措施建议         string
	ENUM_FLD_bol_HPYHDCTB_YGD,	                           //遥感点               bool*
	ENUM_FLD_bol_HPYHDCTB_KCD,	                           //勘查点               bool*
	ENUM_FLD_bol_HPYHDCTB_CHD,	                           //测绘点               bool*
	ENUM_FLD_bol_HPYHDCTB_QCQFD,                           //群测群防点           bool*
	ENUM_FLD_str_HPYHDCTB_FXDJ,	                           //风险等级             string
	ENUM_FLD_str_HPYHDCTB_DZGZ,	                           //地质构造             string
	ENUM_FLD_str_HPYHDCTB_BJTJ,	                           //边界条件             string
	ENUM_FLD_str_HPYHDCTB_BXTZJHDLS,                       //变形特征及活动历史   string
	ENUM_FLD_str_HPYHDCTB_WHDX,                            //危害对象             string
	ENUM_FLD_str_HPYHDCTB_WHXMS,	                       //危害性描述           string
	ENUM_FLD_str_HPYHDCTB_BCXMS,	                       //补充性描述           string
	ENUM_FLD_str_HPYHDCTB_SLPIMT,	                       //矢量平面图           string
	ENUM_FLD_str_HPYHDCTB_SLPOMT,	                       //矢量剖面图           string
	ENUM_FLD_lon_HPYHDCTB_TBSJN,	                       //填表日期年           long
	ENUM_FLD_lon_HPYHDCTB_TBSJY,	                       //填表日期月           long
	ENUM_FLD_lon_HPYHDCTB_TBSJR,	                       //填表日期日           long
	ENUM_FLD_str_HPYHDCTB_TBR,		                       //填表人               string
	ENUM_FLD_str_HPYHDCTB_SHR,		                       //审核人               string
	ENUM_FLD_str_HPYHDCTB_DCFZR,	                       //调查负责人           string
	ENUM_FLD_lon_HPYHDCTB_RKRS,                            //人口人数             long
};							                      
								                       

	//属性数据库的表和字段定义初始化类
	class S3D_DIS_DBENGINE_API S3d_DisaDbTblFldDef :public DbTblFldDef
	{
	public:
		static S3d_DisaDbTblFldDef* getSingletonPtr();
	public:
		void forceInitDbMap() override;//强制初始化,给s3dMdlContainer赋值
	};
}

#endif // !__S3D_DISADBTBLFLDDEF__
