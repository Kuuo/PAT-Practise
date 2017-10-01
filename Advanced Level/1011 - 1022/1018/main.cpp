#include <bits/stdc++.h>
using namespace std;

int cap, n, sp, m;
int bcnt[501], visited[501];
int cost[501][501];
int mincost = 999999;
int taketo = 999999, takeback = 999999;
int curtaketo, curtakeback;
vector<int> curpath, retpath;

void setret() {
    curtaketo = 0;
    curtakeback = 0;
    for (auto& v : curpath) {
        if (bcnt[v] >= cap) {
            curtakeback += bcnt[v] - cap;
        } else {
            if (curtakeback >= cap - bcnt[v]) {
                curtakeback -= cap - bcnt[v];
            } else {
                curtaketo += cap - bcnt[v] - curtakeback;
                curtakeback = 0;
            }
        }
    }
}

void dfs(int v, int curcost) {
    if (curcost > mincost) return;

    if (v == sp) {
        setret();
        if (curcost < mincost ||
            (curcost == mincost && curtaketo < taketo) ||
            (curcost == mincost && curtaketo == taketo && curtakeback < takeback)) {
            taketo = curtaketo;
            takeback = curtakeback;
            retpath = curpath;
        }
        mincost = curcost;
        return;
    }

    for (int i = 0; i <= n; ++i) {
        if (visited[i] || cost[v][i] == -1) continue;
        curpath.push_back(i);
        visited[i] = 1;
        dfs(i, curcost + cost[v][i]);
        curpath.pop_back();
        visited[i] = 0;
    }
}

int main() {
    scanf("%d %d %d %d", &cap, &n, &sp, &m);
    cap /= 2;
    for (int i = 1; i <= n; ++i) scanf("%d", &bcnt[i]);

    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            cost[i][j] = -1;
        }
    }

    int from, to, tcost;
    for (int i = 0; i < m; ++i) {
        scanf("%d %d %d", &from, &to, &tcost);
        cost[from][to] = tcost;
        cost[to][from] = tcost;
    }

    visited[0] = 1;
    dfs(0, 0);

    printf("%d 0", taketo);
    for (auto& x : retpath) {
        printf("->%d", x);
    }
    printf(" %d", takeback);

    return 0;
}
