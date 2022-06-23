#include "analise.h"

int main()
{
    auto data = ReadData("g2_cs.txt");
    HistMaker(data, true, 1024, 2.04 * 0 - 15.54, 2.04 * 1023 - 15.54, "Espetro de Energia - ^{137}Cs;Energia [keV];Contagens", "", "P");
    return 0;
}