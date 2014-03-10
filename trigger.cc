#include <string>
#include <iostream>
#include <math.h>
#include <fstream.h>
#include <algorithm>

#include <TH1.h>
#include <TStyle.h>
#include <THStack.h>
#include <TCanvas.h>
#include <TLegend.h>
#include <TROOT.h>
#include <TFile.h>
#include <TCanvas.h>
#include <TGraphAsymmErrors.h>
#include <TEfficiency.h>


using namespace std;

int trigger(){



  TFile *Data  			= new TFile("PhotonParkedD_V06.1_sel.root");
//  TFile *Data  	= new TFile("PhotonParkedD_METstud.1_sel.root"); //Single Photon Parked dataset!
	TFile *DataMET  			= new TFile("METParkedD_V06.1_sel.root");
//  TFile *Data  			= new TFile("MinimumBias_V07.1_sel.root");
//	TFile *Data2  			= new TFile("PhotonHadD_V02.1_sel.root");

	
	TH1F *H_Data_triggereff_metcross_mytrigger;
	TH1F *H_Data_triggereff_metcross_crosstrigger;
	TH1F *H_Data_triggereff_photonptcross_mytrigger_vor;
	TH1F *H_Data_triggereff_photonptcross_crosstrigger_vor;
	TH1F *H_Data_triggereff_photonptcross_mytrigger_vor2;
	TH1F *H_Data_triggereff_photonptcross_crosstrigger_vor2;		
	TH1F *H_triggereff_metcross_mytrigger2;
	TH1F *H_triggereff_metcross_crosstrigger2;	
	TH1F *H_triggereff_metcross_mytrigger3;
	TH1F *H_triggereff_metcross_crosstrigger3;
	
	TH1F *H_denumerator_loose_eta;
	TH1F *H_denumerator_loose_eta_r9;		
	TH1F *H_numerator_loose_eta;
	TH1F *H_numerator_loose_eta_r9;	
	TH1F *H_denumerator_tight_eta;
	TH1F *H_denumerator_tight_eta_r9;		
	TH1F *H_numerator_tight_eta;
	TH1F *H_numerator_tight_eta_r9;	
	TH1F *H_denumerator_all_loose_eta;
	TH1F *H_denumerator_all_loose_eta_r9;	
	TH1F *H_numerator_all_loose_eta;
	TH1F *H_numerator_all_loose_eta_r9;	

	TH1F *H_numerator_final_pt_leg_tight_1; 
	TH1F *H_denumerator_final_pt_leg_tight_1; 
	TH1F *H_numerator_final_ID_leg_tight_1; 
	TH1F *H_denumerator_final_ID_leg_tight_1; 		
	TH1F *H_numerator_final_met_leg_tight_1; 
	TH1F *H_denumerator_final_met_leg_tight_1; 
	TH1F *H_numerator_final_pt_leg_tight_2; 
	TH1F *H_denumerator_final_pt_leg_tight_2; 
	TH1F *H_numerator_final_pt_leg_tight_woMETcut_2; 
	TH1F *H_denumerator_final_pt_leg_tight_woMETcut_2; 
	TH1F *H_numerator_final_met_leg_tight_2; 
	TH1F *H_denumerator_final_met_leg_tight_2; 
	
	TH1F *H_numerator_final_pt_leg_loose_1; 
	TH1F *H_denumerator_final_pt_leg_loose_1; 
	TH1F *H_numerator_final_ID_leg_loose_1; 
	TH1F *H_denumerator_final_ID_leg_loose_1; 		
	TH1F *H_numerator_final_met_leg_loose_1; 
	TH1F *H_denumerator_final_met_leg_loose_1; 
	TH1F *H_numerator_final_pt_leg_loose_2; 
	TH1F *H_denumerator_final_pt_leg_loose_2; 
	TH1F *H_numerator_final_pt_leg_loose_woMETcut_2; 
	TH1F *H_denumerator_final_pt_leg_loose_woMETcut_2; 
	TH1F *H_numerator_final_met_leg_loose_2; 
	TH1F *H_denumerator_final_met_leg_loose_2;	
	
//	H_denumerator_r9_2 = (TH1F*)DataMET->Get("h_denumerator_r9_2");
//	H_numerator_r9_2 = (TH1F*)DataMET->Get("h_numerator_r9_2");		
	
	H_denumerator_MET_corr_wo_1 = (TH1F*)Data->Get("h_denumerator_MET_corr_wo_1");
	H_denumerator_MET_corr_1 = (TH1F*)Data->Get("h_denumerator_MET_corr_1");		
	H_denumerator_MET_corr_2 = (TH1F*)DataMET->Get("h_denumerator_MET_corr_2");
		
	H_numerator_MET_corr_wo_1 = (TH1F*)Data->Get("h_numerator_MET_corr_wo_1");
	H_numerator_MET_corr_1 = (TH1F*)Data->Get("h_numerator_MET_corr_1");		
	H_numerator_MET_corr_2 = (TH1F*)DataMET->Get("h_numerator_MET_corr_2");	
	
	H_denumerator_JET_corr_wo_1 = (TH1F*)Data->Get("h_denumerator_JET_corr_wo_1");
	H_denumerator_JET_corr_1 = (TH1F*)Data->Get("h_denumerator_JET_corr_1");		
	H_denumerator_JET_corr_2 = (TH1F*)DataMET->Get("h_denumerator_JET_corr_2");
		
	H_numerator_JET_corr_wo_1 = (TH1F*)Data->Get("h_numerator_JET_corr_wo_1");
	H_numerator_JET_corr_1 = (TH1F*)Data->Get("h_numerator_JET_corr_1");		
	H_numerator_JET_corr_2 = (TH1F*)DataMET->Get("h_numerator_JET_corr_2");
		
	H_numerator_MET_calc = (TH1F*)Data->Get("h_numerator_MET_calc");	
	H_denumerator_MET_calc = (TH1F*)Data->Get("h_denumerator_MET_calc");	
	
	H_numerator_DeltaRCut_DeltaPhiCut_PtCut_2 = (TH1F*)DataMET->Get("h_numerator_DeltaRCut_DeltaPhiCut_PtCut_2");		
	H_denumerator_DeltaRCut_DeltaPhiCut_PtCut_2 = (TH1F*)DataMET->Get("h_denumerator_DeltaRCut_DeltaPhiCut_PtCut_2");	

//	H_numerator_DeltaRCut2_DeltaPhiCut_PtCut_2 = (TH1F*)DataMET->Get("h_numerator_DeltaRCut2_DeltaPhiCut_PtCut_2");		
//	H_denumerator_DeltaRCut2_DeltaPhiCut_PtCut_2 = (TH1F*)DataMET->Get("h_denumerator_DeltaRCut2_DeltaPhiCut_PtCut_2");	
	
//	H_numerator_DeltaRCut_DeltaPhiCut_PtCut_100_2 = (TH1F*)DataMET->Get("h_numerator_DeltaRCut_DeltaPhiCut_PtCut_100_2");		
//	H_denumerator_DeltaRCut_DeltaPhiCut_PtCut_100_2 = (TH1F*)DataMET->Get("h_denumerator_DeltaRCut_DeltaPhiCut_PtCut_100_2");		
	
	H_numerator_DeltaRCut_PtCut_2 = (TH1F*)DataMET->Get("h_numerator_DeltaRCut_PtCut_2");		
	H_denumerator_DeltaRCut_PtCut_2 = (TH1F*)DataMET->Get("h_denumerator_DeltaRCut_PtCut_2");		
	H_numerator_DeltaRCut_2 = (TH1F*)DataMET->Get("h_numerator_DeltaRCut_2");		
	H_denumerator_DeltaRCut_2 = (TH1F*)DataMET->Get("h_denumerator_DeltaRCut_2");		
	
		
	H_numerator_final_pt_leg_tight_1 = (TH1F*)Data->Get("h_numerator_final_pt_leg_tight_1"); 
	H_denumerator_final_pt_leg_tight_1 = (TH1F*)Data->Get("h_denumerator_final_pt_leg_tight_1"); 
	H_numerator_final_ID_leg_tight_1 = (TH1F*)Data->Get("h_numerator_final_ID_leg_tight_1"); 
	H_denumerator_final_ID_leg_tight_1 = (TH1F*)Data->Get("h_denumerator_final_ID_leg_tight_1"); 		
	H_numerator_final_ID_leg_tight_wo_1 = (TH1F*)Data->Get("h_numerator_final_ID_leg_tight_wo_1"); 
	H_denumerator_final_ID_leg_tight_wo_1 = (TH1F*)Data->Get("h_denumerator_final_ID_leg_tight_wo_1"); 	
	H_numerator_final_met_leg_tight_1 = (TH1F*)Data->Get("h_numerator_final_met_leg_tight_1"); 
	H_denumerator_final_met_leg_tight_1 = (TH1F*)Data->Get("h_denumerator_final_met_leg_tight_1"); 
	H_numerator_final_pt_leg_tight_2 = (TH1F*)DataMET->Get("h_numerator_final_pt_leg_tight_2"); 
	H_denumerator_final_pt_leg_tight_2 = (TH1F*)DataMET->Get("h_denumerator_final_pt_leg_tight_2"); 
	H_numerator_final_pt_leg_tight_woMETcut_2 = (TH1F*)DataMET->Get("h_numerator_final_pt_leg_tight_woMETcut_2"); 
	H_denumerator_final_pt_leg_tight_woMETcut_2 = (TH1F*)DataMET->Get("h_denumerator_final_pt_leg_tight_woMETcut_2");
	H_numerator_final_pt_leg_tight_40_2 = (TH1F*)DataMET->Get("h_numerator_final_pt_leg_tight_40_2"); 
	H_denumerator_final_pt_leg_tight_40_2 = (TH1F*)DataMET->Get("h_denumerator_final_pt_leg_tight_40_2");	
	 
	H_numerator_final_met_leg_tight_2 = (TH1F*)Data->Get("h_numerator_final_met_leg_tight_2"); 
	H_denumerator_final_met_leg_tight_2 = (TH1F*)Data->Get("h_denumerator_final_met_leg_tight_2");
	
	H_numerator_final_pt_leg_loose_1 = (TH1F*)Data->Get("h_numerator_final_pt_leg_loose_1"); 
	H_denumerator_final_pt_leg_loose_1 = (TH1F*)Data->Get("h_denumerator_final_pt_leg_loose_1"); 
	H_numerator_final_ID_leg_loose_1 = (TH1F*)Data->Get("h_numerator_final_ID_leg_loose_1"); 
	H_denumerator_final_ID_leg_loose_1 = (TH1F*)Data->Get("h_denumerator_final_ID_leg_loose_1"); 
	H_numerator_final_ID_leg_loose_wo_1 = (TH1F*)Data->Get("h_numerator_final_ID_leg_loose_wo_1"); 
	H_denumerator_final_ID_leg_loose_wo_1 = (TH1F*)Data->Get("h_denumerator_final_ID_leg_loose_wo_1"); 	
			
	H_numerator_final_met_leg_loose_1 = (TH1F*)Data->Get("h_numerator_final_met_leg_loose_1"); 
	H_denumerator_final_met_leg_loose_1 = (TH1F*)Data->Get("h_denumerator_final_met_leg_loose_1"); 
	H_numerator_final_pt_leg_loose_2 = (TH1F*)DataMET->Get("h_numerator_final_pt_leg_loose_2"); 
	H_denumerator_final_pt_leg_loose_2 = (TH1F*)DataMET->Get("h_denumerator_final_pt_leg_loose_2"); 
	H_numerator_final_pt_leg_loose_woMETcut_2 = (TH1F*)DataMET->Get("h_numerator_final_pt_leg_loose_woMETcut_2"); 
	H_denumerator_final_pt_leg_loose_woMETcut_2 = (TH1F*)DataMET->Get("h_denumerator_final_pt_leg_loose_woMETcut_2"); 
	H_numerator_final_met_leg_loose_2 = (TH1F*)Data->Get("h_numerator_final_met_leg_loose_2"); 
	H_denumerator_final_met_leg_loose_2 = (TH1F*)Data->Get("h_denumerator_final_met_leg_loose_2");	
	
/*	H_numerator_final_pt_leg_loose_2 = (TH1F*)Data->Get("h_numerator_final_pt_leg_loose_2"); 
	H_denumerator_final_pt_leg_loose_2 = (TH1F*)Data->Get("h_denumerator_final_pt_leg_loose_2"); 
	H_numerator_final_pt_leg_loose_woMETcut_2 = (TH1F*)Data->Get("h_numerator_final_pt_leg_loose_woMETcut_2"); 
	H_denumerator_final_pt_leg_loose_woMETcut_2 = (TH1F*)Data->Get("h_denumerator_final_pt_leg_loose_woMETcut_2"); 	
	H_numerator_final_pt_leg_tight_2 = (TH1F*)Data->Get("h_numerator_final_pt_leg_tight_2"); 
	H_denumerator_final_pt_leg_tight_2 = (TH1F*)Data->Get("h_denumerator_final_pt_leg_tight_2"); 
	H_numerator_final_pt_leg_tight_woMETcut_2 = (TH1F*)Data->Get("h_numerator_final_pt_leg_tight_woMETcut_2"); 
	H_denumerator_final_pt_leg_tight_woMETcut_2 = (TH1F*)Data->Get("h_denumerator_final_pt_leg_tight_woMETcut_2"); 	*/
	
	
//	H_numerator_final_met_leg_loose_wo = (TH1F*)Data->Get("h_numerator_final_met_leg_loose_wo"); 
//	H_denumerator_final_met_leg_loose_wo = (TH1F*)Data->Get("h_denumerator_final_met_leg_loose_wo");	
		
	
	
	H_denumerator_loose_eta = (TH1F*)Data->Get("h_denumerator_loose_eta");
	H_denumerator_loose_eta_r9 = (TH1F*)Data->Get("h_denumerator_loose_eta_r9");	
	H_numerator_loose_eta = (TH1F*)Data->Get("h_numerator_loose_eta");
	H_numerator_loose_eta_r9 = (TH1F*)Data->Get("h_numerator_loose_eta_r9");	
	H_denumerator_tight_eta = (TH1F*)Data->Get("h_denumerator_tight_eta");
	H_denumerator_tight_eta_r9 = (TH1F*)Data->Get("h_denumerator_tight_eta_r9");	
	H_numerator_tight_eta = (TH1F*)Data->Get("h_numerator_tight_eta");
	H_numerator_tight_eta_r9 = (TH1F*)Data->Get("h_numerator_tight_eta_r9");	
	H_denumerator_all_loose_eta = (TH1F*)Data->Get("h_denumerator_all_loose_eta");
	H_denumerator_all_loose_eta_r9 = (TH1F*)Data->Get("h_denumerator_all_loose_eta_r9");	
	H_numerator_all_loose_eta = (TH1F*)Data->Get("h_numerator_all_loose_eta");
	H_numerator_all_loose_eta_r9 = (TH1F*)Data->Get("h_numerator_all_loose_eta_r9");
	H_denumerator_all_loose_eta_r9_e5x5 = (TH1F*)Data->Get("h_denumerator_all_loose_eta_r9_e5x5");
	H_numerator_all_loose_eta_r9_e5x5 = (TH1F*)Data->Get("h_numerator_all_loose_eta_r9_e5x5");	
	
	H_numerator_trigger = (TH1F*)Data->Get("h_numerator_trigger");
	H_denumerator_trigger = (TH1F*)Data->Get("h_denumerator_trigger");	
	
	
	H_numerator_tight_eta_r9->GetYaxis()->SetTitle("Efficiency");	
	H_denumerator_tight_eta_r9->GetXaxis()->SetTitle("1st tight photon p_T");	
	H_numerator_tight_eta_r9->GetXaxis()->SetTitle("1st tight photon p_T");
	
	H_denumerator_loose_eta->Rebin(2.5);
	H_denumerator_loose_eta_r9->Rebin(2.5);
	H_numerator_loose_eta->Rebin(2.5);
	H_numerator_loose_eta_r9->Rebin(2.5);	
	H_denumerator_tight_eta->Rebin(2.5);
	H_denumerator_tight_eta_r9->Rebin(2.5);	
	H_numerator_tight_eta->Rebin(2.5);
	H_numerator_tight_eta_r9->Rebin(2.5);	
	H_denumerator_all_loose_eta->Rebin(2.5);
	H_denumerator_all_loose_eta_r9->Rebin(2.5);	
	H_numerator_all_loose_eta->Rebin(2.5);
	H_numerator_all_loose_eta_r9->Rebin(2.5);	
	H_denumerator_all_loose_eta_r9_e5x5->Rebin(2.5);
	H_numerator_all_loose_eta_r9_e5x5->Rebin(2.5);		
	
	H_numerator_trigger->Rebin(2.5);
	H_denumerator_trigger->Rebin(2.5);
	
	H_denumerator_JET_corr_wo_1->Rebin(2);
	H_numerator_JET_corr_wo_1->Rebin(2);	
	H_denumerator_JET_corr_1->Rebin(2);
	H_numerator_JET_corr_1->Rebin(2);	
	H_denumerator_JET_corr_2->Rebin(2);
	H_numerator_JET_corr_2->Rebin(2);	
	/////////////////////
	
//	H_numerator_DeltaRCut2_DeltaPhiCut_PtCut_2->Rebin(4);
//	H_denumerator_DeltaRCut2_DeltaPhiCut_PtCut_2->Rebin(4);

	H_numerator_MET_calc->Rebin(80);
	H_denumerator_MET_calc->Rebin(80);	
	
	
	H_numerator_DeltaRCut_2->Rebin(4);
	H_denumerator_DeltaRCut_2->Rebin(4);
	
	H_numerator_final_ID_leg_tight_1->Rebin(4);
	H_denumerator_final_ID_leg_tight_1->Rebin(4); 		
	H_numerator_final_ID_leg_tight_wo_1->Rebin(4);
	H_denumerator_final_ID_leg_tight_wo_1->Rebin(4);
		
	H_numerator_final_ID_leg_loose_1->Rebin(4);
	H_denumerator_final_ID_leg_loose_1->Rebin(4);
	H_numerator_final_ID_leg_loose_wo_1->Rebin(4); 
	H_denumerator_final_ID_leg_loose_wo_1->Rebin(4);	
	
	H_numerator_final_pt_leg_tight_woMETcut_2->Rebin(4);
	H_denumerator_final_pt_leg_tight_woMETcut_2->Rebin(4);
	H_numerator_final_pt_leg_tight_40_2->Rebin(4);
	H_denumerator_final_pt_leg_tight_40_2->Rebin(4);
	
	H_numerator_final_pt_leg_loose_2->Rebin(4);
	H_denumerator_final_pt_leg_loose_2->Rebin(4); 
	H_numerator_final_pt_leg_loose_woMETcut_2->Rebin(4);
	H_denumerator_final_pt_leg_loose_woMETcut_2->Rebin(4); 
	
	
	H_numerator_DeltaRCut_PtCut_2->Rebin(4);
	H_denumerator_DeltaRCut_PtCut_2->Rebin(4);	
	H_numerator_DeltaRCut_DeltaPhiCut_PtCut_2->Rebin(4);
	H_denumerator_DeltaRCut_DeltaPhiCut_PtCut_2->Rebin(4);
//	H_numerator_DeltaRCut_DeltaPhiCut_PtCut_100_2->Rebin(80);
//	H_denumerator_DeltaRCut_DeltaPhiCut_PtCut_100_2->Rebin(80);


//	 H_Data_triggereff_metcross_mytrigger = (TH1F*)Data->Get("h_triggereff_metcross_mytrigger");
//	 H_Data_triggereff_metcross_crosstrigger = (TH1F*)Data->Get("h_triggereff_metcross_crosstrigger");
	
	H_Data_triggereff_metcross_mytrigger = (TH1F*)Data->Get("h_numerator");
	H_Data_triggereff_metcross_crosstrigger = (TH1F*)Data->Get("h_denumerator");
//	H_Data_triggereff_metcross_mytrigger = (TH1F*)Data->Get("h_multiTrigger_numerator");
//	H_Data_triggereff_metcross_crosstrigger = (TH1F*)Data->Get("h_multiTrigger_denumerator");	
	
	H_Data_triggereff_metcross_mytrigger->Rebin(2.5);
	H_Data_triggereff_metcross_crosstrigger->Rebin(2.5);
	
	H_Data_triggereff_photonptcross_mytrigger_vor = (TH1F*)Data->Get("h_triggereff_photonptcross_mytrigger_vor");
	H_Data_triggereff_photonptcross_crosstrigger_vor =	(TH1F*)Data->Get("h_triggereff_photonptcross_crosstrigger_vor");
	H_Data_triggereff_photonptcross_mytrigger_vor2 = (TH1F*)Data->Get("h_triggereff_photonptcross_mytrigger_vor2");
	H_Data_triggereff_photonptcross_crosstrigger_vor2 =	(TH1F*)Data->Get("h_triggereff_photonptcross_crosstrigger_vor2");	
	
	H_triggereff_metcross_mytrigger2 =  (TH1F*)Data->Get("h_triggereff_metcross_mytrigger2");
  H_triggereff_metcross_crosstrigger2 = (TH1F*)Data->Get("h_triggereff_metcross_crosstrigger2");
	H_triggereff_metcross_mytrigger3 =  (TH1F*)Data->Get("h_triggereff_metcross_mytrigger3");
  H_triggereff_metcross_crosstrigger3 = (TH1F*)Data->Get("h_triggereff_metcross_crosstrigger3");
	
	TEfficiency *T_pt_leg_1 = new TEfficiency(*H_numerator_final_pt_leg_tight_1, *H_denumerator_final_pt_leg_tight_1);
	TEfficiency *T_ID_leg_1 = new TEfficiency(*H_numerator_final_ID_leg_tight_1, *H_denumerator_final_ID_leg_tight_1);
	TEfficiency *T_ID_leg_wo_1 = new TEfficiency(*H_numerator_final_ID_leg_tight_wo_1, *H_denumerator_final_ID_leg_tight_wo_1);	
	TEfficiency *T_met_leg_1 = new TEfficiency(*H_numerator_final_met_leg_tight_1, *H_denumerator_final_met_leg_tight_1);	
	TEfficiency *T_pt_leg_2 = new TEfficiency(*H_numerator_final_pt_leg_tight_2, *H_denumerator_final_pt_leg_tight_2);
	TEfficiency *T_pt_leg_wo_2 = new TEfficiency(*H_numerator_final_pt_leg_tight_woMETcut_2, *H_denumerator_final_pt_leg_tight_woMETcut_2);
	TEfficiency *T_pt_leg_40_2 = new TEfficiency(*H_numerator_final_pt_leg_tight_40_2, *H_denumerator_final_pt_leg_tight_40_2);	
	TEfficiency *T_met_leg_2 = new TEfficiency(*H_numerator_final_met_leg_tight_2, *H_denumerator_final_met_leg_tight_2);	
	
	TEfficiency *T_pt_leg_1_loose = new TEfficiency(*H_numerator_final_pt_leg_loose_1, *H_denumerator_final_pt_leg_loose_1);
	TEfficiency *T_ID_leg_1_loose = new TEfficiency(*H_numerator_final_ID_leg_loose_1, *H_denumerator_final_ID_leg_loose_1);
	TEfficiency *T_ID_leg_1_loose_wo = new TEfficiency(*H_numerator_final_ID_leg_loose_wo_1, *H_denumerator_final_ID_leg_loose_wo_1);	
	TEfficiency *T_met_leg_1_loose = new TEfficiency(*H_numerator_final_met_leg_loose_1, *H_denumerator_final_met_leg_loose_1);	
	TEfficiency *T_pt_leg_2_loose = new TEfficiency(*H_numerator_final_pt_leg_loose_2, *H_denumerator_final_pt_leg_loose_2);
	TEfficiency *T_pt_leg_wo_2_loose = new TEfficiency(*H_numerator_final_pt_leg_loose_woMETcut_2, *H_denumerator_final_pt_leg_loose_woMETcut_2);
	TEfficiency *T_met_leg_2_loose = new TEfficiency(*H_numerator_final_met_leg_loose_2, *H_denumerator_final_met_leg_loose_2);	
//	TEfficiency *T_met_leg_2_loose_wo = new TEfficiency(*H_numerator_final_met_leg_loose_wo, *H_denumerator_final_met_leg_loose_wo);	
		
//	TEfficiency *T_r9_2 = new TEfficiency(*H_numerator_r9_2, *H_denumerator_r9_2);		
	TEfficiency *T_MET_calc = new TEfficiency(*H_numerator_MET_calc,*H_denumerator_MET_calc);
		
	TEfficiency *T_delta_wo_1 = new TEfficiency(*H_numerator_MET_corr_wo_1, *H_denumerator_MET_corr_wo_1);
	TEfficiency *T_delta_1 = new TEfficiency(*H_numerator_MET_corr_1, *H_denumerator_MET_corr_1);
	TEfficiency *T_delta_2 = new TEfficiency(*H_numerator_MET_corr_2, *H_denumerator_MET_corr_2);	
	
	TEfficiency *T_delta_wo_1_JET = new TEfficiency(*H_numerator_JET_corr_wo_1, *H_denumerator_JET_corr_wo_1);
	TEfficiency *T_delta_1_JET = new TEfficiency(*H_numerator_JET_corr_1, *H_denumerator_JET_corr_1);
	TEfficiency *T_delta_2_JET = new TEfficiency(*H_numerator_JET_corr_2, *H_denumerator_JET_corr_2);		
	
//	TEfficiency *T_DeltaRCut2_DeltaPhiCut_PtCut_2 = new TEfficiency(*H_numerator_DeltaRCut2_DeltaPhiCut_PtCut_2, *H_denumerator_DeltaRCut2_DeltaPhiCut_PtCut_2);	
	TEfficiency *T_DeltaRCut_DeltaPhiCut_PtCut_2 = new TEfficiency(*H_numerator_DeltaRCut_DeltaPhiCut_PtCut_2, *H_denumerator_DeltaRCut_DeltaPhiCut_PtCut_2);	
//	TEfficiency *T_DeltaRCut_DeltaPhiCut_PtCut_100_2 = new TEfficiency(*H_numerator_DeltaRCut_DeltaPhiCut_PtCut_100_2, *H_denumerator_DeltaRCut_DeltaPhiCut_PtCut_100_2);		
	TEfficiency *T_DeltaRCut_PtCut_2 = new TEfficiency(*H_numerator_DeltaRCut_PtCut_2, *H_denumerator_DeltaRCut_PtCut_2);		
	TEfficiency *T_DeltaRCut_2 = new TEfficiency(*H_numerator_DeltaRCut_2, *H_denumerator_DeltaRCut_2);
				
	TEfficiency *TlooseEta = new TEfficiency(*H_numerator_loose_eta, *H_denumerator_loose_eta);
	TEfficiency *TlooseEtaR9 = new TEfficiency(*H_numerator_loose_eta_r9, *H_denumerator_loose_eta_r9);
	TEfficiency *TtightEta = new TEfficiency(*H_numerator_tight_eta, *H_denumerator_tight_eta);
	TEfficiency *TtightEtaR9 = new TEfficiency(*H_numerator_tight_eta_r9, *H_denumerator_tight_eta_r9);	
	TEfficiency *TalllooseEta = new TEfficiency(*H_numerator_all_loose_eta, *H_denumerator_all_loose_eta);
	TEfficiency *TalllooseEtaR9 = new TEfficiency(*H_numerator_all_loose_eta_r9, *H_denumerator_all_loose_eta_r9);
	TEfficiency *TalllooseEtaR9_e5x5 = new TEfficiency(*H_numerator_all_loose_eta_r9_e5x5, *H_denumerator_all_loose_eta_r9_e5x5);		
	TEfficiency *Ttrigger = new TEfficiency(*H_numerator_trigger, *H_denumerator_trigger);
	
	TEfficiency *Teffi = new TEfficiency(*H_Data_triggereff_metcross_mytrigger, *H_Data_triggereff_metcross_crosstrigger);
	TEfficiency *Teffi3 = new TEfficiency(*H_triggereff_metcross_mytrigger2, *H_triggereff_metcross_crosstrigger2);	
	TEfficiency *Teffi5 = new TEfficiency(*H_triggereff_metcross_mytrigger3, *H_triggereff_metcross_crosstrigger3);		
	TEfficiency *Teffi2 = new TEfficiency(*H_Data_triggereff_photonptcross_mytrigger_vor, *H_Data_triggereff_photonptcross_crosstrigger_vor);	
	TEfficiency *Teffi4 = new TEfficiency(*H_Data_triggereff_photonptcross_mytrigger_vor2, *H_Data_triggereff_photonptcross_crosstrigger_vor2);
/*	TCanvas *canvas1 = new TCanvas("canvas1","Plots",600,600);
	canvas1->Divide(2,1);
	canvas1->cd(1);
	Teffi3->Draw();
/*	canvas1->cd(2);
	Teffi4->Draw(); 
	canvas1->cd(2);	
	Teffi5->Draw();	
	TCanvas *canvas2 = new TCanvas("canvas2","Plots",600,600);
*/
	gStyle->SetPadTickX(1);
	gStyle->SetPadTickY(1);
 /*
/*	h_triggereff_metcross_mytrigger->Draw();
  h_triggereff_metcross_crosstrigger->SetLineColor(kRed);   <- das funktioniert? ohne get und alles..scheinbar ja
	h_triggereff_metcross_crosstrigger->Draw("same");  
	
	h_numerator->Draw();
	h_denumerator->SetLineColor(kRed);
	h_denumerator->Draw("same"); */
	TCanvas *canvas3 = new TCanvas("canvas3","Plots",600,600);
//  canvas3->Divide(2,1);
//  canvas3->cd(1);
//	H_Data_triggereff_metcross_mytrigger->Draw();
	Teffi2->Draw();
	gPad->Update();	
	Teffi2->SetTitle("Efficiency");	
	Teffi2->GetPaintedGraph()->GetXaxis()->SetTitle("Missing E_{T} [GeV]");
//	canvas3->cd(2);
//	Teffi4->Draw();
	
	TCanvas *canvas4 = new TCanvas("canvas4","Plots",600,600);
  canvas4->Divide(2,1);
  canvas4->cd(1);
	TlooseEta->Draw();
	gPad->Update();	
	TlooseEta->SetTitle("Efficiency");	
	TlooseEta->GetPaintedGraph()->GetXaxis()->SetTitle("1st loose photon p_{T} [GeV]");		
  canvas4->cd(2);	
	TlooseEtaR9->Draw(); 
	TlooseEtaR9->SetTitle("Efficiency");	
	gPad->Update();
	TlooseEtaR9->GetPaintedGraph()->GetXaxis()->SetTitle("1st loose photon p_{T} [GeV]");	
	
	TCanvas *canvas5 = new TCanvas("canvas5","Plots",600,600);
  canvas5->Divide(2,1);
  canvas5->cd(1);
  TtightEta->Draw();
	gPad->Update();	
	TtightEta->SetTitle("Efficiency");	
	TtightEta->GetPaintedGraph()->GetXaxis()->SetTitle("1st tight photon p_{T} [GeV]");	
//	TtightEta->GetPaintedGraph()->GetYaxis()->SetTitle("#epsilon");	
  canvas5->cd(2);		
	TtightEtaR9->Draw();
	TtightEtaR9->SetTitle("Efficiency");	
	gPad->Update();
	TtightEtaR9->GetPaintedGraph()->GetXaxis()->SetTitle("1st tight photon p_{T} [GeV]");
//	TtightEtaR9->GetPaintedGraph()->GetYaxis()->SetTitle("#epsilon");		
	
	TCanvas *canvas6 = new TCanvas("canvas6","Plots",600,600);
//  canvas6->Divide(2,1);
//  canvas6->cd(1);
;
//	TalllooseEta->Draw();
//  canvas6->cd(2);	
//	TalllooseEtaR9->Draw();	
	H_denumerator_loose_eta_r9->SetLineColor(kRed);
	H_denumerator_loose_eta_r9->GetYaxis()->SetTitle("# Events");
	H_denumerator_loose_eta_r9->Draw();	
	H_numerator_loose_eta_r9->Draw("same");	

	
	TCanvas *cFinal = new TCanvas("cFinal","Plots",600,600);
	cFinal->Divide(2,1);
	cFinal->cd(1);	
	T_pt_leg_1->Draw();
	cFinal->cd(2); 
	T_ID_leg_1->Draw();
	T_ID_leg_1->SetTitle("ID Efficiency");		
	gPad->Update();
	T_ID_leg_1->GetPaintedGraph()->GetXaxis()->SetTitle("tight photon p_{T} [GeV]");		
	
//	cFinal->cd(3);
//	T_met_leg_1->Draw();	
	
	
	TCanvas *cFinal2 = new TCanvas("cFinal2","Plots",600,600);	
/*	cFinal2->Divide(2,1);
	cFinal2->cd(1);	
	T_pt_leg_2->Draw();
	T_pt_leg_2->SetTitle("ID Efficiency with offline PF MET > 100 cut");		
	gPad->Update();
	T_pt_leg_2->GetPaintedGraph()->GetXaxis()->SetTitle("tight photon p_{T} [GeV]");
	
	cFinal2->cd(2);
	T_pt_leg_wo_2->Draw();
	T_pt_leg_wo_2->SetTitle("ID Efficiency without offline PF MET > 100 cut");	
	gPad->Update();
	T_pt_leg_wo_2->GetPaintedGraph()->GetXaxis()->SetTitle("tight photon p_{T} [GeV]");
	*/
	//cFinal2->cd(3);
	T_met_leg_2->Draw();	
	T_met_leg_2->SetTitle("Offline PF MET Efficiency");		
	gPad->Update();
	T_met_leg_2->GetPaintedGraph()->GetXaxis()->SetTitle("Offline PF MET [GeV]");	



	TCanvas *cFinal_loose = new TCanvas("cFinal_loose","Plots",600,600);
//	cFinal_loose->Divide(2,1);
//	cFinal_loose->cd(1);	
//	T_pt_leg_1_loose->Draw();
//	cFinal_loose->cd(2);
 	gPad->SetGridx(1);
	gPad->SetGridy(1);
	T_ID_leg_1->SetMarkerStyle(8);
	T_ID_leg_1->Draw();
	T_ID_leg_1->SetTitle("ID Efficiency");		
	gPad->Update();
	T_ID_leg_1->GetPaintedGraph()->GetXaxis()->SetTitle("loose photon p_{T} [GeV]");		
	gPad->Update();	
//	cFinal_loose->cd(3);
//	T_met_leg_1_loose->Draw();	
	
	
	TCanvas *cFinal2_loose = new TCanvas("cFinal2_loose","Plots",600,600);	
//	cFinal2_loose->Divide(2,1);
//	cFinal2_loose->cd(1);	
/*	T_pt_leg_2_loose->Draw();
	T_pt_leg_2_loose->SetTitle("ID Efficiency with offline PF MET > 100 cut");		
	gPad->Update();
	T_pt_leg_2_loose->GetPaintedGraph()->GetXaxis()->SetTitle("tight photon p_{T} [GeV]");
	
	cFinal2_loose->cd(2);*/
	gPad->SetGridx(1);
	gPad->SetGridy(1);
	T_pt_leg_wo_2->SetMarkerStyle(8);
	T_pt_leg_wo_2->Draw();
	T_pt_leg_wo_2->SetTitle("ID Efficiency");	
	gPad->Update();
	T_pt_leg_wo_2->GetPaintedGraph()->GetXaxis()->SetTitle("loose photon p_{T} [GeV]");
	
	//cFinal2_loose->cd(3); */
/*	T_met_leg_2_loose_wo->Draw();	
	T_met_leg_2_loose_wo->SetTitle("Offline PF MET Efficiency");

	gPad->SetGridx(1);
	gPad->SetGridy(1);		
	gPad->Update();
	T_met_leg_2_loose_wo->GetPaintedGraph()->GetXaxis()->SetTitle("Offline PF MET [GeV]");	
*/
	
/*	TCanvas *c0 = new TCanvas("c0","Plots",600,600);
	(TH1F*)Data->Get("h_HT")->Draw();
  h_HT->SetLineColor(kRed);
	(TH1F*)Data2->Get("h_HT")->Draw("same");*/
	
	TCanvas *csame = new TCanvas("csame","Plots",600,600);
	
	//zeynep_tight no met cut
  T_ID_leg_wo_1->SetMarkerStyle(8);	
  T_ID_leg_wo_1->Draw();
	T_ID_leg_wo_1->SetTitle("ID Efficiency");		
	
  T_ID_leg_1_loose_wo->SetMarkerStyle(31);	
  T_ID_leg_1_loose_wo->Draw("same");	

	

		
	//johannes tight no met
/*  T_pt_leg_40_2->SetLineColor(kRed);
  T_pt_leg_40_2->SetMarkerColor(kRed);
  T_pt_leg_40_2->SetMarkerStyle(8);		
	T_pt_leg_40_2->Draw("same"); */
	 
//  T_ID_leg_1->SetMarkerStyle(8);	
//  T_ID_leg_1->Draw("same");		
	
  T_pt_leg_wo_2->SetLineColor(kRed);
  T_pt_leg_wo_2->SetMarkerColor(kRed);
  T_pt_leg_wo_2->SetMarkerStyle(8);		
	T_pt_leg_wo_2->Draw("same");	
	
	//zeynep met
//  T_ID_leg_1->SetMarkerStyle(8);		
//  T_ID_leg_1->Draw("same");	
	
	//johannes loose no met
  T_pt_leg_wo_2_loose->SetMarkerStyle(31);		
	T_pt_leg_wo_2_loose->Draw("same");	

	double num1 = H_numerator_final_ID_leg_tight_1->Integral(0,-1);
	double denum1 = H_denumerator_final_ID_leg_tight_1->Integral(0,-1);
	std::cout << "num1: "<<  num1 << " denum1: "<<  denum1 <<std::endl;
	gPad->SetGridx(1);
	gPad->SetGridy(1);		
	TLegend *infoBox = new TLegend(0.77, 0.8, 0.99, 0.99,"");//0.75, 0.83, 0.99, 0.99, "");
  infoBox->AddEntry(T_ID_leg_wo_1,"1st way (tight)","lep");
//  infoBox->AddEntry(T_ID_leg_1,"1st way (tight, MET > 40)","lep");	
  infoBox->AddEntry(T_ID_leg_1_loose_wo,"1st way (loose)","lep");		
//  infoBox->AddEntry(T_ID_leg_1,"1st way (tight, MET > 40)","lep");	
  infoBox->AddEntry(T_pt_leg_wo_2,"2nd way (tight)","lep");
 // infoBox->AddEntry(T_pt_leg_40_2,"2nd way (tight, MET > 40)","lep");		
  infoBox->AddEntry(T_pt_leg_wo_2_loose,"2nd way (loose)","lep");	
  infoBox->SetShadowColor(0);  // 0 = transparent
  infoBox->SetFillColor(kWhite); 
	infoBox->SetTextSize(0.025);
  infoBox->Draw();
	
	TCanvas *csame2 = new TCanvas("csame2","Plots",600,600);
		
	//ohne met cut tight
  T_pt_leg_wo_2->SetLineColor(kRed);
  T_pt_leg_wo_2->SetMarkerColor(kRed);	
	T_pt_leg_wo_2->Draw();
	//ohne met cut loose
  T_pt_leg_wo_2_loose->SetLineColor(kRed);
  T_pt_leg_wo_2_loose->SetMarkerColor(kRed);
  T_pt_leg_wo_2_loose->SetMarkerStyle(31);		
	T_pt_leg_wo_2_loose->Draw("same");
			
	//mit met cut tight
	
	T_pt_leg_2->Draw("same");
	T_pt_leg_2->SetMarkerStyle(8);
	//mit met cut loose
  T_pt_leg_2_loose->SetMarkerStyle(31);		
	T_pt_leg_2_loose->Draw("same");
	
	gPad->SetGridx(1);
	gPad->SetGridy(1);
	
	TLegend *infoBox = new TLegend(0.77, 0.8, 0.99, 0.99,"");//0.75, 0.83, 0.99, 0.99, "");
	infoBox->SetHeader("2nd way:");
  infoBox->AddEntry(T_pt_leg_wo_2,"without MET cut (tight)","lep");	
  infoBox->AddEntry(T_pt_leg_wo_2_loose,"without MET cut (loose)","lep");	
  infoBox->AddEntry(T_pt_leg_2,"with MET cut (tight)","lep");		
  infoBox->AddEntry(T_pt_leg_2_loose,"with MET cut (loose)","lep");	
  infoBox->SetShadowColor(0);  // 0 = transparent
  infoBox->SetFillColor(kWhite); 
	infoBox->SetTextSize(0.025);
  infoBox->Draw();	
	
	TCanvas *cdelta = new TCanvas("cdelta","Plots",600,600);
	

  T_delta_2->SetLineColor(kRed);
  T_delta_2->SetMarkerColor(kRed);
  T_delta_2->SetMarkerStyle(8);		
	T_delta_2->Draw();

//	T_delta_1->Draw("same");
//	T_delta_1->SetMarkerStyle(8);
	gPad->SetGridx(1);
	gPad->SetGridy(1);	
		
	double num2 = H_numerator_MET_corr_1->Integral(0,-1);
	double denum2 = H_denumerator_MET_corr_1->Integral(0,-1);
	std::cout << "num2: "<<  num2 << " denum2: "<<  denum2 <<std::endl;
	
//  T_delta_wo_1->SetMarkerStyle(31);
//	T_delta_wo_1->Draw("same"); 
	
/*		TLegend *infoBox = new TLegend(0.77, 0.8, 0.99, 0.99,"");//0.75, 0.83, 0.99, 0.99, "");
//  infoBox->AddEntry(T_ID_leg_wo_1,"Zeyneps way (tight)","lep");	
//  infoBox->AddEntry(T_ID_leg_1,"Zeyneps way (tight, met cut 40)","lep");	
  infoBox->AddEntry(T_delta_2,"2nd way (tight, met cut 40)","lep");		
//  infoBox->AddEntry(T_pt_leg_wo_2_loose,"Johannes way (loose)","lep");	
  infoBox->SetShadowColor(0);  // 0 = transparent
  infoBox->SetFillColor(kWhite); 
	infoBox->SetTextSize(0.025);
  infoBox->Draw(); */
	
		TCanvas *cdelta2 = new TCanvas("cdelta2","Plots",600,600);
	gPad->SetGridx(1);
	gPad->SetGridy(1);	

  T_delta_2_JET->SetLineColor(kRed);
  T_delta_2_JET->SetMarkerColor(kRed);
  T_delta_2_JET->SetMarkerStyle(8);		
	T_delta_2_JET->Draw();

//	T_delta_1_JET->Draw("same");
//	T_delta_1_JET->SetMarkerStyle(8);
	

 // T_delta_wo_1_JET->SetMarkerStyle(31);
//	T_delta_wo_1_JET->Draw("same"); 
	
/*		TLegend *infoBox = new TLegend(0.77, 0.8, 0.99, 0.99,"");//0.75, 0.83, 0.99, 0.99, "");
 // infoBox->AddEntry(T_ID_leg_wo_1,"Zeyneps way (tight)","lep");	
 // infoBox->AddEntry(T_ID_leg_1,"Zeyneps way (tight, met cut 40)","lep");	
  infoBox->AddEntry(T_pt_leg_40_2,"Johannes way (tight, met cut 40)","lep");		
//  infoBox->AddEntry(T_pt_leg_wo_2_loose,"Johannes way (loose)","lep");	
  infoBox->SetShadowColor(0);  // 0 = transparent
  infoBox->SetFillColor(kWhite); 
	infoBox->SetTextSize(0.025);
  infoBox->Draw();	*/
	
	TCanvas *cdelta3 = new TCanvas("cdelta3","Plots",600,600);
	
/*	T_pt_leg_40_2->Draw();
	T_pt_leg_40_2->SetMarkerStyle(8);
	T_pt_leg_40_2->SetLineColor(kRed);
  T_pt_leg_40_2->SetMarkerColor(kRed);	*/
	
//	T_DeltaRCut_2->Draw();

/*  T_pt_leg_40_2->SetLineColor(kRed);
  T_pt_leg_40_2->SetMarkerColor(kRed);
  T_pt_leg_40_2->SetMarkerStyle(8);		
	T_pt_leg_40_2->Draw(); */
	T_DeltaRCut_PtCut_2->SetMarkerStyle(8);	
	T_DeltaRCut_PtCut_2->Draw();	

	T_DeltaRCut_DeltaPhiCut_PtCut_2->SetMarkerStyle(8);
	T_DeltaRCut_DeltaPhiCut_PtCut_2->SetLineColor(kBlue);
	T_DeltaRCut_DeltaPhiCut_PtCut_2->SetMarkerColor(kBlue);
	T_DeltaRCut_DeltaPhiCut_PtCut_2->Draw("same");	
	
		
//	T_DeltaRCut2_DeltaPhiCut_PtCut_2->SetMarkerStyle(8);
//	T_DeltaRCut2_DeltaPhiCut_PtCut_2->Draw("same");	
	
	gPad->SetGridx(1);
	gPad->SetGridy(1);
	
	TH1F *Error = new TH1F("Error","bla",1,40,400);
	Error->SetBinContent(1,0.896);
	Error->SetBinError(1,0.03);
	Error->SetFillColor(kGreen);
	Error->SetFillStyle(3002);
	Error->Draw("E2 same");
	
	TH1F *Error2 = new TH1F("Error2","bla",1,40,400);
	Error2->SetBinContent(1,0.896);
	Error2->SetBinError(1,0.003);
	Error2->SetFillColor(kViolet+10);
	Error2->SetFillStyle(3001);
	Error2->Draw("E2 same");	
	
//	T_DeltaRCut_2->SetMarkerStyle(8);
//	T_DeltaRCut_2->Draw("same");	
	 
	
	
	TLegend *infoBox = new TLegend(0.77, 0.8, 0.99, 0.99,"");//0.75, 0.83, 0.99, 0.99, "");
	infoBox->SetHeader("2nd way:");
  infoBox->AddEntry(T_pt_leg_40_2,"MET > 40 (tight)","lep");		
  infoBox->AddEntry(T_DeltaRCut_DeltaPhiCut_PtCut_2,"MET > 40 - cleaned (tight)","lep");
  infoBox->AddEntry(Error2,"Eff. with stat. uncertainty","f");	
  infoBox->AddEntry(Error,"3 % syst. uncertainty","f");		
 // infoBox->AddEntry(T_DeltaRCut2_DeltaPhiCut_PtCut_2,"MET > 40 - cleaned (tight)","lep");	
  infoBox->SetShadowColor(0);  // 0 = transparent
  infoBox->SetFillColor(kWhite); 
	infoBox->SetTextSize(0.025);
  infoBox->Draw();
			
//	T_DeltaRCut_DeltaPhiCut_PtCut_100_2->SetMarkerStyle(8);
//	T_DeltaRCut_DeltaPhiCut_PtCut_100_2->Draw("same");
		
  TGraphAsymmErrors *Effi = new TGraphAsymmErrors();
  Effi->Divide(H_numerator_DeltaRCut_DeltaPhiCut_PtCut_2,H_denumerator_DeltaRCut_DeltaPhiCut_PtCut_2,"v cp");
 
  double effi = Effi->GetMean(2); //2 = Y axis
  double error_high = Effi->GetErrorYhigh(0);
  double error_low = Effi->GetErrorYlow(0);
	cout << "____________________________________" << endl;
  cout << "Error_high: " << error_high << endl;
  cout << "Error_low: " << error_low << endl;
  cout << "Efficieny: " << effi << endl;
	cout << "____________________________________" << endl;
	TCanvas *cdelta4 = new TCanvas("cdelta4","Plots",600,600);
	
  TGraphAsymmErrors *Effi2 = new TGraphAsymmErrors();
  Effi2->Divide(H_numerator_MET_calc,H_denumerator_MET_calc,"v cp");
	cout << "____________________________________" << endl; 
  double effi2 = Effi2->GetMean(2); //2 = Y axis
  double error_high2 = Effi2->GetErrorYhigh(0);
  double error_low2 = Effi2->GetErrorYlow(0);
	cout << "____________________________________" << endl;
  cout << "Error_high: " << error_high2 << endl;
  cout << "Error_low: " << error_low2 << endl;
  cout << "Efficieny: " << effi2 << endl;	
	cout << "____________________________________" << endl;
//	T_r9_2->Draw();
	
//	T_DeltaRCut_2->SetMarkerStyle(8);
//	T_DeltaRCut_2->Draw();
	
  T_MET_calc->SetMarkerStyle(8);
  T_MET_calc->Draw();
}


