/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0669 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

long long calc_min(int x) {
    vector<int> dt;
    for (int i = 9; i > 1; i--){
        if (x % i == 0) {
            x /= i;
            dt.push_back(i++);
        }
    }
    if (x > 1) return -1;
    long long ans = 0;
    while (!dt.empty()) {
        ans = ans * 10 + dt.back();
        dt.pop_back();
    }
    return ans;
}


long long calc_max(int x) {
    vector<int> dt;
    for (int i = 2; i < 10; i++){
        if (x % i == 0) {
            x /= i;
            dt.push_back(i--);
        }
    }
    if (x > 1) return -1;
    long long ans = 0;
    while (!dt.empty()) {
        ans = ans * 10 + dt.back();
        dt.pop_back();
    }
    return ans;
}

int main() {
    int n; cin >> n;
    cout << calc_min(n) << ' ' << calc_max(n);
}