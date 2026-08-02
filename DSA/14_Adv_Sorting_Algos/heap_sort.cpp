// https://www.geeksforgeeks.org/problems/heap-sort/1

#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int> &arr, int n, int i)
{
  int largest = i;
  int left_child = 2 * i + 1;
  int right_child = 2 * i + 2;

  if (left_child < n && arr[left_child] > arr[largest])
    largest = left_child;

  if (right_child < n && arr[right_child] > arr[largest])
    largest = right_child;

  if (largest != i)
  {
    swap(arr[i], arr[largest]);
    heapify(arr, n, largest);
  }
}

void heapSort(vector<int> &arr)
{
  int n = arr.size();

  // Build max heap
  for (int i = n / 2 - 1; i >= 0; i--)
  {
    heapify(arr, n, i);
  }

  // Extract elements
  for (int i = n - 1; i > 0; i--)
  {
    swap(arr[0], arr[i]);

    // Heapify only remaining heap
    heapify(arr, i, 0);
  }
}