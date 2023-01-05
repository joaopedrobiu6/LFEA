#include "analise.h"

int main()
{
    auto data = ReadData("1_5in.txt");
    for (int i = 0; i < data.size(); i++)
        data[i][2] = data[i][2] * 0.2;
    GraphMaker(data, "Correlac#tilde{o}es Angulares #gamma-#gamma - Fonte Deslocada -1.5in;#theta [^{o}];Rates [cts/s]", "", "AP", 60);
    return 0;
}