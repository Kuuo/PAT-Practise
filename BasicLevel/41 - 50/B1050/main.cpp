#include <bits/stdc++.h>
using namespace std;

int num[10005];
int N, m, n;
int** out;

void setmn() {
    int bound = sqrt(N);
    int mindiff = 99999;
    int k;
    for (int i = 1; i <= bound; ++i) {
        if (N % i != 0) continue;
        k = N / i;
        if (mindiff > k - i) {
            mindiff = k - i;
            m = k;
            n = i;
        }
    }
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) scanf("%d", &num[i]);
    sort(num, num + N, greater<int>());
    setmn();

    out = new int* [m];
    for (int i = 0; i < m; ++i) {
        out[i] = new int[n];
        fill(out[i], out[i] + n, 0);
    }

    out[0][0] = num[0];
    int i = 0, j = 0, k = 1;
    while (k < N) {
        while (j + 1 < n && out[i][j + 1] == 0) {
            j++;
            out[i][j] = num[k++];
        }
        while (i + 1 < m && out[i + 1][j] == 0) {
            i++;
            out[i][j] = num[k++];
        }
        while (j - 1 > -1 && out[i][j - 1] == 0) {
            j--;
            out[i][j] = num[k++];
        }
        while (i - 1 > -1 && out[i - 1][j] == 0) {
            i--;
            out[i][j] = num[k++];
        }
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (j != 0) printf(" ");
            printf("%d", out[i][j]);
        }
        printf("\n");
    }

    return 0;
}
