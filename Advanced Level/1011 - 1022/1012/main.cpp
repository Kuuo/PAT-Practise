#include <bits/stdc++.h>
using namespace std;

typedef struct info {
    int id, s;
} info;

int cmp(info a, info b) {
    return a.s > b.s;
}

vector<info> vc, vm, ve, va;

int n, k, id;
int c, m, e, a;

// 100 90 90 80 ，排名应该为1，2，2，4
int ranki(vector<info>& v, int id) {
    if (v[0].id == id) return 1;
    int size = v.size();
    int* ranks = new int[size];
    ranks[0] = 1;
    for (int j = 1; j < size; j++) {
        if (v[j].s == v[j - 1].s) {
            ranks[j] = ranks[j - 1];
        } else {
            ranks[j] = j + 1;
        }
        if (v[j].id == id) return ranks[j];
    }
    return -1;
}

char chara[] = { 'A', 'C', 'M', 'E' };

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%d %d %d %d", &id, &c, &m, &e);
        vc.push_back({ id, c });
        vm.push_back({ id, m });
        ve.push_back({ id, e });
        va.push_back({ id, (c + m + e) });
    }

    sort(vc.begin(), vc.end(), cmp);
    sort(vm.begin(), vm.end(), cmp);
    sort(ve.begin(), ve.end(), cmp);
    sort(va.begin(), va.end(), cmp);

    int rr[4], besti;
    for (int i = 0; i < k; ++i) {
        scanf("%d", &id);
        rr[1] = ranki(vc, id);
        rr[2] = ranki(vm, id);
        rr[3] = ranki(ve, id);
        rr[0] = ranki(va, id);

        if (any_of(rr, rr + 4, [](int i) -> int { return i < 0; })) {
            printf("N/A\n");
            continue;
        }

        besti = 0;
        for (int i = 1; i < 4; ++i) {
            if (rr[i] < rr[besti]) besti = i;
        }
        printf("%d %c\n", rr[besti], chara[besti]);
    }
    return 0;
}
