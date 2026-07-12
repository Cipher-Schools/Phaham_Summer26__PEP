# Data types - sizes and binary connection
```
Type	    Size	      Range / Values	                      Use for
int	        4 bytes       (32 bits)	−2.1B to +2.1B	              Whole numbers - age, count, index
long long	8 bytes       (64 bits)	−9.2 quintillion to +9.2Q	  Very large numbers in DSA
float	    4 bytes	      ~7 decimal digits precision	          Decimal numbers (less precise)
double	    8 bytes	      ~15 decimal digits precision	          Decimal numbers (more precise)
char	    1 byte        (8 bits)	0–255 (ASCII)	              Single character: 'A', '5', '?'
bool	    1 byte	      true (1) or false (0)	                  Yes/no conditions
```
```
int age = 20;
double price = 99.99;
char grade = 'A';
bool passed = true;
```
```
cout << sizeof(int) << endl;      // 4 bytes
cout << sizeof(double) << endl;   // 8 bytes
cout << sizeof(char) << endl;     // 1 byte
```
The sizeof() operator tells you how many bytes a type uses. This directly connects to binary — int = 4 bytes = 32 bits = exactly the 2's complement range we calculated.

# Variables, cin/cout, and arithmetic
```
#include <iostream>
using namespace std;

int main() {
    int a, b;
    
    cout << "Enter two numbers: ";
    cin >> a >> b;           // cin reads from keyboard
    
    cout << "Sum: " << a + b << endl;
    cout << "Product: " << a * b << endl;
    cout << "Division: " << a / b << endl;  // integer division!
    cout << "Remainder: " << a % b << endl; // modulo operator
    
    return 0;
}
```
Gotcha - integer division: If a=7 and b=2, then a/b gives 3 (not 3.5). To get 3.5 you need (double)a / b. Integer division drops the decimal part.

# Conditionals - if / else if / else

```
#include <iostream>
using namespace std;

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;
    
    if (num > 0) {
        cout << "Positive" << endl;
    } else if (num < 0) {
        cout << "Negative" << endl;
    } else {
        cout << "Zero" << endl;
    }
    
    // Ternary operator - shorthand for simple if/else
    string result = (num >= 0) ? "Non-negative" : "Negative";
    cout << result << endl;
    
    return 0;
}
Analogy: A traffic light. If green → go. Else if yellow → slow down. Else (red) → stop. The program picks exactly one path, just like you pick one action at a traffic light.
```

# Loops - for and while
- for loop - when you know how many times

Use when you know the count in advance: "print 10 times", "go through 5 elements".
// Multiplication table of 5
for (int i = 1; i <= 10; i++) {
    cout << "5 x " << i << " = " << 5 * i << endl;
}

// for loop anatomy:
// for (initialization; condition; update)
//      ↑ int i=1        ↑ i<=10      ↑ i++

- while loop — when you don't know how many times
Use when you repeat "until something happens": "keep asking until valid input", "keep running until user quits".
int n;
cout << "Enter a positive number: ";
cin >> n;

while (n <= 0) {           // keep asking as long as input is invalid
    cout << "Invalid! Try again: ";
    cin >> n;
}

# Arrays — your first data structure
An array is a collection of items of the same type, stored in consecutive memory locations. Think of it like a row of numbered lockers - all lockers are the same size, and you access each one by its number (index).
Analogy: A train with numbered coaches - Coach 0, Coach 1, Coach 2... Each coach holds one item. You jump directly to any coach by its number. That's O(1) access — instant.

```
#include <iostream>
using namespace std;

int main() {
    int marks[5] =  {85, 90, 78, 92, 88};  // array of 5 integers
    //              [0]  [1]  [2]  [3]  [4]   ← indices (start at 0!)
    
    cout << marks[0] << endl;  // 85 (first element)
    cout << marks[4] << endl;  // 88 (last element)
    
    // Iterate through array using a loop
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        sum += marks[i];
    }
    cout << "Average: " << sum / 5.0 << endl;
    
    return 0;
}
Important: Arrays start at index 0, not 1. An array of size 5 has indices 0 to 4. Accessing index 5 is "out of bounds" - undefined behavior in C++.
```
# Time Complexity - Big O notation
Big O tells you how the number of steps your algorithm takes grows as the input size (n) grows. It's the language of comparing algorithms without worrying about hardware.

O(1) - Constant — best!
O(log n) - Logarithmic — great
O(n) - Linear — acceptable
O(n²) - Quadratic — slow
O(2ⁿ) - Exponential — avoid

