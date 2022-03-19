#ifndef __S3D_DISADBTBLFLDDEF__
#define __S3D_DISADBTBLFLDDEF__

#include "s3d_DisaDbTblFldDef_exp.h"
#include "s3d_DbTblFldDef.h"

namespace Smart3dMap
{
	//���ú�

/*----------------------------------�����--------------------------------------*/
#define BASEINFO_HPYH_CLASS "�����" 

//���¼����������//Landslide hazard
#define                 TBL_HPYHDCTB_TBL "LandSliderHazard"
#define                 FLD_HPYHDCTB_MC                                      "mc"                             //����                                 
#define                 FLD_HPYHDCTB_TYBH                                   "tybh"                           //ͳһ���		PK		               	
#define                 FLD_HPYHDCTB_XSBH                                   "xsbh"                           //���б��				               	
#define                 FLD_HPYHDCTB_YWBH                                   "ywbh"                           //Ұ����				               	
#define                 FLD_HPYHDCTB_WWXCBH                                 "wwxcbh"                         //���������			               	
#define                 FLD_HPYHDCTB_WZS                                    "wzs"                            //ʡ					               	
#define                 FLD_HPYHDCTB_WZDS                                   "wzds"                           //��					               	
#define                 FLD_HPYHDCTB_WZX                                    "wzx"                            //��					               	
#define                 FLD_HPYHDCTB_WZXZ                                   "wzxz"                           //����					               	
#define                 FLD_HPYHDCTB_WZC                                    "wzc"                            //��					               	
#define                 FLD_HPYHDCTB_WZZ                                    "wzz"                            //��					               	
#define                 FLD_HPYHDCTB_JD                                      "jd"                            //����					               	
#define                 FLD_HPYHDCTB_WD                                      "wd"                            //ά��					               	
#define                 FLD_HPYHDCTB_X                                       "x"                             //x����				               	
#define                 FLD_HPYHDCTB_Y                                       "y"                             //y����				               	                                                                                                                              		                                                                                                                                           		               	
#define                 FLD_HPYHDCTB_XPGZLX                                  "xpgzlx"                        //б�¹�������			               	
#define                 FLD_HPYHDCTB_QZMLX                                   "qzmlx"                         //Ǳ��������			               	
#define                 FLD_HPYHDCTB_MQWDZT                                  "mqwdzt"                        //Ŀǰ�ȶ�״̬			               	
#define                 FLD_HPYHDCTB_YDXS                                    "ydxs"                          //�˶���ʽ				               	
#define                 FLD_HPYHDCTB_HPLX                                    "hplx"                          //��������				               	
#define                 FLD_HPYHDCTB_TZFS                                    "tzfs"                          //��չ��ʽ		                        
#define                 FLD_HPYHDCTB_HPND                                    "hpnd"                          //�������				               	
#define                 FLD_HPYHDCTB_DCYX                                    "dcyx"                          //�ײ�����				               	                                                                                                         				          
#define                 FLD_HPYHDCTB_SJN                                     "sjn"                           //��					               	
#define                 FLD_HPYHDCTB_SJY                                     "sjy"                           //��					               	
#define                 FLD_HPYHDCTB_SJR                                     "sjr"                           //��					               	
#define                 FLD_HPYHDCTB_SJS                                     "sjs"                           //ʱ					               	
#define                 FLD_HPYHDCTB_SJF                                     "sjf"                           //��					               	
#define                 FLD_HPYHDCTB_YCQX1                                   "ycqx1"                         //�Ҳ�����1				               	
#define                 FLD_HPYHDCTB_YCQX2                                   "ycqx2"                         //�Ҳ�����2						               
#define                 FLD_HPYHDCTB_YCQX3                                   "ycqx3"                         //�Ҳ�����3						               
#define                 FLD_HPYHDCTB_YCQJ1                                   "ycqj1"                         //�Ҳ����1				               	
#define                 FLD_HPYHDCTB_YCQJ2                                   "ycqj2"                         //�Ҳ����2						               
#define                 FLD_HPYHDCTB_YCQJ3                                   "ycqj3"                         //�Ҳ����3						               
#define                 FLD_HPYHDCTB_DCQX1                                   "dcqx1"                         //�ϲ�����1				               	
#define                 FLD_HPYHDCTB_DCQX2                                   "dcqx2"                         //�ϲ�����2						               
#define                 FLD_HPYHDCTB_DCQX3                                   "dcqx3"                         //�ϲ�����3						               
#define                 FLD_HPYHDCTB_DCQJ1                                   "dcqj1"                         //�ϲ����1				               	
#define                 FLD_HPYHDCTB_DCQJ2                                   "dcqj2"                         //�ϲ����2						               
#define                 FLD_HPYHDCTB_DCQJ3                                   "dcqj3"                         //�ϲ����3						               
#define                 FLD_HPYHDCTB_JLQX1                                   "jlqx1"                         //��������1				               	
#define                 FLD_HPYHDCTB_JLQX2                                   "jlqx2"                         //��������2						               
#define                 FLD_HPYHDCTB_JLQX3                                   "jlqx3"                         //��������3						               
#define                 FLD_HPYHDCTB_JLQJ1                                   "jlqj1"                         //�������1				               	
#define                 FLD_HPYHDCTB_JLQJ2                                   "jlqj2"						 //�������2 						               
#define                 FLD_HPYHDCTB_JLQJ3                                   "jlqj3"						 //�������3						               
#define                 FLD_HPYHDCTB_YFYS                                    "yfys"							 //�շ����� 						               
#define                 FLD_HPYHDCTB_HPPIMXT                                 "hppimxt"                       //����ƽ����̬			               	
#define                 FLD_HPYHDCTB_HPPOMXT                                 "hppomxt"                       //����������̬			               	
#define                 FLD_HPYHDCTB_HPPD                                    "hppd"                          //�����¶�				               	
#define                 FLD_HPYHDCTB_HPPX                                    "hppx"                          //��������				               	
#define                 FLD_HPYHDCTB_STGH                                    "stgh"                          //ʵ�年��				               	
#define                 FLD_HPYHDCTB_QYGC                                    "qygc"                          //ǰԵ�߳�				               	
#define                 FLD_HPYHDCTB_HYGC                                    "hygc"                          //��Ե�߳�				               	
#define                 FLD_HPYHDCTB_HPCD                                    "hpcd"                          //���³���				               	
#define                 FLD_HPYHDCTB_HPKD                                    "hpkd"                          //���¿��				               	
#define                 FLD_HPYHDCTB_HPHD                                    "hphd"                          //���º��				               	
#define                 FLD_HPYHDCTB_HPMJ                                    "hpmj"                          //�������				               	
#define                 FLD_HPYHDCTB_HPTJ                                    "hptj"                          //�������				               	
#define                 FLD_HPYHDCTB_GMDJ                                    "gmdj"                          //��ģ�ȼ�				               	
#define                 FLD_HPYHDCTB_SWRS                                    "swrs"                          //��������				               	
#define                 FLD_HPYHDCTB_WXRS                                    "wxrs"                          //��в����				               	
#define                 FLD_HPYHDCTB_ZJSS                                    "zjss"                          //ֱ����ʧ                             
#define                 FLD_HPYHDCTB_WXCC                                    "wxcc"                          //��в�Ʋ�				               	
#define                 FLD_HPYHDCTB_ZQDJ                                    "zqdj"                          //����ȼ�				               	
#define                 FLD_HPYHDCTB_XQDJ                                    "xqdj"                          //����ȼ�				               	
#define                 FLD_HPYHDCTB_WXDX                                    "wxdx"                          //��в����				               	
#define                 FLD_HPYHDCTB_RKHS                                    "rkhs"                          //�˿ڻ���				               	
#define                 FLD_HPYHDCTB_ETRS                                    "etrs"                          //0-14 ����			               	
#define                 FLD_HPYHDCTB_QNRS                                    "qnrs"                          //15-59 ����			               	
#define                 FLD_HPYHDCTB_LNRS                                    "lnrs"                          //60 �꼰������		               	
#define                 FLD_HPYHDCTB_GZLXFWJ                                 "gzlxfwj"                       //�ṹ���ͷ��ݼ�		               	
#define                 FLD_HPYHDCTB_GZLXGJGJ                                "gzlxgjgj"                      //�ṹ���͸ֽṹ��		               	
#define                 FLD_HPYHDCTB_GZLXGHJ                                 "gzlxghj"                       //�ṹ���͸ֻ��		               	
#define                 FLD_HPYHDCTB_GZLXZHJ                                 "gzlxzhj"                       //�ṹ����ש���		               	
#define                 FLD_HPYHDCTB_GZLXZMJ                                 "gzlxzmj"                       //�ṹ����שľ��		               	
#define                 FLD_HPYHDCTB_JGLXTPJ                                 "gzlxtpj"                       //�ṹ����������		               	
#define                 FLD_HPYHDCTB_GZLXQT                                  "gzlxqt"                        //�ṹ��������			               	
#define                 FLD_HPYHDCTB_JZYTXX                                  "jzytxx"                        //������;ѧУ��		               	
#define                 FLD_HPYHDCTB_JZYTYY                                  "jzytyy"                        //������;ҽԺ��		               	
#define                 FLD_HPYHDCTB_JZYTKS                                  "jzytks"                        //������;��ɽ��		               	
#define                 FLD_HPYHDCTB_JZYTGC                                  "jzytgc"                        //������;������		               	
#define                 FLD_HPYHDCTB_JZYTG1                                  "jzytgl"                        //������;��·��		               	
#define                 FLD_HPYHDCTB_JZYTT1                                  "jzyttl"                        //������;��·��		               	
#define                 FLD_HPYHDCTB_GCSSLXSK                                "gcsslxsk"                      //������ʩ���Ϳ���		               	
#define                 FLD_HPYHDCTB_GCSSLXDZ                                "gcsslxdz"                      //������ʩ���͵�վ��	               	
#define                 FLD_HPYHDCTB_GCSSLXSDX                               "gcsslxsdx"                     //������ʩ���������·	               	
#define                 FLD_HPYHDCTB_GCSSLXTXX                               "gcsslxtxx"                     //������ʩ����ͨѶ��·	               	
#define                 FLD_HPYHDCTB_GCSSLXQT                                "gcsslxqt"                      //������ʩ��������		               	
#define                 FLD_HPYHDCTB_FZCS                                    "fzcs"                          //���δ�ʩ				               	
#define                 FLD_HPYHDCTB_FZLX                                    "fzlx"                          //��������				               	
#define                 FLD_HPYHDCTB_FZCSJY                                  "fzcsjy"                        //���δ�ʩ����			               	
#define                 FLD_HPYHDCTB_YGD                                     "ygd"                           //ң�е�				               	
#define                 FLD_HPYHDCTB_KCD                                     "kcd"                           //�����				               	
#define                 FLD_HPYHDCTB_CHD                                     "chd"                           //����				               	
#define                 FLD_HPYHDCTB_QCQFD                                   "qcqfd"                         //Ⱥ��Ⱥ����			               	
#define                 FLD_HPYHDCTB_FXDJ                                    "fxdj"                          //���յȼ�				               	
#define                 FLD_HPYHDCTB_DZGZ                                    "dzgz"                          //���ʹ���				               	
#define                 FLD_HPYHDCTB_BJTJ                                    "bjtj"                          //�߽�����				               	
#define                 FLD_HPYHDCTB_BXTZJHDLS                               "bxtzjhdls"                     //�������������ʷ	               	
#define                 FLD_HPYHDCTB_WHDX                                    "whdx"                          //Σ������				               	
#define                 FLD_HPYHDCTB_WHXMS                                   "whxms"                         //Σ��������			               	
#define                 FLD_HPYHDCTB_BCXMS                                   "bcxms"                         //����������			               	
#define                 FLD_HPYHDCTB_SLPIMT                                   "slpmt"                        //ʸ��ƽ��ͼ			               	
#define                 FLD_HPYHDCTB_SLPOMT                                  "slpomt"                        //ʸ������ͼ			               	
#define                 FLD_HPYHDCTB_TBSJN                                   "tbsjn"                         //���������			               	
#define                 FLD_HPYHDCTB_TBSJY                                   "tbsjy"                         //���������			               	
#define                 FLD_HPYHDCTB_TBSJR                                   "tbsjr"                         //���������			               	
#define                 FLD_HPYHDCTB_TBR                                     "tbr"                           //�����				               	
#define                 FLD_HPYHDCTB_SHR                                     "shr"                           //�����				               	
#define                 FLD_HPYHDCTB_DCFZR                                   "dcfzr"                         //���鸺����			               	
#define 		        FLD_HPYHDCTB_RKRS                                    "rkrs"                          //�˿�����
/*----------------------------------�����������ڴ�д--------------------------------------*/
				   



//�ֶ�ö��
typedef enum FieldMacro
{
	ENUM_FLD_str_HPYHDCTB_MC,                              //����         string              
	ENUM_FLD_str_HPYHDCTB_TYBH,                            //ͳһ���     string 
	ENUM_FLD_str_HPYHDCTB_XSBH,                            //���б��     string 
	ENUM_FLD_str_HPYHDCTB_YWBH,                            //Ұ����     string 
	ENUM_FLD_str_HPYHDCTB_WWXCBH,                          //��������� string 
	ENUM_FLD_str_HPYHDCTB_WZS,                             //ʡ           string 
	ENUM_FLD_str_HPYHDCTB_WZDS,                            //��           string 
	ENUM_FLD_str_HPYHDCTB_WZX,                             //��           string 
	ENUM_FLD_str_HPYHDCTB_WZXZ,                            //����         string  
	ENUM_FLD_str_HPYHDCTB_WZC,                             //��           string    
	ENUM_FLD_str_HPYHDCTB_WZZ,                             //��           string
	ENUM_FLD_dou_HPYHDCTB_JD,                              //����         double
	ENUM_FLD_dou_HPYHDCTB_WD,                              //ά��         double
	ENUM_FLD_dou_HPYHDCTB_X,                               //x����        double
	ENUM_FLD_dou_HPYHDCTB_Y,                               //y����        double
	ENUM_FLD_str_HPYHDCTB_XPGZLX,                          //б�¹������� string
	ENUM_FLD_str_HPYHDCTB_QZMLX,                           //Ǳ��������   string
	ENUM_FLD_str_HPYHDCTB_MQWDZT,                          //Ŀǰ�ȶ�״̬ string 
	ENUM_FLD_str_HPYHDCTB_YDXS,                            //�˶���ʽ     string
	ENUM_FLD_str_HPYHDCTB_HPLX,                            //��������     string
	ENUM_FLD_str_HPYHDCTB_TZFS,                            //��չ��ʽ     string
	ENUM_FLD_str_HPYHDCTB_HPND,                            //�������     string 
	ENUM_FLD_str_HPYHDCTB_DCYX,                            //�ײ�����     string 
	ENUM_FLD_int_HPYHDCTB_SJN,                             //��            int
	ENUM_FLD_int_HPYHDCTB_SJY,                             //��            int
	ENUM_FLD_int_HPYHDCTB_SJR,                             //��            int
	ENUM_FLD_int_HPYHDCTB_SJS,                             //ʱ            int
	ENUM_FLD_int_HPYHDCTB_SJF,                             //��            int
	ENUM_FLD_flo_HPYHDCTB_YCQX1,                           //�Ҳ�����1     float
	ENUM_FLD_flo_HPYHDCTB_YCQX2,                           //�Ҳ�����2 	   float	  
	ENUM_FLD_flo_HPYHDCTB_YCQX3,                           //�Ҳ�����3 	   float	  
	ENUM_FLD_flo_HPYHDCTB_YCQJ1,                           //�Ҳ����1     float
	ENUM_FLD_flo_HPYHDCTB_YCQJ2,						   //�Ҳ����2	   float			  
	ENUM_FLD_flo_HPYHDCTB_YCQJ3,						   //�Ҳ����3	   float			  
	ENUM_FLD_flo_HPYHDCTB_DCQX1,                           //�ϲ�����1     float
	ENUM_FLD_flo_HPYHDCTB_DCQX2,						   //�ϲ�����2     float		  
	ENUM_FLD_flo_HPYHDCTB_DCQX3,						   //�ϲ�����3	   float	  
	ENUM_FLD_flo_HPYHDCTB_DCQJ1,                           //�ϲ����1     float
	ENUM_FLD_flo_HPYHDCTB_DCQJ2,						   //�ϲ����2	   float			  
	ENUM_FLD_flo_HPYHDCTB_DCQJ3,						   //�ϲ����3	   float			  
	ENUM_FLD_flo_HPYHDCTB_JLQX1,                           //��������1     float
	ENUM_FLD_flo_HPYHDCTB_JLQX2,						   //��������2	   float 			  
	ENUM_FLD_flo_HPYHDCTB_JLQX3,						   //��������3	   float			  
	ENUM_FLD_flo_HPYHDCTB_JLQJ1,                           //�������1     float
	ENUM_FLD_flo_HPYHDCTB_JLQJ2,						   //�������2	   float		  
	ENUM_FLD_flo_HPYHDCTB_JLQJ3,						   //�������3	   float		  
	ENUM_FLD_str_HPYHDCTB_YFYS,							   //�շ����� 	   string		  
	ENUM_FLD_str_HPYHDCTB_HPPIMXT,                         //����ƽ����̬         string
	ENUM_FLD_str_HPYHDCTB_HPPOMXT,                         //����������̬         string
	ENUM_FLD_flo_HPYHDCTB_HPPD,                            //�����¶�             float 
	ENUM_FLD_flo_HPYHDCTB_HPPX,                            //��������             float 
	ENUM_FLD_bol_HPYHDCTB_STGH,                            //ʵ�年��             bool*
	ENUM_FLD_dou_HPYHDCTB_QYGC,                            //ǰԵ�߳�             double
	ENUM_FLD_dou_HPYHDCTB_HYGC,                            //��Ե�߳�             double 
	ENUM_FLD_dou_HPYHDCTB_HPCD,                            //���³���             double
	ENUM_FLD_dou_HPYHDCTB_HPKD,                            //���¿��             double
	ENUM_FLD_dou_HPYHDCTB_HPHD,                            //���º��             double
	ENUM_FLD_dou_HPYHDCTB_HPMJ,                            //�������             double
	ENUM_FLD_dou_HPYHDCTB_HPTJ,                            //�������             double
	ENUM_FLD_str_HPYHDCTB_GMDJ,                            //��ģ�ȼ�             string
	ENUM_FLD_lon_HPYHDCTB_SWRS,                            //��������             long
	ENUM_FLD_lon_HPYHDCTB_WXRS,                            //��в����             long
	ENUM_FLD_dou_HPYHDCTB_ZJSS,                            //ֱ����ʧ	          double
	ENUM_FLD_dou_HPYHDCTB_WXCC,                            //��в�Ʋ�	          double 
	ENUM_FLD_str_HPYHDCTB_ZQDJ,                            //����ȼ�	          string
	ENUM_FLD_str_HPYHDCTB_XQDJ,                            //����ȼ�	          string
	ENUM_FLD_str_HPYHDCTB_WXDX,                            //��в���� 	          string
	ENUM_FLD_lon_HPYHDCTB_RKHS,                            //�˿ڻ���             long
	ENUM_FLD_lon_HPYHDCTB_ETRS,                            //0-14 ����            long
	ENUM_FLD_lon_HPYHDCTB_QNRS,                            //15-59 ����           long
	ENUM_FLD_lon_HPYHDCTB_LNRS,                            //60 �꼰������        long
	ENUM_FLD_lon_HPYHDCTB_GZLXFWJ,                         //�ṹ���ͷ��ݼ�       long
	ENUM_FLD_lon_HPYHDCTB_GZLXGJGJ,	                       //�ṹ���͸ֽṹ��     long
	ENUM_FLD_lon_HPYHDCTB_GZLXGHJ, 	                       //�ṹ���͸ֻ��       long
	ENUM_FLD_lon_HPYHDCTB_GZLXZHJ, 	                       //�ṹ����ש���       long
	ENUM_FLD_lon_HPYHDCTB_GZLXZMJ, 	                       //�ṹ����שľ��       long
	ENUM_FLD_lon_HPYHDCTB_JGLXTPJ, 	                       //�ṹ����������       long
	ENUM_FLD_str_HPYHDCTB_GZLXQT,  	                       //�ṹ��������         string
	ENUM_FLD_lon_HPYHDCTB_JZYTXX,  	                       //������;ѧУ��       long
	ENUM_FLD_lon_HPYHDCTB_JZYTYY,  	                       //������;ҽԺ��       long
	ENUM_FLD_lon_HPYHDCTB_JZYTKS,  	                       //������;��ɽ��       long
	ENUM_FLD_lon_HPYHDCTB_JZYTGC,  	                       //������;������       long
	ENUM_FLD_dou_HPYHDCTB_JZYTG1,  	                       //������;��·��       double
	ENUM_FLD_dou_HPYHDCTB_JZYTT1,  	                       //������;��·��       double
	ENUM_FLD_lon_HPYHDCTB_GCSSLXSK,	                       //������ʩ���Ϳ���     long
	ENUM_FLD_lon_HPYHDCTB_GCSSLXDZ,	                       //������ʩ���͵�վ��   long
	ENUM_FLD_dou_HPYHDCTB_GCSSLXSDX,                       //������ʩ���������· double
	ENUM_FLD_dou_HPYHDCTB_GCSSLXTXX,                       //������ʩ����ͨѶ��· double
	ENUM_FLD_str_HPYHDCTB_GCSSLXQT,                        //������ʩ��������     string
	ENUM_FLD_bol_HPYHDCTB_FZCS,	                           //���δ�ʩ             bool*
	ENUM_FLD_str_HPYHDCTB_FZLX,	                           //��������             string
	ENUM_FLD_str_HPYHDCTB_FZCSJY,                          //���δ�ʩ����         string
	ENUM_FLD_bol_HPYHDCTB_YGD,	                           //ң�е�               bool*
	ENUM_FLD_bol_HPYHDCTB_KCD,	                           //�����               bool*
	ENUM_FLD_bol_HPYHDCTB_CHD,	                           //����               bool*
	ENUM_FLD_bol_HPYHDCTB_QCQFD,                           //Ⱥ��Ⱥ����           bool*
	ENUM_FLD_str_HPYHDCTB_FXDJ,	                           //���յȼ�             string
	ENUM_FLD_str_HPYHDCTB_DZGZ,	                           //���ʹ���             string
	ENUM_FLD_str_HPYHDCTB_BJTJ,	                           //�߽�����             string
	ENUM_FLD_str_HPYHDCTB_BXTZJHDLS,                       //�������������ʷ   string
	ENUM_FLD_str_HPYHDCTB_WHDX,                            //Σ������             string
	ENUM_FLD_str_HPYHDCTB_WHXMS,	                       //Σ��������           string
	ENUM_FLD_str_HPYHDCTB_BCXMS,	                       //����������           string
	ENUM_FLD_str_HPYHDCTB_SLPIMT,	                       //ʸ��ƽ��ͼ           string
	ENUM_FLD_str_HPYHDCTB_SLPOMT,	                       //ʸ������ͼ           string
	ENUM_FLD_lon_HPYHDCTB_TBSJN,	                       //���������           long
	ENUM_FLD_lon_HPYHDCTB_TBSJY,	                       //���������           long
	ENUM_FLD_lon_HPYHDCTB_TBSJR,	                       //���������           long
	ENUM_FLD_str_HPYHDCTB_TBR,		                       //�����               string
	ENUM_FLD_str_HPYHDCTB_SHR,		                       //�����               string
	ENUM_FLD_str_HPYHDCTB_DCFZR,	                       //���鸺����           string
	ENUM_FLD_lon_HPYHDCTB_RKRS,                            //�˿�����             long
};							                      
								                       

	//�������ݿ�ı���ֶζ����ʼ����
	class S3D_DIS_DBENGINE_API S3d_DisaDbTblFldDef :public DbTblFldDef
	{
	public:
		static S3d_DisaDbTblFldDef* getSingletonPtr();
	public:
		void forceInitDbMap() override;//ǿ�Ƴ�ʼ��,��s3dMdlContainer��ֵ
	};
}

#endif // !__S3D_DISADBTBLFLDDEF__
