/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0578 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    char buf[200];
    int n; cin >> n;
    string ans = itoa(n, buf, 3);
    for (int i = ans.length(); --i; ) {
        if (ans[i] < '1') { ans[i] += 3; ans[i-1]--; }
    }
    if (ans.front() < '1') {
        ans.erase(0, 1);
    }
    cout << ans;
}