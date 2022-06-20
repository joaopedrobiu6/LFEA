#include "alfa.h"

int main()
{
    auto data = ReadData("g_calib2.txt");
    GraphMaker(data, "Reta de Calibrac#tilde{a}o;CHN;Energia [keV]", "pol1", "AP", kOrange + 7);
}