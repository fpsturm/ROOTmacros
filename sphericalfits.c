// requires function get1DHistFromPad()

void sphfit(int fitmode=0,int polariz=0){
    
    // fitmode:     choose fitmode=0 for fit with spherical harmonics
    //              or fitmode=1 for only Legendre polynominals
    // polariz:     0 for linear polarization, 1 for circular polarization

        
    //create a function pointer//
    gSystem->Load("libMathMore");
    //find the histogram in current pad//
    TH1* hist = get1DHistFromPad();

    // compile function
     gROOT->ProcessLine(".L sphericalfunc.c+");	//loading using ACLIC (root has to be started in the compiling environment for that)
    
    // get range of histogram
    double rangelow = hist->GetXaxis()->GetXmin();
    double rangehigh = hist->GetXaxis()->GetXmax();

    //check wether the histo has the right ranges and is in degrees or in cos--//
    bool degrees = false;
    if( ((hist->GetXaxis()->GetXmin() ==-180) && (hist->GetXaxis()->GetXmax() == 180)) ||
	((hist->GetXaxis()->GetXmin() ==   0) && (hist->GetXaxis()->GetXmax() == 360))
    )
        degrees = true;
    
    else if ((hist->GetXaxis()->GetXmin() ==  -1) && (hist->GetXaxis()->GetXmax() ==   1))
	degrees = false;
        
    else{
	cout << "The Histogram has the wrong Range:"<<endl;
	cout << "   "<< hist->GetXaxis()->GetXmin() << " ... "<< hist->GetXaxis()->GetXmax()<<endl;
	cout << "This Macro only supports Histograms in the following Ranges:"<<endl;
	cout << "   -180 ... 180"<<endl;
	cout << "or    0 ... 360"<<endl;
	cout << "or   -1 ... 1"<<endl;
        return;
    }
    
    if(fitmode==0){ 
	if(polariz==0)
	    TF1 *func = new TF1("func",YlmFunc,rangelow,rangehigh,21);
	else
	    TF1 *func = new TF1("func",YlmFunc_circ,rangelow,rangehigh,21);
    }
    else{
	if(polariz==0)
	    TF1 *func = new TF1("func",PlmFunc,rangelow,rangehigh,11);
	else
	    TF1 *func = new TF1("func",PlmFunc_circ,rangelow,rangehigh,15);
    }
    
    // set up function by function mode
    if(fitmode==0){
        //  give parameters their names (Ylm function)//
	func->SetParName(0,"A00Real");
	func->SetParName(1,"A10Real");
	func->SetParName(2,"A10Imag");
	func->SetParName(3,"A11Real");
	func->SetParName(4,"A11Imag");
	func->SetParName(5,"A20Real");
	func->SetParName(6,"A20Imag");
	func->SetParName(7,"A21Real");
	func->SetParName(8,"A21Imag");
	func->SetParName(9,"A30Real");
	func->SetParName(10,"A30Imag");
	func->SetParName(11,"A31Real");
	func->SetParName(12,"A31Imag");
	func->SetParName(13,"A40Real");
	func->SetParName(14,"A40Imag");
	func->SetParName(15,"A41Real");
	func->SetParName(16,"A41Imag");
	func->SetParName(17,"A50Real");
	func->SetParName(18,"A50Imag");
	func->SetParName(19,"A51Real");
	func->SetParName(20,"A51Imag");        
    }

     else{
	//  give parameters their names (Plm function)//
 	func->SetParName(0,"A00");
1,01 	func->SetParName(1,"A10");
 	func->SetParName(2,"A20");
 	func->SetParName(3,"A30");
 	func->SetParName(4,"A40");
  	func->SetParName(5,"A50");
  	func->SetParName(6,"A60");
 	func->SetParName(7,"A70");
 	func->SetParName(8,"A80");
 	func->SetParName(9,"A90");
 	func->SetParName(10,"A100");
 //	func->SetParName(11,"A110");
 //	func->SetParName(12,"A120");
 //	func->SetParName(13,"A130");
 //	func->SetParName(14,"A140");
    }
     
     hist->Fit("func");

}