#include "TMath.h"
#include "TComplex.h"
#include "Math/SpecFunc.h"

Double_t PlmFunc(Double_t *x, Double_t *par)
{
	const double theta	= x[0];

	//Define the Spherical harmonics//
	const double P10 = ROOT::Math::assoc_legendre(1,0,theta);

	const double P20 = ROOT::Math::assoc_legendre(2,0,theta);

	const double P30 = ROOT::Math::assoc_legendre(3,0,theta);

	const double P40 = ROOT::Math::assoc_legendre(4,0,theta);

	const double P50 = ROOT::Math::assoc_legendre(5,0,theta);
	
	const double P60 = ROOT::Math::assoc_legendre(6,0,theta);
	
	const double P70 = ROOT::Math::assoc_legendre(7,0,theta);
	
	const double P80 = ROOT::Math::assoc_legendre(8,0,theta);
	
	const double P90 = ROOT::Math::assoc_legendre(9,0,theta);

	const double P100 = ROOT::Math::assoc_legendre(10,0,theta);
	
	//const double P110 = ROOT::Math::assoc_legendre(11,0,theta);
	//const double P120 = ROOT::Math::assoc_legendre(12,0,theta);
	//const double P130 = ROOT::Math::assoc_legendre(13,0,theta);
	//const double P140 = ROOT::Math::assoc_legendre(14,0,theta);
	
	
	//get the amplitudes from the parameter vector//
	const double A00 = par[0];
	const double A10 = par[1];
	const double A20 = par[2];
	const double A30 = par[3];
	const double A40 = par[4];
	const double A50 = par[5];
	const double A60 = par[6];
	const double A70 = par[7];	
	const double A80 = par[8];	
	const double A90 = par[9];	
	const double A100 = par[10];
	//const double A110 = par[11];
	//const double A120 = par[12];
	//const double A130 = par[13];
	//const double A140 = par[14];
	//Calculate the things//
	const double tx	=	A00 +
						A10*P10 +
						A20*P20 +
						A30*P30 +
						A40*P40+
						A50*P50+
						A60*P60+
						A70*P70+
						A80*P80+
						A90*P90+
						A100*P100/*+
						A110*P110+
						A120*P120+
						A130*P130+
						A140*P140*/;
						

	//calculate the return value//
	double retval = (tx);

	return retval;
}	





Double_t YlmFunc(Double_t *x, Double_t *par)
{
	const double angle	= 0;
	
	const double c		= TMath::Cos(angle*TMath::DegToRad());
	const double s		= TMath::Sin(angle*TMath::DegToRad());

	const double phi	= 0;
	const double theta	= x[0];
	//if you want to fit a 2D histo, where the y-values are the the phi values//
	//access to y-values: x[1]//
	//const double phi	= x[1];//

	//Define the Spherical harmonics//
	TComplex Y11 (ROOT::Math::assoc_legendre(1,1,theta)*TMath::Cos(phi), ROOT::Math::assoc_legendre(1,1,theta)*TMath::Sin(phi));
	TComplex Y10 (ROOT::Math::assoc_legendre(1,0,theta), 0);
	TComplex Y1m1(-1.*TComplex::Conjugate(Y11));

	TComplex Y21 (ROOT::Math::assoc_legendre(2,1,theta)*TMath::Cos(phi), ROOT::Math::assoc_legendre(2,1,theta)*TMath::Sin(phi));
	TComplex Y20 (ROOT::Math::assoc_legendre(2,0,theta), 0);
	TComplex Y2m1(-1.*TComplex::Conjugate(Y21));

	TComplex Y31 (ROOT::Math::assoc_legendre(3,1,theta)*TMath::Cos(phi), ROOT::Math::assoc_legendre(3,1,theta)*TMath::Sin(phi));
	TComplex Y30 (ROOT::Math::assoc_legendre(3,0,theta), 0);
	TComplex Y3m1(-1.*TComplex::Conjugate(Y31));

	TComplex Y41 (ROOT::Math::assoc_legendre(4,1,theta)*TMath::Cos(phi), ROOT::Math::assoc_legendre(4,1,theta)*TMath::Sin(phi));
	TComplex Y40 (ROOT::Math::assoc_legendre(4,0,theta), 0);
	TComplex Y4m1(-1.*TComplex::Conjugate(Y41));
	
	TComplex Y51 (ROOT::Math::assoc_legendre(5,1,theta)*TMath::Cos(phi), ROOT::Math::assoc_legendre(5,1,theta)*TMath::Sin(phi));
	TComplex Y50 (ROOT::Math::assoc_legendre(5,0,theta), 0);
	TComplex Y5m1(-1.*TComplex::Conjugate(Y51));

	//get the amplitudes from the parameter vector//
	TComplex A00(par[0] ,0.);
	TComplex A10(par[1] ,par[2]);
	TComplex A11(par[3] ,par[4]);
	TComplex A20(par[5] ,par[6]);
	TComplex A21(par[7] ,par[8]);
	TComplex A30(par[9] ,par[10]);
	TComplex A31(par[11],par[12]);
	TComplex A40(par[13],par[14]);
	TComplex A41(par[15],par[16]);
	TComplex A50(par[17],par[18]);
	TComplex A51(par[19],par[20]);

	//Calculate the things//
	TComplex tx	=	A00 +
					A10*Y10 +
					A20*Y20 +
					A30*Y30 +
					A40*Y40 +
					A50*Y50;

	TComplex ty	=	A11*(Y11+Y1m1) +
					A21*(Y21+Y2m1) +
					A31*(Y31+Y3m1) +
					A41*(Y41+Y4m1) +
					A51*(Y51+Y5m1);

	TComplex tz	=	A11*(Y11-Y1m1) +
					A21*(Y21-Y2m1) +
					A31*(Y31-Y3m1) +
					A41*(Y41-Y4m1) +
					A51*(Y51-Y5m1);

	//calculate the return value//
	double retval = TComplex::Abs(tx*c + ty*s) * TComplex::Abs(tx*c + ty*s);

	return retval;
}


