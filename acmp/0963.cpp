/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0963 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;



int main() {
    int n, k, p; cin >> n >> k >> p;
    string w, s;
    getline(cin, w);
    getline(cin, w);

    map<int, string> F;
    for (char c = 'A'; getline(cin, s); c++) {
        F[c] = s;
    }

    auto next = [&](const string &a) -> string {
        string b = "";
        for (auto &c: a) {
            b += F[c];
            if (b.length() > p) {
                b.resize(p);
                return b;
            }
        }
        return b;
    };

    string f = next(w); s = w;
    int pr = 0;
    while (f != s) { f = next(next(f)), s = next(s); pr ++; }
    int per = 1;
    while ((f = next(f)) != s) per ++;
    while (k && pr--) w = next(w), k--;
    k %= per;
    while (k--) w = next(w);
    cout << (p > w.size() ? '-': w[p-1]);
}