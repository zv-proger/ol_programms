/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0735 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    string s, d; cin >> s >> d;
    int ls = s.length(), ld = d.length();
    string a = s + '#' + d;
    vector<int> p(a.length());
    for (int i = 1, j = 0; a[i]; i++) {
        while(j && a[i] != a[j]) j = p[j-1];
        if (a[i] == a[j]) {
            p[i] = ++j  ;
        }
    }
    int c = ld;
    for (; p[c + ls]; c--);

    a = d + '#' + s;
    p.assign(a.length(), 0);
    for (int i = 1, j = 0; a[i]; i++) {
        while(j && a[i] != a[j]) j = p[j-1];
        if (a[i] == a[j]) {
            p[i] = ++j  ;
        }
        if (p[i] == c) { cout << "YES"; return 0; }
    }
    cout << "NO";
}
