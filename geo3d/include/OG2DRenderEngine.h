#pragma once
#include "OGMessageListener.h"
#include "OGBasDef.h"

using namespace Smart3dMap;


//using namespace Geo3D;

struct StdStratInfoDLM;
struct WellData;

struct DelaminatOper;
typedef enum RenderEngineType
{
	RE_MAPGIS = 1,
	RE_ARCGIS = 2,
	RE_LAYEROUT = 3,
	RE_MAPGISHISVIEW = 4
}RenderEngineType;


typedef struct OG_D_RECT
{
	double xmin;
	double ymin;
	double xmax;
	double ymax;
}OG_D_RECT;

//���ڲ���
typedef struct OG_WIN_ORG
{
	double  x0,y0;  //�ӿ����½�(ԭ��)
	OG_D_RECT  frc;    //��ʾ��Χ
	double  r;      //��ʾ����
}OG_WIN_ORG;

typedef struct OG_ENTITY_MSG
{
	short ai;      //������
	short type;    //ͼԪ����
	long  elmi;    //ͼԪ��
}OG_ENTITY_MSG;


typedef vector<gme_vector2d> OG_LINE;
typedef vector<gme_vector2d> OG_REG;

class CSubsectionInfo;
class OG_LIN_INFO;
class OG_REG_INFO;

class OG_FRAME_DLL C2DRendEngine :public Smart3dMap::COGListener
{
public:
	C2DRendEngine(void);
	virtual ~C2DRendEngine(void);

public:
	//��Ϣע�ắ��
	virtual void registerIntMsg(){ } //int��
	virtual void registerStrMsg(){ } //�ַ�����
	//������Ϣ����
	virtual long OnMessagePro(string msg, __int64 wParam, __int64 lParam) {return 1;} //int��
	virtual long OnMessagePro(long msg, WPARAM wParam, LPARAM lParam) {return 1;}	//�ַ�����

	//���ƴ���
	virtual void _setRenderWnd(HWND hWnd){m_hREWnd = hWnd;}
	virtual HWND _getRenderWnd() {return m_hREWnd;}

	//virtual void _setRenderCWnd(CWnd* pWnd){m_pWnd = pWnd;}
	//virtual CWnd* _getRenderCWnd() {return m_pWnd;}


	virtual void _setREType(RenderEngineType reType= RE_MAPGIS){m_lREType = reType;}
	virtual RenderEngineType _getREType(){return m_lREType;}

	//ȡ�����ƶ���
	virtual long _GetRenderObj(){return 0;}
	virtual void _DelRenderObj(long& lRenderObj){return;}

	virtual void _SetCrossCursorFlg(short flag){}
	virtual short _GetCrossCursorFlg(){return 0;}

	virtual void _SetCommandFlag(long cmdFlg){}  //1.����cmdFlg,2.������ڲ���״̬,3.�ָ���ꡣ
	virtual long _GetCommandFlag(void){return 0;}

	//�����Ĵ��ڲ����ӿ�
	virtual void _OnDraw(){} //����
	virtual void _OpenWindow(){};	//�������Ŵ�
	virtual void _ReduceWindow(){};	//��С
	virtual void _MoveWindow(){};	//�ƶ�
	virtual void _PrevWindow(){};	//��(ǰ)������
	virtual void _PostWindow(){};//��һ��ͼ����
	virtual void _AlwayOpenWindow(){};//�̶������Ŵ�
	virtual void _AlwayReduceWindow(){};//�̶�������С
	virtual void _CenterAlig(){};//���ж���
	virtual void _SelectFeature(){};//ѡ��Ҫ��
	virtual void _Pick(){};//ʶ��
	virtual void _RestoreWindow(){};	//��λ����
	virtual void _UpdateWindow(){};	//���´���
	virtual void _CleanWindow(){};	//�崰��
	virtual void _2dViewParam(){};	//ȡ���ڲ���
	virtual void _CleanLayer(short lyrPtr){};//���ͼ������
	//�޸ı�����ɫ
	virtual void _EditWndBkFace(long lR, long lG,long lB) {}

