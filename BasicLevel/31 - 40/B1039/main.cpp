#include <bits/stdc++.h>
using namespace std;

char shop[1005], want[1005];
int dp[300], canbuy = 1, sum;

int main() {
    gets(shop);
    gets(want);

    for (int i = 0; shop[i]; ++i) dp[shop[i]]++;
    for (int i = 0; want[i]; ++i) {
        if (--dp[want[i]] < 0) canbuy = 0;
    }

    for (int i = 0; i < 300; ++i) {
        if (dp == 0) continue;
        if (canbuy) {
            if (dp[i] > 0) sum += dp[i];
        } else {
            if (dp[i] < 0) sum -= dp[i];
        }
    }

    printf("%s", canbuy ? "Yes" : "No");
    printf(" %d", sum);

    return 0;
}
