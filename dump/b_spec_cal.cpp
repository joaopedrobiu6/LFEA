#include "alfa.h"
#include "TLine.h"
#include "TLegend.h"

int main()
{
    auto data = ReadData("cesiobeta.txt");

    // HistMaker(data, true, 200, 0, 199, "Espectro de Energia ^{137}Cs;CHN;Eventos", "", "P");

    TApplication app("app", NULL, NULL);
    TCanvas c("canvas", "histogram", 0, 0, 1280, 720);
    TRootCanvas *r = (TRootCanvas *)c.GetCanvasImp();
    r->Connect("CloseWindow()", "TApplication", gApplication, "Terminate()");

    TH1D h("Dados", "Dados", 200, 0, 199);

    h.SetFillColor(kBlue);
    h.SetMarkerStyle(kFullDiamond);
    h.SetMarkerColor(kBlue);
    h.SetLineColor(1);

    gStyle->SetStatY(0);
    gStyle->SetStatX(0);

    h.SetTitle("Espectro de Energia ^{137}Cs;CHN;Eventos");

    for (int i = 0; i < data.size(); i++)
    {
        h.SetBinContent(i, data[i][1]);
    }
    h.Draw("P");

    auto line = new TLine(116.29, 100, 116.29, 1300);
    line->SetLineColor(kRed);
    line->SetLineWidth(2);
    line->Draw("SAME");

    auto menor = new TLine(113.59, 100, 113.59, 1300);
    menor->SetLineColor(kRed);
    menor->SetLineWidth(1.5);
    menor->SetLineStyle(9);
    menor->Draw("SAME");

    auto maior = new TLine(118.99, 100, 118.99, 1300);
    maior->SetLineColor(kRed);
    maior->SetLineWidth(1.5);
    maior->SetLineStyle(9);
    maior->Draw("SAME");

    TLegend legend(0.45, 0.73, 0.8, 0.8);
    legend.AddEntry(line, "CHN 116.29 - Pico de Convers#tilde{a}o do ^{137}Cs (620 keV)");
    legend.AddEntry(maior, "Incerteza de 2.7 CHN");

    legend.Draw();

    app.Run("true");

    return 0;
}