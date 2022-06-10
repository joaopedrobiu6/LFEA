#include "alfa.h"

int main()
{
    auto cal = ReadData("calib2.txt");
    auto data = ReadData("cesiobeta.txt");

    TApplication app("app", NULL, NULL);
    TCanvas c("canvas", "histogram", 0, 0, 1280, 720);
    TRootCanvas *r = (TRootCanvas *)c.GetCanvasImp();
    r->Connect("CloseWindow()", "TApplication", gApplication, "Terminate()");

    TH1D h("Dados", "Dados", 1024, 0, 1023);

    h.SetFillColor(kBlue);
    h.SetMarkerStyle(kFullDiamond);
    h.SetMarkerColor(kBlue);
    h.SetLineColor(1);

    // gStyle->SetStatY(0.85);
    // gStyle->SetStatX(0.35);

    h.SetTitle("Espectro de Energia do Cesio-137;CHN;Energia [keV]");

    for (int i = 0; i < data.size(); i++)
    {
        h.SetBinContent(i, data[i][1]);
    }

    h.Draw("AP");
    c.Update();

    int n = cal.size();
    Double_t x[n];
    Double_t y[n];
    Double_t ex[n];
    Double_t ey[n];

    for (int i = 0; i < cal.size(); i++)
    {
        x[i] = cal[i][0];
        y[i] = cal[i][1];
        ex[i] = cal[i][2];
        ey[i] = cal[i][3];
    }

    TGraphErrors gr(n, x, y, ex, ey);    
    // gr.SetMarkerSize(1);
    gr.SetMarkerStyle(21);

    TF1 *f = new TF1("func", "pol1", x[0], x[cal.size()]);
    f->SetLineColor(kRed + 1);
    f->SetLineWidth(2);

    gr.Fit(f);

    c.Update();
    gr.Draw("SAME");


    app.Run("true");

    return 0;
}