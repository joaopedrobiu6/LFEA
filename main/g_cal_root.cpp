#include "alfa.h"

int main()
{
    auto data = ReadData("g_cal_root.txt");
    GraphMaker(data, "Calibrac#tilde{a}o;CHN;Energia [keV]", "pol1", "AP", 60);
}