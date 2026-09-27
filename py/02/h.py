
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
current_sum = cur.value
max_sum = cur.value

cur = cur.next

while cur:
    current_sum = max(cur.value, current_sum + cur.value)
    max_sum = max(max_sum, current_sum)

    cur = cur.next

print(max_sum)