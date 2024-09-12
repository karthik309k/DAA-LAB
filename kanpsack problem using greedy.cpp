#include <stdio.h>
typedef struct {
    int weight;
    int value;
} Item;
void knapsack(Item items[], int n, int W) {
    float ratio[n];
    int i, j;

    for (i = 0; i < n; i++)
        ratio[i] = (float)items[i].value / items[i].weight;

    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (ratio[j] < ratio[j + 1]) {
                float tempRatio = ratio[j];
                ratio[j] = ratio[j + 1];
                ratio[j + 1] = tempRatio;

                Item tempItem = items[j];
                items[j] = items[j + 1];
                items[j + 1] = tempItem;
            }

    int currentWeight = 0;
    float totalValue = 0.0;

    for (i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= W) {
            currentWeight += items[i].weight;
            totalValue += items[i].value;
        } else {
            int remain = W - currentWeight;
            totalValue += items[i].value * ((float)remain / items[i].weight);
            break;
        }
    }
    printf("Total value in Knapsack = %.2f\n", totalValue);
}
int main() {
    Item items[] = {{10, 60}, {20, 100}, {30, 120}};
    int W = 50; 
    int n = sizeof(items) / sizeof(items[0]);
    knapsack(items, n, W);
    return 0;
}

