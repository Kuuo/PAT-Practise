#include <bits/stdc++.h>
using namespace std;

int n, m;
int numcurlvlnode, numcurlvlleaf, cur;
vector<int> node[105], ret;
queue<int> que;

int main() {
    scanf("%d %d", &n, &m);
    int tid, tid1, tk;
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &tid, &tk);
        for (int j = 0; j < tk; ++j) {
            scanf("%d", &tid1);
            node[tid].push_back(tid1);
        }
    }

    que.push(1);

    while (!que.empty()) {
        numcurlvlnode = que.size();
        for (int i = 0; i < numcurlvlnode; ++i) {
            cur = que.front();
            que.pop();

            if (node[cur].empty()) {
                numcurlvlleaf++;
            } else {
                for (auto& x : node[cur]) {
                    que.push(x);
                }
            }
        }
        ret.push_back(numcurlvlleaf);
        numcurlvlleaf = 0;
    }

    printf("%d", ret[0]);
    for (int i = 1; i < ret.size(); ++i) printf(" %d", ret[i]);

    return 0;
}
