#include <bits/stdc++.h>
using namespace std;

// lc - 34
int firstPos(vector<int>& arr, int target) {
    int lo=0, hi=arr.size()-1, ans=-1;
    while (lo <= hi) {
        int mid = lo + (hi-lo)/2;
        if (arr[mid] == target) { ans=mid; hi=mid-1; } // found, go LEFT
        else if (arr[mid] < target) lo=mid+1;
        else hi=mid-1;
    }
    return ans;
}

int lastPos(vector<int>& arr, int target) {
    int lo=0, hi=arr.size()-1, ans=-1;
    while (lo <= hi) {
        int mid = lo + (hi-lo)/2;
        if (arr[mid] == target) { ans=mid; lo=mid+1; } // found, go RIGHT
        else if (arr[mid] < target) lo=mid+1;
        else hi=mid-1;
    }
    return ans;
}
// Call both, return {firstPos, lastPos}
// Count of occurrences = lastPos - firstPos + 1