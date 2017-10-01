#include <cstdio>
#include <iostream>
#include <cstring>
#include <map>

using namespace std;

typedef struct info
{
    string id;
    int testid;
}info;

map<int, info> infos;

int main()
{
    int n;
    scanf("%d", &n);

    string tid;
    int tid1, tid2;
    for (int i = 0; i < n; ++i)
    {
        cin >> tid >> tid1 >> tid2;
        infos[tid1] = { tid, tid2 };
    }

    int cnt;
    scanf("%d", &cnt);

    int needid;
    for (int i = 0; i < cnt; ++i)
    {
        scanf("%d", &needid);
        auto found = infos[needid];
        cout << found.id << " " << found.testid << '\n';
    }
    return 0;
}
