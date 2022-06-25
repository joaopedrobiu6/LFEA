#include "analise.h"

int main()
{
    auto data = ReadData("g2_cs.txt");
    HistMaker(data, true, 1024, 0, 1023, "Espetro de Energia - ^{137}Cs;Canal [CHN];Contagens", "", "P");
    return 0;
}