#include "multifit.h"
#include "analise.h"

int main()
{
    auto data1 = MFReadData("1in.txt");
    auto data2 = MFReadData("1_5in.txt");
    auto dataset = DataSet(data1, data2);
    DataSetDump(dataset);
    MultiFit(dataset, 0, 150, -40, 40, "Correlac#tilde{o}es Angulares com a Fonte Deslocada;#theta [^{o}];Rates [cts/s]");
    return 0;
}