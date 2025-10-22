#include <iostream>
#include <set>
#include <algorithm>


void findMax(const std::set<int>& setA, const std::set<int>& setB) {
    std::set<int> diff;
    std::set_difference(
        setA.begin(), setA.end(),
        setB.begin(), setB.end(),
        inserter(diff, diff.begin())
    );

    if (diff.empty()) {
        std::cout << "Разность множеств пуста" << std::endl;
    }
    else {
        std::cout << "Разность множеств: ";
        for (int x : diff) {
            std::cout << x << " ";
        }
        std::cout << std::endl;

        int mx = *diff.rbegin();
        std::cout << "Максимальный элемент: " << mx << std::endl;
    }
}

int main() {
    int sizeA;
    std::cout << "Размер множества A: ";
    std::cin >> sizeA;
    std::set<int>setA;

    int sizeB;
    std::cout << "Размер множества B: ";
    std::cin >> sizeB;
    std::set<int>setB;

    int val;
    std::cout << "Введите " << sizeA << " элем. множества А:" << std::endl;
    for (int i = 0; i < sizeA; i++) {
        std::cin >> val;
        setA.insert(val);
    }

    std::cout << "Введите " << sizeB << " элем. массива B:" << std::endl;
    for (int i = 0; i < sizeB; i++) {
        std::cin >> val;
        setB.insert(val);
    }

    findMax(setA, setB);

    setA.clear();
    setB.clear();

    system("PAUSE");

    return 0;

}
