#ifndef __hist__
#define __hist__

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

#include "DataReader.h"

class hist
{
public:
    hist(std::string);
    ~hist() = default;

    // void DataInput(std::string); // ler dados usando DataReader.h
    void MakeHist(const char *, const char *, const char *, const char *, int, int, int, bool, const char*);
    /* Título, Nome do PDF, Nome do eixo xx, Nome do Eixo yy, Número de bins, Valor min dos bins, valor max dos bins */
    void fit();

    void dump();

protected:
    std::vector<float> data;
    //TH1D *histogram;
};

#endif
