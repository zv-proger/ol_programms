/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0623 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(), x.end()

using pii = pair<int, int>;

struct mat_t {
    int a, b, c, d;
    mat_t(int aa, int bb, int cc, int dd) {
        a = aa, b = bb, c = cc, d = dd;
    }
    mat_t(): mat_t(0,0,0,0) {};
    pii mul(const pii &p) const {
        return {(a * p.first + c * p.second) % 10, (b * p.first + d * p.second) % 10};
    }
    mat_t mul (const mat_t &o) const {
        int _a = a * o.a + b * o.c;
        int _b = a * o.b + b * o.d;
        int _c = c * o.a + d * o.c;
        int _d = c * o.b + d * o.d;
        return mat_t(_a % 10, _b % 10, _c % 10, _d % 10);
    }
};

mat_t pw(const mat_t &m, int n) {
    if (n == 0) return {1, 0, 0, 1};
    if (n == 1) return m;
    mat_t ans = pw(m.mul(m), n / 2);
    if (n % 2) return ans.mul(m);
    return ans;
}

int main() {
    int n; cin >> n;
    
    cout << pw({0, 1, 1, 1}, n).mul({1, 1}).first;
}