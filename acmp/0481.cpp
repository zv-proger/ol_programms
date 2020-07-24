/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0481 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(), x.end()
#define f first
#define s second

const int inf = 1e9;

using ll = long long;
using pii = pair<int, int>;

template <class A> void print(A a) { cout << a << ' '; }
template <class A, class... O> void print(A a, O... o) { print(a); print(o...); }
template <class A> void read(A &a) { cin >> a; }
template <class A, class... O> void read(A &a, O &...o) { read(a); read(o...); }
template <class A> void doans(A a) { print(a); exit(0); }
template <class A, class... O> void doans(A a, O... o) { print(a); doans(o...); exit(0); }


int main() {
    string s; read(s);
    int len = s.length();

    map <pii, ll> dp;
    for (int i = 0; i < len; i++) {
        dp[{i,i}] = 1;
        if (i) {
            dp[{i - 1, i}] = 2 + (s[i - 1] == s[i]);
        }
    }
    for (int i = 2; i < len; i++) {
        for (int j = 0; i + j < len; j++) {
            dp[{j, i + j}] += dp[{j + 1, j + i}];
            dp[{j, i + j}] += dp[{j, j + i - 1}];
            dp[{j, i + j}] -= dp[{j + 1, j + i - 1}];
            if (s[j + i] == s[j]) {
                dp[{j, i + j}] += dp[{j + 1, j + i - 1}] + 1;
            }
        }
    }
    doans(dp[{0, len - 1}]);
}