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


	bool Vg = false;
//	double trigger_effi = 0.885339;
  double trigger_effi = 0.865;
//  double trigger_effi = 0.856;
	double e_fakerate = 0.0148;
	int rebin = 1.;
	

/*MET Significance */

//		string histo = "h_MET_significance_80";
//		string histo = "h_MET_significance_90";
//		string histo = "h_MET_significance_100_39";
//		string histo = "h_MET_significance_100_23";
//		string histo = "h_MET_significance_110";		
//		string histo = "h_MET_significance_120";
		
/*  METoverSqHT */

//    string histo = "h_METoverSqHT_100_30";		
 //   string histo = "h_METoverSqHT_100_36";				
//    string histo = "h_METoverSqHT_100_24";		 
//   string histo = "h_METoverSqHT_100_17";
 //    string histo = "h_METoverSqHT_100_12"; //beste!
 string histo = "h_METoverSqHT_double_control_20";
//		 string histo = "h_METoverSqHT_met_sign_control";
  //   string histo = "h_METoverSqHT_trans_mass_control";
//		 string histo = "h_final_MET_significance_unblind";

/*  HT_array */

//	string histo = "h_HT_array_80";
//	string histo = "h_HT_array_90";
//	string histo = "h_HT_array_pt_cut"; // good cross check
//	string histo = "h_HT_array_110";	
//	string histo = "h_HT_array_100_41";	


	
  TFile *Data  			= new TFile("PhotonParkedD_V06.1_sel.root");
	TFile *GJets_file	  	= new TFile("GJetsAdd.root");	
	TFile *QCD	  	= new TFile("QCDAdd.root");	
	TFile *WG	  	= new TFile("WGammaAdd.root");
//  TFile *WG	  	= new TFile("WGamma_splitAdd.root");
	TFile *ZG	  	= new TFile("ZGammatest/Znew.root");
//	TFile *ZG	  	= new TFile("ZGammaAdd.root");
//  TFile *EWKBG 		= new TFile("EWKBG.root");
	TFile *GammaPixel	= new TFile("GammaPixel.root");		
  TFile *ttbar	= new TFile("TTGamma_V02.1_sel.root");
	TFile *Diboson	= new TFile("Diboson.root");	
	TFile *signal	= new TFile("signal_640_630.root");	
	TFile *signal2	= new TFile("signal_540_530.root");	
		
	TH1F *	H_Data  = (TH1F*)Data->Get(histo.c_str());	
	TH1F *	H_GJets2 = (TH1F*)GJets_file->Get(histo.c_str());
	
	TH1F *	H_WG  	 = (TH1F*)WG->Get(histo.c_str());	
	TH1F *	H_ZG     = (TH1F*)ZG->Get(histo.c_str());
	TH1F *	H_QCD    = (TH1F*)QCD->Get(histo.c_str());		
//  TH1F *	H_EWKBG	 = (TH1F*)EWKBG->Get(histo.c_str());
	TH1F *	H_GammaPixel = (TH1F*)GammaPixel->Get(histo.c_str());	
	TH1F *	H_ttbar = (TH1F*)ttbar->Get(histo.c_str());
	TH1F *	H_Diboson = (TH1F*)Diboson->Get(histo.c_str());	
	TH1F *	H_signal = (TH1F*)signal->Get(histo.c_str());	
	TH1F *	H_signal2 = (TH1F*)signal2->Get(histo.c_str());	
	
	TH1F *	H_GJets2_scale    = (TH1F*)GJets_file->Get("h_met");
	gStyle->SetPaintTextFormat(".2f");	
