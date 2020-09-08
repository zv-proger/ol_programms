/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0987 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    string ip, s; cin >> s >> ip;
    int mn = 999999, mx = 0, sm = 0, cnt = 0;
    for (int i = 0; i < 4; i++) {
        cin >> s;
        if (s == "Time") { cin >> s; continue; }
        cin >> s >> s >> s;
        int v;
        istringstream(s.substr(5)) >> v;
        sm += v; mx = max(mx, v); mn = min(mn, v);
        cnt++;
    }
    cout << "Ping statistics for " << ip << ":" << endl;
    cout << "Packets: Sent = 4 Received = " << cnt << " Lost = " << 4 - cnt << " (" << 25 * (4 - cnt) << "% loss)" << endl;
    if (cnt == 0) return 0;
    cout << "Approximate round trip times:" << endl;
    cout << "Minimum = " << mn << " Maximum = " << mx << " Average = " << (sm + cnt / 2) / cnt;
}