#include <bits/stdc++.h>
using namespace std;

string input;
int num0, num1, sum;

int main() {
    getline(cin, input);
    int len = input.length();

    char ch;
    for (int i = 0; i < len; ++i) {
        ch = tolower(input[i]);
        if (ch > 'z' || ch < 'a') continue;
        sum += ch - 'a' + 1;
    }

    while (sum) {
        if ((sum & 1)) num1++;
        else num0++;
        sum >>= 1;
    }

    printf("%d %d", num0, num1);

    return 0;
}
