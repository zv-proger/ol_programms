/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0821 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;
pii operator+ (pii a, pii b) {
    return {a.first + b.first, a.second + b.second};
}

struct pl {
    int n;
    pii pos;
    vector<vector<int>> dt;
    pl(int nn) {
        n = nn;
        dt.assign(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dt[i][j] = (i * n + j + 1) % (n * n);
            }
        }
        pos = {n - 1, n - 1};
    }

    bool can(pii x) {
        return x.first >= 0 && x.second >= 0 && x.first < n && x.second < n;
    }

    int &get(pii x) {
        return dt[x.first][x.second];
    }

    bool step(char c) {
        pii nxt = pos + map<char, pii>({{'U', {-1, 0}},{'D', {1, 0}},{'L', {0, -1}},{'R', {0, 1}}})[c];
        if (!can(nxt)) return false;
        swap(get(pos), get(nxt));
        pos = nxt;
        return true;
    }

    void print() const {
        for (auto &v: dt) {
            for (auto &x: v) {
                cout << x << ' ';
            }
            cout << endl;
        }
    }
};

int main() {
    int n; string s; cin >> n >> s;

    pl x(n);
    for (int i = 0; s[i]; i++) {
        if (!x.step(s[i])) {
            cout << "ERROR " << i + 1;
            return 0;
        }
    }

    x.print();
}