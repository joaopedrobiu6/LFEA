#include "analise.h"
#include "multifit.h"

int main()
{
    auto data = ReadData("45.txt");
    GraphMaker(data, "Detec#tilde{a}o de Coicid#hat{e}ncias Fortuitas por Janela Temporal -45^{o};time [ns];rates [cts/s]", "pol1", "AP", 70);
    return 0;
}