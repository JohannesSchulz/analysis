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
	H_denumerator_JET_corr_100_2 = (TH1F*)DataMET->Get("h_denumerator_JET_corr_100_2");
	H_denumerator_JET_corr_2 = (TH1F*)DataMET->Get("h_denumerator_JET_corr_2");	
		
	H_numerator_JET_corr_wo_1 = (TH1F*)Data->Get("h_numerator_JET_corr_wo_1");
	H_numerator_JET_corr_1 = (TH1F*)Data->Get("h_numerator_JET_corr_1");		
	H_numerator_JET_corr_100_2 = (TH1F*)DataMET->Get("h_numerator_JET_corr_100_2");
	H_numerator_JET_corr_2 = (TH1F*)DataMET->Get("h_numerator_JET_corr_2");	
		
	H_numerator_MET_calc = (TH1F*)Data->Get("h_numerator_MET_calc");	
	H_denumerator_MET_calc = (TH1F*)Data->Get("h_denumerator_MET_calc");

  /////////////
 //selection//
/////////////	

	H_numerator_selection_met = (TH1F*)Data->Get("h_numerator_selection_met");	
	H_denumerator_selection_met = (TH1F*)Data->Get("h_denumerator_selection_met");	
	H_numerator_selection_pt = (TH1F*)DataMET->Get("h_numerator_selection_pt");	
	H_denumerator_selection_pt = (TH1F*)DataMET->Get("h_denumerator_selection_pt");	
	H_numerator_PT_calc_selection = (TH1F*)DataMET->Get("h_numerator_PT_calc_selection");	
	H_denumerator_PT_calc_selection = (TH1F*)DataMET->Get("h_denumerator_PT_calc_selection");	
	H_numerator_MET_calc_selection = (TH1F*)Data->Get("h_numerator_MET_calc_selection");	
	H_denumerator_MET_calc_selection = (TH1F*)Data->Get("h_denumerator_MET_calc_selection");	
	H_numerator_PT_calc_selection_40 = (TH1F*)DataMET->Get("h_numerator_PT_calc_selection_40");	
	H_denumerator_PT_calc_selection_40 = (TH1F*)DataMET->Get("h_denumerator_PT_calc_selection_40");
	H_numerator_PT_calc_selection_100 = (TH1F*)DataMET->Get("h_numerator_PT_calc_selection_100");	
	H_denumerator_PT_calc_selection_100 = (TH1F*)DataMET->Get("h_denumerator_PT_calc_selection_100");	

	H_numerator_PT_calc_MET40 = (TH1F*)DataMET->Get("h_numerator_PT_calc_MET40");	
	H_denumerator_PT_calc_MET40 = (TH1F*)DataMET->Get("h_denumerator_PT_calc_MET40");	
			
	
	H_numerator_vert = (TH1F*)Data->Get("h_numerator_vert");	
	H_denumerator_vert = (TH1F*)Data->Get("h_denumerator_vert");
	H_numerator_vertMET = (TH1F*)DataMET->Get("h_numerator_vert");	
	H_denumerator_vertMET = (TH1F*)DataMET->Get("h_denumerator_vert");	
	
	H_numerator_vert_100 = (TH1F*)Data->Get("h_numerator_vert_100");	
	H_denumerator_vert_100 = (TH1F*)Data->Get("h_denumerator_vert_100");		
	H_numerator_vert_100MET = (TH1F*)DataMET->Get("h_numerator_vert_100");	
	H_denumerator_vert_100MET = (TH1F*)DataMET->Get("h_denumerator_vert_100");		
	
	H_numerator_DeltaRCut_DeltaPhiCut_PtCut_2 = (TH1F*)DataMET->Get("h_numerator_DeltaRCut_DeltaPhiCut_PtCut_2");		
	H_denumerator_DeltaRCut_DeltaPhiCut_PtCut_2 = (TH1F*)DataMET->Get("h_denumerator_DeltaRCut_DeltaPhiCut_PtCut_2");	

//	H_numerator_DeltaRCut2_DeltaPhiCut_PtCut_2 = (TH1F*)DataMET->Get("h_numerator_DeltaRCut2_DeltaPhiCut_PtCut_2");		
//	H_denumerator_DeltaRCut2_DeltaPhiCut_PtCut_2 = (TH1F*)DataMET->Get("h_denumerator_DeltaRCut2_DeltaPhiCut_PtCut_2");	
	
	H_numerator_DeltaRCut_DeltaPhiCut_PtCut_100_2 = (TH1F*)DataMET->Get("h_numerator_DeltaRCut_DeltaPhiCut_PtCut_100_2");		
	H_denumerator_DeltaRCut_DeltaPhiCut_PtCut_100_2 = (TH1F*)DataMET->Get("h_denumerator_DeltaRCut_DeltaPhiCut_PtCut_100_2");		
	
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
	
	
	H_numerator_final_met_leg_loose_wo = (TH1F*)Data->Get("h_numerator_final_met_leg_loose_wo"); 
	H_denumerator_final_met_leg_loose_wo = (TH1F*)Data->Get("h_denumerator_final_met_leg_loose_wo");	
	
		
	
	
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
	
	
	H2_denumerator = (TH2F*)Data->Get("h2_trigger_effis_denumerator");
	H2_numerator = (TH2F*)Data->Get("h2_trigger_effis_numerator");	
	H2_denumerator->RebinX(2);
	H2_denumerator->RebinY(2);	
	H2_numerator->RebinX(2);	
	H2_numerator->RebinY(2);	
	
	H_numerator_trigger = (TH1F*)Data->Get("h_numerator_trigger");
	H_denumerator_trigger = (TH1F*)Data->Get("h_denumerator_trigger");
	
	H_numerator_r9_2 = (TH1F*)DataMET->Get("h_numerator_r9_2");
	H_denumerator_r9_2 = (TH1F*)DataMET->Get("h_denumerator_r9_2");		
	
	
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
	H_denumerator_JET_corr_100_2->Rebin(2);
	H_numerator_JET_corr_100_2->Rebin(2);	
	/////////////////////
	
//	H_numerator_DeltaRCut2_DeltaPhiCut_PtCut_2->Rebin(4);
//	H_denumerator_DeltaRCut2_DeltaPhiCut_PtCut_2->Rebin(4);
	H_numerator_JET_corr_2->Rebin(2);
	H_denumerator_JET_corr_2->Rebin(2);	
	
	H_numerator_MET_calc->Rebin(80);
	H_denumerator_MET_calc->Rebin(80);	
	
	//------------------------------------------------------------------------------------//
	//Interesting!
	
	H_numerator_selection_met->Rebin(4);
	H_denumerator_selection_met->Rebin(4);
	
	H_numerator_selection_pt->Rebin(4);
	H_denumerator_selection_pt->Rebin(4);		
	
	H_numerator_MET_calc_selection->Rebin(25);
	H_denumerator_MET_calc_selection->Rebin(25);	
	H_numerator_PT_calc_selection->Rebin(25);
	H_denumerator_PT_calc_selection->Rebin(25);	
	H_numerator_PT_calc_selection_40->Rebin(25);
	H_denumerator_PT_calc_selection_40->Rebin(25);		
	H_numerator_PT_calc_selection_100->Rebin(25);
	H_denumerator_PT_calc_selection_100->Rebin(25);		
