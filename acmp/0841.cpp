/*
    ����� ����: ����� ����� (zv.proger@yandex.ru)
    ������� ������ 0841 � ����� acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    long long n; cin >> n;
    if (!n) cout << 1;
    else cout << n*(n-1) + 2;
}