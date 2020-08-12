/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0918 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

int main() {
    priority_queue<pii> dt; int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int t, s;
        cin >> t >> s; dt.push({s, t});
    }
    int ans = 0;
    set <int> usd;
    while(!dt.empty()) {
        int j = dt.top().second;
        for (; j > 0; j--) {
            if (!usd.count(j)) {
                usd.insert(j);
                ans += dt.top().first;
                break;
            }
        }
        dt.pop();
    }
    cout << ans;
}