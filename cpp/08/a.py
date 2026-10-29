n = int(input())
p = []
for i in range(2*n):
    p.append(input().strip())
c = 0
mod = 10**9 + 7
b = 11

hash_table = set(p)

for s in p:
    h = 0
    pw = 1
    for i in s:
        h = (h + (ord(i) - 47) * pw) % mod
        pw = pw * b % mod
    if str(h) in hash_table:
        c+=1
        print(f'Hash of string "{s}" is {h}')
    if c == n:
        break

# ичключение