#include "analise.h"

int main()
{
    auto data = ReadData("coinfort.txt");
    GraphMaker(data, "Detec#tilde{a}o de Coicid#hat{e}ncias Fortuitas por Janela Temporal;time [ns];rates [cts/s]", "pol1", "AP", 70);
    return 0;
}