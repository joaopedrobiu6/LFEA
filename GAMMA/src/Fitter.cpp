#include "Fitter.h"
/***************************************************************************************************************/
/***************************************************************************************************************/
/***************************************************************************************************************/
/***************************************************************************************************************/
/***************************************SET DATA/INPUT**********************************************************/
/***************************************************************************************************************/
/***************************************************************************************************************/
/***************************************************************************************************************/
/***************************************************************************************************************/
void Fitter::SetFit(TF1 *f_)
{
    f = f_;
};
TF1 *Fitter::GetFit()
{
    return f;
};

std::vector<std::vector<float>> Fitter::GetData()
{
    return data;
}

void Fitter::InputData(std::vector<std::vector<float>> vec)
{
    int N = vec.size();
    data.resize(N);

    for (int i = 0; i < N; i++)
    {
        data[i][0] = vec[i][0];
        data[i][1] = vec[i][1];
        data[i][2] = vec[i][2];
        data[i][3] = vec[i][3];
    }
};

void Fitter::SetData()
{
    std::fstream rFile("data.txt"); // read mode
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

void Fitter::SetDataFromDataReader(std::string filename)
{
    DataReader S(filename);
    int N = S.GetData().size();
    data.resize(N);
    data = S.GetData();
};

/***************************************************************************************************************/
/***************************************************************************************************************/
/***************************************************************************************************************/
/***************************************************************************************************************/
/***************************************DATA DUMP***************************************************************/
/***************************************************************************************************************/
/***************************************************************************************************************/
/***************************************************************************************************************/
/***************************************************************************************************************/

void Fitter::Print(std::string s)
{
    if (s == "data")
    {
        std::cout << "\n******************Data******************" << std::endl;
        for (int i = 0; i < int(data.size()); i++)
        {
            std::cout << "(" << std::setprecision(5) << data[i][0] << ", " << data[i][1] << ")"
                      << "; ex= " << data[i][2] << "; ey= " << data[i][3] << std::endl;
        }
    }
}

/***************************************************************************************************************/
/***************************************************************************************************************/
/***************************************************************************************************************/
/***************************************************************************************************************/
/***************************************FIT AND FIT INFO********************************************************/
/***************************************************************************************************************/
/***************************************************************************************************************/
/***************************************************************************************************************/
/***************************************************************************************************************/
void Fitter::GetFitInfo(TF1 *f_)
{
    std::cout << "\nChi Squared: " << std::setprecision(10) << f_->GetChisquare() << std::endl;
    // std::cout << "\nVariance: " << std::setprecision(10) << f_->Variance() << std::endl;
    std::cout << "Number of Free Parameters: " << f_->GetNumberFreeParameters() << std::endl;
    for (int i = 0; i < f_->GetNumberFreeParameters(); i++)
    {
        std::cout << "[" << i << "]"
                  << "\t" << f_->GetParName(i) << ":\t\t" << std::setprecision(5) << f_->GetParameters()[i] << " +/- " << f_->GetParErrors()[i] << std::endl;
    }
    std::cout << "\n"
              << std::endl;
};

void Fitter::fit()
{
    int n = data.size();
    TGraph *gr1 = new TGraph(n);
    for (int i = 0; i < n; i++)
    {
        gr1->SetPoint(i, data[i][0], data[i][1]);
    }
    gr1->Fit(f, "q");
};

/***************************************************************************************************************/
/***************************************************************************************************************/
/***************************************************************************************************************/
/***************************************************************************************************************/
/***************************************DRAW********************************************************************/
/***************************************************************************************************************/
/***************************************************************************************************************/
/***************************************************************************************************************/
/***************************************************************************************************************/

void Fitter::DrawPoints()
{
    TApplication *app = new TApplication("app", nullptr, nullptr);
    TCanvas *c = new TCanvas("c", "Points", 1280, 720);
    TRootCanvas *r = (TRootCanvas *)c->GetCanvasImp();
    r->Connect("CloseWindow()", "TApplication", gApplication, "Terminate()");
    c->SetGrid();
    c->GetFrame()->SetFillColor(21);
    c->GetFrame()->SetBorderSize(12);
    int n = data.size();
    TGraph *gr = new TGraph();

    for (int i = 0; i < n; i++)
    {
        gr->SetPoint(i, data[i][0], data[i][1]);
    }

    gr->SetTitle("Points");
    gr->GetXaxis()->SetTitle("x");
    gr->GetYaxis()->SetTitle("y");
    gr->SetMarkerColor(kBlue);
    gr->SetMarkerStyle(21);
    gr->Draw("AP");
    //c->SaveAs("fitterpoints.pdf");
    c->Update();
    app->Run();
};

void Fitter::DrawFit(const char *title, const char *x_name, const char *y_name, int color, const char *filename)
{
    // BIU -_-

    // TApplication *app = new TApplication("app", nullptr, nullptr);
    TCanvas *c1 = new TCanvas("c1", "FIT", 1280, 720);

    // TRootCanvas *r = (TRootCanvas *)c1->GetCanvasImp();
    // r->Connect("CloseWindow()", "TApplication", gApplication, "Terminate()");

    c1->SetGrid();
    c1->SetTickx();
    c1->SetTicky();
    c1->SetGridx();
    c1->SetGridy();

    int n = data.size();
    TGraph *gr1 = new TGraph(n);
    gStyle->SetTitleFontSize(0.05);

    for (int i = 0; i < n; i++)
    {
        gr1->SetPoint(i, data[i][0], data[i][1]);
    }

    gr1->Fit(f, "q");
    GetFitInfo(f);

    gr1->SetTitle(title);
    gr1->GetXaxis()->SetTitle(x_name);
    gr1->GetYaxis()->SetTitle(y_name);

    gr1->SetLineColor(69);
    gr1->SetLineWidth(4);
    gr1->SetMarkerColor(color);
    gr1->SetMarkerStyle(21);
    gr1->Draw("AP");
    // c1->Update();
    c1->SaveAs(filename);
    // app->Run();

    delete c1;
    delete gr1;
};

void Fitter::DrawFitErrors(const char *title, const char *x_name, const char *y_name, int color, const char *filename)
{
    // TApplication *app = new TApplication("app", nullptr, nullptr);
    TCanvas *c2 = new TCanvas("c2", "FIT", 1280, 720);

    // TRootCanvas *r = (TRootCanvas *)c1->GetCanvasImp();
    // r->Connect("CloseWindow()", "TApplication", gApplication, "Terminate()");

    c2->SetGrid();
    c2->SetTickx();
    c2->SetTicky();
    c2->SetGridx();
    c2->SetGridy();
    int n = data.size();

    float_t x[n], y[n], ex[n], ey[n];

    for (int i = 0; i < n; i++)
    {
        x[i] = data[i][0];
        y[i] = data[i][1];
        ex[i] = data[i][2];
        ey[i] = data[i][3];
    }

    TGraphErrors *gr1 = new TGraphErrors(n, x, y, ex, ey);
    gStyle->SetTitleFontSize(0.05);

    gr1->Fit(f);
    //GetFitInfo(f);

    gr1->SetTitle(title);
    gr1->GetXaxis()->SetTitle(x_name);
    gr1->GetYaxis()->SetTitle(y_name);

    gr1->SetLineColor(1);
    gr1->SetLineWidth(2);
    gr1->SetMarkerColor(color);
    gr1->SetMarkerStyle(21);
    gr1->Draw("AP");
    // c1->Update();
    c2->SaveAs(filename);
    // app->Run();
    delete c2;
    delete gr1;
};

/***************************************************************************************************************/
/***************************************************************************************************************/
/***************************************************************************************************************/
/***************************************************************************************************************/
/***************************************EXTRAS******************************************************************/
/***************************************************************************************************************/
/***************************************************************************************************************/
/***************************************************************************************************************/
/***************************************************************************************************************/
std::pair<double, double> Fitter::Derivate(double x, double order)
{
    fit();
    std::pair<double, double> v;
    if (order == 1)
    {
        v.first = f->Derivative(x);
        v.second = f->DerivativeError();
    }
    if (order == 2)
    {
        v.first = f->Derivative2(x);
        v.second = f->DerivativeError();
    }
    if (order == 3)
    {
        v.first = f->Derivative3(x);
        v.second = f->DerivativeError();
    }
    return v;
}

double Fitter::Image(double x)
{
    fit();
    return f->Eval(x);
}

double Fitter::Integrate(double min, double max)
{
    fit();
    double value = f->Integral(min, max);
    return value;
}
