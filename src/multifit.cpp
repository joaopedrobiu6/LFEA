#include "multifit.h"

std::vector<std::vector<float>> MFReadData(std::string filename)
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
    {
        // loop on file lines

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

std::vector<std::vector<std::vector<float>>> DataSet(std::vector<std::vector<float>> data1, std::vector<std::vector<float>> data2)
{
    std::vector<std::vector<std::vector<float>>> set;
    set.push_back(data1);
    set.push_back(data2);
    return set;
};

void DataSetDump(std::vector<std::vector<std::vector<float>>> set)
{
    for (int i = 0; i < set.size(); i++)
    {
        std::cout << "\n"
                  << "SET " << i << "\n"
                  << std::endl;
        for (int j = 0; j < set[i].size(); j++)
            std::cout << "(" << set[i][j][0] << ", " << set[i][j][1] << ", " << set[i][j][2] << ", " << set[i][j][3] << ")" << std::endl;
    }
};

void MultiFit(std::vector<std::vector<std::vector<float>>> data)
{
    TApplication app("app", NULL, NULL);
    TCanvas c("canvas", "histogram", 0, 0, 1280, 720);
    TRootCanvas *r = (TRootCanvas *)c.GetCanvasImp();
    r->Connect("CloseWindow()", "TApplication", gApplication, "Terminate()");
};