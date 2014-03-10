
#include <string>
#include <iostream>
#include <math.h>
#include <fstream.h>
#include <algorithm>

#include <TH1.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TLegend.h>
#include <TROOT.h>
#include <TFile.h>
#include <TCanvas.h>


using namespace std;

int fake_e(){

  TH1::SetDefaultSumw2();	
	
	int rebin = 5;	
	double order = 1.8;  // WZ, ZZ hängen davon ab. Insgesamt kaum Einfluss wegen ttbar
	double efficiency = 0.885339;  // unabhängig von dieser zahl -> Skalierung
	double FakeRateMC = 0.009591; // 0.0095
//	double FakeRateMC =0.008471; //0.0084;//0.008471;  // schwarze Linie skaliert damit
	double error = 0;
	double error_final = 0;
	double bin_content = 0;
	//double error_fake = 0.004234383;
	double error_fake = 0.00053852;
	
	string histo = "h_truth_fake_inverse_met_sel"; //"h_truth_fake_inverse_met_sel";//h_truth_electrons_pt_sel";

	TFile *GJets40  	= new TFile("GJets_40_100_V06.1_sel.root");	
	TFile *GJets100 	= new TFile("GJets_100_200_V02.1_sel.root");
	TFile *GJets200 	= new TFile("GJets_200_400_V02.1_sel.root");
	TFile *GJets400 	= new TFile("GJets_400_inf_V02.1_sel.root");
	TFile *QCD100 		= new TFile("QCD_100_250_V06.1_sel.root");	
	TFile *QCD250 		= new TFile("QCD_250_500_V02.1_sel.root");
	TFile *QCD500 		= new TFile("QCD_500_1000_V02.1_sel.root");
	TFile *QCD1000 		= new TFile("QCD_1000_inf_V02.1_sel.root");
	TFile *TTJets 		= new TFile("TTJets_V02.1_sel.root");
	TFile *ZGamma 		= new TFile("ZGammaAdd.root");
	TFile *WGamma 		= new TFile("WGamma_V02.1_sel.root");
	TFile *WW					= new TFile("WW_incl_V06.1_sel.root");
	TFile *WZ					= new TFile("WZ_incl_V06.1_sel.root");	
	TFile *ZZ					= new TFile("ZZ_incl_V06.1_sel.root");	
	
	TFile *GJets40_P  	= new TFile("GammaPixel/GJets_40_100_V06.1_sel.root");	
	TFile *GJets100_P 	= new TFile("GammaPixel/GJets_100_200_V02.1_sel.root");
	TFile *GJets200_P 	= new TFile("GammaPixel/GJets_200_400_V02.1_sel.root");
	TFile *GJets400_P 	= new TFile("GammaPixel/GJets_400_inf_V02.1_sel.root");
	TFile *QCD100_P 		= new TFile("GammaPixel/QCD_100_250_V06.1_sel.root");	
	TFile *QCD250_P 		= new TFile("GammaPixel/QCD_250_500_V02.1_sel.root");
	TFile *QCD500_P 		= new TFile("GammaPixel/QCD_500_1000_V02.1_sel.root");
	TFile *QCD1000_P 		= new TFile("GammaPixel/QCD_1000_inf_V02.1_sel.root");
	TFile *TTJets_P 		= new TFile("GammaPixel/TTJets_V02.1_sel.root");
	TFile *ZGamma_P 		= new TFile("GammaPixel/ZGammaAdd.root");
	TFile *WGamma_P 		= new TFile("GammaPixel/WGamma_V02.1_sel.root");	
	TFile *WW_P					= new TFile("GammaPixel/WW_incl_V06.1_sel.root");	
	TFile *WZ_P					= new TFile("GammaPixel/WZ_incl_V06.1_sel.root");	
	TFile *ZZ_P					= new TFile("GammaPixel/ZZ_incl_V06.1_sel.root");
	
/*	H_GJets40_signal = (TH1F*)GJets40->Get(histo.c_str());	
	H_GJets100_signal = (TH1F*)GJets100->Get(histo.c_str());
	H_GJets200_signal = (TH1F*)GJets200->Get(histo.c_str());
	H_GJets400_signal = (TH1F*)GJets400->Get(histo.c_str());
	H_QCD100_signal	 = (TH1F*)QCD100->Get(histo.c_str());
	H_QCD250_signal	 = (TH1F*)QCD250->Get(histo.c_str());
	H_QCD500_signal	 = (TH1F*)QCD500->Get(histo.c_str());
	H_QCD1000_signal	 = (TH1F*)QCD1000->Get(histo.c_str()); */
	H_TTJets_signal	 = (TH1F*)TTJets->Get(histo.c_str());
//	H_ZGamma_signal	 = (TH1F*)ZGamma->Get(histo.c_str());
//	H_WGamma_signal		 = (TH1F*)WGamma->Get(histo.c_str());
	H_WW_signal			=(TH1F*)WW->Get(histo.c_str());
	H_WZ_signal			=(TH1F*)WZ->Get(histo.c_str());	
	H_ZZ_signal			=(TH1F*)ZZ->Get(histo.c_str());	
	
	
/*	H_GJets40_P_signal = (TH1F*)GJets40_P->Get(histo.c_str());	
	H_GJets100_P_signal = (TH1F*)GJets100_P->Get(histo.c_str());
	H_GJets200_P_signal = (TH1F*)GJets200_P->Get(histo.c_str());
	H_GJets400_P_signal = (TH1F*)GJets400_P->Get(histo.c_str());
	H_QCD100_P_signal	 = (TH1F*)QCD100_P->Get(histo.c_str());
	H_QCD250_P_signal	 = (TH1F*)QCD250_P->Get(histo.c_str());
	H_QCD500_P_signal	 = (TH1F*)QCD500_P->Get(histo.c_str());
	H_QCD1000_P_signal	 = (TH1F*)QCD1000_P->Get(histo.c_str()); */
	H_TTJets_P_signal	 = (TH1F*)TTJets_P->Get(histo.c_str());
//	H_ZGamma_P_signal	 = (TH1F*)ZGamma_P->Get(histo.c_str());
//	H_WGamma_P_signal		 = (TH1F*)WGamma_P->Get(histo.c_str());	
	H_WW_P_signal			=(TH1F*)WW_P->Get(histo.c_str());
	H_WZ_P_signal			=(TH1F*)WZ_P->Get(histo.c_str());	
	H_ZZ_P_signal			=(TH1F*)ZZ_P->Get(histo.c_str());		
	

	
/*	H_GJets40_signal->Scale(order*efficiency);
	H_GJets100_signal->Scale(order*efficiency);
	H_GJets200_signal->Scale(order*efficiency);
	H_GJets400_signal->Scale(order*efficiency);
	H_QCD100_signal->Scale(order*efficiency);
	H_QCD250_signal->Scale(order*efficiency);
	H_QCD500_signal->Scale(order*efficiency);
	H_QCD1000_signal->Scale(order*efficiency); */
	H_TTJets_signal->Scale(efficiency);
//	H_ZGamma_signal->Scale(order*efficiency);
//	H_WGamma_signal->Scale(order*efficiency);
	H_WW_signal->Scale(efficiency);
	H_WZ_signal->Scale(order*efficiency);
	H_ZZ_signal->Scale(order*efficiency);	
	
	
/*	H_GJets40_P_signal->Scale(order*efficiency*FakeRateMC);
	H_GJets100_P_signal->Scale(order*efficiency*FakeRateMC);
	H_GJets200_P_signal->Scale(order*efficiency*FakeRateMC);
	H_GJets400_P_signal->Scale(order*efficiency*FakeRateMC);
	H_QCD100_P_signal->Scale(order*efficiency*FakeRateMC);
	H_QCD250_P_signal->Scale(order*efficiency*FakeRateMC);
	H_QCD500_P_signal->Scale(order*efficiency*FakeRateMC);
	H_QCD1000_P_signal->Scale(order*efficiency*FakeRateMC); */
	H_TTJets_P_signal->Scale(efficiency*FakeRateMC);
//	H_ZGamma_P_signal->Scale(order*efficiency*FakeRateMC);
//	H_WGamma_P_signal->Scale(order*efficiency*FakeRateMC);
	H_WW_P_signal->Scale(efficiency*FakeRateMC);
	H_WZ_P_signal->Scale(order*efficiency*FakeRateMC);
	H_ZZ_P_signal->Scale(order*efficiency*FakeRateMC);
	
	
/*	H_GJets40_signal->Rebin(rebin);
	H_GJets100_signal->Rebin(rebin);
	H_GJets200_signal->Rebin(rebin);
	H_GJets400_signal->Rebin(rebin);
	H_QCD100_signal->Rebin(rebin);
	H_QCD250_signal->Rebin(rebin);
	H_QCD500_signal->Rebin(rebin);
	H_QCD1000_signal->Rebin(rebin); */
	H_TTJets_signal->Rebin(rebin);
//	H_ZGamma_signal->Rebin(rebin);
//	H_WGamma_signal->Rebin(rebin);
	H_WW_signal->Rebin(rebin);
	H_WZ_signal->Rebin(rebin);
	H_ZZ_signal->Rebin(rebin);
	
/*	H_GJets40_P_signal->Rebin(rebin);
	H_GJets100_P_signal->Rebin(rebin);
	H_GJets200_P_signal->Rebin(rebin);
	H_GJets400_P_signal->Rebin(rebin);
	H_QCD100_P_signal->Rebin(rebin);
	H_QCD250_P_signal->Rebin(rebin);
	H_QCD500_P_signal->Rebin(rebin);
	H_QCD1000_P_signal->Rebin(rebin); */
	H_TTJets_P_signal->Rebin(rebin);
//	H_ZGamma_P_signal->Rebin(rebin);
//	H_WGamma_P_signal->Rebin(rebin);
	H_WW_P_signal->Rebin(rebin);
	H_WZ_P_signal->Rebin(rebin);
	H_ZZ_P_signal->Rebin(rebin);
	
	
	TCanvas *c2 = new TCanvas("c2","Plots",1200,700);
	
//	int bins = H_GJets40_signal->GetNbinsX();	
	int bins = H_TTJets_signal->GetNbinsX();		
	
	for ( int i = 0; i < bins; i++) {
		error = H_TTJets_P_signal->GetBinError(i);
		bin_content = H_TTJets_P_signal->GetBinContent(i);
		error_final = sqrt( (bin_content * 1./FakeRateMC * error_fake)*(bin_content * 1./FakeRateMC * error_fake) + error*error );
		H_TTJets_P_signal->SetBinError(i,error_final);	
		
		}
	
	c2->SetLogy(1);
	H_TTJets_P_signal->SetLineColor(kRed);
	H_TTJets_P_signal->SetFillColor(kRed);	
	H_TTJets_P_signal->SetFillStyle(3002);	
	H_TTJets_P_signal->Draw("E2");

	H_TTJets_signal->SetLineColor(kBlack);
	H_TTJets_signal->SetLineWidth(2);	
	H_TTJets_signal->Draw("E1 hist same");
	
	TLegend *infoBox2 = new TLegend(0.67, 0.55, 0.9, 0.9,"");
  infoBox2->SetHeader("ttbar");		
  infoBox2->AddEntry(H_TTJets_P_signal,"#gamma_{pixel} * fakerate","f");	
  infoBox2->AddEntry(H_TTJets_signal,"generated e","l");	 	
	infoBox2->SetBorderSize(0);
  infoBox2->SetShadowColor(0);  // 0 = transparent
  infoBox2->SetFillColor(kWhite); 
	infoBox2->SetTextSize(0.035);
  infoBox2->Draw();	
	
	
	H_WW_signal->Add(H_WZ_signal);
	H_WW_signal->Add(H_ZZ_signal);	
	H_WW_P_signal->Add(H_WZ_P_signal);
	H_WW_P_signal->Add(H_ZZ_P_signal);	
	
		
		
	TCanvas *c3 = new TCanvas("c3","Plots",1200,700);
		
	for ( int i = 0; i < bins; i++) {
		error = H_WW_P_signal->GetBinError(i);
		bin_content = H_WW_P_signal->GetBinContent(i);
		error_final = sqrt( (bin_content * 1./FakeRateMC * error_fake)*(bin_content * 1./FakeRateMC * error_fake) + error*error );
		H_WW_P_signal->SetBinError(i,error_final);	
		
		}
	
	c3->SetLogy(1);
	H_WW_P_signal->SetLineColor(kRed);
	H_WW_P_signal->SetFillColor(kRed);	
	H_WW_P_signal->SetFillStyle(3002);	
	H_WW_P_signal->Draw("E2");

	H_WW_signal->SetLineColor(kBlack);
	H_WW_signal->SetLineWidth(2);	
	H_WW_signal->Draw("E1 hist same");	
	
	TLegend *infoBox3 = new TLegend(0.67, 0.55, 0.9, 0.9,"");
  infoBox3->SetHeader("Diboson");		
  infoBox3->AddEntry(H_TTJets_P_signal,"#gamma_{pixel} * fakerate","f");	
  infoBox3->AddEntry(H_TTJets_signal,"generated e","l");	 	
	infoBox3->SetBorderSize(0);
  infoBox3->SetShadowColor(0);  // 0 = transparent
  infoBox3->SetFillColor(kWhite); 
	infoBox3->SetTextSize(0.035);
  infoBox3->Draw();
		
/*	H_GJets40_signal->Add(H_GJets100_signal);
	H_GJets40_signal->Add(H_GJets200_signal);				
	H_GJets40_signal->Add(H_GJets400_signal);	
	H_GJets40_signal->Add(H_QCD100_signal);	
	H_GJets40_signal->Add(H_QCD250_signal);	
	H_GJets40_signal->Add(H_QCD500_signal);	
	H_GJets40_signal->Add(H_QCD1000_signal);	
	H_GJets40_signal->Add(H_TTJets_signal);
	H_GJets40_signal->Add(H_ZGamma_signal);
	H_GJets40_signal->Add(H_WGamma_signal);	
	H_GJets40_signal->Add(H_WW_signal);		

	H_GJets40_P_signal->Add(H_GJets100_P_signal);
	H_GJets40_P_signal->Add(H_GJets200_P_signal);				
	H_GJets40_P_signal->Add(H_GJets400_P_signal);	
	H_GJets40_P_signal->Add(H_QCD100_P_signal);	
	H_GJets40_P_signal->Add(H_QCD250_P_signal);	
	H_GJets40_P_signal->Add(H_QCD500_P_signal);	
	H_GJets40_P_signal->Add(H_QCD1000_P_signal);	
	H_GJets40_P_signal->Add(H_TTJets_P_signal);
	H_GJets40_P_signal->Add(H_ZGamma_P_signal);
	H_GJets40_P_signal->Add(H_WGamma_P_signal);	
	H_GJets40_P_signal->Add(H_WW_P_signal);	 */
	
	H_TTJets_signal->Add(H_WW_signal);	
	H_TTJets_P_signal->Add(H_WW_P_signal);	

	
	TCanvas *c1 = new TCanvas("c1","Plots",1200,700);
		gStyle->SetOptStat(0);

/*	for ( int i = 0; i < bins; i++) {
		error = H_GJets40_signal->GetBinError(i);
		bin_content = H_GJets40_signal->GetBinContent(i);
		error_final = sqrt( (bin_content * 1./FakeRateMC * error_fake)*(bin_content * 1./FakeRateMC * error_fake) + error*error );
		H_GJets40_signal->SetBinError(i,error_final);	
		
		} */
		
	for ( int i = 0; i < bins; i++) {
		error = H_TTJets_signal->GetBinError(i);
		bin_content = H_TTJets_signal->GetBinContent(i);
		error_final = sqrt( (bin_content * 1./FakeRateMC * error_fake)*(bin_content * 1./FakeRateMC * error_fake) + error*error );
		H_TTJets_signal->SetBinError(i,error_final);	
		
		} 	
		
	c1->cd();	
	c1->Clear();	
	TPad *canvasDefault_1 = new TPad("canvasDefault_1", "newpad",0.0,0.0,1.0,0.325);	

  canvasDefault_1->SetTopMargin(0.01);
  canvasDefault_1->SetBottomMargin(0.3);
  canvasDefault_1->SetRightMargin(0.1);
  canvasDefault_1->SetFillStyle(0);
	
/*	TH1F *simulation = (TH1F*)H_GJets40_signal->Clone("simulation");
	
	TH1F *prediction = (TH1F*)H_GJets40_P_signal->Clone("prediction");
	TH1F *numerator = (TH1F*)H_GJets40_signal->Clone("numerator");*/
	
	TH1F *simulation = (TH1F*)H_TTJets_signal->Clone("simulation");
	
	TH1F *prediction = (TH1F*)H_TTJets_P_signal->Clone("prediction");
	TH1F *numerator = (TH1F*)H_TTJets_signal->Clone("numerator");	
	
	//Wenn Fehler von denumerator eingezeichnet, dann muss man beim Teilen der Histos aufpassen, addieren sich!
	
	
  canvasDefault_1->cd();
//	numerator->Divide(H_GJets40_P_signal);
  numerator->Divide(H_TTJets_P_signal);
	numerator->SetTitle("");
	numerator->SetMaximum(2.1);	
	numerator->SetMinimum(0.1);
	numerator->SetLineColor(kBlack);
	numerator->SetLineWidth(2);
	numerator->GetYaxis()->SetNdivisions(5);
  numerator->GetYaxis()->SetTitle("ratio");
  numerator->GetYaxis()->CenterTitle();	
  numerator->GetYaxis()->SetTitleSize(0.1);
  numerator->GetXaxis()->SetTitleSize(0.1);		
	numerator->GetYaxis()->SetLabelSize(0.1);
	numerator->GetXaxis()->SetLabelSize(0.1);
  numerator->GetYaxis()->SetTitleOffset(0.4);	
	prediction->Divide(prediction);
	prediction->SetFillStyle(3002);	
	prediction->SetFillColor(kRed);
	
/*	for ( int i = 0; i < bins; i++) {
		error_final = H_GJets40_P_signal->GetBinError(i)/(H_GJets40_P_signal->GetBinContent(i));
		prediction->SetBinError(i,error_final);			
		}	
	
	for ( int i = 0; i < bins; i++) {
		error_final = H_GJets40_signal->GetBinError(i)/(H_GJets40_P_signal->GetBinContent(i));
		numerator->SetBinError(i,error_final);			
		} */
		
	for ( int i = 0; i < bins; i++) {
		error_final = H_TTJets_P_signal->GetBinError(i)/(H_TTJets_P_signal->GetBinContent(i));
		prediction->SetBinError(i,error_final);			
		}	
	
	for ( int i = 0; i < bins; i++) {
		error_final = H_TTJets_signal->GetBinError(i)/(H_TTJets_P_signal->GetBinContent(i));
		numerator->SetBinError(i,error_final);			
		} 	
		
		
	numerator->Draw("E1");		
	prediction->Draw("same E2");	
	numerator->Draw("same E1");	
	
	gPad->SetGrid();
	gStyle->SetGridStyle(3);
	gStyle->SetPadTickX(1);
  gStyle->SetPadTickY(1);
	
  c1->cd();
  canvasDefault_1->Draw();	
	 	
	c1->cd();
	
  TPad *canvasDefault_2 = new TPad("canvasDefault_2", "newpad",0.0,0.32,1,1);
  canvasDefault_2->Draw(); 
  canvasDefault_2->cd();
  canvasDefault_2->SetTopMargin(0.1);
  canvasDefault_2->SetBottomMargin(0.01);
  canvasDefault_2->SetRightMargin(0.1);
  canvasDefault_1->SetFillStyle(0);
	
  canvasDefault_2->SetLogy(1);
/*	H_GJets40_P_signal->SetLineColor(kRed);
	H_GJets40_P_signal->SetFillColor(kRed);	
	H_GJets40_P_signal->SetFillStyle(3002);	
	H_GJets40_P_signal->Draw("E2");
	
	H_GJets40_signal->SetLineColor(kBlack);
	H_GJets40_signal->SetLineWidth(2);	
	H_GJets40_signal->Draw("E1 hist same"); */
	
	H_TTJets_P_signal->SetLineColor(kRed);
	H_TTJets_P_signal->SetFillColor(kRed);	
	H_TTJets_P_signal->SetFillStyle(3002);	
	H_TTJets_P_signal->Draw("E2");
	
	H_TTJets_signal->SetLineColor(kBlack);
	H_TTJets_signal->SetLineWidth(2);	
	H_TTJets_signal->Draw("E1 hist same"); 
	

	prediction->SetLabelSize(0.0);
	prediction->GetXaxis()->SetTitleSize(0.00);
	prediction->GetYaxis()->SetLabelSize(0.05);
	prediction->GetYaxis()->SetTitle("# events");
	prediction->GetYaxis()->SetTitleSize(0.05);	

	
	prediction->GetXaxis()->SetTitle("");
	
/*	TLegend *infoBox = new TLegend(0.78, 0.6, 0.99, 0.99,"");
  infoBox->SetHeader("Total background");		
  infoBox->AddEntry(H_GJets40_P_signal,"#gamma_{pixel} * fakerate","f");	
  infoBox->AddEntry(H_GJets40_signal,"generated e","l");	 */	
	
	TLegend *infoBox = new TLegend(0.7, 0.6, 0.9, 0.9,"");
  infoBox->SetHeader("Total background");		
  infoBox->AddEntry(H_TTJets_P_signal,"#gamma_{pixel} * fakerate","f");	
	infoBox->SetBorderSize(0);
	infoBox->AddEntry(H_TTJets_signal,"generated e","l");	 	

  infoBox->SetShadowColor(0);  // 0 = transparent
  infoBox->SetFillColor(kWhite); 
	infoBox->SetTextSize(0.042);
  infoBox->Draw();
	
	
	}
	
 /*
	
	
	// For inverse Presentation
	
#include <string>
#include <iostream>
#include <math.h>
#include <fstream.h>
#include <algorithm>

#include <TH1.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TLegend.h>
#include <TROOT.h>
#include <TFile.h>
#include <TCanvas.h>


using namespace std;

int fake_e(){

  TH1::SetDefaultSumw2();	
	
	int rebin = 5;	
	double order = 1.8;  // WZ, ZZ hängen davon ab. Insgesamt kaum Einfluss wegen ttbar
	double efficiency = 0.885339;  // unabhängig von dieser zahl -> Skalierung
//	double FakeRateMC = 0.008471;  // schwarze Linie skaliert damit
	double error = 0;
	double error_final = 0;
	double bin_content = 0;
	double error_fake = 0.004234383;
	//double error_fake = 0.00053852;	
	double FakeRateMC = 0.009591; // 0.0095
//	double FakeRateMC =0.008471; //0.0084;//0.008471;  // schwarze Linie skaliert damit
	
	string histo = "h_truth_electrons_pt_sel";

	TFile *GJets40  	= new TFile("GJets_40_100_V06.1_sel.root");	
	TFile *GJets100 	= new TFile("GJets_100_200_V02.1_sel.root");
	TFile *GJets200 	= new TFile("GJets_200_400_V02.1_sel.root");
	TFile *GJets400 	= new TFile("GJets_400_inf_V02.1_sel.root");
	TFile *QCD100 		= new TFile("QCD_100_250_V06.1_sel.root");	
	TFile *QCD250 		= new TFile("QCD_250_500_V02.1_sel.root");
	TFile *QCD500 		= new TFile("QCD_500_1000_V02.1_sel.root");
	TFile *QCD1000 		= new TFile("QCD_1000_inf_V02.1_sel.root");
	TFile *TTJets 		= new TFile("TTJets_V02.1_sel.root");
	TFile *ZGamma 		= new TFile("ZGammaAdd.root");
	TFile *WGamma 		= new TFile("WGamma_V02.1_sel.root");
	TFile *WW					= new TFile("WW_incl_V06.1_sel.root");
	TFile *WZ					= new TFile("WZ_incl_V06.1_sel.root");	
	TFile *ZZ					= new TFile("ZZ_incl_V06.1_sel.root");	
	
	TFile *GJets40_P  	= new TFile("GammaPixel/GJets_40_100_V06.1_sel.root");	
	TFile *GJets100_P 	= new TFile("GammaPixel/GJets_100_200_V02.1_sel.root");
	TFile *GJets200_P 	= new TFile("GammaPixel/GJets_200_400_V02.1_sel.root");
	TFile *GJets400_P 	= new TFile("GJets_400_inf_V02.1_sel.root");
	TFile *QCD100_P 		= new TFile("GammaPixel/QCD_100_250_V06.1_sel.root");	
	TFile *QCD250_P 		= new TFile("GammaPixel/QCD_250_500_V02.1_sel.root");
	TFile *QCD500_P 		= new TFile("GammaPixel/QCD_500_1000_V02.1_sel.root");
	TFile *QCD1000_P 		= new TFile("GammaPixel/QCD_1000_inf_V02.1_sel.root");
	TFile *TTJets_P 		= new TFile("GammaPixel/TTJets_V02.1_sel.root");
	TFile *ZGamma_P 		= new TFile("GammaPixel/ZGammaAdd.root");
	TFile *WGamma_P 		= new TFile("GammaPixel/WGamma_V02.1_sel.root");	
	TFile *WW_P					= new TFile("GammaPixel/WW_incl_V06.1_sel.root");	
	TFile *WZ_P					= new TFile("GammaPixel/WZ_incl_V06.1_sel.root");	
	TFile *ZZ_P					= new TFile("GammaPixel/ZZ_incl_V06.1_sel.root");
	
	H_GJets40_signal = (TH1F*)GJets40->Get(histo.c_str());	
	H_GJets100_signal = (TH1F*)GJets100->Get(histo.c_str());
	H_GJets200_signal = (TH1F*)GJets200->Get(histo.c_str());
	H_GJets400_signal = (TH1F*)GJets400->Get(histo.c_str());
	H_QCD100_signal	 = (TH1F*)QCD100->Get(histo.c_str());
	H_QCD250_signal	 = (TH1F*)QCD250->Get(histo.c_str());
	H_QCD500_signal	 = (TH1F*)QCD500->Get(histo.c_str());
	H_QCD1000_signal	 = (TH1F*)QCD1000->Get(histo.c_str());
	H_TTJets_signal	 = (TH1F*)TTJets->Get(histo.c_str());
	H_ZGamma_signal	 = (TH1F*)ZGamma->Get(histo.c_str());
	H_WGamma_signal		 = (TH1F*)WGamma->Get(histo.c_str());
	H_WW_signal			=(TH1F*)WW->Get(histo.c_str());
	H_WZ_signal			=(TH1F*)WZ->Get(histo.c_str());	
	H_ZZ_signal			=(TH1F*)ZZ->Get(histo.c_str());	
	
	
	H_GJets40_P_signal = (TH1F*)GJets40_P->Get(histo.c_str());	
	H_GJets100_P_signal = (TH1F*)GJets100_P->Get(histo.c_str());
	H_GJets200_P_signal = (TH1F*)GJets200_P->Get(histo.c_str());
	H_GJets400_P_signal = (TH1F*)GJets400_P->Get(histo.c_str());
	H_QCD100_P_signal	 = (TH1F*)QCD100_P->Get(histo.c_str());
	H_QCD250_P_signal	 = (TH1F*)QCD250_P->Get(histo.c_str());
	H_QCD500_P_signal	 = (TH1F*)QCD500_P->Get(histo.c_str());
	H_QCD1000_P_signal	 = (TH1F*)QCD1000_P->Get(histo.c_str());
	H_TTJets_P_signal	 = (TH1F*)TTJets_P->Get(histo.c_str());
	H_ZGamma_P_signal	 = (TH1F*)ZGamma_P->Get(histo.c_str());
	H_WGamma_P_signal		 = (TH1F*)WGamma_P->Get(histo.c_str());	
	H_WW_P_signal			=(TH1F*)WW_P->Get(histo.c_str());
	H_WZ_P_signal			=(TH1F*)WZ_P->Get(histo.c_str());	
	H_ZZ_P_signal			=(TH1F*)ZZ_P->Get(histo.c_str());		
	

	
	H_GJets40_signal->Scale(order*efficiency);
	H_GJets100_signal->Scale(order*efficiency);
	H_GJets200_signal->Scale(order*efficiency);
	H_GJets400_signal->Scale(order*efficiency);
	H_QCD100_signal->Scale(order*efficiency);
	H_QCD250_signal->Scale(order*efficiency);
	H_QCD500_signal->Scale(order*efficiency);
	H_QCD1000_signal->Scale(order*efficiency);
	H_TTJets_signal->Scale(efficiency);
	H_ZGamma_signal->Scale(order*efficiency);
	H_WGamma_signal->Scale(order*efficiency);
	H_WW_signal->Scale(efficiency);
	H_WZ_signal->Scale(order*efficiency);
	H_ZZ_signal->Scale(order*efficiency);	
	
	
	H_GJets40_P_signal->Scale(order*efficiency*FakeRateMC);
	H_GJets100_P_signal->Scale(order*efficiency*FakeRateMC);
	H_GJets200_P_signal->Scale(order*efficiency*FakeRateMC);
	H_GJets400_P_signal->Scale(order*efficiency*FakeRateMC);
	H_QCD100_P_signal->Scale(order*efficiency*FakeRateMC);
	H_QCD250_P_signal->Scale(order*efficiency*FakeRateMC);
	H_QCD500_P_signal->Scale(order*efficiency*FakeRateMC);
	H_QCD1000_P_signal->Scale(order*efficiency*FakeRateMC);
	H_TTJets_P_signal->Scale(efficiency*FakeRateMC);
	H_ZGamma_P_signal->Scale(order*efficiency*FakeRateMC);
	H_WGamma_P_signal->Scale(order*efficiency*FakeRateMC);
	H_WW_P_signal->Scale(efficiency*FakeRateMC);
	H_WZ_P_signal->Scale(order*efficiency*FakeRateMC);
	H_ZZ_P_signal->Scale(order*efficiency*FakeRateMC);
	
	
	H_GJets40_signal->Rebin(rebin);
	H_GJets100_signal->Rebin(rebin);
	H_GJets200_signal->Rebin(rebin);
	H_GJets400_signal->Rebin(rebin);
	H_QCD100_signal->Rebin(rebin);
	H_QCD250_signal->Rebin(rebin);
	H_QCD500_signal->Rebin(rebin);
	H_QCD1000_signal->Rebin(rebin);
	H_TTJets_signal->Rebin(rebin);
	H_ZGamma_signal->Rebin(rebin);
	H_WGamma_signal->Rebin(rebin);
	H_WW_signal->Rebin(rebin);
	H_WZ_signal->Rebin(rebin);
	H_ZZ_signal->Rebin(rebin);
	
	H_GJets40_P_signal->Rebin(rebin);
	H_GJets100_P_signal->Rebin(rebin);
	H_GJets200_P_signal->Rebin(rebin);
	H_GJets400_P_signal->Rebin(rebin);
	H_QCD100_P_signal->Rebin(rebin);
	H_QCD250_P_signal->Rebin(rebin);
	H_QCD500_P_signal->Rebin(rebin);
	H_QCD1000_P_signal->Rebin(rebin);
	H_TTJets_P_signal->Rebin(rebin);
	H_ZGamma_P_signal->Rebin(rebin);
	H_WGamma_P_signal->Rebin(rebin);
	H_WW_P_signal->Rebin(rebin);
	H_WZ_P_signal->Rebin(rebin);
	H_ZZ_P_signal->Rebin(rebin);
	
	
	TCanvas *c2 = new TCanvas("c2","Plots",1200,700);
	
	int bins = H_GJets40_signal->GetNbinsX();	
	
	for ( int i = 0; i < bins; i++) {
		error = H_TTJets_signal->GetBinError(i);
		bin_content = H_TTJets_signal->GetBinContent(i);
		error_final = sqrt( (bin_content * 1./FakeRateMC * error_fake)*(bin_content * 1./FakeRateMC * error_fake) + error*error );
		H_TTJets_signal->SetBinError(i,error_final);	
		
		}
	
	c2->SetLogy(1);
	H_TTJets_signal->SetLineColor(kRed);
	H_TTJets_signal->SetFillColor(kRed);	
	H_TTJets_signal->SetFillStyle(3002);	
	H_TTJets_signal->Draw("E2");

	H_TTJets_P_signal->SetLineColor(kBlack);
	H_TTJets_P_signal->SetLineWidth(2);	
	H_TTJets_P_signal->Draw("E1 hist same");
	
	
	H_WW_signal->Add(H_WZ_signal);
	H_WW_signal->Add(H_ZZ_signal);	
	H_WW_P_signal->Add(H_WZ_P_signal);
	H_WW_P_signal->Add(H_ZZ_P_signal);	
		
	TCanvas *c3 = new TCanvas("c3","Plots",1200,700);
	
	int bins = H_GJets40_signal->GetNbinsX();	
	
	for ( int i = 0; i < bins; i++) {
		error = H_WW_signal->GetBinError(i);
		bin_content = H_WW_signal->GetBinContent(i);
		error_final = sqrt( (bin_content * 1./FakeRateMC * error_fake)*(bin_content * 1./FakeRateMC * error_fake) + error*error );
		H_WW_signal->SetBinError(i,error_final);	
		
		}
	
	c3->SetLogy(1);
	H_WW_signal->SetLineColor(kRed);
	H_WW_signal->SetFillColor(kRed);	
	H_WW_signal->SetFillStyle(3002);	
	H_WW_signal->Draw("E2");

	H_WW_P_signal->SetLineColor(kBlack);
	H_WW_P_signal->SetLineWidth(2);	
	H_WW_P_signal->Draw("E1 hist same");	
	
		
	H_GJets40_signal->Add(H_GJets100_signal);
	H_GJets40_signal->Add(H_GJets200_signal);				
	H_GJets40_signal->Add(H_GJets400_signal);	
	H_GJets40_signal->Add(H_QCD100_signal);	
	H_GJets40_signal->Add(H_QCD250_signal);	
	H_GJets40_signal->Add(H_QCD500_signal);	
	H_GJets40_signal->Add(H_QCD1000_signal);	
	H_GJets40_signal->Add(H_TTJets_signal);
	H_GJets40_signal->Add(H_ZGamma_signal);
	H_GJets40_signal->Add(H_WGamma_signal);	
	H_GJets40_signal->Add(H_WW_signal);		

	H_GJets40_P_signal->Add(H_GJets100_P_signal);
	H_GJets40_P_signal->Add(H_GJets200_P_signal);				
	H_GJets40_P_signal->Add(H_GJets400_P_signal);	
	H_GJets40_P_signal->Add(H_QCD100_P_signal);	
	H_GJets40_P_signal->Add(H_QCD250_P_signal);	
	H_GJets40_P_signal->Add(H_QCD500_P_signal);	
	H_GJets40_P_signal->Add(H_QCD1000_P_signal);	
	H_GJets40_P_signal->Add(H_TTJets_P_signal);
	H_GJets40_P_signal->Add(H_ZGamma_P_signal);
	H_GJets40_P_signal->Add(H_WGamma_P_signal);	
	H_GJets40_P_signal->Add(H_WW_P_signal);	

	
	TCanvas *c1 = new TCanvas("c1","Plots",1200,700);
	
	gStyle->SetOptStat(0);
	
	for ( int i = 0; i < bins; i++) {
		error = H_GJets40_signal->GetBinError(i);
		bin_content = H_GJets40_signal->GetBinContent(i);
		error_final = sqrt( (bin_content * 1./FakeRateMC * error_fake)*(bin_content * 1./FakeRateMC * error_fake) + error*error );
		H_GJets40_signal->SetBinError(i,error_final);	
		
		}
	
	c1->cd();	
	c1->Clear();	
	TPad *canvasDefault_1 = new TPad("canvasDefault_1", "newpad",0.0,0.0,1.0,0.325);	

  canvasDefault_1->SetTopMargin(0.01);
  canvasDefault_1->SetBottomMargin(0.3);
  canvasDefault_1->SetRightMargin(0.1);
  canvasDefault_1->SetFillStyle(0);
	
	TH1F *simulation = (TH1F*)H_GJets40_signal->Clone("simulation");
	
	TH1F *prediction = (TH1F*)H_GJets40_P_signal->Clone("prediction");
	TH1F *numerator = (TH1F*)H_GJets40_P_signal->Clone("numerator");
	
	//Wenn Fehler von denumerator eingezeichnet, dann muss man beim Teilen der Histos aufpassen, addieren sich!
	
	
  canvasDefault_1->cd();
	numerator->Divide(H_GJets40_signal);
	numerator->SetTitle("");
	numerator->SetMaximum(2.1);	
	numerator->SetMinimum(0.1);
	numerator->SetLineColor(kBlack);
	numerator->SetLineWidth(2);
	numerator->GetYaxis()->SetNdivisions(5);
  numerator->GetYaxis()->SetTitle("ratio");
  numerator->GetYaxis()->CenterTitle();	
  numerator->GetYaxis()->SetTitleSize(0.1);
  numerator->GetXaxis()->SetTitleSize(0.1);		
	numerator->GetYaxis()->SetLabelSize(0.1);
	numerator->GetXaxis()->SetLabelSize(0.1);
  numerator->GetYaxis()->SetTitleOffset(0.4);	
	simulation->Divide(simulation);
	simulation->SetFillStyle(3002);	
	simulation->SetFillColor(kRed);
	
	for ( int i = 0; i < bins; i++) {
		error_final = H_GJets40_signal->GetBinError(i)/(H_GJets40_signal->GetBinContent(i));
		simulation->SetBinError(i,error_final);			
		}	
			
	for ( int i = 0; i < bins; i++) {
		error_final = H_GJets40_P_signal->GetBinError(i)/(H_GJets40_signal->GetBinContent(i));
		numerator->SetBinError(i,error_final);			
		}
		
	numerator->Draw("E1");		
	simulation->Draw("same E2");	
	numerator->Draw("same E1");	
	
	gPad->SetGrid();
	gStyle->SetGridStyle(3);
	gStyle->SetPadTickX(1);
  gStyle->SetPadTickY(1);
	
  c1->cd();
  canvasDefault_1->Draw();	
	 	
	c1->cd();
	
  TPad *canvasDefault_2 = new TPad("canvasDefault_2", "newpad",0.0,0.32,1,1);
  canvasDefault_2->Draw(); 
  canvasDefault_2->cd();
  canvasDefault_2->SetTopMargin(0.1);
  canvasDefault_2->SetBottomMargin(0.01);
  canvasDefault_2->SetRightMargin(0.1);
  canvasDefault_1->SetFillStyle(0);
  canvasDefault_2->SetLogy(1);

	H_GJets40_signal->SetLineColor(kRed);
	H_GJets40_signal->SetFillColor(kRed);	
	H_GJets40_signal->SetFillStyle(3002);	
	H_GJets40_signal->Draw("E2");
	
	H_GJets40_P_signal->SetLineColor(kBlack);
	H_GJets40_P_signal->SetLineWidth(2);	
	H_GJets40_P_signal->Draw("E1 hist same");

	prediction->SetLabelSize(0.0);
	prediction->GetXaxis()->SetTitleSize(0.00);
	prediction->GetYaxis()->SetLabelSize(0.05);
	prediction->GetYaxis()->SetTitle("# events");
	prediction->GetYaxis()->SetTitleSize(0.05);	

	
	prediction->GetXaxis()->SetTitle("");
	
	TLegend *infoBox = new TLegend(0.78, 0.6, 0.99, 0.99,"");
  infoBox->SetHeader("Total background");		
  infoBox->AddEntry(H_GJets40_P_signal,"#gamma_{pixel} * fakerate","l");	
  infoBox->AddEntry(H_GJets40_signal,"generated e","f");		

  infoBox->SetShadowColor(0);  // 0 = transparent
  infoBox->SetFillColor(kWhite); 
	infoBox->SetTextSize(0.045);
  infoBox->Draw();
	}
	
	
*/
