/*
    ����� ����: ����� ����� (zv.proger@yandex.ru)
    ������� ������ 0949 � ����� acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, a, b; cin >> n >> b >> a;
    while (--n) {
        swap(a = a - b, b);
    }
    cout << b << ' ' << a;
}