#include "alfa.h"

int main()
{
    auto data = ReadData("calibeta.txt");
    GraphMaker(data, "Reta de Calibrac#tilde{a}o - #beta;Escala Arbitr#acute{a}ria do Pulser;CHN", "pol1", "AP", 60);
    return 0;
}