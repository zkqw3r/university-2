#include "sorts.h"
#include <chrono>
#include <iostream>

int main() {
    std::vector<int> arrSizes {100, 500, 1000, 10000, 50000};

    std::cout << "Сортировка вставками: " << std::endl;
    for (int n:arrSizes) {
        std::vector<int> arr(n);
        arr = randomArray(n, 1, 999999);
        
        auto start_time = std::chrono::high_resolution_clock::now();

        insertionSort(arr);

        auto end_time = std::chrono::high_resolution_clock::now();
        auto sortTime = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);

        std::cout << "n = " << n << " -> " << sortTime.count() << " мс" << std::endl;
    }

    arrSizes.insert(arrSizes.end(), {1000000, 5000000, 10000000, 50000000});

    std::cout << "\nПоразрядная сортировка: " << std::endl;
    for (int n:arrSizes) {
        std::vector<int> arr(n);
        arr = randomArray(n, 1, 999999);
        
        auto start_time = std::chrono::high_resolution_clock::now();

        radixSort(arr);

        auto end_time = std::chrono::high_resolution_clock::now();
        auto sortTime = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);

        std::cout << "n = " << n << " -> " << sortTime.count() << " мс" << std::endl;
    }

    std::cout << "\nБыстрая сортировка: " << std::endl;
    for (int n:arrSizes) {
        std::vector<int> arr(n);
        arr = randomArray(n, 1, 999999);
        
        auto start_time = std::chrono::high_resolution_clock::now();

        quickSort(arr, 0, arr.size()-1);

        auto end_time = std::chrono::high_resolution_clock::now();
        auto sortTime = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);

        std::cout << "n = " << n << " -> " << sortTime.count() << " мс" << std::endl;
    }

    return 0;
}