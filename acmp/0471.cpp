/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0471 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

using ll = long long;

struct big_t {
    static const ll MOD = 1e9;
    vector<ll> dt;
    big_t(ll x = 0) { dt.push_back(x); norm(); }
    void norm() {
        ll o = 0;
        for (auto &x : dt) {
            x += o; o = x / MOD; x %= MOD;
        }
        if (o) dt.push_back(o);
    }
    big_t &operator += (const big_t &o) {
        if (o.dt.size() > dt.size()) dt.resize(o.dt.size());
        for (int i = 0; i < o.dt.size(); i++) {
            dt[i] += o.dt[i];
        }
        norm();
        return *this;
    }
    void print() {
        cout << (dt.back());
        for (int i = dt.size() - 2; i >= 0; i--) {
            ll q = MOD / 10;
            while(q > 1 && q > dt[i]) { cout << 0; q /= 10; }
            cout << dt[i];
        }
    }
};

vector<vector<int>> from = {
    {4, 6}, // 0
    {6, 8}, // 1
    {7, 9}, // 2
    {4, 8}, // 3
    {0, 3, 9}, // 4
    {}, // 5
    {0, 1, 7}, // 6
    {2, 6}, // 7
    {1, 3}, // 8
    {2, 4} // 9
};

int main() {
    big_t dt[2][10], *p = dt[0], *c = dt[1];
    c[9] = c[7] = c[6] = c[5] = c[4] = c[3] = c[2] = c[1] = 1;
    int n; cin >> n;

    for (; --n;) {
        swap(c, p);
        for (int i = 0; i < 10; i++) {
            c[i] = 0;
            for (auto f : from[i]) {
                c[i] += p[f];
            }
        }
    }

    big_t ans;
    for (int i = 0; i < 10; i++) { ans += c[i]; }
    ans.print();
}