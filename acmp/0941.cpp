/*
    ����� ����: ����� ����� (zv.proger@yandex.ru)
    ������� ������ 0941 � ����� acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    string x, y; cin >> x >> y;
    ll a = 0, b = 0;
    for (auto &c: x) a = a * 3 + c - '0';
    for (auto &c: y) b = b * 3 + c - '0';

    cout << a + b;
}