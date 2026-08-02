// https://www.geeksforgeeks.org/problems/nearly-sorted-1587115620/1

#include <bits/stdc++.h>
using namespace std;

void nearlySorted(vector<int> &arr, int k)
{
  // code here
  int idx = 0, n = arr.size();
  priority_queue<int, vector<int>, greater<int>> min_heap;
  for (int i = 0; i <= min(n - 1, k); i++)
  {
    min_heap.push(arr[i]);
  }
  for (int i = k + 1; i < n; i++)
  {
    arr[idx++] = min_heap.top();
    min_heap.pop();
    min_heap.push(arr[i]);
  }
  while (!min_heap.empty())
  {
    arr[idx++] = min_heap.top();
    min_heap.pop();
  }
}