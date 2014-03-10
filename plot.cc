#include <string.h>
#include "TFile.h"
#include "TH1.h"
#include "TH1F.h"
#include "TKey.h"
#include "Riostream.h"
#include "TCanvas.h"
#include "TPad.h"
#include "TSystem.h"
#include "TLegend.h"
#include "THStack.h"
#include "TStyle.h"
#include <map>
#include <vector>
#include <list>
#include <algorithm>

// Accesable everywhere
TObject *obj;
TFile   *sourceFile1, *sourceFile2, *sourceFile3,  *sourceFile4,
				*sourceFile5, *sourceFile6, *sourceFile7,  *sourceFile8,
				*sourceFile9, *sourceFile10, *sourceFile11,  *sourceFile12,
				*sourceFile13, *sourceFile14, *sourceFile15, *sourceFile16, 
				*sourceFile17, *sourceFile18, *sourceFile19;

TString outputFolder,outputFilename;
TCanvas *canvasDefault;

bool showStatsBoxes;
bool seperated = false;
bool GJetsPt = false;
// *******************************************
// Variables
TString imageType = "pdf";
int outputWidth   = 960;
int outputHeight  = 720;
bool showStats = false;
double weight = 1.;
double rebin = 1.;
double efficiency = 0.885339;
double e_Fakerate = 0.0148;
//double scale_ISR = 1.99563;
//double scale_GJets = 2.05726;
double scale_ISR = 1.70597;
double scale_GJets = 2.34293;

std::map < int , TH1F* > order;


// End of Variables
// *******************************************
//TString fileName1 = "PhotonParkedD_V06.1__20_sel.root";
TString fileName1 = "PhotonParkedD_V06.1_sel.root";
//TString fileName1 = "PhotonHadD_V02.1_sel.root";
TString fileName2 = "TTJets_V02.1_sel.root"; // higher order
//TString fileName3 = "ZGamma_V02.1_sel.root";
TString fileName3 = "ZGammaAdd.root";
//TString fileName17 = "ZGammaNuNu_V02.1_sel.root";
// TString fileName4 = "WJets_V02.1_sel.root";
TString fileName4 = "WGamma_V02.1_sel.root";
TString fileName5 = "QCD_100_250_V06.1_sel.root";
TString fileName6 = "QCD_250_500_V02.1_sel.root";
TString fileName7 = "QCD_500_1000_V02.1_sel.root";
TString fileName8 = "QCD_1000_inf_V02.1_sel.root";
TString fileName9 = "GJets_40_100_V06.1_sel.root";
TString fileName10 = "GJets_100_200_V02.1_sel.root";
TString fileName11 = "GJets_200_400_V02.1_sel.root";
TString fileName12 = "GJets_400_inf_V02.1_sel.root";
TString fileName13 = "WW_incl_V06.1_sel.root";
TString fileName14 = "WZ_incl_V06.1_sel.root";
TString fileName15 = "ZZ_incl_V06.1_sel.root";
TString fileName16 = "signal_540_530.root";
TString fileName18 = "signal_540_480.root";
TString fileName17 = "signal_640_630.root";

TString fileName19 = "GammaPixel.root";
//TString fileName19 = "signal_640_630.root";
/*TString fileName18 = "G_30_50_V07.1_sel.root";
TString fileName19 = "G_50_80_V07.1_sel.root";
TString fileName20 = "G_80_120_V07.1_sel.root";
TString fileName21 = "G_120_170_V07.1_sel.root";
TString fileName22 = "G_170_300_V07.1_sel.root";
TString fileName23 = "G_300_470_V07.1_sel.root";
TString fileName24 = "G_470_800_V07.1_sel.root";
TString fileName25 = "G_800_1400_V07.1_sel.root";
TString fileName26 = "G_1400_1800_V07.1_sel.root";
TString fileName27 = "G_1800_V07.1_sel.root";
TString fileName28 = "G_0_15_V07.1_sel.root";
TString fileName29 = "G_15_30_V07.1_sel.root"; */

TString    fileLabel1 = fileName1;
TString    fileLabel2 = fileName2;
TString    fileLabel3 = fileName3;
TString    fileLabel4 = fileName4;		
TString    fileLabel5 = fileName5;
TString    fileLabel6 = fileName6;		
TString    fileLabel7 = fileName7;
TString    fileLabel8 = fileName8;		
TString    fileLabel9 = fileName9;
TString    fileLabel10 = fileName10;		
TString    fileLabel11 = fileName11;		
TString    fileLabel12 = fileName12;
TString    fileLabel13 = fileName13;		
TString    fileLabel14 = fileName14;		
TString    fileLabel15 = fileName15;
TString    fileLabel16 = fileName16;
TString    fileLabel17 = fileName17;
TString    fileLabel18 = fileName18;
TString    fileLabel19 = fileName19;
/*TString    fileLabel18 = fileName18;		
TString    fileLabel19 = fileName19;
TString    fileLabel20 = fileName20;		
TString    fileLabel21 = fileName21;		
TString    fileLabel22 = fileName22;
TString    fileLabel23 = fileName23;		
TString    fileLabel24 = fileName24;		
TString    fileLabel25 = fileName25;
TString    fileLabel26 = fileName26;
TString    fileLabel27 = fileName27;
TString    fileLabel28 = fileName28;
TString    fileLabel29 = fileName29; */
		
