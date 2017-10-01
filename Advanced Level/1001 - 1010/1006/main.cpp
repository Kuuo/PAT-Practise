#include <bits/stdc++.h>
using namespace std;

int n;

typedef struct _info {
    string id;
    int inh, inm, ins;
    int outh, outm, outs;
} info;

int cmpin(info a, info b) {
    if (a.inh == b.inh) {
        if (a.inm == a.inm) return a.ins < b.ins;
        return a.inm < b.inm;
    }
    return a.inh < b.inh;
}

int cmpout(info a, info b) {
    if (a.outh == b.outh) {
        if (a.outm == b.outm) return a.outs > b.outs;
        return a.outm > b.outm;
    }
    return a.outh > b.outh;
}

int main() {
    info mini, maxi, cur;
    string id;
    int inh, inm, ins;
    int outh, outm, outs;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        cin >> id;
        scanf("%d:%d:%d", &inh, &inm, &ins);
        scanf("%d:%d:%d", &outh, &outm, &outs);
        cur = { id, inh, inm, ins, outh, outm, outs };
        if (i == 0) {
            maxi = mini = cur;
        } else {
            if (cmpin(cur, mini)) mini = cur;
            if (cmpout(cur, maxi)) maxi = cur;
        }
    }

    cout << mini.id << " " << maxi.id;

    return 0;
}
