#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string n1, n2, n;
int tag, radix;
ll target, cur;

ll todec(string num, ll base) {
    ll ret = 0, factor = 1;

    int cur;
    for (int i = num.length() - 1; i >= 0; i--) {
        if (isdigit(num[i])) cur = num[i] - '0';
        else cur = num[i] - 'a' + 10;
        ret += cur * factor;
        factor *= base;
    }

    return ret;
}

int cmp(string num, ll base) {
    ll ret = 0, factor = 1;

    int cur;
    for (int i = num.length() - 1; i >= 0; i--) {
        if (isdigit(num[i])) cur = num[i] - '0';
        else cur = num[i] - 'a' + 10;
        ret += cur * factor;
        if (ret > target) return 1;
        factor *= base;
    }

    return ret == target ? 0 : ret > target ? 1 : -1;
}

int leastbase(string num) {
    int ret = -1, cur;
    for (int i = num.length() - 1; i >= 0; i--) {
        if (isdigit(num[i])) cur = num[i] - '0';
        else cur = num[i] - 'a' + 10;
        ret = max(cur, ret);
    }
    return ret + 1;
}

int main() {
    cin >> n1 >> n2 >> tag >> radix;

    if (tag == 1) {
        target = todec(n1, radix);
        n = n2;
    } else {
        target = todec(n2, radix);
        n = n1;
    }

    int flag = 0, cmpt;
    ll low = leastbase(n), high = target + 1;
    ll curbase = low;
    while (low <= high) {
        cmpt = cmp(n, curbase);
        if (cmpt == 0) {
            flag = 1;
            break;
        } else if (cmpt == 1) {
            high = curbase - 1;
        } else {
            low = curbase + 1;
        }
        curbase = (low + high) / 2;
    }

    if (flag == 1) printf("%ld", curbase);
    else printf("Impossible");

    return 0;
}
