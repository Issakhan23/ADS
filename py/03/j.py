n, k = map(int, input().split())
a = []

for _ in range(n):
    x1, y1, x2, y2 = map(int, input().split())
    a.append(max(x2, y2))

a.sort()
print(a[k-1])