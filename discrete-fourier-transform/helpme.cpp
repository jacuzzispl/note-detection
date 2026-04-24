#include <iostream>
#include <iomanip>
#include <cmath>
#include <complex>

int main()
{
    const double pi = std::acos(-1.0);
    const std::complex<double> i(0.0, 1.0);
    std::cout << pi << std::endl;
    std::cout << std::fixed << std::setprecision(2) << "This should be 1: " << std::abs(std::exp(i * pi)) << std::endl;
}