#include <bits/stdc++.h>
using namespace std;
#define MAX 100005

int n, m;
int mark[MAX];
vector<int> v;

struct info {
    int married, come, other;
} data[MAX];

int main() {
    scanf("%d", &n);
    int a, b, maxid = 0, minid = 999999;
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &a, &b);
        data[a].married = data[b].married = 1;
        data[a].other = b;
        data[b].other = a;
        minid = min(minid, min(a, b));
        maxid = max(maxid, max(a, b));
    }

    int c;
    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d", &c);
        if (c > maxid) maxid = c;
        if (c < minid) minid = c;
        if (data[c].married == 0) {
            v.push_back(c);
        } else {
            data[c].come = 1;
        }
    }

    for (int i = minid; i <= maxid; ++i) {
        if (!data[i].married) continue;
        if (data[i].come == 1 && data[data[i].other].come != 1)
            v.push_back(i);
    }

    sort(v.begin(), v.end());
    printf("%d\n", v.size());
    for (int i = 0; i < v.size(); ++i) {
        if (i > 0) printf(" ");
        printf("%05d", v[i]);
    }

    return 0;
}
