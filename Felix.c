#include "TMath.h"
	void felixhelp(){
		printf("\nMacros from Felix:\n");
		printf("(1)	arc(minangle,maxangle,radius) or arc()");
		printf("	draws an arc as an optical subsiduary line\n");
		printf("(2)	void browser() creates small browser in upper right corner (1280 width displ.)");
		printf("\n");
	}



//-------------------------------------------------------------------------------------------------------//
//
//										Felix' functions	
//
//-------------------------------------------------------------------------------------------------------//


void arc(void){
	TArc* A = new TArc(0,0,10,180,360);
	A->Draw();
	A->SetFillStyle(4000);
	A->SetNoEdges();

}
void arc(double min_angle,double max_angle,double radius){

	TArc* A = new TArc(0,0,radius,min_angle,max_angle);
	A->Draw();
	A->SetFillStyle(0);
	A->SetNoEdges();
}

//-------------------------------------------------------------------------------------------------------//
//							Browser, Canvas constructors and maintenance	
//-------------------------------------------------------------------------------------------------------//

///////////////////////////////////////////////////////////////////
void browser(int mode=0)
///////////////////////////////////////////////////////////////////
{
	static int nbrBrowser;
	char name[64];
	sprintf(name,"Browser%i",nbrBrowser);
	if(mode==1)
	new TBrowser(name,name,1250,0,650,600,0,"");
	else
	new TBrowser(name,name,630,0,650,600,0,"");
	nbrBrowser++;
}

///////////////////////////////////////////////////////////////////
void crosshair(int on=1)
///////////////////////////////////////////////////////////////////
{
	if(on)
		gPad->SetCrosshair(1);
	else
		gPad->SetCrosshair(0);
}


///////////////////////////////////////////////////////////////////
void eventbar(int on=1)
///////////////////////////////////////////////////////////////////
{
	if(on)
		gPad->ToggleEventStatus();
}


///////////////////////////////////////////////////////////////////
void close(int all=0)
///////////////////////////////////////////////////////////////////
{
	TList* list = gROOT->GetListOfFiles();
	TFile* gf = dynamic_cast<TFile*>(list->Last());
	if(gf)
		 gf->Close();
	if(all==1)
	{
		int file=1;
		while(file){
			gf= dynamic_cast<TFile*>(list->Last());
			if(!gf)
				file=0;
			else 
				gf->Close();
		}
	}
	else return;
}


///////////////////////////////////////////////////////////////////
void closepads(int all=0)
///////////////////////////////////////////////////////////////////
{
	TList* list = gROOT->GetListOfCanvases();
	TCanvas* gf = dynamic_cast<TCanvas*>(list->Last());
	if(gf)
		 gf->Close();
	if(all==1)
	{
		int Canvas=1;
		while(Canvas){
			gf= dynamic_cast<TCanvas*>(list->Last());
			if(!gf)
				Canvas=0;
			else 
				gf->Close();
		}
	}
	else return;
}


///////////////////////////////////////////////////////////////////
void clean()
///////////////////////////////////////////////////////////////////
{
	close(1);
	closepads(1);
}

///////////////////////////////////////////////////////////////////
void clear()
///////////////////////////////////////////////////////////////////
{
	gPad->Clear();
}


///////////////////////////////////////////////////////////////////
void newc(int hor=1,int ver=1)
///////////////////////////////////////////////////////////////////
{
	printstyle();
	TCanvas* c = newcp(hor,ver,0);
	c->Draw();
}

