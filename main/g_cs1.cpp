#include "alfa.h"

int main()
{
    auto data = ReadData("g_cs1.txt");
    HistMaker(data, true, 1024, 0, 1023, "Espectro ^{137}Cs;CHN;Eventos", "g_cs1_n.pdf", "P");
    return 0;
}