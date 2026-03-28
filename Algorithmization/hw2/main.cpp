#include <iostream>
#include <iomanip>
#include "functions.h"

int main() {
    double answer = 1.0;
    double a = 3.0;
    double b = 5.0;
    int arr[] = {2, 3, 4, 5, 6, 8, 10, 50, 80, 100, 123, 163};

    std::cout << "Приближенное значение интеграла при" << std::endl;
    for (int n:arr) {
        double result = simpson_rule(integral, a, b, n);
        std::cout << "n = " << n << " -> " << result << " погрешность: " << std::fixed << std::setprecision(6) << result - answer << std::endl;
    }
    std::cout << "Правильное значение: " << answer << std::endl;

    return 0;
}