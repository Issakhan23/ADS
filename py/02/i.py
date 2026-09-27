
class Node:
    def init(self, value):
        self.value = value
        self.prev = None
        self.next = None


head = None
tail = None

while True:
    cmd = input().split()

    if cmd[0] == "add_front":
        node = Node(cmd[1])
        node.next = head

        if head:
            head.prev = node
        else:
            tail = node

        head = node
        print("ok")

    elif cmd[0] == "add_back":
        node = Node(cmd[1])
        node.prev = tail

        if tail:
            tail.next = node
        else:
            head = node

        tail = node
        print("ok")

    elif cmd[0] == "erase_front":
        if not head:
            print("error")
        else:
            print(head.value)
            head = head.next

            if head:
                head.prev = None
            else:
                tail = None

    elif cmd[0] == "erase_back":
        if not tail:
            print("error")
        else:
            print(tail.value)
            tail = tail.prev

            if tail:
                tail.next = None
            else:
                head = None

    elif cmd[0] == "front":
        print(head.value if head else "error")

    elif cmd[0] == "back":
        print(tail.value if tail else "error")

    elif cmd[0] == "clear":
        head = None
        tail = None
        print("ok")

    elif cmd[0] == "exit":
        print("goodbye")
        break