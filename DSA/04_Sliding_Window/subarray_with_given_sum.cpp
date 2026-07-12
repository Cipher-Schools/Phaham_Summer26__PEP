// gfg

#include <bits/stdc++.h>
using namespace std;

int minSwaps(int arr[], int n, int k) {
    int cnt = 0;
    for (int i = 0; i < n; i++)
        if (arr[i] <= k) cnt++;       // window size = elements <= k
    
    int good = 0;                      // elements <= k in first window
    for (int i = 0; i < cnt; i++)
        if (arr[i] <= k) good++;
    int max_good = good;
    
    for (int i = cnt; i < n; i++) {
        if (arr[i] <= k) good++;                   // new element enters
        if (arr[i - cnt] <= k) good--;             // old element leaves
        max_good = max(max_good, good);
    }
    return cnt - max_good;   // elements > k in best window = swaps needed
}
// Same logic as problem 3, just a different condition: arr[i] <= k instead of arr[i]==1