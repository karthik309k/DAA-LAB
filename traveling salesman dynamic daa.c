#include <stdio.h>
#include <limits.h>

#define N 4
#define VISITED_ALL ((1 << N) - 1)

// Function to find the minimum cost using Dynamic Programming
int tsp(int graph[][N], int mask, int pos, int dp[][N]) {
    if (mask == VISITED_ALL)
        return graph[pos][0]; // Return to starting point

    if (dp[mask][pos] != -1)
        return dp[mask][pos];

    int ans = INT_MAX, city;
    for (city = 0; city < N; city++) {
        if ((mask & (1 << city)) == 0) {
            int newAns = graph[pos][city] + tsp(graph, mask | (1 << city), city, dp);
            if (newAns < ans)
                ans = newAns;
        }
    }

    return dp[mask][pos] = ans;
}

int main() {
    int graph[N][N] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };
    int dp[1 << N][N];
    int i, j;

    for (i = 0; i < (1 << N); i++)
        for (j = 0; j < N; j++)
            dp[i][j] = -1;

    printf("Minimum cost for Traveling Salesman Problem is %d\n", tsp(graph, 1, 0, dp));
    return 0;
}

