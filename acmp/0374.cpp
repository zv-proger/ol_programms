/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0374 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(), x.end()

const int inf = 1e9;

using ll = long long;
using vec = pair<int, int>;
#define x first
#define y second
vec readVec() { vec x; cin >> x.x >> x.y; return x; }
vec operator -(const vec &a, const vec &b) { return {a.x - b.x, a.y - b.y}; }

double dist(const vec &a) { return sqrt(a.x*a.x + a.y*a.y); }

int main() {
    vec dt[1000], ob[1000];
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        dt[i] = readVec();
        if (*dt > dt[i]) swap(*dt, dt[i]);
    }
    vec l = *dt;
    sort(dt + 1, dt + n, [&l](const vec &a, const vec &b) -> bool {
        vec da = a - l, db = b - l;
        int i = da.x * db.y - da.y * db.x;
        return i ? i < 0: a < b;
    });
    int m = 0;
    for (int i = 0; i < n; i++) {
        if ( m < 2 ) { ob[m++] = dt[i]; continue; }
        vec c = dt[i] - ob[m-1], p = ob[m-1] - ob[m-2];
        if ( c.x * p.y <= p.x * c.y ) {
            m--; i--; continue;
        }
        ob[m++] = dt[i];
    }
    ob[m++] = *ob;
    double ans;
    for (int i = 1; i < m; i++) {
        ans += dist(ob[i] - ob[i-1]);
    }
    cout << fixed << setprecision(1) << ans;
}