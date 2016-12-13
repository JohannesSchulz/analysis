#include <string.h>
#include "TFile.h"
#include "TH1.h"
#include "TVirtualFitter.h"
#include "TF1.h"
#include "TH1F.h"
#include "TKey.h"
#include "Riostream.h"
#include "TCanvas.h"
#include "TPad.h"
#include "TSystem.h"
#include "TLegend.h"
#include "THStack.h"
#include "TStyle.h"
#include "TLatex.h"
#include "TMatrixD.h"
#include "TFitResult.h"
#include "TFitResultPtr.h"
#include "TMatrixDSym.h"
#include "TMinuit.h"
#include <map>
#include <vector>
#include <list>
#include <algorithm>

// Accesable everywhere
TObject *obj;
TFile   *sourceFile1, *sourceFile2, *sourceFile3,  *sourceFile4,
				*sourceFile5, *sourceFile6, *sourceFile7,  *sourceFile8,
				*sourceFile9, *sourceFile10,
				*sourceFile11, *sourceFile12,*sourceFile13, *sourceFile14,
				*sourceFile15, *sourceFile16, *sourceFile17, *sourceFile19,
				*sourceFile21, *sourceFile22, *sourceFile23, *sourceFile24,				
				*sourceFile25, *sourceFile26, *sourceFile27, *sourceFile28,
				*sourceFile29, *sourceFile30,
				*sourceFile31, *sourceFile32, *sourceFile33, *sourceFile34,				
				*sourceFile35, *sourceFile36, *sourceFile37, *sourceFile38,
				*sourceFile39, *sourceFile40, *sourceFile41;
											
TH1F *plain;
TF1 *f;			
TString outputFolder,outputFilename;
TLatex *CMS_text, *CMS_text2;
TPad *canvasDefault_1,*canvasDefault_2,*canvasDefault_3;
TCanvas *canvasDefault;
TLegend *infoBox, *infoBoxData, *infoBoxSignal, *infoBoxError;
bool showStatsBoxes;
bool seperated = false;
bool GJetsPt = false;
// if true -> htemp!=0 hinzu

bool plot_data = true;
// *******************************************
// Variables
TString imageType = "pdf";
int outputWidth   = 600;
int outputHeight  = 600;
//int outputWidth   = 960;
//int outputHeight  = 720;
bool showStats = false;
double weight = 1.;
double rebin = 10;
double N_bins = 1;
double efficiency = 0.865;
//double efficiency = 0.885339;
double e_Fakerate = 0.0148;
//double scale_ISR = 1.99563;
//double scale_GJets = 2.05726;
double scale_640 = 1.154034091;
double scale_540 = 1.183054415;
//double scale_ISR = 1.92996;


/* double scale_ISR = 1.33;
double scale_GJets = 2.385;
double scale_ISR_error = 0.18; //absolut
double scale_GJets_error = 0.63; //absolut
*/


double scale_ISR = 1.15;
double scale_GJets = 2.35;
double scale_ISR_error = 0.23; //absolut
double scale_GJets_error = 0.37; //absolut

/*
double scale_ISR = 1.2;
double scale_GJets = 2.61;
double scale_ISR_error = 0.23; //absolut
double scale_GJets_error = 0.93; //absolut
*/
/*
double scale_ISR = 1.78;
double scale_GJets = 2.56;
double scale_ISR_error = 0.35; //absolut
double scale_GJets_error = 0.92; //absolut
*/
/*double scale_ISR = 1.36;
double scale_GJets = 2.23;
double scale_ISR_error = 0.20; //absolut
double scale_GJets_error = 0.47; //absolut */

/*double scale_ISR = 1.31;
double scale_GJets = 2.353;
double scale_ISR_error = 0.1755; //absolut
double scale_GJets_error = 0.636; //absolut 
*/
//double scale_ISR = 1.91;
//double scale_GJets = 2.3;

//double scale_GJets = 2.34993;

//double scale_ISR = 1.97;
//double scale_GJets = 2.14;
//double scale_ISR_error = 0.29; //absolut
//double scale_GJets_error = 0.49; //absolut


//double scale_ISR_error = 0.28; //absolut
//double scale_GJets_error = 0.67; //absolut
//double scale_ISR_error = 0.318974; //absolut
//double scale_GJets_error = 0.753576; //absolut

double e_fake_error = 0.00164; //absolut
double qcd_error = 1; //relativ
double tt_error = 0.26;  // relativ
double dibo_error = 0.5;  //relativ
double lumi_error = 0.026; //relativ
double trigger_error = 0.0133; //relativ

int bins = 0;
double error_Vg = 0;
double error_gJ = 0;	
double error_gJPt = 0;	
double error_e_fake = 0;
double error_qcd = 0;
double error_tt = 0;
double error_dibo = 0;

double minimum = 0.005;

std::map < int , TH1F* > order;


// End of Variables
// *******************************************
//TString fileName1 = "PhotonParkedD_V06.1__20_sel.root";
TString fileName1 = "PhotonParkedD_V06.1_sel.root";
//TString fileName1 = "PhotonHadD_V02.1_sel.root";
//TString fileName2 = "TTJets_V02.1_sel.root"; // higher order
TString fileName2 = "TTGamma_V02.1_sel.root";
//TString fileName3 = "ZGamma_V02.1_sel.root";
TString fileName3 = "ZGammaAdd.root";
//TString fileName3 = "ZGammaAdd.root";
//TString fileName3 = "ZG_merge.root";
//TString fileName17 = "ZGammaNuNu_V02.1_sel.root";
// TString fileName4 = "WJets_V02.1_sel.root";
//TString fileName4 = "WGamma_V02.1_sel.root";
TString fileName4 = "WGammaAdd.root";

//TString fileName5 = "scaled_normal/ZGammaAdd.root";
//TString fileName6 = "scaled_normal/WGammaAdd.root";

//TString fileName5 = "ZGammaUp.root";
//TString fileName6 = "WGammaUp.root";
TString fileName5 = "ZGammaAdd.root";
TString fileName6 = "WGammaAdd.root";

TString fileName7 = "QCD_500_1000_V02.1_sel.root";
TString fileName8 = "QCD_1000_inf_V02.1_sel.root";
TString fileName9 = "GJets_40_100_V06.1_sel.root";
TString fileName10 = "GJets_100_200_V02.1_sel.root";
TString fileName11 = "GJets_200_400_V02.1_sel.root";
TString fileName12 = "GJets_400_inf_V02.1_sel.root";
TString fileName13 = "WW_incl_V06.1_sel.root";
TString fileName14 = "WZ_incl_V06.1_sel.root";
TString fileName15 = "ZZ_incl_V06.1_sel.root";
TString fileName16 = "signal_540_530.root";
//TString fileName18 = "signal_540_480.root";
TString fileName17 = "signal_640_630.root";

TString fileName19 = "GammaPixel.root";


TString fileName21 = "signal_490_480.root";
TString fileName22 = "signal_515_505.root";
TString fileName23 = "signal_515_480.root";	
TString fileName24 = "signal_540_480.root";
TString fileName25 = "signal_540_505.root";	
TString fileName26 = "signal_540_530.root";	
TString fileName27 = "signal_565_555.root";	
TString fileName28 = "signal_565_530.root";	
TString fileName29 = "signal_565_505.root";	

TString fileName30 = "signal_590_580.root";
TString fileName31 = "signal_590_555.root";	
TString fileName32 = "signal_590_530.root";		
TString fileName33 = "signal_615_605.root";	
TString fileName34 = "signal_615_580.root";
TString fileName35 = "signal_615_555.root";		
TString fileName36 = "signal_640_630.root";	
TString fileName37 = "signal_640_605.root";	
TString fileName38 = "signal_640_580.root";		
TString fileName39 = "signal_665_655.root";	

TString fileName40 = "signal_690_680.root";	
TString fileName41 = "signal_715_705.root";		

//TString fileName19 = "signal_640_630.root";

/* if (GJetsPt == true){
	TString fileName28 = "G_0_15_V07.1_sel.root";
	TString fileName29 = "G_15_30_V07.1_sel.root"; 
	TString fileName18 = "G_30_50_V07.1_sel.root";
	TString fileName30 = "G_50_80_V07.1_sel.root";
	TString fileName20 = "G_80_120_V07.1_sel.root";
	TString fileName21 = "G_120_170_V07.1_sel.root";
	TString fileName22 = "G_170_300_V07.1_sel.root";
	TString fileName23 = "G_300_470_V07.1_sel.root";
	TString fileName24 = "G_470_800_V07.1_sel.root";
	TString fileName25 = "G_800_1400_V07.1_sel.root";
	TString fileName26 = "G_1400_1800_V07.1_sel.root";
	TString fileName27 = "G_1800_V07.1_sel.root";
	} */

TString    fileLabel1 = fileName1;
TString    fileLabel2 = fileName2;
TString    fileLabel3 = fileName3;
TString    fileLabel4 = fileName4;		
TString    fileLabel5 = fileName5;
TString    fileLabel6 = fileName6;		
TString    fileLabel7 = fileName7;
TString    fileLabel8 = fileName8;		
TString    fileLabel9 = fileName9;
TString    fileLabel10 = fileName10;		
TString    fileLabel11 = fileName11;		
TString    fileLabel12 = fileName12;
TString    fileLabel13 = fileName13;		
TString    fileLabel14 = fileName14;		
TString    fileLabel15 = fileName15;
TString    fileLabel16 = fileName16;
TString    fileLabel17 = fileName17;
TString    fileLabel19 = fileName19;

		
TString    fileLabel21 = fileName21;		
TString    fileLabel22 = fileName22;
TString    fileLabel23 = fileName23;		
TString    fileLabel24 = fileName24;		
TString    fileLabel25 = fileName25;
TString    fileLabel26 = fileName26;
TString    fileLabel27 = fileName27;
TString    fileLabel28 = fileName28;
TString    fileLabel29 = fileName29;

TString    fileLabel30 = fileName30;		
TString    fileLabel31 = fileName31;		
TString    fileLabel32 = fileName32;
TString    fileLabel33 = fileName33;		
TString    fileLabel34 = fileName34;		
TString    fileLabel35 = fileName35;
TString    fileLabel36 = fileName36;
TString    fileLabel37 = fileName37;
TString    fileLabel38 = fileName38;
TString    fileLabel39 = fileName39;

TString    fileLabel40 = fileName40;		
TString    fileLabel41 = fileName41;		

bool compare(TH1F* x, TH1F* y){
	
	//return (x < y);
	return( x->Integral() < y->Integral() );
	
	}
	