//	H_numerator_PT_calc_MET40->Rebin(25);
//	H_denumerator_PT_calc_MET40->Rebin(25);		
	
	H_numerator_DeltaRCut_2->Rebin(8);
	H_denumerator_DeltaRCut_2->Rebin(8);
	
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
	
	H_numerator_final_met_leg_loose_wo->Rebin(4);
	H_denumerator_final_met_leg_loose_wo->Rebin(4);
	
	H_numerator_DeltaRCut_PtCut_2->Rebin(80);
	H_denumerator_DeltaRCut_PtCut_2->Rebin(80);	
	H_numerator_DeltaRCut_DeltaPhiCut_PtCut_2->Rebin(4);
	H_denumerator_DeltaRCut_DeltaPhiCut_PtCut_2->Rebin(4);
//	H_numerator_DeltaRCut_DeltaPhiCut_PtCut_100_2->Rebin(80);
//	H_denumerator_DeltaRCut_DeltaPhiCut_PtCut_100_2->Rebin(80);





//Histo options

	 H_denumerator_selection_met->SetTitle("");
	 H_denumerator_selection_met->GetYaxis()->SetTitle("#varepsilon_{#slash{E}_{T}-req.}");
	 H_denumerator_selection_met->GetYaxis()->SetTitleOffset(0.5);	
	 H_denumerator_selection_met->GetXaxis()->SetTitleOffset(0.7);
	 H_denumerator_selection_met->GetXaxis()->SetRangeUser(0,400);	 
	 H_denumerator_selection_met->GetYaxis()->SetTitleSize(0.5);	
	 H_denumerator_selection_met->GetXaxis()->SetTitleSize(0.15);	 		
	 H_denumerator_selection_met->GetXaxis()->SetTitle("#slash{E}_{T} [GeV]"); 
	 
	 H_denumerator_selection_pt->GetXaxis()->SetRangeUser(0,400); 	 
	 H_denumerator_selection_pt->SetTitle("");
	 H_denumerator_selection_pt->GetYaxis()->SetTitle("#varepsilon_{#gamma-req.}");
	 H_denumerator_selection_pt->GetYaxis()->SetTitleOffset(0.5);	
	 H_denumerator_selection_pt->GetXaxis()->SetTitleOffset(0.7);
	 H_denumerator_selection_pt->GetXaxis()->SetRangeUser(0,400);	 
	 H_denumerator_selection_pt->GetYaxis()->SetTitleSize(0.5);	
	 H_denumerator_selection_pt->GetXaxis()->SetTitleSize(0.15);	 		
	 H_denumerator_selection_pt->GetXaxis()->SetTitle("#gamma p_{T} [GeV]");	 	

	 H_numerator_selection_met->GetYaxis()->SetTitle("#varepsilon_{#slash{E}_{T}-req.}");
	 H_numerator_selection_met->GetYaxis()->SetTitleOffset(0.5);	
	 H_numerator_selection_met->GetXaxis()->SetTitleOffset(0.7); 
	 H_numerator_selection_met->GetYaxis()->SetTitleSize(0.5);	
	 H_numerator_selection_met->GetXaxis()->SetTitleSize(0.15);		 		
	 H_numerator_selection_met->GetXaxis()->SetTitle("#slash{E}_{T} [GeV]"); 
	 H_numerator_selection_met->GetXaxis()->SetRangeUser(0,400);
	 
	 H_denumerator_JET_corr_100_2->SetTitle("");
	 H_denumerator_JET_corr_100_2->GetYaxis()->SetTitle("#varepsilon_{#DeltaR}");
	 H_denumerator_JET_corr_100_2->GetYaxis()->SetTitleOffset(0.5);	
	 H_denumerator_JET_corr_100_2->GetXaxis()->SetTitleOffset(0.7); 
	 H_denumerator_JET_corr_100_2->GetYaxis()->SetTitleSize(0.5);	
	 H_denumerator_JET_corr_100_2->GetXaxis()->SetTitleSize(0.15);		 		
	 H_denumerator_JET_corr_100_2->GetXaxis()->SetTitle("#DeltaR(#gamma, nearest Jet)"); 
	 
	 
	 
//	 H_Data_triggereff_metcross_mytrigger = (TH1F*)Data->Get("h_triggereff_metcross_mytrigger");
//	 H_Data_triggereff_metcross_crosstrigger = (TH1F*)Data->Get("h_triggereff_metcross_crosstrigger");
	
	H_Data_triggereff_metcross_mytrigger = (TH1F*)Data->Get("h_numerator");
	H_Data_triggereff_metcross_crosstrigger = (TH1F*)Data->Get("h_denumerator");
//	H_Data_triggereff_metcross_mytrigger = (TH1F*)Data->Get("h_multiTrigger_numerator");
//	H_Data_triggereff_metcross_crosstrigger = (TH1F*)Data->Get("h_multiTrigger_denumerator");	
	
	H_Data_triggereff_metcross_mytrigger->Rebin(2.5);
	H_Data_triggereff_metcross_crosstrigger->Rebin(2.5);
	
//	H_numerator_JET_corr_2->GetYaxis()->SetTitle("Efficiency #epsilon");
//	H_denumerator_JET_corr_2->GetYaxis()->SetTitle("Efficiency #epsilon");	
		
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
	TEfficiency *T_met_leg_2_loose_wo = new TEfficiency(*H_numerator_final_met_leg_loose_wo, *H_denumerator_final_met_leg_loose_wo);	
		
	TEfficiency *T_r9_2 = new TEfficiency(*H_numerator_r9_2, *H_denumerator_r9_2);		
	TEfficiency *T_MET_calc = new TEfficiency(*H_numerator_MET_calc,*H_denumerator_MET_calc);
		
	TEfficiency *T_delta_wo_1 = new TEfficiency(*H_numerator_MET_corr_wo_1, *H_denumerator_MET_corr_wo_1);
	TEfficiency *T_delta_1 = new TEfficiency(*H_numerator_MET_corr_1, *H_denumerator_MET_corr_1);
	TEfficiency *T_delta_2 = new TEfficiency(*H_numerator_MET_corr_2, *H_denumerator_MET_corr_2);	
	
	TEfficiency *T_delta_wo_1_JET = new TEfficiency(*H_numerator_JET_corr_wo_1, *H_denumerator_JET_corr_wo_1);
	TEfficiency *T_delta_1_JET = new TEfficiency(*H_numerator_JET_corr_1, *H_denumerator_JET_corr_1);
	TEfficiency *T_delta_2_100_JET = new TEfficiency(*H_numerator_JET_corr_100_2, *H_denumerator_JET_corr_100_2);		
	TEfficiency *T_delta_2_JET = new TEfficiency(*H_numerator_JET_corr_2, *H_denumerator_JET_corr_2);		
