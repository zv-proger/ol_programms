/*
    ����� ����: ����� ����� (zv.proger@yandex.ru)
    ������� ������ 0439 � ����� acmp.ru
*/
    
#include<bits/stdc++.h>
using namespace std;

int main() {
    double n, p; cin >> n >> p;
    p /= 100;
    cout << fixed << setprecision(7) << 1/(p + (1 - p) / n);
}