void plotHistograms(
TH1F* htemp1, TH1F* htemp2, TH1F* htemp3, TH1F* htemp4, TH1F* htemp5, TH1F* htemp6, TH1F* htemp7, TH1F* htemp8, TH1F* htemp9, TH1F* htemp10,
TH1F* htemp11, TH1F* htemp12, TH1F* htemp13, TH1F* htemp14, TH1F* htemp15, TH1F* htemp16, TH1F* htemp17, TH1F* htemp19,
TH1F* htemp21, TH1F* htemp22, TH1F* htemp23, TH1F* htemp24, TH1F* htemp25, TH1F* htemp26, TH1F* htemp27, TH1F* htemp28, TH1F* htemp29, TH1F* htemp30,
TH1F* htemp31, TH1F* htemp32, TH1F* htemp33, TH1F* htemp34, TH1F* htemp35, TH1F* htemp36, TH1F* htemp37, TH1F* htemp38, TH1F* htemp39, TH1F* htemp40, TH1F* htemp41, TString filename) {

  //TString title = htemp1->GetName();
  TString title = htemp1->GetTitle();

  // Make sure histograms exist
  if (
	!htemp1 || !htemp2 || !htemp3 ||!htemp4 ||!htemp5 ||!htemp6 || !htemp7 ||!htemp8 || !htemp9 ||!htemp10 ||
	!htemp11 || !htemp12 ||!htemp13 ||!htemp14 || !htemp15 ||!htemp16 ||!htemp17 || !htemp19 ||
	!htemp21 || !htemp22 ||!htemp23 ||!htemp24 || !htemp25	||!htemp26 ||!htemp27 ||!htemp28 ||!htemp29 || !htemp30 ||
  !htemp31 || !htemp32 ||!htemp33 ||!htemp34 || !htemp35	||!htemp36 ||!htemp37 ||!htemp38 ||!htemp39 || !htemp40 ||
	!htemp41) { 
	
    cout << "Histogram missing from a file: " << htemp1->GetName() << endl;
    return;
  }  
// htemp2 = ttbar is NNLO and htemp13 = WW is NLO

 htemp3->Scale(1.424); //k factor
 htemp4->Scale(1.579); //k factor
 
 htemp5->Scale(1.424); //k factor
 htemp6->Scale(1.579); //k factor

 htemp3->Scale(scale_ISR);
 htemp4->Scale(scale_ISR);
 htemp5->Scale(scale_ISR);
 htemp6->Scale(scale_ISR);
 htemp7->Scale(weight);
 htemp8->Scale(weight);
 htemp9->Scale(scale_GJets);
 htemp10->Scale(scale_GJets);
 htemp11->Scale(scale_GJets);
 htemp12->Scale(scale_GJets);
 htemp14->Scale(weight);
 htemp15->Scale(weight);
 htemp16->Scale(weight);
 htemp17->Scale(weight);

 
 htemp19->Scale(e_Fakerate); 
 

/*if (GJetsPt){ 
 htemp18->Scale(weight);
 htemp30->Scale(weight);
 htemp20->Scale(weight);
 htemp21->Scale(weight);
 htemp22->Scale(weight);
 htemp23->Scale(weight); 
 htemp24->Scale(weight);
 htemp25->Scale(weight);
 htemp26->Scale(weight);
 htemp27->Scale(weight);  
 htemp28->Scale(weight);
 htemp29->Scale(weight); 
 }*/
 
 htemp2->Scale(efficiency); 
 htemp3->Scale(efficiency);
 htemp4->Scale(efficiency);
 htemp5->Scale(efficiency);
 htemp6->Scale(efficiency);
 htemp7->Scale(efficiency);
 htemp8->Scale(efficiency);
 htemp9->Scale(efficiency);
 htemp10->Scale(efficiency);
 htemp11->Scale(efficiency);
 htemp12->Scale(efficiency);
 htemp13->Scale(efficiency); 
 htemp14->Scale(efficiency);
 htemp15->Scale(efficiency); 
 htemp16->Scale(efficiency*scale_540); 
 htemp17->Scale(efficiency*scale_640); 
 
 htemp21->Scale(efficiency*scale_640); 
 htemp22->Scale(efficiency*scale_640); 
 htemp23->Scale(efficiency*scale_640); 
 htemp24->Scale(efficiency*scale_640); 
 htemp25->Scale(efficiency*scale_640); 
 htemp26->Scale(efficiency*scale_640); 
 htemp27->Scale(efficiency*scale_640);  
 htemp28->Scale(efficiency*scale_640); 
 htemp29->Scale(efficiency*scale_640);
 
 htemp30->Scale(efficiency*scale_640); 
 htemp31->Scale(efficiency*scale_640); 
 htemp32->Scale(efficiency*scale_640); 
 htemp33->Scale(efficiency*scale_640); 
 htemp34->Scale(efficiency*scale_640); 
 htemp35->Scale(efficiency*scale_640); 
 htemp36->Scale(efficiency*scale_640); 
 htemp37->Scale(efficiency*scale_640);  
 htemp38->Scale(efficiency*scale_640); 
 htemp39->Scale(efficiency*scale_640); 
 
 htemp40->Scale(efficiency*scale_640); 
 htemp41->Scale(efficiency*scale_640); 


 
  
/* if (GJetsPt){
 htemp18->Scale(efficiency);
 htemp30->Scale(efficiency);
 htemp20->Scale(efficiency);
 htemp21->Scale(efficiency);
 htemp22->Scale(efficiency);
 htemp23->Scale(efficiency); 
 htemp24->Scale(efficiency);
 htemp25->Scale(efficiency);
 htemp26->Scale(efficiency);
 htemp27->Scale(efficiency); 
 htemp28->Scale(efficiency);
 htemp29->Scale(efficiency); 
 const double METsign10[] = {0,15,26,34,60,100,140,180,230,350}; } */
 //  float METsign14[] = {0,15,22,26,30,34,40,46,60,80,100,140,180,230,350};
// const double METsign10[] = {0,15,22,34,60,80,100,140,180,230,350};
 
 rebin =1;
 
 const double METsign10[] = {60,80,100,140,180,230,350};
// const double METsign10[] = {0,15,26,34,60,100,140,180,230,350}; 
// const double PT[] = {30,68.8,117.3,165.8,214.3,291.9,388.9,1000}; 
 const double MT[] = {0,120,180,240,300,360,420,480,540,600,660,800,1000}; 
 const double PTCR[] = {0,20,40,60,80,100,120,140,160,180,200,220,240,260,280,300,320,340,380,420,500,700};
 const double PTbefore[] = {0,20,40,60,80,100,120,140,160,180,200,220,240,260,280,300,320,340,360,380,400,440,480,520,560,600,650,700,750,800,900,1000};
 const double PT[] = {160,320,480,640,800,1120,2000}; 
 const double PTbefore2[] = {0,20,40,60,80,100,120,140,160,180,200,220,240,260,280,300,320,340,360,380,400,420,440,460,480,500,520,540,560,580,600,620,640,680,750};   
 
 
//if ( true ) {
   if (title == "h_METoverSqHT_double_control_3_regions_100_10_80" || title == "h_sum_signal" || title == "h_MET_significance_per_gev_14" || title == "h_trans_mass_pt_CR" || title == "h_tight_photon_pt_before" || title == "h_trans_mass_pt_before_per_gev"|| title == "h_MET_significance_per_gev_14_CR" ||  title == "h_n_jets_cleaned_before" ||  title == "h_trans_mass_pt_before_per_gev") {
//if (title == "h_MET_significance_MT_sideband" || title == "h_MET_significance_MT_sideband_2"|| title == "h_MET_significance_per_gev_14" || title == "h_sum_signal"|| title == "h_HT_raw"|| title == "h_MET_significance_metsig_sideband") {
/* if(title == "h_HT_CR" ||title == "h_jet_pt_CR" ||title == "h_tight_photon_pt_before" ||title == "h_tight_photon_pt_CR" ||title == "h_trans_mass_pt_40" || title == "h_METoverSqHT_double_control_20" || title == "h_MET_significance_scale" ||title == "h_MET_significance" || title == "h_pt_dep_1" ||title == "h_pt_dep_2" ||title == "h_pt_dep_3" ||title == "h_pt_dep_4"|| title == "h_pt_orth" ||title == "h_final_MET_significance_unblind" ||title == "h_photon_pt_trans_mass_control" || title == "h_photon_pt_trans_mass_signal" || title == "h_METoverSqHT_100_12" || title == "h_cutflow"
 ||title == "h_METoverSqHT_trans_mass_control" || title == "h_METoverSqHT_met_sign_control"
 || title == "h_met_significance_40"|| title == "h_photon_pt_met_sign_control" ||title == "h_photon_pt_met_sign_signal"||title == "h_tight_1photons_pt" || title == "h_final_MET_significance_blind" || title == "h_MET_significance_per_gev_14" || title ==
 "h_MET_significance_per_gev_14_before" || title == "h_final_n_loose_photons_blind") {
*/
// if(title == "h_cutflow" || title == "h_upper_right_SR" || title == "h_upper_left_SR" || title == "h_lower_right_SR" || title == "h_lower_left_SR") {
 
// if(title == "h_MET_significance_metsig_sideband" ||  title == "h_HT_raw" ||title == "h_InvMass_2jets_CR" ||title == "h_Angle_MJ1_CR" ||  title == "h_final_MET_significance_unblind"|| title == "h_n_jets_cleaned_CR" || title == "h_MET_significance_per_gev_14" || title == "h_sum_signal_over_sqMET") {

// if(title == "h_MET_significance_per_gev_14_before" || title == "h_n_jets_cleaned_before" || title == "h_n_jets_cleaned_CR"|| title == "h_tight_photon_pt_before" || title == "h_tight_photon_pt_CR" || title ==
// "h_METoverSqHT_double_control_3_regions_100_10_80"|| title == "h_trans_mass_pt_before") {

 
 minimum = 0.005;
// plot_data = true; 
rebin = 2;
 
  if (title == "h_MET_significance_metsig_sideband" ||title == "h_met" || title == "h_InvMass_2jets_CR" ||title == "h_Angle_MJ1_CR" ||title == "h_HT_CR" ||title == "h_tight_photon_pt_before" ||title == "h_MET_significance_scale" || title == "h_pt_dep_1" ||title == "h_pt_dep_2" ||title == "h_pt_dep_3"
 || title == "h_pt_orth" ||title == "h_tight_1photons_pt"|| title == "h_photon_pt_trans_mass_control" || title == "h_photon_pt_trans_mass_signal"
 || title == "h_photon_pt_met_sign_control" ||title == "h_photon_pt_met_sign_signal" ) {
 htemp1 = (TH1F*)htemp1->Rebin(rebin);
 htemp2 = (TH1F*)htemp2->Rebin(rebin);
 htemp3 = (TH1F*)htemp3->Rebin(rebin);
 htemp4 = (TH1F*)htemp4->Rebin(rebin);
 htemp5 = (TH1F*)htemp5->Rebin(rebin);
 htemp6 = (TH1F*)htemp6->Rebin(rebin);
 htemp7 = (TH1F*)htemp7->Rebin(rebin);
 htemp8 = (TH1F*)htemp8->Rebin(rebin);
 htemp9 = (TH1F*)htemp9->Rebin(rebin);
 htemp10 = (TH1F*)htemp10->Rebin(rebin);
 htemp11 = (TH1F*)htemp11->Rebin(rebin);
 htemp12 = (TH1F*)htemp12->Rebin(rebin);
 htemp13 = (TH1F*)htemp13->Rebin(rebin); 
 htemp14 = (TH1F*)htemp14->Rebin(rebin);
 htemp15 = (TH1F*)htemp15->Rebin(rebin); 
 htemp16 = (TH1F*)htemp16->Rebin(rebin);
 htemp17 = (TH1F*)htemp17->Rebin(rebin); 
 htemp19 = (TH1F*)htemp19->Rebin(rebin);
 } 
  
 rebin = 6;
 
 if ( title == "h_MET_significance_per_gev_14") {
 htemp1 = (TH1F*)htemp1->Rebin(rebin,"htemp1",METsign10);
 htemp2 = (TH1F*)htemp2->Rebin(rebin,"htemp2",METsign10);
 htemp3 = (TH1F*)htemp3->Rebin(rebin,"htemp3",METsign10);
 htemp4 = (TH1F*)htemp4->Rebin(rebin,"htemp4",METsign10);
 htemp5 = (TH1F*)htemp5->Rebin(rebin,"htemp5",METsign10);
 htemp6 = (TH1F*)htemp6->Rebin(rebin,"htemp6",METsign10);
 htemp7 = (TH1F*)htemp7->Rebin(rebin,"htemp7",METsign10);
 htemp8 = (TH1F*)htemp8->Rebin(rebin,"htemp8",METsign10);
 htemp9 = (TH1F*)htemp9->Rebin(rebin,"htemp9",METsign10);
 htemp10 = (TH1F*)htemp10->Rebin(rebin,"htemp10",METsign10);
 htemp11 = (TH1F*)htemp11->Rebin(rebin,"htemp11",METsign10);
 htemp12 = (TH1F*)htemp12->Rebin(rebin,"htemp12",METsign10);
 htemp13 = (TH1F*)htemp13->Rebin(rebin,"htemp13",METsign10); 
 htemp14 = (TH1F*)htemp14->Rebin(rebin,"htemp14",METsign10);
 htemp15 = (TH1F*)htemp15->Rebin(rebin,"htemp15",METsign10); 
 htemp16 = (TH1F*)htemp16->Rebin(rebin,"htemp16",METsign10);
 htemp17 = (TH1F*)htemp17->Rebin(rebin,"htemp17",METsign10); 
 htemp19 = (TH1F*)htemp19->Rebin(rebin,"htemp19",METsign10);
 } 
 
// htemp1->SetBinErrorOption(kPoisson);
 rebin = 6;
 if (title == "h_sum_signal") { 
// if (title == "h_pt_dep_4") {
 htemp1 = (TH1F*)htemp1->Rebin(rebin,"htemp1",PT);
 htemp2 = (TH1F*)htemp2->Rebin(rebin,"htemp2",PT);
 htemp3 = (TH1F*)htemp3->Rebin(rebin,"htemp3",PT);
 htemp4 = (TH1F*)htemp4->Rebin(rebin,"htemp4",PT);
 htemp5 = (TH1F*)htemp5->Rebin(rebin,"htemp5",PT);
 htemp6 = (TH1F*)htemp6->Rebin(rebin,"htemp6",PT);
 htemp7 = (TH1F*)htemp7->Rebin(rebin,"htemp7",PT);
 htemp8 = (TH1F*)htemp8->Rebin(rebin,"htemp8",PT);
 htemp9 = (TH1F*)htemp9->Rebin(rebin,"htemp9",PT);
 htemp10 = (TH1F*)htemp10->Rebin(rebin,"htemp10",PT);
 htemp11 = (TH1F*)htemp11->Rebin(rebin,"htemp11",PT);
 htemp12 = (TH1F*)htemp12->Rebin(rebin,"htemp12",PT);
 htemp13 = (TH1F*)htemp13->Rebin(rebin,"htemp13",PT); 
 htemp14 = (TH1F*)htemp14->Rebin(rebin,"htemp14",PT);
 htemp15 = (TH1F*)htemp15->Rebin(rebin,"htemp15",PT); 
 htemp16 = (TH1F*)htemp16->Rebin(rebin,"htemp16",PT);
 htemp17 = (TH1F*)htemp17->Rebin(rebin,"htemp17",PT); 
 htemp19 = (TH1F*)htemp19->Rebin(rebin,"htemp19",PT);
 }
 rebin = 12;
 if (title == "h_trans_mass_pt_CR" || title == "h_trans_mass_pt_before") {
 htemp1 = (TH1F*)htemp1->Rebin(rebin,"htemp1",MT);
 htemp2 = (TH1F*)htemp2->Rebin(rebin,"htemp2",MT);
 htemp3 = (TH1F*)htemp3->Rebin(rebin,"htemp3",MT);
 htemp4 = (TH1F*)htemp4->Rebin(rebin,"htemp4",MT);
 htemp5 = (TH1F*)htemp5->Rebin(rebin,"htemp5",MT);
 htemp6 = (TH1F*)htemp6->Rebin(rebin,"htemp6",MT);
 htemp7 = (TH1F*)htemp7->Rebin(rebin,"htemp7",MT);
 htemp8 = (TH1F*)htemp8->Rebin(rebin,"htemp8",MT);
 htemp9 = (TH1F*)htemp9->Rebin(rebin,"htemp9",MT);
 htemp10 = (TH1F*)htemp10->Rebin(rebin,"htemp10",MT);
 htemp11 = (TH1F*)htemp11->Rebin(rebin,"htemp11",MT);
 htemp12 = (TH1F*)htemp12->Rebin(rebin,"htemp12",MT);
 htemp13 = (TH1F*)htemp13->Rebin(rebin,"htemp13",MT); 
 htemp14 = (TH1F*)htemp14->Rebin(rebin,"htemp14",MT);
 htemp15 = (TH1F*)htemp15->Rebin(rebin,"htemp15",MT); 
 htemp16 = (TH1F*)htemp16->Rebin(rebin,"htemp16",MT);
 htemp17 = (TH1F*)htemp17->Rebin(rebin,"htemp17",MT); 
 htemp19 = (TH1F*)htemp19->Rebin(rebin,"htemp19",MT);
 } 
 
 rebin = 21;
  if (title == "h_tight_photon_pt_CR") {
 htemp1 = (TH1F*)htemp1->Rebin(rebin,"htemp1",PTCR);
 htemp2 = (TH1F*)htemp2->Rebin(rebin,"htemp2",PTCR);
 htemp3 = (TH1F*)htemp3->Rebin(rebin,"htemp3",PTCR);
 htemp4 = (TH1F*)htemp4->Rebin(rebin,"htemp4",PTCR);
 htemp5 = (TH1F*)htemp5->Rebin(rebin,"htemp5",PTCR);
 htemp6 = (TH1F*)htemp6->Rebin(rebin,"htemp6",PTCR);
 htemp7 = (TH1F*)htemp7->Rebin(rebin,"htemp7",PTCR);
 htemp8 = (TH1F*)htemp8->Rebin(rebin,"htemp8",PTCR);
 htemp9 = (TH1F*)htemp9->Rebin(rebin,"htemp9",PTCR);
 htemp10 = (TH1F*)htemp10->Rebin(rebin,"htemp10",PTCR);
 htemp11 = (TH1F*)htemp11->Rebin(rebin,"htemp11",PTCR);
 htemp12 = (TH1F*)htemp12->Rebin(rebin,"htemp12",PTCR);
 htemp13 = (TH1F*)htemp13->Rebin(rebin,"htemp13",PTCR); 
 htemp14 = (TH1F*)htemp14->Rebin(rebin,"htemp14",PTCR);
 htemp15 = (TH1F*)htemp15->Rebin(rebin,"htemp15",PTCR); 
 htemp16 = (TH1F*)htemp16->Rebin(rebin,"htemp16",PTCR);
 htemp17 = (TH1F*)htemp17->Rebin(rebin,"htemp17",PTCR); 
 htemp19 = (TH1F*)htemp19->Rebin(rebin,"htemp19",PTCR);
 } 
 
/* rebin = 34;
 if (title == "h_jet_pt_CR"|| title == "h_trans_mass_pt_before") {
 htemp1 = (TH1F*)htemp1->Rebin(rebin,"htemp1",PTbefore2);
 htemp2 = (TH1F*)htemp2->Rebin(rebin,"htemp2",PTbefore2);
 htemp3 = (TH1F*)htemp3->Rebin(rebin,"htemp3",PTbefore2);
 htemp4 = (TH1F*)htemp4->Rebin(rebin,"htemp4",PTbefore2);
 htemp5 = (TH1F*)htemp5->Rebin(rebin,"htemp5",PTbefore2);
 htemp6 = (TH1F*)htemp6->Rebin(rebin,"htemp6",PTbefore2);
 htemp7 = (TH1F*)htemp7->Rebin(rebin,"htemp7",PTbefore2);
 htemp8 = (TH1F*)htemp8->Rebin(rebin,"htemp8",PTbefore2);
 htemp9 = (TH1F*)htemp9->Rebin(rebin,"htemp9",PTbefore2);
 htemp10 = (TH1F*)htemp10->Rebin(rebin,"htemp10",PTbefore2);
 htemp11 = (TH1F*)htemp11->Rebin(rebin,"htemp11",PTbefore2);
 htemp12 = (TH1F*)htemp12->Rebin(rebin,"htemp12",PTbefore2);
 htemp13 = (TH1F*)htemp13->Rebin(rebin,"htemp13",PTbefore2); 
 htemp14 = (TH1F*)htemp14->Rebin(rebin,"htemp14",PTbefore2);
 htemp15 = (TH1F*)htemp15->Rebin(rebin,"htemp15",PTbefore2); 
 htemp16 = (TH1F*)htemp16->Rebin(rebin,"htemp16",PTbefore2);
 htemp17 = (TH1F*)htemp17->Rebin(rebin,"htemp17",PTbefore2); 
 htemp19 = (TH1F*)htemp19->Rebin(rebin,"htemp19",PTbefore2);
 } 
*/  
/*if (GJetsPt){
 htemp18->Rebin(rebin);
 htemp20->Rebin(rebin);
 htemp21->Rebin(rebin);
 htemp22->Rebin(rebin);
 htemp23->Rebin(rebin); 
 htemp24->Rebin(rebin);
 htemp25->Rebin(rebin); 
 htemp26->Rebin(rebin); 
 htemp27->Rebin(rebin); 
 htemp28->Rebin(rebin); 
 htemp29->Rebin(rebin); 
 } 

*/
  // Set the histogram colors & lines
	htemp1	->SetLineColor(kBlack);
  htemp1	->SetMarkerStyle(8);
	htemp2  ->SetFillColor(kCyan);
	htemp2  ->SetLineColor(kBlack);
	htemp2	->SetLineWidth(1);	
	htemp2	->SetFillStyle(1001);
	
	//vorher orange-> Gjets, green -> Vgamma, red-> ttbar, diboson->kMagenta, blue->QCD, egamma->gray+2
	
	htemp3  ->SetFillColor(kOrange);
	htemp3	->SetFillStyle(1001);
	htemp3  ->SetLineColor(kBlack);	
	htemp3	->SetLineWidth(1);	
//	htemp17 ->SetFillColor(kGreen);
//	htemp17	->SetFillStyle(1001);	
//	htemp4  ->SetFillColor(kCyan);
	htemp4  ->SetFillColor(kViolet);
	htemp4	->SetFillStyle(1001);
	htemp4  ->SetLineColor(kBlack);
	htemp4	->SetLineWidth(1);	
	htemp19 ->SetFillColor(kSpring);
	htemp19	->SetFillStyle(1001);	
	htemp16	->SetLineColor(kBlue+4); //kBlue+4
	htemp16	->SetLineWidth(3);		
	htemp17	->SetLineColor(kViolet-1); //(kPink-7);
	htemp17	->SetLineWidth(3);
//	htemp18	->SetLineColor(kRed+3);
//	htemp18	->SetLineWidth(3);
				
	if ( seperated ) {
  	htemp9	->SetFillColor(kOrange-7);
		htemp9	->SetFillStyle(1001);		
	  htemp10	->SetFillColor(kOrange+3);
		htemp10	->SetFillStyle(1001);	
		htemp11  ->SetFillColor(kOrange-3);
		htemp11	->SetFillStyle(1001);	
		htemp12  ->SetFillColor(kYellow);
		htemp12	->SetFillStyle(1001);	
		htemp13	->SetFillColor(kMagenta);
		htemp13	->SetFillStyle(1001);	
		htemp14  ->SetFillColor(kMagenta+3);
		htemp14	->SetFillStyle(1001);	
		htemp15  ->SetFillColor(kMagenta-3);
		htemp15	->SetFillStyle(1001);	
		htemp7  ->SetFillColor(kBlue+2);
		htemp7	->SetFillStyle(1001);
		htemp8  ->SetFillColor(kBlue+4);
		htemp8	->SetFillStyle(1001);
		}
	else {
  	htemp9	->SetFillColor(kRed+2);
		htemp9	->SetFillStyle(1001);		
		htemp9  ->SetLineColor(kBlack);	
  	htemp9	->SetLineWidth(1);	
	  htemp10	->SetFillColor(kOrange);
		htemp10	->SetFillStyle(1001);	
		htemp11  ->SetFillColor(kOrange);
		htemp11	->SetFillStyle(1001);	
		htemp12  ->SetFillColor(kOrange);
		htemp12	->SetFillStyle(1001);	
	  htemp13	->SetFillColor(kBlue+1);
		htemp13	->SetFillStyle(1001);	
		htemp13  ->SetLineColor(kBlack);	
  	htemp13	->SetLineWidth(1);				
		htemp14  ->SetFillColor(kMagenta);
		htemp14	->SetFillStyle(1001);	
		htemp15  ->SetFillColor(kMagenta);
		htemp15	->SetFillStyle(1001);		
		htemp7  ->SetLineColor(kBlack);	
  	htemp7	->SetLineWidth(1);		
		htemp7  ->SetFillColor(kGray+2);
		htemp7	->SetFillStyle(1001);
		htemp8  ->SetFillColor(kBlue);
		htemp8	->SetFillStyle(1001);
		
/*    if (GJetsPt) {
  	 htemp18 ->SetFillColor(kOrange);
		 htemp18 ->SetFillStyle(1001);   
  	 htemp30 ->SetFillColor(kOrange);
		 htemp30 ->SetFillStyle(1001);   
		 htemp20 ->SetFillColor(kOrange);
		 htemp20 ->SetFillStyle(1001); 
		 htemp21  ->SetFillColor(kOrange);
		 htemp21 ->SetFillStyle(1001); 
		 htemp22  ->SetFillColor(kOrange);
		 htemp22 ->SetFillStyle(1001);   
  	 htemp23 ->SetFillColor(kOrange);
		 htemp23 ->SetFillStyle(1001);   
		 htemp24 ->SetFillColor(kOrange);
		 htemp24 ->SetFillStyle(1001); 
		 htemp25  ->SetFillColor(kOrange);
		 htemp25 ->SetFillStyle(1001); 
		 htemp26  ->SetFillColor(kOrange);
		 htemp26 ->SetFillStyle(1001);   
		 htemp27  ->SetFillColor(kOrange);
		 htemp27 ->SetFillStyle(1001);   
		 htemp28  ->SetFillColor(kOrange);
		 htemp28 ->SetFillStyle(1001);   
		 htemp29  ->SetFillColor(kOrange);
		 htemp29 ->SetFillStyle(1001); 
		 } */
		}
	



/*	list< TH1F* > BGs;	
		
if ( htemp2 != 0)	BGs.push_back(htemp2);
if ( htemp3 != 0)	BGs.push_back(htemp3);
if ( htemp4 != 0)	BGs.push_back(htemp4);
if ( htemp5 != 0)	BGs.push_back(htemp5);	
if ( htemp6 != 0)	BGs.push_back(htemp6);
if ( htemp7 != 0)	BGs.push_back(htemp7);	
if ( htemp8 != 0)	BGs.push_back(htemp8);
if ( htemp9 != 0)	BGs.push_back(htemp9);	
if ( htemp10 != 0)	BGs.push_back(htemp10);
if ( htemp11 != 0)	BGs.push_back(htemp11);	
if ( htemp12 != 0)	BGs.push_back(htemp12);
	
	
	sort(BGs.begin(),BGs.end(),compare);			
//	BGs.sort(compare);
	
	
  THStack *tempStack = new THStack();
if (BGs.size() != 0){	
	list< TH1F* >::iterator iter = BGs.begin();
		
	while (iter!= BGs.end()) {	
		tempStack->Add(*iter);
		}	
	}
/*	for ( i = 0; i < 12; i++ ) {
		order[i] = BGs[i]->Integral();
		} */
		//overflow
		
/*	
	N_bins = htemp3->GetNbinsX();
	//data
	htemp1->SetBinError(N_bins, sqrt(htemp1->GetBinError(N_bins)*htemp1->GetBinError(N_bins) + htemp1->GetBinError(N_bins+1)*htemp1->GetBinError(N_bins+1)));
	htemp1->SetBinContent(N_bins, htemp1->GetBinContent(N_bins) + htemp1->GetBinContent(N_bins+1));	
	//signal 540

	htemp16->SetBinError(N_bins, sqrt(htemp16->GetBinError(N_bins)*htemp16->GetBinError(N_bins) + htemp16->GetBinError(N_bins+1)*htemp16->GetBinError(N_bins+1)));
	htemp16->SetBinContent(N_bins, htemp16->GetBinContent(N_bins) + htemp16->GetBinContent(N_bins+1));	
	//signal 640

	htemp17->SetBinError(N_bins, sqrt(htemp17->GetBinError(N_bins)*htemp17->GetBinError(N_bins) + htemp17->GetBinError(N_bins+1)*htemp17->GetBinError(N_bins+1)));
	htemp17->SetBinContent(N_bins, htemp17->GetBinContent(N_bins) + htemp17->GetBinContent(N_bins+1));		
	//Vgamma

	htemp3->SetBinError(N_bins, sqrt(htemp3->GetBinError(N_bins)*htemp3->GetBinError(N_bins) + htemp3->GetBinError(N_bins+1)*htemp3->GetBinError(N_bins+1)));
	htemp3->SetBinContent(N_bins, htemp3->GetBinContent(N_bins) + htemp3->GetBinContent(N_bins+1));	
	
	//Vgamma scaled with uncertainty up

	htemp5->SetBinError(N_bins, sqrt(htemp5->GetBinError(N_bins)*htemp5->GetBinError(N_bins) + htemp5->GetBinError(N_bins+1)*htemp5->GetBinError(N_bins+1)));
	htemp5->SetBinContent(N_bins, htemp5->GetBinContent(N_bins) + htemp5->GetBinContent(N_bins+1));	
	
	
	//ttgamma

	htemp2->SetBinError(N_bins, sqrt(htemp2->GetBinError(N_bins)*htemp2->GetBinError(N_bins) + htemp2->GetBinError(N_bins+1)*htemp2->GetBinError(N_bins+1)));
	htemp2->SetBinContent(N_bins, htemp2->GetBinContent(N_bins) + htemp2->GetBinContent(N_bins+1));	
	//gammaJets

	htemp9->SetBinError(N_bins, sqrt(htemp9->GetBinError(N_bins)*htemp9->GetBinError(N_bins) + htemp9->GetBinError(N_bins+1)*htemp9->GetBinError(N_bins+1)));
	htemp9->SetBinContent(N_bins, htemp9->GetBinContent(N_bins) + htemp9->GetBinContent(N_bins+1));	
	//QCD

	htemp7->SetBinError(N_bins, sqrt(htemp7->GetBinError(N_bins)*htemp7->GetBinError(N_bins) + htemp7->GetBinError(N_bins+1)*htemp7->GetBinError(N_bins+1)));
	htemp7->SetBinContent(N_bins, htemp7->GetBinContent(N_bins) + htemp7->GetBinContent(N_bins+1));	
	//Diboson

	htemp13->SetBinError(N_bins, sqrt(htemp13->GetBinError(N_bins)*htemp13->GetBinError(N_bins) + htemp13->GetBinError(N_bins+1)*htemp13->GetBinError(N_bins+1)));
	htemp13->SetBinContent(N_bins, htemp13->GetBinContent(N_bins) + htemp13->GetBinContent(N_bins+1));	
	//Signal
	htemp19->SetBinContent(N_bins, htemp19->GetBinContent(N_bins) + htemp19->GetBinContent(N_bins+1));
	htemp19->SetBinError(N_bins, sqrt(htemp19->GetBinError(N_bins)*htemp19->GetBinError(N_bins) + htemp19->GetBinError(N_bins+1)*htemp19->GetBinError(N_bins+1)));
	
	//Signal

	htemp21->SetBinError(N_bins, sqrt(htemp21->GetBinError(N_bins)*htemp21->GetBinError(N_bins) + htemp21->GetBinError(N_bins+1)*htemp21->GetBinError(N_bins+1)));	
	htemp21->SetBinContent(N_bins, htemp21->GetBinContent(N_bins) + htemp21->GetBinContent(N_bins+1));	
	//Signal

	htemp22->SetBinError(N_bins, sqrt(htemp22->GetBinError(N_bins)*htemp22->GetBinError(N_bins) + htemp22->GetBinError(N_bins+1)*htemp22->GetBinError(N_bins+1)));	
	htemp22->SetBinContent(N_bins, htemp22->GetBinContent(N_bins) + htemp22->GetBinContent(N_bins+1));			
	//Signal

	htemp23->SetBinError(N_bins, sqrt(htemp23->GetBinError(N_bins)*htemp23->GetBinError(N_bins) + htemp23->GetBinError(N_bins+1)*htemp23->GetBinError(N_bins+1)));	
	htemp23->SetBinContent(N_bins, htemp23->GetBinContent(N_bins) + htemp23->GetBinContent(N_bins+1));				
	//Signal
	htemp24->SetBinContent(N_bins, htemp24->GetBinContent(N_bins) + htemp24->GetBinContent(N_bins+1));
	htemp24->SetBinError(N_bins, sqrt(htemp24->GetBinError(N_bins)*htemp24->GetBinError(N_bins) + htemp24->GetBinError(N_bins+1)*htemp24->GetBinError(N_bins+1)));				
	//Signal

	htemp25->SetBinError(N_bins, sqrt(htemp25->GetBinError(N_bins)*htemp25->GetBinError(N_bins) + htemp25->GetBinError(N_bins+1)*htemp25->GetBinError(N_bins+1)));	
	htemp25->SetBinContent(N_bins, htemp25->GetBinContent(N_bins) + htemp25->GetBinContent(N_bins+1));				
	//Signal
	
	htemp26->SetBinError(N_bins, sqrt(htemp26->GetBinError(N_bins)*htemp26->GetBinError(N_bins) + htemp26->GetBinError(N_bins+1)*htemp26->GetBinError(N_bins+1)));
	htemp26->SetBinContent(N_bins, htemp26->GetBinContent(N_bins) + htemp26->GetBinContent(N_bins+1));
		
	//Signal

	htemp27->SetBinError(N_bins, sqrt(htemp27->GetBinError(N_bins)*htemp27->GetBinError(N_bins) + htemp27->GetBinError(N_bins+1)*htemp27->GetBinError(N_bins+1)));
	htemp27->SetBinContent(N_bins, htemp27->GetBinContent(N_bins) + htemp27->GetBinContent(N_bins+1));	
	//Signal

	htemp28->SetBinError(N_bins, sqrt(htemp28->GetBinError(N_bins)*htemp28->GetBinError(N_bins) + htemp28->GetBinError(N_bins+1)*htemp28->GetBinError(N_bins+1)));
	htemp28->SetBinContent(N_bins, htemp28->GetBinContent(N_bins) + htemp28->GetBinContent(N_bins+1));	
	//Signal
	htemp29->SetBinContent(N_bins, htemp29->GetBinContent(N_bins) + htemp29->GetBinContent(N_bins+1));
	htemp29->SetBinError(N_bins, sqrt(htemp29->GetBinError(N_bins)*htemp29->GetBinError(N_bins) + htemp29->GetBinError(N_bins+1)*htemp29->GetBinError(N_bins+1)));
	//Signal

	htemp30->SetBinError(N_bins, sqrt(htemp30->GetBinError(N_bins)*htemp30->GetBinError(N_bins) + htemp30->GetBinError(N_bins+1)*htemp30->GetBinError(N_bins+1)));
	htemp30->SetBinContent(N_bins, htemp30->GetBinContent(N_bins) + htemp30->GetBinContent(N_bins+1));	
	

	htemp31->SetBinError(N_bins, sqrt(htemp31->GetBinError(N_bins)*htemp31->GetBinError(N_bins) + htemp31->GetBinError(N_bins+1)*htemp31->GetBinError(N_bins+1)));
	htemp31->SetBinContent(N_bins, htemp31->GetBinContent(N_bins) + htemp31->GetBinContent(N_bins+1));	
	//Signal

	htemp32->SetBinError(N_bins, sqrt(htemp32->GetBinError(N_bins)*htemp32->GetBinError(N_bins) + htemp32->GetBinError(N_bins+1)*htemp32->GetBinError(N_bins+1)));
	htemp32->SetBinContent(N_bins, htemp32->GetBinContent(N_bins) + htemp32->GetBinContent(N_bins+1));	
	//Signal

	htemp33->SetBinError(N_bins, sqrt(htemp33->GetBinError(N_bins)*htemp33->GetBinError(N_bins) + htemp33->GetBinError(N_bins+1)*htemp33->GetBinError(N_bins+1)));
	htemp33->SetBinContent(N_bins, htemp33->GetBinContent(N_bins) + htemp33->GetBinContent(N_bins+1));	
	//Signal

	htemp34->SetBinError(N_bins, sqrt(htemp34->GetBinError(N_bins)*htemp34->GetBinError(N_bins) + htemp34->GetBinError(N_bins+1)*htemp34->GetBinError(N_bins+1)));
	htemp34->SetBinContent(N_bins, htemp34->GetBinContent(N_bins) + htemp34->GetBinContent(N_bins+1));	
		

	htemp35->SetBinError(N_bins, sqrt(htemp35->GetBinError(N_bins)*htemp35->GetBinError(N_bins) + htemp35->GetBinError(N_bins+1)*htemp35->GetBinError(N_bins+1)));
	htemp35->SetBinContent(N_bins, htemp35->GetBinContent(N_bins) + htemp35->GetBinContent(N_bins+1));	
	//Signal

	htemp36->SetBinError(N_bins, sqrt(htemp36->GetBinError(N_bins)*htemp36->GetBinError(N_bins) + htemp36->GetBinError(N_bins+1)*htemp36->GetBinError(N_bins+1)));
		htemp36->SetBinContent(N_bins, htemp36->GetBinContent(N_bins) + htemp36->GetBinContent(N_bins+1));
	//Signal

	htemp37->SetBinError(N_bins, sqrt(htemp37->GetBinError(N_bins)*htemp37->GetBinError(N_bins) + htemp37->GetBinError(N_bins+1)*htemp37->GetBinError(N_bins+1)));
	htemp37->SetBinContent(N_bins, htemp37->GetBinContent(N_bins) + htemp37->GetBinContent(N_bins+1));	
	//Signal

	htemp38->SetBinError(N_bins, sqrt(htemp38->GetBinError(N_bins)*htemp38->GetBinError(N_bins) + htemp38->GetBinError(N_bins+1)*htemp38->GetBinError(N_bins+1)));	
	htemp38->SetBinContent(N_bins, htemp38->GetBinContent(N_bins) + htemp38->GetBinContent(N_bins+1));	
	

	htemp39->SetBinError(N_bins, sqrt(htemp39->GetBinError(N_bins)*htemp39->GetBinError(N_bins) + htemp39->GetBinError(N_bins+1)*htemp39->GetBinError(N_bins+1)));
	htemp39->SetBinContent(N_bins, htemp39->GetBinContent(N_bins) + htemp39->GetBinContent(N_bins+1));	
	//Signal

	htemp40->SetBinError(N_bins, sqrt(htemp40->GetBinError(N_bins)*htemp40->GetBinError(N_bins) + htemp40->GetBinError(N_bins+1)*htemp40->GetBinError(N_bins+1)));
	htemp40->SetBinContent(N_bins, htemp40->GetBinContent(N_bins) + htemp40->GetBinContent(N_bins+1));	
	//Signal

	htemp41->SetBinError(N_bins, sqrt(htemp41->GetBinError(N_bins)*htemp41->GetBinError(N_bins) + htemp41->GetBinError(N_bins+1)*htemp41->GetBinError(N_bins+1)));
	htemp41->SetBinContent(N_bins, htemp41->GetBinContent(N_bins) + htemp41->GetBinContent(N_bins+1));	
		
*/				
	std::map<TH1F*, std::string> histoname;
	std::vector< TH1F* > BGs;	
		
	if ( htemp2 != 0)	BGs.push_back(htemp2); //ttbarGamma
//	if ( htemp3 != 0)	BGs.push_back(htemp3);
//	if ( htemp17 != 0)	BGs.push_back(htemp17);	
//	if ( htemp4 != 0)	BGs.push_back(htemp4);

	if ( htemp19 != 0)	BGs.push_back(htemp19);	//GammaPixel
	
	if ( seperated ) {
		if ( htemp7 != 0)	BGs.push_back(htemp7);	
		if ( htemp8 != 0)	BGs.push_back(htemp8);
		if ( !GJetsPt) {
     if ( htemp9 != 0) BGs.push_back(htemp9);  
     if ( htemp10 != 0)  BGs.push_back(htemp10);
     if ( htemp11 != 0)  BGs.push_back(htemp11); 
     if ( htemp12 != 0)  BGs.push_back(htemp12);
     }
		if ( htemp13 != 0)	BGs.push_back(htemp13);
		if ( htemp14 != 0)	BGs.push_back(htemp14);	
		if ( htemp15 != 0)	BGs.push_back(htemp15);		
		histoname[htemp2] = fileLabel2;
		histoname[htemp3] = fileLabel3;
//		histoname[htemp17] = fileLabel17;		
		histoname[htemp4] = fileLabel4;	
		histoname[htemp7] = fileLabel7;
		histoname[htemp8] = fileLabel8;	
		histoname[htemp9] = fileLabel9;	
		histoname[htemp10] = fileLabel10;	
		histoname[htemp11] = fileLabel11;	
		histoname[htemp12] = fileLabel12;
		histoname[htemp13] = fileLabel13;	
		histoname[htemp14] = fileLabel14;	
		histoname[htemp15] = fileLabel15;		
		
	}
	else {
		htemp3->Add(htemp4);
		htemp5->Add(htemp6);		
//		htemp5->Add(htemp6);
//		htemp5->Add(htemp7);
		htemp7->Add(htemp8);
		htemp9->Add(htemp10);
		htemp9->Add(htemp11);
		htemp9->Add(htemp12);
		htemp9->Add(htemp7);  // Add QCD to GJets
		htemp13->Add(htemp14);
		htemp13->Add(htemp15);

/*if (GJetsPt){
		htemp18->Add(htemp30);
		htemp18->Add(htemp20);		
		htemp18->Add(htemp21);		
		htemp18->Add(htemp22);		
		htemp18->Add(htemp23);		
		htemp18->Add(htemp24);		
		htemp18->Add(htemp25);
		htemp18->Add(htemp26);		
		htemp18->Add(htemp27);	
		htemp18->Add(htemp28);		
		htemp18->Add(htemp29);	
		} */
							
//		if ( htemp7 != 0)	BGs.push_back(htemp7); // if QCD seperated than uncommand
		if ( !GJetsPt) {		
	  	if ( htemp9 != 0)	BGs.push_back(htemp9); //GammaJets
			}
/*		else {
		  if ( htemp18 != 0)	BGs.push_back(htemp18);
			} */
	 	if ( htemp13 != 0)	BGs.push_back(htemp13);		//Dibo
	 	if ( htemp3 != 0)	BGs.push_back(htemp3);		 //VGamma
	// 	if ( htemp4 != 0)	BGs.push_back(htemp4);   //WGamma
		histoname[htemp1] = "#bf{#bf{Data}}";				
		histoname[htemp2] = "#bf{t#bar{t}#gamma}";
		histoname[htemp3] =  "#bf{V#gamma}";
		histoname[htemp4] =  "#bf{W#gamma}";				
//		histoname[htemp17] = fileLabel17;		
//		histoname[htemp4] = fileLabel4;	
		histoname[htemp7] = "#bf{QCD}";	
		histoname[htemp9] = "#bf{#gammaJets}";
		histoname[htemp13] = "#bf{DiBoson}";	
		histoname[htemp19] = "#bf{e#rightarrow#gamma}";	
		histoname[htemp17] = "#bf{MW_640_MB_630}";	
		histoname[htemp16] = "#bf{MW_540_MB_530}";					
/*		if (GJetsPt) {
			histoname[htemp18] = "#gammaJets";			
			} */
		}
		
	std::sort(BGs.begin(), BGs.end(), compare );
				
	bins = htemp3->GetNbinsX();	
	error_Vg = 0;
	error_gJ = 0;	
	error_gJPt = 0;
	double error_total[bins];
	
//		cout << "error scale:  " << htemp5->GetBinContent(3) << endl;	
//		cout << "error nortmal:  " << htemp3->GetBinContent(3) << endl;
//	htemp5->Add(htemp3,-1);
//		cout << "error scale:  " << htemp5->GetBinContent(3) << endl;	
//		cout << "error nortmal:  " << htemp3->GetBinContent(3) << endl;		
		
	for ( int i = 1; i < (bins+1); i++) {
		error_Vg = htemp3->GetBinContent(i)*(scale_ISR_error/scale_ISR);
	//	error_Vg =error_Vg + (htemp4->GetBinContent(i)*(sqrt((scale_ISR_error/scale_ISR)*(scale_ISR_error/scale_ISR) + (trigger_error*trigger_error) )));			
	//	cout << "error VG:  " << error_Vg << endl;
//		error_Vg = sqrt( error_Vg*error_Vg + (htemp5->GetBinContent(i)*htemp5->GetBinContent(i)) );
		error_gJ = htemp9->GetBinContent(i)*(scale_GJets_error/scale_GJets);
		error_e_fake = (htemp19->GetBinContent(i)/e_Fakerate)*e_fake_error;
		error_qcd = htemp7->GetBinContent(i)*(sqrt((qcd_error*qcd_error) + (trigger_error*trigger_error)+ (lumi_error*lumi_error))); //Pay attention if QCD is added to GJets
		error_tt  = htemp2->GetBinContent(i)*(sqrt((tt_error*tt_error) + (trigger_error*trigger_error)+ (lumi_error*lumi_error)));		
		error_dibo = (htemp13->GetBinContent(i))*(sqrt((dibo_error*dibo_error) + (trigger_error*trigger_error)+ (lumi_error*lumi_error)));			
	//	error_total[i-1] = sqrt((error_Vg * error_Vg) + (error_gJ * error_gJ) + (error_e_fake * error_e_fake) + (error_qcd * error_qcd) + (error_tt * error_tt) +
	//	(error_dibo * error_dibo));
		error_total[i-1] = error_Vg + error_gJ + error_e_fake + error_qcd + error_tt + error_dibo;		
		}
	
  THStack *tempStack = new THStack();
/*if (BGs.size() != 0){	
	vector< TH1F* >::iterator iter = BGs.begin();
		
	while (iter!= BGs.end()) {	
		tempStack->Add(*iter);
		}	
	}	 */
	
	for ( unsigned int i = 0; i < BGs.size(); i++) {
	  tempStack->Add(BGs[i]);
//		histoname[BGs[i]]
		}	
		

  // Turn off stats
  if (!showStatsBoxes) {
    gStyle->SetOptStat(0);
  }
	
	
	TH1F *denumerator = (TH1F*)htemp2->Clone("denumerator");
  denumerator->Add(htemp3);  //VGamma	
//  denumerator->Add(htemp17);	
//  denumerator->Add(htemp4);  // WGamma in ZGamma combined
	denumerator->Add(htemp19);  //GammaPixel
	if ( seperated ) {	
  	denumerator->Add(htemp7);	
  	denumerator->Add(htemp8);
		denumerator->Add(htemp9);
  	denumerator->Add(htemp10);
  	denumerator->Add(htemp11);	
  	denumerator->Add(htemp12);
  	denumerator->Add(htemp13);
  	denumerator->Add(htemp14);	
  	denumerator->Add(htemp15);			
	  }
	else {
 //		denumerator->Add(htemp7);	//if QCD seperated -> Add to denumerator!!
 		denumerator->Add(htemp13); //Dibo
		if ( !GJetsPt) {
			denumerator->Add(htemp9); //GJets
			}
/*		else {
			denumerator->Add(htemp18);
			}			*/
		}
		
	canvasDefault->cd();	
	canvasDefault->Clear();	
	gStyle->SetPadTickX(1);
  gStyle->SetPadTickY(1);
	canvasDefault->cd();	
	TH1F *data = (TH1F*)htemp1->Clone("data");
	string xtitle = data->GetXaxis()->GetTitle();
		
	TH1F *h_Vg_safe = (TH1F*)htemp3->Clone("h_Vg_safe");
	TH1F *h_ratio = (TH1F*)htemp3->Clone("h_ratio");	
	TH1F *h_stat_uncertainty = (TH1F*)htemp3->Clone("h_stat_uncertainty");		
	THStack *h_stack_safe = (THStack*)tempStack->Clone("h_stack_safe");	
	THStack *h_mid = (THStack*)tempStack->Clone("h_mid");	
	TH1F *h_uncertainty = (TH1F*)h_mid->GetStack()->Last();
	
	
 	for ( int i = 1; i < (bins+1); i++) {
		 //h_uncertainty->SetBinContent(i,tempStack->GetStack()->Last()->GetBinContent(i)); //i); //tempStack->GetHistogram()->GetBinContent(i));
		 h_uncertainty->SetBinError(i,error_total[i-1]);
//		 h_uncertainty->SetBinError(i,sqrt((((h_uncertainty->GetBinContent(i))*lumi_error) * ((h_uncertainty->GetBinContent(i))*lumi_error)) +
//		 (error_total[i-1] * error_total[i-1])));	
	//	 h_uncertainty->SetBinError(i,h_uncertainty->GetBinContent(i)*lumi_error + error_total[i-1]);		
		 h_stat_uncertainty->SetBinContent(i,1);	
		 h_stat_uncertainty->SetBinError(i,(denumerator->GetBinError(i)/denumerator->GetBinContent(i)));		 	 
	//	 h_ratio->SetBinError(i,(error_total[i-1]/h_uncertainty->GetBinContent(i)));
	   h_ratio->SetBinError(i,(h_uncertainty->GetBinError(i)/h_uncertainty->GetBinContent(i)));
		 h_ratio->SetBinContent(i,1);		 	
		 }		
	h_uncertainty->SetLineColor(kRed);
	h_uncertainty->SetFillColor(kRed);	
	h_uncertainty->SetFillStyle(3354);
	h_uncertainty->SetMarkerSize(2);	
	h_stat_uncertainty->SetLineColor(kBlue);
	h_stat_uncertainty->SetFillColor(kBlue);	
	h_stat_uncertainty->SetFillStyle(3345);	
	h_stat_uncertainty->SetMarkerSize(2);
	h_ratio->SetLineColor(kRed);
	h_ratio->SetFillColor(kRed);	
	h_ratio->SetFillStyle(3354);
	h_ratio->SetMarkerSize(2);		
			
//	canvasDefault_1 = new TPad("canvasDefault_1", "newpad",0.0,0.0,1.0,0.1);//0.325);	
	if (plot_data){
	
/*********************************Aufpassen****************************/	
//	TH1F *numerator = (TH1F*)htemp1->Clone("numerator");	
//	numerator->Divide(denumerator);


	TH1F *numerator = (TH1F*)htemp1->Clone("numerator");
	numerator->Divide(denumerator);
//	numerator->Add(htemp19,-1);
//	numerator->Add(htemp9,-1);	
//	numerator->Add(htemp13,-1);	
//	numerator->Add(htemp2,-1);
//  numerator->Divide(htemp3);
	numerator->SetTitle("");
	numerator->SetMaximum(2.2);	
	numerator->SetMinimum(0.1);
//	numerator->SetMaximum(4.);	
//	numerator->SetMinimum(0.3);
	numerator->SetLineWidth(1);	
//	numerator->GetYaxis()->SetMoreLogLabels();
	numerator->GetYaxis()->SetNdivisions(5);	
	numerator->GetXaxis()->SetNdivisions(5);		
  numerator->GetYaxis()->SetTitle("Data / bkg");
//  numerator->GetXaxis()->SetTitle("S_{T}^{#gamma} [GeV]");	
//  numerator->GetYaxis()->CenterTitle();	
  numerator->GetYaxis()->SetTitleSize(0.158);
  numerator->GetXaxis()->SetTitleSize(0.15);		
	numerator->GetYaxis()->SetLabelSize(0.15);
	numerator->GetXaxis()->SetLabelSize(0.15);
	numerator->GetXaxis()->SetLabelOffset(0.02);	
  numerator->GetYaxis()->SetTitleOffset(0.35);
  numerator->GetXaxis()->SetTitleOffset(0.95);
	//0.95
	
	//TF1 *poly = new TF1("poly","[0]+[1]*pow(x-[2],2)",2.2,2.5);
			
  canvasDefault_1 = new TPad("canvasDefault_1", "newpad",0.0,0.0,1.0,0.325);//0.325);		
//  canvasDefault_1->SetLogy(1);	
  canvasDefault_1->SetTopMargin(0.01);
  canvasDefault_1->SetBottomMargin(0.35);
  canvasDefault_1->SetRightMargin(0.1);
  canvasDefault_1->SetLeftMargin(0.12);	
  canvasDefault_1->SetFillStyle(0);
  canvasDefault_1->cd(); 
	numerator->Draw("E1");
	numerator->SetMarkerSize(1.4);
	h_ratio->Draw("same E2");
	h_stat_uncertainty->Draw("same E2");
	numerator->Draw("same E1");	
	gPad->SetGrid();
	gStyle->SetGridStyle(3);	

	TF1 *f1 = new TF1("f","pol1",30,1000);	
	TF1 *f3 = new TF1("f","pol3",30,1000);
  f1->SetLineWidth(2);	
/*  numerator->Fit(f1,"S");
//	TF1 *myfunc = numerator->GetFunction("myfunc");
     TFitResultPtr r = numerator->Fit(f1,"S");
     TMatrixDSym cov = r->GetCovarianceMatrix();  //  to access the covariance matrix
     Double_t par0   = r->Parameter(0); // retrieve the value for the parameter 0
     Double_t err0   = r->ParError(0); // retrieve the error for the parameter 0
     r->Print("V");     // print full information of fit including covariance matrix
    // r->Write();*/
		 
  f3->SetLineWidth(2);	
/*  numerator->Fit(f3);	
	TH1F *fit3 = (TH1F*)numerator->Clone("fit3");	
	(TVirtualFitter::GetFitter())->GetConfidenceIntervals(fit3,0.68);	
   //Now the "hint" histogram has the fitted function values as the 
   //bin contents and the confidence intervals as bin errors
  // fit->SetStats(kFALSE);
   fit3->SetFillColor(kBlack);
   fit3->SetMarkerStyle(1);	 
   fit3->Draw("e5 a same");
	 fit3->SetFillStyle(3002);	*/
	 
/*	TH1F *fit = (TH1F*)numerator->Clone("fit");	
	(TVirtualFitter::GetFitter())->GetConfidenceIntervals(fit,0.68);	
   //Now the "hint" histogram has the fitted function values as the 
   //bin contents and the confidence intervals as bin errors
  // fit->SetStats(kFALSE);
   fit->SetFillColor(kRed);
   fit->SetMarkerStyle(1);	 
   fit->Draw("e5 a same");
	 fit->SetFillStyle(3002);	
	 numerator->Draw("same E0");
 //  TF1 *fitresult = numerator->GetFunction("f1");
//	 fitresult->GetChisquare();
//	 gMinuit->mnmatu(1);
//	 TMatrixD matrix0(2,2);
//	 gMinuit->mnemat(matrix0.GetMatrixArray(),2);
//	 matrix0.Print();
/*  canvasDefault_3 = new TPad("canvasDefault_1", "newpad",0.0,0.325,1.0,0.4);//0.325);		
	TH1F *plain = (TH1F*)htemp1->Clone("plain");
	plain->SetNdivisions(0);
//  canvasDefault_3->SetTopMargin(0.01);
//  canvasDefault_3->SetBottomMargin(0.35);
//  canvasDefault_3->SetRightMargin(0.1);
  canvasDefault_3->SetFillStyle(0);
  canvasDefault_3->cd(); 
	plain->Draw("");*/
	
	//numerator->Draw();	
	
	infoBoxError = new TLegend(0.5, 0.78, 0.89, 0.89,"");//0.75, 0.83, 0.99, 0.99, "");	
	infoBoxError->AddEntry(h_ratio,"#bf{#sigma^{syst}}","f");
	infoBoxError->AddEntry(h_stat_uncertainty,"#bf{#sigma^{stat}}","f");	
  infoBoxError->SetFillStyle(0);	
  infoBoxError->SetShadowColor(0);  // 0 = transparent
  infoBoxError->SetFillColor(kWhite); 
	infoBoxError->SetBorderSize(0);
	infoBoxError->SetTextSize(0.19);
	infoBoxError->SetNColumns(2);	
  infoBoxError->Draw();	
  canvasDefault->cd();
	canvasDefault_1->Draw();
	canvasDefault->cd();	
	}
	
	 
  data->GetXaxis()->SetTitleSize(0.15);
	data->GetXaxis()->SetLabelSize(0.06);	
	data->GetYaxis()->SetLabelSize(0.07);
	data->GetYaxis()->SetTitle("Events / unit");
	data->GetYaxis()->SetTitleSize(0.08);
//	data->GetXaxis()->SetTitleOffset(0.9);
	data->GetXaxis()->SetTitleOffset(1.3);
	data->GetXaxis()->SetLabelOffset(1.3);			
	data->GetYaxis()->SetTitleOffset(0.75);
	data->SetMinimum(minimum);
	data->SetMarkerSize(1.4);
	data->SetTitle("");
	data->SetLineWidth(1);
 	
	if (plot_data) {	

	 canvasDefault_2 = new TPad("canvasDefault_2", "newpad",0.0,0.315,1,1); //0.32
	 canvasDefault_2->Draw(); 
 	 canvasDefault_2->cd();
 	 canvasDefault_2->SetTopMargin(0.1);
 	 canvasDefault_2->SetBottomMargin(0.01);
 	 canvasDefault_2->SetRightMargin(0.1);
	 canvasDefault_2->SetLeftMargin(0.12);	
 	 canvasDefault_2->SetFillStyle(0);		 
	 data->GetXaxis()->SetTitleSize(0.0);
	// data->GetYaxis()->SetNdivisions(20);
	 data->SetMaximum(1.5*data->GetMaximum());
	// data->SetMaximum(2);	 
	 data->Draw("E1");
	 tempStack->Draw("same hist f");	 		
	 h_uncertainty->Draw("same E2");
	 data->Draw("same E1");
//	 gPad->SetGrid();		 	
	 }
/*
	cout << "_____________________________________________________________________" << endl;
	cout << "_____________________________________________________________________" << endl;	
  cout << "Region:   " << title << endl;
	cout << "BG:   " << histoname[htemp2] << endl;
	cout << "BG yield:   " <<htemp2->GetBinContent(1) << endl;
	cout << "BG syst uncertainty abs:   " << htemp2->GetBinContent(1)*(sqrt((tt_error*tt_error) + (trigger_error*trigger_error)+	(lumi_error*lumi_error))) << endl;	
	cout << "BG stat uncertainty abs:   " <<htemp2->GetBinError(1) << endl;	
	cout << "------------------------------------------------------------" << endl;	 
	cout << "BG:   " << histoname[htemp3] << endl;
	cout << "BG yield:   " <<htemp3->GetBinContent(1) << endl;
	cout << "BG syst uncertainty abs:   " << htemp3->GetBinContent(1)*(scale_ISR_error/scale_ISR) << endl;	
	cout << "BG stat uncertainty abs:   " <<htemp3->GetBinError(1) << endl;	
	cout << "------------------------------------------------------------" << endl;	
	cout << "BG:   " << histoname[htemp7] << endl;
	cout << "BG yield:   " <<htemp7->GetBinContent(1) << endl;
	cout << "BG syst uncertainty abs:   " << htemp7->GetBinContent(1)*(sqrt((qcd_error*qcd_error) + (trigger_error*trigger_error)+	(lumi_error*lumi_error))) << endl;	
	cout << "BG stat uncertainty abs:   " <<htemp7->GetBinError(1) << endl;	
	cout << "------------------------------------------------------------" << endl;	
	cout << "BG:   " << histoname[htemp9] << endl;
	cout << "BG yield:   " <<htemp9->GetBinContent(1) << endl;
	cout << "BG syst uncertainty abs:   " << htemp9->GetBinContent(1)*(scale_GJets_error/scale_GJets) << endl;	
	cout << "BG stat uncertainty abs:   " <<htemp9->GetBinError(1) << endl;	
	cout << "------------------------------------------------------------" << endl;		
	cout << "BG:   " << histoname[htemp13] << endl;
	cout << "BG yield:   " <<htemp13->GetBinContent(1) << endl;
	cout << "BG syst uncertainty abs:   " << htemp13->GetBinContent(1)*(sqrt((dibo_error*dibo_error) + (trigger_error*trigger_error)+	(lumi_error*lumi_error))) << endl;	
	cout << "BG stat uncertainty abs:   " <<htemp13->GetBinError(1) << endl;	
	cout << "------------------------------------------------------------" << endl;			
	cout << "BG:   " << histoname[htemp19] << endl;
	cout << "BG yield:   " <<htemp19->GetBinContent(1) << endl;
	cout << "BG syst uncertainty abs:   " << htemp19->GetBinContent(1)/e_Fakerate*e_fake_error << endl;	
	cout << "BG stat uncertainty abs:   " <<htemp19->GetBinError(1) << endl;	
	cout << "------------------------------------------------------------" << endl;			
	cout << "_____________________________________________________________________" << endl;	 
	cout << "_____________________________________________________________________" << endl;	 
	cout << "_____________________________________________________________________" << endl;
  cout << "Region:   " << title << endl;
	cout << "Signal:   " << histoname[htemp17] << endl;
	cout << "Signal yield:   " <<htemp17->GetBinContent(1) << endl;
	cout << "Signal stat. uncertainty:   " <<htemp17->GetBinError(1) << endl;	
	cout << "------------------------------------------------------------" << endl;
	cout << "Signal:   " << fileLabel16 << endl;
	cout << "Signal yield:   " <<htemp16->GetBinContent(1) << endl;
	cout << "Signal stat. uncertainty:   " <<htemp16->GetBinError(1) << endl;	
	cout << "------------------------------------------------------------" << endl;
	cout << "Signal:   " << fileLabel21 << endl;
	cout << "Signal yield:   " <<htemp21->GetBinContent(1) << endl;
	cout << "Signal stat. uncertainty:   " <<htemp21->GetBinError(1) << endl;	
	cout << "------------------------------------------------------------" << endl;
	cout << "Signal:   " << fileLabel22 << endl;
	cout << "Signal yield:   " <<htemp22->GetBinContent(1) << endl;
	cout << "Signal stat. uncertainty:   " <<htemp22->GetBinError(1) << endl;	
	cout << "------------------------------------------------------------" << endl;	
	cout << "Signal:   " << fileLabel23 << endl;
	cout << "Signal yield:   " <<htemp23->GetBinContent(1) << endl;
	cout << "Signal stat. uncertainty:   " <<htemp23->GetBinError(1) << endl;	
	cout << "------------------------------------------------------------" << endl;
	cout << "Signal:   " << fileLabel24 << endl;
	cout << "Signal yield:   " <<htemp24->GetBinContent(1) << endl;
	cout << "Signal stat. uncertainty:   " <<htemp24->GetBinError(1) << endl;	
	cout << "------------------------------------------------------------" << endl;	
	cout << "Signal:   " << fileLabel25 << endl;
	cout << "Signal yield:   " <<htemp25->GetBinContent(1) << endl;
	cout << "Signal stat. uncertainty:   " <<htemp25->GetBinError(1) << endl;	
	cout << "------------------------------------------------------------" << endl;
	cout << "Signal:   " << fileLabel26 << endl;
	cout << "Signal yield:   " <<htemp26->GetBinContent(1) << endl;
	cout << "Signal stat. uncertainty:   " <<htemp26->GetBinError(1) << endl;	
	cout << "------------------------------------------------------------" << endl;		
	cout << "Signal:   " << fileLabel27 << endl;
	cout << "Signal yield:   " <<htemp27->GetBinContent(1) << endl;
	cout << "Signal stat. uncertainty:   " <<htemp27->GetBinError(1) << endl;	
	cout << "------------------------------------------------------------" << endl;
	cout << "Signal:   " << fileLabel28 << endl;
	cout << "Signal yield:   " <<htemp28->GetBinContent(1) << endl;
	cout << "Signal stat. uncertainty:   " <<htemp28->GetBinError(1) << endl;	
	cout << "------------------------------------------------------------" << endl;		
	cout << "Signal:   " << fileLabel29 << endl;
	cout << "Signal yield:   " <<htemp29->GetBinContent(1) << endl;
	cout << "Signal stat. uncertainty:   " <<htemp29->GetBinError(1) << endl;	
	cout << "------------------------------------------------------------" << endl;
	cout << "Signal:   " << fileLabel30 << endl;
	cout << "Signal yield:   " <<htemp30->GetBinContent(1) << endl;
	cout << "Signal stat. uncertainty:   " <<htemp30->GetBinError(1) << endl;	
	cout << "------------------------------------------------------------" << endl;	
	cout << "Signal:   " << fileLabel31 << endl;
	cout << "Signal yield:   " <<htemp31->GetBinContent(1) << endl;
	cout << "Signal stat. uncertainty:   " <<htemp31->GetBinError(1) << endl;	
	cout << "------------------------------------------------------------" << endl;
	cout << "Signal:   " << fileLabel32 << endl;
	cout << "Signal yield:   " <<htemp32->GetBinContent(1) << endl;
	cout << "Signal stat. uncertainty:   " <<htemp32->GetBinError(1) << endl;	
	cout << "------------------------------------------------------------" << endl;	
	cout << "Signal:   " << fileLabel33 << endl;
	cout << "Signal yield:   " <<htemp33->GetBinContent(1) << endl;
	cout << "Signal stat. uncertainty:   " <<htemp33->GetBinError(1) << endl;	
	cout << "------------------------------------------------------------" << endl;
	cout << "Signal:   " << fileLabel34 << endl;
	cout << "Signal yield:   " <<htemp34->GetBinContent(1) << endl;
	cout << "Signal stat. uncertainty:   " <<htemp34->GetBinError(1) << endl;	
	cout << "------------------------------------------------------------" << endl;	
	cout << "Signal:   " << fileLabel35 << endl;
	cout << "Signal yield:   " <<htemp35->GetBinContent(1) << endl;
	cout << "Signal stat. uncertainty:   " <<htemp35->GetBinError(1) << endl;	
	cout << "------------------------------------------------------------" << endl;
	cout << "Signal:   " << fileLabel36 << endl;
	cout << "Signal yield:   " <<htemp36->GetBinContent(1) << endl;
	cout << "Signal stat. uncertainty:   " <<htemp36->GetBinError(1) << endl;	
	cout << "------------------------------------------------------------" << endl;		
	cout << "Signal:   " << fileLabel37 << endl;
	cout << "Signal yield:   " <<htemp37->GetBinContent(1) << endl;
	cout << "Signal stat. uncertainty:   " <<htemp37->GetBinError(1) << endl;	
	cout << "------------------------------------------------------------" << endl;
	cout << "Signal:   " << fileLabel38 << endl;
	cout << "Signal yield:   " <<htemp38->GetBinContent(1) << endl;
	cout << "Signal stat. uncertainty:   " <<htemp38->GetBinError(1) << endl;	
	cout << "------------------------------------------------------------" << endl;		
	cout << "Signal:   " << fileLabel39 << endl;
	cout << "Signal yield:   " <<htemp39->GetBinContent(1) << endl;
	cout << "Signal stat. uncertainty:   " <<htemp39->GetBinError(1) << endl;	
	cout << "------------------------------------------------------------" << endl;
	cout << "Signal:   " << fileLabel40 << endl;
	cout << "Signal yield:   " <<htemp40->GetBinContent(1) << endl;
	cout << "Signal stat. uncertainty:   " <<htemp40->GetBinError(1) << endl;	
	cout << "------------------------------------------------------------" << endl;	
	cout << "Signal:   " << fileLabel41 << endl;
	cout << "Signal yield:   " <<htemp41->GetBinContent(1) << endl;
	cout << "Signal stat. uncertainty:   " <<htemp41->GetBinError(1) << endl;	
	cout << "------------------------------------------------------------" << endl;

*/	
	
/*	cout << "------------------------------------------------------------" << endl;	
	cout << "Data yield:     " << htemp1->GetBinContent(1) << endl;
	cout << "BG yield:       " << h_uncertainty->GetBinContent(1) << endl;
	cout << "BG stat. uncertainty:       " << h_stat_uncertainty->GetBinError(1)*h_uncertainty->GetBinContent(1) << endl;	
	cout << "BG syst. uncertainty:       " << h_uncertainty->GetBinError(1)<< endl;	
*/		
	if (!plot_data){
	
	  canvasDefault_2 = new TPad("canvasDefault_2", "newpad",0.0,0.0,1,1); //0.32
	  canvasDefault_2->Draw(); 
 	  canvasDefault_2->cd();
 	  canvasDefault_2->SetTopMargin(0.1);
 	  canvasDefault_2->SetBottomMargin(0.13);
 	  canvasDefault_2->SetRightMargin(0.1);
 	  canvasDefault_2->SetFillStyle(0);	
	//	data->GetXaxis()->SetTitleSize(0.5); 

		//data->Draw("AXIS");		
  	tempStack->Draw("hist f");	
		canvasDefault->Update();		
		canvasDefault->Modified();				
	  tempStack->GetHistogram()->GetXaxis()->SetTitle(xtitle.c_str());	
		tempStack->GetHistogram()->GetXaxis()->SetTitleSize(0.055);
		tempStack->GetHistogram()->GetXaxis()->SetLabelSize(0.05);	
		tempStack->GetHistogram()->GetYaxis()->SetLabelSize(0.06);
		tempStack->GetHistogram()->GetYaxis()->SetTitle("Events / bin");
		tempStack->GetHistogram()->GetYaxis()->SetTitleSize(0.06);
		tempStack->GetHistogram()->GetXaxis()->SetTitleOffset(1);	
		tempStack->GetHistogram()->GetYaxis()->SetTitleOffset(1);

		tempStack->GetHistogram()->SetMinimum(minimum);
		tempStack->SetMinimum(minimum);
		tempStack->GetHistogram()->SetMaximum(1.5*tempStack->GetMaximum());
		tempStack->SetMaximum(1.5*tempStack->GetMaximum());		
		tempStack->GetHistogram()->SetTitle("");
		tempStack->Draw("same hist f");		
		canvasDefault->Modified();					
		canvasDefault->Draw();
		h_uncertainty->Draw("same E2");
	//	gPad->RedrawAxis();		
		}
		
/*	tempStack->GetXaxis()->SetTitleSize(0.1);
	tempStack->GetXaxis()->SetLabelSize(0.05);  
	tempStack->GetYaxis()->SetLabelSize(0.05);
	tempStack->GetYaxis()->SetTitle("# events");
	tempStack->GetYaxis()->SetTitleSize(0.05);
  tempStack->GetXaxis()->SetTitleOffset(0.01);	
  tempStack->GetYaxis()->SetTitleOffset(1);	*/
//	gPad->Update();
//	data->Draw("same E1");
		
//	htemp18->Draw("same hist");	
	htemp17->Draw("same hist");
	htemp16->Draw("same hist");	
	//gPad->RedrawAxis();	
//	data->GetXaxis()->SetTitle("");
//  tempStack->SetTitle(title);
 // tempStack->GetXaxis()->SetTitle(data->GetXaxis()->GetTitle());
//  tempStack->GetYaxis()->SetTitle("# events");
 // canvasDefault_2->Draw();	
	

  // Draw the legend
	if (plot_data){	
  infoBoxData = new TLegend(0.5, 0.82, 0.89, 0.89,"");//0.75, 0.83, 0.99, 0.99, "");	
	infoBoxData->AddEntry(htemp1,fileLabel1,"lep");
  infoBoxData->SetFillStyle(0);	
  infoBoxData->SetShadowColor(0);  // 0 = transparent
  infoBoxData->SetFillColor(kWhite); 
	infoBoxData->SetBorderSize(0);
	infoBoxData->SetTextSize(0.058);
  infoBoxData->Draw();		
  infoBox = new TLegend(0.5, 0.6, 0.89, 0.83,"");//0.75, 0.83, 0.99, 0.99, "");  infoBox = new TLegend(0.66, 0.49, 0.9, 0.89,"");
//  infoBox->AddEntry(htemp1,fileLabel1,"lep");	
	for ( int i = 0; i < BGs.size(); i++) {
		int size = BGs.size() - 1;
	  int reverse = size - i;
	  infoBox->AddEntry(BGs[reverse],histoname[BGs[reverse]].c_str() , "f"); 
		}
	infoBox->AddEntry(h_uncertainty,"#bf{#sigma^{syst}}","f");
//  infoBox->AddEntry(htemp18,fileLabel18,"l");		
	infoBox->SetNColumns(2);
//  infoBox->AddEntry(htemp16,"M_{Wino} = 540 GeV","l");	
//  infoBox->AddEntry(htemp17,"M_{Wino} = 640 GeV","l");
  infoBox->SetFillStyle(0);	
  infoBox->SetShadowColor(0);  // 0 = transparent
  infoBox->SetFillColor(kWhite); 
	infoBox->SetBorderSize(0);
	infoBox->SetTextSize(0.058);
  infoBox->Draw();
  infoBoxSignal = new TLegend(0.5, 0.49, 0.89, 0.59,"");//0.75, 0.83, 0.99, 0.99, "");	
	infoBoxSignal->AddEntry(htemp16,"#bf{M_{Wino} = 540 GeV}","l");
	infoBoxSignal->AddEntry(htemp17,"#bf{M_{Wino} = 640 GeV}","l");
  infoBoxSignal->SetFillStyle(0);	
  infoBoxSignal->SetShadowColor(0);  // 0 = transparent
  infoBoxSignal->SetFillColor(kWhite); 
	infoBoxSignal->SetBorderSize(0);
	infoBoxSignal->SetTextSize(0.058);
  infoBoxSignal->Draw();	
  cout << "Data:   " << htemp1->Integral(0,-1) << endl;	
  cout << "B:   " << h_uncertainty->Integral(0,-1) << endl;
  cout << "S:   " << htemp17->Integral(0,-1) << endl;		
	
//	CMS_text = new TLatex(0.1,0.91,"#int L dt = 7.4 fb^{-1},  #sqrt{S} = 8 TeV,   CMS PRIVATE WORK");
//  CMS_text = new TLatex(0.1,0.91,"#scale[1.2]{CMS}#scale[0.5]{ }#scale[0.8]{#bf{#it{Private Work}}}#bf{, 7.4 fb^{-1} (8 TeV)}");
  CMS_text = new TLatex(0.11,0.92,"#scale[1.2]{CMS}#scale[7]{   }#bf{L_{int} = 7.4 fb^{-1}  (8 TeV),  #geq1#gamma + MET}");
	CMS_text->SetNDC();
  CMS_text->SetTextSize(0.058);
  CMS_text->Draw();	

/*	CMS_text = new TLatex(0.37,0.82,"#int L dt = 7.4 fb^{-1},  #sqrt{S} = 8 TeV");
	CMS_text->SetNDC();
  CMS_text->SetTextSize(0.05);
  CMS_text->Draw();	*/
	CMS_text2 = new TLatex(0.42,0.77,"CMS PRIVATE WORK");
	CMS_text2->SetNDC();
  CMS_text2->SetTextSize(0.05);
//  CMS_text2->Draw(); 
	
	canvasDefault_2->SetLogy(0);
	canvasDefault->SaveAs(filename+"_lin."+imageType);
  canvasDefault_2->SetLogy(1);	
	
	
	}
	else {
	infoBoxData = new TLegend(0.5, 0.81, 0.89, 0.89,"");//0.75, 0.83, 0.99, 0.99, "");	
	infoBoxData->AddEntry(htemp1,fileLabel1,"lep");
  infoBoxData->SetFillStyle(0);	
  infoBoxData->SetShadowColor(0);  // 0 = transparent
  infoBoxData->SetFillColor(kWhite); 
	infoBoxData->SetBorderSize(0);
	infoBoxData->SetTextSize(0.039);
 // infoBoxData->Draw();		
  infoBox = new TLegend(0.5, 0.7, 0.89, 0.89,"");//0.75, 0.83, 0.99, 0.99, "");  infoBox = new TLegend(0.66, 0.49, 0.9, 0.89,"");
//  infoBox->AddEntry(htemp1,fileLabel1,"lep");	
	for ( int i = 0; i < BGs.size(); i++) {
		int size = BGs.size() - 1;
	  int reverse = size - i;
	  infoBox->AddEntry(BGs[reverse],histoname[BGs[reverse]].c_str() , "f"); 
		}	
	infoBox->AddEntry(h_uncertainty,"#bf{#sigma_{syst}}","f");
//  infoBox->AddEntry(htemp18,fileLabel18,"l");		
	infoBox->SetNColumns(2);
//  infoBox->AddEntry(htemp16,"M_{Wino} = 540 GeV","l");	
//  infoBox->AddEntry(htemp17,"M_{Wino} = 640 GeV","l");
  infoBox->SetFillStyle(0);	
  infoBox->SetShadowColor(0);  // 0 = transparent
  infoBox->SetFillColor(kWhite); 
	infoBox->SetBorderSize(0);
	infoBox->SetTextSize(0.039);
  infoBox->Draw();
  infoBoxSignal = new TLegend(0.5, 0.62, 0.89, 0.69,"");//0.75, 0.83, 0.99, 0.99, "");	
	infoBoxSignal->AddEntry(htemp16,"#bf{M_{Wino} = 540 GeV}","l");
	infoBoxSignal->AddEntry(htemp17,"#bf{M_{Wino} = 640 GeV}","l");
  infoBoxSignal->SetFillStyle(0);	
  infoBoxSignal->SetShadowColor(0);  // 0 = transparent
  infoBoxSignal->SetFillColor(kWhite); 
	infoBoxSignal->SetBorderSize(0);
	infoBoxSignal->SetTextSize(0.039);
  infoBoxSignal->Draw();	
/*  infoBox = new TLegend(0.64, 0.55, 0.9, 0.89,"");//0.75, 0.83, 0.99, 0.99, "");
	for ( int i = 0; i < BGs.size(); i++) {
		int size = BGs.size() - 1;
	  int reverse = size - i;
	  infoBox->AddEntry(BGs[reverse],histoname[BGs[reverse]].c_str() , "f"); 
		}	
//  infoBox->AddEntry(htemp18,fileLabel18,"l");	
//  infoBox->AddEntry(htemp16,fileLabel16,"l");	
//  infoBox->AddEntry(htemp17,fileLabel17,"l");
  infoBox->AddEntry(htemp16,"M_{Wino} = 540 GeV","l");	
  infoBox->AddEntry(htemp17,"M_{Wino} = 640 GeV","l");
  infoBox->SetFillStyle(0);	
  infoBox->SetShadowColor(0);  // 0 = transparent
  infoBox->SetFillColor(kWhite); 
	infoBox->SetBorderSize(0);
	infoBox->SetTextSize(0.035);
  infoBox->Draw(); */	
	
	//CMS_text = new TLatex(0.1,0.91,"#int L dt = 7.4 fb^{-1},  #sqrt{S} = 8 TeV,   CMS PRIVATE WORK");  
//	CMS_text = new TLatex(0.1,0.91,"#scale[1.2]{CMS}#scale[0.5]{ }#scale[0.8]{#bf{#it{Private Work}}}#bf{, 7.4 fb^{-1} (8 TeV)}");
	CMS_text = new TLatex(0.11,0.92,"#scale[1.2]{CMS}#scale[7]{   }#bf{L_{int} = 7.4 fb^{-1}  (8 TeV),  #geq1#gamma + MET}");	
	CMS_text->SetNDC();
  CMS_text->SetTextSize(0.037);
  CMS_text->Draw();		
/*	CMS_text = new TLatex(0.34,0.82,"#int L dt = 7.4 fb^{-1},  #sqrt{S} = 8 TeV");
	CMS_text->SetNDC();
  CMS_text->SetTextSize(0.035);
  CMS_text->Draw();	
	CMS_text2 = new TLatex(0.4,0.77,"CMS PRIVATE WORK");
	CMS_text2->SetNDC();
  CMS_text2->SetTextSize(0.035);
  CMS_text2->Draw(); */
	
//	canvasDefault->Draw();	
	canvasDefault_2->SetLogy(0);
	canvasDefault->SaveAs(filename+"_lin."+imageType);
  canvasDefault_2->SetLogy(1);		
	}

	double stack_max = tempStack->GetMaximum();
	double data_max = data->GetMaximum();
	double signal_max = htemp16->GetMaximum();
	
	if ( plot_data){
		data->SetMaximum(4*data_max);
		if ( data_max < stack_max ) {
			data->SetMaximum(4*stack_max);
			}			
		data->SetMinimum(minimum);						
//		data->SetMinimum(0.05);	
		data->Draw("E1");			
 	  tempStack->Draw("same hist f");
//		htemp18->Draw("same hist");					
		h_uncertainty->Draw("same E2");
		htemp17->Draw("same hist");
		htemp16->Draw("same hist");			
		data->Draw("same E1");		
		gPad->RedrawAxis();
	}
	
	if ( !plot_data){ 
	  tempStack->GetHistogram()->SetMaximum(2*stack_max);
	  tempStack->SetMaximum(2*stack_max);				
		if ( signal_max > stack_max ) {
	    tempStack->GetHistogram()->SetMaximum(2*signal_max);	
	    tempStack->SetMaximum(2*signal_max);				
			}	
		tempStack->GetHistogram()->SetMinimum(minimum);
		tempStack->SetMinimum(minimum);					
	 	tempStack->Draw("hist f");	
		canvasDefault->Update();		
		canvasDefault->Modified();						
	  tempStack->GetHistogram()->GetXaxis()->SetTitle(xtitle.c_str());	
		tempStack->GetHistogram()->GetXaxis()->SetTitleSize(0.055);
		tempStack->GetHistogram()->GetXaxis()->SetLabelSize(0.05);	
		tempStack->GetHistogram()->GetYaxis()->SetLabelSize(0.05);
		tempStack->GetHistogram()->GetYaxis()->SetTitle("Events / bin");
		tempStack->GetHistogram()->GetYaxis()->SetTitleSize(0.06);
		tempStack->GetHistogram()->GetXaxis()->SetTitleOffset(1);	
		tempStack->GetHistogram()->GetYaxis()->SetTitleOffset(0.95);
	//	tempStack->GetHistogram()->SetMinimum(0.001);
		tempStack->GetHistogram()->SetTitle("");
		tempStack->Draw("same hist f");	
	//	data->SetMaximum(stack_max+(stack_max/2));
	//	data->SetMinimum(0.01);			
		//data->Draw("AXIS");	
	//	tempStack->SetMinimum(0.01);
//		htemp18->Draw("same hist");
//		h_uncertainty->Draw("same E2");		
//		htemp17->Add(h_uncertainty);
//		htemp16->Add(h_uncertainty);
		htemp17->Draw("same hist");
		htemp16->Draw("same hist");	
		h_uncertainty->Draw("same E2");
	//	canvasDefault->Update();	
	//	gPad->RedrawAxis();
	} 

  CMS_text->Draw();
//  if( !plot_data ){
//	  CMS_text2->Draw();
//		}
	if (plot_data){
		infoBoxData->Draw();
		}
	infoBox->Draw();	
	infoBoxSignal->Draw();	
	canvasDefault->SaveAs(filename+"_log."+imageType);
	}
}


