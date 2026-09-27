
class Node:
    def init(self, value):
        self.value = value
        self.next = None

n = int(input())
a = list(map(int, input().split()))

head = Node(a[0])
cur = head

for x in a[1:]:
    cur.next = Node(x)
    cur = cur.next

cur = head
while cur and cur.next:
    cur.next = cur.next.next
    cur = cur.next

cur = head
while cur:
    print(cur.value, end=' ')
    cur = cur.next