
class Node(object):
    def init(self, val=0, next=None):
        self.val : int = val        
        self.next: Node = next

def insert(head: Node, node: Node, p: int): # return new head of linked list   
    if p == 0:
        old = head
        head = node
        head.next = old
    else:
        cnt = 0
        current = head
        while cnt < p - 1:
            current = current.next
            cnt += 1
        tail = current.next
        current.next = node
        node.next = tail
    return head
def remove(head: Node, p: int): # return new head of linked list    
    if p == 0:
        first = head.next
        head = None
        head = first
    else:
        cnt = 0
        current = head
        while cnt < p - 1:
            current = current.next
            cnt += 1
        second = current.next.next if current.next is not None else None
        current.next = second
    return head

def printAll(head: Node): # void function
    if head is None:
        print(-1)
    else:
        current = head
        while current is not None:
            print(current.val, end=" ")
            current = current.next
        print()

def replace(head: Node, p1: int, p2: int):
    current = head
    prev = None

    for i in range(p1):
        prev = current
        current = current.next

    if prev is None:
        head = current.next
    else:
        prev.next = current.next

    if p2 == 0:
        current.next = head
        head = current
    else:
        prev = head
        for i in range(p2 - 1):
            prev = prev.next

        current.next = prev.next
        prev.next = current

    return head

def reverse(head: Node):  # return head of new linked list    
    current = head
    prev = None
    while current is not None:
        temp = current.next
        current.next = prev
        prev = current
        current = temp
    return prev

def cyclic_left(head: Node, x: int):
    if x == 0:
        return head

    cur = head

    for i in range(x - 1):
        cur = cur.next

    new_head = cur.next

    tail = new_head
    while tail.next:
        tail = tail.next

    tail.next = head
    cur.next = None

    return new_head


def cyclic_right(head: Node, x: int):
    if x == 0:
        return head

    n = 0
    cur = head

    while cur:
        n += 1
        cur = cur.next

    return cyclic_left(head, n - x)


head: Node = None 
while(True):
    vals = [int(i) for i in input().split()]
    if (vals[0] == 0):
        break    
    elif (vals[0] == 1):
        head = insert(head, Node(vals[1]), vals[2])
    elif (vals[0] == 2):
        head = remove(head, vals[1])
    elif (vals[0] == 3):
        printAll(head)
    elif (vals[0] == 4):
        head = replace(head, vals[1], vals[2])
    elif (vals[0] == 5):
        head = reverse(head)
    elif (vals[0] == 6):
        head = cyclic_left(head, vals[1])
    elif (vals[0] == 7):
        head = cyclic_right(head, vals[1])