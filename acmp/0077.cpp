/*
    ����� ����: ����� ����� (zv.proger@yandex.ru)
    ������� ������ 0077 � ����� acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> pp(32, vector<int>(32));

// ����������� ��������� �� n �� m ��������� (��������������, � <= n <= 31)
int per(int n, int m) {
    int ans = 1, p = n - m;
    vector<int> a, b;
    for(;m; m--) a.push_back(m);
    for(;p; p--) b.push_back(p);
    for(int i = 1; i <= n; i++) {
        ans *= i;
        while(!a.empty() && ans % a.back()== 0) { ans /= a.back(); a.pop_back(); }
        while(!b.empty() && ans % b.back()== 0) { ans /= b.back(); b.pop_back(); }
    }
    return ans;
}

// ������������ ��������� ��� ���� ��������� n � m � ������
void init() {
    pp[0][0] = 1;
    for (int i = 0; i < 32; i++) {
        for (int j = 0; j <= i; j++) {
            pp[i][j] = per(i, j);
        }
    }
}

int main() {
    init();
    int n, k; cin >> n >> k;
    if (k > 31) { cout << 0; return 0; }

    int ans = 0, l;
    // �������� ��� ���������� �������� � ������� ���. ��������
    for (l = 0; (1 << l + 1) <= n; l++) {
        ans += pp[l][k];
    }

    // �������� ��������� ��������
    for (l--; l >= 0 && k > 0; l--) {
        if (n & (1 << l)) {
            ans += pp[l][k - 1];
        } else {
            k--;
        }
    }
    // ��� �������� � ������������ �� ��������� ��-�� ���� �������
    ans += !k && l < 0;

    cout << ans << endl;
}