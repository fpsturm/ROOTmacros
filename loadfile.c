{
char filename[64];
//sprintf(filename,"C:/Users/fpsturm/GoogleDrive/Data/ROOTFiles/H2p_scan_m20top70_Tpresort.root");
//sprintf(filename,"S:/MISTERS/Data/ROOTFiles/He_Alfilter_Ar_RTOFPOS_presort.root");
//TFile* file1 = new TFile("C:/Users/fpsturm/GoogleDrive/Data/ROOTFiles/CH2p_scan_m100top400_ana.root");
//TFile* file1 = new TFile("C:/Users/fpsturm/GoogleDrive/Data/ROOTFiles/CH2p_scan_m100top400_presort.root");
//TFile* file1 = new TFile("C:/Users/fpsturm/GoogleDrive/Data/ROOTFiles/H2p_scan_m20top70_Tpresort.root");
//TFile* file2 = new TFile("C:/Users/fpsturm/GoogleDrive/Data/ROOTFiles/H2p_scan_m20top70_Tana.root");
//TFile* file1 = new TFile("C:/Users/fpsturm/GoogleDrive/Data/ROOTFiles/H2p_scan_m50top300_Tpresort.root");
//TFile* file1 = new TFile("C:/Users/fpsturm/GoogleDrive/Data/ROOTFiles/H2p_scan_m50top300_Tana.root");
//TFile* file1 = new TFile("C:/Users/fpsturm/GoogleDrive/Data/ROOTFiles/H2p_scan_m50top300_Tana_pos.root");
//TFile* file1 = new TFile("C:/Users/fpsturm/GoogleDrive/Data/ROOTFiles/H2p_scan_m2top2_Tpresort.root");
//TFile* file1 = new TFile("C:/Users/fpsturm/GoogleDrive/Data/ROOTFiles/H2p_scan_m2top2_Tpresort_part1of2.root");
//TFile* file2 = new TFile("C:/Users/fpsturm/GoogleDrive/Data/ROOTFiles/H2p_scan_m2top2_Tpresort_part2of2.root");
//TFile* file1 = new TFile("C:/Users/fpsturm/GoogleDrive/Data/ROOTFiles/H2p_scan_m2top2_Tana.root");
//TFile* file1 = new TFile("C:/Users/fpsturm/GoogleDrive/Data/ROOTFiles/H2_ArFilter_scan_m100p300_1cut.root");
//TFile* file1 = new TFile("C:/Users/fpsturm/GoogleDrive/Data/ROOTFiles/H2_ArFilter_scan_m100p300_2cut.root");
//TFile* file1 = new TFile("C:/Users/fpsturm/GoogleDrive/Data/ROOTFiles/H2_ArFilter_scan_m100p300_3cut.root");
//TFile* file1 = new TFile("C:/Users/fpsturm/GoogleDrive/Data/ROOTFiles/H2_ArFilter_scan_m100p300_4cut.root");
//TFile* file1 = new TFile("C:/Users/fpsturm/GoogleDrive/Data/ROOTFiles/H2_ArFilter_scan_m100p300_4cut_shift.root");
//TFile* file1 = new TFile("C:/Users/fpsturm/GoogleDrive/Data/ROOTFiles/H2_ArFilter_scan_m100p300_6cut.root");
//TFile* file1 = new TFile("C:/Users/fpsturm/GoogleDrive/Data/ROOTFiles/H2_ArFilter_scan_m100p300_Tana_6.root");
//TFile* file1 = new TFile("C:/Users/fpsturm/GoogleDrive/Data/ROOTFiles/H2_ArFilter_scan_m100p300_Tana_all.root");
//TFile* file1 = new TFile("C:/Users/fpsturm/GoogleDrive/Data/ROOTFiles/H2_ArFilter_scan_m100p300_Tana_all_PZNEG.root");
//TFile* file1 = new TFile("C:/Users/fpsturm/GoogleDrive/Data/ROOTFiles/H2_ArFilter_MgF2MMC_scan_m100p300_Tana_1.root");
//TFile* file1 = new TFile("C:/Users/fpsturm/GoogleDrive/Data/ROOTFiles/H2_ArFilter_scan_m100p300_sept_pres.root");
//TFile* file1 = new TFile("C:/Users/fpsturm/GoogleDrive/Data/ROOTFiles/H2_ArFilter_scan_m100p300_sept_pres_2_test.root");
//TFile* file1 = new TFile("C:/Users/fpsturm/GoogleDrive/Data/ROOTFiles/C2H4_open_0924_pres.root");
//TFile* file1 = new TFile("C:/Users/fpsturm/GoogleDrive/Data/ROOTFiles/C2H4_open_0924_test.root");
//TFile* file1 = new TFile("C:/Users/fpsturm/GoogleDrive/Data/ROOTFiles/O2_noFilter_hellfire_pres.root");
TFile* file1 = new TFile("C:/Users/fpsturm/GoogleDrive/Data/ROOTFiles/O2_noFilter_hellfire_Dana.root");
//TFile* file1 = new TFile("C:/Users/fpsturm/GoogleDrive/Data/ROOTFiles/O2_noFilter_hellfire_Mana.root");
//TFile* file1 = new TFile("C:/Users/fpsturm/GoogleDrive/Data/ROOTFiles/C2H4_open_0924_Dana.root");
//TFile* file1 = new TFile("C:/Users/fpsturm/GoogleDrive/Data/ROOTFiles/O2_noFilter_pres.root");
//TFile* file1 = new TFile("C:/Users/fpsturm/GoogleDrive/Data/ROOTFiles/O2_Tin_OpOp_Mana.root");
TFile* file2 = new TFile("C:/Users/fpsturm/GoogleDrive/Data/ROOTFiles/O2_Tin_OpOp_Dana.root");
//TFile* file1 = new TFile("C:/Users/fpsturm/GoogleDrive/Data/ROOTFiles/O2_Tin_pres.root");
//TFile* file1 = new TFile("C:/Users/fpsturm/GoogleDrive/Data/ROOTFiles/O2_Tin_OpOp_Iana_nc.root");

//TFile* file1 = new TFile(filename)
file1->cd();
sprintf(filename,"x");
sprintf("---> File %s has been loaded <---",filename);
}