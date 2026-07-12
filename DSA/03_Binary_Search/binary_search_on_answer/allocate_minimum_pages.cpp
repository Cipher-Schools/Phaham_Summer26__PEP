#include <bits/stdc++.h>
using namespace std;

// gfg

bool canAllocate(vector<int>& books, int m, int maxPages) {
    int students = 1, pagesRead = 0;
    for (int pages : books) {
        if (pages > maxPages) return false;  // single book exceeds limit
        if (pagesRead + pages > maxPages) {
            students++;                       // new student
            pagesRead = pages;
            if (students > m) return false;
        } else {
            pagesRead += pages;
        }
    }
    return true;
}

int allocateBooks(vector<int>& books, int m) {
    int lo = *max_element(books.begin(), books.end()); // min possible
    int hi = accumulate(books.begin(), books.end(), 0); // max possible
    int ans = hi;
    
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (canAllocate(books, m, mid)) {
            ans = mid;      // works — try smaller max
            hi = mid - 1;
        } else {
            lo = mid + 1;  // doesn't work — need more pages allowed
        }
    }
    return ans;
}
// Answer range: lo=max(books), hi=sum(books)
// Feasibility: can we serve m students if each student reads ≤ mid pages?
// Minimizing → go left on success