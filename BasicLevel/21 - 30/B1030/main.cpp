#include <bits/stdc++.h>
using namespace std;

int n, p, t;
long num[100005], q;

int lbpos(long nn) {
    return lower_bound(num, num + n, nn) - num;
}

int solve() {
    if (p == 1) return n;
    if (p > num[n - 1]) return 0;

    int ret = 0;
    for (int i = 0; i < n; i++) {
        q = num[i] * p;
        t = lbpos(q);
        if (!binary_search(num, num + n, q)) t--;
        ret = max(ret, t - i + 1);
    }

    return ret;
}

int main() {
    scanf("%d %d", &n, &p);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &num[i]);
    }

    sort(num, num + n);

    printf("%d", solve());

    return 0;
}
