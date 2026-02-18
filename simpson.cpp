#include <iostream>
#include <cmath>
#include <iomanip>

// The function to integrate: f(x) = x^(1.5)
double f(double x) {
    return std::pow(x, 1.5);
}

int main() {
    // Exact integral: (2/5) * x^(5/2) evaluated from 0 to 2
    const double exact_val = (2.0 / 5.0) * std::pow(2.0, 2.5);

    std::cout << std::left << std::setw(12) << "n"
              << "| " << std::setw(18) << "Approximation"
              << "| " << std::setw(18) << "Error"
              << "| " << std::setw(10) << "Ratio" << std::endl;
    std::cout << std::string(65, '-') << std::endl;

    double prev_error = 0.0;

    // Loop powers of 2 from 1 to 24
    for (int p = 1; p <= 24; ++p) {
        long long n = 1LL << p; // 2^p
        double a = 0.0;
        double b = 2.0;
        double h = (b - a) / n;

        // Simpson's Rule: h/3 * (f(a) + f(b) + 4*sum_odd + 2*sum_even)
        double sum_odd = 0.0;
        double sum_even = 0.0;

        // Calculate sum of odd indices: f(x_1), f(x_3), ...
        for (long long i = 1; i < n; i += 2) {
            sum_odd += f(a + i * h);
        }

        // Calculate sum of even indices: f(x_2), f(x_4), ...
        for (long long i = 2; i < n; i += 2) {
            sum_even += f(a + i * h);
        }

        double approx = (h / 3.0) * (f(a) + f(b) + 4.0 * sum_odd + 2.0 * sum_even);
        double error = std::abs(approx - exact_val);

        // Calculate convergence ratio
        std::string ratio_str = "-";
        if (p > 1 && error > 0) {
            double ratio = prev_error / error;
            ratio_str = std::to_string(ratio);
        }

        std::cout << "2^" << std::left << std::setw(2) << p
                  << " (" << std::setw(8) << n << ") | "
                  << std::fixed << std::setprecision(14) << approx << " | "
                  << std::scientific << std::setprecision(6) << error << "       | "
                  << std::defaultfloat << ratio_str << std::endl;

        prev_error = error;
    }

    return 0;
}