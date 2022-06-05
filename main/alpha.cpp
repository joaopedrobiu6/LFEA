#include "alfa.h"

int main()
{
    auto d = ReadData("americio.txt");
    HistMaker(d, true, 1024, 4.63800, 0.00177 * 1023 + 4.63800, "Espectro de Energia de uma fonte emissora #alpha;Energia [MeV];Eventos Detetados", "americio_chn.pdf", "P");
    return 0;
}