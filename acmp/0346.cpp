/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0346 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(), x.end()

bool check (int a, int b) {
    if (b < 0) return false;
    int digs[10] = {0};
    for (;a; a /= 10) digs[a % 10] ++;
    for (;b; b /= 10) digs[b % 10] --;
    if (digs[0] < 0) return false;
    for (int i = 1; i < 10; i++) if (digs[i]) return false;
    return true;
}

int main() {
    int a, b, c; cin >> a >> b >> c;

    vector<int> dt;
    for (; a; a /= 10) dt.push_back(a % 10);
    sort(ALL(dt));
    do {
        a = 0;
        for (auto x: dt) { a = a * 10 + x; }
        if (check (b, c - a)) {
            cout << "YES" << endl << a << ' ' << c - a;
            return 0;
        }
    } while (next_permutation(ALL(dt)));

    cout << "NO";
}