#include <bits/stdc++.h>
using namespace std;

int diff = 'A' - 'a';
char a[100], b[100], ret[100];
unordered_set<char> csb, csa;

char toUpper(char c) {
    if (c >= 'a' && c <= 'z') return c + diff;
    return c;
}

int main() {
    scanf("%s", &a);
    scanf("%s", &b);

    int len2 = strlen(b);
    for (int i = 0; i < len2; ++i) {
        csb.insert(toUpper(b[i]));
    }

    int len = strlen(a);
    for (int i = 0; i < len; ++i) {
        a[i] = toUpper(a[i]);
        if (csb.count(a[i]) < 1 && csa.count(a[i]) < 1) {
            csa.insert(a[i]);
            printf("%c", a[i]);
        }
    }

    return 0;
}
