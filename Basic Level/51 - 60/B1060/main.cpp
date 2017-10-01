#include <bits/stdc++.h>
using namespace std;

int data[100005];

int cmp(int a, int b) { return a > b; }

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &data[i + 1]);
    }
    sort(data + 1, data + n + 1, cmp);

    int ret = 0, i = 1;
    while (i <= n && data[i] > i) { ret++; i++; }

    printf("%d", ret);
    return 0;
}
