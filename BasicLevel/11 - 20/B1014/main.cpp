#include <cstdio>
#include <cstring>
#include <algorithm>

char a[61], b[61];
char day[][4] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
int f1 = 0;

int main()
{
    scanf("%s", a);
    scanf("%s", b);

    int minlen = std::min(strlen(a), strlen(b));

    for (int i = 0; i < minlen; ++i)
    {
        if (a[i] == b[i])
        {
            if (f1 == 0 && a[i] >= 'A' && a[i] <= 'G')
            {
                f1 = 1;
                printf("%s ", day[a[i] - 'A']);
            }
            else if (f1 == 1)
            {
                if (a[i] >= '0' && a[i] <= '9')
                {
                    printf("0%d:", a[i] - '0');
                    break;
                }
                else if (a[i] >= 'A' && a[i] <= 'N')
                {
                    printf("%d:", 10 + (a[i] - 'A'));
                    break;
                }
            }
        }
    }

    scanf("%s", a);
    scanf("%s", b);

    minlen = std::min(strlen(a), strlen(b));
    for (int i = 0; i < minlen; ++i)
    {
        if (a[i] == b[i] &&
            ((a[i] <= 'Z' && a[i] >= 'A') ||
             (a[i] <= 'z' && a[i] >= 'a')))
        {
            if (i < 10) {
                printf("0%d", i);
                break;
            }
            else
            {
                printf("%d", i);
                break;
            }
        }
    }
    return 0;
}
