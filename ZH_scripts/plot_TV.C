#include <iostream>
#include "TString.h"
#include "TH1F.h"
#include "TCanvas.h"
#include "THStack.h"
#include "TLegend.h"
#include "TPad.h"
#include "TStyle.h"
#include "TText.h"
#include "TFile.h"
#include <TLatex.h>
#include <stdio.h>
#include <cstdlib> /* mkdir */

#include <stdlib.h>     /* getenv */

TH1F* rebin(TH1F* h_TF){
  TH1F* dummy = new TH1F("N_{j}^{dis}","N_{j}^{dis}",3,-0.5,2.5) ;
  dummy->SetBinContent(1,h_TF->GetBinContent(1));
  dummy->SetBinContent(2,h_TF->GetBinContent(2));
  dummy->SetBinContent(3,h_TF->GetBinContent(3));
   
  dummy->SetBinError(1,h_TF->GetBinError(1));
  dummy->SetBinError(2,h_TF->GetBinError(2));
  dummy->SetBinError(3,h_TF->GetBinError(3));

  return dummy;
}

void plot_TV( TString path, TString infileName_, Bool_t dolog, TString s_lumi, TString description){
 //TString infileName_ = "EleMuOSOFCombo_nSelectedAODCaloJetTag_log"; 
 bool drawData   = true;
 bool hadded = false;
 if (infileName_.Contains("CaloJetTag")) hadded   = true;
 bool drawSignal = false;
 ////if (infileName_.Contains("ZH") &&  infileName_.Contains("CaloJetTag") ) {drawData = false;  drawSignal = true;}
 //if (infileName_.Contains("DY")) drawData = false;
 //bool dolog = true;

 TString infileName = infileName_; 
 TFile* infile = TFile::Open( path+infileName+".root" ) ;

// int canx = 1100;
// int cany = 1200;
// float lmarg = 0.12;
// float rmarg = 0.05;
// if(drawData) cany = 1200;
// TCanvas* canvas = new TCanvas("canvas","canvas",canx,cany);

 int canx = 1100;
 int cany = 900;
 float lmarg = 0.12;
 float rmarg = 0.05;
 if(drawData) cany = 1200;

 TCanvas* canvas = new TCanvas("canvas","canvas",canx,cany);


 gStyle->SetOptStat(0);
 gPad->SetLogy(dolog);
 gPad->SetTickx();
 gPad->SetTicky();
 gStyle->SetLineWidth(3);
 gStyle->SetPalette(kBird);
 gStyle->SetPadTickY(1);
 canvas->Clear();
 canvas->cd();

 TLatex lumi;// = new TText(1,1,"") ;
 lumi.SetTextSize(0.05);
 lumi.SetTextColor(kBlack);
 lumi.SetTextAlign(31);
 lumi.SetTextFont(42);
 
 TPad *plotpad  = new TPad("plotpad", "plotpad", 0, 0., 1, 1);
 //if(drawData) i
 plotpad->SetBottomMargin(0.12);
 plotpad->SetLeftMargin(lmarg);
 plotpad->SetRightMargin(rmarg);
 plotpad->SetFrameLineWidth(3);
 plotpad->SetLogy(dolog);
 plotpad->Draw();

 canvas->cd();

 TText* title = new TText(1,1,"") ;
 title->SetTextSize(0.06);
 title->SetTextColor(kBlack);
 title->SetTextAlign(11);
 title->SetTextFont(62);

 TText* extra = new TText(1,1,"") ;
 extra->SetTextSize(0.045);
 extra->SetTextColor(kBlack);
 extra->SetTextAlign(11);
 extra->SetTextFont(52);

 TText* extra2 = new TText(1,1,"") ;
 extra2->SetTextSize(0.03);
 extra2->SetTextColor(kBlack);
 extra2->SetTextAlign(11);
 extra2->SetTextFont(62);

// TText* lumi = new TText(1,1,"") ;
// lumi->SetTextSize(0.05);
// lumi->SetTextColor(kBlack);
// lumi->SetTextAlign(31);
// lumi->SetTextFont(42);




 TH1F* h_DY     ;
 TH1F* h_ratio     ;
 TH1F* h_ratiostaterr     ;
 TH1F* h_Data   ;
 TH1F* h_GJets  ;
 TH1F* h_ST     ;
 TH1F* h_VV     ;
 TH1F* h_VG     ;
 TH1F* h_ZH     ;
 TH1F* h_TT     ;
 TH1F* h_WJetsToLNu ;
 TH1F* h_QCD    ;
 TH1F* h_bkgtotal ;
 TH1F* h_light ;
 TH1F* h_heavy ;
 TH1F* h_other ;
 TH1F* h_light_alt ;
 TH1F* h_heavy_alt ;
 TH1F* h_other_alt ;

 TH1F* h_altDY ;
 TH1F* h_altVV ;
 TH1F* h_altTT ;


 TH1F* h_Sig_MS15ct1000 ;
 TH1F* h_Sig_MS15ct100  ;
 TH1F* h_Sig_MS15ct10   ;
 TH1F* h_Sig_MS15ct1    ;
 TH1F* h_Sig_MS40ct1000 ;
 TH1F* h_Sig_MS40ct100  ;
 TH1F* h_Sig_MS40ct10   ;
 TH1F* h_Sig_MS40ct1    ;
 TH1F* h_Sig_MS55ct1000 ;
 TH1F* h_Sig_MS55ct100  ;
 TH1F* h_Sig_MS55ct10   ;
 TH1F* h_Sig_MS55ct1    ;
 TH1F* h_Sig_MS15ct200  ;
 TH1F* h_Sig_MS15ct20   ;
 TH1F* h_Sig_MS15ct2    ;
 TH1F* h_Sig_MS40ct200  ;
 TH1F* h_Sig_MS40ct20   ;
 TH1F* h_Sig_MS40ct2    ;
 TH1F* h_Sig_MS55ct200  ;
 TH1F* h_Sig_MS55ct20   ;
 TH1F* h_Sig_MS55ct2    ;
 TH1F* h_Sig_MS15ct300  ;
 TH1F* h_Sig_MS15ct30   ;
 TH1F* h_Sig_MS15ct3    ;
 TH1F* h_Sig_MS40ct300  ;
 TH1F* h_Sig_MS40ct30   ;
 TH1F* h_Sig_MS40ct3    ;
 TH1F* h_Sig_MS55ct300  ;
 TH1F* h_Sig_MS55ct30   ;
 TH1F* h_Sig_MS55ct3    ;
 TH1F* h_Sig_MS15ct500  ;
 TH1F* h_Sig_MS15ct50   ;
 TH1F* h_Sig_MS15ct5    ;
 TH1F* h_Sig_MS40ct500  ;
 TH1F* h_Sig_MS40ct50   ;
 TH1F* h_Sig_MS40ct5    ;
 TH1F* h_Sig_MS55ct500  ;
 TH1F* h_Sig_MS55ct50   ;
 TH1F* h_Sig_MS55ct5    ;

 TH1F* h_Sig_4d_MS15ct1000 ;
 TH1F* h_Sig_4d_MS15ct100  ;
 TH1F* h_Sig_4d_MS15ct10   ;
 TH1F* h_Sig_4d_MS40ct1000 ;
 TH1F* h_Sig_4d_MS40ct100  ;
 TH1F* h_Sig_4d_MS40ct10   ;
 TH1F* h_Sig_4d_MS40ct1    ;
 TH1F* h_Sig_4d_MS55ct1000 ;
 TH1F* h_Sig_4d_MS55ct100  ;
 TH1F* h_Sig_4d_MS55ct10   ;
 TH1F* h_Sig_4d_MS55ct1    ;
 TH1F* h_Sig_4d_MS15ct200  ;
 TH1F* h_Sig_4d_MS15ct20   ;
 TH1F* h_Sig_4d_MS15ct2    ;
 TH1F* h_Sig_4d_MS40ct200  ;
 TH1F* h_Sig_4d_MS40ct20   ;
 TH1F* h_Sig_4d_MS40ct2    ;
 TH1F* h_Sig_4d_MS55ct200  ;
 TH1F* h_Sig_4d_MS55ct20   ;
 TH1F* h_Sig_4d_MS55ct2    ;
 TH1F* h_Sig_4d_MS15ct300  ;
 TH1F* h_Sig_4d_MS15ct30   ;
 TH1F* h_Sig_4d_MS15ct3    ;
 TH1F* h_Sig_4d_MS40ct300  ;
 TH1F* h_Sig_4d_MS40ct30   ;
 TH1F* h_Sig_4d_MS40ct3    ;
 TH1F* h_Sig_4d_MS55ct300  ;
 TH1F* h_Sig_4d_MS55ct30   ;
 TH1F* h_Sig_4d_MS55ct3    ;
 TH1F* h_Sig_4d_MS15ct500  ;
 TH1F* h_Sig_4d_MS15ct50   ;
 TH1F* h_Sig_4d_MS15ct5    ;
 TH1F* h_Sig_4d_MS40ct500  ;
 TH1F* h_Sig_4d_MS40ct50   ;
 TH1F* h_Sig_4d_MS40ct5    ;
 TH1F* h_Sig_4d_MS55ct500  ;
 TH1F* h_Sig_4d_MS55ct50   ;
 TH1F* h_Sig_4d_MS55ct5    ;

 TH1F* h_Sig_4Tau_MS15ct1000 ;
 TH1F* h_Sig_4Tau_MS15ct100  ;
 TH1F* h_Sig_4Tau_MS15ct10   ;
 TH1F* h_Sig_4Tau_MS15ct1    ;
 TH1F* h_Sig_4Tau_MS40ct1000 ;
 TH1F* h_Sig_4Tau_MS40ct100  ;
 TH1F* h_Sig_4Tau_MS40ct10   ;
 TH1F* h_Sig_4Tau_MS40ct1    ;
 TH1F* h_Sig_4Tau_MS55ct1000 ;
 TH1F* h_Sig_4Tau_MS55ct100  ;
 TH1F* h_Sig_4Tau_MS55ct10   ;
 TH1F* h_Sig_4Tau_MS55ct1    ;



h_Sig_MS55ct1     = (TH1F*)infile->Get("Sig_MS55ct1")   ->Clone( "h_Sig_MS55ct1") ;
h_Sig_MS55ct10    = (TH1F*)infile->Get("Sig_MS55ct10")  ->Clone( "h_Sig_MS55ct10") ;
h_Sig_MS55ct100   = (TH1F*)infile->Get("Sig_MS55ct100") ->Clone( "h_Sig_MS55ct100") ;
h_Sig_MS55ct1000  = (TH1F*)infile->Get("Sig_MS55ct1000")->Clone( "h_Sig_MS55ct1000") ;

h_Sig_MS40ct10    = (TH1F*)infile->Get("Sig_MS40ct10") ->Clone( "h_Sig_MS40ct10") ;
h_Sig_MS15ct10    = (TH1F*)infile->Get("Sig_MS15ct10")->Clone( "h_Sig_MS15ct10") ;

h_bkgtotal        = (TH1F*)infile->Get("bkgtotal")->Clone( "h_bkgtotal") ;

h_Data            = (TH1F*)infile->Get("Data")->Clone( "h_Data") ;


h_bkgtotal->SetFillColorAlpha(kCyan, 0.7);
h_bkgtotal->SetFillStyle(1001);
h_Data->SetFillColorAlpha(kCyan, 0.7);
h_Data->SetFillStyle(1001);

std::cout<<"Set Attributes"<<std::endl;

std::cout<<"Set Attributes"<<std::endl;
std::cout<<"2-tag Bin: "<<h_bkgtotal->GetBinContent(3)<<" +/ -"<<h_bkgtotal->GetBinError(3)<<std::endl;

double rel_unc=0.0;
//for ( int i  = 1; i <= h_Data->GetNbinsX(); i++ )
//{
//  std::cout<<"Before:   "<< h_Data->GetBinError(i) <<std::endl;
//  std::cout<<"sqrt      "<< sqrt(h_Data->GetBinContent(i)) <<std::endl;
//  rel_unc = h_Data->GetBinError(i)/sqrt(h_Data->GetBinContent(i));
//  h_Data->SetBinError(i,rel_unc);
//  std::cout<< rel_unc <<std::endl;
//}


h_bkgtotal->Scale(1.0/h_bkgtotal->Integral(0,-1));
h_Data->Scale(1.0/h_Data->Integral(0,-1));
h_Sig_MS55ct1->Scale(1.0/h_Sig_MS55ct1->Integral(0,-1));
h_Sig_MS55ct10->Scale(1.0/h_Sig_MS55ct10->Integral(0,-1));
h_Sig_MS55ct100->Scale(1.0/h_Sig_MS55ct100->Integral(0,-1));
h_Sig_MS55ct1000->Scale(1.0/h_Sig_MS55ct1000->Integral(0,-1));


//for ( int i  = 1; i <= h_Data->GetNbinsX(); i++ )
//{
//  std::cout<<"Before:   "<< h_Data->GetBinError(i) <<std::endl;
//  std::cout<<"sqrt      "<< sqrt(h_Data->GetBinContent(i)) <<std::endl;
//  rel_unc = sqrt(h_Data->GetBinContent(i));
//  h_Data->SetBinError(i,rel_unc);
//  std::cout<< rel_unc <<std::endl;
//}
     canvas->cd();  
 
   
     TLegend *sigleg = new TLegend(0.2,0.74,0.9,0.82);
       sigleg->SetBorderSize(0);
       sigleg->SetNColumns(2);
       sigleg->SetFillColor(kWhite);
       sigleg->AddEntry(h_Sig_MS55ct1     , "c#tau_{S} = 1 mm", "l");
       sigleg->AddEntry(h_Sig_MS55ct10    , "c#tau_{S} = 10 mm", "l");
       sigleg->AddEntry(h_Sig_MS55ct100   , "c#tau_{S} = 100 mm", "l");
       sigleg->AddEntry(h_Sig_MS55ct1000  , "c#tau_{S} = 1000 mm", "l");

     TLegend *leg;
     leg = new TLegend(0.65,0.64,0.9,0.72);
     leg->SetBorderSize(0);
     leg->SetNColumns(1);
     leg->SetFillColor(kWhite);
     leg->AddEntry(h_Data     , "Data", "pe");

     //TMarker *m_data = new TMarker(0.65, 0.9, 20);
     TMarker *m_data = new TMarker(0.68135, 4.785, 20);
     //std::cout<<"Here: "<<canvas->GetWindowTopX()<<std::endl;
     //std::cout<<"Here: "<<canvas->GetWindowTopY()<<std::endl;
     //std::cout<<"Here: "<<plotpad->GetAbsXlowNDC()<<std::endl;
     //std::cout<<"Here: "<<plotpad->GetAbsYlowNDC()<<std::endl;
     m_data->SetMarkerStyle(20);
     m_data->SetMarkerSize(2);

     leg->Draw();
     sigleg->Draw();
     m_data->Draw();
     Double_t ymax;
     ymax = std::max(h_Data->GetMaximum(), h_bkgtotal->GetMaximum() );
     //ymax = h_bkgtotal->GetMaximum() ;
     
     if(dolog){
      if(drawSignal)h_bkgtotal->SetMaximum(60000*ymax); 
      else h_bkgtotal->SetMaximum(1.2); 
      h_bkgtotal->SetMinimum(1.0e-3);
     }    
     else {
      h_bkgtotal->SetMaximum(ymax*10.);
     }    
     if(dolog){
      if(drawSignal)h_Data->SetMaximum(60000*ymax); 
      else h_Data->SetMaximum(1.2); 
      h_Data->SetMinimum(1.0e-3);
     }    
     else {
      h_Data->SetMaximum(ymax*10.);
     }    

     h_Data->SetMaximum(1.4);    
     h_Sig_MS55ct1->SetMaximum(1.4);
     if(dolog &&  infileName.Contains("Alpha") )h_Sig_MS55ct1->SetMinimum(1.0e-3);    
     if(dolog &&  infileName.Contains("IPSig") )h_Sig_MS55ct1->SetMinimum(2.0e-3);    
     if(dolog &&  infileName.Contains("TrackAngle") )h_Sig_MS55ct1->SetMinimum(1.5e-3);    
 
     h_Sig_MS55ct1   ->SetLineColor(kRed);
     h_Sig_MS55ct10  ->SetLineColor(kTeal+4);
     h_Sig_MS55ct100 ->SetLineColor(kViolet);
     h_Sig_MS55ct1000->SetLineColor(kBlue);
     
     h_Sig_MS55ct1   ->SetLineWidth(4);
     h_Sig_MS55ct10  ->SetLineWidth(4);
     h_Sig_MS55ct100 ->SetLineWidth(4);
     h_Sig_MS55ct1000->SetLineWidth(4);
     
     h_Sig_MS55ct1   ->SetLineStyle(1);
     h_Sig_MS55ct10  ->SetLineStyle(1);
     h_Sig_MS55ct100 ->SetLineStyle(1);
     h_Sig_MS55ct1000->SetLineStyle(1);



      plotpad->cd();
       if     ( infileName.Contains("TrackAngle") ) h_bkgtotal->SetTitle("#hat{#Theta}^{2D}");
       else if( infileName.Contains("IPSig") )      h_bkgtotal->SetTitle("#hat{IP}^{2D}_{sig}");
       else if( infileName.Contains("Alpha") )      h_bkgtotal->SetTitle("#alpha_{max}");
       if     ( infileName.Contains("Alpha") )      h_bkgtotal->GetXaxis()->SetRangeUser(0.,1.0);
       if     ( infileName.Contains("TrackAngle") ) h_bkgtotal->GetXaxis()->SetRangeUser(-5.,0.25);
       if     ( infileName.Contains("IPSig") )      h_bkgtotal->GetXaxis()->SetRangeUser(-3.,3);
                                                    //h_bkgtotal->GetXaxis()->CenterTitle(kTRUE);
       if     ( infileName.Contains("TrackAngle") ) h_Data->SetTitle("#hat{#Theta}^{2D}");
       else if( infileName.Contains("IPSig") )      h_Data->SetTitle("#hat{IP}^{2D}_{sig}");
       else if( infileName.Contains("Alpha") )      h_Data->SetTitle("#alpha_{max}");
       if     ( infileName.Contains("Alpha") )      h_Data->GetXaxis()->SetRangeUser(0.,1.0);
       if     ( infileName.Contains("TrackAngle") ) h_Data->GetXaxis()->SetRangeUser(-3.25,0.25);
       if     ( infileName.Contains("IPSig") )      h_Data->GetXaxis()->SetRangeUser(-1.5,3.1);

      float g_x [h_Data->GetNbinsX()];  
      float g_y [h_Data->GetNbinsX()];  
      float g_ex[h_Data->GetNbinsX()];  
      float g_ey[h_Data->GetNbinsX()];  
      for(int i =0; i<h_Data->GetNbinsX(); i++){
        g_x[i]  = h_Data->GetBinCenter(i+1);
        g_y[i]  = h_Data->GetBinContent(i+1);
        g_ex[i] = 0.0;
        g_ey[i] = h_Data->GetBinError(i+1);
      }
      TGraphErrors* g_Data = new TGraphErrors(h_Data->GetNbinsX(), g_x, g_y, g_ex, g_ey);   
      double x,y;
      g_Data->GetPoint(5,x,y); 
      std::cout<<x<<"  "<<y<<std::endl;
      std::cout<<h_Data->GetBinCenter(6)<<"  "<<h_Data->GetBinContent(6)<<std::endl;
      if     ( infileName.Contains("Alpha") )      g_Data->GetXaxis()->SetLimits(0.,1.0);
      if     ( infileName.Contains("TrackAngle") ) g_Data->GetXaxis()->SetLimits(-3.25,0.25);
      if     ( infileName.Contains("IPSig") )      g_Data->GetXaxis()->SetLimits(-1.5,3.1);
      if     ( infileName.Contains("Alpha") )      h_Sig_MS55ct1->GetXaxis()->SetRangeUser(0.,1.0);
      if     ( infileName.Contains("TrackAngle") ) h_Sig_MS55ct1->GetXaxis()->SetRangeUser(-3.25,0.25);
      if     ( infileName.Contains("IPSig") )      h_Sig_MS55ct1->GetXaxis()->SetRangeUser(-1.5,3.1);
      g_Data->SetMarkerStyle(20);
      g_Data->SetMarkerSize(2);


      //h_bkgtotal->Draw("hist");
      h_Data->Draw("E1");
      h_Sig_MS55ct1->Draw("hist");
      h_Sig_MS55ct10->Draw("hist sames");
      h_Sig_MS55ct100->Draw("hist sames");
      h_Sig_MS55ct1000->Draw("hist sames");
      g_Data->Draw("P sames");
      TArrow *arrow;
      TLine *l;//=new TLine(0.6,canvas->GetUymin(),0.6,canvas->GetUymax());
      if( infileName.Contains("Alpha"))     {arrow = new TArrow(0.45,0.1,0.375,0.1, 0.02); l=new TLine(0.45,canvas->GetUymin(),0.45,0.6*canvas->GetUymax());}
      if( infileName.Contains("TrackAngle")){arrow = new TArrow(-1.5,0.2,-1.25,0.2, 0.02); l=new TLine(-1.5,canvas->GetUymin(),-1.5,0.6*canvas->GetUymax());}
      if( infileName.Contains("IPSig"))     {arrow = new TArrow(1.25,0.14,1.5,0.14, 0.02);   l=new TLine(1.25,canvas->GetUymin(),1.25,0.6*canvas->GetUymax());}
      l->SetLineColor(kBlack);
      l->Draw();
      arrow->Draw();
      gPad->RedrawAxis();

  float cmsSize = 0.06;
  float lumifont = 42; 

  TLatex t;
  t.SetTextColor(kBlack);
  t.SetTextFont(lumifont);
  t.SetTextSize(0.6*cmsSize);
  if( infileName.Contains("Alpha"))      t.DrawLatex(0.1 , 0.9,"Signal: ZH; H#rightarrow SS; S#rightarrow bb; M_{S} = 55 GeV");
  if( infileName.Contains("TrackAngle")) t.DrawLatex(-3.1, 0.9,"Signal: ZH; H#rightarrow SS; S#rightarrow bb; M_{S} = 55 GeV");
  if( infileName.Contains("IPSig"))      t.DrawLatex(-1.3, 0.9,"Signal: ZH; H#rightarrow SS; S#rightarrow bb; M_{S} = 55 GeV");

       //if     (infileName.Contains("TwoEleZH"))       h_bkgtotal->GetXaxis()->SetTitle("SR (High ZPt):        "      +(TString)h_bkgtotal->GetTitle());
       //else if(infileName.Contains("TwoEleDY"))       h_bkgtotal->GetXaxis()->SetTitle("Z(e^{+}e^{-})_{low-p_{T}}:        "  +(TString)h_bkgtotal->GetTitle());
       ////else if(infileName.Contains("eemumu"))         h_bkgtotal->GetXaxis()->SetTitle("Z(\\ell^{+}\\ell^{-})_{low-p_{T}}:\\ \\  \\:        "  +(TString)h_bkgtotal->GetTitle());
       //else if(infileName.Contains("eemumu"))         h_bkgtotal->GetXaxis()->SetTitle("Z(\\ell^{+}\\ell^{-}) Inclusive Zpt:\\ \\  \\        dilepton Pt    "+description );
       //else if(infileName.Contains("TwoMuZH")){
       //                                         if(hadded) h_bkgtotal->GetXaxis()->SetTitle("Z(\\ell^{+}\\ell^{-})_{high-p_{T}}:\\ \\  \\     "        +(TString)h_bkgtotal->GetTitle());
       //                                         else       h_bkgtotal->GetXaxis()->SetTitle("Z(#mu^{+}#mu^{-})_{high-p_{T}}:        "      +(TString)h_bkgtotal->GetTitle());
       //                                       }
       //else if(infileName.Contains("TwoMuDY")){
       //                                         if(hadded) h_bkgtotal->GetXaxis()->SetTitle("Z(\\ell^{+}\\ell^{-})_{low-p_{T}}:\\ \\  \\     "        +(TString)h_bkgtotal->GetTitle());
       //                                         else       h_bkgtotal->GetXaxis()->SetTitle("Z(#mu{^+}#mu^{-})_{low-p_{T}}:        "      +(TString)h_bkgtotal->GetTitle());
       //                                       }
       //else if(infileName.Contains("EleMuOSOF_"))     h_bkgtotal->GetXaxis()->SetTitle("TopCR (High Pt):        "      +(TString)h_bkgtotal->GetTitle());
       //else if(infileName.Contains("EleMuOSOFCombo")) h_bkgtotal->GetXaxis()->SetTitle("TopCR             "      +(TString)h_bkgtotal->GetTitle());
       //else if(infileName.Contains("EleMuOSOFL"))     h_bkgtotal->GetXaxis()->SetTitle("TopCR (Low Pt):        "      +(TString)h_bkgtotal->GetTitle());
       //else if(infileName.Contains("TwoEleOffZ"))     h_bkgtotal->GetXaxis()->SetTitle("TwoEle Inclusive Zpt:        "+(TString)h_bkgtotal->GetTitle());
       //else if(infileName.Contains("TwoMuOffZ"))      h_bkgtotal->GetXaxis()->SetTitle("TwoMu  Inclusive Zpt:        "+(TString)h_bkgtotal->GetTitle());
       //else                                   
       //h_bkgtotal->GetXaxis()->SetTitle("SR (High ZPt):    "+(TString)h_DY->GetTitle());
    

     h_bkgtotal->GetXaxis()->SetTitle((TString)h_bkgtotal->GetTitle());
     h_Data->GetXaxis()->SetTitle((TString)h_Data->GetTitle());
     h_Sig_MS55ct1->GetXaxis()->SetTitle((TString)h_Data->GetTitle());
     //h_Data->GetXaxis()->SetTitle("Test");
     
     title->DrawTextNDC(0.12,0.905,"CMS");
     //extra->DrawTextNDC(0.28,0.91,"Preliminary");
     TString lumiText = "117 fb^{-1} (13 TeV)";
     if     ( infileName.Contains("Alpha"))      lumi.DrawLatex(0.99,1.5,lumiText);
     else if( infileName.Contains("TrackAngle")) lumi.DrawLatex(0.3,1.5,lumiText);
     else if( infileName.Contains("IPSig"))      lumi.DrawLatex(3.1,1.5,lumiText);
     else                                   lumi.DrawLatex(0.99,1.5,lumiText);

     h_Data->GetYaxis()->SetTitle("Probability");//"Events (a.u.)");
     h_Data->GetYaxis()->SetTitleSize(40);
     h_Data->GetYaxis()->SetTitleFont(43);
     h_Data->GetYaxis()->SetTitleOffset(1.2);
     h_Data->SetTitle("");
     h_Data->GetXaxis()->SetLabelFont(43); //43 Absolute font size in pixel (precision 3)
     h_Data->GetXaxis()->SetLabelSize(45);//20
     
     h_Sig_MS55ct1->GetYaxis()->SetTitle("Probability");//"Events (a.u.)");
     h_Sig_MS55ct1->GetYaxis()->SetTitleSize(40);
     h_Sig_MS55ct1->GetYaxis()->SetTitleFont(43);
     h_Sig_MS55ct1->GetYaxis()->SetTitleOffset(1.2);
     h_Sig_MS55ct1->SetTitle("");
     h_Sig_MS55ct1->GetXaxis()->SetLabelFont(43); //43 Absolute font size in pixel (precision 3)
     h_Sig_MS55ct1->GetXaxis()->SetLabelSize(45);//20


     h_bkgtotal->GetYaxis()->SetTitle("Events (a.u.)");
     h_bkgtotal->GetYaxis()->SetTitleSize(40);
     h_bkgtotal->SetTitle("");
     h_bkgtotal->GetYaxis()->SetTitleFont(43);
     h_bkgtotal->GetYaxis()->SetTitleOffset(1.45);
     h_bkgtotal->GetXaxis()->SetTitleOffset(1.45);
     h_bkgtotal->GetXaxis()->SetLabelFont(43); //43 Absolute font size in pixel (precision 3)
     h_bkgtotal->GetXaxis()->SetLabelSize(35);//20


     if( infileName.Contains("Alpha")) {h_Data->GetXaxis()->SetTitleSize(0.07); h_Data->GetXaxis()->SetTitleOffset(0.8);}
     if( infileName.Contains("IPSig")) {h_Data->GetXaxis()->SetTitleSize(0.05); h_Data->GetXaxis()->SetTitleOffset(1.0);}
     if( infileName.Contains("Angle")) {h_Data->GetXaxis()->SetTitleSize(0.05); h_Data->GetXaxis()->SetTitleOffset(1.0);}
     h_Data->GetYaxis()->SetTitleSize(50);

     if( infileName.Contains("Alpha")) {h_Sig_MS55ct1->GetXaxis()->SetTitleSize(0.07); h_Sig_MS55ct1->GetXaxis()->SetTitleOffset(0.8);}
     if( infileName.Contains("IPSig")) {h_Sig_MS55ct1->GetXaxis()->SetTitleSize(0.05); h_Sig_MS55ct1->GetXaxis()->SetTitleOffset(1.0);}
     if( infileName.Contains("Angle")) {h_Sig_MS55ct1->GetXaxis()->SetTitleSize(0.05); h_Sig_MS55ct1->GetXaxis()->SetTitleOffset(1.0);}
     h_Sig_MS55ct1->GetYaxis()->SetTitleSize(50);
     plotpad->Update();
     canvas->Update();
     std::cout<<"Here2: "<<canvas->GetWindowTopX()<<std::endl;
     std::cout<<"Here2: "<<canvas->GetWindowTopY()<<std::endl;

     if(infileName_.Contains("CaloJetTag")) {
       if(dolog) canvas->SaveAs("SigPlots_2/"+infileName_+"_log.png");
       else      canvas->SaveAs("SigPlots_2/"+infileName_+".png");
     }
       if(dolog) canvas->SaveAs("SigPlots_2/"+infileName_+"_log.pdf");
       else      canvas->SaveAs("SigPlots_2/"+infileName_+".png");
}
