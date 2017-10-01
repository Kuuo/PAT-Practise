#include <bits/stdc++.h>
using namespace std;

int N, m, n;
vector<int> num;
int table[105][105];

void setmn() {
    int ub = sqrt(N);
    for (int i = 1; i <= ub + 1; ++i) {
        for (int j = 1; i * j <= N; ++j) {
            if (i * j == N) {
                m = max(i, j);
                n = min(i, j);
            }
        }
    }
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        int t;
        scanf("%d", &t);
        num.push_back(t);
    }
    sort(num.begin(), num.end(), greater<int>());
    setmn();

    table[0][0] = num[0];
    int x = 0, y = 0, i = 1;
    while (i < N) {
        while (y + 1 < n && table[x][y + 1] == 0) {
            table[x][++y] = num[i++];
        }
        while (x + 1 < m && table[x + 1][y] == 0) {
            table[++x][y] = num[i++];
        }
        while (y - 1 >= 0 && table[x][y - 1] == 0) {
            table[x][--y] = num[i++];
        }
        while (x - 1 >= 0 && table[x - 1][y] == 0) {
            table[--x][y] = num[i++];
        }
    }

    for (int i = 0; i < m; ++i) {
        printf("%d", table[i][0]);
        for (int j = 1; j < n; ++j) {
            printf(" %d", table[i][j]);
        }
        printf("\n");
    }
    return 0;
}
