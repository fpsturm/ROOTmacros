
{
	//gROOT->ProcessLine(".X felix_logonscript.c");
 	TCanvas *c1 = newcp(4,3);
	eventbar();
	crosshair();
	TH2*hist;
	//TFile* file = new TFile("S:/FPSturm/ICD/Data/ALS092011_N2_horiz_60eV_analysis_calibrated.root");
	//TFile* file = new TFile("S:/FPSturm/ICD/Data/ALS092011_N2_horiz_60eV_analysis_calibrated.root");
	//TFile* file = new TFile("S:/FPSturm/ICD/Data/ALS092011_O2mol_46eV_full_analysis.root");
	//TFile* file = new TFile("S:/FPSturm/ICD/Data/ALS092011_O2mol_41p5eV_f_analysis.root");
	//TFile* file = new TFile("S:/FPSturm/ICD/Data/ALS092011_O2mol_41p5eV_a_analysis.root");
	//TFile* file = new TFile("S:/FPSturm/ICD/Data/ALS092011_O2mol_41p5eV_b_analysis.root");
	//TFile* file = new TFile("S:/FPSturm/ICD/Data/ALS092011_O2_horiz_46eV_full_analysis_pwide.root");
	//TFile* file = new TFile("S:/FPSturm/ICD/Data/ALS092011_O2_horiz_41p5eV_a-b_analysis.root");
	//TFile* file = new TFile("S:/FPSturm/ICD/Data/ALS092011_O2_horiz_41p5eV_f_analysis.root");
	//TFile* file = new TFile("S:/FPSturm/ICD/Data/ALS092011_O2_horiz_38eV_full_analysis.root");
	//TFile* file = new TFile("S:/FPSturm/ICD/Data/ALS092011_O2_horiz_46eV_full_analysis.root");
	//TFile* file = new TFile("S:/FPSturm/ICD/Data/ALS092011_O2_horiz_41p5eV_full_analysis.root");
	//TFile* file = new TFile("S:/FPSturm/ICD/Data/ALS092011_O2_horiz_46eV_full_analysis_TEST.root");
	TFile* file = new TFile("S:/FPSturm/O2_irina/Sep18_O2_46eV_par_to_pol.root");

	file->cd();
	
	// mometum sums
 	c1->cd(1);
	TString name ("r1_px vs r2_px");
 	hist = dynamic_cast<TH2*>(file->FindKeyAny(name)->ReadObj());
	hist->GetXaxis()->SetRangeUser(-50.,50.);
	hist->GetYaxis()->SetRangeUser(-50.,50.);
 	hist->Draw();
	gPad->SetLogz();
 	
 	c1->cd(2);
	name ="r1_py vs r2_py";
	hist = dynamic_cast<TH2*>(file->FindKeyAny(name)->ReadObj());
	hist->GetXaxis()->SetRangeUser(-50.,50.);
	hist->GetYaxis()->SetRangeUser(-50.,50.);
	hist->Draw();
	gPad->SetLogz();

	c1->cd(3);
	name ="r1_pz vs r2_pz";
	hist = dynamic_cast<TH2*>(file->FindKeyAny(name)->ReadObj());
	hist->GetXaxis()->SetRangeUser(-50.,50.);
	hist->GetYaxis()->SetRangeUser(-50.,50.);
	hist->Draw();
	gPad->SetLogz();
	
	// momentum bowls
	c1->cd(5);
	//name ="slice rel_px vs rel_py";
	name ="r_p xy bowl slice";
	hist = dynamic_cast<TH2*>(file->FindKeyAny(name)->ReadObj());
	hist->Draw();
	gPad->SetLogz();
	rebin();

	c1->cd(6);
	//name ="slice rel_px vs rel_pz";
	name ="r_p xz bowl slice";
	hist = dynamic_cast<TH2*>(file->FindKeyAny(name)->ReadObj());
	hist->Draw();
	gPad->SetLogz();
	rebin();

	c1->cd(7);
	//name ="slice rel_pz vs rel_py";
	name ="r_p zy bowl slice";
	hist = dynamic_cast<TH2*>(file->FindKeyAny(name)->ReadObj());;
	hist->Draw();
	gPad->SetLogz();
	rebin();

	// mom sums
	c1->cd(9);
	name ="rsum_px";
	hist = dynamic_cast<TH2*>(file->FindKeyAny(name)->ReadObj());
	hist->GetXaxis()->SetRangeUser(-20.,20.);
	hist->Draw();

	c1->cd(10);
	name ="rsum_py";
	hist = dynamic_cast<TH2*>(file->FindKeyAny(name)->ReadObj());
	hist->GetXaxis()->SetRangeUser(-20.,20.);
	hist->Draw();

	c1->cd(11);
	name ="rsum_pz";
	hist = dynamic_cast<TH2*>(file->FindKeyAny(name)->ReadObj());
	hist->GetXaxis()->SetRangeUser(-20.,20.);
	hist->Draw();

	//
	/*
	c1->cd(4);
	name ="rel_pR";
	hist = dynamic_cast<TH2*>(file->FindKeyAny(name)->ReadObj());
	hist->GetXaxis()->SetRangeUser(50.,150.);
	hist->Draw();
*/
	c1->cd(8);
	name ="Atan2(rel_py,rel_pz) vs Relative KER";
	hist = dynamic_cast<TH2*>(file->FindKeyAny(name)->ReadObj());
	hist->Draw();

	c1->cd(12);
	name ="Relative KER";
	hist = dynamic_cast<TH2*>(file->FindKeyAny(name)->ReadObj());
	hist->GetXaxis()->SetRangeUser(0.,20.);
	hist->Draw();

}
