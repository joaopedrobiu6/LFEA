#include "alfa.h"

int main()
{
    auto data = ReadData("calib2.txt");
    GraphMaker(data, "Reta de Calibrac#tilde{a}o - #beta;CHN;Energy [keV]", "pol1", "AP", 60);

    return 0;
}