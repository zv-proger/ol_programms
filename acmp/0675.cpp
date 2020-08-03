/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0675 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(), x.end()

const int inf = 1e9;

using ll = long long;
using pii = pair<int, int>;

int main() {
    int ans = inf, t, f; cin >> f >> f;
    for (char c; cin >> c; c++) {
        switch(c){
            case '.': t++; break;
            case 'A': t = 0; f = true; break;
            case 'B':
              if (f) {
                  f = false;
                  ans = min(ans, t);
              }
              t = 0;
        }
    }
    cout << ans;
}