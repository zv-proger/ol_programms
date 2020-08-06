/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0214 с сайта acmp.ru
*/
    
#include<bits/stdc++.h>
using namespace std;

bool dp[101][201][202];

int main() {
    for (int three = 0; three < 101; three++) {
        for (int two = 0; two < 201; two++) {
            for (int one = 0; one < 202; one++) {
                if (three) { 
                    if (!dp[three - 1][two + 1][one]) { dp[three][two][one] = true; continue; }
                    if (!dp[three - 1][two][one + 1]) { dp[three][two][one] = true; continue; }
                    if (!dp[three - 1][two][one])     { dp[three][two][one] = true; continue; }
                }
                if (two) { 
                    if (!dp[three][two - 1][one + 1]) { dp[three][two][one] = true; continue; }
                    if (!dp[three][two - 1][one])     { dp[three][two][one] = true; continue; }
                }
                if (one) {
                    if (!dp[three][two][one - 1])     { dp[three][two][one] = true; continue; }
                }
            }
        }
    }
    int three, two; cin >> two >> three;
    cout << 2 - dp[three][two][0];
}