//	H_WG->Scale(1.424);
//	H_ZG->Scale(1.579);
	
	H_WG->Add(H_ZG);	
	
	TH1F *H_EWKBG = (TH1F*)H_WG->Clone("H_EWKBG");	
			
	H_GammaPixel->Scale(e_fakerate);
  H_signal->Scale(trigger_effi);
		
	TH2F *Chi2D = new TH2F("Chi2D", "2D Chi2 tests",26,0.45,3.05,26,0.45,3.05);
			
	TCanvas *canvas = new TCanvas("canvas","Plots",1000,700);
	TCanvas *canvas2 = new TCanvas("canvas2","Plots",1000,700);			
	TCanvas *canvas3 = new TCanvas("canvas3","Plots",1000,700);	
	//canvas->Divide(6,10);	
	canvas->Divide(2,2);
	canvas2->Divide(1,1);
	canvas3->Divide(1,1);
	
	
		
	H_EWKBG->Scale(trigger_effi);
	H_GJets2->Scale(trigger_effi);

	H_ttbar->Scale(trigger_effi);
	H_Diboson->Scale(trigger_effi);
	H_QCD->Scale(trigger_effi);		
		
	H_GJets2_scale->Scale(trigger_effi);
	
		
	int bin_low = 0;
	
	double dataFake = H_GammaPixel->Integral(bin_low,-1);	
	double dataEWK = H_EWKBG->Integral(bin_low,-1);	
	double dataGJets = H_GJets2->Integral(bin_low,-1);

	double datattbar = H_ttbar->Integral(bin_low,-1);	
	double dataDiboson = H_Diboson->Integral(bin_low,-1);	
	double dataQCD = H_QCD->Integral(bin_low,-1);	
	
	double dataGJets_scale = H_GJets2_scale->Integral(bin_low,-1);
	
	
	H_Data->Add(H_ttbar,-1);
	H_Data->Add(H_Diboson,-1);	
	H_Data->Add(H_QCD,-1);	
	H_Data->Add(H_GammaPixel,-1);	
	
	double data = H_Data->Integral(bin_low,-1);
