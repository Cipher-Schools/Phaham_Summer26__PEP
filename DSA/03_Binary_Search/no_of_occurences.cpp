#include <bits/stdc++.h>
using namespace std;

// lc - gfg
int firstPos(vector<int>& arr,int n,  int target) {
    int lo=0, hi=arr.size()-1, ans=-1;
    while (lo <= hi) {
        int mid = lo + (hi-lo)/2;
        if (arr[mid] == target) { ans=mid; hi=mid-1; } // found, go LEFT
        else if (arr[mid] < target) lo=mid+1;
        else hi=mid-1;
    }
    return ans;
}
int lastPos(vector<int>& arr, int n, int target) {
    int lo=0, hi=arr.size()-1, ans=-1;
    while (lo <= hi) {
        int mid = lo + (hi-lo)/2;
        if (arr[mid] == target) { ans=mid; lo=mid+1; } // found, go RIGHT
        else if (arr[mid] < target) lo=mid+1;
        else hi=mid-1;
    }
    return ans;
}

int countOccurrences(vector<int>& arr, int n, int target) {
    int first = firstPos(arr, n, target);
    if (first == -1) return 0;           // target not present
    int last = lastPos(arr, n, target);
    return last - first + 1;
}
// Time O(log n), Space O(1)