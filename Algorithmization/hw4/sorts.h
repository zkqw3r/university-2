#pragma once
#include <vector>

std::vector<int> randomArray(int size, int min, int max);

void quickSort(std::vector<int>& arr, int low, int high);
int partition(std::vector<int>& arr, int low, int high);

void parallelQuickSort(std::vector<int>& arr, int low, int high, int N, int num_threads);