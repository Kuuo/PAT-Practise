#include <bits/stdc++.h>
using namespace std;
#define MAX 2500

typedef struct node {
    int e;
    double c;
} node;

vector<node> p1, p2;

void input(vector<node>& p) {
    int n, te;
    double tc;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d %lf", &te, &tc);
        p.push_back({ te, tc });
    }
}

int main() {
    input(p1);
    input(p2);
    vector<double> ret(MAX, 0.0);
    int cnt = 0;

    for (auto& t1 : p1) {
        for (auto& t2 : p2) {
            ret[t1.e + t2.e] += t1.c * t2.c;
        }
    }

    cnt = count_if(ret.begin(), ret.end(),
                   [](double a) -> int { return fabs(a) > 1e-6; });

    printf("%d", cnt);
    for (int i = MAX; i >= 0; --i) {
        if (fabs(ret[i]) > 1e-6) {
            printf(" %d %.1f", i, ret[i]);
        }
    }

    return 0;
}
