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


	int bin_low = 0;
//	int bin_high = 7;
	double MCweight = 2;
	string histo = "h_inverse_met_selection_high";//"h_selection_high2";//h_inverse_met_selection_low_log.pdf

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
	TFile *ZGamma 		= new TFile("ZGammaAdd.root");
	TFile *WGamma 			= new TFile("WGamma_V02.1_sel.root");
	TFile *Signal_440_430 = new TFile("signal_440_430.root");
	TFile *Signal_490_480 = new TFile("signal_490_480.root");
	TFile *Signal_540_480 = new TFile("signal_540_480.root");
	TFile *Signal_540_530 = new TFile("signal_540_530.root");	
	TFile *Signal_590_580 = new TFile("signal_590_580.root");
	TFile *Signal_640_630 = new TFile("signal_640_630.root");	
	TFile *Signal_690_680 = new TFile("signal_690_680.root");		
	TFile *Signal_740_730 = new TFile("signal_740_730.root");
	
	H_Data_signal  	 = (TH1F*)Data->Get(histo.c_str());	
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
		
//	H_Signal_440_430_signal	 = (TH1F*)Signal_440_430->Get(histo.c_str());
	H_Signal_490_480_signal	 = (TH1F*)Signal_490_480->Get(histo.c_str());	
	H_Signal_540_480_signal	 = (TH1F*)Signal_540_480->Get(histo.c_str());	
	H_Signal_540_530_signal	 = (TH1F*)Signal_540_530->Get(histo.c_str());	
	H_Signal_590_580_signal	 = (TH1F*)Signal_590_580->Get(histo.c_str());	
	H_Signal_640_630_signal	 = (TH1F*)Signal_640_630->Get(histo.c_str());
	H_Signal_690_680_signal	 = (TH1F*)Signal_690_680->Get(histo.c_str());			
	H_Signal_740_730_signal	 = (TH1F*)Signal_740_730->Get(histo.c_str());	
	
	
	TCanvas *c1 = new TCanvas("c1","Plots",1000,700);	
	c1->Divide(2,2);	
		
	TCanvas *c_z = new TCanvas("c_z","Plots",1000,700);	
	c_z->Divide(2,2);
		
	TCanvas *c2 = new TCanvas("c2","Plots",700,700);		
	TH2F *h_xs = new TH2F("h_xs", "Cross section of signals in fb", 9, 355, 805, 9, 365, 815);
	c2->Divide(1,1);				
		
	TCanvas *c3 = new TCanvas("c3","Plots",700,700);		
	TH1F *h_sensi = new TH1F("h_sensi", "S/#sqrt{(S+B)}", 5, -50, 450);	
	c3->Divide(1,1);		
	
	TCanvas *c4 = new TCanvas("c4","Plots",700,700);		
	TH1F *h_sensi_bin = new TH1F("h_sensi_bin", "S/#sqrt{(S+B)}", 14, 0.5, 14.5);	
	c4->Divide(1,1);		
		
