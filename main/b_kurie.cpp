#include "alfa.h"

int main()
{
    auto data = ReadData("kurie.txt");
    GraphMaker(data, "Kurie Plot - Estudo do Limite Cinem#acute{a}tico de ^{204}Tl; Energia [MeV];#frac{1}{W} #sqrt{#frac{N(E)}{G(Z,W)}}", "pol1", "AP", 60);

    return 0;
}