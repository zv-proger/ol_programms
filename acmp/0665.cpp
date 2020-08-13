/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0665 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

int readTime() {
    int h, m; char c; cin >> h >> c >> m;
    return h * 60 + m;
}

string makeTime(int t) {
    stringstream ss;
    if (t < 600) ss << 0;
    ss << t / 60 << ":";
    t %= 60;
    if (t < 10) ss << 0;
    ss << t;
    return ss.str();
}

bool ispal(const string &a) {
    int l = 0, r = a.length() - 1;
    while (l < r) {
        if (a[l] != a[r]) return 0;
        l++, r--;
    }
    return 1;
}

int main() {
    int t = readTime();
    do {t = (t + 1) % 1440;} while(!ispal(makeTime(t)));
    cout << makeTime(t);
}