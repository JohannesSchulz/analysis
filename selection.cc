#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <map>
#include <sstream>

#include <TH1.h>
#include <TH1F.h>
#include <TH2.h>
#include <TF1.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TLegend.h>
#include <TROOT.h>
#include <TFile.h>
#include <TCanvas.h>
#include <TGraph.h>
#include <TGraphQQ.h>
#include <TMath.h>

using namespace std;

int selection(){

	double trigger_effi = 0.865;
//	double trigger_effi = 0.885339;
	double e_fakerate = 0.0148;
	
	double scale_EWK = 1.95;
	double scale_Z = 1.424;
	double scale_W = 1.579;
	double scale_VGamma = 1.33;	
	double scale_GJets = 2.385;	
//	double scale_EWK = 1.9223;
//	double scale_GJets = 2.34156;
	double scale_740 = 1.135;		
	double scale_640 = 1.154034091;	
	double scale_540 = 1.183054415;		
	
	int rebin = 1.;
	
//	string histo = "h_met_array";
//	string histo = "h_METoverSqHT_scale";

  TFile *Data  					= new TFile("PhotonParkedD_V06.1_sel.root");
	TFile *GJets			  	= new TFile("GJetsAdd.root");	
//	TFile *G_file	  	= new TFile("GAdd.root");	
	TFile *QCD	  				= new TFile("QCDAdd.root");		
  TFile *EWKBG 					= new TFile("EWKBG.root");
  TFile *Z 							= new TFile("ZGammaAdd.root");	
  TFile *W 							= new TFile("WGammaAdd.root");	
	TFile *GammaPixel			= new TFile("GammaPixel.root");	
//	TFile *ttbar	= new TFile("TTJets_V02.1_sel.root");	
  TFile *ttbar					= new TFile("TTGamma_V02.1_sel.root");
	TFile *Diboson				= new TFile("Diboson.root");	
  TFile *signal_540			= new TFile("signal_540_530.root");
	TFile *signal_640			= new TFile("signal_640_630.root");	
	TFile *signal_740			= new TFile("signal_740_730.root");	
	
//////////////////////////////////////////
/* Get all histos, right scale, add BGs */
//////////////////////////////////////////
		
	TH1F *	H_Data_1  	 	= (TH1F*)Data->Get("h_stage1_met_significance");	
	TH1F *	H_GJets_1    = (TH1F*)GJets->Get("h_stage1_met_significance");
//	TH1F *	H_G2    	= (TH1F*)G_file->Get(histo.c_str());	
	TH1F *	H_QCD_1    		= (TH1F*)QCD->Get("h_stage1_met_significance");		
  TH1F *	H_EWKBG_1	 		= (TH1F*)EWKBG->Get("h_stage1_met_significance");
	TH1F *	H_GammaPixel_1= (TH1F*)GammaPixel->Get("h_stage1_met_significance");	
	TH1F *	H_ttbar_1 		= (TH1F*)ttbar->Get("h_stage1_met_significance");
	TH1F *	H_Diboson_1 	= (TH1F*)Diboson->Get("h_stage1_met_significance");	
	TH1F *	H_signal_540_1= (TH1F*)signal_540->Get("h_stage1_met_significance");
	TH1F *	H_signal_640_1= (TH1F*)signal_640->Get("h_stage1_met_significance");		
	
	H_GammaPixel_1->Scale(e_fakerate);
	H_EWKBG_1->Scale(scale_EWK);
	H_GJets_1->Scale(scale_GJets);

  H_EWKBG_1->Add(H_GJets_1);
  H_EWKBG_1->Add(H_QCD_1);	
  H_EWKBG_1->Add(H_ttbar_1);	
  H_EWKBG_1->Add(H_Diboson_1);
	
  H_EWKBG_1->Scale(trigger_effi);
	
  H_EWKBG_1->Add(H_GammaPixel_1);
	
  H_signal_540_1->Scale(trigger_effi);
	H_signal_640_1->Scale(scale_640*trigger_effi);	
	
/////////////////	
	/*Next stage */
/////////////////	
	
	TH1F *	H_Data_2  	 	= (TH1F*)Data->Get("h_stage2_met_significance");	
	TH1F *	H_GJets_2    = (TH1F*)GJets->Get("h_stage2_met_significance");
//	TH1F *	H_G2    	= (TH1F*)G_file->Get(histo.c_str());	
	TH1F *	H_QCD_2    		= (TH1F*)QCD->Get("h_stage2_met_significance");		
  TH1F *	H_EWKBG_2	 		= (TH1F*)EWKBG->Get("h_stage2_met_significance");
	TH1F *	H_GammaPixel_2= (TH1F*)GammaPixel->Get("h_stage2_met_significance");	
	TH1F *	H_ttbar_2 		= (TH1F*)ttbar->Get("h_stage2_met_significance");
	TH1F *	H_Diboson_2 	= (TH1F*)Diboson->Get("h_stage2_met_significance");	
	TH1F *	H_signal_540_2= (TH1F*)signal_540->Get("h_stage2_met_significance");
	TH1F *	H_signal_640_2= (TH1F*)signal_640->Get("h_stage2_met_significance");		
	
	H_GammaPixel_2->Scale(e_fakerate);
	H_EWKBG_2->Scale(scale_EWK);
	H_GJets_2->Scale(scale_GJets);

  H_EWKBG_2->Add(H_GJets_2);
  H_EWKBG_2->Add(H_QCD_2);	
  H_EWKBG_2->Add(H_ttbar_2);	
  H_EWKBG_2->Add(H_Diboson_2);
	
  H_EWKBG_2->Scale(trigger_effi);
	
  H_EWKBG_2->Add(H_GammaPixel_2);
	
  H_signal_540_2->Scale(trigger_effi);
	H_signal_640_2->Scale(scale_640*trigger_effi);	
	
/////////////////	
	/*Next stage */
/////////////////	
		
	TH1F *	H_Data_3  	 	= (TH1F*)Data->Get("h_stage3_met_significance");	
	TH1F *	H_GJets_3    = (TH1F*)GJets->Get("h_stage3_met_significance");
//	TH1F *	H_G2    	= (TH1F*)G_file->Get(histo.c_str());	
	TH1F *	H_QCD_3    		= (TH1F*)QCD->Get("h_stage3_met_significance");		
  TH1F *	H_EWKBG_3	 		= (TH1F*)EWKBG->Get("h_stage3_met_significance");
	TH1F *	H_GammaPixel_3= (TH1F*)GammaPixel->Get("h_stage3_met_significance");	
	TH1F *	H_ttbar_3 		= (TH1F*)ttbar->Get("h_stage3_met_significance");
	TH1F *	H_Diboson_3 	= (TH1F*)Diboson->Get("h_stage3_met_significance");	
	TH1F *	H_signal_540_3= (TH1F*)signal_540->Get("h_stage3_met_significance");
	TH1F *	H_signal_640_3= (TH1F*)signal_640->Get("h_stage3_met_significance");		
	
	H_GammaPixel_3->Scale(e_fakerate);
	H_EWKBG_3->Scale(scale_EWK);
	H_GJets_3->Scale(scale_GJets);

  H_EWKBG_3->Add(H_GJets_3);
  H_EWKBG_3->Add(H_QCD_3);	
  H_EWKBG_3->Add(H_ttbar_3);	
  H_EWKBG_3->Add(H_Diboson_3);
	
  H_EWKBG_3->Scale(trigger_effi);
	
  H_EWKBG_3->Add(H_GammaPixel_3);
	
  H_signal_540_3->Scale(trigger_effi);
	H_signal_640_3->Scale(scale_640*trigger_effi);	
	
/////////////////	
	/*Next stage */
/////////////////	
		
	TH1F *	H_Data_4  	 	= (TH1F*)Data->Get("h_stage4_met_significance");	
	TH1F *	H_GJets_4    = (TH1F*)GJets->Get("h_stage4_met_significance");
//	TH1F *	H_G2    	= (TH1F*)G_file->Get(histo.c_str());	
	TH1F *	H_QCD_4    		= (TH1F*)QCD->Get("h_stage4_met_significance");		
  TH1F *	H_EWKBG_4	 		= (TH1F*)EWKBG->Get("h_stage4_met_significance");
	TH1F *	H_GammaPixel_4= (TH1F*)GammaPixel->Get("h_stage4_met_significance");	
	TH1F *	H_ttbar_4 		= (TH1F*)ttbar->Get("h_stage4_met_significance");
	TH1F *	H_Diboson_4 	= (TH1F*)Diboson->Get("h_stage4_met_significance");	
	TH1F *	H_signal_540_4= (TH1F*)signal_540->Get("h_stage4_met_significance");
	TH1F *	H_signal_640_4= (TH1F*)signal_640->Get("h_stage4_met_significance");		
	
	H_GammaPixel_4->Scale(e_fakerate);
	H_EWKBG_4->Scale(scale_EWK);
	H_GJets_4->Scale(scale_GJets);

  H_EWKBG_4->Add(H_GJets_4);
  H_EWKBG_4->Add(H_QCD_4);	
  H_EWKBG_4->Add(H_ttbar_4);	
  H_EWKBG_4->Add(H_Diboson_4);
	
  H_EWKBG_4->Scale(trigger_effi);
	
  H_EWKBG_4->Add(H_GammaPixel_4);
	
  H_signal_540_4->Scale(trigger_effi);
	H_signal_640_4->Scale(scale_640*trigger_effi);	
	
/////////////////	
	/*Next stage */
/////////////////	
		
	
	TH1F *	H_Data_5  	 	= (TH1F*)Data->Get("h_stage5_met_significance");	
	TH1F *	H_GJets_5    = (TH1F*)GJets->Get("h_stage5_met_significance");
//	TH1F *	H_G2    	= (TH1F*)G_file->Get(histo.c_str());	
	TH1F *	H_QCD_5    		= (TH1F*)QCD->Get("h_stage5_met_significance");		
  TH1F *	H_EWKBG_5	 		= (TH1F*)EWKBG->Get("h_stage5_met_significance");
	TH1F *	H_GammaPixel_5= (TH1F*)GammaPixel->Get("h_stage5_met_significance");	
	TH1F *	H_ttbar_5 		= (TH1F*)ttbar->Get("h_stage5_met_significance");
	TH1F *	H_Diboson_5 	= (TH1F*)Diboson->Get("h_stage5_met_significance");	
	TH1F *	H_signal_540_5= (TH1F*)signal_540->Get("h_stage5_met_significance");
	TH1F *	H_signal_640_5= (TH1F*)signal_640->Get("h_stage5_met_significance");		
	
	H_GammaPixel_5->Scale(e_fakerate);
	H_EWKBG_5->Scale(scale_EWK);
	H_GJets_5->Scale(scale_GJets);

  H_EWKBG_5->Add(H_GJets_5);
  H_EWKBG_5->Add(H_QCD_5);	
  H_EWKBG_5->Add(H_ttbar_5);	
  H_EWKBG_5->Add(H_Diboson_5);
	
  H_EWKBG_5->Scale(trigger_effi);
	
  H_EWKBG_5->Add(H_GammaPixel_5);
	
  H_signal_540_5->Scale(trigger_effi);
	H_signal_640_5->Scale(scale_640*trigger_effi);	
	
/////////////////	
	/*Next stage */
/////////////////	
		
	
	TH1F *	H_Data_6  	 	= (TH1F*)Data->Get("h_stage6_met_significance");	
	TH1F *	H_GJets_6    = (TH1F*)GJets->Get("h_stage6_met_significance");
//	TH1F *	H_G2    	= (TH1F*)G_file->Get(histo.c_str());	
	TH1F *	H_QCD_6    		= (TH1F*)QCD->Get("h_stage6_met_significance");		
  TH1F *	H_EWKBG_6	 		= (TH1F*)EWKBG->Get("h_stage6_met_significance");
	TH1F *	H_GammaPixel_6= (TH1F*)GammaPixel->Get("h_stage6_met_significance");	
	TH1F *	H_ttbar_6 		= (TH1F*)ttbar->Get("h_stage6_met_significance");
	TH1F *	H_Diboson_6 	= (TH1F*)Diboson->Get("h_stage6_met_significance");	
	TH1F *	H_signal_540_6= (TH1F*)signal_540->Get("h_stage6_met_significance");
	TH1F *	H_signal_640_6= (TH1F*)signal_640->Get("h_stage6_met_significance");		
	
	H_GammaPixel_6->Scale(e_fakerate);
	H_EWKBG_6->Scale(scale_EWK);
	H_GJets_6->Scale(scale_GJets);

  H_EWKBG_6->Add(H_GJets_6);
  H_EWKBG_6->Add(H_QCD_6);	
  H_EWKBG_6->Add(H_ttbar_6);	
  H_EWKBG_6->Add(H_Diboson_6);
	
  H_EWKBG_6->Scale(trigger_effi);
	
  H_EWKBG_6->Add(H_GammaPixel_6);
	
  H_signal_540_6->Scale(trigger_effi);
	H_signal_640_6->Scale(scale_640*trigger_effi);	
	
/////////////////	
	/*Next stage */
/////////////////	
		
	
	TH1F *	H_Data_7  	 	= (TH1F*)Data->Get("h_stage7_met_significance");	
	TH1F *	H_GJets_7    = (TH1F*)GJets->Get("h_stage7_met_significance");
//	TH1F *	H_G2    	= (TH1F*)G_file->Get(histo.c_str());	
	TH1F *	H_QCD_7    		= (TH1F*)QCD->Get("h_stage7_met_significance");		
  TH1F *	H_EWKBG_7	 		= (TH1F*)EWKBG->Get("h_stage7_met_significance");
	TH1F *	H_GammaPixel_7= (TH1F*)GammaPixel->Get("h_stage7_met_significance");	
	TH1F *	H_ttbar_7 		= (TH1F*)ttbar->Get("h_stage7_met_significance");
	TH1F *	H_Diboson_7 	= (TH1F*)Diboson->Get("h_stage7_met_significance");	
	TH1F *	H_signal_540_7= (TH1F*)signal_540->Get("h_stage7_met_significance");
	TH1F *	H_signal_640_7= (TH1F*)signal_640->Get("h_stage7_met_significance");		
	
	H_GammaPixel_7->Scale(e_fakerate);
	H_EWKBG_7->Scale(scale_EWK);
	H_GJets_7->Scale(scale_GJets);

  H_EWKBG_7->Add(H_GJets_7);
  H_EWKBG_7->Add(H_QCD_7);	
  H_EWKBG_7->Add(H_ttbar_7);	
  H_EWKBG_7->Add(H_Diboson_7);
	
  H_EWKBG_7->Scale(trigger_effi);
	
  H_EWKBG_7->Add(H_GammaPixel_7);
	
  H_signal_540_7->Scale(trigger_effi);
	H_signal_640_7->Scale(scale_640*trigger_effi);	
	
/////////////////	
	/*Next stage */
/////////////////	
		
	
	TH1F *	H_Data_8  	 	= (TH1F*)Data->Get("h_stage1_N-1_met_ratio_pt_ratio");	
	TH1F *	H_GJets_8    = (TH1F*)GJets->Get("h_stage1_N-1_met_ratio_pt_ratio");
//	TH1F *	H_G2    	= (TH1F*)G_file->Get(histo.c_str());	
	TH1F *	H_QCD_8    		= (TH1F*)QCD->Get("h_stage1_N-1_met_ratio_pt_ratio");		
  TH1F *	H_EWKBG_8	 		= (TH1F*)EWKBG->Get("h_stage1_N-1_met_ratio_pt_ratio");
	TH1F *	H_GammaPixel_8= (TH1F*)GammaPixel->Get("h_stage1_N-1_met_ratio_pt_ratio");	
	TH1F *	H_ttbar_8 		= (TH1F*)ttbar->Get("h_stage1_N-1_met_ratio_pt_ratio");
	TH1F *	H_Diboson_8 	= (TH1F*)Diboson->Get("h_stage1_N-1_met_ratio_pt_ratio");	
	TH1F *	H_signal_540_8= (TH1F*)signal_540->Get("h_stage1_N-1_met_ratio_pt_ratio");
	TH1F *	H_signal_640_8= (TH1F*)signal_640->Get("h_stage1_N-1_met_ratio_pt_ratio");		
	
	H_GammaPixel_8->Scale(e_fakerate);
	H_EWKBG_8->Scale(scale_EWK);
	H_GJets_8->Scale(scale_GJets);

  H_EWKBG_8->Add(H_GJets_8);
  H_EWKBG_8->Add(H_QCD_8);	
  H_EWKBG_8->Add(H_ttbar_8);	
  H_EWKBG_8->Add(H_Diboson_8);
	
  H_EWKBG_8->Scale(trigger_effi);
	
  H_EWKBG_8->Add(H_GammaPixel_8);
	
  H_signal_540_8->Scale(trigger_effi);
	H_signal_640_8->Scale(scale_640*trigger_effi);	
	
/////////////////	
	/*Next stage */
/////////////////	
		
	
	TH1F *	H_Data_12  	 	= (TH1F*)Data->Get("h_stage12_met_significance");	
	TH1F *	H_GJets_12    = (TH1F*)GJets->Get("h_stage12_met_significance");
//	TH1F *	H_G2    	= (TH1F*)G_file->Get(histo.c_str());	
	TH1F *	H_QCD_12    		= (TH1F*)QCD->Get("h_stage12_met_significance");		
  TH1F *	H_EWKBG_12	 		= (TH1F*)EWKBG->Get("h_stage12_met_significance");
	TH1F *	H_GammaPixel_12= (TH1F*)GammaPixel->Get("h_stage12_met_significance");	
	TH1F *	H_ttbar_12 		= (TH1F*)ttbar->Get("h_stage12_met_significance");
	TH1F *	H_Diboson_12 	= (TH1F*)Diboson->Get("h_stage12_met_significance");	
	TH1F *	H_signal_540_12= (TH1F*)signal_540->Get("h_stage12_met_significance");
	TH1F *	H_signal_640_12= (TH1F*)signal_640->Get("h_stage12_met_significance");		
	
	H_GammaPixel_12->Scale(e_fakerate);
	H_EWKBG_12->Scale(scale_EWK);
	H_GJets_12->Scale(scale_GJets);

  H_EWKBG_12->Add(H_GJets_12);
  H_EWKBG_12->Add(H_QCD_12);	
  H_EWKBG_12->Add(H_ttbar_12);	
  H_EWKBG_12->Add(H_Diboson_12);
	
  H_EWKBG_12->Scale(trigger_effi);
	
  H_EWKBG_12->Add(H_GammaPixel_12);
	
  H_signal_540_12->Scale(trigger_effi);
	H_signal_640_12->Scale(scale_640*trigger_effi);	
	
/////////////////	
	/*Next stage */
/////////////////			
		
	
			
	TH1F *	H_Data_10  	 	= (TH1F*)Data->Get("h_stage10_met_significance_32");	
	TH1F *	H_GJets_10    = (TH1F*)GJets->Get("h_stage10_met_significance_32");
//	TH1F *	H_G2    	= (TH1F*)G_file->Get(histo.c_str());	
	TH1F *	H_QCD_10    		= (TH1F*)QCD->Get("h_stage10_met_significance_32");		
  TH1F *	H_EWKBG_10	 		= (TH1F*)EWKBG->Get("h_stage10_met_significance_32");
	TH1F *	H_GammaPixel_10= (TH1F*)GammaPixel->Get("h_stage10_met_significance_32");	
	TH1F *	H_ttbar_10 		= (TH1F*)ttbar->Get("h_stage10_met_significance_32");
	TH1F *	H_Diboson_10 	= (TH1F*)Diboson->Get("h_stage10_met_significance_32");	
	TH1F *	H_signal_540_10= (TH1F*)signal_540->Get("h_stage10_met_significance_32");
	TH1F *	H_signal_640_10= (TH1F*)signal_640->Get("h_stage10_met_significance_32");		
	
	H_GammaPixel_10->Scale(e_fakerate);
	H_EWKBG_10->Scale(scale_EWK);
	H_GJets_10->Scale(scale_GJets);

  H_EWKBG_10->Add(H_GJets_10);
  H_EWKBG_10->Add(H_QCD_10);	
  H_EWKBG_10->Add(H_ttbar_10);	
  H_EWKBG_10->Add(H_Diboson_10);
	
  H_EWKBG_10->Scale(trigger_effi);
	
  H_EWKBG_10->Add(H_GammaPixel_10);
	
  H_signal_540_10->Scale(trigger_effi);
	H_signal_640_10->Scale(scale_640*trigger_effi);	
	
/////////////////	
	/*Next stage */
/////////////////	
	TH1F *	H_Data_11  	 	= (TH1F*)Data->Get("h_stage11_met_significance");	
	TH1F *	H_GJets_11    = (TH1F*)GJets->Get("h_stage11_met_significance");
//	TH1F *	H_G2    	= (TH1F*)G_file->Get(histo.c_str());	
	TH1F *	H_QCD_11    		= (TH1F*)QCD->Get("h_stage11_met_significance");		
  TH1F *	H_EWKBG_11	 		= (TH1F*)EWKBG->Get("h_stage11_met_significance");
	TH1F *	H_GammaPixel_11= (TH1F*)GammaPixel->Get("h_stage11_met_significance");	
	TH1F *	H_ttbar_11 		= (TH1F*)ttbar->Get("h_stage11_met_significance");
	TH1F *	H_Diboson_11 	= (TH1F*)Diboson->Get("h_stage11_met_significance");	
	TH1F *	H_signal_540_11= (TH1F*)signal_540->Get("h_stage11_met_significance");
	TH1F *	H_signal_640_11= (TH1F*)signal_640->Get("h_stage11_met_significance");		
	TH1F *	H_signal_740_11= (TH1F*)signal_740->Get("h_stage11_met_significance");	
	H_GammaPixel_11->Scale(e_fakerate);
	H_EWKBG_11->Scale(scale_EWK);
	H_GJets_11->Scale(scale_GJets);

  H_EWKBG_11->Add(H_GJets_11);
  H_EWKBG_11->Add(H_QCD_11);	
  H_EWKBG_11->Add(H_ttbar_11);	
  H_EWKBG_11->Add(H_Diboson_11);
	
  H_EWKBG_11->Scale(trigger_effi);
	
  H_EWKBG_11->Add(H_GammaPixel_11);
	
  H_signal_540_11->Scale(scale_540*trigger_effi);
	H_signal_640_11->Scale(scale_640*trigger_effi);
	H_signal_740_11->Scale(scale_740*trigger_effi);
	
//////////////////////
/*Plot all together */
//////////////////////
			
	TCanvas *canvas = new TCanvas("canvas","Plots",1000,700);
  canvas->Divide(1,1);
	TCanvas *canvas2 = new TCanvas("canvas2","Plots",1000,700);
  canvas2->Divide(2,1);	
	
	canvas->cd(1);
	H_EWKBG_1->GetYaxis()->SetTitleSize(0.06);
  H_EWKBG_1->GetXaxis()->SetTitleSize(0.06);		
	H_EWKBG_1->GetYaxis()->SetLabelSize(0.06);
	H_EWKBG_1->GetXaxis()->SetLabelSize(0.06);
	H_EWKBG_1->GetXaxis()->SetTitleOffset(0.85);
	H_EWKBG_1->GetYaxis()->SetTitleOffset(0.5);	
  H_EWKBG_1->SetTitle("");
  H_EWKBG_1->GetXaxis()->SetRangeUser(0,600);
  H_EWKBG_1->SetLineColor(kRed);
	H_EWKBG_1->SetFillStyle(3003);	
  H_EWKBG_1->SetFillColor(kRed);	
  H_EWKBG_1->Draw("hist");	

	H_EWKBG_2->Draw("hist same");
	H_EWKBG_2->SetLineColor(kAzure+7);
	H_EWKBG_2->SetLineWidth(4);		
	
	H_EWKBG_3->Draw("hist  same");
	H_EWKBG_3->SetLineColor(kCyan);
	H_EWKBG_3->SetLineWidth(4);		
	
	H_EWKBG_4->Draw("hist  same");
	H_EWKBG_4->SetLineColor(kGreen+2);
	H_EWKBG_4->SetLineWidth(4);		
	
	H_EWKBG_5->Draw("hist  same");
	H_EWKBG_5->SetLineColor(kBlue+2);
	H_EWKBG_5->SetLineWidth(4);		
	
	H_EWKBG_6->Draw("hist  same");
	H_EWKBG_6->SetLineColor(kRed+2);	
	H_EWKBG_6->SetLineWidth(4);		
		
	H_EWKBG_7->Draw("hist  same");
	H_EWKBG_7->SetLineColor(kOrange+8);
	H_EWKBG_7->SetLineWidth(4);		
	
	H_EWKBG_8->Draw("hist  same");
  H_EWKBG_8->SetLineColor(kYellow);
	H_EWKBG_8->SetLineWidth(4);		
	
	H_EWKBG_12->Draw("hist  same");
	H_EWKBG_12->SetLineColor(kMagenta+2);
	H_EWKBG_12->SetLineWidth(4);	
		
	H_EWKBG_10->Draw("hist  same");
	H_EWKBG_10->SetLineColor(kRed);
	H_EWKBG_10->SetLineWidth(4);	
	
	H_EWKBG_11->Draw("hist  same");
	H_EWKBG_11->SetLineColor(kTeal-2);
	H_EWKBG_11->SetLineWidth(4);	
	
	H_signal_540_1->Draw("hist  same");
	H_signal_540_1->SetLineColor(kBlack);
	H_signal_540_1->SetLineWidth(3);		
	H_signal_640_1->Draw("hist  same");
	H_signal_640_1->SetLineColor(kGray+3);
	H_signal_640_1->SetLineWidth(3);	
	
	canvas->Update();
	
	gPad->SetBottomMargin(0.12);
 	gStyle->SetOptStat(00000);
	gPad->SetLogy(1);
	
	TLegend *infoBox = new TLegend(0.245, 0.68, 0.9, 0.899,"");//0.75, 0.83, 0.99, 0.99, "");

	infoBox->AddEntry(H_EWKBG_1,"before selection" , "f");
	infoBox->AddEntry((TObject*)0, "", "");
	infoBox->AddEntry(H_EWKBG_2,"angle_photon_met > 0.9" , "l");
	infoBox->AddEntry(H_EWKBG_3,"angle_met_1jet > 0.9" , "l");	
	infoBox->AddEntry(H_EWKBG_4,"met_over_pt < 1.5" , "l");	
	infoBox->AddEntry(H_EWKBG_5,"pt_over_HT > 0.6" , "l");	
	infoBox->AddEntry(H_EWKBG_6,"n_jets < 3" , "l");	
	infoBox->AddEntry(H_EWKBG_7,"sum_signal > 500 GeV" , "l");		
	infoBox->AddEntry(H_EWKBG_8,"pt ratio + met ratio" , "l");	
	infoBox->AddEntry(H_EWKBG_12,"n loose #gamma > 1" , "l");
	infoBox->AddEntry(H_EWKBG_10,"pt_over_sqrt_met > 10" , "l");	
	infoBox->AddEntry(H_EWKBG_11,"pt_over_sqrt_ht> 10" , "l");		
	infoBox->AddEntry(H_signal_540_1,"signal_540" , "l");	
	infoBox->AddEntry(H_signal_640_1,"signal_640" , "l");				 
  infoBox->SetShadowColor(0);  // 0 = transparent
	infoBox->SetNColumns(2);
  infoBox->SetFillColor(kWhite); 
	infoBox->SetTextSize(0.035);
  infoBox->Draw("same");

//////////////////////////////////////////////////
/*Check the influence of good cuts on the signal*/
//////////////////////////////////////////////////
	
/*	canvas2->cd(1);
  H_EWKBG_1->Draw("hist");
	H_EWKBG_4->Draw("hist same");
	H_signal_640_1->Draw("hist same");	
	H_signal_640_4->Draw("hist  same");
	H_signal_640_4->SetLineColor(kBlack);
	H_signal_640_4->SetLineStyle(2);	
	H_signal_640_4->SetLineWidth(3);	
	
	double NMC = H_EWKBG_4->Integral(H_EWKBG_4->FindBin(230),-1);
	double N_signal_640_630 = H_signal_640_4->Integral(H_EWKBG_4->FindBin(230),-1);		
	double significance_640_630 =  N_signal_640_630 / sqrt(N_signal_640_630 + NMC);	
	cout << "significance_640_630 (met_over_pt):  " << significance_640_630 << endl;	
			
 	gStyle->SetOptStat(00000);
	gPad->SetLogy(1);	
//	gPad->SetBottomMargin(0.12);	*/
/////////////////////////////////////
/*Check the influence on the signal*/
/////////////////////////////////////
	
	canvas2->cd(1);
  H_EWKBG_1->Draw("hist");
	H_EWKBG_12->Draw("hist same");
	H_signal_640_1->Draw("hist same");	
	H_signal_640_12->Draw("hist  same");
	H_signal_640_12->SetLineColor(kBlack);
	H_signal_640_12->SetLineStyle(2);	
	H_signal_640_12->SetLineWidth(3);	
			
	double NMC = H_EWKBG_12->Integral(H_EWKBG_12->FindBin(230),-1);
	double N_signal_640_630 = H_signal_640_12->Integral(H_EWKBG_12->FindBin(230),-1);
	cout << "find bin:   " << 	H_EWKBG_12->FindBin(230)	<< endl;
	double significance_640_630 =  N_signal_640_630 / sqrt(N_signal_640_630 + NMC);	
	cout << "significance_640_630 (trans mass):  " << significance_640_630 << endl;				
	TLegend *infoBox3 = new TLegend(0.4, 0.68, 0.9, 0.899,"");//0.75, 0.83, 0.99, 0.99, "");

	infoBox3->AddEntry(H_EWKBG_1,"before selection" , "f");	
	infoBox3->AddEntry(H_EWKBG_12,"n loose #gamma > 1" , "l");	
	infoBox3->AddEntry(H_signal_640_1,"signal_640 before" , "l");	
	infoBox3->AddEntry(H_signal_640_12,"signal_640 after" , "l");					 
  infoBox3->SetShadowColor(0);  // 0 = transparent
  infoBox3->SetFillColor(kWhite); 
	infoBox3->SetTextSize(0.035);
  infoBox3->Draw("same");			
 	gStyle->SetOptStat(00000);
	gPad->SetLogy(1);	
//	gPad->SetBottomMargin(0.12);	
/////////////////////////////////////
/*Check the influence on the signal*/
/////////////////////////////////////
	
	canvas2->cd(2);
  H_EWKBG_1->Draw("hist");
	H_EWKBG_10->Draw("hist same");
	H_signal_640_1->Draw("hist same");	
	H_signal_640_10->Draw("hist  same");
	H_signal_640_10->SetLineColor(kBlack);	
	H_signal_640_10->SetLineStyle(2);	
	H_signal_640_10->SetLineWidth(3);	
			
	double NMC = H_EWKBG_10->Integral(22,-1);
	double N_signal_640_630 = H_signal_640_10->Integral(22,-1);		
	double significance_640_630 =  N_signal_640_630 / sqrt(N_signal_640_630 + NMC);	
	cout << "significance_640_630 (pt_over_sqrt_met):  " << significance_640_630 << endl;	
	cout << "Bin 22 low edge:  " << 		H_signal_640_10->GetBinLowEdge(22) << endl;
			
	TLegend *infoBox4 = new TLegend(0.4, 0.68, 0.9, 0.899,"");//0.75, 0.83, 0.99, 0.99, "");

	infoBox4->AddEntry(H_EWKBG_1,"before selection" , "f");
	infoBox4->AddEntry(H_EWKBG_10,"sum_signal_over_sqrt_met > 32" , "l");	
	infoBox4->AddEntry(H_signal_640_1,"signal_640 before" , "l");
	infoBox4->AddEntry(H_signal_640_10,"signal_640 after" , "l");				 
  infoBox4->SetShadowColor(0);  // 0 = transparent
  infoBox4->SetFillColor(kWhite); 
	infoBox4->SetTextSize(0.035);
  infoBox4->Draw("same");			
 	gStyle->SetOptStat(00000);
	gPad->SetLogy(1);	
//	gPad->SetBottomMargin(0.12);	
	
/////////////////////////////////////
/*Check the influence on the signal*/
/////////////////////////////////////
/*	
	canvas2->cd(4);
  H_EWKBG_1->Draw("hist");
	H_EWKBG_11->Draw("hist same");
	H_signal_640_1->Draw("hist same");	
	H_signal_640_11->Draw("hist  same");
	H_signal_640_11->SetLineColor(kBlack);	
	H_signal_640_11->SetLineStyle(2);	
	H_signal_640_11->SetLineWidth(3);	
			
	double NMC = H_EWKBG_11->Integral(H_EWKBG_11->FindBin(230),-1);
	double N_signal_640_630 = H_signal_640_11->Integral(H_EWKBG_11->FindBin(230),-1);
	double N_signal_540_530 = H_signal_540_11->Integral(H_EWKBG_11->FindBin(230),-1);
	double N_signal_740_730 = H_signal_740_11->Integral(H_EWKBG_11->FindBin(230),-1);			
	double significance_640_630 =  N_signal_640_630 / sqrt(N_signal_640_630 + NMC);	
	double significance_540_530 =  N_signal_540_530 / sqrt(N_signal_540_530 + NMC);
	double significance_740_730 =  N_signal_740_730 / sqrt(N_signal_740_730 + NMC);			
	cout << "significance_640_630 (pt_over_sqrt_ht):  " << significance_640_630 << endl;
	cout << "significance_540_530 (pt_over_sqrt_ht):  " << significance_540_530 << endl;
	cout << "significance_740_730 (pt_over_sqrt_ht):  " << significance_740_730 << endl;						
	double MC_error = 0;
	for (int i = H_EWKBG_11->FindBin(230); i < (H_EWKBG_11->FindBin(600)+1); i++){
		MC_error = MC_error + H_EWKBG_11->GetBinError(i);
		}	
	MC_error = sqrt(MC_error*MC_error + (0.17*NMC*0.17*NMC));
	double s_640_630 =  N_signal_640_630 / sqrt(MC_error*MC_error + NMC);			
	cout << "s_640_630 (pt_over_sqrt_ht):  " << s_640_630 << endl;	
	double s_b_640_630 =  N_signal_640_630 / sqrt(NMC);	
	double s_b_740_730 =  N_signal_740_730 / sqrt(NMC);	
	double s_b_540_530 =  N_signal_540_530 / sqrt(NMC);			
	cout << "s_b_540_530 (pt_over_sqrt_ht):  " << s_b_540_530 << endl;	
	cout << "s_b_640_630 (pt_over_sqrt_ht):  " << s_b_640_630 << endl;
	cout << "s_b_740_730 (pt_over_sqrt_ht):  " << s_b_740_730 << endl;		
	double Z_A_640_630 = sqrt(2*( (N_signal_640_630 + NMC)*log(1+(N_signal_640_630/NMC)) - N_signal_640_630) );
	cout << "Z_A_640_630 (pt_over_sqrt_ht):  " << Z_A_640_630 << endl;				
 	gStyle->SetOptStat(00000);
	gPad->SetLogy(1);	
//	gPad->SetBottomMargin(0.12);	

*/
	canvas2->Update();
		
////////////////////	
/*Now inverse MET */	
////////////////////		
//////////////////////////////////////////
/* Get all histos, right scale, add BGs */
//////////////////////////////////////////
		
	TH1F *	H_met_Data_1  	 	= (TH1F*)Data->Get("h_stage1_inverse_met");	
	TH1F *	H_met_GJets_1    = (TH1F*)GJets->Get("h_stage1_inverse_met");
//	TH1F *	H_met_G2    	= (TH1F*)G_file->Get(histo.c_str());	
	TH1F *	H_met_QCD_1    		= (TH1F*)QCD->Get("h_stage1_inverse_met");		
  TH1F *	H_met_EWKBG_1	 		= (TH1F*)EWKBG->Get("h_stage1_inverse_met");
	TH1F *	H_met_GammaPixel_1= (TH1F*)GammaPixel->Get("h_stage1_inverse_met");	
	TH1F *	H_met_ttbar_1 		= (TH1F*)ttbar->Get("h_stage1_inverse_met");
	TH1F *	H_met_Diboson_1 	= (TH1F*)Diboson->Get("h_stage1_inverse_met");	
	TH1F *	H_met_signal_540_1= (TH1F*)signal_540->Get("h_stage1_inverse_met");
	TH1F *	H_met_signal_640_1= (TH1F*)signal_640->Get("h_stage1_inverse_met");		
	
	H_met_GammaPixel_1->Scale(e_fakerate);
	H_met_EWKBG_1->Scale(scale_EWK);
	H_met_GJets_1->Scale(scale_GJets);

  H_met_EWKBG_1->Add(H_met_GJets_1);
  H_met_EWKBG_1->Add(H_met_QCD_1);	
  H_met_EWKBG_1->Add(H_met_ttbar_1);	
  H_met_EWKBG_1->Add(H_met_Diboson_1);
	
  H_met_EWKBG_1->Scale(trigger_effi);
	
  H_met_EWKBG_1->Add(H_met_GammaPixel_1);
	
  H_met_signal_540_1->Scale(trigger_effi);
	H_met_signal_640_1->Scale(scale_640*trigger_effi);	
	
/////////////////	
	/*Next stage */
/////////////////	
	
	TH1F *	H_met_Data_2  	 	= (TH1F*)Data->Get("h_stage2_inverse_met");	
	TH1F *	H_met_GJets_2    = (TH1F*)GJets->Get("h_stage2_inverse_met");
//	TH1F *	H_met_G2    	= (TH1F*)G_file->Get(histo.c_str());	
	TH1F *	H_met_QCD_2    		= (TH1F*)QCD->Get("h_stage2_inverse_met");		
  TH1F *	H_met_EWKBG_2	 		= (TH1F*)EWKBG->Get("h_stage2_inverse_met");
	TH1F *	H_met_GammaPixel_2= (TH1F*)GammaPixel->Get("h_stage2_inverse_met");	
	TH1F *	H_met_ttbar_2 		= (TH1F*)ttbar->Get("h_stage2_inverse_met");
	TH1F *	H_met_Diboson_2 	= (TH1F*)Diboson->Get("h_stage2_inverse_met");	
	TH1F *	H_met_signal_540_2= (TH1F*)signal_540->Get("h_stage2_inverse_met");
	TH1F *	H_met_signal_640_2= (TH1F*)signal_640->Get("h_stage2_inverse_met");		
	
	H_met_GammaPixel_2->Scale(e_fakerate);
	H_met_EWKBG_2->Scale(scale_EWK);
	H_met_GJets_2->Scale(scale_GJets);

  H_met_EWKBG_2->Add(H_met_GJets_2);
  H_met_EWKBG_2->Add(H_met_QCD_2);	
  H_met_EWKBG_2->Add(H_met_ttbar_2);	
  H_met_EWKBG_2->Add(H_met_Diboson_2);
	
  H_met_EWKBG_2->Scale(trigger_effi);
	
  H_met_EWKBG_2->Add(H_met_GammaPixel_2);
	
  H_met_signal_540_2->Scale(trigger_effi);
	H_met_signal_640_2->Scale(scale_640*trigger_effi);	
	
/////////////////	
	/*Next stage */
/////////////////	
		
	TH1F *	H_met_Data_3  	 	= (TH1F*)Data->Get("h_stage3_inverse_met");	
	TH1F *	H_met_GJets_3    = (TH1F*)GJets->Get("h_stage3_inverse_met");
//	TH1F *	H_met_G2    	= (TH1F*)G_file->Get(histo.c_str());	
	TH1F *	H_met_QCD_3    		= (TH1F*)QCD->Get("h_stage3_inverse_met");		
  TH1F *	H_met_EWKBG_3	 		= (TH1F*)EWKBG->Get("h_stage3_inverse_met");
	TH1F *	H_met_GammaPixel_3= (TH1F*)GammaPixel->Get("h_stage3_inverse_met");	
	TH1F *	H_met_ttbar_3 		= (TH1F*)ttbar->Get("h_stage3_inverse_met");
	TH1F *	H_met_Diboson_3 	= (TH1F*)Diboson->Get("h_stage3_inverse_met");	
	TH1F *	H_met_signal_540_3= (TH1F*)signal_540->Get("h_stage3_inverse_met");
	TH1F *	H_met_signal_640_3= (TH1F*)signal_640->Get("h_stage3_inverse_met");		
	
	H_met_GammaPixel_3->Scale(e_fakerate);
	H_met_EWKBG_3->Scale(scale_EWK);
	H_met_GJets_3->Scale(scale_GJets);

  H_met_EWKBG_3->Add(H_met_GJets_3);
  H_met_EWKBG_3->Add(H_met_QCD_3);	
  H_met_EWKBG_3->Add(H_met_ttbar_3);	
  H_met_EWKBG_3->Add(H_met_Diboson_3);
	
  H_met_EWKBG_3->Scale(trigger_effi);
	
  H_met_EWKBG_3->Add(H_met_GammaPixel_3);
	
  H_met_signal_540_3->Scale(trigger_effi);
	H_met_signal_640_3->Scale(trigger_effi);	
	
/////////////////	
	/*Next stage */
/////////////////	
		
	TH1F *	H_met_Data_4  	 	= (TH1F*)Data->Get("h_stage4_inverse_met");	
	TH1F *	H_met_GJets_4    = (TH1F*)GJets->Get("h_stage4_inverse_met");
//	TH1F *	H_met_G2    	= (TH1F*)G_file->Get(histo.c_str());	
	TH1F *	H_met_QCD_4    		= (TH1F*)QCD->Get("h_stage4_inverse_met");		
  TH1F *	H_met_EWKBG_4	 		= (TH1F*)EWKBG->Get("h_stage4_inverse_met");
	TH1F *	H_met_GammaPixel_4= (TH1F*)GammaPixel->Get("h_stage4_inverse_met");	
	TH1F *	H_met_ttbar_4 		= (TH1F*)ttbar->Get("h_stage4_inverse_met");
	TH1F *	H_met_Diboson_4 	= (TH1F*)Diboson->Get("h_stage4_inverse_met");	
	TH1F *	H_met_signal_540_4= (TH1F*)signal_540->Get("h_stage4_inverse_met");
	TH1F *	H_met_signal_640_4= (TH1F*)signal_640->Get("h_stage4_inverse_met");		
	
	H_met_GammaPixel_4->Scale(e_fakerate);
	H_met_EWKBG_4->Scale(scale_EWK);
	H_met_GJets_4->Scale(scale_GJets);

  H_met_EWKBG_4->Add(H_met_GJets_4);
  H_met_EWKBG_4->Add(H_met_QCD_4);	
  H_met_EWKBG_4->Add(H_met_ttbar_4);	
  H_met_EWKBG_4->Add(H_met_Diboson_4);
	
  H_met_EWKBG_4->Scale(trigger_effi);
	
  H_met_EWKBG_4->Add(H_met_GammaPixel_4);
	
  H_met_signal_540_4->Scale(trigger_effi);
	H_met_signal_640_4->Scale(scale_640*trigger_effi);	
	
/////////////////	
	/*Next stage */
/////////////////	
		
	
	TH1F *	H_met_Data_5  	 	= (TH1F*)Data->Get("h_stage5_inverse_met");	
	TH1F *	H_met_GJets_5    = (TH1F*)GJets->Get("h_stage5_inverse_met");
//	TH1F *	H_met_G2    	= (TH1F*)G_file->Get(histo.c_str());	
	TH1F *	H_met_QCD_5    		= (TH1F*)QCD->Get("h_stage5_inverse_met");		
  TH1F *	H_met_EWKBG_5	 		= (TH1F*)EWKBG->Get("h_stage5_inverse_met");
	TH1F *	H_met_GammaPixel_5= (TH1F*)GammaPixel->Get("h_stage5_inverse_met");	
	TH1F *	H_met_ttbar_5 		= (TH1F*)ttbar->Get("h_stage5_inverse_met");
	TH1F *	H_met_Diboson_5 	= (TH1F*)Diboson->Get("h_stage5_inverse_met");	
	TH1F *	H_met_signal_540_5= (TH1F*)signal_540->Get("h_stage5_inverse_met");
	TH1F *	H_met_signal_640_5= (TH1F*)signal_640->Get("h_stage5_inverse_met");		
	
	H_met_GammaPixel_5->Scale(e_fakerate);
	H_met_EWKBG_5->Scale(scale_EWK);
	H_met_GJets_5->Scale(scale_GJets);

  H_met_EWKBG_5->Add(H_met_GJets_5);
  H_met_EWKBG_5->Add(H_met_QCD_5);	
  H_met_EWKBG_5->Add(H_met_ttbar_5);	
  H_met_EWKBG_5->Add(H_met_Diboson_5);
	
  H_met_EWKBG_5->Scale(trigger_effi);
	
  H_met_EWKBG_5->Add(H_met_GammaPixel_5);
	
  H_met_signal_540_5->Scale(trigger_effi);
	H_met_signal_640_5->Scale(scale_640*trigger_effi);	
	
/////////////////	
	/*Next stage */
/////////////////	
		
	
	TH1F *	H_met_Data_6  	 	= (TH1F*)Data->Get("h_stage6_inverse_met");	
	TH1F *	H_met_GJets_6    = (TH1F*)GJets->Get("h_stage6_inverse_met");
//	TH1F *	H_met_G2    	= (TH1F*)G_file->Get(histo.c_str());	
	TH1F *	H_met_QCD_6    		= (TH1F*)QCD->Get("h_stage6_inverse_met");		
  TH1F *	H_met_EWKBG_6	 		= (TH1F*)EWKBG->Get("h_stage6_inverse_met");
	TH1F *	H_met_GammaPixel_6= (TH1F*)GammaPixel->Get("h_stage6_inverse_met");	
	TH1F *	H_met_ttbar_6 		= (TH1F*)ttbar->Get("h_stage6_inverse_met");
	TH1F *	H_met_Diboson_6 	= (TH1F*)Diboson->Get("h_stage6_inverse_met");	
	TH1F *	H_met_signal_540_6= (TH1F*)signal_540->Get("h_stage6_inverse_met");
	TH1F *	H_met_signal_640_6= (TH1F*)signal_640->Get("h_stage6_inverse_met");		
	
	H_met_GammaPixel_6->Scale(e_fakerate);
	H_met_EWKBG_6->Scale(scale_EWK);
	H_met_GJets_6->Scale(scale_GJets);

  H_met_EWKBG_6->Add(H_met_GJets_6);
  H_met_EWKBG_6->Add(H_met_QCD_6);	
  H_met_EWKBG_6->Add(H_met_ttbar_6);	
  H_met_EWKBG_6->Add(H_met_Diboson_6);
	
  H_met_EWKBG_6->Scale(trigger_effi);
	
  H_met_EWKBG_6->Add(H_met_GammaPixel_6);
	
  H_met_signal_540_6->Scale(trigger_effi);
	H_met_signal_640_6->Scale(scale_640*trigger_effi);	
	
/////////////////	
	/*Next stage */
/////////////////	
		
	
	TH1F *	H_met_Data_7  	 	= (TH1F*)Data->Get("h_stage7_inverse_met");	
	TH1F *	H_met_GJets_7    = (TH1F*)GJets->Get("h_stage7_inverse_met");
//	TH1F *	H_met_G2    	= (TH1F*)G_file->Get(histo.c_str());	
	TH1F *	H_met_QCD_7    		= (TH1F*)QCD->Get("h_stage7_inverse_met");		
  TH1F *	H_met_EWKBG_7	 		= (TH1F*)EWKBG->Get("h_stage7_inverse_met");
	TH1F *	H_met_GammaPixel_7= (TH1F*)GammaPixel->Get("h_stage7_inverse_met");	
	TH1F *	H_met_ttbar_7 		= (TH1F*)ttbar->Get("h_stage7_inverse_met");
	TH1F *	H_met_Diboson_7 	= (TH1F*)Diboson->Get("h_stage7_inverse_met");	
	TH1F *	H_met_signal_540_7= (TH1F*)signal_540->Get("h_stage7_inverse_met");
	TH1F *	H_met_signal_640_7= (TH1F*)signal_640->Get("h_stage7_inverse_met");		
	
	H_met_GammaPixel_7->Scale(e_fakerate);
	H_met_EWKBG_7->Scale(scale_EWK);
	H_met_GJets_7->Scale(scale_GJets);

  H_met_EWKBG_7->Add(H_met_GJets_7);
  H_met_EWKBG_7->Add(H_met_QCD_7);	
  H_met_EWKBG_7->Add(H_met_ttbar_7);	
  H_met_EWKBG_7->Add(H_met_Diboson_7);
	
  H_met_EWKBG_7->Scale(trigger_effi);
	
  H_met_EWKBG_7->Add(H_met_GammaPixel_7);
	
  H_met_signal_540_7->Scale(trigger_effi);
	H_met_signal_640_7->Scale(scale_640*trigger_effi);	
	
/////////////////	
	/*Next stage */
/////////////////	
		
	
	TH1F *	H_met_Data_8  	 	= (TH1F*)Data->Get("h_stage8_inverse_met");	
	TH1F *	H_met_GJets_8    = (TH1F*)GJets->Get("h_stage8_inverse_met");
//	TH1F *	H_met_G2    	= (TH1F*)G_file->Get(histo.c_str());	
	TH1F *	H_met_QCD_8    		= (TH1F*)QCD->Get("h_stage8_inverse_met");		
  TH1F *	H_met_EWKBG_8	 		= (TH1F*)EWKBG->Get("h_stage8_inverse_met");
	TH1F *	H_met_GammaPixel_8= (TH1F*)GammaPixel->Get("h_stage8_inverse_met");	
	TH1F *	H_met_ttbar_8 		= (TH1F*)ttbar->Get("h_stage8_inverse_met");
	TH1F *	H_met_Diboson_8 	= (TH1F*)Diboson->Get("h_stage8_inverse_met");	
	TH1F *	H_met_signal_540_8= (TH1F*)signal_540->Get("h_stage8_inverse_met");
	TH1F *	H_met_signal_640_8= (TH1F*)signal_640->Get("h_stage8_inverse_met");		
	
	H_met_GammaPixel_8->Scale(e_fakerate);
	H_met_EWKBG_8->Scale(scale_EWK);
	H_met_GJets_8->Scale(scale_GJets);

  H_met_EWKBG_8->Add(H_met_GJets_8);
  H_met_EWKBG_8->Add(H_met_QCD_8);	
  H_met_EWKBG_8->Add(H_met_ttbar_8);	
  H_met_EWKBG_8->Add(H_met_Diboson_8);
	
  H_met_EWKBG_8->Scale(trigger_effi);
	
  H_met_EWKBG_8->Add(H_met_GammaPixel_8);
	
  H_met_signal_540_8->Scale(trigger_effi);
	H_met_signal_640_8->Scale(scale_640*trigger_effi);	
	
/////////////////	
	/*Next stage */
/////////////////	
		
	
	TH1F *	H_met_Data_9  	 	= (TH1F*)Data->Get("h_stage9_inverse_met");	
	TH1F *	H_met_GJets_9    = (TH1F*)GJets->Get("h_stage9_inverse_met");
//	TH1F *	H_met_G2    	= (TH1F*)G_file->Get(histo.c_str());	
	TH1F *	H_met_QCD_9    		= (TH1F*)QCD->Get("h_stage9_inverse_met");		
  TH1F *	H_met_EWKBG_9	 		= (TH1F*)EWKBG->Get("h_stage9_inverse_met");
	TH1F *	H_met_GammaPixel_9= (TH1F*)GammaPixel->Get("h_stage9_inverse_met");	
	TH1F *	H_met_ttbar_9 		= (TH1F*)ttbar->Get("h_stage9_inverse_met");
	TH1F *	H_met_Diboson_9 	= (TH1F*)Diboson->Get("h_stage9_inverse_met");	
	TH1F *	H_met_signal_540_9= (TH1F*)signal_540->Get("h_stage9_inverse_met");
	TH1F *	H_met_signal_640_9= (TH1F*)signal_640->Get("h_stage9_inverse_met");		
	
	H_met_GammaPixel_9->Scale(e_fakerate);
	H_met_EWKBG_9->Scale(scale_EWK);
	H_met_GJets_9->Scale(scale_GJets);

  H_met_EWKBG_9->Add(H_met_GJets_9);
  H_met_EWKBG_9->Add(H_met_QCD_9);	
  H_met_EWKBG_9->Add(H_met_ttbar_9);	
  H_met_EWKBG_9->Add(H_met_Diboson_9);
	
  H_met_EWKBG_9->Scale(trigger_effi);
	
  H_met_EWKBG_9->Add(H_met_GammaPixel_9);
	
  H_met_signal_540_9->Scale(trigger_effi);
	H_met_signal_640_9->Scale(scale_640*trigger_effi);	
		
/////////////////	
	/*Next stage */
/////////////////			
		
	
	
//////////////////////
/*Plot all together */
//////////////////////
			
	TCanvas *canvas_met = new TCanvas("canvas_met","Plots",1000,700);
  canvas_met->Divide(1,1);
	TCanvas *canvas2_met = new TCanvas("canvas2_met","Plots",1000,700);
  canvas2_met->Divide(2,2);	
	
	canvas_met->cd(1);
	
	H_met_EWKBG_1->GetYaxis()->SetTitleSize(0.06);
  H_met_EWKBG_1->GetXaxis()->SetTitleSize(0.06);		
	H_met_EWKBG_1->GetYaxis()->SetLabelSize(0.06);
	H_met_EWKBG_1->GetXaxis()->SetLabelSize(0.06);
	H_met_EWKBG_1->GetXaxis()->SetTitleOffset(0.85);
	H_met_EWKBG_1->GetYaxis()->SetTitleOffset(0.5);
  H_met_EWKBG_1->SetTitle("");
  H_met_EWKBG_1->GetXaxis()->SetRangeUser(0,0.02);
  H_met_EWKBG_1->GetXaxis()->SetNdivisions(5);	
  H_met_EWKBG_1->SetLineColor(kRed);
	H_met_EWKBG_1->SetFillStyle(3003);	
  H_met_EWKBG_1->SetFillColor(kRed);	
  H_met_EWKBG_1->Draw("hist");	
		
	H_met_EWKBG_2->Draw("hist same");
	H_met_EWKBG_2->SetLineColor(kAzure+7);
	H_met_EWKBG_2->SetLineWidth(4);		
	
	H_met_EWKBG_3->Draw("hist  same");
	H_met_EWKBG_3->SetLineColor(kCyan);
	H_met_EWKBG_3->SetLineWidth(4);		
	
	H_met_EWKBG_4->Draw("hist  same");
	H_met_EWKBG_4->SetLineColor(kGreen+2);
	H_met_EWKBG_4->SetLineWidth(4);		
	
	H_met_EWKBG_5->Draw("hist  same");
	H_met_EWKBG_5->SetLineColor(kBlue+2);
	H_met_EWKBG_5->SetLineWidth(4);		
	
	H_met_EWKBG_6->Draw("hist  same");
	H_met_EWKBG_6->SetLineColor(kRed+2);	
	H_met_EWKBG_6->SetLineWidth(4);		
		
	H_met_EWKBG_7->Draw("hist  same");
	H_met_EWKBG_7->SetLineColor(kOrange+8);
	H_met_EWKBG_7->SetLineWidth(4);		
	
	H_met_EWKBG_8->Draw("hist  same");
	H_met_EWKBG_8->SetLineColor(kYellow);
	H_met_EWKBG_8->SetLineWidth(4);		
	
	H_met_EWKBG_9->Draw("hist  same");
	H_met_EWKBG_9->SetLineColor(kMagenta+2);
	H_met_EWKBG_9->SetLineWidth(4);	
			
	
	H_met_signal_540_1->Draw("hist  same");
	H_met_signal_540_1->SetLineColor(kBlack);
	H_met_signal_540_1->SetLineWidth(3);		
	H_met_signal_640_1->Draw("hist  same");
	H_met_signal_640_1->SetLineColor(kGray+3);
	H_met_signal_640_1->SetLineWidth(3);	
	
	canvas_met->Update();
	
	gPad->SetBottomMargin(0.12);	
 	gStyle->SetOptStat(00000);
	gPad->SetLogy(1);
	
	TLegend *infoBox_met = new TLegend(0.55, 0.4, 0.9, 0.899,"");//0.75, 0.83, 0.99, 0.99, "");
	infoBox_met->AddEntry(H_EWKBG_1,"before selection" , "f");
	infoBox_met->AddEntry(H_EWKBG_2,"angle_photon_met > 0.9" , "l");
	infoBox_met->AddEntry(H_EWKBG_3,"angle_met_1jet > 0.9" , "l");	
	infoBox_met->AddEntry(H_EWKBG_4,"met_over_pt < 1.5" , "l");	
	infoBox_met->AddEntry(H_EWKBG_5,"pt_over_HT > 0.6" , "l");	
	infoBox_met->AddEntry(H_EWKBG_6,"n_jets < 3" , "l");	
	infoBox_met->AddEntry(H_EWKBG_7,"sum_signal > 500 GeV" , "l");		
	infoBox_met->AddEntry(H_EWKBG_8,"met_significance > 150" , "l");	
	infoBox_met->AddEntry(H_EWKBG_12,"n loose #gamma > 1" , "l");		
	infoBox_met->AddEntry(H_signal_540_1,"signal_540" , "l");	
	infoBox_met->AddEntry(H_signal_640_1,"signal_640" , "l");		 
  infoBox_met->SetShadowColor(0);  // 0 = transparent
//	infoBox_met->SetNColumns(2);
  infoBox_met->SetFillColor(kWhite); 
	infoBox_met->SetTextSize(0.035);
  infoBox_met->Draw("same");

//////////////////////////////////////////////////
/*Check the influence of good cuts on the signal*/
//////////////////////////////////////////////////
	
	canvas2_met->cd(1);
  H_met_EWKBG_1->Draw("hist");
	H_met_EWKBG_4->Draw("hist same");
	H_met_signal_640_1->Draw("hist same");	
	H_met_signal_640_4->Draw("hist  same");
	H_met_signal_640_4->SetLineColor(kBlack);
	H_met_signal_640_4->SetLineStyle(2);	
	H_met_signal_640_4->SetLineWidth(3);	
			
 	gStyle->SetOptStat(00000);
	gPad->SetLogy(1);	
//	gPad->SetBottomMargin(0.11);		
/////////////////////////////////////
/*Check the influence on the signal*/
/////////////////////////////////////
	
	canvas2_met->cd(2);
  H_met_EWKBG_1->Draw("hist");
	H_met_EWKBG_5->Draw("hist same");
//	double NMC = H_met_EWKBG_5->Integral(H_met_EWKBG_5->FindBin(245),-1);
//	double N_signal_640_630 = H_met_signal_640_5->Integral(H_met_EWKBG_5->FindBin(245),-1);	
	H_met_signal_640_1->Draw("hist same");	
	H_met_signal_640_5->Draw("hist  same");
	H_met_signal_640_5->SetLineColor(kBlack);
	H_met_signal_640_5->SetLineStyle(2);		
	H_met_signal_640_5->SetLineWidth(3);	
			
 	gStyle->SetOptStat(00000);
	gPad->SetLogy(1);	
//	gPad->SetBottomMargin(0.11);		
/////////////////////////////////////
/*Check the influence on the signal*/
/////////////////////////////////////
	
	canvas2_met->cd(3);
  H_met_EWKBG_1->Draw("hist");
	H_met_EWKBG_6->Draw("hist same");
	H_met_signal_640_1->Draw("hist same");	
	H_met_signal_640_6->Draw("hist  same");
	H_met_signal_640_6->SetLineColor(kBlack);
	H_met_signal_640_6->SetLineStyle(2);		
	H_met_signal_640_6->SetLineWidth(3);	
//	gPad->SetBottomMargin(0.11);				
 	gStyle->SetOptStat(00000);
	gPad->SetLogy(1);	
/////////////////////////////////////
/*Check the influence on the signal*/
/////////////////////////////////////
	
	canvas2_met->cd(4);
  H_met_EWKBG_1->Draw("hist");
	H_met_EWKBG_2->Draw("hist same");
	H_met_signal_640_1->Draw("hist same");	
	H_met_signal_640_2->Draw("hist  same");
	H_met_signal_640_2->SetLineColor(kBlack);
	H_met_signal_640_2->SetLineStyle(2);		
	H_met_signal_640_2->SetLineWidth(3);	
//	gPad->SetBottomMargin(0.11);				
 	gStyle->SetOptStat(00000);
	gPad->SetLogy(1);		
	
	
	canvas2_met->Update();
	 }