/*
///////////////////////////////////////////////////////////////////
void newcd(int hor=1, int ver=1)
///////////////////////////////////////////////////////////////////
{
	TCanvas * c = newcd(hor, ver);
	c->Draw();
	}
*/
///////////////////////////////////////////////////////////////////
TCanvas* newcd(int hor=1, int ver=1)
///////////////////////////////////////////////////////////////////
// Canvas for displaystyle
{
	static int nbrCanv;
	char name[64];
	char title[64];
	sprintf(name,"c%i",nbrCanv);
	sprintf(title,"MyCanvas%i",nbrCanv);
	nbrCanv++;
	Double_t w,h;
		w =hor*500;
		h =ver*500;
		
	TCanvas * c = new TCanvas(name,title,w,h);
	c->SetWindowSize(w*1.23,h);
	c->Divide(hor,ver,0.0001,0.0001);
	return c;
}
///////////////////////////////////////////////////////////////////
TCanvas* newcp(int hor=1,int ver=1,int format_0eps_1png =0)
///////////////////////////////////////////////////////////////////
{

	//function aus LutzAchim.c

	////find out which size is the max, so that all subpads are still rectangluar but not bigger than 367//
	//double h = gClient->GetDisplayHeight();
	//double w = gClient->GetDisplayWidth();
	//h -=26;
	//w -=10;
	//double hm = h/(double)ver;
	//double wm = w/(double)hor;
	//double maxsize = (wm>hm)? hm:wm;
	//if (maxsize > 500) maxsize = 500;
	//double cw = gStyle->GetScreenFactor();	//root multiplies the height and the width by this number
	//so in order to get the wanted size we need to divide the values by this number first

	static int nbrCanv;
	char name[64];
	char title[64];
	sprintf(name,"c%i",nbrCanv);
	sprintf(title,"MyCanvas%i",nbrCanv);
	nbrCanv++;
	Double_t w,h;
	
	if(format_0eps_1png==1){
		w =hor*350*2;
		h =ver*340;
	}
	else{
		w =hor*350;
		h =ver*340;
	}	
	TCanvas * c = new TCanvas(name,title,w,h);
	c->SetWindowSize(w+ (w- c->GetWw()),h + (h- c->GetWh()));
	c->Divide(hor,ver,0.0001,0.0001);
	return c;
}


// Format canvas size for print
/*void resizec(TCanvas* c,Double_t w,Double_t h,int format_0eps_1png =0)
{
	if(format_0eps_1png==1){
	w =hor*350;
	h =ver*350+20;
	}
	else{
	Double_t w =hor*350;
	Double_t h =ver*350;
	}
	C->SetWindowSize(w+ (w- C->GetWw()),h + (h- C->GetWh()));
}*/


///////////////////////////////////////////////////////////////////
void bcanv(int hor=1, int ver=1)
///////////////////////////////////////////////////////////////////
{
	TCanvas*c = bcanv(hor,ver);
	c->Draw();
}


///////////////////////////////////////////////////////////////////
TCanvas* bcanvp(int hor=1, int ver=1)
///////////////////////////////////////////////////////////////////
{
	//find out which size is the max, so that all subpads are still rectangluar but not bigger than 367//
	double h = gClient->GetDisplayHeight();
	double w = gClient->GetDisplayWidth();
	h -=26;
	w -=10;
	double hm = h/(double)ver;
	double wm = w/(double)hor;
	double maxsize = (wm>hm)? hm:wm;
	if (maxsize > 500) maxsize = 500;
	double cw = gStyle->GetScreenFactor();	//root multiplies the height and the width by this number
											//so in order to get the wanted size we need to divide the values by this number first

	static int nbrCanv;
	char name[64];
	char title[64];
	sprintf(name,"MyC%i",nbrCanv);
	sprintf(title,"MyCanvas %i",nbrCanv);
	nbrCanv++;
	TCanvas * MyC = new TCanvas(name,title,-1,1,maxsize*(double)hor/cw,maxsize*(double)ver/cw);
	MyC->Divide(hor,ver,0.0001,0.0001);
	MyC->ToggleEventStatus();
	for (int i=1;i<=hor*ver;++i)
	{
		MyC->cd(i);
		//gPad->SetRightMargin(0.15);
		gPad->SetLeftMargin(0.15);
		gPad->SetTopMargin(0.15);
		gPad->SetBottomMargin(0.15);
	}
	return MyC;
}


//-------------------------------------------------------------------------------------------------------//
//										Histogram drawing	
//-------------------------------------------------------------------------------------------------------//

///////////////////////////////////////////////////////////////////
void drawhistos(TObject * hi1,TObject * hi2)
///////////////////////////////////////////////////////////////////
{
	TH1D * hi1d1;
	TH1D * hi1d2;
		hi1d1 = (TH1D*)hi1;
		hi1d2 = (TH1D*)hi2;

		hi1d2->SetLineColor(2);
		hi1d1->SetLineWidth(2);
		hi1d2->SetLineWidth(2);
		hi1d1->Draw();
		normalize_integral_y();
		hi1d2->Draw();
		normalize_integral_y();

		double ymax1 = hi1d1->GetMaximum();
		double ymax2 = hi1d2->GetMaximum();
		double ymax;
		if(ymax1>=ymax2)ymax = ymax1;
		else ymax = ymax2;

		hi1d1->GetYaxis()->SetRangeUser(0,1.02*ymax);
		hi1d2->GetYaxis()->SetRangeUser(0,1.02*ymax);
		hi1d1->Draw();
		hi1d2->Draw("same");
}


