n, k = map(int, input().split())
a = list(map(int, input().split()))

l = 1
r = max(a)

while l < r:
    h = l + (r - l) // 2
    hours = 0
    for x in a:
        hours += (x + h - 1) // h


    if hours <= k:
        r = h
    else:
        l = h + 1
print(l)