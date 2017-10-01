#include <bits/stdc++.h>
using namespace std;

string pwd, input;
int n, numtry, numwrong;

int main() {
    cin >> pwd >> n;
    getchar();
    while (true) {
        getline(cin, input);
        if (input.length() == 1 && input == "#") break;
        numtry++;
        if (input != pwd) {
            cout << "Wrong password: " << input << '\n';
            numwrong++;
            if (numwrong == n) {
                cout << "Account locked\n";
                break;
            }
        } else if (numtry <= n) {
            cout << "Welcome in\n";
            break;
        }
    }

    return 0;
}
