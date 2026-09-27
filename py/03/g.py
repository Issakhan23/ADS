n, k = map(int, input().split())
a = list(map(int, input().split()))


l = 0.0
r = max(a) + 1

for _ in range(45):
    m = (l + r) / 2
    
    p = 0
    for x in a:
        p += int(x/m)

        if p >= k:
            break

    if p >= k:
        l = m
    else:
        r = m

print(f"{l:.9f}")