/*
    ����� ����: ����� ����� (zv.proger@yandex.ru)
    ������� ������ 0548 � ����� acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    string a, b, ans; cin >> a >> b;
    while (a.length() && b.length()) {
        auto &x = (a + b < b + a ? a : b);
        ans += x.front();
        x.erase(0, 1);
    }
    cout << ans + a + b;
}