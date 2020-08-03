/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0711 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;


int main() {
    int n, m; cin >> n >> m;
    string ans;
    int ansc = 1e9;
    for (;n--;) {
        int c = 0;
        string cs; cin >> cs;
        for(int i = 0; i < m; i++) {
            int x; cin >> x;
            c += x;
        }
        if (c < ansc) ansc = c, ans = cs;
    }
    cout << ans;
}
