/*
    ����� ����: ����� ����� (zv.proger@yandex.ru)
    ������� ������ 0543 � ����� acmp.ru
*/
    
#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ll n, w, d, p; cin >> n >> w >> d >> p;
    cout << (((n-1) * n * w / 2 - p) / d - 1 + n) % n + 1;
}