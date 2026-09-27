n, k = map(int, input().split())
a = list(map(int, input().split()))


def can(x):
    groups = 1
    current = 0

    for value in a:
        if current + value <= x:
            current += value
        else:
            groups += 1
            current = value

    return groups <= k


left = max(a)
right = sum(a)

while left < right:
    mid = (left + right) // 2

    if can(mid):
        right = mid
    else:
        left = mid + 1

print(left)