#include <bits/stdc++.h>
using namespace std;
#define MAXN 10005

int n, m;
int mincost = 999999, mintransfer = 999999;
int line[MAXN][MAXN];
vector<int> adj[MAXN];
vector<int> minpath, curpath;
vector<int> visited(MAXN);

int getTransferCount(vector<int>& path) {
    int ret = 0, preline = -1, size = path.size();
    for (int i = 1; i < size; ++i) {
        int curline = line[path[i - 1]][path[i]];
        if (preline != curline) {
            ret++;
            preline = curline;
        }
    }
    return ret;
}

void dfs(int target, int cur, int cost) {
    if (cost > mincost) return;
    if (cur == target) {
        int numtransfer = getTransferCount(curpath);
        if ((cost < mincost) ||
            (cost == mincost && numtransfer < mintransfer)) {
            mincost = cost;
            mintransfer = numtransfer;
            minpath = curpath;
        }
        return;
    }

    for (auto& s : adj[cur]) {
        if (visited[s]) continue;
        visited[s] = 1;
        curpath.push_back(s);
        dfs(target, s, cost + 1);
        curpath.pop_back();
        visited[s] = 0;
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        int m, id1, id2;
        scanf("%d %d", &m, &id1);
        for (int j = 1; j < m; ++j) {
            scanf("%d", &id2);
            line[id1][id2] = line[id2][id1] = i;
            adj[id1].push_back(id2);
            adj[id2].push_back(id1);
            id1 = id2;
        }
    }

    int numq;
    scanf("%d", &numq);
    for (int i = 0; i < numq; ++i) {
        int source, target;
        scanf("%d %d", &source, &target);

        mincost = 999999;
        mintransfer = 999999;
        curpath.clear();
        curpath.push_back(source);
        visited[source] = 1;
        dfs(target, source, 0);
        visited[source] = 0;

        printf("%d\n", mincost);
        int s = 0, preline = line[minpath[0]][minpath[1]];
        int size = minpath.size();
        for (int i = 1; i < size; ++i) {
            int curline = line[minpath[i - 1]][minpath[i]];
            if (curline != preline) {
                printf("Take Line#%d from %04d to %04d.\n", preline, minpath[s], minpath[i - 1]);
                s = i - 1;
                preline = curline;
            }
        }
        printf("Take Line#%d from %04d to %04d.\n", preline, minpath[s], minpath[size - 1]);
    }

    return 0;
}
