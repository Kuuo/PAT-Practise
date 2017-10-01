#include <bits/stdc++.h>
using namespace std;

struct node {
    int address, data, next;
} data[100005];

int start, n, k;

int main() {
    scanf("%d %d %d", &start, &n, &k);
    for (int i = 0; i < n; ++i) {
        int address, cdata, next;
        scanf("%d %d %d", &address, &cdata, &next);
        data[address] = { address, cdata, next };
    }

    vector<node> v1, v2, v3;
    int cur = start;
    while (cur != -1) {
        if (data[cur].data < 0) {
            v1.push_back(data[cur]);
        } else if (data[cur].data <= k) {
            v2.push_back(data[cur]);
        } else {
            v3.push_back(data[cur]);
        }
        cur = data[cur].next;
    }

    vector<node> ret;
    for (auto& n : v1) ret.push_back(n);
    for (auto& n : v2) ret.push_back(n);
    for (auto& n : v3) ret.push_back(n);

    int size = ret.size();
    for (int i = 0; i < size - 1; ++i) {
        printf("%05d %d %05d\n", ret[i].address, ret[i].data, ret[i + 1].address);
    }
    printf("%05d %d -1", ret[size - 1].address, ret[size - 1].data);

    return 0;
}
