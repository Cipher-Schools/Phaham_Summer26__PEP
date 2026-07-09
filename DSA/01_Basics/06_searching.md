# Linear search
Check every element one by one from the start. No precondition needed — works on any array, sorted or not. Simple but slow for large inputs.
You lost your keys somewhere at home. You check every room, every drawer, one by one until you find them - or confirm they're lost. That's linear search. Works on a messy house (unsorted). Worst case: last drawer.
```
int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target)
            return i;      // found — return index
    }
    return -1;             // not found
}
// Time:  O(n)  - worst case checks every element
// Space: O(1)  - no extra memory used
```

# Binary search
Only works on a sorted array. Each step eliminates half the remaining elements. Instead of checking one at a time, you ask "is the target in the left half or right half?" and discard the other half entirely.
A dictionary has 1000 pages. You open to page 500. The word you want comes after "M" — so you rip out pages 1-500 and throw them away. Now check page 750 of what's left. Keep halving. You find any word in at most 10 steps — not 1000.

```
int binarySearch(int arr[], int n, int target) {
    int lo = 0, hi = n - 1;
    
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;   // avoids overflow (vs (lo+hi)/2)
        
        if (arr[mid] == target) return mid;       // found!
        else if (arr[mid] < target) lo = mid + 1; // target in right half
        else                         hi = mid - 1; // target in left half
    }
    return -1;   // not found
}
// Time:  O(log n) - halves the search space each step
// Space: O(1)     - just three int variables
```

The classic overflow bug: mid = (lo + hi) / 2 can overflow if lo and hi are near INT_MAX. Always write mid = lo + (hi - lo) / 2 - same result, safe from overflow.