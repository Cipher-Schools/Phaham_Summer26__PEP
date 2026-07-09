# Classes and objects - only what DSA needs
A class is a blueprint. An object is something built from that blueprint. In DSA, you use classes to define node structures — like a Linked List node that holds a value and a pointer to the next node.
Analogy: A class is like the blueprint of a house. The object is the actual house built from it. The blueprint says "this house has 2 bedrooms and 1 kitchen". Each house built from it is a separate object with its own bedroom contents.
```
#include <iostream>
using namespace std;

class Student {
public:              // public = accessible from outside the class
    string name;
    int age;
    float gpa;
    
    void display() {
        cout << name << " | Age: " << age << " | GPA: " << gpa << endl;
    }
};

int main() {
    Student s1;         // s1 is an object (instance) of Student
    s1.name = "Rahul";
    s1.age = 20;
    s1.gpa = 8.5;
    s1.display();       // Rahul | Age: 20 | GPA: 8.5
    return 0;
}
```

-----------------

# Constructor - automatic setup
A constructor is a special function that runs automatically when an object is created. It has the same name as the class and no return type. Use it to set initial values so your object is ready to use the moment it's created.
Analogy: When a new employee joins a company, HR automatically fills in their ID card, assigns an email, and gives them a badge. You don't call a "setup" function manually — it just happens when they join. That automatic setup is the constructor.
```
class Node {               // This is the core building block of Linked Lists
public:
    int data;
    Node* next;            // pointer to the next node
    
    Node(int val) {        // Constructor — called automatically when Node is created
        data = val;
        next = nullptr;    // no next node yet
    }
};

int main() {
    Node* n1 = new Node(10);   // constructor runs: data=10, next=nullptr
    Node* n2 = new Node(20);
    n1->next = n2;             // n1 points to n2 (arrow notation for pointer to object)
    
    cout << n1->data << endl;        // 10
    cout << n1->next->data << endl;  // 20
    return 0;
}
```
n1->data is shorthand for (*n1).data — "go to what n1 points to, then get data". The arrow -> is used whenever you access members through a pointer. You'll use this every single day in DSA.

# The this keyword
Inside a class method, this is a pointer that refers to the current object itself. You need it when the constructor parameter has the same name as the member variable — otherwise there's ambiguity about which "data" you mean.
```
class Node {
public:
    int data;
    Node* next;
    
    Node(int data) {          // parameter name = same as member name
        this->data = data;    // this->data = member variable
                              // data (alone) = the parameter
        this->next = nullptr;
    }
};
```
Without "this->", the compiler doesn't know which "data" you mean.
this->data = the object's own data field
data       = the constructor argument

Analogy: In a classroom, two students are both named "Arjun". The teacher says "Arjun, tell Arjun your answer." Ambiguous! If one says "this Arjun" while pointing to himself, it's clear. this is exactly that - the current object pointing to itself.
