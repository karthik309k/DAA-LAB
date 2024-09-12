#include <stdio.h>
#include <time.h>

void multiplyMatrices(int firstMatrix[][10], int secondMatrix[][10], int result[][10], int r1, int c1, int r2, int c2) {
    int i, j, k;
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c2; j++) {
            result[i][j] = 0;
            for (k = 0; k < c1; k++) {
                result[i][j] += firstMatrix[i][k] * secondMatrix[k][j];
            }
        }
    }
}

int main() {
    int r1, c1, r2, c2;
    int firstMatrix[10][10], secondMatrix[10][10], result[10][10];
    
    printf("Enter rows and columns for first matrix: ");
    scanf("%d %d", &r1, &c1);
    
    printf("Enter rows and columns for second matrix: ");
    scanf("%d %d", &r2, &c2);

    if (c1 != r2) {
        printf("Error! column of first matrix not equal to row of second.\n");
        return -1;
    }

    printf("Enter elements of first matrix:\n");
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            scanf("%d", &firstMatrix[i][j]);
        }
    }

    printf("Enter elements of second matrix:\n");
    for (int i = 0; i < r2; i++) {
        for (int j = 0; j < c2; j++) {
            scanf("%d", &secondMatrix[i][j]);
        }
    }

    clock_t start = clock();
    multiplyMatrices(firstMatrix, secondMatrix, result, r1, c1, r2, c2);
    clock_t end = clock();

    printf("Resultant matrix:\n");
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken to multiply matrices: %f seconds\n", time_taken);

    return 0;
}
