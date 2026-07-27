#include <bits/stdc++.h>
using namespace std;

void max_heapify(vector<int>arr, int i, int n){
  int largest = i;
  int left_child = 2*i+1;
  int right_child = 2*i+2;
  if(left_child < n && arr[left_child]>arr[largest]){
    largest = left_child;
  }
  if(right_child < n && arr[right_child]>arr[largest]){
    largest = right_child;
  }
  if(largest != i){
    swap(arr[largest], arr[i]);
    max_heapify(arr, largest, n);
  }
}

void insert(vector<int>arr, int val){

}

int main(){
  vector<int>arr;
  int n = arr.size();
  max_heapify(arr, 0, n);
}