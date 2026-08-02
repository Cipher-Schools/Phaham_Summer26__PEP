// https://www.geeksforgeeks.org/problems/merge-sort/1

#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int mid, int l, int r)
{
  int n1 = mid - l + 1;
  int n2 = r - mid;
  vector<int> L, R;
  for (int i = 0; i < n1; i++)
  {
    L.push_back(arr[l + i]);
  }
  for (int i = 0; i < n2; i++)
  {
    R.push_back(arr[mid + i + 1]);
  }
  int i = 0, j = 0, k = l;
  while (i < n1 && j < n2)
  {
    if (L[i] <= R[j])
    {
      arr[k++] = L[i++];
    }
    else
    {
      arr[k++] = R[j++];
    }
  }
  while (i < n1)
  {
    arr[k++] = L[i++];
  }
  while (j < n2)
  {
    arr[k++] = R[j++];
  }
}
void mergeSort(vector<int> &arr, int l, int r)
{
  // code here
  if (l >= r)
    return;
  int mid = l + (r - l) / 2;
  mergeSort(arr, l, mid);
  mergeSort(arr, mid + 1, r);
  merge(arr, mid, l, r);
}