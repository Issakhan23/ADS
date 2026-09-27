def binary_search(a, target):
    left = 0
    right = len(a) - 1

    while left <= right:
        mid = left + (right - left) // 2

        if a[mid] == target:
            return mid
        elif a[mid] < target:
            left = mid + 1
        else:
            right = mid - 1

    return -1


n = int(input())

a = list(map(int, input().split()))

target = int(input())

idx = binary_search(a, target)

if idx == -1:
    print("No")
else:
    print("Yes")