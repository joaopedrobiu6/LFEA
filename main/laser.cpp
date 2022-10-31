#include "analise.h"

int main()
{
    auto p1 = ReadData("perto1.txt");
    auto p2 = ReadData("perto2.txt");
    auto p3 = ReadData("perto3.txt");
    auto p4 = ReadData("perto4.txt");
    auto t1 = ReadData("teste1.txt");
    auto t2 = ReadData("teste2.txt");
    auto t3 = ReadData("teste3.txt");
    auto t4 = ReadData("teste4.txt");
    auto t5 = ReadData("teste5.txt");
    for (int i = 0; i < p1.size(); i++)
    {
        p1[i][2] = 0.;
        p1[i][3] = 0.;
    }
    for (int i = 0; i < p2.size(); i++)
    {
        p2[i][2] = 0.;
        p2[i][3] = 0.;
    }
    for (int i = 0; i < p3.size(); i++)
    {
        p3[i][2] = 0.;
        p3[i][3] = 0.;
    }
    for (int i = 0; i < p4.size(); i++)
    {
        p4[i][2] = 0.;
        p4[i][3] = 0.;
    }
    for (int i = 0; i < t1.size(); i++)
    {
        t1[i][2] = 0.;
        t1[i][3] = 0.;
    }
    for (int i = 0; i < t2.size(); i++)
    {
        t2[i][2] = 0.;
        t2[i][3] = 0.;
    }
    for (int i = 0; i < t3.size(); i++)
    {
        t3[i][2] = 0.;
        t3[i][3] = 0.;
    }
    for (int i = 0; i < t4.size(); i++)
    {
        t4[i][2] = 0.;
        t4[i][3] = 0.;
    }
    for (int i = 0; i < t5.size(); i++)
    {
        t5[i][2] = 0.;
        t5[i][3] = 0.;
    }
    GraphPDF(p1, "Graphic;U_{A} [V];U_{B} [V]", "", "AP", "p1.png", 60);
    GraphPDF(p2, "Graphic;U_{A} [V];U_{B} [V]", "", "AP", "p2.png", 60);
    GraphPDF(p3, "Graphic;U_{A} [V];U_{B} [V]", "", "AP", "p3.png", 60);
    GraphPDF(p4, "Graphic;U_{A} [V];U_{B} [V]", "", "AP", "p4.png", 60);
    GraphPDF(t1, "Graphic;U_{A} [V];U_{B} [V]", "", "AP", "t1.png", 60);
    GraphPDF(t2, "Graphic;U_{A} [V];U_{B} [V]", "", "AP", "t2.png", 60);
    GraphPDF(t3, "Graphic;U_{A} [V];U_{B} [V]", "", "AP", "t3.png", 60);
    GraphPDF(t4, "Graphic;U_{A} [V];U_{B} [V]", "", "AP", "t4.png", 60);
    GraphPDF(t5, "Graphic;U_{A} [V];U_{B} [V]", "", "AP", "t5.png", 60);
    return 0;
}
