#include <bits/stdc++.h>
using namespace std;

int n, m, k, q;
queue<int> que[20];
int needtime[1001], passedtime[20], ret[1001], sumtime[20];

int mintimeindex() {
    int ret = 0;
    // first queue that is not full
    while (ret < n && (int)que[ret].size() >= m) ret++;

    // if all queue is full...
    if (ret == n) {
        ret = 0;
        for (int i = 1; i < n; ++i) {
            if (passedtime[i] + que[i].front() < passedtime[ret] + que[ret].front()) ret = i;
        }
        passedtime[ret] += que[ret].front();
        que[ret].pop();
        return ret;
    }

    for (int i = ret + 1; i < n; ++i) {
        if (que[i].size() < que[ret].size()) ret = i;
    }
    return ret;
}

int main() {
    scanf("%d %d %d %d", &n, &m, &k, &q);
    int transactiontime;
    for (int i = 0; i < k; ++i) {
        scanf("%d", &transactiontime);
        needtime[i + 1] = transactiontime;
        int index = mintimeindex();
        que[index].push(transactiontime);
        sumtime[index] += transactiontime;
        ret[i + 1] = sumtime[index];
    }

    int request;
    for (int i = 0; i < q; ++i) {
        scanf("%d", &request);
        if (request > k || ret[request] - needtime[request] >= 540) {
            printf("Sorry\n");
            continue;
        }
        int totmin = ret[request];
        int h = 8 + totmin / 60;
        int m = totmin % 60;
        printf("%02d:%02d\n", h, m);
    }

    return 0;
}
