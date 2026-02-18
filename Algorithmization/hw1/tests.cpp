#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <vector>

long long append(int n) {
    std::vector<int> arr;
    for (int i = 0; i < n; i++) {
        arr.push_back(i);
    }
    return (long long)arr.capacity() * sizeof(int);
}

// После n вставок размер массива равен n
TEST_CASE("test_size") {
    std::vector<int> arr;
    for (int i = 0; i < 1000; i++) {
        arr.push_back(i);
    }
    CHECK(arr.size() == 1000);
}

// Память не превышает n*sizeof(int)*2 (capacity удваивается)
TEST_CASE("test_memory_bound") {
    int n = 1000;
    long long mem = append(n);
    long long maxMem = n * (long long)sizeof(int) * 2LL;
    CHECK(mem <= maxMem);
}

// При росте n память тоже растёт
TEST_CASE("test_memory_up") {
    long long mem_small = append(100);
    long long mem_large = append(10000);
    CHECK(mem_large > mem_small);
}
