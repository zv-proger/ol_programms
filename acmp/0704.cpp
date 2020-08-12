/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0704 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

#define vec pair<int, int>
#define x first
#define y second

istream &operator >>(istream &in, vec &a) { return in >> a.x >> a.y; }
vec operator -(const vec &a, const vec &b) { return {a.x - b.x, a.y - b.y}; }

struct line{
    int a, b, c;
    line(const vec &v1, const vec &v2){
        auto vd = v1 - v2;
        a = -vd.y; b = vd.x;
        c = -a * v1.x - b * v1.y;
    }
    int sign(const vec &v) {
        int d = a * v.x + b * v.y + c;
        return d ? d > 0 ? 1 : -1 : 0;
    }
};

void do_no() { cout << "NO"; exit(0); }
void do_yes() { cout << "YES"; exit(0); }

int main() {
    vec dt[100]; int n, m; cin >> n >> m;
    if (!m) do_yes(); int coef = 10, N = coef * n;
    auto cen = vec(coef / 2 * n, coef / 2 * n);
    for (int i = 0; i < m; i++) {
        cin >> dt[i]; dt[i].x *= coef; dt[i].y *= coef;
        if (dt[i] == cen) do_no();
    }
    for (int i = 0; i <= N; i++) {
        auto l = line(cen, {0, i});
        int f = 0;
        for (int j = 0; j < m; j++) {
            f += l.sign(dt[j]);
        }
        if (f == m) do_yes();
    }
    for (int i = 1; i <= N; i++) {
        auto l = line(cen, {i, N});
        int f = 0;
        for (int j = 0; j < m; j++) {
            f += l.sign(dt[j]);
        }
        if (f == m) do_yes();
    }
    for (int i = N; i--; ) {
        auto l = line(cen, {N, i});
        int f = 0;
        for (int j = 0; j < m; j++) {
            f += l.sign(dt[j]);
        }
        if (f == m) do_yes();
    }
    for (int i = N; i--; ) {
        auto l = line(cen, {i, 0});
        int f = 0;
        for (int j = 0; j < m; j++) {
            f += l.sign(dt[j]);
        }
        if (f == m) do_yes();
    }

    do_no();
}