//	TEfficiency *T_DeltaRCut2_DeltaPhiCut_PtCut_2 = new TEfficiency(*H_numerator_DeltaRCut2_DeltaPhiCut_PtCut_2, *H_denumerator_DeltaRCut2_DeltaPhiCut_PtCut_2);	
	TEfficiency *T_DeltaRCut_DeltaPhiCut_PtCut_2 = new TEfficiency(*H_numerator_DeltaRCut_DeltaPhiCut_PtCut_2, *H_denumerator_DeltaRCut_DeltaPhiCut_PtCut_2);	
	TEfficiency *T_DeltaRCut_DeltaPhiCut_PtCut_100_2 = new TEfficiency(*H_numerator_DeltaRCut_DeltaPhiCut_PtCut_100_2, *H_denumerator_DeltaRCut_DeltaPhiCut_PtCut_100_2);		
	TEfficiency *T_DeltaRCut_PtCut_2 = new TEfficiency(*H_numerator_DeltaRCut_PtCut_2, *H_denumerator_DeltaRCut_PtCut_2);		
	TEfficiency *T_DeltaRCut_2 = new TEfficiency(*H_numerator_DeltaRCut_2, *H_denumerator_DeltaRCut_2);
	
	TEfficiency *T_htCut_2 = new TEfficiency(*H_numerator_PT_calc_MET40, *H_denumerator_PT_calc_MET40);			
		
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
	
	TEfficiency *TSelection_met = new TEfficiency(*H_numerator_selection_met, *H_denumerator_selection_met);
	TEfficiency *TSelection_pt = new TEfficiency(*H_numerator_selection_pt, *H_denumerator_selection_pt);		
	TEfficiency *TVert = new TEfficiency(*H_numerator_vert, *H_denumerator_vert);
	TEfficiency *TVertMET = new TEfficiency(*H_numerator_vertMET, *H_denumerator_vertMET);	
	TEfficiency *TVert100 = new TEfficiency(*H_numerator_vert_100, *H_denumerator_vert_100);
	TEfficiency *TVert100MET = new TEfficiency(*H_numerator_vert_100MET, *H_denumerator_vert_100MET);
	TEfficiency *TPTcalc = new TEfficiency(*H_numerator_PT_calc_selection,*H_denumerator_PT_calc_selection);	
	TEfficiency *TPTcalc40 = new TEfficiency(*H_numerator_PT_calc_selection_40,*H_denumerator_PT_calc_selection_40);	
	TEfficiency *TPTcalc100 = new TEfficiency(*H_numerator_PT_calc_selection_100,*H_denumerator_PT_calc_selection_100);	
	
	TEfficiency *T_2D = new TEfficiency(*H2_numerator,*H2_denumerator);			
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
	gStyle->SetMarkerStyle(8);
 /*
/*	h_triggereff_metcross_mytrigger->Draw();
  h_triggereff_metcross_crosstrigger->SetLineColor(kRed);   <- das funktioniert? ohne get und alles..scheinbar ja
	h_triggereff_metcross_crosstrigger->Draw("same");  
	
	h_numerator->Draw();
	h_denumerator->SetLineColor(kRed);
	h_denumerator->Draw("same"); */
	TCanvas *canvas3 = new TCanvas("canvas3","Plots",700,600);
	
  canvasDefault_1 = new TPad("canvasDefault_1", "newpad",0.0,0.0,1.0,0.41);//0.325);		

  canvasDefault_1->SetTopMargin(0.01);
  canvasDefault_1->SetBottomMargin(0.3);
  canvasDefault_1->SetRightMargin(0.05);
  canvasDefault_1->SetLeftMargin(0.11);	
  canvasDefault_1->SetFillStyle(0);
  canvasDefault_1->cd(); 
	TSelection_met->Draw("");
	


	
  canvas3->cd();
	canvasDefault_1->Draw();
	canvasDefault_1->cd();	
	gPad->Update();	
	TSelection_met->GetPaintedGraph()->GetXaxis()->SetRangeUser(0,400);	
	TSelection_met->GetPaintedGraph()->GetYaxis()->SetRangeUser(0,1.05);		
	TSelection_met->GetPaintedGraph()->GetXaxis()->SetTitleSize(0.1);	
  TSelection_met->GetPaintedGraph()->GetYaxis()->SetTitleSize(0.12);	
  TSelection_met->GetPaintedGraph()->GetXaxis()->SetLabelSize(0.1);	
  TSelection_met->GetPaintedGraph()->GetYaxis()->SetLabelSize(0.1);		
  TSelection_met->GetPaintedGraph()->GetYaxis()->SetTitleOffset(0.38);
	TSelection_met->SetTitle("");//"#slash{E}_{T}-req. efficiency");	
	TSelection_met->GetPaintedGraph()->GetYaxis()->SetTitle("#varepsilon_{#slash{E}_{T}-req.}");
	TSelection_met->GetPaintedGraph()->GetXaxis()->SetTitleOffset(0.7);		
	TSelection_met->GetPaintedGraph()->GetXaxis()->SetTitle("#slash{E}_{T} [GeV]"); 		
	
	H_denumerator_selection_met->GetXaxis()->SetRangeUser(0,400); 	
	TH1F *ratio3 = (TH1F*)H_denumerator_selection_met->Clone("ratio");

	for ( int i = 1; i < H_denumerator_selection_met->GetNbinsX(); i++){
		ratio3->SetBinContent(i,0);			
		}
  ratio3->Draw("AXIS");
  ratio3->Draw("same AXIG");	
	ratio3->GetYaxis()->SetRangeUser(0,1.05);		
	ratio3->GetXaxis()->SetTitleSize(0.1);	
  ratio3->GetYaxis()->SetTitleSize(0.12);	
  ratio3->GetXaxis()->SetLabelSize(0.1);	
  ratio3->GetYaxis()->SetLabelSize(0.1);		
  ratio3->GetYaxis()->SetTitleOffset(0.38);
	ratio3->SetTitle("");//"#slash{E}_{T}-req. efficiency");	
	ratio3->GetYaxis()->SetTitle("#varepsilon_{#slash{E}_{T}-req.}");
	ratio3->GetXaxis()->SetTitleOffset(0.9);		
	ratio3->GetXaxis()->SetTitle("#slash{E}_{T} [GeV]"); 	
	ratio3->GetYaxis()->SetRangeUser(0,1.05);	
	TSelection_met->Draw("same");	

	EffiMet = new TLatex(105,0.2,"#varepsilon_{#slash{E}_{T}-req.} = (98.3^{+0.8}_{-1.3} (stat.)) %"); 
  EffiMet->SetTextSize(0.1);
  EffiMet->Draw();
	TLine *l_cut_met = new TLine(100,0,100,1.05);
	l_cut_met->SetLineWidth(4);
	l_cut_met->Draw("same");
	Arrow3 = new TLatex(100,0.6,"#rightarrow");
	Arrow3->SetTextSize(0.13);
	Arrow3->Draw("same");
	gPad->SetGrid();
	gStyle->SetGridStyle(3);	
	gPad->Update();	
		
	canvas3->cd();	
		
	 canvasDefault_2 = new TPad("canvasDefault_2", "newpad",0.0,0.4,1,1); //0.32
	 canvasDefault_2->Draw(); 
 	 canvasDefault_2->cd();
 	 canvasDefault_2->SetTopMargin(0.1);
 	 canvasDefault_2->SetBottomMargin(0.01);
 	 canvasDefault_2->SetRightMargin(0.05);
 	 canvasDefault_2->SetLeftMargin(0.11);	 
 	 canvasDefault_2->SetFillStyle(0);
	 H_denumerator_selection_met->SetMaximum(H_denumerator_selection_met->GetMaximum()*4);
	 H_denumerator_selection_met->GetYaxis()->SetTitle("Events / bin");
	 H_denumerator_selection_met->GetYaxis()->SetTitleOffset(0.7);	
	 H_denumerator_selection_met->GetXaxis()->SetTitleOffset(0.5);		
	 H_denumerator_selection_met->GetXaxis()->SetTitle("#slash{E}_{T} [GeV]"); 	 
	 H_denumerator_selection_met->GetYaxis()->SetTitleSize(0.065); 	
	 H_denumerator_selection_met->GetYaxis()->SetLabelSize(0.06); 		  
	 H_denumerator_selection_met->GetXaxis()->SetRangeUser(0,400); 	 		 
	 H_denumerator_selection_met->GetXaxis()->SetTitleSize(0.0); 
	 H_denumerator_selection_met->Draw("hist");
	 H_numerator_selection_met->Draw("same f hist");	 	 	
	 H_denumerator_selection_met->SetLineColor(kRed); 
	 H_denumerator_selection_met->SetLineStyle(1);
	 H_denumerator_selection_met->SetLineWidth(3);	 	 	
	 H_denumerator_selection_met->SetMinimum(0.3);
	 H_numerator_selection_met->SetLineColor(kBlue);	
	 H_numerator_selection_met->SetFillStyle(3003);	
	 H_numerator_selection_met->SetFillColor(kBlue);	  	 
	 H_numerator_selection_met->SetLineWidth(1);
	 gStyle->SetOptStat(00000);
	 gPad->Update();  	 			 	
  canvasDefault_2->SetLogy(1);
	CMS_text = new TLatex(0.1,0.91,"#int L dt = 7.4 fb^{-1},  #sqrt{S} = 8 TeV,   CMS PRIVATE WORK");
	CMS_text->SetNDC();
  CMS_text->SetTextSize(0.05);
  CMS_text->Draw();		
	TLegend *infoBox = new TLegend(0.27, 0.65, 0.95, 0.9,"");//0.75, 0.83, 0.99, 0.99, "");
  infoBox->AddEntry(H_denumerator_selection_met,"Events triggered by baseline trigger","l");
  infoBox->AddEntry(H_numerator_selection_met,"Events triggered by signal and baseline trigger","f");	
  infoBox->SetShadowColor(0);  // 0 = transparent
  infoBox->SetFillColor(kWhite); 
	infoBox->SetTextSize(0.05);
  infoBox->Draw();	

	gStyle->SetPadTickX(1);
	gStyle->SetPadTickY(1);
	gPad->SetGridx(1);
	gPad->SetGridy(1);

	gPad->Update();

	gStyle->SetPadTickX(1);
	gStyle->SetPadTickY(1);
	TSelection_met->SetLineColor(kBlack);
	TSelection_met->SetMarkerStyle(8);	
	gPad->Update();	
	
