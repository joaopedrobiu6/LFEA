#include "hist.h"
#include "Fitter.h"

int main()
{
    // gaus = [Constant]*exp(-0.5*((x-[Mean])/[Sigma])*((x-[Mean])/[Sigma]))

    // histogramas 50 pulsos, números diferentes de BINS
    hist lab1("lab1_pulses.txt");
    lab1.MakeHist("Hist Pulses", "lab1_hist.png", "Amp [V]", "Freq", 20, 0, 1.2, true, "gaus");
    lab1.MakeHist("Hist Pulses", "lab1_hist1.pdf", "Amp [V]", "Freq", 50, 0, 1.2, true, "gaus");
    lab1.MakeHist("Hist Pulses", "lab1_hist2.pdf", "Amp [V]", "Freq", 100, 0, 1.2, true, "gaus");

    // Calibração

    std::vector<std::vector<float>> vec;
    vec = {{307, 15.1}, {762, 39}, {450, 24}};

    TF1 *f_1 = new TF1("f", "[0] + x[0]*[1]", 0, 0.5);
    f_1->SetParNames("b", "a");
    f_1->SetParameters(5, 20);

    Fitter cal(f_1, vec);
    // cal.DrawFitErrors("Calibration", "CHN (MCA)", "Amp[V]", 69, "calib_e.pdf");
    cal.DrawFit("Calibration", "CHN (MCA)", "Amp[V]", 69, "calib.png");

    TF1 *f_MCA = new TF1("f", "gaus", 0, 0.5);
    f_MCA->SetParNames("Const", "Mean", "Sigma");
    f_MCA->SetParameters(700, 120, 100);

    Fitter MCA1(f_MCA);
    MCA1.SetDataFromDataReader("mca1.txt");
    MCA1.DrawPoints();
    MCA1.DrawFit("MCA no amp", "CHN", "Ocurrences", 65, "MCA1_cpp.png");

    TF1 *f_MCA2 = new TF1("f", "gaus", 0, 0.5);
    f_MCA2->SetParNames("Const", "Mean", "Sigma");
    f_MCA2->SetParameters(700, 150, 100);

    Fitter MCA2(f_MCA2);
    MCA2.SetDataFromDataReader("mca2.txt");
    MCA2.DrawFitErrors("MCA Amp", "CHN", "Ocurrences", 65, "MCA2_cpp.png");

    // aplicando a relação da calibração:
    DataReader mca1_data("mca1.txt");
    auto MCA1_d = mca1_data.GetData();

    for (int i = 0; i < MCA1_d.size(); i++)
    {
        MCA1_d[i][0] = 0.051805 * MCA1_d[i][0] - 0.19727;
    }

    DataReader mca2_data("mca2.txt");
    auto MCA2_d = mca2_data.GetData();

    for (int i = 0; i < MCA2_d.size(); i++)
    {
        MCA2_d[i][0] = 0.051805 * MCA2_d[i][0] - 0.19727;
    }

    // FITS CALIBRADOS
    TF1 *f_MCA1_calib = new TF1("f", "gaus", 0, 0.5);
    f_MCA1_calib->SetParNames("Const", "Mean", "Sigma");
    f_MCA1_calib->SetParameters(35, 6, 5);

    Fitter MCA1_calib(f_MCA1_calib, MCA1_d);
    MCA1_calib.DrawFit("MCA no amp calib", "[V]", "Ocurrences", 65, "MCA1_calib.png");

    TF1 *f_MCA2_calib = new TF1("f", "gaus", 0, 0.5);
    f_MCA2_calib->SetParNames("Const", "Mean", "Sigma");
    f_MCA2_calib->SetParameters(35, 6, 5);

    Fitter MCA2_calib(f_MCA2_calib, MCA2_d);
    MCA2_calib.DrawFitErrors("MCA Amp calib", "[V]", "Ocurrences", 65, "MCA2_calib.png");

    return 0;
}

// y = 0.051805x - 0.19727