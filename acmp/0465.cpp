/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0465 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;
using ll = unsigned long long;

struct lll {
    vector<ll> dt;
    static const ll MOD = 1e9;
    lll(ll x) {
        dt.push_back(x);
        norm();
    }
    void norm() {
        ll o = 0;
        for (auto &x: dt) {
            x += o;
            o = x / MOD;
            x %= MOD;
        }
        if (o) dt.push_back(o);
    }
    lll &operator += (const lll &o) {
        if (dt.size() < o.dt.size()) dt.resize(o.dt.size());
        for (int i = 0; i < o.dt.size(); i++) {
            dt[i] += o.dt[i];
        }
        norm();
        return *this;
    }
    friend ostream &operator << (ostream &out, const lll &v) {
        cout << v.dt.back();
        for (int i = v.dt.size() - 1; i--;) {
            for (ll x = MOD / 10; x > v.dt[i] && x > 1; x /= 10) out << 0;
            out << v.dt[i];
        }
        return out;
    }
};

int main() {
    int n; cin >> n;
    lll z = 1, o = 1;
    for (; --n;) {
        lll zz = 0, oo = 0;
        zz += z; zz += o;
        oo += z;
        z = zz; o = oo;
    }
    z += o;
    cout << z;
}