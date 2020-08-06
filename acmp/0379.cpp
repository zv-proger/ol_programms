/*
    јвтор кода: ¬адим «инов (zv.proger@yandex.ru)
    –ешение задачи 0379 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> mxday = { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 0, 0}; // максимум дней в iый мес€ц



int main() {
    bool dp[15][34];
    for (int i = 0; i < 15; i++) for (int j = 0; j < 34; j++) dp[i][j] = 1;
    for (int m = 12; m; m--) {
        for (int d = 31 - (m == 12); d; d--) {
            dp[m][d] = 0;
            if (mxday[m] >= d + 1 && !dp[m][d + 1]) dp[m][d] = 1;
            if (mxday[m] >= d + 2 && !dp[m][d + 2]) dp[m][d] = 1;
            if (mxday[m + 1] >= d && !dp[m + 1][d]) dp[m][d] = 1;
            if (mxday[m + 2] >= d && !dp[m + 2][d]) dp[m][d] = 1;
        }
    }
    int d, m; cin >> d >> m;
    cout << 2 - dp[m][d];
}