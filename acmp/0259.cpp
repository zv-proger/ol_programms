/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0259 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(), x.end()

int z[500000];

int main() {
    size_t n; scanf("%d", &n);
    char s[500000];

    gets(gets(s));

    size_t ns = n; scanf("%d", &n);
    s[ns++] = '#';
    for (int i = n; i--; ) s[ns++] = s[i];
    s[ns] = 0;

    int l = -1, r = -1;
    for(int i = 1; s[i]; i++) {
        if (r > i) z[i] = min(r - i, z[i - l]);
        while (s[i + z[i]] && s[i + z[i]] == s[z[i]]) z[i]++;
        if (i + s[i] > r)
            l = i, r = i + z[i];
    }
    for (int i = 1; i <= n; i++) { printf("%d ", z[ns - i]); }
}