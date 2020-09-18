#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int dt[30];
int n, s, cur;

char sign[30];

void step(int i) {
    if (i == n) {
        if (cur == s) {
            cout << *dt;
            for (int i = 1; i < n; i++) {
                cout << sign[i] << dt[i];
            }
            cout << "=" << s;
            exit(0);
        }
        return;
    }
    int &x = dt[i];
    char &c = sign[i];
    cur += x;
    c = '+';
    step(i + 1);
    cur -= x << 1;
    c = '-';
    step(i + 1);
    cur += x;
    return;
}

int main()
{
    cin >> n >> s;
    for(int i = 0; i < n; i++) {
        cin >> dt[i];
    }
    cur = *dt;
    step(1);
    cout << "No solution" << endl;
}