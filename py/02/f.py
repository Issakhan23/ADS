
class Node:
    def init(self, value):
        self.value = value
        self.next = None


def create_list(a):
    if not a:
        return None

    head = Node(a[0])
    cur = head

    for x in a[1:]:
        cur.next = Node(x)
        cur = cur.next

    return head


a = list(map(int, input().split()))
b = list(map(int, input().split()))

list1 = create_list(a[1:])
list2 = create_list(b[1:])

dummy = Node(0)
cur = dummy

while list1 and list2:
    if list1.value <= list2.value:
        cur.next = list1
        list1 = list1.next
    else:
        cur.next = list2
        list2 = list2.next

    cur = cur.next

if list1:
    cur.next = list1
else:
    cur.next = list2

cur = dummy.next

while cur:
    print(cur.value, end=' ')
    cur = cur.next