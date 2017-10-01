#include <bits/stdc++.h>
using namespace std;

int n, flag = 0;
int isnotroot[11];
int lch[11], rch[11];

void bfs(int root) {
    queue<int> que;
    que.push(root);
    int flag = 1;
    while (!que.empty()) {
        int v = que.front();
        que.pop();
        if (flag == 0) printf(" ");
        if (flag == 1) flag = 0;
        printf("%d", v);

        if (rch[v] != -1) que.push(rch[v]);
        if (lch[v] != -1) que.push(lch[v]);
    }
    printf("\n");
}

void inorder(int v) {
    if (v == -1) return;

    inorder(rch[v]);
    if (flag == 1) printf(" ");
    flag = 1;
    printf("%d", v);
    inorder(lch[v]);
}

int main() {
    scanf("%d", &n);
    getchar();
    string line;
    for (int i = 0; i < n; ++i) {
        getline(cin, line);
        lch[i] = line[0] == '-' ? -1 : (line[0] - '0');
        rch[i] = line[2] == '-' ? -1 : (line[2] - '0');
    }

    for (int i = 0; i < n; ++i) {
        if (lch[i] != -1) isnotroot[lch[i]] = 1;
        if (rch[i] != -1) isnotroot[rch[i]] = 1;
    }

    int root;
    for (int i = 0; i < n; ++i) {
        if (!isnotroot[i]) { root = i; break; }
    }

    bfs(root);
    inorder(root);

    return 0;
}
