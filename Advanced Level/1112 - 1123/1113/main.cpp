#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
vector<ll> num;

ll sum(int l, int r) {
    ll ret = 0;
    for (int i = l; i < r; ++i) ret += num[i];
    return ret;
}

int main() {
    scanf("%d", &n);
    num.resize(n);
    for (int i = 0; i < n; ++i) cin>> num[i];
    sort(num.begin(), num.end());

    int m = n / 2;
    printf("%d %lld", n % 2, sum(m, n) - sum(0, m));
    return 0;
}