bool compare(TH1F* x, TH1F* y){
	
	//return (x < y);
	return( x->Integral() < y->Integral() );
	
	}
	

void plotHistograms(TH1F* htemp1, TH1F* htemp2, TH1F* htemp3, TH1F* htemp4, TH1F* htemp5, TH1F* htemp6, TH1F* htemp7, TH1F* htemp8, TH1F* htemp9, TH1F* htemp10, TH1F*
htemp11, TH1F* htemp12, TH1F* htemp13, TH1F* htemp14, TH1F* htemp15, TH1F* htemp16,TH1F* htemp17, TH1F* htemp18, TH1F* htemp19, TString filename) {// {TH1F* htemp18, TH1F* htemp19, TH1F* htemp20, TH1F*
//htemp21, TH1F* htemp22, TH1F* htemp23, TH1F* htemp24, TH1F* htemp25, TH1F* htemp26, TH1F* htemp27, TH1F* htemp28, TH1F* htemp29, TString filename) {

  //TString title = htemp1->GetName();
  TString title = htemp1->GetTitle();

  // Make sure histograms exist
  if ( !htemp2 || !htemp3 ||!htemp4 || !htemp5 || !htemp6 ||!htemp7 ||!htemp8 || !htemp9 ||!htemp10 ||!htemp11 || !htemp12 ||!htemp13 ||!htemp14 || !htemp15
	||!htemp16 ||!htemp17 ||!htemp18 ||!htemp19) { //||!htemp18 || !htemp19 ||!htemp20 ||!htemp21 || !htemp22 ||!htemp23 ||!htemp24 || !htemp25
//	||!htemp26 ||!htemp27 ||!htemp28 ||!htemp29) {
    cout << "Histogram missing from a file: " << htemp1->GetName() << endl;
    return;
  } 
// htemp2 = ttbar is NNLO and htemp13 = WW is NLO

 htemp3->Scale(scale_ISR);
 htemp4->Scale(scale_ISR);
 htemp5->Scale(weight);
 htemp6->Scale(weight);
 htemp7->Scale(weight);
 htemp8->Scale(weight);
 htemp9->Scale(scale_GJets);
 htemp10->Scale(scale_GJets);
 htemp11->Scale(scale_GJets);
 htemp12->Scale(scale_GJets);
 htemp14->Scale(weight);
 htemp15->Scale(weight);
 htemp16->Scale(weight);
 htemp17->Scale(weight);
 htemp18->Scale(weight);
 
 htemp19->Scale(e_Fakerate); 
/* htemp19->Scale(weight);
 htemp20->Scale(weight);
 htemp21->Scale(weight);
 htemp22->Scale(weight);
 htemp23->Scale(weight); 
 htemp24->Scale(weight);
 htemp25->Scale(weight);
 htemp26->Scale(weight);
 htemp27->Scale(weight);  
 htemp28->Scale(weight);
 htemp29->Scale(weight); */
 
 htemp2->Scale(efficiency); 
 htemp3->Scale(efficiency);
 htemp4->Scale(efficiency);
 htemp5->Scale(efficiency);
 htemp6->Scale(efficiency);
 htemp7->Scale(efficiency);
 htemp8->Scale(efficiency);
 htemp9->Scale(efficiency);
 htemp10->Scale(efficiency);
 htemp11->Scale(efficiency);
 htemp12->Scale(efficiency);
 htemp13->Scale(efficiency); 
 htemp14->Scale(efficiency);
 htemp15->Scale(efficiency); 
 htemp16->Scale(efficiency); 
 htemp17->Scale(efficiency);  
 htemp18->Scale(efficiency);
/* htemp19->Scale(efficiency);
 htemp20->Scale(efficiency);
 htemp21->Scale(efficiency);
 htemp22->Scale(efficiency);
 htemp23->Scale(efficiency); 
 htemp24->Scale(efficiency);
 htemp25->Scale(efficiency);
 htemp26->Scale(efficiency);
 htemp27->Scale(efficiency); 
 htemp28->Scale(efficiency);
 htemp29->Scale(efficiency); */

 
 htemp1->Rebin(rebin);
 htemp2->Rebin(rebin);
 htemp3->Rebin(rebin);
 htemp4->Rebin(rebin);
 htemp5->Rebin(rebin);
 htemp6->Rebin(rebin);
 htemp7->Rebin(rebin);
 htemp8->Rebin(rebin);
 htemp9->Rebin(rebin);
 htemp10->Rebin(rebin);
 htemp11->Rebin(rebin);
 htemp12->Rebin(rebin);
 htemp13->Rebin(rebin); 
 htemp14->Rebin(rebin);
 htemp15->Rebin(rebin); 
 htemp16->Rebin(rebin);
 htemp17->Rebin(rebin); 
 htemp18->Rebin(rebin);
 htemp19->Rebin(rebin);
/* htemp20->Rebin(rebin);
 htemp21->Rebin(rebin);
 htemp22->Rebin(rebin);
 htemp23->Rebin(rebin); 
 htemp24->Rebin(rebin);
 htemp25->Rebin(rebin); 
 htemp26->Rebin(rebin); 
 htemp27->Rebin(rebin); 
 htemp28->Rebin(rebin); 
 htemp29->Rebin(rebin); */


  // Set the histogram colors & lines
	htemp1	->SetLineColor(kBlack);
  htemp1	->SetMarkerStyle(8);
	htemp2  ->SetFillColor(kRed);
	htemp2  ->SetLineColor(kBlack);
	htemp2	->SetLineWidth(1);	
	htemp2	->SetFillStyle(1001);
	htemp3  ->SetFillColor(kGreen);
	htemp3	->SetFillStyle(1001);
	htemp3  ->SetLineColor(kBlack);	
	htemp3	->SetLineWidth(1);	
//	htemp17 ->SetFillColor(kGreen);
//	htemp17	->SetFillStyle(1001);	
//	htemp4  ->SetFillColor(kCyan);
	htemp4  ->SetFillColor(kGreen);
	htemp4	->SetFillStyle(1001);
	htemp4  ->SetLineColor(kBlack);
	htemp4	->SetLineWidth(1);	
	htemp19 ->SetFillColor(kGray+2);
	htemp19	->SetFillStyle(1001);	
	htemp16	->SetLineColor(kBlue+4);
	htemp16	->SetLineWidth(2);	
	htemp16	->SetLineColor(kBlue+4);
	htemp16	->SetLineWidth(3);	
	htemp17	->SetLineColor(kAzure); //(kPink-7);
	htemp17	->SetLineWidth(3);
	htemp18	->SetLineColor(kRed+3);
	htemp18	->SetLineWidth(3);
				
	if ( seperated ) {
  	htemp9	->SetFillColor(kOrange-7);
		htemp9	->SetFillStyle(1001);		
	  htemp10	->SetFillColor(kOrange+3);
		htemp10	->SetFillStyle(1001);	
		htemp11  ->SetFillColor(kOrange-3);
		htemp11	->SetFillStyle(1001);	
		htemp12  ->SetFillColor(kYellow);
		htemp12	->SetFillStyle(1001);	
		htemp13	->SetFillColor(kMagenta);
		htemp13	->SetFillStyle(1001);	
		htemp14  ->SetFillColor(kMagenta+3);
		htemp14	->SetFillStyle(1001);	
		htemp15  ->SetFillColor(kMagenta-3);
		htemp15	->SetFillStyle(1001);	
		htemp5  ->SetFillColor(kBlue-2);
		htemp5	->SetFillStyle(1001);	
		htemp6  ->SetFillColor(kBlue);
		htemp6	->SetFillStyle(1001);
		htemp7  ->SetFillColor(kBlue+2);
		htemp7	->SetFillStyle(1001);
		htemp8  ->SetFillColor(kBlue+4);
		htemp8	->SetFillStyle(1001);
		}
	else {
  	htemp9	->SetFillColor(kOrange);
		htemp9	->SetFillStyle(1001);		
		htemp9  ->SetLineColor(kBlack);	
  	htemp9	->SetLineWidth(1);	
	  htemp10	->SetFillColor(kOrange);
		htemp10	->SetFillStyle(1001);	
		htemp11  ->SetFillColor(kOrange);
		htemp11	->SetFillStyle(1001);	
		htemp12  ->SetFillColor(kOrange);
		htemp12	->SetFillStyle(1001);	
	  htemp13	->SetFillColor(kMagenta);
		htemp13	->SetFillStyle(1001);	
		htemp13  ->SetLineColor(kBlack);	
  	htemp13	->SetLineWidth(1);				
		htemp14  ->SetFillColor(kMagenta);
		htemp14	->SetFillStyle(1001);	
		htemp15  ->SetFillColor(kMagenta);
		htemp15	->SetFillStyle(1001);		
		htemp5  ->SetFillColor(kBlue);
		htemp5	->SetFillStyle(1001);	
		htemp5  ->SetLineColor(kBlack);	
  	htemp5	->SetLineWidth(1);		
		htemp6  ->SetFillColor(kBlue);
		htemp6	->SetFillStyle(1001);
		htemp7  ->SetFillColor(kBlue);
		htemp7	->SetFillStyle(1001);
		htemp8  ->SetFillColor(kBlue);
		htemp8	->SetFillStyle(1001);
 /* 	htemp18	->SetFillColor(kOrange);
		htemp18	->SetFillStyle(1001);		
  	htemp19	->SetFillColor(kOrange);
		htemp19	->SetFillStyle(1001);		
	  htemp20	->SetFillColor(kOrange);
		htemp20	->SetFillStyle(1001);	
		htemp21  ->SetFillColor(kOrange);
		htemp21	->SetFillStyle(1001);	
		htemp22  ->SetFillColor(kOrange);
		htemp22	->SetFillStyle(1001);		
  	htemp23	->SetFillColor(kOrange);
		htemp23	->SetFillStyle(1001);		
	  htemp24	->SetFillColor(kOrange);
		htemp24	->SetFillStyle(1001);	
		htemp25  ->SetFillColor(kOrange);
		htemp25	->SetFillStyle(1001);	
		htemp26  ->SetFillColor(kOrange);
		htemp26	->SetFillStyle(1001);		
		htemp27  ->SetFillColor(kOrange);
		htemp27	->SetFillStyle(1001);		
		htemp28  ->SetFillColor(kOrange);
		htemp28	->SetFillStyle(1001);		
		htemp29  ->SetFillColor(kOrange);
		htemp29	->SetFillStyle(1001);		*/	
		}
	



/*	list< TH1F* > BGs;	
		
if ( htemp2 != 0)	BGs.push_back(htemp2);
if ( htemp3 != 0)	BGs.push_back(htemp3);
if ( htemp4 != 0)	BGs.push_back(htemp4);
if ( htemp5 != 0)	BGs.push_back(htemp5);	
if ( htemp6 != 0)	BGs.push_back(htemp6);
if ( htemp7 != 0)	BGs.push_back(htemp7);	
if ( htemp8 != 0)	BGs.push_back(htemp8);
if ( htemp9 != 0)	BGs.push_back(htemp9);	
if ( htemp10 != 0)	BGs.push_back(htemp10);
if ( htemp11 != 0)	BGs.push_back(htemp11);	
if ( htemp12 != 0)	BGs.push_back(htemp12);
	
	
	sort(BGs.begin(),BGs.end(),compare);			
//	BGs.sort(compare);
	
	
  THStack *tempStack = new THStack();
if (BGs.size() != 0){	
	list< TH1F* >::iterator iter = BGs.begin();
		
	while (iter!= BGs.end()) {	
		tempStack->Add(*iter);
		}	
	}
/*	for ( i = 0; i < 12; i++ ) {
		order[i] = BGs[i]->Integral();
		} */
		
	std::map<TH1F*, std::string> histoname;
	std::vector< TH1F* > BGs;	
		
	if ( htemp2 != 0)	BGs.push_back(htemp2);
//	if ( htemp3 != 0)	BGs.push_back(htemp3);
//	if ( htemp17 != 0)	BGs.push_back(htemp17);	
//	if ( htemp4 != 0)	BGs.push_back(htemp4);
	if ( htemp19 != 0)	BGs.push_back(htemp19);	
	
	if ( seperated ) {
		if ( htemp5 != 0)	BGs.push_back(htemp5);	
		if ( htemp6 != 0)	BGs.push_back(htemp6);
		if ( htemp7 != 0)	BGs.push_back(htemp7);	
		if ( htemp8 != 0)	BGs.push_back(htemp8);
		if ( !GJetsPt) {
     if ( htemp9 != 0) BGs.push_back(htemp9);  
     if ( htemp10 != 0)  BGs.push_back(htemp10);
     if ( htemp11 != 0)  BGs.push_back(htemp11); 
     if ( htemp12 != 0)  BGs.push_back(htemp12);
     }
		if ( htemp13 != 0)	BGs.push_back(htemp13);
		if ( htemp14 != 0)	BGs.push_back(htemp14);	
		if ( htemp15 != 0)	BGs.push_back(htemp15);		
		histoname[htemp2] = fileLabel2;
		histoname[htemp3] = fileLabel3;
//		histoname[htemp17] = fileLabel17;		
		histoname[htemp4] = fileLabel4;	
		histoname[htemp5] = fileLabel5;	
		histoname[htemp6] = fileLabel6;	
		histoname[htemp7] = fileLabel7;
		histoname[htemp8] = fileLabel8;	
		histoname[htemp9] = fileLabel9;	
		histoname[htemp10] = fileLabel10;	
		histoname[htemp11] = fileLabel11;	
		histoname[htemp12] = fileLabel12;
		histoname[htemp13] = fileLabel13;	
		histoname[htemp14] = fileLabel14;	
		histoname[htemp15] = fileLabel15;		
		
	}
	else {
		htemp3->Add(htemp4);
		htemp5->Add(htemp6);
		htemp5->Add(htemp7);
		htemp5->Add(htemp8);
		htemp9->Add(htemp10);
		htemp9->Add(htemp11);
		htemp9->Add(htemp12);
		htemp9->Add(htemp5);  // Add QCD to GJets
		htemp13->Add(htemp14);
		htemp13->Add(htemp15);
/*		htemp18->Add(htemp19);
		htemp18->Add(htemp20);		
		htemp18->Add(htemp21);		
		htemp18->Add(htemp22);		
		htemp18->Add(htemp23);		
		htemp18->Add(htemp24);		
		htemp18->Add(htemp25);
		htemp18->Add(htemp26);		
		htemp18->Add(htemp27);	
		htemp18->Add(htemp28);		
		htemp18->Add(htemp29);		*/
									
	//	if ( htemp5 != 0)	BGs.push_back(htemp5);
		if ( !GJetsPt) {		
	  	if ( htemp9 != 0)	BGs.push_back(htemp9);
			}
		else {
		//  if ( htemp18 != 0)	BGs.push_back(htemp18);
			}
	 	if ( htemp13 != 0)	BGs.push_back(htemp13);		
	 	if ( htemp3 != 0)	BGs.push_back(htemp3);			
		histoname[htemp2] = fileLabel2;
		histoname[htemp3] = fileLabel3;
		histoname[htemp3] =  "#gamma ISR";		
//		histoname[htemp17] = fileLabel17;		
//		histoname[htemp4] = fileLabel4;	
		histoname[htemp5] = "QCD";	
		histoname[htemp9] = "GJets";
		histoname[htemp13] = "DiBoson";	
		histoname[htemp19] = "e->#gamma";		
	//	histoname[htemp18] = "GJets";			
		}
		
	std::sort(BGs.begin(), BGs.end(), compare );			

	
  THStack *tempStack = new THStack();
/*if (BGs.size() != 0){	
	vector< TH1F* >::iterator iter = BGs.begin();
		
	while (iter!= BGs.end()) {	
		tempStack->Add(*iter);
		}	
	}	 */
	
	for ( unsigned int i = 0; i < BGs.size(); i++) {
	  tempStack->Add(BGs[i]);
//		histoname[BGs[i]]
		}	
		

  // Turn off stats
  if (!showStatsBoxes) {
    gStyle->SetOptStat(0);
  }

//  THStack *tempStack = new THStack();

/*  tempStack->Add(htemp2);
  tempStack->Add(htemp3);	
  tempStack->Add(htemp4);	
  tempStack->Add(htemp5);
  tempStack->Add(htemp6);
  tempStack->Add(htemp7);	
  tempStack->Add(htemp8);
	tempStack->Add(htemp9);
  tempStack->Add(htemp10);
  tempStack->Add(htemp11);	
  tempStack->Add(htemp12); */
	
	
	TH1F *denumerator = (TH1F*)htemp2->Clone("denumerator");
  denumerator->Add(htemp3);	
//  denumerator->Add(htemp17);	
//  denumerator->Add(htemp4);  // WGamma in ZGamma combined
	denumerator->Add(htemp19);  //GammaPixel
	if ( seperated ) {	
 		denumerator->Add(htemp5);
 		denumerator->Add(htemp6);
  	denumerator->Add(htemp7);	
  	denumerator->Add(htemp8);
		denumerator->Add(htemp9);
  	denumerator->Add(htemp10);
  	denumerator->Add(htemp11);	
  	denumerator->Add(htemp12);
  	denumerator->Add(htemp13);
  	denumerator->Add(htemp14);	
  	denumerator->Add(htemp15);			
	  }
	else {
 	//	denumerator->Add(htemp5);	
 		denumerator->Add(htemp13);
		if ( !GJetsPt) {
			denumerator->Add(htemp9);
			}
		else {
		//	denumerator->Add(htemp18);
			}			
		}
		
	canvasDefault->cd();	
	canvasDefault->Clear();	
	
	TPad *canvasDefault_1 = new TPad("canvasDefault_1", "newpad",0.0,0.0,1.0,0.325);	

//  canvasDefault_1->Draw();
//  canvasDefault_1->cd();
  canvasDefault_1->SetTopMargin(0.01);
  canvasDefault_1->SetBottomMargin(0.3);
  canvasDefault_1->SetRightMargin(0.1);
  canvasDefault_1->SetFillStyle(0);
	
	TH1F *data = (TH1F*)htemp1->Clone("data");
	TH1F *numerator = (TH1F*)htemp1->Clone("numerator");
  canvasDefault_1->cd();
	numerator->Divide(denumerator);
	numerator->SetTitle("");
	numerator->SetMaximum(2.1);	
	numerator->SetMinimum(0.1);
//	numerator->Draw("AXIS");
	numerator->SetLineWidth(0);
	numerator->GetYaxis()->SetNdivisions(5);
//	TString *title = htemp1->GetXaxis()->GetTitle();
  numerator->GetYaxis()->SetTitle("ratio");
  numerator->GetYaxis()->CenterTitle();	
  numerator->GetYaxis()->SetTitleSize(0.1);
  numerator->GetXaxis()->SetTitleSize(0.1);		
	numerator->GetYaxis()->SetLabelSize(0.1);
	numerator->GetXaxis()->SetLabelSize(0.1);
  numerator->GetYaxis()->SetTitleOffset(0.4);		
	numerator->Draw("E1");
//	numerator->Draw();	
	gPad->SetGrid();
	gStyle->SetGridStyle(3);
	gStyle->SetPadTickX(1);
  gStyle->SetPadTickY(1);
  canvasDefault->cd();
  canvasDefault_1->Draw();	
	 
//	float defaultRatioYmin = 1.02;
 // float defaultRatioYmax = 0.60;
//	numerator->SetMinimum(defaultRatioYmin);
//  numerator->SetMaximum(defaultRatioYmax); 
//  numerator->GetYaxis()->SetNdivisions(5); 
	
	canvasDefault->cd();
  TPad *canvasDefault_2 = new TPad("canvasDefault_2", "newpad",0.0,0.32,1,1);
  canvasDefault_2->Draw(); 
  canvasDefault_2->cd();
  canvasDefault_2->SetTopMargin(0.1);
  canvasDefault_2->SetBottomMargin(0.01);
  canvasDefault_2->SetRightMargin(0.1);
  canvasDefault_1->SetFillStyle(0);
	
	
  // Draw the histogram and titles

	//data->SetLabelSize(0.05);
	data->GetXaxis()->SetTitleSize(0.05);
	data->GetXaxis()->SetLabelSize(0.05);	
	data->GetYaxis()->SetLabelSize(0.05);
	data->GetYaxis()->SetTitle("# events");
	data->GetYaxis()->SetTitleSize(0.05);
	data->SetMinimum(0.01);
	double max = htemp18->GetMaximum();
//	data->SetMaximum(max);
	data->Draw("AXIS X+");
	data->Draw("E1");
//	htemp19->Draw("same E1 h f");
  tempStack->Draw("same E1 h f X+");
	data->Draw("same E1");
		
	htemp18->Draw("same hist");	
	htemp17->Draw("same hist");
	htemp16->Draw("same hist");	
	//gPad->RedrawAxis();	
	data->GetXaxis()->SetTitle("");
//  tempStack->SetTitle(title);
 // tempStack->GetXaxis()->SetTitle(data->GetXaxis()->GetTitle());
//  tempStack->GetYaxis()->SetTitle("# events");
 // canvasDefault_2->Draw();	
	
  // Draw the legend
  TLegend *infoBox = new TLegend(0.7, 0.5, 0.9, 0.899,"");//0.75, 0.83, 0.99, 0.99, "");
  infoBox->AddEntry(htemp1,fileLabel1,"lep");	
	for ( int i = 0; i < BGs.size(); i++) {
		int size = BGs.size() - 1;
	  int reverse = size - i;
	  infoBox->AddEntry(BGs[reverse],histoname[BGs[reverse]].c_str() , "f"); 
		}	
  infoBox->AddEntry(htemp18,fileLabel18,"l");	
  infoBox->AddEntry(htemp16,fileLabel16,"l");	
  infoBox->AddEntry(htemp17,fileLabel17,"l");
  infoBox->SetFillStyle(0);	
  infoBox->SetShadowColor(0);  // 0 = transparent
  infoBox->SetFillColor(kWhite); 
	infoBox->SetBorderSize(0);
	infoBox->SetTextSize(0.042);
  infoBox->Draw();

  // Place the stats boxes to be non-overlapping
/*  if (showStatsBoxes) {
    canvasDefault->SetRightMargin(0.2);
    canvasDefault->Update();
    TPaveStats *st1 = (TPaveStats*)htemp1->GetListOfFunctions()->FindObject("stats"); 
    TPaveStats *st2 = (TPaveStats*)htemp2->GetListOfFunctions()->FindObject("stats");
    TPaveStats *st3 = (TPaveStats*)htemp3->GetListOfFunctions()->FindObject("stats"); 
    TPaveStats *st4 = (TPaveStats*)htemp4->GetListOfFunctions()->FindObject("stats");		
		
    st1->SetX1NDC(.79); st1->SetX2NDC(.99);
    st1->SetY1NDC(.6);  st1->SetY2NDC(.8);
    st2->SetX1NDC(.79); st2->SetX2NDC(.99);
    st2->SetY1NDC(.38); st2->SetY2NDC(.58);
    st3->SetX1NDC(.79); st1->SetX3NDC(.99);
    st3->SetY1NDC(.6);  st1->SetY3NDC(.8);
    st4->SetX1NDC(.79); st2->SetX4NDC(.99);
    st4->SetY1NDC(.38); st2->SetY4NDC(.58);		
		
		
    canvasDefault->Modified(); 
  } */

  // Set log y axis
  // Save the canvas 
	//canvasDefault->SetLogy(0);
	canvasDefault_2->SetLogy(0);
	canvasDefault->SaveAs(filename+"_lin."+imageType);
 // canvasDefault->SetLogy(1);
  canvasDefault_2->SetLogy(1);
	
	double stack_max = tempStack->GetMaximum();
	double data_max = data->GetMaximum();
	double signal_max = htemp18->GetMaximum();
	
	if ( data_max > stack_max ) {
		data->SetMinimum(0.01);
		data->Draw("AXIS X+");	
		data->Draw("E1 X+");
 	//  htemp19->Draw("same h f");			
 	  tempStack->Draw("h f X+");
		data->Draw("same E1");
		htemp18->Draw("same hist");			
		htemp17->Draw("same hist");
		htemp16->Draw("same hist");	
	//	gPad->RedrawAxis();
		
		}
	else if( data_max < stack_max){

	  tempStack->GetXaxis()->SetTitleSize(0.05);
	  tempStack->GetXaxis()->SetLabelSize(0.05);  
	  tempStack->GetYaxis()->SetLabelSize(0.05);
	  tempStack->GetYaxis()->SetTitle("# events");
	  tempStack->GetYaxis()->SetTitleSize(0.05); 
		tempStack->SetMinimum(0.01);
 	//  htemp19->Draw("h f");	
	  tempStack->Draw("h f X+");
		data->Draw("same AXIS X+");			
		data->Draw("same E1");			
		htemp18->Draw("same hist");			
		htemp17->Draw("same hist");
		htemp16->Draw("same hist");	
					
	//	gPad->RedrawAxis();
		}
	else if( signal_max > stack_max){

	  htemp18->GetXaxis()->SetTitleSize(0.05);
	  htemp18->GetXaxis()->SetLabelSize(0.05);  
	  htemp18->GetYaxis()->SetLabelSize(0.05);
	  htemp18->GetYaxis()->SetTitle("# events");
	  htemp18->GetYaxis()->SetTitleSize(0.05); 
		htemp18->SetMinimum(0.01);
 	//  htemp19->Draw("h f");	
	 htemp18 ->Draw("hist X+");
		data->Draw("same AXIS X+");			
	//	data->Draw("same E1");
	  tempStack->Draw("same h f X+");				
		htemp18->Draw("same hist");			
		htemp17->Draw("same hist");
		htemp16->Draw("same hist");	
					
	//	gPad->RedrawAxis();
		}		
	infoBox->Draw();
	canvasDefault->SaveAs(filename+"_log."+imageType);
}


