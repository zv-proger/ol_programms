/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0538 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

int pr_ar[2500];
void init_snm() { for (int i = 0; i < 2500; i++) pr_ar[i] = i; }
int par(int a) { return pr_ar[a] == a? a: pr_ar[a] = par(pr_ar[pr_ar[a]]); }
void uni(int a, int b) { a = par(a); b = par(b); rand() % 2 ? pr_ar[a] = b: pr_ar[b] = a; }
bool joint(int a, int b) { return par(a) == par(b); }

using pii = pair<short, short>;
#define x first
#define y second
pii operator - (const pii &a, const pii &b) { return {a.x - b.x, a.y - b.y}; }
int dist(const pii &a, const pii &b) { pii d = a - b; return d.x * d.x + d.y * d.y; }

pii dt[1200], edgs[1200*1200 / 2];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    init_snm();
    int n, k = 0; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> dt[i].x >> dt[i].y;
        for (int j = 0; j < i; j++) {
            edgs[k++] = {i, j};
        }
    }
    sort(edgs, edgs + k, [&dt] (const pii &a, const pii & b) {
        return dist(dt[a.first], dt[a.second]) < dist(dt[b.first], dt[b.second]);
    });
    bool f = true;
    double ans;
    for (int i = 0; i < k; i++) {
        int a = edgs[i].first, b = edgs[i].second;
        if (joint(a * 2, b * 2) || joint(a * 2 + 1, b * 2 + 1)) {
            if (f) ans = sqrt(dist(dt[a], dt[b])) / 2;
            f = false;
            continue;
        }
        uni(a * 2, b * 2 + 1);
        uni(b * 2, a * 2 + 1);
    }
    cout << fixed << setprecision(9) << ans << endl << 1;
    for (int i = 1; i < n; i++) {
        cout << ' ' << 1 + (joint(0, i * 2 + 1) || joint(1, i * 2));
    }
}