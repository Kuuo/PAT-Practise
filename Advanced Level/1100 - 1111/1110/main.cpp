#include <bits/stdc++.h>
using namespace std;

int n;
int lch[20], rch[20];
int parent[20];

int findroot() {
    for (int i = 0; i < n; ++i) {
        if (parent[i] == -1) return i;
    }
    return -1;
}

int iscbt(int root, int& lastid) {
    int numnode = 0;
    queue<int> que;
    que.push(root);
    while (!que.empty()) {
        int v = que.front();
        que.pop();
        if (v == -1) break;
        lastid = v;
        numnode++;
        que.push(lch[v]);
        que.push(rch[v]);
    }

    return numnode == n;
}


int main() {
    scanf("%d", &n);
    fill(parent, parent + n, -1);
    for (int i = 0; i < n; ++i) {
        string l, r;
        cin >> l >> r;
        lch[i] = l[0] == '-' ? -1 : stoi(l);
        rch[i] = r[0] == '-' ? -1 : stoi(r);
        if (lch[i] != -1) parent[lch[i]] = i;
        if (rch[i] != -1) parent[rch[i]] = i;
    }

    int last = -1, root = findroot();
    if (iscbt(root, last)) printf("YES %d", last);
    else printf("NO %d", root);

    return 0;
}
