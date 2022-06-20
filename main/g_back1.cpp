#include "alfa.h"

int main()
{
    auto data = ReadData("g_back1.txt");
    HistMaker(data, true, 1024, 1.56130 * 0 - 11.8719, 1.56130 * 1023 - 11.8719, "Radiação de Fundo;Energia [keV];Eventos", "g_cs2_n.pdf", "P");
    return 0;
}