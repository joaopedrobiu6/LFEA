#include "Fitter.h"

int main()
{
    TF1 *f_1 = new TF1("f", "[0]*exp(-[1]*x[0])*cos(sqrt([2]/[3] - [1]*[1]))", 0, 16);
    f_1->SetParNames("Z0", "l", "K", "m");
    f_1->SetParameters(0.207, 0.13617, 11.648, 0.2004);

    Fitter Fit(f_1);
    Fit.SetDataFromDataReader("docs.txt");

    Fit.DrawFit("title", "asd", "fgh", 64, "asdasd.pdf");

    Fitter Fit2(f_1);
    Fit2.SetDataFromDataReader("docs.txt");

    Fit2.DrawFitErrors("titulo", "eixo x", "eixo y", 860, "teste.pdf");
    // Fit.Print("data");

    delete f_1;
    return 0;
}
