#include "alfa.h"

int main()
{
    auto data = ReadData("ajuste2.txt");
    for (int i = 0; i < data.size(); i++)
    {
        data[i][1] = (5.305 * data[i][1]) / 5.163;
        data[i][3] = (5.305 * data[i][3]) / 5.163;
    }
    GraphMaker(data, "Reta de Calibrac#tilde{a}o;CHN (MCA);Energia [MeV]", "[a]*x + [b]", "AP", kBlack + 1);
    return 0;
}
