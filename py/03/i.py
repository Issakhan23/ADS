n, k = map(int, input().split())
a = list(map(int, input().split()))

def can(x):
    g = 1
    cur = 0

    for val in a:
        if cur + val <= x:
            cur += val
        else:
            g += 1
            cur = val

    return g <= k

l = max(a)
r = sum(a)


while l < r:
    m = (l + r) // 2

    if can(m):
        r = m
    else:
        l = m + 1

print(l)