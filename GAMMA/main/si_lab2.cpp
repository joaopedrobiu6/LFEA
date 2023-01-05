#include "analise.h"

int main()
{
    auto si3 = ReadData("si_lab.txt");
    GraphPDF(si3, "Espetro com cristal de Si; #theta [^{o}];Rates [1/s]", "", "AP", "si3.png", 80);
    auto al = ReadData("al.lab2.txt");
    GraphPDF(al, "Espetro com Al;#theta [^{o}];Rates [1/s]", "", "AP", "al.png", 80);
    auto lif = ReadData("lif.txt");
    GraphPDF(lif, "Espetro com LiF;#theta [^{o}];Rates [1/s]", "", "AP", "lif.png", 80);
    return 0;
}