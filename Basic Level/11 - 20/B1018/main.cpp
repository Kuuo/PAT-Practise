#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
char ca, cb;
int N, a1 = 0, a2 = 0, a3 = 0;
int a[3] = {0}, b[3] = {0};
int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; ++i)
    {
        cin >> ca >> cb;
        if (ca == cb) {
            a2++;
        } else {
            if (ca == 'C') {
                if (cb == 'J') {
                    a1++;
                    a[0]++;
                } else if (cb == 'B') {
                    a3++;
                    b[2]++;
                }
            } else if (ca == 'J') {
                if (cb == 'C') {
                    a3++;
                    b[0]++;
                } else if (cb == 'B') {
                    a1++;
                    a[1]++;
                }
            } else if (ca == 'B') {
                if (cb == 'C') {
                    a1++;
                    a[2]++;
                } else if (cb == 'J') {
                    a3++;
                    b[1]++;
                }
            }
        }
    }
    printf("%d %d %d\n", a1, a2, a3);
    printf("%d %d %d\n", a3, a2, a1);
    int amax = max(a[0], max(a[1], a[2]));
    int bmax = max(b[0], max(b[1], b[2]));
    if (a[2] == amax) {
        printf("B ");
    } else if (a[0] == amax) {
        printf("C ");
    } else {
        printf("J ");
    }
    if (b[2] == bmax) {
        printf("B");
    } else if (b[0] == bmax) {
        printf("C");
    } else {
        printf("J");
    }

    return 0;
}
