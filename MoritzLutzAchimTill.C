#ifndef LUTZACHIMTILL_C
#define LUTZACHIMTILL_C

#include <iostream>
#include <fstream>

#include "TH1.h"
#include "TH2.h"
#include "TH3.h"
#include "TCanvas.h"
#include "TStyle.h"
#include "TRoot.h"
#include "TMath.h"
#include "TList.h"
#include "TGClient.h"
#include "TGAxis.h"
#include "TPaveText.h"
#include "TGraph.h"
#include "TMarker.h"
#include "TF1.h"
#include "TEllipse.h"
#include "THLimitsFinder.h"
#include "TLatex.h"
#include "TKey.h"
#include "RQ_OBJECT.h"
#include "TVirtualX.h"
#include "TRandom.h"
#include "TArc.h"
#include "TPoint.h"
#include "TPolyLine.h"
#include "TPaveStats.h"
#include "TColor.h"


//--This file contains macros that were written by Achim Czasch, Till Jahnke and Lutz Foucar--//
void help()
{
	cout<<"******Root macros written by Achim Czasch, Till Jahnke and Lutz Foucar modified by Moritz Meckel******"<<endl;
	cout<<endl;
	cout<<"Version date: 05. Nov. 2013"<<endl;
	cout<<endl;
	cout<<"##################Commonly used Macros#########################"<<endl;
	cout<<"*.)  aspect(0 or 1)"<<endl;
	cout<<"*.)  zoom2d(Rectangle=true) (true means that an rectangle is forced)"<<endl;
	cout<<"*.)  circle() (draws a circle at center 0,0)"<<endl;
	cout<<"     circle(x,y) (draws a circle with radius at center x,y)"<<endl;
	cout<<"     circle(center=0,0,radius) (draws a circle with radius at center)"<<endl;
	cout<<"     circle(true) (first find center Cobold style, then draw circle)"<<endl;
	cout<<"*.)  Int() (gives U the nbr of entries interactively)"<<endl;
	cout<<"     Int(from, to) (gives U the nbr of entries in the given range)"<<endl;
	cout<<"*.)  add(nbr) (add nbr to current histogram)"<<endl;
	cout<<"     add(hist,nbr) (add nbr to hist)"<<endl;
	cout<<"*.)  mult(nbr)      (multiply nbr to current histogram)"<<endl;
	cout<<"*.)  mult(hist,nbr) (multiply nbr to hist)"<<endl;
	cout<<"*.)  printHistos(const char* Name, dimension=2, format=3)"<<endl;
	cout<<"              format = 1 => ps"<<endl;
	cout<<"              format = 2 => eps"<<endl;
	cout<<"              format = 3 => gif"<<endl;
	cout<<"              format = 4 => svg"<<endl;
	cout<<"              format = 5 => pdf"<<endl;
	cout<<"*.)  gaus() (makes a gaus fit in a 1D histo interactively)"<<endl;
	cout<<"     gaus(from,to) (makes a gauss fit to a 1D histo in given range)"<<endl;
	cout<<"*.)  unzoom() (unzooms histograms)"<<endl;
	cout<<"*.)  dist() (measures the distance between two points)"<<endl;
	cout<<"*.)  findMaximum(hist, max=0)   (find the maximum in hist)"<<endl; 
	cout<<"*.)  findMinimum(hist, min=0)   (find the minimum in hist)"<<endl;
	cout<<"*.)  locate() (draws the points you click in Histo)"<<endl;
	cout<<"*.)  locate_c() (gives out c-code)"<<endl;
	cout<<"*.)  flipx(hist) (makes a Hist symmetrical in x)"<<endl;
	cout<<"*.)  flipy(2dhist) (makes a 2d Hist symmetrical in y)"<<endl;
	cout<<endl;
	cout<<"*.)  lin() (makes y linear scale)"<<endl;
	cout<<"*.)  log() (makes y log scale)"<<endl;
	cout<<"*.)  linz() (makes z linear scale)"<<endl;
	cout<<"*.)  logz() (makes z log scale)"<<endl;
	cout<<"*.)  linx() (makes x linear scale)"<<endl;
	cout<<"*.)  logx() (makes x log scale)"<<endl;
	cout<<endl;
	cout<<"*.)  swap(pad1,pad2) (swaps the contents of two pads)"<<endl;
	cout<<"*.)  color(int colornbr) (0:Greyscale)"<<endl;
	cout<<"                         (1:Cobold)"<<endl;
	cout<<"                         (2:Till)"<<endl;
	cout<<"                         (3:Maciek)"<<endl;
	cout<<"                         (4:Till Std)"<<endl;
	cout<<"*.)  setminmax(min,max) (sets the minimum and maximum of the histogram)"<<endl;
	cout<<"*.)  remfit() (removes the fit from the hist)"<<endl;
	cout<<"*.)  printCanv() (prints the contents of all open Canvases)"<<endl;
	cout<<"*.)  hist2ascii(hist_pointer,\"FileName\") (Converts a Histogram to ASCII)"<<endl;
	cout<<"*.)  hist2ascii(\"FileName\") (Converts the active Histogram to ASCII)"<<endl;
	cout<<"*.)  centerTitleBox(TPad * pad=0) (Centers the Title Box for Pad. If no Pad is"<<endl;
	cout<<"             given, then centers the title of current pad)"<<endl;
	cout<<"*.)  pointer = addHistos(histpointer1,histpointer2) (adds the histos)"<<endl;
	cout<<"*.)  pointer = subHistos(histpointer1,histpointer2) (substracts hist2 from hist1)"<<endl;
	cout<<"*.)  divHistos(histpointer1,histpointer2) (divides hist1 by hist2)"<<endl;
	cout<<"*.)  Canv(int tilehor=1, int tilever=1) (creates a Canvas with nbr of hor"<<endl;
	cout<<"                                          and nbr of ver subpads)"<<endl;
	cout<<"*.)  foldGauss(hist,fwhm) (fold 1D- or 2D-hist with gauss function)"<<endl;
	cout<<endl;
	cout<<"*.)  prox(Nbr+-Bins=-1) (if nbr+-bins is >-1 then it draws the"<<endl;
	cout<<"              projection in a separat canvas online with +- nbrbins"<<endl;
	cout<<"              around the mouse)"<<endl;
	cout<<"     prox() (interactive projection to the x-axis)"<<endl;
	cout<<"     prox(from,to) (project current histogram to x in given region)"<<endl;
	cout<<"     prox(hist,from,to) (project hist to x in given region)"<<endl;
	cout<<"*.)  proy(Mbr+-Bins=-1) (same thing here for projection to Y)"<<endl;
	cout<<"     proy() (interactive projection to the y-axis)"<<endl;
	cout<<"     proy(from,to) (project current histogram to y in given region)"<<endl;
	cout<<"     proy(hist,from,to) (project hist to y in given region)"<<endl;

	cout<<endl;	cout<<endl;
	cout<<"special:"<<endl;
	cout<<endl;
	cout<<"*.)  normalize_y() (for TH2D. Normalizes each column to 1.)"<<endl;
	cout<<"*.)  normalize_integral_y() (for TH2D: Normalizes the integral of each column to 1)"<<endl;
	cout<<"                            (for TH1D: Normalizes the integral to 1)"<<endl;
	cout<<"*.)  normalize(y,ybin) (special. Ask Achim. Divide each cell in each column by the content of biny of this column.)"<<endl;
	cout<<"*.)  get1DHistFromPad() (returns the 1D hist in the current pad)"<<endl;
	cout<<"*.)  get2DHistFromPad() (returns the 2D hist in the current pad)"<<endl;
	cout<<"*.)  test1d()      (creates a 1d histo for testing)"<<endl;
	cout<<"*.)  test2d()      (creates a 2d histo for testing)"<<endl;
	cout<<"*.)  test3d()      (creates a 3d histo for testing)"<<endl;
	cout<<"*.)  drawsum(char *var, char * layer) (to correct timesums)"<<endl;


	cout<<endl;	cout<<endl;

	cout<<"NOT TESTED:"<<endl;
	cout<<endl;
	cout<<"*.)  pro3d(\"Plane\",from,to) (projects a 3d histogram onto the chosen plane)"<<endl;

	cout<<"*.)  polartill(hist)"<<endl;
	cout<<"        (Draws hist as a polarplot in good old PAW style. Will detect automatically"<<endl;
	cout<<"         if hist is in deg or rad. Ranges are -180:180, 0:360, -1:1 "<<endl;
	cout<<"         or -1:3 (for full theta)"<<endl;
	cout<<"         Will draw currently plotted histogram if no histogram is specified.)"<<endl;
	cout<<"*.)  polarline(hist, overlay true/false)"<<endl;
	cout<<"         (Draws hist as a polarplot with a line connecting the data points. Will"<<endl;
	cout<<"         detect automatically if hist is in deg or rad. Ranges are -180:180,"<<endl;
	cout<<"         0:360, -1:1 or -1:3 (for full theta))"<<endl;
	cout<<"*.)  polar(ErrorBars=true) (use this when the histogram is already in pad)"<<endl;
	cout<<"	       (Detects ranges automaticly. Will plot fit, when histogram was "<<endl;
	cout<<"	       fitted before. When giving range in cos(theta), then it will mirror"<<endl;
	cout<<"        the distribution to make a full circle.)"<<endl;
	cout<<"*.)  polar(histname) (use to polar plot histname)"<<endl;
	cout<<"	       (Detects ranges automaticly. Will plot fit, when histogram was "<<endl;
	cout<<"	       fitted before. When giving range in cos(theta), then it will mirror"<<endl;
	cout<<"        the distribution to make a full circle.)"<<endl;

	cout<<"*.)  pipico(Mass_amu, charge_au, EField1_Vpcm, EField2_Vpcm, "<<endl;
	cout<<"             LenReg1_mm, LenReg2_mm, MaxEnergy_ev)"<<endl; 
	cout<<"             (this will draw a pipico line, for two equal particles)"<<endl;
	cout<<"*.)  pipico2(M1 amu, M2 amu, charge1 au, charge2 au, EField V/cm, AccReg mm)"<<endl;;
	cout<<"            (Draw PIPICO-lines to histogram currently displayed)"<<endl;;
	cout<<"*.)  add_root_files(\"file1.root\",f1,\"file2.root\",f2,\"new_file.root\") (adds 2 root files with weights)"<<endl;

	cout<<endl;
}





















////////////////////////////////////////////////////////////////////////////////////////
//---------------------create Canvas---------------------------------------------------
TCanvas* Canv(int hor=1, int ver=1)
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
////////////////////////////////////////////////////////////////////////////////////////













////////////////////////////////////////////////////////////////////////////////////////
bool AreYouofType(TObject * obj, const char * name)
////////////////////////////////////////////////////////////////////////////////////////
{
	const char * aaa = obj->ClassName();
	if (!strcmp(aaa,name)) return true;
	return false;
}






////////////////////////////////////////////////////////////////////////////////////////
TH1* get1DHistFromPad()
{
	TIter next(gPad->GetListOfPrimitives());
	TObject *obj;
	TH1 *hist = 0;
	//find histogram in current pad//
	while((obj = next()))
	{
		if( obj->InheritsFrom("TH1") && (!obj->InheritsFrom("TH2")   )) 
		{
			hist = (TH1*)obj;
			break;
		}
	}

	return hist;
}


TH2* get2DHistFromPad()
{
	TIter next(gPad->GetListOfPrimitives());
	TObject *obj;
	TH2 *hist = 0;
	//find histogram in current pad//
	while((obj = next()))
	{
		if( obj->InheritsFrom("TH2") ) 
		{
			hist = (TH2*)obj;
			break;
		}
	}

	return hist;
}
////////////////////////////////////////////////////////////////////////////////////////
















////////////////////////////////////////////////////////////////////////////////////////
//---------------------print all open Canvase---------------------------------------------------
void printCanv()
{
	//go through all open canvase//
	TIter next(gROOT->GetListOfCanvases());
	TCanvas * can;
	char name[290];
	name[0] = 0;
	while( (can = (TCanvas*) next()) )
	{
		//go through all pads in canvase//
		sprintf(name,"%s.ps",can->GetName());
		can->Print(name);
	}
	return;
}
////////////////////////////////////////////////////////////////////////////////////////







