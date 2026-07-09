#include <bits/stdc++.h>
using namespace std;

// lc 121

int maxProfit(vector<int>& prices) {
    int minPrice = INT_MAX, maxProfit = 0;
    for (int price : prices) {
        minPrice = min(minPrice, price);        // best buy seen so far
        maxProfit = max(maxProfit, price - minPrice); // profit if sell today
    }
    return maxProfit;
}
// prices=[7,1,5,3,6,4]
// min:    7,1,1,1,1,1   profit: 0,0,4,2,5,3
// Answer: 5
// Time O(n), Space O(1)