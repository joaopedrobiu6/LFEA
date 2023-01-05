#include "analise.h"

int main()
{
    auto data = ReadData("rend.txt");
    GraphMaker(data, "Preco m#acute{e}dio de uma Crianca/Ano;Preco;Ano da Crianca", "", "APL", 60);
    return 0;
}