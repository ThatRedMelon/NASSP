// ==============================================================
//                 ORBITER MODULE: DialogTemplate
//                  Part of the ORBITER SDK
//            Copyright (C) 2003 Martin Schweiger
//                   All rights reserved
//
// ApolloRTCCMFDe.h
//
// This module demonstrates how to build an Orbiter plugin which
// inserts a new MFD (multi-functional display) mode. The code
// is not very useful in itself, but it can be used as a starting
// point for your own MFD developments.
// ==============================================================

#ifndef __ApolloRTCCMFD_H
#define __ApolloRTCCMFD_H

#include "ARCore.h"
#include "soundlib.h"
#include "apolloguidance.h"
#include "csmcomputer.h"
#include "lemcomputer.h"
#include "saturn.h"
#include "saturnv.h"
#include "LEM.h"

class ApolloRTCCMFD: public MFD2 {
public:
	ApolloRTCCMFD (DWORD w, DWORD h, VESSEL *vessel, UINT im);
	~ApolloRTCCMFD ();
	char *ButtonLabel (int bt);
	int ButtonMenu (const MFDBUTTONMENU **menu) const;
	bool Update (oapi::Sketchpad *skp);
	bool ConsumeButton(int bt, int event);
	bool ConsumeKeyBuffered(DWORD key);
	void WriteStatus(FILEHANDLE scn) const;
	void ReadStatus(FILEHANDLE scn);
	void StoreStatus(void) const;
	void RecallStatus(void);

	bool Text(oapi::Sketchpad *skp, int x, int y, const std::string & str);

