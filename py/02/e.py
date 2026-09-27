
class Node:
    def __init__(self, value):
        self.value = value
        self.next = None


n = int(input())
a = list(map(int, input().split()))

if n == 1:
    print()
else:
    head = Node(a[0])
    cur = head

    for x in a[1:]:
        cur.next = Node(x)
        cur = cur.next

    
    position = n // 2 - 1

    if position == 0:
        head = head.next
    else:
        cur = head

        for i in range(position):
            cur = cur.next

        cur.next = cur.next.next

    cur = head

    while cur:
        print(cur.value, end=' ')
        cur = cur.next