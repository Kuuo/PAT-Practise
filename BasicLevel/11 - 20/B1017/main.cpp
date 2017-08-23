#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
char a[1005];
int b;
int main()
{
    scanf("%s %d", &a, &b);
    int len = strlen(a);
    int q = (a[0] - '0') / b;
    if ((q != 0 && len > 1) || len == 1) {
        printf("%d", q);
    }
    int r = (a[0] - '0') % b;
    for (int i = 1; i < len; ++i)
    {
        r = r * 10 + a[i] - '0';
        q = r / b;
        printf("%d", q);
        r = r % b;
    }
    printf(" %d", r);
    return 0;
}