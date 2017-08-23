#include <bits/stdc++.h>
using namespace std;

int n, d;
int num1, num2;
double e;

int main() {
    scanf("%d %lf %d", &n, &e, &d);

    int totalday = 0, leday = 0;;
    double cure;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &totalday);
        leday = 0;
        for (int j = 0; j < totalday; ++j) {
            scanf("%lf", &cure);
            if (cure < e) leday++;
        }
        if (leday > totalday / 2) {
            if (totalday > d) num2++;
            else num1++;
        }
    }

    printf("%.1f%% %.1f%%", (double)num1 / n * 100, (double)num2 / n * 100);

    return 0;
}
