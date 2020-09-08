/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0627 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

map<char, int> cnt;

void init(string s) { for (auto c: s) cnt[c]++; }
bool check(string s){ auto x = cnt; for (auto c: s) { if (--x[c] < 0) return false; } return true; }

int gg(int a, int b, int c) {
    if (!c) return (a > b) - (b > a);
    return gg(a + (c + 1) / 2, b + c / 2, 0);
}

int bg(int a, int b, int c) {
    return gg(max(0, a - c), b, max(0, c - a));
}

int gb(int a, int b, int c) {
    return gg(a, max(0, b - c), max(0, c - b));
}

int main() {
    string s; cin >> s; init(s);
    set<string> aa, bb, cc;
    int n;
    for (cin >> n; n--;) {
        cin >> s;
        if (check(s)) {
            aa.insert(s);
        }
    }
    for (cin >> n; n--;) {
        cin >> s;
        if (check(s)) {
            bb.insert(s);
        }
        if (aa.count(s))
            cc.insert(s);
    }
    int c = cc.size(), a = aa.size() - c, b = bb.size() - c;
    cout << (3 + gg(a, b, c)) % 3 << endl;
    cout << (3 + bg(a, b, c)) % 3 << endl;
    cout << (3 + gb(a, b, c)) % 3 << endl;
}