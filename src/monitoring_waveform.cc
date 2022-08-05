#include <cstdio>
#include <algorithm>
#include <vector>
#include <numeric>
#include <TPad.h>
#include <TFile.h>
#include <utility>
#include <iostream>
#include <TH1.h>

void pad_set(TPad* tPad, double margin) {
    tPad->Draw();
    tPad->cd();

    tPad->SetTopMargin(margin);
    tPad->SetLeftMargin(margin);    
    tPad->SetRightMargin(margin);
    tPad->SetBottomMargin(margin);
}


void monitoring_waveform() {

	TCanvas* cWave = new TCanvas("cWave", "cWave", 1000., 500.);

	cWave->cd(); TPad* pWaveM1T1  = new TPad("pWaveM1T1", "pWaveM1T1" ,0.50, 0.50, 0.74, 0.98); pad_set(pWaveM1T1, 0.); 
	cWave->cd(); TPad* pWaveM1T2  = new TPad("pWaveM1T2", "pWaveM1T2" ,0.74, 0.50, 0.98, 0.98); pad_set(pWaveM1T2, 0.); 
	cWave->cd(); TPad* pWaveM1T3  = new TPad("pWaveM1T3", "pWaveM1T3" ,0.50, 0.02, 0.74, 0.50); pad_set(pWaveM1T3, 0.); 
	cWave->cd(); TPad* pWaveM1T4  = new TPad("pWaveM1T4", "pWaveM1T4" ,0.74, 0.02, 0.98, 0.50); pad_set(pWaveM1T4, 0.); 

	cWave->cd(); TPad* pWaveM2T7  = new TPad("pWaveM2T7", "pWaveM2T7" ,0.02, 0.02, 0.18, 0.34); pad_set(pWaveM2T7, 0.); 
	cWave->cd(); TPad* pWaveM2T8  = new TPad("pWaveM2T8", "pWaveM2T8" ,0.18, 0.02, 0.34, 0.34); pad_set(pWaveM2T8, 0.); 
	cWave->cd(); TPad* pWaveM2T9  = new TPad("pWaveM2T9", "pWaveM2T9" ,0.34, 0.02, 0.50, 0.34); pad_set(pWaveM2T9, 0.); 
	cWave->cd(); TPad* pWaveM2T4  = new TPad("pWaveM2T4", "pWaveM2T4" ,0.02, 0.34, 0.18, 0.66); pad_set(pWaveM2T4, 0.); 
	cWave->cd(); TPad* pWaveM2T5  = new TPad("pWaveM2T5", "pWaveM2T5" ,0.18, 0.34, 0.34, 0.66); pad_set(pWaveM2T5, 0.); 
	cWave->cd(); TPad* pWaveM2T6  = new TPad("pWaveM2T6", "pWaveM2T6" ,0.34, 0.34, 0.50, 0.66); pad_set(pWaveM2T6, 0.); 
	cWave->cd(); TPad* pWaveM2T1  = new TPad("pWaveM2T1", "pWaveM2T1" ,0.02, 0.66, 0.18, 0.98); pad_set(pWaveM2T1, 0.); 
	cWave->cd(); TPad* pWaveM2T2  = new TPad("pWaveM2T2", "pWaveM2T2" ,0.18, 0.66, 0.34, 0.98); pad_set(pWaveM2T2, 0.); 
	cWave->cd(); TPad* pWaveM2T3  = new TPad("pWaveM2T3", "pWaveM2T3" ,0.34, 0.66, 0.50, 0.98); pad_set(pWaveM2T3, 0.); 

	TH1D* hWaveCM1T1  = new TH1D("hWaveCM1T1", "hWaveCM1T1;ns;ADC", 1000, 0., 200.); ChM1T1->SetTitle(""); hWaveCM1T1->SetStats(0); hWaveCM1T1->SetLineWidth(1); hWaveCM1T1->SetLineColor(kBlue); hWaveCM1T1->GetYaxis()->SetRangeUser(0., 4100.);
	TH1D* hWaveCM1T2  = new TH1D("hWaveCM1T2", "hWaveCM1T2;ns;ADC", 1000, 0., 200.); ChM1T2->SetTitle(""); hWaveCM1T2->SetStats(0); hWaveCM1T2->SetLineWidth(1); hWaveCM1T2->SetLineColor(kBlue); hWaveCM1T2->GetYaxis()->SetRangeUser(0., 4100.);
	TH1D* hWaveCM1T3  = new TH1D("hWaveCM1T3", "hWaveCM1T3;ns;ADC", 1000, 0., 200.); ChM1T3->SetTitle(""); hWaveCM1T3->SetStats(0); hWaveCM1T3->SetLineWidth(1); hWaveCM1T3->SetLineColor(kBlue); hWaveCM1T3->GetYaxis()->SetRangeUser(0., 4100.);
	TH1D* hWaveCM1T4  = new TH1D("hWaveCM1T4", "hWaveCM1T4;ns;ADC", 1000, 0., 200.); ChM1T4->SetTitle(""); hWaveCM1T4->SetStats(0); hWaveCM1T4->SetLineWidth(1); hWaveCM1T4->SetLineColor(kBlue); hWaveCM1T4->GetYaxis()->SetRangeUser(0., 4100.);
	TH1D* hWaveCM2T7  = new TH1D("hWaveCM2T7", "hWaveCM2T7;ns;ADC", 1000, 0., 200.); ChM2T7->SetTitle(""); hWaveCM2T7->SetStats(0); hWaveCM2T7->SetLineWidth(1); hWaveCM2T7->SetLineColor(kBlue); hWaveCM2T7->GetYaxis()->SetRangeUser(0., 4100.);
	TH1D* hWaveCM2T8  = new TH1D("hWaveCM2T8", "hWaveCM2T8;ns;ADC", 1000, 0., 200.); ChM2T8->SetTitle(""); hWaveCM2T8->SetStats(0); hWaveCM2T8->SetLineWidth(1); hWaveCM2T8->SetLineColor(kBlue); hWaveCM2T8->GetYaxis()->SetRangeUser(0., 4100.);
	TH1D* hWaveCM2T9  = new TH1D("hWaveCM2T9", "hWaveCM2T9;ns;ADC", 1000, 0., 200.); ChM2T9->SetTitle(""); hWaveCM2T9->SetStats(0); hWaveCM2T9->SetLineWidth(1); hWaveCM2T9->SetLineColor(kBlue); hWaveCM2T9->GetYaxis()->SetRangeUser(0., 4100.);
	TH1D* hWaveCM2T4  = new TH1D("hWaveCM2T4", "hWaveCM2T4;ns;ADC", 1000, 0., 200.); ChM2T4->SetTitle(""); hWaveCM2T4->SetStats(0); hWaveCM2T4->SetLineWidth(1); hWaveCM2T4->SetLineColor(kBlue); hWaveCM2T4->GetYaxis()->SetRangeUser(0., 4100.);
	TH1D* hWaveCM2T6  = new TH1D("hWaveCM2T6", "hWaveCM2T6;ns;ADC", 1000, 0., 200.); ChM2T6->SetTitle(""); hWaveCM2T6->SetStats(0); hWaveCM2T6->SetLineWidth(1); hWaveCM2T6->SetLineColor(kBlue); hWaveCM2T6->GetYaxis()->SetRangeUser(0., 4100.);
	TH1D* hWaveCM2T1  = new TH1D("hWaveCM2T1", "hWaveCM2T1;ns;ADC", 1000, 0., 200.); ChM2T1->SetTitle(""); hWaveCM2T1->SetStats(0); hWaveCM2T1->SetLineWidth(1); hWaveCM2T1->SetLineColor(kBlue); hWaveCM2T1->GetYaxis()->SetRangeUser(0., 4100.);
	TH1D* hWaveCM2T2  = new TH1D("hWaveCM2T2", "hWaveCM2T2;ns;ADC", 1000, 0., 200.); ChM2T2->SetTitle(""); hWaveCM2T2->SetStats(0); hWaveCM2T2->SetLineWidth(1); hWaveCM2T2->SetLineColor(kBlue); hWaveCM2T2->GetYaxis()->SetRangeUser(0., 4100.);
	TH1D* hWaveCM2T3  = new TH1D("hWaveCM2T3", "hWaveCM2T3;ns;ADC", 1000, 0., 200.); ChM2T3->SetTitle(""); hWaveCM2T3->SetStats(0); hWaveCM2T3->SetLineWidth(1); hWaveCM2T3->SetLineColor(kBlue); hWaveCM2T3->GetYaxis()->SetRangeUser(0., 4100.);

	TH1D* hWaveSM1T1  = new TH1D("hWaveSM1T1", "hWaveSM1T1;ns;ADC", 1000, 0., 200.); ChM1T1->SetTitle(""); hWaveSM1T1->SetStats(0); hWaveSM1T1->SetLineWidth(1); hWaveSM1T1->SetLineColor(kBlue); hWaveSM1T1->GetYaxis()->SetRangeUser(0., 4100.);
	TH1D* hWaveSM1T2  = new TH1D("hWaveSM1T2", "hWaveSM1T2;ns;ADC", 1000, 0., 200.); ChM1T2->SetTitle(""); hWaveSM1T2->SetStats(0); hWaveSM1T2->SetLineWidth(1); hWaveSM1T2->SetLineColor(kBlue); hWaveSM1T2->GetYaxis()->SetRangeUser(0., 4100.);
	TH1D* hWaveSM1T3  = new TH1D("hWaveSM1T3", "hWaveSM1T3;ns;ADC", 1000, 0., 200.); ChM1T3->SetTitle(""); hWaveSM1T3->SetStats(0); hWaveSM1T3->SetLineWidth(1); hWaveSM1T3->SetLineColor(kBlue); hWaveSM1T3->GetYaxis()->SetRangeUser(0., 4100.);
	TH1D* hWaveSM1T4  = new TH1D("hWaveSM1T4", "hWaveSM1T4;ns;ADC", 1000, 0., 200.); ChM1T4->SetTitle(""); hWaveSM1T4->SetStats(0); hWaveSM1T4->SetLineWidth(1); hWaveSM1T4->SetLineColor(kBlue); hWaveSM1T4->GetYaxis()->SetRangeUser(0., 4100.);
	TH1D* hWaveSM2T7  = new TH1D("hWaveSM2T7", "hWaveSM2T7;ns;ADC", 1000, 0., 200.); ChM2T7->SetTitle(""); hWaveSM2T7->SetStats(0); hWaveSM2T7->SetLineWidth(1); hWaveSM2T7->SetLineColor(kBlue); hWaveSM2T7->GetYaxis()->SetRangeUser(0., 4100.);
	TH1D* hWaveSM2T8  = new TH1D("hWaveSM2T8", "hWaveSM2T8;ns;ADC", 1000, 0., 200.); ChM2T8->SetTitle(""); hWaveSM2T8->SetStats(0); hWaveSM2T8->SetLineWidth(1); hWaveSM2T8->SetLineColor(kBlue); hWaveSM2T8->GetYaxis()->SetRangeUser(0., 4100.);
	TH1D* hWaveSM2T9  = new TH1D("hWaveSM2T9", "hWaveSM2T9;ns;ADC", 1000, 0., 200.); ChM2T9->SetTitle(""); hWaveSM2T9->SetStats(0); hWaveSM2T9->SetLineWidth(1); hWaveSM2T9->SetLineColor(kBlue); hWaveSM2T9->GetYaxis()->SetRangeUser(0., 4100.);
	TH1D* hWaveSM2T4  = new TH1D("hWaveSM2T4", "hWaveSM2T4;ns;ADC", 1000, 0., 200.); ChM2T4->SetTitle(""); hWaveSM2T4->SetStats(0); hWaveSM2T4->SetLineWidth(1); hWaveSM2T4->SetLineColor(kBlue); hWaveSM2T4->GetYaxis()->SetRangeUser(0., 4100.);
	TH1D* hWaveSM2T6  = new TH1D("hWaveSM2T6", "hWaveSM2T6;ns;ADC", 1000, 0., 200.); ChM2T6->SetTitle(""); hWaveSM2T6->SetStats(0); hWaveSM2T6->SetLineWidth(1); hWaveSM2T6->SetLineColor(kBlue); hWaveSM2T6->GetYaxis()->SetRangeUser(0., 4100.);
	TH1D* hWaveSM2T1  = new TH1D("hWaveSM2T1", "hWaveSM2T1;ns;ADC", 1000, 0., 200.); ChM2T1->SetTitle(""); hWaveSM2T1->SetStats(0); hWaveSM2T1->SetLineWidth(1); hWaveSM2T1->SetLineColor(kBlue); hWaveSM2T1->GetYaxis()->SetRangeUser(0., 4100.);
	TH1D* hWaveSM2T2  = new TH1D("hWaveSM2T2", "hWaveSM2T2;ns;ADC", 1000, 0., 200.); ChM2T2->SetTitle(""); hWaveSM2T2->SetStats(0); hWaveSM2T2->SetLineWidth(1); hWaveSM2T2->SetLineColor(kBlue); hWaveSM2T2->GetYaxis()->SetRangeUser(0., 4100.);
	TH1D* hWaveSM2T3  = new TH1D("hWaveSM2T3", "hWaveSM2T3;ns;ADC", 1000, 0., 200.); ChM2T3->SetTitle(""); hWaveSM2T3->SetStats(0); hWaveSM2T3->SetLineWidth(1); hWaveSM2T3->SetLineColor(kBlue); hWaveSM2T3->GetYaxis()->SetRangeUser(0., 4100.);


	TCanvas* cHeat = new TCanvas("cHeat", "cHeat", 1000, 1000);

	cHeat->cd(); TPad* pHeatCpCol   = new TPad("pHeatCpCol ", "pHeatCpCol ", 0.90 , 0.01 , 0.99 , 0.99 ); pad_set(pHeatCpCol , 0.);

	cHeat->cd(); TPad* pHeatCpM1    = new TPad("pHeatCpM1  ", "pHeatCpM1  ", 0.45 , 0.01 , 0.90 , 0.49 ); pad_set(pHeatCpM1  , 0.);
	cHeat->cd(); TPad* pHeatCpM2T7  = new TPad("pHeatCpM2T7", "pHeatCpM2T7", 0.01 , 0.01 , 0.156, 0.17 ); pad_set(pHeatCpM2T7, 0.);
	cHeat->cd(); TPad* pHeatCpM2T8  = new TPad("pHeatCpM2T8", "pHeatCpM2T8", 0.156, 0.01 , 0.303, 0.17 ); pad_set(pHeatCpM2T8, 0.);
	cHeat->cd(); TPad* pHeatCpM2T9  = new TPad("pHeatCpM2T9", "pHeatCpM2T9", 0.303, 0.01 , 0.450, 0.17 ); pad_set(pHeatCpM2T9, 0.);
	cHeat->cd(); TPad* pHeatCpM2T4  = new TPad("pHeatCpM2T4", "pHeatCpM2T4", 0.01 , 0.17 , 0.156, 0.33 ); pad_set(pHeatCpM2T4, 0.);
	cHeat->cd(); TPad* pHeatCpM2T5  = new TPad("pHeatCpM2T5", "pHeatCpM2T5", 0.156, 0.17 , 0.303, 0.33 ); pad_set(pHeatCpM2T5, 0.);
	cHeat->cd(); TPad* pHeatCpM2T6  = new TPad("pHeatCpM2T6", "pHeatCpM2T6", 0.303, 0.17 , 0.450, 0.33 ); pad_set(pHeatCpM2T6, 0.);
	cHeat->cd(); TPad* pHeatCpM2T1  = new TPad("pHeatCpM2T1", "pHeatCpM2T1", 0.01 , 0.33 , 0.156, 0.49 ); pad_set(pHeatCpM2T1, 0.);
	cHeat->cd(); TPad* pHeatCpM2T2  = new TPad("pHeatCpM2T2", "pHeatCpM2T2", 0.156, 0.33 , 0.303, 0.49 ); pad_set(pHeatCpM2T2, 0.);
	cHeat->cd(); TPad* pHeatCpM2T3  = new TPad("pHeatCpM2T3", "pHeatCpM2T3", 0.303, 0.33 , 0.450, 0.49 ); pad_set(pHeatCpM2T3, 0.);

	cHeat->cd(); TPad* pHeatSpM1    = new TPad("pHeatSpM1  ", "pHeatSpM1  ", 0.45 , 0.51 , 0.90 , 0.99 ); pad_set(pHeatSpM1  , 0.); 
	cHeat->cd(); TPad* pHeatSpM2T7  = new TPad("pHeatSpM2T7", "pHeatSpM2T7", 0.01 , 0.51 , 0.156, 0.67 ); pad_set(pHeatSpM2T7, 0.); 
	cHeat->cd(); TPad* pHeatSpM2T8  = new TPad("pHeatSpM2T8", "pHeatSpM2T8", 0.156, 0.51 , 0.303, 0.67 ); pad_set(pHeatSpM2T8, 0.); 
	cHeat->cd(); TPad* pHeatSpM2T9  = new TPad("pHeatSpM2T9", "pHeatSpM2T9", 0.303, 0.51 , 0.450, 0.67 ); pad_set(pHeatSpM2T9, 0.); 
	cHeat->cd(); TPad* pHeatSpM2T4  = new TPad("pHeatSpM2T4", "pHeatSpM2T4", 0.01 , 0.67 , 0.156, 0.83 ); pad_set(pHeatSpM2T4, 0.); 
	cHeat->cd(); TPad* pHeatSpM2T5  = new TPad("pHeatSpM2T5", "pHeatSpM2T5", 0.156, 0.67 , 0.303, 0.83 ); pad_set(pHeatSpM2T5, 0.); 
	cHeat->cd(); TPad* pHeatSpM2T6  = new TPad("pHeatSpM2T6", "pHeatSpM2T6", 0.303, 0.67 , 0.450, 0.83 ); pad_set(pHeatSpM2T6, 0.); 
	cHeat->cd(); TPad* pHeatSpM2T1  = new TPad("pHeatSpM2T1", "pHeatSpM2T1", 0.01 , 0.83 , 0.156, 0.99 ); pad_set(pHeatSpM2T1, 0.); 
	cHeat->cd(); TPad* pHeatSpM2T2  = new TPad("pHeatSpM2T2", "pHeatSpM2T2", 0.156, 0.83 , 0.303, 0.99 ); pad_set(pHeatSpM2T2, 0.); 
	cHeat->cd(); TPad* pHeatSpM2T3  = new TPad("pHeatSpM2T3", "pHeatSpM2T3", 0.303, 0.83 , 0.450, 0.99 ); pad_set(pHeatSpM2T3, 0.); 

	TH2D* hHeatCM1    = new TH2D("hHeatCM1  ", "", 2 , 0 , 2 , 2 , 0 , 2 ); hHeatCM1  ->SetStats(0); hHeatCM1  ->GetXaxis()->SetTickLength(0.); hHeatCM1  ->GetYaxis()->SetTickLength(0.); hHeatCM1  ->GetZaxis()->SetRangeUser(0., HeatADCmax);
	TH2D* hHeatCM2T7  = new TH2D("hHeatCM2T7", "", 1 , 0 , 1 , 1 , 0 , 1 ); hHeatCM2T7->SetStats(0); hHeatCM2T7->GetXaxis()->SetTickLength(0.); hHeatCM2T7->GetYaxis()->SetTickLength(0.); hHeatCM2T7->GetZaxis()->SetRangeUser(0., HeatADCmax);
	TH2D* hHeatCM2T8  = new TH2D("hHeatCM2T8", "", 1 , 0 , 1 , 1 , 0 , 1 ); hHeatCM2T8->SetStats(0); hHeatCM2T8->GetXaxis()->SetTickLength(0.); hHeatCM2T8->GetYaxis()->SetTickLength(0.); hHeatCM2T8->GetZaxis()->SetRangeUser(0., HeatADCmax);
	TH2D* hHeatCM2T9  = new TH2D("hHeatCM2T9", "", 1 , 0 , 1 , 1 , 0 , 1 ); hHeatCM2T9->SetStats(0); hHeatCM2T9->GetXaxis()->SetTickLength(0.); hHeatCM2T9->GetYaxis()->SetTickLength(0.); hHeatCM2T9->GetZaxis()->SetRangeUser(0., HeatADCmax);
	TH2D* hHeatCM2T4  = new TH2D("hHeatCM2T4", "", 1 , 0 , 1 , 1 , 0 , 1 ); hHeatCM2T4->SetStats(0); hHeatCM2T4->GetXaxis()->SetTickLength(0.); hHeatCM2T4->GetYaxis()->SetTickLength(0.); hHeatCM2T4->GetZaxis()->SetRangeUser(0., HeatADCmax);
	TH2D* hHeatCM2T5  = new TH2D("hHeatCM2T5", "", 20, 0 , 20, 20, 0 , 20); hHeatCM2T5->SetStats(0); hHeatCM2T5->GetXaxis()->SetTickLength(0.); hHeatCM2T5->GetYaxis()->SetTickLength(0.); hHeatCM2T5->GetZaxis()->SetRangeUser(0., HeatADCmax);
	TH2D* hHeatCM2T6  = new TH2D("hHeatCM2T6", "", 1 , 0 , 1 , 1 , 0 , 1 ); hHeatCM2T6->SetStats(0); hHeatCM2T6->GetXaxis()->SetTickLength(0.); hHeatCM2T6->GetYaxis()->SetTickLength(0.); hHeatCM2T6->GetZaxis()->SetRangeUser(0., HeatADCmax);
	TH2D* hHeatCM2T1  = new TH2D("hHeatCM2T1", "", 1 , 0 , 1 , 1 , 0 , 1 ); hHeatCM2T1->SetStats(0); hHeatCM2T1->GetXaxis()->SetTickLength(0.); hHeatCM2T1->GetYaxis()->SetTickLength(0.); hHeatCM2T1->GetZaxis()->SetRangeUser(0., HeatADCmax);
	TH2D* hHeatCM2T2  = new TH2D("hHeatCM2T2", "", 1 , 0 , 1 , 1 , 0 , 1 ); hHeatCM2T2->SetStats(0); hHeatCM2T2->GetXaxis()->SetTickLength(0.); hHeatCM2T2->GetYaxis()->SetTickLength(0.); hHeatCM2T2->GetZaxis()->SetRangeUser(0., HeatADCmax);
	TH2D* hHeatCM2T3  = new TH2D("hHeatCM2T3", "", 1 , 0 , 1 , 1 , 0 , 1 ); hHeatCM2T3->SetStats(0); hHeatCM2T3->GetXaxis()->SetTickLength(0.); hHeatCM2T3->GetYaxis()->SetTickLength(0.); hHeatCM2T3->GetZaxis()->SetRangeUser(0., HeatADCmax);

	TH2D* hHeatSM1    = new TH2D("hHeatSM1  ", "", 2 , 0 , 2 , 2 , 0 , 2 ); hHeatSM1  ->SetStats(0); hHeatSM1  ->GetXaxis()->SetTickLength(0.); hHeatSM1  ->GetYaxis()->SetTickLength(0.); hHeatSM1  ->GetZaxis()->SetRangeUser(0., HeatADCmax);
	TH2D* hHeatSM2T7  = new TH2D("hHeatSM2T7", "", 1 , 0 , 1 , 1 , 0 , 1 ); hHeatSM2T7->SetStats(0); hHeatSM2T7->GetXaxis()->SetTickLength(0.); hHeatSM2T7->GetYaxis()->SetTickLength(0.); hHeatSM2T7->GetZaxis()->SetRangeUser(0., HeatADCmax);
	TH2D* hHeatSM2T8  = new TH2D("hHeatSM2T8", "", 1 , 0 , 1 , 1 , 0 , 1 ); hHeatSM2T8->SetStats(0); hHeatSM2T8->GetXaxis()->SetTickLength(0.); hHeatSM2T8->GetYaxis()->SetTickLength(0.); hHeatSM2T8->GetZaxis()->SetRangeUser(0., HeatADCmax);
	TH2D* hHeatSM2T9  = new TH2D("hHeatSM2T9", "", 1 , 0 , 1 , 1 , 0 , 1 ); hHeatSM2T9->SetStats(0); hHeatSM2T9->GetXaxis()->SetTickLength(0.); hHeatSM2T9->GetYaxis()->SetTickLength(0.); hHeatSM2T9->GetZaxis()->SetRangeUser(0., HeatADCmax);
	TH2D* hHeatSM2T4  = new TH2D("hHeatSM2T4", "", 1 , 0 , 1 , 1 , 0 , 1 ); hHeatSM2T4->SetStats(0); hHeatSM2T4->GetXaxis()->SetTickLength(0.); hHeatSM2T4->GetYaxis()->SetTickLength(0.); hHeatSM2T4->GetZaxis()->SetRangeUser(0., HeatADCmax);
	TH2D* hHeatSM2T5  = new TH2D("hHeatSM2T5", "", 20, 0 , 20, 20, 0 , 20); hHeatSM2T5->SetStats(0); hHeatSM2T5->GetXaxis()->SetTickLength(0.); hHeatSM2T5->GetYaxis()->SetTickLength(0.); hHeatSM2T5->GetZaxis()->SetRangeUser(0., HeatADCmax);
	TH2D* hHeatSM2T6  = new TH2D("hHeatSM2T6", "", 1 , 0 , 1 , 1 , 0 , 1 ); hHeatSM2T6->SetStats(0); hHeatSM2T6->GetXaxis()->SetTickLength(0.); hHeatSM2T6->GetYaxis()->SetTickLength(0.); hHeatSM2T6->GetZaxis()->SetRangeUser(0., HeatADCmax);
	TH2D* hHeatSM2T1  = new TH2D("hHeatSM2T1", "", 1 , 0 , 1 , 1 , 0 , 1 ); hHeatSM2T1->SetStats(0); hHeatSM2T1->GetXaxis()->SetTickLength(0.); hHeatSM2T1->GetYaxis()->SetTickLength(0.); hHeatSM2T1->GetZaxis()->SetRangeUser(0., HeatADCmax);
	TH2D* hHeatSM2T2  = new TH2D("hHeatSM2T2", "", 1 , 0 , 1 , 1 , 0 , 1 ); hHeatSM2T2->SetStats(0); hHeatSM2T2->GetXaxis()->SetTickLength(0.); hHeatSM2T2->GetYaxis()->SetTickLength(0.); hHeatSM2T2->GetZaxis()->SetRangeUser(0., HeatADCmax);
	TH2D* hHeatSM2T3  = new TH2D("hHeatSM2T3", "", 1 , 0 , 1 , 1 , 0 , 1 ); hHeatSM2T3->SetStats(0); hHeatSM2T3->GetXaxis()->SetTickLength(0.); hHeatSM2T3->GetYaxis()->SetTickLength(0.); hHeatSM2T3->GetZaxis()->SetRangeUser(0., HeatADCmax);


	TCanvas* cDist = new TCanvas("cDist", "cDist", 1000, 500);

	cDist->cd(); TPad* pDistM1T1  = new TPad("pDistM1T1", "pDistM1T1", 0.50, 0.50, 0.74, 0.98); pad_set(pDistM1T1, 0.);
	cDist->cd(); TPad* pDistM1T2  = new TPad("pDistM1T2", "pDistM1T2", 0.74, 0.50, 0.98, 0.98); pad_set(pDistM1T2, 0.);
	cDist->cd(); TPad* pDistM1T3  = new TPad("pDistM1T3", "pDistM1T3", 0.50, 0.02, 0.74, 0.50); pad_set(pDistM1T3, 0.);
	cDist->cd(); TPad* pDistM1T4  = new TPad("pDistM1T4", "pDistM1T4", 0.74, 0.02, 0.98, 0.50); pad_set(pDistM1T4, 0.);
	
	cDist->cd(); TPad* pDistM1T7  = new TPad("pDistM1T7", "pDistM1T7", 0.02, 0.01, 0.18, 0.17); pad_set(pDistM1T7, 0.);
	cDist->cd(); TPad* pDistM1T8  = new TPad("pDistM1T8", "pDistM1T8", 0.18, 0.01, 0.34, 0.17); pad_set(pDistM1T8, 0.);
	cDist->cd(); TPad* pDistM1T9  = new TPad("pDistM1T9", "pDistM1T9", 0.34, 0.01, 0.50, 0.17); pad_set(pDistM1T9, 0.);
	cDist->cd(); TPad* pDistM1T4  = new TPad("pDistM1T4", "pDistM1T4", 0.02, 0.17, 0.18, 0.33); pad_set(pDistM1T4, 0.);
	cDist->cd(); TPad* pDistM1T5  = new TPad("pDistM1T5", "pDistM1T5", 0.18, 0.17, 0.34, 0.33); pad_set(pDistM1T5, 0.);
	cDist->cd(); TPad* pDistM1T6  = new TPad("pDistM1T6", "pDistM1T6", 0.34, 0.17, 0.50, 0.33); pad_set(pDistM1T6, 0.);
	cDist->cd(); TPad* pDistM1T1  = new TPad("pDistM1T1", "pDistM1T1", 0.02, 0.33, 0.18, 0.49); pad_set(pDistM1T1, 0.);
	cDist->cd(); TPad* pDistM1T2  = new TPad("pDistM1T2", "pDistM1T2", 0.18, 0.33, 0.34, 0.49); pad_set(pDistM1T2, 0.);
	cDist->cd(); TPad* pDistM1T3  = new TPad("pDistM1T3", "pDistM1T3", 0.34, 0.33, 0.50, 0.49); pad_set(pDistM1T3, 0.);

	TH2D* hDistCM1    = new TH2D("hDistCM1  ", "", 2 , 0 , 2 , 2 , 0 , 2 ); hDistCM1  ->SetStats(0); hDistCM1  ->GetXaxis()->SetTickLength(0.); hDistCM1  ->GetYaxis()->SetTickLength(0.); hDistCM1  ->GetZaxis()->SetRangeUser(0., intgratedADCmax);
	TH2D* hDistCM2T7  = new TH2D("hDistCM2T7", "", 1 , 0 , 1 , 1 , 0 , 1 ); hDistCM2T7->SetStats(0); hDistCM2T7->GetXaxis()->SetTickLength(0.); hDistCM2T7->GetYaxis()->SetTickLength(0.); hDistCM2T7->GetZaxis()->SetRangeUser(0., intgratedADCmax);
	TH2D* hDistCM2T8  = new TH2D("hDistCM2T8", "", 1 , 0 , 1 , 1 , 0 , 1 ); hDistCM2T8->SetStats(0); hDistCM2T8->GetXaxis()->SetTickLength(0.); hDistCM2T8->GetYaxis()->SetTickLength(0.); hDistCM2T8->GetZaxis()->SetRangeUser(0., intgratedADCmax);
	TH2D* hDistCM2T9  = new TH2D("hDistCM2T9", "", 1 , 0 , 1 , 1 , 0 , 1 ); hDistCM2T9->SetStats(0); hDistCM2T9->GetXaxis()->SetTickLength(0.); hDistCM2T9->GetYaxis()->SetTickLength(0.); hDistCM2T9->GetZaxis()->SetRangeUser(0., intgratedADCmax);
	TH2D* hDistCM2T4  = new TH2D("hDistCM2T4", "", 1 , 0 , 1 , 1 , 0 , 1 ); hDistCM2T4->SetStats(0); hDistCM2T4->GetXaxis()->SetTickLength(0.); hDistCM2T4->GetYaxis()->SetTickLength(0.); hDistCM2T4->GetZaxis()->SetRangeUser(0., intgratedADCmax);
	TH2D* hDistCM2T6  = new TH2D("hDistCM2T6", "", 1 , 0 , 1 , 1 , 0 , 1 ); hDistCM2T6->SetStats(0); hDistCM2T6->GetXaxis()->SetTickLength(0.); hDistCM2T6->GetYaxis()->SetTickLength(0.); hDistCM2T6->GetZaxis()->SetRangeUser(0., intgratedADCmax);
	TH2D* hDistCM2T1  = new TH2D("hDistCM2T1", "", 1 , 0 , 1 , 1 , 0 , 1 ); hDistCM2T1->SetStats(0); hDistCM2T1->GetXaxis()->SetTickLength(0.); hDistCM2T1->GetYaxis()->SetTickLength(0.); hDistCM2T1->GetZaxis()->SetRangeUser(0., intgratedADCmax);
	TH2D* hDistCM2T2  = new TH2D("hDistCM2T2", "", 1 , 0 , 1 , 1 , 0 , 1 ); hDistCM2T2->SetStats(0); hDistCM2T2->GetXaxis()->SetTickLength(0.); hDistCM2T2->GetYaxis()->SetTickLength(0.); hDistCM2T2->GetZaxis()->SetRangeUser(0., intgratedADCmax);
	TH2D* hDistCM2T3  = new TH2D("hDistCM2T3", "", 1 , 0 , 1 , 1 , 0 , 1 ); hDistCM2T3->SetStats(0); hDistCM2T3->GetXaxis()->SetTickLength(0.); hDistCM2T3->GetYaxis()->SetTickLength(0.); hDistCM2T3->GetZaxis()->SetRangeUser(0., intgratedADCmax);

	TH2D* hHeatSM1    = new TH2D("hHeatSM1  ", "", 2 , 0 , 2 , 2 , 0 , 2 ); hHeatSM1  ->SetStats(0); hHeatSM1  ->GetXaxis()->SetTickLength(0.); hHeatSM1  ->GetYaxis()->SetTickLength(0.); hHeatSM1  ->GetZaxis()->SetRangeUser(0., intgratedADCmax);
	TH2D* hHeatSM2T7  = new TH2D("hHeatSM2T7", "", 1 , 0 , 1 , 1 , 0 , 1 ); hHeatSM2T7->SetStats(0); hHeatSM2T7->GetXaxis()->SetTickLength(0.); hHeatSM2T7->GetYaxis()->SetTickLength(0.); hHeatSM2T7->GetZaxis()->SetRangeUser(0., intgratedADCmax);
	TH2D* hHeatSM2T8  = new TH2D("hHeatSM2T8", "", 1 , 0 , 1 , 1 , 0 , 1 ); hHeatSM2T8->SetStats(0); hHeatSM2T8->GetXaxis()->SetTickLength(0.); hHeatSM2T8->GetYaxis()->SetTickLength(0.); hHeatSM2T8->GetZaxis()->SetRangeUser(0., intgratedADCmax);
	TH2D* hHeatSM2T9  = new TH2D("hHeatSM2T9", "", 1 , 0 , 1 , 1 , 0 , 1 ); hHeatSM2T9->SetStats(0); hHeatSM2T9->GetXaxis()->SetTickLength(0.); hHeatSM2T9->GetYaxis()->SetTickLength(0.); hHeatSM2T9->GetZaxis()->SetRangeUser(0., intgratedADCmax);
	TH2D* hHeatSM2T4  = new TH2D("hHeatSM2T4", "", 1 , 0 , 1 , 1 , 0 , 1 ); hHeatSM2T4->SetStats(0); hHeatSM2T4->GetXaxis()->SetTickLength(0.); hHeatSM2T4->GetYaxis()->SetTickLength(0.); hHeatSM2T4->GetZaxis()->SetRangeUser(0., intgratedADCmax);
\	TH2D* hHeatSM2T6  = new TH2D("hHeatSM2T6", "", 1 , 0 , 1 , 1 , 0 , 1 ); hHeatSM2T6->SetStats(0); hHeatSM2T6->GetXaxis()->SetTickLength(0.); hHeatSM2T6->GetYaxis()->SetTickLength(0.); hHeatSM2T6->GetZaxis()->SetRangeUser(0., intgratedADCmax);
	TH2D* hHeatSM2T1  = new TH2D("hHeatSM2T1", "", 1 , 0 , 1 , 1 , 0 , 1 ); hHeatSM2T1->SetStats(0); hHeatSM2T1->GetXaxis()->SetTickLength(0.); hHeatSM2T1->GetYaxis()->SetTickLength(0.); hHeatSM2T1->GetZaxis()->SetRangeUser(0., intgratedADCmax);
	TH2D* hHeatSM2T2  = new TH2D("hHeatSM2T2", "", 1 , 0 , 1 , 1 , 0 , 1 ); hHeatSM2T2->SetStats(0); hHeatSM2T2->GetXaxis()->SetTickLength(0.); hHeatSM2T2->GetYaxis()->SetTickLength(0.); hHeatSM2T2->GetZaxis()->SetRangeUser(0., intgratedADCmax);
	TH2D* hHeatSM2T3  = new TH2D("hHeatSM2T3", "", 1 , 0 , 1 , 1 , 0 , 1 ); hHeatSM2T3->SetStats(0); hHeatSM2T3->GetXaxis()->SetTickLength(0.); hHeatSM2T3->GetYaxis()->SetTickLength(0.); hHeatSM2T3->GetZaxis()->SetRangeUser(0., intgratedADCmax);

	// ~define canvas and pad

	

	// define varialbes needed
	
	// ~define varialbes needed



	// define data struct (actually, vector on vector on vector)

	// ~define data struct (actually, vector on vector on vector)



	std::vector< std::string > FilesOnDir = LoadingFiles();


	// loading data

	// fp = open ~~~

	






	

}