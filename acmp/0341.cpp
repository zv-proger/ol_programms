/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0341 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

string calc(int n) {
    vector<string> prcalc = { "0", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
    if (n < prcalc.size()) return prcalc[n];
    char f = '1', s = '0';
    int c = 1;
    for (int i = prcalc.size(); i < n; i++) {
        char x = s;
        if (s > '0') s = '0'; else
        if (f == '1') s = '2'; else
        s = '1';
        f++; if (f > '9') f = x == '1'? '2': '1', c++;
    }
    string ans;
    ans.push_back(f);
    while (c--) ans.push_back(s);
    return ans;
}

int main() {
    int n; cin >> n;
    cout << calc(n);
}