//////////////////////////////////////////////////////////////////////////////////	
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////


	
	TCanvas *cSelection = new TCanvas("cSelection","Plots",600,600);
//  canvas3->Divide(2,1);
//  canvas3->cd(1);
//	H_Data_triggereff_metcross_mytrigger->Draw();
//	gStyle->SetPadTickX(1);
//	gStyle->SetPadTickY(1);
//	gPad->SetGridx(1);
//	gPad->SetGridy(1);
	
	TSelection_met->Draw();

	TSelection_met->SetMarkerStyle(8);
	TSelection_met->SetLineWidth(2);		
//	Teffi2->Draw();
	gPad->Update();
/*	TSelection_met->GetPaintedGraph()->GetXaxis()->SetTitleSize(0.06);	
  TSelection_met->GetPaintedGraph()->GetYaxis()->SetTitleSize(0.06);	
  TSelection_met->GetPaintedGraph()->GetXaxis()->SetLabelSize(0.055);	
  TSelection_met->GetPaintedGraph()->GetYaxis()->SetLabelSize(0.06);		
  TSelection_met->GetPaintedGraph()->GetYaxis()->SetTitleOffset(0.9);
	TSelection_met->SetTitle("");//"#slash{E}_{T}-req. efficiency");	
	TSelection_met->GetPaintedGraph()->GetYaxis()->SetTitle("#varepsilon_{#slash{E}_{T}-req.}");
	TSelection_met->GetPaintedGraph()->GetXaxis()->SetTitleOffset(0.7);		
	TSelection_met->GetPaintedGraph()->GetYaxis()->SetTitleOffset(0.7);		
	TSelection_met->GetPaintedGraph()->GetXaxis()->SetTitle("#slash{E}_{T} [GeV]"); */
//	EffiMet = new TLatex(100,0.3,"#varepsilon_{#slash{E}_{T}-req.} = (98.7 #pm 0.2(stat.)) %");
//  EffiMet->SetTextSize(0.06);
 // EffiMet->Draw();
	TLine *l_cut_met = new TLine(100,0,100,1.05);
	l_cut_met->SetLineWidth(4);
	l_cut_met->Draw("same");
	Arrow3 = new TLatex(100,0.6,"#rightarrow");
	Arrow3->SetTextSize(0.06);
	Arrow3->Draw("same");
//	canvas3->cd(2);
//	Teffi4->Draw();
//	gStyle->SetPadTickX(1);
//	gStyle->SetPadTickY(1);	
	

	
	TCanvas *cSelection_pt = new TCanvas("cSelection_pt","Plots",600,600);
//  canvas3->Divide(2,1);
//  canvas3->cd(1);
//	H_Data_triggereff_metcross_mytrigger->Draw();
//	gStyle->SetPadTickX(1);
//	gStyle->SetPadTickY(1);
//	gPad->SetGridx(1);
//	gPad->SetGridy(1);
	
	TSelection_pt->Draw();

	TSelection_pt->SetMarkerStyle(8);
	TSelection_pt->SetMarkerSize(1);
	TSelection_pt->SetLineWidth(1);		
//	Teffi2->Draw();
	gPad->Update();
	TSelection_pt->GetPaintedGraph()->GetXaxis()->SetTitleSize(0.06);	
  TSelection_pt->GetPaintedGraph()->GetYaxis()->SetTitleSize(0.06);	
  TSelection_pt->GetPaintedGraph()->GetXaxis()->SetLabelSize(0.055);	
  TSelection_pt->GetPaintedGraph()->GetYaxis()->SetLabelSize(0.06);		
  TSelection_pt->GetPaintedGraph()->GetYaxis()->SetTitleOffset(0.9);
	TSelection_pt->SetTitle("");//"#slash{E}_{T}-req. efficiency");
	TSelection_pt->GetPaintedGraph()->GetXaxis()->SetTitle("#gamma p_{T} [GeV]");	
  TSelection_pt->GetPaintedGraph()->GetYaxis()->SetTitle("#varepsilon_{#gamma-req.}");
	TSelection_pt->GetPaintedGraph()->GetXaxis()->SetTitleOffset(0.7);		
	TSelection_pt->GetPaintedGraph()->GetYaxis()->SetTitleOffset(0.7);		
	Effipt = new TLatex(50,0.3,"#varepsilon_{#gamma-req.} = (88.0 #pm 0.7(stat.)) %");
  Effipt->SetTextSize(0.06);
