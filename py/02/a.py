
from collections import deque

n = int(input())

for _ in range(n):
    k = int(input())
    t = input().split()

    count = {}
    queue = deque()

    for x in t:
        if x not in count:
            count[x] = 1
        else:
            count[x] += 1

        if count[x] == 1:
            queue.append(x)

        while queue and count[queue[0]] > 1:
            queue.popleft()

        if queue:
            print(queue[0], end=' ')
        else:
            print(-1, end=' ')

    print()