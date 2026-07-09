# What is STL and why does it matter?
STL (Standard Template Library) is C++'s built-in toolkit of ready-made data structures and algorithms. Instead of building a stack from scratch, you use stack<int>. Instead of coding a sort, you call sort(). In DSA classes and interviews, STL saves you hours.

# vector - dynamic array
- vector<T>

Use when: you need an array but don't know the size upfront, or need to add/remove from the end
Like an array that grows automatically. Internally doubles its capacity when full. Best replacement for raw arrays in most DSA problems.

push_back(val) - O(1) amortized
pop_back() - O(1)
v[i], v.at(i) - O(1)
v.size() - O(1)
insert at middle - O(n)
```
#include <vector>
vector<int> v;              // empty vector
v.push_back(10);            // [10]
v.push_back(20);            // [10, 20]
v.push_back(30);            // [10, 20, 30]

cout << v[1]      << endl; // 20
cout << v.size()  << endl; // 3
v.pop_back();               // [10, 20]

vector<int> v2(5, 0);      // [0, 0, 0, 0, 0]  — size 5, all zeros

for (int x : v) cout << x << " ";  // range-based for
```

# set and unordered_map
- set<T>

Use when: you need unique elements, automatically sorted
Stores only unique values, sorted in ascending order. Built on a balanced BST internally. Great for "find duplicates" or "keep unique elements" problems.

insert(val) - O(log n)
find(val) - O(log n)
erase(val) - O(log n)
count(val) - O(log n)

- set<int> s;
s.insert(30); s.insert(10); s.insert(20); s.insert(10); // duplicate ignored
for (int x : s) cout << x << " ";  // prints: 10 20 30  (sorted, unique)

if (s.find(20) != s.end()) cout << "Found!" << endl;

# unordered_map<K, V>
Use when: you need key→value lookup in O(1). Most common in DSA problems.
Stores key-value pairs using hashing. The go-to structure for frequency counting, caching, and two-sum type problems. Unordered = no sorting, but faster than map.

mp[key] = val - O(1) avg
mp.find(key) - O(1) avg
mp.count(key) - O(1) avg
mp.erase(key) - O(1) avg

```
unordered_map<string, int> freq;

// Count word frequencies
string words[] = {"apple","banana","apple","cherry","banana","apple"};
for (string w : words) freq[w]++;

cout << freq["apple"]  << endl;  // 3
cout << freq["banana"] << endl;  // 2

// Iterate
for (auto& pair : freq)
    cout << pair.first << ": " << pair.second << endl;
```
Analogy: unordered_map is like a phone contact list - you type "Rahul" and instantly get his number. You don't search through all contacts sequentially - the phone's internal hashing jumps straight to the entry. O(1) lookup.

# map - sorted key-value pairs
- map<K, V>

Use when: you need key→value pairs AND need them sorted by key
Like unordered_map but keys are always sorted. Slower than unordered_map (O(log n) vs O(1)) but useful when order matters - e.g. printing results in alphabetical/numerical order.
```
map<string, int> scores;
scores["Rahul"] = 95;
scores["Arjun"] = 88;
scores["Zara"]  = 91;

for (auto& [name, score] : scores)   // structured binding (C++17)
    cout << name << ": " << score << endl;
// Output (alphabetical):
// Arjun: 88
// Rahul: 95
// Zara: 91 
```

# queue and deque
- queue<T>

Use when: FIFO — first in, first out (like a real queue)
Elements enter from the back, leave from the front. Critical for BFS (Breadth First Search) in graphs and trees, and for level-order traversal.
push(val) - O(1)
pop() - O(1)
front(), back() - O(1)
queue<int> q;
q.push(10); q.push(20); q.push(30);
// queue: 10 → 20 → 30  (10 is at front, 30 at back)

cout << q.front() << endl;  // 10  (first in)
q.pop();                     // removes 10
cout << q.front() << endl;  // 20  (now first)

- deque<T>

Use when: you need to add/remove from BOTH ends efficiently
Double-ended queue. Supports push/pop at both front AND back in O(1). Used in sliding window problems and monotonic deque patterns — common in intermediate DSA.

push_front/back() - O(1)
pop_front/back() - O(1)
d[i] random access - O(1)
```
deque<int> dq;
dq.push_back(10);   // [10]
dq.push_front(5);   // [5, 10]
dq.push_back(20);   // [5, 10, 20]
dq.pop_front();     // [10, 20]
cout << dq[0];      // 10
```

# priority_queue - the heap
priority_queue<T>
Use when: you always want the largest (or smallest) element instantly
Not a FIFO queue — it always gives you the highest-priority element. By default: max at top. Internally a max-heap. Used in Dijkstra's algorithm, top-K problems, and scheduling.

push(val) - O(log n)
top() - O(1) - always max!
pop() - O(log n)

```
priority_queue<int> maxpq;     // max-heap (default)
maxpq.push(30);
maxpq.push(10);
maxpq.push(50);
maxpq.push(20);
cout << maxpq.top() << endl;  // 50 (always the largest)
maxpq.pop();
cout << maxpq.top() << endl;  // 30

// Min-heap (gives smallest first)
priority_queue<int, vector<int>, greater<int>> minpq;
minpq.push(30); minpq.push(10); minpq.push(50);
cout << minpq.top() << endl;  // 10
```
Analogy: A hospital emergency room. Patients don't wait in line - the most critically ill person is always seen first, regardless of when they arrived. Priority queue does the same: always pulls the highest-priority (largest or smallest) item first.

# Iterators and algorithms
An iterator is like a pointer that moves through an STL container. Every container has .begin() (first element) and .end() (one past last). STL algorithms like sort, find, reverse all take iterators as input.
```
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v = {64, 12, 93, 7, 45};

// sort
sort(v.begin(), v.end());               // ascending: 7 12 45 64 93
sort(v.begin(), v.end(), greater<int>()); // descending: 93 64 45 12 7

// find
auto it = find(v.begin(), v.end(), 45);
if (it != v.end())
    cout << "Found at index: " << (it - v.begin()) << endl;

// reverse
reverse(v.begin(), v.end());

// min and max element
cout << *min_element(v.begin(), v.end()) << endl;
cout << *max_element(v.begin(), v.end()) << endl;

// count occurrences
vector<int> nums = {1,2,2,3,2,4};
cout << count(nums.begin(), nums.end(), 2) << endl; // 3

// binary search (array must be sorted first)
sort(nums.begin(), nums.end());
cout << binary_search(nums.begin(), nums.end(), 3) << endl; // 1 (true)
```
The pattern algo(v.begin(), v.end(), ...) is universal in STL. Learn it once, apply it to any container. These algorithms are O(n log n) for sort, O(n) for find/count/reverse, O(log n) for binary_search.