void plot_old(){
  const Int_t npri = 16;
  TString pname[npri];
  Int_t dbl_buf[npri];
  pname[0]  = "acc4150";  dbl_buf[0]  = 0;
  pname[1]  = "acc5585";  dbl_buf[1]  = 1;
  pname[2]  = "a2c2276";  dbl_buf[2]  = 0;
  pname[3]  = "a2c3540";  dbl_buf[3]  = 0;
  pname[4]  = "a3c4476";  dbl_buf[4]  = 0;
  pname[5]  = "ri1c2250"; dbl_buf[5]  = 0;
  pname[6]  = "rbc4150";  dbl_buf[6]  = 0;
  pname[7]  = "rcc4000a"; dbl_buf[7]  = 0;
  pname[8]  = "rcc4000b"; dbl_buf[8]  = 0;
  pname[9]  = "h1c3540";  dbl_buf[9]  = 0;
  pname[10] = "h2c3376";  dbl_buf[10] = 0;
  pname[11] = "h3c7785";  dbl_buf[11] = 1;
  pname[12] = "h4c7785";  dbl_buf[12] = 1;
  pname[13] = "h5c7785";  dbl_buf[13] = 1;
  pname[14] = "h6c4476";  dbl_buf[14] = 0;
  pname[15] = "g1c2250";  dbl_buf[15] = 0;
  
  TGraph *gr[npri][5];
  TMultiGraph *mg[npri];
  TList  *gl[npri];
  for (Int_t i = 0; i < npri; i++) {
    if (i==7) { continue; }
    gl[i] = new TList();
    gl[i]->SetName(pname[i].Data());
    gROOT->Add(gl[i]);
    mg[i] = new TMultiGraph(Form("%s_multi",pname[i].Data()),
			    Form("%s_multi",pname[i].Data()));
    gl[i]->Add(mg[i]);
    TString fname = Form("./status/tnr_per_%s.txt", pname[i].Data());
    gr[i][0] = new TGraph(fname.Data(),"%lg %*s %lg");
    gr[i][1] = new TGraph(fname.Data(),"%lg %*s %*s %lg");
    gr[i][2] = new TGraph(fname.Data(),"%lg %*s %*s %*s %lg");
    gr[i][3] = new TGraph(fname.Data(),"%lg %*s %*s %*s %*s %lg");
    if (dbl_buf[i]) {
      gr[i][4] = new TGraph(fname.Data(),"%lg %*s %*s %*s %*s %lg");
    }else{
      gr[i][4] = new TGraph();
    }
  }
  for (Int_t i = 0; i < npri; i++) {
    if (i==7) { continue; }
    if (dbl_buf[i] == 0) {
      gr[i][0]->SetMarkerColor(kBlack);
      gr[i][1]->SetMarkerColor(kCyan+2);
      gr[i][2]->SetMarkerColor(kMagenta);
      gr[i][3]->SetMarkerColor(kYellow+2);
      gr[i][0]->SetLineColor(kBlack);
      gr[i][1]->SetLineColor(kCyan+2);
      gr[i][2]->SetLineColor(kMagenta);
      gr[i][3]->SetLineColor(kYellow+2);
      gr[i][0]->SetName(Form("%s_black",   pname[i].Data()));
      gr[i][1]->SetName(Form("%s_cyan",    pname[i].Data()));
      gr[i][2]->SetName(Form("%s_magenta", pname[i].Data()));
      gr[i][3]->SetName(Form("%s_yellow",  pname[i].Data()));
      for (Int_t j = 0; j < 4; j++) {
	gr[i][j]->SetMarkerStyle(20);
	gr[i][j]->SetMarkerSize(0.5);
	gr[i][j]->GetXaxis()->SetTimeDisplay(1);
	gr[i][j]->GetXaxis()->SetNdivisions(-503);
	gr[i][j]->GetXaxis()->SetTimeFormat("#splitline{%Y\/%m\/%d}{%H:%M}");
	gr[i][j]->GetXaxis()->SetTimeOffset(0,"jst");
	gr[i][j]->GetYaxis()->SetRangeUser(-10.,110.);
	gl[i]->Add(gr[i][j]);
	mg[i]->Add(gr[i][j]);
	for (Int_t k = 0; k < gr[i][j]->GetN(); k++) {
	  gr[i][j]->GetY()[k] -= (j-1)*1;
	}
      }
      std::cout << pname[i]<< ": mg[i]->GetXaxis()" << mg[i]->GetXaxis() << std::endl;
      mg[i]->Draw("APL");
      std::cout << pname[i]<< ": mg[i]->GetXaxis()" << mg[i]->GetXaxis() << std::endl;
    }else{
      gr[i][0]->SetMarkerColor(kBlack);
      gr[i][1]->SetMarkerColor(kGray+2);
      gr[i][2]->SetMarkerColor(kCyan+2);
      gr[i][3]->SetMarkerColor(kMagenta);
      gr[i][4]->SetMarkerColor(kYellow+2);
      gr[i][0]->SetLineColor(kBlack);
      gr[i][1]->SetLineColor(kGray+2);
      gr[i][2]->SetLineColor(kCyan+2);
      gr[i][3]->SetLineColor(kMagenta);
      gr[i][4]->SetLineColor(kYellow+2);
      gr[i][0]->SetName(Form("%s_black1",  pname[i].Data()));
      gr[i][1]->SetName(Form("%s_black2",  pname[i].Data()));
      gr[i][2]->SetName(Form("%s_cyan",    pname[i].Data()));
      gr[i][3]->SetName(Form("%s_magenta", pname[i].Data()));
      gr[i][4]->SetName(Form("%s_yellow",  pname[i].Data()));
      for (Int_t j = 0; j < 5; j++) {
	gr[i][j]->SetMarkerStyle(20);
	gr[i][j]->SetMarkerSize(0.5);
	gr[i][j]->GetXaxis()->SetTimeDisplay(1);
	gr[i][j]->GetXaxis()->SetNdivisions(-503);
	gr[i][j]->GetXaxis()->SetTimeFormat("#splitline{%Y\/%m\/%d}{%H:%M}");
	gr[i][j]->GetXaxis()->SetTimeOffset(0,"jst");
	gr[i][j]->GetYaxis()->SetRangeUser(-10.,110.);
	gl[i]->Add(gr[i][j]);
	mg[i]->Add(gr[i][j]);
	for (Int_t k = 0; k < gr[i][j]->GetN(); k++) {
	  gr[i][j]->GetY()[k] -= (j-2)*1;
	}
      }
    }
  }
  
  gr[1][0]->Draw("apl");
  gr[1][1]->Draw("pl");
  gr[1][2]->Draw("pl");
  gr[1][3]->Draw("pl");
  gr[1][4]->Draw("pl");
  return;
}
