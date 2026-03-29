#include "sorts.h"
#include <random>
#include <algorithm>


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


void insertionSort(std::vector<int>& arr) {
    if (arr.size() <= 1) return;
    for (size_t i = 1; i < arr.size(); ++i) {
        int curr = arr[i];
        int j = i-1;
        while (j>=0 && arr[j]>curr) {
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = curr;
    }
}


void radixSort(std::vector<int>& arr) {
    if (arr.size() <= 1) return;
    int mx = *std::max_element(arr.begin(), arr.end());
    int range = 1;
    while (mx/range>0) {
        sortByRange(arr, range);
        range *= 10;
    }
}

void sortByRange(std::vector<int>& arr, int range) {
    std::vector<std::vector<int>> buckets(10);
    for (int num:arr) {
        int idx = (num/range) % 10;
        buckets[idx].push_back(num);
    }
    arr = mergeBuckets(buckets);
}

std::vector<int> mergeBuckets(std::vector<std::vector<int>>& buckets) {
    std::vector<int> mergedArray;
    for (std::vector<int> bucket:buckets) {
        mergedArray.insert(mergedArray.end(), bucket.begin(), bucket.end());
    }

    return mergedArray;
}


void quickSort(std::vector<int>& arr, int low, int high) {
    if (arr.size() <= 1) return;
    if (low < high) {
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot-1);
        quickSort(arr, pivot+1, high); 
    }
}

int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j<=high-1; ++j) {
        if (arr[j] <= pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i+1], arr[high]);
    
    return ++i;
}
