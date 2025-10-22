#include <iostream>


void findMax(const int* arrA, const int* arrB, int sizeA, int sizeB) {
    int mxA = 0, mxB = 0, idx_mx_a = 0, idx_mx_b = 0;

    for (int i = 0; i < sizeA; i++) {
        if (arrA[i] > mxA) {
            mxA = arrA[i];
            idx_mx_a = i;
        }
    }

    for (int i = 0; i < sizeB; i++) {
        if (arrB[i] > mxB) {
            mxB = arrB[i];
            idx_mx_b = i;
        }
    }

    if (mxA > mxB) {
        std::cout << "Массив с максимальным значением - A" << std::endl;
        std::cout << "Элементы массива A: ";
        for (int i = 0; i < sizeA; i++) {
            std::cout << arrA[i] << " ";
        }
        std::cout << std::endl << "Максимальное значение: " << mxA << std::endl;
        std::cout << "Порядковый номер: " << idx_mx_a+1 << std::endl;
    }
    else {
        std::cout << "Массив с максимальным значением - B" << std::endl;
        std::cout << "Элементы массива B: ";
        for (int i = 0; i < sizeB; i++) {
            std::cout << arrB[i] << " ";
        }
        std::cout << std::endl << "Максимальное значение: " << mxB << std::endl;
        std::cout << "Порядковый номер: " << idx_mx_b+1 << std::endl;
    }
}

int main() {
    int sizeA;
    std::cout << "Размер массива A: ";
    std::cin >> sizeA;
    int* A = new int[sizeA];

    int sizeB;
    std::cout << "Размер массива B: ";
    std::cin >> sizeB;
    int* B = new int[sizeB];

    std::cout << "Введите " << sizeA << " элем. массива А:" << std::endl;
    for (int i = 0; i < sizeA; i++) {
        std::cin >> A[i];
    }

    std::cout << "Введите " << sizeB << " элем. массива B:" << std::endl;
    for (int i = 0; i < sizeB; i++) {
        std::cin >> B[i];
    }

    findMax(A, B, sizeA, sizeB);

    delete[] A;
    delete[] B;

    system("PAUSE");

    return 0;
}