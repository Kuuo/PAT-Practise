#include <bits/stdc++.h>
using namespace std;

double epsilon = 1e-2;
double r1, p1, r2, p2;
double a, b;

int main() {
    scanf("%lf %lf %lf %lf", &r1, &p1, &r2, &p2);

    a = r1 * r2 * cos(p1 + p2);
    b = r1 * r2 * sin(p1 + p2);

    if (a <= -epsilon) printf("-");
    printf("%.2f", fabs(a));

    if (b <= -epsilon) printf("-");
    else printf("+");
    printf("%.2fi", fabs(b));

    return 0;
}
