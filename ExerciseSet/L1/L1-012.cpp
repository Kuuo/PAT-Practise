#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    printf("2^%d = %ld", n, (1 << n));

    return 0;
}