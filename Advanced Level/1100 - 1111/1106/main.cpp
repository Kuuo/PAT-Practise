#include <bits/stdc++.h>
using namespace std;

int n;
double p, r;
int mindis = 9999999, mincnt = 999999;
int visited[100005], isretailer[100005];
vector<int> adj[100005];

void dfs(int v, int dis) {
    if (isretailer[v]) {
        if (dis < mindis) {
            mindis = dis;
            mincnt = 1;
        } else if (dis == mindis) {
            mincnt++;
        }
        return;
    }

    for (auto& x : adj[v]) {
        if (visited[x]) continue;
        visited[x] = 1;
        dfs(x, dis + 1);
        visited[x] = 0;
    }
}

int main() {
    scanf("%d %lf %lf", &n, &p, &r);
    for (int i = 0; i < n; ++i) {
        int k;
        scanf("%d", &k);
        if (k == 0) isretailer[i] = 1;
        for (int j = 0; j < k; ++j) {
            int t;
            scanf("%d", &t);
            adj[i].push_back(t);
            adj[t].push_back(i);
        }
    }

    dfs(0, 0);
    printf("%.4f %d", p * pow(1 + r / 100.0, mindis), mincnt);
    return 0;
}
