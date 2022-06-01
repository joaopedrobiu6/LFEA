#include "Fitter.h"
#include "hist.h"

int main()
{
    hist2 lab1("countsgeiger.txt");
    lab1.MakeHist("Estatística de contagens\nDetetor Geiger Muller", "geigercounts.png", "Contagens", "Frequencia", 20, 1780, 1950, false, "gaus");
    return 0;
}
