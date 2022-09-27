#include "analise.h"

int main()
{
    /* auto data = ReadData("PET1.txt");
    for (int i = 0; i < data.size(); i++)
        data[i][2] = data[i][2] * 5;
    GraphMaker(data, "Correlac#tilde{o}es Angulares #gamma-#gamma;#theta [^{o}];Rates [cts/s]", "", "AP", 60);
 */
    auto data = ReadData("NA22.txt");
    for (int i = 0; i < data.size(); i++)
        data[i][3] = 0;
    HistMaker(data, true, 1024, 0, 1023, "Espetro Na-22;CHN;Counts", "na22.png", "P");
    return 0;
}