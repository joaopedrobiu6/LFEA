#include "alfa.h"

std::vector<std::vector<float>> ReadData(std::string filename)
{
    std::vector<std::vector<float>> data;
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

    return data;
};

void HistMaker(std::vector<std::vector<float>> data, bool wapp, int n, double min, double max, const char *title, const char *savename, const char* draw)
{
    TApplication app("app", NULL, NULL);
    TCanvas c("canvas", "histogram", 0, 0, 1280, 720);
    TRootCanvas *r = (TRootCanvas *)c.GetCanvasImp();
    r->Connect("CloseWindow()", "TApplication", gApplication, "Terminate()");

    TH1D h("Dados", "Dados", n, min, max);

    h.SetFillColor(kBlue);
    h.SetMarkerStyle(kFullDiamond);
    h.SetMarkerColor(kBlue);
    h.SetLineColor(1);

    // gStyle->SetStatY(0.85);
    // gStyle->SetStatX(0.35);

    h.SetTitle(title);

    for (int i = 0; i < data.size(); i++)
    {
        h.SetBinContent(i, data[i][1]);
    }

    h.Draw(draw);

    if (wapp == true)
    {
        app.Run("true");
    }
    if (wapp == false)
    {
        c.Update();
        c.SaveAs(savename);
    }
};
