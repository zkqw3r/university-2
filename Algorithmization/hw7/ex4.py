def find_partitions(target, current_sum, start_num, path):
    if current_sum == target:
        print(*path)
        return
    for i in range(start_num, target - current_sum + 1):
        path.append(i)
        find_partitions(target, current_sum + i, i, path)
        path.pop()

n = int(input())
find_partitions(n, 0, 1, [])