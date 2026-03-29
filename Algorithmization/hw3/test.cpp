#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "sorts.h"

// Пустой массив
TEST_CASE("Empty array") {
    std::vector<int> original = {};

    SUBCASE("insertionSort") {
        std::vector<int> arr = original;
        insertionSort(arr);
        CHECK(arr.empty());
    }
    SUBCASE("radixSort") {
        std::vector<int> arr = original;
        radixSort(arr);
        CHECK(arr.empty());
    }
    SUBCASE("quickSort") {
        std::vector<int> arr = original;
        if (!arr.empty()) {
            quickSort(arr, 0, arr.size() - 1);
        }
        CHECK(arr.empty());
    }
}

// Массив с одним элементом
TEST_CASE("One element") {
    std::vector<int> original = {1337};
    std::vector<int> expected = {1337};

    SUBCASE("insertionSort") {
        std::vector<int> arr = original;
        insertionSort(arr);
        CHECK(arr == expected);
    }
    SUBCASE("radixSort") {
        std::vector<int> arr = original;
        radixSort(arr);
        CHECK(arr == expected);
    }
    SUBCASE("quickSort") {
        std::vector<int> arr = original;
        quickSort(arr, 0, arr.size() - 1);
        CHECK(arr == expected);
    }
}

// Отсортированный массив
TEST_CASE("Sorted array") {
    std::vector<int> original = {1, 2, 3, 4, 5};
    std::vector<int> expected = {1, 2, 3, 4, 5};

    SUBCASE("insertionSort") {
        std::vector<int> arr = original;
        insertionSort(arr);
        CHECK(arr == expected);
    }
    SUBCASE("radixSort") {
        std::vector<int> arr = original;
        radixSort(arr);
        CHECK(arr == expected);
    }
    SUBCASE("quickSort") {
        std::vector<int> arr = original;
        quickSort(arr, 0, arr.size() - 1);
        CHECK(arr == expected);
    }
}

// Обратно отсортированный массив
TEST_CASE("Reversed array") {
    std::vector<int> original = {5, 4, 3, 2, 1};
    std::vector<int> expected = {1, 2, 3, 4, 5};

    SUBCASE("insertionSort") {
        std::vector<int> arr = original;
        insertionSort(arr);
        CHECK(arr == expected);
    }
    SUBCASE("radixSort") {
        std::vector<int> arr = original;
        radixSort(arr);
        CHECK(arr == expected);
    }
    SUBCASE("quickSort") {
        std::vector<int> arr = original;
        quickSort(arr, 0, arr.size() - 1);
        CHECK(arr == expected);
    }
}

// Массив с одинаковыми элементами
TEST_CASE("Identical elements") {
    std::vector<int> original = {1, 1, 1};
    std::vector<int> expected = {1, 1, 1};

    SUBCASE("insertionSort") {
        std::vector<int> arr = original;
        insertionSort(arr);
        CHECK(arr == expected);
    }
    SUBCASE("radixSort") {
        std::vector<int> arr = original;
        radixSort(arr);
        CHECK(arr == expected);
    }
    SUBCASE("quickSort") {
        std::vector<int> arr = original;
        quickSort(arr, 0, arr.size() - 1);
        CHECK(arr == expected);
    }
}

// Массив со случайными элементами
TEST_CASE("Random array"){
    std::vector<int> original = {1, 9, 5, 123, 12, 934, 12394143, 235};
    std::vector<int> expected = {1, 5, 9, 12, 123, 235, 934, 12394143};

    SUBCASE("insertionSort") {
        std::vector<int> arr = original;
        insertionSort(arr);
        CHECK(arr == expected);
    }
    SUBCASE("radixSort") {
        std::vector<int> arr = original;
        radixSort(arr);
        CHECK(arr == expected);
    }
    SUBCASE("quickSort") {
        std::vector<int> arr = original;
        quickSort(arr, 0, arr.size() - 1);
        CHECK(arr == expected);
    }
}