// lc - 415

#include <bits/stdc++.h>
using namespace std;

string addStrings(string num1, string num2) {
    int i = num1.size() - 1, j = num2.size() - 1, carry = 0;
    string result = "";
    while (i >= 0 || j >= 0 || carry) {
        int x = (i >= 0) ? num1[i] - '0' : 0;   // digit or 0 if exhausted
        int y = (j >= 0) ? num2[j] - '0' : 0;
        int sum = x + y + carry;
        result += (sum % 10) + '0';              // append digit (reversed order)
        carry = sum / 10;
        i--; j--;
    }
    reverse(result.begin(), result.end());      // fix the order
    return result;
}
// Time O(max(len1,len2)), Space O(max(len1,len2))
// This pattern extends directly to: multiply strings, add binary strings, big integer arithmetic