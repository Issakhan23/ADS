import sys


def solve():
  input_data = sys.stdin.read().split()
  if not input_data:
    return

  n = int(input_data[0])
  p = [int(x) for x in input_data[1:]]

  ans = []
  prev_hash = 0
  for i in range(n):
    curr_hash = p[i]
    diff = curr_hash - prev_hash
    val = diff // (2**i)
    char_code = val + 97
    ans.append(chr(char_code))
    prev_hash = curr_hash

  print("".join(ans))


if __name__ == "__main__":
  solve()