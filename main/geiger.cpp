#include "Fitter.h"
#include "hist.h"
#include "TAxis.h"
#include "TROOT.h"
#include "TF1.h"
#include "TH2F.h"
#include "TApplication.h"
#include "TRootCanvas.h"
#include <TROOT.h>
#include <TStyle.h>
#include "TH1F.h"
#include "TH1.h"
#include "TCanvas.h"
#include "TGraph.h"
#include "TDirectory.h"
#include "TFrame.h"
#include "TGraphErrors.h"

#include <vector>
#include <iostream>
#include <sstream> // std::stringstream
#include <fstream> // std::fstream
#include <iomanip>

void HistMaker(std::vector<std::vector<float>> data, bool wapp);
std::vector<std::vector<float>> ReadData(std::string filename);

int main()
{
    std::vector<std::vector<float>> data = ReadData("gmdist.txt");
    HistMaker(data, true);
    /* hist2 lab1("countsgeiger.txt");
    lab1.MakeHist("Estatística de contagens\nDetetor Geiger Muller", "geigercounts.png", "Contagens", "Frequencia", 20, 1780, 1950, false, "gaus");
     */
    return 0;
}

void HistMaker(std::vector<std::vector<float>> data, bool wapp)
{
    TApplication app("app", NULL, NULL);
    TCanvas c("canvas", "histogram", 0, 0, 1280, 720);
    TRootCanvas *r = (TRootCanvas *)c.GetCanvasImp();
    r->Connect("CloseWindow()", "TApplication", gApplication, "Terminate()");

    int n = data.size();
    Double_t x[n];
    Double_t y[n];
    Double_t ex[n];
    Double_t ey[n];
    for (int i = 0; i < data.size(); i++)
    {
        x[i] = data[i][0];
        y[i] = data[i][1];
        ex[i] = data[i][2];
        ey[i] = data[i][3];
    }

    TGraphErrors gr(n, x, y, ex, ey);
    gr.SetTitle("Cs-137 - Variacao das\ncontagens com a distancia;Dist. [m];Contagens");
    gr.SetMarkerColor(4);
    gr.SetMarkerStyle(21);

    TF1 *f = new TF1("func", "[0]/(x*x) + [1]", 0, 6);
    gr.Fit(f);
    
    c.Update();
    gr.Draw("AP");
    app.Run("true");

    /*         h.SetFillColor(kBlue);
        h.SetMarkerStyle(kFullDiamond);
        h.SetMarkerColor(kBlue);
        h.SetLineColor(1);

        gStyle->SetStatY(0.85);
        gStyle->SetStatX(0.35);

        h.SetTitle("Variacao com a Distancia");
        h.GetXaxis()->SetTitle("dist [m]");
        h.GetYaxis()->SetTitle("Contagens");
        h.Smooth();

        for (int i = 0; i < data.size(); i++)
        {
            j
            h.SetBinContent(data[i][0], data[i][1]);
        }

        h.Draw("E1");

        if (wapp == true)
        {

            app.Run("true");
        }
        if (wapp == false)
        {
            c.Update();
            c.SaveAs("gmhist.pdf");
        } */
};

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