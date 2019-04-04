void compare(){

	TFile* f=new TFile("result_GdLS_normal.root","READ");
	TH1D* hUODep=(TH1D*)f->Get("hUODep");
	TH1D* hmyDep=(TH1D*)f->Get("hmyDep");
	TH1D* hcom=new TH1D("hcom","",3600,0,36);

	auto c1=new TCanvas();
	hUODep->Rebin(10);
	hmyDep->Rebin(10);
	hcom->Rebin(10);
	hUODep->GetXaxis()->SetTitle("Prompt + Delayed Energy [MeV]");
	hUODep->GetXaxis()->SetRangeUser(0,20);
	hmyDep->GetXaxis()->SetRangeUser(0,20);
	TLegend* lg=new TLegend();
	lg->SetTextFont(132);
	lg->SetFillColor(0);
	lg->AddEntry(hUODep,"Unobservable Statistic","l");
	lg->AddEntry(hmyDep,"Input of Toy Model","l");
	gPad->SetLogy();
	hUODep->SetLineColor(2);
	hmyDep->SetLineColor(4);
    	TRatioPlot* rp1=new TRatioPlot(hUODep,hmyDep);
	rp1->SetH1DrawOpt("hist");
	rp1->SetH2DrawOpt("hist");
    	rp1->Draw();
	rp1->SetGraphDrawOpt("L");
   	rp1->SetSeparationMargin(0.0);
	rp1->GetLowerRefGraph()->SetLineColor(4);
	rp1->GetLowerRefGraph()->SetMarkerColor(4);
	rp1->GetLowerRefGraph()->SetMarkerStyle(6);
	rp1->GetLowerRefGraph()->SetMarkerSize(1);
	rp1->GetLowerRefYaxis()->SetRangeUser(0,2);
	rp1->GetLowYaxis()->SetNdivisions(2);
    	rp1->GetLowerRefYaxis()->SetTitle("Ratio");
    	rp1->GetUpperRefYaxis()->SetTitle("Entries");
	rp1->SetSeparationMargin(0.04);
	rp1->GetUpperPad()->cd();
	lg->Draw();
    	c1->Update();
		
}
