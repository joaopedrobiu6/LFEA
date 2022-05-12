#include "hist.h"

int main()
{
    hist teste("test.txt");
    teste.dump();
    teste.MakeHist("Título", "teste22", "Nº de Ocorrências", "Valores", 10, 0, 10);
    // teste.DataInput("test.txt");
    return 0;
}