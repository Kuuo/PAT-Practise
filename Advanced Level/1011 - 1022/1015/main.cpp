#include <bits/stdc++.h>
using namespace std;

int todec(string num, int base) {
    int ret = 0, factor = 1;

    for (int i = num.size() - 1; i >= 0; i--) {
        ret += factor * (num[i] - '0');
        factor *= base;
    }

    return ret;
}

string toradixrev(int num, int radix) {
    string ret = "";
    while (num) {
        ret += (num % radix + '0');
        num /= radix;
    }
    return ret;
}

int isprime(int n) {
    if (n < 2) return 0;
    if (n == 2) return 1;
    if ((n & 1) == 0) return 0;
    int ub = sqrt(n) + 1;
    for (int i = 3; i <= ub; ++i) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int main() {
    int num, base, rnum;
    string snum;
    while (cin >> num >> base) {
        if (!isprime(num)) {
            printf("No\n");
            continue;
        }
        snum = toradixrev(num, base);
        rnum = todec(snum, base);
        if (isprime(rnum)) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }

    return 0;
}
