# Автор кода: Вадим Зинов (zv.proger@yandex.ru)
# Решение задачи 0299 с сайта acmp.ru

from math import factorial as f
def calc(s):
    a, b = map(int, s.split(':'))

    if a < b:
        a, b = b, a

    if b < 24:
        return f(24 + b) // f(24) // f(b)

    return f(48) // f(24) // f(24) * 2 ** (b - 24)

print(calc(input()))