	virtual double _GetMaxDispRate(void) {return 0;}	    //ȡ�����ʾ����,��=0��ʾ��û����������
	virtual double _GetMinDispRate(void) {return 0;}	    //ȡ��С��ʾ����,��=0��ʾ��û������С����
	virtual double _SetMaxDispRate(double rate) {return 0;}  //���������ʾ����,�����ϴ����õ�������(>0)
	virtual double _SetMinDispRate(double rate) {return 0;}  //������С��ʾ����,�����ϴ����õ���С����(>0)

public:
	//�豸����(�������½�Ϊԭ�㣬��������ϵ)--->�߼�����(ͼ������)����������
	virtual short _DpToLp(gme_vector2d *xy0, gme_vector2d *xy1) {return 0;}	//xy1���Ե���xy0��
	virtual short _DpToLp(double x0, double y0, double *x1,double *y1) {return 0;}
	virtual short _DpToLp(long  x0, long  y0, double *x1,double *y1) {return 0;}
	virtual short _DpToLp(long  x0, long  y0, gme_vector2d *xy1) {return 0;}
	//virtual short _DpToLp(CPoint *xy0, double *x1,double *y1) {return 0;}

	//virtual short _DpToWp(gme_vector2d *xy0, CPoint *xy1) {return 0;}
	//virtual short _DpToWp(long x0,long y0, CPoint *xy1) {return 0;}
	//virtual short _DpToWp(CPoint *xy0, CPoint *xy1) {return 0;}
	//�߼�����(��ͼ�����꣬���½�Ϊԭ�㣬��������ϵ)--->�豸���ꡢ��������
	virtual short _LpToDp(gme_vector2d *xy0, gme_vector2d *xy1) {return 0;}
	//virtual short _LpToDp(gme_vector2d *xy0,CPoint *xy1) {return 0;}		    //���ڰ汾Ϊ_FactXY_WinXY1
	virtual short _LpToDp(gme_vector2d *xy0, double *x1, double *y1) {return 0;}
	virtual short _LpToDp(gme_vector2d *xy0, long  *x1, long  *y1) {return 0;}
	virtual short _LpToDp(double x0,double y0, double *x1, double *y1) {return 0;}
	virtual short _LpToDp(double x0,double y0, long  *x1, long  *y1) {return 0;} //���ڰ汾Ϊ_FactXY_WinXY
	//virtual short _LpToDp(double x0,double y0, CPoint *xy1) {return 0;}

	virtual short _LpToWp(double x0,double y0,long *x1,long *y1) {return 0;}
	//virtual short _LpToWp(gme_vector2d *xy0,CPoint *xy1) {return 0;}
	virtual short _LpToWp(gme_vector2d *xy0,double *x1,double *y1) {return 0;}
	virtual short _LpToWp(gme_vector2d *xy0, long * x1, long * y1) {return 0;}
	//virtual short _LpToWp(double x0,double y0,CPoint *xy1) {return 0;}
	//��������(���Ͻ�Ϊԭ�㣬��������ϵ)--->�豸���ꡢ�߼�����
	//virtual short _WpToDp(CPoint *xy0, CPoint *xy1) {return 0;}
	//virtual short _WpToDp(CPoint *xy0, gme_vector2d  *xy1) {return 0;}
	//virtual short _WpToLp(CPoint *xy0, gme_vector2d  *xy1) {return 0;}	    //���ڰ汾Ϊ_WinXY_FactXY1
	virtual short _WpToLp(long x0,long y0,double *x1,double *y1) {return 0;} //���ڰ汾Ϊ_WinXY_FactXY
	//virtual short _WpToLp(CPoint *xy0, double *x1,double *y1) {return 0;}
	//virtual short _WpToDp(long x0,long y0, CPoint *xy1) {return 0;}

