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

int analysis(){



  TFile *Data  			= new TFile("PhotonParkedD_V06.1_sel.root");
	TFile *GJets40  	= new TFile("GJets_40_100_V06.1_sel.root");	
	TFile *GJets100 	= new TFile("GJets_100_200_V02.1_sel.root");
	TFile *GJets200 	= new TFile("GJets_200_400_V02.1_sel.root");
	TFile *GJets400 	= new TFile("GJets_400_inf_V02.1_sel.root");
	TFile *QCD100 		= new TFile("QCD_100_250_V06.1_sel.root");	
	TFile *QCD250 		= new TFile("QCD_250_500_V02.1_sel.root");
	TFile *QCD500 		= new TFile("QCD_500_1000_V02.1_sel.root");
	TFile *QCD1000 		= new TFile("QCD_1000_inf_V02.1_sel.root");
	TFile *TTJets 		= new TFile("TTJets_V02.1_sel.root");
	TFile *ZGamma 		= new TFile("ZGamma_V02.1_sel.root");
	TFile *WJets 			= new TFile("WJets_V02.1_sel.root");

	

	
  TH1F *H_Data_met;
  TH1F *H_GJets40_met;	
  TH1F *H_GJets100_met;
	TH1F *H_GJets200_met;
	TH1F *H_GJets400_met;
	TH1F *H_QCD100_met;	
	TH1F *H_QCD250_met;
	TH1F *H_QCD500_met;
	TH1F *H_QCD1000_met;
	TH1F *H_TTJets_met;
	TH1F *H_ZGamma_met;
	TH1F *H_WJets_met;
	
	
  TH1F *H_Data_met_cut;
  TH1F *H_GJets40_met_cut;	
  TH1F *H_GJets100_met_cut;
	TH1F *H_GJets200_met_cut;
	TH1F *H_GJets400_met_cut;
	TH1F *H_QCD100_met_cut;	
	TH1F *H_QCD250_met_cut;
	TH1F *H_QCD500_met_cut;
	TH1F *H_QCD1000_met_cut;
	TH1F *H_TTJets_met_cut;
	TH1F *H_ZGamma_met_cut;
	TH1F *H_WJets_met_cut;	
	
	
	
  TH1F *H_Data_ht;
  TH1F *H_GJets40_ht;	
  TH1F *H_GJets100_ht;
	TH1F *H_GJets200_ht;
	TH1F *H_GJets400_ht;
	TH1F *H_QCD100_ht;	
	TH1F *H_QCD250_ht;
	TH1F *H_QCD500_ht;
	TH1F *H_QCD1000_ht;
	TH1F *H_TTJets_ht;
	TH1F *H_ZGamma_ht;
	TH1F *H_WJets_ht;	
	
  TH1F *H_Data_cutflow;
  TH1F *H_GJets40_cutflow;	
  TH1F *H_GJets100_cutflow;
	TH1F *H_GJets200_cutflow;
	TH1F *H_GJets400_cutflow;
	TH1F *H_QCD100_cutflow;	
	TH1F *H_QCD250_cutflow;
	TH1F *H_QCD500_cutflow;
	TH1F *H_QCD1000_cutflow;
	TH1F *H_TTJets_cutflow;
	TH1F *H_ZGamma_cutflow;
	TH1F *H_WJets_cutflow;	
	
	
	TH1F *H_Data_vertex_vor;
	TH1F *H_GJets100_vertex_vor;
	TH1F *H_GJets200_vertex_vor;
	TH1F *H_GJets400_vertex_vor;
	TH1F *H_QCD250_vertex_vor;
	TH1F *H_QCD500_vertex_vor;
	TH1F *H_QCD1000_vertex_vor;	
	TH1F *H_TTJets_vertex_vor;
	TH1F *H_ZGamma_vertex_vor;	
	TH1F *H_WJets_vertex_vor;	
	
	TH1F *H_Data_vertex_nach;
	TH1F *H_GJets100_vertex_nach;
	TH1F *H_GJets200_vertex_nach;
	TH1F *H_GJets400_vertex_nach;
	TH1F *H_QCD250_vertex_nach;
	TH1F *H_QCD500_vertex_nach;
	TH1F *H_QCD1000_vertex_nach;	
	TH1F *H_TTJets_vertex_nach;
	TH1F *H_ZGamma_vertex_nach;	
	TH1F *H_WJets_vertex_nach;			
	
	TH1F *H_Data_triggereff_metcross_mytrigger;
	TH1F *H_Data_triggereff_metcross_crosstrigger;
	TH1F *H_Data_triggereff_photonptcross_mytrigger_vor;
	TH1F *H_Data_triggereff_photonptcross_crosstrigger_vor;
	
  TH1F	*H_triggereff__mytrigger_instLumi;
  TH1F	*H_triggereff__mytrigger_runNumber;
  TH1F	*H_triggereff__mytrigger_lumiBlock;
  TH1F	*H_triggereff__crosstrigger_instLumi;
  TH1F	*H_triggereff__crosstrigger_runNumber;
  TH1F	*H_triggereff__crosstrigger_lumiBlock;	
	
	H_triggereff__mytrigger_instLumi = (TH1F*)Data->Get("h_triggereff__mytrigger_instLumi");
	H_triggereff__crosstrigger_instLumi = (TH1F*)Data->Get("h_triggereff__crosstrigger_instLumi");
	H_triggereff__mytrigger_runNumber = (TH1F*)Data->Get("h_triggereff__mytrigger_runNumber");
	H_triggereff__crosstrigger_runNumber = (TH1F*)Data->Get("h_triggereff__crosstrigger_runNumber");
	H_triggereff__mytrigger_lumiBlock = (TH1F*)Data->Get("h_triggereff__mytrigger_lumiBlock");
	H_triggereff__crosstrigger_lumiBlock = (TH1F*)Data->Get("h_triggereff__crosstrigger_lumiBlock");	 
	 
	 
	
	H_Data_triggereff_metcross_mytrigger = (TH1F*)Data->Get("h_triggereff_metcross_mytrigger");
	H_Data_triggereff_metcross_crosstrigger = (TH1F*)Data->Get("h_triggereff_metcross_crosstrigger");
//	H_Data_triggereff_photonptcross_mytrigger_vor = (TH1F*)Data->Get("h_triggereff_photonptcross_mytrigger_vor");
//	H_Data_triggereff_photonptcross_crosstrigger_vor =	(TH1F*)Data->Get("h_triggereff_photonptcross_crosstrigger_vor");
	
	H_Data_triggereff_photonptcross_mytrigger_2 = (TH1F*)Data->Get("h_triggereff_photonptcross_mytrigger_2");
	H_Data_triggereff_photonptcross_crosstrigger_2 =	(TH1F*)Data->Get("h_triggereff_photonptcross_crosstrigger_2");	
	
/*	H_Data_triggereff_metcross_mytrigger->Divide(H_Data_triggereff_metcross_crosstrigger);
	H_Data_triggereff_photonptcross_mytrigger->Divide(H_Data_triggereff_photonptcross_crosstrigger);
	H_Data_triggereff_photonptcross_mytrigger_2->Divide(H_Data_triggereff_photonptcross_crosstrigger_2); */
	
/*	TGraphAsymmErrors *Effi = new TGraphAsymmErrors();
  Effi->Divide(H_Data_triggereff_metcross_mytrigger,H_Data_triggereff_metcross_crosstrigger,"cp");
  Effi->SetTitle("Trigger efficiency");
  Effi->SetMarkerColor(4);
  Effi->SetMarkerStyle(21);
  Effi->GetXaxis()->SetTitle("p_{T,#gamma} [GeV]");
  Effi->GetYaxis()->SetTitle("#varepsilon_{trig}");
  
  TGraphAsymmErrors *Effi2 = new TGraphAsymmErrors();
  Effi2->Divide(H_Data_triggereff_photonptcross_mytrigger_2,H_Data_triggereff_photonptcross_crosstrigger_2,"cp");*/
	
	H_triggereff__mytrigger_instLumi->GetXaxis()->SetTitle("inst. Lumi");
	H_triggereff__crosstrigger_instLumi->GetXaxis()->SetTitle("inst. Lumi");	
	
	
	TEfficiency *Teffi = new TEfficiency(*H_Data_triggereff_metcross_mytrigger, *H_Data_triggereff_metcross_crosstrigger);
//	TEfficiency *Teffi2 = new TEfficiency(*H_Data_triggereff_photonptcross_mytrigger_vor, *H_Data_triggereff_photonptcross_crosstrigger_vor);	
	TEfficiency *Teffi3 = new TEfficiency(*H_Data_triggereff_photonptcross_mytrigger_2, *H_Data_triggereff_photonptcross_crosstrigger_2);
	
	TEfficiency *Teffi4 = new TEfficiency(*H_triggereff__mytrigger_instLumi, *H_triggereff__crosstrigger_instLumi);	
	TEfficiency *Teffi5 = new TEfficiency(*H_triggereff__mytrigger_runNumber, *H_triggereff__crosstrigger_runNumber);	
	TEfficiency *Teffi6 = new TEfficiency(*H_triggereff__mytrigger_lumiBlock, *H_triggereff__crosstrigger_lumiBlock);		
	
	Teffi->SetTitle("trigger efficiency");
//	Teffi2->SetTitle("trigger efficiency");
	Teffi3->SetTitle("trigger efficiency");
/*  Teffi->Divide(H_Data_triggereff_metcross_mytrigger,H_Data_triggereff_metcross_crosstrigger,"cp");
  Effi->SetTitle("Trigger efficiency");
  Effi->SetMarkerColor(4);
  Effi->SetMarkerStyle(21);
  Effi->GetXaxis()->SetTitle("p_{T,#gamma} [GeV]");
  Effi->GetYaxis()->SetTitle("#varepsilon_{trig}");
  
  TGraphAsymmErrors *Effi2 = new TGraphAsymmErrors();
  Effi2->Divide(H_Data_triggereff_photonptcross_mytrigger_2,H_Data_triggereff_photonptcross_crosstrigger_2,"cp"); */
	
//  double effi = Effi2->GetMean(2);
//  double error_high = Effi2->GetErrorYhigh(0);
//  double error_low = Effi2->GetErrorYlow(0); 

  // Develop your analysis blindly, i.e. without looking at the data.
  // Leave the next line commented out until you finish designing your
  // analysis, i.e. after deciding on all cuts.


	H_Data_met  	 = (TH1F*)Data->Get("h_met");	
	H_GJets40_met = (TH1F*)GJets40->Get("h_met");	
	H_GJets100_met = (TH1F*)GJets100->Get("h_met");
	H_GJets200_met = (TH1F*)GJets200->Get("h_met");
	H_GJets400_met = (TH1F*)GJets400->Get("h_met");
	H_QCD100_met	 = (TH1F*)QCD100->Get("h_met");
	H_QCD250_met	 = (TH1F*)QCD250->Get("h_met");
	H_QCD500_met	 = (TH1F*)QCD500->Get("h_met");
	H_QCD1000_met	 = (TH1F*)QCD1000->Get("h_met");
	H_TTJets_met	 = (TH1F*)TTJets->Get("h_met");
	H_ZGamma_met	 = (TH1F*)ZGamma->Get("h_met");
	H_WJets_met		 = (TH1F*)WJets->Get("h_met");
	
	H_Data_met_cut 	 = (TH1F*)Data->Get("h_met_cut");	
	H_GJets40_met_cut = (TH1F*)GJets40->Get("h_met_cut");		
	H_GJets100_met_cut = (TH1F*)GJets100->Get("h_met_cut");
	H_GJets200_met_cut = (TH1F*)GJets200->Get("h_met_cut");
	H_GJets400_met_cut = (TH1F*)GJets400->Get("h_met_cut");
	H_QCD100_met_cut	 = (TH1F*)QCD100->Get("h_met_cut");	
	H_QCD250_met_cut	 = (TH1F*)QCD250->Get("h_met_cut");
	H_QCD500_met_cut	 = (TH1F*)QCD500->Get("h_met_cut");
	H_QCD1000_met_cut	 = (TH1F*)QCD1000->Get("h_met_cut");
	H_TTJets_met_cut	 = (TH1F*)TTJets->Get("h_met_cut");
	H_ZGamma_met_cut	 = (TH1F*)ZGamma->Get("h_met_cut");
	H_WJets_met_cut		 = (TH1F*)WJets->Get("h_met_cut");	
	
	
	H_Data_ht  	 = (TH1F*)Data->Get("h_HT");
	H_GJets40_ht = (TH1F*)GJets40->Get("h_HT");
	H_GJets100_ht = (TH1F*)GJets100->Get("h_HT");
	H_GJets200_ht = (TH1F*)GJets200->Get("h_HT");
	H_GJets400_ht = (TH1F*)GJets400->Get("h_HT");
	H_QCD100_ht	 = (TH1F*)QCD100->Get("h_HT");	
	H_QCD250_ht	 = (TH1F*)QCD250->Get("h_HT");
	H_QCD500_ht	 = (TH1F*)QCD500->Get("h_HT");
	H_QCD1000_ht	 = (TH1F*)QCD1000->Get("h_HT");
	H_TTJets_ht	 = (TH1F*)TTJets->Get("h_HT");
	H_ZGamma_ht	 = (TH1F*)ZGamma->Get("h_HT");
	H_WJets_ht		 = (TH1F*)WJets->Get("h_HT");	
	
	
	H_Data_cutflow  	 = (TH1F*)Data->Get("h_cutflow");	
	H_GJets40_cutflow = (TH1F*)GJets40->Get("h_cutflow");		
	H_GJets100_cutflow = (TH1F*)GJets100->Get("h_cutflow");
	H_GJets200_cutflow = (TH1F*)GJets200->Get("h_cutflow");
	H_GJets400_cutflow = (TH1F*)GJets400->Get("h_cutflow");
	H_QCD100_cutflow	 = (TH1F*)QCD100->Get("h_cutflow");	
	H_QCD250_cutflow	 = (TH1F*)QCD250->Get("h_cutflow");
	H_QCD500_cutflow	 = (TH1F*)QCD500->Get("h_cutflow");
	H_QCD1000_cutflow	 = (TH1F*)QCD1000->Get("h_cutflow");
	H_TTJets_cutflow	 = (TH1F*)TTJets->Get("h_cutflow");
	H_ZGamma_cutflow   = (TH1F*)ZGamma->Get("h_cutflow");
	H_WJets_cutflow 	 = (TH1F*)WJets->Get("h_cutflow");	
	
/*	H_Data_  	 = (TH1F*)Data->Get("");	
	H_GJets100_ = (TH1F*)GJets100->Get("");
	H_GJets200_ = (TH1F*)GJets200->Get("");
	H_GJets400_ = (TH1F*)GJets400->Get("");
	H_QCD250_	 = (TH1F*)QCD250->Get("");
	H_QCD500_	 = (TH1F*)QCD500->Get("");
	H_QCD1000_	 = (TH1F*)QCD1000->Get("");
	H_TTJets_	 = (TH1F*)TTJets->Get("");
	H_ZGamma_	 = (TH1F*)ZGamma->Get("");
	H_WJets_		 = (TH1F*)WJets->Get("");	*/
	
	double Ndata = H_Data_met->Integral(); 
	
	double NMC = H_GJets40_met->Integral() +	H_GJets100_met->Integral() + H_GJets200_met->Integral() + H_GJets400_met->Integral() +
	H_QCD100_met->Integral() + H_QCD250_met->Integral() +	H_QCD500_met->Integral() +	 H_QCD1000_met->Integral() +	
	H_TTJets_met->Integral() +	H_ZGamma_met->Integral() +	H_WJets_met->Integral();
	double NQCD = H_QCD100_met->Integral() + H_QCD250_met->Integral() +	H_QCD500_met->Integral() +	 H_QCD1000_met->Integral();
	
	std::cout << "number of data: " << Ndata << "  and number of MC: " << NMC << std::endl;
	
	std::cout << "QCD events: " << NQCD << std::endl;

	
	H_Data_vertex_vor			= (TH1F*)Data->Get("h_reco_vert_n_vor");
	H_GJets100_vertex_vor = (TH1F*)GJets100->Get("h_reco_vert_n_vor");
	H_GJets200_vertex_vor = (TH1F*)GJets200->Get("h_reco_vert_n_vor");
	H_GJets400_vertex_vor = (TH1F*)GJets400->Get("h_reco_vert_n_vor");
	H_QCD250_vertex_vor	  = (TH1F*)QCD250->Get("h_reco_vert_n_vor");
	H_QCD500_vertex_vor 	= (TH1F*)QCD500->Get("h_reco_vert_n_vor");
	H_QCD1000_vertex_vor 	= (TH1F*)QCD1000->Get("h_reco_vert_n_vor");	
	H_TTJets_vertex_vor 	= (TH1F*)TTJets->Get("h_reco_vert_n_vor");
	H_ZGamma_vertex_vor 	= (TH1F*)ZGamma->Get("h_reco_vert_n_vor");	
	H_WJets_vertex_vor 		= (TH1F*)WJets->Get("h_reco_vert_n_vor");
		
	H_Data_vertex_nach		= (TH1F*)Data->Get("h_reco_vert_n_nach");
	H_GJets100_vertex_nach = (TH1F*)GJets100->Get("h_reco_vert_n_nach");
	H_GJets200_vertex_nach = (TH1F*)GJets200->Get("h_reco_vert_n_nach");
	H_GJets400_vertex_nach = (TH1F*)GJets400->Get("h_reco_vert_n_nach");
	H_QCD250_vertex_nach	  = (TH1F*)QCD250->Get("h_reco_vert_n_nach");
	H_QCD500_vertex_nach 	= (TH1F*)QCD500->Get("h_reco_vert_n_nach");
	H_QCD1000_vertex_nach 	= (TH1F*)QCD1000->Get("h_reco_vert_n_nach");	
	H_TTJets_vertex_nach 	= (TH1F*)TTJets->Get("h_reco_vert_n_nach");
	H_ZGamma_vertex_nach 	= (TH1F*)ZGamma->Get("h_reco_vert_n_nach");	
	H_WJets_vertex_nach 		= (TH1F*)WJets->Get("h_reco_vert_n_nach");	
	
	
	H_Data_vertex_nach->Scale(1./H_Data_vertex_nach->Integral());
	H_GJets100_vertex_nach->Scale(1./H_GJets100_vertex_nach->Integral());
	H_GJets200_vertex_nach->Scale(1./H_GJets200_vertex_nach->Integral());
	H_GJets400_vertex_nach->Scale(1./H_GJets400_vertex_nach->Integral());
	H_QCD250_vertex_nach->Scale(1./H_QCD250_vertex_nach->Integral());
	H_QCD500_vertex_nach->Scale(1./H_QCD500_vertex_nach->Integral());
	H_QCD1000_vertex_nach->Scale(1./H_QCD1000_vertex_nach->Integral());	
	H_TTJets_vertex_nach->Scale(1./H_TTJets_vertex_nach->Integral());
	H_ZGamma_vertex_nach->Scale(1./H_ZGamma_vertex_nach->Integral());	
	H_WJets_vertex_nach->Scale(1./H_WJets_vertex_nach->Integral());	
	
	H_Data_vertex_vor->Scale(1./H_Data_vertex_vor->Integral());
	H_GJets100_vertex_vor->Scale(1./H_GJets100_vertex_vor->Integral());
	H_GJets200_vertex_vor->Scale(1./H_GJets200_vertex_vor->Integral());
	H_GJets400_vertex_vor->Scale(1./H_GJets400_vertex_vor->Integral());
	H_QCD250_vertex_vor->Scale(1./H_QCD250_vertex_vor->Integral());
	H_QCD500_vertex_vor->Scale(1./H_QCD500_vertex_vor->Integral());
	H_QCD1000_vertex_vor->Scale(1./H_QCD1000_vertex_vor->Integral());	
	H_TTJets_vertex_vor->Scale(1./H_TTJets_vertex_vor->Integral());
	H_ZGamma_vertex_vor->Scale(1./H_ZGamma_vertex_vor->Integral());	
	H_WJets_vertex_vor->Scale(1./H_WJets_vertex_vor->Integral());	
	
//	H_Data_n_loose_photon_pt	  = (TH1F*)Data->Get("h_loose_photons_pt");	
//	H_GJets100_loose_photon_pt = (TH1F*)GJets100->Get("h_loose_photons_pt");
	
  THStack *hsCUTFLOW  			   = new THStack("hsCUTFLOW","stack/unstack cutflow");	
  THStack *hsMET  			   = new THStack("hsMET","stack/unstack MET");
	THStack *hsMET_cut  			   = new THStack("hsMET_cut","stack/unstack MET");
	THStack *hsVERTEX 			 = new THStack("hsVERTEX", "stack/unstack Vertex");
  THStack *hsHT  			   = new THStack("hsHT","stack/unstack HT");
  THStack *hsHTQCD  			   = new THStack("hsHTQCD","stack/unstack HT");	
  THStack *hsHTGJETS  			   = new THStack("hsHTGJETS","stack/unstack HT");
	
	
	H_Data_cutflow	->SetLineColor(kBlack);
  H_Data_cutflow	->SetMarkerStyle(8);
  H_GJets40_cutflow	->SetFillColor(kMagenta-7);
	H_GJets40_cutflow	->SetFillStyle(1001);		
  H_GJets100_cutflow	->SetFillColor(kMagenta+3);
	H_GJets100_cutflow	->SetFillStyle(1001);	
	H_GJets200_cutflow  ->SetFillColor(kOrange-3);
	H_GJets200_cutflow	->SetFillStyle(1001);	
	H_GJets400_cutflow  ->SetFillColor(kYellow);
	H_GJets400_cutflow	->SetFillStyle(1001);	
	H_QCD100_cutflow  ->SetFillColor(kBlue-2);
	H_QCD100_cutflow	->SetFillStyle(1001);	
	H_QCD250_cutflow  ->SetFillColor(kBlue);
	H_QCD250_cutflow	->SetFillStyle(1001);
	H_QCD500_cutflow  ->SetFillColor(kBlue+2);
	H_QCD500_cutflow	->SetFillStyle(1001);
	H_QCD1000_cutflow  ->SetFillColor(kBlue+4);
	H_QCD1000_cutflow	->SetFillStyle(1001);
	H_TTJets_cutflow  ->SetFillColor(kRed);
	H_TTJets_cutflow	->SetFillStyle(1001);
	H_ZGamma_cutflow  ->SetFillColor(kGreen);
	H_ZGamma_cutflow	->SetFillStyle(1001);
	H_WJets_cutflow  ->SetFillColor(kCyan);
	H_WJets_cutflow	->SetFillStyle(1001);	
	
	
/*	H_Data_	->SetLineColor(kBlack);
  H_Data_	->SetMarkerStyle(8);
  H_GJets100_	->SetFillColor(kMagenta+3);
	H_GJets100_	->SetFillStyle(1001);	
	H_GJets200_  ->SetFillColor(kOrange-3);
	H_GJets200_	->SetFillStyle(1001);	
	H_GJets400_  ->SetFillColor(kYellow);
	H_GJets400_	->SetFillStyle(1001);	
	H_QCD250_  ->SetFillColor(kBlue);
	H_QCD250_	->SetFillStyle(1001);
	H_QCD500_  ->SetFillColor(kBlue);
	H_QCD500_	->SetFillStyle(1001);
	H_QCD1000_  ->SetFillColor(kBlue);
	H_QCD1000_	->SetFillStyle(1001);
	H_TTJets_  ->SetFillColor(kRed);
	H_TTJets_	->SetFillStyle(1001);
	H_ZGamma_  ->SetFillColor(kGreen);
	H_ZGamma_	->SetFillStyle(1001);
	H_WJets_  ->SetFillColor(kCyan);
	H_WJets_	->SetFillStyle(1001);	 */
			
	H_Data_met	->SetLineColor(kBlack);
  H_Data_met	->SetMarkerStyle(8);
  H_GJets40_met	->SetFillColor(kMagenta-7);
	H_GJets40_met	->SetFillStyle(1001);	
  H_GJets100_met	->SetFillColor(kMagenta+3);
	H_GJets100_met	->SetFillStyle(1001);	
	H_GJets200_met  ->SetFillColor(kOrange-3);
	H_GJets200_met	->SetFillStyle(1001);	
	H_GJets400_met  ->SetFillColor(kYellow);
	H_GJets400_met	->SetFillStyle(1001);	
	H_QCD100_met  ->SetFillColor(kBlue-2);
	H_QCD100_met	->SetFillStyle(1001);	
	H_QCD250_met  ->SetFillColor(kBlue);
	H_QCD250_met	->SetFillStyle(1001);
	H_QCD500_met  ->SetFillColor(kBlue+2);
	H_QCD500_met	->SetFillStyle(1001);
	H_QCD1000_met  ->SetFillColor(kBlue+4);
	H_QCD1000_met	->SetFillStyle(1001);
	H_TTJets_met  ->SetFillColor(kRed);
	H_TTJets_met	->SetFillStyle(1001);
	H_ZGamma_met  ->SetFillColor(kGreen);
	H_ZGamma_met	->SetFillStyle(1001);
	H_WJets_met  ->SetFillColor(kCyan);
	H_WJets_met	->SetFillStyle(1001);
	
	
	H_Data_met_cut	->SetLineColor(kBlack);
  H_Data_met_cut	->SetMarkerStyle(8);
  H_GJets40_met_cut	->SetFillColor(kMagenta-7);
	H_GJets40_met_cut	->SetFillStyle(1001);	
  H_GJets100_met_cut	->SetFillColor(kMagenta+3);
	H_GJets100_met_cut	->SetFillStyle(1001);	
	H_GJets200_met_cut  ->SetFillColor(kOrange-3);
	H_GJets200_met_cut	->SetFillStyle(1001);	
	H_GJets400_met_cut  ->SetFillColor(kYellow);
	H_GJets400_met_cut	->SetFillStyle(1001);	
	H_QCD100_met_cut  ->SetFillColor(kBlue-2);
	H_QCD100_met_cut	->SetFillStyle(1001);	
	H_QCD250_met_cut  ->SetFillColor(kBlue);
	H_QCD250_met_cut	->SetFillStyle(1001);
	H_QCD500_met_cut  ->SetFillColor(kBlue+2);
	H_QCD500_met_cut	->SetFillStyle(1001);
	H_QCD1000_met_cut  ->SetFillColor(kBlue+4);
	H_QCD1000_met_cut	->SetFillStyle(1001);
	H_TTJets_met_cut  ->SetFillColor(kRed);
	H_TTJets_met_cut	->SetFillStyle(1001);
	H_ZGamma_met_cut  ->SetFillColor(kGreen);
	H_ZGamma_met_cut	->SetFillStyle(1001);
	H_WJets_met_cut  ->SetFillColor(kCyan);
	H_WJets_met_cut	->SetFillStyle(1001);	
	
	
	
	
	
	
	H_Data_ht	->SetLineColor(kBlack);
  H_Data_ht	->SetMarkerStyle(8);
  H_GJets40_ht	->SetFillColor(kMagenta-7);
	H_GJets40_ht	->SetFillStyle(1001);	
  H_GJets100_ht	->SetFillColor(kMagenta+3);
	H_GJets100_ht	->SetFillStyle(1001);	
	H_GJets200_ht  ->SetFillColor(kOrange-3);
	H_GJets200_ht	->SetFillStyle(1001);	
	H_GJets400_ht  ->SetFillColor(kYellow);
	H_GJets400_ht	->SetFillStyle(1001);	
	H_QCD100_ht  ->SetFillColor(kBlue-2);
	H_QCD100_ht	->SetFillStyle(1001);	
	H_QCD250_ht  ->SetFillColor(kBlue);
	H_QCD250_ht	->SetFillStyle(1001);
	H_QCD500_ht  ->SetFillColor(kBlue+2);
	H_QCD500_ht	->SetFillStyle(1001);
	H_QCD1000_ht  ->SetFillColor(kBlue+4);
	H_QCD1000_ht	->SetFillStyle(1001);
	H_TTJets_ht  ->SetFillColor(kRed);
	H_TTJets_ht	->SetFillStyle(1001);
	H_ZGamma_ht  ->SetFillColor(kGreen);
	H_ZGamma_ht	->SetFillStyle(1001);
	H_WJets_ht  ->SetFillColor(kCyan);
	H_WJets_ht	->SetFillStyle(1001);	
	
		
	
//  H_GJets100_loose_photon_pt	->SetFillColor(kOrange-3);	
	
//	H_GJets100_vertex	->SetFillColor(kBlue);
/*	H_GJets200_vertex	->SetFillColor(kBlue);
	H_GJets400_vertex	->SetFillColor(kBlue);
	H_QCD250_vertex	->SetFillColor(kBlue);
	H_QCD500_vertex	->SetFillColor(kBlue);
	H_QCD1000_vertex	->SetFillColor(kBlue);
	H_TTJets_vertex	->SetFillColor(kBlue);
	H_ZGamma_vertex	->SetFillColor(kBlue);
	H_WJets_vertex	->SetFillColor(kBlue);*/
	

//  hsMET->Add(H_Data_met);

  hsCUTFLOW->Add(H_ZGamma_cutflow);	
  hsCUTFLOW->Add(H_TTJets_cutflow);	
  hsCUTFLOW->Add(H_WJets_cutflow);	
  hsCUTFLOW->Add(H_QCD250_cutflow);	
  hsCUTFLOW->Add(H_QCD500_cutflow);
  hsCUTFLOW->Add(H_QCD1000_cutflow);
	hsCUTFLOW->Add(H_QCD100_cutflow);
  hsCUTFLOW->Add(H_GJets400_cutflow);
  hsCUTFLOW->Add(H_GJets200_cutflow);			
  hsCUTFLOW->Add(H_GJets100_cutflow);
  hsCUTFLOW->Add(H_GJets40_cutflow);	
/*  ->Add(H_ZGamma_);	
  ->Add(H_TTJets_);	
  ->Add(H_WJets_);
  ->Add(H_QCD250_);	
  ->Add(H_QCD500_);
  ->Add(H_QCD1000_);
  ->Add(H_GJets400_);
  ->Add(H_GJets200_);			
  ->Add(H_GJets100_); */
	
  hsMET->Add(H_ZGamma_met);	
  hsMET->Add(H_TTJets_met);	
  hsMET->Add(H_WJets_met);
  	
  hsMET->Add(H_QCD250_met);	
  hsMET->Add(H_QCD500_met);
  hsMET->Add(H_QCD1000_met);
	hsMET->Add(H_QCD100_met);
  hsMET->Add(H_GJets400_met);
  hsMET->Add(H_GJets200_met);			
  hsMET->Add(H_GJets100_met);
  hsMET->Add(H_GJets40_met);
		
  hsMET_cut->Add(H_ZGamma_met_cut);	
  hsMET_cut->Add(H_TTJets_met_cut);	
  hsMET_cut->Add(H_WJets_met_cut);
		
  hsMET_cut->Add(H_QCD250_met_cut);	
  hsMET_cut->Add(H_QCD500_met_cut);
  hsMET_cut->Add(H_QCD1000_met_cut);
	hsMET_cut->Add(H_QCD100_met_cut);
  hsMET_cut->Add(H_GJets400_met_cut);
  hsMET_cut->Add(H_GJets200_met_cut);			
  hsMET_cut->Add(H_GJets100_met_cut);	
  hsMET_cut->Add(H_GJets40_met_cut);	
	
  hsHT->Add(H_ZGamma_ht);	
  hsHT->Add(H_TTJets_ht);	
  hsHT->Add(H_WJets_ht);
	
  hsHT->Add(H_QCD1000_ht);
  hsHT->Add(H_QCD500_ht);	
  hsHT->Add(H_QCD250_ht);
	hsHT->Add(H_QCD100_ht);		
  hsHT->Add(H_GJets400_ht);
  hsHT->Add(H_GJets200_ht);			
  hsHT->Add(H_GJets40_ht);
	hsHT->Add(H_GJets100_ht);

		
  hsHTGJETS->Add(H_GJets400_ht);
  hsHTGJETS->Add(H_GJets200_ht);			
  hsHTGJETS->Add(H_GJets100_ht);
  hsHTGJETS->Add(H_GJets40_ht);	
		
  hsHTQCD->Add(H_QCD1000_ht);			
  hsHTQCD->Add(H_QCD500_ht);
  hsHTQCD->Add(H_QCD250_ht);		
	hsHTQCD->Add(H_QCD100_ht);
		
	
 // hsLOOOSEPHOTONPT->Add(H_Data_n_loose_photon_pt);
//  hsLOOOSEPHOTONPT->Add(H_GJets100_loose_photon_pt, "nostack");	
//	hs2->Add(H_Data_vertex);
//	hs2->Add(H_ZGammaNuNu_vertex);

  TCanvas *canvas = new TCanvas("canvas","Plots",600,600);
  canvas->Divide(2,1);
  canvas->cd(1);
        //canvas->GetPad(1)->SetLogy(1);
        //canvas->GetPad(1)->Range(0,0.1,3.2,70);

  // H_Data_met->Draw("E1");
	 hsMET->Draw(" h f");  // F\ufffdr stack option besser den kleineren BG zuerst adden 
	 
   H_Data_met->Draw("same E1");
	 canvas->SetLogy(1);
	 	 hsMET->SetMinimum(0.1);
	 H_Data_met->SetMinimum(0.1);
	canvas->GetPad(1)->SetLogy(1);	
	 
	leg1 = new TLegend(0.65,0.65,0.9,0.9);
	leg1->AddEntry(H_Data_met,"Data","lep");
	leg1->AddEntry(H_GJets40_met,"GJets40-100","f");	
	leg1->AddEntry(H_GJets100_met,"GJets100-200","f");
	leg1->AddEntry(H_GJets200_met,"GJets200-400","f");
	leg1->AddEntry(H_GJets400_met,"GJets400-inf","f");
	leg1->AddEntry(H_QCD100_met,"QCD100","f");	
	leg1->AddEntry(H_QCD250_met,"QCD250","f");
	leg1->AddEntry(H_QCD500_met,"QCD500","f");	
	leg1->AddEntry(H_QCD1000_met,"QCD1000","f");	
	leg1->AddEntry(H_TTJets_met,"TTJets","f");	
	leg1->AddEntry(H_ZGamma_met,"ZGamma","f");	
	leg1->AddEntry(H_WJets_met,"WJets","f");	
//	leg1->SetTextSize(1);
	
	leg1->SetTextSize(0.04);
	leg1->Draw();
	gPad->RedrawAxis();
	canvas->cd(2);
	
 //  H_Data_met_cut->Draw("E1");
	 hsMET_cut->Draw(" h f");  // F\ufffdr stack option besser den kleineren BG zuerst adden 
   hsMET_cut->SetMinimum(1);
	 H_Data_met_cut->Draw("same E1");	
	leg1->Draw();
	canvas->GetPad(2)->SetLogy(1);	 
  H_Data_met->SetXTitle("MET");
  H_Data_met->SetYTitle("# events");
//	H_Data_vertex->SetXTitle("# vertices");
//  H_Data_vertex->SetYTitle("# events");

//  canvas->cd(2);
//  H_GJets100_met->SetFillStyle(3003);
 // H_GJets100_vertex->SetFillStyle(3003);
//  hsMET->Draw("nostack"); // Fuer nostack sollte Kleiner BG spaeter geadded werden
	TCanvas *cutflow = new TCanvas("cutflow","Plots",600,600);
	
	H_Data_cutflow->Draw("E1");
	hsCUTFLOW->Draw("same h f");  // F\ufffdr stack option besser den kleineren BG zuerst adden 
  H_Data_cutflow->Draw("same E1");	
	leg1->Draw();
	H_Data_cutflow->SetMinimum(500);
	cutflow->SetLogy(1);	
	TCanvas *c1 = new TCanvas("c1","Plots",600,600);
	
	c1->Divide(3,1);
	c1->cd(1);
	Teffi4->SetTitle("efficiency;inst. Lumi;efficiency");
	Teffi4->Draw();
	c1->cd(2);
	Teffi5->Draw();
	c1->cd(3);
	Teffi6->Draw();
		
	TCanvas *c2 = new TCanvas("c2","Plots",600,600);
	
	c2->Divide(2,1);
	c2->cd(1);
	H_Data_vertex_vor->SetLineColor(kBlack);  
	H_Data_vertex_vor->SetMarkerStyle(8);
	H_Data_vertex_vor->Draw();
	
	H_GJets100_vertex_vor->SetLineColor(kRed);
	H_GJets200_vertex_vor->SetLineColor(kRed);
	H_GJets400_vertex_vor->SetLineColor(kRed);
	H_QCD250_vertex_vor->SetLineColor(kRed);
	H_QCD500_vertex_vor->SetLineColor(kRed);
	H_QCD1000_vertex_vor->SetLineColor(kRed);
	H_TTJets_vertex_vor->SetLineColor(kRed);
	H_ZGamma_vertex_vor->SetLineColor(kRed);	
	H_WJets_vertex_vor->SetLineColor(kRed);
	
	H_GJets100_vertex_vor->Draw("same");
	H_GJets200_vertex_vor->Draw("same");
	H_GJets400_vertex_vor->Draw("same");
	H_QCD250_vertex_vor->Draw("same");
	H_QCD500_vertex_vor->Draw("same");
	H_QCD1000_vertex_vor->Draw("same");	
	H_TTJets_vertex_vor->Draw("same");
	H_ZGamma_vertex_vor->Draw("same");	
	H_WJets_vertex_vor->Draw("same");	

	
	c2->cd(2);

	
	H_Data_vertex_nach->SetLineColor(kBlack);
	H_Data_vertex_nach->SetMarkerStyle(8);
	H_Data_vertex_nach->Draw();
	
	H_GJets100_vertex_nach->SetLineColor(kRed);
	H_GJets200_vertex_nach->SetLineColor(kRed);
	H_GJets400_vertex_nach->SetLineColor(kRed);
	H_QCD250_vertex_nach->SetLineColor(kRed);
	H_QCD500_vertex_nach->SetLineColor(kRed);
	H_QCD1000_vertex_nach->SetLineColor(kRed);
	H_TTJets_vertex_nach->SetLineColor(kRed);
	H_ZGamma_vertex_nach->SetLineColor(kRed);
	H_WJets_vertex_nach->SetLineColor(kRed);
	
	H_GJets100_vertex_nach->Draw("same");
	H_GJets200_vertex_nach->Draw("same");
	H_GJets400_vertex_nach->Draw("same");
	H_QCD250_vertex_nach->Draw("same");
	H_QCD500_vertex_nach->Draw("same");
	H_QCD1000_vertex_nach->Draw("same");
	H_TTJets_vertex_nach->Draw("same");
	H_ZGamma_vertex_nach->Draw("same");	
	H_WJets_vertex_nach->Draw("same");	
 
	TCanvas *canvas2 = new TCanvas("canvas2","Plots",600,600);
  canvas2->Divide(3,1);
	
  canvas2->cd(1);
//  H_Data_ht->Draw("E1");
  hsHT->Draw(" h f");  // F\ufffdr stack option besser den kleineren BG zuerst adden 
  hsHT->SetMinimum(1);
  H_Data_ht->Draw("same E1");	
	leg1->Draw();	
	canvas2->GetPad(1)->SetLogy(1);
	canvas2->cd(2);
/*	H_QCD250_ht->Draw();
	H_QCD500_ht->Draw("same");
	H_QCD1000_ht->Draw("same");*/
	hsHTGJETS->Draw("h f");
	canvas2->GetPad(2)->SetLogy(1);
	canvas2->cd(3);
/*  H_GJets100_ht	->Draw();	
  H_GJets200_ht	->Draw("same");
  H_GJets400_ht	->Draw("same");*/
	hsHTQCD->Draw(" h f");
	canvas2->GetPad(3)->SetLogy(1);
	
	
	TCanvas *canvas3 = new TCanvas("canvas3","Plots",600,600);
  canvas3->Divide(3,1);
  canvas3->cd(1);
//	H_Data_triggereff_metcross_mytrigger->Draw();
	Teffi->Draw();
	canvas3->cd(2);
//	H_Data_triggereff_photonptcross_mytrigger->Draw();
	Teffi3->Draw();
	canvas3->cd(3);
//	Teffi2->Draw();
	
  return 0;
}
