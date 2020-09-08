/*
    ����� ����: ����� ����� (zv.proger@yandex.ru)
    ������� ������ 0180 � ����� acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, k; cin >> n >> k;
    vector<int> digs;
    for (int i = 9; i > 1; i--) {
        while (k % i == 0) { k /= i; digs.push_back(i); }
    }
    sort(digs.begin(), digs.end());
	long long w = 0;
    for (auto c: digs) w = w * 10 + c;
    cout << ( k > 1 || w > n ? "NO": "YES");
}