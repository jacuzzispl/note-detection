#include <iostream>
#include <vector>
#include <complex>
#include <cmath>

using namespace std;

void DFT(const std::vector<double> samples, int rate)
{
    const double pi = std::acos(-1.0);

    std::vector<std::complex<double>> output(samples.size(), std::complex<double>(0.0, 0.0));

    // k = i (the frequency index)
    // n = j (the index of the current sample)
    // N = samples.size() (the number of samples)

    for (int i = 0; i < samples.size(); i++) // this first for loop is the frequencies
    {
        double theta = (-2 * pi * i) / samples.size();

        for (int j = 0; j < samples.size(); j++) // why do we need this second for loop?
        {
            // multiplying the current xn with the frequency wave

            // turning real number from sample into complex number
            // output.at(i) += static_cast<std::complex<double>>(samples[i], 0.0) * std::exp(-i * ((2 * pi) / samples.size()) * i);
            // std::cout << static_cast<std::complex<double>>(samples[i]) * std::exp(-i * ((2 * pi) / samples.size()) * j) << endl;

            std::complex<double> weight(cos(theta * j), sin(theta * j));

            output.at(i) += samples.at(j) * weight;
        }
        std::cout << "Index " << i << " : " << output[i] << endl;
    }
}

int main()
{
    std::vector<double> input = {0.16, -0.32, 0.88, 0.77, -0.39};

    DFT(input, 2);
}