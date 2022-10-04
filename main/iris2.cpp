#include "analise.h"
#include "multifit.h"

int main()
{
    
    auto data2 = ReadData("maxx.txt");
    GraphMaker(data2, "", "[0] * (sin(([1]/c)*(x[0]-[2])) * sin(([1]/c)*(x[0]-[2]))) / (([1]/c)*(x[0]-[2])*([1]/c)*(x[0]-[2])) + [3]", "AP", 69);

    return 0;
}