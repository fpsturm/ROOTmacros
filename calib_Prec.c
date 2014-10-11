
{
	//gROOT->ProcessLine(".X felix_logonscript.c");
 	TCanvas *c1 = newcd(3,2);
	//TCanvas *c2 = newcd(3,1);
	crosshair();
	TH2*hist2;
	TH1*hist;
	//TFile* file = new TFile("C:/Users/fpsturm/GoogleDrive/Data/ROOTFiles/H2_ArFilter_scan_m100p300_Tana_6.root");
	//TFile* file = new TFile("C:/Users/fpsturm/GoogleDrive/Data/ROOTFiles/C2H4_open_0924_Dana.root");
	//TFile* file = new TFile("C:/Users/fpsturm/GoogleDrive/Data/ROOTFiles/O2_noFilter_hellfire_Iana.root");
	//TFile* file = new TFile("C:/Users/fpsturm/GoogleDrive/Data/ROOTFiles/O2_Tin_OpOp_Iana_nc.root");
	TFile* file = new TFile("C:/Users/fpsturm/GoogleDrive/Data/ROOTFiles/O2_Tin_OpOp_Dana.root");
	
	TString name;
	file->cd();
	
	double range = 100;
	// mometum sums
 	c1->cd(1);
 	file->cd("OpOp/ions/momenta");
	name ="p_x vs p_y";
	gDirectory->GetObject(name,hist);
	hist->GetXaxis()->SetRangeUser(-range,range);
	hist->GetYaxis()->SetRangeUser(-range,range);
 	hist->Draw();
	//gPad->SetLogz();
 	
 	c1->cd(2);
	name ="p_z vs p_x";
	gDirectory->GetObject(name,hist);
	hist->GetXaxis()->SetRangeUser(-range,range);
	hist->GetYaxis()->SetRangeUser(-range,range);
	hist->Draw();
	//gPad->SetLogz();

	c1->cd(3);
	name ="p_z vs p_y";
	gDirectory->GetObject(name,hist);
	hist->GetXaxis()->SetRangeUser(-range,range);
	hist->GetYaxis()->SetRangeUser(-range,range);
	hist->Draw();
	//TH1* pro = proy(-1.5,1.5);
	//gaus(-2,2);
	//pro->GetXaxis()->SetRangeUser(-2.,2.);
	//gPad->SetLogz();
	
	range = 3.;
	c1->cd(4);
	name ="p phi_xy vs ion energy";
	gDirectory->GetObject(name,hist);
	//hist->GetXaxis()->SetRangeUser(-range,range);
	hist->GetYaxis()->SetRangeUser(0,range);
	hist->Draw();
	
		c1->cd(5);
	name ="p phi_xz vs ion energy";
	gDirectory->GetObject(name,hist);
	//hist->GetXaxis()->SetRangeUser(-range,range);
	hist->GetYaxis()->SetRangeUser(0,range);
	hist->Draw();
	
		c1->cd(6);
	name ="p phi_yz vs ion energy";
	gDirectory->GetObject(name,hist);
	//hist->GetXaxis()->SetRangeUser(-range,range);
	hist->GetYaxis()->SetRangeUser(0,range);
	hist->Draw();
	
/*	
	c1->cd(4);
	file->cd("H");
	name ="fish y";
	hist = dynamic_cast<TH2*>(file->FindKeyAny(name)->ReadObj());
	hist->GetXaxis()->SetRangeUser(3000.,5000.);
	hist->GetYaxis()->SetRangeUser(-10.,10.);
	hist->Draw();
	//gPad->SetLogz();
	*/
/*
	c2->cd(1);
 	file->cd("CH2/ions/angles");
	name ="phi_x";
	gDirectory->GetObject(name,hist);
	//hist->GetXaxis()->SetRangeUser(-range,range);
	//hist->GetYaxis()->SetRangeUser(-range,range);
 	hist->Draw();
	//gPad->SetLogz();
 	
 	c2->cd(2);
	name ="phi_y";
	gDirectory->GetObject(name,hist);
	//hist->GetXaxis()->SetRangeUser(-range,range);
	//hist->GetYaxis()->SetRangeUser(-range,range);
	hist->Draw();
	//gPad->SetLogz();

	c2->cd(3);
	name ="phi_z";
	gDirectory->GetObject(name,hist);
	//hist->GetXaxis()->SetRangeUser(-range,range);
	//hist->GetYaxis()->SetRangeUser(-range,range);
	hist->Draw();
	*/
}
