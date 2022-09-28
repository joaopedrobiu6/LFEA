#include "analise.h"

int main()
{
    auto data = ReadData("g2_co.txt");
    HistMaker(data, true, 1024, 0, 1023, "Espetro de Energia - ^{60}Co;Canal [CHN];Contagens", "", "P");
    return 0;
}