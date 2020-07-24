/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0991 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

const int MX_N = 100;
const int MX_M = 200;

struct cl_t;

int n, k;
vector<set<int>> frg_owners;
vector<cl_t> clients;

struct cl_t {
    bool frg[MX_M] = {0}; // описание фрагментов true == скачано
    int cnt[MX_N] = {0};  // ценность клиентов
    int frgn = 0;         // общее кол-во фрагментов
    int last;             // последний запрашиваемый фрагмент
    bool was_approved = 0;// было согласовано
    int addressee = -1;   // выбор адресанта
    int addresser = -1;   // выбор адресанта
    int self;             // индекс в общем списке

    void init() {
        addressee = -1;
        addresser = -1;
        last = -1;
        was_approved = false;
    }

    bool norm() {
        if (was_approved) {
            frg[last] = true;
            frgn ++;
            cnt[addresser]++;
            frg_owners[last].insert(self);
        }
        return frgn == k;
    }

    void choise_frg() {
        last = -1;
        if (frgn == k) return;
        for (int i = 0; i < k; i++) {
            if (frg[i]) continue;
            if (last < 0 || frg_owners[last].size() > frg_owners[i].size()) {
                last = i;
            }
        }
    }

    void choise_addresser() {
        if (last < 0) return;
        for (auto &c: frg_owners[last]) {
            if (addresser < 0 || clients[addresser].frgn > clients[c].frgn)
                addresser = c;
        }
    }

    void request(int who) {
        if (addressee < 0) { addressee = who; return; }
        if (cnt[addressee] < cnt[who]) { addressee = who; return; }
        if (cnt[addressee] > cnt[who]) { return; }
        if (clients[addressee].frgn > clients[who].frgn) { addressee = who; return; }
        if (clients[addressee].frgn < clients[who].frgn) { return; }
        addressee = min(addressee, who);
    }
};

vector<int> ans;

int step = 1;

void part1() {
    for (auto &cur : clients) {
        cur.init();
        cur.choise_frg();
        cur.choise_addresser();
    }
}

void part2() {
    for (int i = 0; i < n; i++) {
        auto &cur = clients[i];
        if (cur.addresser >= 0)
            clients[cur.addresser].request(i);
    }
}

void part3() {
    for (auto &cur : clients) {
        if (cur.addressee >= 0)
            clients[cur.addressee].was_approved = true;
    }
}

bool part4() {
    bool f = true;
    for (int i = 0; i < n; i++) {
        auto &cur = clients[i];
        auto q = cur.norm();
        if (!ans[i] && q)
            ans[i] = step;
        f &= q;
    }
    return f;
}

int main() {
    cin >> n >> k;
    clients.resize(n);
    for (int i = 0; i < n; i++) {
        clients[i].self = i;
    }
    ans.resize(n);
    frg_owners.resize(k);
    auto &f = clients.front();
    for (int i = 0; i < k; i++) {
        f.frg[i] = true;
        frg_owners[i].insert(0);
    }
    f.frgn = k;
    for (;;step++) {
        part1();
        part2();
        part3();
        if (part4()) break;
    }
    for (int i = 1; i < n; i++)
        cout << ans[i] << ' ';
}