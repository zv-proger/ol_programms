/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0154 с сайта acmp.ru

    Выведите не более восьми натуральных чисел в порядке невозрастания, кубы которых в сумме дают N
*/

#include<bits/stdc++.h>
using namespace std;

int mx = 1; // Максимальное число куб которого не больше заданого
void init(int n) {
    for (int i = 1; 1LL * i*i*i <= n; i++) {
        mx = i;
    }
}

vector<int> ans;

void calc(int n) {
    if (n == 0) { for (auto x : ans) cout << x << ' '; exit(0); }
    if (ans.size() > 7) return;

     // Определяем максимальное число куб которого не больше n
    int l = 0, r = mx + 1;
    while(l < r -1) {
        int m = (l + r) / 2;
        if (m * m * m > n) {
            r = m;
        } else {
            l = m;
        }
    }

    for (int x = l; x > 0; x--) {
        int y = x*x*x;
        if (y > n) continue;
        ans.push_back(x);
        calc(n - y);
        ans.pop_back();
    }
}

int main() {
    ll n; cin >> n;
    init(n);
    calc(n);
    cout << "IMPOSSIBLE";
}