//	double scale = (data - dataFake - datattbar - dataDiboson - dataQCD)/(dataEWK+dataGJets);
	
	double scale = (data)/(dataEWK+dataGJets);	
		
	Double_t chi2[150], x[150];	
		
	for ( int i = 1; i < 150; i++) { 	
		
	TH1F *H_EWK = (TH1F*)H_EWKBG->Clone("H_EWK");	
	TH1F *H_GJets = (TH1F*)H_GJets2->Clone("H_GJets");	
	
			
	if ( Vg ) {
		double scale_EWK = 0.04 + i*0.02;		
		H_EWK->Scale(scale_EWK);
		double scale_GJets = (scale*(dataEWK + dataGJets) - scale_EWK*dataEWK)/dataGJets;

		H_GJets->Scale(scale_GJets);
							
		}
	else {
		double scale_GJets = 0.04 + i*0.02;
		double scale_G = 0.04 + i*0.02;		
		H_GJets->Scale(scale_GJets);
		
		double scale_EWK = (scale*(dataEWK + dataGJets) - scale_GJets*dataGJets)/dataEWK;
	
		H_EWK->Scale(scale_EWK);
		}	
		
		
/*	double scale_EWK = 0.05 + i*0.05;	
//	double scale_GJets = 0.05 + i*0.05;
	H_EWK->Scale(scale_EWK);
//	H_GJets->Scale(scale_GJets);	
	
	double scale_GJets = (scale*(dataEWK + dataGJets) - scale_EWK*dataEWK)/dataGJets;	
//	double scale_EWK = (scale*(dataEWK + dataGJets) - scale_GJets*dataGJets)/dataEWK;	
	cout << "***" << scale << "***"<< scale_EWK << "***" << scale_GJets << "*******************************************************" <<endl;  
	
	H_GJets->Scale(scale_GJets);	
//	H_EWK->Scale(scale_EWK); */

//	H_EWK->Add(H_G);	
	
	gStyle->SetTitleW(0.9);
	gStyle->SetTitleH(0.08);	
	
	TH1F *EWK_BG = (TH1F*)H_EWK->Clone("EWK_BG");
	
	H_EWK->Add(H_GJets);	
//	H_EWK->Add(H_GammaPixel);
//	H_EWK->Add(H_ttbar);		//Zwar gleicher Prozess aber bereits NNLO, deswegen nicht mitskalieren
//	H_EWK->Add(H_Diboson);
//	H_EWK->Add(H_QCD);	
	canvas->cd(i);
	
	chi2[i-1] = H_Data->Chi2Test(H_EWK,"UW OF P CHI2/NDF");

	canvas->Update();
if (i == 21 || i == 141 || i == 64 || i == 65){
  if (i == 64 || i == 65){
	canvas->cd(i - 62); 
	}
  if (i == 21){
	canvas->cd(1);
	}		
  if (i == 141){
	canvas->cd(4);
	}		
	gPad->SetLogy(1);
	gStyle->SetPaintTextFormat(".2f");		
	H_Data->Draw("E1");
	H_Data->SetTitle("");		
//	H_Data->GetYaxis()->SetRangeUser(8,500);
	H_Data->GetYaxis()->SetTitle("corrected events per bin");	
	H_Data->SetMarkerStyle(8);
	H_Data->SetMarkerColor(kBlack);
	H_Data->SetLineColor(kBlack);
	H_Data->SetTitleSize(0.5);	
	H_Data->GetXaxis()->SetTitle("#slash{E}_{T} / #sqrt{H_{T}} [#sqrt{GeV}]");	
	H_Data->GetYaxis()->SetTitleSize(0.062);
  H_Data->GetXaxis()->SetTitleSize(0.062);		
	H_Data->GetYaxis()->SetLabelSize(0.07);
	H_Data->GetXaxis()->SetLabelSize(0.062);
	H_Data->GetXaxis()->SetTitleOffset(0.8);
	gPad->SetBottomMargin(0.12);	
	gPad->SetLeftMargin(0.12);
	gPad->SetRightMargin(0.03);	
	CMS_text = new TLatex(0.1,0.91,"#int L dt = 7.4 fb^{-1},  #sqrt{S} = 8 TeV,   CMS PRIVATE WORK");
	CMS_text->SetNDC();
  CMS_text->SetTextSize(0.05);
  CMS_text->Draw();		
	std::string s;
	std::stringstream out;
	out << scale_EWK;
	s = out.str();
	string factor = "k_{V#gamma} = ";
	factor.append(s);
	
	std::string s1;
	std::stringstream out1;
	out1 << scale_GJets;
	s1 = out1.str();
	string factor1 = "#Rightarrow k_{#gammaJets} = ";
	factor1.append(s1);	
	
	std::string s2;
	std::stringstream out2;
	out2 << chi2[i-1];
	s2 = out2.str();
	string factor2 = "#chi^{2}/ndf = ";
	factor2.append(s2);	
	
	gStyle->SetPaintTextFormat(".2f");		
	kEWK = new TLatex(12.5,200,factor.c_str());
  kEWK->SetTextSize(0.07);
  kEWK->Draw();	
	kGJets = new TLatex(12.5,160,factor1.c_str());
  kGJets->SetTextSize(0.07);
  kGJets->Draw("same");	
	Chi2T = new TLatex(12.5,120,factor2.c_str());
  Chi2T->SetTextSize(0.07);
  Chi2T->Draw("same");	
	gStyle->SetPaintTextFormat(".2f");	
	//gPad->Update();
	gPad->SetLogy(1);
	gPad->Update();
	double N_BG = H_EWK->Integral();
	double N_signal = H_signal->Integral();
	double N_signal2 = H_signal2->Integral();	
	
	EWK_BG->SetLineColor(kBlack);
	EWK_BG->Draw("hist same");	
	EWK_BG->SetFillStyle(1001);	
  EWK_BG->SetFillColor(kOrange);
		
	H_GJets->SetLineColor(kBlack);
	H_GJets->Draw("same hist");
	H_GJets->SetFillStyle(1001);	
  H_GJets->SetFillColor(kRed+2);	
	
//	H_GammaPixel->Draw("same hist");
	H_GammaPixel->SetFillStyle(1001);	
	H_GammaPixel->SetFillColor(kSpring);
	
	H_EWK->Draw("hist E1 same");
	H_EWK->SetLineColor(kBlue);
	H_EWK->SetLineWidth(3);	
	
	H_Data->Draw("same E1");	
	gPad->SetLogy(0);
	gPad->RedrawAxis();
	gStyle->SetOptStat(00000);
	
	TLegend *infoBox = new TLegend(0.69, 0.4, 0.97, 0.899,"");//0.75, 0.83, 0.99, 0.99, "");

	infoBox->AddEntry(H_Data,"corr. Data" , "lep");
	infoBox->AddEntry(H_EWK,"V#gamma + #gammaJets" , "l");		
	infoBox->AddEntry(EWK_BG,"V#gamma" , "f");
	infoBox->AddEntry(H_GJets,"#gammaJets" , "f");	
//	infoBox->AddEntry(H_GammaPixel,"e#rightarrow#gamma" , "f");				 
  infoBox->SetShadowColor(0);  // 0 = transparent
  infoBox->SetFillColor(kWhite); 
	infoBox->SetTextSize(0.069);
  infoBox->Draw("same");
	
	}
		
		
		
	}
	
	
	canvas2->cd(1);
	for (int j=0; j<149; j++){
	  x[j]= 0.06 + j*0.02;
	  }
	cout << "  -------------------------------------------" << endl;		
	TGraph *chi2_graph = new TGraph(149,x,chi2);
	chi2_graph->GetXaxis()->SetRangeUser(0.0,3.1);
	chi2_graph->GetXaxis()->SetTitle("V#gamma scale");
	double max = chi2_graph->GetMaximum();
	chi2_graph->GetYaxis()->SetRangeUser(0,max); //(0.5,2.7);
	chi2_graph->GetYaxis()->SetTitle("#chi^{2}/ndf");
	chi2_graph->SetMarkerStyle(21);
	chi2_graph->SetMarkerColor(1);
	chi2_graph->SetMarkerSize(.9);
	chi2_graph->GetYaxis()->SetTitleSize(0.06);
  chi2_graph->GetXaxis()->SetTitleSize(0.06);		
	chi2_graph->GetYaxis()->SetLabelSize(0.06);
	chi2_graph->GetXaxis()->SetLabelSize(0.06);
	chi2_graph->GetXaxis()->SetTitleOffset(0.85);
	chi2_graph->GetYaxis()->SetTitleOffset(0.5);		
	chi2_graph->SetTitle("#chi^{2} distribution for scale factor");
	//chi2_graph->SetTitleSize(0.1);	
	gStyle->SetOptStat(0);
	gStyle->SetPadTickX(1);
	gStyle->SetPadTickY(1);
	gPad->SetGridx(1);
	gPad->SetGridy(1);
	chi2_graph->Draw("AP E1");	
