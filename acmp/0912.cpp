/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0912 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    pair<int, int> dt[101] = {{0, 0}};
    int n, x; cin >> n;
    for (int i = 0; i <= 100; i++) {
        dt[i].second = i;
    }
    for (int i = 0; i < n; i++) {
        cin >> x; dt[x].first++;
    }
    sort(dt, dt + 101, greater<pair<int, int> >());
    cout << (dt[0].first == dt[1].first ? 0 : dt[0].second);
}