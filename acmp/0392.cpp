/*
    ����� ����: ����� ����� (zv.proger@yandex.ru)
    ������� ������ 0392 � ����� acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

template <class A> istream &operator >> (istream &a, vector<A> &b) { int n; a >> n; b.resize(n); for(auto &x : b) a >> x; return a;}

int main() {
    vector<int> dt; cin >> dt;
    int s = 0;
    for (; dt[s] != 1; s++);
    for (int i = s; i < dt.size(); i++) cout << dt[i] << ' ';
    for (int i = 0; i < s; i++) cout << dt[i] << ' ';
}