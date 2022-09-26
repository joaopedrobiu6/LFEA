#include "analise.h"

int main()
{
    auto data = ReadData("PET1.txt");
    for (int i = 0; i < data.size(); i++)
        data[i][2] = data[i][2] * 5;
    GraphMaker(data, "Correlac#tilde{o}es Angulares #gamma-#gamma;#theta [^{o}];Rates [cts/s]", "", "AP", 60);

    return 0;
}