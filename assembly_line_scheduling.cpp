#include <iostream>
using namespace std;

#define N 5

int *fastestWay(int a[2][N], int t[2][N], int e[2], int x[2], int n, int *f) {
    int *f0 = new int[n], *f1 = new int[n], *l0 = new int[n], *l1 = new int[n];
    f0[0] = e[0] + a[0][0], f1[0] = e[1] + a[1][0];

    for (int i = 1; i < n; i++) {
        if (f0[i - 1] <= f1[i - 1] + t[1][i - 1]) {
            f0[i] = f0[i - 1] + a[0][i], l0[i] = 0;
        } else {
            f0[i] = f1[i - 1] + t[1][i - 1] + a[0][i], l0[i] = 1;
        }

        if (f1[i - 1] <= f0[i - 1] + t[0][i - 1]) {
            f1[i] = f1[i - 1] + a[1][i], l1[i] = 0;
        } else {
            f1[i] = f0[i - 1] + t[0][i - 1] + a[1][i], l1[i] = 1;
        }
    }

    if (f0[n - 1] + x[0] < f1[n - 1] + x[1]) {
        *f = f0[n - 1] + x[0];
        delete[] f0, f1, l1;
        return l0;
    } else {
        *f = f1[n - 1] + x[1];
        delete[] f0, f1, l0;
        return l1;
    }
}

void printStation(int *l, int n) {
    for (int i = 1; i < n; i++) {
        cout << l[i] + 1 << endl;
    }
}

int main() {
    int a[2][N] =
        {
            {3, 2, 100, 5, 6},
            {5, 2, 1, 5, 6},
        },
        t[2][N] =
            {
                {7, 3, 1, 3, 3},
                {2, 3, 1, 1, 2},
            },
        e[2] = {2, 4}, x[2] = {1, 2};

    int *f = new int;
    int *l = fastestWay(a, t, e, x, N, f);

    cout << *f << endl;
    printStation(l, N);

    delete f;
    delete[] l;

    return 0;
}
