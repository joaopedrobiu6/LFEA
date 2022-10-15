#include "analise.h"
#include "multifit.h"

int main()
{
    auto data1 = MFReadData("dadosfinais.txt");
    /* for (int i = 0; i < data1.size(); i++)
    {
        data1[i][2] = 0;
        data1[i][3] = 0;
    } */
    auto data2 = MFReadData("max.txt");
    /*  for (int i = 0; i < data1.size(); i++)
    {
        data2[i][2] = 0;
        data2[i][3] = 0;
    } */
    auto set = DataSet(data1, data2);
    MultiFit(set, "Graph;px;I (grey scale)");

    return 0;
}

//([0] * (sin([1]*(x[0]-[2])) * sin([1]*(x[0]-[2]))) / ([1]*(x[0]-[2])*[1]*(x[0]-[2]))) + [3] 