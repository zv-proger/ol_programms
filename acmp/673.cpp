/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 673 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(), x.end()

vector<int> dg(10);
string a = "9999999999999999999999999999999999999";
long long s, p = 1, ans, n;

void upgrade() {
    long long x = 1;
    vector<int> m, d;
    for (int i = 2; i <= n; i++) {
        m.push_back(i);
    }
    for (int i = 1; i < 10; i++) {
        for (int j = 2; j <= dg[i]; j++)
            d.push_back(j);
    }
    sort(ALL(m), greater<int>());
    sort(ALL(d), greater<int>());
    while (!m.empty()) {
        x *= m.back(); m.pop_back();
        while (!d.empty() && x % d.back() == 0) {
            x /= d.back(); d.pop_back();
        }
    }
    assert(d.empty());
    string s;
    for (int i = 1; i < 10; i++) {
        for (int j = 0; j < dg[i]; j++)
            s.push_back('0' + i);
    }
    a = min(a, s);
    ans += x;
}

int mn = 100;

void step(int i, int j) {
    if (p > 200) return;
    if (i == 0) {
        if (s == p) upgrade();
        return;
    }
    for (; j; j--) {
        dg[j] ++;
        s += j; p *= j;
        step(i - 1, j);
        s -= j; p /= j;
        dg[j] --;
    }
}

int main() {
    cin >> n;
    if (n == 1) { cout << "10 0"; return 0; }
    step(n, 9);
    cout << ans << ' ' << a;
}