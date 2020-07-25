/*
    ����� ����: ����� ����� (zv.proger@yandex.ru)
    ������� ������ 0510 � ����� acmp.ru
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
    ll dp[34] = {1};
    dp[2] = 3;
    for (int i = 4; i < 34; i += 2) {
        dp[i] = 3 * dp[i-2];
        for (int j = i-4; j >= 0; j -= 2) {
            dp[i] += 2 * dp[j];
        }
    }
    int n; read(n);
    doans(dp[n]);
}