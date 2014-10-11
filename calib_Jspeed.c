
{
	//gROOT->ProcessLine(".X felix_logonscript.c");
 	TCanvas *c1 = newcp(2,1);
	crosshair();
	TH1*hist;
	//TFile* file = new TFile("C:/Users/fpsturm/GoogleDrive/Data/ROOTFiles/H2_ArFilter_scan_m100p300_Tana_1.root");
	TFile* file = new TFile("C:/Users/fpsturm/GoogleDrive/Data/ROOTFiles/C2H4_open_0924_ana.root");
	TString name;
	
	// mometum sums
 	c1->cd(1);
	file->cd("CH2/ions/raw");
	name ="position";
	gDirectory->GetObject(name,hist);
 	hist->Draw();
	TH1* pro = proy(-10,10);
	gaus(-10,10);
	pro->GetXaxis()->SetRangeUser(-5.,5.);
	
	//gPad->SetLogz();
 	
 	c1->cd(2);
	file->cd("H2/ions/raw");
	name ="position";
	gDirectory->GetObject(name,hist);
	hist->Draw();
	pro = proy(-10,10);
	gaus(-10,10);
	pro->GetXaxis()->SetRangeUser(-5.,5.);
	//gPad->SetLogz();

}
