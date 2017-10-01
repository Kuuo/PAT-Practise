#include <bits/stdc++.h>
using namespace std;

int n, m, start, target;
int table[501][501];
int number[500];
int visited[500];
int mincost = 999999, maxnumber = -1, mincnt;

void dfs(int s, int cost, int curnum) {
    if (s >= n) return;
    if (s == target) {
        if (cost < mincost) {
            mincnt = 1;
            mincost = cost;
            maxnumber = curnum;
        } else if (cost == mincost) {
            mincnt++;
            maxnumber = max(curnum, maxnumber);
        }
        return;
    }

    if (cost > mincost) return;

    for (int i = 0; i < n; ++i) {
        if (visited[i]) continue;
        if (table[s][i] == 0) continue;
        visited[i] = 1;
        dfs(i, cost + table[s][i], curnum + number[i]);
        visited[i] = 0;
    }
}

int main() {
    scanf("%d %d %d %d", &n, &m, &start, &target);
    for (int i = 0; i < n; i++) scanf("%d", &number[i]);
    int ts, tt, tc;
    for (int i = 0; i < m; ++i) {
        scanf("%d %d %d", &ts, &tt, &tc);
        table[tt][ts] = table[ts][tt] = tc;
    }

    visited[start] = 1;
    dfs(start, 0, number[start]);

    printf("%d %d", mincnt, maxnumber);

    return 0;
}
