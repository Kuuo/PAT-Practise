#include <bits/stdc++.h>
using namespace std;

int n;
int pre[30], pos[30];
vector<int> ret;

int build(int l1, int r1, int l2, int r2) {
    if (l1 > r1) return 0;
    if (l1 == r1) {
        ret.push_back(pre[l1]);
        return 1;
    }

    int i = l2;
    while (i <= r2 && pos[i] != pre[l1 + 1]) i++;

    int isunique = 1;
    isunique &= build(l1 + 1, l1 + 1 + i - l2, l2, i);
    ret.push_back(pre[l1]);
    isunique &= build(l1 + i - l2 + 2, r1, i + 1, r2 - 1);

    return isunique;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &pre[i]);
    for (int i = 0; i < n; ++i) scanf("%d", &pos[i]);

    int isunique = build(0, n - 1, 0, n - 1);
    printf(isunique ? "Yes\n" : "No\n");

    printf("%d", ret[0]);
    for (int i = 1; i < (int)ret.size(); ++i) printf(" %d", ret[i]);
    printf("\n");
    return 0;
}
