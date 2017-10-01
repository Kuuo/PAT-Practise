#include <bits/stdc++.h>
using namespace std;

int n, m, k;
vector<int> uf, e1, e2;

void init() { for (int i = 0; i <= n; i++) uf[i] = i; }
int find(int x) { return (uf[x] == x) ? x : uf[x] = find(uf[x]); }
void merge(int a, int b) { uf[find(a)] = find(b); }
int cnt() {
    int ret = 0;
    for (int i = 1; i <= n; ++i) {
        if (uf[i] == i) ret++;
    }
    return ret - 2;
}

int main() {
    scanf("%d %d %d", &n, &m, &k);
    uf.resize(n);

    int ine1, ine2;
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &ine1, &ine2);
        e1.push_back(ine1);
        e2.push_back(ine2);
    }

    int v;
    for (int i = 0; i < k; ++i) {
        scanf("%d", &v);
        if (v > n || v < 1) {
            printf("0\n");
            continue;
        }
        init();
        for (int j = 0; j < m; ++j) {
            if (e1[j] == v || e2[j] == v) continue;
            merge(e1[j], e2[j]);
        }
        printf("%d\n", cnt());
    }

    return 0;
}
