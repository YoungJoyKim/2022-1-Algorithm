from itertools import combinations

arr = [0] * 9
idx_arr = [0, 1, 2, 3, 4, 5, 6, 7, 8]
for i in range(9):
    arr[i] = int(input())

arr.sort()
summation = sum(arr)
for i in combinations(idx_arr, 2):
    if summation - (arr[i[0]] + arr[i[1]]) == 100:
        for idx, val in enumerate(arr):
            if idx not in i:
                print(val)
        break
