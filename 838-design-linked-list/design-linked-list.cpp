class MyLinkedList {
public:
    struct Node {
        int data;
        Node* next;
        Node(int data, Node* next = nullptr) : data(data), next(next) {}
    };

    Node* head;

    MyLinkedList() {
        head = nullptr;
    }

    int get(int index) {
        int i = 0;
        Node* temp = head;
        while (temp != nullptr && i < index) {
            temp = temp->next;
            i++;
        }
        if (temp == nullptr) return -1;
        return temp->data;
    }

    void addAtHead(int val) {
        Node* node = new Node(val, head);
        head = node;
    }

    void addAtTail(int val) {
        Node* node = new Node(val);
        if (!head) {
            head = node;
            return;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = node;
    }

    void addAtIndex(int index, int val) {
        if (index == 0) {
            addAtHead(val);
            return;
        }
        int i = 0;
        Node* temp = head;
        while (temp != nullptr && i < index - 1) {
            temp = temp->next;
            i++;
        }
        if (temp == nullptr) return;  // Index out of bounds
        Node* node = new Node(val, temp->next);
        temp->next = node;
    }

    void deleteAtIndex(int index) {
        if (!head) return;
        if (index == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        int i = 0;
        Node* temp = head;
        while (temp->next != nullptr && i < index - 1) {
            temp = temp->next;
            i++;
        }
        if (temp->next == nullptr) return; // Index out of bounds
        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }
};
