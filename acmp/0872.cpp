/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0872 с сайта acmp.ru
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

inline bool is_prefix(const string &a, const string &b) {
    return b.find(a) == 0;
}

int main() {
    vector<string> dt; read(dt);
    vector<int> dp(dt.size(), 1);
    for (int i = 1; i < dt.size(); i++) {
        for (int j = i; j--; ) {
            if (is_prefix(dt[j], dt[i])) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    doans(dp.back());
}