/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0440 с сайта acmp.ru
*/
    
#include<bits/stdc++.h>
using namespace std;

#define vec pair<int, int>
#define x first
#define y second
#define sqr(x) ((x)*(x))

struct comp {
    bool operator() (const vec &a, const vec &b) const {
        if (sqr(a.first - b.first) + sqr(a.second - b.second) <= 100) return false;
        return a < b;
    }
};

int main() {
    set<vec, comp> dt = {{0, 0},{25, 0},{50, 0},{75, 0},{100, 0}};
    for (int i = 0; i < 5; i++) {
        int x, y; cin >> x >> y;
        dt.erase({x, y});
    }
    cout << 5 - dt.size();
}