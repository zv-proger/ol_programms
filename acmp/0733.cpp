/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0733 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> dt(n);
    for (auto &x: dt) cin >> x;
    int mx = dt.front();
    vector<int> ans1, ans2;
    for (auto &x: dt) {
        if (x > mx) {
            ans1.push_back(mx);
            mx = x;
        }
    }
    for (auto &x: dt) {
        if (x == mx) {
            ans1.push_back(mx);
            mx = x;
        }
    }
    reverse(dt.begin(), dt.end());
    mx = dt.front();
    for (auto &x: dt) {
        if (x > mx) {
            ans2.push_back(mx);
            mx = x;
        }
    }
    reverse(ans2.begin(), ans2.end());
    ans1.insert(ans1.end(), ans2.begin(), ans2.end());
    cout << ans1.size() << endl;
    for (auto &x: ans1) {
        cout << x << ' ';
    }

}