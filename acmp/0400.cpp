/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0400 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

void do_no() {
    cout << "IMPOSSIBLE";
    exit(0);
}
void do_yes() {
    cout << "POSSIBLE";
    exit(0);
}

int main() {
    vector<pii> dt;
    for (int i = 0; i < 6; i++) {
        int a, b; cin >> a >> b;
        dt.push_back(minmax(a, b));
    }
    sort(dt.begin(), dt.end());
    if (dt[0] != dt[1]) do_no();
    if (dt[2] != dt[3]) do_no();
    if (dt[4] != dt[5]) do_no();
    #define f first
    #define s second
    auto &a = dt[0], &b = dt[2], &c = dt[4];
    if (a.f == b.f && a.s == c.f && b.s == c.s) do_yes();
    if (a.f == b.f && a.s == c.s && b.s == c.f) do_yes();
    if (a.f == c.f && a.s == b.f && b.s == c.s) do_yes();
    if (a.f == c.f && a.s == b.s && b.f == c.s) do_yes();
    if (a.f == b.s && a.s == c.f && b.f == c.s) do_yes();
    if (a.f == b.s && a.s == c.s && b.f == c.f) do_yes();
    if (a.f == c.s && a.s == b.f && b.s == c.f) do_yes();
    if (a.f == c.s && a.s == b.s && b.f == c.f) do_yes();
    do_no();
}