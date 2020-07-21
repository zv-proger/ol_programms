#   Автор кода: Вадим Зинов (zv.proger@yandex.ru)
#   Решение задачи 0401 с сайта acmp.ru
   

from math import factorial as f

x, a = map(int, input().split())
x //= 5

print(f(a + x) // f(a) // f(x));