#include <bits/stdc++.h>
using namespace std;

// gfg

vector<int> commonElements(int a[], int b[], int c[], int n1, int n2, int n3) {
    vector<int> res;
    int i=0, j=0, k=0;
    while (i < n1 && j < n2 && k < n3) {
        if (a[i]==b[j] && b[j]==c[k]) {
            res.push_back(a[i]);
            i++; j++; k++;                    // all three advance
        } else if (a[i] <= b[j] && a[i] <= c[k])
            i++;                              // a is smallest, advance it
        else if (b[j] <= a[i] && b[j] <= c[k])
            j++;
        else
            k++;
    }
    return res;
}
// Time O(n1+n2+n3), Space O(1) — single pass through all three