//  Effipt->Draw();
	TLine *l_cut_pt = new TLine(40,0,40,1.05);
	l_cut_pt->SetLineWidth(4);
	l_cut_pt->Draw("same");
	Arrowp = new TLatex(40,0.6,"#rightarrow");
	Arrowp->SetTextSize(0.06);
	Arrowp->Draw("same");
	canvas3->cd(2);
//	Teffi4->Draw();
//	gStyle->SetPadTickX(1);
//	gStyle->SetPadTickY(1);	
	T_DeltaRCut_2->SetMarkerStyle(8);
	T_DeltaRCut_2->SetLineColor(kRed);
	T_htCut_2->SetMarkerStyle(8);
	T_htCut_2->SetLineColor(kRed);	
	T_htCut_2->SetMarkerSize(2);
	T_htCut_2->SetLineWidth(2);	
	T_DeltaRCut_2->Draw("same");		
//	T_htCut_2->Draw("same");
//////   n vertex dependency ////
////////////////////////////////////////////////////////////////////////////////////////	
	TCanvas *cVert = new TCanvas("cVert","Plots",600,600);
  cVert->Divide(1,1);
  cVert->cd(1);
	TVert->Draw();
	gPad->Update();
	TVert->SetMarkerStyle(8);
	TVert->SetMarkerSize(1);
	TVert->SetLineWidth(2);		
	TVert->SetTitle("Efficiency");	
	TVert->GetPaintedGraph()->GetXaxis()->SetTitle("# vertices");	
	TVert->GetPaintedGraph()->GetXaxis()->SetTitleSize(0.06);	
  TVert->GetPaintedGraph()->GetYaxis()->SetTitleSize(0.06);	
  TVert->GetPaintedGraph()->GetXaxis()->SetLabelSize(0.055);	
  TVert->GetPaintedGraph()->GetYaxis()->SetLabelSize(0.06);		
  TVert->GetPaintedGraph()->GetYaxis()->SetTitleOffset(0.9);
	TVert->SetTitle("");//"#slash{E}_{T}-req. efficiency");
  TVert->GetPaintedGraph()->GetYaxis()->SetTitle("#varepsilon_{# vert.}");
	TVert->GetPaintedGraph()->GetXaxis()->SetTitleOffset(0.7);		
	TVert->GetPaintedGraph()->GetYaxis()->SetTitleOffset(0.7);		
/*  cVert->cd(2);	
	TVert100->Draw(); 
	TVert100->SetTitle("Efficiency");	
	gPad->Update();
	TVert100->GetPaintedGraph()->GetXaxis()->SetTitle("n vertices");	
	*/
	TCanvas *cVert2 = new TCanvas("cVert2","Plots",600,600);
  cVert2->Divide(1,1);
  cVert2->cd(1);
	TVertMET->Draw();
	gPad->Update();
	TVertMET->SetMarkerStyle(8);
	TVertMET->SetMarkerSize(1);
	TVertMET->SetLineWidth(2);	
	TVertMET->SetTitle("Efficiency");	
	TVertMET->GetPaintedGraph()->GetXaxis()->SetTitle("# vertices");	
	TVertMET->GetPaintedGraph()->GetXaxis()->SetTitleSize(0.06);	
  TVertMET->GetPaintedGraph()->GetYaxis()->SetTitleSize(0.06);	
  TVertMET->GetPaintedGraph()->GetXaxis()->SetLabelSize(0.055);	
  TVertMET->GetPaintedGraph()->GetYaxis()->SetLabelSize(0.06);		
  TVertMET->GetPaintedGraph()->GetYaxis()->SetTitleOffset(0.9);
	TVertMET->SetTitle("");//"#slash{E}_{T}-req. efficiency");
  TVertMET->GetPaintedGraph()->GetYaxis()->SetTitle("#varepsilon_{# vert.}");
	TVertMET->GetPaintedGraph()->GetXaxis()->SetTitleOffset(0.7);		
	TVertMET->GetPaintedGraph()->GetYaxis()->SetTitleOffset(0.7);				
/*  cVert2->cd(2);	
	
	TVert100MET->Draw(); 
	TVert100MET->SetTitle("Efficiency");	
	gPad->Update();
	TVert100MET->GetPaintedGraph()->GetXaxis()->SetTitle("n vertices");	*/


/////////////////////////////////////////////////////////////////////////////////////
	
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
// 	gPad->SetGridx(1);
//	gPad->SetGridy(1);
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
//	gPad->SetGridx(1);
//	gPad->SetGridy(1);
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
//	gPad->SetGridx(1);
//	gPad->SetGridy(1);		
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
	
//	gPad->SetGridx(1);
//	gPad->SetGridy(1);
	
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
//	gPad->SetGridx(1);
//	gPad->SetGridy(1);	
		
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

	gStyle->SetMarkerStyle(8);	
	
	TCanvas *cdelta2 = new TCanvas("cdelta2","Plots",700,600);


  canvasDefault_1 = new TPad("canvasDefault_1", "newpad",0.0,0.0,1.0,0.41);//0.325);		

  canvasDefault_1->SetTopMargin(0.01);
  canvasDefault_1->SetBottomMargin(0.3);
  canvasDefault_1->SetRightMargin(0.05);
  canvasDefault_1->SetLeftMargin(0.11);	
  canvasDefault_1->SetFillStyle(0);
  canvasDefault_1->cd(); 
	T_delta_2_100_JET->Draw("");
	DR = new TLatex(0.8,0.3,"#DeltaR = #sqrt{#Delta #Phi^{2} + #Delta #eta^{2}}");
	Arrow = new TLatex(0.5,0.6,"#rightarrow");
	Arrow->Draw("same");
	Arrow->SetTextSize(0.13);	
  DR->SetTextSize(0.13);
