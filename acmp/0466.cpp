/*
    ����� ����: ����� ����� (zv.proger@yandex.ru)
    ������� ������ 0466 � ����� acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

int f(int x) {
    if (x < 2) return x;
    if (x & 1) return f(x/2) + f(x/2 + 1);
    return f(x/2);
}

int main() {
    int n; cin >> n;
    cout << f(n);
}

