#include <bits/stdc++.h>
using namespace std;

int n, k;
set<int> ret;

int getid(int n) {
    int id = 0;
    while (n) {
        id = id + n % 10;
        n /= 10;
    }
    return id;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &k);
        ret.insert(getid(k));
    }

    int flag = 0;
    printf("%d\n", ret.size());
    for (auto& x : ret) {
        if (flag) printf(" ");
        flag = 1;
        printf("%d", x);
    }

    return 0;
}
