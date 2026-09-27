n = int(input())
a = list(map(int, input().split()))

p_freq = [0] * 1001
p_sum = [0] * 1001
for i in a:
    p_freq[i] += 1
    p_sum[i] += i

for x in range(1, 1001):
    p_freq[x] += p_freq[x - 1]
    p_sum[x] += p_sum[x - 1]

p = int(input())
for i in range(p):
    t = int(input())

    print(p_freq[t], p_sum[t])