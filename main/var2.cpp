#include "multifit.h"
#include "analise.h"

int main()
{
    auto data1 = MFReadData("1in.txt");
    auto data2 = MFReadData("1_5in.txt");
    auto dataset = DataSet(data1, data2);
    DataSetDump(dataset);
    return 0;
}