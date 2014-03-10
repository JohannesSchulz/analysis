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

int bypass(){

  TFile *Data  			= new TFile("PhotonParkedD_V06.1_sel.root");
	TFile *DataMET  	= new TFile("METParkedD_V06.1_sel.root");
	
	H_denumerator_bypass_tight_MET_2 = (TH1F*)Data->Get("h_denumerator_bypass_tight_MET_2");
	H_numerator_bypass_tight_MET_2 = (TH1F*)Data->Get("h_numerator_bypass_tight_MET_2");
	H_denumerator_bypass_loose_MET_2 = (TH1F*)Data->Get("h_denumerator_bypass_loose_MET_2");
	H_numerator_bypass_loose_MET_2 = (TH1F*)Data->Get("h_numerator_bypass_loose_MET_2");
	
	H_denumerator_bypass_tight_2 = (TH1F*)Data->Get("h_denumerator_bypass_tight_2");
	H_numerator_bypass_tight_2 = (TH1F*)Data->Get("h_numerator_bypass_tight_2");
	H_denumerator_bypass_loose_2 = (TH1F*)Data->Get("h_denumerator_bypass_loose_2");
	H_numerator_bypass_loose_2 = (TH1F*)Data->Get("h_numerator_bypass_loose_2");	
	
	
	H_numerator_bypass_tight_MET_2->GetXaxis()->SetTitle("MET [GeV]");
	H_denumerator_bypass_tight_MET_2->GetXaxis()->SetTitle("MET [GeV]");	
	H_numerator_bypass_loose_MET_2->GetXaxis()->SetTitle("MET [GeV]");
	H_denumerator_bypass_loose_MET_2->GetXaxis()->SetTitle("MET [GeV]");	
	H_denumerator_bypass_tight_MET_2->Rebin(4);
	H_numerator_bypass_tight_MET_2->Rebin(4);
	H_denumerator_bypass_loose_MET_2->Rebin(4);
	H_numerator_bypass_loose_MET_2->Rebin(4);
	
	H_denumerator_bypass_tight_2->Rebin(4);
	H_numerator_bypass_tight_2->Rebin(4);
	H_denumerator_bypass_loose_2->Rebin(4);
	H_numerator_bypass_loose_2->Rebin(4);
	
	
	
	
	TEfficiency *T_by_tight_MET = new TEfficiency(*H_numerator_bypass_tight_MET_2, *H_denumerator_bypass_tight_MET_2);	
	TEfficiency *T_by_loose_MET = new TEfficiency(*H_numerator_bypass_loose_MET_2, *H_denumerator_bypass_loose_MET_2);	
	TEfficiency *T_by_tight = new TEfficiency(*H_numerator_bypass_tight_2, *H_denumerator_bypass_tight_2);	
	TEfficiency *T_by_loose = new TEfficiency(*H_numerator_bypass_loose_2, *H_denumerator_bypass_loose_2);
		
	TCanvas *c1 = new TCanvas("c1","Plots",600,600);
//  c1->Divide(2,1);
//  c1->cd(1);
	gPad->SetGridx(1);
	gPad->SetGridy(1);

	T_by_tight_MET->SetTitle("(Signaltrigger && MET100)/MET100, PhotonParked");
	T_by_tight_MET->Draw();
	gPad->Update();
	T_by_tight_MET->GetPaintedGraph()->GetXaxis()->SetTitle("MET [GeV]");		
	T_by_tight_MET->SetMarkerStyle(8);	
	T_by_loose_MET->Draw("same");
	T_by_loose_MET->SetMarkerStyle(8);
	T_by_loose_MET->SetMarkerColor(kRed);	
	T_by_loose_MET->SetLineColor(kRed);		
	TLegend *infoBox = new TLegend(0.77, 0.8, 0.99, 0.99,"");
  infoBox->AddEntry(T_by_tight_MET,"# tight photon == 0","lep");
  infoBox->AddEntry(T_by_loose_MET,"# loose photon == 0","lep");
  infoBox->SetShadowColor(0);  // 0 = transparent
  infoBox->SetFillColor(kWhite); 
	infoBox->SetTextSize(0.025);
  infoBox->Draw();	
	
	
/*	c1->cd(2);
	T_by_tight_MET->SetTitle("(Signaltrigger && MET100)/MET100, METParked");
	T_by_tight_MET->Draw();
	T_by_tight_MET->SetMarkerStyle(8);	
	T_by_loose_MET->Draw("same");
	T_by_loose_MET->SetMarkerColor(kRed);	
	T_by_loose_MET->SetLineColor(kRed);	
	T_by_loose_MET->SetMarkerStyle(8);	
	
	gPad->SetGridx(1);
	gPad->SetGridy(1);		
	
	TLegend *infoBox = new TLegend(0.77, 0.8, 0.99, 0.99,"");
  infoBox->AddEntry(T_by_tight_MET,"# tight photon == 0","lep");
  infoBox->AddEntry(T_by_loose_MET,"# loose photon == 0","lep");
  infoBox->SetShadowColor(0);  // 0 = transparent
  infoBox->SetFillColor(kWhite); 
	infoBox->SetTextSize(0.025);
  infoBox->Draw(); */
	
	TCanvas *c2 = new TCanvas("c2","Plots",600,600);
	T_by_tight->SetTitle("(Signaltrigger && Photon30)/Photon30, PhotonParked");
	T_by_tight->Draw();
	T_by_tight->SetMarkerStyle(8);	
	gPad->Update();
	T_by_tight->GetPaintedGraph()->GetXaxis()->SetTitle("MET [GeV]");	
	T_by_loose->Draw("same");	
	T_by_loose->SetMarkerStyle(8);
	T_by_loose->SetLineColor(kRed);
	T_by_loose->SetMarkerColor(kRed);	
	gPad->SetGridx(1);
	gPad->SetGridy(1);		
	TLegend *infoBox = new TLegend(0.77, 0.8, 0.99, 0.99,"");
  infoBox->AddEntry(T_by_tight,"# tight photon == 0","lep");
  infoBox->AddEntry(T_by_loose,"# loose photon == 0","lep");
  infoBox->SetShadowColor(0);  // 0 = transparent
  infoBox->SetFillColor(kWhite); 
	infoBox->SetTextSize(0.025);
  infoBox->Draw();	
	
	}
	
	
	