//Fit a parable
	cout << "  -------------------------------------------" << endl;
  cout << " Fit" << endl;
	cout << "  -------------------------------------------" << endl;	
	if ( Vg ) {
		chi2_graph->GetXaxis()->SetTitle("V#gamma scale");
		TF1 *parable = new TF1("parable","[0]+[1]*pow(x-[2],2)",1.65,1.9);
//		TF1 *parable = new TF1("parable","[0]+[1]*pow(x-[2],2)",1.,1.5);
		parable->SetParameter(2,1.3);
		}
	else {
	  chi2_graph->GetXaxis()->SetTitle("#gammaJets scale");
		TF1 *parable = new TF1("parable","[0]+[1]*pow(x-[2],2)",2.45,2.65);
		parable->SetParameter(2,2.4);
		}
//	TF1 *parable = new TF1("parable","[0]+[1]*pow(x-[2],2)",1.8,2.4);
//	TF1 *parable = new TF1("parable","[0]+[1]*pow(x-[2],2)",1.6,2.2);	
	parable->SetParName(0,"offset_y_m");
	parable->SetParName(1,"factor_m");
	parable->SetParName(2,"offset_x_m");
	parable->SetParameter(0,2);
	parable->SetParameter(1,0.5);
//	parable->SetParameter(2,2.7);
//	parable->SetParameter(2,1.7);	
	parable->SetLineWidth(3);	
  chi2_graph->Fit("parable","R");
	double offset_y_m = parable->GetParameter(0);
	double factor_m = parable->GetParameter(1);
	double offset_x_m = parable->GetParameter(2);
	double mean_up_m = parable->GetX(offset_y_m + 1, offset_x_m , 10);
	double mean_down_m = parable->GetX(offset_y_m + 1, -10 , offset_x_m);
	TLine *l_chi_p1 = new TLine(1,(offset_y_m + 1),3,(offset_y_m + 1));
	l_chi_p1->SetLineWidth(4);
	l_chi_p1->SetLineStyle(7);
	l_chi_p1->SetLineColor(kBlue);	
	l_chi_p1->Draw("same");	
	text = new TLatex((offset_x_m - 0.3),(offset_y_m + 1.2),"(#chi^{2}/ndf @ min) + 1");
	text->SetTextSize(0.055);
	text->SetTextColor(kBlue);	
	text->Draw("same");
	std::string t;
	std::stringstream add;
	add << offset_x_m;
	t = add.str();
	string value = "";
	value.append(t);
	text2 = new TLatex((offset_x_m - 0.1),(offset_y_m + 0.2),value.c_str());
	text2->SetTextSize(0.055);
	text2->SetTextColor(kRed);	
	text2->Draw("same");	
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

	if ( Vg ) {
	double result = (scale*(dataEWK + dataGJets) - offset_x_m*dataEWK)/dataGJets;	
	cout << "----RESULT_GJetScale:  " << result << "   -----" << endl;	
		}
	else {
	double result = (scale*(dataEWK + dataGJets) - offset_x_m*dataGJets)/dataEWK;	
	cout << "----RESULT_EWKScale:  " << result << "   -----" << endl;	
		}
		
	cout << "total Scale:  " << scale << "   -----" << endl;	
	cout << "data:  " << data << "    GammaPixel:   " << dataFake << "    EWKBG:   " << dataEWK << "   GJets:   " << dataGJets << endl;
	cout << "BG integral:  " << N_BG << "   signal integral:  " << N_signal << "   contamination:  " << N_signal/N_BG << endl;
	cout << "BG integral:  " << N_BG << "   signal2 integral:  " << N_signal2 << "   contamination:  " << N_signal2/N_BG << endl;
	
	
	TH1F *MSH = new TH1F("MSH", "cut dependency (upper cut & binning)",5,75,125);
	TH1F *MSH_2 = new TH1F("MSH_2", "cut dependency (upper cut)",5,75,125);	
	TH1F *MS = new TH1F("MS", "cut dependency",5,75,125);
	TH1F *H = new TH1F("H", "cut dependency",5,75,125);	
	TH1F *choice = new TH1F("choice", "cut dependency",5,75,125);	
		
	MSH->SetBinContent(1,1.86);
	MSH->SetBinError(1,0.45);	
	MSH->SetBinContent(2,1.86);
	MSH->SetBinError(2,0.42);		
	MSH->SetBinContent(3,1.90);
	MSH->SetBinError(3,0.41);	
	MSH->SetBinContent(4,1.84);
	MSH->SetBinError(4,0.43);		
	MSH->SetBinContent(5,1.86);
	MSH->SetBinError(5,0.43);	
	MSH->SetLineColor(kCyan);
