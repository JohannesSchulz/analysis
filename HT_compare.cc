
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

int HT_compare(){

	TFile *Had  	= new TFile("PhotonHadD_V02.1_sel.root");	
	TFile *Data 	= new TFile("HT_Compare.root");

	h_Had			=(TH1F*)Had->Get("h_HT");	
	h_Data		=(TH1F*)Data->Get("h_HT");	
	
	TCanvas *c = new TCanvas("c","Plots",1200,700);
	
	h_Data->GetXaxis()->SetTitle("H_{T} of all jets [GeV]");	
  h_Data->GetYaxis()->SetTitle("# Events");
	h_Data->GetXaxis()->SetTitleSize(0.06);	
  h_Data->GetYaxis()->SetTitleSize(0.07);	
  h_Data->GetXaxis()->SetLabelSize(0.06);	
  h_Data->GetYaxis()->SetLabelSize(0.06);	
  h_Data->GetXaxis()->SetTitleOffset(0.8);	
  h_Data->GetYaxis()->SetTitleOffset(0.7);	
	gStyle->SetOptStat(0000);
	h_Data->SetLineColor(kRed);
	h_Data->SetLineWidth(3);
	h_Data->Draw("E1");
	h_Data->SetTitle("");
		
	h_Had->SetLineColor(kBlue);
	h_Had->SetLineWidth(4);
	h_Had->Draw("same E1");
	
	TLine *l_cut_met = new TLine(500,0,500,190000);
	l_cut_met->SetLineWidth(3);
	l_cut_met->Draw("same");
	
	Arrow3 = new TLatex(500,10000,"#rightarrow");
	Arrow3->SetTextSize(0.1);		
	Arrow3->Draw("same");	
	
	TLegend *infoBox = new TLegend(0.77, 0.8, 0.99, 0.99,"");//0.75, 0.83, 0.99, 0.99, "");
	infoBox->SetHeader("H_{T} comparison");

	infoBox->AddEntry(h_Data,"new analysis","lep");	
	infoBox->AddEntry(h_Had,"#gamma analysis with jets","lep");
	
  infoBox->SetShadowColor(0);  // 0 = transparent
  infoBox->SetFillColor(kWhite); 
	infoBox->SetTextSize(0.055);
  infoBox->Draw();

}
