/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0422 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(), x.end()

const int inf = 1e9;

using ll = long long;
using pii = pair<int, int>;

int gcd(int a, int b) {
    return b ? gcd(b, a % b): a;
}

struct comp{ bool operator()(pii a, pii b) { return 1.0 * a.first / a.second < 1.0 * b.first / b.second; } };

int main() {
    set<pii> dt;
    int n; cin >> n;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            dt.insert({j / gcd(i, j), i / gcd(i, j)});
        }
    }
    set<pii, comp> ans;
    for (auto &x: dt) ans.insert(x);
    for (auto &x: ans) {
        cout << x.first << '/' << x.second << endl;
    }
}