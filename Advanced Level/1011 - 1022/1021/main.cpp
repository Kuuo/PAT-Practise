#include <bits/stdc++.h>
using namespace std;

int n, nc;
int visited[10001];
int curmaxdepth = 0;
vector<int> ret;
set<int> s;
map<int, vector<int>> adj;

void dfs(int i, int curdepth) {
    visited[i] = 1;
    if (curmaxdepth < curdepth) {
        curmaxdepth = curdepth;
        ret.clear();
        ret.push_back(i);
    } else if (curmaxdepth == curdepth) {
        ret.push_back(i);
    }

    for (auto& v : adj[i]) {
        if (visited[v]) continue;
        dfs(v, curdepth + 1);
    }
}

int main() {
    scanf("%d", &n);
    int a, b;
    for (int i = 0; i < n - 1; ++i) {
        scanf("%d %d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 1; i <= n; ++i) {
        if (visited[i]) continue;
        dfs(i, 0);
        if (i == 1) {
            for (auto& x : ret) s.insert(x);
        }
        nc++;
    }
    if (nc > 1) {
        printf("Error: %d components", nc);
        return 0;
    }

    int temp = *(ret.begin());
    ret.clear();
    fill(visited, visited + 10001, 0);
    curmaxdepth = -1;
    dfs(temp, 0);

    for (auto& x : ret) s.insert(x);
    for (auto& v : s) printf("%d\n", v);
    return 0;
}
