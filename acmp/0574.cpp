/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0574 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(), x.end()

int main() {
    string a, b; cin >> a >> b;
    sort(ALL(a)); sort(ALL(b));
    cout << (a == b ? "YES" : "NO");
}