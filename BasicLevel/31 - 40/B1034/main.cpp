#include <bits/stdc++.h>
using namespace std;

long a1, b1, a2, b2;
long a3, b3;
char s1[200], s2[200], s3[200];

long gcd(long a, long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

void minify(long& n, long& d) {
    if (n == 0 || d == 0) return;
    long m = gcd(n, d);
    n /= m;
    d /= m;
}

void setrepr(long n, long d, char *s) {
    if (n == 0) { sprintf(s, "0"); return; }
    if (d == 0) { sprintf(s, "Inf"); return; }
    int isneg = n < 0 || d < 0;
    n = abs(n);
    d = abs(d);
    long q = n / d;
    long r = n % d;
    if (r == 0) {
        sprintf(s, isneg ? "(-%ld)" : "%ld", q);
    } else if (q == 0) {
        sprintf(s, isneg ? "(-%ld/%ld)" : "%ld/%ld", r, d);
    } else {
        sprintf(s, isneg ? "(-%ld %ld/%ld)" : "%ld %ld/%ld", q, r, d);
    }
}

void add() {
    a3 = a1 * b2 + a2 * b1;
    b3 = b1 * b2;
    minify(a3, b3);
    setrepr(a3, b3, s3);
    printf("%s + %s = %s\n", s1, s2, s3);
}

void subs() {
    a3 = a1 * b2 - a2 * b1;
    b3 = b1 * b2;
    minify(a3, b3);
    setrepr(a3, b3, s3);
    printf("%s - %s = %s\n", s1, s2, s3);
}

void mul() {
    a3 = a1 * a2;
    b3 = b1 * b2;
    minify(a3, b3);
    setrepr(a3, b3, s3);
    printf("%s * %s = %s\n", s1, s2, s3);
}

void divd() {
    if (a2 == 0) {
        printf("%s / %s = Inf", s1, s2);
        return;
    }
    a3 = a1 * b2;
    b3 = b1 * a2;
    minify(a3, b3);
    setrepr(a3, b3, s3);
    printf("%s / %s = %s", s1, s2, s3);
}

int main() {
    scanf("%ld/%ld %ld/%ld", &a1, &b1, &a2, &b2);

    minify(a1, b1);
    minify(a2, b2);

    setrepr(a1, b1, s1);
    setrepr(a2, b2, s2);

    add();
    subs();
    mul();
    divd();

    return 0;
}
