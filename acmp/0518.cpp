/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0518 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(), x.end()
#define f first
#define s second

const int inf = 1e9;

using ll = long long;
using pii = pair<int, int>;
using pff = pair<double, double>;
using pll = pair<ll, ll>;

void print(const double &a) { cout << fixed << setprecision(6) << a << ' '; }
template <class A> void print(const A &a) { cout << a << ' '; }
template <class A, class... O> void print(const A &a, const O &...o) { print(a); print(o...); }
template <class... O> void println(O &...o) { print(o...); cout << endl; }
template <class... O> void doans(const O &...o) { println(o...); exit(0); }
template <class A> void read(A &a) { cin >> a; }
template <class A, class... O> void read(A &a, O &...o) { read(a); read(o...); }
template <class A, class B> pair<A, B> operator + (const pair<A, B>& a, const pair<A, B> &b) {return pair<A, B>(a.f + b.f, a.s + b.s);}
template <class A, class B> pair<A, B> operator - (const pair<A, B>& a, const pair<A, B> &b) {return pair<A, B>(a.f - b.f, a.s - b.s);}
template <class A, class B> istream &operator >> (istream &a, pair<A, B> &b) {return a >> b.f >> b.s;}
template <class A, class B> ostream &operator << (ostream &a, const pair<A, B> &b) {return a << b.f << ' ' << b.s;}

const vector<pii> nght = {{0, 1},{0, -1},{1, 0},{-1, 0}};

template <class A> A &get(vector<vector<A>> &a, const pii &p) {
    static A bad;
    if (p.f < 0 || p.s < 0 || p.f >= a.size() || p.s >= a[p.f].size())
        return bad;
    return a[p.f][p.s];
}

int main() {
    int n, k; read(n, k);
    vector<vector<bool>> mp(n, vector<bool>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char c; read(c);
            mp[i][j] = c == '1';
        }
    }
    vector<vector<int>> dp1(n, vector<int>(n)), dp2 = dp1, *cur = &dp1, *prev = &dp2;
    (*cur)[0][0] = 1;

    for (; k--;) {
        swap(cur, prev);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (mp[i][j]) continue;
                get(*cur, {i, j}) = 0;
                for (auto &d : nght) {
                    get(*cur, {i, j}) += get(*prev, (pii){i, j} + d);
                }
            }
        }
    }

    doans((*cur)[n-1][n-1]);
}