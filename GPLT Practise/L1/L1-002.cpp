#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

int n;
char shape;

void print_ss(int scnt, int ccnt) {
    for (int i = 0; i < scnt; ++i)
    {
        printf(" ");
    }
    for (int i = 0; i < ccnt; ++i)
    {
        printf("%c", shape);
    }
    printf("\n");
}

int main() {
    scanf("%d %c", &n, &shape);

    int row = sqrt((n + 1) / 2);

    for (int i = 0; i < row; ++i)
    {
        print_ss(i, 2 * (row - i) - 1);
    }

    for (int i = row - 2; i > -1; --i)
    {
        print_ss(i, 2 * (row - i) - 1);
    }

    int left = n - 2 * row * row + 1;
    printf("%d\n", left);
    return 0;
}
