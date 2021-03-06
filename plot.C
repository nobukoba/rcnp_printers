void plot(){
  const Int_t npri = 15;
  TString pname[npri];
  Int_t dbl_buf[npri];
  pname[0]  = "acc4150";  dbl_buf[0]  = 0;
  pname[1]  = "acc5585";  dbl_buf[1]  = 1;
  pname[2]  = "a2c2276";  dbl_buf[2]  = 0;
  pname[3]  = "a2c3540";  dbl_buf[3]  = 0;
  pname[4]  = "a3c4476";  dbl_buf[4]  = 0;
  pname[5]  = "ri1c2250"; dbl_buf[5]  = 0;
  pname[6]  = "rbc4150";  dbl_buf[6]  = 0;
  /*  pname[7]  = "rcc4000a"; dbl_buf[7]  = 0; */
  pname[7]  = "rcc4000b"; dbl_buf[7]  = 0;
  pname[8]  = "h1c3540";  dbl_buf[8]  = 0;
  pname[9]  = "h2c3376";  dbl_buf[9]  = 0;
  pname[10] = "h3c7785";  dbl_buf[10] = 1;
  pname[11] = "h4c7785";  dbl_buf[11] = 1;
  pname[12] = "h5c7785";  dbl_buf[12] = 1;
  pname[13] = "h6c4476";  dbl_buf[13] = 0;
  pname[14] = "g1c2250";  dbl_buf[14] = 0;

  gROOT->SetBatch(kTRUE);
  TGraph *gr[npri][5];
  for (Int_t i = 0; i < npri; i++) {
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
    TCanvas * c = new TCanvas (Form("%s",  pname[i].Data()),
			       Form("%s",  pname[i].Data()));
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
    }
    for (Int_t j = 0; j < 4 + dbl_buf[i]; j++) {
      gr[i][j]->SetMarkerStyle(20);
      gr[i][j]->SetMarkerSize(0.5);
      gr[i][j]->GetXaxis()->SetTimeDisplay(1);
      gr[i][j]->GetXaxis()->SetTimeFormat("%Y%m%d-%H%M");
      gr[i][j]->GetXaxis()->SetTimeOffset(0,"jst");
      gr[i][j]->GetYaxis()->SetRangeUser(-5.,105.);
      for (Int_t k = 0; k < gr[i][j]->GetN(); k++) {
	gr[i][j]->GetY()[k] -= (j-2)*1;
      }
      if (j==0){
	gr[i][j]->Draw("apl");
      }else{
	gr[i][j]->Draw("pl");
      }
    }
  }
  TCanvas * c1 = new TCanvas ("canvas_1","canvas_1");
  TCanvas * c2 = new TCanvas ("canvas_2","canvas_2");
  c1->Divide(4,2,0.001,0.001);
  c2->Divide(4,2,0.001,0.001);
  for (Int_t i = 0; i < 8; i++) {
    c1->cd(i+1);
    for (Int_t j = 0; j < 4 + dbl_buf[i]; j++) {
      if (j==0){
	gr[i][j]->Draw("apl");
      }else{
	gr[i][j]->Draw("pl");
      }
    }
  }
  for (Int_t i = 9; i < npri; i++) {
    c2->cd(i-8);
    for (Int_t j = 0; j < 4 + dbl_buf[i]; j++) {
      if (j==0){
	gr[i][j]->Draw("apl");
      }else{
	gr[i][j]->Draw("pl");
      }
    }
  }

  THttpServer * serv = new THttpServer("http:8081?top=job");
  return;
}
