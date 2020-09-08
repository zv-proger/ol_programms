/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0546 с сайта acmp.ru
*/
    
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    list<int> q;
    for (int i = 1; i <= (n + 3) / 4 * 4; i++) {
        q.push_back(i > n ? 0 : i);
    }
    for (int i = 1; !q.empty(); i++) {
        cout << i << ' ' << 1 << ' ' << q.back() << ' ' << q.front() << endl;
        q.pop_back(); q.pop_front();
        cout << i << ' ' << 2 << ' ' << q.front() << ' ' << q.back() << endl;
        q.pop_back(); q.pop_front();
    }
}