	//��Χ�����ӿ�
	//ȡ������ͼ�η�Χ
	virtual short _GetWinMapRange(OG_D_RECT *frc){return 0;}
	virtual short _SetWinMapRange(OG_D_RECT *frc){return 0;}
	//ȡ��������ʾ��Χ
	virtual short _GetWinDispRect(OG_D_RECT *frc){return 0;}
	virtual short _SetWinDispRect(OG_D_RECT *frc){return 0;}
	//ȡ�������Ӵ��ڲ���
	virtual short  _GetWinDispParam(OG_WIN_ORG *wxy){return 0;}
	virtual short  _SetWinDispParam(OG_WIN_ORG *wxy){return 0;}
	virtual short  _SetWinDispRate(double rate){return 0;}
	virtual double _GetWinDispRate(void){return 0;}

	//ͼ�Ρ�ͼ��������ʾ
	virtual long _GetRectToRect(OG_D_RECT rect1,OG_D_RECT& rect2){return 1;}

	virtual long _LoadSubGraph(BOOL bReLoad /*= FALSE*/,CSubsectionInfo*	m_pRESecInfo){return 0;}
	virtual long _LoadSubGraph(BOOL bReLoad /*= FALSE*/,CSubsectionInfo*	m_pRESecInfo,char* NoteString){return 0;}
	virtual void _ClearSubGraph(){}
	
	virtual void _DrawOneVecLayer(string strURL,short& VecPtr) {return ;}
	virtual void _DrawOneVecLayer(long lLayerPtr,short& VecPtr) {return ;}
	virtual void _SetOneVecLayerRation(long lLayerPtr,short& VecPtr,double& MaxRation,double& MinRation) {return ;}
	virtual void _GetVecLayerRect(OG_D_RECT* p_rect,short& VecPtr){}

	virtual void _DrawOneRasLayer(string strURL,long& RasPtr) {return ;}
	virtual void _DrawOneRasLayer(long lLayerPtr,long& RasPtr) {return ;}
	virtual void _GetRasterLayerRect(OG_D_RECT* p_rect,long& RasPtr){}

	virtual void _DrawOnMap(string strURL ,long& mapPtr) {return ;}
	virtual void _DrawOnLayer(long lMapPtr,long& mapPtr) {return ;}
	virtual void _SetOneMapLayerRation(long lLayerPtr,long& mapPtr,double& MaxRation,double& MinRation) {return ;}
	virtual void _GetVecMapRect(OG_D_RECT* p_rect,long& mapPtr){}

	//�ڴ�������ʾ
	virtual void _DrawDotsLayer(vecSubSingOGDot* pDots, long lDotParaPtr,OG_D_RECT& lRect,CSubsectionInfo*	m_pRESecInfo){return ;}
	virtual	void _DrawLinsLayer(vector<vecSubSingOGDot>*, long lLinParaPtr,OG_D_RECT& lRect,vector<OG_LIN_INFO*>m_pRELineInfo){return ;}
	virtual	void _DrawRegsLayer(vector<vecSubSingOGDot>*, long lRegParaPtr,OG_D_RECT& lRect,vector<OG_REG_INFO*>m_pRERegInfo){return ;}

	virtual void _DrawLinsLayer(vecSubSingOGDot* pLins, long lLinParaPtr){return ;}
	virtual void _DrawRegsLayer(vecSubSingOGDot* pRegs, long lRegParaPtr){return ;}

	//�ڴ�������ʾ
	virtual void _DrawDotsLayer(vecSubSingOGDot* pDots, long& lDotParaPtr){return ;}


	virtual short _StopFlash(short type){return 0;}	    //type=-1/PNT/LIN/REG/NOD,�ֱ��ʾֹͣȫ����˸/ֹͣ��˸��/ֹͣ��˸��/ֹͣ��˸��/ֹͣ��˸���
	virtual short _StartFlash(short ai,long *ptNo, long num, short type){return 0;}; //��ʼ(����)��˸ĳ��ͼԪ
	virtual short _StartFlash(OG_ENTITY_MSG *pt, long num){return 0;};	 //��ʼ(����)��˸ͼԪ

