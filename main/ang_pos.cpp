#include "analise.h"

int main()
{
    auto data = ReadData("ang_pos.txt");
    GraphMaker(data, "Convers#tilde{a}o #theta vs. xx;[in];#theta [^{o}]", "pol1", "AP", 80);
    return 0;
}