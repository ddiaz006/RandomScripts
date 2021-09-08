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

#include <stdlib.h> 


bool AddCMS( TCanvas* C )
{
//CMS STANDARD
  TString CMSText = "CMS";
  TString extraText   = "";//"Preliminary";
  TString lumiText = "117 fb^{-1} (13 TeV)";
  C->cd();
  float lumix = 0.955;
  float lumiy = 0.945;
  float lumifont = 42;

  float cmsx = 0.25;
  float cmsy = 0.94;
  float cmsTextFont   = 61;  // default is helvetic-bold
  float extrax = cmsx +0.20;
  float extray = cmsy;
  float extraTextFont = 52;  // default is helvetica-italics
  // ratio of "CMS" and extra text size
  float extraOverCmsTextSize  = 0.76;
  float cmsSize = 0.06;
  TLatex latex;
  latex.SetNDC();
  latex.SetTextAngle(0);
  latex.SetTextColor(kBlack);
  float extraTextSize = extraOverCmsTextSize*cmsSize;
  latex.SetTextFont(lumifont);
  latex.SetTextAlign(31);
  latex.SetTextSize(cmsSize);
  latex.DrawLatex(lumix, lumiy,lumiText);

  latex.SetTextFont(cmsTextFont);
  latex.SetTextAlign(31);
  latex.SetTextSize(cmsSize);
  latex.DrawLatex(cmsx, cmsy, CMSText);

  latex.SetTextFont(extraTextFont);
  latex.SetTextAlign(31);
  latex.SetTextSize(extraTextSize);
  latex.DrawLatex(extrax, extray, extraText);
  return true;
};


