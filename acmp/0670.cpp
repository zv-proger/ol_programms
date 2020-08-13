/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0670 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

bool f(int x) {
    bool t[10] = {0};
    while(x) {
        if (t[x%10]++) return false;
        x /= 10;
    }
    return true;
}

int main() {
    int n; cin >> n;
    int ans = 0;
    for (; n--;) {
        while(!f(++ans));
    }
    cout << ans;
}