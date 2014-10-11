{
	TCanvas *c1 = newcd(3,1);
	TCanvas *c2 = newcd(3,1);
	
	//TH2* hist;
	TH1* hist;

	//Tfile1* file1 = new Tfile1("C:/Users/fpsturm/GoogleDrive/Data/ROOTfiles/H2p_scan_m2top2_Tpresort.root");
	//TFile* file1 = new TFile("C:/Users/fpsturm/GoogleDrive/Data/ROOTFiles/H2_ArFilter_scan_m100p300_2cut.root");
	//TFile* file1 = new TFile("C:/Users/fpsturm/GoogleDrive/Data/ROOTFiles/H2_ArFilter_scan_m100p300_sept_1.root");
	//TFile* file1 = new TFile("C:/Users/fpsturm/GoogleDrive/Data/ROOTFiles/C2H4_0924_open_veto_pres.root");
	TFile* file1 = new TFile("C:/Users/fpsturm/GoogleDrive/Data/ROOTFiles/C2H4_0924_open_noVeto_pres.root");
	//TFile* file1 = new TFile("C:/Users/fpsturm/GoogleDrive/Data/ROOTFiles/O2_noFilter_hellfire_pres.root");
	//TFile* file1 = new TFile("C:/Users/fpsturm/GoogleDrive/Data/ROOTFiles/O2_noFilter_pres_test.root");
	//file11->cd();

	
	// rec detector
	
	//time sums
 	c1->cd(1);
 	hist = dynamic_cast<TH2*>(file1->FindKeyAny("rec_sumu_ns")->ReadObj());
 	hist->Draw();
	gaus(-50.,50.);
 	c1->cd(2);
	hist = dynamic_cast<TH2*>(file1->FindKeyAny("rec_sumv_ns")->ReadObj());
	hist->Draw();
	gaus(-50.,50.);
	c1->cd(3);
	hist = dynamic_cast<TH2*>(file1->FindKeyAny("rec_sumw_ns")->ReadObj());
	hist->Draw();
	gaus(-50.,50.);
	
	// rec det pictures corrected
	c2->cd(1);
 	hist = dynamic_cast<TH2*>(file1->FindKeyAny("rec_uv_mm")->ReadObj());
	//hist->GetXaxis()->SetRangeUser(-45.,45.);
	//hist->GetYaxis()->SetRangeUser(-45.,45.);
 	hist->Draw();
	gPad->SetLogz();
 
 	c2->cd(2);
	hist = dynamic_cast<TH2*>(file1->FindKeyAny("rec_vw_mm")->ReadObj());
	//hist->GetXaxis()->SetRangeUser(-45.,45.);
	//hist->GetYaxis()->SetRangeUser(-45.,45.);
	hist->Draw();
	gPad->SetLogz();
	c2->cd(3);
	hist = dynamic_cast<TH2*>(file1->FindKeyAny("rec_uw_mm")->ReadObj());
	//hist->GetXaxis()->SetRangeUser(-45.,45.);
	//hist->GetYaxis()->SetRangeUser(-45.,45.);
	hist->Draw();
	gPad->SetLogz();
/*
	// layers
	TCanvas *c3 = newcd(3,1);
	c1->cd(1);
 	hist = dynamic_cast<TH2*>(file1->FindKeyAny("rec_sumu_ns")->ReadObj());
 	hist->Draw();
	gaus(-50.,50.);
 	c1->cd(2);
	hist = dynamic_cast<TH2*>(file1->FindKeyAny("rec_sumv_ns")->ReadObj());
	hist->Draw();
	gaus(-50.,50.);
	c1->cd(3);
	hist = dynamic_cast<TH2*>(file1->FindKeyAny("rec_sumw_ns")->ReadObj());
	hist->Draw();
	gaus(-50.,50.);
	*/
	}
