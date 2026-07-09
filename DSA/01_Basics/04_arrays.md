# What is an array and how is it laid out in memory
An array is a contiguous block of memory - all elements sit right next to each other, no gaps. This is what makes arrays fast: to find element at index i, the computer does one calculation: base_address + i × size_of_type. No searching needed — instant.
Analogy: A row of lockers in a school. All lockers are the same size, numbered from 0, and sit right next to each other. To reach locker 5, you don't search — you just walk exactly 5 lockers from the start. That's O(1) access.

Each int = 4 bytes, so addresses jump by 4. arr[3] = base + 3×4 = 1000+12 = address 1012. The CPU computes this in one step - that's why array access is O(1).

# Declaration, initialization, input/output
// Declaration - fixed size, known at compile time
```
int arr[5];                          // 5 ints, values garbage (uninitialized)
int scores[5] = {85, 90, 78, 92, 88}; // declare + initialize
int zeros[5] = {0};                  // all zeros
int auto_size[] = {1, 2, 3, 4};     // compiler figures out size = 4

// Input — read from user
int n = 5;
int a[100];
for (int i = 0; i < n; i++) {
    cin >> a[i];
}

// Output - print all
for (int i = 0; i < n; i++) {
    cout << a[i] << " ";
}
cout << endl;

// Cleaner with range-based for (C++11)
for (int x : scores) {
    cout << x << " ";
}
```
# CRUD operations on arrays — interactive demo
CRUD = Create, Read, Update, Delete. These are the four fundamental operations on any data - arrays 
```
int arr[10] = {10, 20, 30, 40, 50};
int n = 5;  // current number of elements

// READ - O(1)
cout << arr[2];  // 30

// UPDATE - O(1)
arr[2] = 99;

// INSERT at position pos - O(n) because we shift elements right
int pos = 2, val = 99;
for (int i = n; i > pos; i--)
    arr[i] = arr[i-1];   // shift right
arr[pos] = val;
n++;                     // array grew by 1

// DELETE at position pos - O(n) because we shift elements left
for (int i = pos; i < n-1; i++)
    arr[i] = arr[i+1];   // shift left
n--;                     // array shrank by 1
```
Insert and delete in arrays are O(n) - you have to shift elements. This is why Linked Lists exist: they insert/delete in O(1) once you have the position. Arrays win on random access (O(1)); Linked Lists win on insert/delete.

# Traversal, min, max, sum
```
#include <iostream>
using namespace std;

int main() {
    int arr[] = {64, 12, 93, 7, 45, 28};
    int n = 6;
    
    int sum = 0, minVal = arr[0], maxVal = arr[0];
    
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        if (arr[i] < minVal) minVal = arr[i];
        if (arr[i] > maxVal) maxVal = arr[i];
    }
    
    cout << "Sum: "     << sum << endl;           // 249
    cout << "Average: " << (double)sum/n << endl; // 41.5
    cout << "Min: "     << minVal << endl;         // 7
    cout << "Max: "     << maxVal << endl;         // 93
    return 0;
}
```