//////////////////////////////////////////////////////////////////////////////////////////////////////////////
void centerTitleBox(TPad* pad=0)
{
	if (!pad)
		pad = (TPad*)gPad;

	TPaveText * pt = (TPaveText *)pad->GetListOfPrimitives()->FindObject("title");
	if (!pt) return;
	double sizeX = pt->GetX2NDC() - pt->GetX1NDC();
	double y1 = pt->GetY1NDC();
	double y2 = pt->GetY2NDC();

	pt->SetX1NDC(0.5 - 0.5*sizeX);
	pt->SetX2NDC(0.5 + 0.5*sizeX);
	pt->SetY1NDC(y1);
	pt->SetY2NDC(y2);

	pad->Modified();
	pad->Update();
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////














////////////////////////////////polar stuff////////////////////////////////////////////////////////
void preparePad(double rmax, const char * title, TPad * pad =0)
{
	//prepare the pad, if no pad is given create a canvas//
	if(!pad)
	{
		TCanvas * MyPolarCanvas = Canv(1,1);
		MyPolarCanvas->cd();
		pad = (TPad*)gPad;
	}
	pad->cd();
	pad->SetBorderSize(2);
	//pad->SetFrameLineColor(19);
	pad->SetFrameLineColor(0);
	pad->SetFrameBorderMode(0);
	pad->SetLeftMargin(0.2);
	pad->SetBottomMargin(0.2);

	TH1 *hframe = new TH1F("hframe",title,1000,-1,1);
	hframe->SetMinimum(-1);
	hframe->SetMaximum(1);
	hframe->SetDirectory(0);
	hframe->SetStats(0);
	hframe->GetXaxis()->SetAxisColor(0);
	hframe->GetXaxis()->SetLabelOffset(999);
	hframe->GetXaxis()->SetTickLength(0);
	hframe->GetYaxis()->SetAxisColor(0);
	hframe->GetYaxis()->SetLabelOffset(999);
	hframe->GetYaxis()->SetTickLength(0);
	hframe->Draw("a");

	//Draw the axis//
	double rmin = 0;
	TGaxis *axis = new TGaxis(-1.25,0.,-1.25,1,rmin,rmax,510,"");
	axis->SetLabelSize(.03);
	axis->Draw();

	//compute where the ticks in the axis are using the same function the axis is using//
	double binLow,binHigh,binWidth;
	int nbins;
	THLimitsFinder::Optimize(rmin,rmax,10,binLow,binHigh,nbins,binWidth,"");

	double conv2NDC = 1./rmax;

	//Draw the polar circles//
	TEllipse el;
	el.SetFillStyle(0);
	el.SetLineStyle(3);
	el.SetFillColor(0);
	Double_t r = (rmin+binWidth)*conv2NDC;
	Double_t dr = binWidth*conv2NDC;
	for (Int_t i=1; i<=nbins; i++) 
	{
		el.DrawEllipse(0.,0.,r,r,0.,360,0);
		r += dr;
	}

	//Draw the radial lines and labels//
	TLine l;
	TLatex t;
	char s[24];
	Double_t theta = 0;
	Double_t dtheta = TMath::Pi()/6.;
	t.SetTextSize(.03);
	l.SetLineStyle(3);
	for (int i=1; i<=12; i++)
	{
		l.DrawLine(0.,0.,TMath::Cos(theta),TMath::Sin(theta));
		sprintf(s,"%g^{#circ}",theta*180./TMath::Pi());
		t.SetTextAlign(12);
		if (i>4 && i<10) t.SetTextAlign(32);
		if (i==4) t.SetTextAlign(21);
		if (i==10) t.SetTextAlign(23);
		t.DrawLatex(1.03*TMath::Cos(theta),1.03*TMath::Sin(theta),s);
		theta += dtheta;
	}
	return;
}




void polar(TH1 * hist1, bool errorbar=true, const char * tit= "", TPad * pad = 0)
{
	//check wether the histo has the right ranges and is in degrees or in cos--//
	bool degrees = false;
	if( ((hist1->GetXaxis()->GetXmin() ==-180) && (hist1->GetXaxis()->GetXmax() == 180)) ||
		((hist1->GetXaxis()->GetXmin() ==   0) && (hist1->GetXaxis()->GetXmax() == 360))
	  )
		degrees = true;
	else if ((hist1->GetXaxis()->GetXmin() ==  -1) && (hist1->GetXaxis()->GetXmax() ==   1))
		degrees = false;
	else
	{
		cout << "The Histogram has the wrong Range:"<<endl;
		cout << "   "<< hist1->GetXaxis()->GetXmin() << " ... "<< hist1->GetXaxis()->GetXmax()<<endl;
		cout << "This Macro only supports Histograms in the following Ranges:"<<endl;
		cout << "   -180 ... 180"<<endl;
		cout << "or    0 ... 360"<<endl;
		cout << "or   -1 ... 1"<<endl;

		return;
	}

	double pi = 3.14159265;

	//stuff that we need to draw errorlines and markers//
	TLine * l = new TLine();
	TGraph * gr = new TGraph();
	TMarker * m = new TMarker();
	m->SetMarkerStyle(20);
	m->SetMarkerSize(1);
	gr->SetMarkerStyle(1);

	//find a function that we might want to draw later//
	TIter next(hist1->GetListOfFunctions());
	TF1 * func=0;
	while((func = (TF1*) next()))		//find first fit function
		if (func->InheritsFrom("TF1"))
			break;

	//find Maximum of fit or histogram whichever is bigger//
	double maximumhist = hist1->GetMaximum();
	double maximumfit = (func)? func->GetMaximum() : 0;
	double maximum = (maximumhist > maximumfit)? maximumhist : maximumfit;

	//write the 360 degree labels and lines//
	preparePad(maximum, tit, pad);

	//plot the dots and the errorbars if wanted//
	double conv2NDC = 1./maximum;
	for (int i=1;i<=hist1->GetNbinsX();i++)
	{	
		//convert polar koordinates to kartesian koordinates//
		double cos_x = (degrees)? cos(hist1->GetBinCenter(i)*pi/180.) : hist1->GetBinCenter(i);
		double sin_x = (degrees)? sin(hist1->GetBinCenter(i)*pi/180.): sqrt(1.- (hist1->GetBinCenter(i)*hist1->GetBinCenter(i)));
		double y = hist1->GetBinContent(i);
		double error = hist1->GetBinError(i);

		double mx = cos_x * y * conv2NDC;
		double my = sin_x * y * conv2NDC;

		double ex1 = mx - error * cos_x * conv2NDC;
		double ex2 = mx + error * cos_x * conv2NDC;
		double ey1 = my - error * sin_x * conv2NDC;
		double ey2 = my + error * sin_x * conv2NDC;
		
		//draw the markers and the errorbars//
		m->DrawMarker(mx,my);
		if (errorbar)
			l->DrawLine(ex1,ey1,ex2,ey2);

		//if hist is in cos(theta) then mirror the distribution//
		if(!degrees)
		{
			m->DrawMarker(mx,-my);
			if (errorbar)
				l->DrawLine(ex1,-ey1,ex2,-ey2);
		}
	}
	

	//--if we found a fit before function draw it--//
	if (func)
	{
		const int nPoints = 361;
		gr->Set(nPoints);
		for (int i=0;i<nPoints;++i)
		{
			double x = i;

			double cos_x = TMath::Cos(x*TMath::DegToRad());
			double sin_x = TMath::Sin(x*TMath::DegToRad());

			double y = (degrees)? func->Eval(x) : func->Eval(cos_x);

			double mx = cos_x * y * conv2NDC;
			double my = sin_x * y * conv2NDC;

			gr->SetPoint(i,mx,my);
		}
		gr->SetLineColor(func->GetLineColor());
		gr->SetLineStyle(func->GetLineStyle());
		gr->SetLineWidth(func->GetLineWidth());
		gr->SetFillColor(func->GetFillColor());
		gr->SetFillStyle(func->GetFillStyle());
		gr->SetMarkerColor(func->GetMarkerColor());
		gr->SetMarkerStyle(func->GetMarkerStyle());
		gr->SetMarkerSize(func->GetMarkerSize());

		gr->Draw("l");
	}
	return;
}



void polar(bool errorbar=true, const char * tit ="", TPad * pad = 0)
{
    TIter next(gPad->GetListOfPrimitives());
    TObject *obj;
	TH1 *hist1;
	//find histogram in current pad//
	while((obj = next()))
	{
		if( obj->InheritsFrom("TH1") ) 
		{
			hist1 = (TH1*)obj;
			break;
		}
	}
	//check if histogram is a 1D Histogram//
	if (hist1->InheritsFrom("TH2"))
	{
		cout << "This histogram is a 2D Histogram, stopping here"<<endl;
		return;
	}
	polar(hist1,errorbar,tit,pad);
	return;
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////
void polartill(TH1D * hist1)
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
		cout << "The histogram has the wrong range:"<<endl;
		cout << "   "<< hist1->GetXaxis()->GetXmin() << " ... "<< hist1->GetXaxis()->GetXmax()<<endl;
		cout << "This macro only supports histograms in the following ranges:"<<endl;
		cout << "   -180 ... 180"<<endl;
		cout << "or    0 ... 360"<<endl;
		cout << "or   -1 ... 1"<<endl;
		cout << "or   -1 ... 3 (for full cos(theta) plot)"<<endl;

		return;
	}

	gPad->Range(-hist1->GetMaximum()*1.5,-hist1->GetMaximum()*1.5,hist1->GetMaximum()*1.5,hist1->GetMaximum()*1.5);
	gPad->Clear();


	// box
	TLine *l = new TLine(-hist1->GetMaximum()*1.2,-hist1->GetMaximum()*1.2,-hist1->GetMaximum()*1.2,hist1->GetMaximum()*1.2);
	l->Draw();
	l = new TLine(hist1->GetMaximum()*1.2,-hist1->GetMaximum()*1.2,hist1->GetMaximum()*1.2,hist1->GetMaximum()*1.2);
	l->Draw();
	l = new TLine(-hist1->GetMaximum()*1.2,-hist1->GetMaximum()*1.2,hist1->GetMaximum()*1.2,-hist1->GetMaximum()*1.2);
	l->Draw();
	l = new TLine(-hist1->GetMaximum()*1.2,hist1->GetMaximum()*1.2,hist1->GetMaximum()*1.2,hist1->GetMaximum()*1.2);
	l->Draw();
	// cross
	l = new TLine(-hist1->GetMaximum()*1.2,0,hist1->GetMaximum()*1.2,0);
	l->Draw();
	l = new TLine(0,-hist1->GetMaximum()*1.2,0,hist1->GetMaximum()*1.2);
	l->Draw();

	//tics
	double pi=3.14159265;

	for(int i=0;i<12;i++) {
		double phi=double(i)*2.*pi/12.;
		
		if((phi >= pi*7./4.)||(phi < pi/4.)) {  
			double x1=0.9 * hist1->GetMaximum()*1.2;
			double y1=0.9 * tan(phi) * hist1->GetMaximum()*1.2;    
			double x2=1. * hist1->GetMaximum()*1.2;
			double y2=tan(phi) * hist1->GetMaximum()*1.2;
			TLine *l = new TLine(x1,y1,x2,y2);
			l->Draw();

		}
		if((phi >= pi/4.)&&(phi < pi*3./4.)) {  
			double x1=0.9/tan(phi) * hist1->GetMaximum()*1.2;
			double y1=0.9 * hist1->GetMaximum()*1.2;    
			double x2=1./tan(phi) * hist1->GetMaximum()*1.2;
			double y2=1. * hist1->GetMaximum()*1.2;
			TLine *l = new TLine(x1,y1,x2,y2);
			l->Draw();
		}			
		if((phi >= pi*3./4.) && (phi < pi*5./4.)) {  
			double x1=-0.9 * hist1->GetMaximum()*1.2;
			double y1=-0.9*tan(phi) * hist1->GetMaximum()*1.2;    
			double x2=-1. * hist1->GetMaximum()*1.2;
			double y2=-tan(phi) * hist1->GetMaximum()*1.2;
			TLine *l = new TLine(x1,y1,x2,y2);
			l->Draw();
		}
		if((phi >= pi*5./4.)&&(phi < pi*7./4.)) {
			double x1=-0.9/tan(phi) * hist1->GetMaximum()*1.2;
			double y1=-0.9 * hist1->GetMaximum()*1.2;    
			double x2=-1./tan(phi) * hist1->GetMaximum()*1.2;
			double y2=-1. * hist1->GetMaximum()*1.2;
			TLine *l = new TLine(x1,y1,x2,y2);
			l->Draw();
		}
	}

	for (int i=1;i<=hist1->GetNbinsX();i++)
	{	
		double mx1=0;
		double my1=0;
		double ex1=0;
		double ex2=0;
		double ey1=0;
		double ey2=0;
		

		if(   hist1->GetXaxis()->GetXmax()==180 && hist1->GetXaxis()->GetXmin()==-180 //for when things are in degrees
		   || hist1->GetXaxis()->GetXmax()==360 && hist1->GetXaxis()->GetXmin()==0 )
		{
			mx1 = cos(hist1->GetBinCenter(i)*pi/180.)*hist1->GetBinContent(i);
			my1 = sin(hist1->GetBinCenter(i)*pi/180.)*hist1->GetBinContent(i);
			
			ex1=mx1 - 1.*hist1->GetBinError(i)*cos(hist1->GetBinCenter(i)*pi/180.);
			ex2=mx1 + 1.*hist1->GetBinError(i)*cos(hist1->GetBinCenter(i)*pi/180.);
			ey1=my1 - 1.*hist1->GetBinError(i)*sin(hist1->GetBinCenter(i)*pi/180.);
			ey2=my1 + 1.*hist1->GetBinError(i)*sin(hist1->GetBinCenter(i)*pi/180.);
		}

		if(hist1->GetXaxis()->GetXmin()==-1 ) //for when things are in cos
		{
			if(hist1->GetBinCenter(i)<=1) {
				mx1 = hist1->GetBinCenter(i)*hist1->GetBinContent(i);
				my1 = sqrt(1.- (hist1->GetBinCenter(i)*hist1->GetBinCenter(i)))*hist1->GetBinContent(i);

				ex1=hist1->GetBinCenter(i)*hist1->GetBinContent(i) - hist1->GetBinError(i)*hist1->GetBinCenter(i);
				ex2=hist1->GetBinCenter(i)*hist1->GetBinContent(i) + hist1->GetBinError(i)*hist1->GetBinCenter(i);
				ey1=sqrt(1.- (hist1->GetBinCenter(i)*hist1->GetBinCenter(i)))*hist1->GetBinContent(i) - hist1->GetBinError(i)*sin(acos(hist1->GetBinCenter(i)));
				ey2=sqrt(1.- (hist1->GetBinCenter(i)*hist1->GetBinCenter(i)))*hist1->GetBinContent(i) + hist1->GetBinError(i)*sin(acos(hist1->GetBinCenter(i)));
			} else {
                double BinCenter = hist1->GetBinCenter(i);
                BinCenter = 2. - BinCenter;

                mx1 = BinCenter * hist1->GetBinContent(i);
                my1 = -sqrt(1.- (BinCenter*BinCenter))*hist1->GetBinContent(i);
			
                ex1=BinCenter*hist1->GetBinContent(i) - hist1->GetBinError(i)*BinCenter;
                ex2=BinCenter*hist1->GetBinContent(i) + hist1->GetBinError(i)*BinCenter;
                ey1=-sqrt(1.- (BinCenter*BinCenter))*hist1->GetBinContent(i) + hist1->GetBinError(i)*sin(acos(BinCenter));
                ey2=-sqrt(1.- (BinCenter*BinCenter))*hist1->GetBinContent(i) - hist1->GetBinError(i)*sin(acos(BinCenter));
			}
		}		

		TMarker *m = new TMarker(mx1,my1,8);
		m->Draw();
		TLine *l = new TLine(ex1,ey1,ex2,ey2);
		l->Draw();
	}

}



void polartill()
{
    TList   *list = gPad->GetListOfPrimitives();
    TObject *obj  = list->First();

	while(obj)
	{
		if( !strncmp("TH1",obj->ClassName(),3) ) 
		{
			TH1D *hist1 = (TH1D*)obj;
			polartill(hist1);
		}
		obj = list->After(obj);
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void polarline(TH1D * hist1,bool ovl=true)
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
		cout << "The histogram has the wrong range:"<<endl;
		cout << "   "<< hist1->GetXaxis()->GetXmin() << " ... "<< hist1->GetXaxis()->GetXmax()<<endl;
		cout << "This macro only supports histograms in the following ranges:"<<endl;
		cout << "   -180 ... 180"<<endl;
		cout << "or    0 ... 360"<<endl;
		cout << "or   -1 ... 1"<<endl;
		cout << "or   -1 ... 3 (for full cos(theta) plot)"<<endl;

		return;
	}

	double pi=3.14159265;

	gPad->Range(-hist1->GetMaximum()*1.5,-hist1->GetMaximum()*1.5,hist1->GetMaximum()*1.5,hist1->GetMaximum()*1.5);

	if(!ovl) {
		gPad->Clear();

		// box
		TLine *l = new TLine(-hist1->GetMaximum()*1.2,-hist1->GetMaximum()*1.2,-hist1->GetMaximum()*1.2,hist1->GetMaximum()*1.2);
		l->Draw();
		l = new TLine(hist1->GetMaximum()*1.2,-hist1->GetMaximum()*1.2,hist1->GetMaximum()*1.2,hist1->GetMaximum()*1.2);
		l->Draw();
		l = new TLine(-hist1->GetMaximum()*1.2,-hist1->GetMaximum()*1.2,hist1->GetMaximum()*1.2,-hist1->GetMaximum()*1.2);
		l->Draw();
		l = new TLine(-hist1->GetMaximum()*1.2,hist1->GetMaximum()*1.2,hist1->GetMaximum()*1.2,hist1->GetMaximum()*1.2);
		l->Draw();
		// cross
		l = new TLine(-hist1->GetMaximum()*1.2,0,hist1->GetMaximum()*1.2,0);
		l->Draw();
		l = new TLine(0,-hist1->GetMaximum()*1.2,0,hist1->GetMaximum()*1.2);
		l->Draw();

		//tics
		for(int i=0;i<12;i++) {
			double phi=double(i)*2.*pi/12.;
			
			if((phi >= pi*7./4.)||(phi < pi/4.)) {  
				double x1=0.9 * hist1->GetMaximum()*1.2;
				double y1=0.9 * tan(phi) * hist1->GetMaximum()*1.2;    
				double x2=1. * hist1->GetMaximum()*1.2;
				double y2=tan(phi) * hist1->GetMaximum()*1.2;
				TLine *l = new TLine(x1,y1,x2,y2);
				l->Draw();
			}
			if((phi >= pi/4.)&&(phi < pi*3./4.)) {  
				double x1=0.9/tan(phi) * hist1->GetMaximum()*1.2;
				double y1=0.9 * hist1->GetMaximum()*1.2;    
				double x2=1./tan(phi) * hist1->GetMaximum()*1.2;
				double y2=1. * hist1->GetMaximum()*1.2;
				TLine *l = new TLine(x1,y1,x2,y2);
				l->Draw();
			}			
			if((phi >= pi*3./4.) && (phi < pi*5./4.)) {  
				double x1=-0.9 * hist1->GetMaximum()*1.2;
				double y1=-0.9*tan(phi) * hist1->GetMaximum()*1.2;    
				double x2=-1. * hist1->GetMaximum()*1.2;
				double y2=-tan(phi) * hist1->GetMaximum()*1.2;
				TLine *l = new TLine(x1,y1,x2,y2);
				l->Draw();
			}
			if((phi >= pi*5./4.)&&(phi < pi*7./4.)) {
				double x1=-0.9/tan(phi) * hist1->GetMaximum()*1.2;
				double y1=-0.9 * hist1->GetMaximum()*1.2;    
				double x2=-1./tan(phi) * hist1->GetMaximum()*1.2;
				double y2=-1. * hist1->GetMaximum()*1.2;
				TLine *l = new TLine(x1,y1,x2,y2);
				l->Draw();
			}
		}
	}

	for (int i=1;i<=hist1->GetNbinsX();i++)
	{	
		double mx1=0;
		double my1=0;
		double mx2=0;
		double my2=0;

		if(   hist1->GetXaxis()->GetXmax()==180 && hist1->GetXaxis()->GetXmin()==-180 //for when things are in degrees
		   || hist1->GetXaxis()->GetXmax()==360 && hist1->GetXaxis()->GetXmin()==0 )
		{
			mx1 = cos(hist1->GetBinCenter(i)*pi/180.)*hist1->GetBinContent(i);
			my1 = sin(hist1->GetBinCenter(i)*pi/180.)*hist1->GetBinContent(i);
			if(i == hist1->GetNbinsX()) {
				mx2 = cos(hist1->GetBinCenter(1)*pi/180.)*hist1->GetBinContent(1);
				my2 = sin(hist1->GetBinCenter(1)*pi/180.)*hist1->GetBinContent(1);
			} else { 
				mx2 = cos(hist1->GetBinCenter(i+1)*pi/180.)*hist1->GetBinContent(i+1);
				my2 = sin(hist1->GetBinCenter(i+1)*pi/180.)*hist1->GetBinContent(i+1);
			}
		}

		if(   hist1->GetXaxis()->GetXmax()==1 && hist1->GetXaxis()->GetXmin()==-1 ) //for when things are in cos
		{
			mx1 = hist1->GetBinCenter(i)*hist1->GetBinContent(i);
			my1 = sqrt(1.- (hist1->GetBinCenter(i)*hist1->GetBinCenter(i)))*hist1->GetBinContent(i);
			if(i == hist1->GetNbinsX()) {
				mx2 = hist1->GetBinCenter(1)*hist1->GetBinContent(1);
				my2 = sqrt(1.- (hist1->GetBinCenter(1)*hist1->GetBinCenter(1)))*hist1->GetBinContent(1);
			} else { 
				mx2 = hist1->GetBinCenter(i+1)*hist1->GetBinContent(i+1);
				my2 = sqrt(1.- (hist1->GetBinCenter(i+1)*hist1->GetBinCenter(i+1)))*hist1->GetBinContent(i+1);
			}
		}

		TLine *l = new TLine(mx1,my1,mx2,my2);
		l->Draw();
	}
}












//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////





















////////////////////////////findmaximum/////////////////////////////////////////////////////////////
void findMaximum(TH1 * hist, double max = 0)
{
	double maximum=0;
	double maxx=0;
	double maxy=0;
	long k=0;

	for (int i=1;i<=hist->GetNbinsX();++i)
	{
		for (int j=1;j<=hist->GetNbinsY();++j)
		{
			bool inRange = (max)? ((hist->GetBinContent(i,j)>maximum) && (hist->GetBinContent(i,j)< max)) : (hist->GetBinContent(i,j)>maximum);
			if (inRange)
			{
				maximum = hist->GetBinContent(i,j);
				maxx=i;
				maxy=j;
			}
		}
	}

	for (int i=1;i<=hist->GetNbinsX();++i)
	{
		for (int j=1;j<=hist->GetNbinsY();++j)
		{
			if (hist->GetBinContent(i,j)==maximum)
			{
				cout << "maximum["<<++k<<"]("<<hist->GetBinContent(i,j)<<") is at ("<<i<<","<<j<<") ("<<hist->GetXaxis()->GetBinCenter(i)<<","<<hist->GetYaxis()->GetBinCenter(j)<<")"<<endl;
			}
		}
	}
	return;
}
/////////////////////////////////////////////////////////////////////////////////////////



















////////////////////////////findminimum/////////////////////////////////////////////////////////////
void findMinimum(TH1 * hist, double min = 0)
{
	double minimum = hist->GetBinContent(1,1);;
	double minx=1;
	double miny=1;
	long k=0;

	for (int i=1;i<=hist->GetNbinsX();++i)
	{
		for (int j=1;j<=hist->GetNbinsY();++j)
		{
			bool inRange = (min)? ((hist->GetBinContent(i,j) < minimum) && (hist->GetBinContent(i,j) < min)) : (hist->GetBinContent(i,j) < minimum);
			if (inRange)
			{
				minimum = hist->GetBinContent(i,j);
				minx=i;
				miny=j;
			}
		}
	}

	for (int i=1;i<=hist->GetNbinsX();++i)
	{
		for (int j=1;j<=hist->GetNbinsY();++j)
		{
			if (hist->GetBinContent(i,j)==minimum)
			{
				cout << "minimum["<<++k<<"]("<<hist->GetBinContent(i,j)<<") is at ("<<i<<","<<j<<") ("<<hist->GetXaxis()->GetBinCenter(i)<<","<<hist->GetYaxis()->GetBinCenter(j)<<")"<<endl;
			}
		}
	}
	return;
}
/////////////////////////////////////////////////////////////////////////////////////////













