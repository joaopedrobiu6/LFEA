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
            data.push_back(d);
        }
        ss.clear(); // erase stringstream contents
        // data.push_back(temp);
    }
    rFile.close();
};

/* void hist::DataInput(std::string filename)
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
}; */

void hist::MakeHist(const char *name, const char *filename, const char *x_name, const char *y_name, int a, int b, int d, bool opt, const char *expr)
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

    histogram->Draw("same");
    c->Update();
    c->SaveAs(filename);

    delete histogram;
    delete c;
};

void hist::dump()
{
    for (int i = 0; i < data.size(); i++)
        std::cout << data[i] << std::endl;
};
