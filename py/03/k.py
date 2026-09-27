t = int(input())
queries = list(map(int, input().split()))

n, m = map(int, input().split())

a = []
row_max = []

for i in range(n):
    row = list(map(int, input().split()))
    a.append(row)

    if i % 2 == 0:
        row_max.append(row[0])
    else:
        row_max.append(row[-1])


def find_row(x):
    left = 0
    right = n - 1

    while left <= right:
        mid = (left + right) // 2

        if row_max[mid] >= x:
            left = mid + 1
        else:
            right = mid - 1

    return right


def find_in_row(row, x, increasing):
    left = 0
    right = m - 1

    while left <= right:
        mid = (left + right) // 2

        if row[mid] == x:
            return mid

        if increasing:
            if row[mid] < x:
                left = mid + 1
            else:
                right = mid - 1
        else:
            if row[mid] > x:
                left = mid + 1
            else:
                right = mid - 1

    return -1


for x in queries:
    r = find_row(x)

    if r < 0:
        print(-1)
        continue


    row = a[r]

    if r % 2 == 0:
        if x < row[-1]:
            print(-1)
            continue
    else:
        if x < row[0]:
            print(-1)
            continue

    c = find_in_row(row, x, r % 2 == 1)

    if c == -1:
        print(-1)
    else:
        print(r, c)