#include "hist.h"

int main()
{
    hist teste("aula1/test.txt");
    teste.dump();
    teste.MakeHist("Título", "teste22", "Nº de Ocorrências", "Valores", 10, 0, 10, true, "gaus");
    // teste.DataInput("test.txt");
    return 0;
}