/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0699 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(), x.end()

const int inf = 1e9;

using ll = long long;
using pii = pair<int, int>;

#define x first
#define y second

pii readPii() {
    pii a; cin >> a.x >> a.y; return a;
}

double dist(pii a, pii b) {
    #define sq(x) ((x)*(x))
    return sqrt(sq(a.x - b.x) + sq(a.y - b.y));
}

int main() {
    int n, t; cin >> n >> t;
    vector<pair<pii, int>> dt;
    double bst = 1e9;
    for (; n--; ) {
        pii pos = readPii();
        int r; cin >> r;
        for (auto &p: dt) {
            bst = min(bst, max(0.0, dist(p.first, pos) - r - p.second));
        }
        dt.push_back({pos, r});
    }
    cout << fixed << setprecision(5) << min(t + 0.0, bst / 2);
}