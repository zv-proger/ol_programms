/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0946 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

/*
    Первое из них (1 или 2) показывает, что диск ставится с левого края или с правого края
    соответственно. Второе целое число (от 0 до 10000) обозначает номер диска. Операции
    снятия диска с полки описывается одним числом 3 или 4, обозначающим с левого и правого
    края полки соответственно снимается диск.
*/

list<int> dt;

void request() {
    int i, x; cin >> i;
    switch (i) {
        case 1: cin >> x; dt.push_front(x); break;
        case 2: cin >> x; dt.push_back(x); break;
        case 3: cout << dt.front() << ' '; dt.pop_front(); break;
        case 4: cout << dt.back() << ' '; dt.back(); break;
    }
}

int main() {
    int n; cin >> n;
    for (; n--;) request();
}