///////////////////////////////////////////////////////////////////
void drawhistos(TObject * hi1,TObject * hi2,double XrangeMin,double XrangeMax,int rebin)
///////////////////////////////////////////////////////////////////
{
	TH1D * hi1d1;
	TH1D * hi1d2;
		hi1d1 = (TH1D*)hi1;
		hi1d2 = (TH1D*)hi2;

		hi1d2->SetLineColor(2);
		hi1d1->SetLineWidth(2);
		hi1d2->SetLineWidth(2);
		hi1d1->Rebin(rebin);
		hi1d1->Draw();
		normalize_integral_y();
		hi1d2->Draw();
		hi1d2->Rebin(rebin);
		normalize_integral_y();

		double ymax1 = hi1d1->GetMaximum();
		double ymax2 = hi1d2->GetMaximum();
		double ymax;
		if(ymax1>=ymax2)ymax = ymax1;
		else ymax = ymax2;

		
		
		hi1d1->GetYaxis()->SetRangeUser(0,1.02*ymax);
		hi1d2->GetYaxis()->SetRangeUser(0,1.02*ymax);
		hi1d1->GetXaxis()->SetRangeUser(XrangeMin,XrangeMax);
		hi1d2->GetXaxis()->SetRangeUser(XrangeMin,XrangeMax);
		
		hi1d1->Draw();
		hi1d2->Draw("same");
}


///////////////////////////////////////////////////////////////////
void drawhistos(TObject * hi1,TObject * hi2,double XrangeMin,double XrangeMax,double YrangeMin,double YrangeMax,int rebin)
///////////////////////////////////////////////////////////////////
{
	TH1D * hi1d1;
	TH1D * hi1d2;
		hi1d1 = (TH1D*)hi1;
		hi1d2 = (TH1D*)hi2;

		hi1d2->SetLineColor(2);
		hi1d1->SetLineWidth(2);
		hi1d2->SetLineWidth(2);
		hi1d1->Rebin(rebin);
		hi1d1->Draw();
		normalize_integral_y();
		hi1d2->Draw();
		hi1d2->Rebin(rebin);
		normalize_integral_y();
		
		hi1d1->GetYaxis()->SetRangeUser(YrangeMin,YrangeMax);
		hi1d2->GetYaxis()->SetRangeUser(YrangeMin,YrangeMax);
		hi1d1->GetXaxis()->SetRangeUser(XrangeMin,XrangeMax);
		hi1d2->GetXaxis()->SetRangeUser(XrangeMin,XrangeMax);
		
		hi1d1->Draw();
		hi1d2->Draw("same");
}


///////////////////////////////////////////////////////////////////
TObject* drawhistosp(TObject * hi1,TObject * hi2)
///////////////////////////////////////////////////////////////////
{
	//TCanvas *c1 = gPad->GetCanvas();
	TH1D * hi1d1;
	TH1D * hi1d2;
		hi1d1 = (TH1D*)hi1;
		hi1d2 = (TH1D*)hi2;

		hi1d2->SetLineColor(2);
		hi1d1->Draw();
		normalize_integral_y();
		hi1d2->Draw();
		normalize_integral_y();

		double ymax1 = hi1d1->GetMaximum();
		double ymax2 = hi1d2->GetMaximum();
		double ymax;
		if(ymax1>=ymax2)ymax = ymax1;
		else ymax = ymax2;

		hi1d1->GetYaxis()->SetRangeUser(0,1.02*ymax);
		hi1d2->GetYaxis()->SetRangeUser(0,1.02*ymax);
		hi1d1->Draw();
		hi1d2->Draw("same");
		return hi1d2;
}


///////////////////////////////////////////////////////////////////
void drawhistos(TObject * hi1,TObject * hi2,TObject* hi3)
///////////////////////////////////////////////////////////////////
{
	TH1D * hi1d1;
	TH1D * hi1d2;
	TH1D * hi1d3;
	hi1d1 = dynamic_cast<TH1D*>(hi1);
	hi1d2 = dynamic_cast<TH1D*>(hi2);
	hi1d3 = dynamic_cast<TH1D*>(hi3);

	hi1d2->SetLineColor(2);
	hi1d3->SetLineColor(4);
	hi1d1->Draw();
	normalize_integral_y();
	hi1d2->Draw();
	normalize_integral_y();
	hi1d3->Draw();
	normalize_integral_y();

	double ymax1 = hi1d1->GetMaximum();
	double ymax2 = hi1d2->GetMaximum();
	double ymax3 = hi1d3->GetMaximum();
	double ymax;
	if(ymax1>=ymax2){
		if(ymax>=ymax3)ymax = ymax1;
		else ymax = ymax3;
	}
	else{
		if(ymax2>=ymax3) ymax =ymax2;
		else ymax = ymax3;
	}

	hi1d1->GetYaxis()->SetRangeUser(0,1.02*ymax);
	hi1d2->GetYaxis()->SetRangeUser(0,1.02*ymax);
	hi1d3->GetYaxis()->SetRangeUser(0,1.02*ymax);
	hi1d1->Draw();
	hi1d2->Draw("same");
	hi1d3->Draw("same");
}


