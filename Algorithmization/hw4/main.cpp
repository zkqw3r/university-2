#include "sorts.h"
#include <chrono>
#include <iostream>
#include <iomanip>
#include <vector>

int main() {
    std::vector<int> arrSizes {100, 1000, 10000, 20000, 30000, 40000, 50000};
    int N = 1000;

    std::cout << "Размер    Обычная     2 потока    4 потока    8 потоков\n";
    std::cout << std::fixed << std::setprecision(6);

    for (int n : arrSizes) {
        std::vector<int> base_arr = randomArray(n, 1, 999999);

        // Обычная БС
        std::vector<int> arr = base_arr;
        auto start = std::chrono::high_resolution_clock::now();
        quickSort(arr, 0, arr.size() - 1);
        auto end = std::chrono::high_resolution_clock::now();
        double time_normal = std::chrono::duration<double>(end - start).count();

        // 2 потока
        arr = base_arr;
        start = std::chrono::high_resolution_clock::now();
        parallelQuickSort(arr, 0, arr.size() - 1, N, 2);
        end = std::chrono::high_resolution_clock::now();
        double time_p2 = std::chrono::duration<double>(end - start).count();

        // 4 потока
        arr = base_arr;
        start = std::chrono::high_resolution_clock::now();
        parallelQuickSort(arr, 0, arr.size() - 1, N, 4);
        end = std::chrono::high_resolution_clock::now();
        double time_p4 = std::chrono::duration<double>(end - start).count();

        // 8 потоков
        arr = base_arr;
        start = std::chrono::high_resolution_clock::now();
        parallelQuickSort(arr, 0, arr.size() - 1, N, 8);
        end = std::chrono::high_resolution_clock::now();
        double time_p8 = std::chrono::duration<double>(end - start).count();

        std::cout << std::left << std::setw(10) << n << std::setw(12) << time_normal 
        << std::setw(12) << time_p2 << std::setw(12) << time_p4 << std::setw(12) << time_p8 << "\n";
    }

    return 0;
}