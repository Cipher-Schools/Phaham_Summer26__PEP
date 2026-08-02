// https://www.geeksforgeeks.org/problems/quick-sort/1

#include <bits/stdc++.h>
using namespace std;

void quickSort(vector<int> &arr, int low, int high)
{
  // code here
  if (low < high)
  {
    int pivot = partition(arr, low, high);
    quickSort(arr, low, pivot - 1);
    quickSort(arr, pivot + 1, high);
  }
}

int partition(vector<int> &arr, int low, int high)
{
  // code here
  int pivot = arr[high];
  int idx = low - 1;
  for (int i = low; i < high; i++)
  {
    if (arr[i] <= pivot)
    {
      idx++;
      swap(arr[idx], arr[i]);
    }
  }
  swap(arr[idx + 1], arr[high]);
  return (idx + 1);
}