/*
    ����� ����: ����� ����� (zv.proger@yandex.ru)
    ������� ������ 0792 � ����� acmp.ru
*/
    
#include<bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

int ncof(int n, int p) {
    int ans = 0;
    for (; n; n /= p) ans += n % p;
    return ans;
}

int main() {
    int a, b, c, d; cin >> a >> b >> c >> d;
    cout << (ncof(a, b) == ncof(c, d) ? ncof(c, d) : 0);
}