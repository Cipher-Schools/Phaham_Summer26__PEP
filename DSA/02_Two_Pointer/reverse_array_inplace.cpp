#include <bits/stdc++.h>
using namespace std;

// Reverse array — O(n) time, O(1) space
void reverse(int arr[], int n) {
    int lo = 0, hi = n - 1;
    while (lo < hi) {
        swap(arr[lo], arr[hi]);
        lo++;
        hi--;
    }
}
// Each swap puts two elements in their final position.
// Total swaps = n/2. No extra array needed.