//// circular part

Double_t YlmFunc_circ(Double_t *x, Double_t *par)
{
	const double angle	= 90;
	
	const double c		= TMath::Cos(angle*TMath::DegToRad());
	const double s		= TMath::Sin(angle*TMath::DegToRad());

	//	  if(u.gt.0)azi=90./180*3.1415
	// if(u.lt.0)azi=-90./180*3.1415
	 double phi	= 0;
	if(x[0]<180) phi = 90./180*3.1415;
	else phi =-90./180*3.1415;
	
	const double theta	= TMath::Cos(x[0]*TMath::DegToRad());
	//if you want to fit a 2D histo, where the y-values are the the phi values//
	//access to y-values: x[1]//
	//const double phi	= x[1];//

	//Define the Spherical harmonics//
	TComplex Y11 (ROOT::Math::assoc_legendre(1,1,theta)*TMath::Cos(phi), ROOT::Math::assoc_legendre(1,1,theta)*TMath::Sin(phi));
	TComplex Y10 (ROOT::Math::assoc_legendre(1,0,theta), 0);
	TComplex Y1m1(-1.*TComplex::Conjugate(Y11));

	TComplex Y21 (ROOT::Math::assoc_legendre(2,1,theta)*TMath::Cos(phi), ROOT::Math::assoc_legendre(2,1,theta)*TMath::Sin(phi));
	TComplex Y20 (ROOT::Math::assoc_legendre(2,0,theta), 0);
	TComplex Y2m1(-1.*TComplex::Conjugate(Y21));

	TComplex Y31 (ROOT::Math::assoc_legendre(3,1,theta)*TMath::Cos(phi), ROOT::Math::assoc_legendre(3,1,theta)*TMath::Sin(phi));
	TComplex Y30 (ROOT::Math::assoc_legendre(3,0,theta), 0);
	TComplex Y3m1(-1.*TComplex::Conjugate(Y31));

	TComplex Y41 (ROOT::Math::assoc_legendre(4,1,theta)*TMath::Cos(phi), ROOT::Math::assoc_legendre(4,1,theta)*TMath::Sin(phi));
	TComplex Y40 (ROOT::Math::assoc_legendre(4,0,theta), 0);
	TComplex Y4m1(-1.*TComplex::Conjugate(Y41));

	//get the amplitudes from the parameter vector//
	TComplex A00(par[0] ,0.);
	TComplex A10(par[1] ,par[2]);
	TComplex A11(par[3] ,par[4]);
	TComplex A20(par[5] ,par[6]);
	TComplex A21(par[7] ,par[8]);
	TComplex A30(par[9] ,par[10]);
	TComplex A31(par[11],par[12]);
	TComplex A40(par[13],par[14]);
	TComplex A41(par[15],par[16]);

	//Calculate the things//
	TComplex tx	=	A00 +
					A10*Y10 +
					A20*Y20 +
					A30*Y30 +
					A40*Y40;

	TComplex ty	=	A11*(Y11+Y1m1) +
					A21*(Y21+Y2m1) +
					A31*(Y31+Y3m1) +
					A41*(Y41+Y4m1);

	TComplex tz	=	A11*(Y11-Y1m1) +
					A21*(Y21-Y2m1) +
					A31*(Y31-Y3m1) +
					A41*(Y41-Y4m1);

	//calculate the return value//
	// double retval = TComplex::Abs(tx*c + ty*s);//  * TComplex::Abs(tx*c + ty*s);
	TComplex f(0.,1.);
	//  test=cabs((tx-cmplx(0.,1.)*ty)*s+(tz*c))**2
	double retval = pow( TComplex::Abs( (tx- f*ty)*s + (tz*c) ),2);
	return retval;
}	

