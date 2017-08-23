#include <bits/stdc++.h>
using namespace std;

typedef struct node {
    int address;
    int data;
    int next;
}node;

node allNode[100005];
int start;
int n, k;
node ret[100005];

void print(node& n) {
    printf("%05d %d %05d\n", n.address, n.data, n.next);
}

int main() {
    scanf("%d %d %d", &start, &n, &k);

    if (start == -1) {
        printf("-1");
        return 0;
    }

    int tadd, tdata, tnext;
    for (int i = 0; i < n; ++i) {
        scanf("%d %d %d", &tadd, &tdata, &tnext);
        allNode[tadd] = { tadd, tdata, tnext };
    }

    int cnt = 1;
    ret[0] = allNode[start];
    for (int i = 1; i < n; i++, cnt++) {
        if (ret[i - 1].next == -1) break;
        ret[i] = allNode[ret[i - 1].next];
    }

    n = cnt;
    if (k != 0) {
        int revnum = n / k;
        for (int i = 1; i <= revnum; i++) {
            reverse(ret + (i - 1) * k, ret + i * k);
        }
    }

    for (int i = 0; i < n - 1; ++i) {
        ret[i].next = ret[i + 1].address;
        print(ret[i]);
    }
    printf("%05d %d -1", ret[n - 1].address, ret[n - 1].data);

    return 0;
}
