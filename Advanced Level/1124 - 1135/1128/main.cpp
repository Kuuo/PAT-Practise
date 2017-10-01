#include <bits/stdc++.h>
using namespace std;

int k, n;
int board[1002][1002];

int isvalid(int n) {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; j++) {
            if (!board[i][j]) continue;

            for (int l = -1; l <= 1; l++) {
                for (int m = -1; m <= 1; m++) {
                    if (l == 0 && m == 0) continue;
                    int x = i + l, y = j + m;
                    while (x > 0 && x <= n && y > 0 && y <= n) {
                        if (board[x][y]) return 0;
                        x += l; y += m;
                    }
                }
            }
        }
    }
    return 1;
}

int main() {
    scanf("%d", &k);
    for (int i = 0; i < k; ++i) {
        scanf("%d", &n);
        for (int j = 1; j <= n; j++) fill(board[j], board[j] + n + 1, 0);
        int q;
        for (int j = 1; j <= n; ++j) {
            scanf("%d", &q);
            board[j][q] = 1;
        }
        printf(isvalid(n) ? "YES\n" : "NO\n");
    }

    return 0;
}
