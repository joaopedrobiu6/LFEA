#include "analise.h"

int main()
{
    auto data = ReadData("fitar_erro.txt");
    GraphMaker(data, "", "pol1", "AP", kOrange + 7);
}