#include "analise.h"

int main()
{
    auto data = ReadData("grupo5B.txt");

    GraphMaker(data, "Evoluc#tilde{a}o do #hat{A}ngulo S#acute{o}lido;Raio [mm];Rate [counts s^{-1}]", "[0]*(1-[1]/(sqrt([2]+x*x)))", "AP", kOrange + 7);
}