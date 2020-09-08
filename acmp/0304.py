# Автор кода: Вадим Зинов (zv.proger@yandex.ru)
# Решение задачи 0304 с сайта acmp.ru

from math import factorial as f
def calc(s, k):
    a, b = map(int, s.split(':'))

    if a < b:
        a, b = b, a

    if b < k:
        return f(k + b) // f(k) // f(b)

    return f(2*k) // f(k) // f(k) * 2 ** (b - k)

n, *d = input().split()
ans = 1
for i in range(int(n)):
    ans *= calc(d[i], 24 if i < 4 else 14)
print(ans)