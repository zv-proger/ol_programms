/*
    ����� ����: ����� ����� (zv.proger@yandex.ru)
    ������� ������ 0930 � ����� acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    string a, b; cin >> a >> b;
    string ans;
    int la = 0, lb = 0;
    for (char c = 'z'; c >= 'a'; c--) {
        int lla = la, llb = lb;
        for (; a[lla]; lla++) {
            if (a[lla] == c) break;
        }
        for (; b[llb]; llb++) {
            if (b[llb] == c) break;
        }
        if (a[lla] && b[llb]) {
            ans += c;
            la = lla + 1;
            lb = llb + 1;
            c++;
        }
    }
    cout << ans;
}