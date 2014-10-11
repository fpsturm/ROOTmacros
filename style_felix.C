/*****************************************************************************\
|						    style settings							        |
\*****************************************************************************/

	void gstyles(){

	gStyle->SetOptStat("eou");
	gStyle->SetNdivisions(508,"XY");
	gStyle->SetOptFit(0000);

	//Pad
	gStyle->SetPadBorderMode(1);
	gStyle->SetPadColor(0);
	gStyle->SetPadGridX(kTRUE);
	gStyle->SetPadGridY(kTRUE);
	gStyle->SetPadLeftMargin(0.15);
	gStyle->SetPadRightMargin(0.15);
	gStyle->SetPadTopMargin(0.15);
	gStyle->SetPadBottomMargin(0.15);

	//Canvas
	gStyle->SetCanvasBorderMode(0);
	gStyle->SetCanvasColor(0);

	//Title
	gStyle->SetTitleColor(1);
	gStyle->SetTitleBorderSize(1);
	gStyle->SetTitleFillColor(0);
	gStyle->SetTitleX(0.5);		// Title box in horiz center 
	gStyle->SetTitleY(0.95);	// Title box 0.05 from top
	gStyle->SetTitleAlign(23);	// title aligned center, bottom of title box
	
	//Frame
	gStyle->SetFrameFillColor(0);
	gStyle->SetFrameLineColor(1);
	gStyle->SetFrameFillStyle(1001);
	gStyle->SetFrameLineStyle(1);
	gStyle->SetFrameLineWidth(1);
	gStyle->SetFrameBorderSize(1);
	gStyle->SetFrameBorderMode(0);
	
	//Stat
	gStyle->SetStatColor(0);
	gStyle->SetStatTextColor(1);
	gStyle->SetStatBorderSize(1);
	gStyle->SetStatFont(42);
	gStyle->SetStatFontSize(0.025);
	gStyle->SetStatStyle(0);
	gStyle->SetStatFormat("6.4g");
	gStyle->SetStatX(0.87);
	gStyle->SetStatY(0.87);
	gStyle->SetStatW(0.30);
	gStyle->SetStatH(0.20);

	//Fill
	gStyle->SetMarkerStyle(20);
	gStyle->SetMarkerSize(1);
	
	gStyle->SetNumberContours(255);
	}

	void displaystyle(){

		gEnv->SetValue("Canvas.ShowEventStatus",1);	// disable event status bar
		gEnv->SetValue("Canvas.ShowEditor",1);		// disable Canvas Editor
		
		gStyle->SetNdivisions(508,"XY");
		//Pad
		gStyle->SetPadBorderMode(1);
		gStyle->SetPadColor(0);
		gStyle->SetPadGridX(kTRUE);
		gStyle->SetPadGridY(kTRUE);
		gStyle->SetPadLeftMargin(0.15);
		gStyle->SetPadRightMargin(0.15);
		gStyle->SetPadTopMargin(0.15);
		gStyle->SetPadBottomMargin(0.15);
	
		//Canvas
		gStyle->SetCanvasBorderMode(0);
		//gStyle->SetCanvasColor(0);
	
		//Title
		gStyle->SetTitleX(0.15);	// Title box 0.15 off left border
		gStyle->SetTitleAlign(13);	// text is aliged to the left and bottom of title box

		// Axis styles
		gStyle->SetTitleFont(42,"xyz");
		
		
		//Frame
		gStyle->SetFrameFillColor(0);//kCyan-10
		gStyle->SetFrameLineColor(1);
		gStyle->SetFrameFillStyle(1001);
		gStyle->SetFrameLineStyle(1);
		gStyle->SetFrameLineWidth(1);
		gStyle->SetFrameBorderSize(1);
		gStyle->SetFrameBorderMode(0);
		
		//Stat
		gStyle->SetOptStat("euo");
		gStyle->SetOptFit(0);
		gStyle->SetStatBorderSize(1);
		gStyle->SetStatFont(42);
		gStyle->SetStatFontSize(0.025);
		gStyle->SetStatStyle(0);
		gStyle->SetStatFormat("6.4g");
		gStyle->SetStatX(0.99);
		gStyle->SetStatY(0.99);
		gStyle->SetStatW(0.3);
		gStyle->SetStatH(0.20);
	
		//Fill
		gStyle->SetMarkerStyle(20);
		gStyle->SetMarkerSize(1);
		
		gStyle->SetNumberContours(255);
	}

	void printstyle(){
	
	gEnv->SetValue("Canvas.ShowEventStatus",0);	// disable event status bar
	gEnv->SetValue("Canvas.ShowEditor",0);		// disable Canvas Editor
	
		gStyle->SetNdivisions(508,"XY");
		gStyle->SetOptFit(0000);
	
		//Pad
		gStyle->SetPadBorderMode(1);
		gStyle->SetPadColor(0);
		gStyle->SetPadGridX(kTRUE);
		gStyle->SetPadGridY(kTRUE);
		gStyle->SetPadLeftMargin(0.15);
		gStyle->SetPadRightMargin(0.15);
		gStyle->SetPadTopMargin(0.15);
		gStyle->SetPadBottomMargin(0.15);
	
		//Canvas
		gStyle->SetCanvasBorderMode(0);
		gStyle->SetCanvasColor(0);
	
		//Title
		gStyle->SetTitleFont(42,"xyz");
		gStyle->SetTitle(0);
		
		
		//Frame
		gStyle->SetFrameFillColor(0);
		gStyle->SetFrameLineColor(1);
		gStyle->SetFrameFillStyle(1001);
		gStyle->SetFrameLineStyle(1);
		gStyle->SetFrameLineWidth(1);
		gStyle->SetFrameBorderSize(1);
		gStyle->SetFrameBorderMode(0);
		
		//Stat
		gStyle->SetOptStat("e");
		gStyle->SetStatColor(0);
		gStyle->SetStatTextColor(1);
		gStyle->SetStatBorderSize(0);
		gStyle->SetStatFont(42);
		gStyle->SetStatFontSize(0.03);
		gStyle->SetStatStyle(0);
		gStyle->SetStatFormat("6.4g");
		/*
		gStyle->SetStatX(0.89);
		gStyle->SetStatY(0.89);
		gStyle->SetStatW(0.20);
		gStyle->SetStatH(0.100);
		*/
		// small minimal stat in upper right corner
		gStyle->SetStatX(0.85);
		gStyle->SetStatY(0.88);
		gStyle->SetStatW(0.20);
		//---------------------------
		
	

		//Fill
		gStyle->SetMarkerStyle(20);
		gStyle->SetMarkerSize(1);
		
		gStyle->SetNumberContours(255);
	}

	void s1(){
	}
	void s2(){

		//Stat
		gStyle->SetStatX(0.85);
		//gStyle->SetStatY(0.95);
		gStyle->SetPadLeftMargin(0.15);
		gStyle->SetPadRightMargin(0.15);
		gStyle->SetPadTopMargin(0.15);
		gStyle->SetPadBottomMargin(0.15);

	
		MyC->UseCurrentStyle();
	}



