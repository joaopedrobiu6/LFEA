#include "analise.h"
#include "TCanvas.h"
#include "TStyle.h"
#include "TH1.h"
#include "TGaxis.h"
#include "TRandom.h"

int main()
{
    auto data = ReadData("g2_background.txt");
    // HistMaker(data, true, 1024, 0, 1023, "Espetro da Radiac#{a}o de Fundo;Canal[CHN];Contagens", "", "P");

    TApplication app("app", NULL, NULL);
    TCanvas c("canvas", "histogram", 0, 0, 1280, 720);
    TRootCanvas *r = (TRootCanvas *)c.GetCanvasImp();
    r->Connect("CloseWindow()", "TApplication", gApplication, "Terminate()");

    TH1D h("Dados", "Dados", 1024, 0, 1023);

    h.SetFillColor(kBlue);
    h.SetMarkerStyle(kFullDiamond);
    h.SetMarkerColor(kBlue);
    h.SetLineColor(1);

    gStyle->SetOptStat(kFALSE);

    h.SetTitle("Espetro da Radiac#tilde{a}o de Fundo;Canal[CHN];Contagens");

    for (int i = 0; i < data.size(); i++)
    {
        h.SetBinContent(i, data[i][1]);
    }

    h.Draw("P");
    c.Update();

    gStyle->SetOptStat(kFALSE);

    /* TGaxis *axis = new TGaxis(gPad->GetUxmin(), gPad->GetUymax(),
                              gPad->GetUxmax(), gPad->GetUymax(), 2.04 * 0 - 15.54, 2.04 * 1023 - 15.54, 510, "-");
    /* axis->SetLineColor(kBlack);
    axis->SetLabelColor(kBlack); 
    axis->SetTitle("Energia [keV]");
    axis->SetLabelSize(0.03);
    axis->SetTitleSize(0.03);
    axis->SetTitleOffset(-1.2);
    axis->Draw(); */

    app.Run("true");

    return 0;
}