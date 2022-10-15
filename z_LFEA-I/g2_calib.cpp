#include "analise.h"

int main()
{
    auto data = ReadData("g2_calib.txt");
    GraphMaker(data, "Reta de Calibrac#tilde{a}o;CHN;Energia [keV]", "pol1", "AP", kOrange + 7);
}