#include "analise.h"
#include "multifit.h"

int main()
{
    auto data = ReadData("90.txt");
    GraphMaker(data, "Detec#tilde{a}o de Coicid#hat{e}ncias Fortuitas por Janela Temporal 90^{o};time [ns];rates [cts/s]", "pol1", "AP", 70);
    return 0;
}