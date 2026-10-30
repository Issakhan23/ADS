struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

int main() {

    Node* head = nullptr;
    Node* tail = nullptr;

    for () {
        cin >> x;
        Node* newNode = new Node(x);
        if (head == nullptr) {
            head = newNode;
            tail = newNode
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    Node* prev = nullptr;
    Node* cur = head;






}