///////////////////////////////print Histos////////////////////////////////////////
void printHistos(const char* inName, int format=3)
{
	char filename[250];
	sprintf(filename,"no histo");
	TString name = inName;

	TKey *key = 0;
	TObject * obj = 0;
	TCanvas *c0 = gPad->GetCanvas();

	TIter nextkey(gDirectory->GetListOfKeys());
	while (key = (TKey*)nextkey())
	{
		obj = key->ReadObj();
		if( obj->InheritsFrom("TH1")) {
			if( name.EqualTo(obj->GetName()) )
			{
				obj->Draw();
				c0->Update();
				switch (format)
				{
				case 1:	sprintf(filename,"%s.ps",obj->GetName());
						gPad->Print(filename,"ps"); 
						return;
				case 2: sprintf(filename,"%s.eps",obj->GetName());
						gPad->Print(filename,"eps"); 
						return;
				case 3:	sprintf(filename,"%s.gif",obj->GetName());
						gPad->Print(filename,"gif"); 
						return;
				case 4:	sprintf(filename,"%s.svg",obj->GetName());
						gPad->Print(filename,"svg"); 
						return;
				case 5: sprintf(filename,"%s.pdf",obj->GetName());
						gPad->Print(filename,"pdf"); 
						return;
				default:break;
				}
			}
		}
	}

	obj = (TObject*)gDirectory->FindObjectAny(inName);
	if (!obj) return;
	if( obj->InheritsFrom("TH1")) {
		obj->Draw();
		c0->Update();
		switch (format)
		{
		case 1:	sprintf(filename,"%s.ps",obj->GetName());
				gPad->Print(filename,"ps"); 
				return;
		case 2: sprintf(filename,"%s.eps",obj->GetName());
				gPad->Print(filename,"eps"); 
				return;
		case 3:	sprintf(filename,"%s.gif",obj->GetName());
				gPad->Print(filename,"gif"); 
				return;
		case 4:	sprintf(filename,"%s.svg",obj->GetName());
				gPad->Print(filename,"svg"); 
				return;
		case 5: sprintf(filename,"%s.pdf",obj->GetName());
				gPad->Print(filename,"pdf"); 
				return;
		default:break;
		}
	}

	return;
}
//////////////////////////////////////////////////////////////////////















///////////////////////////////////add two 2d histos/////////////////
TH2D* addHistos(TH2D * hi1, TH2D * hi2)
{
	if ((hi1->GetNbinsX() != hi2->GetNbinsX()) || (hi1->GetNbinsY() != hi2->GetNbinsY()) )
	{
		cout <<"Histos have to have the same binning"<<endl;
		return 0;
	}

	TString HistoName = hi1->GetName();
	HistoName += "_add";

	TString HistoTitle = hi2->GetName();
	HistoTitle += " added to ";
	HistoTitle += hi1->GetName();


	TH2D * sub = new TH2D(HistoName.Data(),HistoTitle.Data(),hi1->GetNbinsX(),hi1->GetXaxis()->GetXmin(),hi1->GetXaxis()->GetXmax(),hi1->GetNbinsY(),hi1->GetYaxis()->GetXmin(),hi1->GetYaxis()->GetXmax());
	sub->SetOption("colz");

	sub->Add(hi1,hi2,1,1);

	return sub;
}
/////////////////////////////////////////////////////////////////////////////////








///////////////////////////////////add two 1d histos/////////////////
TH1D* addHistos(TH1 * hi1, TH1 * hi2)
{
	if (!hi1) return;
	if (!hi2) return;
	if (!hi1->InheritsFrom("TH1")) return;
	if (!hi2->InheritsFrom("TH1")) return;
	if (hi1->InheritsFrom("TH2")) return;
	if (hi2->InheritsFrom("TH2")) return;

	if (hi1->GetNbinsX() != hi2->GetNbinsX() )
	{
		cout <<"Histos have to have the same binning"<<endl;
		return 0;
	}

	TString HistoName = hi1->GetName();
	HistoName += "_add";

	TString HistoTitle = hi2->GetName();
	HistoTitle += " added to ";
	HistoTitle += hi1->GetName();


	TH1D * sub = new TH1D(HistoName.Data(),HistoTitle.Data(),hi1->GetNbinsX(),hi1->GetXaxis()->GetXmin(),hi1->GetXaxis()->GetXmax());

	sub->Add(hi1,hi2,1,1);

	return sub;
}
/////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////add two 1d histos/////////////////
TH1D* addHistos(TH1D * hi1, TH1D * hi2)
{
	if (!hi1) return;
	if (!hi2) return;
	if (!hi1->InheritsFrom("TH1")) return;
	if (!hi2->InheritsFrom("TH1")) return;
	if (hi1->InheritsFrom("TH2")) return;
	if (hi2->InheritsFrom("TH2")) return;

	if (hi1->GetNbinsX() != hi2->GetNbinsX() )
	{
		cout <<"Histos have to have the same binning"<<endl;
		return 0;
	}

	TString HistoName = hi1->GetName();
	HistoName += "_add";

	TString HistoTitle = hi2->GetName();
	HistoTitle += " added to ";
	HistoTitle += hi1->GetName();


	TH1D * sub = new TH1D(HistoName.Data(),HistoTitle.Data(),hi1->GetNbinsX(),hi1->GetXaxis()->GetXmin(),hi1->GetXaxis()->GetXmax());

	sub->Add(hi1,hi2,1,1);

	return sub;
}
/////////////////////////////////////////////////////////////////////////////////















///////////////////////////////////substract two 2d histos/////////////////
TH2D* subHistos(TH2D * hi1, TH2D * hi2)
{
	if (!hi1) return;
	if (!hi2) return;
	if (!hi1->InheritsFrom("TH1")) return;
	if (!hi2->InheritsFrom("TH1")) return;
	if (!hi1->InheritsFrom("TH2")) return;
	if (!hi2->InheritsFrom("TH2")) return;

	if ((hi1->GetNbinsX() != hi2->GetNbinsX()) || (hi1->GetNbinsY() != hi2->GetNbinsY()) )
	{
		cout <<"Histos have to have the same binning"<<endl;
		return 0;
	}

	TString HistoName = hi1->GetName();
	HistoName += "_sub";

	TString HistoTitle = hi2->GetName();
	HistoTitle += " substracted from ";
	HistoTitle += hi1->GetName();


	TH2D * sub = new TH2D(HistoName.Data(),HistoTitle.Data(),hi1->GetNbinsX(),hi1->GetXaxis()->GetXmin(),hi1->GetXaxis()->GetXmax(),hi1->GetNbinsY(),hi1->GetYaxis()->GetXmin(),hi1->GetYaxis()->GetXmax());
	sub->SetOption("colz");

	sub->Add(hi1,hi2,1,-1);

	return sub;
}
/////////////////////////////////////////////////////////////////////////////////





///////////////////////////////////substract two 2d histos/////////////////
TH2D* subHistos(TH2 * hi1, TH2 * hi2)
{
	if (!hi1) return;
	if (!hi2) return;
	if (!hi1->InheritsFrom("TH1")) return;
	if (!hi2->InheritsFrom("TH1")) return;
	if (!hi1->InheritsFrom("TH2")) return;
	if (!hi2->InheritsFrom("TH2")) return;

	if ((hi1->GetNbinsX() != hi2->GetNbinsX()) || (hi1->GetNbinsY() != hi2->GetNbinsY()) )
	{
		cout <<"Histos have to have the same binning"<<endl;
		return 0;
	}

	TString HistoName = hi1->GetName();
	HistoName += "_sub";

	TString HistoTitle = hi2->GetName();
	HistoTitle += " substracted from ";
	HistoTitle += hi1->GetName();


	TH2D * sub = new TH2D(HistoName.Data(),HistoTitle.Data(),hi1->GetNbinsX(),hi1->GetXaxis()->GetXmin(),hi1->GetXaxis()->GetXmax(),hi1->GetNbinsY(),hi1->GetYaxis()->GetXmin(),hi1->GetYaxis()->GetXmax());
	sub->SetOption("colz");

	sub->Add(hi1,hi2,1,-1);

	return sub;
}
/////////////////////////////////////////////////////////////////////////////////








///////////////////////////////////substract two 1d histos/////////////////
TH1D* subHistos(TH1D * hi1, TH1D * hi2)
{
	if (!hi1) return;
	if (!hi2) return;
	if (!hi1->InheritsFrom("TH1")) return;
	if (!hi2->InheritsFrom("TH1")) return;
	if (hi1->InheritsFrom("TH2")) return;
	if (hi2->InheritsFrom("TH2")) return;

	if (hi1->GetNbinsX() != hi2->GetNbinsX() )
	{
		cout <<"Histos have to have the same binning"<<endl;
		return 0;
	}

	TString HistoName = hi1->GetName();
	HistoName += "_sub";

	TString HistoTitle = hi2->GetName();
	HistoTitle += " substracted from ";
	HistoTitle += hi1->GetName();


	TH1D * sub = new TH1D(HistoName.Data(),HistoTitle.Data(),hi1->GetNbinsX(),hi1->GetXaxis()->GetXmin(),hi1->GetXaxis()->GetXmax());

	sub->Add(hi1,hi2,1,-1);

	return sub;
}
/////////////////////////////////////////////////////////////////////////////////






///////////////////////////////////substract two 1d histos/////////////////
TH1D* subHistos(TH1 * hi1, TH1 * hi2)
{
	if (!hi1) return;
	if (!hi2) return;
	if (!hi1->InheritsFrom("TH1")) return;
	if (!hi2->InheritsFrom("TH1")) return;
	if (hi1->InheritsFrom("TH2")) return;
	if (hi2->InheritsFrom("TH2")) return;

	if (hi1->GetNbinsX() != hi2->GetNbinsX() )
	{
		cout <<"Histos have to have the same binning"<<endl;
		return 0;
	}

	TString HistoName = hi1->GetName();
	HistoName += "_sub";

	TString HistoTitle = hi2->GetName();
	HistoTitle += " substracted from ";
	HistoTitle += hi1->GetName();


	TH1D * sub = new TH1D(HistoName.Data(),HistoTitle.Data(),hi1->GetNbinsX(),hi1->GetXaxis()->GetXmin(),hi1->GetXaxis()->GetXmax());

	sub->Add(hi1,hi2,1,-1);

	return sub;
}
/////////////////////////////////////////////////////////////////////////////////











//There is no THn::Add(double). Workaround: Make TF1 with constant and add this.
TF1* ConstantFunction(double TheConstant) {
	TF1* f = new TF1("Constant","[0]",-1E99,1E99);
	f->SetParameter(0,TheConstant);
	return f;
}







/////////////////////////Add something to histos//////////////////////////////////
void add(TH1* hist1, double addme_dbl)
{
	TF1* addme = ConstantFunction(addme_dbl);
	hist1->Add(addme);
	delete addme;
	return;
}

void add(TH2* hist2,double addme_dbl)
{
	add((TH1*)hist2,addme_dbl);
//	hist2->Add(addme);
	return;
}

void add(double addme_dbl)
{
	TF1* addme = ConstantFunction(addme_dbl);
    TList   *list = gPad->GetListOfPrimitives();
    TObject *obj  = list->First();

	while(obj)
	{
		if( !strncmp("TH1",obj->ClassName(),3) ) 
		{
			TH1 *hist1 = (TH1*)obj;
			hist1->Add(addme);
			hist1->Draw();
		}

		if( !strncmp("TH2",obj->ClassName(),3) ) 
		{
			TH2 *hist2 = (TH2*)obj;
			hist2->Add(addme);
			hist2->Draw("colz");
		}
		obj = list->After(obj);
	}
	delete addme;
	return;
}
///////////////////////////////////////////////////////////




/////////////////////////Multiply something to histos//////////////////////////////////
void mult(double m)
{
    TList   *list = gPad->GetListOfPrimitives();
    TObject *obj  = list->First();

	while(obj)
	{
		if( !strncmp("TH1",obj->ClassName(),3) ) 
		{
			TH1 *hist1 = (TH1*)obj;
			hist1->Scale(m);
			hist1->Draw();
		}

		if( !strncmp("TH2",obj->ClassName(),3) ) 
		{
			TH2 *hist2 = (TH2*)obj;
			hist2->Scale(m);
			hist2->Draw("colz");
		}
		obj = list->After(obj);
	}
	return;
}


void mult(TH1* hist1,double m)
{

	hist1->Scale(m);
	return;
}


void mult(TH2* hist2,double m)
{
	hist2->Scale(m);
	return;
}
///////////////////////////////////////////////////////////























/////////////////////ZOOM2D///////////////////////////////
class Zoom2D
{
RQ_OBJECT("Zoom2D")

private:
	Float_t x1;
	Float_t y1;
	Float_t x2;
	Float_t y2;
	Float_t fx1;
	Float_t fy1;
	Float_t rx2;
	Float_t ry2;
	Bool_t rect;

	void getRectangle(Float_t recx1, Float_t recx2, Float_t &recy1, Float_t &recy2);

public:
	Zoom2D(Bool_t r) {x1=0;y1=0;x2=0;y2=0;fx1=0;fy1=0;rx2=0;ry2=0;rect=r;}
	~Zoom2D() {}

	void ExecuteZoom2D(Int_t event, Int_t px, Int_t py, TObject *sel);
};
void Zoom2D::getRectangle(Float_t recx1, Float_t recy1, Float_t &recx2, Float_t &recy2)
{
	Float_t x = recx1-recx2;
	Float_t y = recy1-recy2;

	if ( ((x<0.)&&(y<0.)) || ((x>0.)&&(y>0.)) )
	{
		if (fabs(x)>fabs(y)) recy2=recy1-x;
		if (fabs(x)<fabs(y)) recx2=recx1-y;
	}

	if ( ((x<0.)&&(y>0.)) || ((x>0)&&(y<0.)) )
	{
		if (fabs(x)>fabs(y)) recy2=recy1+x;
		if (fabs(x)<fabs(y)) recx2=recx1+y;
	}
}
void Zoom2D::ExecuteZoom2D(Int_t event, Int_t px, Int_t py, TObject *sel)
{

   TCanvas * c = (TCanvas *) gTQSender;
   TPad * pad = (TPad *) c->GetSelectedPad();
   TH2 * hist2 = (TH2 *) sel;


   if ( event == kButton1Double)
   {
		//--quit--//
		c->Disconnect("ProcessedEvent(Int_t,Int_t,Int_t,TObject*)");
		delete this;
   }
   else if ( event == kButton1Down )
   {
		//--Get x1,y1--//
		fx1 = px;
		fy1 = py; 
	   	x1 = pad->AbsPixeltoX(fx1);
		y1 = pad->AbsPixeltoY(fy1);
   }
   else if ( event == kButton1Up )
   {
		//--Get Coordinates--//
		x2 = pad->AbsPixeltoX(px);
		y2 = pad->AbsPixeltoY(py);
		if (rect) getRectangle(x1,y1,x2,y2);
     
		//--now zoom in--//
		Float_t xmax = (x1 > x2)? x1 : x2;
		Float_t xmin = (x1 < x2)? x1 : x2;
		Float_t ymax = (y1 > y2)? y1 : y2;
		Float_t ymin = (y1 < y2)? y1 : y2;
		hist2->GetXaxis()->SetRangeUser(xmin,xmax);
		hist2->GetYaxis()->SetRangeUser(ymin,ymax);
		hist2->Draw();
		c->Modified();
		c->Update();
     
		//--end program here //
		c->Disconnect("ProcessedEvent(Int_t,Int_t,Int_t,TObject*)");
		delete this;
   }
   else if ( event == kButton1Motion )
   {
		Float_t ix2 = pad->AbsPixeltoX(px);
		Float_t iy2 = pad->AbsPixeltoY(py);
		if (rect) getRectangle(x1,y1,ix2,iy2);

		Float_t fx2 = pad->XtoAbsPixel(ix2);
		Float_t fy2 = pad->YtoAbsPixel(iy2);

		pad->GetCanvas()->FeedbackMode(kTRUE);

     	//--delete old box--//
     	if (rx2 && ry2)
			gVirtualX->DrawBox(fx1,fy1,rx2,ry2,(TVirtualX::EBoxMode)1);	//left line
		// draw new Box //
		gVirtualX->DrawBox(fx1,fy1,fx2,fy2,(TVirtualX::EBoxMode)1);	 	
		rx2=fx2;
		ry2=fy2;

       /********************box explanation******************
        *           top line                                *
        * #-------------------------------# tempx2,y1       *
        * | x1,y1                         |                 *
        * |                               |                 *
        * |                               |                 *
        * |                               | right line      *
        * | left line                     |                 *
        * |                               |                 *
        * |                               |                 *
        * | x1,tempy2                     |                 *
        * #-------------------------------# tempx2,tempy2   *
        *          bottom line                              *
        *****************************************************/
   }
   return;
}
void zoom2d(Bool_t rect=true)
{
	Zoom2D * z = new Zoom2D(rect);
	TCanvas *c1 = gPad->GetCanvas();
	c1->Connect("ProcessedEvent(Int_t,Int_t,Int_t,TObject*)", "Zoom2D",
                    z,"ExecuteZoom2D(Int_t,Int_t,Int_t,TObject*)");
	return;
}
////////////////////////////////////////////////////////////////////////////////////














///////////////////////Integral/////////////////////////////////////
class geilesIntegral
{
RQ_OBJECT("Integral")

private:
	Int_t dx1;
	Int_t dy1;
	Int_t dx2;
	Int_t dy2;

public:
	geilesIntegral() {dx1=0;dy1=0;dx2=0;dy1=0;}
	~geilesIntegral() {}

	void ExecuteIntegral(Int_t event, Int_t px, Int_t py, TObject *sel);
};

