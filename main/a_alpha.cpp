#include "alfa.h"

int main()
{
    auto d = ReadData("americio.txt");
    /* for (int i = 0; i < d.size(); i++)
    {
        d[i][0] = 0.00177 * d[i][0] + 4.63800;
    }

    auto c = new TCanvas("Example", "", 0, 0, 1500, 1500);
    c->SetGrid();

    // Convert vec to array to use in TGraph
    float ax[d.size()];
    float ay[d.size()];

    for (int i = 0; i < d.size(); i++)
    {
        ax[i] = d[i][0];
        ay[i] = d[i][1];
    }

    auto g = new TGraph(d.size(), ax, ay);
    g->SetTitle("Plot example");
    g->SetMarkerStyle(8);
    g->SetMarkerSize(0.8);

    auto f4 = new TF1("Three gaussian fit", "[0]*exp(-0.5*((x-[1])/[2])*((x-[1])/[2])) + [3]*exp(-0.5*((x-[4])/[5])*((x-[4])/[5])) + [6]*exp(-0.5*((x-[7])/[8])*((x-[7])/[8]))", ax[0], ax[d.size()]);
    f4->SetParameters(141.85, 59.2324, 3.51108, 251.659, 42.6864, 5.93927, 100, 50, 10);
    g->Fit(f4);
    g->Draw("AP");
    c->SaveAs("fit.png");
 */
    HistMaker(d, true, 1024, 4.63800, 0.00177 * 1023 + 4.63800, "Espectro de Energia de uma fonte emissora #alpha;Energia [MeV];Eventos Detetados", "americio_chn.pdf", "P");
    
    return 0;
}

//[0]*exp(-0.5*((x-[1])/[2])*((x-[1])/[2])) + [3]*exp(-0.5*((x-[4])/[5])*((x-[4])/[5]))