/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0236 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

string s;
long long x;

long long calc_val(int l, int r) {
    if (s[l] == 'x') {
        if (l + 1 == r) return x;
        switch(s[l+2]) {
            case '1': return x;
            case '2': return x * x;
            case '3': return x * x * x;
            case '4': return x * x * x * x;
        }
    }
    int ans; istringstream(s.substr(l, r - l)) >> ans;
    return ans;
}

long long calc_mul(int l, int r) {
    if (l >= r) return 0;
    long long ans = 1;
    for (int i = l; i < r; i++) {
        if (s[i] == '*') {
            ans *= calc_val(l, i);
            l = i + 1;
        }
    }
    return ans * calc_val(l, r);
}

long long calc_add(int l, int r) {
    long long ans = 0, sg = 1;
    for (int i = l; i < r; i++) {
        switch(s[i]) {
            case '+':
            case '-':
            ans += sg * calc_mul(l, i);
            sg = s[i] == '-'? -1: 1;
            l = i + 1;
        }
    }
    return ans + calc_mul(l, r) * sg;
}

int main() {
    cin >> s >> x;
    cout << calc_add(0, s.length());
}