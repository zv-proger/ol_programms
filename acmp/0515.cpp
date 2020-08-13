/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0515 с сайта acmp.ru
*/
    
#include<bits/stdc++.h>
using namespace std;

#define vec pair<int, int>
#define x first
#define y second
#define sqr(x) ((x)*(x))
double dist(vec a, vec b) { return sqrt(sqr(a.x-b.x)+sqr(a.y-b.y)); }


int main() {
    int n; cin >> n;
    vec cur(0, 0); double ans = 0;
    for (; n--;) {
        int x, y; cin >> x >> y;
        ans += dist(cur, {x, y});
        cur = {x, y};
    }
    cout << fixed << setprecision(10) << ans + dist(cur, {0, 0});
}