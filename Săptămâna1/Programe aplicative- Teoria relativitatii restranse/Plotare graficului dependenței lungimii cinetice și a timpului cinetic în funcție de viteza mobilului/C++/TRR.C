#include "TCanvas.h"
#include "TROOT.h"
#include "TF1.h"
#include "TLegend.h"

void TRR(){
   
   TCanvas *c1 = new TCanvas("c1","Timpul cinetic in functie de viteza mobilului... ");
   c1->SetFillColor(42);
   c1->SetGrid();
   c1->Divide(2,1);
   float t0, l0, v;
   
   cout<<"Timpul de repaus(in s)- masurat in SR al mobilului: "; cin>>t0;
   cout<<"Lungimea de repaus(in s) a corpului- masurat in SR al mobilului: "; cin>>l0;
   
   cout<<"Viteza mobilului in MRU(m/s): "; cin>>v;
  
  //grafic1 
   double x[200], y[200];
   int n = 100;
   
   for (int i=0; i<n; i++) {
     x[i] = 0.01*i;
     y[i] = t0/sqrt(1-x[i]);
   }
   
   TGraph* gr = new TGraph(n, x, y);
   gr->SetLineColor(kBlue+2);
   gr->SetTitle(" t_cinetic = f(v^2/c^2); v^2/c^2(la limita v=c); t_cinetic[s]");
   gr->SetLineWidth(3);
   gr->SetLineColor(kRed);

//grafic 2
 double x2[200], y2[200];
   int n2 = 100;
   
   for (int i2=0; i2<n2; i2++) {
     x2[i2] = 0.01*i2;
     y2[i2] = l0*sqrt(1-x[i2]);
   }
   
   TGraph* gr2 = new TGraph(n2, x2, y2);
   gr2->SetLineColor(kBlue+2);
   gr2->SetTitle(" l_cinetica = f(v^2/c^2); v^2/c^2(la limita v=c); l_cinetica[m]");
   gr2->SetLineWidth(3);
   gr2->SetLineColor(kBlue);

TF1 f("Linear law","[0]+x*[1]",.5,10.5);
    // Let's make the function line nicer
    f.SetLineColor(kRed); f.SetLineStyle(2);
    
   c1->cd(1);
   gr->Draw();
   f.DrawClone("Same");
   
   TGraph graph = TGraph(1);
 
 //set three points of the graph
   graph.SetPoint(0, 2.0, 2.1);
   graph.SetMarkerStyle(21);
   graph.SetMarkerSize(1);
   
   graph.Draw("P");
      
   c1->cd(2);
   gr2->Draw();
}
