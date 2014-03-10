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

int q_chi2(){

	double trigger_effi = 0.885339;
	double e_fakerate = 0.0148;
	int rebin = 1.;
//	string histo = "h_met_array";
//	string histo = "h_met";
//	string histo = "h_METoverSqHT_scale";
	string histo = "h_HT_array_HT_cut";	
//	string histo = "h_METoverSqHT_scale_HT_cut";	
//	string histo = "h_1tightPhotonPtOverMET_scale_HT_cut";			
//	string histo = "h_HT";	
//	string histo = "h_METoverSqHT";
//	string histo = "h_1tightPhotonPtOverMET_scale";
//	string histo = "h_1tightPhotonPtOverMET_scale_HT";	
//	string histo = "h_AngleMJ1";
//	string histo = "h_DR_test";
//	string histo = "h_Delta_Phi_JMother";
//  string histo = "h_trans_mass_MET_Gamma";
//  string histo = "h_HToverMET";
//  string histo = "h_InvMassJetsRel";
	
  TFile *Data  			= new TFile("PhotonParkedD_V06.1_sel.root");
	TFile *GJets_file	  	= new TFile("GJetsAdd.root");	
  TFile *EWKBG 		= new TFile("EWKBG.root");
	TFile *GammaPixel	= new TFile("GammaPixel.root");	

	
	TH1F *	H_Data  	 = (TH1F*)Data->Get(histo.c_str());	
	TH1F *	H_GJets2    = (TH1F*)GJets_file->Get(histo.c_str());	
  TH1F *	H_EWKBG	 = (TH1F*)EWKBG->Get(histo.c_str());
	TH1F *	H_GammaPixel = (TH1F*)GammaPixel->Get(histo.c_str());	
	
	H_GammaPixel->Scale(e_fakerate);

		
	TH2F *Chi2D = new TH2F("Chi2D", "2D Chi2 tests",26,0.45,3.05,26,0.45,3.05);
			
	TCanvas *canvas = new TCanvas("canvas","Plots",1000,700);
	TCanvas *canvas2 = new TCanvas("canvas2","Plots",1000,700);			

	canvas->Divide(6,10);	
	canvas2->Divide(1,1);
	
	H_EWKBG->Scale(trigger_effi);
	H_GJets2->Scale(trigger_effi);
	
	double data = H_Data->Integral(1,-1);
	double dataFake = H_GammaPixel->Integral(1,-1);	
	double dataEWK = H_EWKBG->Integral(1,-1);	
	double dataGJets = H_GJets2->Integral(1,-1);
	
	
	double scale = (data - dataFake)/(dataEWK+dataGJets);	
		
	Double_t chi2[60], x[60];	
		
	for ( int i = 1; i < 60; i++) { 	
		
	TH1F *H_EWK = (TH1F*)H_EWKBG->Clone("H_EWK");	
	TH1F *H_GJets = (TH1F*)H_GJets2->Clone("H_GJets");	
		
	double scale_EWK = 0.05 + i*0.05;	
	
	H_EWK->Scale(scale_EWK);
	
	double scale_GJets = (scale*(dataEWK + dataGJets) - scale_EWK*dataEWK)/dataGJets;	
	cout << "***" << scale << "***"<< scale_EWK << "***" << scale_GJets << "*******************************************************" <<endl;  
	
	H_GJets->Scale(scale_GJets);	
	

	H_EWK->Add(H_GJets);
	
	gStyle->SetTitleW(0.9);
	gStyle->SetTitleH(0.08);	
	
	H_EWK->Add(H_GammaPixel);
		

	canvas->cd(i);
	
	chi2[i-1] = H_Data->Chi2Test(H_EWK,"UW OF P CHI2/NDF");

	canvas->Update();
	canvas->cd(i);
	H_Data->Draw("E1");
	H_Data->SetMarkerStyle(8);
	H_Data->SetMarkerColor(kBlack);
	H_Data->SetLineColor(kBlack);
	H_Data->GetYaxis()->SetTitleSize(0.1);
  H_Data->GetXaxis()->SetTitleSize(0.1);		
	H_Data->GetYaxis()->SetLabelSize(0.1);
	H_Data->GetXaxis()->SetLabelSize(0.1);
	
	H_EWK->Draw("hist E1 same");
	H_EWK->SetLineColor(kRed);
	H_EWK->SetLineWidth(2);
	
	H_GJets->Draw("same E1 hist");
	H_GJets->SetFillStyle(1001);	
  H_GJets->SetFillColor(kOrange);	
	
	H_GammaPixel->Draw("same hist");
	H_GammaPixel->SetFillStyle(1001);	
	H_GammaPixel->SetFillColor(kGray+2);	
	H_Data->Draw("same E1");	
	gPad->SetLogy(0);
	gPad->RedrawAxis();
	
/*	TLegend *infoBox = new TLegend(0.7, 0.5, 0.9, 0.899,"");//0.75, 0.83, 0.99, 0.99, "");
  infoBox->AddEntry(htemp1,fileLabel1,"lep");	
	for ( int i = 0; i < BGs.size(); i++) {
		int size = BGs.size() - 1;
	  int reverse = size - i;
	  infoBox->AddEntry(BGs[reverse],histoname[BGs[reverse]].c_str() , "f"); 
		}	
		*/
		
	}
	
	canvas2->cd(1);
	for (int j=0; j<59; j++){
	  x[j]= 0.1 + j*0.05;
	  }
	cout << "  -------------------------------------------" << endl;		
	TGraph *chi2_graph = new TGraph(59,x,chi2);
	chi2_graph->GetXaxis()->SetRangeUser(0.0,3.1);
	chi2_graph->GetXaxis()->SetTitle("scale");
	double max = chi2_graph->GetMaximum();
	chi2_graph->GetYaxis()->SetRangeUser(0,max); //(0.5,2.7);
	chi2_graph->GetYaxis()->SetTitle("#chi^{2}/ndf");
	chi2_graph->SetMarkerStyle(21);
	chi2_graph->SetMarkerColor(1);
	chi2_graph->SetMarkerSize(.9);
	chi2_graph->GetYaxis()->SetTitleSize(0.1);
  chi2_graph->GetXaxis()->SetTitleSize(0.1);		
	chi2_graph->GetYaxis()->SetLabelSize(0.1);
	chi2_graph->GetXaxis()->SetLabelSize(0.1);
	chi2_graph->GetXaxis()->SetTitleOffset(0.45);
		
	chi2_graph->SetTitle("#chi^{2} distribution for scale factor");
	//chi2_graph->SetTitleSize(0.1);	
	gStyle->SetOptStat(0);
	chi2_graph->Draw("AP E1");	
//Fit a parable
	cout << "  -------------------------------------------" << endl;
  cout << " Fit" << endl;
	cout << "  -------------------------------------------" << endl;	
	TF1 *parable = new TF1("parable","[0]+[1]*pow(x-[2],2)",1.5,2.5);
	parable->SetParName(0,"offset_y_m");
	parable->SetParName(1,"factor_m");
	parable->SetParName(2,"offset_x_m");
	parable->SetParameter(0,2);
	parable->SetParameter(1,0.5);
	parable->SetParameter(2,1.7);
  chi2_graph->Fit("parable","R");
	double offset_y_m = parable->GetParameter(0);
	double factor_m = parable->GetParameter(1);
	double offset_x_m = parable->GetParameter(2);
	double mean_up_m = parable->GetX(offset_y_m + 1, offset_x_m , 3.2);
	double mean_down_m = parable->GetX(offset_y_m + 1, 0.2 , offset_x_m);

	cout << endl;
	cout << "  ***Fit to scale" << endl;
	cout << endl;
	cout << endl;
	cout << "  RESULTS:" << endl;
	cout << "  -------------------------------------------" << endl;
	cout << "  offset_y = " << offset_y_m << endl;
	cout << "  -------------------------------------------" << endl;
	cout << "  factor = " << factor_m << endl;
	cout << "  -------------------------------------------" << endl;
	cout << "  offset_x = " << offset_x_m << endl;
	cout << "  -------------------------------------------" << endl;
	cout << "  sigma_x_up = " << mean_up_m - offset_x_m << endl;
	cout << "  -------------------------------------------" << endl;
	cout << "  sigma_x_down = " << offset_x_m - mean_down_m << endl;

	cout << endl;
	parable->Draw("SAME"); 
	
/*	TF1 *parable2 = new TF1("parable2","[0]+[1]*pow(x-[2],2)",1.7,3.2);
	parable2->SetParName(0,"offset_y_m");
	parable2->SetParName(1,"factor_m");
	parable2->SetParName(2,"offset_x_m");
	parable2->SetParameter(0,2);
	parable2->SetParameter(1,1);
	parable2->SetParameter(2,1.7);
  chi2_graph->Fit("parable2","R");
	double offset_y_m2 = parable2->GetParameter(0);
	double factor_m2 = parable2->GetParameter(1);
	double offset_x_m2 = parable2->GetParameter(2);
	double mean_up_m2 = parable2->GetX(offset_y_m2 + 1, offset_x_m2 , 3.2);
	double mean_down_m2 = parable2->GetX(offset_y_m2 + 1, 0.2 , offset_x_m2);

	cout << endl;
	cout << "  ***Fit to scale2" << endl;
	cout << endl;
	cout << endl;
	cout << "  RESULTS2:" << endl;
	cout << "  -------------------------------------------" << endl;
	cout << "  offset_y2 = " << offset_y_m2 << endl;
	cout << "  -------------------------------------------" << endl;
	cout << "  facto2r = " << factor_m2 << endl;
	cout << "  -------------------------------------------" << endl;
	cout << "  offset_x2 = " << offset_x_m2 << endl;
	cout << "  -------------------------------------------" << endl;
	cout << "  sigma_x_up2 = " << mean_up_m2 - offset_x_m2 << endl;
	cout << "  -------------------------------------------" << endl;
	cout << "  sigma_x_down2 = " << offset_x_m2 - mean_down_m2 << endl;

	cout << endl;
	parable2->Draw("SAME");	*/
	
	double result = (scale*(dataEWK + dataGJets) - offset_x_m*dataEWK)/dataGJets;	
	cout << "----RESULT_GJetScale:  " << result << "   -----" << endl;
	
	cout << "data:  " << data << "    GammaPixel:   " << dataFake << "    EWKBG:   " << dataEWK << "   GJets:   " << dataGJets << endl;
	}