//  DR->Draw("same");
	TLine *l_cut = new TLine(0.5,0,0.5,1.05);
	l_cut->SetLineWidth(4);
	l_cut->Draw("same");	

	gPad->SetGrid();
	gStyle->SetGridStyle(3);

	
  cdelta2->cd();
	canvasDefault_1->Draw();
	canvasDefault_1->cd();	
	gPad->Update();	
	T_delta_2_100_JET->GetPaintedGraph()->GetXaxis()->SetRangeUser(0,4.2);	
	T_delta_2_100_JET->GetPaintedGraph()->GetYaxis()->SetRangeUser(0,1.05);		
	T_delta_2_100_JET->GetPaintedGraph()->GetXaxis()->SetTitleSize(0.1);	
  T_delta_2_100_JET->GetPaintedGraph()->GetYaxis()->SetTitleSize(0.12);	
  T_delta_2_100_JET->GetPaintedGraph()->GetXaxis()->SetLabelSize(0.1);	
  T_delta_2_100_JET->GetPaintedGraph()->GetYaxis()->SetLabelSize(0.1);		
  T_delta_2_100_JET->GetPaintedGraph()->GetYaxis()->SetTitleOffset(0.38);
	T_delta_2_100_JET->SetTitle("");//"#slash{E}_{T}-req. efficiency");	
	T_delta_2_100_JET->GetPaintedGraph()->GetYaxis()->SetTitle("#varepsilon_{#DeltaR}");
	T_delta_2_100_JET->GetPaintedGraph()->GetXaxis()->SetTitleOffset(0.7);		
	T_delta_2_100_JET->GetPaintedGraph()->GetXaxis()->SetTitle("#DeltaR(#gamma, nearest Jet)"); 		
	 
	H_denumerator_JET_corr_100_2->GetXaxis()->SetRangeUser(0,4.2);	
	TH1F *ratio2 = (TH1F*)H_denumerator_JET_corr_100_2->Clone("ratio");

	for ( int i = 1; i < H_denumerator_JET_corr_100_2->GetNbinsX(); i++){
		ratio2->SetBinContent(i,0);			
		}
  ratio2->Draw("AXIS");
  ratio2->Draw("same AXIG");	
	ratio2->GetYaxis()->SetRangeUser(0,1.05);		
	ratio2->GetXaxis()->SetTitleSize(0.1);	
  ratio2->GetYaxis()->SetTitleSize(0.12);	
  ratio2->GetXaxis()->SetLabelSize(0.1);	
  ratio2->GetYaxis()->SetLabelSize(0.1);		
  ratio2->GetYaxis()->SetTitleOffset(0.38);
	ratio2->SetTitle("");//"#slash{E}_{T}-req. efficiency");	
	ratio2->GetYaxis()->SetTitle("#varepsilon_{#DeltaR}");
	ratio2->GetXaxis()->SetTitleOffset(0.9);		
	ratio2->GetXaxis()->SetTitle("#DeltaR(#gamma, nearest Jet)"); 	
	ratio2->GetYaxis()->SetRangeUser(0,1.05);	
	T_delta_2_100_JET->Draw("same");	
	
	DR = new TLatex(0.8,0.3,"#DeltaR = #sqrt{#Delta #Phi^{2} + #Delta #eta^{2}}");
	Arrow = new TLatex(0.5,0.6,"#rightarrow");
	Arrow->Draw("same");
	Arrow->SetTextSize(0.13);	
  DR->SetTextSize(0.13);
//  DR->Draw("same");
	TLine *l_cut = new TLine(0.5,0,0.5,1.05);
	l_cut->SetLineWidth(4);
	l_cut->Draw("same");	

	gPad->SetGrid();
	gStyle->SetGridStyle(3);
	gPad->Update();		
	cdelta2->cd();	
	
	 canvasDefault_2 = new TPad("canvasDefault_2", "newpad",0.0,0.4,1,1); //0.32
	 canvasDefault_2->Draw(); 
 	 canvasDefault_2->cd();
 	 canvasDefault_2->SetTopMargin(0.1);
 	 canvasDefault_2->SetBottomMargin(0.01);
 	 canvasDefault_2->SetRightMargin(0.05);
 	 canvasDefault_2->SetLeftMargin(0.11);	 
 	 canvasDefault_2->SetFillStyle(0);
	
	 H_denumerator_JET_corr_100_2->SetMaximum(10000);
	 H_denumerator_JET_corr_100_2->GetYaxis()->SetTitle("Events / bin");
	 H_denumerator_JET_corr_100_2->GetYaxis()->SetTitleOffset(0.7);	
	 H_denumerator_JET_corr_100_2->GetXaxis()->SetTitleOffset(0.5);		
	 H_denumerator_JET_corr_100_2->GetXaxis()->SetTitle("#DeltaR(#gamma, nearest Jet)"); 	 
	 H_denumerator_JET_corr_100_2->GetYaxis()->SetTitleSize(0.065); 	
	 H_denumerator_JET_corr_100_2->GetYaxis()->SetLabelSize(0.06); 		  
	 H_denumerator_JET_corr_100_2->GetXaxis()->SetRangeUser(0,4.2); 	 		 
	 H_denumerator_JET_corr_100_2->GetXaxis()->SetTitleSize(0.0); 
	 H_denumerator_JET_corr_100_2->Draw("hist");
	 H_numerator_JET_corr_100_2->Draw("same f hist");	 	 	
	 H_denumerator_JET_corr_100_2->SetLineColor(kRed); 
	 H_denumerator_JET_corr_100_2->SetLineStyle(1);
	 H_denumerator_JET_corr_100_2->SetLineWidth(3);	 	 	
	 H_denumerator_JET_corr_100_2->SetMinimum(0.3);
	 H_numerator_JET_corr_100_2->SetLineColor(kBlue);	
	 H_numerator_JET_corr_100_2->SetFillStyle(3003);	
	 H_numerator_JET_corr_100_2->SetFillColor(kBlue);	  	 
	 H_numerator_JET_corr_100_2->SetLineWidth(1);
	 
	 	gStyle->SetOptStat(00000);	
	gPad->SetGrid();
	gStyle->SetGridStyle(3);		  	 			 	
  canvasDefault_2->SetLogy(1);
  CMS_text->Draw();	
	TLegend *infoBox = new TLegend(0.27, 0.65, 0.95, 0.9,"");//0.75, 0.83, 0.99, 0.99, "");
  infoBox->AddEntry(H_denumerator_JET_corr_100_2,"Events triggered by baseline trigger","l");
  infoBox->AddEntry(H_numerator_JET_corr_100_2,"Events triggered by signal and baseline trigger","f");	
  infoBox->SetShadowColor(0);  // 0 = transparent
  infoBox->SetFillColor(kWhite); 
	infoBox->SetTextSize(0.05);
  infoBox->Draw();
		

//	gPad->SetGridx(1);
//	gPad->SetGridy(1);
	//gPad->SetGrid();
	gPad->Update();

//	gStyle->SetPadTickX(1);
//	gStyle->SetPadTickY(1);
	T_delta_2_100_JET->SetLineColor(kBlack);
	T_delta_2_100_JET->SetMarkerStyle(8);
	T_delta_2_100_JET->SetLineWidth(2);		
	gPad->Update();	
		
	
/*  T_delta_2_JET->SetLineColor(kRed);
  T_delta_2_JET->SetMarkerColor(kRed);
  T_delta_2_JET->SetMarkerStyle(1);
  T_delta_2_JET->SetLineWidth(2);			
	T_delta_2_100_JET->SetMarkerStyle(8);
	T_delta_2_100_JET->SetLineWidth(2);		
	T_delta_2_100_JET->Draw();*/
//	T_delta_2_JET->Draw("same");	
//	H_numerator_JET_corr_100_2->Draw();
//	H_denumerator_JET_corr_100_2->Draw();	
//	TVert100->Draw();
//	T_DeltaRCut_DeltaPhiCut_PtCut_100_2->Draw();
//	T_delta_1_JET->SetMarkerStyle(8);

/*  T_delta_2_100_JET->GetPaintedGraph()->GetXaxis()->SetTitleSize(0.06);	
  T_delta_2_100_JET->GetPaintedGraph()->GetYaxis()->SetTitleSize(0.07);	
  T_delta_2_100_JET->GetPaintedGraph()->GetXaxis()->SetLabelSize(0.06);	
  T_delta_2_100_JET->GetPaintedGraph()->GetYaxis()->SetLabelSize(0.06);	
  T_delta_2_100_JET->GetPaintedGraph()->GetXaxis()->SetTitle("#DeltaR(#gamma, nearest Jet)");	
  T_delta_2_100_JET->GetPaintedGraph()->GetYaxis()->SetTitle("#varepsilon_{#DeltaR}");
  T_delta_2_100_JET->GetPaintedGraph()->GetXaxis()->SetTitleOffset(0.7);	
  T_delta_2_100_JET->GetPaintedGraph()->GetYaxis()->SetTitleOffset(0.7);*/
		
