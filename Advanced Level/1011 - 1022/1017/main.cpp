#include <bits/stdc++.h>
using namespace std;

const int STIME = 8 * 3600;

typedef struct info {
    int p, t;
} info;

int cmp(info a, info b) { return a.t < b.t; }

int arrivetime(int h, int m, int s) {
    return h * 3600 + m * 60 + s - STIME;
}

int n, k, numc, waits;
vector<info> data;
int quewaittime[100];

int minindex() {
    int ret = 0;
    for (int i = 1; i < k; ++i) {
        if (quewaittime[i] < quewaittime[ret]) ret = i;
    }
    return ret;
}

int main() {
    scanf("%d %d", &n, &k);
    int h, m, s, p;
    for (int i = 0; i < n; ++i) {
        scanf("%d:%d:%d %d", &h, &m, &s, &p);
        if (h >= 17) continue;
        numc++;
        data.push_back({ min(p * 60, 3600), arrivetime(h, m, s) });
    }
    sort(data.begin(), data.end(), cmp);

    for (auto& ci : data) {
        int i = minindex();
        if (quewaittime[i] > ci.t) {
            waits += quewaittime[i] - ci.t;
            quewaittime[i] += ci.p;
        } else {
            quewaittime[i] = ci.p + ci.t;
        }
    }

    printf("%.1f", waits / 60.0 / numc);
    return 0;
}
