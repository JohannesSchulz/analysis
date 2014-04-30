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

int significance(){


	int bin_high = -1;
//	int bin_low = 0;
//	int bin_high = 7;
	double EWK_scale = 1.9223;
	double GJets_scale = 2.34156;
	double MCweight = 1.154034091;		
	double fake_scale = 0.0148;
	double trigger_effi = 0.885339;
//	string histo = "h_selection_high2";
//	string histo = "h_stage5_inverse_met";	
		string histo = "h_stage16_met_significance";
		
	MCweight = MCweight * trigger_effi;

//	string histo = "h_inverse_met_selection_high";	//"h_selection_high2";//h_inverse_met_selection_low_log.pdf

  TFile *Data  			= new TFile("PhotonParkedD_V06.1_sel.root");
	TFile *GJets	  	= new TFile("GJetsAdd.root");	
	TFile *ZGamma 		= new TFile("ZGammaAdd.root");
//	TFile *WGamma 		= new TFile("WGamma_V02.1_sel.root");	
	TFile *WGamma 		= new TFile("WGamma_split.root");		
	TFile *GammaPixel = new TFile("GammaPixel.root");
	TFile *QCD100 		= new TFile("QCD_100_250_V06.1_sel.root");	
	TFile *QCD250 		= new TFile("QCD_250_500_V02.1_sel.root");
	TFile *QCD500 		= new TFile("QCD_500_1000_V02.1_sel.root");
	TFile *QCD1000 		= new TFile("QCD_1000_inf_V02.1_sel.root");
	TFile *TTJets 		= new TFile("TTGamma_V02.1_sel.root");
	TFile *Dibo 			= new TFile("Diboson.root");	
	TFile *Signal_440_430 = new TFile("signal_440_430.root");
	TFile *Signal_490_480 = new TFile("signal_490_480.root");
	TFile *Signal_515_505 = new TFile("signal_515_505.root");	
	TFile *Signal_540_480 = new TFile("signal_540_480.root");
	TFile *Signal_540_530 = new TFile("signal_540_530.root");	
	TFile *Signal_565_555 = new TFile("signal_565_555.root");	
	TFile *Signal_590_580 = new TFile("signal_590_580.root");
	TFile *Signal_615_605 = new TFile("signal_615_605.root");	
	TFile *Signal_640_630 = new TFile("signal_640_630.root");	
	TFile *Signal_665_655 = new TFile("signal_665_655.root");	
	TFile *Signal_690_680 = new TFile("signal_690_680.root");	
	TFile *Signal_715_705 = new TFile("signal_715_705.root");		
	TFile *Signal_740_730 = new TFile("signal_740_730.root");
	
	H_Data_signal  	 = (TH1F*)Data->Get(histo.c_str());	
	H_GJets_signal   = (TH1F*)GJets->Get(histo.c_str());	
	H_QCD100_signal	 = (TH1F*)QCD100->Get(histo.c_str());
	H_QCD250_signal	 = (TH1F*)QCD250->Get(histo.c_str());
	H_QCD500_signal	 = (TH1F*)QCD500->Get(histo.c_str());
	H_QCD1000_signal = (TH1F*)QCD1000->Get(histo.c_str());
	H_TTJets_signal	 = (TH1F*)TTJets->Get(histo.c_str());
	H_ZGamma_signal	 = (TH1F*)ZGamma->Get(histo.c_str());
	H_WGamma_signal	 = (TH1F*)WGamma->Get(histo.c_str());
	H_GammaPixel_signal	 = (TH1F*)GammaPixel->Get(histo.c_str());	
	H_Diboson_signal	 = (TH1F*)Dibo->Get(histo.c_str());	
		
//	H_Signal_440_430_signal	 = (TH1F*)Signal_440_430->Get(histo.c_str());
	H_Signal_490_480_signal	 = (TH1F*)Signal_490_480->Get(histo.c_str());	
	H_Signal_515_505_signal	 = (TH1F*)Signal_515_505->Get(histo.c_str());		
	H_Signal_540_480_signal	 = (TH1F*)Signal_540_480->Get(histo.c_str());	
	H_Signal_540_530_signal	 = (TH1F*)Signal_540_530->Get(histo.c_str());	
	H_Signal_565_555_signal	 = (TH1F*)Signal_565_555->Get(histo.c_str());		
	H_Signal_590_580_signal	 = (TH1F*)Signal_590_580->Get(histo.c_str());	
	H_Signal_615_605_signal	 = (TH1F*)Signal_615_605->Get(histo.c_str());		
	H_Signal_640_630_signal	 = (TH1F*)Signal_640_630->Get(histo.c_str());
	H_Signal_665_655_signal	 = (TH1F*)Signal_665_655->Get(histo.c_str());		
	H_Signal_690_680_signal	 = (TH1F*)Signal_690_680->Get(histo.c_str());			
	H_Signal_715_705_signal	 = (TH1F*)Signal_715_705->Get(histo.c_str());		
	H_Signal_740_730_signal	 = (TH1F*)Signal_740_730->Get(histo.c_str());	
	
	H_GJets_signal->Scale(GJets_scale);	
	H_ZGamma_signal->Scale(EWK_scale);
	H_WGamma_signal->Scale(EWK_scale);
	H_GammaPixel_signal->Scale(fake_scale);
	
	TCanvas *c1 = new TCanvas("c1","Plots",1000,700);	
	c1->Divide(1,1);	
		
	TCanvas *c_z = new TCanvas("c_z","Plots",1000,700);	
	c_z->Divide(1,1);
		
	TCanvas *c2 = new TCanvas("c2","Plots",700,700);		
	TH2F *h_xs = new TH2F("h_xs", "Cross section of signals in fb", 11, 467.5, 742.5, 11, 477.5, 752.5);
	c2->Divide(1,1);				
		
	TCanvas *c3 = new TCanvas("c3","Plots",700,700);		
	TH1F *h_sensi = new TH1F("h_sensi", "S/#sqrt{(S+B)}", 5, -50, 450);	
	c3->Divide(1,1);		
	
	
	
	
	TCanvas *c4 = new TCanvas("c4","Plots",700,700);		
	TH1F *h_sensi_bin = new TH1F("h_sensi_bin", "S/#sqrt{(S+B)}", 20, 10.5, 30.5);
//	TH1F *h_sensi_bin = new TH1F("h_sensi_bin", "S/#sqrt{(S+B)}", 14, 0.5, 14.5);		
	c4->Divide(1,1);
			
	double NMC = 0;		
	double Ndata = 0;
//for  ( bin_high = 0; bin_high < 14; bin_high++) {		
for  ( bin_low = 10; bin_low < 31; bin_low++) {		
	Ndata = 0;
	Ndata = H_Data_signal->Integral(bin_low,bin_high); 
	NMC = 0;
	NMC = H_GJets_signal->Integral(bin_low,bin_high) + H_QCD100_signal->Integral(bin_low,bin_high) + H_QCD250_signal->Integral(bin_low,bin_high) +	H_QCD500_signal->Integral(bin_low,bin_high) +	 H_QCD1000_signal->Integral(bin_low,bin_high) +	
	H_TTJets_signal->Integral(bin_low,bin_high) +	H_ZGamma_signal->Integral(bin_low,bin_high) +	H_WGamma_signal->Integral(bin_low,bin_high) +
	H_GammaPixel_signal->Integral(bin_low,bin_high) +	H_Diboson_signal->Integral(bin_low,bin_high);
	NMC = NMC * trigger_effi;
	
//	double Nsignal_440_430 = H_Signal_440_430_signal->Integral(bin_low,bin_high);	
	double Nsignal_490_480 = H_Signal_490_480_signal->Integral(bin_low,bin_high);
	double Nsignal_515_505 = H_Signal_515_505_signal->Integral(bin_low,bin_high);	
	double Nsignal_540_480 = H_Signal_540_480_signal->Integral(bin_low,bin_high);	
	double Nsignal_540_530 = H_Signal_540_530_signal->Integral(bin_low,bin_high);
	double Nsignal_565_555 = H_Signal_565_555_signal->Integral(bin_low,bin_high);		
	double Nsignal_590_580 = H_Signal_590_580_signal->Integral(bin_low,bin_high);	
	double Nsignal_615_605 = H_Signal_615_605_signal->Integral(bin_low,bin_high);	
	double Nsignal_640_630 = H_Signal_640_630_signal->Integral(bin_low,bin_high);
	double Nsignal_665_655 = H_Signal_665_655_signal->Integral(bin_low,bin_high);	
	double Nsignal_690_680 = H_Signal_690_680_signal->Integral(bin_low,bin_high);	
	double Nsignal_715_705 = H_Signal_715_705_signal->Integral(bin_low,bin_high);		
	double Nsignal_740_730 = H_Signal_740_730_signal->Integral(bin_low,bin_high);		

//	Nsignal_440_430	= Nsignal_440_430 * MCweight;
	Nsignal_490_480 = Nsignal_490_480 * MCweight;
	Nsignal_515_505	= Nsignal_515_505 * MCweight;	
	Nsignal_540_480	= Nsignal_540_480 * MCweight;
	Nsignal_540_530 = Nsignal_540_530 * MCweight;
	Nsignal_565_555	= Nsignal_565_555 * MCweight;		
	Nsignal_590_580	= Nsignal_590_580 * MCweight;
	Nsignal_615_605	= Nsignal_615_605 * MCweight;	
	Nsignal_640_630 = Nsignal_640_630 * MCweight;
	Nsignal_665_655	= Nsignal_665_655 * MCweight;	
	Nsignal_690_680 = Nsignal_690_680 * MCweight;	
	Nsignal_715_705	= Nsignal_715_705 * MCweight;		
	Nsignal_740_730	= Nsignal_740_730 * MCweight;
	
		
	cout << "Number of data: " << Ndata << " , number of BG events: " << NMC << " - number of signal(640_630) events: " << Nsignal_640_630 << 
	" - number of signal(540_530) events: " << Nsignal_540_530 << endl;
	
//	double significance_440_430 =  Nsignal_440_430 / sqrt(Nsignal_440_430 + NMC);

	if  ((Nsignal_490_480 + NMC) > 0){
	
	double significance_490_480 =  Nsignal_490_480 / sqrt(Nsignal_490_480 + NMC);
	double significance_515_505 =  Nsignal_515_505 / sqrt(Nsignal_515_505 + NMC);	
	double significance_540_480 =  Nsignal_540_480 / sqrt(Nsignal_540_480 + NMC);
	double significance_540_530 =  Nsignal_540_530 / sqrt(Nsignal_540_530 + NMC);
	double significance_565_555 =  Nsignal_565_555 / sqrt(Nsignal_565_555 + NMC);			
	double significance_590_580 =  Nsignal_590_580 / sqrt(Nsignal_590_580 + NMC);
	double significance_615_605 =  Nsignal_615_605 / sqrt(Nsignal_615_605 + NMC);		
	double significance_640_630 =  Nsignal_640_630 / sqrt(Nsignal_640_630 + NMC);
	double significance_665_655 =  Nsignal_665_655 / sqrt(Nsignal_665_655 + NMC);		
	double significance_690_680 =  Nsignal_690_680 / sqrt(Nsignal_690_680 + NMC);	
	double significance_715_705 =  Nsignal_715_705 / sqrt(Nsignal_715_705 + NMC);		
	double significance_740_730 =  Nsignal_740_730 / sqrt(Nsignal_740_730 + NMC);
		
	
	cout << "Significance S/sqrt(S+B) for 640_630: " << significance_640_630 << " and significance S/sqrt(S+B) for 540_530: " << significance_540_530 << endl;
	
//	double Z_A_440_430 = sqrt(2*( (Nsignal_440_430 + NMC)*log(1+(Nsignal_440_430/NMC)) - Nsignal_440_430) );
	double Z_A_490_480 = sqrt(2*( (Nsignal_490_480 + NMC)*log(1+(Nsignal_490_480/NMC)) - Nsignal_490_480) );
	double Z_A_515_505 = sqrt(2*( (Nsignal_515_505 + NMC)*log(1+(Nsignal_515_505/NMC)) - Nsignal_515_505) );	
	double Z_A_540_480 = sqrt(2*( (Nsignal_540_480 + NMC)*log(1+(Nsignal_540_480/NMC)) - Nsignal_540_480) );
	double Z_A_540_530 = sqrt(2*( (Nsignal_540_530 + NMC)*log(1+(Nsignal_540_530/NMC)) - Nsignal_540_530) );
	double Z_A_565_555 = sqrt(2*( (Nsignal_565_555 + NMC)*log(1+(Nsignal_565_555/NMC)) - Nsignal_565_555) );			
	double Z_A_590_580 = sqrt(2*( (Nsignal_590_580 + NMC)*log(1+(Nsignal_590_580/NMC)) - Nsignal_590_580) );
	double Z_A_615_605 = sqrt(2*( (Nsignal_615_605 + NMC)*log(1+(Nsignal_615_605/NMC)) - Nsignal_615_605) );		
	double Z_A_640_630 = sqrt(2*( (Nsignal_640_630 + NMC)*log(1+(Nsignal_640_630/NMC)) - Nsignal_640_630) );
	double Z_A_665_655 = sqrt(2*( (Nsignal_665_655 + NMC)*log(1+(Nsignal_665_655/NMC)) - Nsignal_665_655) );		
	double Z_A_690_680 = sqrt(2*( (Nsignal_690_680 + NMC)*log(1+(Nsignal_690_680/NMC)) - Nsignal_690_680) );
	double Z_A_715_705 = sqrt(2*( (Nsignal_715_705 + NMC)*log(1+(Nsignal_715_705/NMC)) - Nsignal_715_705) );			
	double Z_A_740_730 = sqrt(2*( (Nsignal_740_730 + NMC)*log(1+(Nsignal_740_730/NMC)) - Nsignal_740_730) );
		
	cout << "Z_A for 640_630: " << Z_A_640_630 << " and Z_A for 540_530: " << Z_A_540_530 <<endl;
	} else {
	double significance_490_480 =0; 
	double significance_540_480 =0;
	double significance_540_530 =0;	
	double significance_590_580 =0;
	double significance_640_630 =0;
	double significance_690_680 =0;	
	double significance_740_730 =0;
	double Z_A_490_480 =0;
	double Z_A_540_480 =0; 
	double Z_A_540_530 =0;
	double Z_A_590_580 =0;
	double Z_A_640_630 =0; 
	double Z_A_690_680 =0;	
	double Z_A_740_730 =0; 	
	}
	gStyle->SetStatFontSize(200);	
	
	bool plot = true; //(bin_high == 50);
	
if ( plot ){	
	c1->cd(1);	
	TH2F *h_significance = new TH2F("h_significance", "S/#sqrt{(S+B)}",11, 455, 755, 11, 465, 765);
	TH2F *h_Z_A = new TH2F("h_Z_A", "Z_{A}",11, 455, 755, 11, 465, 765);		
	TLine *l_excl = new TLine(455,500,500,500);
	TLine *l_diag = new TLine(465,465,755,755);	
//	h_significance->Fill(430,440,significance_440_430);

	h_significance->Fill(480,490,significance_490_480);
	h_significance->Fill(505,515,significance_515_505);		
	h_significance->Fill(480,540,significance_540_480);
	h_significance->Fill(530,540,significance_540_530);
	h_significance->Fill(555,565,significance_565_555);		
	h_significance->Fill(580,590,significance_590_580);
	h_significance->Fill(605,615,significance_615_605);	
	h_significance->Fill(630,640,significance_640_630);
	h_significance->Fill(655,665,significance_665_655);	
	h_significance->Fill(680,690,significance_690_680);	
	h_significance->Fill(705,715,significance_715_705);		
	h_significance->Fill(730,740,significance_740_730);
	
//	gStyle->GetPalette()->SetWmax(20);
	
	h_significance->GetYaxis()->SetTitleSize(0.05);
  h_significance->GetXaxis()->SetTitleSize(0.05);		
	h_significance->GetYaxis()->SetLabelSize(0.05);
	h_significance->GetXaxis()->SetLabelSize(0.05);
	h_significance->GetXaxis()->SetTitleOffset(0.95);
	
	h_significance->GetYaxis()->SetTitle("Wino mass [GeV]");
	h_significance->GetYaxis()->SetTitleOffset(0.95);		
	h_significance->GetXaxis()->SetTitle("Bino mass [GeV]");	
	h_significance->SetMarkerSize(1.5);
//	h_significance->SetContour(30);
	
	h_significance->Draw("text colz");
	l_excl->SetLineWidth(2);
	l_diag->SetLineWidth(2);		
	l_excl->Draw("same");
	l_diag->Draw("same");		
	gStyle->SetOptStat(0000);
	
	
	c1->Update();	
	c_z->cd(1);
//	h_Z_A->Fill(430,440,Z_A_440_430);
	h_Z_A->Fill(480,490,Z_A_490_480);	
	h_Z_A->Fill(505,515,Z_A_515_505);	
	h_Z_A->Fill(480,540,Z_A_540_480);
	h_Z_A->Fill(530,540,Z_A_540_530);	
	h_Z_A->Fill(555,565,Z_A_565_555);		
	h_Z_A->Fill(580,590,Z_A_590_580);
	h_Z_A->Fill(605,615,Z_A_615_605);		
	h_Z_A->Fill(630,640,Z_A_640_630);	
	h_Z_A->Fill(655,665,Z_A_665_655);		
	h_Z_A->Fill(680,690,Z_A_690_680);	
	h_Z_A->Fill(705,715,Z_A_715_705);		
	h_Z_A->Fill(730,740,Z_A_740_730);
	
	h_Z_A->GetYaxis()->SetTitleSize(0.05);
  h_Z_A->GetXaxis()->SetTitleSize(0.05);		
	h_Z_A->GetYaxis()->SetLabelSize(0.05);
	h_Z_A->GetXaxis()->SetLabelSize(0.05);	
	h_Z_A->GetXaxis()->SetTitleOffset(0.95);
	
	h_Z_A->GetYaxis()->SetTitle("Wino mass [GeV]");	
	h_Z_A->GetYaxis()->SetTitleOffset(0.95);	
	h_Z_A->GetXaxis()->SetTitle("Bino mass [GeV]");	
	h_Z_A->SetMarkerSize(1.5);
	h_Z_A->Draw("text colz");	
	l_excl->Draw("same");
	l_diag->Draw("same");		
	gStyle->SetOptStat(0000);	
	gStyle->SetStatFontSize(2);		
	c_z->Update();
	
	}	
	c4->cd(1);
	
	h_sensi_bin->Fill(bin_low,significance_640_630);
//	h_sensi_bin->Fill(bin_high,significance_640_630);	
	h_sensi_bin->SetLineWidth(3);	
	h_sensi_bin->GetXaxis()->SetTitle("bin range");	
	h_sensi_bin->GetYaxis()->SetTitle("S/#sqrt{(S+B)}");
	h_sensi_bin->GetYaxis()->SetTitleOffset(1.1);			
	h_sensi_bin->Draw("hist");		
	gStyle->SetOptStat(0000);		
	}
	c2->cd(1);
//	h_xs->Fill(430,440,);
	h_xs->Fill(480,490,16.34);
	h_xs->Fill(505,515,12.38);
	h_xs->Fill(480,515,12.41);			
	h_xs->Fill(480,540,9.638);
	h_xs->Fill(530,540,9.425);
	h_xs->Fill(505,540,9.539);	
	h_xs->Fill(555,565,7.475);
	h_xs->Fill(530,565,7.441);
	h_xs->Fill(505,565,7.430);				
	h_xs->Fill(580,590,5.774);
	h_xs->Fill(555,590,5.769);
	h_xs->Fill(530,590,5.806);		
	h_xs->Fill(605,615,4.457);
	h_xs->Fill(580,615,4.518);		
	h_xs->Fill(630,640,3.520);
	h_xs->Fill(605,640,3.534);	
	h_xs->Fill(655,665,2.764);	
	h_xs->Fill(680,690,2.181);
	h_xs->Fill(705,715,1.715);			
	h_xs->Fill(730,740,1.378);
	h_xs->SetMarkerSize(1.5);
	h_xs->GetYaxis()->SetTitle("Wino mass [GeV]");	
	h_xs->GetXaxis()->SetTitle("Bino mass [GeV]");		
	h_xs->Draw("text colz");
	l_excl->Draw("same");
	l_diag->Draw("same");		
	gStyle->SetOptStat(0000);
  gStyle->SetPadTickX(1);
	gStyle->SetPadTickY(1);
	gPad->SetGridx(1);
	gPad->SetGridy(1);
	c3->cd(1);
	
	h_sensi->Fill(0,0.1);	
	h_sensi->Fill(100,1.2);		
	h_sensi->Fill(200,3.4);		
	h_sensi->Fill(300,2.3);
	h_sensi->Fill(400,1.1);		
	h_sensi->SetLineWidth(3);	
	h_sensi->GetXaxis()->SetTitle("Cut Value");	
	h_sensi->GetYaxis()->SetTitle("S/#sqrt{(S+B)}");
	h_sensi->GetYaxis()->SetTitleOffset(1.1);			
	
	gStyle->SetOptStat(0000);		
	h_sensi->Draw("hist");	
	}
	
	
	
	
	
	
	
