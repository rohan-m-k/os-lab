#include<stdio.h>

int main() {
    int n, m, i, j, k;
    int alloc[20][20], max[20][20], avail[20];

    printf("Enter n and m:\n");
    scanf("%d%d", &n, &m);

    printf("Enter the matrix of allocation:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &alloc[i][j]);
        }
    }

    printf("Enter the matrix of maximum:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    printf("Enter the array of available resources:\n");
    for (i = 0; i < m; i++) {
        scanf("%d", &avail[i]);
    }

    int f[n], ans[n], ind = 0;
    for (i = 0; i < n; i++) {
        ans[i] = 0;
    }

    for (k = 0; k < n; k++) {
        f[k] = 0;
    }

    int need[n][m];
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    int y = 0;
    for (k = 0; k < n; k++) {
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
                    for (y = 0; y < m; y++) {
                        avail[y] += alloc[i][y];
                    }
                    f[i] = 1;
                }
            }
        }
    }

    printf("Following is the safe sequence:\n");
    for (i = 0; i < n - 1; i++) {
        printf("p%d -> ", ans[i]);
    }
    printf("p%d\n", ans[n - 1]);

    return 0;
}
