#include <bits/stdc++.h>
using namespace std;

int n, num[10], singlesum, ret;


int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &num[i]);
        singlesum += num[i];
    }

    for (int i = 0; i < n; ++i) {
        ret += num[i] * 10 * (n - 1) + singlesum - num[i];
    }

    printf("%d", ret);

    return 0;
}
