/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0847 с сайта acmp.ru
*/
    
#include<bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(), x.end()

bool check(string a, string b) {
    if (a.length() != b.length()) return false;
    for (int i = 0; a[i]; i++) {
        if (a[i] == b[i]) return false;
    }
    sort(ALL(a)); sort(ALL(b));
    return a == b;
}

int main() {
    string a, b; cin >> a >> b;
    cout << (check(a, b)? "YES": "NO");
}