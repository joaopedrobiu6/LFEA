#include "alfa.h"

int main()
{
    auto data = ReadData("g_co2.txt");
    HistMaker(data, true, 1024, 0, 1023, "Espectro ^{60}Co;CHN;Eventos", "g_c01_n.pdf", "P");
    return 0;
}