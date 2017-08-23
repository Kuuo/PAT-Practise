#include <bits/stdc++.h>
using namespace std;

int m, n, tol;
int data[1005][1005];
map<int, int> counter;

int inrange(int i, int j) {
    return (i > -1 && i < n && j > -1 && j < m);
}

int isvalid(int i, int j) {
    int newi, newj;
    for (int dx = -1; dx < 2; ++dx) {
        for (int dy = -1; dy < 2; ++dy) {
            if (dx == 0 && dy == 0) continue;
            newi = i + dx;
            newj = j + dy;
            if (!inrange(newi, newj)) continue;
            if (abs(data[i][j] - data[newi][newj]) <= tol) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    scanf("%d %d %d", &m, &n, &tol);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &data[i][j]);
            counter[data[i][j]]++;
        }
    }

    int numans = 0, reti = 0, retj = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (counter[data[i][j]] == 1 && isvalid(i, j)) {
                reti = i;
                retj = j;
                numans++;
                if (numans >= 2) {
                    printf("Not Unique");
                    return 0;
                }
            }
        }
    }

    if (numans == 0) {
        printf("Not Exist");
    } else {
        printf("(%d, %d): %d\n", retj + 1, reti + 1, data[reti][retj]);
    }

    return 0;
}
