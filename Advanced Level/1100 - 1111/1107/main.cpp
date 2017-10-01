#include <bits/stdc++.h>
using namespace std;

int n;

typedef struct node {
    set<int> hobbies;
    int count, isvalid;
} node;

int cmp(node a, node b) {
    if (a.isvalid != b.isvalid) return a.isvalid > b.isvalid;
    return a.count > b.count;
}

vector<node> slist;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int k;
        scanf("%d", &k);
        getchar();
        set<int> hs;
        for (int j = 0; j < k; ++j) {
            int h;
            scanf("%d", &h);
            hs.insert(h);
        }
        int found = 0;
        set<int> foundindex;
        for (auto& h : hs) {
            for (int i = 0; i < (int)slist.size(); i++) {
                if (!slist[i].isvalid) continue;
                auto hh = slist[i].hobbies;
                if (hh.find(h) != hh.end()) {
                    foundindex.insert(i);
                    slist[i].isvalid = 0;
                    found = 1;
                }
            }
        }
        if (found){
            int newcount = 1;
            for (auto& index : foundindex) {
                newcount += slist[index].count;
                for (auto& h : slist[index].hobbies) {
                    hs.insert(h);
                }
            }
            slist.push_back({ hs, newcount, 1 });
        } else {
            slist.push_back({ hs, 1, 1 });
        }
    }

    sort(slist.begin(), slist.end(), cmp);
    int size = 0;
    while (slist[size].isvalid) size++;
    cout << size << endl;
    printf("%d", slist[0].count);
    for (int i = 1; i < size; ++i) printf(" %d", slist[i].count);

    return 0;
}
