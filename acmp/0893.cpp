/*
    ����� ����: ����� ����� (zv.proger@yandex.ru)
    ������� ������ 0893 � ����� acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(), x.end()

const int inf = 1e9;

using ll = long long;
using pii = pair<int, int>;

int main() {
    ll a; cin >> a;
    switch(a) {
        case 1 : cout << 1; break;
        case 2 : cout << 2; break;
        default : cout << a * (a - 1) * (a - 2);
    }

}