void recurseOverKeys( TDirectory *target1 ) {

  // Figure out where we are
  TString path( (char*)strstr( target1->GetPath(), ":" ) );
  path.Remove( 0, 2 );

  sourceFile1->cd( path );
  
  TDirectory *current_sourcedir = gDirectory;

  TKey *key;
  TIter nextkey(current_sourcedir->GetListOfKeys());

  while ( key = (TKey*)nextkey() ) {

    obj = key->ReadObj();

    // Check if this is a 1D histogram or a directory
    if (obj->IsA()->InheritsFrom("TH1F")) {

      // **************************
      // Plot & Save this Histogram
      TH1F *htemp1, *htemp2, *htemp3, *htemp4, *htemp5, *htemp6, *htemp7, *htemp8, *htemp9, *htemp10, *htemp11, *htemp12, *htemp13, *htemp14, *htemp15,
			*htemp16, *htemp17, *htemp18, *htemp19;// *htemp18, *htemp19, *htemp20, *htemp21, *htemp22, *htemp23, *htemp24, *htemp25,
		//	*htemp26, *htemp27, *htemp28, *htemp29;

      htemp1 = (TH1F*)obj;
      TString histName = htemp1->GetName();

      if (path != "") {
        sourceFile2->GetObject(path+"/"+histName, htemp2);
        sourceFile3->GetObject(path+"/"+histName, htemp3);				
        sourceFile4->GetObject(path+"/"+histName, htemp4);
        sourceFile5->GetObject(path+"/"+histName, htemp5);
        sourceFile6->GetObject(path+"/"+histName, htemp6);				
        sourceFile7->GetObject(path+"/"+histName, htemp7);				
        sourceFile8->GetObject(path+"/"+histName, htemp8);
        sourceFile9->GetObject(path+"/"+histName, htemp9);				
        sourceFile10->GetObject(path+"/"+histName, htemp10);				
        sourceFile11->GetObject(path+"/"+histName, htemp11);
        sourceFile12->GetObject(path+"/"+histName, htemp12);	
        sourceFile13->GetObject(path+"/"+histName, htemp13);				
        sourceFile14->GetObject(path+"/"+histName, htemp14);
        sourceFile15->GetObject(path+"/"+histName, htemp15);
        sourceFile16->GetObject(path+"/"+histName, htemp16);																				
        sourceFile17->GetObject(path+"/"+histName, htemp17);
        sourceFile18->GetObject(path+"/"+histName, htemp18);				
        sourceFile19->GetObject(path+"/"+histName, htemp19);
    /*    sourceFile19->GetObject(path+"/"+histName, htemp19);				
        sourceFile20->GetObject(path+"/"+histName, htemp20);				
        sourceFile21->GetObject(path+"/"+histName, htemp21);
        sourceFile22->GetObject(path+"/"+histName, htemp22);	
        sourceFile23->GetObject(path+"/"+histName, htemp23);				
        sourceFile24->GetObject(path+"/"+histName, htemp24);
        sourceFile25->GetObject(path+"/"+histName, htemp25);
        sourceFile26->GetObject(path+"/"+histName, htemp26);																				
        sourceFile27->GetObject(path+"/"+histName, htemp27);				
        sourceFile28->GetObject(path+"/"+histName, htemp28);																				
        sourceFile29->GetObject(path+"/"+histName, htemp29);		*/				
							
      } else {
			sourceFile2->GetObject(histName, htemp2);
			sourceFile3->GetObject(histName, htemp3);
			sourceFile4->GetObject(histName, htemp4);
      sourceFile5->GetObject(histName, htemp5);
      sourceFile6->GetObject(histName, htemp6);				
      sourceFile7->GetObject(histName, htemp7);				
      sourceFile8->GetObject(histName, htemp8);
      sourceFile9->GetObject(histName, htemp9);				
      sourceFile10->GetObject(histName, htemp10);				
      sourceFile11->GetObject(histName, htemp11);
      sourceFile12->GetObject(histName, htemp12);			
      sourceFile13->GetObject(histName, htemp13);				
      sourceFile14->GetObject(histName, htemp14);
      sourceFile15->GetObject(histName, htemp15);
      sourceFile16->GetObject(histName, htemp16);		
      sourceFile17->GetObject(histName, htemp17);	
      sourceFile18->GetObject(histName, htemp18);			
      sourceFile19->GetObject(histName, htemp19);				
 /*     sourceFile20->GetObject(histName, htemp20);				
      sourceFile21->GetObject(histName, htemp21);
      sourceFile17->GetObject(histName, htemp17);     		
      sourceFile23->GetObject(histName, htemp23);				
      sourceFile24->GetObject(histName, htemp24);
      sourceFile25->GetObject(histName, htemp25);
      sourceFile26->GetObject(histName, htemp26);		
      sourceFile27->GetObject(histName, htemp27);			
      sourceFile28->GetObject(histName, htemp28);		
      sourceFile29->GetObject(histName, htemp29);			*/								
      }

      outputFilename=histName;
      plotHistograms(htemp1, htemp2, htemp3, htemp4, htemp5, htemp6, htemp7, htemp8, htemp9, htemp10, htemp11, htemp12, htemp13, htemp14, htemp15,
			htemp16, htemp17, htemp18, htemp19,outputFolder+path+"/"+outputFilename); // htemp18, htemp19, htemp20, htemp21, htemp22, htemp23, htemp24, htemp25,
		//	htemp26, htemp27, htemp28, htemp29, outputFolder+path+"/"+outputFilename);

    } else if ( obj->IsA()->InheritsFrom( "TDirectory" ) ) {
      // it's a subdirectory

      cout << "Found subdirectory " << obj->GetName() << endl;
      gSystem->MakeDirectory(outputFolder+path+"/"+obj->GetName());

      // obj is now the starting point of another round of merging
      // obj still knows its depth within the target file via
      // GetPath(), so we can still figure out where we are in the recursion
      recurseOverKeys( (TDirectory*)obj );

      } // end of IF a TDriectory 
  }
}
int plot() {

  // If file labels were not given as argument,
  // use the filename as a label
TH1::SetDefaultSumw2();		
fileLabel1.ReplaceAll("_V06.1_sel.root","");
fileLabel2.ReplaceAll("_V02.1_sel.root","");
fileLabel3.ReplaceAll("Add.root","");
fileLabel17.ReplaceAll(".root","");		
fileLabel4.ReplaceAll("_V02.1_sel.root","");		
fileLabel5.ReplaceAll("_V06.1_sel.root","");		
fileLabel6.ReplaceAll("_V02.1_sel.root","");		
fileLabel7.ReplaceAll("_V02.1_sel.root","");		
fileLabel8.ReplaceAll("_V02.1_sel.root","");		
fileLabel9.ReplaceAll("_V06.1_sel.root","");		
fileLabel10.ReplaceAll("_V02.1_sel.root","");		
fileLabel11.ReplaceAll("_V02.1_sel.root","");
fileLabel12.ReplaceAll("_V02.1_sel.root","");	
fileLabel13.ReplaceAll("_V06.1_sel.root","");		
fileLabel14.ReplaceAll("_V06.1_sel.root","");
fileLabel15.ReplaceAll("_V06.1_sel.root","");
fileLabel16.ReplaceAll(".root","");
fileLabel18.ReplaceAll(".root","");
fileLabel19.ReplaceAll(".root","");
//fileLabel18.ReplaceAll("_30_50_V07.1_sel.root","");
//  label1 = fileLabel1;
//  label2 = fileLabel2;

  showStatsBoxes = showStats;
	
  sourceFile1 = TFile::Open( fileName1 );
  sourceFile2 = TFile::Open( fileName2 );
  sourceFile3 = TFile::Open( fileName3 );
  sourceFile4 = TFile::Open( fileName4 );
  sourceFile5 = TFile::Open( fileName5 );
  sourceFile6 = TFile::Open( fileName6 );
  sourceFile7 = TFile::Open( fileName7 );
  sourceFile8 = TFile::Open( fileName8 );	
  sourceFile9 = TFile::Open( fileName9 );
  sourceFile10 = TFile::Open( fileName10 );
  sourceFile11 = TFile::Open( fileName11 );
  sourceFile12 = TFile::Open( fileName12 );		
  sourceFile13 = TFile::Open( fileName13 );
  sourceFile14 = TFile::Open( fileName14 );
  sourceFile15 = TFile::Open( fileName15 );			
  sourceFile16 = TFile::Open( fileName16 );
  sourceFile17 = TFile::Open( fileName17 );	
  sourceFile18 = TFile::Open( fileName18 );	
  sourceFile19 = TFile::Open( fileName19 );
/*  sourceFile20 = TFile::Open( fileName20 );
  sourceFile21 = TFile::Open( fileName21 );
  sourceFile22 = TFile::Open( fileName22 );		
  sourceFile23 = TFile::Open( fileName23 );
  sourceFile24 = TFile::Open( fileName24 );
  sourceFile25 = TFile::Open( fileName25 );			
  sourceFile26 = TFile::Open( fileName26 );
  sourceFile27 = TFile::Open( fileName27 );
  sourceFile28 = TFile::Open( fileName28 );
  sourceFile29 = TFile::Open( fileName29 );		 */
  outputFolder = "HistogramsTogether"; // Blank to use current directory,
                                          // or, for a specific dir type
                                          // something like "images/"
  gSystem->MakeDirectory(outputFolder);

  canvasDefault = new TCanvas("canvasDefault","testCanvas",outputWidth,outputHeight);
	canvasDefault->Range(0,0,1,1);

  // This function will plot all histograms from 
  // file1 against matching histogram from file2
	
  recurseOverKeys(sourceFile1);

  sourceFile1->Close();
  sourceFile2->Close();
  sourceFile3->Close();
	sourceFile4->Close();
  sourceFile5->Close();
  sourceFile6->Close();
  sourceFile7->Close();
	sourceFile8->Close();	
  sourceFile9->Close();
  sourceFile10->Close();
  sourceFile11->Close();
	sourceFile12->Close();	
  sourceFile13->Close();
  sourceFile14->Close();
	sourceFile15->Close();
	sourceFile16->Close();		
	sourceFile17->Close();	
	sourceFile18->Close();	
  sourceFile19->Close();
/*  sourceFile20->Close();
  sourceFile21->Close();
	sourceFile22->Close();	
  sourceFile23->Close();
  sourceFile24->Close();
	sourceFile25->Close();
	sourceFile26->Close();		
	sourceFile27->Close();	
	sourceFile28->Close();		
	sourceFile29->Close();	*/
  TString currentDir = gSystem->pwd();
  cout << "Done. See images in:" << endl << currentDir << "/" << outputFolder << endl;
	
	return 0;
}




