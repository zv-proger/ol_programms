/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0920 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> cn; // Взаимно неперекрывающиеся маски, описывающие совместимые группы животных
int ans = 20, n;

void calc(int msk, int i, int cur) {
    if (!msk) { ans = min(ans, cur); return; }
    if (cur >= min(ans, n)) return;
    for (; i < cn.size(); i++) {
        calc((msk | cn[i]) ^ cn[i], i + 1, cur + 1);
    }
}

void read() {
    // Читаем начальные данные
    cin >> n; int con[18] = {0};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int c; cin >> c;
            if (!c) con[i] |= 1 << j;
        }
    }
    // Инициируем множестова can
    bool sub[1 << 18] = {0};
    set<int> can;
    for (int i = 1; i < (1 << n); i++) {
        sub[i] = true;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                if ((i & con[j]) != i) {
                    sub[i] = false; break;
                }
            }
        }
        if (sub[i]) {
            for (int j = 0; j < n; j++) {
                if (!(i & (1 << j))) continue;
                if (sub[i ^ (1 << j)]) { can.erase(i ^ (1 << j)); sub[i ^ (1 << j)] = false; }
            }
            can.insert(i);
        }
    }
    for (auto i: can) {
        cn.push_back(i);
    }
}

int main() {
    read();
    calc((1 << n) - 1, 0, 0);
    cout << ans;
}