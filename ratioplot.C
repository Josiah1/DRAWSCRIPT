
// Example displaying two histograms and their ratio.
// Author: Olivier Couet
void ratioplot() {
   TH1F *h1 = new TH1F("h1", "", 100, -5, 5);
   TH1F *h2 = new TH1F("h2", "", 100, -5, 5);
   h1->FillRandom("gaus");
   h2->FillRandom("gaus");
	
   auto c=new TCanvas();
   // Upper plot will be in pad1
   TPad *pad1 = new TPad("pad1", "pad1", 0, 0.3, 1, 1.0);
   pad1->SetBottomMargin(0.02); // Upper and lower plot are joined
   pad1->SetGridx();         // Vertical grid
   pad1->Draw();             // Draw the upper pad: pad1
   pad1->cd();               // pad1 becomes the current pad
   h1->Draw();               // Draw h1
   h2->Draw("same");         // Draw h2 on top of h1

   TLegend* lg=new TLegend(0.1,0.1,0.3,0.3);
   lg->SetFillColor(0);
   lg->SetTextFont(133);
   lg->AddEntry("h1","h1","lp");
   lg->AddEntry("h2","h2","lp");
   lg->Draw();

   h1->GetYaxis()->SetLabelSize(0.045);
   h1->GetXaxis()->SetLabelSize(0.);

   // lower plot will be in pad
   c->cd();          // Go back to the main canvas before defining pad2
   TPad *pad2 = new TPad("pad2", "pad2", 0, 0.05, 1, 0.3);
   pad2->SetTopMargin(0);
   pad2->SetBottomMargin(0.3);
   pad2->SetGridx(); // vertical grid
   pad2->Draw();
   pad2->cd();       // pad2 becomes the current pad

   // Define the ratio plot
   TH1F *h3 = (TH1F*)h1->Clone("h3");
   h3->SetLineColor(kBlack);
   h3->SetMinimum(0.8);  // Define Y ..
   h3->SetMaximum(1.35); // .. range
   h3->Sumw2();
   h3->Divide(h2);
   h3->Draw("hist");       // Draw the ratio plot

   // h1 settings
   h1->SetLineColor(kBlue+1);
   h1->SetMarkerStyle(21);
   h1->SetMarkerColor(kBlue+1);

   // Y axis h1 plot settings
   h1->GetYaxis()->SetTitle("Entries");
   h1->GetYaxis()->SetTitleSize(20);
   h1->GetYaxis()->SetTitleFont(133);

   // h2 settings
   h2->SetLineColor(kRed);
   h2->SetMarkerStyle(21);
   h2->SetMarkerColor(kRed);

   // Ratio plot (h3) settings
   // Y axis ratio plot settings
   h3->GetYaxis()->SetTitle("Ratio");
   h3->GetYaxis()->SetNdivisions(505);
   h3->GetYaxis()->SetTitleSize(20);
   h3->GetYaxis()->SetTitleFont(133);
   h3->GetYaxis()->SetLabelFont(133); // Absolute font size in pixel (precision 3)
   h3->GetYaxis()->SetLabelSize(15);

   // X axis ratio plot settings
   h3->GetXaxis()->SetTitle("Energy [MeV]");
   h3->GetXaxis()->SetTitleSize(20);
   h3->GetXaxis()->SetTitleOffset(3.4);
   h3->GetXaxis()->SetTitleFont(133);
   h3->GetXaxis()->SetLabelFont(133); // Absolute font size in pixel (precision 3)
   h3->GetXaxis()->SetLabelSize(15);
}
