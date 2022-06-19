#include "alfa.h"

int main()
{
    auto data = ReadData("g_calib2.txt");
    GraphMaker(data, "Calibrac#tilde{a}o 2;CHN;Energia [keV]", "pol1", "AP", 60);
}