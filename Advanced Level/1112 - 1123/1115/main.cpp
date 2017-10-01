#include <bits/stdc++.h>
using namespace std;

typedef struct node {
    int value = 0;
    node *lch = nullptr, *rch = nullptr;
    node(int data = 0) : value(data) {}
} node;

void insert(node* root, int data) {
    if (data <= root->value) {
        if (root->lch == nullptr) {
            root->lch = new node(data);
        } else {
            insert(root->lch, data);
        }
    } else {
        if (root->rch == nullptr) {
            root->rch = new node(data);
        } else {
            insert(root->rch, data);
        }
    }
}

int maxdepth(node* root) {
    if (root == nullptr) return 0;
    return max(maxdepth(root->lch), maxdepth(root->rch)) + 1;
}

int k, depth, count1, count2;

void bfs(node* root) {
    queue<node*> que;
    que.push(root);
    int curdepth = 0;
    while (!que.empty()) {
        curdepth++;
        int len = que.size();
        for (int i = 0; i < len; ++i) {
            auto cur = que.front();
            if (curdepth == depth) {
                count1++;
            } else if (curdepth == depth - 1) {
                count2++;
            }
            if (cur->lch != nullptr) que.push(cur->lch);
            if (cur->rch != nullptr) que.push(cur->rch);
            que.pop();
        }
    }
}

int main() {
    cin >> k;
    int n;
    cin >> n;
    node* root = new node(n);
    for (int i = 1; i < k; ++i) {
        cin >> n;
        insert(root, n);
    }
    depth = maxdepth(root);
    bfs(root);
    printf("%d + %d = %d", count1, count2, count1 + count2);
    return 0;
}
