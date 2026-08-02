// https://leetcode.com/problems/kth-largest-element-in-a-stream/

#include <bits/stdc++.h>
using namespace std;

priority_queue<int, vector<int>, greater<int>> min_heap;
int K;

KthLargest(int k, vector<int> &nums)
{
  K = k;
  for (int num : nums)
    add(num);
}

int add(int val)
{
  min_heap.push(val);
  if (min_heap.size() > K)
    min_heap.pop();
  return min_heap.top();
}