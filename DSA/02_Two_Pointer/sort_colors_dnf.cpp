#include <bits/stdc++.h>
using namespace std;

// Sort an array containing only 0, 1, and 2 in one pass without counting. Three pointers: lo (boundary of 0s), mid (current), hi (boundary of 2s). 
// Move mid through the array, placing each element in the right section.

// Dutch National Flag — O(n) time, O(1) space
void dutchFlag(int arr[], int n) {
    int lo = 0, mid = 0, hi = n - 1;
    while (mid <= hi) {
        if (arr[mid] == 0) {
            swap(arr[lo], arr[mid]);
            lo++; mid++;           // 0 placed, move both forward
        } else if (arr[mid] == 1) {
            mid++;                 // 1 already in correct region
        } else {                   // arr[mid] == 2
            swap(arr[mid], arr[hi]);
            hi--;                  // 2 placed at end, don't move mid yet
        }
    }
}
// Three pointers, three regions, one pass - O(n)