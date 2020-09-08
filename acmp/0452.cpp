/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0452 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(), x.end()

int main() {
    string a, b; cin >> a >> b;
    reverse(ALL(a));
    reverse(ALL(b));
    for (auto &c: a) c -= '0';
    for (auto &c: b) c -= '0';
    while (a.size() < 300) a.push_back(0);
    while (b.size() < 300) b.push_back(0);
    for (int i = 0; i < 300; i++) {
        a[i]+=b[i];
    }
    bool f;
    ret: f = false;
    for (int i = 2; i < 299; i++) {
        while (a[i-1] && a[i-2]) { a[i]++; a[i-1]--; a[i-2]--; f = true; }
        if (a[i] > 1) { a[i]-=2; f = true; a[i+1]++; a[i-2]++; }
    }
    if (a[0] > 1) { a[0]-=2; f = true; a[1]++; }
    if (a[1] > 1) { a[1]-=2; f = true; a[2]++; a[0]++; }
    if (f) goto ret;
    while (a.back() == 0 && a.size() > 1) a.pop_back();
    reverse(ALL(a));
    for (auto c: a) cout << +c;
}