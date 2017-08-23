#include <bits/stdc++.h>
using namespace std;

char signn, signe;
int n, e;
char fl[10004];

int main() {
    scanf("%c%d.%s", &signn, &n, &fl);

    int _t;
    sscanf(fl, "%dE%c%d", &_t, &signe, &e);

    int flen = strlen(fl);
    for (int i = 0; i < flen; ++i) {
        if (fl[i] == 'E') {
            fl[i] = '\0';
            flen = i;
            break;
        }
    }

    if (signn == '-') printf("%c", signn);

    if (e == 0) {
        printf("%d.%s\n", n, fl);
        return 0;
    }

    if (signe == '+') {
        printf("%d", n);
        if (flen <= e) {
            printf("%s", fl);
            for (int i = 0; i < e - flen; ++i) {
                printf("0");
            }
        } else {
            int ptr;
            for (ptr = 0; ptr <= flen - e; ptr++) {
                printf("%c", fl[ptr]);
            }
            printf(".");
            for (; ptr < flen; ptr++) printf("%c", fl[ptr]);
        }
    } else {
        printf("0.");
        for (int i = 0; i < e - 1; ++i) {
            printf("0");
        }
        printf("%d%s", n, fl);
    }

    return 0;
}