//-------------------------------------------------------------------------------------------------------//
//										Histogram editing	
//-------------------------------------------------------------------------------------------------------//

///////////////////////////////////////////////////////////////////
void rebin(int merge_n_bins=2)
///////////////////////////////////////////////////////////////////
{

    TList   *list = gPad->GetListOfPrimitives();
    TObject *obj  = list->First();

	while(obj)
	{
		if( !strncmp("TH1",obj->ClassName(),3) ) 
		{
			TH1D *hist1 = (TH1D*)obj;
			hist1->Rebin(merge_n_bins);
		}
		if( !strncmp("TH2",obj->ClassName(),3) ) 
		{
			TH2D *hist2 = (TH2D*)obj;
			hist2->Rebin2D();
		}
		obj = list->After(obj);


	}
	
}


///////////////////////////////////////////////////////////////////
void Int(double x1, double x2)
///////////////////////////////////////////////////////////////////
{
	int a = Int(x1,x2);
	cout << "Integral: "<<a<<endl;
	
}


///////////////////////////////////////////////////////////////////
int Int(double x1,double x2)
///////////////////////////////////////////////////////////////////
{
	TH1*hist1 = get1DHistFromPad();
	//--get min and max--//     
	Double_t xmin = (x1 >= x2)? x2:x1;
	Double_t xmax = (x1 <= x2)? x2:x1;

	//--find the corosponding bins--//
	Int_t binx1 = hist1->GetXaxis()->FindBin(xmin);
	Int_t binx2 = hist1->GetXaxis()->FindBin(xmax);

	//--get Integral--//
	Double_t integral = hist1->Integral(binx1,binx2);
	int res = (int) integral;
	return res;
}


///////////////////////////////////////////////////////////////////
void normalize2peak(int bin_number=0)
///////////////////////////////////////////////////////////////////
//if no bin is specified, the function normalizes to the maximum
{

    	TList *list = gPad->GetListOfPrimitives();
   	TObject *obj  = list->First();
	TH1D *hist1;
	int dimension=0;

 	while(obj) {
      		if( !strncmp("TH1",obj->ClassName(),3) ) {
	        	dimension = 1;
			TH1D *hist1 = (TH1D*)obj;
			break;
      		}
      		obj = list->After(obj);
      	}

    	if (dimension == 0) printf("No histgram found in this pad.\n");

	if (dimension == 1){
		normalize2peak(hist1,bin_number);
	}

}


///////////////////////////////////////////////////////////////////
TH1* normalize2peakX(TH1* hist1,double peakX)
///////////////////////////////////////////////////////////////////
{	
	int peakXbin = hist1->GetXaxis()->FindBin(peakX);
	hist1 = normalize2peak(hist1,peakXbin);
}


///////////////////////////////////////////////////////////////////
TH1* normalize2peak(TH1* hist1,int bin_number=0)
///////////////////////////////////////////////////////////////////
//if no bin is specified, the function normalizes to the maximum
{
	int binxmin,binxmax,binymin,binymax;
	double content,factor;
	int peak =10;

	hist1->GetXaxis()->UnZoom();
	hist1->GetYaxis()->UnZoom();
	binxmin = hist1->GetXaxis()->GetFirst();
	binxmax = hist1->GetXaxis()->GetLast();	
	if (bin_number==0)	bin_number=hist1->GetMaximumBin();
	if(bin_number==-1) bin_number= hist1->GetNbinsX()/2;
	
	if(hist1->GetBinContent(bin_number)!=0){
		factor = peak / (hist1->GetBinContent(bin_number));
		
		for (int i=binxmax;i>=binxmin;i--) {
			content = hist1->GetBinContent(i);
			hist1->SetBinContent(i,content*factor);
			hist1->SetBinError(i,sqrt(content)*factor);
		}
		//gPad->Modified();
		//gPad->Update();
	} 
	else printf("Bin content is zero.\n");
	
	return hist1;
}


