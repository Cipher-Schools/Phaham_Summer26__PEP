// lc - 498

#include <bits/stdc++.h>
using namespace std;

vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
    int m=mat.size(), n=mat[0].size(), r=0, c=0;
    vector<int> res;
    bool goingUp = true;
    for (int i=0; i<m*n; i++) {
        res.push_back(mat[r][c]);
        if (goingUp) {
            if (r==0 && c<n-1) { c++; goingUp=false; }       // hit top → go right then down
            else if (c==n-1) { r++; goingUp=false; }           // hit right → go down then down-left
            else { r--; c++; }                                  // normal up-right move
        } else {
            if (c==0 && r<m-1) { r++; goingUp=true; }        // hit left → go down then up-right
            else if (r==m-1) { c++; goingUp=true; }            // hit bottom → go right then up-right
            else { r++; c--; }                                  // normal down-left move
        }
    }
    return res;
}
// The boundary checks must come BEFORE the normal move — hits take priority.
// Time O(m*n), Space O(1) extra