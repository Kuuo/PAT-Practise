#include <bits/stdc++.h>
using namespace std;
#define MAXN 100005

struct person {
    int single = 1, otherid = 0, come = 0;
} data[MAXN];

int numcouple, numcome, tid1, tid2;

int main() {
    scanf("%d", &numcouple);
    for (int i = 0; i < numcouple; ++i) {
        scanf("%d %d", &tid1, &tid2);
        data[tid1].single = 0;
        data[tid2].single = 0;
        data[tid1].otherid = tid2;
        data[tid2].otherid = tid1;
    }

    scanf("%d", &numcome);
    for (int i = 0; i < numcome; ++i) {
        scanf("%d", &tid1);
        data[tid1].come = 1;
    }

    vector<int> ret;
    for (int i = 0; i < MAXN; ++i) {
        if (!data[i].come) continue;
        if ((!data[i].single && !data[data[i].otherid].come) ||
            (data[i].single)) {
            ret.push_back(i);
        }
    }

    int retnum = ret.size();
    printf("%d\n", retnum);

    if (retnum > 0) {
        printf("%05d", ret[0]);
        for (int i = 1; i < retnum; ++i) {
            printf(" %05d", ret[i]);
        }
    }

    return 0;
}
