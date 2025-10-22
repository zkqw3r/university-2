def find_max(array1, array2):
    mx = array1[0]
    idx = 0
    mx_array = array1
    for i in range(len(array1)):
        if array1[i] > mx:
            mx = array1[i]
            idx = i
    for i in range(len(array2)):
        if array2[i] > mx:
            mx = array2[i]
            idx = i
            mx_array = array2
    return mx, idx+1, mx_array
    

def main():
    a = [int(input(f"a[{i}]: ")) for i in range(int(input("Введите длину массива а: ")))]
    b = [int(input(f"b[{i}]: ")) for i in range(int(input("Введите длину массива b: ")))]
    mx, index_mx, mx_array = find_max(a, b)
    print(f"\nМассив с максимальным значением: {mx_array}\n"+
        f"Максимальное значение: {mx}\n"+
        f"Порядковый номер: {index_mx}")
    

if __name__ == "__main__":
    main()