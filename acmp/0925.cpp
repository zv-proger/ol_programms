/*
    ����� ����: ����� ����� (zv.proger@yandex.ru)
    ������� ������ 925 � ����� acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    int c, n, a, b, c; cin >> c >> n >> a >> b >> c;
    int x = max (a + b - n, 0);
    x = max (x + c - n, 0);
    cout << (c - 1 ? min(a, min(b, c)) : x);
}