///////////////////////////////////////////////////////////////////
void normalize_integral_y(TH1*hist1)
///////////////////////////////////////////////////////////////////
{    
	int binx = hist1->GetXaxis()->GetNbins();

	double integral = 0.;
	for (int x = 1;x<=binx;++x) {
		integral +=  hist1->GetBinContent(x);
	}
	for (int x = 1;x<=binx;++x) {
		hist1->SetBinContent(x,hist1->GetBinContent(x)/integral);
	}
}


///////////////////////////////////////////////////////////////////
void mirrorhist(int range =1) 
///////////////////////////////////////////////////////////////////
{
	TH1* hist = get1DHistFromPad();
	int nbins = hist->GetNbinsX();
	int newnbins= 2*nbins;
	if(range==1)
	TH1D* mhist = new TH1D("mhist","mirrorhist",newnbins,-1,3);
	else
	TH1D* mhist = new TH1D("mhist","mirrorhist",newnbins,0,360);
	
	for (int i=1;i<=nbins;++i)
		{
			double temp = hist->GetBinContent(i);
			mhist->SetBinContent(i,temp);
			mhist->SetBinContent(newnbins-i+1,temp);
		}
	mhist->Draw();
}


///////////////////////////////////////////////////////////////////	
void mirrorAngle(int mode=0)
///////////////////////////////////////////////////////////////////
{
	TH1* hist = get1DHistFromPad();
	if (mode == 1)
	mirrorAngle360(hist);
	else 
	mirrorAngle1(hist);
	}


///////////////////////////////////////////////////////////////////
TH1* mirrorAngle1(TH1*hist)
// make 1D hist of range -1 to 1
///////////////////////////////////////////////////////////////////
{
	//TH1* hist = get1DHistFromPad();
	int nbins = hist->GetNbinsX();
	int newnbins= nbins; 
	TH1D* mhist = new TH1D("mhist","mirrorhist",newnbins,-1,1);
	
	for (int i=1;i<=nbins/2;++i)
		{
			double temp = hist->GetBinContent(i);
			mhist->SetBinContent(i,temp);
			mhist->SetBinContent(newnbins-i+1,temp);
		}
	return mhist;

}


///////////////////////////////////////////////////////////////////
TH1* mirrorAngle360(TH1*hist)
// make 1D hist of range 0 to 360
///////////////////////////////////////////////////////////////////
{
	//TH1* hist = get1DHistFromPad();
	int nbins = hist->GetNbinsX();
	int newnbins= nbins;
	TH1D* mhist = new TH1D("mhist","mirrorhist",newnbins,0,360);
	
	for (int i=1;i<=nbins/2;++i)
		{
			double temp = hist->GetBinContent(i);
			mhist->SetBinContent(i,temp);
			mhist->SetBinContent(newnbins-i+1,temp);
		}
	return mhist;

}


///////////////////////////////////////////////////////////////////
void MakeFullAG()
// convert Angular distribtution from Hist(0-180) to 0-360
///////////////////////////////////////////////////////////////////
{
	TH1* Phist = get1DHistFromPad();
//UNFINISHED!
	}


///////////////////////////////////////////////////////////////////
TH1*mirror1D(TH1*hist)
///////////////////////////////////////////////////////////////////
{
	TH1D*mhist= (TH1D*)hist->Clone("mirrorhist");
	int nbins = hist->GetNbinsX();
	
	for (int i=1;i<=nbins;++i)
		{
			double temp = hist->GetBinContent(i);
			mhist->SetBinContent(nbins-i+1,temp);
		}
	return mhist;
}

///////////////////////////////////////////////////////////////////
void mirrorX_2d(int pos_only =1)
///////////////////////////////////////////////////////////////////
{
	TH2D* hist = get2DHistFromPad();
	
		if (!hist) return;
	int i,j;

	int Nx,Ny;
	double a1;

	if (!hist->InheritsFrom("TH2")) return;		

	hist->GetXaxis()->UnZoom();
	hist->GetYaxis()->UnZoom();

	Nx = hist->GetXaxis()->GetLast();
	Ny = hist->GetYaxis()->GetLast();

	double max = -1.e200;
	double min = 1.e200;

	for (i=1;i<=int(Nx/2);i++)
	{
		for (j=1;j<=Ny;j++)
		{
			if(pos =1)
				a1 = (hist->GetBinContent(Nx-i+1,j));
			else if(pos=2)
				a1 = (hist->GetBinContent(i,j));
			else
				a1 = (hist->GetBinContent(i,j)+hist->GetBinContent(Nx-i+1,j))*0.5;
			if (a1 > max) max = a1;
			if (a1 < min) min = a1;
			hist->SetBinContent(i,j,a1);
			hist->SetBinContent(Nx-i+1,j,a1);
		}
	}
	hist->SetMaximum(max*1.1);
	hist->SetMinimum(min);
	
	hist->Draw();
}


