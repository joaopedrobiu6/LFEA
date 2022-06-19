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
    std::vector<std::vector<float>> data = ReadData("plateau1.txt");

    for (int i = 0; i < data.size(); i++)
    {
        data[i][0] = data[i][0] * 25;
    }
    HistMaker(data, false);

    return 0;
}

void HistMaker(std::vector<std::vector<float>> data, bool wapp)
{
    TApplication app("app", NULL, NULL);
    TCanvas c("canvas", "histogram", 0, 0, 1280, 720);
    TRootCanvas *r = (TRootCanvas *)c.GetCanvasImp();
    r->Connect("CloseWindow()", "TApplication", gApplication, "Terminate()");

    TH1D h("Dados", "Dados", 48, 1, 48 * 25);

    h.SetFillColor(kBlue);
    h.SetMarkerStyle(kFullDiamond);
    h.SetMarkerColor(kBlue);
    h.SetLineColor(1);

    gStyle->SetStatY(0.85);
    gStyle->SetStatX(0.35);

    h.SetTitle("Curva de Resposta do detetor Geiger Muller em Func#tilde{a}o da Tens#tilde{a}o Aplicada");
    h.GetXaxis()->SetTitle("V");
    h.GetYaxis()->SetTitle("Contagens");
    h.Smooth();

    for (int i = 0; i < data.size(); i++)
    {
        h.SetBinContent(i, data[i][1]);
    }

    h.Draw("E1");

    if (wapp == true)
    {

        app.Run("true");
    }
    if (wapp == false)
    {
        c.Update();
        c.SaveAs("plateau1.pdf");
    }
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