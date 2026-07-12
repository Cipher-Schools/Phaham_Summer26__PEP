// lc - 904

#include <bits/stdc++.h>
using namespace std;

int totalFruit(vector<int>& fruits) {
    unordered_map<int,int> basket;   // basket[type] = count
    int lo=0, maxPick=0;
    for (int hi=0; hi < fruits.size(); hi++) {
        basket[fruits[hi]]++;
        while (basket.size() > 2) {          // more than 2 types
            basket[fruits[lo]]--;
            if (!basket[fruits[lo]]) basket.erase(fruits[lo]);
            lo++;
        }
        maxPick = max(maxPick, hi-lo+1);
    }
    return maxPick;
}
// Identical logic to "at most 2 distinct" - only the variable name changed.
// The skill is recognizing that "2 baskets" = "at most 2 distinct types".