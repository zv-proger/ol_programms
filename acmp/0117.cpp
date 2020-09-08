/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0117 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(), x.end()

using vec = pair<long long, long long>;
#define x first
#define y second
vec operator -(vec a, vec b) {return {a.x - b.x, a.y - b.y};}

double len(vec x) {
    return sqrt(x.x * x.x + x.y * x.y);
}

int main() {
    int n; cin >> n;
    vector<vec> dt(n);
    int lpos = 0;
    for (int i = 0; i < n; i++) {
        auto &x = dt[i];
        cin >> x.x >> x.y;
        if (x < dt[lpos]) lpos = i;
    }
    swap(dt[0], dt[lpos]);
    vec l = dt.front();
    sort(++ALL(dt), [l](vec a, vec b) -> bool {
        if ((a.y - l.y) * (b.x - l.x) == (a.x - l.x) * (b.y - l.y)) return a < b;
        return (a.y - l.y) * (b.x - l.x) > (a.x - l.x) * (b.y - l.y);
    });
    vector <vec> ob;
    for (int i = 0; i < n; i++) {
        if (ob.size() < 2) { ob.push_back(dt[i]); continue; }
        vec c = dt[i] - ob.back(), p = ob.back() - *++ob.rbegin();
        if (c.x * p.y <= c.y * p.x) { ob.pop_back(); i--; continue; }
        ob.push_back(dt[i]);
    }
    long long s = 0;
    ob.push_back(ob.front());
    for (int i = 1; i < ob.size(); i++) {
        s += (ob[i].x - ob[i-1].x) * (ob[i].y + ob[i-1].y);
    }
    cout << (s + 1) / 2;
}