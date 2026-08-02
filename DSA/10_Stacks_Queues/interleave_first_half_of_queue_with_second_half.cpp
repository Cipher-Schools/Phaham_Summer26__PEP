// https://www.geeksforgeeks.org/problems/interleave-the-first-half-of-the-queue-with-second-half/1

#include <bits/stdc++.h>
using namespace std;

// Using temp Queue

void rearrangeQueue(queue<int> &q)
{
  int n = q.size();

  if (n % 2 != 0)
  {
    cout << "Queue should have even number of elements.\n";
    return;
  }

  queue<int> temp;

  // Move first half to temp queue
  for (int i = 0; i < n / 2; i++)
  {
    temp.push(q.front());
    q.pop();
  }

  // Interleave
  while (!temp.empty())
  {
    q.push(temp.front());
    temp.pop();

    q.push(q.front());
    q.pop();
  }
}

// Using temp Stack
void rearrangeQueue(queue<int> &q)
{
  int n = q.size();

  if (n % 2 != 0)
  {
    cout << "Queue size must be even.\n";
    return;
  }

  stack<int> st;

  // Step 1: Push first half into stack
  for (int i = 0; i < n / 2; i++)
  {
    st.push(q.front());
    q.pop();
  }

  // Step 2: Push stack back into queue
  while (!st.empty())
  {
    q.push(st.top());
    st.pop();
  }

  // Step 3: Move first half to back
  for (int i = 0; i < n / 2; i++)
  {
    q.push(q.front());
    q.pop();
  }

  // Step 4: Push first half into stack
  for (int i = 0; i < n / 2; i++)
  {
    st.push(q.front());
    q.pop();
  }

  // Step 5: Interleave
  while (!st.empty())
  {
    q.push(st.top());
    st.pop();

    q.push(q.front());
    q.pop();
  }
}