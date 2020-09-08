/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0596 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

struct circle_t {
    int x, y, r;
    void read() { cin >> x >> y >> r; }
    bool near(int xx, int yy) {
        #define sq(x) ((x)*(x))
        return (sq(xx - x) + sq(yy - y) <= r * r);
    }
};

circle_t readCircle() {
    circle_t x; x.read();
    return x;
}

map<int, string> ord;
map<string, vector<circle_t>> dt;

int main() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        if (!dt.count(s)) {
            ord[i] = s;
        }
        dt[s].push_back(readCircle());
    }
    cout << ord.size() << endl;
    int x, y; cin >> x >> y;
    for (auto &p: ord) {
        int ans = 0;
        for (auto &c: dt[p.second])
            ans += c.near(x, y);
        cout << p.second << ' ' << ans << endl;
    }
}