	///���к���������˸ͼԪ����ʼ��˸, ���滻������˸��ͬ��ͼԪ
	virtual short _FlashPnt(short ai, long *ptNo, long num){return 0;}//����(��ʼ)��˸��ͼԪ��ptNo[0]��ptNo[num-1]ΪͼԪ��
	virtual short _FlashLin(short ai, long *ptNo, long num){return 0;} //����(��ʼ)��˸��ͼԪ��ptNo[0]��ptNo[num-1]ΪͼԪ��
	virtual short _FlashReg(short ai, long *ptNo, long num){return 0;} //����(��ʼ)��˸��ͼԪ��ptNo[0]��ptNo[num-1]ΪͼԪ��
	virtual short _FlashNod(short ai, long *ptNo, long num){return 0;} //����(��ʼ)��˸���ͼԪ��ptNo[0]��ptNo[num-1]ΪͼԪ��
	virtual short _FlashDot(gme_vector2d *ptXY, long num){return 0;}          //����(��ʼ)��˸����㣬  ptXY[0]��ptXY[num-1]Ϊ������ֵ

	virtual void  _DrawXORLine(long x0,long y0,long x1,long y1){return;};
	virtual	short _AppendFlashDot(gme_vector2d *ptxy, long num){return 0;};          //�����˸����㣬  ptXY[0]��ptXY[num-1]Ϊ������ֵ
	virtual void  _DrawXORRect(long x0,long y0,long x1,long y1){return;};
	virtual void _GetOGRange(short ai,OG_D_RECT *rect){return;};

