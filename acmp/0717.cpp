/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0717 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

using ll = long long;

template <class A> istream &operator >> (istream &a, vector<A> &b) { int n; a >> n; b.resize(n); for(auto &x : b) a >> x; return a;}
template <class A> ostream &operator << (ostream &a, const vector<A> &b) { for(auto &x : b) a << x << ' '; return a;}
template <class A> void read(A &a) { cin >> a; }
template <class A> void print(A a) { cout << a << ' '; }
template <class A, class... O> void print(A a, O... o) { print(a); print(o...); }
template <class A> void doans(A a) { print(a); exit(0); }
template <class A, class... O> void doans(A a, O... o) { print(a); doans(o...); exit(0); }

vector<vector<int>> gr;
vector<int> xxx, tsrt;
vector<bool> usd;

void dfs(int v) {
    if (usd[v]) return;
    usd[v] = true;
    for (auto &n : gr[v]) {
        dfs(n - 1);
    }
    tsrt.push_back(v + 1);
}

int main() {
    read(xxx);
    gr.resize(xxx.size());
    usd.resize(xxx.size());
    for (auto &r : gr)
        read(r);
    dfs(0);

    ll ans = 0;
    for (auto &x : tsrt) {
        ans += xxx[x - 1];
    }
    doans(ans, tsrt.size(), "\n", tsrt);
}