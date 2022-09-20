#include "analise.h"

int main()
{
    auto data = ReadData("PET1.txt");
    GraphMaker(data, "Correlac#tilde{o}es Angulares #gamma-#gamma;#theta [^{o}];Rates [cts/s]", "", "AP", 60);

    return 0;
}