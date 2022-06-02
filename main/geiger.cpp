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

void GraphMaker(std::vector<std::vector<float>> data, bool wapp);
std::vector<std::vector<float>> ReadData(std::string filename);

int main()
{
    std::vector<std::vector<float>> data = ReadData("gmdist.txt");
    GraphMaker(data, true);
    return 0;
}

void GraphMaker(std::vector<std::vector<float>> data, bool wapp)
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
        ex[i] = sqrt(0.015875 * 0.015875 + data[i][0] * data[i][0]) - data[i][0];
        ey[i] = data[i][3];
    }

    TGraphErrors gr(n, x, y, ex, ey);
    gr.SetTitle("Cs-137 - Variac#tilde{a}o da taxa de contagens com a dist#hat{a}ncia;Dist. [m];Taxa de Contagens");
    gr.SetMarkerColor(4);
    gr.SetMarkerStyle(21);

    TF1 *f = new TF1("func", "[0]*(1/(x*x)) + [1]", 0, 6);
    gr.Fit(f);

    c.Update();
    gr.Draw("AP");
    app.Run("true");
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