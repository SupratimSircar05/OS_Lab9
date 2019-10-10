// Banker's Algorithm

#include <stdio.h>

int main() {
    // P1, P2, P3, P4, P5 are the Process names here

    int n, m, i, j, k;
    n = 5; // Number of processes
    m = 4; // Number of resources

    int alloc[5][4] = {{0, 0, 1, 2}, // P1 // Allocation Matrix
                       {1, 0, 0, 0}, // P2
                       {1, 3, 5, 4}, // P3
                       {0, 6, 3, 2}, // P4
                       {0, 0, 1, 4}}; // P5


    int max[5][4] = {{0, 0, 1, 2}, // P1 // MAX Matrix
                     {1, 7, 5, 0}, // P2
                     {2, 3, 5, 6}, // P3
                     {0, 6, 5, 2}, // P4
                     {0, 6, 5, 6}}; // P5


    int avail[4] = {1, 5, 2, 0}; // Available Resources


    int f[n], ans[n], ind = 0;
    for (k = 0; k < n; k++) {
        f[k] = 0;
    }

    // calculate need matrix
    int need[n][m];
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];
    }

    int y = 0;
    for (k = 0; k < 5; k++) {
        for (i = 0; i < n; i++) {
            if (f[i] == 0) {

                int flag = 0;
                for (j = 0; j < m; j++) {
                    if (need[i][j] > avail[j]) {
                        flag = 1;
                        break;
                    }
                }

                if (flag == 0) {
                    ans[ind++] = i;
                    for (y = 0; y < m; y++)
                        avail[y] += alloc[i][y];
                    f[i] = 1;
                }
            }
        }
    }

    printf("Following is the SAFE Sequence\n");
    for (i = 0; i < n - 1; i++)
        printf(" P%d ->", ans[i]);
    printf(" P%d\n", ans[n - 1]);

    return 0;
}
