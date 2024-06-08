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
#include "CSMcomputer.h"
#include "LEMcomputer.h"
#include "saturn.h"
#include "saturnv.h"
#include "LEM.h"

class ApolloRTCCMFD;

struct RTCCMFDInputBoxData
{
	double *dVal, *dVal2;
	int *iVal, *iVal2;
	int min1, max1, min2, max2;
	VECTOR3 *vVal;
	double factor, factor2;
	std::string *sVal;
	ApolloRTCCMFD *ptr = NULL;
	void (ApolloRTCCMFD::*func)(void) = NULL;
};

struct MEDInput
{
	std::string Label;			//Short description on MFD page
	std::string Description;	//Detailed description in MFD input box
	std::string Unit;			//Unit displayed on MFD page
	std::string Data;
};

struct MEDInputPage
{
	std::string Title;			//Title displayed on MFD page
	std::string MEDCode;
	std::vector<MEDInput> table;
};

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

	void Text(oapi::Sketchpad *skp, std::string message, int x, int y, int xmax = 1024, int ymax = 1024);

	void SelectPage(int page);
	void menuTIChaserVectorTime();
	void menuTITargetVectorTime();
	void menuTITimeIncrement();
	void menuTITimeRange();
	void t1dialogue();
	void t2dialogue();
	void menuCycleK30Vehicle();
	void SPQtimedialogue();
	void set_SPQtime(double tig);
	void menuSetSPQChaserThresholdTime();
	void menuSetSPQTargetThresholdTime();
	void menuDKINSRDHInput();
	void menuDKINCCDHInput();
	void SPQDHdialogue();
	void set_SPQDH(double DH);
	void set_Vessel();
	void set_CSMVessel();
	void set_LMVessel();
	void set_IUVessel();
	void set_TargetVessel();
	void CycleThroughVessels(VESSEL **v) const;
	void menuSLVLaunchTargetingPad();
	void menuSLVLaunchTargeting();
	void menuSLVLaunchUplink();
	void menuVoid();
	void menuSetLambertPage();
	void menuSetSPQPage();
	void menuSetTIMultipleSolutionPage();
	void menuSetREFSMMATPage();
	void menuSetReturnToEarthPage();
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
	void OrbAdjRevDialogue();
	void GPMPCalc();
	void menuCycleGMPManeuverVehicle();
	void menuCycleGMPManeuverPoint();
	void menuCycleGMPManeuverType();
	void menuCycleMarkerUp();
	void menuCycleMarkerDown();
	void menuSetGMPInput();
	void menuGPMCycleVessel();
	void SPQcalc();
	void lambertcalc();
	void Angle_Display(char *Buff, double angle, bool DispPlus = true);
	void GET_Display(char * Buff, double time, bool DispGET = true);
	void GET_Display2(char * Buff, double time);
	void GET_Display3(char* Buff, double time);
	void GET_Display4(char* Buff, double time);
	void GET_Display_HHMM(char *Buff, double time);
	void AGC_Display(char * Buff, double time);
	void FormatLatitude(char * Buff, double lat);
	void FormatLongitude(char * Buff, double lng);
	void FormatIMUAngle0(char *Buff, double ang); //0 digits
	void FormatIMUAngle1(char *Buff, double ang); //0 digits
	void FormatIMUAngle2(char *Buff, double ang); //0 digits
	void REFSMMATName(char* Buff, int n);
	void ThrusterName(char *Buff, int n);
	bool ThrusterType(std::string name, int &id);
	void MPTAttitudeName(char *Buff, int n);
	void CycleREFSMMATopt();
	void UploadREFSMMAT();
	void menuSLVTLITargetingUplink();
	void menuP30Uplink();
	void menuP30UplinkCalc();
	void menuRetrofireEXDVUplink();
	void menuRetrofireEXDVUplinkCalc();
	bool set_RetrofireEXDVUplinkCalc(char *str);
	void menuEntryUplinkCalc();
	void menuEnterSplashdownLat();
	void menuEnterSplashdownLng();
	void menuRTED_REFSMMAT();
	void set_RTED_REFSMMAT(char *str);
	void menuRTEDASTCodeDialogue();
	void menuSetRTEDUllage();
	void set_RTEDUllage(int thrusters, double duration);
	void menuCycleRTEDTrimAnglesOption();
	void menuCycleRTEDHeadsOption();
	void menuCycleRTEDIterateOption();
	void menuSetEntryDesiredInclination();
	void set_EntryDesiredInclination(double inc);
	void menuSetRTEConstraintF86();
	void set_RTEConstraintF86(std::string constr, double value);
	void menuSetRTEConstraintF87();
	void set_RTEConstraintF87(std::string constr, std::string value);
	void menuAddRTESite();
	void menuReplaceRTESite();
	void menuDeleteRTESite();
	void CycleRTECalcMode();
	void menuSetRTEManeuverCode();
	void set_RTEManeuverCode(char *code);
	void menuEntryCalc();
	void menuEntryUpdateCalc();
	void menuSaveSplashdownTarget();
	bool set_SaveSplashdownTarget(char *str);
	void LoadSplashdownTargetToRTEDManualInput();
	void menuDeorbitCalc();
	void menuCycleRetrofireType();
	void menuTransferRTEToMPT();
	bool set_RTESolution(char *str);
	void menuGeneralMEDRequest();
	void menuGeneralMEDRequest(char *message);
	void GeneralMEDRequest(char *str);
	void EntryRangeDialogue();
	void set_SVPageTarget();
	void menuSVCalc();
	void menuSVUpload();
	void menuLSCalc();
	void menuRevertRLSToPrelaunch();
	void menuAGSSVCalc();
	void menuEntryUpdateUpload();
	void menuCycleTwoImpulseOption();
	void menuSwitchHeadsUp();
	void menuCalcManPAD();
	void menuSetManPADPage();
	void menuCalcEntryPAD();
	void menuSetEntryPADPage();
	void menuSwitchEntryPADOpt();
	void menuManPADUllage();
	bool set_ManPADUllageOption(int num, double dt);
	void menuManPADTIG();
	void menusextantstartime();
	void set_sextantstartime(double time);
	void menuManPADDV();
	void set_P30DV(VECTOR3 dv);
	void menuREFSMMATAtt();
	void set_REFSMMATAtt(VECTOR3 att);
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
	void menuUpdateGRRTime();
	void menuSetAGSKFactor();
	void set_AGSKFactor(char *str);
	void menuGetAGSKFactor();
	void menuCalcMapUpdate();
	void menuSwitchMapUpdate();
	void menuSetMapUpdateGET();
	void menuCycleMapUpdatePM();
	void menuCycleSPQMode();
	void set_CDHtimemode();
	void menuCycleSPQChaser();
	void menuSetLaunchDate();
	void set_launchdate(int year, int month, int day);
	void menuSetLaunchTime();
	void set_LaunchTime(int hours, int minutes, double seconds);
	void menuChangeVesselStatus();
	void menuCycleLMStage();
	void menuUpdateLiftoffTime();
	bool set_LiftoffTime(bool cmc);
	void TwoImpulseOffset();
	void GetREFSMMATfromAGC();
	void menuCycleLunarEntryPADSxtOption();
	void GetEntryTargetfromAGC();
	void menuSetRTEReentryTime();
	void set_RTEReentryTime(double t);
	void menuSetLOIPage();
	void menuTLCCVectorTime();
	void menuCycleTLCCColumnNumber();
	void menuCycleTLCCCSFPBlockNumber();
	void menuSwitchTLCCManeuver();
	void menuSetTLCCGET();
	void menuCycleTLCCConfiguration();
	void menuSetTLCCAlt();
	void menuSetTLCCAltMode5();
	void menuSetTLCCDesiredInclination();
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
	void menuSetLOIApo();
	void menuSetLOIPeri();
	void menuSetLOIDesiredAzi();
	void menuSetLOIMinAzi();
	void menuSetLOIMaxAzi();
	void menuSetLOIMaxDVPos();
	void menuSetLOIMaxDVNeg();
	void menuSetLOI_HALLS();
	void menuSetLOI_HPLLS();
	void menuSetLOIDHBias();
	void menuSetLOIDW();
	void menuCycleLOIInterSolnFlag();
	void menuSetLOIRevs1();
	void menuSetLOIRevs2();
	void menuSetLOIEta1();
	void menuSetLOIInitPage();
	void menuSetLOIDisplayPage();
	void menuSetTLAND();
	void menuLOICalc();
	void menuSetLandmarkTrkPage();
	void menuSetLmkTime();
	void menuSetLmkLat();
	void menuSetLmkLng();
	void menuLmkUseLandingSite();
	void menuLmkPADCalc();
	void menuSetTargetingMenu();
	void menuSetPADMenu();
	void menuSetUtilityMenu();
	void menuSetVECPOINTPage();
	void menuMidcoursePage();
	void menuSetLunarLiftoffPage();
	void menuSetNavCheckPADPage();
	void menuSetDeorbitPage();
	void menuSetRTEDigitalsInputPage();
	void menuCycleRTEDColumn();
	void menuSetRTEDigitalsPage();
	void menuSetRTEConstraintsPage();
	void menuSetEntryUpdatePage();
	void menuSetRTCCFilesPage();
	void menuLoadSystemParametersFile();
	void LoadSystemParametersFile(char *file);
	void menuLoadTLIFile();
	void LoadTLIFile(char *file);
	void menuLoadSFPFile();
	void LoadSFPFile(char *file);
	void menuSetRendezvousPage();
	void menuSetDKIPage();
	void menuSetDKIOptionsPage();
	void menuSetLunarAscentPage();
	void cycleVECDirOpt();
	void vecbodydialogue();
	void set_vecbody(OBJHANDLE body);
	void menuVECPOINTCalc();
	void menuSetLDPPVectorTime();
	void menuLSRadius();
	void menuSetLDPPDwellOrbits();
	void menuSetLDPPDescentFlightArc();
	void menuSetLDPPDescIgnHeight();
	void cycleLDPPPoweredDescSimFlag();
	void menuSetLDPPPoweredDescTime();
	void menuLDPPCalc();
	void menuSetDescPlanCalcPage();
	void menuTranslunarPage();
	void menuSetLDPPMode();
	void menuSetLDPPSequence();
	void menuTLANDUplinkCalc();
	void menuTLANDUpload();
	void set_t_TPI(double time);
	void menuSetDescPlanInitPage();
	void menuCycleLLWPChaserOption();
	void menuSetLiftoffguess();
	void menuLLWPVectorTime();
	void menuSetLLWPCSIFlag();
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
	void menuLunarLiftoffVHorInput();
	void menuLunarLiftoffVVertInput();
	void menuLunarLiftoffSaveInsertionSV();
	void menuSetEMPFileName();
	void ErasableMemoryFileRead();
	void menuSetEMPUplinkNumber();
	void menuInitializeEMP();
	void set_EMPInit(char *str);
	void menuEditEMPOctal();
	void set_EMPOctal(int line, int value);
	void menuDeleteEMPLine();
	void set_EMPDelete(int line);
	void menuLoadEMP();
	void menuUplinkEMP();
	void menuTMLat();
	void menuTMLng();
	void menuTMAzi();
	void menuSetTerrainModelPage();
	void menuTMDistance();
	void menuTMStepSize();
	void menuTerrainModelCalc();
	void set_TLand(double time);
	void menuTLCCCalc();
	void menuTLIProcessorCalc();
	void menuTLIProcessorMode();
	void menuTLIProcessorGET();
	void menuTLIEllipseApogee();
	void menuNavCheckPADCalc();
	void menuSetNavCheckGET();
	void menuLAPCalc();
	void menuDKINC1Line();
	void menuDKINHLine();
	void menuCycleDKIChaserVehicle();
	void menuDKICalc();
	void menuDKINSRLine();
	void menuDKIMILine();
	void menuDKINPCLine();
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
	void menuSetDKITerminalPhaseAngle();
	void menuSetDKIMinimumPerigee();
	void menuCycleDKIManeuverLineDefinition();
	void menuCycleDKIProfile();
	void menuDKITIG();
	void menuDKIManeuverLineValue();
	void menuDKIInitialPhaseFlag();
	void menuCycleDKITerminalPhaseOption();
	void menuDKITerminalPhaseDefinitionValue();
	void menuCycleTPIMode();
	void TPIDTDialogue();
	void menuSetLAPLiftoffTime();
	void menuSetDAPPADPage();
	void menuDAPPADCalc();
	void menuSetSaturnIBLVDCPage();
	void menuSetSaturnVLVDCPage();
	void menuLaunchAzimuthCalc();
	void cycleVECPOINTOpt();
	void menuSetLMAscentPADPage();
	void menuAscentPADCalc();
	void menuCycleAscentPADVersion();
	void menuSetPDAPPage();
	void menuPDAPCalc();
	void menuCyclePDAPSegments();
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
	void set_SpaceDigitalsNoMPT(int opt, double get);
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
	void menuSetLandmarkAcquisitionDisplayPage();
	void PredSiteAcqCSM1Calc();
	void PredSiteAcqLM1Calc();
	void PredSiteAcqCSM2Calc();
	void PredSiteAcqLM2Calc();
	void ExpSiteAcqLMCalc();
	void LandmarkAcqDisplayCalc();
	void GroundPointTableUpdate();
	void CyclePredSiteAcqPage();
	void menuSetExpSiteAcqPage();
	void CycleExpSiteAcqPage();
	void CycleLandmarkAcqDisplayPage();
	void menuSetRelativeMotionDigitalsPage();
	void RelativeMotionDigitalsCalc();
	void menuChooseRETPlan();
	void menuSetUplinkMenu();
	void menuSetLSUpdateMenu();
	void menuCSMLSUplinkCalc();
	void menuLMLSUplinkCalc();
	void menuCSMLSUpload();
	void menuLMLSUpload();
	void menuREFSMMATUplinkCalc();
	bool REFSMMATUplinkCalc(char *str);
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
	void menuM70UllageOption();
	bool set_UllageOption(int med, int num, double dt);
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
	void CheckoutMonitorCalc();
	void menuCycleMPTTable();
	void menuCycleMPTMED();
	void menuSetMPTInitInput();
	void set_MPTInitM55Config(char *cfg);
	void menuMPTUpdate();
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
	void menuSetLDPPDescentFlightTime();
	void set_LDPPDescentFlightTime(double dt);
	void cycleLDPPVehicle();
	void menuSetLDPPDesiredHeight();
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
	void menuUplinkDisplayRequest();
	void SelectUplinkScreen(int num);
	void menuSetOnlineMonitorPage();
	void menuSetSkeletonFlightPlanPage();
	void menuMidcourseTradeoffPage();
	void menuTLIPlanningPage();
	void menuCycleSFPDisplay();
	void menuAlterationSFPData();
	void menuTransferMCCPlanToSFP();
	void menuInterpolateSFP();
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
	void set_VectorCompareTime(double time);
	void menuVectorCompareReference();
	void menuSetGuidanceOpticsSupportTablePage();
	void menuGOSTDisplayREFSMMAT();
	void menuGOSTEnterAttitude();
	void menuGOSTEnterSXTData();
	void menuGOSTBoresightSCTCalc();
	void menuGOSTSXTCalc();
	void menuGOSTShowStarVector();
	void menuGOSTShowLandmarkVector();
	void menuGOSTEnterStarInCatalog();
	void menuSaveOSTREFSMMAT();
	void menuSetLMOpticsSupportTablePage();
	void menuLOSTMode();
	void set_LOSTMode(int mode);
	void menuLOSTAttitude1();
	void menuLOSTAttitude2();
	void menuLOST_REFSMMAT1();
	bool set_LOST_REFSMMAT1(char *str);
	void menuLOST_REFSMMAT2();
	bool set_LOST_REFSMMAT2(char *str);
	void menuLOST_CSM_REFSMMAT();
	bool set_LOST_CSM_REFSMMAT(char *str);
	void menuLOSTOptics1();
	void menuLOSTOptics2();
	bool set_LOST_AGS_Star2(int star, char *pos, double ang);
	void menuLOSTRealign();
	void menuCalcLOST();
	void set_LOSTCheckMode(double get,int Detent, int COASAxis);
	void UpdateLOSTDisplay();
	void CalculateLOSTDOKOption();
	void menuSetDebugPage();
	void menuCalculateIMUComparison();
	void menuSetIMUParkingAnglesPage();
	void menuCalculateIMUParkingAngles();
	void menuSLVNavigationUpdateCalc();
	void menuSLVNavigationUpdateUplink();
	void menuVectorPanelSummaryPage();
	void menuGetOnboardStateVectors();
	void menuSetRetrofireConstraintsPage();
	void menuSetRetrofireDigitalsPage();
	void menuRetrofireGETIDialogue();
	void menuRetrofireLatDialogue();
	void menuRetrofireLngDialogue();
	void menuSetRetrofireXDVPage();
	void menuSwitchRetrofireEngine();
	void menuSwitchRetrofireBurnMode();
	void menuSwitchRetrofireAttitudeMode();
	void menuSwitchRetrofireGimbalIndicator();
	void menuChooseRetrofireValue();
	void set_RetrofireValue(double val);
	void menuChooseRetrofireAttitude();
	void set_RetrofireAttitude(VECTOR3 att);
	void menuChooseRetrofireK1();
	void set_RetrofireK1(double val);
	void menuChooseRetrofireK2();
	void set_RetrofireK2(double val);
	void menuChooseRetrofireGs();
	bool set_RetrofireGs(double val);
	void menuChooseRetrofireUllage();
	bool set_RetrofireUllage(int num, double dt);
	void menuSetRetrofireTargetSelectionPage();
	void menuCycleRecoveryTargetSelectionPages();
	void menuRecoveryTargetSelectionCalc();
	void set_RecoveryTargetSelectionCalc(double get, double lng);
	void menuSelectRecoveryTarget();
	bool set_RecoveryTarget(int num);
	void menuSaveDODREFSMMAT();
	void menuSaveRTEREFSMMAT();
	void menuMakeDODREFSMMATCurrent();
	void menuSetRetrofireMissDistance();
	bool set_RetrofireMissDistance(double val);
	void menuSetAbortScanTableInputPage();
	void menuCycleASTType();
	void menuSetASTSiteOrType();
	void set_ASTSiteOrType(char *site);
	void menuASTVectorTime();
	void set_ASTVectorTime(double get);
	void menuASTAbortTime();
	void set_ASTAbortTime(double get);
	void menuASTLandingTime();
	void set_ASTLandingTime(double get);
	void menuSetAbortScanTablePage();
	void menuASTTMAXandDVInput();
	bool set_ASTTMaxandDV(char *str);
	void menuASTEntryProfile();
	void set_ASTEntryProfile(char *str);
	void menuASTCalc();
	void menuDeleteASTRow();
	void menuSetRTEDManualManeuverInputPage();
	void menuRTEDManualVectorTime();
	void set_RTEDManualVectorTime(double get);
	void menuRTEDManualIgnitionTime();
	void set_RTEDManualIgnitionTime(double get);
	void menuCycleRTEDManualReference();
	void menuEnterRTEDManualDV();
	void set_RTEDManualDV(VECTOR3 DV);
	void menuSetRTEDEntryProfilePage();
	void menuAGCTimeUpdateCalc();
	void set_AGCTimeUpdateCalc(char *dt);
	void menuAGCTimeUpdateComparison();
	void menuAGCTimeUpdateUplink();
	void menuAGCLiftoffTimeComparision();
	void set_AGCLiftoffTimeComparision(double tim);
	void menuSetLunarTargetingProgramPage();
	void LUNTAR_TIGInput();
	void LUNTAR_BTInput();
	void LUNTAR_PitchInput();
	void LUNTAR_YawInput();
	void LUNTAR_LatInput();
	void LUNTAR_LngInput();
	void LUNTARCalc();
	void menuSetRetrofireSeparationPage();
	void menuRetroShapingGET();
	void menuRetroSepDeltaTTIG();
	void menuRetroSepThruster();
	bool set_RetroSepThruster(std::string th);
	void menuRetroSepDeltaV();
	void menuRetroSepDeltaT();
	void menuRetroSepUllageDT();
	void menuRetroSepUllageThrusters();
	void menuRetroSepGimbalIndicator();
	void menuRetroSepAtt();
	void menuSetRetrofireSeparationInputsPage();
	void menuSetRetrofireSubsystemPage();
	void menuSetEntryUplinkPage();
	void menuLWPLiftoffTimeOption();
	void menuLWPLiftoffTime();
	void menuLWP_RINS();
	void menuLWP_VINS();
	void menuLWP_GAMINS();
	void menuLWP_PhaseFlags();
	void menuLWPCycleDELNOF();
	void menuLWP_DELNO();
	void menuSetLWPDisplayPage();
	void menuSetRendezvousPlanningDisplayPage();
	void menuSetPerigeeAdjustInputPage();
	void menuSetPerigeeAdjustDisplayPage();
	void menuPerigeeAdjustCalc();
	void CyclePerigeeAdjustVehicle();
	void menuPerigeeAdjustVectorTime();
	void menuPerigeeAdjustThresholdTime();
	void menuPerigeeAdjustTimeIncrement();
	void menuPerigeeAdjustHeight();
	void menuSetAGOPPage();
	void menuCycleAGOPPage();
	void menuSetAGOPInput();
	void menuAGOPCalc();
	void menuAGOPSaveREFSMMAT();
	void menuSetRTACFPage();
	void CycleCSMOrLMSelection();

	void SetMEDInputPageP13();
	void SetMEDInputPageP14();
	void SetMEDInputPage(std::string med);
	void menuMEDInputCalc();
	void menuInputMEDData();
	void set_MEDData(char *str);

	void GenericGETInput(double *get, char *message);
	void GenericDoubleInput(double *val, char* message, double factor = 1.0);
	void GenericDouble2Input(double *val1, double *val2, char* message, double factor1 = 1.0, double factor2 = 1.0);
	void GenericIntInput(int *val, char* message, void (ApolloRTCCMFD::*func)(void) = NULL, int min = 1, int max = 0);
	void GenericInt2Input(int *val1, int *val2, char* message, int min1, int max1, int min2, int max2, void (ApolloRTCCMFD::*func)(void) = NULL);
	void GenericVectorInput(VECTOR3 *val, char* message, double factor = 1.0, void (ApolloRTCCMFD::*func)(void) = NULL);
	void GenericStringInput(std::string *val, char* message, void (ApolloRTCCMFD::*func)(void) = NULL);
