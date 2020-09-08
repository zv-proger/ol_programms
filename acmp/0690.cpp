/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0690 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
#define f first
#define s second
inline pii operator + (const pii &a, const pii &b) { return {a.f + b.f, a.s + b.s}; }

int ans[102][102], n, m;

inline bool check(const pii &p) {
    if (p.f >= n || p.f < 0 || p.s >= m || p.s < 0) return false;
    return ans[p.f][p.s] == 0;
}

inline int &get(const pii &p) {
    return ans[p.f][p.s];
}

vector<pii> ds = {
    {1, 2},  // 0
    {2, 1},  // 1
    {-1, 2}, // 2
    {2, -1}, // 3
    {-2, 1}, // 4
    {1, -2}, // 5
    {-1, -2},// 6
    {-2, -1},// 7
};

map<pii, int> cnt;

inline int count(const pii &a) {
    int ans = 0;
    for (auto &d: ds) {
        ans += check(a + d);
    }
    return ans;
}

int one = 0;

void step(const pii &cur, const int i) {
    get(cur) = i;
    for (auto &d: ds) {
        if (check(d + cur)) {
            if (--cnt[d + cur] < 2) one++;
        }
    }
    if (cnt[cur] < 2) one--;
    if (i == n * m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                printf("%6d", ans[i][j]);
            } puts("");
        }
        exit(0);
    }
    vector<pii> nxt;
    if (one > 2) goto ret;
    for (auto &d: ds) {
        if (check(d + cur)) {
            nxt.push_back(d + cur);
        }
    }
    sort(nxt.begin(), nxt.end(), [&](const pii &a, const pii &b) -> bool { return cnt[a] <= cnt[b];});
    for (auto &d: nxt) {
        step(d, i + 1);
    }


    for (auto &d: ds) {
        if (check(d + cur)) {
            step(d + cur, i+1);
        }
    }
    ret:
    for (auto &d: ds) {
        if (check(d + cur)) {
            if (cnt[d + cur]++ < 2) one--;
        }
    }
    get(cur) = 0;
    if (cnt[cur] < 2) one++;
    return;
}

int main() {
    cin >> n >> m;
    pii s;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c; cin >> c;
            if (c == 'K') {
                s = {i, j};
            }
            cnt[{i, j}] = count({i, j});
        }
    }
    if (s.second > m / 2 && s.first > n / 2) {
        swap(ds[0], ds[6]);
        swap(ds[1], ds[7]);
        swap(ds[2], ds[5]);
        swap(ds[3], ds[4]);
    }
    if (s.first > n / 2) {
        swap(ds[0], ds[2]);
        swap(ds[1], ds[4]);
        swap(ds[3], ds[7]);
        swap(ds[5], ds[6]);
    } else
    if (s.second > m / 2) {
        swap(ds[0], ds[4]);
        swap(ds[1], ds[5]);
        swap(ds[2], ds[6]);
        swap(ds[3], ds[7]);
    }
    step(s, 1);
}