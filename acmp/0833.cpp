/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0833 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    string a, b; cin >> b >> a;
    vector<pair<int, int>> ans;
    for (int i = 0; a[i]; i++) {
        if (a[i] == b[i]) continue;
        for (int j = i + 1; b[j]; j++) {
            if (a[i] == b[j]) {
                reverse(b.begin() + i, b.begin() + j + 1);
                ans.push_back({i+1, j+1});
                break;
            }
        }
    }
    cout << ans.size() << endl;
    for (auto &p: ans) {
        cout << p.first << ' ' << p.second << endl;
    }
}