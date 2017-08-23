#include <cstdio>
#include <cstring>

long p[10005];
long isC[105000];
int init()
{
    memset(p, 0, sizeof(p));
    memset(isC, 0, sizeof(isC));
    int m = 0;
    for (int i = 2; i < 400; ++i)
    {
        if (isC[i] == 0)
        {
            p[m++] = i;
            for (long k = i * i; k < 105000; k += i)
            {
                isC[k] = 1;
            }
        }
    }

    for (long j = 400; j < 105000; ++j)
    {
        if (isC[j] == 0) p[m++] = j;
    }

    return m;
}

int main()
{
    init();

    int M, N;
    scanf("%d %d", &N, &M);

    int flag = 0, cnt = 0;;
    for (long i = N - 1; i < M; ++i)
    {
        printf("%ld", p[i]);
        cnt++;
        if (cnt == 10) {
            cnt = 0;
            printf("\n");
        } else {
            if (i != M - 1) printf(" ");
        }
    }

    return 0;
}