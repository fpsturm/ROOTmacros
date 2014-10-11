{
 	TCanvas *c1 = newcd(3,2);
	//eventbar();
	crosshair();
	///TH2*hist2;
	TH1*hist;

	//TFile* file1 = new TFile("C:/Users/fpsturm/GoogleDrive/Data/ROOTFiles/H2p_scan_m2top2_Tpresort.root");
	
	file1->cd();
	
	// time sum check
 	c1->cd(1);	
	file1->cd("rec");
	
	name ="rec_u_ns";
	gDirectory->GetObject(name,hist);
 	hist->Draw();
	gaus(-1000.,1000.);
 	
 	c1->cd(2);
	name ="rec_v_ns";
	gDirectory->GetObject(name,hist);
 	hist->Draw();
	gaus(-1000.,1000.);

	c1->cd(3);
	name ="rec_w_ns";
	gDirectory->GetObject(name,hist);
 	hist->Draw();
	gaus(-1000.,1000.);
	
	c1->cd(4);
	name ="rec_uv_ns";
	gDirectory->GetObject(name,hist);
 	hist->Draw();
	
	c1->cd(5);
	name ="rec_uw_ns";
	gDirectory->GetObject(name,hist);
 	hist->Draw();
	
	c1->cd(6);
	name ="rec_vw_ns";
	gDirectory->GetObject(name,hist);
 	hist->Draw();
	}