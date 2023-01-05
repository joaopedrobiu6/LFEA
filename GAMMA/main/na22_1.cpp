#include "analise.h"

int main()
{
    auto data = ReadData("na22_1.txt");
    HistMaker(data, true, 1024, 0, 1023, "Espetro ^{22}Na - Detetor M#acute{o}vel;CHN;Counts", "na22_1.png", "P");
    return 0;
}