import sys


def solve():
  input_data = sys.stdin.read().split()
  if not input_data:
    print(0)
    return

  s = input_data[0]
  n = len(s)
  if n == 0:
    print(0)
    return

  MOD1 = 10**9 + 7
  MOD2 = 10**9 + 9
  P1 = 31
  P2 = 37

  pow1 = [1] * (n + 1)
  pow2 = [1] * (n + 1)
  for i in range(1, n + 1):
    pow1[i] = (pow1[i - 1] * P1) % MOD1
    pow2[i] = (pow2[i - 1] * P2) % MOD2

  h1 = [0] * (n + 1)
  h2 = [0] * (n + 1)
  for i in range(n):
    val = ord(s[i]) - 96
    h1[i + 1] = (h1[i] * P1 + val) % MOD1
    h2[i + 1] = (h2[i] * P2 + val) % MOD2

  distinct_hashes = set()
  add = distinct_hashes.add

  for length in range(1, n + 1):
    p1_len = pow1[length]
    p2_len = pow2[length]
    for i in range(n - length + 1):
      r = i + length
      val1 = (h1[r] - h1[i] * p1_len) % MOD1
      val2 = (h2[r] - h2[i] * p2_len) % MOD2
      if val1 < 0:
        val1 += MOD1
      if val2 < 0:
        val2 += MOD2
      
      add((val1 << 32) | val2)

  print(len(distinct_hashes))


if __name__ == "__main__":
  solve()