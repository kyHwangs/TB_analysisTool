#include <cstdio>
#include <algorithm>
#include <vector>
#include <numeric>
#include <TPad.h>
#include <TFile.h>
#include <utility>
#include <iostream>
#include <TH1.h>


void pad_set(TPad* tPad) {
    tPad->Draw();
    tPad->cd();

    tPad->SetTopMargin(0.12);
    tPad->SetLeftMargin(0.12);    
    tPad->SetRightMargin(0.12);
    tPad->SetBottomMargin(0.12);
}

void BasePeak_GenericPMT(std::string fileNum, std::string pedNum, enum runMode mode) {

      TCanvas* c = new TCanvas("c", "c", 1000, 500);

      c->cd();
      TPad* pad_LT = new TPad("pad_LT","pad_LT", 0.01, 0.01, 0.5, 0.99 );
      pad_set(pad_LT);

      c->cd();
      TPad* pad_RT = new TPad("pad_RT","pad_RT", 0.5, 0.01, 0.99, 0.99 );
      pad_set(pad_RT);

    FILE *fp;
    int file_size;
    int nevt;
    char data[64];
    short adc[32736];

    std::vector<std::vector<float>> chPed; 
    std::vector<float> tmpchPed; 
    for (int j = 0; j < NofDAQModule; j++) {
        for (int i = 0; i < 32; i++) tmpchPed.push_back(0);
        chPed.push_back(tmpchPed);
    }
    if (mode == runMode::kFull) {
        for (int j = 0; j < NofDAQModule; j++) {
            std::ifstream in;
            int i_tmp; float ped_tmp;
            in.open(BASE_DIR+SCENARIO+"/"+pedNum+"/Ped/Full/"+FILE_NAME+"_"+std::to_string(j+1)+"_"+std::string(pedNum)+".csv",std::ios::in);
            std::cout << "[FULL] loading mid" << j+1 << " ped file : " << BASE_DIR+SCENARIO+"/"+pedNum+"/Ped/Full/"+FILE_NAME+"_"+std::to_string(j+1)+"_"+std::string(pedNum)+".csv" << std::endl;

            while (true) {
                in >> i_tmp >> ped_tmp;
                if (!in.good()) break;
                chPed.at(j).at(i_tmp) = ped_tmp;
            }
            in.close();
        }
    }

    if (mode == runMode::kPrompt) {
        for (int j = 0; j < NofDAQModule; j++) {
            std::ifstream in;
            int i_tmp; float ped_tmp;
            in.open(BASE_DIR+SCENARIO+"/"+pedNum+"/Ped/Prompt/"+FILE_NAME+"_"+std::to_string(j+1)+"_"+std::string(pedNum)+".csv",std::ios::in);
            std::cout << "[PROMPT] loading mid" << j << " ped file : " << BASE_DIR+SCENARIO+"/"+pedNum+"/Ped/Prompt/"+FILE_NAME+"_"+std::to_string(j+1)+"_"+std::string(pedNum)+".csv" << std::endl;

            while (true) {
                in >> i_tmp >> ped_tmp;
                if (!in.good()) break;
                chPed.at(j).at(i_tmp) = ped_tmp;
            }
            in.close();
        }

    }

    // std::cout << mode << std::endl;
    // for (int j = 0; j < NofDAQModule; j++) { 
    //     for (int chInt = 0; chInt < chInput.at(j).size(); chInt++ ) { 
    //         std::cout << j << " " << chInput.at(j).at(chInt) << " " << chPed.at(j).at(chInput.at(j).at(chInt)) << std::endl;
    //     }
    // }

    if (mode == runMode::kCoarse) {
        std::cout << "[COARSE] Using Ped. with coarse ped. calculation" << std::endl;
    }
    



    std::vector<std::vector<TH1F*>> plotCol;

    for (int j = 0; j < NofDAQModule; j++) {
        std::vector<TH1F*> tmpPlotCol; 
        plotCol.push_back(tmpPlotCol);
        for ( int i = 0; i < chInput.at(j).size(); i++ ) {
            TH1F* plot = new TH1F((TString)("mid"+std::to_string(j+1)+" ch"+std::to_string(chInput.at(j).at(i))), 
                                  (TString)(";#font[42]{Peak (ADC)};#font[42]{# evts}"), 
                                  100, -1024., 4096.);

            plotCol.at(j).push_back(plot);
            plotCol.at(j).at(i)->SetLineWidth(1); 
            plotCol.at(j).at(i)->SetLineColor(plotColor.at(j).at(i)); 
            plotCol.at(j).at(i)->Sumw2(); 
            plotCol.at(j).at(i)->SetStats(0);
        }
    }

    for (int j = 0; j < NofDAQModule; j++) { 
        std::cout <<  "[INT] loading data file : "<< DATA_DIR+FILE_NAME+"_"+std::to_string(j+1)+"_"+fileNum+".dat" << std::endl;
        fp = fopen((DATA_DIR+FILE_NAME+"_"+std::to_string(j+1)+"_"+fileNum+".dat").c_str(), "rb");
        fseek(fp, 0L, SEEK_END);
        file_size = ftell(fp);
        fclose(fp);
        nevt = file_size / 65536;


        fp = fopen((DATA_DIR+FILE_NAME+"_"+std::to_string(j+1)+"_"+fileNum+".dat").c_str(), "rb");
        for (int evt = 0; evt < nevt; evt++) {
            fread(data, 1, 64, fp);
            fread(adc, 2, 32736, fp);

            std::vector< std::vector<int> > waveformCol;
            for (int i = 0; i < chInput.at(j).size(); i++ ) {
                std::vector<int> tmpVec;
                waveformCol.push_back(tmpVec);
            }

            if (mode == runMode::kCoarse) {
                for (int i = 0; i < chPed.at(j).size(); i++) chPed.at(j).at(i) = 0;
                float pedNbin = 50.;
                for (int promptPed = 1; promptPed < pedNbin + 1; promptPed++) {
                    for (int chInt = 0; chInt < chInput.at(j).size(); chInt++ ) {
                        chPed.at(j).at(chInput.at(j).at(chInt)) += (float)adc[promptPed * 32 + chInput.at(j).at(chInt)] / pedNbin;
                    }
                }
            }

            for (int i = 1; i < 1001; i++) {
                for (int chInt = 0; chInt < chInput.at(j).size(); chInt++ ) {
                    waveformCol.at(chInt).push_back(chPed.at(j).at(chInput.at(j).at(chInt)) - adc[i * 32 + chInput.at(j).at(chInt)]);
                }
            } 
            
            for (int chInt = 0; chInt < chInput.at(j).size(); chInt++ ) {
                plotCol.at(j).at(chInt)->Fill(*std::max_element(std::begin(waveformCol.at(chInt)), std::end(waveformCol.at(chInt))));
            }     
        }
        fclose(fp);

        c->cd(); pad_LT->cd(); 
        TLegend* leg1 = new TLegend(0.55,0.70,0.85,0.85); 
        leg1->SetFillStyle(0); leg1->SetBorderSize(0); leg1->SetTextFont( 42 ); leg1->SetTextSize( 0.045 );

        c->cd(); pad_RT->cd(); 
        TLegend* leg2 = new TLegend(0.65,0.70,0.85,0.85); 
        leg2->SetFillStyle(0); leg2->SetBorderSize(0); leg2->SetTextFont( 42 ); leg2->SetTextSize( 0.045 );

        c->cd(); pad_LT->cd(); 
        plotCol.at(j).at(1)->Draw("Hist");       leg1->AddEntry(plotCol.at(j).at(1), plotName.at(j).at(1), "l");
        plotCol.at(j).at(2)->Draw("Hist&sames"); leg1->AddEntry(plotCol.at(j).at(2), plotName.at(j).at(2), "l");
        leg1->Draw();

        c->cd(); pad_RT->cd(); 
        plotCol.at(j).at(0)->Draw("Hist");       leg2->AddEntry(plotCol.at(j).at(0), plotName.at(j).at(0), "l");  
        plotCol.at(j).at(3)->Draw("Hist&sames"); leg2->AddEntry(plotCol.at(j).at(3), plotName.at(j).at(3), "l");
        plotCol.at(j).at(4)->Draw("Hist&sames"); leg2->AddEntry(plotCol.at(j).at(4), plotName.at(j).at(4), "l");
        leg2->Draw();

        if ( mode == runMode::kFull ) {
            c->SaveAs((TString)(BASE_DIR+SCENARIO+"/"+fileNum+"/Peak/FullPed_"+FILE_NAME+"_mid"+std::to_string(j+1)+"_PeakADC.png"));
        }                       
        if ( mode == runMode::kPrompt ) {
            c->SaveAs((TString)(BASE_DIR+SCENARIO+"/"+fileNum+"/Peak/PromptPed_"+FILE_NAME+"_mid"+std::to_string(j+1)+"_PeakADC.png"));
        }
        if ( mode == runMode::kCoarse ) {
            c->SaveAs((TString)(BASE_DIR+SCENARIO+"/"+fileNum+"/Peak/CoarsePed_"+FILE_NAME+"_mid"+std::to_string(j+1)+"_PeakADC.png"));
        }
    }
}