///////////////////////////////////////////////////////////////////
TH1*merge(TH1*hist1,TH1*hist2)
///////////////////////////////////////////////////////////////////
{
	TH1D*shist= (TH1D*)hist1->Clone("SumHist");
	int nbins = hist1->GetNbinsX();

	for (int i=1;i<=nbins;++i)
		{
			shist->SetBinContent(i,0);
		}

	shist->Add(hist1,hist2,1,1);
	return shist;
}

///////////////////////////////////////////////////////////////////
TObject* tcos2angle(TObject* hist, char* newhistname)
///////////////////////////////////////////////////////////////////
{
//	transform cos(theta) to theta plot
	TH1D * hist1d;
	hist1d = dynamic_cast<TH1D*>(hist);
	TH1D* newhist = new TH1D(newhistname,newhistname,hist1d->GetNbinsX(),0,180);

	for (i=hist1d->GetXaxis()->GetFirst();i<=hist1d->GetXaxis()->GetLast();i++)
	{	
		if (fabs(hist1d->GetBinContent(i))>1.e-300)
		{
			double costheta = hist1d->GetBinContent(i);
			double theta = ROOT::TMath::ACos(costheta);
			newhist->SetBinContent(i,theta);
		 }
	 }	
	 return newhist;
}


///////////////////////////////////////////////////////////////////
void polarfelix(TH1D * hist1, bool mirror=true)
///////////////////////////////////////////////////////////////////
{
	//check wether the histo has the right ranges--//
	if( (hist1->GetXaxis()->GetXmin() !=-180) && 
		(hist1->GetXaxis()->GetXmax() != 180) &&
		(hist1->GetXaxis()->GetXmin() !=   0) &&
		(hist1->GetXaxis()->GetXmax() != 360) &&
		(hist1->GetXaxis()->GetXmin() !=  -1) &&
		(hist1->GetXaxis()->GetXmax() !=   1) &&
		(hist1->GetXaxis()->GetXmax() !=   3)
	  )
	{
		cout << "The Histogram has the wrong Range:"<<endl;
		cout << "   "<< hist1->GetXaxis()->GetXmin() << " ... "<< hist1->GetXaxis()->GetXmax()<<endl;
		cout << "This Macro only supports Histograms in the following Ranges:"<<endl;
		cout << "   -180 ... 180"<<endl;
		cout << "or    0 ... 360"<<endl;
		cout << "or   -1 ... 1"<<endl;
		cout << "or   -1 ... 3 (for full cos(theta) plot)"<<endl;

		return;
	}

	double Max = hist1->GetMaximum();
	gPad->Range(-Max*1.5,-Max*1.5,Max*1.5,Max*1.5);
	gPad->Clear();


	//-----------------------------		Graphics		-----------------------------//
	
	
	
	// box
	TLine *l = new TLine(-Max*1.2,-Max*1.2,-Max*1.2,Max*1.2);
	l->SetLineColor(17);// gray
	l->Draw();
	l->DrawLine(Max*1.2,-Max*1.2,Max*1.2,Max*1.2);
	l->DrawLine(-Max*1.2,-Max*1.2,Max*1.2,-Max*1.2);
	l->DrawLine(-Max*1.2,Max*1.2,Max*1.2,Max*1.2);
	
	
	// cross
	l->DrawLine(-Max*1.2,0,Max*1.2,0);
	l->DrawLine(0,-Max*1.2,0,Max*1.2);
	//l->DrawLine(0,-Max*1.2,0,Max*1.2);
	
//circle
	
	TArc * ar = new TArc(0.,0.,Max*0.9);
	ar->SetLineColor(17);	//gray; alternative kRed
	//ar->SetLineWidth(2);
	ar->SetFillStyle(0);
	ar->Draw();
	//ar->DrawArc(0.,0.,0.5*Max);
	*/
	
	//tics
	double pi=3.1415;
	for(int i=0;i<12;i++) {
		double phi=double(i)*2.*pi/12.;
	
		if((phi >= pi*7./4.)||(phi < pi/4.)) {  
			double x1=0.9 * Max*1.2;
			double y1=0.9 * tan(phi) * Max*1.2;    
			double x2=1. * Max*1.2;
			double y2=tan(phi) * Max*1.2;
			l->DrawLine(x1,y1,x2,y2);

		}
		if((phi >= pi/4.)&&(phi < pi*3./4.)) {  
			double x1=0.9/tan(phi) * Max*1.2;
			double y1=0.9 * Max*1.2;    
			double x2=1./tan(phi) * Max*1.2;
			double y2=1. * Max*1.2;
			l->DrawLine(x1,y1,x2,y2);
		}			
		if((phi >= pi*3./4.) && (phi < pi*5./4.)) {  
			double x1=-0.9 * Max*1.2;
			double y1=-0.9*tan(phi) * Max*1.2;    
			double x2=-1. * Max*1.2;
			double y2=-tan(phi) * Max*1.2;
			l->DrawLine(x1,y1,x2,y2);
			l->Draw();
		}
		if((phi >= pi*5./4.)&&(phi < pi*7./4.)) {
			double x1=-0.9/tan(phi) * Max*1.2;
			double y1=-0.9 * Max*1.2;    
			double x2=-1./tan(phi) * Max*1.2;
			double y2=-1. * Max*1.2;
			l->DrawLine(x1,y1,x2,y2);
		}
	}
	
	
	//--------------------------------------------------------------------------------//


	// Draw points and errors
	for (int i=1;i<=hist1->GetNbinsX();i++)
	{	
		double mx=0;
		double my=0;
		double ex1=0;
		double ex2=0;
		double ey1=0;
		double ey2=0;
		

		if(   hist1->GetXaxis()->GetXmax()==180 && hist1->GetXaxis()->GetXmin()==-180 //for when things are in degrees
		   || hist1->GetXaxis()->GetXmax()==360 && hist1->GetXaxis()->GetXmin()==0 )
		{
			mx = cos(hist1->GetBinCenter(i)*3.1415/180.)*hist1->GetBinContent(i);
			my = sin(hist1->GetBinCenter(i)*3.1415/180.)*hist1->GetBinContent(i);
			
			ex1=mx - 0.5*hist1->GetBinError(i)*cos(hist1->GetBinCenter(i)*3.1415/180.);
			ex2=mx + 0.5*hist1->GetBinError(i)*cos(hist1->GetBinCenter(i)*3.1415/180.);
			ey1=my - 0.5*hist1->GetBinError(i)*sin(hist1->GetBinCenter(i)*3.1415/180.);
			ey2=my + 0.5*hist1->GetBinError(i)*sin(hist1->GetBinCenter(i)*3.1415/180.);
		}

		if(   hist1->GetXaxis()->GetXmax()==1 && hist1->GetXaxis()->GetXmin()==-1 ) //for when things are in cos
		{
			mx = hist1->GetBinCenter(i)*hist1->GetBinContent(i);
			my = sqrt(1.- (hist1->GetBinCenter(i)*hist1->GetBinCenter(i)))*hist1->GetBinContent(i);

			ex1=hist1->GetBinCenter(i)*hist1->GetBinContent(i) - 0.5*hist1->GetBinError(i)*hist1->GetBinCenter(i);
			ex2=hist1->GetBinCenter(i)*hist1->GetBinContent(i) + 0.5*hist1->GetBinError(i)*hist1->GetBinCenter(i);
			ey1=sqrt(1.- (hist1->GetBinCenter(i)*hist1->GetBinCenter(i)))*hist1->GetBinContent(i) - 0.5*hist1->GetBinError(i)*sin(acos(hist1->GetBinCenter(i)));
			ey2=sqrt(1.- (hist1->GetBinCenter(i)*hist1->GetBinCenter(i)))*hist1->GetBinContent(i) + 0.5*hist1->GetBinError(i)*sin(acos(hist1->GetBinCenter(i)));
			
		}		

		TMarker *m = new TMarker(mx,my,8);
		m->Draw();
		TLine *l = new TLine(ex1,ey1,ex2,ey2);
		l->Draw();
		
		
		// mirror histogramm to make a full distribution
		
		if(mirror && hist1->GetXaxis()->GetXmax() == 1)
		
		{
		
			m->DrawMarker(mx,-my);
			l->DrawLine(ex1,-ey1,ex2,-ey2);
	
		}
	}
}

