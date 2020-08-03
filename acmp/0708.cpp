/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0708 с сайта acmp.ru

    Первым на сбор урожая выходит один из кроликов, следом идет хомяк, потом снова кролик и так до тех пор, пока на поле есть хоть одна морковка.

    Кролики суетливы, поэтому они выбирают путь наиболее выгодный внешне: стартуют от самого богатого куста первой грядки, а из трех последующих
     вариантов всегда выбирают самый большой куст (при наличии нескольких кустов с одинаковым числом морковок выбирается куст с наибольшим номером).

    Хомяки, прибыв на поле раньше, успели составить подробную карту поля и поддерживают её в актуальном состоянии на основе оперативных данных о сборе урожая,
     поэтому они для каждого хомяка выбирают путь, позволяющий собрать максимальное количество морковок из возможных (при наличии нескольких вариантов с
     максимально возможным количеством морковок выбирается тот, где лексикографически больше последовательность номеров кустов в порядке посещения).
*/

#include<bits/stdc++.h>
using namespace std;

int dt[102][102], n, m;

int rabbit_collects() {
    int cur = 1;
    for (int j = 1; j <= m; j++) {
        if (dt[1][j] >= dt[1][cur]) cur = j;
    }
    int ans = dt[1][cur]; dt[1][cur] = 0;
    for (int i = 2; i <= n; i++) {
        int ncur = cur;
        if (cur > 1 && dt[i][ncur] < dt[i][cur - 1]) ncur = cur - 1;
        if (cur < m && dt[i][ncur] <= dt[i][cur + 1]) ncur = cur + 1;
        cur = ncur;
        ans += dt[i][cur];
        dt[i][cur] = 0;
    }
    return ans;
}

int hamster_collects() {
    int dp[102][102] = {0}, pr[102][102];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int p = j;
            if (j < m && dp[i-1][p] <= dp[i - 1][j + 1]) p = j + 1;
            if (j > 1 && dp[i-1][p] < dp[i - 1][j - 1]) p = j - 1;
            pr[i][j] = p;
            dp[i][j] = dp[i - 1][p] + dt[i][j];
        }
    }
    int cur = 1;
    for (int j = 2; j <= m; j++) {
        if (dp[n][cur] <= dp[n][j]) cur = j;
    }
    int ans = dp[n][cur];
    for (int i = n; i > 0; i--) {
        dt[i][cur] = 0;
        cur = pr[i][cur];
    }
    return ans;
}

int main() {
    int total = 0, rabbits_total = 0, hamsters_total = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j<= m; j++) {
            cin >> dt[i][j];
            total += dt[i][j];
        }
    }
    while (rabbits_total + hamsters_total != total) {
        rabbits_total += rabbit_collects();
        hamsters_total += hamster_collects();
    }
    cout << rabbits_total << ' ' << hamsters_total;
}