# Linked List
A linked list is a chain of nodes. Each node holds a value and a pointer to the next node. Unlike arrays, nodes are not contiguous in memory - each node lives anywhere in RAM and holds the address of the next one. The last node's pointer is nullptr.

- Analogy: a treasure hunt. Each clue (node) has the treasure (data) and the location of the next clue (next pointer). You can't jump to clue 5 directly - you must follow the chain from clue 1. That's the trade-off: no random access, but you can insert and delete anywhere in O(1) if you already have the pointer.

```
Node structure - 

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

```

```
Implementation - 

class LinkedList {
public:
    Node* head = nullptr;

    void pushFront(int val) {            // Insert at beginning — O(1)
        Node* node = new Node(val);
        node->next = head;
        head = node;
    }
    void pushBack(int val) {             // Insert at end — O(n)
        Node* node = new Node(val);
        if (!head) { head = node; return; }
        Node* curr = head;
        while (curr->next) curr = curr->next;
        curr->next = node;
    }
    void traverse() {                    // Print all nodes — O(n)
        Node* curr = head;
        while (curr) {
            cout << curr->data << " → ";
            curr = curr->next;
        }
        cout << "null" << endl;
    }
    int length() {                       // Count nodes — O(n)
        int len = 0;
        Node* curr = head;
        while (curr) { len++; curr = curr->next; }
        return len;
    }
    bool search(int val) {               // Find a value — O(n)
        Node* curr = head;
        while (curr) {
            if (curr->data == val) return true;
            curr = curr->next;
        }
        return false;
    }
};
```
