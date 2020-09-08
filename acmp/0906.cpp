/*
    ����� ����: ����� ����� (zv.proger@yandex.ru)
    ������� ������ 0906 � ����� acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

using ll = long long;

map<int, ll> csh;

int hsh(int a, int b, int c) {
    return a + b * 31 + c * 961;
}

/*
    ���� a ? 0 ��� b ? 0 ��� c ? 0, �� F(a, b, c) = 1
    ���� a > 20 ��� b > 20 ��� c > 20, �� F(a, b, c) = F(20, 20, 20)
    ���� a < b � b < c, �� F(a, b, c) = F(a, b, c-1) + F(a, b-1, c-1) - F(a, b-1, c)
    ����� F(a, b, c) = F(a-1, b, c) + F(a-1, b-1, c) + F(a-1, b, c-1) - F(a-1, b-1, c-1)
*/

ll f(int a, int b, int c) {
    if (a <= 0 || b <= 0 || c <= 0) return 1;
    if (a > 20 || b > 20 || c > 20) return f(20, 20, 20);
    if (csh.count(hsh(a, b, c))) return csh[hsh(a, b, c)];
    if (a < b && b < c) return csh[hsh(a, b, c)] = f(a, b, c-1) + f(a, b-1, c-1) - f(a, b-1, c);
    return csh[hsh(a, b, c)] = f(a-1, b, c) + f(a-1, b-1, c) + f(a-1, b, c-1) - f(a-1, b-1, c-1);
}

int main() {
    int a, b, c; cin >> a >> b >> c;
    cout << f(a, b, c);
}