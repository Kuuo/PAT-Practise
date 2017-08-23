#include <cstdio>

int main()
{
    int N = 0;
    int a1 = 0, a2 = 0, a3 = 0, a5 = -1;
    int f1 = 0, f2 = 0, f3 = 0, f4 = 0, f5 = 0;
    double a4 = 0;
    int numa4 = 0;
    int ca2 = 1;

    scanf("%d", &N);

    int curnum, reminder;
    for (int i = 0; i < N; ++i)
    {
        scanf("%d", &curnum);
        reminder = curnum % 10;
        if (reminder == 0) {
            f1 = 1;
            a1 += curnum;
        }
        if (reminder == 1 || reminder == 6) {
            f2 = 1;
            a2 += ca2 * curnum;
            ca2 *= -1;
        }
        if (reminder == 2 || reminder == 7) {
            f3 = 1;
            a3++;
        }
        if (reminder == 3 || reminder == 8) {
            f4 = 1;
            a4 += curnum;
            numa4++;
        }
        if (reminder == 4 || reminder == 9) {
            f5 = 1;
            a5 = (a5 >= curnum) ? a5 : curnum;
        }
    }

    a4 = a4 / numa4;

    if (f1 == 0) printf("N ");
    else printf("%d ", a1);
    if (f2 == 0) printf("N ");
    else printf("%d ", a2);
    if (f3 == 0) printf("N ");
    else printf("%d ", a3);
    if (f4 == 0) printf("N ");
    else printf("%.1f ", a4);
    if (f5 == 0) printf("N");
    else printf("%d", a5);

    return 0;
}