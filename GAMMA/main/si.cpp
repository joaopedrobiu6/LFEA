#include "analise.h"

int main()
{
    auto data = ReadData("si.txt");
    GraphMaker(data, "Espetro de ^{42}Mo (cristal de Si);#theta [^{o}];Counts", "", "AP", 60);
    return 0;
}