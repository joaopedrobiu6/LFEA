#include "Fitter.h"
#include "hist.h"

int main()
{
/*     DataReader sil("si.txt");
    auto data = sil.GetData();

    TCanvas c("canvas", "histogram", 0, 0, 1280, 720);

    TH1D h("h", "h", 1024, 0, 1023);

    h.SetFillColor(kBlue);
    h.SetLineColor(1);

    h.SetTitle("Si Detector with Cs-137");
    h.GetXaxis()->SetTitle("CHN");
    h.GetYaxis()->SetTitle("Events");

    for (int i = 0; i < data.size(); i++)
    {
        h.SetBinContent(i, data[i][1]);
    }
    h.Draw("E");

    c.Update();
    c.SaveAs("sil.pdf");

    DataReader sil2("si_cortado.txt");
    auto data2 = sil2.GetData();

    TCanvas c2("canvas", "histogram", 0, 0, 1280, 720);

    TH1D h2("h", "h", 140, 0, 139);

    h2.SetFillColor(kBlue);
    h2.SetLineColor(1);

    h2.SetTitle("Si Detector with Cs-137");
    h2.GetXaxis()->SetTitle("CHN");
    h2.GetYaxis()->SetTitle("Events");

    for (int i = 0; i < data2.size(); i++)
    {
        h2.SetBinContent(i, data2[i][1]);
    }
    h2.Draw("E");

    c2.Update();
    c2.SaveAs("sil2.pdf"); */

    hist sil("si.txt");
    sil.MCA_Hist("Si Detector with Cs-137 ", "CHN", "Events", "sil.pdf", 1024, 0, 1023, false, false, "");
    hist sil2("si_cortado.txt");
    sil2.MCA_Hist("Si Detector with Cs-137 ", "CHN", "Events", "sil_cortado2.pdf", 141, 0, 140, true, false, "gaus");
    return 0;
}