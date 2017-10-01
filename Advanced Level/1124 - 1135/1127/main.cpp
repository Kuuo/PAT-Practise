#include <bits/stdc++.h>
using namespace std;

typedef struct node {
    int data = -1;
    node *lch = nullptr, *rch = nullptr;
    node(int val = 0) : data(val) {}
} node;

int n;
vector<int> in, post;

node* build(int inl, int inr, int pol, int por) {
    if (inl > inr) return nullptr;
    int rootdata = post[por];
    node* root = new node(rootdata);

    int rootindex = find(in.begin() + inl, in.begin() + inr + 1, rootdata) - in.begin();
    int numlch = rootindex - inl;

    root->lch = build(inl, rootindex - 1, pol, pol + numlch - 1);
    root->rch = build(rootindex + 1, inr, pol + numlch, por - 1);

    return root;
}


vector<int> zigret;

void bfs(node* root) {
    deque<node*> que;
    que.push_back(root);
    int depth = 0;
    while (!que.empty()) {
        int size = que.size();

        vector<int> curlvl;
        for (auto& n : que) {
            if (n == nullptr) continue;
            curlvl.push_back(n->data);
        }
        if ((depth & 1) == 0) reverse(curlvl.begin(), curlvl.end());
        for (auto& x : curlvl) zigret.push_back(x);

        for (int i = 0; i < size; ++i) {
            auto cur = que.front();
            que.pop_front();
            if (cur == nullptr) continue;
            que.push_back(cur->lch);
            que.push_back(cur->rch);
        }
        depth++;
    }
}

int main() {
    scanf("%d", &n);
    in.resize(n);
    post.resize(n);
    for (int i = 0; i < n; ++i) scanf("%d", &in[i]);
    for (int i = 0; i < n; ++i) scanf("%d", &post[i]);

    node* root = build(0, n - 1, 0, n - 1);
    bfs(root);

    printf("%d", zigret[0]);
    for (int i = 1; i < (int)zigret.size(); ++i) {
        printf(" %d", zigret[i]);
    }

    return 0;
}
