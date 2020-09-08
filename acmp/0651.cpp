/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0651 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    return b? gcd(b, a % b): a;
}

int main() {
    int n, m; cin >> n >> m;
    int c = gcd(n, m);
    n /= c; m /= c;
    int ans = 0;
    for (int i = 2; i * i <= m; i++) {
        if (m % i == 0) {
            ans ++;
            m /= i;
            i--;
        }
    }
    ans += m != 1;
    m = n;
    for (int i = 2; i * i <= m; i++) {
        if (m % i == 0) {
            ans ++;
            m /= i;
            i--;
        }
    }
    ans += m != 1;
    cout << ans;
}