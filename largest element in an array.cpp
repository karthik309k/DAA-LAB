#include <stdio.h>
int findLargest(int arr[], int n) {
    int max = arr[0]; 
    for (int i = 1; i < n; i++) { 
        if (arr[i] > max) { 
            max = arr[i]; 
        }
    }
    return max;  
}
int main() {
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    if (n <= 0 || n > 100) {
        printf("Invalid number of elements. Please enter a number between 1 and 100.\n");
        return 1; 
    }
    int arr[100];
    printf("Enter the elements: ");

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("The largest element is %d\n", findLargest(arr, n));

    return 0;
}   

