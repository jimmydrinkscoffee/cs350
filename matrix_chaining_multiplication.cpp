#include <iostream>
using namespace std;

#define N 5

pair<int (*)[N], int (*)[N]> matrixChainingOrder(int p[]) {
    int m[N][N], s[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            m[i][j] = 0;
        }
    }

    for (int l = 2; l < N + 1; l++) {
        for (int i = 0; i < N - l + 1; i++) {
            int j = i + l - 1;
            m[i][j] = INT32_MAX;

            for (int k = i; k < j; k++) {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q, s[i][j] = k;
                }
            }
        }
    }

    return make_pair(m, s);
}

int lookupChaining(int p[], int **m, int i, int j) {
    if (m[i][j] < INT32_MAX) {
        return m[i][j];
    }

    if (i = j) {
        return 0;
    }

    for (int k = i; k < j; k++) {
        int q = lookupChaining(p, m, i, k) + lookupChaining(p, m, k + 1, j) +
                p[i - 1] * p[k] * p[j];

        if (q < m[i][j]) {
            m[i][j] = q;
        }
    }

    return m[i][j];
}

int memorizeMatrixChaining(int p[]) {
    int **m = new int *[N];
    for (int i = 0; i < N; i++) {
        m[i] = new int[N];
        for (int j = 0; j < N; j++) {
            m[i][j] = INT32_MAX;
        }
    }

    return lookupChaining(p, m, 0, N - 1);
}
