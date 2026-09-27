
class Node:
    def init(self, value):
        self.value = value
        self.next = None


n = int(input())

head = None
tail = None

for i in range(n):
    name = input()

    if head is None:
        head = Node(name)
        tail = head

    elif name != tail.value:
        tail.next = Node(name)
        tail = tail.next


# Count and print
cur = head
count = 0

while cur:
    count += 1
    cur = cur.next

print(count)

cur = head
while cur:
    print(cur.value)
    cur = cur.next