//  T_delta_2_JET->GetPaintedGraph()->GetYaxis()->SetTitleOffset(0.9);
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

	
	TCanvas *cdelta3 = new TCanvas("cdelta3","Plots",700,600);
	
	canvasDefault_1 = new TPad("canvasDefault_1", "newpad",0.0,0.0,1.0,0.41);//0.325);		

  canvasDefault_1->SetTopMargin(0.01);
  canvasDefault_1->SetBottomMargin(0.3);
  canvasDefault_1->SetRightMargin(0.05);
  canvasDefault_1->SetLeftMargin(0.11);	
  canvasDefault_1->SetFillStyle(0);
  canvasDefault_1->cd(); 
	TSelection_pt->Draw("");
		
  cdelta3->cd();
	canvasDefault_1->Draw();
	canvasDefault_1->cd();	
	gPad->Update();	
	TSelection_pt->GetPaintedGraph()->GetXaxis()->SetRangeUser(0,400);	
	TSelection_pt->GetPaintedGraph()->GetYaxis()->SetRangeUser(0,1.05);		
	TSelection_pt->GetPaintedGraph()->GetXaxis()->SetTitleSize(0.1);	
  TSelection_pt->GetPaintedGraph()->GetYaxis()->SetTitleSize(0.12);	
  TSelection_pt->GetPaintedGraph()->GetXaxis()->SetLabelSize(0.1);	
  TSelection_pt->GetPaintedGraph()->GetYaxis()->SetLabelSize(0.1);		
  TSelection_pt->GetPaintedGraph()->GetYaxis()->SetTitleOffset(0.38);
	TSelection_pt->SetTitle("");//"#slash{E}_{T}-req. efficiency");	
	TSelection_pt->GetPaintedGraph()->GetYaxis()->SetTitle("#varepsilon_{#gamma-req.}");
	TSelection_pt->GetPaintedGraph()->GetXaxis()->SetTitleOffset(0.9);		
	TSelection_pt->GetPaintedGraph()->GetXaxis()->SetTitle("#gamma p_{T} [GeV]"); 	
		gPad->SetGrid();	
	TH1F *ratio = (TH1F*)H_denumerator_selection_pt->Clone("ratio");

	for ( int i = 1; i < H_denumerator_selection_pt->GetNbinsX(); i++){
		ratio->SetBinContent(i,0);			
		}
  ratio->Draw("AXIS");
  ratio->Draw("same AXIG");	
	ratio->GetYaxis()->SetRangeUser(0,1.05);		
	ratio->GetXaxis()->SetTitleSize(0.1);	
  ratio->GetYaxis()->SetTitleSize(0.12);	
  ratio->GetXaxis()->SetLabelSize(0.1);	
  ratio->GetYaxis()->SetLabelSize(0.1);		
  ratio->GetYaxis()->SetTitleOffset(0.38);
	ratio->SetTitle("");//"#slash{E}_{T}-req. efficiency");	
	ratio->GetYaxis()->SetTitle("#varepsilon_{#gamma-req.}");
	ratio->GetXaxis()->SetTitleOffset(0.9);		
	ratio->GetXaxis()->SetTitle("#gamma p_{T} [GeV]"); 	
	ratio->GetYaxis()->SetRangeUser(0,1.05);	
	TSelection_pt->Draw("same");
	
	EffiPt = new TLatex(45,0.2,"#varepsilon_{#gamma-req.} = (88.0 #pm 0.7(stat.)) %");
  EffiPt->SetTextSize(0.1);
  EffiPt->Draw();
	TLine *l_cut_pt = new TLine(40,0,40,1.05);
	l_cut_pt->SetLineWidth(4);
	l_cut_pt->Draw("same");
	Arrow2 = new TLatex(40,0.6,"#rightarrow");
	Arrow2->SetTextSize(0.13);	
	Arrow2->Draw("same");	

	gPad->SetGrid();
	gStyle->SetGridStyle(3);				
	gPad->Update();		
	
	 cdelta3->cd();	
			
	 canvasDefault_2 = new TPad("canvasDefault_2", "newpad",0.0,0.4,1,1); //0.32
	 canvasDefault_2->Draw(); 
 	 canvasDefault_2->cd();
 	 canvasDefault_2->SetTopMargin(0.1);
 	 canvasDefault_2->SetBottomMargin(0.01);
 	 canvasDefault_2->SetRightMargin(0.05);
 	 canvasDefault_2->SetLeftMargin(0.11);	 
 	 canvasDefault_2->SetFillStyle(0);

	 H_denumerator_selection_pt->Draw("same hist");
	 H_numerator_selection_pt->Draw("same f hist");		 
	 H_denumerator_selection_pt->SetMaximum(20000);
//	 H_denumerator_selection_pt->GetXaxis()->SetRangeUser(0,400); 	 
	 H_denumerator_selection_pt->GetYaxis()->SetTitle("Events / bin");
	 H_denumerator_selection_pt->GetYaxis()->SetTitleOffset(0.7);	
	 H_denumerator_selection_pt->GetXaxis()->SetTitleOffset(0.5);		
	 H_denumerator_selection_pt->GetXaxis()->SetTitle("#gamma p_{T} [GeV]"); 	 
	 H_denumerator_selection_pt->GetYaxis()->SetTitleSize(0.065); 	
	 H_denumerator_selection_pt->GetYaxis()->SetLabelSize(0.06); 		  	 		 
	 H_denumerator_selection_pt->GetXaxis()->SetTitleSize(0.0); 
	 gPad->Update(); 	 
 	 	
	 H_denumerator_selection_pt->SetLineColor(kRed); 
	 H_denumerator_selection_pt->SetLineStyle(1);
	 H_denumerator_selection_pt->SetLineWidth(3);	 	 	
	 H_denumerator_selection_pt->SetMinimum(0.3);
	 H_numerator_selection_pt->SetLineColor(kBlue);	
	 H_numerator_selection_pt->SetFillStyle(3003);	
	 H_numerator_selection_pt->SetFillColor(kBlue);	  	 
	 H_numerator_selection_pt->SetLineWidth(1);
	 gStyle->SetOptStat(00000);
	 gPad->Update();  	 			 	
  canvasDefault_2->SetLogy(1);
  CMS_text->Draw();	
	TLegend *infoBox = new TLegend(0.27, 0.65, 0.95, 0.9,"");//0.75, 0.83, 0.99, 0.99, "");
  infoBox->AddEntry(H_denumerator_selection_pt,"Events triggered by baseline trigger","l");
  infoBox->AddEntry(H_numerator_selection_pt,"Events triggered by signal and baseline trigger","f");	
  infoBox->SetShadowColor(0);  // 0 = transparent
  infoBox->SetFillColor(kWhite); 
	infoBox->SetTextSize(0.05);
  infoBox->Draw();	

	gStyle->SetPadTickX(1);
	gStyle->SetPadTickY(1);
	gPad->SetGridx(1);
	gPad->SetGridy(1);

	gPad->Update();

	gStyle->SetPadTickX(1);
	gStyle->SetPadTickY(1);
	TSelection_pt->SetLineColor(kBlack);
	TSelection_pt->SetMarkerStyle(8);	
	TSelection_pt->SetLineWidth(2);		
	gPad->Update();	

	
	TLegend *infoBox = new TLegend(0.77, 0.8, 0.99, 0.99,"");//0.75, 0.83, 0.99, 0.99, "");
	infoBox->SetHeader("#gamma-req. efficiency:");
 // infoBox->AddEntry(T_pt_leg_40_2,"MET > 40 (tight)","lep");		
 // infoBox->AddEntry(T_DeltaRCut_DeltaPhiCut_PtCut_2,"MET > 40 - cleaned (tight)","lep");
