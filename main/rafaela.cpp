#include "analise.h"

int main()
{
    auto data = ReadData("rafa.txt");
    for (int i = 0; i < data.size(); i++)
    {
        data[i][2] = 0;
        data[i][3] = 0;
    }

    GraphMaker(data, "", "", "AP", kPink);
    return 0;
}