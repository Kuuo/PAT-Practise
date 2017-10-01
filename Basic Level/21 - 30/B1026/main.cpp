#include <bits/stdc++.h>
using namespace std;

int c1, c2;

int main() {
    scanf("%d %d", &c1, &c2);

    int t = (c2 - c1) / 100.0 + .5;

    int h = t / 3600;
    int m = t % 3600 / 60;
    int s = t % 60;

    printf("%02d:%02d:%02d", h, m, s);

    return 0;
}
