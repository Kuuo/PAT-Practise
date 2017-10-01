#include <bits/stdc++.h>
using namespace std;
#define MAX 100005

int n, num[MAX];
int lmax[MAX], rmin[MAX];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &num[i]);

    lmax[0] = num[0];
    for (int i = 1; i < n; ++i) {
        lmax[i] = num[i] > lmax[i - 1] ? num[i] : lmax[i - 1];
    }

    rmin[n - 1] = num[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        rmin[i] = num[i] < rmin[i + 1] ? num[i] : rmin[i + 1];
    }

    vector<int> ret;
    for (int i = 0; i < n; ++i) {
        if (num[i] >= lmax[i] && num[i] <= rmin[i]) ret.push_back(num[i]);
    }

    int cnt = ret.size();
    printf("%d\n", cnt);
    if (cnt <= 0) { printf("\n"); return 0; }

    printf("%d", ret[0]);
    for (int i = 1; i < cnt; ++i) {
        printf(" %d", ret[i]);
    }

    return 0;
}
