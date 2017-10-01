#include <bits/stdc++.h>
using namespace std;

string input;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> input;
        int len = input.size();
        int x = stoi(input);
        int a = stoi(input.substr(0, len / 2));
        int b = stoi(input.substr(len / 2, len / 2));
        if (a == 0 || b == 0) {
            printf("No\n");
            continue;
        }
        if (x % (a * b) == 0) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}
