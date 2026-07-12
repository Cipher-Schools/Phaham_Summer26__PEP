# Selection sort
Find the minimum element in the unsorted portion. Swap it to its correct position. Repeat. After pass i, the first i elements are sorted and in their final positions.
You have 6 unsorted books on a shelf. You scan all of them, pick the thinnest (smallest), put it first. Scan the remaining 5, pick the next thinnest, put it second. You always pick the minimum from what's left and place it. You do n–1 complete scans total.

```
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;                      // assume current is minimum
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx])
                minIdx = j;                  // found a smaller element
        }
        swap(arr[i], arr[minIdx]);           // place minimum at position i
    }
}
```
// Time:  O(n²) - always. Outer loop n times, inner loop n-i times.
// Space: O(1)  - in-place, just an index variable
Selection sort's key property: it makes exactly n–1 swaps — fewer than bubble sort. So if swapping is expensive (writing to disk, network call), selection sort beats bubble sort even though they're both O(n²). Algorithm choice depends on the real cost model.

# Bubble sort
Compare adjacent elements. If they're in the wrong order, swap them. After each pass, the largest unsorted element "bubbles up" to its correct position at the end. Repeat until no swaps occur.
Imagine bubbles in a soda glass — light bubbles (small numbers) rise to the top, heavy ones (large numbers) sink to the bottom. Each pass floats the heaviest remaining bubble to its position. The name is literal.
```
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;                    // optimization flag
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;   // already sorted — exit early
    }
}
// Time:  O(n²) worst/average, O(n) best (already sorted + flag)
// Space: O(1)
```
The swapped flag is the key optimization. Without it, bubble sort always runs O(n²) passes. With it, if the array is already sorted, it does one pass, finds no swaps, and stops — making best case O(n). Always include it.

# Insertion sort
Take the next unsorted element. Insert it into its correct position among the already-sorted elements on the left - by shifting elements right to make room. Like sorting cards in your hand.
You're dealt cards one by one. After each card, you slide it left into the right position among the cards you're already holding. Your left hand always has a sorted set. Each new card gets inserted into it. This is exactly insertion sort — and it's how humans naturally sort cards.
```
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];        // the card we're inserting
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j]; // shift right to make room
            j--;
        }
        arr[j + 1] = key;        // place in correct position
    }
}
// Time:  O(n²) worst, O(n) best (nearly sorted array!)
// Space: O(1) - in-place
```
