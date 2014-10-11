
{
	//gROOT->ProcessLine(".X felix_logonscript.c");
 	TCanvas *c1 = newcp(3,1);
	eventbar();
	crosshair();
	TH2*hist;
	TH1*hist1;
	//TFile* file = new TFile("C:/Users/fpsturm/GoogleDrive/Data/ROOTFiles/H2p_scan_m20top70_Tana.root");
	TFile* file = new TFile("C:/Users/fpsturm/GoogleDrive/Data/ROOTFiles/H2p_scan_m50top300_Tana.root");

	file->cd();
	
	// mometum sums
 	c1->cd(1);
	TString name ("p_x vs p_y");
	file->cd("H/ions/hit_0/momenta");
	gDirectory->GetObject(name,hist);
 	//hist = dynamic_cast<TH2*>(file->FindKeyAny(name)->ReadObj());
	hist->GetXaxis()->SetRangeUser(-3.,3.);
	hist->GetYaxis()->SetRangeUser(-3.,3.);
 	hist->Draw();
	hist->Smooth();
	//gPad->SetLogz();
 	
 	c1->cd(2);
	name ="p_z vs p_x";
	file->cd("H/ions/hit_0/momenta");
	gDirectory->GetObject(name,hist);
	//hist = dynamic_cast<TH2*>(file->FindKeyAny(name)->ReadObj());
	hist->GetXaxis()->SetRangeUser(-3.,3.);
	hist->GetYaxis()->SetRangeUser(-3.,3.);
	hist->Draw();
	hist->Smooth();
	//gPad->SetLogz();

	c1->cd(3);
	name ="p_z vs p_y";
	file->cd("H/ions/hit_0/momenta");
	gDirectory->GetObject(name,hist);
	//hist = dynamic_cast<TH2*>(file->FindKeyAny(name)->ReadObj());
	hist->GetXaxis()->SetRangeUser(-3.,3.);
	hist->GetYaxis()->SetRangeUser(-3.,3.);
	hist->Draw();
	hist->Smooth();
	//gPad->SetLogz();
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

}
