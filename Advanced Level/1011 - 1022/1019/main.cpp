#include <bits/stdc++.h>
using namespace std;

vector<int> tobase(int n, int base) {
    vector<int> ret;
    do {
        ret.push_back(n % base);
        n /= base;
    } while (n);
    return ret;
}

int ispldmc(vector<int>& n) {
    int i = 0, j = n.size() - 1;
    while (i < j) {
        if (n[i] != n[j]) return 0;
        i++;
        j--;
    }
    return 1;
}

int n, b;

int main() {
    scanf("%d %d", &n, &b);
    auto str = tobase(n, b);
    printf(ispldmc(str) ? "Yes\n" : "No\n");

    printf("%d", str[str.size() - 1]);
    for (int i = str.size() - 2; i >= 0; i--) {
        printf(" %d", str[i]);
    }

    return 0;
}
