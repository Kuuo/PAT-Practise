#include <bits/stdc++.h>
using namespace std;

int n;

struct node {
    string data;
    int lch = -1, rch = -1, p = -1;
} node[21];

string inorder(int root) {
    if (root == -1) return "";
    if (node[root].lch != -1 || node[root].rch != -1)
        return "(" + inorder(node[root].lch) + node[root].data + inorder(node[root].rch) + ")";

    return node[root].data;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        string data;
        int li, ri;
        cin >> data >> li >> ri;
        node[i].data = data;
        node[i].lch = li;
        node[i].rch = ri;
        node[li].p = i;
        node[ri].p = i;
    }

    int rootindex = -1;
    for (int i = 1; i <= n; i++) {
        if (node[i].p == -1) {
            rootindex = i;
            break;
        }
    }
    string ret = inorder(rootindex);

    if ((int)ret.size() == 1) {
        cout << ret;
    } else {
        cout << ret.substr(1, ret.size() - 2);
    }

    return 0;
}
