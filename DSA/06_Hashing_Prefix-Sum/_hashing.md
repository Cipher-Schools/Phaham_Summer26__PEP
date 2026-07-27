# Hash Function
A hash function takes any input (a string, a number, an object) and converts it into a fixed-size number called a hash code. That number is then used as an index into an array of "buckets". The goal: jump directly to where data should be, instead of searching for it.
Analogy: a library where every book's call number is computed instantly from its title — no card catalog needed. You don't search shelf by shelf; you compute the shelf number directly from the book's name and walk straight there. That computation is the hash function. The shelf is the bucket.

- Why this beats arrays and search : 

O(n) - Linear search through array
O(log n) - Binary search (sorted only)
O(1) - Hashmap lookup (average case)
No comparisons needed, no sorting needed, no traversal needed. Compute the hash, jump to the bucket, done.

```
Step 1: hash() converts key → a large number
For strings, a common approach is to combine character codes: treat the string like a number in some base (often 31 or 37), multiply and add as you go. The exact formula doesn't matter for using a hashmap — what matters is that it's fast, deterministic (same input always gives same output), and spreads inputs evenly across possible numbers.
// A simple string hash function (polynomial rolling hash)
int simpleHash(string s) {
    long hash = 0;
    int p = 31;          // a prime base
    for (char c : s) {
        hash = hash * p + c;
    }
    return hash;
}
// "cat" → ('c'*31 + 'a')*31 + 't' → some large number
// Same string ALWAYS produces the same hash — this is essential.
```
```
Step 2: modulo maps the number → a bucket index
The hash code can be huge (millions, billions). The table only has a fixed number of buckets (say, 16 or 1024). Taking hash % numBuckets squeezes any number into a valid index range.
int bucketIndex = hashCode % numBuckets;
// hashCode = 2348177, numBuckets = 5
// bucketIndex = 2348177 % 5 = 2
// "banana" always lands in bucket 2 — every single time you look it up.
This is why hashmap operations are O(1): computing the hash is O(key length), and modulo is O(1). No matter how many elements are already stored, finding the right bucket takes the same constant time.
```

# When two keys land in the same bucket

A collision happens when two different keys hash to the same bucket index. This is unavoidable - with infinite possible keys and a finite number of buckets, collisions WILL happen eventually (pigeonhole principle). The question isn't "how do we avoid them" but "how do we handle them gracefully".
Analogy: two students are assigned the same locker number by mistake. You don't refuse the second student a locker - you put a small shelf divider inside, so locker 12 now holds two students' bags, each labeled with a name tag. Finding a specific bag means going to locker 12, then checking name tags. Slightly slower than a perfect 1-to-1 system, but still way faster than searching all lockers.

```
Chaining — the standard solution
Each bucket doesn't hold one item — it holds a small list (chain) of items. When a collision happens, the new item is appended to that bucket's list. To find a key, hash to the bucket, then scan the short list inside it (usually just 1-2 items if the table is sized well).
// Conceptual structure of a hashmap bucket array (simplified)
vector<list<pair<string,int>>> buckets(numBuckets);

void insert(string key, int value) {
    int idx = hash(key) % numBuckets;
    buckets[idx].push_back({key, value});   // append to that bucket's chain
}

int get(string key) {
    int idx = hash(key) % numBuckets;
    for (auto& [k, v] : buckets[idx]) {     // scan the small chain
        if (k == key) return v;
    }
    return -1;   // not found
}
// If buckets are well-distributed, each chain has ~1 item → O(1) average
// Worst case (everything hashes to one bucket): O(n) - but this is rare with a good hash function
If the hash function is poor (e.g., everyone's key hashes to bucket 0), every operation degrades to O(n) - you're back to a linked list. This is why a well-designed hash function matters: it should spread keys evenly across all buckets, not cluster them.
```
- Other Collition solution involve probing (linear probing, quadratic probing), double hashing

```
Load factor = (number of elements) / (number of buckets). As more keys are inserted, chains get longer, and lookups slow down toward O(n). To prevent this, hashmaps automatically resize (usually double) the bucket array once load factor crosses a threshold (commonly 0.75), then re-hash every existing key into the new, bigger table.
Load factor - 0.40
Healthy - most buckets near-empty, lookups stay fast
This is exactly why hashmap operations are described as "O(1) amortized average case" rather than a strict guarantee. The occasional resize costs O(n), but it happens rarely enough (doubling means exponentially fewer resizes over time) that the average cost per operation stays O(1).
```

