#include "hist.h"

int main()
{
    hist2 GM("countsgeiger.txt");
    GM.MakeHist("hist", "m_hist.png", "contagens", "frequencia", 40, 1790, 1935, false, "");
    return 0;
}