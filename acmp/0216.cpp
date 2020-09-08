/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0216 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    priority_queue<int> q;
    int k; cin >> k;
    for (; k--;) { int x; cin >> x; q.push(x); }
    int ans = 0;
    while(q.size() > 1) {
        int a = q.top(); q.pop();
        int b = q.top(); q.pop();
        ans ++; a--; b--;
        if (a) q.push(a);
        if (b) q.push(b);
    }
    cout << ans;
}