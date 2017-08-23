#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
char a[15], b[15];
char da, db;
int na, nb, pa = 0, pb = 0;
int main()
{
    scanf("%s %c %s %c", &a, &da, &b, &db);
    na = da - '0';
    nb = db - '0';
    for (int i = 0; i < strlen(a); ++i)
    {
        if (a[i] == da) {
            pa = pa * 10 + na;
        }
    }
    for (int i = 0; i < strlen(b); ++i)
    {
        if (b[i] == db) {
            pb = pb * 10 + nb;
        }
    }
    printf("%d\n", pa + pb);
    return 0;
}
