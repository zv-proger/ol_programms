/*
    ����� ����: ����� ����� (zv.proger@yandex.ru)
    ������� ������ 0508 � ����� acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ll cur = 0, n; cin >> n;
    for (; n--; ) {
        char c; int oa, ob, ia, ib; cin >> c >> oa >> ob >> ia >> ib;
        cur += ia - ob;
        cout << (c == 'L'? -1: cur) << ' ';
        cur += ib - oa;
    }
}