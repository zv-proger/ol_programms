/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0629 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, k, m; cin >> n >> k >> m;
    int sub[26][27] = {0};
    for (int i = 1; i <= k; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 1) sub[j][i] = 1;
            else for (int l = j + 1; l < n; l++) {
                sub[j][i] += sub[l][i - 1];
            }
        }
    }
    int l = 0;
    for (; k; k--) {
        while(sub[l][k] < m) m -= sub[l++][k];
        cout << char('a' + l);
        l++;
    }
}