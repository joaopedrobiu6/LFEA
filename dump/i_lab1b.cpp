#include "Fitter.h"
#include <iostream>
#include <cmath>
#include "TF1.h"
#include "TH1D.h"
#include "TApplication.h"
#include <fstream>

#include "hist.h"

int main()
{

    /*     TApplication app("app", NULL, NULL);
        TCanvas c("canvas", "Pendulum", 0, 0, 1280, 720);
        TRootCanvas *r = (TRootCanvas *)c.GetCanvasImp();
        r->Connect("CloseWindow()", "TApplication", gApplication, "Terminate()");

        DataReader Data("CS1.txt");
        auto dados = Data.GetData();

        int n_bin = 1023;     // INSERIR
        double minimo = 0;    // inserir canal minimo
        double maximo = 1023; // inserir o canal maximo

        TH1D h("h", "h", n_bin, minimo, maximo);

        double channel, contagem;

        for (int i = 0; i < dados.size(); i++)
        {
            h.SetBinContent(i, dados[i][1]);
        }

        h.Draw("E");

        // TF1 f("f", "gaus", minimo, maximo); // Inserir formula para fazer o fit

        // h.Fit("f");

        // f.Draw("SAME");

        app.Run("true"); */

    hist h("BG.ASC");

    h.MCA_Hist("BG Energy Spectrum", "CHN", "Ocurrences", "BG_hist.pdf", 1024, 0, 1023, false, true, "1");

    return 0;
}