	//virtual void OnCreate(CWnd* parentWnd, int cx, int cy, int wid, int hei){} //
	virtual void OnSize(UINT nType, int cx, int cy){}
	virtual void OnTimer(UINT nIDEvent){}
	virtual void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags){}
	/*virtual void OnLButtonDown(UINT nFlags, CPoint point){}
	virtual void OnLButtonUp(UINT nFlags, CPoint point){}
	virtual void OnMouseMove(UINT nFlags, CPoint point){}
	virtual void OnRButtonDown(UINT nFlags, CPoint point){}
	virtual void OnRButtonUp(UINT nFlags, CPoint point){}
	virtual void OnLButtonDblClick(UINT nFlags, CPoint point){}
	virtual void OnRButtonDblClick(UINT nFlags, CPoint point){}
	virtual void OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags){}
	virtual BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint point){return TRUE;}*/

	//  [3/9/2015 Feng]
	virtual void _DrawOnWebLayer(string strURL ,long& webPtr){return ;}
	virtual void _DrawOnWebLayer(long lLayerPtr,long& webPtr){return ;}
	virtual void _GetWebLayerRect(OG_D_RECT* p_rect,long& webPtr){return ;}

	virtual void _DrawOnMosaicLayer(string strURL,long& MosaicPtr){return ;}
	virtual void _DrawOnMosaicLayer(long lLayerPtr,long& MosaicPtr){return ;}
	virtual void _GetMosaicLayerRect(OG_D_RECT* p_rect,long& MosaicPtr){return ;}

	virtual short CreateHistogram(){return 0;}
	virtual BOOL OpenHistm(char* szFileName,double	dStaDepth=0,double dEndDepth=0){return true;}
	virtual long CreateTblHead(){return 0;}
	virtual long CreateTblTail(){return 0;}
	virtual void SaveHistm(){return ;}
	//�ر���״ͼ
	virtual void	CloseHistm(){return ;}
	virtual BOOL	SaveToGisFile(char* strParthName=NULL){return true;}
	//����ѡ��m_pSelTraceͼ������,��ͼ���Լ����Ի���
	virtual void SetTraceParam(){return;}
	//ȡ����ǰ�ϲ�
	virtual void DisUnite(){return;}
	//�����
	virtual void UnionLeft(){return;}

	virtual void	UnionRight(){return;}

	//ɾ��ѡ��ͼ��-��ѡ
	virtual void DeleteSelTraces(){return;}

	//��������ҳ����Ϣ
	virtual void SetPageParam(){return;}

	//����ͼ��
	//˵��:���öԻ���,�ٵ������溯��ʵ��
	virtual void InsertTrace(){return;}

	//���ѡ��ͼ������	
	virtual BOOL  ClearTraceDat(){return TRUE;}

	//�����������==================================
	virtual void	SetUnionParam(){return;}

	//�޸ı�ͷ��β��Ԫ������
	virtual void OnPopGridPro(){return;}

	virtual void OnPoptraceAdjData() {return;}

	virtual void OnPopLayProperty() {return;}

	virtual void OnPopLayDelLay(){return;}

	virtual void OnPopLayNextMerge(){return;}

	virtual void OnPopLayPreMerge(){return;}

	virtual void OnPopTextPro(){return;}

	virtual void OnPopGridAverWidth(){return;}

	virtual void OnPopGridDelGrid(){return;}

	virtual void OnPopGridDelRow(){return;}

	virtual void OnPopGridSplit(){return;}

	virtual void OnPopGridInsertRow(){return;}

	virtual void OnPopTextgridDel(){return;}

	virtual void OnPopTextgridPro(){return;}

	virtual void OnPopSetgridborder(){return;}

	virtual void OnPopSetgridrow(){return;}

	virtual void OnPopSetgridtext(){return;}

	virtual void OnPoptraceSetdelam(){return;}
	
	//test,���ý��ͷֲ�״̬,һ��Ӧ�����ڼ�������֮������,
	//���ڲ���,������SetDelamination(); �� AutoAddTraceBind();
	//���Ұѽ��ͷֲ��׼����BasFrmView
	virtual void SetDelaminationAuto(){return;}
	
	//����-��ǰ�ֲ��׼�µı�׼�ֲ�--
	virtual void SetStdStratInfo(std::vector<StdStratInfoDLM> *pStdStratList){return;}
	
	//����-��ǰ��״ͼ��ʵ�ʵز�
	virtual void SetStratInfo(std::vector<StdStratInfoDLM> *pStratList){return;}
	
	//�����״ͼͼ������������
	virtual void	CleanAllTraceData(){return;}
	
	//��ȡרҵ����
	virtual long	GetHistmProType(){return 0;}
	
	//��ȡ��ͼ����
	virtual double	GetScale(){return 0;}
	
	//������״ͼ��ʼ����ֹ��Ⱥͱ���
	//dStaDepth	in	��״ͼ��ʼ����趨ֵ
	//dEndDepth	in	��״ͼ��ֹ����趨ֵ,��С�ڵ���0,���޸�ԭ����趨
	virtual void SetPageDepth(double	dStaDepth=0,double dEndDepth=0,double dScale =0){return;}
	
	//ȡ��ͼ����Ŀ
	virtual long GetTraceNum(){return 0;}
	
	//��ȡ��ͷ/β��������Ԫ������
	virtual long	GetHeadGridNum(){return 0;}
	virtual long	GetTailGridNum(){return 0;}
	//����������ȡ��Ԫ��Mac��,
	//���:	Idx			������
	//����:	lGridMac	���ص�Ԫ��ĺ�
	//����:�ɹ�1,����0
	virtual long	GetHeadGridMac(long Idx,long& lGridMac){return 0;}
	virtual long	GetTailGridMac(long Idx,long& lGridMac){return 0;}
	//�����������õ�Ԫ�����
	virtual void	SetHeadGridTitle(long Idx,char* strTitle){return ;}
	virtual void	SetTailGridTitle(long Idx,char* strTitle){return ;}
	
	virtual long	GetTraceType(long lIndex){return 0;}
	
	//��ȡͼ����ID,���Ƶ���Ϣ=========================================================
	//˵��:ͼ�����ָ��״ͼ������,���ϵ��µ�˳��,��0��ʼ��ͼ�����,����ͬ
	//����:	lIndex			in	ͼ�����
	//		lTraceMac		out	ͼ��ID,	ʧ�ܷ���-1
	//		strTraceTitle	out	ͼ������,ʧ�ܷ���Null
	virtual void	GetTraceInfo(long	lIndex,long &lTraceMac,char* strTraceTitle=NULL){return ;}
	
	//��������==========================================================
	//����˵��: lIndex	in	ͼ����������,����������,��0��ʼ
	//pFirData		in	��һ������ָ��
	//pFirData		in	��һ�����ݳ���
	//pSecData		in	�ڶ�������ָ��
	//pSecData		in	�ڶ������ݳ���
	//lFlag=0		in	������־λ
	virtual void	SetTraceData(long	lIndex,
						WellData* pFirData, 
						long	lFstDatelen,
						WellData* pSecData=NULL,
						long	lSecDatalen=0,
						long	lFlag=0){return ;}
						
