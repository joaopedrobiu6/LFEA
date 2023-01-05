#include "analise.h"

int main()
{
    auto data = ReadData("teste6.txt");

    GraphMaker(data, "Teste 6;U_{a} [V];U_{b} [V]", "", "AP", 60);
    return 0;
}
//(0.5*[0]*[1]) / ((x[0]-[2])*(x[0]-[2])+ 0.25*[1]*[1])