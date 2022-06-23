#include "analise.h"

int main()
{
    auto data = ReadData("cosemfundo.txt");
    HistMaker(data, true, 1024, 0, 1023, "^{60}Co Sem Rad. de Fundo;Canais [CHN];Contagens", "", "P");
    return 0;
}