/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0689 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

int f(int n, int k) {
    int ans = 0, dig[99] = {0};
    while(n) {
        ans += !dig[n % k]++;
        ans ++;
        n /= k;
    }
    return ans;
}

char dig(int c) {
    if (c < 10) return '0' + c;
    return 'A' + c - 10;
}

string g(int n, int k) {
    string ans;
    while (n) {
        ans.push_back(dig(n % k));
        n /= k;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        int best = 2;
        for (int i = 2; i <= 36; i++) {
            if (f(a, best) > f(a, i)) best = i;
        }
        cout << best << ' ' << g(a, best) << endl;
    }
}