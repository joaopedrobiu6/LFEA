#include "alfa.h"

int main()
{
    auto data = ReadData("calib_gamma.txt");
    for (int i = 0; i < data.size(); i++)
    {
        data[i][2] = data[i][2] / 2.35;
    }
    GraphMaker(data, "Calib Gamma", "pol1", "AP", 60);
    return 0;
}