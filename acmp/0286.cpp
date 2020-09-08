/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0286 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

using pss = pair<string, string>;

pss split(string a) {
    a += '.';
    pss x; x.first = a.substr(0, a.find("."));
    x.second = a.substr(a.find(".") + 1);
    if (x.second != "") x.second.pop_back();
    while (x.second.back() == '0') x.second.pop_back();
    x.second += '0';
    return x;
}

int cmp(string a, string b) {
    if (a.front() == '-' && b.front() == '-') return cmp(b.substr(1), a.substr(1));
    if (a.front() == '-') return -1;
    if (b.front() == '-') return 1;
    auto aa = split(a);
    auto bb = split(b);
    if (aa.first.length() < bb.first.length()) return -1;
    if (aa.first.length() > bb.first.length()) return 1;
    if (aa.first < bb.first) return -1;
    if (aa.first > bb.first) return 1;
    if (aa.second < bb.second) return -1;
    if (aa.second > bb.second) return 1;
    return 0;
}

int main() {
    string a, b; cin >> a >> b;
    int ans = cmp(a, b);
    cout << char(ans + '=');
}