from bisect import bisect_left, bisect_right
n, k = map(int, input().split())
a = list(map(int, input().split()))

p = []
t = 0

for x in a:
    t += x
    p.append(t)

for _ in range(k):
    c = int(input())
    b = bisect_left(p, c)
    print(b + 1)