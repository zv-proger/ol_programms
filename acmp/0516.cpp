/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0516 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

bool msimp(int i) {
    if (i == 1) return false;
    for (int j = 2; 1LL * j * j <= i; j++) {
        if (i % j == 0) return false;
    }
    return true;
}

bool check(int a) {
    vector<int> dgs;
    while (a) { dgs.push_back(a % 10); a /= 10; }
    sort(dgs.begin(), dgs.end());
    for (auto x: dgs) a = a * 10 + x;
    if (!msimp(a)) return false;
    a = 0; reverse(dgs.begin(), dgs.end());
    for (auto x: dgs) a = a * 10 + x;
    if (!msimp(a)) return false;
    return true;
}

int main() {
    int a; cin >> a;
    if (check(a)) cout << "Yes";
    else cout << "No";
}