void YuriPlot(){

  const float axisTitleSize = 0.06;
  const float axisTitleOffset = .8; 
  
  const float axisTitleSizeRatioX   = 0.18;
  const float axisLabelSizeRatioX   = 0.23;
  const float axisTitleOffsetRatioX = 0.94;
  
  const float axisTitleSizeRatioY   = 0.15;
  const float axisLabelSizeRatioY   = 0.09;
  const float axisTitleOffsetRatioY = 0.45;
  
  const float RatioYMin = 0.0;//0.0;//0.0; //0.4;
  const float RatioYMax = 2.1;//2.5;//2.5; //1.6;
  
  //Margins
  const float leftMargin   = 0.16;
  const float rightMargin  = 0.05;
  const float topMargin    = 0.07;
  const float bottomMargin = 0.12;


  TH1F* Data  = new TH1F("Data",  "Data" , 8, -0.5, 7.5);
  TH1F* heavy = new TH1F("heavy", "heavy", 8, -0.5, 7.5);
  TH1F* light = new TH1F("light", "light", 8, -0.5, 7.5);
  TH1F* other = new TH1F("other", "other", 8, -0.5, 7.5);
  TH1F* total = new TH1F("total", "total", 8, -0.5, 7.5);
  TH1F* signal_55= new TH1F("signal_55", "signal_55", 8, -0.5, 7.5);
  TH1F* signal_15= new TH1F("signal_15", "signal_15", 8, -0.5, 7.5);
  THStack* stack = new THStack( "stack" , "stack" );

  signal_55->SetBinContent(8,168.02626); signal_55->SetBinError(8,0.0);
  signal_55->SetBinContent(3,14.647618); signal_55->SetBinError(3,0.0);
  signal_55->SetBinContent(4,3.8798301); signal_55->SetBinError(4,0.0);
  signal_55->SetBinContent(2,104.39426); signal_55->SetBinError(2,0.0);
  signal_55->SetBinContent(5,0.0);       signal_55->SetBinError(5,0.0);
  signal_55->SetBinContent(6,0.0);       signal_55->SetBinError(6,0.0);
  signal_55->SetBinContent(1,43.23861);  signal_55->SetBinError(1,0.0);
  signal_55->SetBinContent(7,0.0);       signal_55->SetBinError(7,0.0);

  signal_15->SetBinContent(8,56.904633);    signal_15->SetBinError(8,0.0);
  signal_15->SetBinContent(3,25.629076);    signal_15->SetBinError(3,0.0);
  signal_15->SetBinContent(4,2.18885881);   signal_15->SetBinError(4,0.0);
  signal_15->SetBinContent(2,127.92859);    signal_15->SetBinError(2,0.0);
  signal_15->SetBinContent(5,0.0);          signal_15->SetBinError(5,0.0);
  signal_15->SetBinContent(6,0.0021673278); signal_15->SetBinError(6,0.0);
  signal_15->SetBinContent(1,47.978035);    signal_15->SetBinError(1,0.0);
  signal_15->SetBinContent(7,0.0);          signal_15->SetBinError(7,0.0);

  Data->SetBinContent(8, 3.);      Data->SetBinError(8, 2.918186);
  Data->SetBinContent(3, 42.);     Data->SetBinError(3, 7.53218);
  Data->SetBinContent(4, 25.);     Data->SetBinError(4, 6.066589);
  Data->SetBinContent(2, 67205.);  Data->SetBinError(2, 260.2406);
  Data->SetBinContent(5, 4.);      Data->SetBinError(5, 3.162753);
  Data->SetBinContent(6, 15.);     Data->SetBinError(6, 4.958738);
  Data->SetBinContent(1, 672649.); Data->SetBinError(1, 821.1522);
  Data->SetBinContent(7, 2.);      Data->SetBinError(7, 2.63786);

  Double_t v_x  [8] = {0,1,2,3,4,5,6,7};
  Double_t v_elx[8] = {0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5};
  Double_t v_ehx[8] = {0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5};
  //normal order V1-V7, SR
  //Double_t v_y  [8] = {42.,25.,67205.,4.,15.,672649.,2.,3.};
  //Double_t v_ely[8] = {6.454831,4.966335,259.2386,1.914339,3.82938, 820.1516,1.291815,1.632705 };
  //Double_t v_ehy[8] = {7.53218 ,6.066589,260.2406,3.162753,4.958738,821.1522,2.63786, 2.918186};
  //Mod order          6         3        1        2        4        5        7        8
  Double_t v_y  [8] = {672649.  ,67205.  ,42.     ,25.     ,4.      ,15.     ,2.      ,3.};
  Double_t v_ely[8] = {820.1516 ,259.2386,6.454831,4.966335,1.914339,3.82938 ,1.291815,1.632705 };
  Double_t v_ehy[8] = {821.1522 ,260.2406,7.53218 ,6.066589,3.162753,4.958738,2.63786 ,2.918186};
  
  
  
  
  

  TGraphAsymmErrors* data = new TGraphAsymmErrors(8,v_x, v_y, v_elx, v_ehx, v_ely, v_ehy);
  heavy->SetBinContent(8, 0.4646396);    heavy->SetBinError(8,0.4321173);
  heavy->SetBinContent(3, 11.53099);     heavy->SetBinError(3,1.412789);
  heavy->SetBinContent(4, 2.000473);     heavy->SetBinError(4,0.9590909);
  heavy->SetBinContent(2, 10664.);       heavy->SetBinError(2,88.43134);
  heavy->SetBinContent(5, 0.0);          heavy->SetBinError(5,0.0);
  heavy->SetBinContent(6, 0.0);          heavy->SetBinError(6,0.0);
  heavy->SetBinContent(1, 15168.53);     heavy->SetBinError(1,233.6577);
  heavy->SetBinContent(7, 0.0);          heavy->SetBinError(7,0.0);

  light->SetBinContent(8, 2.947021);    light->SetBinError(8,1.762373);
  light->SetBinContent(3, 32.2637);     light->SetBinError(3,6.605161);
  light->SetBinContent(4, 24.20566);    light->SetBinError(4,5.330073);
  light->SetBinContent(2, 54756.61);    light->SetBinError(2,338.0315);
  light->SetBinContent(5, 2.90372);     light->SetBinError(5,1.690863);
  light->SetBinContent(6, 13.2178);     light->SetBinError(6,3.738364);
  light->SetBinContent(1, 644432.9);    light->SetBinError(1,1569.438);
  light->SetBinContent(7, 1.582846);    light->SetBinError(7,1.145305);

  other->SetBinContent(8, 0.006808776);  other->SetBinError(8,0.001837889);
  other->SetBinContent(3, 1.337789);     other->SetBinError(3,0.7124419);
  other->SetBinContent(4, 0.2950748);    other->SetBinError(4,0.2020908);
  other->SetBinContent(2, 1265.989);     other->SetBinError(2,38.55132);
  other->SetBinContent(5, 0.1161336);    other->SetBinError(5,0.08682292);
  other->SetBinContent(6, 0.002734099);  other->SetBinError(6,0.001248643);
  other->SetBinContent(1, 11537.71);     other->SetBinError(1,285.4911);
  other->SetBinContent(7, 0.0001045591); other->SetBinError(7,2.102323e-06);

  total->SetBinContent(8, light->GetBinContent(8)+heavy->GetBinContent(8)+other->GetBinContent(8) );
  total->SetBinContent(3, light->GetBinContent(3)+heavy->GetBinContent(3)+other->GetBinContent(3) );
  total->SetBinContent(4, light->GetBinContent(4)+heavy->GetBinContent(4)+other->GetBinContent(4) );
  total->SetBinContent(2, light->GetBinContent(2)+heavy->GetBinContent(2)+other->GetBinContent(2) );
  total->SetBinContent(5, light->GetBinContent(5)+heavy->GetBinContent(5)+other->GetBinContent(5) );
  total->SetBinContent(6, light->GetBinContent(6)+heavy->GetBinContent(6)+other->GetBinContent(6) );
  total->SetBinContent(1, light->GetBinContent(1)+heavy->GetBinContent(1)+other->GetBinContent(1) );
  total->SetBinContent(7, light->GetBinContent(7)+heavy->GetBinContent(7)+other->GetBinContent(7) );

  total->SetBinError(8, 1.77261);
  total->SetBinError(3, 6.44013);
  total->SetBinError(4, 5.24327);
  total->SetBinError(2, 338.853);
  total->SetBinError(5, 1.70120);
  total->SetBinError(6, 3.73843);
  total->SetBinError(1, 1518.73);
  total->SetBinError(7, 1.14531);

  Data->GetXaxis()->SetBinLabel(8, "SS");
  Data->GetXaxis()->SetBinLabel(1, "VS1");
  Data->GetXaxis()->SetBinLabel(2, "VS2");
  Data->GetXaxis()->SetBinLabel(3, "VS3");
  Data->GetXaxis()->SetBinLabel(4, "VS4");
  Data->GetXaxis()->SetBinLabel(5, "VS5");
  Data->GetXaxis()->SetBinLabel(6, "VS6");
  Data->GetXaxis()->SetBinLabel(7, "VS7");

  //cosmetics for light
  light->SetFillColor(kRed-8);
  light->SetLineColor(kRed-8);
  //cosmetics for heavy
  heavy->SetFillColor(kOrange+6);
  heavy->SetLineColor(kOrange+6);
  //cosmetics for other
  other->SetFillColor(kAzure+6);
  other->SetLineColor(kAzure+6);
 
  //cosmetics for data
  Data->SetLineColor(kBlack);
  Data->SetMarkerColor(kBlack);
  Data->SetLineWidth(2);
  Data->SetMarkerSize(1.5);
  Data->SetMarkerStyle(20);
  
  data->SetLineColor(kBlack);
  data->SetMarkerColor(kBlack);
  data->SetLineWidth(2);
  data->SetMarkerSize(1.5);
  data->SetMarkerStyle(20);
 
  stack->Add( other, "histo" );
  stack->Add( heavy, "histo" );
  stack->Add( light, "histo" );


  TCanvas* c1 = new TCanvas( "c", "c", 2119, 33, 800, 700 );
  c1->SetHighLightColor(2);
  c1->SetFillColor(0);
  c1->SetBorderMode(0);
  c1->SetBorderSize(2);
  c1->SetLeftMargin( leftMargin );
  c1->SetRightMargin( rightMargin );
  c1->SetTopMargin( topMargin );
  c1->SetBottomMargin( bottomMargin );
  c1->SetFrameBorderMode(0);
  c1->SetFrameBorderMode(0);
  c1->cd();

  TPad *pad1 = new TPad("pad1","pad1", 0.0, 0.3, 1., 1.);
  pad1->SetBottomMargin(0.01);
  pad1->SetRightMargin( rightMargin );
  pad1->SetLeftMargin( leftMargin );
  pad1->Draw();
  pad1->cd();
  pad1->SetLogy();
  stack->SetMaximum(10000000.*Data->GetBinContent(1));
  stack->SetMinimum(1e-3);
  stack->SetTitle("");

  //Plot Stack Here
  stack->Draw();
  stack->GetYaxis()->SetTitle("Events");
  stack->GetYaxis()->SetTitleSize( 0.5*axisTitleSizeRatioY );
  signal_15->Draw("hist sames");
  signal_55->Draw("hist sames");
  data->Draw("P sames");
  TH1F* ratio  = new TH1F( *Data );
  TH1F* ratio2 = new TH1F( *Data );
  TH1F* ratio3 = new TH1F( *Data );
  TH1F* pulls;

  stack->GetYaxis()->SetLabelSize(0.65*axisLabelSizeRatioY );
 
  TLegend* leg = new TLegend( 0.63, 0.5, 0.88, 0.88, NULL, "brNDC" );
  leg->SetBorderSize(0);
  leg->SetLineColor(1);
  leg->SetLineStyle(1);
  leg->SetLineWidth(1);
  leg->SetFillColor(0);
  leg->SetFillStyle(1001);
  leg->SetTextSize(0.06);
  leg->AddEntry( Data, "Data", "lep" );
  leg->AddEntry( light, "Z/#gamma^{*}", "f" );
  leg->AddEntry( heavy, "t#bar{t} and single top", "f" );
  leg->AddEntry( other, "Other", "f" );
  leg->AddEntry( ratio2, "Background pred.", "lfp" );

  leg->Draw();

  TLegend *sigleg = new TLegend(0.18,0.63,0.63,0.8);
  sigleg->SetBorderSize(0);
  sigleg->SetFillColor(kWhite);
  sigleg->AddEntry((TObject*)0,    "","" ) ;
  sigleg->AddEntry(signal_55, "M_{S} = 55 GeV ", "l" ) ;
  sigleg->AddEntry(signal_15, "M_{S} = 15 GeV ", "l" ) ;
  sigleg->Draw();

  float extraOverCmsTextSize  = 0.76;
  float cmsSize = 0.06;
  float lumifont = 42;
  float extraTextSize = extraOverCmsTextSize*cmsSize;

  TLatex t;
  t.SetTextColor(kBlack);
  t.SetTextFont(lumifont);
  t.SetTextSize(0.85*cmsSize);
  t.DrawLatex(-0.15, 1e12,"ZH; H#rightarrow SS; S#rightarrow bb; c#tau_{S} = 20 mm");
  TLatex t2;
  t2.SetTextColor(kBlack);
  t2.SetTextFont(lumifont);
  t2.SetTextSize(0.85*cmsSize);
  //t2.DrawLatex(-0.17, 5e10,"#bf{#it{#Beta}}(#PH#to#mathrm{S}#mathrm{S}) = 20%");
  t2.DrawLatex(-0.17, 5e10,"#bf{#it{#Beta}}(H#rightarrow SS) = 20%");

  t.Draw();
  t2.Draw();
 
  c1->cd();
  TPad *pad2 = new TPad("pad2","pad2", .0, 0.0, 1., 0.3);
  pad2->SetTopMargin(0.05);
  pad2->SetBottomMargin(0.4);
  pad2->SetRightMargin( rightMargin );
  pad2->SetLeftMargin( leftMargin );
  pad2->SetGridy();
  pad2->Draw();
  pad2->cd();

  signal_55->SetLineColor(kRed);
  signal_55->SetLineWidth(4);
  signal_55->SetLineStyle(5);
  signal_55->Scale(0.20);///0.0371);
  signal_55->SetStats(false);
  signal_55->SetTitle("");
  signal_15->SetLineColor(kTeal+3);
  signal_15->SetLineWidth(4);
  signal_15->SetLineStyle(9);
  signal_15->Scale(0.20);///0.0371);
  signal_15->SetStats(false);
  signal_15->SetTitle("");

//Plot Ratio Here
 
  pulls=(TH1F*)Data->Clone("pulls");
  pulls->Add(total,-1);

  //using poisson prrdicted
//  pulls->SetBinContent(8,-0.226333);
//  pulls->SetBinContent(36,-0.466276);
//  pulls->SetBinContent(43,-0.291614);
//  pulls->SetBinContent(21,2.00745);
//  pulls->SetBinContent(52,0.564025);
//  pulls->SetBinContent(64,0.489401);
//  pulls->SetBinContent(15,1.84304);
//  pulls->SetBinContent(77,0.331477);
 
//  pulls->SetBinContent(8,pulls->GetBinContent(8)/sqrt(pulls->GetBinContent(8)));
//  pulls->SetBinContent(36,pulls->GetBinContent(1)/sqrt(pulls->GetBinContent(1)));
//  pulls->SetBinContent(43,pulls->GetBinContent(2)/sqrt(pulls->GetBinContent(2)));
//  pulls->SetBinContent(21,pulls->GetBinContent(3)/sqrt(pulls->GetBinContent(3)));
//  pulls->SetBinContent(52,pulls->GetBinContent(4)/sqrt(pulls->GetBinContent(4)));
//  pulls->SetBinContent(64,pulls->GetBinContent(5)/sqrt(pulls->GetBinContent(5)));
//  pulls->SetBinContent(15,pulls->GetBinContent(6)/sqrt(pulls->GetBinContent(6)));
//  pulls->SetBinContent(77,pulls->GetBinContent(7)/sqrt(pulls->GetBinContent(7)));




 // using sqrt(NData)
  pulls->SetBinContent(1,1.84097);
  pulls->SetBinContent(2,1.99969);
  pulls->SetBinContent(3,-0.483352);
  pulls->SetBinContent(4,-0.300241);
  pulls->SetBinContent(5,0.490073);
  pulls->SetBinContent(6,0.459456);
  pulls->SetBinContent(7,0.294898);
  pulls->SetBinContent(8,-0.241603);
 // using fit error   
 // pulls->SetBinContent(8,-0.23607526);
 // pulls->SetBinContent(3,-0.461199);
 // pulls->SetBinContent(4,-0.277004);
 // pulls->SetBinContent(2,1.4747);
 // pulls->SetBinContent(5,0.57891);
 // pulls->SetBinContent(6,0.476);
 // pulls->SetBinContent(1,0.936526);
 // pulls->SetBinContent(7,0.364139);
  
  pulls->GetXaxis()->SetBinLabel(8, "SS");
  pulls->GetXaxis()->SetBinLabel(1, "VS1");
  pulls->GetXaxis()->SetBinLabel(2, "VS2");
  pulls->GetXaxis()->SetBinLabel(3, "VS3");
  pulls->GetXaxis()->SetBinLabel(4, "VS4");
  pulls->GetXaxis()->SetBinLabel(5, "VS5");
  pulls->GetXaxis()->SetBinLabel(6, "VS6");
  pulls->GetXaxis()->SetBinLabel(7, "VS7");


  //ratio->Sumw2();
  //ratio->Divide( total );
  //Set Uncertainty to only the poisson, remove the one from bkg
  for ( int i  = 1; i <= ratio->GetNbinsX(); i++ )
  { 
    double rel_unc   = total->GetBinError(i)/sqrt(Data->GetBinContent(i));
    double pull_unc  = sqrt(abs(Data->GetBinError(i)*Data->GetBinError(i) - total->GetBinError(i)*total->GetBinError(i)) );
    double pull_unc2 = sqrt(abs(Data->GetBinError(i)*Data->GetBinError(i) - total->GetBinError(i)*total->GetBinError(i)) );
    //std::cout << "relative unc("<<i<<"): "<<Data->GetBinError(i)<<"/"<<Data->GetBinContent(i)
    //          <<" = "<<rel_unc << std::endl;
    //std::cout << "relative unc("<<i<<"): "<<total->GetBinError(i)<<"/"<<total->GetBinContent(i)
    //          <<" = "<<rel_unc << std::endl;
    //std::cout << "ratio("<<i<<"): "<<Data->GetBinContent(i)<<"/"<<total->GetBinContent(i)
    //          <<" = "<<Data->GetBinContent(i)/total->GetBinContent(i) << std::endl;
    //if (i==4) rel_unc = 0.5633394;
    if(rel_unc == 0)
    {
      std::cout << "relative uncertainty is ZERO!" << std::endl;
      rel_unc = 1e-6;
    }
    //std::cout<<total->GetBinContent(i)<<endl;
    std::cout<<(Data->GetBinContent(i) - total->GetBinContent(i))/sqrt(Data->GetBinContent(i))<<endl;
    //std::cout<<"DataErr: "<< Data->GetBinError(i)<<"  MCErr: "<<total->GetBinError(i)<<"  sigma: "<<pull_unc<<endl;
    //std::cout<<"  Fit Err: "<<total->GetBinError(i)<<"  sqrt(N_Pred) "<<sqrt(total->GetBinContent(i))<<endl;
    pulls->SetBinError(i,1.0);
    //pulls->SetBinError(i,pull_unc2);
    //ratio->SetBinError(i,rel_unc);
    //ratio2->SetBinContent(i,rel_unc);
    //ratio2->SetBinError(i,sqrt(Data->GetBinContent(i)));
    //ratio2->SetBinError(i,Data->GetBinError(i)/Data->GetBinContent(i));
    ratio2->SetBinError(i,total->GetBinError(i)/sqrt(Data->GetBinContent(i)));

    //ratio3->SetBinContent(i,1.0);
    ratio3->SetBinContent(i,0.0);
    ratio2->SetBinContent(i,0.0);
  }
ratio->SetStats( 0 );
  ratio->SetMarkerStyle( 20 );
  ratio->SetMarkerSize( 1.0 );
  ratio->GetXaxis()->SetTitleSize( axisTitleSizeRatioX );
  ratio->GetXaxis()->SetLabelSize( axisLabelSizeRatioX );
  ratio->GetXaxis()->SetTitleOffset( axisTitleOffsetRatioX );
  ratio->GetYaxis()->SetTitleSize( axisTitleSizeRatioY );
  ratio->GetYaxis()->SetLabelSize( axisLabelSizeRatioY );
  ratio->GetYaxis()->SetTitleOffset( axisTitleOffsetRatioY );
  ratio->SetMarkerColor( kBlack );
  ratio->SetLineColor( kBlack );
  ratio->SetLineWidth( 2 );
  ratio->GetYaxis()->SetRangeUser( RatioYMin, RatioYMax);
  //ratio->GetYaxis()->SetNdivisions(-105);
  ratio->SetTitle("");
  ratio->GetYaxis()->SetTitle("data / mc");
  ratio->GetXaxis()->SetTitle("N_{j}^{dis}");
  ratio->GetYaxis()->CenterTitle( true );
  //ratio->GetYaxis()->SetNdivisions( 10, false );
  ratio->SetStats( 0 );
  //ratio->Draw("E1");

  ratio2->SetMarkerSize( 0 ); 
  //ratio2->SetMarkerStyle( 20 );
  ratio2->GetXaxis()->SetTitleSize( axisTitleSizeRatioX );
  ratio2->GetXaxis()->SetLabelSize( axisLabelSizeRatioX );
  ratio2->GetXaxis()->SetTitleOffset( axisTitleOffsetRatioX );
  ratio2->GetYaxis()->SetTitleSize( axisTitleSizeRatioY );
  ratio2->GetYaxis()->SetLabelSize( axisLabelSizeRatioY );
  ratio2->GetYaxis()->SetTitleOffset( axisTitleOffsetRatioY );
  ratio2->SetMarkerColor( kBlue );
  ratio2->SetLineColor( kBlue );
  ratio2->SetFillColorAlpha(kBlue-9, 0.35);
  ratio2->SetLineWidth( 2 );
  ratio2->GetYaxis()->SetRangeUser( RatioYMin, RatioYMax);
  ratio2->SetTitle("");
  ratio2->GetYaxis()->SetTitle("data / mc");
  ratio2->GetXaxis()->SetTitle("N_{j}^{dis}");
  ratio2->GetYaxis()->CenterTitle( true );
  ratio2->SetStats( 0 );

  ratio3->GetXaxis()->SetTitleSize( axisTitleSizeRatioX );
  ratio3->GetXaxis()->SetLabelSize( axisLabelSizeRatioX );
  ratio3->GetXaxis()->SetTitleOffset( axisTitleOffsetRatioX );
  ratio3->GetYaxis()->SetTitleSize( axisTitleSizeRatioY );
  ratio3->GetYaxis()->SetLabelSize( axisLabelSizeRatioY );
  ratio3->GetYaxis()->SetTitleOffset( axisTitleOffsetRatioY );
  ratio3->SetMarkerColor( kBlue );
  ratio3->SetLineColor( kBlue );
  ratio3->SetLineWidth( 2 );
  ratio3->GetYaxis()->SetRangeUser( RatioYMin, RatioYMax);
  ratio3->SetTitle("");
  ratio3->GetYaxis()->SetTitle("data / mc");
  ratio3->GetYaxis()->SetTitleOffset(0.5);
  ratio3->GetYaxis()->SetLabelFont(43);
  ratio3->GetYaxis()->SetLabelSize(25);
  ratio3->GetXaxis()->SetTitle("N_{j}^{dis}");
  ratio3->GetYaxis()->CenterTitle( true );
  ratio3->GetYaxis()->SetNdivisions( 4, false );
  ratio3->SetStats( 0 );


  pulls->SetMarkerSize( 1.25 ); 
  pulls->GetXaxis()->SetTitleSize( axisTitleSizeRatioX );
  pulls->GetXaxis()->SetLabelSize( axisLabelSizeRatioX );
  pulls->GetXaxis()->SetTitleOffset( axisTitleOffsetRatioX );
  pulls->GetYaxis()->SetTitleSize( axisTitleSizeRatioY );
  pulls->GetYaxis()->SetLabelSize( axisLabelSizeRatioY );
  pulls->GetYaxis()->SetTitleOffset( axisTitleOffsetRatioY );
  pulls->SetMarkerColor( kBlack );
  pulls->SetLineColor( kBlack );
  pulls->SetFillColorAlpha(kBlack-9, 0.35);
  pulls->SetLineWidth( 2 );
  pulls->SetMarkerStyle(8);
  pulls->SetTitle("");
  pulls->GetYaxis()->SetTitle("#frac{Data - pred.}{#sigma_{Data}}");
  pulls->GetXaxis()->SetTitle("N_{j}^{dis} #geq 2");
  pulls->GetXaxis()->CenterTitle( true );
  pulls->SetStats( 0 );
  pulls->GetYaxis()->SetRangeUser(  -3.5, 3.5);
  ratio->GetYaxis()->SetRangeUser(  -3.5, 3.5);
  ratio2->GetYaxis()->SetRangeUser( -3.5, 3.5);
  ratio3->GetYaxis()->SetRangeUser( -3.5, 3.5);
  pulls->GetYaxis()->SetNdivisions( 4, false );


  pulls ->Draw("E0 sames");
  ratio2->Draw("E2 sames");
  ratio3->Draw("HIST sames"); //line at 0
//End Plot Ratio Here


c1->cd();
pad1->Draw();

AddCMS( c1 );
c1->SaveAs("Alt_Ntag.pdf");
}

