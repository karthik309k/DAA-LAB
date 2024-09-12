#include <stdio.h>

typedef struct {
    int min;
    int max;
} MinMax;

MinMax findMinMax(int arr[], int low, int high) {
    MinMax result, left, right;
    if (low == high) {
        result.min = result.max = arr[low];
        return result;
    }
    
    if (high == low + 1) {
        if (arr[low] < arr[high]) {
            result.min = arr[low];
            result.max = arr[high];
        } else {
            result.min = arr[high];
            result.max = arr[low];
        }
        return result;
    }

    int mid = (low + high) / 2;
    left = findMinMax(arr, low, mid);
    right = findMinMax(arr, mid + 1, high);

    result.min = (left.min < right.min) ? left.min : right.min;
    result.max = (left.max > right.max) ? left.max : right.max;

    return result;
}

int main() {
    int arr[] = {1000, 11, 445, 1, 330, 3000};
    int n = sizeof(arr) / sizeof(arr[0]);
    MinMax result = findMinMax(arr, 0, n - 1);
    printf("Minimum element is %d\n", result.min);
    printf("Maximum element is %d\n", result.max);
    return 0;
}

