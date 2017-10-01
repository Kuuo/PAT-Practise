#include <bits/stdc++.h>
using namespace std;

int n, m;
int ret[105], maxdepth;
vector<int> node[105];

void dfs(int id, int depth) {
    if (node[id].size() == 0) {
        ret[depth]++;
        maxdepth = max(maxdepth, depth);
        return;
    }

    for (auto& x : node[id]) {
        dfs(x, depth + 1);
    }
}

int main() {
    scanf("%d %d", &n, &m);
    int tid, tid1, tk;
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &tid, &tk);
        for (int j = 0; j < tk; ++j) {
            scanf("%d", &tid1);
            node[tid].push_back(tid1);
        }
    }

    dfs(1, 0);

    printf("%d", ret[0]);
    for (int i = 1; i <= maxdepth; ++i) printf(" %d", ret[i]);

    return 0;
}
