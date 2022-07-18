#include <stdio.h>
#include <chrono>
#include <thread>
#include <TPad.h>
#include <TLegend.h>
#include <string>
// #include <Windows.h>

void pad_set(TPad* tPad) {
    tPad->Draw();
    tPad->cd();

    tPad->SetTopMargin(0.08);
    tPad->SetLeftMargin(0.12);    
    tPad->SetRightMargin(0.08);
    tPad->SetBottomMargin(0.08);
}


void BaseWaveform_SiPM(std::string fileNum)
{
  int ch_to_plot;
  FILE *fp;
  int file_size;
  int nevt;
  char data[64];
  short adc[32736];

  TCanvas* c = new TCanvas("c", "c", 1000, 1000);
  c->cd();
  TPad* pad_LB = new TPad("pad_LB","pad_LB", 0.01, 0.01, 0.5, 0.5 );
  pad_set(pad_LB);

  c->cd();
  TPad* pad_RB = new TPad("pad_RB","pad_RB", 0.5, 0.01, 0.99, 0.5 );
  pad_set(pad_RB);

  c->cd();
  TPad* pad_LT = new TPad("pad_LT","pad_LT", 0.01, 0.5, 0.5, 0.99 );
  pad_set(pad_LT);

  c->cd();
  TPad* pad_RT = new TPad("pad_RT","pad_RT", 0.5, 0.5, 0.99, 0.99 );
  pad_set(pad_RT);

  std::vector<std::vector<TH1F*>> plotCol;

  for (int j = 0; j < NofDAQModule; j++) {
    std::vector<TH1F*> tmpPlotCol; 
    plotCol.push_back(tmpPlotCol);
    for ( int i = 0; i < 32; i++ ) {

      plotCol.at(j).push_back(
                              new TH1F((TString)("mid"+std::to_string(j+6)+" ch"+std::to_string(i)), 
                                       (TString)(";ns;ADC"), 
                                       1000, 0, 200
                                      )
                             );

      plotCol.at(j).at(i)->SetLineWidth(1); 
      plotCol.at(j).at(i)->SetLineColor(plotColor.at(0).at(i)); 
      plotCol.at(j).at(i)->GetYaxis()->SetRangeUser(0, 4096);
      plotCol.at(j).at(i)->Sumw2(); 
      plotCol.at(j).at(i)->SetStats(0);
    }
  }

  for (int j = 0; j < NofDAQModule; j++) { 
    std::cout <<  "[INT] loading data file : "<< DATA_DIR+FILE_NAME+"_"+std::to_string(j+6)+"_"+fileNum+".dat" << std::endl;

    fp = fopen((DATA_DIR+FILE_NAME+"_"+std::to_string(j+6)+"_"+fileNum+".dat").c_str(), "rb");
    fseek(fp, 0L, SEEK_END);
    file_size = ftell(fp);
    fclose(fp);
    nevt = file_size / 65536;

    fp = fopen((DATA_DIR+FILE_NAME+"_"+std::to_string(j+6)+"_"+fileNum+".dat").c_str(), "rb");

    for (int evt = 0; evt < nevt; evt++) {

      for (int i = 0; i < NofDAQModule; i++) {
        for (int j = 0; j < 32; j++) {
          plotCol.at(NofDAQModule).at(j)->Reset();
        }
      } 

      fread(data, 1, 64, fp);
      fread(adc, 2, 32736, fp);

      for (int i = 0; i < 1000; i++) {
        for (int t = 0; t < 32; t++) {
          plotCol.at(j).at(t)->Fill(i * 0.2, adc[(i + 1) * 32 + chInput.at(j).at(t)]); 
        }
      }

      c->cd(); pad_LT->cd(); TLegend* leg1 = new TLegend(0.77,0.1,0.99,0.3); leg1->SetFillStyle(0); leg1->SetBorderSize(0); leg1->SetTextFont( 42 ); leg1->SetTextSize( 0.045 );
      c->cd(); pad_RT->cd(); TLegend* leg2 = new TLegend(0.77,0.1,0.99,0.3); leg2->SetFillStyle(0); leg2->SetBorderSize(0); leg2->SetTextFont( 42 ); leg2->SetTextSize( 0.045 );
      c->cd(); pad_LB->cd(); TLegend* leg3 = new TLegend(0.77,0.1,0.99,0.3); leg3->SetFillStyle(0); leg3->SetBorderSize(0); leg3->SetTextFont( 42 ); leg3->SetTextSize( 0.045 );
      c->cd(); pad_RB->cd(); TLegend* leg4 = new TLegend(0.77,0.1,0.99,0.3); leg4->SetFillStyle(0); leg4->SetBorderSize(0); leg4->SetTextFont( 42 ); leg4->SetTextSize( 0.045 );

      for (int i = 0; i < 8; i++) {
        if ( i == 0 ) {
          c->cd(); pad_LT->cd(); plotCol.at(j).at(i     )->Draw("Hist"); leg1->AddEntry(plotCol.at(j).at(i     ), (TString)("ch"+std::to_string(i       +1)), "l");
          c->cd(); pad_RT->cd(); plotCol.at(j).at(i + 8 )->Draw("Hist"); leg2->AddEntry(plotCol.at(j).at(i + 8 ), (TString)("ch"+std::to_string(i + 8   +1)), "l");
          c->cd(); pad_LB->cd(); plotCol.at(j).at(i + 16)->Draw("Hist"); leg3->AddEntry(plotCol.at(j).at(i + 16), (TString)("ch"+std::to_string(i + 16  +1)), "l");
          c->cd(); pad_RB->cd(); plotCol.at(j).at(i + 24)->Draw("Hist"); leg4->AddEntry(plotCol.at(j).at(i + 24), (TString)("ch"+std::to_string(i + 24  +1)), "l");
        } else {
          c->cd(); pad_LT->cd(); plotCol.at(j).at(i     )->Draw("Hist&sames"); leg1->AddEntry(plotCol.at(j).at(i     ), (TString)("ch"+std::to_string(i       +1)), "l");
          c->cd(); pad_RT->cd(); plotCol.at(j).at(i + 8 )->Draw("Hist&sames"); leg2->AddEntry(plotCol.at(j).at(i + 8 ), (TString)("ch"+std::to_string(i + 8   +1)), "l");
          c->cd(); pad_LB->cd(); plotCol.at(j).at(i + 16)->Draw("Hist&sames"); leg3->AddEntry(plotCol.at(j).at(i + 16), (TString)("ch"+std::to_string(i + 16  +1)), "l");
          c->cd(); pad_RB->cd(); plotCol.at(j).at(i + 24)->Draw("Hist&sames"); leg4->AddEntry(plotCol.at(j).at(i + 24), (TString)("ch"+std::to_string(i + 24  +1)), "l");
        }

        if ( i == 7 ) {
          c->cd(); pad_LT->cd(); leg1->Draw();
          c->cd(); pad_RT->cd(); leg2->Draw();
          c->cd(); pad_LB->cd(); leg3->Draw();
          c->cd(); pad_RB->cd(); leg4->Draw();
        }
      }
      c->SaveAs((TString)(BASE_DIR+SCENARIO+"/"+fileNum+"/Waveform/"+std::to_string(j+6)+"/"+FILE_NAME+"_mid"+std::to_string(j+6)+"_"+std::to_string(evt)+"evt_waveform.png"));
      
    }
    fclose(fp);
  }
}

