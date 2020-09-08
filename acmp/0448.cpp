/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0448 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(), x.end()
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(0)


bool issimp[1'000'000];

void init() {
    memset(issimp + 2, 1, sizeof(issimp) - 2);
    for (long long i = 2; i < 1'000'000; i++) {
        if (issimp[i]) {
            for (long long j = i * i; j < 1'000'000; j += i) {
                issimp[j] = 0;
            }
        }
    }
}

int main() {
    FASTIO;
    init();
    int n; cin >> n;
    int frnd[500'001] = {0};
    for (int i = 2; i <= n; i += 2) {
        frnd[i] = i - 1;
        for (int j = i - 2; j > 0; j -= 2) {
            if (issimp[i + frnd[j]] && issimp[j + frnd[i]]) {
                swap(frnd[j], frnd[i]);
                break;
            }
        }
    }
    for (int i = 2; i <= n; i += 2) {
        cout << frnd[i] << ' ' << i << endl;
    }
}