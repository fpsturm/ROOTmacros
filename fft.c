{
// perform FFT
#include "TH1D.h"
#include "TVirtualFFT.h"
#include "TF1.h"
#include "TCanvas.h"
#include "TMath.h"

	TH1*hist = get1DHistFromPad();
	TH1 *hm =0;
	TVirtualFFT::SetTransform(0);
	hm = hist->FFT(hm, "MAG");
	hm->SetTitle("Magnitude of the 1st transform");
	hm->Draw();
}