#include "alfa.h"

int main()
{
    auto d = ReadData("polonio_energia.txt");
    HistMaker(d, true, 1024, 0, 1023, "Po-210 Energy Spectrum;CHN;Events Recorded", "pol_energy_chn.pdf", "P");
    return 0;
}