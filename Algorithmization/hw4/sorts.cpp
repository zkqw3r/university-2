#include "sorts.h"
#include <random>
#include <algorithm>
#include <thread>

std::vector<int> randomArray(int size, int min, int max) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(min, max);

    std::vector<int> arr(size);
    for (int i = 0; i<size; ++i) {
        arr[i] = dist(gen);
    }
    return arr;
}

int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; ++j) {
        if (arr[j] <= pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return ++i;
}

void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high); 
    }
}

void parallelQuickSort(std::vector<int>& arr, int low, int high, int N, int num_threads) {
    if (low >= high) return;

    int current_size = high - low + 1;

    if (current_size > N && num_threads > 1) {
        int pivot = partition(arr, low, high);

        /*
        кол-во доступных потоков делим между левой и правой частью, чтобы каждая рекурсия
        не плодила новые потоки и их кол-во не выходило из под контроля
        */
        int left_threads = num_threads / 2;
        int right_threads = num_threads - left_threads;

        std::thread tleft(parallelQuickSort, std::ref(arr), low, pivot - 1, N, left_threads);
        std::thread tright(parallelQuickSort, std::ref(arr), pivot + 1, high, N, right_threads);
        tleft.join();
        tright.join();
    } else {
        quickSort(arr, low, high);
    }
}