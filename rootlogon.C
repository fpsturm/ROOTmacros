{	
	//////////////////////////////////////////////////////
	//					load macros						//
	//////////////////////////////////////////////////////
	gROOT->LoadMacro("MoritzLutzAchimTill.c");
	gROOT->LoadMacro("Felix.C");
	gROOT->LoadMacro("style_felix.C");

	//////////////////////////////////////////////////////
	//				set new styles						//
	//////////////////////////////////////////////////////
	gStyle->SetOptFit(0000);
	gStyle->SetNumberContours(255);
	gStyle->SetOptStat("");
	
	//gROOT->ProcessLine(".L style_felix.C");
	displaystyle();
	color(2);//choose colorset from Achim_Lutz_Till	
	
	//////////////////////////////////////////////////////
	//				launch custom browser				//
	//////////////////////////////////////////////////////
	//new TBrowser("MyBrowser","MyBrowser",1210,5,700,450,0,"");;	// Felix.c for 1920 display width
	new TBrowser("MyBrowser","MyBrowser",1210,5,700,850,0,"");;	// for Office 122
	//new TBrowser();
/*
	//////////////////////////////////////////////////////
	//					build canvas					//
	//////////////////////////////////////////////////////
	TCanvas * MyC = new TCanvas("MyC","MyCanvas",1,1,541.*1.,541.*1.);
	//	MyC->Divide(2,1,0.0001,0.0001);
	
	for (int i=0;i<1;++i)
	{
		MyC->cd(i);
		gPad->SetRightMargin(0.15);
		gPad->SetLeftMargin(0.15);
		gPad->SetTopMargin(0.15);
		gPad->SetBottomMargin(0.15);
	}
	MyC->cd(1);

	*/
//	gStyle->SetCanvasDefX(1); doesn't work??!!
//	gStyle->SetCanvasDefY(1);
	newcd(1,1);	
	crosshair();	// Felix.c
	//eventbar();	// Felix.c

	//////////////////////////////////////////////////////
	//				laod root file						//
	//////////////////////////////////////////////////////
	//TFile* f = new TFile("CO2_320p5_0318_horiz_calib1.root");

	//////////////////////////////////////////////////////
	//			execute additional macros				//
	//////////////////////////////////////////////////////
	//e1pxyphi->Draw();

}
