/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0886 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    string a; cin >> a;
    int n = a.size(), ans = 1;
    a += a;
    vector<int> z(n * 2);
    int l, r = l = 0;
    for (int i = 1; i < n; i++) {
        if (i < r) {
            z[i] = min(z[i - l], r - i);
        }
        while (a[z[i]] == a[i + z[i]]) z[i]++;
        if (i + z[i] > r) {
            r = i + z[i]; l = i;
        }
        ans += z[i] > n;
    }
    cout << ans;
}