void geilesIntegral::ExecuteIntegral(Int_t event, Int_t px, Int_t py, TObject *sel)
{

	TCanvas * c = (TCanvas *) gTQSender;
	TPad * pad = (TPad *) c->GetSelectedPad();
	
	if ( event == kButton1Double)
	{
		//--quit--//
		c->Disconnect("ProcessedEvent(Int_t,Int_t,Int_t,TObject*)");
		delete this;
		return;
	}

	//--if hist is a 2d histo--//
	if(sel->InheritsFrom("TH2"))
	{
		TH2 * hist2 = (TH2 *) sel;
		if ( event == kButton1Down )
		{
			//--Get x1,y1--//
   			dx1 = px;
			dy1 = py;
		}
		else if ( event == kButton1Up )
		{
			//--Get Coordinates--//
			Double_t x1 = pad->AbsPixeltoX(dx1);
			Double_t y1 = pad->AbsPixeltoY(dy1);
			Double_t x2 = pad->AbsPixeltoX(px);
			Double_t y2 = pad->AbsPixeltoY(py);
	 
			//--find out which one is bigger an which on is smaller--//
			Double_t xmax = (x1 > x2)? x1 : x2;
			Double_t xmin = (x1 < x2)? x1 : x2;
			Double_t ymax = (y1 > y2)? y1 : y2;
			Double_t ymin = (y1 < y2)? y1 : y2;

			//--find the corosponding bins--//
			Int_t binx1 = hist2->GetXaxis()->FindBin(xmin);
			Int_t binx2 = hist2->GetXaxis()->FindBin(xmax);
			Int_t biny1 = hist2->GetYaxis()->FindBin(ymin);
			Int_t biny2 = hist2->GetYaxis()->FindBin(ymax);

			//--get Integral--//
			Double_t integral = hist2->Integral(binx1,binx2,biny1,biny2);
			hist2->Draw();
			c->Modified();
			c->Update();
			cout << "Integral: "<<integral<<endl;
		 
			//--end program here //
			c->Disconnect("ProcessedEvent(Int_t,Int_t,Int_t,TObject*)");
			delete this;
		}
		else if ( event == kButton1Motion )
		{
			pad->GetCanvas()->FeedbackMode(kTRUE);

 			//--delete old box--//
 			if (dx2 && dy2)
				 gVirtualX->DrawBox(dx1,dy1,dx2,dy2,(TVirtualX::EBoxMode)1);	//box
			// draw new Box //
			gVirtualX->DrawBox(dx1,dy1,px,py,(TVirtualX::EBoxMode)1);	 	
			dx2=px;
			dy2=py;
		}

	}
	//--if hist a 1d histo--//
	else
	{
		if ( event == kButton1Down )
		{
			// Get ymin,ymax// 
			Double_t uymin = pad->GetUymin();
			Double_t uymax = pad->GetUymax();
			dy1 = pad->YtoAbsPixel(uymin);
			dy2 = pad->YtoAbsPixel(uymax);

			dx1 = px;
			pad->SetEditable(kFALSE);
			
			pad->GetCanvas()->FeedbackMode(kTRUE);
			gVirtualX->DrawLine(px,dy1,px,dy2);
		}
		else if ( event == kButton1Up )
		{
			TH1* hist1;

			//--get histo--//
			TList * list = pad->GetListOfPrimitives();
			TObject * obj  = list->First();
			while(obj)
			{
				if (obj->InheritsFrom("TH1") && (!obj->InheritsFrom("TH2")))
				{
					hist1 = (TH1 *) obj;
					break;
				}
				obj = list->After(obj);
			}

			//--get coordinates--//
			Double_t x1 = pad->AbsPixeltoX(dx1);
			Double_t x2 = pad->AbsPixeltoX(px);
		    
   			//--get min and max--//     
			Double_t xmin = (x1 >= x2)? x2:x1;
			Double_t xmax = (x1 <= x2)? x2:x1;

			//--find the corosponding bins--//
			Int_t binx1 = hist1->GetXaxis()->FindBin(xmin);
			Int_t binx2 = hist1->GetXaxis()->FindBin(xmax);

			//--get Integral--//
			Double_t integral = hist1->Integral(binx1,binx2);
			c->Modified();
			c->Update();
			cout << "Integral: "<<integral<<endl;

  			// end program here //
 			pad->SetEditable(kTRUE);
			c->Disconnect("ProcessedEvent(Int_t,Int_t,Int_t,TObject*)");
			delete this;
		}
		else if ( event == kButton1Motion )
		{
			//--delete if drawn before--//
			pad->GetCanvas()->FeedbackMode(kTRUE);
			if (dx2)
				gVirtualX->DrawLine(dx2,dy1,dx2,dy2);
				
			gVirtualX->DrawLine(px,dy1,px,dy2);
			dx2=px;
		}
	}
	return;
}


//This seems very weird. Will not compile. 
//--Moritz

