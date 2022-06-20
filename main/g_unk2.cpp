#include "alfa.h"

int main()
{
    auto data = ReadData("unk2.txt");
    HistMaker(data, true, 1024, 1.68 * 0 - 13.95, 1.68 * 1023 - 13.95, "Espectro;Energia [kwV];Eventos", "g_cs2_n.pdf", "P");
    return 0;
}