#include "alfa.h"
#include "TSpline.h"

int main()
{
    TApplication app("app", NULL, NULL);
    TCanvas c("canvas", "histogram", 0, 0, 1920, 1080);
    TRootCanvas *r = (TRootCanvas *)c.GetCanvasImp();
    r->Connect("CloseWindow()", "TApplication", gApplication, "Terminate()");

    auto data = ReadData("fermi.txt");
    int n = data.size();
    double_t x[n];
    double_t y[n];

    for (int i = 0; i < n; i++)
    {
        x[i] = data[i][0];
        y[i] = data[i][1];
    }

    TSpline3 t("Cubic Spline", x, y, n, 0, 0, 2.4);

    t.SetTitle("Cubic Spline - Func#tilde{a}o de Fermi Modificada;P;G(Z, W)");

    t.SetMarkerStyle(kFullDiamond);
    t.SetMarkerColor(kBlue);
    t.SetMarkerSize(1.5);

    t.SetLineWidth(2);
    t.SetLineColor(kRed + 1);

    /* std::cout << t.Eval(1.483394075) << std::endl;
    std::cout << t.Eval(1.567429173) << std::endl;
    std::cout << t.Eval(1.650177962) << std::endl;
    std::cout << t.Eval(1.731824835) << std::endl;
    std::cout << t.Eval(1.812518711) << std::endl;
    std::cout << t.Eval(1.892381504) << std::endl;
    std::cout << t.Eval(1.971514215) << std::endl;
    std::cout << t.Eval(2.050001391) << std::endl;
    std::cout << t.Eval(2.127914465) << std::endl;
    std::cout << t.Eval(2.205314286) << std::endl;
    std::cout << t.Eval(2.282253073) << std::endl; */

    std::cout << t.Derivative(1.483394075) << std::endl;
    std::cout << t.Derivative(1.567429173) << std::endl;
    std::cout << t.Derivative(1.650177962) << std::endl;
    std::cout << t.Derivative(1.731824835) << std::endl;
    std::cout << t.Derivative(1.812518711) << std::endl;
    std::cout << t.Derivative(1.892381504) << std::endl;
    std::cout << t.Derivative(1.971514215) << std::endl;
    std::cout << t.Derivative(2.050001391) << std::endl;
    std::cout << t.Derivative(2.127914465) << std::endl;
    std::cout << t.Derivative(2.205314286) << std::endl;
    std::cout << t.Derivative(2.282253073) << std::endl;

    t.Draw("LP");
    c.Update();
    app.Run("true");

    return 0;
}