void Int()
{
	geilesIntegral* theintegral = new geilesIntegral();
	TCanvas *c1 = gPad->GetCanvas();
	c1->Connect("ProcessedEvent(Int_t,Int_t,Int_t,TObject*)", "geilesIntegral",theintegral,"ExecuteIntegral(Int_t,Int_t,Int_t,TObject*)");
	return;
}
void Int(double x1, double x2)
{
	TH1* hist1 = get1DHistFromPad();
	//--get min and max--//     
	Double_t xmin = (x1 >= x2)? x2:x1;
	Double_t xmax = (x1 <= x2)? x2:x1;

	//--find the corosponding bins--//
	Int_t binx1 = hist1->GetXaxis()->FindBin(xmin);
	Int_t binx2 = hist1->GetXaxis()->FindBin(xmax);

	//--get Integral--//
	Double_t integral = hist1->Integral(binx1,binx2);
	gPad->Modified();
	gPad->GetCanvas()->Update();
	cout << "Integral: "<<integral<<endl;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
















/////////////////////Distance///////////////////////////////
class Distance
{
RQ_OBJECT("Distance")

private:
	Float_t x1;
	Float_t y1;
	Float_t x2;
	Float_t y2;
	Float_t fx1;
	Float_t fy1;
	Float_t rx2;
	Float_t ry2;

	void getRectangle(Float_t recx1, Float_t recx2, Float_t &recy1, Float_t &recy2);

public:
	Distance() {x1=0;y1=0;x2=0;y2=0;fx1=0;fy1=0;rx2=0;ry2=0;}
	~Distance() {}

	void ExecuteDistance(Int_t event, Int_t px, Int_t py, TObject *sel);
};
void Distance::ExecuteDistance(Int_t event, Int_t px, Int_t py, TObject *sel)
{

   TCanvas * c = (TCanvas *) gTQSender;
   TPad * pad = (TPad *) c->GetSelectedPad();
   TH2 * hist2 = (TH2 *) sel;

   if ( event == kButton1Double)
   {
		//--quit--//
		cout << endl;
		c->Disconnect("ProcessedEvent(Int_t,Int_t,Int_t,TObject*)");
		delete this;
   }
   else if ( event == kButton1Down )
   {
		//--Get x1,y1--//
		fx1 = px;
		fy1 = py; 
	   	x1 = pad->AbsPixeltoX(fx1);
		y1 = pad->AbsPixeltoY(fy1);
		cout << endl;
   }
   else if ( event == kButton1Up )
   {
		//--Get Coordinates--//
		x2 = pad->AbsPixeltoX(px);
		y2 = pad->AbsPixeltoY(py);
		
		TLine * li = new TLine(x1,y1,x2,y2);
		li->Draw();
		c->Modified();
		c->Update();
 		cout << endl;
    
		//--end program here //
		c->Disconnect("ProcessedEvent(Int_t,Int_t,Int_t,TObject*)");
		delete this;
   }
   else if ( event == kButton1Motion )
   {
		Float_t ix2 = pad->AbsPixeltoX(px);
		Float_t iy2 = pad->AbsPixeltoY(py);

		Float_t fx2 = px;
		Float_t fy2 = py;

		pad->GetCanvas()->FeedbackMode(kTRUE);

     	//--delete old line--//
     	if (rx2 && ry2)
			 gVirtualX->DrawLine(fx1,fy1,rx2,ry2);
		// draw new line //
		gVirtualX->DrawLine(fx1,fy1,fx2,fy2);	 	
		rx2=fx2;
		ry2=fy2;

		cout << "\rDistance: "<< sqrt((x1-ix2)*(x1-ix2)+ (y1-iy2)*(y1-iy2));
   }
   return;
}
void dist()
{
	Distance * z = new Distance();
	TCanvas *c1 = gPad->GetCanvas();
	c1->Connect("ProcessedEvent(Int_t,Int_t,Int_t,TObject*)", "Distance",
                    z,"ExecuteDistance(Int_t,Int_t,Int_t,TObject*)");
	return;
}
////////////////////////////////////////////////////////////////////////////////////

















//////////////////////////////////test3d///////////////////////////////////////////
void test3d()
{
	TH3D * threed = new TH3D("hpxpypz","py vs px vs pz",200,-2,2,200,-2,2,200,0,40);
	threed->SetXTitle("x");
	threed->GetXaxis()->CenterTitle(true);
	threed->SetYTitle("y");
	threed->GetYaxis()->CenterTitle(true);
	threed->GetYaxis()->SetTitleOffset(1.5);
	threed->SetZTitle("z");
	threed->GetZaxis()->CenterTitle(true);
	threed->GetZaxis()->SetTitleOffset(1.5);
	threed->SetOption("colz");
	double px,py,pz;
	for (int i = 0; i < 5000; i++)
	{
		gRandom->Rannor(px,py);
		pz = (gRandom->Rndm())*40;
		threed->Fill(px,py,pz,1.);
	}

	
	threed->Draw();
}
///////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////test2d///////////////////////////////////////////
void test2d()
{
	TH2D * twod = new TH2D("hpxpy","py vs px",200,-4,4,200,-4,4);
	twod->SetOption("colz");
	Double_t px,py;
	for (Int_t i = 0; i < 500000; i++)
	{
		gRandom->Rannor(px,py);
		twod->Fill(px,py);
	}
	twod->Draw();
	return;
} 
/////////////////////////////////////////////////////////////////////////////
//////////////////////////////////test1d///////////////////////////////////////////
void test1d()
{
	TH1D * oned = new TH1D("hpx","px",30,-180,180);
	Double_t px,py;
	for (Int_t i = 0; i < 50000; i++)
	{
		gRandom->Rannor(px,py);
		oned->Fill(px*180./3.14);
	}
	oned->Draw();
	return;
}
/////////////////////////////////////////////////////////////////////////////
















/////////////////////Circle///////////////////////////////
TArc * circle(double cx, double cy, double r)
{
	//--Draw an circle that stayes--//
	TArc * ar = new TArc(cx,cy,r);
	ar->SetLineColor(kRed);
	ar->SetLineWidth(1);
	ar->SetFillStyle(0);
	ar->Draw();
	return ar;
}
class MyCircle
{
RQ_OBJECT("MyCircle")
public:
	MyCircle(double centerX, double centerY, bool findCenterFirst) 
		    {cx = centerX; cy = centerY;fcf = findCenterFirst;rr=0;
		     rpx=0;rpy=0;bx=0;by=0;}
	~MyCircle() {}

	void ExecuteCircle(Int_t event, Int_t px, Int_t py, TObject *sel);

private:
	void drawArc(double radius);

	double cx,cy,rr;
	bool fcf;
	int rpx,rpy,bx,by;
};
void MyCircle::drawArc(double radius)
{
	const int nbrp = 360;
	TPoint * tp = new TPoint[nbrp+1];
	double angle;

	for (int i=0; i<= nbrp;++i)
	{
		angle = 2.*TMath::Pi()*(double)i/(double)nbrp;
		tp[i].SetX(gPad->XtoAbsPixel((TMath::Cos(angle)*radius)+cx));
		tp[i].SetY(gPad->YtoAbsPixel((TMath::Sin(angle)*radius)+cy));
	}
	gVirtualX->DrawPolyLine(nbrp+1,tp);
	delete[] tp;
	return;
}
void MyCircle::ExecuteCircle(Int_t event, Int_t px, Int_t py, TObject *sel)
{
   TCanvas * c = (TCanvas *) gTQSender;
   TPad * pad = (TPad *) c->GetSelectedPad();

   //--if we need to find the center for the circle first, do it--//
   if (fcf)
   {
	   if ( event == kButton1Down)
	   {
		    //--remember x and y position--//
		    bx = px;
		    by = py;
	   }
	   else if ( event == kButton1Up)
	   {
		   fcf = false;
		   //--calculate the center--//
   		   double x1 = pad->AbsPixeltoX(px);
   		   double x2 = pad->AbsPixeltoX(bx);
   		   double xbmin = (x1>x2)?x2:x1;
   		   double xbmax = (x1<x2)?x2:x1;
   		   cx = xbmin + (0.5 * fabs(x1-x2));
   		   
		   double y1 = pad->AbsPixeltoY(py);
		   double y2 = pad->AbsPixeltoY(by);
   		   double ybmin = (y1>y2)?y2:y1;
   		   double ybmax = (y1<y2)?y2:y1;
   		   cy = ybmin +(0.5 * fabs(y1-y2));
	   }
	   else if ( (event == kMouseMotion)  || (event == kButton1Motion) )
	   {
	   		pad->GetCanvas()->FeedbackMode(kTRUE);
	   		//--get xmin,xmax,ymin,ymax--//
			double uxmin = pad->GetUxmin();
			double uxmax = pad->GetUxmax();
			int xmin = pad->XtoAbsPixel(uxmin);
			int xmax = pad->XtoAbsPixel(uxmax);

			double uymin = pad->GetUymin();
			double uymax = pad->GetUymax();
			int ymin = pad->YtoAbsPixel(uymin);
			int ymax = pad->YtoAbsPixel(uymax);
				   		
			//--delete old crosshair--//
			if(rpx && rpy)
			{
				gVirtualX->DrawLine(xmin,rpy,xmax,rpy);		//horizontal line
				gVirtualX->DrawLine(rpx,ymin,rpx,ymax);		//vertical line
			}
			//--draw crosshair--//
			gVirtualX->DrawLine(xmin,py,xmax,py);	//horizontal line
			gVirtualX->DrawLine(px,ymin,px,ymax);	//vertical line
			
			//--if we now one point of the box (mouse button is clicked)--//
			if(event == kButton1Motion)
			{ 
				//--first delete the old box--//
				gVirtualX->DrawBox(bx,by,rpx,rpy,(TVirtualX::EBoxMode)1);
				//--Draw Box--//
				gVirtualX->DrawBox(bx,by,px,py,(TVirtualX::EBoxMode)1);
			}
			
			//--remember values--//			
			rpy = py;
			rpx = px;
	   }
   }
   //--if we have the center, draw the circle around it--//
   else
   {
	   if ( event == kButton1Down)
	   {
		    //--draw permanent circle--//
			double x = pad->AbsPixeltoX(px)-cx;
			double y = pad->AbsPixeltoY(py)-cy;
			double r = TMath::Sqrt(x*x+y*y);
			circle(cx,cy,r);
			
			//--draw angle line--//
			TLine * l = new TLine(cx,cy,pad->AbsPixeltoX(px),pad->AbsPixeltoY(py));
			l->SetLineColor(kRed);
			l->SetLineWidth(2);
			l->Draw();

			double phi = TMath::ATan2(y,x)*180./3.14;
			phi = (phi < 0)?phi+360.:phi;
			
			//--quit--//
		    cout << "Center is: x=" << cx << " y="<<cy<<endl;
			cout << "Radius: "<<r<<endl;
			cout << "Phi: "<<phi<<endl;
			cout << "exiting circle"<<endl;
			c->Disconnect("ProcessedEvent(Int_t,Int_t,Int_t,TObject*)");
			delete this;
	   }
	   else if ( event == kMouseMotion )
	   {
	   		pad->GetCanvas()->FeedbackMode(kTRUE);
	   		//--get radius and phi--//
			double x = pad->AbsPixeltoX(px)-cx;
			double y = pad->AbsPixeltoY(py)-cy;
			double r = TMath::Sqrt(x*x+y*y);
			
			int pxl = pad->XtoAbsPixel(cx);
			int pyl = pad->YtoAbsPixel(cy);
			double phi = TMath::ATan2(y,x)*180./3.14;
			phi = (phi < 0)?phi+360.:phi;
			
			//--delete old circle--//
			if(rr) drawArc(rr);
			//--draw circle--//
		    drawArc(r);
		    
		    //--delete old angle line--//
			if (rr) gVirtualX->DrawLine(pxl,pyl,rpx,rpy);
		    //--draw angle line--//
			gVirtualX->DrawLine(pxl,pyl,px,py);
		    
		    //--remember values--//
		    rpx=px;
		    rpy=py;
			rr=r;
	   }
   }
   return;
}
void circle(double centerX, double centerY, bool findCenterFirst)
{
	MyCircle * circ = new MyCircle(centerX,centerY,findCenterFirst);
	TCanvas *c1 = gPad->GetCanvas();
	c1->Connect("ProcessedEvent(Int_t,Int_t,Int_t,TObject*)", "MyCircle",
                    circ,"ExecuteCircle(Int_t,Int_t,Int_t,TObject*)");
	return;
}
void circle()
{
	circle(0,0,false);
	return;
}
void circle(double cx, double cy)
{
	circle(cx,cy,false);
	return;
}
void circle(bool findCfirst)
{
	circle(0,0,findCfirst);
	return;
}
/////////////////////////////////////////////////////////////////////////////















///////////////////////projection for 3d histograms/////////////////////////////////////
TH1* pro3d(TH3 * hist, char * option, double fr, double to, char * title="", TPad * pad=0)
{
	TH1 * h;
	TAxis * ax;
	char tmp[64];
	TString opt = option; opt.ToLower();

	//first unzoom all other axes one can zoom later in the 2d histogram//
	hist->GetXaxis()->UnZoom();
	hist->GetYaxis()->UnZoom();
	hist->GetZaxis()->UnZoom();
	static int count;
	if ((opt.EqualTo("xy")) || (opt.EqualTo("yx")))
		ax = hist->GetZaxis();
	if ((opt.EqualTo("xz")) || (opt.EqualTo("zx")))
		ax = hist->GetYaxis();
	if ((opt.EqualTo("zy")) || (opt.EqualTo("yz")))
		ax = hist->GetXaxis();
	
	//set the range of the axis//
	double min = (fr > to)? to:fr;
	double max = (fr > to)? fr:to;
	ax->SetRangeUser(min,max);
	if ((ax->GetXmin() > fr) || (ax->GetXmax() < to))
	{
		cout << "The given Range is out of Limits for Axis \""<< ax->GetTitle()<< "\""<<endl;
		int fi = ax->GetFirst();
		int la = ax->GetLast();
		cout << "The range is set to "<< ax->GetBinLowEdge(fi)<< " ... "<<ax->GetBinUpEdge(la)<<endl;
	}

	//project the histogram//
	h = hist->Project3D(option);

	//unzoom the axis range//
	ax->UnZoom();
	
	//set the attributes to the projected histo//
	h->SetOption("colz");
	sprintf(tmp,"project_%s_%i",h->GetName(),count++);
	h->SetName(tmp);
	TString tit = title;
	if(tit == "") 
		title = (char*)hist->GetTitle();
	h->SetTitle(title);
	if (!pad)
	{
		TCanvas * c2 = Canv(1,1);
		c2->cd();
		pad = (TPad*)gPad;
	}
	pad->cd();
	h->Draw();

	return h;
}

TH1* pro3d(char * option, double fr, double to,char * title="", TPad * pad=0)
{
	TH3 * hist3=0;
	
	//find histogram in pad//
	TIter next(gPad->GetListOfPrimitives());
	TObject * obj;
	while((obj = next()))
	{
		if (obj->InheritsFrom("TH3"))
		{
			hist3 = (TH3*) obj;
			break;
		}
	}
	if (!hist3){cout <<"No 3D-Histogram in Pad"<<endl; return 0;}

	return (pro3d(hist3,option,fr,to,title,pad));
}
/////////////////////////////////////////////////////////////////////////














///////////////////////projection to X/////////////////////////////////////
TH1 * prox(TH2* hist2, double fr, double to, TPad *pad = 0, bool d=true)
{
	static int count;
	char title[80];

	int biny1 = hist2->GetYaxis()->FindBin(fr);
	int biny2 = hist2->GetYaxis()->FindBin(to);
	
	int binymin = (biny1 >= biny2)? biny2:biny1;
	int binymax = (biny1 <= biny2)? biny2:biny1;
	TH1D * pro = hist2->ProjectionX("",binymin,binymax);
	double ymin = hist2->GetYaxis()->GetBinLowEdge(binymin);
	double ymax = hist2->GetYaxis()->GetBinUpEdge(binymax);
	
	sprintf(title,"Pro to X from y=%f to %f",ymin,ymax);
	pro->SetTitle(title);
	sprintf(title,"projectx_%s%i",hist2->GetName(),count++);
	pro->SetName(title);
	if (d)
	{
		if (pad) pad->cd();
		if (!pad)
		{
			TCanvas * c2 = Canv(1,1);
			c2->cd();
		}
		pro->Draw();
	}
	return ((TH1*)pro);
}

TH1* prox(double fr, double to, TPad * pad = 0, bool d=true)
{
	TH2 * hist2=0;
	
	//find histogram in pad//
	TIter next(gPad->GetListOfPrimitives());
	TObject * obj;
	while((obj = next()))
	{
		if (obj->InheritsFrom("TH2"))
		{
			hist2 = (TH2*) obj;
			break;
		}
	}
	if (!hist2) {cout <<"No 2D-Histogram in Pad"<<endl; return 0;}

	return (prox(hist2,fr,to,pad,d));
}

class ProX
{
RQ_OBJECT("ProX")

private:
	Float_t xmin;
	Float_t xmax;
	Float_t remy;
	Float_t remy1;
	Float_t remy2;
	Float_t ymin;
	Float_t ymax;
	Float_t uxmin;
	Float_t uxmax;
	Float_t y;
	double y2;
	double y1;
	int binymin;
	int binymax;
	int py1;
	int py2;
	char title[80];
	int biny1;
	int biny2;
	int pmbins;
	TCanvas *c2;
	TH1D * pro;

public:
	ProX(int PMBins) {pmbins=PMBins;xmin=0;xmax=0;remy=0;remy1=0;remy2=0;biny1=0;biny2=0;c2=0;
					 ymin=0;ymax=0;uxmax=0;uxmin=0;y=0;binymin=0;binymax=0;py1=0;py2=0;pro=0;}
	~ProX() {}

	void ExecuteProx(Int_t event, Int_t px, Int_t py, TObject *sel);
};

void ProX::ExecuteProx(Int_t event, Int_t px, Int_t py, TObject *sel)
{
	//--if selected is not the 2d histo remove the lines & return--//
	if(!sel->InheritsFrom("TH2"))
	{
		if (remy)
			gVirtualX->DrawLine(xmin,remy,xmax,remy);
		if (remy1 && remy2)
		{
			gVirtualX->DrawLine(xmin,remy1,xmax,remy1);
			gVirtualX->DrawLine(xmin,remy2,xmax,remy2);
		}

		remy=0;
		remy1=0;
		remy2=0;
		return;
	}

	TCanvas * c = (TCanvas *) gTQSender;
	TPad * pad = (TPad *) c->GetSelectedPad();
	TH2 * hist2 = (TH2 *) sel;

	
	if (pmbins== -1)
	{
	   if ( event == kButton1Double)
	   {
			//--quit--//
			c->Disconnect("ProcessedEvent(Int_t,Int_t,Int_t,TObject*)");
			delete this;
	   }
	   else if ( event == kButton1Down )
	   {
			// Get xmin,xmax// 
			uxmin = pad->GetUxmin();
			uxmax = pad->GetUxmax();
			xmin = pad->XtoAbsPixel(uxmin);
			xmax = pad->XtoAbsPixel(uxmax);
			
			//--get y--//
			y1 = pad->AbsPixeltoY(py);
	
			pad->GetCanvas()->FeedbackMode(kTRUE);
			gVirtualX->DrawLine(xmin,py,xmax,py);
	   }
	   else if ( event == kButton1Up )
	   {	
		   	//--get y--//     
			y2 = pad->AbsPixeltoY(py);
			
			prox(hist2,y1,y2);

		   	// end program here //
			c->Disconnect("ProcessedEvent(Int_t,Int_t,Int_t,TObject*)");
			delete this;
	   }
	   else if ( event == kButton1Motion )
	   {
			//--delete if drawn before--//
			pad->GetCanvas()->FeedbackMode(kTRUE);
			if (remy)
				gVirtualX->DrawLine(xmin,remy,xmax,remy);
				
			gVirtualX->DrawLine(xmin,py,xmax,py);
			remy=py;
		}
	
	}
	else
	{
		if ( event == kMouseMotion )
		{
			//--check if we are inside the histo--//
			
			// Get xmin,xmax// 
			uxmin = pad->GetUxmin();
			uxmax = pad->GetUxmax();
			xmin = pad->XtoAbsPixel(uxmin);
			xmax = pad->XtoAbsPixel(uxmax);
			
			//--get biny--//
			y = pad->AbsPixeltoY(py);
			biny1 = hist2->GetYaxis()->FindBin(y);
	
			
			binymin = biny1 - pmbins;
	    		binymax = biny1 + pmbins;
		   	ymin = hist2->GetYaxis()->GetBinLowEdge(binymin);
		   	ymax = hist2->GetYaxis()->GetBinUpEdge(binymax);
			py1 = pad->YtoAbsPixel(ymin);
			py2 = pad->YtoAbsPixel(ymax);
	    	
	    	
		   	pro = hist2->ProjectionX("",binymin,binymax);
		   	
		   	if (!c2)
		   	{
			   	c2 = Canv(1,1);
				c2->cd();
				pro->Draw();
	   		}
	   		c2->Modified();
			c2->Update();
			
			pad->GetCanvas()->FeedbackMode(kTRUE);
			if (remy1 && remy2)
			{
				gVirtualX->DrawLine(xmin,remy1,xmax,remy1);
				gVirtualX->DrawLine(xmin,remy2,xmax,remy2);
			}
			gVirtualX->DrawLine(xmin,py1,xmax,py1);
			gVirtualX->DrawLine(xmin,py2,xmax,py2);
	
			remy1 = py1;
			remy2 = py2;
		}
		else if ( event == kButton1Down)
		{
		   	sprintf(title,"Pro to X from y=%f to %f",ymin,ymax);
			pro->SetTitle(title);
			static int count;
			sprintf(title,"projectx_%s%i",hist2->GetName(),count++);
			pro->SetName(title);
			c2->ToggleEventStatus();
			c2->Modified();
			c2->Update();

			//--quit--//
			c->Disconnect("ProcessedEvent(Int_t,Int_t,Int_t,TObject*)");
			delete this;
		}
	}
}

void prox(int pmbins=-1)
{
	ProX * z = new ProX(pmbins);
	TCanvas *c1 = gPad->GetCanvas();
	c1->Connect("ProcessedEvent(Int_t,Int_t,Int_t,TObject*)", "ProX",z,"ExecuteProx(Int_t,Int_t,Int_t,TObject*)");
	return;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




















////////////////////////////////projection to y/////////////////////////////////////////////////////
TH1* proy(TH2 * hist2, double fr, double to, TPad * pad = 0)
{
	static int count;
	char title[80];

	int binx1 = hist2->GetXaxis()->FindBin(fr);
	int binx2 = hist2->GetXaxis()->FindBin(to);
	
	int binxmin = (binx1 >= binx2)? binx2:binx1;
	int binxmax = (binx1 <= binx2)? binx2:binx1;
	double xmin = hist2->GetXaxis()->GetBinLowEdge(binxmin);
	double xmax = hist2->GetXaxis()->GetBinUpEdge(binxmax);
	
	TH1D * pro = hist2->ProjectionY("",binxmin,binxmax);
	
	sprintf(title,"Pro to Y from x=%f to %f",xmin,xmax);
	pro->SetTitle(title);
	sprintf(title,"projecty_%s%i",hist2->GetName(),count++);
	pro->SetName(title);
	if (pad) pad->cd();
	if (!pad)
	{
		TCanvas * c2 = Canv(1,1);
		c2->cd();
	}
	pro->Draw();

	return ((TH1*) pro);
}

TH1* proy(double fr, double to, TPad * pad = 0)
{
	TH2* hist2=0;
	
	//find histogram in pad//
	TIter next(gPad->GetListOfPrimitives());
	TObject *obj;
	while((obj = next()))
	{
		if (obj->InheritsFrom("TH2"))
		{
			hist2 = (TH2*) obj;
			break;
		}
	}
	if (!hist2){cout <<"No 2D-Histogram in Pad"<<endl; return 0;}

	return (proy(hist2,fr,to,pad));
}

class ProY
{
RQ_OBJECT("ProY")

private:
	Float_t xmin;
	Float_t xmax;
	Float_t ymin;
	Float_t ymax;
	Float_t remx;
	Float_t remx1;
	Float_t remx2;
	Float_t uymin;
	Float_t uymax;
	Float_t x;
	double x1;
	double x2;
	int binxmin;
	int binxmax;
	int px1;
	int px2;
	char title[80];
	int binx1;
	int binx2;
	int pmbins;
	TCanvas *c2;
	TH1D * pro;

public:
	ProY(int PMBins) {pmbins=PMBins;xmin=0;xmax=0;remx=0;remx1=0;remx2=0;binx1=0;binx2=0;c2=0;
					 ymin=0;ymax=0;uymax=0;uymin=0;x=0;binxmin=0;binxmax=0;px1=0;px2=0;pro=0;}
	~ProY() {}

	void ExecuteProy(Int_t event, Int_t px, Int_t py, TObject *sel);
};


void ProY::ExecuteProy(Int_t event, Int_t px, Int_t py, TObject *sel)
{
	//--if selected is not the 2d histo remove the lines & return--//
	if(!sel->InheritsFrom("TH2"))
	{
		if (remx)
			gVirtualX->DrawLine(remx,ymin,remx,ymax);
		if (remx1 && remx2)
		{
			gVirtualX->DrawLine(remx1,ymin,remx1,ymax);
			gVirtualX->DrawLine(remx2,ymin,remx2,ymax);
		}

		remx=0;
		remx1=0;
		remx2=0;
		return;
	}

	TCanvas * c = (TCanvas *) gTQSender;
	TPad * pad = (TPad *) c->GetSelectedPad();
	TH2 * hist2 = (TH2 *) sel;

	
	if (pmbins== -1)
	{
	   if ( event == kButton1Double)
	   {
			//--quit--//
			c->Disconnect("ProcessedEvent(Int_t,Int_t,Int_t,TObject*)");
			delete this;
	   }
	   else if ( event == kButton1Down )
	   {
			// Get xmin,xmax// 
			uymin = pad->GetUymin();
			uymax = pad->GetUymax();
			ymin = pad->YtoAbsPixel(uymin);
			ymax = pad->YtoAbsPixel(uymax);
			
			//--get biny--//
			x1 = pad->AbsPixeltoX(px);

			pad->GetCanvas()->FeedbackMode(kTRUE);
			gVirtualX->DrawLine(px,ymin,px,ymax);
	   }
	   else if ( event == kButton1Up )
	   {	
		   	//--get biny--//     
			x2 = pad->AbsPixeltoX(px);
			proy(hist2,x1,x2);
		   	
		   	// end program here //
			c->Disconnect("ProcessedEvent(Int_t,Int_t,Int_t,TObject*)");
			delete this;
	   }
	   else if ( event == kButton1Motion )
	   {
			//--delete if drawn before--//
			pad->GetCanvas()->FeedbackMode(kTRUE);
			if (remx)
				gVirtualX->DrawLine(remx,ymin,remx,ymax);
				
			gVirtualX->DrawLine(px,ymin,px,ymax);
			remx=px;
		}
	
	}
	else
	{
		if ( event == kMouseMotion )
		{
			// Get xmin,xmax// 
			uymin = pad->GetUymin();
			uymax = pad->GetUymax();
			ymin = pad->YtoAbsPixel(uymin);
			ymax = pad->YtoAbsPixel(uymax);
			
			//--get biny--//
			x = pad->AbsPixeltoX(px);
			binx1 = hist2->GetYaxis()->FindBin(x);
	
			
			binxmin = binx1 - pmbins;
	    		binxmax = binx1 + pmbins;
		   	xmin = hist2->GetXaxis()->GetBinLowEdge(binxmin);
		   	xmax = hist2->GetXaxis()->GetBinUpEdge(binxmax);
			px1 = pad->XtoAbsPixel(xmin);
			px2 = pad->XtoAbsPixel(xmax);
	    	
	    	
		   	pro = hist2->ProjectionY("",binxmin,binxmax);
		   	
		   	if (!c2)
		   	{
			   	c2 = Canv(1,1);
				c2->cd();
				pro->Draw();
	   		}
	   		c2->Modified();
			c2->Update();
			
			pad->GetCanvas()->FeedbackMode(kTRUE);
			if (remx1 && remx2)
			{
				gVirtualX->DrawLine(remx1,ymin,remx1,ymax);
				gVirtualX->DrawLine(remx2,ymin,remx2,ymax);
			}
			gVirtualX->DrawLine(px1,ymin,px1,ymax);
			gVirtualX->DrawLine(px2,ymin,px2,ymax);
	
			remx1 = px1;
			remx2 = px2;
		}
		else if ( event == kButton1Down)
		{
		   	sprintf(title,"Pro to Y from x=%f to %f",xmin,xmax);
			pro->SetTitle(title);
			static int count;
			sprintf(title,"project_%s%i",hist2->GetName(),count++);
			pro->SetName(title);
			c2->Modified();
			c2->Update();

			//--quit--//
			c->Disconnect("ProcessedEvent(Int_t,Int_t,Int_t,TObject*)");
			delete this;
		}
	}
}

void proy(int pmbins=-1)
{
	ProY * z = new ProY(pmbins);
	TCanvas *c1 = gPad->GetCanvas();
	c1->Connect("ProcessedEvent(Int_t,Int_t,Int_t,TObject*)", "ProY",z,"ExecuteProy(Int_t,Int_t,Int_t,TObject*)");
	return;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////




















/////////////////////////////////////Drawsum///////////////////////////////////////////////////////////////
class DrawSum
{
RQ_OBJECT("DrawSum")

public:
	DrawSum(const char * lay, const char * v) {
		var = (char*)v;
		layer = (char*)lay;
		cntr=0;
		firsttime=true;
	}
	~DrawSum() {}

	void ExecuteDrawSum(Int_t event, Int_t px, Int_t py, TObject *sel);

private:
	long cntr;
	bool firsttime;
	char * layer;
	char * var;
};
void DrawSum::ExecuteDrawSum(Int_t event, Int_t px, Int_t py, TObject *sel)
{
	TCanvas * c = (TCanvas *) gTQSender;
	TPad * pad = (TPad *) c->GetSelectedPad();
	
	
	if ( event == kButton1Double)
	{
		//--quit--//
		double x1 = pad->AbsPixeltoX(px);
		double y1 = pad->AbsPixeltoY(py);

		cout <<var<<".SumCorrection_"<<layer<<".pos["<<cntr<<"] = 400;";
		cout << "\t"<<var<<".SumCorrection_"<<layer<<".sum["<<cntr++<<"] = "<<y1<<";"<<endl;
		cout <<var<<".SumCorrection_"<<layer<<".number_of_points = "<<cntr<<";"<<endl;

		c->Disconnect("ProcessedEvent(Int_t,Int_t,Int_t,TObject*)");
		delete this;
	}
	else if ( event == kButton1Down )
	{
		double x1 = pad->AbsPixeltoX(px);
		double y1 = pad->AbsPixeltoY(py);

		if (firsttime)
		{
			cout << endl;
			cout <<var<<".SumCorrection_"<<layer<<".pos["<<cntr<<"] = -400;";
			cout << "\t"<<var<<".SumCorrection_"<<layer<<".sum["<<cntr++<<"] = "<<y1<<";"<<endl;
			firsttime = false;
		}
		cout <<var<<".SumCorrection_"<<layer<<".pos["<<cntr<<"] = "<<x1<<";";
		cout << "\t"<<var<<".SumCorrection_"<<layer<<".sum["<<cntr++<<"] = "<<y1<<";"<<endl;
	}
	return;
}
void drawsum(const char * v, const char * layer)
{
	DrawSum * ds = new DrawSum(layer,v);
	TCanvas *c1 = gPad->GetCanvas();
	c1->Connect("ProcessedEvent(Int_t,Int_t,Int_t,TObject*)", "DrawSum",ds,"ExecuteDrawSum(Int_t,Int_t,Int_t,TObject*)");
	return;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////


















/////////////////////////////////////////////gaus()/////////////////////////////////////////////////////////////
TF1 * gaus(TH1D * hist, double fr, double to)
{
	double xmin = (fr >= to)? to:fr;
	double xmax = (fr <= to)? to:fr;
	
	hist->Fit("gaus","qw","",xmin,xmax);
	
	hist->GetFunction("gaus")->SetLineColor(kRed);
	gPad->Update();
	TPaveStats * s = (TPaveStats*) hist->GetFunction("stats");

	printf("\nx0=%lf",  hist->GetFunction("gaus")->GetParameter(1));
	printf("  fwhm=%lf",hist->GetFunction("gaus")->GetParameter(2)*2.35482);
	printf("  y0=%lf\n",hist->GetFunction("gaus")->GetParameter(0));

	if (s) {	
		s->SetX1NDC(0.62);
		s->SetY1NDC(0.675);
	}
	gPad->Modified();
	gPad->Update();
	return (hist->GetFunction("gaus"));
}

TF1 * gaus(double fr, double to)
{
	//--find hist first--//
	TH1D*hist1 = 0;
 	TIter next(gPad->GetListOfPrimitives());
	TObject* obj = 0;
 
 	while((obj = next()))
 	{
        	if (obj->InheritsFrom("TH1") && (!obj->InheritsFrom("TH2")) )
        	{
	        	hist1 = (TH1D *) obj;
		        break;
        	}
	}

    	//--if we did not find a hist haven't found anything--//
	if (!hist1) {printf("no 1D-hist found\n"); return 0;}

	return (gaus(hist1,fr,to));
}


class Gaus
{
RQ_OBJECT("Gaus")

private:
	Float_t xmin;
	Float_t xmax;
	Float_t ymin;
	Float_t ymax;
	Float_t remx;
	Float_t uymin;
	Float_t uymax;
	Float_t x1;
	Float_t x2;
	int binxmin;
	int binxmax;
	int binx1;
	int binx2;
	TH1 * hist1; 

public:
	Gaus() {xmin=0;xmax=0;remx=0;ymin=0;ymax=0;uymax=0;uymin=0;x1=0;x2=0;hist1=NULL;}
	~Gaus() {}

	void ExecuteGaus(Int_t event, Int_t px, Int_t py, TObject *sel);
};

void Gaus::ExecuteGaus(Int_t event, Int_t px, Int_t py, TObject *sel)
{
	TCanvas * c = (TCanvas *) gTQSender;
	TPad * pad = (TPad *) c->GetSelectedPad();

	if ( event == kButton1Double)
	{
		//--quit--//
		c->Disconnect("ProcessedEvent(Int_t,Int_t,Int_t,TObject*)");
		delete this;
	}
	else if ( event == kButton1Down )
	{
		// Get ymin,ymax// 
		uymin = pad->GetUymin();
		uymax = pad->GetUymax();
		ymin = pad->YtoAbsPixel(uymin);
		ymax = pad->YtoAbsPixel(uymax);

		x1 = pad->AbsPixeltoX(px);
		pad->SetEditable(kFALSE);
		
		pad->GetCanvas()->FeedbackMode(kTRUE);
		gVirtualX->DrawLine(px,ymin,px,ymax);
	}
	else if ( event == kButton1Up )
	{
	   	//--get biny--//     
		x2 = pad->AbsPixeltoX(px);
	    pad->SetEditable(kTRUE);
		    
		gaus(x1,x2);
	   	c->Update();
	
	   	// end program here //
		c->Disconnect("ProcessedEvent(Int_t,Int_t,Int_t,TObject*)");
		delete this;
	}
	else if ( event == kButton1Motion )
	{
		//--delete if drawn before--//
		pad->GetCanvas()->FeedbackMode(kTRUE);
		if (remx)
			gVirtualX->DrawLine(remx,ymin,remx,ymax);
			
		gVirtualX->DrawLine(px,ymin,px,ymax);
		remx=px;
	}
	return;
}

void gaus()
{
	Gaus * z = new Gaus();
	TCanvas *c1 = gPad->GetCanvas();
	c1->Connect("ProcessedEvent(Int_t,Int_t,Int_t,TObject*)", "Gaus",z,"ExecuteGaus(Int_t,Int_t,Int_t,TObject*)");
	return;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////



















/////////////////////////////////////////ColorScales/////////////////////////////////////////////////////////////////////////
void color(int colpal=1)
{ 
	//remove every color above 228 because otherwise this function cannot be called very often//
	TIter next(gROOT->GetListOfColors());
	TSeqCollection * coltab = gROOT->GetListOfColors();
	TColor * col;
	while (col = (TColor*) next())
	{
		if (col->GetNumber() > 999-230)
		{
			coltab->Remove(col);
			delete col;
		}
	}

	switch (colpal)
	{
	case 0: {		//grayscale
		UInt_t Number = 2;
		Double_t Red[2]   = { 0.93, 0.05};
		Double_t Green[2] = { 0.93, 0.05};
		Double_t Blue[2]  = { 0.93, 0.05};//{0.88, 0.15};
		Double_t Stops[2] = { 0.0, 1.0};

		//gStyle->CreateGradientColorTable(Number,Stops,Red,Green,Blue,230);	//doesn't work with root 5.16
		TColor::CreateGradientColorTable(Number,Stops,Red,Green,Blue,230);
		break;
	}
	case 1:	{	//standart cobold palette
		UInt_t Number = 7;
		Double_t Red[7]   = { 0.00, 0.00, 0.00, 0.00, 0.65, 0.99, 0.99};
		Double_t Green[7] = { 0.00, 0.00, 0.75, 0.99, 0.00, 0.00, 0.99};
		Double_t Blue[7]  = { 0.33, 0.99, 0.75, 0.00, 0.65, 0.00, 0.00};
		//Define the length of the (color)-interval between this points
		Double_t Stops[7] = { 0.00, 0.10, 0.30, 0.45, 0.70, 0.80, 1.00};

		//gStyle->CreateGradientColorTable(Number,Stops,Red,Green,Blue,230);	//doesn't work with root 5.16
		TColor::CreateGradientColorTable(Number,Stops,Red,Green,Blue,230);
		break;
	}
	case 2:	{	//tills palette
		UInt_t Number = 4;
		Double_t Red[4]   = { 0.50, 0.00, 0.99, 0.99};
		Double_t Green[4] = { 0.99, 0.00, 0.00, 0.99};
		Double_t Blue[4]  = { 0.99, 0.99, 0.00, 0.00};
		Double_t Stops[4] = { 0.00, 0.30, 0.70, 1.00};

		//gStyle->CreateGradientColorTable(Number,Stops,Red,Green,Blue,230);	//doesn't work with root 5.16
		TColor::CreateGradientColorTable(Number,Stops,Red,Green,Blue,230);
		break;
	}
	case 3:	{	//macieks palette
		UInt_t Number = 6;
		Double_t Red[6]   = { 0.55, 0.00, 0.00, 0.00, 0.99, 0.99};
		Double_t Green[6] = { 0.00, 0.00, 0.99, 0.99, 0.99, 0.00};
		Double_t Blue[6]  = { 0.99, 0.99, 0.99, 0.00, 0.00, 0.00};
		Double_t Stops[6] = { 0.00, 0.15, 0.35, 0.57, 0.77, 1.00};

		//gStyle->CreateGradientColorTable(Number,Stops,Red,Green,Blue,255);
		TColor::CreateGradientColorTable(Number,Stops,Red,Green,Blue,230);
		break;
	}
	case 4:	{	//tills std. palette
		UInt_t Number = 5;
		Double_t Red[5]   = { 0.00, 0.23, 0.99, 0.99, 0.99};
		Double_t Green[5] = { 0.00, 0.00, 0.00, 0.99, 0.99};
		Double_t Blue[5]  = { 0.30, 0.70, 0.00, 0.00, 0.99};
		Double_t Stops[5] = { 0.00, 0.10, 0.33, 0.70, 1.00};
		TColor::CreateGradientColorTable(Number,Stops,Red,Green,Blue,255);
		gStyle->SetFrameFillColor(229); 
		break;
	}

	default:break;
	}
}
/////////////////////////////////////////////////////////////////////















////////////////////////////setminmax///////////////////////////////////////
void setminmax(double min, double max)
{
	TIter next(gPad->GetListOfPrimitives());
	TObject *obj;
    while((obj = next()))
	{
		if( obj->InheritsFrom("TH2"))
		{
			TH2 *hist2 = (TH2*)obj;
			hist2->SetMinimum(min);
			hist2->SetMaximum(max);
			break;
		}
		if( obj->InheritsFrom("TH1"))
		{
			TH1 *hist1 = (TH1*)obj;
			hist1->SetMinimum(min);
			hist1->SetMaximum(max);
			break;
		}
    }
	gPad->Modified();
	gPad->Update();
}
///////////////////////////////////////////////////////////////////



















////////////////////////////unzoom///////////////////////////////////////
void unzoom()
{
	TIter next(gPad->GetListOfPrimitives());
	TObject *obj;
    while((obj = next()))
	{
		if( obj->InheritsFrom("TGraph"))
		{
			TGraph *graph = (TGraph*)obj;
			graph->GetXaxis()->UnZoom();
			graph->GetYaxis()->UnZoom();
			break;
		}
		if( obj->InheritsFrom("TH1"))
		{
			TH1 *hist1 = (TH1*)obj;
			hist1->GetXaxis()->UnZoom();
			hist1->GetYaxis()->UnZoom();
			hist1->GetZaxis()->UnZoom();
			break;
		}
    }
	gPad->Modified();
	gPad->Update();
}
///////////////////////////////////////////////////////////////////






























///////////////////////////////////////////pipico stuff///////////////////////////////////////////////////////////////////
double calcTof(double v0, double Charge_au, double Mass_au,
			   double EField1_Vpcm, double LenReg1_mm, 
			   double EField2_Vpcm, double LenReg2_mm)
{
	const double mmnsns = 0.17588e-1;//convert V/cm * C[a.u.]/M[a.u] to mm/ns^2

	double tges=0;
	double v = v0;
	{
		//calculate the accereration from the E-field in the region, charge and mass of the particle//
		double a = EField1_Vpcm * Charge_au/Mass_au * mmnsns;	//the acceleration in Region 1 in mm/ns^2
		double s = LenReg2_mm;	// the length of this region in mm
		
		//calc how long one particle will fly with the given initial velocity//
		double tt=0;
		if (fabs(a) > 1e-8)		//if there is an accerlartion
			tt = (-v + sqrt(v*v + 2.*a*s))/a;
		else					//if there is no accerlaration (eg drift)
			tt = s/v;

		//during its time in this Region the particle gained velocity if it wasn't a drift (a=0)
		//add this additional velocity to its initial velocity for next iteration
		v += a*tt;

		//add the time that the particle stayed in this region to the total time
		tges += tt;
	}
	if (LenReg2_mm > 0.1)
	{
		//calculate the accereration from the E-field in the region, charge and mass of the particle//
		double a = EField2_Vpcm * Charge_au/Mass_au * mmnsns;	//the acceleration in Region 1 in mm/ns^2
		double s = LenReg2_mm;	// the length of this region in mm
		
		//calc how long one particle will fly with the given initial velocity//
		double tt=0;
		if (fabs(a) > 1e-8)		//if there is an accerlartion
			tt = (-v + sqrt(v*v + 2.*a*s))/a;
		else					//if there is no accerlaration (eg drift)
			tt = s/v;

		//during its time in this Region the particle gained velocity if it wasn't a drift (a=0)
		//add this additional velocity to its initial velocity for next iteration
		v += a*tt;

		//add the time that the particle stayed in this region to the total time
		tges += tt;
	}
	//return the total time
	return tges;
}


void pipico(double MassP1_amu, double ChargeP1_au, 
			  double MassP2_amu, double ChargeP2_au,
			  double MaxEnergy_ev,
			  double EField1_Vpcm, double LenReg1_mm, 
			  double EField2_Vpcm, double LenReg2_mm)
{
	double tof1[200];
	double tof2[200];
	TPolyLine pline;
	pline.SetLineColor(kBlack);
	pline.SetLineWidth(2);
	double mmns_au = 0.4571;	//convert mm/ns in a.u.

	//calc the maximum allowed Momentum
	double MaxMom_au = sqrt(MaxEnergy_ev*0.03687*2.*MassP1_amu*MassP2_amu/(MassP1_amu+MassP2_amu)*1836.15);
	
	//calc the tofs for a variety of Momenta
	for (int i=0;i<200;++i)
	{
		//get the momentum that we want to know the tof for in this iteration//
		double currentMom_au = (double) (i-100) * MaxMom_au / 200.;

		//calc initial velocity for first particle
		double v0P1_mmns =  currentMom_au/MassP1_amu*1836.15 / mmns_au;
		//calc initial velocity for second particle
		double v0P2_mmns = -currentMom_au/MassP2_amu*1836.15 / mmns_au;

		//calc tof of first particle
		tof1[i] = calcTof(v0P1_mmns, ChargeP1_au, MassP1_amu*1836.15, EField1_Vpcm,LenReg1_mm,EField2_Vpcm,LenReg2_mm);
		//calc tof of second particle
		tof2[i] = calcTof(v0P2_mmns, ChargeP2_au, MassP2_amu*1836.15, EField1_Vpcm,LenReg1_mm,EField2_Vpcm,LenReg2_mm);
	}

	//draw the line where Particle 1 has tof 1//
	pline.DrawPolyLine(200,tof1,tof2);
	//draw the line where Particle 2 has tof 1//
	pline.DrawPolyLine(200,tof2,tof1);

}
// calculate RTOF2 from RTOF1 for simple  1-acc. region spetrometer
//
double t2(double t1,double m1,double m2, double q1, double q2, double s, double fieldE) {
	
	//convert to mks

	m1 = m1 * 1.661e-27;
	m2 = m2 * 1.661e-27;
	
	q1 = q1 * 1.60322e-19;
	q2 = q2 * 1.60322e-19;
  
	t1 = t1 * 1e-9;

	s = s / 1000.0; 
	fieldE = fieldE * 100.0;

	double z = s * m1 / (q2 * fieldE * t1) - q1 * t1 / (2. * q2);
	double t2 = z + sqrt(2.* s * m2 / (q2 * fieldE) + z * z);
	t2 = t2 * 1e+9;

	return t2;
}

void pipico2(double Mass1_amu, double Mass2_amu, double charge1_au, double charge2_au, double EField_Vpcm, double LenReg_mm)
{
    double tof1[1000];
    double tof2[1000];
    double t1;

    int MinTof,MaxTof;
    int YMinTof,YMaxTof;


// get histogram

    TList   *list = gPad->GetListOfPrimitives();
    TObject *obj  = list->First();
    TH2D *hist1 = 0;
    while(obj)
    {
        if( !strncmp("TH2",obj->ClassName(),3) )
        {
            hist1 = (TH2D*)obj;
            break;
        }
        obj = list->After(obj);
    }

    MinTof = int(hist1->GetXaxis()->GetXmin());
    MaxTof = int(hist1->GetXaxis()->GetXmax());

    YMinTof = int(hist1->GetYaxis()->GetXmin());
    YMaxTof = int(hist1->GetYaxis()->GetXmax());

    t1 = double(MinTof);

    t1 = double(MinTof);

    for (int i=0;i<1000;++i)
    {

        tof1[i] = t1;
        tof2[i] = t2(t1,Mass1_amu,Mass2_amu,charge1_au,charge2_au,LenReg_mm,EField_Vpcm);
        if(tof2[i]>YMaxTof)
            tof2[i]=YMaxTof;
        if(tof2[i]<YMinTof)
            tof2[i]=YMinTof;
        t1 = t1 + double((MaxTof-MinTof)/1000.);
    }

    TPolyLine *pline = new TPolyLine(1000,tof1,tof2);
    pline->SetLineColor(kBlack);
    pline->SetLineWidth(1);
    pline->Draw();

    t1 = double(MinTof);
    for (int i=0;i<1000;++i)
    {

        tof1[i] = t1;
        tof2[i] = t2(t1,Mass2_amu,Mass1_amu,charge2_au,charge1_au,LenReg_mm,EField_Vpcm);
        if(tof2[i]>YMaxTof)
            tof2[i]=YMaxTof;
        if(tof2[i]<YMinTof)
            tof2[i]=YMinTof;
        t1 = t1 + double((MaxTof-MinTof)/1000.);
    }

    TPolyLine *pline = new TPolyLine(1000,tof1,tof2);
    pline->SetLineColor(kBlack);
    pline->SetLineWidth(1);
    pline->Draw();
} 

//////////////////////////////////////////////////////////////////////////////////////////////////////////////










//////////////////////////////////////convert a 3D-histogram to an ascii file////////////////////////////////////////////////////////////////////////
void hist2ascii(TH3 *h, TString FileName)
{
	std::ofstream f(FileName.Data());

	if(!h) return;

	int dim = h->GetDimension();

	int nbinx = h->GetXaxis()->GetNbins();
	int nbiny = h->GetYaxis()->GetNbins();
	int nbinz = h->GetZaxis()->GetNbins();

	//make caption//
	switch(dim)
	{
	case 3:f<<h->GetZaxis()->GetTitle()<<"\t";
	case 2:f<<h->GetYaxis()->GetTitle()<<"\t";
	case 1:f<<h->GetXaxis()->GetTitle()<<"\t";
	}
	f<<"Value"<<std::endl;

	for (int iz=1;iz<=nbinz;++iz)
	{
		for (int iy=1;iy<=nbiny;++iy)
		{
			for (int ix=1;ix<=nbinx;++ix)
			{
				double x = h->GetXaxis()->GetBinCenter(ix);
				double y = h->GetYaxis()->GetBinCenter(iy);
				double z = h->GetZaxis()->GetBinCenter(iz);
				int bin  = h->GetBin(ix,iy,iz);
				double cont = h->GetBinContent(bin);

				switch(dim)
				{
				case 3:f<<z<<"\t";
				case 2:f<<y<<"\t";
				case 1:f<<x<<"\t";
				}
				f<<cont<<std::endl;
			}
		}
	}
	std::cout << "a " << dim <<"D Histogram has been saved to "<<FileName.Data()<<std::endl;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////



//////////////////////////////////////convert a 2D-histogram to an ascii file////////////////////////////////////////////////////////////////////////
void hist2ascii(TH2 *h, TString FileName)
{
	std::ofstream f(FileName.Data());

	if(!h) return;

	int dim = h->GetDimension();

	int nbinx = h->GetXaxis()->GetNbins();
	int nbiny = h->GetYaxis()->GetNbins();

	//make caption//
	switch(dim)
	{
	case 2:f<<h->GetYaxis()->GetTitle()<<"\t";
	case 1:f<<h->GetXaxis()->GetTitle()<<"\t";
	}
	f<<"Value"<<std::endl;

	for (int iy=1;iy<=nbiny;++iy)
	{
		for (int ix=1;ix<=nbinx;++ix)
		{
			double x = h->GetXaxis()->GetBinCenter(ix);
			double y = h->GetYaxis()->GetBinCenter(iy);
			int bin  = h->GetBin(ix,iy);
			double cont = h->GetBinContent(bin);

			switch(dim)
			{
			case 2:f<<y<<"\t";
			case 1:f<<x<<"\t";
			}
			f<<cont<<std::endl;
		}
	}
	
	std::cout << "a " << dim <<"D Histogram has been saved to "<<FileName.Data()<<std::endl;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////



//////////////////////////////////////convert a 1D-histogram to an ascii file////////////////////////////////////////////////////////////////////////
void hist2ascii(TH1 *h, TString FileName)
{
	std::ofstream f(FileName.Data());

	if(!h) return;

	int dim = h->GetDimension();

	int nbinx = h->GetXaxis()->GetNbins();

	//make caption//
	switch(dim)
	{
	case 1:f<<h->GetXaxis()->GetTitle()<<"\t";
	}
	f<<"Value"<<std::endl;

	for (int ix=1;ix<=nbinx;++ix)
	{
		double x = h->GetXaxis()->GetBinCenter(ix);
		int bin  = h->GetBin(ix);
		double cont = h->GetBinContent(bin);

		switch(dim)
		{
		case 1:f<<x<<"\t";
		}
		f<<cont<<std::endl;
	}

	
	std::cout << "a " << dim <<"D Histogram has been saved to "<<FileName.Data()<<std::endl;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////















//////////////////////////////////////convert a histogram to an ascii file////////////////////////////////////////////////////////////////////////
void hist2ascii(TString HistName, TString FileName)
{
	std::ofstream f(FileName.Data());
	TH1 *h = reinterpret_cast<TH1*>(gROOT->FindObject(HistName.Data()));

	if(!h)
	{
		std::cout << "Could not find a Histogram with Name:"<<HistName.Data()<<std::endl;
		return;
	}

	int dim = h->GetDimension();

	int nbinx = h->GetXaxis()->GetNbins();
	int nbiny = h->GetYaxis()->GetNbins();
	int nbinz = h->GetZaxis()->GetNbins();

	//make caption//
	switch(dim)
	{
	case 3:f<<h->GetZaxis()->GetTitle()<<"\t";
	case 2:f<<h->GetYaxis()->GetTitle()<<"\t";
	case 1:f<<h->GetXaxis()->GetTitle()<<"\t";
	}
	f<<"Value"<<std::endl;

	for (int iz=1;iz<=nbinz;++iz)
	{
		for (int iy=1;iy<=nbiny;++iy)
		{
			for (int ix=1;ix<=nbinx;++ix)
			{
				double x = h->GetXaxis()->GetBinCenter(ix);
				double y = h->GetYaxis()->GetBinCenter(iy);
				double z = h->GetZaxis()->GetBinCenter(iz);
				int bin  = h->GetBin(ix,iy,iz);
				double cont = h->GetBinContent(bin);

				switch(dim)
				{
				case 3:f<<z<<"\t";
				case 2:f<<y<<"\t";
				case 1:f<<x<<"\t";
				}
				f<<cont<<std::endl;
			}
		}
	}
	std::cout <<dim<<"D Histogram with Name \""<< HistName.Data() <<"\" has been saved to "<<FileName.Data()<<std::endl;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////







//////////////////////////////////////convert the actually shown/active histogram to an ascii file////////////////////////////////////////////////////////////////////////
void hist2ascii(TString FileName)
{
	TIter next(gPad->GetListOfPrimitives());
	TObject *obj;
   	while((obj = next()))
	{
		if( obj->InheritsFrom("TH3"))
		{
			TH3 *hist3 = (TH3*)obj;
			hist2ascii(hist3,FileName);
			break;
		}

		if( obj->InheritsFrom("TH2"))
		{
			TH2 *hist2 = (TH2*)obj;
			hist2ascii(hist2,FileName);
			break;
		}

		if( obj->InheritsFrom("TH1"))
		{
			TH1 *hist1= (TH1*)obj;
			hist2ascii(hist1,FileName);
			break;
		}
    	}
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
















/////////////////////////////////// folds Histogram with a gauss function ////////////////////////
double gauss_function(double x,double fwhm)
{
	double a1;
	double sigma;
	sigma = fwhm/2.35482;
	a1 = -x*x/(2.*sigma*sigma);
	a1 = exp(a1);
	a1 = a1 /(sqrt(2.*3.1415926536)*sigma);
	return a1;
}
void foldGauss(TObject * hi1, double fwhm)
{
	TH1D * hi1D_a=0;
	TH2D * hi2D_a=0;
	int i,ii,j,jj;
	int binsx,binsy;
	int binx,biny;
	int maxbinx,maxbiny;
	double a1,a2;
	double binwidthx,binwidthy;

	if (!strncmp("TH1",hi1->ClassName(),3)) {
		hi1D_a = (TH1D*)hi1;
		maxbinx = hi1D_a->GetNbinsX();
		binwidthx = hi1D_a->GetXaxis()->GetBinWidth(1);
		binsx = int(1.3*fwhm / binwidthx) + 1;
		if (binsx<7) binsx = binsx + 2;
		TH1D * hi1D_b = new TH1D("hi1D_b","",maxbinx,hi1D_a->GetXaxis()->GetXmin(),hi1D_a->GetXaxis()->GetXmax());
		for (i=1;i<=maxbinx;++i) {
			a1 = hi1D_a->GetBinContent(i);
			for (j=-binsx;j<=binsx;j++) {
				binx = i+j;
				if (binx>0 && binx<=maxbinx) {
					a2 = a1 * gauss_function(j*binwidthx,fwhm);
					hi1D_b->AddBinContent(binx,a2);
				}
			}
		}

		for (i=1;i<=maxbinx;++i) hi1D_a->SetBinContent(i,hi1D_b->GetBinContent(i));
		delete hi1D_b;
	}

	if (!strncmp("TH2",hi1->ClassName(),3)) {
		hi2D_a = (TH2D*)hi1;


		maxbinx = hi2D_a->GetNbinsX();
		maxbiny = hi2D_a->GetNbinsY();
		binwidthx = hi2D_a->GetXaxis()->GetBinWidth(1);
		binwidthy = hi2D_a->GetYaxis()->GetBinWidth(1);
		binsx = int(0.95*fwhm / binwidthx) + 1;
		binsy = int(0.95*fwhm / binwidthy) + 1;
		if (binsx<7) binsx = binsx + 2;
		if (binsy<7) binsy = binsy + 2;
		binsy = int(0.95*fwhm / binwidthy) + 1;
		TH2D * hi2D_b = new TH2D("hi2D_b","",maxbinx,hi2D_a->GetXaxis()->GetXmin(),hi2D_a->GetXaxis()->GetXmax(),maxbiny,hi2D_a->GetYaxis()->GetXmin(),hi2D_a->GetYaxis()->GetXmax());
		for (i=1;i<=maxbinx;++i) {
			printf("\r%i of %i  ",i,maxbinx);
		for (ii=1;ii<=maxbiny;++ii) {
			a1 = hi2D_a->GetBinContent(i,ii);
			for (j =-binsx;j <=binsx;j++) {
			for (jj=-binsy;jj<=binsy;jj++) {
				binx = i+j;
				biny = ii+jj;
				if (binx>0 && binx<=maxbinx) {
				if (biny>0 && biny<=maxbiny) {
					a2 = a1 * gauss_function(j*binwidthx,fwhm) * gauss_function(jj*binwidthy,fwhm);
					a2 = a2 + hi2D_b->GetBinContent(binx,biny);
					hi2D_b->SetBinContent(binx,biny,a2);
				}
				}
			}
			}
		}
		}

		for (i=1;i<=maxbinx;++i) {
			for (j=1;j<=maxbiny;++j) {
			       	hi2D_a->SetBinContent(i,j,hi2D_b->GetBinContent(i,j));
			}
		}
		delete hi2D_b;
		printf("\n");
	}
}
/////////////////////////////////////////////////////////////////////////////////













/////////////////////////////////// divides two Histograms ////////////////////////
void divHistos(TObject * hi1, TObject * hi2)
{
	TH2D * hi2D_a;
	TH2D * hi2D_b;
	TH1D * hi1D_a;
	TH1D * hi1D_b;

	if (!strncmp("TH1",hi1->ClassName(),3) && !strncmp("TH1",hi2->ClassName(),3)) {
		hi1D_a = (TH1D*)hi1;
		hi1D_b = (TH1D*)hi2;
		if ((hi1D_a->GetNbinsX() != hi1D_b->GetNbinsX()))
		{
			cout <<"Histos must have the same binning"<<endl;
			return;
		}

		hi1D_a->Divide(hi1D_b);
	}

	if (!strncmp("TH2",hi1->ClassName(),3) && !strncmp("TH2",hi2->ClassName(),3)) {
		hi2D_a = (TH2D*)hi1;
		hi2D_b = (TH2D*)hi2;
		if ((hi2D_a->GetNbinsX() != hi2D_b->GetNbinsX()) || (hi2D_a->GetNbinsY() != hi2D_b->GetNbinsY()) )
		{
			cout <<"Histos must have the same binning"<<endl;
			return;
		}

		hi2D_a->Divide(hi2D_b);
	}
}
/////////////////////////////////////////////////////////////////////////////////






///////////////////////////////////////////////////////////////////
int get_pos(int *binx,int *biny,double *x1,double *y1,double *aoc_content)
{
  	   TList   *list = gPad->GetListOfPrimitives();
	   TObject *obj  = list->First();
	   *aoc_content = 0.;
	   *binx = 0;
	   *biny = 0;

	   int px=gPad->GetEventX(); // Absolut pixels in canvas
	   int py=gPad->GetEventY();
	   *x1 = gPad->AbsPixeltoX(px); // Floats position in histogram
	   *y1 = gPad->AbsPixeltoY(py);
	   
	   while(obj) {
		    if( !(strncmp("TGraph", obj->ClassName(), 6)) ) {
		      TGraph * gr = (TGraph*)obj;
		      *binx = gr->GetXaxis()->FindBin(gPad->PadtoX(*x1));
 		      *biny = gr->GetYaxis()->FindBin(gPad->PadtoY(*y1));
		      
//		      *aoc_content = gr->GetBinContent(*binx,*biny);
		      *aoc_content = 0.;
		      return 2;
		    }
		    if( !(strncmp("TH2", obj->ClassName(), 3)) ) {
		      TH2D *h2 = (TH2D*)obj;
		      *binx = h2->GetXaxis()->FindBin(gPad->PadtoX(*x1));
 		      *biny = h2->GetYaxis()->FindBin(gPad->PadtoY(*y1));
		      
		      *aoc_content = h2->GetBinContent(*binx,*biny);
		      return 2;
		    }
		    if( !(strncmp("TH1", obj->ClassName(), 3)) ) {	
			TH1D *h1 = (TH1D*)obj;
			*binx = h1->GetXaxis()->FindBin(*x1);
			*aoc_content = h1->GetBinContent(*binx);
			return 1;
		   } 
	          obj = list->After(obj);
	   }
	   return 0;
}
////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////
class Locate
{
RQ_OBJECT("locate")

public:
	Locate() {}
	~Locate() {}
	void Execute_locate(Int_t event, Int_t px, Int_t py, TObject *sel);
};


void Locate::Execute_locate(Int_t event, Int_t px, Int_t py, TObject *sel)
{
   static double AOC_x,AOC_y;
   double new_x,new_y;
   int binx,biny,dimension;
   double aoc_content;
   double dx,dy;
   TCanvas * c = (TCanvas *) gTQSender;

   dimension = 0;
   binx = 0;   biny = 0;
   
   if (event==3) {   // 3 == right button down
	   printf("\rQuit locate()                            \n");
	   c->Disconnect("ProcessedEvent(Int_t,Int_t,Int_t,TObject*)",this,"Execute_locate(Int_t,Int_t,Int_t,TObject*)");
	   delete this;
	   return;
   }
   if (event==1 || event==51) { // 1 = left button down,  51 = move with no buttons down
	   dimension = get_pos(&binx,&biny,&new_x,&new_y,&aoc_content);
	   dx = new_x - AOC_x;  dy = new_y - AOC_y;
	   if (event == 1) printf("\n"); else printf("\r");
	   if (dimension == 1)   printf("c=%f \tx=%f(%f) \ty=%f(%f) ",aoc_content,new_x,dx,new_y,dy);
	   if (dimension == 2)   printf("c=%f \tx=%f(%f) \ty=%f(%f) d=%f ",aoc_content,new_x,dx,new_y,dy,sqrt(dx*dx+dy*dy));

	   if (event == 1){
	  	 AOC_x = new_x;   AOC_y = new_y;
	   }

         if (dimension == 2)     printf("bx=%d, by=%d   ",binx,biny);
	  if(dimension == 1)      printf("bin=%d     ",binx); 

   }
}

void locate()
{
	Locate* z = new Locate();
	TCanvas *c1 = gPad->GetCanvas();
	printf("\nstop with right mouse click.\n");
	c1->Connect("ProcessedEvent(Int_t,Int_t,Int_t,TObject*)", "Locate",
                    z,"Execute_locate(Int_t,Int_t,Int_t,TObject*)");
}
//////////////////////////////////////////////////////////////////










//////////////////////////////////////////////////////////////////
class Locate_c
{
RQ_OBJECT("locate_c")

public:
	Locate_c() {}
	~Locate_c() {}
	void Execute_locate_c(Int_t event, Int_t px, Int_t py, TObject *sel);
};


void Locate_c::Execute_locate_c(Int_t event, Int_t px, Int_t py, TObject *sel)
{
   static double AOC_x,AOC_y;
   double new_x,new_y;
   int binx,biny,dimension;
   double aoc_content;
   double dx,dy;
   TCanvas * c = (TCanvas *) gTQSender;

   dimension = 0;
   binx = 0;   biny = 0;
   static int iii;
   
   if (event==3) {   // 3 == right button down
	   iii = 0;
	   printf("\rQuit locate_c()                            \n");
	   c->Disconnect("ProcessedEvent(Int_t,Int_t,Int_t,TObject*)",this,"Execute_locate_c(Int_t,Int_t,Int_t,TObject*)");
	   delete this;
	   return;
   }
   if (event==1 || event==51) { // 1 = left button down,  51 = move with no buttons down
	   dimension = get_pos(&binx,&biny,&new_x,&new_y,&aoc_content);
	   dx = new_x - AOC_x;  dy = new_y - AOC_y;
	   if (event == 1) printf("\n"); else printf("\r");
	   if (dimension == 1)   printf("x[%i]=%f; \ty[%i]=%f;            ",iii,new_x,iii,new_y);
	   if (dimension == 2)   printf("x[%i]=%f; \ty[%i]=%f;            ",iii,new_x,iii,new_y);
	   if (event == 1) ++iii;

	   if (event == 1){
	  	 AOC_x = new_x;   AOC_y = new_y;
	   }

   }
}

void locate_c()
{
	Locate_c* z = new Locate_c();
	TCanvas *c1 = gPad->GetCanvas();
	printf("\nstop with right mouse click.\n");
	c1->Connect("ProcessedEvent(Int_t,Int_t,Int_t,TObject*)", "Locate_c",
                    z,"Execute_locate_c(Int_t,Int_t,Int_t,TObject*)");
}
//////////////////////////////////////////////////////////////////







///////////////////////////////////////////////////////////////
void flipx1d(TH1D * hist)
{
	printf("flip 1D\n");
	if (!hist) return;
	int i,j;

	if (hist->InheritsFrom("TH2")) return;
	if (!hist->InheritsFrom("TH1")) return;

	int Nx;
	double a1;

	hist->GetXaxis()->UnZoom();
	hist->GetYaxis()->UnZoom();

	Nx = hist->GetXaxis()->GetLast();
	double max = -1.e200;
	double min = 1.e200;

	for (i=1;i<=int(Nx/2);i++)
	{
		a1 = (hist->GetBinContent(i)+hist->GetBinContent(Nx-i+1))*0.5;
		if (a1 > max) max = a1;
		if (a1 < min) min = a1;
		hist->SetBinContent(i,a1);
		hist->SetBinContent(Nx-i+1,a1);	
	}

	hist->SetMaximum(max*1.1);
	hist->SetMinimum(min);
}



void flipx2d(TH2D * hist)
{
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
			a1 = (hist->GetBinContent(i,j)+hist->GetBinContent(Nx-i+1,j))*0.5;
			if (a1 > max) max = a1;
			if (a1 < min) min = a1;
			hist->SetBinContent(i,j,a1);
			hist->SetBinContent(Nx-i+1,j,a1);
		}
	}
	hist->SetMaximum(max*1.1);
	hist->SetMinimum(min);
}

void flipx(TObject * obj) {
	if (obj->InheritsFrom("TH2")) {
		flipx2d((TH2D*)obj);
		return;
	}
	if (obj->InheritsFrom("TH1")) {
		flipx1d((TH1D*)obj);
		return;
	}
}

void flipy(TObject * obj)
{
	if (!obj) return;
	int i,j;

	int Nx,Ny;
	double a1;

	if (!obj->InheritsFrom("TH2")) return;		
	
	TH2D * hist = (TH2D*)obj;

	hist->GetXaxis()->UnZoom();
	hist->GetYaxis()->UnZoom();

	Nx = hist->GetXaxis()->GetLast();
	Ny = hist->GetYaxis()->GetLast();

	double max = -1.e200;
	double min = 1.e200;


	for (j=1;j<=int(Ny/2);j++)
	{
		for (i=1;i<=Nx;i++)
		{
			a1 = (hist->GetBinContent(i,j)+hist->GetBinContent(i,Ny-j+1))*0.5;
			if (a1 > max) max = a1;
			if (a1 < min) min = a1;
			hist->SetBinContent(i,j,a1);
			hist->SetBinContent(i,Ny-j+1,a1);
		}
	}	

	hist->SetMaximum(max*1.1);
	hist->SetMinimum(min);
}

///////////////////////////////////////////////////////////////













///////////////////////////////////////////////////////////////////
void aspect(Int_t onoff)
{
	gPad->SetFixedAspectRatio(onoff);
	if (!onoff) printf("Aspect ratio is free in this pad\n");
	if (onoff) printf("Aspect ratio is locked in this pad\n");
}
///////////////////////////////////////////////////////////////////










//////////////////////////////////////////////////////////////////
void lin()
{
	
    TList   *list = gPad->GetListOfPrimitives();
    TObject *obj  = list->First();

    while(obj) {
      int cmpval = strncmp("TH1", obj->ClassName(), 3);
      if( !cmpval ) {
		gPad->SetLogy(0);
		TH1D *hist1 = (TH1D*)obj;
		hist1->Draw();
		break;
      }
      cmpval = strncmp("TH2", obj->ClassName(), 3);
      if( !cmpval ) {
		gPad->SetLogz(0);
		TH2D *hist2 = (TH2D*)obj;
		hist2->Draw("col");
		break;
      }
      obj = list->After(obj);
    }
}
void log()
{
    TList   *list = gPad->GetListOfPrimitives();
    TObject *obj  = list->First();

    while(obj) {
      int cmpval = strncmp("TH1", obj->ClassName(), 3);
      if( !cmpval ) {
		gPad->SetLogy(1);
		TH1D *hist1 = (TH1D*)obj;
		hist1->Draw();
		break;
      }
      cmpval = strncmp("TH2", obj->ClassName(), 3);
      if( !cmpval ) {
		gPad->SetLogz(1);
		TH2D *hist2 = (TH2D*)obj;
		hist2->Draw("col");
		break;
      }
      obj = list->After(obj);
    }
}
void liny()
{
	
    TList   *list = gPad->GetListOfPrimitives();
    TObject *obj  = list->First();

    while(obj) {
      int cmpval = strncmp("TH1", obj->ClassName(), 3);
      if( !cmpval ) {
		gPad->SetLogy(0);
		TH1D *hist1 = (TH1D*)obj;
		hist1->Draw();
		break;
      }
      obj = list->After(obj);
    }
}
void logy()
{
    TList   *list = gPad->GetListOfPrimitives();
    TObject *obj  = list->First();

    while(obj) {
      int cmpval = strncmp("TH1", obj->ClassName(), 3);
      if( !cmpval ) {
		gPad->SetLogy(1);
		TH1D *hist1 = (TH1D*)obj;
		hist1->Draw();
		break;
      }
      obj = list->After(obj);
    }
}
void linx()
{
	
    TList   *list = gPad->GetListOfPrimitives();
    TObject *obj  = list->First();

    while(obj) {
      int cmpval = strncmp("TH1", obj->ClassName(), 3);
      if( !cmpval ) {
		gPad->SetLogx(0);
		TH1D *hist1 = (TH1D*)obj;
		hist1->Draw();
		break;
      }
      obj = list->After(obj);
    }
}
void logx()
{
    TList   *list = gPad->GetListOfPrimitives();
    TObject *obj  = list->First();

    while(obj) {
      int cmpval = strncmp("TH1", obj->ClassName(), 3);
      if( !cmpval ) {
		gPad->SetLogx(1);
		TH1D *hist1 = (TH1D*)obj;
		hist1->Draw();
		break;
      }
      obj = list->After(obj);
    }
}
void linz()
{
    TList   *list = gPad->GetListOfPrimitives();
    TObject *obj  = list->First();

    while(obj) {
      int cmpval = strncmp("TH2", obj->ClassName(), 3);
      if( !cmpval ) {
		gPad->SetLogz(0);
		TH2D *hist1 = (TH2D*)obj;
		hist1->Draw("col");
		break;
      }
      obj = list->After(obj);
    }
}
void logz()
{
    TList   *list = gPad->GetListOfPrimitives();
    TObject *obj  = list->First();

    while(obj) {
      int cmpval = strncmp("TH2", obj->ClassName(), 3);
      if( !cmpval ) {
		gPad->SetLogz(1);
		TH2D *hist1 = (TH2D*)obj;
		hist1->Draw("col");
		break;
      }
      obj = list->After(obj);
    }
}
//////////////////////////////////////////////////////////////////







///////////////////////////////////////////////////////////////////
void swap(Int_t pad1,Int_t pad2)
{
	TCanvas * MyCanvas;

	TH1D   *first1D=0;
	TH1D   *second1D=0;
	TH2D   *first2D=0;
	TH2D   *second2D=0;
	TH1F   *first1F=0;
	TH1F   *second1F=0;
	TH2F   *first2F=0;
	TH2F   *second2F=0;


	//voidcanvas = gPad->GetVirtCanvas();
	//MyCanvas=voidcanvas;
    MyCanvas = gPad->GetCanvas();
    MyCanvas->cd(pad1);
    TList   *list = gPad->GetListOfPrimitives();
    TObject *obj  = list->First();
  
    while(obj) {
      int cmpval = strncmp("TH1D", obj->ClassName(), 4);
      if( !cmpval ) {
	printf("Pad %d contained a TH1D\n",pad1);
	first1D = (TH1D*)obj;
	break;
      }
      cmpval = strncmp("TH2D", obj->ClassName(), 4);
      if( !cmpval ) {
	printf("Pad %d contained a TH2D\n",pad1);
	first2D = (TH2D*)obj;
	break;
      }
      cmpval = strncmp("TH1F", obj->ClassName(), 4);
      if( !cmpval ) {
	printf("Pad %d contained a TH1F\n",pad1);
	first1F = (TH1F*)obj;
	break;
      }
      cmpval = strncmp("TH2F", obj->ClassName(), 4);
      if( !cmpval ) {
	printf("Pad %d contained a TH2F\n",pad1);
	first2F = (TH2F*)obj;
	break;
      }

      obj = list->After(obj);
    }


    MyCanvas->cd(pad2);
    list = gPad->GetListOfPrimitives();
    obj  = list->First();
  
    while(obj) {
      int cmpval = strncmp("TH1D", obj->ClassName(), 4);
      if( !cmpval ) {
	printf("\nPad %d contained a TH1D\n",pad2);
	second1D = (TH1D*)obj;
	break;
      }
      cmpval = strncmp("TH2D", obj->ClassName(), 4);
      if( !cmpval ) {
	printf("\nPad %d contained a TH2D\n",pad2);
	second2D = (TH2D*)obj;
	break;
      }
      cmpval = strncmp("TH1F", obj->ClassName(), 4);
      if( !cmpval ) {
	printf("\nPad %d contained a TH1F\n",pad2);
	second1F = (TH1F*)obj;
	break;
      }
      cmpval = strncmp("TH2F", obj->ClassName(), 4);
      if( !cmpval ) {
	printf("\nPad %d contained a TH2F\n",pad2);
	second2F = (TH2F*)obj;
	break;
      }

      obj = list->After(obj);
    }

	if (1) 
    
    if (!first1D && !first2D && !first1F && !first2F) {
	    printf("Pad %d was empty\n",pad1);}

    
    if (!second1D && !second2D && !second1F && !second2F) {
	    printf("Pad %d was empty\n",pad2);}


    gPad->Clear();
    if (first1D!=0) first1D->Draw();
    if (first2D!=0) first2D->Draw();
    if (first1F!=0) first1F->Draw();
    if (first2F!=0) first2F->Draw();
    gPad->Modified();
    gPad->Update();	
    
    MyCanvas->cd(pad1);
    gPad->Clear();
    if (second1D!=0) second1D->Draw();
    if (second2D!=0) second2D->Draw();
    if (second1F!=0) second1F->Draw();
    if (second2F!=0) second2F->Draw();
    gPad->Modified();
    gPad->Update();	
}
///////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////
void remfit()
{
    TList   *list = gPad->GetListOfPrimitives();
    TList   *funclist;
    TObject *obj  = list->First();
    TObject *obj2;
    TF1 *fit;
  
    while(obj) {
      if(!strncmp("TH1", obj->ClassName(), 3)) {
	TH1D *hist = (TH1D*)obj;
	funclist = hist->GetListOfFunctions();
	obj2 = funclist->First();
	while (obj2) {
		if(!strncmp("TF1", obj2->ClassName(), 3)) {
			fit = (TF1*)obj2;
			obj2 = funclist->After(obj2);
			fit->Delete();
		} else	obj2 = funclist->After(obj2);
	}
	hist->Draw();
	gPad->Modified();
	gPad->Update();
	break;
      }
      
      obj = list->After(obj);
    }
}
///////////////////////////////////////////////////////////////////











///////////////////////////////////////////////////////////////////
void normalize_y()
{
    TList   *list = gPad->GetListOfPrimitives();
    TObject *obj  = list->First();
    int dimension;
    TH2D *hist2;
    




    dimension = 0;
  
    while(obj) {
      int cmpval = strncmp("TH2", obj->ClassName(), 3);
      if( !cmpval ) {
	        dimension = 2;
		hist2 = (TH2D*)obj;
		break;
      }
      obj = list->After(obj);
    }

    if (dimension == 0) printf("No histgram found in this pad.\n");

	if (dimension == 2) {
		int binx = hist2->GetXaxis()->GetNbins();
		int biny = hist2->GetYaxis()->GetNbins();

		for (int x = 1;x<=binx;++x) {
			double maximum = 0.;
			for (int y = 1;y<=biny;++y) {
				if (maximum < hist2->GetBinContent(x,y)) 
					maximum = hist2->GetBinContent(x,y);
			}
			if (fabs(maximum) > 1.e-200) for (int y = 1;y<=biny;++y) hist2->SetBinContent(x,y,hist2->GetBinContent(x,y)/maximum);
		}
	  
		hist2->Draw();
		gPad->Modified();
		gPad->Update();
	}

	
}
///////////////////////////////////////////////////////////////////







///////////////////////////////////////////////////////////////////
void normalize_integral_y()
{ 
    // normalizes the integral of each column to 1.
 
    TList   *list = gPad->GetListOfPrimitives();
    TObject *obj  = list->First();
    int dimension;
    TH1D *hist1;
    TH2D *hist2;
    dimension = 0;
  
    while(obj) {
      int cmpval = strncmp("TH2", obj->ClassName(), 3);
      if( !cmpval ) {
	        dimension = 2;
		hist2 = (TH2D*)obj;
		break;
      }
      cmpval = strncmp("TH1", obj->ClassName(), 3);
      if( !cmpval ) {
	        dimension = 1;
		hist1 = (TH1D*)obj;
		break;
      }
      obj = list->After(obj);
    }

    if (dimension == 0) printf("No histgram found in this pad.\n");

	if (dimension == 2) {
		int binx = hist2->GetXaxis()->GetNbins();
		int biny = hist2->GetYaxis()->GetNbins();

		for (int x = 1;x<=binx;++x) {
			double integral = 0.;
			for (int y = 1;y<=biny;++y) integral += hist2->GetBinContent(x,y);
			if (fabs(integral)> 1.e-100) for (int y = 1;y<=biny;++y) hist2->SetBinContent(x,y,hist2->GetBinContent(x,y)/integral);
		}
	  
		hist2->Draw();
		gPad->Modified();
		gPad->Update();
	}

	if (dimension == 1) {
		int binx = hist1->GetXaxis()->GetNbins();

		double integral = 0.;
		for (int x = 1;x<=binx;++x) {
			integral +=  hist1->GetBinContent(x);
		}
		for (int x = 1;x<=binx;++x) {
			hist1->SetBinContent(x,hist1->GetBinContent(x)/integral);
		}

		hist1->Draw();
		gPad->Modified();
		gPad->Update();
	}

	
}
///////////////////////////////////////////////////////////////////










///////////////////////////////////////////////////////////////////
void normalize(double peak,int bin_number)
{
    TList   *list = gPad->GetListOfPrimitives();
    TObject *obj  = list->First();
    int dimension;
    TH1D *hist1;
    TH2D *hist2;
    int i,j,flag;
    int binxmin,binxmax,binymin,binymax;
    double content,factor;

    dimension = 0;
  
    while(obj) {
      int cmpval = strncmp("TH1", obj->ClassName(), 3);
      if( !cmpval ) {
	        dimension = 1;
		hist1 = (TH1D*)obj;
		break;
      }
      cmpval = strncmp("TH2", obj->ClassName(), 3);
      if( !cmpval ) {
	        dimension = 2;
		hist2 = (TH2D*)obj;
		break;
      }
      obj = list->After(obj);
    }

    if (dimension == 0) printf("No histgram found in this pad.\n");

	if (dimension == 1) {
	    	hist1->GetXaxis()->UnZoom();
		hist1->GetYaxis()->UnZoom();
		binxmin = hist1->GetXaxis()->GetFirst();
		binxmax = hist1->GetXaxis()->GetLast();
		if (fabs(hist1->GetBinContent(bin_number)) != 0.) {
			flag = 0;
			if (bin_number > 0) {
				flag = 1;
				factor = peak / (hist1->GetBinContent(bin_number));
			}
			hist1->Scale(factor);
			hist1->Draw();
			gPad->Modified();
			gPad->Update();
		} else printf("Bin content is zero.\n");
	}
    
	if (dimension == 2) {
	    	hist2->GetXaxis()->UnZoom();
		hist2->GetYaxis()->UnZoom();
		binxmin = hist2->GetXaxis()->GetFirst();
		binxmax = hist2->GetXaxis()->GetLast();
		binymin = hist2->GetYaxis()->GetFirst();
		binymax = hist2->GetYaxis()->GetLast();

		for (j=binxmin;j<=binxmax;j++) {
			flag = 0;
			if (fabs(hist2->GetBinContent(j,bin_number)) != 0.) {
				if (bin_number > 0) {
					flag = 1;
					factor = peak / (hist2->GetBinContent(j,bin_number));	
				}
				for (i=binymax;i>=binymin;i--) {
					content = hist2->GetBinContent(j,i);		
					if (flag == 0 && content>1.e-90) {
						factor = peak/content;
						flag = 1;
					}
					if (flag == 1 && i != bin_number) hist2->SetBinContent(j,i,content*factor);
				}
			}
			
		}
		hist2->Draw();
		gPad->Modified();
		gPad->Update();
	}

	
}
///////////////////////////////////////////////////////////////////















///////////////////////////////////////////////////////////////////
void add_root_files_(TDirectory * curr_dir,char * old_path, TFile * file1, TFile * file2, TFile * new_file,double f1,double f2)
{
	char name[1024];
	char abs_path[1024];

	sprintf(abs_path,"%s",old_path);

	TObject *obj;
	TDirectory *next_dir;

	TIter next(curr_dir->GetListOfKeys());
	while (obj = next())
	{
		sprintf(name,"%s",obj->GetName());

		next_dir = (TDirectory*)curr_dir->GetDirectory(name);
		if ( next_dir ) {
			sprintf(name,"%s/%s",abs_path,name);
			add_root_files_(next_dir,name,file1,file2,new_file,f1,f2);
		} else {
			if (abs_path[0] != 0) sprintf(name,"%s/%s",abs_path,name); 

			TObject * obj2 = file1->Get(name);
			if (!obj2) {
				printf("could note read object from file 1: %s\n",name);
				break;
			}

			TObject * obj3 = 0;

			if (obj2->InheritsFrom("TH1D")) {
				printf("added TH1D: %s\n",name);
				TH1D * h2_1d = (TH1D*)file2->Get(name);
				if (!h2_1d) {printf("could note read object from file 2: %s\n",name); break;}
				TH1D * h1_1d = (TH1D*)obj2;
				h2_1d->Add(h2_1d,h1_1d,f1,f2);
				obj3 = (TObject*)h2_1d;
			}
			if (obj2->InheritsFrom("TH2D")) {
				printf("added TH2D: %s\n",name);
				TH2D * h2_2d = (TH2D*)file2->Get(name);
				if (!h2_2d) {printf("could note read object from file 2: %s\n",name); break;}
				TH2D * h1_2d = (TH2D*)obj2;
				h2_2d->Add(h2_2d,h1_2d,f1,f2);
				obj3 = (TObject*)h2_2d;
			}
			if (obj2->InheritsFrom("TH3D")) {
				printf("added TH3D: %s\n",name);
				TH3D * h2_3d = (TH3D*)file2->Get(name);
				if (!h2_3d) {printf("could note read object from file 2: %s\n",name); break;}
				TH3D * h1_3d = (TH3D*)obj2;
				h2_3d->Add(h2_3d,h1_3d,f1,f2);
				obj3 = (TObject*)h2_3d;
			}

			if (obj3) {
				TDirectory * new_dir = new_file->GetDirectory(abs_path);
				if (!new_dir) {
					new_file->mkdir(abs_path+1);
					new_file->Write();
					new_dir = new_file->GetDirectory(abs_path);
				}
				h2_1d->SetDirectory(new_dir);
				continue;
			}
			printf("skipped object of unknown type%s\n",name);
		}
	}
}






void add_root_files(char * file1_name, double f1, char * file2_name, double f2, char * new_file_name)
{
	char * c;
	TFile * file1 = new TFile(file1_name,"READ");
	if (file1->IsZombie() || !file1->IsOpen()) {
		printf("can not open file %s\n",file1_name);
		delete file1; file1 = 0;
		return;
	}
	TFile * file2 = new TFile(file2_name,"READ");
	if (file2->IsZombie() || !file2->IsOpen()) {
		printf("can not open file %s\n",file2_name);
		file1->Close();
		delete file1; file1 = 0;
		delete file2; file2 = 0;
		return;
	}
	TFile * new_file = new TFile(new_file_name,"RECREATE");
	if (new_file->IsZombie() || !new_file->IsOpen()) {
		printf("can not open file %s\n",new_file_name);
		file1->Close();
		file2->Close();
		delete file1; file1 = 0;
		delete file2; file2 = 0;
		delete new_file; new_file = 0;
		return;
	}

	add_root_files_((TDirectory*)file1->GetDirectory("/"),c,file1,file2,new_file,f1,f2);

	new_file->Write();
	file1->Close();
	file2->Close();
	new_file->Close();
	delete file1;
	delete file2;
	delete new_file;
}
///////////////////////////////////////////////////////////////////







#endif
