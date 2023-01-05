#include "analise.h"

int main()
{
    auto data = ReadData("na22_2.txt");
    HistMaker(data, true, 1024, 0, 1023, "Espetro ^{22}Na - Detetor Fixo;CHN;Counts", "na22_2.png", "P");
    return 0;
}