#include <stdio.h>
int sumOfDivisors(int num) {
    int sum = 0;
    
    for (int i = 1; i <= num / 2; i++) {
        if (num % i == 0) {
            sum += i;
        }
    }
    return sum;
}
int isPerfectNumber(int num) {
    int sum = sumOfDivisors(num);
    return sum == num; 
}
int main() {
    int num = 5; 
    printf("Sum of divisors of %d is: %d\n", num, sumOfDivisors(num));
    if (isPerfectNumber(num)) {
        printf("%d is a Perfect Number.\n", num);
    } else {
        printf("%d is not a Perfect Number.\n", num);
    }
    return 0;
}

