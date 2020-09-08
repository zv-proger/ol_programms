/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0835 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

ll best; vector<int> best_nums;
ll cur_sum, cur_weight; vector<int> cur_nums;
ll W, n;
vector<pii> dt;

#define w first
#define p second

void step(int i) {
    if (cur_weight > W) return;
    if (cur_sum > best || cur_sum == best && cur_nums.size() < best_nums.size()) {
        best = cur_sum; best_nums = cur_nums;
    }
    if (i == n) return;
    cur_sum += dt[i].p;
    cur_weight += dt[i].w;
    cur_nums.push_back(i);
    step(i + 1);
    cur_nums.pop_back();
    cur_weight -= dt[i].w;
    cur_sum -= dt[i].p;
    step(i + 1);
}

int main() {
    cin >> n >> W;
    dt.resize(n);
    for (auto &x: dt) {
        cin >> x.w >> x.p;
    }
    step(0);
    cout << best_nums.size() << ' ' << best << endl;
    for (auto &x: best_nums) {
        cout << x + 1 << ' ';
    }
}