void recurseOverKeys( TDirectory *target1 ) {

  // Figure out where we are
  TString path( (char*)strstr( target1->GetPath(), ":" ) );
  path.Remove( 0, 2 );

  sourceFile1->cd( path );
  
  TDirectory *current_sourcedir = gDirectory;

  TKey *key;
  TIter nextkey(current_sourcedir->GetListOfKeys());

  while ( key = (TKey*)nextkey() ) {

    obj = key->ReadObj();

    // Check if this is a 1D histogram or a directory
    if (obj->IsA()->InheritsFrom("TH1F")) {

      // **************************
      // Plot & Save this Histogram
      TH1F *htemp1, *htemp2, *htemp3, *htemp4, *htemp5, *htemp6, *htemp7, *htemp8, *htemp9, *htemp10,
			*htemp11, *htemp12, *htemp13, *htemp14, *htemp15, *htemp16, *htemp17, *htemp19,
			*htemp21, *htemp22, *htemp23, *htemp24, *htemp25,	*htemp26, *htemp27, *htemp28, *htemp29, *htemp30, 
			*htemp31, *htemp32, *htemp33, *htemp34, *htemp35,	*htemp36, *htemp37, *htemp38, *htemp39, *htemp40,
			*htemp41;


      htemp1 = (TH1F*)obj;
      TString histName = htemp1->GetName();

      if (path != "") {
        sourceFile2->GetObject(path+"/"+histName, htemp2);
        sourceFile3->GetObject(path+"/"+histName, htemp3);				
        sourceFile4->GetObject(path+"/"+histName, htemp4);
        sourceFile5->GetObject(path+"/"+histName, htemp5);				
        sourceFile6->GetObject(path+"/"+histName, htemp6);				
        sourceFile7->GetObject(path+"/"+histName, htemp7);				
        sourceFile8->GetObject(path+"/"+histName, htemp8);
        sourceFile9->GetObject(path+"/"+histName, htemp9);
								
        sourceFile10->GetObject(path+"/"+histName, htemp10);				
        sourceFile11->GetObject(path+"/"+histName, htemp11);
        sourceFile12->GetObject(path+"/"+histName, htemp12);	
        sourceFile13->GetObject(path+"/"+histName, htemp13);				
        sourceFile14->GetObject(path+"/"+histName, htemp14);
        sourceFile15->GetObject(path+"/"+histName, htemp15);
        sourceFile16->GetObject(path+"/"+histName, htemp16);																				
        sourceFile17->GetObject(path+"/"+histName, htemp17);			
        sourceFile19->GetObject(path+"/"+histName, htemp19);	
												
        sourceFile21->GetObject(path+"/"+histName, htemp21);
        sourceFile22->GetObject(path+"/"+histName, htemp22);	
        sourceFile23->GetObject(path+"/"+histName, htemp23);				
        sourceFile24->GetObject(path+"/"+histName, htemp24);
        sourceFile25->GetObject(path+"/"+histName, htemp25);
        sourceFile26->GetObject(path+"/"+histName, htemp26);																				
        sourceFile27->GetObject(path+"/"+histName, htemp27);				
        sourceFile28->GetObject(path+"/"+histName, htemp28);																				
        sourceFile29->GetObject(path+"/"+histName, htemp29);
					
        sourceFile30->GetObject(path+"/"+histName, htemp30);				
        sourceFile31->GetObject(path+"/"+histName, htemp31);
        sourceFile32->GetObject(path+"/"+histName, htemp32);	
        sourceFile33->GetObject(path+"/"+histName, htemp33);				
        sourceFile34->GetObject(path+"/"+histName, htemp34);
        sourceFile35->GetObject(path+"/"+histName, htemp35);
        sourceFile36->GetObject(path+"/"+histName, htemp36);																				
        sourceFile37->GetObject(path+"/"+histName, htemp37);				
        sourceFile38->GetObject(path+"/"+histName, htemp38);																				
        sourceFile39->GetObject(path+"/"+histName, htemp39);
				
        sourceFile40->GetObject(path+"/"+histName, htemp40);				
        sourceFile41->GetObject(path+"/"+histName, htemp41);
											
							
      } else {
			sourceFile2->GetObject(histName, htemp2);
			sourceFile3->GetObject(histName, htemp3);
			sourceFile4->GetObject(histName, htemp4);
			sourceFile5->GetObject(histName, htemp5);
			sourceFile6->GetObject(histName, htemp6);			
      sourceFile7->GetObject(histName, htemp7);				
      sourceFile8->GetObject(histName, htemp8);
      sourceFile9->GetObject(histName, htemp9);	
						
      sourceFile10->GetObject(histName, htemp10);				
      sourceFile11->GetObject(histName, htemp11);
      sourceFile12->GetObject(histName, htemp12);			
      sourceFile13->GetObject(histName, htemp13);				
      sourceFile14->GetObject(histName, htemp14);
      sourceFile15->GetObject(histName, htemp15);
      sourceFile16->GetObject(histName, htemp16);		
      sourceFile17->GetObject(histName, htemp17);			
      sourceFile19->GetObject(histName, htemp19);
							 					
      sourceFile21->GetObject(histName, htemp21);
      sourceFile22->GetObject(histName, htemp22);     		
      sourceFile23->GetObject(histName, htemp23);				
      sourceFile24->GetObject(histName, htemp24);
      sourceFile25->GetObject(histName, htemp25);
      sourceFile26->GetObject(histName, htemp26);		
      sourceFile27->GetObject(histName, htemp27);			
      sourceFile28->GetObject(histName, htemp28);		
      sourceFile29->GetObject(histName, htemp29);
					
      sourceFile30->GetObject(histName, htemp30);							
      sourceFile31->GetObject(histName, htemp31);
      sourceFile32->GetObject(histName, htemp32);     		
      sourceFile33->GetObject(histName, htemp33);				
      sourceFile34->GetObject(histName, htemp34);
      sourceFile35->GetObject(histName, htemp35);
      sourceFile36->GetObject(histName, htemp36);		
      sourceFile37->GetObject(histName, htemp37);			
      sourceFile38->GetObject(histName, htemp38);		
      sourceFile39->GetObject(histName, htemp39);	
						
      sourceFile40->GetObject(histName, htemp40);							
      sourceFile41->GetObject(histName, htemp41);
 		
										
   
		 }

      outputFilename=histName;
      plotHistograms( htemp1, htemp2, htemp3, htemp4, htemp5, htemp6, htemp7, htemp8, htemp9, htemp10,
			htemp11, htemp12, htemp13, htemp14, htemp15, htemp16, htemp17, htemp19,
			htemp21, htemp22, htemp23, htemp24, htemp25, htemp26, htemp27, htemp28, htemp29, htemp30,
			htemp31, htemp32, htemp33, htemp34, htemp35, htemp36, htemp37, htemp38, htemp39, htemp40,
			htemp41, outputFolder+path+"/"+outputFilename );

    } else if ( obj->IsA()->InheritsFrom( "TDirectory" ) ) {
      // it's a subdirectory

      cout << "Found subdirectory " << obj->GetName() << endl;
      gSystem->MakeDirectory(outputFolder+path+"/"+obj->GetName());

      // obj is now the starting point of another round of merging
      // obj still knows its depth within the target file via
      // GetPath(), so we can still figure out where we are in the recursion
      recurseOverKeys( (TDirectory*)obj );

      } // end of IF a TDriectory 
  }
}
int plot() {

  // If file labels were not given as argument,
  // use the filename as a label
TH1::SetDefaultSumw2();	
//fileLabel1.ReplaceAll("_V06.1_sel_blind.root","");	
fileLabel1.ReplaceAll("PhotonParkedD_V06.1_sel.root","#bf{Data}");
fileLabel2.ReplaceAll("_V02.1_sel.root","");
fileLabel3.ReplaceAll("Add.root","");
fileLabel5.ReplaceAll("Add.root","");
fileLabel6.ReplaceAll("Add.root","");
fileLabel17.ReplaceAll(".root","");		
fileLabel4.ReplaceAll("_V02.1_sel.root","");		
fileLabel7.ReplaceAll("_V02.1_sel.root","");		
fileLabel8.ReplaceAll("_V02.1_sel.root","");		
fileLabel9.ReplaceAll("_V06.1_sel.root","");		
fileLabel10.ReplaceAll("_V02.1_sel.root","");		
fileLabel11.ReplaceAll("_V02.1_sel.root","");
fileLabel12.ReplaceAll("_V02.1_sel.root","");	
fileLabel13.ReplaceAll("_V06.1_sel.root","");		
fileLabel14.ReplaceAll("_V06.1_sel.root","");
fileLabel15.ReplaceAll("_V06.1_sel.root","");
fileLabel16.ReplaceAll(".root","");
fileLabel19.ReplaceAll(".root","");
//fileLabel18.ReplaceAll("_30_50_V07.1_sel.root","");
//  label1 = fileLabel1;
//  label2 = fileLabel2;

  showStatsBoxes = showStats;
	
  sourceFile1 = TFile::Open( fileName1 );
  sourceFile2 = TFile::Open( fileName2 );
  sourceFile3 = TFile::Open( fileName3 );
  sourceFile4 = TFile::Open( fileName4 );
  sourceFile5 = TFile::Open( fileName5 );
  sourceFile6 = TFile::Open( fileName6 );	
  sourceFile7 = TFile::Open( fileName7 );
  sourceFile8 = TFile::Open( fileName8 );	
  sourceFile9 = TFile::Open( fileName9 );
	
  sourceFile10 = TFile::Open( fileName10 );
  sourceFile11 = TFile::Open( fileName11 );
  sourceFile12 = TFile::Open( fileName12 );		
  sourceFile13 = TFile::Open( fileName13 );
  sourceFile14 = TFile::Open( fileName14 );
  sourceFile15 = TFile::Open( fileName15 );			
  sourceFile16 = TFile::Open( fileName16 );
  sourceFile17 = TFile::Open( fileName17 );	
  sourceFile19 = TFile::Open( fileName19 );	
	
  sourceFile21 = TFile::Open( fileName21 );
  sourceFile22 = TFile::Open( fileName22 );		
  sourceFile23 = TFile::Open( fileName23 );
  sourceFile24 = TFile::Open( fileName24 );
  sourceFile25 = TFile::Open( fileName25 );			
  sourceFile26 = TFile::Open( fileName26 );
  sourceFile27 = TFile::Open( fileName27 );
  sourceFile28 = TFile::Open( fileName28 );
  sourceFile29 = TFile::Open( fileName29 );	
	
  sourceFile30 = TFile::Open( fileName30 );
  sourceFile31 = TFile::Open( fileName31 );
  sourceFile32 = TFile::Open( fileName32 );		
  sourceFile33 = TFile::Open( fileName33 );
  sourceFile34 = TFile::Open( fileName34 );
  sourceFile35 = TFile::Open( fileName35 );			
  sourceFile36 = TFile::Open( fileName36 );
  sourceFile37 = TFile::Open( fileName37 );
  sourceFile38 = TFile::Open( fileName38 );
  sourceFile39 = TFile::Open( fileName39 );
	
  sourceFile40 = TFile::Open( fileName40 );		
  sourceFile41 = TFile::Open( fileName41 );

	
		 
  outputFolder = "HistogramsTogether"; // Blank to use current directory,
                                          // or, for a specific dir type
                                          // something like "images/"
  gSystem->MakeDirectory(outputFolder);

  canvasDefault = new TCanvas("canvasDefault","testCanvas",outputWidth,outputHeight);
//	canvasDefault->Range(0,0,1,1);

  // This function will plot all histograms from 
  // file1 against matching histogram from file2
	
  recurseOverKeys(sourceFile1);

  sourceFile1->Close();
  sourceFile2->Close();
  sourceFile3->Close();
	sourceFile4->Close();
  sourceFile5->Close();
	sourceFile6->Close();	
  sourceFile7->Close();
	sourceFile8->Close();	
  sourceFile9->Close();
	
  sourceFile10->Close();
  sourceFile11->Close();
	sourceFile12->Close();	
  sourceFile13->Close();
  sourceFile14->Close();
	sourceFile15->Close();
	sourceFile16->Close();		
	sourceFile17->Close();	
  sourceFile19->Close();
	
  sourceFile21->Close();
	sourceFile22->Close();	
  sourceFile23->Close();
  sourceFile24->Close();
	sourceFile25->Close();
	sourceFile26->Close();		
	sourceFile27->Close();	
	sourceFile28->Close();		
	sourceFile29->Close();
		
  sourceFile30->Close();
  sourceFile31->Close();
	sourceFile32->Close();	
  sourceFile33->Close();
  sourceFile34->Close();
	sourceFile35->Close();
	sourceFile36->Close();		
	sourceFile37->Close();	
	sourceFile38->Close();		
	sourceFile39->Close();
		
  sourceFile40->Close();
  sourceFile41->Close();


  TString currentDir = gSystem->pwd();
//  cout << "Done. See images in:" << endl << currentDir << "/" << outputFolder << endl;
	
	return 0;
}




