#include "alfa.h"

int main()
{
    auto dados = ReadData("fialho");
    GraphMaker(dados, "fialho", "pol1", "AP", 60);
    return 0;
}