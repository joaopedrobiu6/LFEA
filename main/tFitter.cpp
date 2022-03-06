#include "Fitter.h"

int main()
{

  std::vector<std::vector<float>> vec = {{0.425, 1.826}, {1.489, 2.993}, {2.979, 1.324}};

  TF1 *f_1 = new TF1("f", "[0]*sin(x)+[1]", 0, 10);
  f_1->SetParNames("a", "b");
  f_1->SetParameters(1.5, 0.5);
  Fitter Fit(f_1, vec);

  // Fit.Print("data"); 

  Fit.fit();
  Fit.GetFitInfo(f_1);

  auto der1 = Fit.Derivate(0, 1);
  auto der2 = Fit.Derivate(0, 2);
  auto der3 = Fit.Derivate(0, 3);

  std::cout << "for x = 0\n"
            << "Image f(0): " << Fit.Image(0)
            << "\n1st Derivative: " << der1.first << "Erro: " << der1.second << "\n2st Derivative: " << der2.first << "Erro: " << der2.second << "\n3st Derivative: " << der3.first << "Erro: " << der3.second << std::endl;

  std::cout << "Integral [0, Pi]: " << Fit.Integrate(0, M_PI) << std::endl;

  // DRAW
  // Fit.DrawFit();
  // Fit.DrawFitErrors();

  return 0;
}
