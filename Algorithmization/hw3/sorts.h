#pragma once
#include <vector>


std::vector<int> randomArray(int size, int min, int max);

void insertionSort(std::vector<int>& arr);

void radixSort(std::vector<int>& arr);
void sortByRange(std::vector<int>& arr, int range);
std::vector<int> mergeBuckets(std::vector<std::vector<int>>& buckets);

void quickSort(std::vector<int>& arr, int low, int high);
int partition(std::vector<int>& arr, int low, int high);