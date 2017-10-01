#include <bits/stdc++.h>
using namespace std;
#define MAXN 205

int numv, nume, numq;
int haspath[MAXN][MAXN];

int isHamiltonian(vector<int>& cycle) {
    int size = cycle.size();
    if (size != numv + 1) return 0;
    if (cycle[0] != cycle[size - 1]) return 0;

    set<int> s;
    for (auto& v : cycle) s.insert(v);
    if ((int)s.size() < numv) return 0;

    for (int i = 1; i < size; ++i) {
        int u = cycle[i - 1], v = cycle[i];
        if (!haspath[u][v]) return 0;
    }
    return 1;
}

int main() {
    scanf("%d %d", &numv, &nume);
    for (int i = 0; i < nume; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        haspath[a][b] = 1;
        haspath[b][a] = 1;
    }

    scanf("%d", &numq);
    for (int i = 0; i < numq; ++i) {
        int k, v;
        scanf("%d", &k);
        vector<int> cycle;
        for (int j = 0; j < k; ++j) {
            scanf("%d", &v);
            cycle.push_back(v);
        }
        printf(isHamiltonian(cycle) ? "YES\n" : "NO\n");
    }

    return 0;
}
