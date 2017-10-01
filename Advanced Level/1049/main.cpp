#include <bits/stdc++.h>
using namespace std;

long n, ret;

int main() {
    scanf("%ld", &n);

    int low, high, cur;
    for (int i = 1; n / i != 0; i *= 10) {
        low = n % i;
        cur = n / i % 10;
        high = n / i / 10;
        if (cur == 0) {
            ret += high * i;
        } else if (cur == 1) {
            ret += high * i + low + 1;
        } else {
            ret += high * i + i;
        }
    }

    printf("%ld", ret);
    return 0;
}
