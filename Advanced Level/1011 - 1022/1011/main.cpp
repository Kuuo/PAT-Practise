#include <bits/stdc++.h>
using namespace std;

double a[3], ret = .65;

int main() {
    int maxi;
    while (scanf("%lf %lf %lf", &a[0], &a[1], &a[2]) != EOF) {
        maxi = 0;
        if (a[1] > a[maxi]) maxi = 1;
        if (a[2] > a[maxi]) maxi = 2;

        if (maxi == 0) {
            printf("W ");
        } else if (maxi == 1) {
            printf("T ");
        } else {
            printf("L ");
        }
        ret *= a[maxi];
    }

    printf("%.2f", (ret - 1) * 2);

    return 0;
}
