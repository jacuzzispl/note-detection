#include <iostream>
#include <vector>
#include <complex>
#include <cmath>

void DFT(const std::vector<double> &samples, int rate)
{
    double freqResolution = rate / samples.size();

    const double pi = std::acos(-1.0);

    const std::complex<double> i(0.0, 1.0);

    std::vector<std::complex<double>> output(0, samples.size());

    for (int i = 0; i <= samples.size(); i++)
    {
        for (int j = 0; j <= samples.size(); i++)
        {
            // multiplying the current xn with the frequency wave

            // turning real number from sample into complex number
            output[i] += static_cast<std::complex<double>>(samples[i], 0.0) * std::exp(-i * ((2 * pi) / samples.size()) * i);
            std::cout << output[i];
        }
    }
}

int main()
{
    std::vector<double> input = {0.16, -0.32, 0.88, 0.77, -0.39};

    std::vector<double> &ref = input;

    DFT(ref, 2);
}