void twod(){
	gPad->SetRightMargin(0.17);
	gPad->SetLeftMargin(0.13);
	gPad->SetTopMargin(0.15);
	gPad->SetBottomMargin(0.15);
}
void quad(TCanvas* c,int format_0eps_1png =0){

	if(format_0eps_1png =1){
		Double_t w =350;
		Double_t h =370;
	}
	else{
		Double_t w =350;
		Double_t h =350;
	}
	c->SetWindowSize(w+ (w- c->GetWw()),h + (h- c->GetWh()));
	c->Draw();
	
	gPad->SetRightMargin(0.13);
	gPad->SetLeftMargin(0.13);
	gPad->SetTopMargin(0.13);
	gPad->SetBottomMargin(0.13);


}
void quad_notitle(TCanvas* c,int format_0eps_1png =0){

	if(format_0eps_1png =1){
		Double_t w =350;
		Double_t h =350;
	}
	else{
		Double_t w =340;
		Double_t h =350;
	}
	c->SetWindowSize(w+ (w- c->GetWw()),h + (h- c->GetWh()));
	c->Draw();

	gPad->SetRightMargin(0.13);
	gPad->SetLeftMargin(0.13);
	gPad->SetTopMargin(0.05);
	gPad->SetBottomMargin(0.13);

	c->SetStatX(0.87);
	c->SetStatY(0.95);
	c->SetStatW(0.30);
	c->SetStatH(0.20);

}
void smallmargins(){

	TCanvas *c = (TCanvas*)gROOT->GetListOfCanvases()->Last();
	
	Double_t w =320;
	Double_t h =340;
	c->SetWindowSize(w,h);

	gPad->SetRightMargin(0.05);
	gPad->SetLeftMargin(0.05);
	gPad->SetTopMargin(0.05);
	gPad->SetBottomMargin(0.05);
}
void nomargins(){
//	TCanvas *c = dynamic_cast<TCanvas*>gROOT->GetListOfCanvases()->Last();
	
	gPad->SetRightMargin(0.0);
	gPad->SetLeftMargin(0.0);
	gPad->SetTopMargin(0.0);
	gPad->SetBottomMargin(0.0);
	
}

