#include <stdio.h>

void printSubset(int subset[], int n) {
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", subset[i]);
    printf("\n");
}

void sumOfSubsets(int arr[], int subset[], int n, int index, int sum, int target) {
    if (sum == target) {
        printSubset(subset, index);
        return;
    }

    if (index == n || sum > target)
        return;

    subset[index] = arr[index];
    sumOfSubsets(arr, subset, n, index + 1, sum + arr[index], target);

    sumOfSubsets(arr, subset, n, index + 1, sum, target);
}

int main() {
    int arr[] = {3, 34, 4, 12, 5, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 9;
    int subset[n];
    
    sumOfSubsets(arr, subset, n, 0, 0, target);
    return 0;
}