///////////////////////////////////////////////////////////////////
void polarfelix()
///////////////////////////////////////////////////////////////////
{
    TList   *list = gPad->GetListOfPrimitives();
    TObject *obj  = list->First();

	while(obj)
	{
		if( !strncmp("TH1",obj->ClassName(),3) ) 
		{
			TH1D *hist1 = (TH1D*)obj;
			polarfelix(hist1);
		}
		obj = list->After(obj);
	}
}


//-------------------------------------------------------------------------------------------------------//
//										Import/Export	
//-------------------------------------------------------------------------------------------------------//

///////////////////////////////////////////////////////////////////
void saveimg(const char * image = "image", const char* format = ".png")
///////////////////////////////////////////////////////////////////
{
//////////////////////	save current canvas	////////////////////////
//
// Save specific canvas:
// void saveimg(TCanvas* c, const char * image = "image", Option_t* format = ".png")
//
// Save active canvas:
// void saveimg(const char * image = "image", const char* format = ".png")
///////////////////////////////////////////////////////////////////
	TPad* c1= gPad;
	char tdirectory[64];
	char targetd[128];
	//sprintf(tdirectory,"/Volumes/Scratch/FPSturm/ICD/Analysis_plots/");
	sprintf(tdirectory,"C:\Users\fpsturm\GoogleDrive\2-333 Lab Shared\MISTERS_data\09252014_02double_Tin");
	
	sprintf(targetd,"%s%s%s",tdirectory,image,format);
	c1->Print(targetd);
}




