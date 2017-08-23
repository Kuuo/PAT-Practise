#include <cstdio>
#include <cmath>

int main() {
    int col;
    char star;
    scanf("%d %c", &col, &star);
    int row = (int)round(col / 2.0);

    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            printf("%c", star);
        }
        printf("\n");
    }

    return 0;
}