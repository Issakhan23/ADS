
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


prev = None
cur = head

while cur:
    next_node = cur.next
    cur.next = prev
    prev = cur
    cur = next_node

head = prev


cur = head
while cur:
    print(cur.value, end=' ')
    cur = cur.next