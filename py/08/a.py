import sys


def solve():
    input_data = sys.stdin.read().splitlines()
    if not input_data:
        return

    n = int(input_data[0].strip())
    elements = []
    for line in input_data[1:]:
        if line.strip():
            elements.append(line.strip())

    MOD = 10**9 + 7

    def calc_hash(s):
        h = 0
        power = 1
        for char in s:
            val = ord(char) - 47
            h = (h + val * power) % MOD
            power = (power * 11) % MOD
        return str(h)

    element_counts = {}
    for el in elements:
        element_counts[el] = element_counts.get(el, 0) + 1

    results = []
    for el in elements:
        if el.isdigit():
            h_val = calc_hash(el)
            if h_val in element_counts:
                results.append((el, h_val))

    for s, h in results[:n]:
        print(f'Hash of string "{s}" is {h}')


if __name__ == "__main__":
    solve()