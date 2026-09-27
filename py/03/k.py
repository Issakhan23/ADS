t = int(input())
q = list(map(int, input().split()))

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
    l = 0
    r = n - 1

    while l <= r:
        mid = (l + r) // 2

        if row_max[mid] >= x:
            l = mid + 1
        else:
            r = mid - 1
    return r


def find_in_row(row, x, increasing):
    l = 0
    r = m - 1

    while l <= r:
        mid = (l + r) // 2

        if row[mid] == x:
            return mid

        if increasing:
            if row[mid] < x:
                l = mid + 1
            else:
                r = mid - 1
        else:
            if row[mid] > x:
                l = mid + 1
            else:
                r = mid - 1
    return -1

for x in q:
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