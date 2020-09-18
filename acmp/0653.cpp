/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 653 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    vector<int> columns, rows;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x; cin >> x;
            if (!j) rows.push_back(x);
            if (!i) columns.push_back(x);
        }
    }
    cout << n + m << endl;
    for (int i = 0; i < n; i++) {
        int mn = i;
        for (int j = i + 1; j < n; j++) {
            if (rows[mn] > rows[j]) mn = j;
        }
        swap(rows[i], rows[mn]);
        cout << "R " << i + 1 << ' ' << mn + 1 << endl;
    }
    for (int i = 0; i < m; i++) {
        int mn = i;
        for (int j = i + 1; j < m; j++) {
            if (columns[mn] > columns[j]) mn = j;
        }
        swap(columns[i], columns[mn]);
        cout << "C " << i + 1 << ' ' << mn + 1 << endl;
    }
}