//  infoBox->AddEntry(Error2,"Eff. with stat. uncertainty","f");	
//  infoBox->AddEntry(Error,"3 % syst. uncertainty","f");
	infoBox->AddEntry(T_pt_leg_40_2,"before #DeltaR cut","lep");	
	infoBox->AddEntry(T_DeltaRCut_2,"after #DeltaR cut","lep");
 // infoBox->AddEntry(T_DeltaRCut2_DeltaPhiCut_PtCut_2,"MET > 40 - cleaned (tight)","lep");	
  infoBox->SetShadowColor(0);  // 0 = transparent
  infoBox->SetFillColor(kWhite); 
	infoBox->SetTextSize(0.035);
//  infoBox->Draw();
			
//	T_DeltaRCut_DeltaPhiCut_PtCut_100_2->SetMarkerStyle(8);
//	T_DeltaRCut_DeltaPhiCut_PtCut_100_2->Draw("same");
  TGraphAsymmErrors *Effi_loose_pt = new TGraphAsymmErrors();
  Effi_loose_pt->Divide(H_numerator_DeltaRCut_PtCut_2,H_denumerator_DeltaRCut_PtCut_2,"v cp");	
  double effi_loose_pt = Effi_loose_pt->GetMean(2); //2 = Y axis
  double error_high_loose_pt = Effi_loose_pt->GetErrorYhigh(0);
  double error_low_loose_pt = Effi_loose_pt->GetErrorYlow(0);
	cout << "____________________________________" << endl;	
	cout << "*******PT LEG EFFICIENCY************" << endl;
	cout << "********LOOSE SELECTION*************" << endl;
	cout << "____________________________________" << endl;
  cout << "Error_high: " << error_high_loose_pt << endl;
  cout << "Error_low: " << error_low_loose_pt << endl;
  cout << "Efficieny: " << effi_loose_pt << endl;
	cout << "____________________________________" << endl;
	cout << "____________________________________" << endl;	
	
	cout << "Integral:  " << H_numerator_DeltaRCut_PtCut_2->Integral(0,-1)/H_denumerator_DeltaRCut_PtCut_2->Integral(0,-1) << endl;
	
		
  TGraphAsymmErrors *Effi_met_pt = new TGraphAsymmErrors();
  Effi_met_pt->Divide(H_numerator_PT_calc_MET40,H_denumerator_PT_calc_MET40,"v cp");	
  double effi_met_pt = Effi_met_pt->GetMean(2); //2 = Y axis
  double error_high_met_pt = Effi_met_pt->GetErrorYhigh(0);
  double error_low_met_pt = Effi_met_pt->GetErrorYlow(0);
	cout << "____________________________________" << endl;	
	cout << "*******PT LEG EFFICIENCY************" << endl;
	cout << "********MET SELECTION*************" << endl;
	cout << "____________________________________" << endl;
  cout << "Error_high: " << error_high_met_pt << endl;
  cout << "Error_low: " << error_low_met_pt << endl;
  cout << "Efficieny: " << effi_met_pt << endl;
	cout << "____________________________________" << endl;
	cout << "____________________________________" << endl;	
		
		
  TGraphAsymmErrors *Effi = new TGraphAsymmErrors();
	Effi->Divide(H_numerator_PT_calc_selection,H_denumerator_PT_calc_selection,"v cp");
  double effi = Effi->GetMean(2); //2 = Y axis
  double error_high = Effi->GetErrorYhigh(0);
  double error_low = Effi->GetErrorYlow(0);
	cout << "____________________________________" << endl;	
	cout << "*******PT LEG EFFICIENCY************" << endl;
	cout << "********FULL SELECTION**************" << endl;
	cout << "____________________________________" << endl;
  cout << "Error_high: " << error_high << endl;
  cout << "Error_low: " << error_low << endl;
  cout << "Efficieny: " << effi << endl;
	cout << "____________________________________" << endl;
	cout << "____________________________________" << endl;
	cout << "Integral:  " << H_numerator_PT_calc_selection->Integral(0,-1)/H_denumerator_PT_calc_selection->Integral(0,-1) << endl;
	TCanvas *cdelta4 = new TCanvas("cdelta4","Plots",600,600);
	
  TGraphAsymmErrors *Effi2 = new TGraphAsymmErrors();
  Effi2->Divide(H_numerator_MET_calc,H_denumerator_MET_calc,"v cp");
	cout << "____________________________________" << endl;	
	cout << "*******MET LEG EFFICIENCY***********" << endl;	
	cout << "********LOOSE SELECTION*************" << endl;	
	cout << "____________________________________" << endl; 
  double effi2 = Effi2->GetMean(2); //2 = Y axis
  double error_high2 = Effi2->GetErrorYhigh(0);
  double error_low2 = Effi2->GetErrorYlow(0);
	cout << "____________________________________" << endl;
  cout << "Error_high: " << error_high2 << endl;
  cout << "Error_low: " << error_low2 << endl;
  cout << "Efficieny: " << effi2 << endl;	
	cout << "____________________________________" << endl;
	cout << "____________________________________" << endl;	
	
  TGraphAsymmErrors *Effi2_full_met = new TGraphAsymmErrors();
  Effi2_full_met->Divide(H_numerator_MET_calc_selection,H_denumerator_MET_calc_selection,"v cp");
	cout << "____________________________________" << endl;	
	cout << "*******MET LEG EFFICIENCY***********" << endl;	
	cout << "********FULL SELECTION*************" << endl;	
	cout << "____________________________________" << endl; 
  double effi2_full_met = Effi2_full_met->GetMean(2); //2 = Y axis
  double error_high2_full_met = Effi2_full_met->GetErrorYhigh(0);
  double error_low2_full_met = Effi2_full_met->GetErrorYlow(0);
	cout << "____________________________________" << endl;
  cout << "Error_high: " << error_high2_full_met << endl;
  cout << "Error_low: " << error_low2_full_met << endl;
  cout << "Efficieny: " << effi2_full_met << endl;	
	cout << "____________________________________" << endl;
	cout << "____________________________________" << endl;		
	
//	T_r9_2->Draw();
	
//	T_DeltaRCut_2->SetMarkerStyle(8);
//	T_DeltaRCut_2->Draw();
	
  T_MET_calc->SetMarkerStyle(8);
  T_MET_calc->Draw();
	
	TCanvas *c2D = new TCanvas("c2D","Plots",600,600);
	gStyle->SetPalette(55,0);
	T_2D->Draw("colz");
	T_2D->GetTotalHistogram()->GetZaxis()->SetNdivisions(50);
}