	void menuTIChaserVectorTime();
	void set_TIChaserVectorTime(double get);
	void menuTITargetVectorTime();
	void set_TITargetVectorTime(double get);
	void t1dialogue();
	void set_t1(double t1);
	void t2dialogue();
	void set_t2(double t2);
	void menuCycleK30Vehicle();
	void SPQtimedialogue();
	void set_SPQtime(double tig);
	void menuSetSPQChaserThresholdTime();
	void set_SPQChaserThresholdTime(double get);
	void menuSetSPQTargetThresholdTime();
	void set_SPQTargetThresholdTime(double get);
	void DKIDHdialogue();
	void set_DKIDH(double DH);
	void SPQDHdialogue();
	void set_SPQDH(double DH);
	void set_target();
	void menuVoid();
	void menuSetLambertPage();
	void menuSetSPQPage();
	void menuSetTIMultipleSolutionPage();
	void menuSetREFSMMATPage();
	void menuSetEntryPage();
	void menuSetAGSSVPage();
	void menuSetMenu();
	void menuSetConfigPage();
	void menuSetOrbAdjPage();
	void menuSetMapUpdatePage();
	void REFSMMATTimeDialogue();
	void set_REFSMMATTime(double time);
	void menuREFSMMATLockerMovement();
	void cycleREFSMMATHeadsUp();
	void calcREFSMMAT();
	void GMPInput1Dialogue();
	void set_GMPInput1(double val);
	void GMPInput2Dialogue();
	void set_GMPInput2(double val);
	void GMPInput3Dialogue();
	void set_GMPInput3(double val);
	void GMPInput4Dialogue();
	void set_GMPInput4(double val);
	void OrbAdjGETDialogue();
	void set_OrbAdjGET(double SPSGET);
	void OrbAdjRevDialogue();
	void set_OrbAdjRevs(int N);
	void GPMPCalc();
	void menuCycleGMPManeuverVehicle();
	void menuCycleGMPManeuverPoint();
	void menuCycleGMPManeuverType();
	void menuCycleGMPMarkerUp();
	void menuCycleGMPMarkerDown();
	void menuSetGMPInput();
	void menuCycleOrbAdjAltRef();
	void menuMissionNumberInput();
	void set_MissionNumber(int mission);
	void SPQcalc();
	void lambertcalc();
	void Angle_Display(char *Buff, double angle, bool DispPlus = true);
	void GET_Display(char * Buff, double time, bool DispGET = true);
	void GET_Display2(char * Buff, double time);
	void GET_Display3(char* Buff, double time);
	void GET_Display4(char* Buff, double time);
	void GET_Display_HHMM(char *Buff, double time);
	void AGC_Display(char * Buff, double time);
	void REFSMMATName(char* Buff, int n);
	void ThrusterName(char *Buff, int n);
	bool ThrusterType(std::string name, int &id);
	void MPTAttitudeName(char *Buff, int n);
	void SStoHHMMSS(double time, int &hours, int &minutes, double &seconds);
	double timetoperi();
	double timetoapo();
	void CycleREFSMMATopt();
	void UploadREFSMMAT();
	void menuIUUplink();
	void menuP30Uplink();
	void menuP30UplinkCalc();
	void menuRetrofireEXDVUplink();
	void menuRetrofireEXDVUplinkCalc();
	void EntryAngDialogue();
	void set_entryang(double ang);
	void EntryTimeDialogue();
	void set_EntryTime(double time);
	void set_entrylat(double lat);
	void EntryLatDialogue();
	void set_entrylng(double lng);
	void EntryLngDialogue();
	void menuSetEntryDesiredInclination();
	void set_EntryDesiredInclination(double inc);
	void menuSetRTEConstraintF86();
	void set_RTEConstraintF86(std::string constr, double value);
	void menuSetRTEConstraintF87();
	void set_RTEConstraintF87(std::string constr, std::string value);
	void CycleRTECalcMode();
	void menuSetRTEManeuverCode();
	void set_RTEManeuverCode(char *code);
	void menuEntryCalc();
	void menuEntryUpdateCalc();
	void menuDeorbitCalc();
	void menuMoonRTECalc();
	void menuTransferRTEToMPT();
	void menuGeneralMEDRequest();
	void GeneralMEDRequest(char *str);
	void set_entryrange(double range);
	void EntryRangeDialogue();
	void menuSVCalc();
	void menuSwitchSVSlot();
	void menuSVUpload();
	void menuLSCalc();
	void menuLSUpload();
	void menuAGSSVCalc();
	void menuEntryUpdateUpload();
	void menuCycleTwoImpulseOption();
	void menuSwitchHeadsUp();
	void menuCalcManPAD();
	void menuSetManPADPage();
	void menuCalcEntryPAD();
	void menuSetEntryPADPage();
	void menuSwitchCritical();
	void menuSwitchEntryPADOpt();
	void menuManPADTIG();
	void set_ManPADTIG(double ManPADTIG);
	void menusextantstartime();
	void set_sextantstartime(double time);
	void menuManPADDV();
	void set_P30DV(VECTOR3 dv);
	void menuSwitchManPADEngine();
	void CycleThrusterOption(int &thruster);
	void set_lambertelev(double elev);
	void menuSwitchManPADopt();
	void menuLSLat();
	void set_LSLat(double lat);
	void menuLSLng();
	void set_LSLng(double lng);
	void menuSetSVTime();
	void set_SVtime(double SVtime);
	void menuSetAGSKFactor();
	void set_AGSKFactor(char *str);
	void menuCalcMapUpdate();
	void menuSwitchMapUpdate();
	void menuSetMapUpdateGET();
	void set_MapUpdateGET(double time);
	void menuSwitchUplinkInhibit();
	void menuCycleSPQMode();
	void set_CDHtimemode();
	void menuCycleSPQChaser();
	void menuSetLaunchDate();
	void set_launchdate(int year, int month, int day);
	void menuSetLaunchTime();
	void set_LaunchTime(int hours, int minutes, double seconds);
	void menuSetAGCEpoch();
	void set_AGCEpoch(double mjd);
	void menuChangeVesselType();
	void menuCycleLMStage();
	void menuUpdateLiftoffTime();
	void set_svtarget();
	void TwoImpulseOffset();
	void GetREFSMMATfromAGC();
	void GetEntryTargetfromAGC();
	void menuSwitchEntryNominal();
	void menuSwitchDeorbitEngineOption();
	void menuSetRTEReentryTime();
	void set_RTEReentryTime(double t);
	void EntryLongitudeModeDialogue();
	void menuSetLOIPage();
	void menuTLCCVectorTime();
	void set_TLCCVectorTime(double time);
	void menuCycleTLCCColumnNumber();
	void menuCycleTLCCCSFPBlockNumber();
	void menuSwitchTLCCManeuver();
	void menuSetTLCCGET();
	void set_TLCCGET(double time);
	void menuCycleTLCCConfiguration();
	void menuSetTLCCAlt();
	void set_TLCCAlt(double alt);
	void menuSetTLCCAltMode5();
	void set_TLCCAltMode5(double alt);
	void menuSetTLCCDesiredInclination();
	void set_TLCCDesiredInclination(double inc);
	void menuSetMidcourseConstraintsPage();
	void menuSetTLMCCAzimuthConstraints();
	void menuSetTLMCCTLCTimesConstraints();
	void menuSetTLMCCReentryContraints();
	void menuSetTLMCCPericynthionHeightLimits();
	void menuSetTLMCCLatitudeBias();
	void set_TLMCCLatitudeBias(double bias);
	void menuSetTLMCCMaxInclination();
	void set_TLMCCMaxInclination(double inc);
	void menuSetTLMCCLOIEllipseHeights();
	void set_TLMCCLOIEllipseHeights(double ha, double hp);
	void menuSetTLMCCDOIEllipseHeights();
	void set_TLMCCDOIEllipseHeights(double ha, double hp);
	void menuSetTLMCCLOIDOIRevs();
	void set_TLMCCLOIDOIRevs(double revs1, int revs2);
	void menuSetTLMCCLSRotation();
	void set_TLMCCLSRotation(double rot, double eta);
	void menuSetTLMCCLOPCRevs();
	void set_TLMCCLOPCRevs(int m, int n);
	void menuSetLOIVectorTime();
	void set_LOIVectorTime(double get);
	void menuSetLOIApo();
	void set_LOIApo(double alt);
	void menuSetLOIPeri();
	void set_LOIPeri(double alt);
	void menuSetLOIDesiredAzi();
	void set_LOIDesiredAzi(double azi);
	void menuSetLOIMinAzi();
	void set_LOIMinAzi(double azi);
	void menuSetLOIMaxAzi();
	void set_LOIMaxAzi(double azi);
	void menuSetLOIMaxDVPos();
	void set_LOIMaxDVPos(double dv);
	void menuSetLOIMaxDVNeg();
	void set_LOIMaxDVNeg(double dv);
	void menuSetLOI_HALLS();
	void set_LOI_HALLS(double ha);
	void menuSetLOI_HPLLS();
	void set_LOI_HPLLS(double hp);
	void menuSetLOIDHBias();
	void set_LOIDHBias(double dh);
	void menuSetLOIDW();
	void set_LOIDW(double dw);
	void menuCycleLOIInterSolnFlag();
	void menuSetLOIRevs1();
	void set_LOIRevs1(double revs1);
	void menuSetLOIRevs2();
	void set_LOIRevs2(int revs2);
	void menuSetLOIEta1();
	void set_LOIEta1(double eta);
	void menuSetLOIInitPage();
	void menuSetLOIDisplayPage();
	void menuSetTLAND();
	void menuLOICalc();
	void menuRequestLTMFD();
	void menuSetLandmarkTrkPage();
	void menuSetLmkTime();
	void set_LmkTime(double time);
	void menuSetLmkLat();
	void set_LmkLat(double lat);
	void menuSetLmkLng();
	void set_LmkLng(double lng);
	void menuLmkPADCalc();
	void menuSetTargetingMenu();
	void menuSetPADMenu();
	void menuSetUtilityMenu();
	void menuSetVECPOINTPage();
	void menuMidcoursePage();
	void menuSetLunarLiftoffPage();
	void menuSetEMPPage();
	void menuSetNavCheckPADPage();
	void menuSetDeorbitPage();
	void menuSetEarthEntryPage();
	void menuSetMoonEntryPage();
	void menuSetRTEConstraintsPage();
	void menuSetEntryUpdatePage();
	void menuSetP37PADPage();
	void menuSetRendezvousPage();
	void menuSetDKIPage();
	void menuSetDKIOptionsPage();
	void menuSetLunarAscentPage();
	void cycleVECDirOpt();
	void vecbodydialogue();
	void set_vecbody(OBJHANDLE body);
	void menuVECPOINTCalc();
	void menuSetLDPPVectorTime();
	void set_LDPPVectorTime(double time);
	void menuLSRadius();
	void set_LSRadius(double rad);
	void menuSetLDPPDwellOrbits();
	void set_LDPPDwellOrbits(int N);
	void menuSetLDPPDescentFlightArc();
	void set_LDPPDescentFlightArc(double ang);
	void menuSetLDPPDescIgnHeight();
	void set_LDPPDescIgnHeight(double alt);
	void cycleLDPPPoweredDescSimFlag();
	void menuSetLDPPPoweredDescTime();
	void set_LDPPPoweredDescTime(double pdi);
	void menuLDPPCalc();
	void menuSetDescPlanCalcPage();
	void menuSetLDPPMode();
	void menuSetLDPPSequence();
	void menuTLANDUplinkCalc();
	void menuTLANDUpload();
	void menuSetSkylabPage();
	void menuSwitchSkylabManeuver();
	void menuSetSkylabGET();
	void set_SkylabGET(double time);
	void menuSkylabCalc();
	void menuSetSkylabNC();
	void set_SkylabNC(double N);
	void menuSetSkylabDH1();
	void set_SkylabDH1(double dh);
	void menuSetSkylabDH2();
	void set_SkylabDH2(double dh);
	void menuSetSkylabEL();
	void set_SkylabEL(double E_L);
	void set_t_TPI(double time);
	void menuCyclePlaneChange();
	void menuCyclePCManeuver();
	void set_SkylabDTTPM(double dt);
	void menuSetDescPlanInitPage();
	void menuCycleLLWPChaserOption();
	void menuSetLiftoffguess();
	void set_Liftoffguess(double time);
	void menuLLWPVectorTime();
	void set_LLWPVectorTime(double get);
	void menuSetLLWPCSIFlag();
	void set_LLWPCSIFlag(double val);
	void menuSetLLWPCDHFlag();
	void menuSetLLWPDeltaHeights();
	void set_LLWPDeltaHeights(double dh1, double dh2, double dh3);
	void menuSetLLWPElevation();
	void set_LLWPElevation(double elev);
	void menuSetTPIguess();
	void menuLunarLiftoffCalc();
	void menuLLTPCalc();
	void menuSetLiftoffDT();
	void set_LiftoffDT(double dt);
	void menuLLTPThresholdTime();
	void set_LLTPThresholdTime(double get);
	void menuLLTPVectorTime();
	void set_LLTPVectorTime(double get);
	void set_TPIguess(double time);
	void menuLunarLiftoffVHorInput();
	void set_LunarLiftoffVHorInput(double v_lh);
	void menuLunarLiftoffVVertInput();
	void set_LunarLiftoffVVertInput(double v_lv);
	void menuSetEMPUplinkP99();
	void menuEMPUplink();
	void menuSetEMPUplinkNumber();
	void menuTMLat();
	void set_TMLat(double lat);
	void menuTMLng();
	void set_TMLng(double lng);
	void menuTMAzi();
	void set_TMAzi(double azi);
	void menuSetTerrainModelPage();
	void menuTMDistance();
	void set_TMDistance(double distance);
	void menuTMStepSize();
	void set_TMStepSize(double step);
	void menuTerrainModelCalc();
	void set_TLand(double time);
	void menuTLCCCalc();
	void menuNavCheckPADCalc();
	void menuSetNavCheckGET();
	void set_NavCheckGET(double time);
	void menuLAPCalc();
	void menuCycleDKIChaser();
	void menuSetDKIThresholdTime();
	void set_DKIThresholdInput(double get);
	void menuDKICalc();
	void DKITIGDialogue();
	void set_DKITIG(double time);
	void set_DKITIG_DT_PDI(double dt);
	void menuCycleDKIProfile();
	void menuCycleDKITPIMode();
	void menuSetSPQElevation();
	void set_SPQElevation(double elev);
	void menuSetSPQTerminalPhaseAngle();
	void set_SPQTerminalPhaseAngle(double wt);
	void menuSetSPQTPIDefinitionValue();
	void set_SPQTPIDefinitionValue(double get);
	void menuCycleSPQCDHPoint();
	void menuSPQCDHValue();
	bool set_SPQCDHValue(char* val);
	void menuSetDKIElevation();
	void set_DKIElevation(double elev);
	void menuCycleDKIManeuverLine();
	void menuCycleDKIRadialComponent();
	void DKITPIDTDialogue();
	void set_DKITPIDT(double time);
	void DKINHCDialogue();
	void set_DKINHC(int N);
	void DKINPBDialogue();
	void set_DKINPB(int N);
	void menuDKIDeltaT1();
	void set_DKIDT1(double dt);
	void menuDKIDeltaT2();
	void set_DKIDT2(double dt);
	void menuDKIDeltaT3();
	void set_DKIDT3(double dt);
	void menuSetLAPLiftoffTime();
	void set_LAPLiftoffTime(double time);
	void menuSetDAPPADPage();
	void menuDAPPADCalc();
	void menuSetLVDCPage();
	void menuLaunchAzimuthCalc();
	void menuSetAGCEphemerisPage();
	void menuCycleAGCEphemOpt();
	void menuCycleAGCEphemAGCType();
	void menuSetAGCEphemMission();
	void set_AGCEphemMission(int ApolloNo);
	void menuSetAGCEphemBRCSEpoch();
	void set_AGCEphemBRCSEpoch(double mjd);
	void menuSetAGCEphemTEphemZero();
	void set_AGCEphemTEphemZero(double mjd);
	void menuSetAGCEphemTEPHEM();
	void set_AGCEphemTEPHEM(double mjd);
	void menuSetAGCEphemTIMEM0();
	void set_AGCEphemTIMEM0(double mjd);
	void menuSetAGCEphemTLAND();
	void set_AGCEphemTLAND(double get);
	void menuGenerateAGCEphemeris();
	void cycleVECPOINTOpt();
	void menuSetLMAscentPADPage();
	void menuAscentPADCalc();
	void menuSetPDAPPage();
	void menuPDAPCalc();
	void menuCyclePDAPEngine();
	void menuAP11AbortCoefUplink();
	void menuSetFIDOOrbitDigitalsCSMPage();
	void menuSetFIDOOrbitDigitalsLMPage();
	void menuSetFIDOOrbitDigitalsGETL();
	void menuSetFIDOOrbitDigitalsL();
	void menuSetFIDOOrbitDigitalsGETBV();
	void menuSetMCCDisplaysPage();
	void menuSetSpaceDigitalsPage();
	void menuSpaceDigitalsInit();
	void menuGenerateSpaceDigitals();
	void menuSetMPTPage();
	void menuMPTCycleActive();
	void menuMPTDeleteManeuver();
	void menuMPTTLIDirectInput();
	void set_MPTTLIDirectInput(char *str);
	void menuMPTCopyEphemeris();
	void menuMPTVehicleOrientationChange();
	void menuSetMPTInitPage();
	void menuSetNextStationContactsPage();
	void menuNextStationContactLunar();
	void menuGenerateStationContacts();
	void menuSetPredSiteAcquisitionCSM1Page();
	void menuSetPredSiteAcquisitionLM1Page();
	void menuSetPredSiteAcquisitionCSM2Page();
	void menuSetPredSiteAcquisitionLM2Page();
	void PredSiteAcqCSM1Calc();
	void PredSiteAcqLM1Calc();
	void PredSiteAcqCSM2Calc();
	void PredSiteAcqLM2Calc();
	void ExpSiteAcqLMCalc();
	void GroundPointTableUpdate();
	void CyclePredSiteAcqPage();
	void menuSetExpSiteAcqPage();
	void CycleExpSiteAcqPage();
	void menuSetRelativeMotionDigitalsPage();
	void RelativeMotionDigitalsCalc();
	void menuChooseRETPlan();
	void menuSetUplinkMenu();
	void menuSetStateVectorMenu();
	void menuSetLSUpdateMenu();
	void menuLSUplinkCalc();
	void menuSetLSUplinkPage();
	void menuSetP30UplinkPage();
	void menuSetRetrofireEXDVUplinkPage();
	void menuREFSMMATUplinkCalc();
	bool REFSMMATUplinkCalc(char *str);
	void menuSetREFSMMATUplinkPage();
	void menuSetTITransferPage();
	void menuCycleTITable();
	void menuSetTIPlanNumber();
	void set_TIPlanNumber(int plan);
	void menuTIDeleteGET();
	void set_TIDeleteGET(double get);
	void menuChooseTIThruster();
	bool set_ChooseTIThruster(std::string th);
	void menuCycleTIAttitude();
	void menuTIUllageOption();
	bool set_TIUllageOption(int num, double dt);
	void menuCycleTIIterationFlag();
	void menuCycleTITimeFlag();
	void menuTIDPSTenPercentTime();
	void set_TIDPSTenPercentTime(double deltat);
	void menuTIDPSScaleFactor();
	void set_TIDPSScaleFactor(double scale);
	void menuTransferTIToMPT();
	void menuSetSPQorDKIRTransferPage();
	void menuTransferSPQorDKIToMPT();
	void menuBackToSPQorDKIPage();
	void menuChooseSPQDKIThruster();
	bool set_ChooseSPQDKIThruster(std::string th);
	void menuM70DeleteGET();
	void set_MPTM70DeleteGET(double get);
	void menuM70CycleAttitude();
	void menuM70CycleIterationFlag();
	void menuM70CycleTimeFlag();
	void menuM70DPSTenPercentTime();
	void set_M70DPSTenPercentTime(double deltat);
	void menuM70DPSScaleFactor();
	void set_M70DPSScaleFactor(double scale);
	void menuSetGPMTransferPage();
	void menuTransferGPMToMPT();
	void menuCycleGPMTable();
	void menuGPMReplaceCode();
	void set_GPMReplaceCode(unsigned man);
	void menuChooseGPMThruster();
	bool set_ChooseGPMThruster(std::string th);
	void menuCycleGPMAttitude();
	void menuGPMUllageDT();
	void set_GPMUllageDT(double dt);
	void menuGPMUllageThrusters();
	void menuCycleGPMIterationFlag();
	void menuGPMDPSTenPercentDeltaT();
	void set_GPMDPSTenPercentDeltaT(double dt);
	void menuGPMDPSThrustScaling();
	void set_GPMDPSThrustScaling(double scale);
	void menuCycleGPMTimeFlag();
	void menuLOITransferPage();
	void menuMCCTransferPage();
	void menuTransferLOIMCCtoMPT();
	void menuCycleLOIMCCTable();
	void menuLOIMCCReplaceCode();
	void set_LOIMCCReplaceCode(unsigned man);
	void menuChooseLOIMCCThruster();
	bool set_ChooseLOIMCCThruster(std::string th);
	void menuCycleLOIMCCAttitude();
	void menuLOIMCCUllageThrustersDT();
	bool set_LOIMCCUllageThrustersDT(int num, double dt);
	void menuLOIMCCManeuverNumber();
	void set_LOIMCCManeuverNumber(int num);
	void menuCycleLOIMCCIterationFlag();
	void menuLOIMCCDPSTenPercentDeltaT();
	void set_LOIMCCDPSTenPercentDeltaT(double dt);
	void menuLOIMCCDPSThrustScaling();
	void set_LOIMCCDPSThrustScaling(double scale);
	void menuCycleLOIMCCTimeFlag();
	void menuBacktoLOIorMCCPage();
	void menuSetCheckoutMonitorPage();
	void menuSetMPTDirectInputPage();
	void menuMPTDirectInputSecondPage();
	void menuMPTDirectInputMPTCode();
	void menuMPTDirectInputReplaceCode();
	void set_MPTDirectInputReplaceCode(unsigned n);
	void menuMPTDirectInputAttitude();
	void menuMPTDirectInputBurnParameters();
	bool set_MPTDirectInputM40Data(char *str);
	void menuMPTDirectInputCoord();
	void set_MPTDirectInputCoord(VECTOR3 Att, int mode);
	void menuMPTDirectInputHeadsUpDown();
	void menuMPTDirectInputDPSTenPercentTime();
	void set_MPTDirectInputDPSTenPercentTime(double deltat);
	void menuMPTDirectInputDPSScaleFactor();
	void set_MPTDirectInputDPSScaleFactor(double scale);
	void menuChooseMPTDirectInputThruster();
	bool set_ChooseMPTDirectInputThruster(std::string th);
	void menuMPTDirectInputTransfer();
	void menuMPTDirectInputTIG();
	void set_MPTDirectInputTIG(double tig);
	void menuMPTDirectInputDock();
	void menuMPTDirectInputFinalConfig();
	void set_MPTDirectInputFinalConfig(char *cfg);
	void menuMPTDirectInputUllageDT();
	void set_MPTDirectInputUllageDT(double dt);
	void menuMPTDirectInputUllageThrusters();
	void menuMPTDirectInputREFSMMAT();
	void menuMPTDirectInputDeltaDockingAngle();
	void menuMPTDirectInputTrimAngleInd();
	void menuTransferPoweredAscentToMPT();
	void menuTransferPoweredDescentToMPT();
	void menuMPTMEDM49();
	void CheckoutMonitorCalc();
	void menuMPTInitM50M55Table();
	void menuMPTInitM50CSMWT();
	void menuMPTInitM50LMWT();
	void menuMPTInitM50LMAscentWT();
	void menuMPTInitM50SIVBWT();
	void set_MPTInitM50CSMWT(double mass);
	void set_MPTInitM50LMWT(double mass);
	void set_MPTInitM50LMAscentWT(double mass);
	void set_MPTInitM50SIVBWT(double mass);
	void menuMPTInitM55Config();
	void set_MPTInitM55Config(char *cfg);
	void menuMPTM50Update();
	void menuMPTM55Update();
	void menuMPTInitAutoUpdate();
	void menuMPTInitM50M55Vehicle();
	void menuMPTTrajectoryUpdateCSM();
	void menuMPTTrajectoryUpdateLEM();
	bool set_DifferentialCorrectionSolution(char *str, bool csm);
	void menuMoveToEvalTableCSM();
	void menuMoveToEvalTableLEM();
	void menuMoveToUsableTableCSM();
	void menuMoveToUsableTableLEM();
	void menuEphemerisUpdateCSM();
	void menuEphemerisUpdateLEM();
	void VectorControlPBI(int code);
	void menuSetDescPlanTablePage();
	void menuSetLDPPAzimuth();
	void set_LDPPAzimuth(double azi);
	void menuSetLDPPDescentFlightTime();
	void set_LDPPDescentFlightTime(double dt);
	void cycleLDPPVehicle();
	void menuSetLDPPDesiredHeight();
	void set_LDPPDesiredHeight(double alt);
	void menuLDPPThresholdTime1();
	void menuLDPPThresholdTime2();
	void menuLDPPThresholdTime3();
	void menuLDPPThresholdTime4();
	void set_LDPPThresholdTime(double dt, int thr);
	void menuSetSunriseSunsetTablePage();
	void menuSunriseSunsetTimesCalc();
	void menuSetMoonriseMoonsetTablePage();
	void menuMoonriseMoonsetTimesCalc();
	void menuCapeCrossingInit();
	void menuSetFIDOLaunchAnalogNo1Page();
	void menuSetFIDOLaunchAnalogNo2Page();
	void menuSetRTETradeoffDisplayPage();
	void menuCycleRTETradeoffPage();
	void menuCalcRTETradeoff();
	void menuSetRTETradeoffSite();
	void menuSetRTETradeoffRemoteEarthPage();
	void set_RTETradeoffRemoteEarthPage(int page);
	void set_TradeoffSiteInput(const std::string &site);
	void menuSetRTETradeoffVectorTime();
	void set_RTETradeoffVectorTime(double tv);
	void menuSetRTETradeoffT0MinTime();
	void set_RTETradeoffT0MinTime(double get);
	void menuSetRTETradeoffT0MaxTime();
	void set_RTETradeoffT0MaxTime(double get);
	void menuSetRTETradeoffEntryProfile();
	void menuSetRTETradeoffMode();
	void menuSetDetailedManeuverTableNo1Page();
	void menuSetDetailedManeuverTableNo2Page();
	void menuSetSPQInitializationPage();
	void menuSetDKIInitializationPage();
	void menuGenerateDMT();
	void GMPManeuverTypeName(char *buffer, int typ);
	void GMPManeuverPointName(char *buffer, int point);
	void GMPManeuverCodeName(char *buffer, int code);
	void menuMSKRequest();
	void SelectMCCScreen(int num);
	void menuSetOnlineMonitorPage();
	void menuSetSkeletonFlightPlanPage();
	void menuMidcourseTradeoffPage();
	void menuTLIPlanningPage();
	void menuCycleSFPDisplay();
	void menuAlterationSFPData();
	void menuTransferMCCPlanToSFP();
	void menuDeleteMidcourseColumn();
	void menuSetNodalTargetConversionPage();
	void menuCycleNodeConvOption();
	void menuNodeConvCalc();
	void menuSendNodeToSFP();
	void menuSetNodeConvGET();
	void set_NodeConvGET(double get);
	void menuSetNodeConvLat();
	void set_NodeConvLat(double lat);
	void menuSetNodeConvLng();
	void set_NodeConvLng(double lng);
	void menuSetNodeConvHeight();
	void set_NodeConvHeight(double height);
	void menuSetRendezvousEvaluationDisplayPage();
	void menuSetLLWPInitPage();
	void menuSetLaunchTargetingInitPage();
	void menuSetLLWPDisplayPage();
	void menuSetLunarLaunchTargetingPage();
	void menuSetTPITimesPage();
	void menuCalculateTPITime();
	void menuSetVectorCompareDisplay();
	void menuVectorCompareDisplayCalc();
	void menuVectorCompareColumn1();
	void menuVectorCompareColumn2();
	void menuVectorCompareColumn3();
	void menuVectorCompareColumn4();
	void set_VectorCompareColumn(std::string vec, int col);
	void menuVectorCompareVehicle();
	void menuVectorCompareTime();
	void menuVectorCompareReference();
	void menuSetGuidanceOpticsSupportTablePage();
	void menuGOSTDisplayREFSMMAT();
	void menuGOSTEnterAttitude();
	void menuGOSTEnterSXTData();
	void menuGOSTBoresightSCTCalc();
	void menuGOSTSXTCalc();
	void menuGOSTShowStarVector();
	void menuGOSTShowLandmarkVector();
	void menuSetSLVNavigationUpdatePage();
	void menuSLVNavigationUpdateCalc();
	void menuSLVNavigationUpdateUplink();
	void menuVectorPanelSummaryPage();
	void menuGetStateVectorsFromAGC();

protected:
	oapi::Font *font;
	oapi::Font *font2;
	oapi::Font *font2vert;
	oapi::Font *fonttest;
	oapi::Font *font3;
	oapi::Font *font4;
	oapi::Pen *pen;
	oapi::Pen *pen2;
	Saturn *saturn;
	LEM *lem;
	int screen;
	int marker;
	int RTETradeoffScreen;
	static struct ScreenData {
		int screen;
		int RTETradeoffScreen;
	} screenData;
private:

	ARCore* G;
	AR_GCore* GC;
	ApolloRTCCMFDButtons coreButtons;	
};

#endif // !__ApolloRTCCMFD_H
