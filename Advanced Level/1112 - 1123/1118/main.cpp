#include <bits/stdc++.h>
using namespace std;
#define MAXN 10005

int n;
int uf[MAXN], exists[MAXN];

void init() { for (int i = 0; i < MAXN; ++i) uf[i] = i; }
int find(int x) { return uf[x] == x ? x : uf[x] = find(uf[x]); }
void merge(int x, int y) { uf[find(x)] = find(y); }
int same(int x, int y) { return find(x) == find(y); }

void setcount(int& tcount, int& bcount) {
    for (int i = 0; i < MAXN; ++i) {
        if (exists[i]) {
            bcount++;
            if (uf[i] == i) tcount++;
        }
    }
}

int main() {
    init();
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int k, cid, id;
        scanf("%d %d", &k, &cid);
        exists[cid] = 1;
        for (int j = 1; j < k; ++j) {
            scanf("%d", &id);
            exists[id] = 1;
            merge(cid, id);
        }
    }

    int c1 = 0, c2 = 0;
    setcount(c1, c2);
    printf("%d %d\n", c1, c2);

    int m, b1, b2;
    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &b1, &b2);
        printf(same(b1, b2) ? "Yes\n" : "No\n");
    }

    return 0;
}
