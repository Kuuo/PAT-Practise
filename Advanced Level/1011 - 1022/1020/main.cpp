#include <bits/stdc++.h>
using namespace std;

int n, root;
int post[30], in[30];
int lch[30], rch[30];
queue<int> que;

int build(int p1, int p2, int i1, int i2) {
    if (i1 > i2) return 0;
    int root = post[p2];
    int i = i1;
    while (in[i] != root) i++;
    int lcnt = i - i1;
    lch[root] = build(p1, p1 + lcnt - 1, i1, i - 1);
    rch[root] = build(p1 + lcnt, p2 - 1, i + 1, i2);
    return root;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &post[i]);
    for (int i = 0; i < n; ++i) scanf("%d", &in[i]);

    int root = build(0, n - 1, 0, n - 1);
    int isfirst = 1;
    que.push(root);

    while (!que.empty()) {
        int v = que.front();
        que.pop();
        if (!isfirst) printf(" ");
        if (isfirst) { isfirst = 0; }
        printf("%d", v);

        if (lch[v]) que.push(lch[v]);
        if (rch[v]) que.push(rch[v]);
    }

    return 0;
}
