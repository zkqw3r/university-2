import SuperFastFinder
import time
import random


def slow_finder(arr):
    mn = arr[0]
    for i in arr:
        if i < mn:
            mn = i
    return mn


print("Генерация списка...")
arr = [random.randint(0, 10_000_000) for _ in range(100_000_000)]
print("Список сгенерирован")
print("-" * 50)

print("Запуск C++\n")
min_c = SuperFastFinder.find_min_fast(arr)
print(f"min = {min_c}\n")
print("-" * 50)

print("Запуск Python\n")
st = time.time()
min_py = slow_finder(arr)
end = time.time()
print(f"Python time: {end - st:.10f} s")
print(f"min = {min_py}")

print("-" * 50)
