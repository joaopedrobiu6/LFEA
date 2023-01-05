#include "analise.h"

int main()
{
    auto data = ReadData("nacl_todo_data.txt");
    GraphMaker(data, "Espetro de ^{42}Mo (cristal de NaCl);#theta [^{o}];Rate [s^{-1}]", "", "AP", 60);
    return 0;
}