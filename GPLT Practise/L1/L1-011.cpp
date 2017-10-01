#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#define MAX 10004

using namespace std;

char str[MAX], del[MAX];
set<char> delima;

int main() {
    cin.getline(str, MAX);
    cin.getline(del, MAX);

    int len = strlen(del);
    for (int i = 0; i < len; ++i)
    {
        delima.insert(del[i]);
    }

    len = strlen(str);
    for (int i = 0; i < len; ++i)
    {
        if (delima.count(str[i]) <= 0) {
            printf("%c", str[i]);
        }
    }

    return 0;
}