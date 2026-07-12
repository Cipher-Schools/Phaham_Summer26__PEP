// gfg

int arraySum(int arr[], int n) {
    if (n == 0) return 0;                          // empty array = 0
    return arr[n-1] + arraySum(arr, n-1);          // last + sum of rest
}
// arraySum([1,2,3,4], 4):
// = 4 + arraySum([1,2,3], 3)
//     = 3 + arraySum([1,2], 2)
//         = 2 + arraySum([1], 1)
//             = 1 + arraySum([], 0) = 1+0 = 1
// Unwinds: 1 → 3 → 6 → 10