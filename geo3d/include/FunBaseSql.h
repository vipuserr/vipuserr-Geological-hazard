#pragma once
//函数名对应的Sql

#include <string>
#include <map>

using namespace std;

map<string, string> baseSql =
{
	

	

	

	
	
	// TODO: 迁移至数据管理器类内部 -- LH.2021.08.11 10:05 written.
	

	pair<string, string>("getHoleInclinatCount", "select count(*) from HoleInclinat"),
	pair<string,string>("getHoleInclinat","select HoleInclinat.HoleID, HoleInclinat.MeasureDepth, HoleInclinat.AzimuthAngle, HoleInclinat.DipAngle from HoleInclinat"),

	pair<string, string>("getHoleLoggingCount", "select count(*) from HoleLogging"),
	pair<string,string>("getHoleLogging","select HoleLogging.LoggingID, HoleLogging.HoleID, HoleLogging.DeviceName, HoleLogging.DeviceType, HoleLogging.StartDepth, HoleLogging.EndDepth, HoleLogging.SampleGap, HoleLogging.LoggingDoc, HoleLogging.TKALD, HoleLogging._Operator, HoleLogging.DetectDate, HoleLogging.Inputer, HoleLogging.InputOrgn, HoleLogging.InputDate from HoleLogging"),
	//-------------------------------------------------------------
	/*------------------------------------------虚拟钻孔st---------------------------------------------*/
	pair<string, string>("getStdStrat_VHoleCount", "select count(*) from StdStrat_VHole"),
	pair<string,string>("getStdStrat_VHole","select StdStrat_VHole.VIRHOLEID, StdStrat_VHole.VIRHOLENO, StdStrat_VHole.X, StdStrat_VHole.Y, StdStrat_VHole.Z, StdStrat_VHole.VIRHOLEDEPTH, StdStrat_VHole.PlaneCoordSys, StdStrat_VHole.InputOrgn, StdStrat_VHole.Inputer, StdStrat_VHole.InputDate from StdStrat_VHole"),

	pair<string, string>("getStdStrat_VHolelLayerCount", "select count(*) from StdStrat_VHolelLayer"),
	pair<string,string>("getStdStrat_VHolelLayer","select StdStrat_VHolelLayer.VIRHOLELAYERID, StdStrat_VHolelLayer.VIRHOLEID, StdStrat_VHolelLayer.VIRHOLENO, StdStrat_VHolelLayer.LAYERNO, StdStrat_VHolelLayer.VIRLAYERCODE, StdStrat_VHolelLayer.GEOCODE, StdStrat_VHolelLayer.DDCDIA, StdStrat_VHolelLayer.CauseType, StdStrat_VHolelLayer.YSEB, StdStrat_VHolelLayer.LayerDepth, StdStrat_VHolelLayer.LayerThick, StdStrat_VHolelLayer.YSHB, StdStrat_VHolelLayer.EngTrait, StdStrat_VHolelLayer.WateryTrait, StdStrat_VHolelLayer.GCKLT, StdStrat_VHolelLayer.LAYERID, StdStrat_VHolelLayer.LAYERTOPDEPTH, StdStrat_VHolelLayer.BOTTOMDEPTH, StdStrat_VHolelLayer.TOPELEVATION, StdStrat_VHolelLayer.FieldLayerNum, StdStrat_VHolelLayer.HOLECODE, StdStrat_VHolelLayer.PrjCode from StdStrat_VHolelLayer"),
	/*------------------------------------------- 浅井探槽类--------------------------------------*/
	pair<string, string>("getHoleWellSlotCount", "select count(*) from HoleWellSlot"),
	pair<string,string>("getHoleWellSlot","select HoleWellSlot.WellSlotID, HoleWellSlot.PntID, HoleWellSlot.GCEABC, HoleWellSlot.SWBCBC, HoleWellSlot.ExploreType, HoleWellSlot.ExploreDepth, HoleWellSlot.GCJDBN, HoleWellSlot.SWEGAB, HoleWellSlot.GCKBBA, HoleWellSlot.GeoCondit, HoleWellSlot.HydroCondit, HoleWellSlot.EngCondit, HoleWellSlot.HJY, HoleWellSlot.EcoEnvCondit, HoleWellSlot.GCIAEB, HoleWellSlot.SWDCG, HoleWellSlot.TKALD, HoleWellSlot.Technician, HoleWellSlot.DetectDate, HoleWellSlot.InputOrgn, HoleWellSlot.Inputer, HoleWellSlot.InputDate, HoleWellSlot.SWLBAB, HoleWellSlot.SWLBAA, HoleWellSlot.ScenePhoto, HoleWellSlot.ConstructRecord, HoleWellSlot._Memo from HoleWellSlot"),

	pair<string, string>("getHoleWellSlotLayerCount", "select count(*) from HoleWellSlotLayer"),
	pair<string,string>("getHoleWellSlotLayer","select HoleWellSlotLayer.WallSlotLayerID, HoleWellSlotLayer.FieldLayerNo, HoleWellSlotLayer.WellSlotID, HoleWellSlotLayer.GCEABC, HoleWellSlotLayer.PrjCode, HoleWellSlotLayer.DetectID, HoleWellSlotLayer.DetectNo, HoleWellSlotLayer.GeoCode, HoleWellSlotLayer.DDCDIA, HoleWellSlotLayer.CauseType, HoleWellSlotLayer.TopDepth, HoleWellSlotLayer.BottomDepth, HoleWellSlotLayer.TopElevation, HoleWellSlotLayer.BottomElevation, HoleWellSlotLayer.LayerThick, HoleWellSlotLayer.YSEB, HoleWellSlotLayer.YSHB, HoleWellSlotLayer.EngTrait, HoleWellSlotLayer.WateryTrait, HoleWellSlotLayer.GCKLT from HoleWellSlotLayer"),

	pair<string, string>("getHoleDetectCount", "select count(*) from HoleDetect"),
	pair<string,string>("getHoleDetect","select HoleDetect.DetectID, HoleDetect.DetectNo, HoleDetect.WellSlotID, HoleDetect.GCEABC, HoleDetect.PrjCode, HoleDetect.Distance, HoleDetect.Orientation from HoleDetect"),
	/*----------------------------------------物探点线类--------------------------------*/
	pair<string, string>("getPhyLineCount", "select count(*) from PhyLine"),
	pair<string,string>("getPhyLine","select PhyLine.LineID, PhyLine.LineCode, PhyLine.PrjID, PhyLine.DetectMethod, PhyLine.TKALD, PhyLine._Operator, PhyLine.Checker, PhyLine.StartDate, PhyLine.EndDate, PhyLine.OrigDocID, PhyLine.DrrorDocID, PhyLine.ParaDocID, PhyLine.resultDocID, PhyLine.Inputer, PhyLine.InputOrgn, PhyLine.InputDate from PhyLine"),

	pair<string, string>("getPhyEleclineCount", "select count(*) from PhyElecline"),
	pair<string,string>("getPhyElecline","select PhyElecline.EleclineID, PhyElecline.LineID, PhyElecline.LineCode, PhyElecline.DotPitch, PhyElecline.DetedotCount, PhyElecline.DetelineLength, PhyElecline.DatelineOrient, PhyElecline._Device, PhyElecline.DeviceType, PhyElecline.RecdisDist, PhyElecline._Frequency, PhyElecline.LaunchBoxArea, PhyElecline.RecboxArea, PhyElecline.AntennaFre, PhyElecline.AntennaDist from PhyElecline"),

	pair<string, string>("getPhyEardetelineCount", "select count(*) from PhyEardeteline"),
	pair<string,string>("getPhyEardeteline","select PhyEardeteline.EardetelineID, PhyEardeteline.LineID, PhyEardeteline.LineCode, PhyEardeteline.RoadDist, PhyEardeteline.RecTime, PhyEardeteline.FlipcoverTime, PhyEardeteline.SampleGap, PhyEardeteline.RecordLength, PhyEardeteline.BombDist, PhyEardeteline.DffsetDist, PhyEardeteline.RecuLength, PhyEardeteline.TriangleMaxlen from PhyEardeteline"),

	pair<string, string>("getPhyMeasPntCount", "select count(*) from PhyMeasPnt"),
	pair<string,string>("getPhyMeasPnt","select PhyMeasPnt.MeasPntID, PhyMeasPnt.PntNo, PhyMeasPnt.LineID, PhyMeasPnt.LineCode, PhyMeasPnt.Longitude, PhyMeasPnt.Latitude, PhyMeasPnt.TKCAF, PhyMeasPnt.TKCAG, PhyMeasPnt.GCJCBJ, PhyMeasPnt.PlaneCoordSys, PhyMeasPnt.EleDatum from PhyMeasPnt"),

	pair<string, string>("getPhyStdPntCount", "select count(*) from PhyStdPnt"),
	pair<string,string>("getPhyStdPnt","select PhyStdPnt.StdPntID, PhyStdPnt.MeasPntID, PhyStdPnt.PntNo, PhyStdPnt.PrjCode, PhyStdPnt.STKCAF, PhyStdPnt.STKCAG, PhyStdPnt.SGCJCBJ, PhyStdPnt.StdPlaneCoordSys, PhyStdPnt.stdElDatum from PhyStdPnt"),
	/*----------------------------------------钻孔分层类-----------------------------------*/
	pair<string, string>("getHoleOrigLayerCount", "select count(*) from HoleOrigLayer"),
	pair<string,string>("getHoleOrigLayer","select HoleOrigLayer.FieldLayerID, HoleOrigLayer.FieldLayerNum, HoleOrigLayer.HoleID, HoleOrigLayer.GeoCode, HoleOrigLayer.DDCDIA, HoleOrigLayer.CauseType, HoleOrigLayer.TopDepth, HoleOrigLayer.BottomDepth, HoleOrigLayer.TopElevation, HoleOrigLayer.BottomElevation, HoleOrigLayer.LayerThick, HoleOrigLayer.YSEB, HoleOrigLayer.YSHB, HoleOrigLayer.EngTrait, HoleOrigLayer.WateryTrait, HoleOrigLayer.GCKLT from HoleOrigLayer"),
	/*----------------------------------------钻孔结构类-----------------------------------*/
	pair<string, string>("getHoleWaterSealCount", "select count(*) from HoleWaterSeal"),
	pair<string,string>("getHoleWaterSeal","select HoleWaterSeal.WaterSealID, HoleWaterSeal.HoleID, HoleWaterSeal.SWCEA, HoleWaterSeal.SWCEB, HoleWaterSeal.SealingMaterial from HoleWaterSeal"),

	pair<string, string>("getHoleGravelPackCount", "select count(*) from HoleGravelPack"),
	pair<string,string>("getHoleGravelPack","select HoleGravelPack.GravelPackID, HoleGravelPack.HoleID, HoleGravelPack.SWCDH, HoleGravelPack.SWCGBD, HoleGravelPack.SWCGBC, HoleGravelPack.SWCDF, HoleGravelPack.GravelSpecify from HoleGravelPack"),

	pair<string, string>("getHoleWellPipeCount", "select count(*) from HoleWellPipe"),
	pair<string,string>("getHoleWellPipe","select HoleWellPipe.WellPipeID, HoleWellPipe.HoleID, HoleWellPipe.TKACE, HoleWellPipe.HoleTopDiam, HoleWellPipe.SWCCB, HoleWellPipe.WellPipeMaterial from HoleWellPipe"),

	pair<string, string>("getHoleApertureCount", "select count(*) from HoleAperture"),
	pair<string,string>("getHoleAperture","select HoleAperture.ApertureID, HoleAperture.HoleID, HoleAperture.TKACE, HoleAperture.SWCL from HoleAperture"),

	//-------------------------------------------------------------

	
	
	//钻孔分层表 * -- LH.2021.08.05 13:51 updated.
	pair<string, string>("getHoleLayerCount", "select count(*) from HoleLayer"),
	pair<string,string>("getHoleLayer","select HoleLayer.HoleID, HoleLayer.StdStratID, HoleLayer.StratCode, HoleLayer.StratName, HoleLayer.TopDepth, HoleLayer.BtmDepth, HoleLayer.GCKLT, HoleLayer.DDCDIA, HoleLayer.GCKUPE, HoleLayer.GeoCode, HoleLayer.YSEB, HoleLayer.YSHB, HoleLayer.EngTrait, HoleLayer.WateryTrait, HoleLayer.FieldLayerID, HoleLayer.FieldLayerNum, hole_stdStratDesc.StratOrder, hole_stdStratDesc.StratClr from HoleLayer, hole_stdStratDesc where HoleLayer.StratCode=hole_stdStratDesc.StratCode"),
	
	
	

	/*----------------------------------------现场力学试验（原位测试）类-----------------------------------*/
	//原位测试基本情况表 * -- LH.2021.08.05 14:17 updated.
	
	//标准贯入试验记录表 -- LH.2021.08.07 16:28 updated.
	
};