# Space Complexity - memory cost
Time complexity = how long does it take. Space complexity = how much memory does it use. Both matter. Sometimes you trade one for the other - using more memory to make things faster (caching).
Analogy: You can solve a jigsaw puzzle by keeping all pieces in front of you (uses more table space = more memory, but faster). Or you can keep the pile in the box and pick one at a time (less space, slower). The choice depends on your constraints.

# Linear Search - your first algorithm
Start from the first element. Check each element one by one. If it matches your target, return its index. If you reach the end without finding it, return −1.
Real life: You lost your phone somewhere at home. You check room by room, drawer by drawer, until you find it or you've checked everywhere. That's linear search.

```
#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {       // go through each element
        if (arr[i] == target) {          // check if it matches
            return i;                    // found! return index
        }
    }
    return -1;                           // not found
}

int main() {
    int arr[] = {3, 8, 2, 7, 5, 1, 9};
    int n = 7;
    int target = 7;
    
    int result = linearSearch(arr, n, target);
    
    if (result != -1) {
        cout << "Found at index " << result << endl;  // Found at index 3
    } else {
        cout << "Not found" << endl;
    }
    return 0;
}
```

# Pointers - variables that store addresses
A pointer is just a variable whose job is to store a memory address. That's it. Instead of storing a number like 25, it stores an address like 0x61fe14.
Analogy: Your friend lives in flat 304. You can either be your friend (the actual person = variable), or you can hold a piece of paper with "flat 304" written on it (the pointer). The paper itself isn't your friend - but it tells you exactly where to find them.

```
#include <iostream>
using namespace std;
int main() {
    int age = 25;
    int* ptr = &age;   // ptr stores the address of age
                        // int* means "pointer to int"
    
    cout << ptr   << endl;   // prints address:  0x61fe14
    cout << *ptr  << endl;   // prints value:    25  (* = "go to that address and get value")
    
    *ptr = 30;               // change value AT that address
    cout << age   << endl;   // prints: 30  (age changed! ptr and age share the same memory)
    return 0;
}
The two pointer operators to memorize:
&variable = "give me the address of this variable" (address-of operator)
*pointer = "go to that address and get/set the value there" (dereference operator)
```

# References - a simpler alias
A reference is just another name (alias) for the same variable. Unlike a pointer, it can't be null, can't be reassigned to point elsewhere, and doesn't need * to use. In DSA you'll use references constantly for passing data into functions without copying.
Analogy: Your name is "Rahul". Your friends call you "Rocky". Both names refer to the same person. If Rocky gains weight, Rahul gained weight too - they're the same person, just different names. That's a reference.

```
int age = 25;
int& ref = age;   // ref is another name for age (note the & in declaration)

ref = 30;          // modifying ref modifies age
cout << age;       // prints: 30

// KEY USE - pass by reference in functions (avoids copying)
void addTen(int& x) {
    x += 10;        // modifies the original variable, not a copy
}

int score = 50;
addTen(score);
cout << score;      // prints: 60

Pass by value vs pass by reference: Without &, C++ copies your variable into the function. Changes inside don't affect the original. With &, it passes the actual variable - changes stick. This matters hugely in DSA when you pass arrays, vectors, or trees into functions.

```

# Dynamic memory - new and delete
So far, variables live on the stack - memory managed automatically, freed when the function ends. With new, you allocate on the heap - memory you control manually. You decide when it's created and when it's freed.
Analogy: Stack memory = a hotel room (booked automatically for your stay, returned when you leave). Heap memory = renting a flat (you book it yourself with new, and you must return it yourself with delete - if you forget, you're paying rent for an empty flat forever = memory leak).
Stack
Auto-managed, small, fast. Local variables live here. Gone when function ends.
Heap
Manual control, large. new to allocate, delete to free. Persists until you free it.

```
int* p = new int(42);   // allocate 1 int on heap, store 42
cout << *p;             // prints: 42
delete p;               // free the memory - ALWAYS do this
p = nullptr;            // safety: don't leave a dangling pointer

// Dynamic array on heap
int* arr = new int[5];  // allocate array of 5 ints
arr[0] = 10;
arr[1] = 20;
delete[] arr;           // use delete[] for arrays (not delete)
In DSA, new is used when building Linked Lists (new Node), Trees (new TreeNode), and Graphs. Each node is a heap-allocated object. You'll see this constantly from Linked Lists onwards.
```
