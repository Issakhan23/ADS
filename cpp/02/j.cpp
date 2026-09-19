#include <iostream> 
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node (int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

Node* head = nullptr;
Node* tail = nullptr;
int ls = 0;

Node* getNode(int index) {
    if (index < 0 || index >= ls) {
        return nullptr;
    }
    Node* current = nullptr;
    if (index < ls / 2) {
        current = head;
        for (int i = 0; i < index; ++i) {
            current = current -> next;
        }
    } else {
        current = tail;
        for (int i = ls - 1; i > index; --i) {
            current = current -> prev;
        }
    }
    return current;
}

void ins(int x, int p) {
    Node* newNode = new Node(x);
    if (p == 0) {
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            newNode -> next = head;
            head -> prev = newNode;
            head = newNode;
        }
    } else if (p == ls) {
        if (tail == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode -> prev = tail;
            tail = newNode;
        }
    } else {
        Node* current = getNode(p);
        Node* prevNode = current -> prev;
        prevNode -> next = newNode;
        newNode -> prev = prevNode;
        newNode -> next = current;
        current -> prev = newNode;
    }
    ls++;
}

void remove(int p) {
    if (head == nullptr) {
        return;
    }
    Node* del = getNode(p);
    if (!del) {
        return;
    }
    if (del == head) {
        head = head -> next;
        if (head) head -> prev = nullptr;
        else tail = nullptr;
    } else if (del == tail) {
        tail = tail -> prev;
        if (tail) tail -> next = nullptr;
        else head = nullptr;
    } else {
        Node* pNode = del->prev;
        Node* nNode = del -> next;
        pNode -> next = nNode;
        nNode -> prev = pNode;
    }
    delete del;
    ls--;
}

void print() {
    if (head == nullptr) {
        cout << "-1" << endl;
        return;
    }
    Node* current = head;
    while (current != nullptr) {
        cout << current -> data << (current-> next ? " " : "");
        current = current -> next;
    }
    cout << endl;
}

void replace(int p1, int p2) {
    if (p1 == p2 || head == nullptr) return;
    Node* move = getNode(p1);
    int val = move->data;
    if (move == head) {
        head = head -> next;
        if (head) head -> prev = nullptr;
        else tail = nullptr;
    } else if (move == tail) {
        tail = tail -> prev;
        if (tail) tail -> next = nullptr;
        else head = nullptr;
    } else {
        move -> prev -> next = move -> next;
        move -> next -> prev = move -> prev;
    }
    delete move;
    ls--;

    Node* newNode = new Node(val);
    if (p2 == 0) {
        if(!head) head = tail = newNode;
        else {
            newNode -> next = head;
            head -> prev = newNode;
            head = newNode;
        }
    } else if (p2 == ls) {
        if (!tail) head = tail = newNode;
        else {
            tail -> next = newNode;
            newNode -> prev = tail;
            tail = newNode;
        }
    } else {
        Node* current = getNode(p2);
        Node* prevNode = current -> prev;
        prevNode -> next = newNode;
        newNode -> prev = prevNode;
        newNode -> next = current;
        current -> prev = newNode;
    }
    ls++;
}

void reverse() {
    if (!head) return;
    Node* current = head;
    Node* temp = nullptr;
    while (current != nullptr) {
        temp = current -> prev;
        current -> prev = current -> next;
        current -> next = temp;
        current = current -> prev;
    }
    temp = head;
    head = tail;
    tail = temp;
}

void cycleL(int x) {
    if (x <= 0 || ls <= 1) return;
    Node* newHead = getNode(x);
    Node* newTail = newHead -> prev;
    Node* oldHead = head;
    Node* oldTail = tail;

    newTail -> next = nullptr;
    //newHead -> prev -> next = nullptr;
    //newHead -> prev = nullptr;
    oldTail -> next = oldHead;
    oldHead -> prev = oldTail;
    //head = newHead;
    //tail = newHead -> prev;

    //Node* newTail = newHead -> prev;
    //newTail -> next = nullptr;
    newHead -> prev = nullptr;

    oldTail -> next = oldHead;
    oldHead -> prev = oldTail;

    head = newHead;
    tail = newTail;
}

void cycleR(int x) {
    if (x <= 0 || ls <= 1) return;
    int newTailindex = ls - 1 - x;
    Node* newTail = getNode(newTailindex);
    Node* newHead = newTail -> next;

    if (!newHead) return;
    Node* oldHead = head;
    newTail -> next = nullptr;
    tail -> next = oldHead;
    oldHead -> prev = tail;
    newHead -> prev = nullptr;

    head = newHead;
    tail = newTail;
}

int main() {
    int c;
    while (cin >> c) {
        if (c == 0) {
            break;
        } else if (c == 1) {
            int x, p;
            cin >> x >> p;
            ins(x, p);
        } else if (c == 2) {
            int p;
            cin >> p;
            remove(p);
        } else if (c == 3) {
            print();
        } else if (c == 4) {
            int p1, p2;
            cin >> p1 >> p2;
            replace(p1, p2);
        } else if (c == 5) {
            reverse();
        } else if (c == 6) {
            int x;
            cin >> x;
            cycleL(x);
        } else if (c == 7) {
            int x;
            cin >> x;
            cycleR(x);
        }
    }


    return 0;
}