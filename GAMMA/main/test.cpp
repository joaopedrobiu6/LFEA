#include <iostream>
#include <vector>

int main()
{
    float t1 = 3.9;
    float t2 = 3.8;
    float metade1 = 0;
    float metade2 = 9.5;

    while (metade2 >= 0)
    {
        float sum = 0;
        float rep1 = 0, rep2 = 0;
        sum = metade1 + metade2;
        std::cout << "**********************" << std::endl;
        std::cout << "Soma das metades (exame) = " << sum << "\nMetade 1: " << metade1 << "\nMetade 2: " << metade2 << std::endl;

        rep1 = metade1 * 2;
        rep2 = metade2 * 2;

        std::cout << "Repescagem 1: " << rep1 << "\nRepescagem 2: " << rep2 << std::endl;

        if (rep1 <= 7.5 && rep2 <= 7.5)
        {
            std::cout << "NÃO DÁ" << std::endl;
        }
        if (rep1 <= 7.5 && rep2 <= 11.2)
        {
            std::cout << "NÃO DÁ" << std::endl;
        }
        if (rep1 <= 11.4 && rep2 <= 7.5)
        {
            std::cout << "NÃO DÁ" << std::endl;
        }
        std::cout << "**********************" << std::endl;
        metade1 = metade1 + 0.1;
        metade2 = metade2 - 0.1;
    }
    return 0;
}