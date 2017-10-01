#include <bits/stdc++.h>
using namespace std;
#define MAXN 10005

int n, m, numq;
set<int> adj[MAXN], tempadj[MAXN];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].insert(v);
        adj[v].insert(u);
    }

    scanf("%d", &numq);
    for (int i = 0; i < numq; ++i) {
        int nv, v;
        scanf("%d", &nv);

        for (int j = 0; j < n; ++j) {
            tempadj[j] = adj[j];
        }

        for (int j = 0; j < nv; ++j) {
            scanf("%d", &v);
            for (auto& u : tempadj[v]) {
                tempadj[u].erase(v);
            }
            tempadj[v].clear();
        }

        int flag = 1;
        for (int j = 0; j < n; ++j) {
            if (!tempadj[j].empty()) {
                flag = 0;
                break;
            }
        }
        puts(flag == 1 ? "Yes" : "No");
    }

    return 0;
}
