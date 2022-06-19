#include "alfa.h"
#include "TLine.h"
#include "TLegend.h"

int main()
{
    auto data = ReadData("talio.txt");

    // HistMaker(data, true, 200, 0, 199, "Espectro de Energia ^{137}Cs;CHN;Eventos", "", "P");

    TApplication app("app", NULL, NULL);
    TCanvas c("canvas", "histogram", 0, 0, 1280, 720);
    TRootCanvas *r = (TRootCanvas *)c.GetCanvasImp();
    r->Connect("CloseWindow()", "TApplication", gApplication, "Terminate()");

    TH1D h("Dados", "Dados", 200, 23.55, 199 * 5.13 + 23.55);

    h.SetFillColor(kBlue);
    h.SetMarkerStyle(kFullDiamond);
    h.SetMarkerColor(kBlue);
    h.SetLineColor(1);

    gStyle->SetStatY(0);
    gStyle->SetStatX(0);

    h.SetTitle("Espectro de Energia ^{204}Tl;Energia [keV];Eventos");

    for (int i = 0; i < data.size(); i++)
    {
        h.SetBinContent(i, data[i][1]);
    }
    h.Draw("P");

    auto menor = new TLine(772.53, 100, 772.53, 1000);
    menor->SetLineColor(kMagenta);
    menor->SetLineWidth(2);
    menor->SetLineStyle(9);
    menor->Draw("SAME");


    auto maior = new TLine(386.265, 100, 386.265, 1000);
    maior->SetLineColor(kRed);
    maior->SetLineWidth(1.5);
    maior->SetLineStyle(9);
    maior->Draw("SAME");

    app.Run("true");

    return 0;
}