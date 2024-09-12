#include <stdio.h>
#include <time.h>

void multiplyMatrix(int row1, int col1, int row2, int col2, int mat1[2][2], int mat2[2][2], int result[2][2]) {
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < col1; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

int main() {
    int row1 = 2, col1 = 2, row2 = 2, col2 = 2;
    int mat1[2][2] = {{1, 2}, {3, 4}};
    int mat2[2][2] = {{5, 6}, {7, 8}};
    int result[2][2];
    
    clock_t start, end;
    double cpu_time_used;
    
    start = clock();
    multiplyMatrix(row1, col1, row2, col2, mat1, mat2, result);
    end = clock();
    
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Result matrix:\n");
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col2; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    
    printf("Time taken: %f seconds\n", cpu_time_used);
    
    return 0;
}

