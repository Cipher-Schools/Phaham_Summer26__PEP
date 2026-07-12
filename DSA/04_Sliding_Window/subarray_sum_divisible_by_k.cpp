// lc - 974

#include <bits/stdc++.h>
using namespace std;

int subarraysDivByK(vector<int>& nums, int k) {
    unordered_map<int,int> remCount;
    remCount[0] = 1;   // remainder 0 seen once (empty prefix)
    int sum=0, count=0;
    for (int x : nums) {
        sum += x;
        int rem = ((sum % k) + k) % k;   // handle negative mod in C++
        count += remCount[rem];
        remCount[rem]++;
    }
    return count;
}
// Why it works: (prefix[j] - prefix[i]) % k == 0
//             ↔ prefix[j] % k == prefix[i] % k
// For each j, count how many previous i had the same remainder.
// C++ % can be negative for negative numbers - (rem+k)%k forces positive.