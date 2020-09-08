/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0421 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

#define vec pair<int, int>
#define x first
#define y second
vec operator -(const vec &a, const vec &b) { return {a.x - b.x, a.y - b.y}; }
int coso(const vec &a, const vec &b) { return a.x * b.y - a.y * b.x; }
#define sq(x) ((x)*(x))
int sqdist(const vec &a, const vec &b) { return sq((a-b).x) + sq((a-b).y); }

#define tr pair<pair<vec, vec>, vec>
#define tr_ pair<pair<int, int>, int>
#define f first.first
#define s first.second
#define t second

vec readVec() {
    vec ans; cin >> ans.x >> ans.y;
    return ans;
}

tr_ readTr() {
    tr ans;
    ans.f = readVec();
    ans.s = readVec();
    ans.t = readVec();
    if (coso(ans.f - ans.s, ans.f - ans.t) < 0) swap(ans.f, ans.s);
    tr_ x = {{sqdist(ans.f, ans.s), sqdist(ans.s, ans.t)}, sqdist(ans.t, ans.f)};
    if (x.s < x.f || x.t <= x.f) { swap(x.f, x.s); swap(x.s, x.t); }
    if (x.s < x.f) { swap(x.f, x.s); swap(x.t, x.s); }
    return x;
}

int main() {
    int n; cin >> n;
    auto templ = readTr();
    for (; --n;) {
        if (templ != readTr()) {
            cout << "NO"; return 0;
        }
    }
    cout << "YES";
}