//-------------------------------------------------------------------------------------------------------//
//										Graphics	
//-------------------------------------------------------------------------------------------------------//

///////////////////////////////////////////////////////////////////
void drawcross()
///////////////////////////////////////////////////////////////////
{
	// 45deg lines
// 	TLine l;
// 	Double_t theta = TMath::Pi()/4;
// 	Double_t dtheta = TMath::Pi()/2;
// 	for(int i=1;i<=4;i++){
// 		l.DrawLine(0.,0.,TMath::Cos(theta),TMath::Sin(theta));
// 		theta += dtheta;
// 	}
	
	// cross
// 	TLine *l2= new TLine(-1.1,0,1.1,0);
// 	l2->Draw();
// 	TLine *l2 = new TLine(0,-1.1,0,1.1);
// 	l2->Draw();
	
	//1 cross
	TLine *l2= new TLine(-1.,0,1.,0);
	l2->Draw();
	TLine *l2 = new TLine(0,-1.,0,1.);
	l2->Draw();
	
	// tics
	int nboftics=4;
	for(int i=0;i<=nboftics;i++){
		double step = 2./ double (nboftics);
		double  x1,x2,x3,x4,y1,y2,y3,y4;
		//horiz tics
		x1=-1+i*step;
		y1=-0.03;
		x2=x1;
		y2=-y1;
		//vert tics
		x3=-0.03;
		y3=-1+i*step;
		x4=-x3;
		y4=y3;
		
		TLine *t = new TLine(x1,y1,x2,y2);
		TLine *t2 = new TLine(x3,y3,x4,y4);
		t->Draw();
		t2->Draw();	
	}
}	


///////////////////////////////////////////////////////////////////
circle(double radius=5.0,int color=kRed)
///////////////////////////////////////////////////////////////////


//circle at x=0,y=0 with given radius and color
void

{
	TArc * ar = new TArc(0.,0.,radius);
	ar->SetLineColor(color);	//gray; alternative kRed
	//ar->SetLineWidth(2);
	ar->SetFillStyle(0);
	ar->Draw();

}








	
	
	
	
//-------------------------------------------------------------------------------------------------------

//								Unfinished functions

//-------------------------------------------------------------------------------------------------------
/*
///////////////////////////////////////////////////////////////////	
void TextBox(const char* text,int placement=0)
///////////////////////////////////////////////////////////////////

{
	pt = new TPaveText(0.4,0.8,0.6,0.7,0, "NDC"); // NDC sets coords
	// relative to pad dimensions
	
	pt->SetFillColor(0); // text is black on white.
	
	pt->SetTextSize(0.04); 
	
	pt->SetTextAlign(12);
	
	text = pt->AddText(text);
	
	pt->Draw();       //to draw your text object

}



//////////////////////	drawhisto by name	//////////////////////////////////////////////////////////////////////
//void drawbyname(char* histoname)
///////////////////////////////////////////////////////////////////
//{
// TObject *obj;
// obj = gFile->FindKeyAny(histoname)->ReadObj();
// TH1D * hist1d;
// TH2D * hist2d;
//
// 
//	if( !strncmp("TH1D", obj->ClassName(), 4) ) {
//		hist1d = dynamic_cast<TH1>(obj);
//		hist1d->Draw();
//	}
//	else if( !strncmp("TH2D", obj->ClassName(), 4) ) {
//		hist2d = dynamic_cast<TH2>(obj);
//		hist2d->Draw();
//	}
//	else{
//		printf{"Histogram dimension is wrong.\n"}
//		return;
//	}
//	histo->Draw();	
//}

*/