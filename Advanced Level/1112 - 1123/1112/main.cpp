#include <bits/stdc++.h>
using namespace std;

int k;
string input;
int stucked[300], notstucked[300];
vector<char> found;

int contain(char c) {
    int len = found.size();
    int i = 0;
    for (; i < len; ++i) {
        if (found[i] == c) return i;
    }
    return -1;
}

int main() {
    scanf("%d", &k);
    getchar();
    getline(cin, input);

    int len = input.size();
    for (int i = 0; i < len;) {
        char ch = input[i];
        int j = i;
        while (j < len && j < i + k && input[j] == ch) j++;
        if (j == i + k && !notstucked[(int)ch]) {
            i = j;
            stucked[(int)ch] = 1;
            int index = contain(ch);
            if (index == -1) found.push_back(ch);
        } else {
            notstucked[(int)ch] = 1;
            stucked[(int)ch] = 0;
            int index = contain(ch);
            if (index != -1) found.erase(found.begin() + index);
            i++;
        }
    }

    for(auto& c : found) cout << c;
    printf("\n");

    for (int i = 0; i < len;) {
        char ch = input[i];
        printf("%c", ch);
        i += stucked[(int)ch] ? k : 1;
    }

    return 0;
}
