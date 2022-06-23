#include "Fitter.h"

int main()
{
    TF1 *f_1 = new TF1("f", "[0]*exp(-(1/[1])*x[0])", 0, 0.5);
    f_1->SetParNames("C", "K");
    f_1->SetParameters(0.6, 0.3);

    Fitter Fit(f_1);
    Fit.SetDataFromDataReader("osc.txt");

    Fit.DrawFit("Pulse", "time", "amp", 64, "osc1.pdf");

    Fitter Fit2(f_1);
    Fit2.SetDataFromDataReader("osc.txt");

    Fit2.DrawFitErrors("Pulse", "time", "amp", 64, "osc2.pdf");
    // Fit.Print("data");

    delete f_1;
    return 0;
}
