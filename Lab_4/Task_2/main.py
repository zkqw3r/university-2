def find_max(set1, set2):
    diff = set1-set2
    return max(diff)


def main():
    a, b = set(), set()
    for i in range(int(input("Введите длину множества a: "))):
        a.add(int(input(f'a[{i}]: ')))
    for i in range(int(input("Введите длину множества b: "))):
        b.add(int(input(f'b[{i}]: ')))

        
if __name__ == "__main__":
    main()