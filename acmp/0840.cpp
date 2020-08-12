/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0840 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

#define sqr(x) ((x) * (x))

struct share {
    double x, y, z, r;
    void read() {
        cin >> x >> y >> z >> r;
    }
    bool intersept(const share &oth) {
        return sqr(x - oth.x) + sqr(y - oth.y) + sqr(z - oth.z) + 1e-12 < sqr(r + oth.r);
    }
};

int main() {
    vector<share> dt(1);
    dt[0].read();
    set<int> along = {0};
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        share x; x.read(); dt.push_back(x);
        along.insert(i);
        for (int j = 0; j < i; j++) {
            if (dt[j].intersept(x)) {
                along.erase(i);
                along.erase(j);
            }
        }

        if (along.empty()) {
            cout << i;
            return 0;
        }
    }
    cout << 0;
}