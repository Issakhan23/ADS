import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return



    n = int(input_data[0])
    p = [int(x) for x in input_data[1:]]

    ans = []
    pre_hash = 0

    for i in range(n):
        cur_hash = p[i]
        dif = cur_hash - pre_hash
        val = dif//(2**i)
        ch_co = val + 97
        ans.append(chr(ch_co))
        pre_hash = cur_hash

    print("".join(ans))


if __name__ == "__main__":
    solve()