/*
    ����� ����: ����� ����� (zv.proger@yandex.ru)
    ������� ������ 789 � ����� acmp.ru
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
    int n; read(n);
    set<ll> st = {1};
    ll cur;
    for (;n--;) {
        cur = *st.begin();
        st.erase(st.begin());
        st.insert(cur * 2);
        st.insert(cur * 3);
        st.insert(cur * 5);
    }
    doans(cur);
}