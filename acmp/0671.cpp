/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0671 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(), x.end()

int main() {
    string s; cin >> s;
    long long base = (1LL << s.length()) - 2, ost = 1LL;

    reverse(ALL(s));
    for (unsigned i = 0; s[i]; i++) {
        if (s[i] < '4') { ost = 0LL; continue; }
        if (s[i] == '4') { continue; }
        if (s[i] < '7') { ost = (1LL << i); continue; }
        if (s[i] == '7') { ost += (1LL << i); continue; }
        ost = 2LL << i;
    }
    cout << base + ost;
}