for  ( bin_high = 1; bin_high < 15; bin_high++) {		

	double Ndata = H_Data_signal->Integral(bin_low,bin_high); 
	
	double NMC = H_GJets40_signal->Integral(bin_low,bin_high) +	H_GJets100_signal->Integral(bin_low,bin_high) + H_GJets200_signal->Integral(bin_low,bin_high) + H_GJets400_signal->Integral(bin_low,bin_high) +
	H_QCD100_signal->Integral(bin_low,bin_high) + H_QCD250_signal->Integral(bin_low,bin_high) +	H_QCD500_signal->Integral(bin_low,bin_high) +	 H_QCD1000_signal->Integral(bin_low,bin_high) +	
	H_TTJets_signal->Integral(bin_low,bin_high) +	H_ZGamma_signal->Integral(bin_low,bin_high) +	H_WGamma_signal->Integral(bin_low,bin_high);
	
//	double Nsignal_440_430 = H_Signal_440_430_signal->Integral(bin_low,bin_high);	
	double Nsignal_490_480 = H_Signal_490_480_signal->Integral(bin_low,bin_high);
	double Nsignal_540_480 = H_Signal_540_480_signal->Integral(bin_low,bin_high);	
	double Nsignal_540_530 = H_Signal_540_530_signal->Integral(bin_low,bin_high);	
	double Nsignal_590_580 = H_Signal_590_580_signal->Integral(bin_low,bin_high);	
	double Nsignal_640_630 = H_Signal_640_630_signal->Integral(bin_low,bin_high);
	double Nsignal_690_680 = H_Signal_690_680_signal->Integral(bin_low,bin_high);		
	double Nsignal_740_730 = H_Signal_740_730_signal->Integral(bin_low,bin_high);		
	
	NMC = NMC * MCweight;	
//	Nsignal_440_430	= Nsignal_440_430 * MCweight;
	Nsignal_490_480 = Nsignal_490_480 * MCweight;
	Nsignal_540_480	= Nsignal_540_480 * MCweight;
	Nsignal_540_530 = Nsignal_540_530 * MCweight;	
	Nsignal_590_580	= Nsignal_590_580 * MCweight;
	Nsignal_640_630 = Nsignal_640_630 * MCweight;
	Nsignal_690_680 = Nsignal_690_680 * MCweight;		
	Nsignal_740_730	= Nsignal_740_730 * MCweight;
	
		
	cout << "Number of data: " << Ndata << " , number of BG events: " << NMC << " - number of signal(640_630) events: " << Nsignal_640_630 << 
	" - number of signal(540_530) events: " << Nsignal_540_530 << endl;
	
//	double significance_440_430 =  Nsignal_440_430 / sqrt(Nsignal_440_430 + NMC);

	if  ((Nsignal_490_480 + NMC) > 0){
	
	double significance_490_480 =  Nsignal_490_480 / sqrt(Nsignal_490_480 + NMC);
	double significance_540_480 =  Nsignal_540_480 / sqrt(Nsignal_540_480 + NMC);
	double significance_540_530 =  Nsignal_540_530 / sqrt(Nsignal_540_530 + NMC);	
	double significance_590_580 =  Nsignal_590_580 / sqrt(Nsignal_590_580 + NMC);
	double significance_640_630 =  Nsignal_640_630 / sqrt(Nsignal_640_630 + NMC);
	double significance_690_680 =  Nsignal_690_680 / sqrt(Nsignal_690_680 + NMC);	
	double significance_740_730 =  Nsignal_740_730 / sqrt(Nsignal_740_730 + NMC);
		
	
	cout << "Significance S/sqrt(S+B) for 640_630: " << significance_640_630 << " and significance S/sqrt(S+B) for 540_530: " << significance_540_530 << endl;
	
//	double Z_A_440_430 = sqrt(2*( (Nsignal_440_430 + NMC)*log(1+(Nsignal_440_430/NMC)) - Nsignal_440_430) );
	double Z_A_490_480 = sqrt(2*( (Nsignal_490_480 + NMC)*log(1+(Nsignal_490_480/NMC)) - Nsignal_490_480) );
	double Z_A_540_480 = sqrt(2*( (Nsignal_540_480 + NMC)*log(1+(Nsignal_540_480/NMC)) - Nsignal_540_480) );
	double Z_A_540_530 = sqrt(2*( (Nsignal_540_530 + NMC)*log(1+(Nsignal_540_530/NMC)) - Nsignal_540_530) );	
	double Z_A_590_580 = sqrt(2*( (Nsignal_590_580 + NMC)*log(1+(Nsignal_590_580/NMC)) - Nsignal_590_580) );
	double Z_A_640_630 = sqrt(2*( (Nsignal_640_630 + NMC)*log(1+(Nsignal_640_630/NMC)) - Nsignal_640_630) );
	double Z_A_690_680 = sqrt(2*( (Nsignal_690_680 + NMC)*log(1+(Nsignal_690_680/NMC)) - Nsignal_690_680) );	
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
if (bin_high == 6 || bin_high == 7 || bin_high == 8 || bin_high == 9 ){	
	c1->cd(bin_high - 5);	
	TH2F *h_significance = new TH2F("h_significance", "S/#sqrt{(S+B)}", 9, 355, 805, 9, 365, 815);
	TH2F *h_Z_A = new TH2F("h_Z_A", "Z_{A}", 9, 355, 805, 9, 365, 815);		
	TLine *l_excl = new TLine(365,500,500,500);
	TLine *l_diag = new TLine(365,365,805,805);	
//	h_significance->Fill(430,440,significance_440_430);

	h_significance->Fill(480,490,significance_490_480);	
	h_significance->Fill(480,540,significance_540_480);
	h_significance->Fill(530,540,significance_540_530);	
	h_significance->Fill(580,590,significance_590_580);
	h_significance->Fill(630,640,significance_640_630);
	h_significance->Fill(680,690,significance_690_680);		
	h_significance->Fill(730,740,significance_740_730);
	h_significance->GetYaxis()->SetTitle("Wino mass [GeV]");
	h_significance->GetYaxis()->SetTitleOffset(1.5);		
	h_significance->GetXaxis()->SetTitle("Bino mass [GeV]");	
	h_significance->Draw("text colz");
	l_excl->Draw("same");
	l_diag->Draw("same");		
	gStyle->SetOptStat(0000);
	
	
	c1->Update();	
	c_z->cd(bin_high - 5);
//	h_Z_A->Fill(430,440,Z_A_440_430);
	h_Z_A->Fill(480,490,Z_A_490_480);	
	h_Z_A->Fill(480,540,Z_A_540_480);
	h_Z_A->Fill(530,540,Z_A_540_530);	
	h_Z_A->Fill(580,590,Z_A_590_580);
	h_Z_A->Fill(630,640,Z_A_640_630);	
	h_Z_A->Fill(680,690,Z_A_690_680);	
	h_Z_A->Fill(730,740,Z_A_740_730);
	h_Z_A->GetYaxis()->SetTitle("Wino mass [GeV]");	
	h_Z_A->GetYaxis()->SetTitleOffset(1.5);	
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
	
	h_sensi_bin->Fill(bin_high,significance_540_530);
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
	h_xs->Fill(480,540,9.638);
	h_xs->Fill(530,540,9.425);	
	h_xs->Fill(580,590,5.774);
	h_xs->Fill(630,640,3.520);
	h_xs->Fill(680,690,2.181);		
	h_xs->Fill(730,740,1.378);
	h_xs->GetYaxis()->SetTitle("Wino mass [GeV]");	
	h_xs->GetXaxis()->SetTitle("Bino mass [GeV]");		
	h_xs->Draw("text colz");
	l_excl->Draw("same");
	l_diag->Draw("same");		
	gStyle->SetOptStat(0000);
  
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
	
	
	
	
	
	
	