//	MSH->SetLineWidth(3);	
//	MSH->SetLineStyle(2);
	MSH->SetFillColor(kCyan);	
	MSH->SetFillStyle(3944);	
	
	TH1F *points = MSH->Clone("points");
	points->SetLineColor(kBlack);
	points->SetMarkerSize(2);
	points->SetMarkerStyle(34);	
	points->SetFillStyle(1001);
			
	MSH_2->SetBinContent(1,1.88);
	MSH_2->SetBinError(1,0.60);	
	MSH_2->SetBinContent(2,1.89);
	MSH_2->SetBinError(2,0.58);		
	MSH_2->SetBinContent(3,1.95);
	MSH_2->SetBinError(3,0.57);	
	MSH_2->SetBinContent(4,1.92);
	MSH_2->SetBinError(4,0.58);		
	MSH_2->SetBinContent(5,1.92);
	MSH_2->SetBinError(5,0.58);	
	MSH_2->SetLineColor(kMagenta+2);
	MSH_2->SetLineWidth(3);	
	MSH_2->SetLineStyle(2);	
	
	
	MS->SetBinContent(1,1.76);
	MS->SetBinError(1,0.66);	
	MS->SetBinContent(2,1.72);
	MS->SetBinError(2,0.60);		
	MS->SetBinContent(3,1.71);
	MS->SetBinError(3,0.56);	
	MS->SetBinContent(4,1.67);
	MS->SetBinError(4,0.56);		
	MS->SetBinContent(5,1.68);
	MS->SetBinError(5,0.54);	
	MS->SetLineColor(kBlue);
	MS->SetLineWidth(3);				
	MS->SetLineStyle(9);	
	
	H->SetBinContent(1,1.77);
	H->SetBinError(1,0.70);	
	H->SetBinContent(2,1.84);
	H->SetBinError(2,0.67);		
	H->SetBinContent(3,1.85);
	H->SetBinError(3,0.64);	
	H->SetBinContent(4,1.82);
	H->SetBinError(4,0.63);		
	H->SetBinContent(5,1.85);
	H->SetBinError(5,0.61);	
	H->SetLineColor(kGreen);	
	H->SetLineWidth(3);	
		
	for (int i = 1; i < 6; i++) {	
		choice->SetBinContent(i,1,1.914);
		choice->SetBinError(i,0.311948);	
		}
	choice->SetLineColor(kRed);	
	choice->SetFillColor(kRed);
	choice->SetFillStyle(3002);
	
	canvas3->cd(1);
	MSH->GetYaxis()->SetRangeUser(0,4);
	MSH->GetXaxis()->SetRangeUser(60,140);
	MSH->GetYaxis()->SetTitle("V#gamma scale");
	MSH->GetXaxis()->SetTitle("upper p_{T} cut [GeV]");
	MSH->GetYaxis()->SetTitleSize(0.062);
  MSH->GetXaxis()->SetTitleSize(0.062);		
	MSH->GetYaxis()->SetLabelSize(0.07);
	MSH->GetXaxis()->SetLabelSize(0.062);
	MSH->GetXaxis()->SetTitleOffset(0.85);	
	MSH->GetYaxis()->SetTitleOffset(0.8);		
	gPad->SetBottomMargin(0.12);
	MSH->Draw("E2");
	choice->Draw("same E2");			
	H->Draw("same E1 hist ");
	MS->Draw("same hist E1");	
	MSH_2->Draw("same hist E1");
	points->Draw("same");
	TLegend *l = new TLegend(0.55, 0.65, 0.9, 0.899,"");//0.75, 0.83, 0.99, 0.99, "");

	l->AddEntry(H,"HT" , "l");
	l->AddEntry(MS,"MET significance" , "l");		
	l->AddEntry(MSH_2,"MET / #sqrt{HT} [48 bins]" , "l");	
	l->AddEntry(MSH,"MET / #sqrt{HT} [30 bins]" , "f");				 
  l->SetShadowColor(0);  // 0 = transparent
  l->SetFillColor(kWhite); 
	l->SetTextSize(0.040);
  l->Draw("same");
	gStyle->SetPadTickX(1);
	gStyle->SetPadTickY(1);
	gPad->SetGridx(1);
	gPad->SetGridy(1);
	}
