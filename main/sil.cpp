#include "Fitter.h"
#include "hist.h"

int main()
{
    hist sil("si.txt");
    sil.MCA_Hist("Si Detector   ", "CHN", "Events", "sil.pdf", 1024, 0, 1023, false, true, "");
    return 0;
}