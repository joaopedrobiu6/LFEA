#include "alfa.h"

int main()
{
    auto data = ReadData("calib_gamma.txt");
    for (int i = 0; i < data.size(); i++)
    {
        data[i][2] = data[i][2] / 2.35;
    }
        GraphMaker(data, "Calibrac#tilde{a}o 1;CHN;Energy [keV]", "pol1", "AP", kRedBlue);
    return 0;
}