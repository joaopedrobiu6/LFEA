#include "analise.h"
#include "multifit.h"

int main()
{
    /* auto data = ReadData("coinfort.txt");
    GraphMaker(data, "Detec#tilde{a}o de Coicid#hat{e}ncias Fortuitas por Janela Temporal;time [ns];rates [cts/s]", "pol1", "AP", 70); */

    auto data1 = MFReadData("45.txt");
    auto data2 = MFReadData("90.txt");
    auto data = DataSet(data1, data2);

    auto dataset = DataSet(data1, data2);
    DataSetDump(dataset);

    MultiFit(dataset, "Coincid#hat{e}ncias Fortuitas vs. Janela de Detec#tilde{a}o;[ns];Rates [cts/s]");

    return 0;
}