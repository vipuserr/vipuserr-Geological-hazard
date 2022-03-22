#ifndef __S3D_DISADBDEF_H__
#define __S3D_DISADBDEF_H__


#include <string>
#include"s3d_DisaDbTblFldDef_exp.h"


using namespace std;

namespace Smart3dMap
{
	//���¼����������
	class S3D_DIS_DBENGINE_API  LandSliderHazard 
	{
	public:
		string mc ;       //����
		string tybh ;     //ͳһ���
		string xsbh ;     //���б��
		string ywbh ;     //Ұ����
		string wwxcbh ;   //���������
		string wzs ;      //ʡ
		string wzds ;     //��
		string wzx ;      //��
		string wzxz ;     //����
		string wzc ;      //��
		string wzz ;      //��
		double jd ;//����
		double wd ;//ά��
		double x ;//x����
		double y ;//y����
		string hplx ;//��������
		string dcyx ;//�ײ�����
		string xpgzlx ;//б�¹�������
		string qzmlx ;//Ǳ��������
		string mqwdzt ;//Ŀǰ�ȶ�״̬
		string ydxs ;//�˶���ʽ
		string tzfs ;//��չ��ʽ
		string hpnd ;//�������
		int sjn;//��
		int sjy;//��
		int sjr;//��
		int sjs;//ʱ
		int sjf;//��
		float ycqx1;//�Ҳ�����
		float ycqx2;
		float ycqx3;
		float ycqj1;//�Ҳ����
		float ycqj2;
		float ycqj3;
		float dcqx1;//�ϲ�����
		float dcqx2;
		float dcqx3;
		float dcqj1;//�ϲ����
		float dcqj2;
		float dcqj3;
		float jlqx1;//��������
		float jlqx2;
		float jlqx3;
		float jlqj1;//�������
		float jlqj2;
		float jlqj3;
		string yfys;
		string hppimxt;//����ƽ����̬
		string hppomxt;//����������̬
		float hppd;//�����¶�
		float hppx;//��������
		bool stgh;//ʵ�年��*
		double qygc;//ǰԵ�߳�
		double hygc;//��Ե�߳�
		double hpcd;//���³���
		double hpkd;//���¿��
		double hphd;//���º��
		double hpmj;//�������
		double hptj;//�������
		string gmdj;//��ģ�ȼ�
		long swrs;//��������
		long wxrs;//��в����
		double zjss;//ֱ����ʧ
		double wxcc;//��в�Ʋ�
		string zqdj;//����ȼ�
		string xqdj;//����ȼ�
		string wxdx;//��в����
		long rkhs;//�˿ڻ���
		long etrs;//0-14 ����
		long qnrs;//15-59 ����
		long lnrs;//60 �꼰������
		long gzlxfwj;//�ṹ���ͷ��ݼ�
		long gzlxgjgj;//�ṹ���͸ֽṹ��
		long gzlxghj;//�ṹ���͸ֻ��
		long gzlxzhj;//�ṹ����ש���
		long gzlxzmj;// �ṹ����שľ��
		long gzlxtpj;//�ṹ����������
		string gzlxqt;//�ṹ��������
		long jzytxx;//������;ѧУ
		long jzytyy;//������;ҽԺ
		long jzytks;//������;��ɽ��
		long jzytgc;//������;������
		double jzytgl;//������;��·��
		double jzyttl;//������;��·��
		long gcsslxsk;//������ʩ���Ϳ���
		long gcsslxdz;//������ʩ���͵�վ��
		double gcsslxsdx;//������ʩ���������·
		double gcsslxtxx;//������ʩ����ͨѶ��·
		string gcsslxqt;//������ʩ��������
		bool fzcs;//���δ�ʩ*
		string fzlx;//��������
		string fzcsjy;//���δ�ʩ����
		bool ygd;//ң�е�*
		bool kcd;//�����*
		bool chd;//����*
		bool qcqfd;//Ⱥ��Ⱥ����*
		string fxdj;//���յȼ�
		string dzgz;//���ʹ���
		string bjtj;//�߽�����
		string bxtzjhdls;//�������������ʷ
		string whdx;//Σ������
		string whxms;//Σ��������
		string bcxms;//����������
		string slpimt;//ʸ��ƽ��ͼ
		string slpomt;//ʸ������ͼ
		long tbsjn;//���������
		long tbsjy;//���������
		long tbsjr;//���������
		string tbr;//�����
		string shr;//�����
		string dcfzr;//���鸺����
		long rkrs;   //�˿�����
	};
}
#endif