/*----COM ר�ú���,��ʹ�ô�����غ���,��û�д��ڵ�����´���״ͼ,ת����״ͼ��MapGis����
 *������״ͼ�ȹ���.-------------------------------*/
	//����״ͼ
	//szFileName in ����������·��,�ļ���,�ͺ�׺��
	//dStaDepth	in	��״ͼ��ʼ����趨ֵ
	//dEndDepth	in	��״ͼ��ֹ����趨ֵ,��С�ڵ���0,���޸�ԭ�ļ��ڵ�����趨
	//���أ��ɹ�1,ʧ��0
	virtual BOOL ComOpenHistm(char* szFileName,double	dStaDepth=0,double dEndDepth=0){return 0;}
	
	//������״ͼ��ʼ����ֹ���--ԭComSetPageDepth()�޸�
	//dStaDepth	in	��״ͼ��ʼ����趨ֵ
	//dEndDepth	in	��״ͼ��ֹ����趨ֵ,��С�ڵ���0,���޸�ԭ����趨
	virtual void ComSetPageDepth(double	dStaDepth,double dEndDepth,double dScale){return ;}
//------COM ר�ú���----------------------------------------------------------------------//

	//���ݺ��ȡͼ�����ݣ��ڻ�ȡ���ͷֲ������ı�ʱʹ�ã�
	//˵��:;�ڴ���ͼ��������ͷ�
	//����:	lMac		in  ͼ����
	//		pData		out	��������;
	//		DataLength	out	pWellData���鳤��;
	//����:�ɹ�����1,���򷵻�0; 
	virtual bool GetTraceDataByMac(long lMac,WellData* &pWellData,long &lDataLen){return 0;}
	
	//��ȡ�������м�����,�ڴ����ڲ��Զ��ͷ�
	virtual bool GetDelamOper(DelaminatOper* &pDelamOper,long &lDelamOperLen){return 0;}

	virtual void SetHoleTile(string str_holeTitle){return ;}
	virtual	void SaveAsHistm(char* szFileName,long	lFlag = 1){return ;}

	virtual short		GetAreaInst(){return 0;}
	virtual short		SetEditArea(short ai){return 0;}
	virtual short		GetEditArea(short aitype){return 0;}
	virtual short		ClearEditArea(short aitype){return 0;}


	virtual long _GetProject(){return 0;}
	virtual long _SetProject(long new_prj){return 0;}
	virtual long _ClearProject(){return 0;}

	virtual void CloseArea(short& pAI){}
	virtual void PRJDeleteProject(long& prj){}
	virtual void CloseRasterArea(long& rasterAi){}

	virtual char _SetOriginalDispFlag(char flag){return 1;} //��ԭ��ʾ

private:
	HWND m_hREWnd;
	//CWnd*	m_pWnd;
	RenderEngineType m_lREType;
};
