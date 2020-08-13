/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0922 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    int t1, t2, s1, s2, s; cin >> t1 >> t2 >> s1 >> s2 >> s;
    if (s2 >= s1 && s1 < s) { cout << "NO"; return 0; }
    double tm = 0; int cur = 0;
    while ( cur + s1 < s ) {
        tm += t1 + t2;
        cur += s1 - s2;
    }
    tm += 1.0 * t1 * (s - cur) / s1;
    cout << fixed << setprecision(2) << tm;
}