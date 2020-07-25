/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 638 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(), x.end()

const int inf = 1e9;

using ll = long long;
using pii = pair<int, int>;

void print(const double &a) { cout << fixed << setprecision(6) << a << ' '; }
template <class A> void print(const A &a) { cout << a << ' '; }
template <class A, class... O> void print(const A &a, const O &...o) { print(a); print(o...); }
template <class... O> void println(O &...o) { print(o...); cout << endl; }
template <class... O> void doans(const O &...o) { println(o...); exit(0); }
template <class A> void read(A &a) { cin >> a; }
template <class A, class... O> void read(A &a, O &...o) { read(a); read(o...); }

int main() {
    int n, k; read(n, k);
    vector<bool> slv(n, false);
    int w, dw, s; read(w, dw, s); s--;
    for (;dw--;) {
        int z; read(z); z--;
        z = (z - s + w) % w;
        slv[z] = true;
    }
    for (int i = w; i < n; i++) {
        slv[i] = slv[i - w];
    }
    int zc; read(zc);
    for (; zc--;) {
        int z; read(z); z--;
        slv[z] = true;
    }
    int st = 0, l = 0, r = 0;
    for (;r < k; r++) st += slv[r];
    int ans = st == 0;
    for (; r < n; r++, l++) {
        st -= slv[l];
        st += slv[r];
        ans += st == 0;
    }
    doans(ans);
}