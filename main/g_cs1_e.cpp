#include "alfa.h"

int main()
{
    auto data = ReadData("g_cs1.txt");
    HistMaker(data, true, 1024, 1.56582 * 0 - 12.6872, 1.56582 * 1023 - 12.6872, "Espectro ^{137}Co;Energia [keV];Eventos", "g_cs1_s.pdf", "P");
    return 0;
}
