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

int chi2(){

	double trigger_effi = 0.885339;
	double e_fakerate = 0.0148;
	int rebin = 1.;
//	string histo = "h_met_array";
//	string histo = "h_METoverSqHT_scale";
//	string histo = "h_METoverSqHT";
	string histo = "h_1tightPhotonPtOverMET_scale";

  TFile *Data  			= new TFile("PhotonParkedD_V06.1_sel.root");
	TFile *GJets	  	= new TFile("GJetsAdd.root");	
//	TFile *ZGamma 		= new TFile("ZGammaAdd.root");
//	TFile *WGamma 		= new TFile("WGamma_V02.1_sel.root");
  TFile *EWKBG 		= new TFile("EWKBG.root");
	TFile *GammaPixel	= new TFile("GammaPixel.root");	

	
	TH1F *	H_Data  	 = (TH1F*)Data->Get(histo.c_str());	
	TH1F *	H_GJets2    = (TH1F*)GJets->Get(histo.c_str());	
//	TH1F *	H_ZGamma   = (TH1F*)ZGamma->Get(histo.c_str());
//	TH1F *	H_WGamma	 = (TH1F*)WGamma->Get(histo.c_str());
  TH1F *	H_EWKBG	 = (TH1F*)EWKBG->Get(histo.c_str());
	TH1F *	H_GammaPixel = (TH1F*)GammaPixel->Get(histo.c_str());	
	
	H_GammaPixel->Scale(e_fakerate);
	
	H_GJets2->Scale(trigger_effi);
	H_EWKBG->Scale(trigger_effi);	
//	H_ZGamma->Add(H_WGamma);
		
	std::vector< TH1F* > GJetHistos;	
		
	TH2F *Chi2D = new TH2F("Chi2D", "2D Chi2 tests",26,0.45,3.05,26,0.45,3.05);
			
	TCanvas *canvas = new TCanvas("canvas","Plots",1000,700);
	TCanvas *canvas2 = new TCanvas("canvas2","Plots",1000,700);		
	TCanvas *canvas3 = new TCanvas("canvas3","Plots",1000,700);	
	TCanvas *canvas4 = new TCanvas("canvas4","Plots",1000,700);		
//Graph for chi^2-values
	canvas->Divide(4,7);	
	canvas2->Divide(4,7);
	canvas3->Divide(1,1);	
	canvas4->Divide(4,7);	
	
	
	string s_EWK05 = "EWK05";
	string s_EWK06 = "EWK06";	
	string s_EWK07 = "EWK07";	
	string s_EWK08 = "EWK08";	
	string s_EWK09 = "EWK09";	
	string s_EWK10 = "EWK10";
	string s_EWK11 = "EWK11";	
	string s_EWK12 = "EWK12";	
	string s_EWK13 = "EWK13";	
	string s_EWK14 = "EWK14";	
	string s_EWK15 = "EWK15";
	string s_EWK16 = "EWK16";	
	string s_EWK17 = "EWK17";	
	string s_EWK18 = "EWK18";	
	string s_EWK19 = "EWK19";	
	string s_EWK20 = "EWK20";	
	string s_EWK21 = "EWK21";	
	string s_EWK22 = "EWK22";	
	string s_EWK23 = "EWK23";	
	string s_EWK24 = "EWK24";
	string s_EWK25 = "EWK25";	
	string s_EWK26 = "EWK26";	
	string s_EWK27 = "EWK27";	
	string s_EWK28 = "EWK28";	
	string s_EWK29 = "EWK29";
	string s_EWK30 = "EWK30";		
	
	string s_GJets = "GJets";	
		
	for ( int i = 1; i < 27; i++) { 	
//	canvas->Update();
	std::string s;
	std::stringstream out;
	out << i;
	s = out.str();	
	s_GJets.append(s);
		
	TH1F *resi = new TH1F("resi", "resis",16,0,16);			
	TH1F *H_GJets = (TH1F*)H_GJets2->Clone(s_GJets.c_str());	
	
	H_GJets->Scale((0.4 + i*0.1));
	GJetHistos.push_back(H_GJets);	
	
//	string s_EWK05 = "EWK05";
//	s_EWK05.append(i+"");

	Double_t chi2[26], x[26], res[17];	  
	
/*	TH1F *EWK05 = (TH1F*)H_ZGamma->Clone(s_EWK05.c_str());
	
//	cout << "string" << s_EWK05.c_str() << endl;	
	TH1F *EWK06 = (TH1F*)H_ZGamma->Clone("EWK06");
	TH1F *EWK07 = (TH1F*)H_ZGamma->Clone("EWK07");	
	TH1F *EWK08 = (TH1F*)H_ZGamma->Clone("EWK08");	
	TH1F *EWK09 = (TH1F*)H_ZGamma->Clone("EWK09");			
	TH1F *EWK10 = (TH1F*)H_ZGamma->Clone("EWK10");
	TH1F *EWK11 = (TH1F*)H_ZGamma->Clone("EWK11");	
	TH1F *EWK12 = (TH1F*)H_ZGamma->Clone("EWK12");	
	TH1F *EWK13 = (TH1F*)H_ZGamma->Clone("EWK13");	
	TH1F *EWK14 = (TH1F*)H_ZGamma->Clone("EWK14");	
	TH1F *EWK15 = (TH1F*)H_ZGamma->Clone("EWK15");	
	TH1F *EWK16 = (TH1F*)H_ZGamma->Clone("EWK16");
	TH1F *EWK17 = (TH1F*)H_ZGamma->Clone("EWK17");	
	TH1F *EWK18 = (TH1F*)H_ZGamma->Clone("EWK18");	
	TH1F *EWK19 = (TH1F*)H_ZGamma->Clone("EWK19");	
	TH1F *EWK20 = (TH1F*)H_ZGamma->Clone("EWK20");
	TH1F *EWK21 = (TH1F*)H_ZGamma->Clone("EWK21");	
	TH1F *EWK22 = (TH1F*)H_ZGamma->Clone("EWK22");	
	TH1F *EWK23 = (TH1F*)H_ZGamma->Clone("EWK23");	
	TH1F *EWK24 = (TH1F*)H_ZGamma->Clone("EWK24");	
	TH1F *EWK25 = (TH1F*)H_ZGamma->Clone("EWK25");	
	TH1F *EWK26 = (TH1F*)H_ZGamma->Clone("EWK26");
	TH1F *EWK27 = (TH1F*)H_ZGamma->Clone("EWK27");	
	TH1F *EWK28 = (TH1F*)H_ZGamma->Clone("EWK28");	
	TH1F *EWK29 = (TH1F*)H_ZGamma->Clone("EWK29");	
	TH1F *EWK30 = (TH1F*)H_ZGamma->Clone("EWK30"); */	

  s_EWK05.append(s);
  s_EWK06.append(s);	
  s_EWK07.append(s);	
  s_EWK08.append(s);	
  s_EWK09.append(s);	
  s_EWK10.append(s);	
  s_EWK11.append(s);	
  s_EWK12.append(s);
  s_EWK13.append(s);	
  s_EWK14.append(s);	
  s_EWK15.append(s);	
  s_EWK16.append(s);	
  s_EWK17.append(s);	
  s_EWK18.append(s);	
  s_EWK19.append(s);
  s_EWK20.append(s);	
  s_EWK21.append(s);	
  s_EWK22.append(s);	
  s_EWK23.append(s);	
  s_EWK24.append(s);	
  s_EWK25.append(s);
  s_EWK26.append(s);	
  s_EWK27.append(s);	
  s_EWK28.append(s);	
  s_EWK29.append(s);	
  s_EWK30.append(s);	
		
	TH1F *EWK05 = (TH1F*)H_EWKBG->Clone(s_EWK05.c_str());
	TH1F *EWK06 = (TH1F*)H_EWKBG->Clone(s_EWK06.c_str());
	TH1F *EWK07 = (TH1F*)H_EWKBG->Clone(s_EWK07.c_str());	
	TH1F *EWK08 = (TH1F*)H_EWKBG->Clone(s_EWK08.c_str());	
	TH1F *EWK09 = (TH1F*)H_EWKBG->Clone(s_EWK09.c_str());			
	TH1F *EWK10 = (TH1F*)H_EWKBG->Clone(s_EWK10.c_str());
	TH1F *EWK11 = (TH1F*)H_EWKBG->Clone(s_EWK11.c_str());	
	TH1F *EWK12 = (TH1F*)H_EWKBG->Clone(s_EWK12.c_str());	
	TH1F *EWK13 = (TH1F*)H_EWKBG->Clone(s_EWK13.c_str());	
	TH1F *EWK14 = (TH1F*)H_EWKBG->Clone(s_EWK14.c_str());	
	TH1F *EWK15 = (TH1F*)H_EWKBG->Clone(s_EWK15.c_str());	
	TH1F *EWK16 = (TH1F*)H_EWKBG->Clone(s_EWK16.c_str());
	TH1F *EWK17 = (TH1F*)H_EWKBG->Clone(s_EWK17.c_str());	
	TH1F *EWK18 = (TH1F*)H_EWKBG->Clone(s_EWK18.c_str());	
	TH1F *EWK19 = (TH1F*)H_EWKBG->Clone(s_EWK19.c_str());	
	TH1F *EWK20 = (TH1F*)H_EWKBG->Clone(s_EWK20.c_str());
	TH1F *EWK21 = (TH1F*)H_EWKBG->Clone(s_EWK21.c_str());	
	TH1F *EWK22 = (TH1F*)H_EWKBG->Clone(s_EWK22.c_str());	
	TH1F *EWK23 = (TH1F*)H_EWKBG->Clone(s_EWK23.c_str());	
	TH1F *EWK24 = (TH1F*)H_EWKBG->Clone(s_EWK24.c_str());	
	TH1F *EWK25 = (TH1F*)H_EWKBG->Clone(s_EWK25.c_str());	
	TH1F *EWK26 = (TH1F*)H_EWKBG->Clone(s_EWK26.c_str());
	TH1F *EWK27 = (TH1F*)H_EWKBG->Clone(s_EWK28.c_str());	
	TH1F *EWK28 = (TH1F*)H_EWKBG->Clone(s_EWK28.c_str());	
	TH1F *EWK29 = (TH1F*)H_EWKBG->Clone(s_EWK29.c_str());	
	TH1F *EWK30 = (TH1F*)H_EWKBG->Clone(s_EWK30.c_str());	
	
/*	EWK05->Sumw2();
	EWK06->Sumw2();
	EWK07->Sumw2();
	EWK08->Sumw2();
	EWK09->Sumw2();	
	EWK10->Sumw2();
	EWK11->Sumw2();
	EWK12->Sumw2();
	EWK13->Sumw2();	
	EWK14->Sumw2();
	EWK15->Sumw2();
	EWK16->Sumw2();
	EWK17->Sumw2();
	EWK18->Sumw2();
	EWK19->Sumw2();
	EWK20->Sumw2();
	EWK21->Sumw2();
	EWK22->Sumw2();
	EWK23->Sumw2();
	EWK24->Sumw2();	
	EWK25->Sumw2();
	EWK26->Sumw2();
	EWK27->Sumw2();
	EWK28->Sumw2();
	EWK29->Sumw2();
	EWK30->Sumw2();
	H_Data->Sumw2();*/

	EWK05->Scale( (0.5));	
	EWK06->Scale( (0.6));	
	EWK07->Scale((0.7));	
	EWK08->Scale((0.8));	
	EWK09->Scale((0.9));	
	EWK10->Scale((1.0));	
	EWK11->Scale((1.1));
	EWK12->Scale((1.2));	
	EWK13->Scale((1.3));		
	EWK14->Scale((1.4));	
	EWK15->Scale((1.5));	
	EWK16->Scale((1.6));	
	EWK17->Scale((1.7));	
	EWK18->Scale((1.8));	
	EWK19->Scale((1.9));	
	EWK20->Scale((2.0));
	EWK21->Scale((2.1));
	EWK22->Scale((2.2));	
	EWK23->Scale((2.3));		
	EWK24->Scale((2.4));	
	EWK25->Scale((2.5));	
	EWK26->Scale((2.6));	
	EWK27->Scale((2.7));	
	EWK28->Scale((2.8));	
	EWK29->Scale((2.9));	
	EWK30->Scale((3.0));	
	
	
	gStyle->SetTitleW(0.9);
	gStyle->SetTitleH(0.08);

	EWK05->Add(GJetHistos[i-1]);
	EWK06->Add(GJetHistos[i-1]);
	EWK07->Add(GJetHistos[i-1]);
	EWK08->Add(GJetHistos[i-1]);
	EWK09->Add(GJetHistos[i-1]);	 
  EWK10->Add(GJetHistos[i-1]);	
	EWK11->Add(GJetHistos[i-1]);
	EWK12->Add(GJetHistos[i-1]);	
	EWK13->Add(GJetHistos[i-1]);	
	EWK14->Add(GJetHistos[i-1]);
	EWK15->Add(GJetHistos[i-1]);
	EWK16->Add(GJetHistos[i-1]);
	EWK17->Add(GJetHistos[i-1]);
	EWK18->Add(GJetHistos[i-1]);
	EWK19->Add(GJetHistos[i-1]);
	EWK20->Add(GJetHistos[i-1]);	
	EWK21->Add(GJetHistos[i-1]);
	EWK22->Add(GJetHistos[i-1]);	
	EWK23->Add(GJetHistos[i-1]);	
	EWK24->Add(GJetHistos[i-1]);
	EWK25->Add(GJetHistos[i-1]);
	EWK26->Add(GJetHistos[i-1]);
	EWK27->Add(GJetHistos[i-1]);
	EWK28->Add(GJetHistos[i-1]);
	EWK29->Add(GJetHistos[i-1]);
	EWK30->Add(GJetHistos[i-1]);	
	
	
	EWK05->Add(H_GammaPixel);
	EWK06->Add(H_GammaPixel);
	EWK07->Add(H_GammaPixel);
	EWK08->Add(H_GammaPixel);
	EWK09->Add(H_GammaPixel);	
  EWK10->Add(H_GammaPixel);	
	EWK11->Add(H_GammaPixel);
	EWK12->Add(H_GammaPixel);	
	EWK13->Add(H_GammaPixel);	
	EWK14->Add(H_GammaPixel);
	EWK15->Add(H_GammaPixel);
	EWK16->Add(H_GammaPixel);
	EWK17->Add(H_GammaPixel);
	EWK18->Add(H_GammaPixel);
	EWK19->Add(H_GammaPixel);
	EWK20->Add(H_GammaPixel);	
	EWK21->Add(H_GammaPixel);
	EWK22->Add(H_GammaPixel);	
	EWK23->Add(H_GammaPixel);	
	EWK24->Add(H_GammaPixel);
	EWK25->Add(H_GammaPixel);
	EWK26->Add(H_GammaPixel);
	EWK27->Add(H_GammaPixel);
	EWK28->Add(H_GammaPixel);
	EWK29->Add(H_GammaPixel);
	EWK30->Add(H_GammaPixel);		
	
	//EWK30->SetAxisRange(0,70);	
	
/*	H_Data->Rebin(rebin);
	EWK10->Rebin(rebin);
	EWK11->Rebin(rebin);
	EWK12->Rebin(rebin);
	EWK13->Rebin(rebin);
	EWK14->Rebin(rebin);
	EWK15->Rebin(rebin);
	EWK16->Rebin(rebin);
	EWK17->Rebin(rebin);
	EWK18->Rebin(rebin);
	EWK19->Rebin(rebin);
	EWK20->Rebin(rebin); */

	cout << GJetHistos[i-1]->GetBinContent(14) << endl;	
	H_Data->Chi2Test(GJetHistos[i-1],"UW P",res);
	canvas4->Update();	
	canvas4->cd(i);
	for (int p = 0; p < 17; p++){
		resi->Fill(p,res[p]);
		}
		
	resi->Draw("E1 hist");
	cout << resi->GetBinContent(14) << endl;
	cout << "********" << endl;
	resi->GetYaxis()->SetTitleSize(0.1);
  resi->GetXaxis()->SetTitleSize(0.1);		
	resi->GetYaxis()->SetLabelSize(0.1);
	resi->GetXaxis()->SetLabelSize(0.1);		
/*	H_Data->Chi2Test(EWK05,"UW P CHI2/NDF",chi2[0]);
	H_Data->Chi2Test(EWK06,"UW P CHI2/NDF",chi2[1]);
	H_Data->Chi2Test(EWK07,"UW P CHI2/NDF",chi2[2]);
	H_Data->Chi2Test(EWK08,"UW P CHI2/NDF",chi2[3]);
	H_Data->Chi2Test(EWK09,"UW P CHI2/NDF",chi2[4]);	
	H_Data->Chi2Test(EWK10,"UW P CHI2/NDF",chi2[5]);
	H_Data->Chi2Test(EWK11,"UW P CHI2/NDF",chi2[6]);
	H_Data->Chi2Test(EWK12,"UW P CHI2/NDF",chi2[7]);
	H_Data->Chi2Test(EWK13,"UW P CHI2/NDF",chi2[8]);
	H_Data->Chi2Test(EWK14,"UW P CHI2/NDF",chi2[9]);
	H_Data->Chi2Test(EWK15,"UW P CHI2/NDF",chi2[10]);
	H_Data->Chi2Test(EWK16,"UW P CHI2/NDF",chi2[11]);
	H_Data->Chi2Test(EWK17,"UW P CHI2/NDF",chi2[12]);
	H_Data->Chi2Test(EWK18,"UW P CHI2/NDF",chi2[13]);
	H_Data->Chi2Test(EWK19,"UW P CHI2/NDF",chi2[14]);
	H_Data->Chi2Test(EWK20,"UW P CHI2/NDF",chi2[15]);
	H_Data->Chi2Test(EWK21,"UW P CHI2/NDF",chi2[16]);
	H_Data->Chi2Test(EWK22,"UW P CHI2/NDF",chi2[17]);
	H_Data->Chi2Test(EWK23,"UW P CHI2/NDF",chi2[18]);
	H_Data->Chi2Test(EWK24,"UW P CHI2/NDF",chi2[19]);
	H_Data->Chi2Test(EWK25,"UW P CHI2/NDF",chi2[20]);
	H_Data->Chi2Test(EWK26,"UW P CHI2/NDF",chi2[21]);
	H_Data->Chi2Test(EWK27,"UW P CHI2/NDF",chi2[22]);
	H_Data->Chi2Test(EWK28,"UW P CHI2/NDF",chi2[23]);
	H_Data->Chi2Test(EWK29,"UW P CHI2/NDF",chi2[24]);
	H_Data->Chi2Test(EWK30,"UW P CHI2/NDF",chi2[25]); */


	for ( int l = 1; l < 17; l++) { 
		cout << "data: "<< H_Data->GetBinContent(l) << "   BG: "<< EWK05->GetBinContent(l) << "   error_data: "<< H_Data->GetBinError(l)<< "   error_BG: "<<
		H_Data->GetBinError(l) << endl;
		}

	canvas->cd(i);
	chi2[0] = H_Data->Chi2Test(EWK05,"UW P CHI2/NDF");
	chi2[1] = H_Data->Chi2Test(EWK06,"UW P CHI2/NDF");
	chi2[2] = H_Data->Chi2Test(EWK07,"UW P CHI2/NDF");
	chi2[3] = H_Data->Chi2Test(EWK08,"UW P CHI2/NDF");
	chi2[4] = H_Data->Chi2Test(EWK09,"UW P CHI2/NDF");	
	chi2[5] = H_Data->Chi2Test(EWK10,"UW P CHI2/NDF");
	chi2[6] = H_Data->Chi2Test(EWK11,"UW P CHI2/NDF");
	chi2[7] = H_Data->Chi2Test(EWK12,"UW P CHI2/NDF");
	chi2[8] = H_Data->Chi2Test(EWK13,"UW P CHI2/NDF");
	chi2[9] = H_Data->Chi2Test(EWK14,"UW P CHI2/NDF");
	chi2[10] = H_Data->Chi2Test(EWK15,"UW P CHI2/NDF");
	chi2[11] = H_Data->Chi2Test(EWK16,"UW P CHI2/NDF");
	chi2[12] = H_Data->Chi2Test(EWK17,"UW P CHI2/NDF");
	chi2[13] = H_Data->Chi2Test(EWK18,"UW P CHI2/NDF");
	chi2[14] = H_Data->Chi2Test(EWK19,"UW P CHI2/NDF");
	chi2[15] = H_Data->Chi2Test(EWK20,"UW P CHI2/NDF");
	chi2[16] = H_Data->Chi2Test(EWK21,"UW P CHI2/NDF");
	chi2[17] = H_Data->Chi2Test(EWK22,"UW P CHI2/NDF");
	chi2[18] = H_Data->Chi2Test(EWK23,"UW P CHI2/NDF");
	chi2[19] = H_Data->Chi2Test(EWK24,"UW P CHI2/NDF");
	chi2[20] = H_Data->Chi2Test(EWK25,"UW P CHI2/NDF");
	chi2[21] = H_Data->Chi2Test(EWK26,"UW P CHI2/NDF");
	chi2[22] = H_Data->Chi2Test(EWK27,"UW P CHI2/NDF");
	chi2[23] = H_Data->Chi2Test(EWK28,"UW P CHI2/NDF");
	chi2[24] = H_Data->Chi2Test(EWK29,"UW P CHI2/NDF");
	chi2[25] = H_Data->Chi2Test(EWK30,"UW P CHI2/NDF");	
	

	
	
/*	chi2[0] = H_Data->Chi2Test(EWK05,"UU P  CHI2/NDF");
	chi2[1] = H_Data->Chi2Test(EWK06,"UU P  CHI2/NDF");
	chi2[2] = H_Data->Chi2Test(EWK07,"UU P  CHI2/NDF");
	chi2[3] = H_Data->Chi2Test(EWK08,"UU P  CHI2/NDF");
	chi2[4] = H_Data->Chi2Test(EWK09,"UU P  CHI2/NDF");	
	chi2[5] = H_Data->Chi2Test(EWK10,"UU P  CHI2/NDF");
	chi2[6] = H_Data->Chi2Test(EWK11,"UU P  CHI2/NDF");
	chi2[7] = H_Data->Chi2Test(EWK12,"UU P  CHI2/NDF");
	chi2[8] = H_Data->Chi2Test(EWK13,"UU P  CHI2/NDF");
	chi2[9] = H_Data->Chi2Test(EWK14,"UU P  CHI2/NDF");
	chi2[10] = H_Data->Chi2Test(EWK15,"UU P  CHI2/NDF");
	chi2[11] = H_Data->Chi2Test(EWK16,"UU P  CHI2/NDF");
	chi2[12] = H_Data->Chi2Test(EWK17,"UU P  CHI2/NDF");
	chi2[13] = H_Data->Chi2Test(EWK18,"UU P  CHI2/NDF");
	chi2[14] = H_Data->Chi2Test(EWK19,"UU P  CHI2/NDF");
	chi2[15] = H_Data->Chi2Test(EWK20,"UU P  CHI2/NDF");
	chi2[16] = H_Data->Chi2Test(EWK21,"UU P  CHI2/NDF");
	chi2[17] = H_Data->Chi2Test(EWK22,"UU P  CHI2/NDF");
	chi2[18] = H_Data->Chi2Test(EWK23,"UU P  CHI2/NDF");
	chi2[20] = H_Data->Chi2Test(EWK25,"UU P  CHI2/NDF");
	chi2[19] = H_Data->Chi2Test(EWK24,"UU P  CHI2/NDF");
	chi2[21] = H_Data->Chi2Test(EWK26,"UU P  CHI2/NDF");
	chi2[22] = H_Data->Chi2Test(EWK27,"UU P  CHI2/NDF");
	chi2[23] = H_Data->Chi2Test(EWK28,"UU P  CHI2/NDF");
	chi2[24] = H_Data->Chi2Test(EWK29,"UU P  CHI2/NDF");
	chi2[25] = H_Data->Chi2Test(EWK30,"UU P  CHI2/NDF");	*/
	
/*	chi2[0] = H_Data->Chi2Test(EWK05,"WW P CHI2/NDF");
	chi2[1] = H_Data->Chi2Test(EWK06,"WW P CHI2/NDF");
	chi2[2] = H_Data->Chi2Test(EWK07,"WW P CHI2/NDF");
	chi2[3] = H_Data->Chi2Test(EWK08,"WW P CHI2/NDF");
	chi2[4] = H_Data->Chi2Test(EWK09,"WW P CHI2/NDF");	
	chi2[5] = H_Data->Chi2Test(EWK10,"WW P CHI2/NDF");
	chi2[6] = H_Data->Chi2Test(EWK11,"WW P CHI2/NDF");
	chi2[7] = H_Data->Chi2Test(EWK12,"WW P CHI2/NDF");
	chi2[8] = H_Data->Chi2Test(EWK13,"WW P CHI2/NDF");
	chi2[9] = H_Data->Chi2Test(EWK14,"WW P CHI2/NDF");
	chi2[10] = H_Data->Chi2Test(EWK15,"WW P CHI2/NDF");
	chi2[11] = H_Data->Chi2Test(EWK16,"WW P CHI2/NDF");
	chi2[12] = H_Data->Chi2Test(EWK17,"WW P CHI2/NDF");
	chi2[13] = H_Data->Chi2Test(EWK18,"WW P CHI2/NDF");
	chi2[14] = H_Data->Chi2Test(EWK19,"WW P CHI2/NDF");
	chi2[15] = H_Data->Chi2Test(EWK20,"WW P CHI2/NDF");
	chi2[16] = H_Data->Chi2Test(EWK21,"WW P CHI2/NDF");
	chi2[17] = H_Data->Chi2Test(EWK22,"WW P CHI2/NDF");
	chi2[18] = H_Data->Chi2Test(EWK23,"WW P CHI2/NDF");
	chi2[19] = H_Data->Chi2Test(EWK24,"WW P CHI2/NDF");
	chi2[20] = H_Data->Chi2Test(EWK25,"WW P CHI2/NDF");
	chi2[21] = H_Data->Chi2Test(EWK26,"WW P CHI2/NDF");
	chi2[22] = H_Data->Chi2Test(EWK27,"WW P CHI2/NDF");
	chi2[23] = H_Data->Chi2Test(EWK28,"WW P CHI2/NDF");
	chi2[24] = H_Data->Chi2Test(EWK29,"WW P CHI2/NDF");
	chi2[25] = H_Data->Chi2Test(EWK30,"WW P CHI2/NDF");	 */
	
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
	
	EWK05->Draw("hist E1 same");
	EWK05->SetLineColor(kAzure);
	EWK06->Draw("hist E1 same");
	EWK06->SetLineColor(kCyan);
	EWK07->Draw("hist E1 same");
	EWK07->SetLineColor(kTeal);
	EWK08->Draw("hist E1 same");
	EWK08->SetLineColor(kGreen);
	EWK09->Draw("hist E1 same");
	EWK09->SetLineColor(kSpring);		
	EWK10->Draw("hist E1 same");
	EWK10->SetLineColor(kRed);
	EWK11->Draw("hist E1 same");
	EWK11->SetLineColor(kPink);
	EWK12->Draw("hist E1 same");
	EWK12->SetLineColor(kMagenta);
	EWK13->Draw("hist E1 same");
	EWK13->SetLineColor(kViolet);	
	EWK14->Draw("hist E1 same");
	EWK14->SetLineColor(kBlue);
	EWK15->Draw("hist E1 same");
	EWK15->SetLineColor(kAzure);
	EWK16->Draw("hist E1 same");
	EWK16->SetLineColor(kCyan);
	EWK17->Draw("hist E1 same");
	EWK17->SetLineColor(kTeal);
	EWK18->Draw("hist E1 same");
	EWK18->SetLineColor(kGreen);
	EWK19->Draw("hist E1 same");
	EWK19->SetLineColor(kSpring);	
	EWK20->Draw("hist E1 same");
	EWK20->SetLineColor(kYellow);
	EWK21->Draw("hist E1 same");
	EWK21->SetLineColor(kPink);
	EWK22->Draw("hist E1 same");
	EWK22->SetLineColor(kMagenta);
	EWK23->Draw("hist E1 same");
	EWK23->SetLineColor(kViolet);	
	EWK24->Draw("hist E1 same");
	EWK24->SetLineColor(kBlue);
	EWK25->Draw("hist E1 same");
	EWK25->SetLineColor(kAzure);
	EWK26->Draw("hist E1 same");
	EWK26->SetLineColor(kCyan);
	EWK27->Draw("hist E1 same");
	EWK27->SetLineColor(kTeal);
	EWK28->Draw("hist E1 same");
	EWK28->SetLineColor(kGreen);
	EWK29->Draw("hist E1 same");
	EWK29->SetLineColor(kSpring);	
	EWK30->Draw("hist E1 same");
	EWK30->SetLineColor(kYellow);	
	
			
//	H_GJets->Draw("same hist");
//	H_GJets->SetFillStyle(1001);
//	H_GJets->SetFillColor(kOrange);

	GJetHistos[i-1]->Draw("same E1 hist");
	GJetHistos[i-1]->SetFillStyle(1001);	
	GJetHistos[i-1]->SetFillColor(kOrange);	
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
	canvas2->cd(i);
	for (int j=0; j<26; j++){
	  x[j]= 0.5 + j*0.1;
	  }
	cout << "  -------------------------------------------" << endl;		
	TGraph *chi2_graph = new TGraph(26,x,chi2);
	chi2_graph->GetXaxis()->SetRangeUser(0.4,3.1);
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
	chi2_graph->GetXaxis()->SetTitleOffset(0.25);
		
	chi2_graph->SetTitle("#chi^{2} distribution for scale factor");
	//chi2_graph->SetTitleSize(0.1);	
	gStyle->SetOptStat(0);
	chi2_graph->Draw("AP");	
//Fit a parable
	cout << "  -------------------------------------------" << endl;
  cout << " Fit" << endl;
	cout << "  -------------------------------------------" << endl;	
	TF1 *parable = new TF1("parable","[0]+[1]*pow(x-[2],2)",0.1,3.5);
	parable->SetParName(0,"offset_y_m");
	parable->SetParName(1,"factor_m");
	parable->SetParName(2,"offset_x_m");
	parable->SetParameter(0,1);
	parable->SetParameter(1,1);
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
	
	canvas3->cd(1);
	
	for (int k = 0; k < 26; k++) {
				Chi2D->Fill((0.4 + i*0.1),x[k],chi2[k]);
				}
				
				
/*	delete EWK05;
	delete EWK06;	
	delete EWK07;	
	delete EWK08;	
	delete EWK09;	
	delete EWK10;	
	delete EWK11;
	delete EWK12;	
	delete EWK13;		
	delete EWK14;	
  delete EWK15;	
	delete EWK16;	
	delete EWK17;	
	delete EWK18;	
	delete EWK19;	
	delete EWK20;
	delete EWK21;
	delete EWK22;	
	delete EWK23;		
	delete EWK24;	
	delete EWK25;	
	delete EWK26;	
	delete EWK27;	
	delete EWK28;	
	delete EWK29;	
	delete EWK30;			*/
		}	
	Chi2D->SetMarkerStyle(8);
	Chi2D->SetMarkerColor(kBlack);
	Chi2D->SetLineColor(kBlack);				
	Chi2D->Draw("colz");
	
	}
