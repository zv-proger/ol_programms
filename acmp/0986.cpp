/*
    ����� ����: ����� ����� (zv.proger@yandex.ru)
    ������� ������ 0986 � ����� acmp.ru
*/
    
#include<bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

#define sq(x) ((x)*(x))
#define x first
#define y second

int main() {
    int n, x, y, l; cin >> n >> x >> y >> l;
    for (int i = 1; i <= n; i++) {
        int x1, y1; cin >> x1 >> y1;
        if (sq(x - x1) + sq(y - y1) <= sq(l)) {
            cout << i; return 0;
        }
    }
    cout << "Yes";
}