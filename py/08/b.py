import sys


def solve():
  input_data = sys.stdin.read().split()
  if not input_data:
    return

  s1 = input_data[0]
  s2 = input_data[1]
  t = input_data[2]

  MOD1 = 10**9 + 7
  MOD2 = 10**9 + 9
  P1 = 31
  P2 = 37

  n = len(s1)
  m = len(t)

  if len(s2) != n or m > n:
    print(0)
    return

  pow1 = [1] * (n + 1)
  pow2 = [1] * (n + 1)
  for i in range(1, n + 1):
    pow1[i] = (pow1[i - 1] * P1) % MOD1
    pow2[i] = (pow2[i - 1] * P2) % MOD2

  h1_t = 0
  h2_t = 0
  for char in t:
    val = ord(char) - 96
    h1_t = (h1_t * P1 + val) % MOD1
    h2_t = (h2_t * P2 + val) % MOD2

  h1_s1 = [0] * (n + 1)
  h2_s1 = [0] * (n + 1)
  h1_s2 = [0] * (n + 1)
  h2_s2 = [0] * (n + 1)

  for i in range(n):
    v1 = ord(s1[i]) - 96
    v2 = ord(s2[i]) - 96
    h1_s1[i + 1] = (h1_s1[i] * P1 + v1) % MOD1
    h2_s1[i + 1] = (h2_s1[i] * P2 + v2) % MOD2
    h1_s2[i + 1] = (h1_s2[i] * P1 + v1) % MOD1
    h2_s2[i + 1] = (h2_s2[i] * P2 + v2) % MOD2

  count = 0
  for i in range(n - m + 1):
    r = i + m
    sub1_1 = (h1_s1[r] - h1_s1[i] * pow1[m]) % MOD1
    sub2_1 = (h2_s1[r] - h2_s1[i] * pow2[m]) % MOD2
    if sub1_1 == h1_t and sub2_1 == h2_t:
      sub1_2 = (h1_s2[r] - h1_s2[i] * pow1[m]) % MOD1
      sub2_2 = (h2_s2[r] - h2_s2[i] * pow2[m]) % MOD2
      if sub1_2 == h1_t and sub2_2 == h2_t:
        count += 1

  print(count)


if __name__ == "__main__":
  solve()