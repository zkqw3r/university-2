def find_max(set1, set2):
    diff = set1-set2
    print(f"\nРазность множеств: {diff}\n")
    return max(diff)


def main():
    a, b = set(), set()
    for i in range(int(input("Введите длину множества a: "))):
        a.add(int(input(f'Введите элемент a[{i}]: ')))
    for i in range(int(input("Введите длину множества b: "))):
        b.add(int(input(f'Введите элемент b[{i}]: ')))
    print(f"Максимальный элемент: {find_max(a, b)}")

        
if __name__ == "__main__":
    main()
