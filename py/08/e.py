import sys


def solve():
  input_data = sys.stdin.read().split()
  if not input_data:
    return

  idx = 0
  while idx < len(input_data):
    n_str = input_data[idx]
    idx += 1
    n = int(n_str)
    if n == 0:
      break

    patterns = []
    for _ in range(n):
      patterns.append(input_data[idx])
      idx += 1

    text = input_data[idx]
    idx += 1

    MOD1 = 10**9 + 7
    MOD2 = 10**9 + 9
    P1 = 31
    P2 = 37

    text_len = len(text)
    pattern_lengths = set(len(p) for p in patterns)

    pow1 = [1] * (text_len + 1)
    pow2 = [1] * (text_len + 1)
    for i in range(1, text_len + 1):
      pow1[i] = (pow1[i - 1] * P1) % MOD1
      pow2[i] = (pow2[i - 1] * P2) % MOD2

    h1 = [0] * (text_len + 1)
    h2 = [0] * (text_len + 1)
    for i in range(text_len):
      val = ord(text[i]) - 96
      h1[i + 1] = (h1[i] * P1 + val) % MOD1
      h2[i + 1] = (h2[i] * P2 + val) % MOD2

    # Собираем частоты подстрок текста только для нужных длин паттернов
    freq = {}
    for m in pattern_lengths:
      if m > text_len:
        continue
      p1_m = pow1[m]
      p2_m = pow2[m]
      for j in range(text_len - m + 1):
        r = j + m
        sub1 = (h1[r] - h1[j] * p1_m) % MOD1
        sub2 = (h2[r] - h2[j] * p2_m) % MOD2
        if sub1 < 0:
          sub1 += MOD1
        if sub2 < 0:
          sub2 += MOD2
        h_key = (sub1 << 32) | sub2
        freq[h_key] = freq.get(h_key, 0) + 1

    counts = [0] * n
    max_count = 0

    for i, pat in enumerate(patterns):
      m = len(pat)
      if m > text_len:
        counts[i] = 0
        continue

      pat_h1 = 0
      pat_h2 = 0
      for char in pat:
        v = ord(char) - 96
        pat_h1 = (pat_h1 * P1 + v) % MOD1
        pat_h2 = (pat_h2 * P2 + v) % MOD2

      h_key = (pat_h1 << 32) | pat_h2
      cnt = freq.get(h_key, 0)
      counts[i] = cnt
      if cnt > max_count:
        max_count = cnt

    print(max_count)
    for i in range(n):
      if counts[i] == max_count:
        print(patterns[i])


if __name__ == "__main__":
  solve()