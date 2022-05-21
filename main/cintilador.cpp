#include "../src/hist.h"
#include "../src/Fitter.h"

int main()
{
    // Histogramas dos espectros de energia em CHN
    /* hist cs1("CS1.txt");
    cs1.MCA_Hist("Cs-137 Energy Spectrum", "CHN", "Ocurrences", "CS1.pdf", 1024, 0, 1023, false, false, "");

    hist cs1b("CS1b.txt");
    cs1b.MCA_Hist("Cs-137 Energy Spectrum", "CHN", "Ocurrences", "CS1b.pdf", 993 - 31, 31, 993, false, false, "");

    hist cs2("CS2.txt");
    cs2.MCA_Hist("Cs-137 Energy Spectrum", "CHN", "Ocurrences", "CS2.pdf", 1024, 0, 1023, false, false, "");

    hist co("CO1.txt");
    co.MCA_Hist("Co-60 Energy Spectrum", "CHN", "Events", "Co1.pdf", 1024, 0, 1023, false, false, "");

    hist bg("BG.txt");
    bg.MCA_Hist("BackGround Radiation Energy Spectrum", "CHN", "Events", "Bg.pdf", 1024, 0, 1023, false, false, "");
     */
    /* std::vector<std::vector<float>> vec;
    vec = {{81, 0.74}, {43, 0.36},{765, 7.6}, {385, 3.6}, {404, 4}};

    TF1 *f_1 = new TF1("f", "x[0]*[0] + [1]", 0, 0.5);
    f_1->SetParNames("a", "b");
    f_1->SetParameters(5, 20); 

    Fitter cal(f_1, vec);
    // cal.DrawFitErrors("Calibration", "CHN (MCA)", "Amp[V]", 69, "calib_e.pdf");
    cal.DrawFit("Calibration", "CHN (MCA)", "Amp[V]", 69, "calib.png");*/

    hist cs1c("cs1c.txt");
    cs1c.MCA_Hist("Cs-137 Energy Spectrum", "keV", "Ocurrences", "CS1_keV.pdf", 1024, 0, 3160, false, true, "");


    return 0;
};