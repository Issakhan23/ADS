
class Node:
    def init(self, value):
        self.value = value
        self.next = None


n, k = map(int, input().split())
a = input().split()

head = Node(a[0])
cur = head

for x in a[1:]:
    cur.next = Node(x)
    cur = cur.next


if k > 0:
    cur = head

    for i in range(k - 1):
        cur = cur.next

    new_head = cur.next
    cur.next = None

    cur = new_head
    while cur.next:
        cur = cur.next

    cur.next = head
    head = new_head


cur = head
while cur:
    print(cur.value, end=' ')
    cur = cur.next