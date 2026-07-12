// lc - 779

#include <bits/stdc++.h>
using namespace std;

int kthGrammar(int n, int k) {
    if (n == 1) return 0;                // base: row 1 is always "0"
    int parent = kthGrammar(n-1, (k+1)/2); // parent is ceil(k/2)-th in prev row
    if (k % 2 == 1)
        return parent;                   // odd position: same as parent
    else
        return 1 - parent;              // even position: opposite of parent
}
// Row 3, k=4: parent = kthGrammar(2, 2)
//   Row 2, k=2: parent = kthGrammar(1, 1) = 0. k even → 1-0 = 1.
// Back to k=4: parent=1, k even → 1-1 = 0. Answer: 0 ✓