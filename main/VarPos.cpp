#include "analise.h"

int main()
{
    auto data1 = ReadData("1in.txt");
    auto data15 = ReadData("1_5in.txt");

    TApplication app("app", NULL, NULL);
    TCanvas c("canvas", "histogram", 0, 0, 1280, 720);
    TRootCanvas *r = (TRootCanvas *)c.GetCanvasImp();
    r->Connect("CloseWindow()", "TApplication", gApplication, "Terminate()");

    int n = data1.size();
    Double_t x[n];
    Double_t y[n];
    Double_t ex[n];
    Double_t ey[n];

    for (int i = 0; i < data1.size(); i++)
    {
        x[i] = data1[i][0];
        y[i] = data1[i][1];
        ex[i] = data1[i][2];
        ey[i] = data1[i][3];
        std::cout << x[i] << "; " << y[i] << "; " << ex[i] << "; " << ey[i] << std::endl;
    }

    int n1 = data15.size();
    Double_t x15[n1];
    Double_t y15[n1];
    Double_t ex15[n1];
    Double_t ey15[n1];

    TGraphErrors *gr = new TGraphErrors(n, x, y, ex, ey);

    gr->SetTitle("Correlac#tilde{o}es Angulares;Pos Ang [^{o}];Rates [cts/s]");
    gr->SetMarkerColor(70);
    gr->SetMarkerSize(1);
    gr->SetMarkerStyle(8);

    for (int i = 0; i < data15.size(); i++)
    {
        x15[i] = data15[i][0];
        y15[i] = data15[i][1];
        ex15[i] = data15[i][2];
        ey15[i] = data15[i][3];
        std::cout << x15[i] << "; " << y15[i] << "; " << ex15[i] << "; " << ey15[i] << std::endl;
    }

    TGraphErrors *gr15 = new TGraphErrors(n1, x15, y15, ex15, ey15);
    gr15->SetTitle("Correlac#tilde{o}es Angulares;Pos Ang [^{o}];Rates [cts/s]");
    gr15->SetMarkerColor(60);
    gr15->SetMarkerSize(1);
    gr15->SetMarkerStyle(8);

    gr15->GetXaxis()->SetRangeUser(-50, 40);
    gr15->GetYaxis()->SetRangeUser(0, 140);

    auto *MG = new TMultiGraph();
    MG->Add(gr);
    MG->Add(gr15);
    c.Update();
    MG->Draw("AP");
    app.Run("true");

    return 0;
}