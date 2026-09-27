n, k = map(int, input().split())
a = list(map(int, input().split()))

left = 0.0
right = max(a)

for _ in range(100):
    mid = (left + right) / 2

    pieces = 0

    for x in a:
        pieces += int(x / mid)

    if pieces >= k:
        left = mid
    else:
        right = mid

print(f"{left:.9f}")