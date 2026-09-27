n, k = map(int, input().split())
a = list(map(int, input().split()))

left = 0
current_sum = 0
answer = n

for right in range(n):
    current_sum += a[right]

    while current_sum >= k:
        answer = min(answer, right - left + 1)
        current_sum -= a[left]
        left += 1

print(answer)