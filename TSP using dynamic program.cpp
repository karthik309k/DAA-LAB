#include <stdio.h>
#include <limits.h>
#define V 4
#define INF INT_MAX

int tsp(int graph[][V], int set, int pos, int memo[][V]) {
    if (set == (1 << V) - 1)
        return graph[pos][0];

    if (memo[set][pos] != -1)
        return memo[set][pos];

    int ans = INF;

    for (int city = 0; city < V; city++) {
        if ((set & (1 << city)) == 0) {
            int newAns = graph[pos][city] + tsp(graph, set | (1 << city), city, memo);
            ans = (ans < newAns) ? ans : newAns;
        }
    }

    memo[set][pos] = ans;
    return ans;
}

int main() {
    int graph[][V] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    int memo[1 << V][V];
    for (int i = 0; i < (1 << V); i++)
        for (int j = 0; j < V; j++)
            memo[i][j] = -1;

    printf("Minimum cost of TSP is %d\n", tsp(graph, 1, 0, memo));
    return 0;
}

