#include "analise.h"

std::vector<std::vector<float>> DataSet(std::vector<std::vector<float>> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        vec[i][0] = vec[i][2];
        vec[i][1] = vec[i][3];
        vec[i][2] = 0.;
        vec[i][3] = 0.;
    }
    return vec;
}

int main()
{
    /* auto p1 = ReadData("perto1.txt");
    auto p2 = ReadData("perto2.txt");
    auto p3 = ReadData("perto3.txt");
    auto p4 = ReadData("perto4.txt");
    //  auto t1 = ReadData("teste1.txt");
    //  auto t2 = ReadData("teste2.txt");
    auto t3 = ReadData("teste3.txt");
    //  auto t4 = ReadData("teste4.txt");
    //  auto t5 = ReadData("teste5.txt");
    auto t6 = ReadData("teste6.txt");

    GraphPDF(p1, "L = 6.11 #pm 0.01 [cm];U_{A} [V];U_{B} [V]", "", "AP", "p1.png", 60);
    GraphPDF(p2, "L = 6.11 #pm 0.01 [cm];U_{A} [V];U_{B} [V]", "", "AP", "p2.png", 60);
    GraphPDF(p3, "L = 6.11 #pm 0.01 [cm];U_{A} [V];U_{B} [V]", "", "AP", "p3.png", 60);
    GraphPDF(p4, "L = 6.11 #pm 0.01 [cm];U_{A} [V];U_{B} [V]", "", "AP", "p4.png", 60);
    // GraphPDF(t1, "L = 7.25 #pm 0.01 [cm];U_{A} [V];U_{B} [V]", "", "AP", "t1.png", 60);
    // GraphPDF(t2, "L = 7.25 #pm 0.01 [cm];U_{A} [V];U_{B} [V]", "", "AP", "t2.png", 60);
    GraphPDF(t3, "L = 7.25 #pm 0.01 [cm];U_{A} [V];U_{B} [V]", "", "AP", "t3.png", 60);
    // GraphPDF(t4, "L = 7.25 #pm 0.01 [cm];U_{A} [V];U_{B} [V]", "", "AP", "t4.png", 60);
    // GraphPDF(t5, "L = 7.25 #pm 0.01 [cm];U_{A} [V];U_{B} [V]", "", "AP", "t5.png", 60);
    GraphPDF(t6, "L = 7.25 #pm 0.01 [cm];U_{A} [V];U_{B} [V]", "", "AP", "t6.png", 60); */
    /*
        auto lg1 = ReadData("10mW_1.txt");
        GraphPDF(lg1, "L = 3.40 #pm 0.01[cm];U_{A} [V];U_{B} [V]", "", "APL", "10mW_1.png", 75);
        auto lg2 = ReadData("10mW_2.txt");
        GraphPDF(lg2, "L = 6.00 #pm 0.01[cm];U_{A} [V];U_{B} [V]", "", "APL", "10mW_2.png", 75);
     */

    auto ml1 = ReadData("minilaser1.txt");
    auto ml2 = ReadData("minilaser2.txt");
    auto ml3 = ReadData("minilaser3.txt");
    auto ml4 = ReadData("minilaser4.txt");
    auto ml5 = ReadData("minilaser5.txt");
    auto ml6 = ReadData("minilaser6.txt");
    auto ml7 = ReadData("minilaser7.txt");
    auto ml8 = ReadData("minilaser8.txt");

    auto ml1d = ReadData("minilaser1_d.txt");
    auto ml2d = ReadData("minilaser2_d.txt");
    auto ml3d = ReadData("minilaser3_d.txt");

    ml1 = DataSet(ml1);
    ml2 = DataSet(ml2);
    ml3 = DataSet(ml3);
    ml4 = DataSet(ml4);
    ml5 = DataSet(ml5);
    ml6 = DataSet(ml6);
    ml7 = DataSet(ml7);
    ml8 = DataSet(ml8);
    ml1d = DataSet(ml1d);
    ml2d = DataSet(ml2d);
    ml3d = DataSet(ml3d);

    GraphPDF(ml1, "L = [cm];U_{A} [V];U_{B} [V]", "", "APL", "ml1.png", 75);
    GraphPDF(ml2, "L = [cm];U_{A} [V];U_{B} [V]", "", "APL", "ml2.png", 75);
    GraphPDF(ml3, "L = [cm];U_{A} [V];U_{B} [V]", "", "APL", "ml3.png", 75);
    GraphPDF(ml4, "L = [cm];U_{A} [V];U_{B} [V]", "", "APL", "ml4.png", 75);
    GraphPDF(ml5, "L = [cm];U_{A} [V];U_{B} [V]", "", "APL", "ml5.png", 75);
    GraphPDF(ml6, "L = [cm];U_{A} [V];U_{B} [V]", "", "APL", "ml6.png", 75);
    GraphPDF(ml7, "L = [cm];U_{A} [V];U_{B} [V]", "", "APL", "ml7.png", 75);
    GraphPDF(ml8, "L = [cm];U_{A} [V];U_{B} [V]", "", "APL", "ml8.png", 75);
    GraphPDF(ml1d, "L = [cm];U_{A} [V];U_{B} [V]", "", "APL", "ml1d.png", 75);
    GraphPDF(ml2d, "L = [cm];U_{A} [V];U_{B} [V]", "", "APL", "ml2d.png", 75);
    GraphPDF(ml3d, "L = [cm];U_{A} [V];U_{B} [V]", "", "APL", "ml3d.png", 75);

    return 0;
}
