from bisect import bisect_left, bisect_right

n, k = map(int, input().split())
p = list(map(int, input().split()))

p.sort()

def count(l, r):
    return bisect_right(p, r) - bisect_left(p, l)


for _ in range(k):
    l1, r1, l2, r2 = map(int, input().split())
    ans = count(l1, r1) + count(l2, r2)
    left = max(l1, l2)
    right = min(r1, r2)

    if left <= right:
        ans -= count(left, right)
    print(ans)