#include <cstdio>

int main() {
    int fer;
    scanf("%d", &fer);

    double cel = 5.0 * ((fer - 32) / 9.0);
    printf("Celsius = %d", (int)cel);

    return 0;
}
