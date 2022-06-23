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

//Lê os ficheiros txt oganizados em 4 colunas [x y ex ey] separados por espaço e coloca os num vetor de vetores
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

/*
Introduzir:
data (vetor de vetores que obtens usando a função anterior)
wapp (true - abre aplicação do root; false - guarda o ficheiro sem abrir a app; nota: só podes ter um true por ficheiro, não podes abrir mais do que uma app de cada vez)
n - numero de bins
min - primeira bin
max - ultima bin (normalmente para o MCA metes [n=1024, min=0, max=1023])
title - titulo da forma "Titulo;Titulo X;Titulo Y"
savename - nome do ficheiro a guardar só caso metas wapp = false
draw - tipo de desenho que metes no Draw(), por exemplo "AP"
 */
void HistMaker(std::vector<std::vector<float>> data, bool wapp, int n, double min, double max, const char *title, const char *savename, const char *draw)
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

    gStyle->SetStatY(0);
    gStyle->SetStatX(0); 

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

/*
Introduzir:
data (vetor de vetores que obtens usando a função anterior)
title - titulo da forma "Titulo;Titulo X;Titulo Y"
ẽxpr - expressão do Fit, por exemplo "pol1"
draw - tipo de desenho que metes no Draw(), por exemplo "P"
color - cor
 */
void GraphMaker(std::vector<std::vector<float>> data, const char *title, const char *expr, const char *draw, int color)
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
    gr.SetTitle(title);
    gr.SetMarkerColor(color);
    // gr.SetMarkerSize(1);
    gr.SetMarkerStyle(8);

    TF1 *f = new TF1("func", expr, x[0], x[data.size()]);
    f->SetLineColor(kRed + 1);
    f->SetLineWidth(2);

    gr.Fit(f);
    std::cout << "ChiSquared: " << f->GetChisquare() << std::endl;

    c.Update();
    gr.Draw(draw);
    app.Run("true");
};

int main()
{
    //Chama as funções!!!! 
    return 0;
}