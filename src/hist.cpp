#include "hist.h"

hist::hist(std::string filename)
{
    std::fstream rFile(filename); // read mode
    if (rFile.fail())
    {
        std::cout << "Error: Unable to load data file" << std::endl;
        exit(1);
    }

    std::string line;
    while (getline(rFile, line))
    {                               // loop on file lines
        std::stringstream ss(line); // build object stringstream
        float d;
        std::vector<float> temp;
        while (ss >> d)
        { // parse line words to numbers (empty space separated)
            temp.push_back(d);
        }
        ss.clear(); // erase stringstream contents
        data.push_back(temp);
    }
    rFile.close();
};

void hist::dump()
{
    for (int i = 0; i < data.size(); i++)
        for (int j = 0; data[i].size(); j++)
            std::cout << data[i][j] << std::endl;
};

void hist::MCA_Hist(const char *title, const char *x_name, const char *y_name, const char *filename, int n_bin, double min, double max, bool fitopt, bool wapp, const char *expr)
{
    TApplication app("app", NULL, NULL);
    TCanvas c("canvas", "histogram", 0, 0, 1280, 720);
    TRootCanvas *r = (TRootCanvas *)c.GetCanvasImp();
    r->Connect("CloseWindow()", "TApplication", gApplication, "Terminate()");

    TH1D h("h", "h", n_bin, min, max);

    h.SetFillColor(kBlue);
    h.SetLineColor(1);

    h.SetTitle(title);
    h.GetXaxis()->SetTitle(x_name);
    h.GetYaxis()->SetTitle(y_name);

    for (int i = 0; i < data.size(); i++)
    {
        h.SetBinContent(i, data[i][1]);
    }

    h.Draw("E");

    if (fitopt == true)
    {
        TF1 f("f", expr, min, max); // Inserir formula para fazer o fit

        h.Fit("f");

        f.Draw("SAME");
    }

    if (wapp == true)
    {

        app.Run("true");
    }
    if (wapp == false)
    {
        c.Update();
        c.SaveAs(filename);
    }
};

hist2::hist2(std::string filename)
{
    std::fstream rFile(filename); // read mode
    if (rFile.fail())
    {
        std::cout << "Error: Unable to load data file" << std::endl;
        exit(1);
    }

    std::string line;
    while (getline(rFile, line))
    {                               // loop on file lines
        std::stringstream ss(line); // build object stringstream
        float d;
        std::vector<float> temp;
        while (ss >> d)
        { // parse line words to numbers (empty space separated)
            data.push_back(d);
        }
        ss.clear(); // erase stringstream contents
        // data.push_back(temp);
    }
    rFile.close();
};

void hist2::MakeHist(const char *name, const char *filename, const char *x_name, const char *y_name, int a, int b, int d, bool opt, const char *expr)
{
    TCanvas *c = new TCanvas("canvas", "Histogram", 0, 0, 960, 720);

    TH1D *histogram = new TH1D("hist", "hist", a, b, d);
    for (int i = 0; i < data.size(); i++)
        histogram->Fill(data[i]);

    histogram->SetFillColor(kBlue);
    histogram->SetLineColor(1);

    histogram->SetTitle(name);
    histogram->GetXaxis()->SetTitle(x_name);
    histogram->GetYaxis()->SetTitle(y_name);

    if (opt == true)
    {
        std::cout << "\n"
                  << std::endl;
        histogram->Fit(expr);
        std::cout << "\n"
                  << std::endl;
        TF1 *fit = histogram->GetFunction("gaus");
        double chi2 = fit->GetChisquare();
        std::cout << "Chi2: " << chi2 << std::endl;
    }

    histogram->Draw("E1");
    c->Update();
    c->SaveAs(filename);

    delete histogram;
    delete c;
};