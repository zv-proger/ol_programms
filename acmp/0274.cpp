/*
    ����� ����: ����� ����� (zv.proger@yandex.ru)
    ������� ������ 0274 � ����� acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

vector<bool> f(int a) {
    vector<bool> ans(10);
    while(a) { ans[a % 10] = true; a /= 10; }
    return ans;
}

void calc() {
    int a, b; cin >> a >> b;
    if (f(a) == f(b)) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main() {
    int n; cin >> n;
    while(n--) {
        calc();
    }
}