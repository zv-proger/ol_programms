/*
    ����� ����: ����� ����� (zv.proger@yandex.ru)
    ������� ������ 0780 � ����� acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(), x.end()

const int inf = 1e9;

using ll = long long;
using pii = pair<int, int>;

int main() {
    int n; cin >> n;
    int t = 0;
    while (t*(t+1) / 2 != n) t++;
    cout << t;
}