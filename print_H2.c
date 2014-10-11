{

	//TFile* file = new TFile("/Users/Felix/LBNL Gdrive/Data/ROOTFiles/H2p_scan_m50top300_Tana.root");
	//TFile* file2 = new TFile("/Users/Felix/LBNL Gdrive/Data/ROOTFiles/H2p_scan_m20top70_Tana.root");
	TFile* file1 = new TFile("C:/Users/fpsturm/GoogleDrive/Data/ROOTFiles/H2p_scan_m50top300_Tana.root");

	char filename[24];
	sprintf(filename,"H2p_scan_m50top300");
//	sprintf(filename,"H2p_scan_m20top70");
		//-------------------------------------- target directory --------------------------------------//
	char tdirectory[64];
	//sprintf(tdirectory,"/Users/Felix/LBNL Gdrive/Data/Figures/H/%s",filename);
	sprintf(tdirectory,"C:/Users/fpsturm/GoogleDrive/Data/05222014_H2");
	
	//-------------------------------------- file format --------------------------------------//
	char format[5];
	sprintf(format,".pdf");
	char filepath[128];	//complete path with specific histname

	char title[32];
	//change style from style_felix.c
	printstyle();

	//TCanvas *c1 = newcp(1,1);
	//TCanvas* c2 = newcp(2,1);

	
	TString name;
	TH1*hist;
	TH2*hist2;
	
	/*
	// Momenta	----------------------------------------------------------------------------
	c1->cd(1);
	file->cd("H/ions/hit_0/momenta");
	
	
	name ="p_z vs p_x";
	gDirectory->GetObject(name,hist);
	hist->SetTitle("H+ momentum z vs y");
	hist->GetXaxis()->SetRangeUser(-20.,20.);
	hist->GetYaxis()->SetRangeUser(-20.,20.);
	hist->GetXaxis()->CenterTitle(23);
	hist->GetYaxis()->CenterTitle(23);
	hist->Draw();
	hist->Smooth();
	//gPad->SetLogz();
	
//	c2->cd(2);
	name ="p_z vs p_y";
	gDirectory->GetObject(name,hist2);
	hist2->SetTitle("H+ momentum z vs x");
	hist2->GetXaxis()->SetRangeUser(-20.,20.);
	hist2->GetYaxis()->SetRangeUser(-20.,20.);
	hist2->GetXaxis()->CenterTitle(23);
	hist2->GetYaxis()->CenterTitle(23);
	hist2->Draw();
	hist2->Smooth();
	//gPad->SetLogz();

	gPad->Update();
	sprintf(filepath,"%s_%s%s",tdirectory,"pzVSpx",format);
//	sprintf(filepath,"%s_%s%s",tdirectory,"momenta",format);
	c1->Print(filepath);


	// Energy and Momentum ----------------------------------------------------------------------------
	TCanvas* c3 = newcp(2,1);
	c3->cd(1);
	file->cd("H/ions/hit_0/momenta");
	name ="p_mag";
	gDirectory->GetObject(name,hist);
	//hist = dynamic_cast<TH2*>(file->FindKeyAny(name)->ReadObj());
	//hist->GetXaxis()->SetRangeUser(0.,20.);
	hist->GetXaxis()->CenterTitle(23);
	hist->GetYaxis()->CenterTitle(23);
	hist->GetYaxis()->SetTitle("counts");
	hist->Draw("C");
	//hist->Smooth();
	//gPad->SetLogz();

	c3->cd(2);
	file->cd("H/ions/hit_0/energy");
	name ="ion energy";
	gDirectory->GetObject(name,hist);
	//hist = dynamic_cast<TH2*>(file->FindKeyAny(name)->ReadObj());
	hist->GetXaxis()->SetRangeUser(0.,3.);
	hist->GetXaxis()->CenterTitle(23);
	hist->GetYaxis()->CenterTitle(23);
	hist->GetYaxis()->SetTitle("counts");
	hist->Draw("C");
	//hist->Smooth();
	//gPad->SetLogz();

	gPad->Update();
	sprintf(filepath,"%s_%s%s",tdirectory,"totalPandE",format);
	c3->Print(filepath);
	

	// Delay overview	----------------------------------------------------------------------------
	TCanvas* c4 = newcp(2,1);
	c4->cd(1);
	file->cd("H/ions/hit_0");
	name ="delay_p";
	gDirectory->GetObject(name,hist2);
	hist2->SetTitle(" H+ momentum vs Pump-Probe delay");
	hist2->GetXaxis()->CenterTitle(23);
	hist2->GetYaxis()->CenterTitle(23);
	//hist2->RebinX(5);
	//hist->GetXaxis()->SetRangeUser(0.,20.);
	hist2->Draw();
	//hist2->Smooth();
	//gPad->SetLogz();
	
	c4->cd(2);
	name ="delay_E";
	gDirectory->GetObject(name,hist2);
	//hist = dynamic_cast<TH2*>(file->FindKeyAny(name)->ReadObj());
	hist2->GetXaxis()->CenterTitle(23);
	hist2->GetYaxis()->CenterTitle(23);
	//hist2->RebinX(10);
	hist2->GetYaxis()->SetRangeUser(0.,2.);
	hist2->Draw();
	//hist2->Smooth();
	//gPad->SetLogz();

	gPad->Update();
	sprintf(filepath,"%s_%s%s",tdirectory,"DelayP",format);
//	sprintf(filepath,"%s_%s%s",tdirectory,"DelayPandE",format);
//	c4->Print(filepath);
	

	// Delay plots	----------------------------------------------------------------------------
	TCanvas* c5 = newcp(3,1);
	c5->cd(1);
	file->cd("H/ions/hit_0");
	name ="delay_yield";
	gDirectory->GetObject(name,hist);
	hist->Rebin(5);
	hist->GetXaxis()->CenterTitle(23);
	hist->GetYaxis()->CenterTitle(23);
	hist->GetYaxis()->SetTitle("counts");
	hist->SetMarkerStyle(20);
	hist->SetMarkerSize(0.8);
	hist->SetLineColor(2);
	hist->GetYaxis()->SetRangeUser(1100.,1500.);
	//hist->GetYaxis()->SetRangeUser(250.,450.);
	hist->Draw("P E");
	//normalize_integral_y();
	//hist->Smooth();
	//gPad->SetLogz();

	c5->cd(2);
	hist = prox(hist2,0.,0.5,0,false);
	hist->Rebin(5);
	hist->GetXaxis()->CenterTitle(23);
	hist->GetYaxis()->CenterTitle(23);
	hist->GetYaxis()->SetTitle("counts");
	hist->SetTitle("Ion yield for E= 0 to 0.5 eV");
	hist->SetMarkerStyle(20);
	hist->SetMarkerSize(0.8);
	hist->SetLineColor(2);
	//hist->GetYaxis()->SetRangeUser(0.,2.);
	hist->GetYaxis()->SetRangeUser(700.,1000.);
	hist->Draw("P E");
	//normalize_integral_y();
	
	//hist->Smooth();
	//gPad->SetLogz();
	
	c5->cd(3);
	hist = prox(hist2,1.1,2.,0,false);
	hist->Rebin(5);
	hist->GetXaxis()->CenterTitle(23);
	hist->GetYaxis()->CenterTitle(23);
	hist->GetYaxis()->SetTitle("counts");
	hist->SetTitle("Ion yield for E= 1.1 to 2 eV");
	hist->SetMarkerStyle(20);
	hist->SetMarkerSize(0.8);
	hist->SetLineColor(2);
	//hist->GetYaxis()->SetRangeUser(0.,2.);
	hist->GetYaxis()->SetRangeUser(100.,250.);
	hist->Draw("P E");
	//normalize_integral_y();


	gPad->Update();
	sprintf(filepath,"%s_%s%s",tdirectory,"Delay_proj",format);
	c5->Print(filepath);
	*/
	/*
	//	----------------------------------------------------------------------------
	//
	//		H2+
	//
	//	----------------------------------------------------------------------------
	
	TCanvas* c6 = newcp(1,1);
	c6->cd(1);
	file->cd("H2/ions/hit_0");
	name ="delay_yield";
	gDirectory->GetObject(name,hist);
	hist->Rebin(5);
	hist->GetXaxis()->CenterTitle(23);
	hist->GetYaxis()->CenterTitle(23);
	hist->GetYaxis()->SetTitle("Int (arb. units)");
	hist->SetMarkerStyle(20);
	hist->SetMarkerSize(0.8);
	hist->SetLineColor(2);
	
	TH1* hist_n = normalize2peak(hist);
	hist->GetYaxis()->SetRangeUser(9.4,10.2);
	//hist->GetYaxis()->SetRangeUser(250.,450.);
	
	hist_n->Draw("P E1");
	//hist->Smooth();
	//gPad->SetLogz();
	
	gPad->Update();
	sprintf(filepath,"%s_%s%s",tdirectory,"H2_delay",format);
	c6->Print(filepath);
	*/
	
	
	//	----------------------------------------------------------------------------
/*
	// Stusti Bericht
	TCanvas* c1 = newcp(2,1);
	c1->cd(1);
	
	file2->cd("H/ions/hit_0/momenta");
	name ="p_z vs p_y";
	gDirectory->GetObject(name,hist2);
	hist2->SetTitle("H+ momentum z vs y");
	hist2->GetXaxis()->SetRangeUser(-20.,20.);
	hist2->GetYaxis()->SetRangeUser(-20.,20.);
	hist2->GetXaxis()->CenterTitle(23);
	hist2->GetYaxis()->CenterTitle(23);
	hist2->Draw();
	hist2->Smooth();
	//gPad->SetLogz();

	c1->cd(2);
	file->cd("H/ions/hit_0");
	name ="delay_p";
	gDirectory->GetObject(name,hist2);
	hist2->SetTitle(" H+ momentum vs Pump-Probe delay");
	hist2->GetXaxis()->CenterTitle(23);
	hist2->GetYaxis()->CenterTitle(23);
	hist2->RebinX(5);
	//hist->GetXaxis()->SetRangeUser(0.,20.);
	hist2->Draw();
	hist2->Smooth();
	//gPad->SetLogz();
	
	gPad->Update();
	//sprintf(filepath,"%s_%s%s",tdirectory,"pzVSpx",format);
	sprintf(filepath,"%s_%s%s",tdirectory,"StustiOV",format);
	c1->Print(filepath);
*/

	//	----------------------------------------------------------------------------
	// difference plots of p_xy
	
	TCanvas* c3 = newcp(3,1);
	c3->cd(1);
	
	file1->cd("H/ions/Max_A");
	TH1* histA;
	TH1* histB;
	
	name ="ion energy maxA";
	gDirectory->GetObject(name,hist);
	histA = hist;
	name ="ion energy minA";
	gDirectory->GetObject(name,hist);
	histB = hist;
	
	hist = histA;
	hist->Draw();
	normalize_integral_y();
	hist->GetXaxis()->SetRangeUser(0.,2.);
	histA = get1DHistFromPad();
	c3->cd(2);
	hist = histB;
	hist->Draw();
	normalize_integral_y();
	hist->GetXaxis()->SetRangeUser(0.,2.);
	histB = get1DHistFromPad();

	TH1* sub = subHistos(histA,histB);
	c3->cd(3);
	
	sprintf(title,"Max-Min. Energy");
	sub->SetTitle(title);
	sub->Draw();
	
	sprintf(filepath,"%s/%s%s",tdirectory,title,format);
	c3->Print(filepath);
	
	/*
	// Momentum plot pxy
	TCanvas* c3 = newcd(3,1);
	c3->cd(1);
	
	file1->cd("H/ions/Max_A");
	TH2* histA;
	TH2* histB;
	
	name ="pz vs p_xy maxA";
	gDirectory->GetObject(name,hist2);
	histA = hist2;
	name ="pz vs p_xy minA";
	gDirectory->GetObject(name,hist2);
	histB = hist2;
	
	TH1* sub = subHistos(histA,histB);
	
	histA->Rebin(2);
	histB->Rebin(2);
	histA->Draw();
	c3->cd(2);
	histB->Draw();
	c3->cd(3);
	sub->SetTitle("Max-Min. Momentum pz VS pxy ");
	sub->Draw();
	*/
	
	/*
	// Momentum plot pz vs px cth
	TCanvas* c3 = newcd(3,1);
	c3->cd(1);
	
	file1->cd("H/ions/Max_A");
	TH2* histA;
	TH2* histB;
	
	name ="p_z vs p_x maxA";
	gDirectory->GetObject(name,hist2);
	histA = hist2;
	name ="p_z vs p_x minA";
	gDirectory->GetObject(name,hist2);
	histB = hist2;
	
	histA->Rebin2D(2);
	histB->Rebin2D(2);
	histA->Draw();
	normalize_integral_y();
	histA = get2DHistFromPad();
	c3->cd(2);
	histB->Draw();
	normalize_integral_y();
	histB = get2DHistFromPad();
	
	TH1* sub = subHistos(histA,histB);
	c3->cd(3);
	
	sprintf(title,"Max-Min. Momentum pz VS pxy");
	sub->SetTitle(title);
	sub->Draw();
	
	sprintf(filepath,"%s/%s%s",tdirectory,title,format);
	c3->Print(filepath);
	*/
	/*
	delete histA;
	delete histB;
	
	delete hist;
	delete hist2;
*/
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}
