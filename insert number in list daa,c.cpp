#include <stdio.h>

// Function to insert a number in the sorted list
void insertNumber(int arr[], int n, int num) {
    int i;
    int pos = n;

    // Find position to insert the new number
    for (i = 0; i < n; i++) {
        if (arr[i] > num) {
            pos = i;
            break;
        }
    }

    // Shift elements to make space for the new number
    for (i = n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }

    arr[pos] = num;
}

int main() {
    int arr[100] = {2, 5, 8, 10};  // Example sorted list
    int n = 4;  // Number of elements in the list
    int num = 7;  // Number to insert

    insertNumber(arr, n, num);
    n++;  // Increment size of array after insertion

    printf("List after insertion: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}

