#include "alfa.h"

int main()
{
    auto data = ReadData("calib_gamma.txt");

    GraphMaker(data, "Calibrac#tilde{a}o 1;CHN;Energy [keV]", "pol1", "AP", kRedBlue);
    return 0;
}