protected:
	oapi::Font *font;
	oapi::Font *font2;
	oapi::Font *font2vert;
	oapi::Font *fonttest;
	oapi::Font *font3;
	oapi::Font *font4;
	oapi::Font *font5;
	oapi::Pen *pen;
	oapi::Pen *pen2;
	Saturn *saturn;
	LEM *lem;
	int screen;
	int subscreen;
	int marker;
	int markermax;
	int status; //Page dependent status, reset to 0 when new page is entered
	static struct ScreenData {
		int screen;
		int subscreen;
		int marker;
		int markermax;
	} screenData;
private:

	ARCore* G;
	AR_GCore* GC;
	ApolloRTCCMFDButtons coreButtons;

	RTCCMFDInputBoxData tempData;

	bool IsCSM; //Chooses if the CSM or LM vessel in the RTCC is selected
	int ErrorMessage;
	MEDInputPage MEDInputData;

	//Additional display functions
	void AGOPDisplay(oapi::Sketchpad*skp);
	void AGOPDisplayOption1(oapi::Sketchpad*skp);
	void AGOPDisplayOption2(oapi::Sketchpad*skp);
	void AGOPDisplayOption3(oapi::Sketchpad*skp);
	void AGOPDisplayOption4(oapi::Sketchpad*skp);
	void AGOPDisplayOption5(oapi::Sketchpad*skp);
	void AGOPDisplayOption6(oapi::Sketchpad*skp);
	void AGOPDisplayOption7(oapi::Sketchpad*skp);
	void AGOPDisplayOption8(oapi::Sketchpad*skp);
	void AGOPDisplayOption9(oapi::Sketchpad*skp);

	void CSMOrLMSelection(oapi::Sketchpad*skp);
	void CSMOrLMSelectionErrorMessage(oapi::Sketchpad*skp);
	void PrintCSMVessel(char *Buffer, bool ShowCSM = true);
	void PrintLMVessel(char *Buffer);
	void PrintIUVessel(char *Buffer);
	void PrintTargetVessel(char *Buffer);
};

#endif // !__ApolloRTCCMFD_H
