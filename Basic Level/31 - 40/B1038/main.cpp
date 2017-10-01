#include <bits/stdc++.h>
using namespace std;

int n, k, t;
int score[105];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &t);
        score[t]++;
    }

    scanf("%d", &k);
    for (int i = 0; i < k; ++i) {
        scanf("%d", &t);
        if (i > 0) printf(" ");
        printf("%d", score[t]);
    }

    return 0;
}
