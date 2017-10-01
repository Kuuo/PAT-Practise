#include <bits/stdc++.h>
using namespace std;

int score[1005];
int n, ci, ct, cs, maxi;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d-%d %d", &ci, &ct, &cs);
        score[ci] += cs;
        if (score[ci] > score[maxi]) maxi = ci;
    }

    printf("%d %d", maxi, score[maxi]);

    return 0;
}
