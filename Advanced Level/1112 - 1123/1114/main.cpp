#include <bits/stdc++.h>
using namespace std;
#define MAXN 10005

typedef struct {
    set<int> relatives;
    int estate = 0, area = 0, visited = 0, isvalid = 0;
} node;

typedef struct {
    int minid = 999999, count = 0;
    int sumestate = 0, sumarea = 0;
    double avgsets, avgarea;
} fnode;

int cmp(fnode a, fnode b) {
    if (a.avgarea != b.avgarea) return a.avgarea > b.avgarea;
    return a.minid < b.minid;
}

int n;
vector<node> data(MAXN);
vector<fnode> ret;

void dfs(int id, fnode& s) {
    data[id].visited = 1;
    s.minid = min(id, s.minid);
    s.sumestate += data[id].estate;
    s.sumarea += data[id].area;
    s.count++;

    for (auto& r : data[id].relatives) {
        if (data[r].visited) continue;
        dfs(r, s);
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int id1, id2, id3, idc, k, estate, area;
        scanf("%d %d %d %d", &id1, &id2, &id3, &k);
        if (id2 != -1) {
            data[id1].relatives.insert(id2);
            data[id2].relatives.insert(id1);
            data[id2].isvalid = 1;
        }
        if (id3 != -1) {
            data[id1].relatives.insert(id3);
            data[id3].relatives.insert(id1);
            data[id3].isvalid = 1;
        }
        for (int j = 0; j < k; ++j) {
            scanf("%d", &idc);
            data[id1].relatives.insert(idc);
            data[idc].relatives.insert(id1);
            data[idc].isvalid = 1;
        }
        scanf("%d %d", &estate, &area);
        data[id1].estate += estate;
        data[id1].area += area;
        data[id1].isvalid = 1;
    }

    for (int i = 0; i < MAXN; i++) {
        if (!data[i].isvalid || data[i].visited) continue;
        fnode temp;
        dfs(i, temp);
        temp.avgarea = temp.sumarea / (temp.count * 1.0);
        temp.avgsets = temp.sumestate / (temp.count * 1.0);
        ret.push_back(temp);
    }
    sort(ret.begin(), ret.end(), cmp);

    printf("%llu\n", ret.size());
    for (auto& s : ret) {
        printf("%04d %d %.3f %.3f\n", s.minid, s.count, s.avgsets, s.avgarea);
    }
    return 0;
}
