n, k = map(int, input().split())
a = list(map(int, input().split()))

if k == 0:
    print(1)
    exit()

l = 0
cur_sum = 0
ans = n

for r in range(n):
    cur_sum += a[r]

    while cur_sum >= k:
        ans = min(ans, r - l + 1)
        cur_sum -= a[l]
        l += 1

print(ans)