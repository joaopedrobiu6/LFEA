#include "analise.h"

int main()
{
    auto p1 = ReadData("perto1.txt");
    auto p2 = ReadData("perto2.txt");
    auto p3 = ReadData("perto3.txt");
    auto p4 = ReadData("perto4.txt");
    //  auto t1 = ReadData("teste1.txt");
    //  auto t2 = ReadData("teste2.txt");
    auto t3 = ReadData("teste3.txt");
    //  auto t4 = ReadData("teste4.txt");
    //  auto t5 = ReadData("teste5.txt");
    auto t6 = ReadData("teste6.txt");

    GraphPDF(p1, "L = 6.11 #pm 0.005 [cm];U_{A} [V];U_{B} [V]", "", "AP", "p1.png", 60);
    GraphPDF(p2, "L = 6.11 #pm 0.005 [cm];U_{A} [V];U_{B} [V]", "", "AP", "p2.png", 60);
    GraphPDF(p3, "L = 6.11 #pm 0.005 [cm];U_{A} [V];U_{B} [V]", "", "AP", "p3.png", 60);
    GraphPDF(p4, "L = 6.11 #pm 0.005 [cm];U_{A} [V];U_{B} [V]", "", "AP", "p4.png", 60);
    // GraphPDF(t1, "L = 7.25 #pm 0.005 [cm];U_{A} [V];U_{B} [V]", "", "AP", "t1.png", 60);
    // GraphPDF(t2, "L = 7.25 #pm 0.005 [cm];U_{A} [V];U_{B} [V]", "", "AP", "t2.png", 60);
    GraphPDF(t3, "L = 7.25 #pm 0.005 [cm];U_{A} [V];U_{B} [V]", "", "AP", "t3.png", 60);
    // GraphPDF(t4, "L = 7.25 #pm 0.005 [cm];U_{A} [V];U_{B} [V]", "", "AP", "t4.png", 60);
    // GraphPDF(t5, "L = 7.25 #pm 0.005 [cm];U_{A} [V];U_{B} [V]", "", "AP", "t5.png", 60);
    GraphPDF(t6, "L = 7.25 #pm 0.005 [cm];U_{A} [V];U_{B} [V]", "", "AP", "t6.png", 60);

    return 0;
}
