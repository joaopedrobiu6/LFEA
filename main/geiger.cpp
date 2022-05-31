#include "Fitter.h"
#include "hist.h"

int main()
{
    //Primeira parte do geiger!
    // no geiger.txt meter as terceiras e quartas colunas do excel + os erros que nao estão lá ainda
    hist Geiger("geiger.txt");
    Geiger.MCA_Hist("Histogram - Geiger Detector", "V", "Events", "geiger.pdf", int #, int min, int max, false, false, "");
    return 0;
}
