#include <bits/stdc++.h>
using namespace std;

int sum(int n) {
    int ret = 0;
    while (n) {
        ret += n % 10;
        n /= 10;
    }
    return ret;
}

int n;
set<int> ret;

int main() {
    scanf("%d", &n);
    int k;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &k);
        ret.insert(sum(k));
    }

    printf("%llu\n", ret.size());
    int i = 0;
    for (auto& x : ret) {
        if (i == 1) printf(" ");
        i  = 1;
        printf("%d", x);
    }

    return 0;
}
