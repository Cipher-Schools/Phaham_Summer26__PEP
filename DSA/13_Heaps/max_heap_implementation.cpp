#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/max-heap-implementation/1

void shiftUp(int i)
{
  while (i > 0 && max_heap[(i - 1) / 2] < max_heap[i])
  {
    swap(max_heap[(i - 1) / 2], max_heap[i]); // parent<child
    i = (i - 1) / 2;                          // i = parent
  }
}
void shiftDown(int i)
{
  int largest = i;
  int left_child = 2 * i + 1;
  int right_child = 2 * i + 2;
  if (left_child < max_heap.size() && max_heap[left_child] > max_heap[largest])
  {
    largest = left_child;
  }
  if (right_child < max_heap.size() && max_heap[right_child] > max_heap[largest])
  {
    largest = right_child;
  }
  if (largest != i)
  {
    swap(max_heap[largest], max_heap[i]);
    shiftDown(largest);
  }
}
vector<int> max_heap;
void push(int x)
{
  max_heap.push_back(x);
  shiftUp(max_heap.size() - 1);
}

void pop()
{
  max_heap[0] = max_heap.back();
  max_heap.pop_back();
  if (!max_heap.empty())
    shiftDown(0);
}

int peek()
{
  if (!max_heap.empty())
    return max_heap[0];
  return -1;
}

int size()
{
  return max_heap.size();
}




// ------------------------------------------------------------------------------
void max_heapify(vector<int> arr, int i, int n)
{
  int largest = i;
  int left_child = 2 * i + 1;
  int right_child = 2 * i + 2;
  if (left_child < n && arr[left_child] > arr[largest])
  {
    largest = left_child;
  }
  if (right_child < n && arr[right_child] > arr[largest])
  {
    largest = right_child;
  }
  if (largest != i)
  {
    swap(arr[largest], arr[i]);
    max_heapify(arr, largest, n);
  }
}

int main()
{
  vector<int> arr;
  int n = arr.size();
  max_heapify(arr, 0, n);
}