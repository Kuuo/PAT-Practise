#include <bits/stdc++.h>
using namespace std;

int n, i, s, maxi;
int score[100005];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &i, &s);
        score[i] += s;
        if (score[i] > score[maxi]) maxi = i;
    }

    printf("%d %d", maxi, score[maxi]);

    return 0;
}
